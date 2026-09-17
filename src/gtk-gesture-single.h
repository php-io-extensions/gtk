#ifndef PHP_GTK_GTK_GESTURE_SINGLE_H
#define PHP_GTK_GTK_GESTURE_SINGLE_H

/*
 * GtkGestureSingle — input wave. Every gir constructor/method/function is
 * bound or reserved. No gir constructor: obtain a concrete subclass
 * (GtkGestureClick) and call these on its handle.
 *
 * get_current_sequence is reserved: GdkEventSequence* is an opaque boxed
 * pointer the handle registry cannot hold.
 *
 * getButton / setButton: 0 = any button, 1 = primary (GDK_BUTTON_PRIMARY).
 * getCurrentButton: the button of the ongoing interaction, 0 when none.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkGestureSingle getButton(int handle) -> int */
zend_long phpgtk_gtkgesturesingle_get_button(zval *handle);
/*@zep Gtk\GtkGestureSingle getCurrentButton(int handle) -> int */
zend_long phpgtk_gtkgesturesingle_get_current_button(zval *handle);
/*@reserved Gtk\GtkGestureSingle gtk_gesture_single_get_current_sequence(GtkGestureSingle* gesture) — GdkEventSequence* */
/*@zep Gtk\GtkGestureSingle getExclusive(int handle) -> bool */
zend_long phpgtk_gtkgesturesingle_get_exclusive(zval *handle);
/*@zep Gtk\GtkGestureSingle getTouchOnly(int handle) -> bool */
zend_long phpgtk_gtkgesturesingle_get_touch_only(zval *handle);
/*@zep Gtk\GtkGestureSingle setButton(int handle, int button) -> void */
void phpgtk_gtkgesturesingle_set_button(zval *handle, zval *button);
/*@zep Gtk\GtkGestureSingle setExclusive(int handle, bool exclusive) -> void */
void phpgtk_gtkgesturesingle_set_exclusive(zval *handle, zval *exclusive);
/*@zep Gtk\GtkGestureSingle setTouchOnly(int handle, bool touchOnly) -> void */
void phpgtk_gtkgesturesingle_set_touch_only(zval *handle, zval *touchOnly);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_GESTURE_SINGLE_H */
