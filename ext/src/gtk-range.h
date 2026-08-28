#ifndef PHP_GTK_GTK_RANGE_H
#define PHP_GTK_GTK_RANGE_H

/*
 * GtkRange — Wave A4. Every gir constructor/method/function is bound
 * or reserved. No gir constructor; first customer of the obtain-only
 * construction-exemption whitelist.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkRange getAdjustment(int handle) -> int */
zend_long phpgtk_gtkrange_get_adjustment(zval *handle);
/*@zep Gtk\GtkRange getFillLevel(int handle) -> double */
double phpgtk_gtkrange_get_fill_level(zval *handle);
/*@zep Gtk\GtkRange getFlippable(int handle) -> bool */
zend_long phpgtk_gtkrange_get_flippable(zval *handle);
/*@zep Gtk\GtkRange getInverted(int handle) -> bool */
zend_long phpgtk_gtkrange_get_inverted(zval *handle);
/*@zep Gtk\GtkRange getRangeRect(int handle) -> array */
void phpgtk_gtkrange_get_range_rect(zval *return_value, zval *handle);
/*@zep Gtk\GtkRange getRestrictToFillLevel(int handle) -> bool */
zend_long phpgtk_gtkrange_get_restrict_to_fill_level(zval *handle);
/*@zep Gtk\GtkRange getRoundDigits(int handle) -> int */
zend_long phpgtk_gtkrange_get_round_digits(zval *handle);
/*@zep Gtk\GtkRange getShowFillLevel(int handle) -> bool */
zend_long phpgtk_gtkrange_get_show_fill_level(zval *handle);
/*@zep Gtk\GtkRange getSliderRange(int handle) -> array */
void phpgtk_gtkrange_get_slider_range(zval *return_value, zval *handle);
/*@zep Gtk\GtkRange getSliderSizeFixed(int handle) -> bool */
zend_long phpgtk_gtkrange_get_slider_size_fixed(zval *handle);
/*@zep Gtk\GtkRange getValue(int handle) -> double */
double phpgtk_gtkrange_get_value(zval *handle);
/*@zep Gtk\GtkRange setAdjustment(int handle, int adjustment) -> void */
void phpgtk_gtkrange_set_adjustment(zval *handle, zval *adjustment);
/*@zep Gtk\GtkRange setFillLevel(int handle, double fillLevel) -> void */
void phpgtk_gtkrange_set_fill_level(zval *handle, zval *fillLevel);
/*@zep Gtk\GtkRange setFlippable(int handle, bool flippable) -> void */
void phpgtk_gtkrange_set_flippable(zval *handle, zval *flippable);
/*@zep Gtk\GtkRange setIncrements(int handle, double step, double page) -> void */
void phpgtk_gtkrange_set_increments(zval *handle, zval *step, zval *page);
/*@zep Gtk\GtkRange setInverted(int handle, bool setting) -> void */
void phpgtk_gtkrange_set_inverted(zval *handle, zval *setting);
/*@zep Gtk\GtkRange setRange(int handle, double min, double max) -> void */
void phpgtk_gtkrange_set_range(zval *handle, zval *min, zval *max);
/*@zep Gtk\GtkRange setRestrictToFillLevel(int handle, bool restrictToFillLevel) -> void */
void phpgtk_gtkrange_set_restrict_to_fill_level(zval *handle, zval *restrictToFillLevel);
/*@zep Gtk\GtkRange setRoundDigits(int handle, int roundDigits) -> void */
void phpgtk_gtkrange_set_round_digits(zval *handle, zval *roundDigits);
/*@zep Gtk\GtkRange setShowFillLevel(int handle, bool showFillLevel) -> void */
void phpgtk_gtkrange_set_show_fill_level(zval *handle, zval *showFillLevel);
/*@zep Gtk\GtkRange setSliderSizeFixed(int handle, bool sizeFixed) -> void */
void phpgtk_gtkrange_set_slider_size_fixed(zval *handle, zval *sizeFixed);
/*@zep Gtk\GtkRange setValue(int handle, double value) -> void */
void phpgtk_gtkrange_set_value(zval *handle, zval *value);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_RANGE_H */
