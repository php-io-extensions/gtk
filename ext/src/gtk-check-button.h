#ifndef PHP_GTK_GTK_CHECK_BUTTON_H
#define PHP_GTK_GTK_CHECK_BUTTON_H

/*
 * GtkCheckButton — Wave A3. Every gir constructor/method/function is bound
 * or reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkCheckButton new() -> int */
zend_long phpgtk_gtkcheckbutton_new(void);
/*@zep Gtk\GtkCheckButton newWithLabel(var label) -> int */
zend_long phpgtk_gtkcheckbutton_new_with_label(zval *label);
/*@zep Gtk\GtkCheckButton newWithMnemonic(var label) -> int */
zend_long phpgtk_gtkcheckbutton_new_with_mnemonic(zval *label);
/*@zep Gtk\GtkCheckButton getActive(int handle) -> bool */
zend_long phpgtk_gtkcheckbutton_get_active(zval *handle);
/*@zep Gtk\GtkCheckButton getChild(int handle) -> int */
zend_long phpgtk_gtkcheckbutton_get_child(zval *handle);
/*@zep Gtk\GtkCheckButton getInconsistent(int handle) -> bool */
zend_long phpgtk_gtkcheckbutton_get_inconsistent(zval *handle);
/*@zep Gtk\GtkCheckButton getLabel(int handle) -> var */
void phpgtk_gtkcheckbutton_get_label(zval *return_value, zval *handle);
/*@zep Gtk\GtkCheckButton getUseUnderline(int handle) -> bool */
zend_long phpgtk_gtkcheckbutton_get_use_underline(zval *handle);
/*@zep Gtk\GtkCheckButton setActive(int handle, bool setting) -> void */
void phpgtk_gtkcheckbutton_set_active(zval *handle, zval *setting);
/*@zep Gtk\GtkCheckButton setChild(int handle, int child) -> void */
void phpgtk_gtkcheckbutton_set_child(zval *handle, zval *child);
/*@zep Gtk\GtkCheckButton setGroup(int handle, int group) -> void */
void phpgtk_gtkcheckbutton_set_group(zval *handle, zval *group);
/*@zep Gtk\GtkCheckButton setInconsistent(int handle, bool inconsistent) -> void */
void phpgtk_gtkcheckbutton_set_inconsistent(zval *handle, zval *inconsistent);
/*@zep Gtk\GtkCheckButton setLabel(int handle, var label) -> void */
void phpgtk_gtkcheckbutton_set_label(zval *handle, zval *label);
/*@zep Gtk\GtkCheckButton setUseUnderline(int handle, bool setting) -> void */
void phpgtk_gtkcheckbutton_set_use_underline(zval *handle, zval *setting);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_CHECK_BUTTON_H */
