#ifndef PHP_GTK_GTK_EVENT_CONTROLLER_KEY_H
#define PHP_GTK_GTK_EVENT_CONTROLLER_KEY_H

/*
 * GtkEventControllerKey — input wave. Every gir constructor/method/function
 * is bound or reserved. Constructor is transfer-full.
 *
 * Signals are Bridge territory (Bridge::connect): key-pressed
 * (keyval, keycode, state) -> bool, key-released (keyval, keycode, state),
 * modifiers (state) -> bool, im-update (). A PHP bool return reaches the
 * gboolean signal return through the closure's writeback.
 *
 * getGroup belongs inside a key handler: GTK asserts a current event.
 *
 * getImContext / setImContext cross a GtkIMContext handle (0 = NULL).
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkEventControllerKey new() -> int */
zend_long phpgtk_gtkeventcontrollerkey_new(void);
/*@zep Gtk\GtkEventControllerKey forward(int handle, int widget) -> bool */
zend_long phpgtk_gtkeventcontrollerkey_forward(zval *handle, zval *widget);
/*@zep Gtk\GtkEventControllerKey getGroup(int handle) -> int */
zend_long phpgtk_gtkeventcontrollerkey_get_group(zval *handle);
/*@zep Gtk\GtkEventControllerKey getImContext(int handle) -> int */
zend_long phpgtk_gtkeventcontrollerkey_get_im_context(zval *handle);
/*@zep Gtk\GtkEventControllerKey setImContext(int handle, int imContext) -> void */
void phpgtk_gtkeventcontrollerkey_set_im_context(zval *handle, zval *imContext);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_EVENT_CONTROLLER_KEY_H */
