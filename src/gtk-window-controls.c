#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-window-controls.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkwindowcontrols_new(zval *side)
{
    return phpgtk_handle_register(gtk_window_controls_new((GtkPackType) phpgtk_arg_long(side)));
}

void phpgtk_gtkwindowcontrols_get_decoration_layout(zval *return_value, zval *handle)
{
    GtkWindowControls *self = PHPGTK_ARG_AS(GtkWindowControls, GTK_TYPE_WINDOW_CONTROLS, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_window_controls_get_decoration_layout(self));
}

zend_long phpgtk_gtkwindowcontrols_get_empty(zval *handle)
{
    GtkWindowControls *self = PHPGTK_ARG_AS(GtkWindowControls, GTK_TYPE_WINDOW_CONTROLS, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_window_controls_get_empty(self) ? 1 : 0;
}

zend_long phpgtk_gtkwindowcontrols_get_side(zval *handle)
{
    GtkWindowControls *self = PHPGTK_ARG_AS(GtkWindowControls, GTK_TYPE_WINDOW_CONTROLS, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_window_controls_get_side(self);
}

zend_long phpgtk_gtkwindowcontrols_get_use_native_controls(zval *handle)
{
    GtkWindowControls *self = PHPGTK_ARG_AS(GtkWindowControls, GTK_TYPE_WINDOW_CONTROLS, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_window_controls_get_use_native_controls(self) ? 1 : 0;
}

void phpgtk_gtkwindowcontrols_set_decoration_layout(zval *handle, zval *layout)
{
    GtkWindowControls *self = PHPGTK_ARG_AS(GtkWindowControls, GTK_TYPE_WINDOW_CONTROLS, handle);

    if (self == NULL) {
        return;
    }

    gtk_window_controls_set_decoration_layout(self, phpgtk_arg_string(layout));
}

void phpgtk_gtkwindowcontrols_set_side(zval *handle, zval *side)
{
    GtkWindowControls *self = PHPGTK_ARG_AS(GtkWindowControls, GTK_TYPE_WINDOW_CONTROLS, handle);

    if (self == NULL) {
        return;
    }

    gtk_window_controls_set_side(self, (GtkPackType) phpgtk_arg_long(side));
}

void phpgtk_gtkwindowcontrols_set_use_native_controls(zval *handle, zval *setting)
{
    GtkWindowControls *self = PHPGTK_ARG_AS(GtkWindowControls, GTK_TYPE_WINDOW_CONTROLS, handle);

    if (self == NULL) {
        return;
    }

    gtk_window_controls_set_use_native_controls(self, phpgtk_arg_bool(setting));
}

