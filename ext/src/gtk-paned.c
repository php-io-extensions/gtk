#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-paned.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkpaned_new(zval *orientation)
{
    return phpgtk_handle_register(gtk_paned_new((GtkOrientation) phpgtk_arg_long(orientation)));
}

zend_long phpgtk_gtkpaned_get_end_child(zval *handle)
{
    GtkPaned *self = PHPGTK_ARG_AS(GtkPaned, GTK_TYPE_PANED, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_paned_get_end_child(self));
}

zend_long phpgtk_gtkpaned_get_position(zval *handle)
{
    GtkPaned *self = PHPGTK_ARG_AS(GtkPaned, GTK_TYPE_PANED, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_paned_get_position(self);
}

zend_long phpgtk_gtkpaned_get_resize_end_child(zval *handle)
{
    GtkPaned *self = PHPGTK_ARG_AS(GtkPaned, GTK_TYPE_PANED, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_paned_get_resize_end_child(self) ? 1 : 0;
}

zend_long phpgtk_gtkpaned_get_resize_start_child(zval *handle)
{
    GtkPaned *self = PHPGTK_ARG_AS(GtkPaned, GTK_TYPE_PANED, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_paned_get_resize_start_child(self) ? 1 : 0;
}

zend_long phpgtk_gtkpaned_get_shrink_end_child(zval *handle)
{
    GtkPaned *self = PHPGTK_ARG_AS(GtkPaned, GTK_TYPE_PANED, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_paned_get_shrink_end_child(self) ? 1 : 0;
}

zend_long phpgtk_gtkpaned_get_shrink_start_child(zval *handle)
{
    GtkPaned *self = PHPGTK_ARG_AS(GtkPaned, GTK_TYPE_PANED, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_paned_get_shrink_start_child(self) ? 1 : 0;
}

zend_long phpgtk_gtkpaned_get_start_child(zval *handle)
{
    GtkPaned *self = PHPGTK_ARG_AS(GtkPaned, GTK_TYPE_PANED, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_paned_get_start_child(self));
}

zend_long phpgtk_gtkpaned_get_wide_handle(zval *handle)
{
    GtkPaned *self = PHPGTK_ARG_AS(GtkPaned, GTK_TYPE_PANED, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_paned_get_wide_handle(self) ? 1 : 0;
}

void phpgtk_gtkpaned_set_end_child(zval *handle, zval *child)
{
    GtkPaned *self = PHPGTK_ARG_AS(GtkPaned, GTK_TYPE_PANED, handle);

    if (self == NULL) {
        return;
    }

    gtk_paned_set_end_child(self, phpgtk_arg_object(child));
}

void phpgtk_gtkpaned_set_position(zval *handle, zval *position)
{
    GtkPaned *self = PHPGTK_ARG_AS(GtkPaned, GTK_TYPE_PANED, handle);

    if (self == NULL) {
        return;
    }

    gtk_paned_set_position(self, phpgtk_arg_long(position));
}

void phpgtk_gtkpaned_set_resize_end_child(zval *handle, zval *resize)
{
    GtkPaned *self = PHPGTK_ARG_AS(GtkPaned, GTK_TYPE_PANED, handle);

    if (self == NULL) {
        return;
    }

    gtk_paned_set_resize_end_child(self, phpgtk_arg_bool(resize));
}

void phpgtk_gtkpaned_set_resize_start_child(zval *handle, zval *resize)
{
    GtkPaned *self = PHPGTK_ARG_AS(GtkPaned, GTK_TYPE_PANED, handle);

    if (self == NULL) {
        return;
    }

    gtk_paned_set_resize_start_child(self, phpgtk_arg_bool(resize));
}

void phpgtk_gtkpaned_set_shrink_end_child(zval *handle, zval *resize)
{
    GtkPaned *self = PHPGTK_ARG_AS(GtkPaned, GTK_TYPE_PANED, handle);

    if (self == NULL) {
        return;
    }

    gtk_paned_set_shrink_end_child(self, phpgtk_arg_bool(resize));
}

void phpgtk_gtkpaned_set_shrink_start_child(zval *handle, zval *resize)
{
    GtkPaned *self = PHPGTK_ARG_AS(GtkPaned, GTK_TYPE_PANED, handle);

    if (self == NULL) {
        return;
    }

    gtk_paned_set_shrink_start_child(self, phpgtk_arg_bool(resize));
}

void phpgtk_gtkpaned_set_start_child(zval *handle, zval *child)
{
    GtkPaned *self = PHPGTK_ARG_AS(GtkPaned, GTK_TYPE_PANED, handle);

    if (self == NULL) {
        return;
    }

    gtk_paned_set_start_child(self, phpgtk_arg_object(child));
}

void phpgtk_gtkpaned_set_wide_handle(zval *handle, zval *wide)
{
    GtkPaned *self = PHPGTK_ARG_AS(GtkPaned, GTK_TYPE_PANED, handle);

    if (self == NULL) {
        return;
    }

    gtk_paned_set_wide_handle(self, phpgtk_arg_bool(wide));
}
