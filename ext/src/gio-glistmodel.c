#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gio-glistmodel.h"
#include "phpgtk-support.h"

zend_long phpgtk_glistmodel_get_item(zval *handle, zval *position)
{
    GListModel *self = PHPGTK_ARG_AS(GListModel, G_TYPE_LIST_MODEL, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register_take(g_list_model_get_item(self, (guint) phpgtk_arg_long(position)));
}

zend_long phpgtk_glistmodel_get_item_type(zval *handle)
{
    GListModel *self = PHPGTK_ARG_AS(GListModel, G_TYPE_LIST_MODEL, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) g_list_model_get_item_type(self);
}

zend_long phpgtk_glistmodel_get_n_items(zval *handle)
{
    GListModel *self = PHPGTK_ARG_AS(GListModel, G_TYPE_LIST_MODEL, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) g_list_model_get_n_items(self);
}

zend_long phpgtk_glistmodel_get_object(zval *handle, zval *position)
{
    GListModel *self = PHPGTK_ARG_AS(GListModel, G_TYPE_LIST_MODEL, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register_take(g_list_model_get_object(self, (guint) phpgtk_arg_long(position)));
}

void phpgtk_glistmodel_items_changed(zval *handle, zval *position, zval *removed, zval *added)
{
    GListModel *self = PHPGTK_ARG_AS(GListModel, G_TYPE_LIST_MODEL, handle);

    if (self == NULL) {
        return;
    }

    g_list_model_items_changed(self, (guint) phpgtk_arg_long(position), (guint) phpgtk_arg_long(removed), (guint) phpgtk_arg_long(added));
}
