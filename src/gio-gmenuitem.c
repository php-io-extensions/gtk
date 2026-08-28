#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gio-gmenuitem.h"
#include "phpgtk-support.h"

zend_long phpgtk_gmenuitem_new(zval *label, zval *detailedAction)
{
    return phpgtk_handle_register_take(g_menu_item_new(phpgtk_arg_string(label), phpgtk_arg_string(detailedAction)));
}

zend_long phpgtk_gmenuitem_new_from_model(zval *model, zval *itemIndex)
{
    return phpgtk_handle_register_take(g_menu_item_new_from_model(phpgtk_arg_object(model), (gint) phpgtk_arg_long(itemIndex)));
}

zend_long phpgtk_gmenuitem_new_section(zval *label, zval *section)
{
    return phpgtk_handle_register_take(g_menu_item_new_section(phpgtk_arg_string(label), phpgtk_arg_object(section)));
}

zend_long phpgtk_gmenuitem_new_submenu(zval *label, zval *submenu)
{
    return phpgtk_handle_register_take(g_menu_item_new_submenu(phpgtk_arg_string(label), phpgtk_arg_object(submenu)));
}

zend_long phpgtk_gmenuitem_get_link(zval *handle, zval *link)
{
    GMenuItem *self = PHPGTK_ARG_AS(GMenuItem, G_TYPE_MENU_ITEM, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register_take(g_menu_item_get_link(self, phpgtk_arg_string(link)));
}

void phpgtk_gmenuitem_set_detailed_action(zval *handle, zval *detailedAction)
{
    GMenuItem *self = PHPGTK_ARG_AS(GMenuItem, G_TYPE_MENU_ITEM, handle);

    if (self == NULL) {
        return;
    }

    g_menu_item_set_detailed_action(self, phpgtk_arg_string(detailedAction));
}

void phpgtk_gmenuitem_set_icon(zval *handle, zval *icon)
{
    GMenuItem *self = PHPGTK_ARG_AS(GMenuItem, G_TYPE_MENU_ITEM, handle);

    if (self == NULL) {
        return;
    }

    g_menu_item_set_icon(self, phpgtk_arg_object(icon));
}

void phpgtk_gmenuitem_set_label(zval *handle, zval *label)
{
    GMenuItem *self = PHPGTK_ARG_AS(GMenuItem, G_TYPE_MENU_ITEM, handle);

    if (self == NULL) {
        return;
    }

    g_menu_item_set_label(self, phpgtk_arg_string(label));
}

void phpgtk_gmenuitem_set_link(zval *handle, zval *link, zval *model)
{
    GMenuItem *self = PHPGTK_ARG_AS(GMenuItem, G_TYPE_MENU_ITEM, handle);

    if (self == NULL) {
        return;
    }

    g_menu_item_set_link(self, phpgtk_arg_string(link), phpgtk_arg_object(model));
}

void phpgtk_gmenuitem_set_section(zval *handle, zval *section)
{
    GMenuItem *self = PHPGTK_ARG_AS(GMenuItem, G_TYPE_MENU_ITEM, handle);

    if (self == NULL) {
        return;
    }

    g_menu_item_set_section(self, phpgtk_arg_object(section));
}

void phpgtk_gmenuitem_set_submenu(zval *handle, zval *submenu)
{
    GMenuItem *self = PHPGTK_ARG_AS(GMenuItem, G_TYPE_MENU_ITEM, handle);

    if (self == NULL) {
        return;
    }

    g_menu_item_set_submenu(self, phpgtk_arg_object(submenu));
}
