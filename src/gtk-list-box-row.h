#ifndef PHP_GTK_GTK_LIST_BOX_ROW_H
#define PHP_GTK_GTK_LIST_BOX_ROW_H

/*
 * GtkListBoxRow — Wave B3. Every gir
 * constructor/method/function is bound or reserved. Every gir constructor/method/function is bound or reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkListBoxRow new() -> int */
zend_long phpgtk_gtklistboxrow_new(void);
/*@zep Gtk\GtkListBoxRow changed(int handle) -> void */
void phpgtk_gtklistboxrow_changed(zval *handle);
/*@zep Gtk\GtkListBoxRow getActivatable(int handle) -> bool */
zend_long phpgtk_gtklistboxrow_get_activatable(zval *handle);
/*@zep Gtk\GtkListBoxRow getChild(int handle) -> int */
zend_long phpgtk_gtklistboxrow_get_child(zval *handle);
/*@zep Gtk\GtkListBoxRow getHeader(int handle) -> int */
zend_long phpgtk_gtklistboxrow_get_header(zval *handle);
/*@zep Gtk\GtkListBoxRow getIndex(int handle) -> int */
zend_long phpgtk_gtklistboxrow_get_index(zval *handle);
/*@zep Gtk\GtkListBoxRow getSelectable(int handle) -> bool */
zend_long phpgtk_gtklistboxrow_get_selectable(zval *handle);
/*@zep Gtk\GtkListBoxRow isSelected(int handle) -> bool */
zend_long phpgtk_gtklistboxrow_is_selected(zval *handle);
/*@zep Gtk\GtkListBoxRow setActivatable(int handle, bool activatable) -> void */
void phpgtk_gtklistboxrow_set_activatable(zval *handle, zval *activatable);
/*@zep Gtk\GtkListBoxRow setChild(int handle, int child) -> void */
void phpgtk_gtklistboxrow_set_child(zval *handle, zval *child);
/*@zep Gtk\GtkListBoxRow setHeader(int handle, int header) -> void */
void phpgtk_gtklistboxrow_set_header(zval *handle, zval *header);
/*@zep Gtk\GtkListBoxRow setSelectable(int handle, bool selectable) -> void */
void phpgtk_gtklistboxrow_set_selectable(zval *handle, zval *selectable);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_LIST_BOX_ROW_H */
