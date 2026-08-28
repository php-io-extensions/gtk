#ifndef PHP_GTK_GTK_PROGRESS_BAR_H
#define PHP_GTK_GTK_PROGRESS_BAR_H

/*
 * GtkProgressBar — Wave A6. Every gir constructor/method/function is bound
 * or reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkProgressBar new() -> int */
zend_long phpgtk_gtkprogressbar_new(void);
/*@zep Gtk\GtkProgressBar getEllipsize(int handle) -> int */
zend_long phpgtk_gtkprogressbar_get_ellipsize(zval *handle);
/*@zep Gtk\GtkProgressBar getFraction(int handle) -> double */
double phpgtk_gtkprogressbar_get_fraction(zval *handle);
/*@zep Gtk\GtkProgressBar getInverted(int handle) -> bool */
zend_long phpgtk_gtkprogressbar_get_inverted(zval *handle);
/*@zep Gtk\GtkProgressBar getPulseStep(int handle) -> double */
double phpgtk_gtkprogressbar_get_pulse_step(zval *handle);
/*@zep Gtk\GtkProgressBar getShowText(int handle) -> bool */
zend_long phpgtk_gtkprogressbar_get_show_text(zval *handle);
/*@zep Gtk\GtkProgressBar getText(int handle) -> var */
void phpgtk_gtkprogressbar_get_text(zval *return_value, zval *handle);
/*@zep Gtk\GtkProgressBar pulse(int handle) -> void */
void phpgtk_gtkprogressbar_pulse(zval *handle);
/*@zep Gtk\GtkProgressBar setEllipsize(int handle, int mode) -> void */
void phpgtk_gtkprogressbar_set_ellipsize(zval *handle, zval *mode);
/*@zep Gtk\GtkProgressBar setFraction(int handle, double fraction) -> void */
void phpgtk_gtkprogressbar_set_fraction(zval *handle, zval *fraction);
/*@zep Gtk\GtkProgressBar setInverted(int handle, bool inverted) -> void */
void phpgtk_gtkprogressbar_set_inverted(zval *handle, zval *inverted);
/*@zep Gtk\GtkProgressBar setPulseStep(int handle, double fraction) -> void */
void phpgtk_gtkprogressbar_set_pulse_step(zval *handle, zval *fraction);
/*@zep Gtk\GtkProgressBar setShowText(int handle, bool showText) -> void */
void phpgtk_gtkprogressbar_set_show_text(zval *handle, zval *showText);
/*@zep Gtk\GtkProgressBar setText(int handle, var text) -> void */
void phpgtk_gtkprogressbar_set_text(zval *handle, zval *text);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_PROGRESS_BAR_H */
