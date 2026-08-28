#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-range.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkrange_get_adjustment(zval *handle)
{
    GtkRange *self = PHPGTK_ARG_AS(GtkRange, GTK_TYPE_RANGE, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_range_get_adjustment(self));
}

double phpgtk_gtkrange_get_fill_level(zval *handle)
{
    GtkRange *self = PHPGTK_ARG_AS(GtkRange, GTK_TYPE_RANGE, handle);

    if (self == NULL) {
        return 0.0;
    }

    return gtk_range_get_fill_level(self);
}

zend_long phpgtk_gtkrange_get_flippable(zval *handle)
{
    GtkRange *self = PHPGTK_ARG_AS(GtkRange, GTK_TYPE_RANGE, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_range_get_flippable(self) ? 1 : 0;
}

zend_long phpgtk_gtkrange_get_inverted(zval *handle)
{
    GtkRange *self = PHPGTK_ARG_AS(GtkRange, GTK_TYPE_RANGE, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_range_get_inverted(self) ? 1 : 0;
}

void phpgtk_gtkrange_get_range_rect(zval *return_value, zval *handle)
{
    GtkRange *self = PHPGTK_ARG_AS(GtkRange, GTK_TYPE_RANGE, handle);
    GdkRectangle range_rect;

    if (self == NULL) {
        array_init(return_value); return;
    }

    gtk_range_get_range_rect(self, &range_rect);
    phpgtk_ret_rectangle(return_value, &range_rect);
}

zend_long phpgtk_gtkrange_get_restrict_to_fill_level(zval *handle)
{
    GtkRange *self = PHPGTK_ARG_AS(GtkRange, GTK_TYPE_RANGE, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_range_get_restrict_to_fill_level(self) ? 1 : 0;
}

zend_long phpgtk_gtkrange_get_round_digits(zval *handle)
{
    GtkRange *self = PHPGTK_ARG_AS(GtkRange, GTK_TYPE_RANGE, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_range_get_round_digits(self);
}

zend_long phpgtk_gtkrange_get_show_fill_level(zval *handle)
{
    GtkRange *self = PHPGTK_ARG_AS(GtkRange, GTK_TYPE_RANGE, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_range_get_show_fill_level(self) ? 1 : 0;
}

void phpgtk_gtkrange_get_slider_range(zval *return_value, zval *handle)
{
    GtkRange *self = PHPGTK_ARG_AS(GtkRange, GTK_TYPE_RANGE, handle);
    int slider_start = 0;
    int slider_end = 0;

    if (self == NULL) {
        array_init(return_value); return;
    }

    gtk_range_get_slider_range(self, &slider_start, &slider_end);
    array_init(return_value);
    add_assoc_long(return_value, "slider_start", slider_start);
    add_assoc_long(return_value, "slider_end", slider_end);
}

zend_long phpgtk_gtkrange_get_slider_size_fixed(zval *handle)
{
    GtkRange *self = PHPGTK_ARG_AS(GtkRange, GTK_TYPE_RANGE, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_range_get_slider_size_fixed(self) ? 1 : 0;
}

double phpgtk_gtkrange_get_value(zval *handle)
{
    GtkRange *self = PHPGTK_ARG_AS(GtkRange, GTK_TYPE_RANGE, handle);

    if (self == NULL) {
        return 0.0;
    }

    return gtk_range_get_value(self);
}

void phpgtk_gtkrange_set_adjustment(zval *handle, zval *adjustment)
{
    GtkRange *self = PHPGTK_ARG_AS(GtkRange, GTK_TYPE_RANGE, handle);

    if (self == NULL) {
        return;
    }

    gtk_range_set_adjustment(self, phpgtk_arg_object(adjustment));
}

void phpgtk_gtkrange_set_fill_level(zval *handle, zval *fillLevel)
{
    GtkRange *self = PHPGTK_ARG_AS(GtkRange, GTK_TYPE_RANGE, handle);

    if (self == NULL) {
        return;
    }

    gtk_range_set_fill_level(self, phpgtk_arg_double(fillLevel));
}

void phpgtk_gtkrange_set_flippable(zval *handle, zval *flippable)
{
    GtkRange *self = PHPGTK_ARG_AS(GtkRange, GTK_TYPE_RANGE, handle);

    if (self == NULL) {
        return;
    }

    gtk_range_set_flippable(self, phpgtk_arg_bool(flippable));
}

void phpgtk_gtkrange_set_increments(zval *handle, zval *step, zval *page)
{
    GtkRange *self = PHPGTK_ARG_AS(GtkRange, GTK_TYPE_RANGE, handle);

    if (self == NULL) {
        return;
    }

    gtk_range_set_increments(self, phpgtk_arg_double(step), phpgtk_arg_double(page));
}

void phpgtk_gtkrange_set_inverted(zval *handle, zval *setting)
{
    GtkRange *self = PHPGTK_ARG_AS(GtkRange, GTK_TYPE_RANGE, handle);

    if (self == NULL) {
        return;
    }

    gtk_range_set_inverted(self, phpgtk_arg_bool(setting));
}

void phpgtk_gtkrange_set_range(zval *handle, zval *min, zval *max)
{
    GtkRange *self = PHPGTK_ARG_AS(GtkRange, GTK_TYPE_RANGE, handle);

    if (self == NULL) {
        return;
    }

    gtk_range_set_range(self, phpgtk_arg_double(min), phpgtk_arg_double(max));
}

void phpgtk_gtkrange_set_restrict_to_fill_level(zval *handle, zval *restrictToFillLevel)
{
    GtkRange *self = PHPGTK_ARG_AS(GtkRange, GTK_TYPE_RANGE, handle);

    if (self == NULL) {
        return;
    }

    gtk_range_set_restrict_to_fill_level(self, phpgtk_arg_bool(restrictToFillLevel));
}

void phpgtk_gtkrange_set_round_digits(zval *handle, zval *roundDigits)
{
    GtkRange *self = PHPGTK_ARG_AS(GtkRange, GTK_TYPE_RANGE, handle);

    if (self == NULL) {
        return;
    }

    gtk_range_set_round_digits(self, (int) phpgtk_arg_long(roundDigits));
}

void phpgtk_gtkrange_set_show_fill_level(zval *handle, zval *showFillLevel)
{
    GtkRange *self = PHPGTK_ARG_AS(GtkRange, GTK_TYPE_RANGE, handle);

    if (self == NULL) {
        return;
    }

    gtk_range_set_show_fill_level(self, phpgtk_arg_bool(showFillLevel));
}

void phpgtk_gtkrange_set_slider_size_fixed(zval *handle, zval *sizeFixed)
{
    GtkRange *self = PHPGTK_ARG_AS(GtkRange, GTK_TYPE_RANGE, handle);

    if (self == NULL) {
        return;
    }

    gtk_range_set_slider_size_fixed(self, phpgtk_arg_bool(sizeFixed));
}

void phpgtk_gtkrange_set_value(zval *handle, zval *value)
{
    GtkRange *self = PHPGTK_ARG_AS(GtkRange, GTK_TYPE_RANGE, handle);

    if (self == NULL) {
        return;
    }

    gtk_range_set_value(self, phpgtk_arg_double(value));
}
