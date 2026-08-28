#ifndef PHP_GTK_GTK_SWITCH_H
#define PHP_GTK_GTK_SWITCH_H

/*
 * GtkSwitch — Wave A3. Every gir constructor/method/function is bound or
 * reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkSwitch new() -> int */
zend_long phpgtk_gtkswitch_new(void);
/*@zep Gtk\GtkSwitch getActive(int handle) -> bool */
zend_long phpgtk_gtkswitch_get_active(zval *handle);
/*@zep Gtk\GtkSwitch getState(int handle) -> bool */
zend_long phpgtk_gtkswitch_get_state(zval *handle);
/*@zep Gtk\GtkSwitch setActive(int handle, bool isActive) -> void */
void phpgtk_gtkswitch_set_active(zval *handle, zval *isActive);
/*@zep Gtk\GtkSwitch setState(int handle, bool state) -> void */
void phpgtk_gtkswitch_set_state(zval *handle, zval *state);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_SWITCH_H */
