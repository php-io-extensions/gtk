#ifndef PHP_GTK_GTK_LIST_ITEM_H
#define PHP_GTK_GTK_LIST_ITEM_H

/*
 * GtkListItem — Wave C. Every gir constructor/method/function is bound
 * or reserved. Obtain-only: GTK mints these and hands them to a
 * GtkSignalListItemFactory setup/bind closure. getPosition drives the
 * PHP-side cell lookup for a ColumnView.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkListItem getAccessibleDescription(int handle) -> string */
void phpgtk_gtklistitem_get_accessible_description(zval *return_value, zval *handle);
/*@zep Gtk\GtkListItem getAccessibleLabel(int handle) -> string */
void phpgtk_gtklistitem_get_accessible_label(zval *return_value, zval *handle);
/*@zep Gtk\GtkListItem getActivatable(int handle) -> bool */
zend_long phpgtk_gtklistitem_get_activatable(zval *handle);
/*@zep Gtk\GtkListItem getChild(int handle) -> int */
zend_long phpgtk_gtklistitem_get_child(zval *handle);
/*@zep Gtk\GtkListItem getFocusable(int handle) -> bool */
zend_long phpgtk_gtklistitem_get_focusable(zval *handle);
/*@zep Gtk\GtkListItem getItem(int handle) -> int */
zend_long phpgtk_gtklistitem_get_item(zval *handle);
/*@zep Gtk\GtkListItem getPosition(int handle) -> int */
zend_long phpgtk_gtklistitem_get_position(zval *handle);
/*@zep Gtk\GtkListItem getSelectable(int handle) -> bool */
zend_long phpgtk_gtklistitem_get_selectable(zval *handle);
/*@zep Gtk\GtkListItem getSelected(int handle) -> bool */
zend_long phpgtk_gtklistitem_get_selected(zval *handle);
/*@zep Gtk\GtkListItem setAccessibleDescription(int handle, string description) -> void */
void phpgtk_gtklistitem_set_accessible_description(zval *handle, zval *description);
/*@zep Gtk\GtkListItem setAccessibleLabel(int handle, string label) -> void */
void phpgtk_gtklistitem_set_accessible_label(zval *handle, zval *label);
/*@zep Gtk\GtkListItem setActivatable(int handle, bool activatable) -> void */
void phpgtk_gtklistitem_set_activatable(zval *handle, zval *activatable);
/*@zep Gtk\GtkListItem setChild(int handle, int child) -> void */
void phpgtk_gtklistitem_set_child(zval *handle, zval *child);
/*@zep Gtk\GtkListItem setFocusable(int handle, bool focusable) -> void */
void phpgtk_gtklistitem_set_focusable(zval *handle, zval *focusable);
/*@zep Gtk\GtkListItem setSelectable(int handle, bool selectable) -> void */
void phpgtk_gtklistitem_set_selectable(zval *handle, zval *selectable);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_LIST_ITEM_H */
