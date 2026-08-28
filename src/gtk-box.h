#ifndef PHP_GTK_GTK_BOX_H
#define PHP_GTK_GTK_BOX_H

/*
 * GtkBox — slice zero. Every gir constructor/method/function is bound or
 * reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkBox new(int orientation, int spacing) -> int */
zend_long phpgtk_gtkbox_new(zval *orientation, zval *spacing);
/*@zep Gtk\GtkBox append(int handle, int child) -> void */
void phpgtk_gtkbox_append(zval *handle, zval *child);
/*@zep Gtk\GtkBox getBaselineChild(int handle) -> int */
zend_long phpgtk_gtkbox_get_baseline_child(zval *handle);
/*@zep Gtk\GtkBox getBaselinePosition(int handle) -> int */
zend_long phpgtk_gtkbox_get_baseline_position(zval *handle);
/*@zep Gtk\GtkBox getHomogeneous(int handle) -> bool */
zend_long phpgtk_gtkbox_get_homogeneous(zval *handle);
/*@zep Gtk\GtkBox getSpacing(int handle) -> int */
zend_long phpgtk_gtkbox_get_spacing(zval *handle);
/*@zep Gtk\GtkBox insertChildAfter(int handle, int child, int sibling) -> void */
void phpgtk_gtkbox_insert_child_after(zval *handle, zval *child, zval *sibling);
/*@zep Gtk\GtkBox prepend(int handle, int child) -> void */
void phpgtk_gtkbox_prepend(zval *handle, zval *child);
/*@zep Gtk\GtkBox remove(int handle, int child) -> void */
void phpgtk_gtkbox_remove(zval *handle, zval *child);
/*@zep Gtk\GtkBox reorderChildAfter(int handle, int child, int sibling) -> void */
void phpgtk_gtkbox_reorder_child_after(zval *handle, zval *child, zval *sibling);
/*@zep Gtk\GtkBox setBaselineChild(int handle, int child) -> void */
void phpgtk_gtkbox_set_baseline_child(zval *handle, zval *child);
/*@zep Gtk\GtkBox setBaselinePosition(int handle, int position) -> void */
void phpgtk_gtkbox_set_baseline_position(zval *handle, zval *position);
/*@zep Gtk\GtkBox setHomogeneous(int handle, bool homogeneous) -> void */
void phpgtk_gtkbox_set_homogeneous(zval *handle, zval *homogeneous);
/*@zep Gtk\GtkBox setSpacing(int handle, int spacing) -> void */
void phpgtk_gtkbox_set_spacing(zval *handle, zval *spacing);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_BOX_H */
