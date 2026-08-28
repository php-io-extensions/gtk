#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "phpgtk-support.h"

#include <string.h>

/*
 * Convert one signal parameter (or property value) into a zval.
 *
 * GObjects are registered so the handler receives a handle it can pass
 * straight back into any binding — the registry plain-refs an already-sunk
 * object, and the ref is dropped when PHP releases the handle.
 *
 * Non-GObject pointers (raw pointers, GParamSpecs, boxed values) cross as
 * their pointer value. They are NOT registry-resolvable — bindings only
 * accept registered GObjects — so to a handler they are opaque tokens.
 * Signals whose useful payload is a boxed struct get Bridge-level support
 * if and when a wave needs them.
 */
void phpgtk_gvalue_to_zval(const GValue *value, zval *out)
{
    if (G_VALUE_HOLDS_OBJECT(value)) {
        ZVAL_LONG(out, phpgtk_handle_register(g_value_get_object(value)));
        return;
    }
    if (G_VALUE_HOLDS_POINTER(value)) {
        ZVAL_LONG(out, PHPGTK_HANDLE(g_value_get_pointer(value)));
        return;
    }
    if (G_VALUE_HOLDS_BOOLEAN(value)) {
        ZVAL_BOOL(out, g_value_get_boolean(value));
        return;
    }
    if (G_VALUE_HOLDS_INT(value)) {
        ZVAL_LONG(out, g_value_get_int(value));
        return;
    }
    if (G_VALUE_HOLDS_UINT(value)) {
        ZVAL_LONG(out, (zend_long) g_value_get_uint(value));
        return;
    }
    if (G_VALUE_HOLDS_LONG(value)) {
        ZVAL_LONG(out, (zend_long) g_value_get_long(value));
        return;
    }
    if (G_VALUE_HOLDS_INT64(value)) {
        ZVAL_LONG(out, (zend_long) g_value_get_int64(value));
        return;
    }
    if (G_VALUE_HOLDS_FLOAT(value)) {
        ZVAL_DOUBLE(out, (double) g_value_get_float(value));
        return;
    }
    if (G_VALUE_HOLDS_DOUBLE(value)) {
        ZVAL_DOUBLE(out, g_value_get_double(value));
        return;
    }
    if (G_VALUE_HOLDS_STRING(value)) {
        const char *s = g_value_get_string(value);

        if (s == NULL) {
            ZVAL_EMPTY_STRING(out);
        } else {
            ZVAL_STRING(out, s);
        }
        return;
    }
    if (G_VALUE_HOLDS_ENUM(value)) {
        ZVAL_LONG(out, g_value_get_enum(value));
        return;
    }
    if (G_VALUE_HOLDS_FLAGS(value)) {
        ZVAL_LONG(out, g_value_get_flags(value));
        return;
    }

    /*
     * A GParamSpec -- the second argument every "notify" handler is given.
     * Passed through as a raw pointer value, though a handler connected as
     * "notify::prop" already knows which property fired.
     */
    if (G_VALUE_HOLDS_PARAM(value)) {
        ZVAL_LONG(out, PHPGTK_HANDLE(g_value_get_param(value)));
        return;
    }
    if (G_VALUE_HOLDS_BOXED(value)) {
        ZVAL_LONG(out, PHPGTK_HANDLE(g_value_get_boxed(value)));
        return;
    }

    ZVAL_LONG(out, 0);
}

/*
 * Write a handler's PHP return value back into the signal's return GValue.
 *
 * Only the types GTK signals actually return are handled. Anything else is
 * left at its default, which is what an unset return would have produced.
 */
void phpgtk_zval_to_gvalue(zval *in, GValue *return_value)
{
    GType t;

    if (return_value == NULL || !G_IS_VALUE(return_value) || in == NULL || Z_ISUNDEF_P(in)) {
        return;
    }

    t = G_VALUE_TYPE(return_value);

    if (t == G_TYPE_BOOLEAN) {
        g_value_set_boolean(return_value, zend_is_true(in) ? TRUE : FALSE);
        return;
    }
    if (t == G_TYPE_INT) {
        g_value_set_int(return_value, (gint) zval_get_long(in));
        return;
    }
    if (t == G_TYPE_UINT) {
        g_value_set_uint(return_value, (guint) zval_get_long(in));
        return;
    }
    if (t == G_TYPE_LONG) {
        g_value_set_long(return_value, (glong) zval_get_long(in));
        return;
    }
    if (t == G_TYPE_INT64) {
        g_value_set_int64(return_value, (gint64) zval_get_long(in));
        return;
    }
    if (t == G_TYPE_DOUBLE || t == G_TYPE_FLOAT) {
        g_value_set_double(return_value, zval_get_double(in));
        return;
    }
    if (t == G_TYPE_STRING) {
        zend_string *str = zval_get_string(in);

        g_value_set_string(return_value, ZSTR_VAL(str));
        zend_string_release(str);
        return;
    }
}

typedef struct _PhpGtkClosure {
    GClosure closure;
    zval     callback;
} PhpGtkClosure;

static void phpgtk_closure_marshal(
    GClosure     *closure,
    GValue       *return_value,
    guint         n_param_values,
    const GValue *param_values,
    gpointer      invocation_hint,
    gpointer      marshal_data
) {
    PhpGtkClosure *pc = (PhpGtkClosure *) closure;
    zval           retval;
    zval          *params;
    guint          i;

    (void) invocation_hint;
    (void) marshal_data;

    if (Z_TYPE(pc->callback) == IS_UNDEF || Z_TYPE(pc->callback) == IS_NULL) {
        return;
    }

    params = (zval *) safe_emalloc(n_param_values > 0 ? n_param_values : 1, sizeof(zval), 0);
    for (i = 0; i < n_param_values; i++) {
        phpgtk_gvalue_to_zval(&param_values[i], &params[i]);
    }

    ZVAL_UNDEF(&retval);
    call_user_function(EG(function_table), NULL, &pc->callback, &retval, n_param_values, params);

    if (return_value != NULL && G_IS_VALUE(return_value) && !Z_ISUNDEF(retval)) {
        phpgtk_zval_to_gvalue(&retval, return_value);
    }

    if (!Z_ISUNDEF(retval)) {
        zval_ptr_dtor(&retval);
    }
    for (i = 0; i < n_param_values; i++) {
        zval_ptr_dtor(&params[i]);
    }
    efree(params);
}

static void phpgtk_closure_finalize(gpointer data, GClosure *closure)
{
    PhpGtkClosure *pc = (PhpGtkClosure *) closure;

    (void) data;
    zval_ptr_dtor(&pc->callback);
}

GClosure *phpgtk_closure_new(zval *callback)
{
    PhpGtkClosure *pc = (PhpGtkClosure *) g_closure_new_simple(sizeof(PhpGtkClosure), NULL);

    ZVAL_COPY(&pc->callback, callback);
    g_closure_add_finalize_notifier((GClosure *) pc, NULL, phpgtk_closure_finalize);
    g_closure_set_marshal((GClosure *) pc, phpgtk_closure_marshal);

    return (GClosure *) pc;
}

char **phpgtk_zval_to_strv(zval *arr)
{
    HashTable *ht;
    zval      *entry;
    char     **strv;
    guint      n;
    guint      i;

    if (arr == NULL || Z_TYPE_P(arr) != IS_ARRAY) {
        return NULL;
    }

    ht   = Z_ARRVAL_P(arr);
    n    = zend_hash_num_elements(ht);
    strv = (char **) ecalloc(n + 1, sizeof(char *));
    i    = 0;

    ZEND_HASH_FOREACH_VAL(ht, entry) {
        zend_string *s = zval_get_string(entry);

        strv[i] = estrndup(ZSTR_VAL(s), ZSTR_LEN(s));
        zend_string_release(s);
        i++;
    } ZEND_HASH_FOREACH_END();

    strv[i] = NULL;

    return strv;
}

void phpgtk_strv_free(char **strv)
{
    guint i;

    if (strv == NULL) {
        return;
    }

    for (i = 0; strv[i] != NULL; i++) {
        efree(strv[i]);
    }
    efree(strv);
}
