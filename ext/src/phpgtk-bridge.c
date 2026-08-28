#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "phpgtk-bridge.h"
#include "phpgtk-support.h"

#include <string.h>

/* ====================================================================== */
/* Init                                                                   */
/* ====================================================================== */

/*
 * Single-thread expectation: the registry and init flag below are process
 * globals, not thread-locals. The extension supports ZTS builds but assumes
 * one PHP thread talks to GTK — the CLI process model this binding targets.
 */
static gboolean phpgtk_inited = FALSE;
static gboolean phpgtk_init_result = FALSE;

zend_long phpgtk_bridge_init(void)
{
    if (!phpgtk_inited) {
        phpgtk_inited = TRUE;
        phpgtk_init_result = gtk_init_check();
    }

    return phpgtk_init_result ? 1 : 0;
}

/* ====================================================================== */
/* Handle registry                                                        */
/* ====================================================================== */

static GHashTable *phpgtk_registry = NULL;

static GHashTable *phpgtk_registry_table(void)
{
    if (phpgtk_registry == NULL) {
        /* Value destroy drops the registry's reference on remove. */
        phpgtk_registry = g_hash_table_new_full(g_direct_hash, g_direct_equal, NULL, g_object_unref);
    }

    return phpgtk_registry;
}

zend_long phpgtk_handle_register(gpointer object)
{
    if (object == NULL) {
        return 0;
    }

    if (!g_hash_table_contains(phpgtk_registry_table(), object)) {
        /*
         * ref_sink adopts the floating reference a gtk_*_new() returns and
         * plain-refs an already-owned object, so one rule covers both
         * constructors and transfer-none getters.
         */
        g_object_ref_sink(object);
        g_hash_table_insert(phpgtk_registry_table(), object, object);
    }

    return PHPGTK_HANDLE(object);
}

gpointer phpgtk_handle_lookup(zend_long h)
{
    if (h == 0) {
        return NULL;
    }

    return g_hash_table_lookup(phpgtk_registry_table(), (gpointer) (uintptr_t) h);
}

void phpgtk_handle_release(zend_long h)
{
    if (h == 0) {
        return;
    }

    g_hash_table_remove(phpgtk_registry_table(), (gpointer) (uintptr_t) h);
}

zend_long phpgtk_bridge_retain(zval *handle)
{
    return phpgtk_handle_lookup(phpgtk_arg_long(handle)) != NULL ? 1 : 0;
}

void phpgtk_bridge_release(zval *handle)
{
    phpgtk_handle_release(phpgtk_arg_long(handle));
}

zend_long phpgtk_bridge_is_valid(zval *handle)
{
    return phpgtk_handle_lookup(phpgtk_arg_long(handle)) != NULL ? 1 : 0;
}

void phpgtk_bridge_type_name(zval *return_value, zval *handle)
{
    gpointer o = phpgtk_arg_object(handle);

    if (o == NULL) {
        ZVAL_NULL(return_value);
        return;
    }

    phpgtk_ret_string(return_value, G_OBJECT_TYPE_NAME(o));
}

zend_long phpgtk_bridge_is_a(zval *handle, zval *typeName)
{
    gpointer    o    = phpgtk_arg_object(handle);
    const char *name = phpgtk_arg_string(typeName);
    GType       type;

    if (o == NULL || name == NULL) {
        return 0;
    }

    type = g_type_from_name(name);
    if (type == G_TYPE_INVALID) {
        return 0;
    }

    return g_type_check_instance_is_a((GTypeInstance *) o, type) ? 1 : 0;
}

zend_long phpgtk_bridge_type_from_name(zval *typeName)
{
    const char *name = phpgtk_arg_string(typeName);

    if (name == NULL) {
        return 0;
    }

    return (zend_long) g_type_from_name(name);
}

/* ====================================================================== */
/* Main loop pump                                                         */
/* ====================================================================== */

static gboolean phpgtk_pump_timeout_cb(gpointer data)
{
    *(gboolean *) data = TRUE;

    return G_SOURCE_REMOVE;
}

zend_long phpgtk_bridge_pump(zval *timeoutMs)
{
    zend_long ms   = phpgtk_arg_long(timeoutMs);
    zend_long sent = 0;

    while (g_main_context_iteration(NULL, FALSE)) {
        sent++;
        if (EG(exception)) {
            return sent;
        }
    }

    if (sent == 0 && ms > 0) {
        gboolean fired  = FALSE;
        guint    source = g_timeout_add((guint) ms, phpgtk_pump_timeout_cb, &fired);

        /* Block until a real source or the deadline dispatches. */
        while (!fired) {
            if (g_main_context_iteration(NULL, TRUE)) {
                if (!fired) {
                    sent++;
                }
            }
            if (EG(exception) || sent > 0) {
                break;
            }
        }
        if (!fired) {
            g_source_remove(source);
        }

        while (!EG(exception) && g_main_context_iteration(NULL, FALSE)) {
            sent++;
        }
    }

    return sent;
}

/* ====================================================================== */
/* Signals                                                                */
/* ====================================================================== */

/*
 * Lifetime: the closure owns a reference to the PHP callable, and the object
 * owns the closure. Finalizing the object — which is what unparenting a
 * widget does once the registry ref is released — disconnects the handler
 * and drops the callable with it, so a caller owes no cleanup and leaves
 * nothing dangling. The handler id is only good while the object is alive.
 */
zend_long phpgtk_bridge_connect(zval *handle, zval *signal, zval *callback)
{
    gpointer    obj  = phpgtk_arg_object(handle);
    const char *name = phpgtk_arg_string(signal);
    GClosure   *closure;
    gulong      handler_id;
    guint       signal_id = 0;
    GQuark      detail    = 0;

    if (obj == NULL) {
        php_error_docref(NULL, E_WARNING, "connect: handle is not a registered object");
        return 0;
    }

    if (name == NULL || name[0] == '\0') {
        php_error_docref(NULL, E_WARNING, "connect: signal name is empty");
        return 0;
    }

    if (callback == NULL || !zend_is_callable(callback, 0, NULL)) {
        php_error_docref(NULL, E_WARNING, "connect: callback is not callable");
        return 0;
    }

    /*
     * Resolve the name before connecting. g_signal_connect_closure() parses
     * it itself, but reports an unknown signal by writing a GLib warning to
     * stderr, which a PHP caller can neither catch nor read. Parsing first
     * turns that into a returned 0 and a PHP warning.
     */
    if (!g_signal_parse_name(name, G_OBJECT_TYPE(obj), &signal_id, &detail, TRUE)) {
        php_error_docref(NULL, E_WARNING, "connect: %s has no signal \"%s\"",
                         G_OBJECT_TYPE_NAME(obj), name);
        return 0;
    }

    /*
     * A "notify" detail that names no property is worse than an error: GLib
     * accepts the connection and the handler simply never fires. Catch it
     * here, including the case where the property exists but was spelled
     * with underscores — the detail quark is the dashed name, so
     * "notify::my_prop" is silent even though the property is real.
     */
    if (detail != 0 && signal_id == g_signal_lookup("notify", G_TYPE_OBJECT)) {
        const char *want  = g_quark_to_string(detail);
        GParamSpec *pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), want);

        if (pspec == NULL) {
            php_error_docref(NULL, E_WARNING, "connect: %s has no property \"%s\"",
                             G_OBJECT_TYPE_NAME(obj), want);
            return 0;
        }

        if (strcmp(pspec->name, want) != 0) {
            php_error_docref(NULL, E_WARNING,
                             "connect: spell it \"notify::%s\" — \"%s\" never fires",
                             pspec->name, want);
            return 0;
        }
    }

    closure    = phpgtk_closure_new(callback);
    handler_id = g_signal_connect_closure_by_id(obj, signal_id, detail, closure, FALSE);

    if (handler_id == 0) {
        g_closure_unref(closure);
        php_error_docref(NULL, E_WARNING, "connect: g_signal_connect_closure failed");
        return 0;
    }

    return (zend_long) handler_id;
}

void phpgtk_bridge_disconnect(zval *handle, zval *handlerId)
{
    gpointer obj = phpgtk_arg_object(handle);
    gulong   hid = (gulong) phpgtk_arg_long(handlerId);

    if (obj == NULL || hid == 0) {
        return;
    }

    /* A bogus id makes g_signal_handler_disconnect warn on stderr; check first. */
    if (g_signal_handler_is_connected(obj, hid)) {
        g_signal_handler_disconnect(obj, hid);
    }
}

/* ====================================================================== */
/* Properties                                                             */
/* ====================================================================== */

/*
 * zval -> GValue for property writes. Wider than the signal-return
 * converter in phpgtk-support.c: properties also carry enums, flags,
 * unsigned 64-bit ints, and objects (handles).
 */
static gboolean phpgtk_zval_to_property(zval *in, GValue *value)
{
    switch (G_TYPE_FUNDAMENTAL(G_VALUE_TYPE(value))) {
        case G_TYPE_BOOLEAN:
            g_value_set_boolean(value, zend_is_true(in) ? TRUE : FALSE);
            return TRUE;
        case G_TYPE_INT:
            g_value_set_int(value, (gint) zval_get_long(in));
            return TRUE;
        case G_TYPE_UINT:
            g_value_set_uint(value, (guint) zval_get_long(in));
            return TRUE;
        case G_TYPE_LONG:
            g_value_set_long(value, (glong) zval_get_long(in));
            return TRUE;
        case G_TYPE_ULONG:
            g_value_set_ulong(value, (gulong) zval_get_long(in));
            return TRUE;
        case G_TYPE_INT64:
            g_value_set_int64(value, (gint64) zval_get_long(in));
            return TRUE;
        case G_TYPE_UINT64:
            g_value_set_uint64(value, (guint64) zval_get_long(in));
            return TRUE;
        case G_TYPE_FLOAT:
            g_value_set_float(value, (gfloat) zval_get_double(in));
            return TRUE;
        case G_TYPE_DOUBLE:
            g_value_set_double(value, zval_get_double(in));
            return TRUE;
        case G_TYPE_ENUM:
            g_value_set_enum(value, (gint) zval_get_long(in));
            return TRUE;
        case G_TYPE_FLAGS:
            g_value_set_flags(value, (guint) zval_get_long(in));
            return TRUE;
        case G_TYPE_STRING: {
            zend_string *str;

            if (Z_TYPE_P(in) == IS_NULL) {
                g_value_set_string(value, NULL);
                return TRUE;
            }
            str = zval_get_string(in);
            g_value_set_string(value, ZSTR_VAL(str));
            zend_string_release(str);
            return TRUE;
        }
        case G_TYPE_OBJECT:
            /* An int handle; 0 or null means NULL. */
            g_value_set_object(value, phpgtk_handle_lookup(zval_get_long(in)));
            return TRUE;
        default:
            return FALSE;
    }
}

void phpgtk_bridge_get_property(zval *return_value, zval *handle, zval *name)
{
    gpointer    obj  = phpgtk_arg_object(handle);
    const char *prop = phpgtk_arg_string(name);
    GParamSpec *pspec;
    GValue      value = G_VALUE_INIT;

    ZVAL_NULL(return_value);

    if (obj == NULL || prop == NULL) {
        php_error_docref(NULL, E_WARNING, "getProperty: invalid handle or property name");
        return;
    }

    pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), prop);
    if (pspec == NULL) {
        php_error_docref(NULL, E_WARNING, "getProperty: %s has no property \"%s\"",
                         G_OBJECT_TYPE_NAME(obj), prop);
        return;
    }

    g_value_init(&value, pspec->value_type);
    g_object_get_property(obj, prop, &value);
    phpgtk_gvalue_to_zval(&value, return_value);
    g_value_unset(&value);
}

void phpgtk_bridge_set_property(zval *handle, zval *name, zval *value)
{
    gpointer    obj  = phpgtk_arg_object(handle);
    const char *prop = phpgtk_arg_string(name);
    GParamSpec *pspec;
    GValue      gvalue = G_VALUE_INIT;

    if (obj == NULL || prop == NULL) {
        php_error_docref(NULL, E_WARNING, "setProperty: invalid handle or property name");
        return;
    }

    pspec = g_object_class_find_property(G_OBJECT_GET_CLASS(obj), prop);
    if (pspec == NULL) {
        php_error_docref(NULL, E_WARNING, "setProperty: %s has no property \"%s\"",
                         G_OBJECT_TYPE_NAME(obj), prop);
        return;
    }

    if ((pspec->flags & G_PARAM_WRITABLE) == 0 || (pspec->flags & G_PARAM_CONSTRUCT_ONLY) != 0) {
        php_error_docref(NULL, E_WARNING, "setProperty: property \"%s\" of %s is not writable",
                         prop, G_OBJECT_TYPE_NAME(obj));
        return;
    }

    g_value_init(&gvalue, pspec->value_type);
    if (!phpgtk_zval_to_property(phpgtk_deref(value), &gvalue)) {
        g_value_unset(&gvalue);
        php_error_docref(NULL, E_WARNING,
                         "setProperty: unsupported value type %s for property \"%s\"",
                         g_type_name(pspec->value_type), prop);
        return;
    }

    g_object_set_property(obj, prop, &gvalue);
    g_value_unset(&gvalue);
}
