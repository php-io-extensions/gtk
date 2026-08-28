#ifndef PHP_GTK_GTK_STACK_SWITCHER_H
#define PHP_GTK_GTK_STACK_SWITCHER_H

/*
 * GtkStackSwitcher — Wave B5. Every gir
 * constructor/method/function is bound or reserved. Every gir constructor/method/function is bound or reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkStackSwitcher new() -> int */
zend_long phpgtk_gtkstackswitcher_new(void);
/*@zep Gtk\GtkStackSwitcher getStack(int handle) -> int */
zend_long phpgtk_gtkstackswitcher_get_stack(zval *handle);
/*@zep Gtk\GtkStackSwitcher setStack(int handle, int stack) -> void */
void phpgtk_gtkstackswitcher_set_stack(zval *handle, zval *stack);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_STACK_SWITCHER_H */
