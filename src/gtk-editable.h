#ifndef PHP_GTK_GTK_EDITABLE_H
#define PHP_GTK_GTK_EDITABLE_H

/*
 * GtkEditable — Wave A1 interface. Bound as its own class. Implementor
 * helpers that take GValue/GParamSpec/GObjectClass are reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@reserved Gtk\GtkEditable property "selection-bound" — no C accessor; use getSelectionBounds or Bridge::getProperty */
/*@reserved Gtk\GtkEditable gtk_editable_delegate_get_property(object, prop_id, GValue* value, GParamSpec* pspec) — GValue/GParamSpec implementor helper */
/*@reserved Gtk\GtkEditable gtk_editable_delegate_set_property(object, prop_id, GValue* value, GParamSpec* pspec) — GValue/GParamSpec implementor helper */
/*@reserved Gtk\GtkEditable gtk_editable_install_properties(GObjectClass* object_class, first_prop) — GObjectClass implementor helper */

/*@zep Gtk\GtkEditable delegateGetAccessiblePlatformState(int handle, int state) -> bool */
zend_long phpgtk_gtkeditable_delegate_get_accessible_platform_state(zval *handle, zval *state);
/*@zep Gtk\GtkEditable deleteSelection(int handle) -> void */
void phpgtk_gtkeditable_delete_selection(zval *handle);
/*@zep Gtk\GtkEditable deleteText(int handle, int startPos, int endPos) -> void */
void phpgtk_gtkeditable_delete_text(zval *handle, zval *startPos, zval *endPos);
/*@zep Gtk\GtkEditable finishDelegate(int handle) -> void */
void phpgtk_gtkeditable_finish_delegate(zval *handle);
/*@zep Gtk\GtkEditable getAlignment(int handle) -> double */
double phpgtk_gtkeditable_get_alignment(zval *handle);
/*@zep Gtk\GtkEditable getChars(int handle, int startPos, int endPos) -> var */
void phpgtk_gtkeditable_get_chars(zval *return_value, zval *handle, zval *startPos, zval *endPos);
/*@zep Gtk\GtkEditable getDelegate(int handle) -> int */
zend_long phpgtk_gtkeditable_get_delegate(zval *handle);
/*@zep Gtk\GtkEditable getEditable(int handle) -> bool */
zend_long phpgtk_gtkeditable_get_editable(zval *handle);
/*@zep Gtk\GtkEditable getEnableUndo(int handle) -> bool */
zend_long phpgtk_gtkeditable_get_enable_undo(zval *handle);
/*@zep Gtk\GtkEditable getMaxWidthChars(int handle) -> int */
zend_long phpgtk_gtkeditable_get_max_width_chars(zval *handle);
/*@zep Gtk\GtkEditable getPosition(int handle) -> int */
zend_long phpgtk_gtkeditable_get_position(zval *handle);
/*@zep Gtk\GtkEditable getSelectionBounds(int handle) -> array */
void phpgtk_gtkeditable_get_selection_bounds(zval *return_value, zval *handle);
/*@zep Gtk\GtkEditable getText(int handle) -> var */
void phpgtk_gtkeditable_get_text(zval *return_value, zval *handle);
/*@zep Gtk\GtkEditable getWidthChars(int handle) -> int */
zend_long phpgtk_gtkeditable_get_width_chars(zval *handle);
/*@zep Gtk\GtkEditable initDelegate(int handle) -> void */
void phpgtk_gtkeditable_init_delegate(zval *handle);
/*@zep Gtk\GtkEditable insertText(int handle, string text, int length, int position) -> array */
void phpgtk_gtkeditable_insert_text(zval *return_value, zval *handle, zval *text, zval *length, zval *position);
/*@zep Gtk\GtkEditable selectRegion(int handle, int startPos, int endPos) -> void */
void phpgtk_gtkeditable_select_region(zval *handle, zval *startPos, zval *endPos);
/*@zep Gtk\GtkEditable setAlignment(int handle, double xalign) -> void */
void phpgtk_gtkeditable_set_alignment(zval *handle, zval *xalign);
/*@zep Gtk\GtkEditable setEditable(int handle, bool isEditable) -> void */
void phpgtk_gtkeditable_set_editable(zval *handle, zval *isEditable);
/*@zep Gtk\GtkEditable setEnableUndo(int handle, bool enableUndo) -> void */
void phpgtk_gtkeditable_set_enable_undo(zval *handle, zval *enableUndo);
/*@zep Gtk\GtkEditable setMaxWidthChars(int handle, int nChars) -> void */
void phpgtk_gtkeditable_set_max_width_chars(zval *handle, zval *nChars);
/*@zep Gtk\GtkEditable setPosition(int handle, int position) -> void */
void phpgtk_gtkeditable_set_position(zval *handle, zval *position);
/*@zep Gtk\GtkEditable setText(int handle, string text) -> void */
void phpgtk_gtkeditable_set_text(zval *handle, zval *text);
/*@zep Gtk\GtkEditable setWidthChars(int handle, int nChars) -> void */
void phpgtk_gtkeditable_set_width_chars(zval *handle, zval *nChars);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_EDITABLE_H */
