#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-fixed.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkfixed_new(void)
{
    return phpgtk_handle_register(gtk_fixed_new());
}

void phpgtk_gtkfixed_get_child_position(zval *return_value, zval *handle, zval *widget)
{
    GtkFixed *self = PHPGTK_ARG_AS(GtkFixed, GTK_TYPE_FIXED, handle);
    double x = 0.0;
    double y = 0.0;

    if (self == NULL) {
        array_init(return_value); return;
    }

    gtk_fixed_get_child_position(self, phpgtk_arg_object(widget), &x, &y);
    array_init(return_value);
    add_assoc_double(return_value, "x", x);
    add_assoc_double(return_value, "y", y);
}

void phpgtk_gtkfixed_move(zval *handle, zval *widget, zval *x, zval *y)
{
    GtkFixed *self = PHPGTK_ARG_AS(GtkFixed, GTK_TYPE_FIXED, handle);

    if (self == NULL) {
        return;
    }

    gtk_fixed_move(self, phpgtk_arg_object(widget), phpgtk_arg_double(x), phpgtk_arg_double(y));
}

void phpgtk_gtkfixed_put(zval *handle, zval *widget, zval *x, zval *y)
{
    GtkFixed *self = PHPGTK_ARG_AS(GtkFixed, GTK_TYPE_FIXED, handle);

    if (self == NULL) {
        return;
    }

    gtk_fixed_put(self, phpgtk_arg_object(widget), phpgtk_arg_double(x), phpgtk_arg_double(y));
}

void phpgtk_gtkfixed_remove(zval *handle, zval *widget)
{
    GtkFixed *self = PHPGTK_ARG_AS(GtkFixed, GTK_TYPE_FIXED, handle);

    if (self == NULL) {
        return;
    }

    gtk_fixed_remove(self, phpgtk_arg_object(widget));
}
