#ifndef PHP_GTK_GTK_TEXT_VIEW_H
#define PHP_GTK_GTK_TEXT_VIEW_H

/*
 * GtkTextView — Wave B9. Every gir
 * constructor/method/function is bound or reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@reserved Gtk\GtkTextView property "im-module" — no dedicated C accessor; use Bridge::getProperty/setProperty */

/*@zep Gtk\GtkTextView new_() -> int */
zend_long phpgtk_gtktextview_new(void);
/*@zep Gtk\GtkTextView newWithBuffer(int buffer) -> int */
zend_long phpgtk_gtktextview_new_with_buffer(zval *buffer);
/*@zep Gtk\GtkTextView addChildAtAnchor(int handle, int child, int anchor) -> void */
void phpgtk_gtktextview_add_child_at_anchor(zval *handle, zval *child, zval *anchor);
/*@zep Gtk\GtkTextView addOverlay(int handle, int child, int xpos, int ypos) -> void */
void phpgtk_gtktextview_add_overlay(zval *handle, zval *child, zval *xpos, zval *ypos);
/*@reserved Gtk\GtkTextView gtk_text_view_backward_display_line(GtkTextIter* iter) — GtkTextIter* / stack boxed */
/*@reserved Gtk\GtkTextView gtk_text_view_backward_display_line_start(GtkTextIter* iter) — GtkTextIter* / stack boxed */
/*@zep Gtk\GtkTextView bufferToWindowCoords(int handle, int win, int bufferX, int bufferY) -> array */
void phpgtk_gtktextview_buffer_to_window_coords(zval *return_value, zval *handle, zval *win, zval *bufferX, zval *bufferY);
/*@reserved Gtk\GtkTextView gtk_text_view_forward_display_line(GtkTextIter* iter) — GtkTextIter* / stack boxed */
/*@reserved Gtk\GtkTextView gtk_text_view_forward_display_line_end(GtkTextIter* iter) — GtkTextIter* / stack boxed */
/*@zep Gtk\GtkTextView getAcceptsTab(int handle) -> bool */
zend_long phpgtk_gtktextview_get_accepts_tab(zval *handle);
/*@zep Gtk\GtkTextView getBottomMargin(int handle) -> int */
zend_long phpgtk_gtktextview_get_bottom_margin(zval *handle);
/*@zep Gtk\GtkTextView getBuffer(int handle) -> int */
zend_long phpgtk_gtktextview_get_buffer(zval *handle);
/*@reserved Gtk\GtkTextView gtk_text_view_get_cursor_locations(const GtkTextIter* iter, GdkRectangle* strong, GdkRectangle* weak) — GtkTextIter* / stack boxed */
/*@zep Gtk\GtkTextView getCursorVisible(int handle) -> bool */
zend_long phpgtk_gtktextview_get_cursor_visible(zval *handle);
/*@zep Gtk\GtkTextView getEditable(int handle) -> bool */
zend_long phpgtk_gtktextview_get_editable(zval *handle);
/*@zep Gtk\GtkTextView getExtraMenu(int handle) -> int */
zend_long phpgtk_gtktextview_get_extra_menu(zval *handle);
/*@zep Gtk\GtkTextView getGutter(int handle, int win) -> int */
zend_long phpgtk_gtktextview_get_gutter(zval *handle, zval *win);
/*@zep Gtk\GtkTextView getIndent(int handle) -> int */
zend_long phpgtk_gtktextview_get_indent(zval *handle);
/*@zep Gtk\GtkTextView getInputHints(int handle) -> int */
zend_long phpgtk_gtktextview_get_input_hints(zval *handle);
/*@zep Gtk\GtkTextView getInputPurpose(int handle) -> int */
zend_long phpgtk_gtktextview_get_input_purpose(zval *handle);
/*@reserved Gtk\GtkTextView gtk_text_view_get_iter_at_location(GtkTextIter* iter, int x, int y) — GtkTextIter* / stack boxed */
/*@reserved Gtk\GtkTextView gtk_text_view_get_iter_at_position(GtkTextIter* iter, int* trailing, int x, int y) — GtkTextIter* / stack boxed */
/*@reserved Gtk\GtkTextView gtk_text_view_get_iter_location(const GtkTextIter* iter, GdkRectangle* location) — GtkTextIter* / stack boxed */
/*@zep Gtk\GtkTextView getJustification(int handle) -> int */
zend_long phpgtk_gtktextview_get_justification(zval *handle);
/*@zep Gtk\GtkTextView getLeftMargin(int handle) -> int */
zend_long phpgtk_gtktextview_get_left_margin(zval *handle);
/*@reserved Gtk\GtkTextView gtk_text_view_get_line_at_y(GtkTextIter* target_iter, int y, int* line_top) — GtkTextIter* / stack boxed */
/*@reserved Gtk\GtkTextView gtk_text_view_get_line_yrange(const GtkTextIter* iter, int* y, int* height) — GtkTextIter* / stack boxed */
/*@zep Gtk\GtkTextView getLtrContext(int handle) -> int */
zend_long phpgtk_gtktextview_get_ltr_context(zval *handle);
/*@zep Gtk\GtkTextView getMonospace(int handle) -> bool */
zend_long phpgtk_gtktextview_get_monospace(zval *handle);
/*@zep Gtk\GtkTextView getOverwrite(int handle) -> bool */
zend_long phpgtk_gtktextview_get_overwrite(zval *handle);
/*@zep Gtk\GtkTextView getPixelsAboveLines(int handle) -> int */
zend_long phpgtk_gtktextview_get_pixels_above_lines(zval *handle);
/*@zep Gtk\GtkTextView getPixelsBelowLines(int handle) -> int */
zend_long phpgtk_gtktextview_get_pixels_below_lines(zval *handle);
/*@zep Gtk\GtkTextView getPixelsInsideWrap(int handle) -> int */
zend_long phpgtk_gtktextview_get_pixels_inside_wrap(zval *handle);
/*@zep Gtk\GtkTextView getRightMargin(int handle) -> int */
zend_long phpgtk_gtktextview_get_right_margin(zval *handle);
/*@zep Gtk\GtkTextView getRtlContext(int handle) -> int */
zend_long phpgtk_gtktextview_get_rtl_context(zval *handle);
/*@reserved Gtk\GtkTextView gtk_text_view_get_tabs(void) — PangoTabArray* */
/*@zep Gtk\GtkTextView getTopMargin(int handle) -> int */
zend_long phpgtk_gtktextview_get_top_margin(zval *handle);
/*@zep Gtk\GtkTextView getVisibleOffset(int handle) -> array */
void phpgtk_gtktextview_get_visible_offset(zval *return_value, zval *handle);
/*@zep Gtk\GtkTextView getVisibleRect(int handle) -> array */
void phpgtk_gtktextview_get_visible_rect(zval *return_value, zval *handle);
/*@zep Gtk\GtkTextView getWrapMode(int handle) -> int */
zend_long phpgtk_gtktextview_get_wrap_mode(zval *handle);
/*@zep Gtk\GtkTextView imContextFilterKeypress(int handle, int event) -> bool */
zend_long phpgtk_gtktextview_im_context_filter_keypress(zval *handle, zval *event);
/*@zep Gtk\GtkTextView moveMarkOnscreen(int handle, int mark) -> bool */
zend_long phpgtk_gtktextview_move_mark_onscreen(zval *handle, zval *mark);
/*@zep Gtk\GtkTextView moveOverlay(int handle, int child, int xpos, int ypos) -> void */
void phpgtk_gtktextview_move_overlay(zval *handle, zval *child, zval *xpos, zval *ypos);
/*@reserved Gtk\GtkTextView gtk_text_view_move_visually(GtkTextIter* iter, int count) — GtkTextIter* / stack boxed */
/*@zep Gtk\GtkTextView placeCursorOnscreen(int handle) -> bool */
zend_long phpgtk_gtktextview_place_cursor_onscreen(zval *handle);
/*@zep Gtk\GtkTextView remove(int handle, int child) -> void */
void phpgtk_gtktextview_remove(zval *handle, zval *child);
/*@zep Gtk\GtkTextView resetCursorBlink(int handle) -> void */
void phpgtk_gtktextview_reset_cursor_blink(zval *handle);
/*@zep Gtk\GtkTextView resetImContext(int handle) -> void */
void phpgtk_gtktextview_reset_im_context(zval *handle);
/*@zep Gtk\GtkTextView scrollMarkOnscreen(int handle, int mark) -> void */
void phpgtk_gtktextview_scroll_mark_onscreen(zval *handle, zval *mark);
/*@reserved Gtk\GtkTextView gtk_text_view_scroll_to_iter(GtkTextIter* iter, double within_margin, gboolean use_align, double xalign, double yalign) — GtkTextIter* / stack boxed */
/*@zep Gtk\GtkTextView scrollToMark(int handle, int mark, double withinMargin, bool useAlign, double xalign, double yalign) -> void */
void phpgtk_gtktextview_scroll_to_mark(zval *handle, zval *mark, zval *withinMargin, zval *useAlign, zval *xalign, zval *yalign);
/*@zep Gtk\GtkTextView setAcceptsTab(int handle, bool acceptsTab) -> void */
void phpgtk_gtktextview_set_accepts_tab(zval *handle, zval *acceptsTab);
/*@zep Gtk\GtkTextView setBottomMargin(int handle, int bottomMargin) -> void */
void phpgtk_gtktextview_set_bottom_margin(zval *handle, zval *bottomMargin);
/*@zep Gtk\GtkTextView setBuffer(int handle, int buffer) -> void */
void phpgtk_gtktextview_set_buffer(zval *handle, zval *buffer);
/*@zep Gtk\GtkTextView setCursorVisible(int handle, bool setting) -> void */
void phpgtk_gtktextview_set_cursor_visible(zval *handle, zval *setting);
/*@zep Gtk\GtkTextView setEditable(int handle, bool setting) -> void */
void phpgtk_gtktextview_set_editable(zval *handle, zval *setting);
/*@zep Gtk\GtkTextView setExtraMenu(int handle, int model) -> void */
void phpgtk_gtktextview_set_extra_menu(zval *handle, zval *model);
/*@zep Gtk\GtkTextView setGutter(int handle, int win, int widget) -> void */
void phpgtk_gtktextview_set_gutter(zval *handle, zval *win, zval *widget);
/*@zep Gtk\GtkTextView setIndent(int handle, int indent) -> void */
void phpgtk_gtktextview_set_indent(zval *handle, zval *indent);
/*@zep Gtk\GtkTextView setInputHints(int handle, int hints) -> void */
void phpgtk_gtktextview_set_input_hints(zval *handle, zval *hints);
/*@zep Gtk\GtkTextView setInputPurpose(int handle, int purpose) -> void */
void phpgtk_gtktextview_set_input_purpose(zval *handle, zval *purpose);
/*@zep Gtk\GtkTextView setJustification(int handle, int justification) -> void */
void phpgtk_gtktextview_set_justification(zval *handle, zval *justification);
/*@zep Gtk\GtkTextView setLeftMargin(int handle, int leftMargin) -> void */
void phpgtk_gtktextview_set_left_margin(zval *handle, zval *leftMargin);
/*@zep Gtk\GtkTextView setMonospace(int handle, bool monospace) -> void */
void phpgtk_gtktextview_set_monospace(zval *handle, zval *monospace);
/*@zep Gtk\GtkTextView setOverwrite(int handle, bool overwrite) -> void */
void phpgtk_gtktextview_set_overwrite(zval *handle, zval *overwrite);
/*@zep Gtk\GtkTextView setPixelsAboveLines(int handle, int pixelsAboveLines) -> void */
void phpgtk_gtktextview_set_pixels_above_lines(zval *handle, zval *pixelsAboveLines);
/*@zep Gtk\GtkTextView setPixelsBelowLines(int handle, int pixelsBelowLines) -> void */
void phpgtk_gtktextview_set_pixels_below_lines(zval *handle, zval *pixelsBelowLines);
/*@zep Gtk\GtkTextView setPixelsInsideWrap(int handle, int pixelsInsideWrap) -> void */
void phpgtk_gtktextview_set_pixels_inside_wrap(zval *handle, zval *pixelsInsideWrap);
/*@zep Gtk\GtkTextView setRightMargin(int handle, int rightMargin) -> void */
void phpgtk_gtktextview_set_right_margin(zval *handle, zval *rightMargin);
/*@reserved Gtk\GtkTextView gtk_text_view_set_tabs(PangoTabArray* tabs) — PangoTabArray* */
/*@zep Gtk\GtkTextView setTopMargin(int handle, int topMargin) -> void */
void phpgtk_gtktextview_set_top_margin(zval *handle, zval *topMargin);
/*@zep Gtk\GtkTextView setWrapMode(int handle, int wrapMode) -> void */
void phpgtk_gtktextview_set_wrap_mode(zval *handle, zval *wrapMode);
/*@reserved Gtk\GtkTextView gtk_text_view_starts_display_line(const GtkTextIter* iter) — GtkTextIter* / stack boxed */
/*@zep Gtk\GtkTextView windowToBufferCoords(int handle, int win, int windowX, int windowY) -> array */
void phpgtk_gtktextview_window_to_buffer_coords(zval *return_value, zval *handle, zval *win, zval *windowX, zval *windowY);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_TEXT_VIEW_H */
