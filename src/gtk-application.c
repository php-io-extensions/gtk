#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-application.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkapplication_new(zval *applicationId, zval *flags)
{
    return phpgtk_handle_register_take(gtk_application_new(phpgtk_arg_string(applicationId), (GApplicationFlags) phpgtk_arg_long(flags)));
}

void phpgtk_gtkapplication_add_window(zval *handle, zval *window)
{
    GtkApplication *self = PHPGTK_ARG_AS(GtkApplication, GTK_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return;
    }

    gtk_application_add_window(self, phpgtk_arg_object(window));
}

void phpgtk_gtkapplication_get_accels_for_action(zval *return_value, zval *handle, zval *detailedActionName)
{
    GtkApplication *self = PHPGTK_ARG_AS(GtkApplication, GTK_TYPE_APPLICATION, handle);

    if (self == NULL) {
        array_init(return_value); return;
    }

    phpgtk_ret_strv_take(return_value, gtk_application_get_accels_for_action(self, phpgtk_arg_string(detailedActionName)));
}

void phpgtk_gtkapplication_get_actions_for_accel(zval *return_value, zval *handle, zval *accel)
{
    GtkApplication *self = PHPGTK_ARG_AS(GtkApplication, GTK_TYPE_APPLICATION, handle);

    if (self == NULL) {
        array_init(return_value); return;
    }

    phpgtk_ret_strv_take(return_value, gtk_application_get_actions_for_accel(self, phpgtk_arg_string(accel)));
}

zend_long phpgtk_gtkapplication_get_active_window(zval *handle)
{
    GtkApplication *self = PHPGTK_ARG_AS(GtkApplication, GTK_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_application_get_active_window(self));
}

zend_long phpgtk_gtkapplication_get_menu_by_id(zval *handle, zval *id)
{
    GtkApplication *self = PHPGTK_ARG_AS(GtkApplication, GTK_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_application_get_menu_by_id(self, phpgtk_arg_string(id)));
}

zend_long phpgtk_gtkapplication_get_menubar(zval *handle)
{
    GtkApplication *self = PHPGTK_ARG_AS(GtkApplication, GTK_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_application_get_menubar(self));
}

zend_long phpgtk_gtkapplication_get_window_by_id(zval *handle, zval *id)
{
    GtkApplication *self = PHPGTK_ARG_AS(GtkApplication, GTK_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_application_get_window_by_id(self, (guint) phpgtk_arg_long(id)));
}

void phpgtk_gtkapplication_get_windows(zval *return_value, zval *handle)
{
    GtkApplication *self = PHPGTK_ARG_AS(GtkApplication, GTK_TYPE_APPLICATION, handle);

    if (self == NULL) {
        array_init(return_value); return;
    }

    phpgtk_ret_object_glist(return_value, gtk_application_get_windows(self), FALSE, FALSE);
}

zend_long phpgtk_gtkapplication_inhibit(zval *handle, zval *window, zval *flags, zval *reason)
{
    GtkApplication *self = PHPGTK_ARG_AS(GtkApplication, GTK_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_application_inhibit(self, phpgtk_arg_object(window), (GtkApplicationInhibitFlags) phpgtk_arg_long(flags), phpgtk_arg_string(reason));
}

void phpgtk_gtkapplication_list_action_descriptions(zval *return_value, zval *handle)
{
    GtkApplication *self = PHPGTK_ARG_AS(GtkApplication, GTK_TYPE_APPLICATION, handle);

    if (self == NULL) {
        array_init(return_value); return;
    }

    phpgtk_ret_strv_take(return_value, gtk_application_list_action_descriptions(self));
}

void phpgtk_gtkapplication_remove_window(zval *handle, zval *window)
{
    GtkApplication *self = PHPGTK_ARG_AS(GtkApplication, GTK_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return;
    }

    gtk_application_remove_window(self, phpgtk_arg_object(window));
}

void phpgtk_gtkapplication_set_accels_for_action(zval *handle, zval *detailedActionName, zval *accels)
{
    GtkApplication *self = PHPGTK_ARG_AS(GtkApplication, GTK_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return;
    }

    char **c_accels = phpgtk_zval_to_strv(accels);

    gtk_application_set_accels_for_action(self, phpgtk_arg_string(detailedActionName), c_accels);
    phpgtk_strv_free(c_accels);
}

void phpgtk_gtkapplication_set_menubar(zval *handle, zval *menubar)
{
    GtkApplication *self = PHPGTK_ARG_AS(GtkApplication, GTK_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return;
    }

    gtk_application_set_menubar(self, phpgtk_arg_object(menubar));
}

void phpgtk_gtkapplication_uninhibit(zval *handle, zval *cookie)
{
    GtkApplication *self = PHPGTK_ARG_AS(GtkApplication, GTK_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return;
    }

    gtk_application_uninhibit(self, (guint) phpgtk_arg_long(cookie));
}
