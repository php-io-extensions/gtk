#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-popover.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkpopover_new(void)
{
    return phpgtk_handle_register(gtk_popover_new());
}

zend_long phpgtk_gtkpopover_get_autohide(zval *handle)
{
    GtkPopover *self = PHPGTK_ARG_AS(GtkPopover, GTK_TYPE_POPOVER, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_popover_get_autohide(self) ? 1 : 0;
}

zend_long phpgtk_gtkpopover_get_cascade_popdown(zval *handle)
{
    GtkPopover *self = PHPGTK_ARG_AS(GtkPopover, GTK_TYPE_POPOVER, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_popover_get_cascade_popdown(self) ? 1 : 0;
}

zend_long phpgtk_gtkpopover_get_child(zval *handle)
{
    GtkPopover *self = PHPGTK_ARG_AS(GtkPopover, GTK_TYPE_POPOVER, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_popover_get_child(self));
}

zend_long phpgtk_gtkpopover_get_has_arrow(zval *handle)
{
    GtkPopover *self = PHPGTK_ARG_AS(GtkPopover, GTK_TYPE_POPOVER, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_popover_get_has_arrow(self) ? 1 : 0;
}

zend_long phpgtk_gtkpopover_get_mnemonics_visible(zval *handle)
{
    GtkPopover *self = PHPGTK_ARG_AS(GtkPopover, GTK_TYPE_POPOVER, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_popover_get_mnemonics_visible(self) ? 1 : 0;
}

void phpgtk_gtkpopover_get_offset(zval *return_value, zval *handle)
{
    GtkPopover *self = PHPGTK_ARG_AS(GtkPopover, GTK_TYPE_POPOVER, handle);

    int x_offset = 0;
    int y_offset = 0;

    if (self == NULL) {
        array_init(return_value); return;
    }

    gtk_popover_get_offset(self, &x_offset, &y_offset);
    array_init(return_value);
    add_assoc_long(return_value, "x_offset", x_offset);
    add_assoc_long(return_value, "y_offset", y_offset);
}

void phpgtk_gtkpopover_get_pointing_to(zval *return_value, zval *handle)
{
    GtkPopover *self = PHPGTK_ARG_AS(GtkPopover, GTK_TYPE_POPOVER, handle);

    GdkRectangle rect;

    if (self == NULL) {
        array_init(return_value); return;
    }

    gtk_popover_get_pointing_to(self, &rect);
    array_init(return_value);
    add_assoc_long(return_value, "x", rect.x);
    add_assoc_long(return_value, "y", rect.y);
    add_assoc_long(return_value, "width", rect.width);
    add_assoc_long(return_value, "height", rect.height);
}

zend_long phpgtk_gtkpopover_get_position(zval *handle)
{
    GtkPopover *self = PHPGTK_ARG_AS(GtkPopover, GTK_TYPE_POPOVER, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_popover_get_position(self);
}

void phpgtk_gtkpopover_popdown(zval *handle)
{
    GtkPopover *self = PHPGTK_ARG_AS(GtkPopover, GTK_TYPE_POPOVER, handle);

    if (self == NULL) {
        return;
    }

    gtk_popover_popdown(self);
}

void phpgtk_gtkpopover_popup(zval *handle)
{
    GtkPopover *self = PHPGTK_ARG_AS(GtkPopover, GTK_TYPE_POPOVER, handle);

    if (self == NULL) {
        return;
    }

    gtk_popover_popup(self);
}

void phpgtk_gtkpopover_present(zval *handle)
{
    GtkPopover *self = PHPGTK_ARG_AS(GtkPopover, GTK_TYPE_POPOVER, handle);

    if (self == NULL) {
        return;
    }

    gtk_popover_present(self);
}

void phpgtk_gtkpopover_set_autohide(zval *handle, zval *autohide)
{
    GtkPopover *self = PHPGTK_ARG_AS(GtkPopover, GTK_TYPE_POPOVER, handle);

    if (self == NULL) {
        return;
    }

    gtk_popover_set_autohide(self, phpgtk_arg_bool(autohide));
}

void phpgtk_gtkpopover_set_cascade_popdown(zval *handle, zval *cascadePopdown)
{
    GtkPopover *self = PHPGTK_ARG_AS(GtkPopover, GTK_TYPE_POPOVER, handle);

    if (self == NULL) {
        return;
    }

    gtk_popover_set_cascade_popdown(self, phpgtk_arg_bool(cascadePopdown));
}

void phpgtk_gtkpopover_set_child(zval *handle, zval *child)
{
    GtkPopover *self = PHPGTK_ARG_AS(GtkPopover, GTK_TYPE_POPOVER, handle);

    if (self == NULL) {
        return;
    }

    gtk_popover_set_child(self, phpgtk_arg_object(child));
}

void phpgtk_gtkpopover_set_default_widget(zval *handle, zval *widget)
{
    GtkPopover *self = PHPGTK_ARG_AS(GtkPopover, GTK_TYPE_POPOVER, handle);

    if (self == NULL) {
        return;
    }

    gtk_popover_set_default_widget(self, phpgtk_arg_object(widget));
}

void phpgtk_gtkpopover_set_has_arrow(zval *handle, zval *hasArrow)
{
    GtkPopover *self = PHPGTK_ARG_AS(GtkPopover, GTK_TYPE_POPOVER, handle);

    if (self == NULL) {
        return;
    }

    gtk_popover_set_has_arrow(self, phpgtk_arg_bool(hasArrow));
}

void phpgtk_gtkpopover_set_mnemonics_visible(zval *handle, zval *mnemonicsVisible)
{
    GtkPopover *self = PHPGTK_ARG_AS(GtkPopover, GTK_TYPE_POPOVER, handle);

    if (self == NULL) {
        return;
    }

    gtk_popover_set_mnemonics_visible(self, phpgtk_arg_bool(mnemonicsVisible));
}

void phpgtk_gtkpopover_set_offset(zval *handle, zval *xOffset, zval *yOffset)
{
    GtkPopover *self = PHPGTK_ARG_AS(GtkPopover, GTK_TYPE_POPOVER, handle);

    if (self == NULL) {
        return;
    }

    gtk_popover_set_offset(self, (int) phpgtk_arg_long(xOffset), (int) phpgtk_arg_long(yOffset));
}

void phpgtk_gtkpopover_set_pointing_to(zval *handle, zval *x, zval *y, zval *width, zval *height)
{
    GtkPopover *self = PHPGTK_ARG_AS(GtkPopover, GTK_TYPE_POPOVER, handle);

    GdkRectangle rect;
    if (self == NULL) {
        return;
    }

    rect.x = (int) phpgtk_arg_double(x);
    rect.y = (int) phpgtk_arg_double(y);
    rect.width = (int) phpgtk_arg_double(width);
    rect.height = (int) phpgtk_arg_double(height);
    gtk_popover_set_pointing_to(self, &rect);
}

void phpgtk_gtkpopover_set_position(zval *handle, zval *position)
{
    GtkPopover *self = PHPGTK_ARG_AS(GtkPopover, GTK_TYPE_POPOVER, handle);

    if (self == NULL) {
        return;
    }

    gtk_popover_set_position(self, (GtkPositionType) phpgtk_arg_long(position));
}

