#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-list-box-row.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtklistboxrow_new(void)
{
    return phpgtk_handle_register(gtk_list_box_row_new());
}

void phpgtk_gtklistboxrow_changed(zval *handle)
{
    GtkListBoxRow *self = PHPGTK_ARG_AS(GtkListBoxRow, GTK_TYPE_LIST_BOX_ROW, handle);

    if (self == NULL) {
        return;
    }

    gtk_list_box_row_changed(self);
}

zend_long phpgtk_gtklistboxrow_get_activatable(zval *handle)
{
    GtkListBoxRow *self = PHPGTK_ARG_AS(GtkListBoxRow, GTK_TYPE_LIST_BOX_ROW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_list_box_row_get_activatable(self) ? 1 : 0;
}

zend_long phpgtk_gtklistboxrow_get_child(zval *handle)
{
    GtkListBoxRow *self = PHPGTK_ARG_AS(GtkListBoxRow, GTK_TYPE_LIST_BOX_ROW, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_list_box_row_get_child(self));
}

zend_long phpgtk_gtklistboxrow_get_header(zval *handle)
{
    GtkListBoxRow *self = PHPGTK_ARG_AS(GtkListBoxRow, GTK_TYPE_LIST_BOX_ROW, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_list_box_row_get_header(self));
}

zend_long phpgtk_gtklistboxrow_get_index(zval *handle)
{
    GtkListBoxRow *self = PHPGTK_ARG_AS(GtkListBoxRow, GTK_TYPE_LIST_BOX_ROW, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_list_box_row_get_index(self);
}

zend_long phpgtk_gtklistboxrow_get_selectable(zval *handle)
{
    GtkListBoxRow *self = PHPGTK_ARG_AS(GtkListBoxRow, GTK_TYPE_LIST_BOX_ROW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_list_box_row_get_selectable(self) ? 1 : 0;
}

zend_long phpgtk_gtklistboxrow_is_selected(zval *handle)
{
    GtkListBoxRow *self = PHPGTK_ARG_AS(GtkListBoxRow, GTK_TYPE_LIST_BOX_ROW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_list_box_row_is_selected(self) ? 1 : 0;
}

void phpgtk_gtklistboxrow_set_activatable(zval *handle, zval *activatable)
{
    GtkListBoxRow *self = PHPGTK_ARG_AS(GtkListBoxRow, GTK_TYPE_LIST_BOX_ROW, handle);

    if (self == NULL) {
        return;
    }

    gtk_list_box_row_set_activatable(self, phpgtk_arg_bool(activatable));
}

void phpgtk_gtklistboxrow_set_child(zval *handle, zval *child)
{
    GtkListBoxRow *self = PHPGTK_ARG_AS(GtkListBoxRow, GTK_TYPE_LIST_BOX_ROW, handle);

    if (self == NULL) {
        return;
    }

    gtk_list_box_row_set_child(self, phpgtk_arg_object(child));
}

void phpgtk_gtklistboxrow_set_header(zval *handle, zval *header)
{
    GtkListBoxRow *self = PHPGTK_ARG_AS(GtkListBoxRow, GTK_TYPE_LIST_BOX_ROW, handle);

    if (self == NULL) {
        return;
    }

    gtk_list_box_row_set_header(self, phpgtk_arg_object(header));
}

void phpgtk_gtklistboxrow_set_selectable(zval *handle, zval *selectable)
{
    GtkListBoxRow *self = PHPGTK_ARG_AS(GtkListBoxRow, GTK_TYPE_LIST_BOX_ROW, handle);

    if (self == NULL) {
        return;
    }

    gtk_list_box_row_set_selectable(self, phpgtk_arg_bool(selectable));
}
