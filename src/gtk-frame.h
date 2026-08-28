#ifndef PHP_GTK_GTK_FRAME_H
#define PHP_GTK_GTK_FRAME_H

/*
 * GtkFrame — Wave A7. Every gir constructor/method/function is bound
 * or reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkFrame new(var label) -> int */
zend_long phpgtk_gtkframe_new(zval *label);
/*@zep Gtk\GtkFrame getChild(int handle) -> int */
zend_long phpgtk_gtkframe_get_child(zval *handle);
/*@zep Gtk\GtkFrame getLabel(int handle) -> var */
void phpgtk_gtkframe_get_label(zval *return_value, zval *handle);
/*@zep Gtk\GtkFrame getLabelAlign(int handle) -> double */
double phpgtk_gtkframe_get_label_align(zval *handle);
/*@zep Gtk\GtkFrame getLabelWidget(int handle) -> int */
zend_long phpgtk_gtkframe_get_label_widget(zval *handle);
/*@zep Gtk\GtkFrame setChild(int handle, int child) -> void */
void phpgtk_gtkframe_set_child(zval *handle, zval *child);
/*@zep Gtk\GtkFrame setLabel(int handle, var label) -> void */
void phpgtk_gtkframe_set_label(zval *handle, zval *label);
/*@zep Gtk\GtkFrame setLabelAlign(int handle, double xalign) -> void */
void phpgtk_gtkframe_set_label_align(zval *handle, zval *xalign);
/*@zep Gtk\GtkFrame setLabelWidget(int handle, int labelWidget) -> void */
void phpgtk_gtkframe_set_label_widget(zval *handle, zval *labelWidget);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_FRAME_H */
