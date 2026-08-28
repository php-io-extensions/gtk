#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-scrollable.h"
#include "phpgtk-support.h"

void phpgtk_gtkscrollable_get_border(zval *return_value, zval *handle)
{
    GtkScrollable *self = PHPGTK_ARG_AS(GtkScrollable, GTK_TYPE_SCROLLABLE, handle);
    GtkBorder border = {0, 0, 0, 0};

    if (self == NULL) {
        array_init(return_value); return;
    }

    gtk_scrollable_get_border(self, &border);
    array_init(return_value);
    add_assoc_long(return_value, "left", border.left);
    add_assoc_long(return_value, "right", border.right);
    add_assoc_long(return_value, "top", border.top);
    add_assoc_long(return_value, "bottom", border.bottom);
}

zend_long phpgtk_gtkscrollable_get_hadjustment(zval *handle)
{
    GtkScrollable *self = PHPGTK_ARG_AS(GtkScrollable, GTK_TYPE_SCROLLABLE, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_scrollable_get_hadjustment(self));
}

zend_long phpgtk_gtkscrollable_get_hscroll_policy(zval *handle)
{
    GtkScrollable *self = PHPGTK_ARG_AS(GtkScrollable, GTK_TYPE_SCROLLABLE, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_scrollable_get_hscroll_policy(self);
}

zend_long phpgtk_gtkscrollable_get_vadjustment(zval *handle)
{
    GtkScrollable *self = PHPGTK_ARG_AS(GtkScrollable, GTK_TYPE_SCROLLABLE, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_scrollable_get_vadjustment(self));
}

zend_long phpgtk_gtkscrollable_get_vscroll_policy(zval *handle)
{
    GtkScrollable *self = PHPGTK_ARG_AS(GtkScrollable, GTK_TYPE_SCROLLABLE, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_scrollable_get_vscroll_policy(self);
}

void phpgtk_gtkscrollable_set_hadjustment(zval *handle, zval *hadjustment)
{
    GtkScrollable *self = PHPGTK_ARG_AS(GtkScrollable, GTK_TYPE_SCROLLABLE, handle);

    if (self == NULL) {
        return;
    }

    gtk_scrollable_set_hadjustment(self, phpgtk_arg_object(hadjustment));
}

void phpgtk_gtkscrollable_set_hscroll_policy(zval *handle, zval *policy)
{
    GtkScrollable *self = PHPGTK_ARG_AS(GtkScrollable, GTK_TYPE_SCROLLABLE, handle);

    if (self == NULL) {
        return;
    }

    gtk_scrollable_set_hscroll_policy(self, (GtkScrollablePolicy) phpgtk_arg_long(policy));
}

void phpgtk_gtkscrollable_set_vadjustment(zval *handle, zval *vadjustment)
{
    GtkScrollable *self = PHPGTK_ARG_AS(GtkScrollable, GTK_TYPE_SCROLLABLE, handle);

    if (self == NULL) {
        return;
    }

    gtk_scrollable_set_vadjustment(self, phpgtk_arg_object(vadjustment));
}

void phpgtk_gtkscrollable_set_vscroll_policy(zval *handle, zval *policy)
{
    GtkScrollable *self = PHPGTK_ARG_AS(GtkScrollable, GTK_TYPE_SCROLLABLE, handle);

    if (self == NULL) {
        return;
    }

    gtk_scrollable_set_vscroll_policy(self, (GtkScrollablePolicy) phpgtk_arg_long(policy));
}
