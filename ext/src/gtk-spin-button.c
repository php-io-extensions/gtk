#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-spin-button.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkspinbutton_new(zval *adjustment, zval *climbRate, zval *digits)
{
    return phpgtk_handle_register(gtk_spin_button_new(phpgtk_arg_object(adjustment), phpgtk_arg_double(climbRate), (guint) phpgtk_arg_long(digits)));
}

zend_long phpgtk_gtkspinbutton_new_with_range(zval *min, zval *max, zval *step)
{
    return phpgtk_handle_register(gtk_spin_button_new_with_range(phpgtk_arg_double(min), phpgtk_arg_double(max), phpgtk_arg_double(step)));
}

void phpgtk_gtkspinbutton_configure(zval *handle, zval *adjustment, zval *climbRate, zval *digits)
{
    GtkSpinButton *self = PHPGTK_ARG_AS(GtkSpinButton, GTK_TYPE_SPIN_BUTTON, handle);

    if (self == NULL) {
        return;
    }

    gtk_spin_button_configure(self, phpgtk_arg_object(adjustment), phpgtk_arg_double(climbRate), (guint) phpgtk_arg_long(digits));
}

zend_long phpgtk_gtkspinbutton_get_activates_default(zval *handle)
{
    GtkSpinButton *self = PHPGTK_ARG_AS(GtkSpinButton, GTK_TYPE_SPIN_BUTTON, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_spin_button_get_activates_default(self) ? 1 : 0;
}

zend_long phpgtk_gtkspinbutton_get_adjustment(zval *handle)
{
    GtkSpinButton *self = PHPGTK_ARG_AS(GtkSpinButton, GTK_TYPE_SPIN_BUTTON, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_spin_button_get_adjustment(self));
}

double phpgtk_gtkspinbutton_get_climb_rate(zval *handle)
{
    GtkSpinButton *self = PHPGTK_ARG_AS(GtkSpinButton, GTK_TYPE_SPIN_BUTTON, handle);

    if (self == NULL) {
        return 0.0;
    }

    return gtk_spin_button_get_climb_rate(self);
}

zend_long phpgtk_gtkspinbutton_get_digits(zval *handle)
{
    GtkSpinButton *self = PHPGTK_ARG_AS(GtkSpinButton, GTK_TYPE_SPIN_BUTTON, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_spin_button_get_digits(self);
}

void phpgtk_gtkspinbutton_get_increments(zval *return_value, zval *handle)
{
    GtkSpinButton *self = PHPGTK_ARG_AS(GtkSpinButton, GTK_TYPE_SPIN_BUTTON, handle);
    double step = 0.0;
    double page = 0.0;

    if (self == NULL) {
        array_init(return_value); return;
    }

    gtk_spin_button_get_increments(self, &step, &page);
    array_init(return_value);
    add_assoc_double(return_value, "step", (double) step);
    add_assoc_double(return_value, "page", (double) page);
}

zend_long phpgtk_gtkspinbutton_get_numeric(zval *handle)
{
    GtkSpinButton *self = PHPGTK_ARG_AS(GtkSpinButton, GTK_TYPE_SPIN_BUTTON, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_spin_button_get_numeric(self) ? 1 : 0;
}

void phpgtk_gtkspinbutton_get_range(zval *return_value, zval *handle)
{
    GtkSpinButton *self = PHPGTK_ARG_AS(GtkSpinButton, GTK_TYPE_SPIN_BUTTON, handle);
    double min = 0.0;
    double max = 0.0;

    if (self == NULL) {
        array_init(return_value); return;
    }

    gtk_spin_button_get_range(self, &min, &max);
    array_init(return_value);
    add_assoc_double(return_value, "min", (double) min);
    add_assoc_double(return_value, "max", (double) max);
}

zend_long phpgtk_gtkspinbutton_get_snap_to_ticks(zval *handle)
{
    GtkSpinButton *self = PHPGTK_ARG_AS(GtkSpinButton, GTK_TYPE_SPIN_BUTTON, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_spin_button_get_snap_to_ticks(self) ? 1 : 0;
}

zend_long phpgtk_gtkspinbutton_get_update_policy(zval *handle)
{
    GtkSpinButton *self = PHPGTK_ARG_AS(GtkSpinButton, GTK_TYPE_SPIN_BUTTON, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_spin_button_get_update_policy(self);
}

double phpgtk_gtkspinbutton_get_value(zval *handle)
{
    GtkSpinButton *self = PHPGTK_ARG_AS(GtkSpinButton, GTK_TYPE_SPIN_BUTTON, handle);

    if (self == NULL) {
        return 0.0;
    }

    return gtk_spin_button_get_value(self);
}

zend_long phpgtk_gtkspinbutton_get_value_as_int(zval *handle)
{
    GtkSpinButton *self = PHPGTK_ARG_AS(GtkSpinButton, GTK_TYPE_SPIN_BUTTON, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_spin_button_get_value_as_int(self);
}

zend_long phpgtk_gtkspinbutton_get_wrap(zval *handle)
{
    GtkSpinButton *self = PHPGTK_ARG_AS(GtkSpinButton, GTK_TYPE_SPIN_BUTTON, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_spin_button_get_wrap(self) ? 1 : 0;
}

void phpgtk_gtkspinbutton_set_activates_default(zval *handle, zval *activatesDefault)
{
    GtkSpinButton *self = PHPGTK_ARG_AS(GtkSpinButton, GTK_TYPE_SPIN_BUTTON, handle);

    if (self == NULL) {
        return;
    }

    gtk_spin_button_set_activates_default(self, phpgtk_arg_bool(activatesDefault));
}

void phpgtk_gtkspinbutton_set_adjustment(zval *handle, zval *adjustment)
{
    GtkSpinButton *self = PHPGTK_ARG_AS(GtkSpinButton, GTK_TYPE_SPIN_BUTTON, handle);

    if (self == NULL) {
        return;
    }

    gtk_spin_button_set_adjustment(self, phpgtk_arg_object(adjustment));
}

void phpgtk_gtkspinbutton_set_climb_rate(zval *handle, zval *climbRate)
{
    GtkSpinButton *self = PHPGTK_ARG_AS(GtkSpinButton, GTK_TYPE_SPIN_BUTTON, handle);

    if (self == NULL) {
        return;
    }

    gtk_spin_button_set_climb_rate(self, phpgtk_arg_double(climbRate));
}

void phpgtk_gtkspinbutton_set_digits(zval *handle, zval *digits)
{
    GtkSpinButton *self = PHPGTK_ARG_AS(GtkSpinButton, GTK_TYPE_SPIN_BUTTON, handle);

    if (self == NULL) {
        return;
    }

    gtk_spin_button_set_digits(self, (guint) phpgtk_arg_long(digits));
}

void phpgtk_gtkspinbutton_set_increments(zval *handle, zval *step, zval *page)
{
    GtkSpinButton *self = PHPGTK_ARG_AS(GtkSpinButton, GTK_TYPE_SPIN_BUTTON, handle);

    if (self == NULL) {
        return;
    }

    gtk_spin_button_set_increments(self, phpgtk_arg_double(step), phpgtk_arg_double(page));
}

void phpgtk_gtkspinbutton_set_numeric(zval *handle, zval *numeric)
{
    GtkSpinButton *self = PHPGTK_ARG_AS(GtkSpinButton, GTK_TYPE_SPIN_BUTTON, handle);

    if (self == NULL) {
        return;
    }

    gtk_spin_button_set_numeric(self, phpgtk_arg_bool(numeric));
}

void phpgtk_gtkspinbutton_set_range(zval *handle, zval *min, zval *max)
{
    GtkSpinButton *self = PHPGTK_ARG_AS(GtkSpinButton, GTK_TYPE_SPIN_BUTTON, handle);

    if (self == NULL) {
        return;
    }

    gtk_spin_button_set_range(self, phpgtk_arg_double(min), phpgtk_arg_double(max));
}

void phpgtk_gtkspinbutton_set_snap_to_ticks(zval *handle, zval *snapToTicks)
{
    GtkSpinButton *self = PHPGTK_ARG_AS(GtkSpinButton, GTK_TYPE_SPIN_BUTTON, handle);

    if (self == NULL) {
        return;
    }

    gtk_spin_button_set_snap_to_ticks(self, phpgtk_arg_bool(snapToTicks));
}

void phpgtk_gtkspinbutton_set_update_policy(zval *handle, zval *policy)
{
    GtkSpinButton *self = PHPGTK_ARG_AS(GtkSpinButton, GTK_TYPE_SPIN_BUTTON, handle);

    if (self == NULL) {
        return;
    }

    gtk_spin_button_set_update_policy(self, (GtkSpinButtonUpdatePolicy) phpgtk_arg_long(policy));
}

void phpgtk_gtkspinbutton_set_value(zval *handle, zval *value)
{
    GtkSpinButton *self = PHPGTK_ARG_AS(GtkSpinButton, GTK_TYPE_SPIN_BUTTON, handle);

    if (self == NULL) {
        return;
    }

    gtk_spin_button_set_value(self, phpgtk_arg_double(value));
}

void phpgtk_gtkspinbutton_set_wrap(zval *handle, zval *wrap)
{
    GtkSpinButton *self = PHPGTK_ARG_AS(GtkSpinButton, GTK_TYPE_SPIN_BUTTON, handle);

    if (self == NULL) {
        return;
    }

    gtk_spin_button_set_wrap(self, phpgtk_arg_bool(wrap));
}

void phpgtk_gtkspinbutton_spin(zval *handle, zval *direction, zval *increment)
{
    GtkSpinButton *self = PHPGTK_ARG_AS(GtkSpinButton, GTK_TYPE_SPIN_BUTTON, handle);

    if (self == NULL) {
        return;
    }

    gtk_spin_button_spin(self, (GtkSpinType) phpgtk_arg_long(direction), phpgtk_arg_double(increment));
}

void phpgtk_gtkspinbutton_update(zval *handle)
{
    GtkSpinButton *self = PHPGTK_ARG_AS(GtkSpinButton, GTK_TYPE_SPIN_BUTTON, handle);

    if (self == NULL) {
        return;
    }

    gtk_spin_button_update(self);
}
