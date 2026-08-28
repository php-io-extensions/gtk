#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-check-button.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkcheckbutton_new(void)
{
    return phpgtk_handle_register(gtk_check_button_new());
}

zend_long phpgtk_gtkcheckbutton_new_with_label(zval *label)
{
    return phpgtk_handle_register(gtk_check_button_new_with_label(phpgtk_arg_string(label)));
}

zend_long phpgtk_gtkcheckbutton_new_with_mnemonic(zval *label)
{
    return phpgtk_handle_register(gtk_check_button_new_with_mnemonic(phpgtk_arg_string(label)));
}

zend_long phpgtk_gtkcheckbutton_get_active(zval *handle)
{
    GtkCheckButton *self = PHPGTK_ARG_AS(GtkCheckButton, GTK_TYPE_CHECK_BUTTON, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_check_button_get_active(self) ? 1 : 0;
}

zend_long phpgtk_gtkcheckbutton_get_child(zval *handle)
{
    GtkCheckButton *self = PHPGTK_ARG_AS(GtkCheckButton, GTK_TYPE_CHECK_BUTTON, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_check_button_get_child(self));
}

zend_long phpgtk_gtkcheckbutton_get_inconsistent(zval *handle)
{
    GtkCheckButton *self = PHPGTK_ARG_AS(GtkCheckButton, GTK_TYPE_CHECK_BUTTON, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_check_button_get_inconsistent(self) ? 1 : 0;
}

void phpgtk_gtkcheckbutton_get_label(zval *return_value, zval *handle)
{
    GtkCheckButton *self = PHPGTK_ARG_AS(GtkCheckButton, GTK_TYPE_CHECK_BUTTON, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_check_button_get_label(self));
}

zend_long phpgtk_gtkcheckbutton_get_use_underline(zval *handle)
{
    GtkCheckButton *self = PHPGTK_ARG_AS(GtkCheckButton, GTK_TYPE_CHECK_BUTTON, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_check_button_get_use_underline(self) ? 1 : 0;
}

void phpgtk_gtkcheckbutton_set_active(zval *handle, zval *setting)
{
    GtkCheckButton *self = PHPGTK_ARG_AS(GtkCheckButton, GTK_TYPE_CHECK_BUTTON, handle);

    if (self == NULL) {
        return;
    }

    gtk_check_button_set_active(self, phpgtk_arg_bool(setting));
}

void phpgtk_gtkcheckbutton_set_child(zval *handle, zval *child)
{
    GtkCheckButton *self = PHPGTK_ARG_AS(GtkCheckButton, GTK_TYPE_CHECK_BUTTON, handle);

    if (self == NULL) {
        return;
    }

    gtk_check_button_set_child(self, phpgtk_arg_object(child));
}

void phpgtk_gtkcheckbutton_set_group(zval *handle, zval *group)
{
    GtkCheckButton *self = PHPGTK_ARG_AS(GtkCheckButton, GTK_TYPE_CHECK_BUTTON, handle);

    if (self == NULL) {
        return;
    }

    gtk_check_button_set_group(self, phpgtk_arg_object(group));
}

void phpgtk_gtkcheckbutton_set_inconsistent(zval *handle, zval *inconsistent)
{
    GtkCheckButton *self = PHPGTK_ARG_AS(GtkCheckButton, GTK_TYPE_CHECK_BUTTON, handle);

    if (self == NULL) {
        return;
    }

    gtk_check_button_set_inconsistent(self, phpgtk_arg_bool(inconsistent));
}

void phpgtk_gtkcheckbutton_set_label(zval *handle, zval *label)
{
    GtkCheckButton *self = PHPGTK_ARG_AS(GtkCheckButton, GTK_TYPE_CHECK_BUTTON, handle);

    if (self == NULL) {
        return;
    }

    gtk_check_button_set_label(self, phpgtk_arg_string(label));
}

void phpgtk_gtkcheckbutton_set_use_underline(zval *handle, zval *setting)
{
    GtkCheckButton *self = PHPGTK_ARG_AS(GtkCheckButton, GTK_TYPE_CHECK_BUTTON, handle);

    if (self == NULL) {
        return;
    }

    gtk_check_button_set_use_underline(self, phpgtk_arg_bool(setting));
}
