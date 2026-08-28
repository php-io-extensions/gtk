#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-button.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkbutton_new(void)
{
    return phpgtk_handle_register(gtk_button_new());
}

zend_long phpgtk_gtkbutton_new_from_icon_name(zval *iconName)
{
    return phpgtk_handle_register(gtk_button_new_from_icon_name(phpgtk_arg_string(iconName)));
}

zend_long phpgtk_gtkbutton_new_with_label(zval *label)
{
    return phpgtk_handle_register(gtk_button_new_with_label(phpgtk_arg_string(label)));
}

zend_long phpgtk_gtkbutton_new_with_mnemonic(zval *label)
{
    return phpgtk_handle_register(gtk_button_new_with_mnemonic(phpgtk_arg_string(label)));
}

zend_long phpgtk_gtkbutton_get_can_shrink(zval *handle)
{
    GtkButton *self = PHPGTK_ARG_AS(GtkButton, GTK_TYPE_BUTTON, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_button_get_can_shrink(self) ? 1 : 0;
}

zend_long phpgtk_gtkbutton_get_child(zval *handle)
{
    GtkButton *self = PHPGTK_ARG_AS(GtkButton, GTK_TYPE_BUTTON, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_button_get_child(self));
}

zend_long phpgtk_gtkbutton_get_has_frame(zval *handle)
{
    GtkButton *self = PHPGTK_ARG_AS(GtkButton, GTK_TYPE_BUTTON, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_button_get_has_frame(self) ? 1 : 0;
}

void phpgtk_gtkbutton_get_icon_name(zval *return_value, zval *handle)
{
    GtkButton *self = PHPGTK_ARG_AS(GtkButton, GTK_TYPE_BUTTON, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_button_get_icon_name(self));
}

void phpgtk_gtkbutton_get_label(zval *return_value, zval *handle)
{
    GtkButton *self = PHPGTK_ARG_AS(GtkButton, GTK_TYPE_BUTTON, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_button_get_label(self));
}

zend_long phpgtk_gtkbutton_get_use_underline(zval *handle)
{
    GtkButton *self = PHPGTK_ARG_AS(GtkButton, GTK_TYPE_BUTTON, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_button_get_use_underline(self) ? 1 : 0;
}

void phpgtk_gtkbutton_set_can_shrink(zval *handle, zval *canShrink)
{
    GtkButton *self = PHPGTK_ARG_AS(GtkButton, GTK_TYPE_BUTTON, handle);

    if (self == NULL) {
        return;
    }

    gtk_button_set_can_shrink(self, phpgtk_arg_bool(canShrink));
}

void phpgtk_gtkbutton_set_child(zval *handle, zval *child)
{
    GtkButton *self = PHPGTK_ARG_AS(GtkButton, GTK_TYPE_BUTTON, handle);

    if (self == NULL) {
        return;
    }

    gtk_button_set_child(self, phpgtk_arg_object(child));
}

void phpgtk_gtkbutton_set_has_frame(zval *handle, zval *hasFrame)
{
    GtkButton *self = PHPGTK_ARG_AS(GtkButton, GTK_TYPE_BUTTON, handle);

    if (self == NULL) {
        return;
    }

    gtk_button_set_has_frame(self, phpgtk_arg_bool(hasFrame));
}

void phpgtk_gtkbutton_set_icon_name(zval *handle, zval *iconName)
{
    GtkButton *self = PHPGTK_ARG_AS(GtkButton, GTK_TYPE_BUTTON, handle);

    if (self == NULL) {
        return;
    }

    gtk_button_set_icon_name(self, phpgtk_arg_string(iconName));
}

void phpgtk_gtkbutton_set_label(zval *handle, zval *label)
{
    GtkButton *self = PHPGTK_ARG_AS(GtkButton, GTK_TYPE_BUTTON, handle);

    if (self == NULL) {
        return;
    }

    gtk_button_set_label(self, phpgtk_arg_string(label));
}

void phpgtk_gtkbutton_set_use_underline(zval *handle, zval *useUnderline)
{
    GtkButton *self = PHPGTK_ARG_AS(GtkButton, GTK_TYPE_BUTTON, handle);

    if (self == NULL) {
        return;
    }

    gtk_button_set_use_underline(self, phpgtk_arg_bool(useUnderline));
}
