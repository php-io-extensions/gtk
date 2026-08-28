#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-toggle-button.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtktogglebutton_new(void)
{
    return phpgtk_handle_register(gtk_toggle_button_new());
}

zend_long phpgtk_gtktogglebutton_new_with_label(zval *label)
{
    return phpgtk_handle_register(gtk_toggle_button_new_with_label(phpgtk_arg_string(label)));
}

zend_long phpgtk_gtktogglebutton_new_with_mnemonic(zval *label)
{
    return phpgtk_handle_register(gtk_toggle_button_new_with_mnemonic(phpgtk_arg_string(label)));
}

zend_long phpgtk_gtktogglebutton_get_active(zval *handle)
{
    GtkToggleButton *self = PHPGTK_ARG_AS(GtkToggleButton, GTK_TYPE_TOGGLE_BUTTON, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_toggle_button_get_active(self) ? 1 : 0;
}

void phpgtk_gtktogglebutton_set_active(zval *handle, zval *isActive)
{
    GtkToggleButton *self = PHPGTK_ARG_AS(GtkToggleButton, GTK_TYPE_TOGGLE_BUTTON, handle);

    if (self == NULL) {
        return;
    }

    gtk_toggle_button_set_active(self, phpgtk_arg_bool(isActive));
}

void phpgtk_gtktogglebutton_set_group(zval *handle, zval *group)
{
    GtkToggleButton *self = PHPGTK_ARG_AS(GtkToggleButton, GTK_TYPE_TOGGLE_BUTTON, handle);

    if (self == NULL) {
        return;
    }

    gtk_toggle_button_set_group(self, phpgtk_arg_object(group));
}
