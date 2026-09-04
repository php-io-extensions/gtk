#ifndef PHP_GTK_GTK_TEXT_BUFFER_H
#define PHP_GTK_GTK_TEXT_BUFFER_H

/*
 * GtkTextBuffer — Wave B8. Every gir
 * constructor/method/function is bound or reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@reserved Gtk\GtkTextBuffer property "cursor-position" — no dedicated C accessor; use Bridge::getProperty/setProperty */

/*@zep Gtk\GtkTextBuffer new_(int table) -> int */
zend_long phpgtk_gtktextbuffer_new(zval *table);
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_add_commit_notify(GtkTextBufferNotifyFlags flags, GtkTextBufferCommitNotify commit_notify, gpointer user_data, GDestroyNotify destroy) — non-signal callback */
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_add_mark(GtkTextMark* mark, const GtkTextIter* where) — GtkTextIter* / stack boxed */
/*@zep Gtk\GtkTextBuffer addSelectionClipboard(int handle, int clipboard) -> void */
void phpgtk_gtktextbuffer_add_selection_clipboard(zval *handle, zval *clipboard);
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_apply_tag(GtkTextTag* tag, const GtkTextIter* start, const GtkTextIter* end) — GtkTextIter* / stack boxed */
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_apply_tag_by_name(const char* name, const GtkTextIter* start, const GtkTextIter* end) — GtkTextIter* / stack boxed */
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_backspace(GtkTextIter* iter, gboolean interactive, gboolean default_editable) — GtkTextIter* / stack boxed */
/*@zep Gtk\GtkTextBuffer beginIrreversibleAction(int handle) -> void */
void phpgtk_gtktextbuffer_begin_irreversible_action(zval *handle);
/*@zep Gtk\GtkTextBuffer beginUserAction(int handle) -> void */
void phpgtk_gtktextbuffer_begin_user_action(zval *handle);
/*@zep Gtk\GtkTextBuffer copyClipboard(int handle, int clipboard) -> void */
void phpgtk_gtktextbuffer_copy_clipboard(zval *handle, zval *clipboard);
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_create_child_anchor(GtkTextIter* iter) — GtkTextIter* / stack boxed */
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_create_mark(const char* mark_name, const GtkTextIter* where, gboolean left_gravity) — GtkTextIter* / stack boxed */
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_create_tag(const char* tag_name, const char* first_property_name, varargs ...) — varargs */
/*@zep Gtk\GtkTextBuffer cutClipboard(int handle, int clipboard, bool defaultEditable) -> void */
void phpgtk_gtktextbuffer_cut_clipboard(zval *handle, zval *clipboard, zval *defaultEditable);
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_delete(GtkTextIter* start, GtkTextIter* end) — GtkTextIter* / stack boxed */
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_delete_interactive(GtkTextIter* start_iter, GtkTextIter* end_iter, gboolean default_editable) — GtkTextIter* / stack boxed */
/*@zep Gtk\GtkTextBuffer deleteMark(int handle, int mark) -> void */
void phpgtk_gtktextbuffer_delete_mark(zval *handle, zval *mark);
/*@zep Gtk\GtkTextBuffer deleteMarkByName(int handle, string name) -> void */
void phpgtk_gtktextbuffer_delete_mark_by_name(zval *handle, zval *name);
/*@zep Gtk\GtkTextBuffer deleteSelection(int handle, bool interactive, bool defaultEditable) -> bool */
zend_long phpgtk_gtktextbuffer_delete_selection(zval *handle, zval *interactive, zval *defaultEditable);
/*@zep Gtk\GtkTextBuffer endIrreversibleAction(int handle) -> void */
void phpgtk_gtktextbuffer_end_irreversible_action(zval *handle);
/*@zep Gtk\GtkTextBuffer endUserAction(int handle) -> void */
void phpgtk_gtktextbuffer_end_user_action(zval *handle);
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_get_bounds(GtkTextIter* start, GtkTextIter* end) — GtkTextIter* / stack boxed */
/*@zep Gtk\GtkTextBuffer getCanRedo(int handle) -> bool */
zend_long phpgtk_gtktextbuffer_get_can_redo(zval *handle);
/*@zep Gtk\GtkTextBuffer getCanUndo(int handle) -> bool */
zend_long phpgtk_gtktextbuffer_get_can_undo(zval *handle);
/*@zep Gtk\GtkTextBuffer getCharCount(int handle) -> int */
zend_long phpgtk_gtktextbuffer_get_char_count(zval *handle);
/*@zep Gtk\GtkTextBuffer getEnableUndo(int handle) -> bool */
zend_long phpgtk_gtktextbuffer_get_enable_undo(zval *handle);
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_get_end_iter(GtkTextIter* iter) — GtkTextIter* / stack boxed */
/*@zep Gtk\GtkTextBuffer getHasSelection(int handle) -> bool */
zend_long phpgtk_gtktextbuffer_get_has_selection(zval *handle);
/*@zep Gtk\GtkTextBuffer getInsert(int handle) -> int */
zend_long phpgtk_gtktextbuffer_get_insert(zval *handle);
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_get_iter_at_child_anchor(GtkTextIter* iter, GtkTextChildAnchor* anchor) — GtkTextIter* / stack boxed */
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_get_iter_at_line(GtkTextIter* iter, int line_number) — GtkTextIter* / stack boxed */
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_get_iter_at_line_index(GtkTextIter* iter, int line_number, int byte_index) — GtkTextIter* / stack boxed */
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_get_iter_at_line_offset(GtkTextIter* iter, int line_number, int char_offset) — GtkTextIter* / stack boxed */
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_get_iter_at_mark(GtkTextIter* iter, GtkTextMark* mark) — GtkTextIter* / stack boxed */
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_get_iter_at_offset(GtkTextIter* iter, int char_offset) — GtkTextIter* / stack boxed */
/*@zep Gtk\GtkTextBuffer getLineCount(int handle) -> int */
zend_long phpgtk_gtktextbuffer_get_line_count(zval *handle);
/*@zep Gtk\GtkTextBuffer getMark(int handle, string name) -> int */
zend_long phpgtk_gtktextbuffer_get_mark(zval *handle, zval *name);
/*@zep Gtk\GtkTextBuffer getMaxUndoLevels(int handle) -> int */
zend_long phpgtk_gtktextbuffer_get_max_undo_levels(zval *handle);
/*@zep Gtk\GtkTextBuffer getModified(int handle) -> bool */
zend_long phpgtk_gtktextbuffer_get_modified(zval *handle);
/*@zep Gtk\GtkTextBuffer getSelectionBound(int handle) -> int */
zend_long phpgtk_gtktextbuffer_get_selection_bound(zval *handle);
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_get_selection_bounds(GtkTextIter* start, GtkTextIter* end) — GtkTextIter* / stack boxed */
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_get_selection_content(void) — GdkContentProvider* */
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_get_slice(const GtkTextIter* start, const GtkTextIter* end, gboolean include_hidden_chars) — GtkTextIter* / stack boxed */
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_get_start_iter(GtkTextIter* iter) — GtkTextIter* / stack boxed */
/*@zep Gtk\GtkTextBuffer getTagTable(int handle) -> int */
zend_long phpgtk_gtktextbuffer_get_tag_table(zval *handle);
/*@zep Gtk\GtkTextBuffer getText(int handle, int startOffset, int endOffset, bool includeHiddenChars) -> var */
void phpgtk_gtktextbuffer_get_text(zval *return_value, zval *handle, zval *startOffset, zval *endOffset, zval *includeHiddenChars);
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_insert(GtkTextIter* iter, const char* text, int len) — GtkTextIter* / stack boxed */
/*@zep Gtk\GtkTextBuffer insertAtCursor(int handle, string text, int len) -> void */
void phpgtk_gtktextbuffer_insert_at_cursor(zval *handle, zval *text, zval *len);
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_insert_child_anchor(GtkTextIter* iter, GtkTextChildAnchor* anchor) — GtkTextIter* / stack boxed */
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_insert_interactive(GtkTextIter* iter, const char* text, int len, gboolean default_editable) — GtkTextIter* / stack boxed */
/*@zep Gtk\GtkTextBuffer insertInteractiveAtCursor(int handle, string text, int len, bool defaultEditable) -> bool */
zend_long phpgtk_gtktextbuffer_insert_interactive_at_cursor(zval *handle, zval *text, zval *len, zval *defaultEditable);
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_insert_markup(GtkTextIter* iter, const char* markup, int len) — GtkTextIter* / stack boxed */
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_insert_paintable(GtkTextIter* iter, GdkPaintable* paintable) — GtkTextIter* / stack boxed */
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_insert_range(GtkTextIter* iter, const GtkTextIter* start, const GtkTextIter* end) — GtkTextIter* / stack boxed */
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_insert_range_interactive(GtkTextIter* iter, const GtkTextIter* start, const GtkTextIter* end, gboolean default_editable) — GtkTextIter* / stack boxed */
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_insert_with_tags(GtkTextIter* iter, const char* text, int len, GtkTextTag* first_tag, varargs ...) — GtkTextIter* / stack boxed */
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_insert_with_tags_by_name(GtkTextIter* iter, const char* text, int len, const char* first_tag_name, varargs ...) — GtkTextIter* / stack boxed */
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_move_mark(GtkTextMark* mark, const GtkTextIter* where) — GtkTextIter* / stack boxed */
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_move_mark_by_name(const char* name, const GtkTextIter* where) — GtkTextIter* / stack boxed */
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_paste_clipboard(GdkClipboard* clipboard, GtkTextIter* override_location, gboolean default_editable) — GtkTextIter* / stack boxed */
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_place_cursor(const GtkTextIter* where) — GtkTextIter* / stack boxed */
/*@zep Gtk\GtkTextBuffer redo(int handle) -> void */
void phpgtk_gtktextbuffer_redo(zval *handle);
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_remove_all_tags(const GtkTextIter* start, const GtkTextIter* end) — GtkTextIter* / stack boxed */
/*@zep Gtk\GtkTextBuffer removeCommitNotify(int handle, int commitNotifyHandler) -> void */
void phpgtk_gtktextbuffer_remove_commit_notify(zval *handle, zval *commitNotifyHandler);
/*@zep Gtk\GtkTextBuffer removeSelectionClipboard(int handle, int clipboard) -> void */
void phpgtk_gtktextbuffer_remove_selection_clipboard(zval *handle, zval *clipboard);
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_remove_tag(GtkTextTag* tag, const GtkTextIter* start, const GtkTextIter* end) — GtkTextIter* / stack boxed */
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_remove_tag_by_name(const char* name, const GtkTextIter* start, const GtkTextIter* end) — GtkTextIter* / stack boxed */
/*@reserved Gtk\GtkTextBuffer gtk_text_buffer_select_range(const GtkTextIter* ins, const GtkTextIter* bound) — GtkTextIter* / stack boxed */
/*@zep Gtk\GtkTextBuffer setEnableUndo(int handle, bool enableUndo) -> void */
void phpgtk_gtktextbuffer_set_enable_undo(zval *handle, zval *enableUndo);
/*@zep Gtk\GtkTextBuffer setMaxUndoLevels(int handle, int maxUndoLevels) -> void */
void phpgtk_gtktextbuffer_set_max_undo_levels(zval *handle, zval *maxUndoLevels);
/*@zep Gtk\GtkTextBuffer setModified(int handle, bool setting) -> void */
void phpgtk_gtktextbuffer_set_modified(zval *handle, zval *setting);
/*@zep Gtk\GtkTextBuffer setText(int handle, string text, int len) -> void */
void phpgtk_gtktextbuffer_set_text(zval *handle, zval *text, zval *len);
/*@zep Gtk\GtkTextBuffer undo(int handle) -> void */
void phpgtk_gtktextbuffer_undo(zval *handle);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_TEXT_BUFFER_H */
