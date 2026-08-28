#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-adjustment.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkadjustment_new(zval *value, zval *lower, zval *upper, zval *stepIncrement, zval *pageIncrement, zval *pageSize)
{
    return phpgtk_handle_register(gtk_adjustment_new(
        phpgtk_arg_double(value),
        phpgtk_arg_double(lower),
        phpgtk_arg_double(upper),
        phpgtk_arg_double(stepIncrement),
        phpgtk_arg_double(pageIncrement),
        phpgtk_arg_double(pageSize)
    ));
}

void phpgtk_gtkadjustment_clamp_page(zval *handle, zval *lower, zval *upper)
{
    GtkAdjustment *self = PHPGTK_ARG_AS(GtkAdjustment, GTK_TYPE_ADJUSTMENT, handle);

    if (self == NULL) {
        return;
    }

    gtk_adjustment_clamp_page(self, phpgtk_arg_double(lower), phpgtk_arg_double(upper));
}

void phpgtk_gtkadjustment_configure(zval *handle, zval *value, zval *lower, zval *upper, zval *stepIncrement, zval *pageIncrement, zval *pageSize)
{
    GtkAdjustment *self = PHPGTK_ARG_AS(GtkAdjustment, GTK_TYPE_ADJUSTMENT, handle);

    if (self == NULL) {
        return;
    }

    gtk_adjustment_configure(
        self,
        phpgtk_arg_double(value),
        phpgtk_arg_double(lower),
        phpgtk_arg_double(upper),
        phpgtk_arg_double(stepIncrement),
        phpgtk_arg_double(pageIncrement),
        phpgtk_arg_double(pageSize)
    );
}

double phpgtk_gtkadjustment_get_lower(zval *handle)
{
    GtkAdjustment *self = PHPGTK_ARG_AS(GtkAdjustment, GTK_TYPE_ADJUSTMENT, handle);

    if (self == NULL) {
        return 0.0;
    }

    return gtk_adjustment_get_lower(self);
}

double phpgtk_gtkadjustment_get_minimum_increment(zval *handle)
{
    GtkAdjustment *self = PHPGTK_ARG_AS(GtkAdjustment, GTK_TYPE_ADJUSTMENT, handle);

    if (self == NULL) {
        return 0.0;
    }

    return gtk_adjustment_get_minimum_increment(self);
}

double phpgtk_gtkadjustment_get_page_increment(zval *handle)
{
    GtkAdjustment *self = PHPGTK_ARG_AS(GtkAdjustment, GTK_TYPE_ADJUSTMENT, handle);

    if (self == NULL) {
        return 0.0;
    }

    return gtk_adjustment_get_page_increment(self);
}

double phpgtk_gtkadjustment_get_page_size(zval *handle)
{
    GtkAdjustment *self = PHPGTK_ARG_AS(GtkAdjustment, GTK_TYPE_ADJUSTMENT, handle);

    if (self == NULL) {
        return 0.0;
    }

    return gtk_adjustment_get_page_size(self);
}

double phpgtk_gtkadjustment_get_step_increment(zval *handle)
{
    GtkAdjustment *self = PHPGTK_ARG_AS(GtkAdjustment, GTK_TYPE_ADJUSTMENT, handle);

    if (self == NULL) {
        return 0.0;
    }

    return gtk_adjustment_get_step_increment(self);
}

double phpgtk_gtkadjustment_get_upper(zval *handle)
{
    GtkAdjustment *self = PHPGTK_ARG_AS(GtkAdjustment, GTK_TYPE_ADJUSTMENT, handle);

    if (self == NULL) {
        return 0.0;
    }

    return gtk_adjustment_get_upper(self);
}

double phpgtk_gtkadjustment_get_value(zval *handle)
{
    GtkAdjustment *self = PHPGTK_ARG_AS(GtkAdjustment, GTK_TYPE_ADJUSTMENT, handle);

    if (self == NULL) {
        return 0.0;
    }

    return gtk_adjustment_get_value(self);
}

void phpgtk_gtkadjustment_set_lower(zval *handle, zval *lower)
{
    GtkAdjustment *self = PHPGTK_ARG_AS(GtkAdjustment, GTK_TYPE_ADJUSTMENT, handle);

    if (self == NULL) {
        return;
    }

    gtk_adjustment_set_lower(self, phpgtk_arg_double(lower));
}

void phpgtk_gtkadjustment_set_page_increment(zval *handle, zval *pageIncrement)
{
    GtkAdjustment *self = PHPGTK_ARG_AS(GtkAdjustment, GTK_TYPE_ADJUSTMENT, handle);

    if (self == NULL) {
        return;
    }

    gtk_adjustment_set_page_increment(self, phpgtk_arg_double(pageIncrement));
}

void phpgtk_gtkadjustment_set_page_size(zval *handle, zval *pageSize)
{
    GtkAdjustment *self = PHPGTK_ARG_AS(GtkAdjustment, GTK_TYPE_ADJUSTMENT, handle);

    if (self == NULL) {
        return;
    }

    gtk_adjustment_set_page_size(self, phpgtk_arg_double(pageSize));
}

void phpgtk_gtkadjustment_set_step_increment(zval *handle, zval *stepIncrement)
{
    GtkAdjustment *self = PHPGTK_ARG_AS(GtkAdjustment, GTK_TYPE_ADJUSTMENT, handle);

    if (self == NULL) {
        return;
    }

    gtk_adjustment_set_step_increment(self, phpgtk_arg_double(stepIncrement));
}

void phpgtk_gtkadjustment_set_upper(zval *handle, zval *upper)
{
    GtkAdjustment *self = PHPGTK_ARG_AS(GtkAdjustment, GTK_TYPE_ADJUSTMENT, handle);

    if (self == NULL) {
        return;
    }

    gtk_adjustment_set_upper(self, phpgtk_arg_double(upper));
}

void phpgtk_gtkadjustment_set_value(zval *handle, zval *value)
{
    GtkAdjustment *self = PHPGTK_ARG_AS(GtkAdjustment, GTK_TYPE_ADJUSTMENT, handle);

    if (self == NULL) {
        return;
    }

    gtk_adjustment_set_value(self, phpgtk_arg_double(value));
}
