#ifndef PHP_GTK_GTK_LEVEL_BAR_H
#define PHP_GTK_GTK_LEVEL_BAR_H

/*
 * GtkLevelBar — Wave A6. Every gir constructor/method/function is bound
 * or reserved. get_offset_value's out-param is {value}.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkLevelBar new() -> int */
zend_long phpgtk_gtklevelbar_new(void);
/*@zep Gtk\GtkLevelBar newForInterval(double minValue, double maxValue) -> int */
zend_long phpgtk_gtklevelbar_new_for_interval(zval *minValue, zval *maxValue);
/*@zep Gtk\GtkLevelBar addOffsetValue(int handle, string name, double value) -> void */
void phpgtk_gtklevelbar_add_offset_value(zval *handle, zval *name, zval *value);
/*@zep Gtk\GtkLevelBar getInverted(int handle) -> bool */
zend_long phpgtk_gtklevelbar_get_inverted(zval *handle);
/*@zep Gtk\GtkLevelBar getMaxValue(int handle) -> double */
double phpgtk_gtklevelbar_get_max_value(zval *handle);
/*@zep Gtk\GtkLevelBar getMinValue(int handle) -> double */
double phpgtk_gtklevelbar_get_min_value(zval *handle);
/*@zep Gtk\GtkLevelBar getMode(int handle) -> int */
zend_long phpgtk_gtklevelbar_get_mode(zval *handle);
/*@zep Gtk\GtkLevelBar getOffsetValue(int handle, var name) -> array */
void phpgtk_gtklevelbar_get_offset_value(zval *return_value, zval *handle, zval *name);
/*@zep Gtk\GtkLevelBar getValue(int handle) -> double */
double phpgtk_gtklevelbar_get_value(zval *handle);
/*@zep Gtk\GtkLevelBar removeOffsetValue(int handle, var name) -> void */
void phpgtk_gtklevelbar_remove_offset_value(zval *handle, zval *name);
/*@zep Gtk\GtkLevelBar setInverted(int handle, bool inverted) -> void */
void phpgtk_gtklevelbar_set_inverted(zval *handle, zval *inverted);
/*@zep Gtk\GtkLevelBar setMaxValue(int handle, double value) -> void */
void phpgtk_gtklevelbar_set_max_value(zval *handle, zval *value);
/*@zep Gtk\GtkLevelBar setMinValue(int handle, double value) -> void */
void phpgtk_gtklevelbar_set_min_value(zval *handle, zval *value);
/*@zep Gtk\GtkLevelBar setMode(int handle, int mode) -> void */
void phpgtk_gtklevelbar_set_mode(zval *handle, zval *mode);
/*@zep Gtk\GtkLevelBar setValue(int handle, double value) -> void */
void phpgtk_gtklevelbar_set_value(zval *handle, zval *value);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_LEVEL_BAR_H */
