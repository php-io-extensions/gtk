#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-flow-box.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkflowbox_new(void)
{
    return phpgtk_handle_register(gtk_flow_box_new());
}

void phpgtk_gtkflowbox_append(zval *handle, zval *child)
{
    GtkFlowBox *self = PHPGTK_ARG_AS(GtkFlowBox, GTK_TYPE_FLOW_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_flow_box_append(self, phpgtk_arg_object(child));
}

zend_long phpgtk_gtkflowbox_get_activate_on_single_click(zval *handle)
{
    GtkFlowBox *self = PHPGTK_ARG_AS(GtkFlowBox, GTK_TYPE_FLOW_BOX, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_flow_box_get_activate_on_single_click(self) ? 1 : 0;
}

zend_long phpgtk_gtkflowbox_get_child_at_index(zval *handle, zval *idx)
{
    GtkFlowBox *self = PHPGTK_ARG_AS(GtkFlowBox, GTK_TYPE_FLOW_BOX, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_flow_box_get_child_at_index(self, phpgtk_arg_long(idx)));
}

zend_long phpgtk_gtkflowbox_get_child_at_pos(zval *handle, zval *x, zval *y)
{
    GtkFlowBox *self = PHPGTK_ARG_AS(GtkFlowBox, GTK_TYPE_FLOW_BOX, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_flow_box_get_child_at_pos(self, phpgtk_arg_long(x), phpgtk_arg_long(y)));
}

zend_long phpgtk_gtkflowbox_get_column_spacing(zval *handle)
{
    GtkFlowBox *self = PHPGTK_ARG_AS(GtkFlowBox, GTK_TYPE_FLOW_BOX, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_flow_box_get_column_spacing(self);
}

zend_long phpgtk_gtkflowbox_get_homogeneous(zval *handle)
{
    GtkFlowBox *self = PHPGTK_ARG_AS(GtkFlowBox, GTK_TYPE_FLOW_BOX, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_flow_box_get_homogeneous(self) ? 1 : 0;
}

zend_long phpgtk_gtkflowbox_get_max_children_per_line(zval *handle)
{
    GtkFlowBox *self = PHPGTK_ARG_AS(GtkFlowBox, GTK_TYPE_FLOW_BOX, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_flow_box_get_max_children_per_line(self);
}

zend_long phpgtk_gtkflowbox_get_min_children_per_line(zval *handle)
{
    GtkFlowBox *self = PHPGTK_ARG_AS(GtkFlowBox, GTK_TYPE_FLOW_BOX, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_flow_box_get_min_children_per_line(self);
}

zend_long phpgtk_gtkflowbox_get_row_spacing(zval *handle)
{
    GtkFlowBox *self = PHPGTK_ARG_AS(GtkFlowBox, GTK_TYPE_FLOW_BOX, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_flow_box_get_row_spacing(self);
}

void phpgtk_gtkflowbox_get_selected_children(zval *return_value, zval *handle)
{
    GtkFlowBox *self = PHPGTK_ARG_AS(GtkFlowBox, GTK_TYPE_FLOW_BOX, handle);

    if (self == NULL) {
        array_init(return_value); return;
    }

    phpgtk_ret_object_glist(return_value, gtk_flow_box_get_selected_children(self), TRUE, FALSE);
}

zend_long phpgtk_gtkflowbox_get_selection_mode(zval *handle)
{
    GtkFlowBox *self = PHPGTK_ARG_AS(GtkFlowBox, GTK_TYPE_FLOW_BOX, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_flow_box_get_selection_mode(self);
}

void phpgtk_gtkflowbox_insert(zval *handle, zval *widget, zval *position)
{
    GtkFlowBox *self = PHPGTK_ARG_AS(GtkFlowBox, GTK_TYPE_FLOW_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_flow_box_insert(self, phpgtk_arg_object(widget), phpgtk_arg_long(position));
}

void phpgtk_gtkflowbox_invalidate_filter(zval *handle)
{
    GtkFlowBox *self = PHPGTK_ARG_AS(GtkFlowBox, GTK_TYPE_FLOW_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_flow_box_invalidate_filter(self);
}

void phpgtk_gtkflowbox_invalidate_sort(zval *handle)
{
    GtkFlowBox *self = PHPGTK_ARG_AS(GtkFlowBox, GTK_TYPE_FLOW_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_flow_box_invalidate_sort(self);
}

void phpgtk_gtkflowbox_prepend(zval *handle, zval *child)
{
    GtkFlowBox *self = PHPGTK_ARG_AS(GtkFlowBox, GTK_TYPE_FLOW_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_flow_box_prepend(self, phpgtk_arg_object(child));
}

void phpgtk_gtkflowbox_remove(zval *handle, zval *widget)
{
    GtkFlowBox *self = PHPGTK_ARG_AS(GtkFlowBox, GTK_TYPE_FLOW_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_flow_box_remove(self, phpgtk_arg_object(widget));
}

void phpgtk_gtkflowbox_remove_all(zval *handle)
{
    GtkFlowBox *self = PHPGTK_ARG_AS(GtkFlowBox, GTK_TYPE_FLOW_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_flow_box_remove_all(self);
}

void phpgtk_gtkflowbox_select_all(zval *handle)
{
    GtkFlowBox *self = PHPGTK_ARG_AS(GtkFlowBox, GTK_TYPE_FLOW_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_flow_box_select_all(self);
}

void phpgtk_gtkflowbox_select_child(zval *handle, zval *child)
{
    GtkFlowBox *self = PHPGTK_ARG_AS(GtkFlowBox, GTK_TYPE_FLOW_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_flow_box_select_child(self, phpgtk_arg_object(child));
}

void phpgtk_gtkflowbox_set_activate_on_single_click(zval *handle, zval *single)
{
    GtkFlowBox *self = PHPGTK_ARG_AS(GtkFlowBox, GTK_TYPE_FLOW_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_flow_box_set_activate_on_single_click(self, phpgtk_arg_bool(single));
}

void phpgtk_gtkflowbox_set_column_spacing(zval *handle, zval *spacing)
{
    GtkFlowBox *self = PHPGTK_ARG_AS(GtkFlowBox, GTK_TYPE_FLOW_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_flow_box_set_column_spacing(self, (guint) phpgtk_arg_long(spacing));
}

void phpgtk_gtkflowbox_set_hadjustment(zval *handle, zval *adjustment)
{
    GtkFlowBox *self = PHPGTK_ARG_AS(GtkFlowBox, GTK_TYPE_FLOW_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_flow_box_set_hadjustment(self, phpgtk_arg_object(adjustment));
}

void phpgtk_gtkflowbox_set_homogeneous(zval *handle, zval *homogeneous)
{
    GtkFlowBox *self = PHPGTK_ARG_AS(GtkFlowBox, GTK_TYPE_FLOW_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_flow_box_set_homogeneous(self, phpgtk_arg_bool(homogeneous));
}

void phpgtk_gtkflowbox_set_max_children_per_line(zval *handle, zval *nChildren)
{
    GtkFlowBox *self = PHPGTK_ARG_AS(GtkFlowBox, GTK_TYPE_FLOW_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_flow_box_set_max_children_per_line(self, (guint) phpgtk_arg_long(nChildren));
}

void phpgtk_gtkflowbox_set_min_children_per_line(zval *handle, zval *nChildren)
{
    GtkFlowBox *self = PHPGTK_ARG_AS(GtkFlowBox, GTK_TYPE_FLOW_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_flow_box_set_min_children_per_line(self, (guint) phpgtk_arg_long(nChildren));
}

void phpgtk_gtkflowbox_set_row_spacing(zval *handle, zval *spacing)
{
    GtkFlowBox *self = PHPGTK_ARG_AS(GtkFlowBox, GTK_TYPE_FLOW_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_flow_box_set_row_spacing(self, (guint) phpgtk_arg_long(spacing));
}

void phpgtk_gtkflowbox_set_selection_mode(zval *handle, zval *mode)
{
    GtkFlowBox *self = PHPGTK_ARG_AS(GtkFlowBox, GTK_TYPE_FLOW_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_flow_box_set_selection_mode(self, (GtkSelectionMode) phpgtk_arg_long(mode));
}

void phpgtk_gtkflowbox_set_vadjustment(zval *handle, zval *adjustment)
{
    GtkFlowBox *self = PHPGTK_ARG_AS(GtkFlowBox, GTK_TYPE_FLOW_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_flow_box_set_vadjustment(self, phpgtk_arg_object(adjustment));
}

void phpgtk_gtkflowbox_unselect_all(zval *handle)
{
    GtkFlowBox *self = PHPGTK_ARG_AS(GtkFlowBox, GTK_TYPE_FLOW_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_flow_box_unselect_all(self);
}

void phpgtk_gtkflowbox_unselect_child(zval *handle, zval *child)
{
    GtkFlowBox *self = PHPGTK_ARG_AS(GtkFlowBox, GTK_TYPE_FLOW_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_flow_box_unselect_child(self, phpgtk_arg_object(child));
}
