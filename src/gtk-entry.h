#ifndef PHP_GTK_GTK_ENTRY_H
#define PHP_GTK_GTK_ENTRY_H

/*
 * GtkEntry — Wave A2. Every gir constructor/method/function is bound or
 * reserved. PangoAttrList, PangoTabArray, GdkContentProvider, and the
 * deprecated completion pair stay reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@reserved Gtk\GtkEntry property "enable-emoji-completion" — no C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkEntry property "im-module" — no C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkEntry property "invisible-char-set" — no C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkEntry property "primary-icon-activatable" — no dedicated C accessor; use getIconActivatable/setIconActivatable or Bridge::getProperty */
/*@reserved Gtk\GtkEntry property "primary-icon-gicon" — no dedicated C accessor; use getIconGicon/setIconFromGicon or Bridge::getProperty */
/*@reserved Gtk\GtkEntry property "primary-icon-name" — no dedicated C accessor; use getIconName/setIconFromIconName or Bridge::getProperty */
/*@reserved Gtk\GtkEntry property "primary-icon-paintable" — no dedicated C accessor; use getIconPaintable/setIconFromPaintable or Bridge::getProperty */
/*@reserved Gtk\GtkEntry property "primary-icon-sensitive" — no dedicated C accessor; use getIconSensitive/setIconSensitive or Bridge::getProperty */
/*@reserved Gtk\GtkEntry property "primary-icon-storage-type" — no dedicated C accessor; use getIconStorageType or Bridge::getProperty */
/*@reserved Gtk\GtkEntry property "primary-icon-tooltip-markup" — no dedicated C accessor; use getIconTooltipMarkup/setIconTooltipMarkup or Bridge::getProperty */
/*@reserved Gtk\GtkEntry property "primary-icon-tooltip-text" — no dedicated C accessor; use getIconTooltipText/setIconTooltipText or Bridge::getProperty */
/*@reserved Gtk\GtkEntry property "scroll-offset" — no C accessor; use Bridge::getProperty */
/*@reserved Gtk\GtkEntry property "secondary-icon-activatable" — no dedicated C accessor; use getIconActivatable/setIconActivatable or Bridge::getProperty */
/*@reserved Gtk\GtkEntry property "secondary-icon-gicon" — no dedicated C accessor; use getIconGicon/setIconFromGicon or Bridge::getProperty */
/*@reserved Gtk\GtkEntry property "secondary-icon-name" — no dedicated C accessor; use getIconName/setIconFromIconName or Bridge::getProperty */
/*@reserved Gtk\GtkEntry property "secondary-icon-paintable" — no dedicated C accessor; use getIconPaintable/setIconFromPaintable or Bridge::getProperty */
/*@reserved Gtk\GtkEntry property "secondary-icon-sensitive" — no dedicated C accessor; use getIconSensitive/setIconSensitive or Bridge::getProperty */
/*@reserved Gtk\GtkEntry property "secondary-icon-storage-type" — no dedicated C accessor; use getIconStorageType or Bridge::getProperty */
/*@reserved Gtk\GtkEntry property "secondary-icon-tooltip-markup" — no dedicated C accessor; use getIconTooltipMarkup/setIconTooltipMarkup or Bridge::getProperty */
/*@reserved Gtk\GtkEntry property "secondary-icon-tooltip-text" — no dedicated C accessor; use getIconTooltipText/setIconTooltipText or Bridge::getProperty */
/*@reserved Gtk\GtkEntry property "show-emoji-icon" — no C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkEntry property "truncate-multiline" — no C accessor; use Bridge::getProperty/setProperty */

/*@zep Gtk\GtkEntry new() -> int */
zend_long phpgtk_gtkentry_new(void);
/*@zep Gtk\GtkEntry newWithBuffer(int buffer) -> int */
zend_long phpgtk_gtkentry_new_with_buffer(zval *buffer);
/*@zep Gtk\GtkEntry getActivatesDefault(int handle) -> bool */
zend_long phpgtk_gtkentry_get_activates_default(zval *handle);
/*@zep Gtk\GtkEntry getAlignment(int handle) -> double */
double phpgtk_gtkentry_get_alignment(zval *handle);
/*@reserved Gtk\GtkEntry gtk_entry_get_attributes(self) — PangoAttrList* */
/*@zep Gtk\GtkEntry getBuffer(int handle) -> int */
zend_long phpgtk_gtkentry_get_buffer(zval *handle);
/*@reserved Gtk\GtkEntry gtk_entry_get_completion(self) — deprecated */
/*@zep Gtk\GtkEntry getCurrentIconDragSource(int handle) -> int */
zend_long phpgtk_gtkentry_get_current_icon_drag_source(zval *handle);
/*@zep Gtk\GtkEntry getExtraMenu(int handle) -> int */
zend_long phpgtk_gtkentry_get_extra_menu(zval *handle);
/*@zep Gtk\GtkEntry getHasFrame(int handle) -> bool */
zend_long phpgtk_gtkentry_get_has_frame(zval *handle);
/*@zep Gtk\GtkEntry getIconActivatable(int handle, int iconPos) -> bool */
zend_long phpgtk_gtkentry_get_icon_activatable(zval *handle, zval *iconPos);
/*@zep Gtk\GtkEntry getIconArea(int handle, int iconPos) -> array */
void phpgtk_gtkentry_get_icon_area(zval *return_value, zval *handle, zval *iconPos);
/*@zep Gtk\GtkEntry getIconAtPos(int handle, int x, int y) -> int */
zend_long phpgtk_gtkentry_get_icon_at_pos(zval *handle, zval *x, zval *y);
/*@zep Gtk\GtkEntry getIconGicon(int handle, int iconPos) -> int */
zend_long phpgtk_gtkentry_get_icon_gicon(zval *handle, zval *iconPos);
/*@zep Gtk\GtkEntry getIconName(int handle, int iconPos) -> var */
void phpgtk_gtkentry_get_icon_name(zval *return_value, zval *handle, zval *iconPos);
/*@zep Gtk\GtkEntry getIconPaintable(int handle, int iconPos) -> int */
zend_long phpgtk_gtkentry_get_icon_paintable(zval *handle, zval *iconPos);
/*@zep Gtk\GtkEntry getIconSensitive(int handle, int iconPos) -> bool */
zend_long phpgtk_gtkentry_get_icon_sensitive(zval *handle, zval *iconPos);
/*@zep Gtk\GtkEntry getIconStorageType(int handle, int iconPos) -> int */
zend_long phpgtk_gtkentry_get_icon_storage_type(zval *handle, zval *iconPos);
/*@zep Gtk\GtkEntry getIconTooltipMarkup(int handle, int iconPos) -> var */
void phpgtk_gtkentry_get_icon_tooltip_markup(zval *return_value, zval *handle, zval *iconPos);
/*@zep Gtk\GtkEntry getIconTooltipText(int handle, int iconPos) -> var */
void phpgtk_gtkentry_get_icon_tooltip_text(zval *return_value, zval *handle, zval *iconPos);
/*@zep Gtk\GtkEntry getInputHints(int handle) -> int */
zend_long phpgtk_gtkentry_get_input_hints(zval *handle);
/*@zep Gtk\GtkEntry getInputPurpose(int handle) -> int */
zend_long phpgtk_gtkentry_get_input_purpose(zval *handle);
/*@zep Gtk\GtkEntry getInvisibleChar(int handle) -> int */
zend_long phpgtk_gtkentry_get_invisible_char(zval *handle);
/*@zep Gtk\GtkEntry getMaxLength(int handle) -> int */
zend_long phpgtk_gtkentry_get_max_length(zval *handle);
/*@zep Gtk\GtkEntry getOverwriteMode(int handle) -> bool */
zend_long phpgtk_gtkentry_get_overwrite_mode(zval *handle);
/*@zep Gtk\GtkEntry getPlaceholderText(int handle) -> var */
void phpgtk_gtkentry_get_placeholder_text(zval *return_value, zval *handle);
/*@zep Gtk\GtkEntry getProgressFraction(int handle) -> double */
double phpgtk_gtkentry_get_progress_fraction(zval *handle);
/*@zep Gtk\GtkEntry getProgressPulseStep(int handle) -> double */
double phpgtk_gtkentry_get_progress_pulse_step(zval *handle);
/*@reserved Gtk\GtkEntry gtk_entry_get_tabs(self) — PangoTabArray* */
/*@zep Gtk\GtkEntry getTextLength(int handle) -> int */
zend_long phpgtk_gtkentry_get_text_length(zval *handle);
/*@zep Gtk\GtkEntry getVisibility(int handle) -> bool */
zend_long phpgtk_gtkentry_get_visibility(zval *handle);
/*@zep Gtk\GtkEntry grabFocusWithoutSelecting(int handle) -> bool */
zend_long phpgtk_gtkentry_grab_focus_without_selecting(zval *handle);
/*@zep Gtk\GtkEntry progressPulse(int handle) -> void */
void phpgtk_gtkentry_progress_pulse(zval *handle);
/*@zep Gtk\GtkEntry resetImContext(int handle) -> void */
void phpgtk_gtkentry_reset_im_context(zval *handle);
/*@zep Gtk\GtkEntry setActivatesDefault(int handle, bool setting) -> void */
void phpgtk_gtkentry_set_activates_default(zval *handle, zval *setting);
/*@zep Gtk\GtkEntry setAlignment(int handle, double xalign) -> void */
void phpgtk_gtkentry_set_alignment(zval *handle, zval *xalign);
/*@reserved Gtk\GtkEntry gtk_entry_set_attributes(self, PangoAttrList* attrs) — PangoAttrList* */
/*@zep Gtk\GtkEntry setBuffer(int handle, int buffer) -> void */
void phpgtk_gtkentry_set_buffer(zval *handle, zval *buffer);
/*@reserved Gtk\GtkEntry gtk_entry_set_completion(self, GtkEntryCompletion* completion) — deprecated */
/*@zep Gtk\GtkEntry setExtraMenu(int handle, int model) -> void */
void phpgtk_gtkentry_set_extra_menu(zval *handle, zval *model);
/*@zep Gtk\GtkEntry setHasFrame(int handle, bool setting) -> void */
void phpgtk_gtkentry_set_has_frame(zval *handle, zval *setting);
/*@zep Gtk\GtkEntry setIconActivatable(int handle, int iconPos, bool activatable) -> void */
void phpgtk_gtkentry_set_icon_activatable(zval *handle, zval *iconPos, zval *activatable);
/*@reserved Gtk\GtkEntry gtk_entry_set_icon_drag_source(self, icon_pos, GdkContentProvider* provider, actions) — GdkContentProvider* */
/*@zep Gtk\GtkEntry setIconFromGicon(int handle, int iconPos, int icon) -> void */
void phpgtk_gtkentry_set_icon_from_gicon(zval *handle, zval *iconPos, zval *icon);
/*@zep Gtk\GtkEntry setIconFromIconName(int handle, int iconPos, var iconName) -> void */
void phpgtk_gtkentry_set_icon_from_icon_name(zval *handle, zval *iconPos, zval *iconName);
/*@zep Gtk\GtkEntry setIconFromPaintable(int handle, int iconPos, int paintable) -> void */
void phpgtk_gtkentry_set_icon_from_paintable(zval *handle, zval *iconPos, zval *paintable);
/*@zep Gtk\GtkEntry setIconSensitive(int handle, int iconPos, bool sensitive) -> void */
void phpgtk_gtkentry_set_icon_sensitive(zval *handle, zval *iconPos, zval *sensitive);
/*@zep Gtk\GtkEntry setIconTooltipMarkup(int handle, int iconPos, var tooltip) -> void */
void phpgtk_gtkentry_set_icon_tooltip_markup(zval *handle, zval *iconPos, zval *tooltip);
/*@zep Gtk\GtkEntry setIconTooltipText(int handle, int iconPos, var tooltip) -> void */
void phpgtk_gtkentry_set_icon_tooltip_text(zval *handle, zval *iconPos, zval *tooltip);
/*@zep Gtk\GtkEntry setInputHints(int handle, int hints) -> void */
void phpgtk_gtkentry_set_input_hints(zval *handle, zval *hints);
/*@zep Gtk\GtkEntry setInputPurpose(int handle, int purpose) -> void */
void phpgtk_gtkentry_set_input_purpose(zval *handle, zval *purpose);
/*@zep Gtk\GtkEntry setInvisibleChar(int handle, int ch) -> void */
void phpgtk_gtkentry_set_invisible_char(zval *handle, zval *ch);
/*@zep Gtk\GtkEntry setMaxLength(int handle, int max) -> void */
void phpgtk_gtkentry_set_max_length(zval *handle, zval *max);
/*@zep Gtk\GtkEntry setOverwriteMode(int handle, bool overwrite) -> void */
void phpgtk_gtkentry_set_overwrite_mode(zval *handle, zval *overwrite);
/*@zep Gtk\GtkEntry setPlaceholderText(int handle, var text) -> void */
void phpgtk_gtkentry_set_placeholder_text(zval *handle, zval *text);
/*@zep Gtk\GtkEntry setProgressFraction(int handle, double fraction) -> void */
void phpgtk_gtkentry_set_progress_fraction(zval *handle, zval *fraction);
/*@zep Gtk\GtkEntry setProgressPulseStep(int handle, double fraction) -> void */
void phpgtk_gtkentry_set_progress_pulse_step(zval *handle, zval *fraction);
/*@reserved Gtk\GtkEntry gtk_entry_set_tabs(self, PangoTabArray* tabs) — PangoTabArray* */
/*@zep Gtk\GtkEntry setVisibility(int handle, bool visible) -> void */
void phpgtk_gtkentry_set_visibility(zval *handle, zval *visible);
/*@zep Gtk\GtkEntry unsetInvisibleChar(int handle) -> void */
void phpgtk_gtkentry_unset_invisible_char(zval *handle);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_ENTRY_H */
