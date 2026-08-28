#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-progress-bar.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkprogressbar_new(void)
{
    return phpgtk_handle_register(gtk_progress_bar_new());
}

zend_long phpgtk_gtkprogressbar_get_ellipsize(zval *handle)
{
    GtkProgressBar *self = PHPGTK_ARG_AS(GtkProgressBar, GTK_TYPE_PROGRESS_BAR, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_progress_bar_get_ellipsize(self);
}

double phpgtk_gtkprogressbar_get_fraction(zval *handle)
{
    GtkProgressBar *self = PHPGTK_ARG_AS(GtkProgressBar, GTK_TYPE_PROGRESS_BAR, handle);

    if (self == NULL) {
        return 0.0;
    }

    return gtk_progress_bar_get_fraction(self);
}

zend_long phpgtk_gtkprogressbar_get_inverted(zval *handle)
{
    GtkProgressBar *self = PHPGTK_ARG_AS(GtkProgressBar, GTK_TYPE_PROGRESS_BAR, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_progress_bar_get_inverted(self) ? 1 : 0;
}

double phpgtk_gtkprogressbar_get_pulse_step(zval *handle)
{
    GtkProgressBar *self = PHPGTK_ARG_AS(GtkProgressBar, GTK_TYPE_PROGRESS_BAR, handle);

    if (self == NULL) {
        return 0.0;
    }

    return gtk_progress_bar_get_pulse_step(self);
}

zend_long phpgtk_gtkprogressbar_get_show_text(zval *handle)
{
    GtkProgressBar *self = PHPGTK_ARG_AS(GtkProgressBar, GTK_TYPE_PROGRESS_BAR, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_progress_bar_get_show_text(self) ? 1 : 0;
}

void phpgtk_gtkprogressbar_get_text(zval *return_value, zval *handle)
{
    GtkProgressBar *self = PHPGTK_ARG_AS(GtkProgressBar, GTK_TYPE_PROGRESS_BAR, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_progress_bar_get_text(self));
}

void phpgtk_gtkprogressbar_pulse(zval *handle)
{
    GtkProgressBar *self = PHPGTK_ARG_AS(GtkProgressBar, GTK_TYPE_PROGRESS_BAR, handle);

    if (self == NULL) {
        return;
    }

    gtk_progress_bar_pulse(self);
}

void phpgtk_gtkprogressbar_set_ellipsize(zval *handle, zval *mode)
{
    GtkProgressBar *self = PHPGTK_ARG_AS(GtkProgressBar, GTK_TYPE_PROGRESS_BAR, handle);

    if (self == NULL) {
        return;
    }

    gtk_progress_bar_set_ellipsize(self, (PangoEllipsizeMode) phpgtk_arg_long(mode));
}

void phpgtk_gtkprogressbar_set_fraction(zval *handle, zval *fraction)
{
    GtkProgressBar *self = PHPGTK_ARG_AS(GtkProgressBar, GTK_TYPE_PROGRESS_BAR, handle);

    if (self == NULL) {
        return;
    }

    gtk_progress_bar_set_fraction(self, phpgtk_arg_double(fraction));
}

void phpgtk_gtkprogressbar_set_inverted(zval *handle, zval *inverted)
{
    GtkProgressBar *self = PHPGTK_ARG_AS(GtkProgressBar, GTK_TYPE_PROGRESS_BAR, handle);

    if (self == NULL) {
        return;
    }

    gtk_progress_bar_set_inverted(self, phpgtk_arg_bool(inverted));
}

void phpgtk_gtkprogressbar_set_pulse_step(zval *handle, zval *fraction)
{
    GtkProgressBar *self = PHPGTK_ARG_AS(GtkProgressBar, GTK_TYPE_PROGRESS_BAR, handle);

    if (self == NULL) {
        return;
    }

    gtk_progress_bar_set_pulse_step(self, phpgtk_arg_double(fraction));
}

void phpgtk_gtkprogressbar_set_show_text(zval *handle, zval *showText)
{
    GtkProgressBar *self = PHPGTK_ARG_AS(GtkProgressBar, GTK_TYPE_PROGRESS_BAR, handle);

    if (self == NULL) {
        return;
    }

    gtk_progress_bar_set_show_text(self, phpgtk_arg_bool(showText));
}

void phpgtk_gtkprogressbar_set_text(zval *handle, zval *text)
{
    GtkProgressBar *self = PHPGTK_ARG_AS(GtkProgressBar, GTK_TYPE_PROGRESS_BAR, handle);

    if (self == NULL) {
        return;
    }

    gtk_progress_bar_set_text(self, phpgtk_arg_string(text));
}
