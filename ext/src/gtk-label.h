#ifndef PHP_GTK_GTK_LABEL_H
#define PHP_GTK_GTK_LABEL_H

/*
 * GtkLabel — Wave A5. Every gir constructor/method/function is bound
 * or reserved. PangoAttrList and PangoTabArray members stay reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkLabel new(var str) -> int */
zend_long phpgtk_gtklabel_new(zval *str);
/*@zep Gtk\GtkLabel newWithMnemonic(var str) -> int */
zend_long phpgtk_gtklabel_new_with_mnemonic(zval *str);
/*@reserved Gtk\GtkLabel gtk_label_get_attributes(GtkLabel* self) — PangoAttrList* */
/*@zep Gtk\GtkLabel getCurrentUri(int handle) -> var */
void phpgtk_gtklabel_get_current_uri(zval *return_value, zval *handle);
/*@zep Gtk\GtkLabel getEllipsize(int handle) -> int */
zend_long phpgtk_gtklabel_get_ellipsize(zval *handle);
/*@zep Gtk\GtkLabel getExtraMenu(int handle) -> int */
zend_long phpgtk_gtklabel_get_extra_menu(zval *handle);
/*@zep Gtk\GtkLabel getJustify(int handle) -> int */
zend_long phpgtk_gtklabel_get_justify(zval *handle);
/*@zep Gtk\GtkLabel getLabel(int handle) -> string */
void phpgtk_gtklabel_get_label(zval *return_value, zval *handle);
/*@zep Gtk\GtkLabel getLayout(int handle) -> int */
zend_long phpgtk_gtklabel_get_layout(zval *handle);
/*@zep Gtk\GtkLabel getLayoutOffsets(int handle) -> array */
void phpgtk_gtklabel_get_layout_offsets(zval *return_value, zval *handle);
/*@zep Gtk\GtkLabel getLines(int handle) -> int */
zend_long phpgtk_gtklabel_get_lines(zval *handle);
/*@zep Gtk\GtkLabel getMaxWidthChars(int handle) -> int */
zend_long phpgtk_gtklabel_get_max_width_chars(zval *handle);
/*@zep Gtk\GtkLabel getMnemonicKeyval(int handle) -> int */
zend_long phpgtk_gtklabel_get_mnemonic_keyval(zval *handle);
/*@zep Gtk\GtkLabel getMnemonicWidget(int handle) -> int */
zend_long phpgtk_gtklabel_get_mnemonic_widget(zval *handle);
/*@zep Gtk\GtkLabel getNaturalWrapMode(int handle) -> int */
zend_long phpgtk_gtklabel_get_natural_wrap_mode(zval *handle);
/*@zep Gtk\GtkLabel getSelectable(int handle) -> bool */
zend_long phpgtk_gtklabel_get_selectable(zval *handle);
/*@zep Gtk\GtkLabel getSelectionBounds(int handle) -> array */
void phpgtk_gtklabel_get_selection_bounds(zval *return_value, zval *handle);
/*@zep Gtk\GtkLabel getSingleLineMode(int handle) -> bool */
zend_long phpgtk_gtklabel_get_single_line_mode(zval *handle);
/*@reserved Gtk\GtkLabel gtk_label_get_tabs(GtkLabel* self) — PangoTabArray* */
/*@zep Gtk\GtkLabel getText(int handle) -> string */
void phpgtk_gtklabel_get_text(zval *return_value, zval *handle);
/*@zep Gtk\GtkLabel getUseMarkup(int handle) -> bool */
zend_long phpgtk_gtklabel_get_use_markup(zval *handle);
/*@zep Gtk\GtkLabel getUseUnderline(int handle) -> bool */
zend_long phpgtk_gtklabel_get_use_underline(zval *handle);
/*@zep Gtk\GtkLabel getWidthChars(int handle) -> int */
zend_long phpgtk_gtklabel_get_width_chars(zval *handle);
/*@zep Gtk\GtkLabel getWrap(int handle) -> bool */
zend_long phpgtk_gtklabel_get_wrap(zval *handle);
/*@zep Gtk\GtkLabel getWrapMode(int handle) -> int */
zend_long phpgtk_gtklabel_get_wrap_mode(zval *handle);
/*@zep Gtk\GtkLabel getXalign(int handle) -> double */
double phpgtk_gtklabel_get_xalign(zval *handle);
/*@zep Gtk\GtkLabel getYalign(int handle) -> double */
double phpgtk_gtklabel_get_yalign(zval *handle);
/*@zep Gtk\GtkLabel selectRegion(int handle, int startOffset, int endOffset) -> void */
void phpgtk_gtklabel_select_region(zval *handle, zval *startOffset, zval *endOffset);
/*@reserved Gtk\GtkLabel gtk_label_set_attributes(GtkLabel* self, PangoAttrList* attrs) — PangoAttrList* */
/*@zep Gtk\GtkLabel setEllipsize(int handle, int mode) -> void */
void phpgtk_gtklabel_set_ellipsize(zval *handle, zval *mode);
/*@zep Gtk\GtkLabel setExtraMenu(int handle, int model) -> void */
void phpgtk_gtklabel_set_extra_menu(zval *handle, zval *model);
/*@zep Gtk\GtkLabel setJustify(int handle, int jtype) -> void */
void phpgtk_gtklabel_set_justify(zval *handle, zval *jtype);
/*@zep Gtk\GtkLabel setLabel(int handle, string str) -> void */
void phpgtk_gtklabel_set_label(zval *handle, zval *str);
/*@zep Gtk\GtkLabel setLines(int handle, int lines) -> void */
void phpgtk_gtklabel_set_lines(zval *handle, zval *lines);
/*@zep Gtk\GtkLabel setMarkup(int handle, string str) -> void */
void phpgtk_gtklabel_set_markup(zval *handle, zval *str);
/*@zep Gtk\GtkLabel setMarkupWithMnemonic(int handle, string str) -> void */
void phpgtk_gtklabel_set_markup_with_mnemonic(zval *handle, zval *str);
/*@zep Gtk\GtkLabel setMaxWidthChars(int handle, int nChars) -> void */
void phpgtk_gtklabel_set_max_width_chars(zval *handle, zval *nChars);
/*@zep Gtk\GtkLabel setMnemonicWidget(int handle, int widget) -> void */
void phpgtk_gtklabel_set_mnemonic_widget(zval *handle, zval *widget);
/*@zep Gtk\GtkLabel setNaturalWrapMode(int handle, int wrapMode) -> void */
void phpgtk_gtklabel_set_natural_wrap_mode(zval *handle, zval *wrapMode);
/*@zep Gtk\GtkLabel setSelectable(int handle, bool setting) -> void */
void phpgtk_gtklabel_set_selectable(zval *handle, zval *setting);
/*@zep Gtk\GtkLabel setSingleLineMode(int handle, bool singleLineMode) -> void */
void phpgtk_gtklabel_set_single_line_mode(zval *handle, zval *singleLineMode);
/*@reserved Gtk\GtkLabel gtk_label_set_tabs(GtkLabel* self, PangoTabArray* tabs) — PangoTabArray* */
/*@zep Gtk\GtkLabel setText(int handle, string str) -> void */
void phpgtk_gtklabel_set_text(zval *handle, zval *str);
/*@zep Gtk\GtkLabel setTextWithMnemonic(int handle, string str) -> void */
void phpgtk_gtklabel_set_text_with_mnemonic(zval *handle, zval *str);
/*@zep Gtk\GtkLabel setUseMarkup(int handle, bool setting) -> void */
void phpgtk_gtklabel_set_use_markup(zval *handle, zval *setting);
/*@zep Gtk\GtkLabel setUseUnderline(int handle, bool setting) -> void */
void phpgtk_gtklabel_set_use_underline(zval *handle, zval *setting);
/*@zep Gtk\GtkLabel setWidthChars(int handle, int nChars) -> void */
void phpgtk_gtklabel_set_width_chars(zval *handle, zval *nChars);
/*@zep Gtk\GtkLabel setWrap(int handle, bool wrap) -> void */
void phpgtk_gtklabel_set_wrap(zval *handle, zval *wrap);
/*@zep Gtk\GtkLabel setWrapMode(int handle, int wrapMode) -> void */
void phpgtk_gtklabel_set_wrap_mode(zval *handle, zval *wrapMode);
/*@zep Gtk\GtkLabel setXalign(int handle, double xalign) -> void */
void phpgtk_gtklabel_set_xalign(zval *handle, zval *xalign);
/*@zep Gtk\GtkLabel setYalign(int handle, double yalign) -> void */
void phpgtk_gtklabel_set_yalign(zval *handle, zval *yalign);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_LABEL_H */
