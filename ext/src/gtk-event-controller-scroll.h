#ifndef PHP_GTK_GTK_EVENT_CONTROLLER_SCROLL_H
#define PHP_GTK_GTK_EVENT_CONTROLLER_SCROLL_H

/*
 * GtkEventControllerScroll — input wave. Every gir constructor/method/
 * function is bound or reserved. Constructor is transfer-full and takes
 * the GtkEventControllerScrollFlags int.
 *
 * getUnit (GTK 4.8) answers the GdkScrollUnit of the last scroll event
 * (0 = wheel, 1 = surface pixels).
 *
 * Signals are Bridge territory (Bridge::connect): scroll (dx, dy) -> bool,
 * scroll-begin (), scroll-end (), decelerate (vel_x, vel_y).
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkEventControllerScroll new(int flags) -> int */
zend_long phpgtk_gtkeventcontrollerscroll_new(zval *flags);
/*@zep Gtk\GtkEventControllerScroll getFlags(int handle) -> int */
zend_long phpgtk_gtkeventcontrollerscroll_get_flags(zval *handle);
/*@zep Gtk\GtkEventControllerScroll getUnit(int handle) -> int */
zend_long phpgtk_gtkeventcontrollerscroll_get_unit(zval *handle);
/*@zep Gtk\GtkEventControllerScroll setFlags(int handle, int flags) -> void */
void phpgtk_gtkeventcontrollerscroll_set_flags(zval *handle, zval *flags);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_EVENT_CONTROLLER_SCROLL_H */
