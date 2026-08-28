#ifndef PHP_GTK_GTK_SCROLLBAR_H
#define PHP_GTK_GTK_SCROLLBAR_H

/*
 * GtkScrollbar — Wave A4. Every gir constructor/method/function is
 * bound or reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkScrollbar new(int orientation, int adjustment) -> int */
zend_long phpgtk_gtkscrollbar_new(zval *orientation, zval *adjustment);
/*@zep Gtk\GtkScrollbar getAdjustment(int handle) -> int */
zend_long phpgtk_gtkscrollbar_get_adjustment(zval *handle);
/*@zep Gtk\GtkScrollbar setAdjustment(int handle, int adjustment) -> void */
void phpgtk_gtkscrollbar_set_adjustment(zval *handle, zval *adjustment);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_SCROLLBAR_H */
