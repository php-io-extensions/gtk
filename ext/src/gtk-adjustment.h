#ifndef PHP_GTK_GTK_ADJUSTMENT_H
#define PHP_GTK_GTK_ADJUSTMENT_H

/*
 * GtkAdjustment — Wave A1. Every gir constructor/method/function is bound
 * or reserved. First-class; never hidden behind a composite.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkAdjustment new(double value, double lower, double upper, double stepIncrement, double pageIncrement, double pageSize) -> int */
zend_long phpgtk_gtkadjustment_new(zval *value, zval *lower, zval *upper, zval *stepIncrement, zval *pageIncrement, zval *pageSize);
/*@zep Gtk\GtkAdjustment clampPage(int handle, double lower, double upper) -> void */
void phpgtk_gtkadjustment_clamp_page(zval *handle, zval *lower, zval *upper);
/*@zep Gtk\GtkAdjustment configure(int handle, double value, double lower, double upper, double stepIncrement, double pageIncrement, double pageSize) -> void */
void phpgtk_gtkadjustment_configure(zval *handle, zval *value, zval *lower, zval *upper, zval *stepIncrement, zval *pageIncrement, zval *pageSize);
/*@zep Gtk\GtkAdjustment getLower(int handle) -> double */
double phpgtk_gtkadjustment_get_lower(zval *handle);
/*@zep Gtk\GtkAdjustment getMinimumIncrement(int handle) -> double */
double phpgtk_gtkadjustment_get_minimum_increment(zval *handle);
/*@zep Gtk\GtkAdjustment getPageIncrement(int handle) -> double */
double phpgtk_gtkadjustment_get_page_increment(zval *handle);
/*@zep Gtk\GtkAdjustment getPageSize(int handle) -> double */
double phpgtk_gtkadjustment_get_page_size(zval *handle);
/*@zep Gtk\GtkAdjustment getStepIncrement(int handle) -> double */
double phpgtk_gtkadjustment_get_step_increment(zval *handle);
/*@zep Gtk\GtkAdjustment getUpper(int handle) -> double */
double phpgtk_gtkadjustment_get_upper(zval *handle);
/*@zep Gtk\GtkAdjustment getValue(int handle) -> double */
double phpgtk_gtkadjustment_get_value(zval *handle);
/*@zep Gtk\GtkAdjustment setLower(int handle, double lower) -> void */
void phpgtk_gtkadjustment_set_lower(zval *handle, zval *lower);
/*@zep Gtk\GtkAdjustment setPageIncrement(int handle, double pageIncrement) -> void */
void phpgtk_gtkadjustment_set_page_increment(zval *handle, zval *pageIncrement);
/*@zep Gtk\GtkAdjustment setPageSize(int handle, double pageSize) -> void */
void phpgtk_gtkadjustment_set_page_size(zval *handle, zval *pageSize);
/*@zep Gtk\GtkAdjustment setStepIncrement(int handle, double stepIncrement) -> void */
void phpgtk_gtkadjustment_set_step_increment(zval *handle, zval *stepIncrement);
/*@zep Gtk\GtkAdjustment setUpper(int handle, double upper) -> void */
void phpgtk_gtkadjustment_set_upper(zval *handle, zval *upper);
/*@zep Gtk\GtkAdjustment setValue(int handle, double value) -> void */
void phpgtk_gtkadjustment_set_value(zval *handle, zval *value);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_ADJUSTMENT_H */
