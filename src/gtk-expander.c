#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-expander.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkexpander_new(zval *label)
{
    return phpgtk_handle_register(gtk_expander_new(phpgtk_arg_string(label)));
}

zend_long phpgtk_gtkexpander_new_with_mnemonic(zval *label)
{
    return phpgtk_handle_register(gtk_expander_new_with_mnemonic(phpgtk_arg_string(label)));
}

zend_long phpgtk_gtkexpander_get_child(zval *handle)
{
    GtkExpander *self = PHPGTK_ARG_AS(GtkExpander, GTK_TYPE_EXPANDER, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_expander_get_child(self));
}

zend_long phpgtk_gtkexpander_get_expanded(zval *handle)
{
    GtkExpander *self = PHPGTK_ARG_AS(GtkExpander, GTK_TYPE_EXPANDER, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_expander_get_expanded(self) ? 1 : 0;
}

void phpgtk_gtkexpander_get_label(zval *return_value, zval *handle)
{
    GtkExpander *self = PHPGTK_ARG_AS(GtkExpander, GTK_TYPE_EXPANDER, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_expander_get_label(self));
}

zend_long phpgtk_gtkexpander_get_label_widget(zval *handle)
{
    GtkExpander *self = PHPGTK_ARG_AS(GtkExpander, GTK_TYPE_EXPANDER, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_expander_get_label_widget(self));
}

zend_long phpgtk_gtkexpander_get_resize_toplevel(zval *handle)
{
    GtkExpander *self = PHPGTK_ARG_AS(GtkExpander, GTK_TYPE_EXPANDER, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_expander_get_resize_toplevel(self) ? 1 : 0;
}

zend_long phpgtk_gtkexpander_get_use_markup(zval *handle)
{
    GtkExpander *self = PHPGTK_ARG_AS(GtkExpander, GTK_TYPE_EXPANDER, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_expander_get_use_markup(self) ? 1 : 0;
}

zend_long phpgtk_gtkexpander_get_use_underline(zval *handle)
{
    GtkExpander *self = PHPGTK_ARG_AS(GtkExpander, GTK_TYPE_EXPANDER, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_expander_get_use_underline(self) ? 1 : 0;
}

void phpgtk_gtkexpander_set_child(zval *handle, zval *child)
{
    GtkExpander *self = PHPGTK_ARG_AS(GtkExpander, GTK_TYPE_EXPANDER, handle);

    if (self == NULL) {
        return;
    }

    gtk_expander_set_child(self, phpgtk_arg_object(child));
}

void phpgtk_gtkexpander_set_expanded(zval *handle, zval *expanded)
{
    GtkExpander *self = PHPGTK_ARG_AS(GtkExpander, GTK_TYPE_EXPANDER, handle);

    if (self == NULL) {
        return;
    }

    gtk_expander_set_expanded(self, phpgtk_arg_bool(expanded));
}

void phpgtk_gtkexpander_set_label(zval *handle, zval *label)
{
    GtkExpander *self = PHPGTK_ARG_AS(GtkExpander, GTK_TYPE_EXPANDER, handle);

    if (self == NULL) {
        return;
    }

    gtk_expander_set_label(self, phpgtk_arg_string(label));
}

void phpgtk_gtkexpander_set_label_widget(zval *handle, zval *labelWidget)
{
    GtkExpander *self = PHPGTK_ARG_AS(GtkExpander, GTK_TYPE_EXPANDER, handle);

    if (self == NULL) {
        return;
    }

    gtk_expander_set_label_widget(self, phpgtk_arg_object(labelWidget));
}

void phpgtk_gtkexpander_set_resize_toplevel(zval *handle, zval *resizeToplevel)
{
    GtkExpander *self = PHPGTK_ARG_AS(GtkExpander, GTK_TYPE_EXPANDER, handle);

    if (self == NULL) {
        return;
    }

    gtk_expander_set_resize_toplevel(self, phpgtk_arg_bool(resizeToplevel));
}

void phpgtk_gtkexpander_set_use_markup(zval *handle, zval *useMarkup)
{
    GtkExpander *self = PHPGTK_ARG_AS(GtkExpander, GTK_TYPE_EXPANDER, handle);

    if (self == NULL) {
        return;
    }

    gtk_expander_set_use_markup(self, phpgtk_arg_bool(useMarkup));
}

void phpgtk_gtkexpander_set_use_underline(zval *handle, zval *useUnderline)
{
    GtkExpander *self = PHPGTK_ARG_AS(GtkExpander, GTK_TYPE_EXPANDER, handle);

    if (self == NULL) {
        return;
    }

    gtk_expander_set_use_underline(self, phpgtk_arg_bool(useUnderline));
}
