#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-list-item.h"
#include "phpgtk-support.h"

void phpgtk_gtklistitem_get_accessible_description(zval *return_value, zval *handle)
{
    GtkListItem *self = PHPGTK_ARG_AS(GtkListItem, GTK_TYPE_LIST_ITEM, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_list_item_get_accessible_description(self));
}

void phpgtk_gtklistitem_get_accessible_label(zval *return_value, zval *handle)
{
    GtkListItem *self = PHPGTK_ARG_AS(GtkListItem, GTK_TYPE_LIST_ITEM, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_list_item_get_accessible_label(self));
}

zend_long phpgtk_gtklistitem_get_activatable(zval *handle)
{
    GtkListItem *self = PHPGTK_ARG_AS(GtkListItem, GTK_TYPE_LIST_ITEM, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_list_item_get_activatable(self) ? 1 : 0;
}

zend_long phpgtk_gtklistitem_get_child(zval *handle)
{
    GtkListItem *self = PHPGTK_ARG_AS(GtkListItem, GTK_TYPE_LIST_ITEM, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_list_item_get_child(self));
}

zend_long phpgtk_gtklistitem_get_focusable(zval *handle)
{
    GtkListItem *self = PHPGTK_ARG_AS(GtkListItem, GTK_TYPE_LIST_ITEM, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_list_item_get_focusable(self) ? 1 : 0;
}

zend_long phpgtk_gtklistitem_get_item(zval *handle)
{
    GtkListItem *self = PHPGTK_ARG_AS(GtkListItem, GTK_TYPE_LIST_ITEM, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_list_item_get_item(self));
}

zend_long phpgtk_gtklistitem_get_position(zval *handle)
{
    GtkListItem *self = PHPGTK_ARG_AS(GtkListItem, GTK_TYPE_LIST_ITEM, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_list_item_get_position(self);
}

zend_long phpgtk_gtklistitem_get_selectable(zval *handle)
{
    GtkListItem *self = PHPGTK_ARG_AS(GtkListItem, GTK_TYPE_LIST_ITEM, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_list_item_get_selectable(self) ? 1 : 0;
}

zend_long phpgtk_gtklistitem_get_selected(zval *handle)
{
    GtkListItem *self = PHPGTK_ARG_AS(GtkListItem, GTK_TYPE_LIST_ITEM, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_list_item_get_selected(self) ? 1 : 0;
}

void phpgtk_gtklistitem_set_accessible_description(zval *handle, zval *description)
{
    GtkListItem *self = PHPGTK_ARG_AS(GtkListItem, GTK_TYPE_LIST_ITEM, handle);

    if (self == NULL) {
        return;
    }

    gtk_list_item_set_accessible_description(self, phpgtk_arg_string(description));
}

void phpgtk_gtklistitem_set_accessible_label(zval *handle, zval *label)
{
    GtkListItem *self = PHPGTK_ARG_AS(GtkListItem, GTK_TYPE_LIST_ITEM, handle);

    if (self == NULL) {
        return;
    }

    gtk_list_item_set_accessible_label(self, phpgtk_arg_string(label));
}

void phpgtk_gtklistitem_set_activatable(zval *handle, zval *activatable)
{
    GtkListItem *self = PHPGTK_ARG_AS(GtkListItem, GTK_TYPE_LIST_ITEM, handle);

    if (self == NULL) {
        return;
    }

    gtk_list_item_set_activatable(self, phpgtk_arg_bool(activatable));
}

void phpgtk_gtklistitem_set_child(zval *handle, zval *child)
{
    GtkListItem *self = PHPGTK_ARG_AS(GtkListItem, GTK_TYPE_LIST_ITEM, handle);

    if (self == NULL) {
        return;
    }

    gtk_list_item_set_child(self, phpgtk_arg_object(child));
}

void phpgtk_gtklistitem_set_focusable(zval *handle, zval *focusable)
{
    GtkListItem *self = PHPGTK_ARG_AS(GtkListItem, GTK_TYPE_LIST_ITEM, handle);

    if (self == NULL) {
        return;
    }

    gtk_list_item_set_focusable(self, phpgtk_arg_bool(focusable));
}

void phpgtk_gtklistitem_set_selectable(zval *handle, zval *selectable)
{
    GtkListItem *self = PHPGTK_ARG_AS(GtkListItem, GTK_TYPE_LIST_ITEM, handle);

    if (self == NULL) {
        return;
    }

    gtk_list_item_set_selectable(self, phpgtk_arg_bool(selectable));
}
