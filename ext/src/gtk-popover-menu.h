#ifndef PHP_GTK_GTK_POPOVER_MENU_H
#define PHP_GTK_GTK_POPOVER_MENU_H

/*
 * GtkPopoverMenu — Wave B7. Every gir
 * constructor/method/function is bound or reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@reserved Gtk\GtkPopoverMenu property "visible-submenu" — no dedicated C accessor; use Bridge::getProperty/setProperty */

/*@zep Gtk\GtkPopoverMenu newFromModel(int model) -> int */
zend_long phpgtk_gtkpopovermenu_new_from_model(zval *model);
/*@zep Gtk\GtkPopoverMenu newFromModelFull(int model, int flags) -> int */
zend_long phpgtk_gtkpopovermenu_new_from_model_full(zval *model, zval *flags);
/*@zep Gtk\GtkPopoverMenu addChild(int handle, int child, string id) -> bool */
zend_long phpgtk_gtkpopovermenu_add_child(zval *handle, zval *child, zval *id);
/*@zep Gtk\GtkPopoverMenu getFlags(int handle) -> int */
zend_long phpgtk_gtkpopovermenu_get_flags(zval *handle);
/*@zep Gtk\GtkPopoverMenu getMenuModel(int handle) -> int */
zend_long phpgtk_gtkpopovermenu_get_menu_model(zval *handle);
/*@zep Gtk\GtkPopoverMenu removeChild(int handle, int child) -> bool */
zend_long phpgtk_gtkpopovermenu_remove_child(zval *handle, zval *child);
/*@zep Gtk\GtkPopoverMenu setFlags(int handle, int flags) -> void */
void phpgtk_gtkpopovermenu_set_flags(zval *handle, zval *flags);
/*@zep Gtk\GtkPopoverMenu setMenuModel(int handle, int model) -> void */
void phpgtk_gtkpopovermenu_set_menu_model(zval *handle, zval *model);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_POPOVER_MENU_H */
