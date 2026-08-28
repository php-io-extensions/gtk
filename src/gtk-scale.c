#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-scale.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkscale_new(zval *orientation, zval *adjustment)
{
    return phpgtk_handle_register(gtk_scale_new((GtkOrientation) phpgtk_arg_long(orientation), phpgtk_arg_object(adjustment)));
}

zend_long phpgtk_gtkscale_new_with_range(zval *orientation, zval *min, zval *max, zval *step)
{
    return phpgtk_handle_register(gtk_scale_new_with_range((GtkOrientation) phpgtk_arg_long(orientation), phpgtk_arg_double(min), phpgtk_arg_double(max), phpgtk_arg_double(step)));
}

void phpgtk_gtkscale_add_mark(zval *handle, zval *value, zval *position, zval *markup)
{
    GtkScale *self = PHPGTK_ARG_AS(GtkScale, GTK_TYPE_SCALE, handle);

    if (self == NULL) {
        return;
    }

    gtk_scale_add_mark(self, phpgtk_arg_double(value), (GtkPositionType) phpgtk_arg_long(position), phpgtk_arg_string(markup));
}

void phpgtk_gtkscale_clear_marks(zval *handle)
{
    GtkScale *self = PHPGTK_ARG_AS(GtkScale, GTK_TYPE_SCALE, handle);

    if (self == NULL) {
        return;
    }

    gtk_scale_clear_marks(self);
}

zend_long phpgtk_gtkscale_get_digits(zval *handle)
{
    GtkScale *self = PHPGTK_ARG_AS(GtkScale, GTK_TYPE_SCALE, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_scale_get_digits(self);
}

zend_long phpgtk_gtkscale_get_draw_value(zval *handle)
{
    GtkScale *self = PHPGTK_ARG_AS(GtkScale, GTK_TYPE_SCALE, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_scale_get_draw_value(self) ? 1 : 0;
}

zend_long phpgtk_gtkscale_get_has_origin(zval *handle)
{
    GtkScale *self = PHPGTK_ARG_AS(GtkScale, GTK_TYPE_SCALE, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_scale_get_has_origin(self) ? 1 : 0;
}

zend_long phpgtk_gtkscale_get_layout(zval *handle)
{
    GtkScale *self = PHPGTK_ARG_AS(GtkScale, GTK_TYPE_SCALE, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_scale_get_layout(self));
}

void phpgtk_gtkscale_get_layout_offsets(zval *return_value, zval *handle)
{
    GtkScale *self = PHPGTK_ARG_AS(GtkScale, GTK_TYPE_SCALE, handle);
    int x = 0;
    int y = 0;

    if (self == NULL) {
        array_init(return_value); return;
    }

    gtk_scale_get_layout_offsets(self, &x, &y);
    array_init(return_value);
    add_assoc_long(return_value, "x", x);
    add_assoc_long(return_value, "y", y);
}

zend_long phpgtk_gtkscale_get_value_pos(zval *handle)
{
    GtkScale *self = PHPGTK_ARG_AS(GtkScale, GTK_TYPE_SCALE, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_scale_get_value_pos(self);
}

void phpgtk_gtkscale_set_digits(zval *handle, zval *digits)
{
    GtkScale *self = PHPGTK_ARG_AS(GtkScale, GTK_TYPE_SCALE, handle);

    if (self == NULL) {
        return;
    }

    gtk_scale_set_digits(self, (int) phpgtk_arg_long(digits));
}

void phpgtk_gtkscale_set_draw_value(zval *handle, zval *drawValue)
{
    GtkScale *self = PHPGTK_ARG_AS(GtkScale, GTK_TYPE_SCALE, handle);

    if (self == NULL) {
        return;
    }

    gtk_scale_set_draw_value(self, phpgtk_arg_bool(drawValue));
}

void phpgtk_gtkscale_set_has_origin(zval *handle, zval *hasOrigin)
{
    GtkScale *self = PHPGTK_ARG_AS(GtkScale, GTK_TYPE_SCALE, handle);

    if (self == NULL) {
        return;
    }

    gtk_scale_set_has_origin(self, phpgtk_arg_bool(hasOrigin));
}

void phpgtk_gtkscale_set_value_pos(zval *handle, zval *pos)
{
    GtkScale *self = PHPGTK_ARG_AS(GtkScale, GTK_TYPE_SCALE, handle);

    if (self == NULL) {
        return;
    }

    gtk_scale_set_value_pos(self, (GtkPositionType) phpgtk_arg_long(pos));
}
