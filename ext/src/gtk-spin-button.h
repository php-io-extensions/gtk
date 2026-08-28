#ifndef PHP_GTK_GTK_SPIN_BUTTON_H
#define PHP_GTK_GTK_SPIN_BUTTON_H

/*
 * GtkSpinButton — Wave A4. Every gir constructor/method/function is
 * bound or reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkSpinButton new(int adjustment, double climbRate, int digits) -> int */
zend_long phpgtk_gtkspinbutton_new(zval *adjustment, zval *climbRate, zval *digits);
/*@zep Gtk\GtkSpinButton newWithRange(double min, double max, double step) -> int */
zend_long phpgtk_gtkspinbutton_new_with_range(zval *min, zval *max, zval *step);
/*@zep Gtk\GtkSpinButton configure(int handle, int adjustment, double climbRate, int digits) -> void */
void phpgtk_gtkspinbutton_configure(zval *handle, zval *adjustment, zval *climbRate, zval *digits);
/*@zep Gtk\GtkSpinButton getActivatesDefault(int handle) -> bool */
zend_long phpgtk_gtkspinbutton_get_activates_default(zval *handle);
/*@zep Gtk\GtkSpinButton getAdjustment(int handle) -> int */
zend_long phpgtk_gtkspinbutton_get_adjustment(zval *handle);
/*@zep Gtk\GtkSpinButton getClimbRate(int handle) -> double */
double phpgtk_gtkspinbutton_get_climb_rate(zval *handle);
/*@zep Gtk\GtkSpinButton getDigits(int handle) -> int */
zend_long phpgtk_gtkspinbutton_get_digits(zval *handle);
/*@zep Gtk\GtkSpinButton getIncrements(int handle) -> array */
void phpgtk_gtkspinbutton_get_increments(zval *return_value, zval *handle);
/*@zep Gtk\GtkSpinButton getNumeric(int handle) -> bool */
zend_long phpgtk_gtkspinbutton_get_numeric(zval *handle);
/*@zep Gtk\GtkSpinButton getRange(int handle) -> array */
void phpgtk_gtkspinbutton_get_range(zval *return_value, zval *handle);
/*@zep Gtk\GtkSpinButton getSnapToTicks(int handle) -> bool */
zend_long phpgtk_gtkspinbutton_get_snap_to_ticks(zval *handle);
/*@zep Gtk\GtkSpinButton getUpdatePolicy(int handle) -> int */
zend_long phpgtk_gtkspinbutton_get_update_policy(zval *handle);
/*@zep Gtk\GtkSpinButton getValue(int handle) -> double */
double phpgtk_gtkspinbutton_get_value(zval *handle);
/*@zep Gtk\GtkSpinButton getValueAsInt(int handle) -> int */
zend_long phpgtk_gtkspinbutton_get_value_as_int(zval *handle);
/*@zep Gtk\GtkSpinButton getWrap(int handle) -> bool */
zend_long phpgtk_gtkspinbutton_get_wrap(zval *handle);
/*@zep Gtk\GtkSpinButton setActivatesDefault(int handle, bool activatesDefault) -> void */
void phpgtk_gtkspinbutton_set_activates_default(zval *handle, zval *activatesDefault);
/*@zep Gtk\GtkSpinButton setAdjustment(int handle, int adjustment) -> void */
void phpgtk_gtkspinbutton_set_adjustment(zval *handle, zval *adjustment);
/*@zep Gtk\GtkSpinButton setClimbRate(int handle, double climbRate) -> void */
void phpgtk_gtkspinbutton_set_climb_rate(zval *handle, zval *climbRate);
/*@zep Gtk\GtkSpinButton setDigits(int handle, int digits) -> void */
void phpgtk_gtkspinbutton_set_digits(zval *handle, zval *digits);
/*@zep Gtk\GtkSpinButton setIncrements(int handle, double step, double page) -> void */
void phpgtk_gtkspinbutton_set_increments(zval *handle, zval *step, zval *page);
/*@zep Gtk\GtkSpinButton setNumeric(int handle, bool numeric) -> void */
void phpgtk_gtkspinbutton_set_numeric(zval *handle, zval *numeric);
/*@zep Gtk\GtkSpinButton setRange(int handle, double min, double max) -> void */
void phpgtk_gtkspinbutton_set_range(zval *handle, zval *min, zval *max);
/*@zep Gtk\GtkSpinButton setSnapToTicks(int handle, bool snapToTicks) -> void */
void phpgtk_gtkspinbutton_set_snap_to_ticks(zval *handle, zval *snapToTicks);
/*@zep Gtk\GtkSpinButton setUpdatePolicy(int handle, int policy) -> void */
void phpgtk_gtkspinbutton_set_update_policy(zval *handle, zval *policy);
/*@zep Gtk\GtkSpinButton setValue(int handle, double value) -> void */
void phpgtk_gtkspinbutton_set_value(zval *handle, zval *value);
/*@zep Gtk\GtkSpinButton setWrap(int handle, bool wrap) -> void */
void phpgtk_gtkspinbutton_set_wrap(zval *handle, zval *wrap);
/*@zep Gtk\GtkSpinButton spin(int handle, int direction, double increment) -> void */
void phpgtk_gtkspinbutton_spin(zval *handle, zval *direction, zval *increment);
/*@zep Gtk\GtkSpinButton update(int handle) -> void */
void phpgtk_gtkspinbutton_update(zval *handle);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_SPIN_BUTTON_H */
