#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-application-window.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkapplicationwindow_new(zval *application)
{
    return phpgtk_handle_register(gtk_application_window_new(phpgtk_arg_object(application)));
}

zend_long phpgtk_gtkapplicationwindow_get_id(zval *handle)
{
    GtkApplicationWindow *self = PHPGTK_ARG_AS(GtkApplicationWindow, GTK_TYPE_APPLICATION_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_application_window_get_id(self);
}

zend_long phpgtk_gtkapplicationwindow_get_show_menubar(zval *handle)
{
    GtkApplicationWindow *self = PHPGTK_ARG_AS(GtkApplicationWindow, GTK_TYPE_APPLICATION_WINDOW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_application_window_get_show_menubar(self) ? 1 : 0;
}

void phpgtk_gtkapplicationwindow_set_show_menubar(zval *handle, zval *showMenubar)
{
    GtkApplicationWindow *self = PHPGTK_ARG_AS(GtkApplicationWindow, GTK_TYPE_APPLICATION_WINDOW, handle);

    if (self == NULL) {
        return;
    }

    gtk_application_window_set_show_menubar(self, phpgtk_arg_bool(showMenubar));
}

