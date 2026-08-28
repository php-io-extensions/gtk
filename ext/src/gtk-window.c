#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-window.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkwindow_new(void)
{
    return phpgtk_handle_register(gtk_window_new());
}

void phpgtk_gtkwindow_get_default_icon_name(zval *return_value)
{
    phpgtk_ret_string(return_value, gtk_window_get_default_icon_name());
}

zend_long phpgtk_gtkwindow_get_toplevels(void)
{
    return phpgtk_handle_register(gtk_window_get_toplevels());
}

void phpgtk_gtkwindow_list_toplevels(zval *return_value)
{
    phpgtk_ret_object_glist(return_value, gtk_window_list_toplevels(), TRUE, FALSE);
}

void phpgtk_gtkwindow_set_auto_startup_notification(zval *setting)
{
    gtk_window_set_auto_startup_notification(phpgtk_arg_bool(setting));
}

void phpgtk_gtkwindow_set_default_icon_name(zval *name)
{
    gtk_window_set_default_icon_name(phpgtk_arg_string(name));
}

void phpgtk_gtkwindow_set_interactive_debugging(zval *enable)
{
    gtk_window_set_interactive_debugging(phpgtk_arg_bool(enable));
}

void phpgtk_gtkwindow_close(zval *handle)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_window_close(self);
}

void phpgtk_gtkwindow_destroy(zval *handle)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_window_destroy(self);
}

void phpgtk_gtkwindow_fullscreen(zval *handle)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_window_fullscreen(self);
}

void phpgtk_gtkwindow_fullscreen_on_monitor(zval *handle, zval *monitor)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_window_fullscreen_on_monitor(self, phpgtk_arg_object(monitor));
}

zend_long phpgtk_gtkwindow_get_application(zval *handle)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_window_get_application(self));
}

zend_long phpgtk_gtkwindow_get_child(zval *handle)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_window_get_child(self));
}

zend_long phpgtk_gtkwindow_get_decorated(zval *handle)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_window_get_decorated(self) ? 1 : 0;
}

void phpgtk_gtkwindow_get_default_size(zval *return_value, zval *handle)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        array_init(return_value); return;
    }

    int width = 0;
    int height = 0;

    gtk_window_get_default_size(self, &width, &height);
    array_init(return_value);
    add_assoc_long(return_value, "width", width);
    add_assoc_long(return_value, "height", height);
}

zend_long phpgtk_gtkwindow_get_default_widget(zval *handle)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_window_get_default_widget(self));
}

zend_long phpgtk_gtkwindow_get_deletable(zval *handle)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_window_get_deletable(self) ? 1 : 0;
}

zend_long phpgtk_gtkwindow_get_destroy_with_parent(zval *handle)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_window_get_destroy_with_parent(self) ? 1 : 0;
}

zend_long phpgtk_gtkwindow_get_focus(zval *handle)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_window_get_focus(self));
}

zend_long phpgtk_gtkwindow_get_focus_visible(zval *handle)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_window_get_focus_visible(self) ? 1 : 0;
}

zend_long phpgtk_gtkwindow_get_group(zval *handle)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_window_get_group(self));
}

zend_long phpgtk_gtkwindow_get_handle_menubar_accel(zval *handle)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_window_get_handle_menubar_accel(self) ? 1 : 0;
}

zend_long phpgtk_gtkwindow_get_hide_on_close(zval *handle)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_window_get_hide_on_close(self) ? 1 : 0;
}

void phpgtk_gtkwindow_get_icon_name(zval *return_value, zval *handle)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_window_get_icon_name(self));
}

zend_long phpgtk_gtkwindow_get_mnemonics_visible(zval *handle)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_window_get_mnemonics_visible(self) ? 1 : 0;
}

zend_long phpgtk_gtkwindow_get_modal(zval *handle)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_window_get_modal(self) ? 1 : 0;
}

zend_long phpgtk_gtkwindow_get_resizable(zval *handle)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_window_get_resizable(self) ? 1 : 0;
}

void phpgtk_gtkwindow_get_title(zval *return_value, zval *handle)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_window_get_title(self));
}

zend_long phpgtk_gtkwindow_get_titlebar(zval *handle)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_window_get_titlebar(self));
}

zend_long phpgtk_gtkwindow_get_transient_for(zval *handle)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_window_get_transient_for(self));
}

zend_long phpgtk_gtkwindow_has_group(zval *handle)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_window_has_group(self) ? 1 : 0;
}

zend_long phpgtk_gtkwindow_is_active(zval *handle)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_window_is_active(self) ? 1 : 0;
}

zend_long phpgtk_gtkwindow_is_fullscreen(zval *handle)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_window_is_fullscreen(self) ? 1 : 0;
}

zend_long phpgtk_gtkwindow_is_maximized(zval *handle)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_window_is_maximized(self) ? 1 : 0;
}

zend_long phpgtk_gtkwindow_is_suspended(zval *handle)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_window_is_suspended(self) ? 1 : 0;
}

void phpgtk_gtkwindow_maximize(zval *handle)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_window_maximize(self);
}

void phpgtk_gtkwindow_minimize(zval *handle)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_window_minimize(self);
}

void phpgtk_gtkwindow_present(zval *handle)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_window_present(self);
}

void phpgtk_gtkwindow_set_application(zval *handle, zval *application)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_window_set_application(self, phpgtk_arg_object(application));
}

void phpgtk_gtkwindow_set_child(zval *handle, zval *child)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_window_set_child(self, phpgtk_arg_object(child));
}

void phpgtk_gtkwindow_set_decorated(zval *handle, zval *setting)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_window_set_decorated(self, phpgtk_arg_bool(setting));
}

void phpgtk_gtkwindow_set_default_size(zval *handle, zval *width, zval *height)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_window_set_default_size(self, phpgtk_arg_long(width), phpgtk_arg_long(height));
}

void phpgtk_gtkwindow_set_default_widget(zval *handle, zval *defaultWidget)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_window_set_default_widget(self, phpgtk_arg_object(defaultWidget));
}

void phpgtk_gtkwindow_set_deletable(zval *handle, zval *setting)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_window_set_deletable(self, phpgtk_arg_bool(setting));
}

void phpgtk_gtkwindow_set_destroy_with_parent(zval *handle, zval *setting)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_window_set_destroy_with_parent(self, phpgtk_arg_bool(setting));
}

void phpgtk_gtkwindow_set_display(zval *handle, zval *display)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_window_set_display(self, phpgtk_arg_object(display));
}

void phpgtk_gtkwindow_set_focus(zval *handle, zval *focus)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_window_set_focus(self, phpgtk_arg_object(focus));
}

void phpgtk_gtkwindow_set_focus_visible(zval *handle, zval *setting)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_window_set_focus_visible(self, phpgtk_arg_bool(setting));
}

void phpgtk_gtkwindow_set_handle_menubar_accel(zval *handle, zval *handleMenubarAccel)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_window_set_handle_menubar_accel(self, phpgtk_arg_bool(handleMenubarAccel));
}

void phpgtk_gtkwindow_set_hide_on_close(zval *handle, zval *setting)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_window_set_hide_on_close(self, phpgtk_arg_bool(setting));
}

void phpgtk_gtkwindow_set_icon_name(zval *handle, zval *name)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_window_set_icon_name(self, phpgtk_arg_string(name));
}

void phpgtk_gtkwindow_set_mnemonics_visible(zval *handle, zval *setting)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_window_set_mnemonics_visible(self, phpgtk_arg_bool(setting));
}

void phpgtk_gtkwindow_set_modal(zval *handle, zval *modal)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_window_set_modal(self, phpgtk_arg_bool(modal));
}

void phpgtk_gtkwindow_set_resizable(zval *handle, zval *resizable)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_window_set_resizable(self, phpgtk_arg_bool(resizable));
}

void phpgtk_gtkwindow_set_startup_id(zval *handle, zval *startupId)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_window_set_startup_id(self, phpgtk_arg_string(startupId));
}

void phpgtk_gtkwindow_set_title(zval *handle, zval *title)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_window_set_title(self, phpgtk_arg_string(title));
}

void phpgtk_gtkwindow_set_titlebar(zval *handle, zval *titlebar)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_window_set_titlebar(self, phpgtk_arg_object(titlebar));
}

void phpgtk_gtkwindow_set_transient_for(zval *handle, zval *parent)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_window_set_transient_for(self, phpgtk_arg_object(parent));
}

void phpgtk_gtkwindow_unfullscreen(zval *handle)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_window_unfullscreen(self);
}

void phpgtk_gtkwindow_unmaximize(zval *handle)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_window_unmaximize(self);
}

void phpgtk_gtkwindow_unminimize(zval *handle)
{
    GtkWindow *self = PHPGTK_ARG_AS(GtkWindow, GTK_TYPE_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_window_unminimize(self);
}
