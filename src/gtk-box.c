#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-box.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkbox_new(zval *orientation, zval *spacing)
{
    return phpgtk_handle_register(gtk_box_new((GtkOrientation) phpgtk_arg_long(orientation), phpgtk_arg_long(spacing)));
}

void phpgtk_gtkbox_append(zval *handle, zval *child)
{
    GtkBox *self = PHPGTK_ARG_AS(GtkBox, GTK_TYPE_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_box_append(self, phpgtk_arg_object(child));
}

zend_long phpgtk_gtkbox_get_baseline_child(zval *handle)
{
    GtkBox *self = PHPGTK_ARG_AS(GtkBox, GTK_TYPE_BOX, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_box_get_baseline_child(self);
}

zend_long phpgtk_gtkbox_get_baseline_position(zval *handle)
{
    GtkBox *self = PHPGTK_ARG_AS(GtkBox, GTK_TYPE_BOX, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_box_get_baseline_position(self);
}

zend_long phpgtk_gtkbox_get_homogeneous(zval *handle)
{
    GtkBox *self = PHPGTK_ARG_AS(GtkBox, GTK_TYPE_BOX, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_box_get_homogeneous(self) ? 1 : 0;
}

zend_long phpgtk_gtkbox_get_spacing(zval *handle)
{
    GtkBox *self = PHPGTK_ARG_AS(GtkBox, GTK_TYPE_BOX, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_box_get_spacing(self);
}

void phpgtk_gtkbox_insert_child_after(zval *handle, zval *child, zval *sibling)
{
    GtkBox *self = PHPGTK_ARG_AS(GtkBox, GTK_TYPE_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_box_insert_child_after(self, phpgtk_arg_object(child), phpgtk_arg_object(sibling));
}

void phpgtk_gtkbox_prepend(zval *handle, zval *child)
{
    GtkBox *self = PHPGTK_ARG_AS(GtkBox, GTK_TYPE_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_box_prepend(self, phpgtk_arg_object(child));
}

void phpgtk_gtkbox_remove(zval *handle, zval *child)
{
    GtkBox *self = PHPGTK_ARG_AS(GtkBox, GTK_TYPE_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_box_remove(self, phpgtk_arg_object(child));
}

void phpgtk_gtkbox_reorder_child_after(zval *handle, zval *child, zval *sibling)
{
    GtkBox *self = PHPGTK_ARG_AS(GtkBox, GTK_TYPE_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_box_reorder_child_after(self, phpgtk_arg_object(child), phpgtk_arg_object(sibling));
}

void phpgtk_gtkbox_set_baseline_child(zval *handle, zval *child)
{
    GtkBox *self = PHPGTK_ARG_AS(GtkBox, GTK_TYPE_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_box_set_baseline_child(self, phpgtk_arg_long(child));
}

void phpgtk_gtkbox_set_baseline_position(zval *handle, zval *position)
{
    GtkBox *self = PHPGTK_ARG_AS(GtkBox, GTK_TYPE_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_box_set_baseline_position(self, (GtkBaselinePosition) phpgtk_arg_long(position));
}

void phpgtk_gtkbox_set_homogeneous(zval *handle, zval *homogeneous)
{
    GtkBox *self = PHPGTK_ARG_AS(GtkBox, GTK_TYPE_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_box_set_homogeneous(self, phpgtk_arg_bool(homogeneous));
}

void phpgtk_gtkbox_set_spacing(zval *handle, zval *spacing)
{
    GtkBox *self = PHPGTK_ARG_AS(GtkBox, GTK_TYPE_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_box_set_spacing(self, phpgtk_arg_long(spacing));
}
