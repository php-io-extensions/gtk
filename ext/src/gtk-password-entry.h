#ifndef PHP_GTK_GTK_PASSWORD_ENTRY_H
#define PHP_GTK_GTK_PASSWORD_ENTRY_H

/*
 * GtkPasswordEntry — Wave A3. Every gir constructor/method/function is
 * bound or reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@reserved Gtk\GtkPasswordEntry property "activates-default" — no C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkPasswordEntry property "placeholder-text" — no C accessor; use Bridge::getProperty/setProperty */

/*@zep Gtk\GtkPasswordEntry new() -> int */
zend_long phpgtk_gtkpasswordentry_new(void);
/*@zep Gtk\GtkPasswordEntry getExtraMenu(int handle) -> int */
zend_long phpgtk_gtkpasswordentry_get_extra_menu(zval *handle);
/*@zep Gtk\GtkPasswordEntry getShowPeekIcon(int handle) -> bool */
zend_long phpgtk_gtkpasswordentry_get_show_peek_icon(zval *handle);
/*@zep Gtk\GtkPasswordEntry setExtraMenu(int handle, int model) -> void */
void phpgtk_gtkpasswordentry_set_extra_menu(zval *handle, zval *model);
/*@zep Gtk\GtkPasswordEntry setShowPeekIcon(int handle, bool showPeekIcon) -> void */
void phpgtk_gtkpasswordentry_set_show_peek_icon(zval *handle, zval *showPeekIcon);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_PASSWORD_ENTRY_H */
