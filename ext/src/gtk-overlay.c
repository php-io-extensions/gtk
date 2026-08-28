#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-overlay.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkoverlay_new(void)
{
    return phpgtk_handle_register(gtk_overlay_new());
}

void phpgtk_gtkoverlay_add_overlay(zval *handle, zval *widget)
{
    GtkOverlay *self = PHPGTK_ARG_AS(GtkOverlay, GTK_TYPE_OVERLAY, handle);

    if (self == NULL) {
        return;
    }

    gtk_overlay_add_overlay(self, phpgtk_arg_object(widget));
}

zend_long phpgtk_gtkoverlay_get_child(zval *handle)
{
    GtkOverlay *self = PHPGTK_ARG_AS(GtkOverlay, GTK_TYPE_OVERLAY, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_overlay_get_child(self));
}

zend_long phpgtk_gtkoverlay_get_clip_overlay(zval *handle, zval *widget)
{
    GtkOverlay *self = PHPGTK_ARG_AS(GtkOverlay, GTK_TYPE_OVERLAY, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_overlay_get_clip_overlay(self, phpgtk_arg_object(widget)) ? 1 : 0;
}

zend_long phpgtk_gtkoverlay_get_measure_overlay(zval *handle, zval *widget)
{
    GtkOverlay *self = PHPGTK_ARG_AS(GtkOverlay, GTK_TYPE_OVERLAY, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_overlay_get_measure_overlay(self, phpgtk_arg_object(widget)) ? 1 : 0;
}

void phpgtk_gtkoverlay_remove_overlay(zval *handle, zval *widget)
{
    GtkOverlay *self = PHPGTK_ARG_AS(GtkOverlay, GTK_TYPE_OVERLAY, handle);

    if (self == NULL) {
        return;
    }

    gtk_overlay_remove_overlay(self, phpgtk_arg_object(widget));
}

void phpgtk_gtkoverlay_set_child(zval *handle, zval *child)
{
    GtkOverlay *self = PHPGTK_ARG_AS(GtkOverlay, GTK_TYPE_OVERLAY, handle);

    if (self == NULL) {
        return;
    }

    gtk_overlay_set_child(self, phpgtk_arg_object(child));
}

void phpgtk_gtkoverlay_set_clip_overlay(zval *handle, zval *widget, zval *clipOverlay)
{
    GtkOverlay *self = PHPGTK_ARG_AS(GtkOverlay, GTK_TYPE_OVERLAY, handle);

    if (self == NULL) {
        return;
    }

    gtk_overlay_set_clip_overlay(self, phpgtk_arg_object(widget), phpgtk_arg_bool(clipOverlay));
}

void phpgtk_gtkoverlay_set_measure_overlay(zval *handle, zval *widget, zval *measure)
{
    GtkOverlay *self = PHPGTK_ARG_AS(GtkOverlay, GTK_TYPE_OVERLAY, handle);

    if (self == NULL) {
        return;
    }

    gtk_overlay_set_measure_overlay(self, phpgtk_arg_object(widget), phpgtk_arg_bool(measure));
}
