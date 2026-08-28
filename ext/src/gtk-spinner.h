#ifndef PHP_GTK_GTK_SPINNER_H
#define PHP_GTK_GTK_SPINNER_H

/*
 * GtkSpinner — Wave A6. Every gir constructor/method/function is bound
 * or reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkSpinner new() -> int */
zend_long phpgtk_gtkspinner_new(void);
/*@zep Gtk\GtkSpinner getSpinning(int handle) -> bool */
zend_long phpgtk_gtkspinner_get_spinning(zval *handle);
/*@zep Gtk\GtkSpinner setSpinning(int handle, bool spinning) -> void */
void phpgtk_gtkspinner_set_spinning(zval *handle, zval *spinning);
/*@zep Gtk\GtkSpinner start(int handle) -> void */
void phpgtk_gtkspinner_start(zval *handle);
/*@zep Gtk\GtkSpinner stop(int handle) -> void */
void phpgtk_gtkspinner_stop(zval *handle);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_SPINNER_H */
