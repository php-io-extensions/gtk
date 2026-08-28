#ifndef PHP_GTK_GTK_TOGGLE_BUTTON_H
#define PHP_GTK_GTK_TOGGLE_BUTTON_H

/*
 * GtkToggleButton — Wave A3. Every gir constructor/method/function is
 * bound or reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkToggleButton new() -> int */
zend_long phpgtk_gtktogglebutton_new(void);
/*@zep Gtk\GtkToggleButton newWithLabel(string label) -> int */
zend_long phpgtk_gtktogglebutton_new_with_label(zval *label);
/*@zep Gtk\GtkToggleButton newWithMnemonic(string label) -> int */
zend_long phpgtk_gtktogglebutton_new_with_mnemonic(zval *label);
/*@zep Gtk\GtkToggleButton getActive(int handle) -> bool */
zend_long phpgtk_gtktogglebutton_get_active(zval *handle);
/*@zep Gtk\GtkToggleButton setActive(int handle, bool isActive) -> void */
void phpgtk_gtktogglebutton_set_active(zval *handle, zval *isActive);
/*@zep Gtk\GtkToggleButton setGroup(int handle, int group) -> void */
void phpgtk_gtktogglebutton_set_group(zval *handle, zval *group);
/*@reserved Gtk\GtkToggleButton gtk_toggle_button_toggled(self) — deprecated */

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_TOGGLE_BUTTON_H */
