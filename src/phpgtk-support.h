#ifndef PHP_GTK_PHPGTK_SUPPORT_H
#define PHP_GTK_PHPGTK_SUPPORT_H

/*
 * Marshalling between zvals and GTK/GLib values. Included by every binding .c.
 *
 * Handles: every GObject that crosses into PHP does so as an int — its
 * pointer — and the registry in phpgtk-bridge.c holds a reference for as long
 * as PHP holds the handle (registration ref_sinks, so floating refs from
 * *_new() are adopted and everything else is plain-reffed). 0 is NULL.
 * Resolving validates against the registry, so a stale or fabricated int is
 * NULL rather than a crash.
 *
 * Strings cross as string; NULL is null. Structs (GdkRGBA, GdkRectangle,
 * graphene) cross as their components in (doubles) and as assoc arrays out.
 *
 * There is deliberately no error side channel here: a process-global last
 * error is a ZTS hazard. Constructors return 0 on failure; GTK CRITICALs
 * stay on stderr.
 */

#include "php.h"

#include <gtk/gtk.h>
#include <graphene.h>
#include <stdint.h>

#ifdef __cplusplus
extern "C" {
#endif

/* Registry — implemented in phpgtk-bridge.c. */
zend_long phpgtk_handle_register(gpointer object); /* ref_sink + insert if new; 0 for NULL */
gpointer  phpgtk_handle_lookup(zend_long h);       /* NULL when unknown or stale */
void      phpgtk_handle_release(zend_long h);      /* drop the registry's reference */

/* GValue <-> zval marshalling, used by the signal closure and the property bridge. */
void phpgtk_gvalue_to_zval(const GValue *value, zval *out);
void phpgtk_zval_to_gvalue(zval *in, GValue *return_value);

/*
 * Wrap a PHP callable in a GClosure.
 *
 * The returned closure owns a reference on the callable and releases it when
 * GLib finalizes the closure. Signal handler return values are converted back
 * into the signal's return GValue, so handlers for signals like
 * GtkWindow::close-request can return false to let GTK proceed.
 */
GClosure *phpgtk_closure_new(zval *callback);

/* PHP array <-> NULL-terminated char** (GStrv-shaped parameters). */
char **phpgtk_zval_to_strv(zval *arr);
void   phpgtk_strv_free(char **strv);

#ifdef __cplusplus
}
#endif

/* Pointer identity as a handle value. Registration is what makes it resolvable. */
#define PHPGTK_HANDLE(p)  ((zend_long)(uintptr_t)(p))

/* Every binding resolves incoming handles through the registry — never a raw cast. */
#define PHPGTK_RESOLVE(h) (phpgtk_handle_lookup(h))

/* ---- arguments: read zvals defensively ---- */

static inline zval *phpgtk_deref(zval *z)
{
    if (z != NULL) { ZVAL_DEREF(z); }
    return z;
}

static inline zend_long phpgtk_arg_long(zval *z)
{
    z = phpgtk_deref(z);
    if (z == NULL) return 0;
    switch (Z_TYPE_P(z)) {
        case IS_LONG:   return Z_LVAL_P(z);
        case IS_DOUBLE: return (zend_long) Z_DVAL_P(z);
        case IS_TRUE:   return 1;
        default:        return 0;
    }
}

static inline double phpgtk_arg_double(zval *z)
{
    z = phpgtk_deref(z);
    if (z == NULL) return 0.0;
    switch (Z_TYPE_P(z)) {
        case IS_DOUBLE: return Z_DVAL_P(z);
        case IS_LONG:   return (double) Z_LVAL_P(z);
        default:        return 0.0;
    }
}

static inline gboolean phpgtk_arg_bool(zval *z)
{
    z = phpgtk_deref(z);
    if (z == NULL) return FALSE;
    switch (Z_TYPE_P(z)) {
        case IS_TRUE: return TRUE;
        case IS_LONG: return Z_LVAL_P(z) != 0 ? TRUE : FALSE;
        default:      return FALSE;
    }
}

/* const char* borrowed from the zval, or NULL for null / non-string. */
static inline const char *phpgtk_arg_string(zval *z)
{
    z = phpgtk_deref(z);
    if (z == NULL || Z_TYPE_P(z) != IS_STRING) return NULL;
    return Z_STRVAL_P(z);
}

/* Handle -> registered GObject, or NULL when unknown/stale. */
static inline gpointer phpgtk_arg_object(zval *z)
{
    return PHPGTK_RESOLVE(phpgtk_arg_long(z));
}

/* Resolve a handle to an instance of a GType; NULL when not that kind. */
#define PHPGTK_ARG_AS(Type, type_macro, z) \
    ((Type *) phpgtk_arg_typed(z, type_macro))

static inline gpointer phpgtk_arg_typed(zval *z, GType type)
{
    gpointer o = phpgtk_arg_object(z);
    return (o != NULL && g_type_check_instance_is_a((GTypeInstance *) o, type)) ? o : NULL;
}

/* ---- returns: write into return_value ---- */

/* transfer-none string return: copy, never free. NULL -> null. */
static inline void phpgtk_ret_string(zval *rv, const char *s)
{
    if (s == NULL) { ZVAL_NULL(rv); return; }
    ZVAL_STRING(rv, s);
}

/* transfer-full string return: copy then g_free. NULL -> null. */
static inline void phpgtk_ret_string_take(zval *rv, char *s)
{
    if (s == NULL) { ZVAL_NULL(rv); return; }
    ZVAL_STRING(rv, s);
    g_free(s);
}

/* GObject return: register (ref) and hand back the handle. NULL -> 0. */
static inline void phpgtk_ret_object(zval *rv, gpointer o)
{
    ZVAL_LONG(rv, phpgtk_handle_register(o));
}

/*
 * Transfer-full GObject return: register (which refs) then drop the
 * function's own ref so the registry is the remaining owner.
 */
static inline zend_long phpgtk_handle_register_take(gpointer o)
{
    zend_long h = phpgtk_handle_register(o);
    if (o != NULL) {
        g_object_unref(o);
    }
    return h;
}

/* Transfer-full string input: g_strdup so the callee can g_free. */
static inline char *phpgtk_arg_string_give(zval *z)
{
    const char *s = phpgtk_arg_string(z);

    return s != NULL ? g_strdup(s) : NULL;
}

/* Transfer-full GObject input: extra ref so GTK can steal one. */
static inline gpointer phpgtk_arg_object_give(zval *z)
{
    gpointer o = phpgtk_arg_object(z);
    if (o != NULL) {
        g_object_ref(o);
    }
    return o;
}

/* NULL-terminated char** -> PHP list of strings. NULL -> empty array. */
static inline void phpgtk_ret_strv(zval *rv, const char *const *strv)
{
    guint i;

    array_init(rv);
    if (strv == NULL) return;
    for (i = 0; strv[i] != NULL; i++) {
        add_next_index_string(rv, strv[i]);
    }
}

/* Transfer-full strv: copy into PHP then g_strfreev. */
static inline void phpgtk_ret_strv_take(zval *rv, char **strv)
{
    phpgtk_ret_strv(rv, (const char *const *) strv);
    if (strv != NULL) {
        g_strfreev(strv);
    }
}

static inline void phpgtk_ret_rgba(zval *rv, const GdkRGBA *c)
{
    array_init(rv);
    if (c == NULL) return;
    add_assoc_double(rv, "red", (double) c->red);
    add_assoc_double(rv, "green", (double) c->green);
    add_assoc_double(rv, "blue", (double) c->blue);
    add_assoc_double(rv, "alpha", (double) c->alpha);
}

static inline void phpgtk_ret_rectangle(zval *rv, const GdkRectangle *r)
{
    array_init(rv);
    if (r == NULL) return;
    add_assoc_long(rv, "x", r->x);
    add_assoc_long(rv, "y", r->y);
    add_assoc_long(rv, "width", r->width);
    add_assoc_long(rv, "height", r->height);
}

static inline void phpgtk_ret_requisition(zval *rv, const GtkRequisition *r)
{
    array_init(rv);
    if (r == NULL) return;
    add_assoc_long(rv, "width", r->width);
    add_assoc_long(rv, "height", r->height);
}

static inline void phpgtk_ret_graphene_rect(zval *rv, const graphene_rect_t *r)
{
    array_init(rv);
    if (r == NULL) return;
    add_assoc_double(rv, "x", (double) r->origin.x);
    add_assoc_double(rv, "y", (double) r->origin.y);
    add_assoc_double(rv, "width", (double) r->size.width);
    add_assoc_double(rv, "height", (double) r->size.height);
}

static inline void phpgtk_ret_graphene_point(zval *rv, const graphene_point_t *p)
{
    array_init(rv);
    if (p == NULL) return;
    add_assoc_double(rv, "x", (double) p->x);
    add_assoc_double(rv, "y", (double) p->y);
}

/*
 * GList of GObjects -> array of handles. free_list / unref_items follow
 * the gir transfer mode (none / container / full).
 */
static inline void phpgtk_ret_object_glist(zval *rv, GList *list, gboolean free_list, gboolean unref_items)
{
    GList *l;

    array_init(rv);
    for (l = list; l != NULL; l = l->next) {
        add_next_index_long(rv, phpgtk_handle_register(l->data));
    }
    if (free_list && unref_items) {
        g_list_free_full(list, g_object_unref);
    } else if (free_list) {
        g_list_free(list);
    }
}

/* PHP array of handles -> borrowed GObject* vector (efree with phpgtk_object_array_free). */
static inline gpointer *phpgtk_arg_object_array(zval *arr, guint *n)
{
    HashTable *ht;
    zval *entry;
    gpointer *out;
    guint i;

    *n = 0;
    arr = phpgtk_deref(arr);
    if (arr == NULL || Z_TYPE_P(arr) != IS_ARRAY) {
        return NULL;
    }
    ht = Z_ARRVAL_P(arr);
    *n = zend_hash_num_elements(ht);
    if (*n == 0) {
        return NULL;
    }
    out = (gpointer *) ecalloc(*n, sizeof(gpointer));
    i = 0;
    ZEND_HASH_FOREACH_VAL(ht, entry) {
        out[i++] = phpgtk_arg_object(entry);
    } ZEND_HASH_FOREACH_END();

    return out;
}

static inline void phpgtk_object_array_free(gpointer *a)
{
    if (a != NULL) {
        efree(a);
    }
}

#endif /* PHP_GTK_PHPGTK_SUPPORT_H */
