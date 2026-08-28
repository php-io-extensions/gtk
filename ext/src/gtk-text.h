#ifndef PHP_GTK_GTK_TEXT_H
#define PHP_GTK_GTK_TEXT_H

/*
 * GtkText — Wave A2. Every gir constructor/method/function is bound or
 * reserved. PangoAttrList and PangoTabArray members stay reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@reserved Gtk\GtkText property "im-module" — no C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkText property "invisible-char-set" — no C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkText property "scroll-offset" — no C accessor; use Bridge::getProperty */

/*@zep Gtk\GtkText new() -> int */
zend_long phpgtk_gtktext_new(void);
/*@zep Gtk\GtkText newWithBuffer(int buffer) -> int */
zend_long phpgtk_gtktext_new_with_buffer(zval *buffer);
/*@zep Gtk\GtkText computeCursorExtents(int handle, int position) -> array */
void phpgtk_gtktext_compute_cursor_extents(zval *return_value, zval *handle, zval *position);
/*@zep Gtk\GtkText getActivatesDefault(int handle) -> bool */
zend_long phpgtk_gtktext_get_activates_default(zval *handle);
/*@reserved Gtk\GtkText gtk_text_get_attributes(self) — PangoAttrList* */
/*@zep Gtk\GtkText getBuffer(int handle) -> int */
zend_long phpgtk_gtktext_get_buffer(zval *handle);
/*@zep Gtk\GtkText getEnableEmojiCompletion(int handle) -> bool */
zend_long phpgtk_gtktext_get_enable_emoji_completion(zval *handle);
/*@zep Gtk\GtkText getExtraMenu(int handle) -> int */
zend_long phpgtk_gtktext_get_extra_menu(zval *handle);
/*@zep Gtk\GtkText getInputHints(int handle) -> int */
zend_long phpgtk_gtktext_get_input_hints(zval *handle);
/*@zep Gtk\GtkText getInputPurpose(int handle) -> int */
zend_long phpgtk_gtktext_get_input_purpose(zval *handle);
/*@zep Gtk\GtkText getInvisibleChar(int handle) -> int */
zend_long phpgtk_gtktext_get_invisible_char(zval *handle);
/*@zep Gtk\GtkText getMaxLength(int handle) -> int */
zend_long phpgtk_gtktext_get_max_length(zval *handle);
/*@zep Gtk\GtkText getOverwriteMode(int handle) -> bool */
zend_long phpgtk_gtktext_get_overwrite_mode(zval *handle);
/*@zep Gtk\GtkText getPlaceholderText(int handle) -> var */
void phpgtk_gtktext_get_placeholder_text(zval *return_value, zval *handle);
/*@zep Gtk\GtkText getPropagateTextWidth(int handle) -> bool */
zend_long phpgtk_gtktext_get_propagate_text_width(zval *handle);
/*@reserved Gtk\GtkText gtk_text_get_tabs(self) — PangoTabArray* */
/*@zep Gtk\GtkText getTextLength(int handle) -> int */
zend_long phpgtk_gtktext_get_text_length(zval *handle);
/*@zep Gtk\GtkText getTruncateMultiline(int handle) -> bool */
zend_long phpgtk_gtktext_get_truncate_multiline(zval *handle);
/*@zep Gtk\GtkText getVisibility(int handle) -> bool */
zend_long phpgtk_gtktext_get_visibility(zval *handle);
/*@zep Gtk\GtkText grabFocusWithoutSelecting(int handle) -> bool */
zend_long phpgtk_gtktext_grab_focus_without_selecting(zval *handle);
/*@zep Gtk\GtkText setActivatesDefault(int handle, bool activates) -> void */
void phpgtk_gtktext_set_activates_default(zval *handle, zval *activates);
/*@reserved Gtk\GtkText gtk_text_set_attributes(self, PangoAttrList* attrs) — PangoAttrList* */
/*@zep Gtk\GtkText setBuffer(int handle, int buffer) -> void */
void phpgtk_gtktext_set_buffer(zval *handle, zval *buffer);
/*@zep Gtk\GtkText setEnableEmojiCompletion(int handle, bool enableEmojiCompletion) -> void */
void phpgtk_gtktext_set_enable_emoji_completion(zval *handle, zval *enableEmojiCompletion);
/*@zep Gtk\GtkText setExtraMenu(int handle, int model) -> void */
void phpgtk_gtktext_set_extra_menu(zval *handle, zval *model);
/*@zep Gtk\GtkText setInputHints(int handle, int hints) -> void */
void phpgtk_gtktext_set_input_hints(zval *handle, zval *hints);
/*@zep Gtk\GtkText setInputPurpose(int handle, int purpose) -> void */
void phpgtk_gtktext_set_input_purpose(zval *handle, zval *purpose);
/*@zep Gtk\GtkText setInvisibleChar(int handle, int ch) -> void */
void phpgtk_gtktext_set_invisible_char(zval *handle, zval *ch);
/*@zep Gtk\GtkText setMaxLength(int handle, int length) -> void */
void phpgtk_gtktext_set_max_length(zval *handle, zval *length);
/*@zep Gtk\GtkText setOverwriteMode(int handle, bool overwrite) -> void */
void phpgtk_gtktext_set_overwrite_mode(zval *handle, zval *overwrite);
/*@zep Gtk\GtkText setPlaceholderText(int handle, var text) -> void */
void phpgtk_gtktext_set_placeholder_text(zval *handle, zval *text);
/*@zep Gtk\GtkText setPropagateTextWidth(int handle, bool propagateTextWidth) -> void */
void phpgtk_gtktext_set_propagate_text_width(zval *handle, zval *propagateTextWidth);
/*@reserved Gtk\GtkText gtk_text_set_tabs(self, PangoTabArray* tabs) — PangoTabArray* */
/*@zep Gtk\GtkText setTruncateMultiline(int handle, bool truncateMultiline) -> void */
void phpgtk_gtktext_set_truncate_multiline(zval *handle, zval *truncateMultiline);
/*@zep Gtk\GtkText setVisibility(int handle, bool visible) -> void */
void phpgtk_gtktext_set_visibility(zval *handle, zval *visible);
/*@zep Gtk\GtkText unsetInvisibleChar(int handle) -> void */
void phpgtk_gtktext_unset_invisible_char(zval *handle);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_TEXT_H */
