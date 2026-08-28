#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-spinner.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkspinner_new(void)
{
    return phpgtk_handle_register(gtk_spinner_new());
}

zend_long phpgtk_gtkspinner_get_spinning(zval *handle)
{
    GtkSpinner *self = PHPGTK_ARG_AS(GtkSpinner, GTK_TYPE_SPINNER, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_spinner_get_spinning(self) ? 1 : 0;
}

void phpgtk_gtkspinner_set_spinning(zval *handle, zval *spinning)
{
    GtkSpinner *self = PHPGTK_ARG_AS(GtkSpinner, GTK_TYPE_SPINNER, handle);

    if (self == NULL) {
        return;
    }

    gtk_spinner_set_spinning(self, phpgtk_arg_bool(spinning));
}

void phpgtk_gtkspinner_start(zval *handle)
{
    GtkSpinner *self = PHPGTK_ARG_AS(GtkSpinner, GTK_TYPE_SPINNER, handle);

    if (self == NULL) {
        return;
    }

    gtk_spinner_start(self);
}

void phpgtk_gtkspinner_stop(zval *handle)
{
    GtkSpinner *self = PHPGTK_ARG_AS(GtkSpinner, GTK_TYPE_SPINNER, handle);

    if (self == NULL) {
        return;
    }

    gtk_spinner_stop(self);
}
