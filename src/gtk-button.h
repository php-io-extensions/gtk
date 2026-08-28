#ifndef PHP_GTK_GTK_BUTTON_H
#define PHP_GTK_GTK_BUTTON_H

/*
 * GtkButton — slice-zero worked example. Every gir
 * constructor/method/function is bound or reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkButton new() -> int */
zend_long phpgtk_gtkbutton_new(void);
/*@zep Gtk\GtkButton newFromIconName(string iconName) -> int */
zend_long phpgtk_gtkbutton_new_from_icon_name(zval *iconName);
/*@zep Gtk\GtkButton newWithLabel(string label) -> int */
zend_long phpgtk_gtkbutton_new_with_label(zval *label);
/*@zep Gtk\GtkButton newWithMnemonic(string label) -> int */
zend_long phpgtk_gtkbutton_new_with_mnemonic(zval *label);
/*@zep Gtk\GtkButton getCanShrink(int handle) -> bool */
zend_long phpgtk_gtkbutton_get_can_shrink(zval *handle);
/*@zep Gtk\GtkButton getChild(int handle) -> int */
zend_long phpgtk_gtkbutton_get_child(zval *handle);
/*@zep Gtk\GtkButton getHasFrame(int handle) -> bool */
zend_long phpgtk_gtkbutton_get_has_frame(zval *handle);
/*@zep Gtk\GtkButton getIconName(int handle) -> var */
void phpgtk_gtkbutton_get_icon_name(zval *return_value, zval *handle);
/*@zep Gtk\GtkButton getLabel(int handle) -> var */
void phpgtk_gtkbutton_get_label(zval *return_value, zval *handle);
/*@zep Gtk\GtkButton getUseUnderline(int handle) -> bool */
zend_long phpgtk_gtkbutton_get_use_underline(zval *handle);
/*@zep Gtk\GtkButton setCanShrink(int handle, bool canShrink) -> void */
void phpgtk_gtkbutton_set_can_shrink(zval *handle, zval *canShrink);
/*@zep Gtk\GtkButton setChild(int handle, int child) -> void */
void phpgtk_gtkbutton_set_child(zval *handle, zval *child);
/*@zep Gtk\GtkButton setHasFrame(int handle, bool hasFrame) -> void */
void phpgtk_gtkbutton_set_has_frame(zval *handle, zval *hasFrame);
/*@zep Gtk\GtkButton setIconName(int handle, string iconName) -> void */
void phpgtk_gtkbutton_set_icon_name(zval *handle, zval *iconName);
/*@zep Gtk\GtkButton setLabel(int handle, string label) -> void */
void phpgtk_gtkbutton_set_label(zval *handle, zval *label);
/*@zep Gtk\GtkButton setUseUnderline(int handle, bool useUnderline) -> void */
void phpgtk_gtkbutton_set_use_underline(zval *handle, zval *useUnderline);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_BUTTON_H */
