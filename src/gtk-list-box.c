#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-list-box.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtklistbox_new(void)
{
    return phpgtk_handle_register(gtk_list_box_new());
}

void phpgtk_gtklistbox_append(zval *handle, zval *child)
{
    GtkListBox *self = PHPGTK_ARG_AS(GtkListBox, GTK_TYPE_LIST_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_list_box_append(self, phpgtk_arg_object(child));
}

void phpgtk_gtklistbox_drag_highlight_row(zval *handle, zval *row)
{
    GtkListBox *self = PHPGTK_ARG_AS(GtkListBox, GTK_TYPE_LIST_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_list_box_drag_highlight_row(self, phpgtk_arg_object(row));
}

void phpgtk_gtklistbox_drag_unhighlight_row(zval *handle)
{
    GtkListBox *self = PHPGTK_ARG_AS(GtkListBox, GTK_TYPE_LIST_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_list_box_drag_unhighlight_row(self);
}

zend_long phpgtk_gtklistbox_get_activate_on_single_click(zval *handle)
{
    GtkListBox *self = PHPGTK_ARG_AS(GtkListBox, GTK_TYPE_LIST_BOX, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_list_box_get_activate_on_single_click(self) ? 1 : 0;
}

zend_long phpgtk_gtklistbox_get_adjustment(zval *handle)
{
    GtkListBox *self = PHPGTK_ARG_AS(GtkListBox, GTK_TYPE_LIST_BOX, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_list_box_get_adjustment(self));
}

zend_long phpgtk_gtklistbox_get_row_at_index(zval *handle, zval *index)
{
    GtkListBox *self = PHPGTK_ARG_AS(GtkListBox, GTK_TYPE_LIST_BOX, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_list_box_get_row_at_index(self, phpgtk_arg_long(index)));
}

zend_long phpgtk_gtklistbox_get_row_at_y(zval *handle, zval *y)
{
    GtkListBox *self = PHPGTK_ARG_AS(GtkListBox, GTK_TYPE_LIST_BOX, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_list_box_get_row_at_y(self, phpgtk_arg_long(y)));
}

zend_long phpgtk_gtklistbox_get_selected_row(zval *handle)
{
    GtkListBox *self = PHPGTK_ARG_AS(GtkListBox, GTK_TYPE_LIST_BOX, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_list_box_get_selected_row(self));
}

void phpgtk_gtklistbox_get_selected_rows(zval *return_value, zval *handle)
{
    GtkListBox *self = PHPGTK_ARG_AS(GtkListBox, GTK_TYPE_LIST_BOX, handle);

    if (self == NULL) {
        array_init(return_value); return;
    }

    phpgtk_ret_object_glist(return_value, gtk_list_box_get_selected_rows(self), TRUE, FALSE);
}

zend_long phpgtk_gtklistbox_get_selection_mode(zval *handle)
{
    GtkListBox *self = PHPGTK_ARG_AS(GtkListBox, GTK_TYPE_LIST_BOX, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_list_box_get_selection_mode(self);
}

zend_long phpgtk_gtklistbox_get_show_separators(zval *handle)
{
    GtkListBox *self = PHPGTK_ARG_AS(GtkListBox, GTK_TYPE_LIST_BOX, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_list_box_get_show_separators(self) ? 1 : 0;
}

zend_long phpgtk_gtklistbox_get_tab_behavior(zval *handle)
{
    GtkListBox *self = PHPGTK_ARG_AS(GtkListBox, GTK_TYPE_LIST_BOX, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_list_box_get_tab_behavior(self);
}

void phpgtk_gtklistbox_insert(zval *handle, zval *child, zval *position)
{
    GtkListBox *self = PHPGTK_ARG_AS(GtkListBox, GTK_TYPE_LIST_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_list_box_insert(self, phpgtk_arg_object(child), phpgtk_arg_long(position));
}

void phpgtk_gtklistbox_invalidate_filter(zval *handle)
{
    GtkListBox *self = PHPGTK_ARG_AS(GtkListBox, GTK_TYPE_LIST_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_list_box_invalidate_filter(self);
}

void phpgtk_gtklistbox_invalidate_headers(zval *handle)
{
    GtkListBox *self = PHPGTK_ARG_AS(GtkListBox, GTK_TYPE_LIST_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_list_box_invalidate_headers(self);
}

void phpgtk_gtklistbox_invalidate_sort(zval *handle)
{
    GtkListBox *self = PHPGTK_ARG_AS(GtkListBox, GTK_TYPE_LIST_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_list_box_invalidate_sort(self);
}

void phpgtk_gtklistbox_prepend(zval *handle, zval *child)
{
    GtkListBox *self = PHPGTK_ARG_AS(GtkListBox, GTK_TYPE_LIST_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_list_box_prepend(self, phpgtk_arg_object(child));
}

void phpgtk_gtklistbox_remove(zval *handle, zval *child)
{
    GtkListBox *self = PHPGTK_ARG_AS(GtkListBox, GTK_TYPE_LIST_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_list_box_remove(self, phpgtk_arg_object(child));
}

void phpgtk_gtklistbox_remove_all(zval *handle)
{
    GtkListBox *self = PHPGTK_ARG_AS(GtkListBox, GTK_TYPE_LIST_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_list_box_remove_all(self);
}

void phpgtk_gtklistbox_select_all(zval *handle)
{
    GtkListBox *self = PHPGTK_ARG_AS(GtkListBox, GTK_TYPE_LIST_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_list_box_select_all(self);
}

void phpgtk_gtklistbox_select_row(zval *handle, zval *row)
{
    GtkListBox *self = PHPGTK_ARG_AS(GtkListBox, GTK_TYPE_LIST_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_list_box_select_row(self, phpgtk_arg_object(row));
}

void phpgtk_gtklistbox_set_activate_on_single_click(zval *handle, zval *single)
{
    GtkListBox *self = PHPGTK_ARG_AS(GtkListBox, GTK_TYPE_LIST_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_list_box_set_activate_on_single_click(self, phpgtk_arg_bool(single));
}

void phpgtk_gtklistbox_set_adjustment(zval *handle, zval *adjustment)
{
    GtkListBox *self = PHPGTK_ARG_AS(GtkListBox, GTK_TYPE_LIST_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_list_box_set_adjustment(self, phpgtk_arg_object(adjustment));
}

void phpgtk_gtklistbox_set_placeholder(zval *handle, zval *placeholder)
{
    GtkListBox *self = PHPGTK_ARG_AS(GtkListBox, GTK_TYPE_LIST_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_list_box_set_placeholder(self, phpgtk_arg_object(placeholder));
}

void phpgtk_gtklistbox_set_selection_mode(zval *handle, zval *mode)
{
    GtkListBox *self = PHPGTK_ARG_AS(GtkListBox, GTK_TYPE_LIST_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_list_box_set_selection_mode(self, (GtkSelectionMode) phpgtk_arg_long(mode));
}

void phpgtk_gtklistbox_set_show_separators(zval *handle, zval *showSeparators)
{
    GtkListBox *self = PHPGTK_ARG_AS(GtkListBox, GTK_TYPE_LIST_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_list_box_set_show_separators(self, phpgtk_arg_bool(showSeparators));
}

void phpgtk_gtklistbox_set_tab_behavior(zval *handle, zval *behavior)
{
    GtkListBox *self = PHPGTK_ARG_AS(GtkListBox, GTK_TYPE_LIST_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_list_box_set_tab_behavior(self, (GtkListTabBehavior) phpgtk_arg_long(behavior));
}

void phpgtk_gtklistbox_unselect_all(zval *handle)
{
    GtkListBox *self = PHPGTK_ARG_AS(GtkListBox, GTK_TYPE_LIST_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_list_box_unselect_all(self);
}

void phpgtk_gtklistbox_unselect_row(zval *handle, zval *row)
{
    GtkListBox *self = PHPGTK_ARG_AS(GtkListBox, GTK_TYPE_LIST_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_list_box_unselect_row(self, phpgtk_arg_object(row));
}
