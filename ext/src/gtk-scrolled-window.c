#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-scrolled-window.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkscrolledwindow_new(void)
{
    return phpgtk_handle_register(gtk_scrolled_window_new());
}

zend_long phpgtk_gtkscrolledwindow_get_child(zval *handle)
{
    GtkScrolledWindow *self = PHPGTK_ARG_AS(GtkScrolledWindow, GTK_TYPE_SCROLLED_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_scrolled_window_get_child(self));
}

zend_long phpgtk_gtkscrolledwindow_get_hadjustment(zval *handle)
{
    GtkScrolledWindow *self = PHPGTK_ARG_AS(GtkScrolledWindow, GTK_TYPE_SCROLLED_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_scrolled_window_get_hadjustment(self));
}

zend_long phpgtk_gtkscrolledwindow_get_has_frame(zval *handle)
{
    GtkScrolledWindow *self = PHPGTK_ARG_AS(GtkScrolledWindow, GTK_TYPE_SCROLLED_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_scrolled_window_get_has_frame(self) ? 1 : 0;
}

zend_long phpgtk_gtkscrolledwindow_get_hscrollbar(zval *handle)
{
    GtkScrolledWindow *self = PHPGTK_ARG_AS(GtkScrolledWindow, GTK_TYPE_SCROLLED_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_scrolled_window_get_hscrollbar(self));
}

zend_long phpgtk_gtkscrolledwindow_get_kinetic_scrolling(zval *handle)
{
    GtkScrolledWindow *self = PHPGTK_ARG_AS(GtkScrolledWindow, GTK_TYPE_SCROLLED_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_scrolled_window_get_kinetic_scrolling(self) ? 1 : 0;
}

zend_long phpgtk_gtkscrolledwindow_get_max_content_height(zval *handle)
{
    GtkScrolledWindow *self = PHPGTK_ARG_AS(GtkScrolledWindow, GTK_TYPE_SCROLLED_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_scrolled_window_get_max_content_height(self);
}

zend_long phpgtk_gtkscrolledwindow_get_max_content_width(zval *handle)
{
    GtkScrolledWindow *self = PHPGTK_ARG_AS(GtkScrolledWindow, GTK_TYPE_SCROLLED_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_scrolled_window_get_max_content_width(self);
}

zend_long phpgtk_gtkscrolledwindow_get_min_content_height(zval *handle)
{
    GtkScrolledWindow *self = PHPGTK_ARG_AS(GtkScrolledWindow, GTK_TYPE_SCROLLED_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_scrolled_window_get_min_content_height(self);
}

zend_long phpgtk_gtkscrolledwindow_get_min_content_width(zval *handle)
{
    GtkScrolledWindow *self = PHPGTK_ARG_AS(GtkScrolledWindow, GTK_TYPE_SCROLLED_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_scrolled_window_get_min_content_width(self);
}

zend_long phpgtk_gtkscrolledwindow_get_overlay_scrolling(zval *handle)
{
    GtkScrolledWindow *self = PHPGTK_ARG_AS(GtkScrolledWindow, GTK_TYPE_SCROLLED_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_scrolled_window_get_overlay_scrolling(self) ? 1 : 0;
}

zend_long phpgtk_gtkscrolledwindow_get_placement(zval *handle)
{
    GtkScrolledWindow *self = PHPGTK_ARG_AS(GtkScrolledWindow, GTK_TYPE_SCROLLED_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_scrolled_window_get_placement(self);
}

void phpgtk_gtkscrolledwindow_get_policy(zval *return_value, zval *handle)
{
    GtkScrolledWindow *self = PHPGTK_ARG_AS(GtkScrolledWindow, GTK_TYPE_SCROLLED_WINDOW, handle);
    GtkPolicyType hscrollbar_policy = GTK_POLICY_AUTOMATIC;
    GtkPolicyType vscrollbar_policy = GTK_POLICY_AUTOMATIC;

    if (self == NULL) {
        array_init(return_value); return;
    }

    gtk_scrolled_window_get_policy(self, &hscrollbar_policy, &vscrollbar_policy);
    array_init(return_value);
    add_assoc_long(return_value, "hscrollbar_policy", (zend_long) hscrollbar_policy);
    add_assoc_long(return_value, "vscrollbar_policy", (zend_long) vscrollbar_policy);
}

zend_long phpgtk_gtkscrolledwindow_get_propagate_natural_height(zval *handle)
{
    GtkScrolledWindow *self = PHPGTK_ARG_AS(GtkScrolledWindow, GTK_TYPE_SCROLLED_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_scrolled_window_get_propagate_natural_height(self) ? 1 : 0;
}

zend_long phpgtk_gtkscrolledwindow_get_propagate_natural_width(zval *handle)
{
    GtkScrolledWindow *self = PHPGTK_ARG_AS(GtkScrolledWindow, GTK_TYPE_SCROLLED_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_scrolled_window_get_propagate_natural_width(self) ? 1 : 0;
}

zend_long phpgtk_gtkscrolledwindow_get_vadjustment(zval *handle)
{
    GtkScrolledWindow *self = PHPGTK_ARG_AS(GtkScrolledWindow, GTK_TYPE_SCROLLED_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_scrolled_window_get_vadjustment(self));
}

zend_long phpgtk_gtkscrolledwindow_get_vscrollbar(zval *handle)
{
    GtkScrolledWindow *self = PHPGTK_ARG_AS(GtkScrolledWindow, GTK_TYPE_SCROLLED_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_scrolled_window_get_vscrollbar(self));
}

void phpgtk_gtkscrolledwindow_set_child(zval *handle, zval *child)
{
    GtkScrolledWindow *self = PHPGTK_ARG_AS(GtkScrolledWindow, GTK_TYPE_SCROLLED_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_scrolled_window_set_child(self, phpgtk_arg_object(child));
}

void phpgtk_gtkscrolledwindow_set_hadjustment(zval *handle, zval *hadjustment)
{
    GtkScrolledWindow *self = PHPGTK_ARG_AS(GtkScrolledWindow, GTK_TYPE_SCROLLED_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_scrolled_window_set_hadjustment(self, phpgtk_arg_object(hadjustment));
}

void phpgtk_gtkscrolledwindow_set_has_frame(zval *handle, zval *hasFrame)
{
    GtkScrolledWindow *self = PHPGTK_ARG_AS(GtkScrolledWindow, GTK_TYPE_SCROLLED_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_scrolled_window_set_has_frame(self, phpgtk_arg_bool(hasFrame));
}

void phpgtk_gtkscrolledwindow_set_kinetic_scrolling(zval *handle, zval *kineticScrolling)
{
    GtkScrolledWindow *self = PHPGTK_ARG_AS(GtkScrolledWindow, GTK_TYPE_SCROLLED_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_scrolled_window_set_kinetic_scrolling(self, phpgtk_arg_bool(kineticScrolling));
}

void phpgtk_gtkscrolledwindow_set_max_content_height(zval *handle, zval *height)
{
    GtkScrolledWindow *self = PHPGTK_ARG_AS(GtkScrolledWindow, GTK_TYPE_SCROLLED_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_scrolled_window_set_max_content_height(self, phpgtk_arg_long(height));
}

void phpgtk_gtkscrolledwindow_set_max_content_width(zval *handle, zval *width)
{
    GtkScrolledWindow *self = PHPGTK_ARG_AS(GtkScrolledWindow, GTK_TYPE_SCROLLED_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_scrolled_window_set_max_content_width(self, phpgtk_arg_long(width));
}

void phpgtk_gtkscrolledwindow_set_min_content_height(zval *handle, zval *height)
{
    GtkScrolledWindow *self = PHPGTK_ARG_AS(GtkScrolledWindow, GTK_TYPE_SCROLLED_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_scrolled_window_set_min_content_height(self, phpgtk_arg_long(height));
}

void phpgtk_gtkscrolledwindow_set_min_content_width(zval *handle, zval *width)
{
    GtkScrolledWindow *self = PHPGTK_ARG_AS(GtkScrolledWindow, GTK_TYPE_SCROLLED_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_scrolled_window_set_min_content_width(self, phpgtk_arg_long(width));
}

void phpgtk_gtkscrolledwindow_set_overlay_scrolling(zval *handle, zval *overlayScrolling)
{
    GtkScrolledWindow *self = PHPGTK_ARG_AS(GtkScrolledWindow, GTK_TYPE_SCROLLED_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_scrolled_window_set_overlay_scrolling(self, phpgtk_arg_bool(overlayScrolling));
}

void phpgtk_gtkscrolledwindow_set_placement(zval *handle, zval *windowPlacement)
{
    GtkScrolledWindow *self = PHPGTK_ARG_AS(GtkScrolledWindow, GTK_TYPE_SCROLLED_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_scrolled_window_set_placement(self, (GtkCornerType) phpgtk_arg_long(windowPlacement));
}

void phpgtk_gtkscrolledwindow_set_policy(zval *handle, zval *hscrollbarPolicy, zval *vscrollbarPolicy)
{
    GtkScrolledWindow *self = PHPGTK_ARG_AS(GtkScrolledWindow, GTK_TYPE_SCROLLED_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_scrolled_window_set_policy(self, (GtkPolicyType) phpgtk_arg_long(hscrollbarPolicy), (GtkPolicyType) phpgtk_arg_long(vscrollbarPolicy));
}

void phpgtk_gtkscrolledwindow_set_propagate_natural_height(zval *handle, zval *propagate)
{
    GtkScrolledWindow *self = PHPGTK_ARG_AS(GtkScrolledWindow, GTK_TYPE_SCROLLED_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_scrolled_window_set_propagate_natural_height(self, phpgtk_arg_bool(propagate));
}

void phpgtk_gtkscrolledwindow_set_propagate_natural_width(zval *handle, zval *propagate)
{
    GtkScrolledWindow *self = PHPGTK_ARG_AS(GtkScrolledWindow, GTK_TYPE_SCROLLED_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_scrolled_window_set_propagate_natural_width(self, phpgtk_arg_bool(propagate));
}

void phpgtk_gtkscrolledwindow_set_vadjustment(zval *handle, zval *vadjustment)
{
    GtkScrolledWindow *self = PHPGTK_ARG_AS(GtkScrolledWindow, GTK_TYPE_SCROLLED_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_scrolled_window_set_vadjustment(self, phpgtk_arg_object(vadjustment));
}

void phpgtk_gtkscrolledwindow_unset_placement(zval *handle)
{
    GtkScrolledWindow *self = PHPGTK_ARG_AS(GtkScrolledWindow, GTK_TYPE_SCROLLED_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_scrolled_window_unset_placement(self);
}
