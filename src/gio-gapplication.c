#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gio-gapplication.h"
#include "phpgtk-support.h"

zend_long phpgtk_gapplication_new(zval *applicationId, zval *flags)
{
    return phpgtk_handle_register_take(g_application_new(phpgtk_arg_string(applicationId), (GApplicationFlags) phpgtk_arg_long(flags)));
}

zend_long phpgtk_gapplication_get_default(void)
{
    return phpgtk_handle_register(g_application_get_default());
}

zend_long phpgtk_gapplication_id_is_valid(zval *applicationId)
{
    return g_application_id_is_valid(phpgtk_arg_string(applicationId)) ? 1 : 0;
}

void phpgtk_gapplication_activate(zval *handle)
{
    GApplication *self = PHPGTK_ARG_AS(GApplication, G_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return;
    }

    g_application_activate(self);
}

void phpgtk_gapplication_add_main_option(zval *handle, zval *longName, zval *shortName, zval *flags, zval *arg, zval *description, zval *argDescription)
{
    GApplication *self = PHPGTK_ARG_AS(GApplication, G_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return;
    }

    g_application_add_main_option(self, phpgtk_arg_string(longName), (char) phpgtk_arg_long(shortName), (GOptionFlags) phpgtk_arg_long(flags), (GOptionArg) phpgtk_arg_long(arg), phpgtk_arg_string(description), phpgtk_arg_string(argDescription));
}

void phpgtk_gapplication_get_application_id(zval *return_value, zval *handle)
{
    GApplication *self = PHPGTK_ARG_AS(GApplication, G_TYPE_APPLICATION, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, g_application_get_application_id(self));
}

zend_long phpgtk_gapplication_get_dbus_connection(zval *handle)
{
    GApplication *self = PHPGTK_ARG_AS(GApplication, G_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(g_application_get_dbus_connection(self));
}

void phpgtk_gapplication_get_dbus_object_path(zval *return_value, zval *handle)
{
    GApplication *self = PHPGTK_ARG_AS(GApplication, G_TYPE_APPLICATION, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, g_application_get_dbus_object_path(self));
}

zend_long phpgtk_gapplication_get_flags(zval *handle)
{
    GApplication *self = PHPGTK_ARG_AS(GApplication, G_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) g_application_get_flags(self);
}

zend_long phpgtk_gapplication_get_inactivity_timeout(zval *handle)
{
    GApplication *self = PHPGTK_ARG_AS(GApplication, G_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) g_application_get_inactivity_timeout(self);
}

zend_long phpgtk_gapplication_get_is_busy(zval *handle)
{
    GApplication *self = PHPGTK_ARG_AS(GApplication, G_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return 0;
    }

    return g_application_get_is_busy(self) ? 1 : 0;
}

zend_long phpgtk_gapplication_get_is_registered(zval *handle)
{
    GApplication *self = PHPGTK_ARG_AS(GApplication, G_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return 0;
    }

    return g_application_get_is_registered(self) ? 1 : 0;
}

zend_long phpgtk_gapplication_get_is_remote(zval *handle)
{
    GApplication *self = PHPGTK_ARG_AS(GApplication, G_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return 0;
    }

    return g_application_get_is_remote(self) ? 1 : 0;
}

void phpgtk_gapplication_get_resource_base_path(zval *return_value, zval *handle)
{
    GApplication *self = PHPGTK_ARG_AS(GApplication, G_TYPE_APPLICATION, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, g_application_get_resource_base_path(self));
}

void phpgtk_gapplication_get_version(zval *return_value, zval *handle)
{
    GApplication *self = PHPGTK_ARG_AS(GApplication, G_TYPE_APPLICATION, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, g_application_get_version(self));
}

void phpgtk_gapplication_hold(zval *handle)
{
    GApplication *self = PHPGTK_ARG_AS(GApplication, G_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return;
    }

    g_application_hold(self);
}

void phpgtk_gapplication_mark_busy(zval *handle)
{
    GApplication *self = PHPGTK_ARG_AS(GApplication, G_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return;
    }

    g_application_mark_busy(self);
}

void phpgtk_gapplication_open(zval *handle, zval *files, zval *nFiles, zval *hint)
{
    GApplication *self = PHPGTK_ARG_AS(GApplication, G_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return;
    }

    guint c_files_n = 0;
    gpointer *c_files = phpgtk_arg_object_array(files, &c_files_n);

    (void) c_files_n;
    g_application_open(self, (GFile **) c_files, phpgtk_arg_long(nFiles), phpgtk_arg_string(hint));
    phpgtk_object_array_free(c_files);
}

void phpgtk_gapplication_quit(zval *handle)
{
    GApplication *self = PHPGTK_ARG_AS(GApplication, G_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return;
    }

    g_application_quit(self);
}

void phpgtk_gapplication_release(zval *handle)
{
    GApplication *self = PHPGTK_ARG_AS(GApplication, G_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return;
    }

    g_application_release(self);
}

zend_long phpgtk_gapplication_run(zval *handle, zval *argc, zval *argv)
{
    GApplication *self = PHPGTK_ARG_AS(GApplication, G_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return 0;
    }

    char **c_argv = phpgtk_zval_to_strv(argv);

    zend_long _r = (zend_long) g_application_run(self, phpgtk_arg_long(argc), c_argv);
    phpgtk_strv_free(c_argv);
    return _r;
}

void phpgtk_gapplication_send_notification(zval *handle, zval *id, zval *notification)
{
    GApplication *self = PHPGTK_ARG_AS(GApplication, G_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return;
    }

    g_application_send_notification(self, phpgtk_arg_string(id), phpgtk_arg_object(notification));
}

void phpgtk_gapplication_set_application_id(zval *handle, zval *applicationId)
{
    GApplication *self = PHPGTK_ARG_AS(GApplication, G_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return;
    }

    g_application_set_application_id(self, phpgtk_arg_string(applicationId));
}

void phpgtk_gapplication_set_default(zval *handle)
{
    GApplication *self = PHPGTK_ARG_AS(GApplication, G_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return;
    }

    g_application_set_default(self);
}

void phpgtk_gapplication_set_flags(zval *handle, zval *flags)
{
    GApplication *self = PHPGTK_ARG_AS(GApplication, G_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return;
    }

    g_application_set_flags(self, (GApplicationFlags) phpgtk_arg_long(flags));
}

void phpgtk_gapplication_set_inactivity_timeout(zval *handle, zval *inactivityTimeout)
{
    GApplication *self = PHPGTK_ARG_AS(GApplication, G_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return;
    }

    g_application_set_inactivity_timeout(self, (guint) phpgtk_arg_long(inactivityTimeout));
}

void phpgtk_gapplication_set_option_context_description(zval *handle, zval *description)
{
    GApplication *self = PHPGTK_ARG_AS(GApplication, G_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return;
    }

    g_application_set_option_context_description(self, phpgtk_arg_string(description));
}

void phpgtk_gapplication_set_option_context_parameter_string(zval *handle, zval *parameterString)
{
    GApplication *self = PHPGTK_ARG_AS(GApplication, G_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return;
    }

    g_application_set_option_context_parameter_string(self, phpgtk_arg_string(parameterString));
}

void phpgtk_gapplication_set_option_context_summary(zval *handle, zval *summary)
{
    GApplication *self = PHPGTK_ARG_AS(GApplication, G_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return;
    }

    g_application_set_option_context_summary(self, phpgtk_arg_string(summary));
}

void phpgtk_gapplication_set_resource_base_path(zval *handle, zval *resourcePath)
{
    GApplication *self = PHPGTK_ARG_AS(GApplication, G_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return;
    }

    g_application_set_resource_base_path(self, phpgtk_arg_string(resourcePath));
}

void phpgtk_gapplication_set_version(zval *handle, zval *version)
{
    GApplication *self = PHPGTK_ARG_AS(GApplication, G_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return;
    }

    g_application_set_version(self, phpgtk_arg_string(version));
}

void phpgtk_gapplication_unmark_busy(zval *handle)
{
    GApplication *self = PHPGTK_ARG_AS(GApplication, G_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return;
    }

    g_application_unmark_busy(self);
}

void phpgtk_gapplication_withdraw_notification(zval *handle, zval *id)
{
    GApplication *self = PHPGTK_ARG_AS(GApplication, G_TYPE_APPLICATION, handle);

    if (self == NULL) {
        return;
    }

    g_application_withdraw_notification(self, phpgtk_arg_string(id));
}
