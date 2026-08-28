#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-viewport.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkviewport_new(zval *hadjustment, zval *vadjustment)
{
    return phpgtk_handle_register(gtk_viewport_new(phpgtk_arg_object(hadjustment), phpgtk_arg_object(vadjustment)));
}

zend_long phpgtk_gtkviewport_get_child(zval *handle)
{
    GtkViewport *self = PHPGTK_ARG_AS(GtkViewport, GTK_TYPE_VIEWPORT, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_viewport_get_child(self));
}

zend_long phpgtk_gtkviewport_get_scroll_to_focus(zval *handle)
{
    GtkViewport *self = PHPGTK_ARG_AS(GtkViewport, GTK_TYPE_VIEWPORT, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_viewport_get_scroll_to_focus(self) ? 1 : 0;
}

void phpgtk_gtkviewport_set_child(zval *handle, zval *child)
{
    GtkViewport *self = PHPGTK_ARG_AS(GtkViewport, GTK_TYPE_VIEWPORT, handle);

    if (self == NULL) {
        return;
    }

    gtk_viewport_set_child(self, phpgtk_arg_object(child));
}

void phpgtk_gtkviewport_set_scroll_to_focus(zval *handle, zval *scrollToFocus)
{
    GtkViewport *self = PHPGTK_ARG_AS(GtkViewport, GTK_TYPE_VIEWPORT, handle);

    if (self == NULL) {
        return;
    }

    gtk_viewport_set_scroll_to_focus(self, phpgtk_arg_bool(scrollToFocus));
}
