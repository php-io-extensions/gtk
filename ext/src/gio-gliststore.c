#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gio-gliststore.h"
#include "phpgtk-support.h"

zend_long phpgtk_gliststore_new(zval *itemType)
{
    return phpgtk_handle_register_take(g_list_store_new((GType) phpgtk_arg_long(itemType)));
}

void phpgtk_gliststore_append(zval *handle, zval *item)
{
    GListStore *self = PHPGTK_ARG_AS(GListStore, G_TYPE_LIST_STORE, handle);

    if (self == NULL) {
        return;
    }

    g_list_store_append(self, phpgtk_arg_object(item));
}

void phpgtk_gliststore_find(zval *return_value, zval *handle, zval *item)
{
    GListStore *self = PHPGTK_ARG_AS(GListStore, G_TYPE_LIST_STORE, handle);
    guint position = 0;

    if (self == NULL) {
        array_init(return_value); return;
    }

    g_list_store_find(self, phpgtk_arg_object(item), &position);
    array_init(return_value);
    add_assoc_long(return_value, "position", (zend_long) position);
}

void phpgtk_gliststore_insert(zval *handle, zval *position, zval *item)
{
    GListStore *self = PHPGTK_ARG_AS(GListStore, G_TYPE_LIST_STORE, handle);

    if (self == NULL) {
        return;
    }

    g_list_store_insert(self, (guint) phpgtk_arg_long(position), phpgtk_arg_object(item));
}

void phpgtk_gliststore_remove(zval *handle, zval *position)
{
    GListStore *self = PHPGTK_ARG_AS(GListStore, G_TYPE_LIST_STORE, handle);

    if (self == NULL) {
        return;
    }

    g_list_store_remove(self, (guint) phpgtk_arg_long(position));
}

void phpgtk_gliststore_remove_all(zval *handle)
{
    GListStore *self = PHPGTK_ARG_AS(GListStore, G_TYPE_LIST_STORE, handle);

    if (self == NULL) {
        return;
    }

    g_list_store_remove_all(self);
}

void phpgtk_gliststore_splice(zval *handle, zval *position, zval *nRemovals, zval *additions, zval *nAdditions)
{
    GListStore *self = PHPGTK_ARG_AS(GListStore, G_TYPE_LIST_STORE, handle);
    guint n = 0;
    gpointer *items;

    if (self == NULL) {
        return;
    }

    items = phpgtk_arg_object_array(additions, &n);
    g_list_store_splice(self, (guint) phpgtk_arg_long(position), (guint) phpgtk_arg_long(nRemovals), items, (guint) phpgtk_arg_long(nAdditions));
    phpgtk_object_array_free(items);
}
