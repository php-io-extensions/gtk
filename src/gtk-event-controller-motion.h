#ifndef PHP_GTK_GTK_EVENT_CONTROLLER_MOTION_H
#define PHP_GTK_GTK_EVENT_CONTROLLER_MOTION_H

/*
 * GtkEventControllerMotion — input wave. Every gir constructor/method/
 * function is bound or reserved. Constructor is transfer-full.
 *
 * Signals are Bridge territory (Bridge::connect): motion (x, y),
 * enter (x, y), leave (). Coordinates are widget-relative doubles.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkEventControllerMotion new() -> int */
zend_long phpgtk_gtkeventcontrollermotion_new(void);
/*@zep Gtk\GtkEventControllerMotion containsPointer(int handle) -> bool */
zend_long phpgtk_gtkeventcontrollermotion_contains_pointer(zval *handle);
/*@zep Gtk\GtkEventControllerMotion isPointer(int handle) -> bool */
zend_long phpgtk_gtkeventcontrollermotion_is_pointer(zval *handle);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_EVENT_CONTROLLER_MOTION_H */
