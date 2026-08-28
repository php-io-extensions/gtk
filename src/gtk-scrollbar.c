#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-scrollbar.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkscrollbar_new(zval *orientation, zval *adjustment)
{
    return phpgtk_handle_register(gtk_scrollbar_new((GtkOrientation) phpgtk_arg_long(orientation), phpgtk_arg_object(adjustment)));
}

zend_long phpgtk_gtkscrollbar_get_adjustment(zval *handle)
{
    GtkScrollbar *self = PHPGTK_ARG_AS(GtkScrollbar, GTK_TYPE_SCROLLBAR, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_scrollbar_get_adjustment(self));
}

void phpgtk_gtkscrollbar_set_adjustment(zval *handle, zval *adjustment)
{
    GtkScrollbar *self = PHPGTK_ARG_AS(GtkScrollbar, GTK_TYPE_SCROLLBAR, handle);

    if (self == NULL) {
        return;
    }

    gtk_scrollbar_set_adjustment(self, phpgtk_arg_object(adjustment));
}
