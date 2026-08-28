#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-level-bar.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtklevelbar_new(void)
{
    return phpgtk_handle_register(gtk_level_bar_new());
}

zend_long phpgtk_gtklevelbar_new_for_interval(zval *minValue, zval *maxValue)
{
    return phpgtk_handle_register(gtk_level_bar_new_for_interval(phpgtk_arg_double(minValue), phpgtk_arg_double(maxValue)));
}

void phpgtk_gtklevelbar_add_offset_value(zval *handle, zval *name, zval *value)
{
    GtkLevelBar *self = PHPGTK_ARG_AS(GtkLevelBar, GTK_TYPE_LEVEL_BAR, handle);

    if (self == NULL) {
        return;
    }

    gtk_level_bar_add_offset_value(self, phpgtk_arg_string(name), phpgtk_arg_double(value));
}

zend_long phpgtk_gtklevelbar_get_inverted(zval *handle)
{
    GtkLevelBar *self = PHPGTK_ARG_AS(GtkLevelBar, GTK_TYPE_LEVEL_BAR, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_level_bar_get_inverted(self) ? 1 : 0;
}

double phpgtk_gtklevelbar_get_max_value(zval *handle)
{
    GtkLevelBar *self = PHPGTK_ARG_AS(GtkLevelBar, GTK_TYPE_LEVEL_BAR, handle);

    if (self == NULL) {
        return 0.0;
    }

    return gtk_level_bar_get_max_value(self);
}

double phpgtk_gtklevelbar_get_min_value(zval *handle)
{
    GtkLevelBar *self = PHPGTK_ARG_AS(GtkLevelBar, GTK_TYPE_LEVEL_BAR, handle);

    if (self == NULL) {
        return 0.0;
    }

    return gtk_level_bar_get_min_value(self);
}

zend_long phpgtk_gtklevelbar_get_mode(zval *handle)
{
    GtkLevelBar *self = PHPGTK_ARG_AS(GtkLevelBar, GTK_TYPE_LEVEL_BAR, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_level_bar_get_mode(self);
}

void phpgtk_gtklevelbar_get_offset_value(zval *return_value, zval *handle, zval *name)
{
    GtkLevelBar *self = PHPGTK_ARG_AS(GtkLevelBar, GTK_TYPE_LEVEL_BAR, handle);
    double value = 0.0;

    if (self == NULL) {
        array_init(return_value); return;
    }

    gtk_level_bar_get_offset_value(self, phpgtk_arg_string(name), &value);
    array_init(return_value);
    add_assoc_double(return_value, "value", value);
}

double phpgtk_gtklevelbar_get_value(zval *handle)
{
    GtkLevelBar *self = PHPGTK_ARG_AS(GtkLevelBar, GTK_TYPE_LEVEL_BAR, handle);

    if (self == NULL) {
        return 0.0;
    }

    return gtk_level_bar_get_value(self);
}

void phpgtk_gtklevelbar_remove_offset_value(zval *handle, zval *name)
{
    GtkLevelBar *self = PHPGTK_ARG_AS(GtkLevelBar, GTK_TYPE_LEVEL_BAR, handle);

    if (self == NULL) {
        return;
    }

    gtk_level_bar_remove_offset_value(self, phpgtk_arg_string(name));
}

void phpgtk_gtklevelbar_set_inverted(zval *handle, zval *inverted)
{
    GtkLevelBar *self = PHPGTK_ARG_AS(GtkLevelBar, GTK_TYPE_LEVEL_BAR, handle);

    if (self == NULL) {
        return;
    }

    gtk_level_bar_set_inverted(self, phpgtk_arg_bool(inverted));
}

void phpgtk_gtklevelbar_set_max_value(zval *handle, zval *value)
{
    GtkLevelBar *self = PHPGTK_ARG_AS(GtkLevelBar, GTK_TYPE_LEVEL_BAR, handle);

    if (self == NULL) {
        return;
    }

    gtk_level_bar_set_max_value(self, phpgtk_arg_double(value));
}

void phpgtk_gtklevelbar_set_min_value(zval *handle, zval *value)
{
    GtkLevelBar *self = PHPGTK_ARG_AS(GtkLevelBar, GTK_TYPE_LEVEL_BAR, handle);

    if (self == NULL) {
        return;
    }

    gtk_level_bar_set_min_value(self, phpgtk_arg_double(value));
}

void phpgtk_gtklevelbar_set_mode(zval *handle, zval *mode)
{
    GtkLevelBar *self = PHPGTK_ARG_AS(GtkLevelBar, GTK_TYPE_LEVEL_BAR, handle);

    if (self == NULL) {
        return;
    }

    gtk_level_bar_set_mode(self, (GtkLevelBarMode) phpgtk_arg_long(mode));
}

void phpgtk_gtklevelbar_set_value(zval *handle, zval *value)
{
    GtkLevelBar *self = PHPGTK_ARG_AS(GtkLevelBar, GTK_TYPE_LEVEL_BAR, handle);

    if (self == NULL) {
        return;
    }

    gtk_level_bar_set_value(self, phpgtk_arg_double(value));
}
