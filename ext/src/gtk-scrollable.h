#ifndef PHP_GTK_GTK_SCROLLABLE_H
#define PHP_GTK_GTK_SCROLLABLE_H

/*
 * GtkScrollable — Wave A8 interface. Bound as its own class; first
 * implementor in this wave is GtkViewport. Every gir method/function is
 * bound or reserved. get_border's out-param is {left, right, top, bottom}.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkScrollable getBorder(int handle) -> array */
void phpgtk_gtkscrollable_get_border(zval *return_value, zval *handle);
/*@zep Gtk\GtkScrollable getHadjustment(int handle) -> int */
zend_long phpgtk_gtkscrollable_get_hadjustment(zval *handle);
/*@zep Gtk\GtkScrollable getHscrollPolicy(int handle) -> int */
zend_long phpgtk_gtkscrollable_get_hscroll_policy(zval *handle);
/*@zep Gtk\GtkScrollable getVadjustment(int handle) -> int */
zend_long phpgtk_gtkscrollable_get_vadjustment(zval *handle);
/*@zep Gtk\GtkScrollable getVscrollPolicy(int handle) -> int */
zend_long phpgtk_gtkscrollable_get_vscroll_policy(zval *handle);
/*@zep Gtk\GtkScrollable setHadjustment(int handle, int hadjustment) -> void */
void phpgtk_gtkscrollable_set_hadjustment(zval *handle, zval *hadjustment);
/*@zep Gtk\GtkScrollable setHscrollPolicy(int handle, int policy) -> void */
void phpgtk_gtkscrollable_set_hscroll_policy(zval *handle, zval *policy);
/*@zep Gtk\GtkScrollable setVadjustment(int handle, int vadjustment) -> void */
void phpgtk_gtkscrollable_set_vadjustment(zval *handle, zval *vadjustment);
/*@zep Gtk\GtkScrollable setVscrollPolicy(int handle, int policy) -> void */
void phpgtk_gtkscrollable_set_vscroll_policy(zval *handle, zval *policy);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_SCROLLABLE_H */
