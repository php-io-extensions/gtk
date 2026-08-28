#ifndef PHP_GTK_GTK_STACK_SIDEBAR_H
#define PHP_GTK_GTK_STACK_SIDEBAR_H

/*
 * GtkStackSidebar — Wave B5. Every gir
 * constructor/method/function is bound or reserved. Every gir constructor/method/function is bound or reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkStackSidebar new() -> int */
zend_long phpgtk_gtkstacksidebar_new(void);
/*@zep Gtk\GtkStackSidebar getStack(int handle) -> int */
zend_long phpgtk_gtkstacksidebar_get_stack(zval *handle);
/*@zep Gtk\GtkStackSidebar setStack(int handle, int stack) -> void */
void phpgtk_gtkstacksidebar_set_stack(zval *handle, zval *stack);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_STACK_SIDEBAR_H */
