#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-popover-menu-bar.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkpopovermenubar_new_from_model(zval *model)
{
    return phpgtk_handle_register(gtk_popover_menu_bar_new_from_model(phpgtk_arg_object(model)));
}

zend_long phpgtk_gtkpopovermenubar_add_child(zval *handle, zval *child, zval *id)
{
    GtkPopoverMenuBar *self = PHPGTK_ARG_AS(GtkPopoverMenuBar, GTK_TYPE_POPOVER_MENU_BAR, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_popover_menu_bar_add_child(self, phpgtk_arg_object(child), phpgtk_arg_string(id)) ? 1 : 0;
}

zend_long phpgtk_gtkpopovermenubar_get_menu_model(zval *handle)
{
    GtkPopoverMenuBar *self = PHPGTK_ARG_AS(GtkPopoverMenuBar, GTK_TYPE_POPOVER_MENU_BAR, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_popover_menu_bar_get_menu_model(self));
}

zend_long phpgtk_gtkpopovermenubar_remove_child(zval *handle, zval *child)
{
    GtkPopoverMenuBar *self = PHPGTK_ARG_AS(GtkPopoverMenuBar, GTK_TYPE_POPOVER_MENU_BAR, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_popover_menu_bar_remove_child(self, phpgtk_arg_object(child)) ? 1 : 0;
}

void phpgtk_gtkpopovermenubar_set_menu_model(zval *handle, zval *model)
{
    GtkPopoverMenuBar *self = PHPGTK_ARG_AS(GtkPopoverMenuBar, GTK_TYPE_POPOVER_MENU_BAR, handle);

    if (self == NULL) {
        return;
    }

    gtk_popover_menu_bar_set_menu_model(self, phpgtk_arg_object(model));
}

