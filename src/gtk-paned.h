#ifndef PHP_GTK_GTK_PANED_H
#define PHP_GTK_GTK_PANED_H

/*
 * GtkPaned — Wave B5. Every gir
 * constructor/method/function is bound or reserved. max-position / min-position / position-set have no dedicated C accessors.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@reserved Gtk\GtkPaned property "max-position" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkPaned property "min-position" — no dedicated C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkPaned property "position-set" — no dedicated C accessor; use Bridge::getProperty/setProperty */

/*@zep Gtk\GtkPaned new(int orientation) -> int */
zend_long phpgtk_gtkpaned_new(zval *orientation);
/*@zep Gtk\GtkPaned getEndChild(int handle) -> int */
zend_long phpgtk_gtkpaned_get_end_child(zval *handle);
/*@zep Gtk\GtkPaned getPosition(int handle) -> int */
zend_long phpgtk_gtkpaned_get_position(zval *handle);
/*@zep Gtk\GtkPaned getResizeEndChild(int handle) -> bool */
zend_long phpgtk_gtkpaned_get_resize_end_child(zval *handle);
/*@zep Gtk\GtkPaned getResizeStartChild(int handle) -> bool */
zend_long phpgtk_gtkpaned_get_resize_start_child(zval *handle);
/*@zep Gtk\GtkPaned getShrinkEndChild(int handle) -> bool */
zend_long phpgtk_gtkpaned_get_shrink_end_child(zval *handle);
/*@zep Gtk\GtkPaned getShrinkStartChild(int handle) -> bool */
zend_long phpgtk_gtkpaned_get_shrink_start_child(zval *handle);
/*@zep Gtk\GtkPaned getStartChild(int handle) -> int */
zend_long phpgtk_gtkpaned_get_start_child(zval *handle);
/*@zep Gtk\GtkPaned getWideHandle(int handle) -> bool */
zend_long phpgtk_gtkpaned_get_wide_handle(zval *handle);
/*@zep Gtk\GtkPaned setEndChild(int handle, int child) -> void */
void phpgtk_gtkpaned_set_end_child(zval *handle, zval *child);
/*@zep Gtk\GtkPaned setPosition(int handle, int position) -> void */
void phpgtk_gtkpaned_set_position(zval *handle, zval *position);
/*@zep Gtk\GtkPaned setResizeEndChild(int handle, bool resize) -> void */
void phpgtk_gtkpaned_set_resize_end_child(zval *handle, zval *resize);
/*@zep Gtk\GtkPaned setResizeStartChild(int handle, bool resize) -> void */
void phpgtk_gtkpaned_set_resize_start_child(zval *handle, zval *resize);
/*@zep Gtk\GtkPaned setShrinkEndChild(int handle, bool resize) -> void */
void phpgtk_gtkpaned_set_shrink_end_child(zval *handle, zval *resize);
/*@zep Gtk\GtkPaned setShrinkStartChild(int handle, bool resize) -> void */
void phpgtk_gtkpaned_set_shrink_start_child(zval *handle, zval *resize);
/*@zep Gtk\GtkPaned setStartChild(int handle, int child) -> void */
void phpgtk_gtkpaned_set_start_child(zval *handle, zval *child);
/*@zep Gtk\GtkPaned setWideHandle(int handle, bool wide) -> void */
void phpgtk_gtkpaned_set_wide_handle(zval *handle, zval *wide);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_PANED_H */
