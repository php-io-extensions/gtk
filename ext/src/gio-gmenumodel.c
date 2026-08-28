#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gio-gmenumodel.h"
#include "phpgtk-support.h"

zend_long phpgtk_gmenumodel_get_item_link(zval *handle, zval *itemIndex, zval *link)
{
    GMenuModel *self = PHPGTK_ARG_AS(GMenuModel, G_TYPE_MENU_MODEL, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register_take(g_menu_model_get_item_link(self, (gint) phpgtk_arg_long(itemIndex), phpgtk_arg_string(link)));
}

zend_long phpgtk_gmenumodel_get_n_items(zval *handle)
{
    GMenuModel *self = PHPGTK_ARG_AS(GMenuModel, G_TYPE_MENU_MODEL, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) g_menu_model_get_n_items(self);
}

zend_long phpgtk_gmenumodel_is_mutable(zval *handle)
{
    GMenuModel *self = PHPGTK_ARG_AS(GMenuModel, G_TYPE_MENU_MODEL, handle);

    if (self == NULL) {
        return 0;
    }

    return g_menu_model_is_mutable(self) ? 1 : 0;
}

void phpgtk_gmenumodel_items_changed(zval *handle, zval *position, zval *removed, zval *added)
{
    GMenuModel *self = PHPGTK_ARG_AS(GMenuModel, G_TYPE_MENU_MODEL, handle);

    if (self == NULL) {
        return;
    }

    g_menu_model_items_changed(self, (gint) phpgtk_arg_long(position), (gint) phpgtk_arg_long(removed), (gint) phpgtk_arg_long(added));
}
