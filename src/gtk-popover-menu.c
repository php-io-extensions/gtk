#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-popover-menu.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkpopovermenu_new_from_model(zval *model)
{
    return phpgtk_handle_register(gtk_popover_menu_new_from_model(phpgtk_arg_object(model)));
}

zend_long phpgtk_gtkpopovermenu_new_from_model_full(zval *model, zval *flags)
{
    return phpgtk_handle_register(gtk_popover_menu_new_from_model_full(phpgtk_arg_object(model), (GtkPopoverMenuFlags) phpgtk_arg_long(flags)));
}

zend_long phpgtk_gtkpopovermenu_add_child(zval *handle, zval *child, zval *id)
{
    GtkPopoverMenu *self = PHPGTK_ARG_AS(GtkPopoverMenu, GTK_TYPE_POPOVER_MENU, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_popover_menu_add_child(self, phpgtk_arg_object(child), phpgtk_arg_string(id)) ? 1 : 0;
}

zend_long phpgtk_gtkpopovermenu_get_flags(zval *handle)
{
    GtkPopoverMenu *self = PHPGTK_ARG_AS(GtkPopoverMenu, GTK_TYPE_POPOVER_MENU, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_popover_menu_get_flags(self);
}

zend_long phpgtk_gtkpopovermenu_get_menu_model(zval *handle)
{
    GtkPopoverMenu *self = PHPGTK_ARG_AS(GtkPopoverMenu, GTK_TYPE_POPOVER_MENU, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_popover_menu_get_menu_model(self));
}

zend_long phpgtk_gtkpopovermenu_remove_child(zval *handle, zval *child)
{
    GtkPopoverMenu *self = PHPGTK_ARG_AS(GtkPopoverMenu, GTK_TYPE_POPOVER_MENU, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_popover_menu_remove_child(self, phpgtk_arg_object(child)) ? 1 : 0;
}

void phpgtk_gtkpopovermenu_set_flags(zval *handle, zval *flags)
{
    GtkPopoverMenu *self = PHPGTK_ARG_AS(GtkPopoverMenu, GTK_TYPE_POPOVER_MENU, handle);

    if (self == NULL) {
        return;
    }

    gtk_popover_menu_set_flags(self, (GtkPopoverMenuFlags) phpgtk_arg_long(flags));
}

void phpgtk_gtkpopovermenu_set_menu_model(zval *handle, zval *model)
{
    GtkPopoverMenu *self = PHPGTK_ARG_AS(GtkPopoverMenu, GTK_TYPE_POPOVER_MENU, handle);

    if (self == NULL) {
        return;
    }

    gtk_popover_menu_set_menu_model(self, phpgtk_arg_object(model));
}

