#ifndef PHP_GTK_GTK_POPOVER_MENU_BAR_H
#define PHP_GTK_GTK_POPOVER_MENU_BAR_H

/*
 * GtkPopoverMenuBar — Wave B7. Every gir
 * constructor/method/function is bound or reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkPopoverMenuBar newFromModel(int model) -> int */
zend_long phpgtk_gtkpopovermenubar_new_from_model(zval *model);
/*@zep Gtk\GtkPopoverMenuBar addChild(int handle, int child, string id) -> bool */
zend_long phpgtk_gtkpopovermenubar_add_child(zval *handle, zval *child, zval *id);
/*@zep Gtk\GtkPopoverMenuBar getMenuModel(int handle) -> int */
zend_long phpgtk_gtkpopovermenubar_get_menu_model(zval *handle);
/*@zep Gtk\GtkPopoverMenuBar removeChild(int handle, int child) -> bool */
zend_long phpgtk_gtkpopovermenubar_remove_child(zval *handle, zval *child);
/*@zep Gtk\GtkPopoverMenuBar setMenuModel(int handle, int model) -> void */
void phpgtk_gtkpopovermenubar_set_menu_model(zval *handle, zval *model);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_POPOVER_MENU_BAR_H */
