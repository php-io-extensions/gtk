#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-password-entry.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkpasswordentry_new(void)
{
    return phpgtk_handle_register(gtk_password_entry_new());
}

zend_long phpgtk_gtkpasswordentry_get_extra_menu(zval *handle)
{
    GtkPasswordEntry *self = PHPGTK_ARG_AS(GtkPasswordEntry, GTK_TYPE_PASSWORD_ENTRY, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_password_entry_get_extra_menu(self));
}

zend_long phpgtk_gtkpasswordentry_get_show_peek_icon(zval *handle)
{
    GtkPasswordEntry *self = PHPGTK_ARG_AS(GtkPasswordEntry, GTK_TYPE_PASSWORD_ENTRY, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_password_entry_get_show_peek_icon(self) ? 1 : 0;
}

void phpgtk_gtkpasswordentry_set_extra_menu(zval *handle, zval *model)
{
    GtkPasswordEntry *self = PHPGTK_ARG_AS(GtkPasswordEntry, GTK_TYPE_PASSWORD_ENTRY, handle);

    if (self == NULL) {
        return;
    }

    gtk_password_entry_set_extra_menu(self, phpgtk_arg_object(model));
}

void phpgtk_gtkpasswordentry_set_show_peek_icon(zval *handle, zval *showPeekIcon)
{
    GtkPasswordEntry *self = PHPGTK_ARG_AS(GtkPasswordEntry, GTK_TYPE_PASSWORD_ENTRY, handle);

    if (self == NULL) {
        return;
    }

    gtk_password_entry_set_show_peek_icon(self, phpgtk_arg_bool(showPeekIcon));
}
