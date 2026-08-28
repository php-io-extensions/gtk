#ifndef PHP_GTK_GTK_EXPANDER_H
#define PHP_GTK_GTK_EXPANDER_H

/*
 * GtkExpander — Wave A8. Every gir constructor/method/function is bound
 * or reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkExpander new(var label) -> int */
zend_long phpgtk_gtkexpander_new(zval *label);
/*@zep Gtk\GtkExpander newWithMnemonic(var label) -> int */
zend_long phpgtk_gtkexpander_new_with_mnemonic(zval *label);
/*@zep Gtk\GtkExpander getChild(int handle) -> int */
zend_long phpgtk_gtkexpander_get_child(zval *handle);
/*@zep Gtk\GtkExpander getExpanded(int handle) -> bool */
zend_long phpgtk_gtkexpander_get_expanded(zval *handle);
/*@zep Gtk\GtkExpander getLabel(int handle) -> var */
void phpgtk_gtkexpander_get_label(zval *return_value, zval *handle);
/*@zep Gtk\GtkExpander getLabelWidget(int handle) -> int */
zend_long phpgtk_gtkexpander_get_label_widget(zval *handle);
/*@zep Gtk\GtkExpander getResizeToplevel(int handle) -> bool */
zend_long phpgtk_gtkexpander_get_resize_toplevel(zval *handle);
/*@zep Gtk\GtkExpander getUseMarkup(int handle) -> bool */
zend_long phpgtk_gtkexpander_get_use_markup(zval *handle);
/*@zep Gtk\GtkExpander getUseUnderline(int handle) -> bool */
zend_long phpgtk_gtkexpander_get_use_underline(zval *handle);
/*@zep Gtk\GtkExpander setChild(int handle, int child) -> void */
void phpgtk_gtkexpander_set_child(zval *handle, zval *child);
/*@zep Gtk\GtkExpander setExpanded(int handle, bool expanded) -> void */
void phpgtk_gtkexpander_set_expanded(zval *handle, zval *expanded);
/*@zep Gtk\GtkExpander setLabel(int handle, var label) -> void */
void phpgtk_gtkexpander_set_label(zval *handle, zval *label);
/*@zep Gtk\GtkExpander setLabelWidget(int handle, int labelWidget) -> void */
void phpgtk_gtkexpander_set_label_widget(zval *handle, zval *labelWidget);
/*@zep Gtk\GtkExpander setResizeToplevel(int handle, bool resizeToplevel) -> void */
void phpgtk_gtkexpander_set_resize_toplevel(zval *handle, zval *resizeToplevel);
/*@zep Gtk\GtkExpander setUseMarkup(int handle, bool useMarkup) -> void */
void phpgtk_gtkexpander_set_use_markup(zval *handle, zval *useMarkup);
/*@zep Gtk\GtkExpander setUseUnderline(int handle, bool useUnderline) -> void */
void phpgtk_gtkexpander_set_use_underline(zval *handle, zval *useUnderline);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_EXPANDER_H */
