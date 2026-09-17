#ifndef PHP_GTK_GTK_GESTURE_CLICK_H
#define PHP_GTK_GTK_GESTURE_CLICK_H

/*
 * GtkGestureClick — input wave. Every gir constructor/method/function is
 * bound or reserved. Constructor is transfer-full; button selection lives
 * on GtkGestureSingle.
 *
 * Signals are Bridge territory (Bridge::connect): pressed / released
 * (n_press, x, y), stopped (), unpaired-release (x, y, button, sequence —
 * the sequence arrives as a raw pointer int).
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkGestureClick new() -> int */
zend_long phpgtk_gtkgestureclick_new(void);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_GESTURE_CLICK_H */
