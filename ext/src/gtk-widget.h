#ifndef PHP_GTK_GTK_WIDGET_H
#define PHP_GTK_GTK_WIDGET_H

/*
 * GtkWidget — slice zero. Every gir constructor/method/function is bound or
 * reserved. Inherited members bind here; subclasses do not rebind them.
 * Abstract: no constructor.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@reserved Gtk\GtkWidget property "height-request" — no dedicated C accessor; use getSizeRequest/setSizeRequest or Bridge::getProperty */
/*@reserved Gtk\GtkWidget property "width-request" — no dedicated C accessor; use getSizeRequest/setSizeRequest or Bridge::getProperty */

/*@zep Gtk\GtkWidget getDefaultDirection() -> int */
zend_long phpgtk_gtkwidget_get_default_direction(void);
/*@zep Gtk\GtkWidget setDefaultDirection(int dir) -> void */
void phpgtk_gtkwidget_set_default_direction(zval *dir);
/*@zep Gtk\GtkWidget actionSetEnabled(int handle, string actionName, bool enabled) -> void */
void phpgtk_gtkwidget_action_set_enabled(zval *handle, zval *actionName, zval *enabled);
/*@zep Gtk\GtkWidget activate(int handle) -> bool */
zend_long phpgtk_gtkwidget_activate(zval *handle);
/*@reserved Gtk\GtkWidget gtk_widget_activate_action(self, char* name, char* format_string, ... ...) — varargs */
/*@reserved Gtk\GtkWidget gtk_widget_activate_action_variant(self, char* name, GVariant* args) — GVariant* */
/*@zep Gtk\GtkWidget activateDefault(int handle) -> void */
void phpgtk_gtkwidget_activate_default(zval *handle);
/*@zep Gtk\GtkWidget addController(int handle, int controller) -> void */
void phpgtk_gtkwidget_add_controller(zval *handle, zval *controller);
/*@zep Gtk\GtkWidget addCssClass(int handle, string cssClass) -> void */
void phpgtk_gtkwidget_add_css_class(zval *handle, zval *cssClass);
/*@zep Gtk\GtkWidget addMnemonicLabel(int handle, int label) -> void */
void phpgtk_gtkwidget_add_mnemonic_label(zval *handle, zval *label);
/*@reserved Gtk\GtkWidget gtk_widget_add_tick_callback(self, GtkTickCallback callback, gpointer user_data, GDestroyNotify notify) — non-signal callback */
/*@reserved Gtk\GtkWidget gtk_widget_allocate(self, int width, int height, int baseline, GskTransform* transform) — GskTransform* boxed */
/*@zep Gtk\GtkWidget childFocus(int handle, int direction) -> bool */
zend_long phpgtk_gtkwidget_child_focus(zval *handle, zval *direction);
/*@zep Gtk\GtkWidget computeBounds(int handle, int target) -> var */
void phpgtk_gtkwidget_compute_bounds(zval *return_value, zval *handle, zval *target);
/*@zep Gtk\GtkWidget computeExpand(int handle, int orientation) -> bool */
zend_long phpgtk_gtkwidget_compute_expand(zval *handle, zval *orientation);
/*@zep Gtk\GtkWidget computePoint(int handle, int target, double pointX, double pointY) -> var */
void phpgtk_gtkwidget_compute_point(zval *return_value, zval *handle, zval *target, zval *pointX, zval *pointY);
/*@reserved Gtk\GtkWidget gtk_widget_compute_transform(self, GtkWidget* target, graphene_matrix_t* out_transform) — graphene_matrix_t */
/*@zep Gtk\GtkWidget contains(int handle, double x, double y) -> bool */
zend_long phpgtk_gtkwidget_contains(zval *handle, zval *x, zval *y);
/*@zep Gtk\GtkWidget createPangoContext(int handle) -> int */
zend_long phpgtk_gtkwidget_create_pango_context(zval *handle);
/*@zep Gtk\GtkWidget createPangoLayout(int handle, var text) -> int */
zend_long phpgtk_gtkwidget_create_pango_layout(zval *handle, zval *text);
/*@zep Gtk\GtkWidget disposeTemplate(int handle, int widgetType) -> void */
void phpgtk_gtkwidget_dispose_template(zval *handle, zval *widgetType);
/*@zep Gtk\GtkWidget dragCheckThreshold(int handle, int startX, int startY, int currentX, int currentY) -> bool */
zend_long phpgtk_gtkwidget_drag_check_threshold(zval *handle, zval *startX, zval *startY, zval *currentX, zval *currentY);
/*@zep Gtk\GtkWidget errorBell(int handle) -> void */
void phpgtk_gtkwidget_error_bell(zval *handle);
/*@reserved Gtk\GtkWidget gtk_widget_get_allocated_baseline(self) — deprecated */
/*@reserved Gtk\GtkWidget gtk_widget_get_allocated_height(self) — deprecated */
/*@reserved Gtk\GtkWidget gtk_widget_get_allocated_width(self) — deprecated */
/*@reserved Gtk\GtkWidget gtk_widget_get_allocation(self, GtkAllocation* allocation) — deprecated */
/*@zep Gtk\GtkWidget getAncestor(int handle, int widgetType) -> int */
zend_long phpgtk_gtkwidget_get_ancestor(zval *handle, zval *widgetType);
/*@zep Gtk\GtkWidget getBaseline(int handle) -> int */
zend_long phpgtk_gtkwidget_get_baseline(zval *handle);
/*@zep Gtk\GtkWidget getCanFocus(int handle) -> bool */
zend_long phpgtk_gtkwidget_get_can_focus(zval *handle);
/*@zep Gtk\GtkWidget getCanTarget(int handle) -> bool */
zend_long phpgtk_gtkwidget_get_can_target(zval *handle);
/*@zep Gtk\GtkWidget getChildVisible(int handle) -> bool */
zend_long phpgtk_gtkwidget_get_child_visible(zval *handle);
/*@zep Gtk\GtkWidget getClipboard(int handle) -> int */
zend_long phpgtk_gtkwidget_get_clipboard(zval *handle);
/*@zep Gtk\GtkWidget getColor(int handle) -> array */
void phpgtk_gtkwidget_get_color(zval *return_value, zval *handle);
/*@zep Gtk\GtkWidget getCssClasses(int handle) -> array */
void phpgtk_gtkwidget_get_css_classes(zval *return_value, zval *handle);
/*@zep Gtk\GtkWidget getCssName(int handle) -> string */
void phpgtk_gtkwidget_get_css_name(zval *return_value, zval *handle);
/*@zep Gtk\GtkWidget getCursor(int handle) -> int */
zend_long phpgtk_gtkwidget_get_cursor(zval *handle);
/*@zep Gtk\GtkWidget getDirection(int handle) -> int */
zend_long phpgtk_gtkwidget_get_direction(zval *handle);
/*@zep Gtk\GtkWidget getDisplay(int handle) -> int */
zend_long phpgtk_gtkwidget_get_display(zval *handle);
/*@zep Gtk\GtkWidget getFirstChild(int handle) -> int */
zend_long phpgtk_gtkwidget_get_first_child(zval *handle);
/*@zep Gtk\GtkWidget getFocusChild(int handle) -> int */
zend_long phpgtk_gtkwidget_get_focus_child(zval *handle);
/*@zep Gtk\GtkWidget getFocusOnClick(int handle) -> bool */
zend_long phpgtk_gtkwidget_get_focus_on_click(zval *handle);
/*@zep Gtk\GtkWidget getFocusable(int handle) -> bool */
zend_long phpgtk_gtkwidget_get_focusable(zval *handle);
/*@zep Gtk\GtkWidget getFontMap(int handle) -> int */
zend_long phpgtk_gtkwidget_get_font_map(zval *handle);
/*@reserved Gtk\GtkWidget gtk_widget_get_font_options(self) — deprecated */
/*@zep Gtk\GtkWidget getFrameClock(int handle) -> int */
zend_long phpgtk_gtkwidget_get_frame_clock(zval *handle);
/*@zep Gtk\GtkWidget getHalign(int handle) -> int */
zend_long phpgtk_gtkwidget_get_halign(zval *handle);
/*@zep Gtk\GtkWidget getHasTooltip(int handle) -> bool */
zend_long phpgtk_gtkwidget_get_has_tooltip(zval *handle);
/*@zep Gtk\GtkWidget getHeight(int handle) -> int */
zend_long phpgtk_gtkwidget_get_height(zval *handle);
/*@zep Gtk\GtkWidget getHexpand(int handle) -> bool */
zend_long phpgtk_gtkwidget_get_hexpand(zval *handle);
/*@zep Gtk\GtkWidget getHexpandSet(int handle) -> bool */
zend_long phpgtk_gtkwidget_get_hexpand_set(zval *handle);
/*@zep Gtk\GtkWidget getLastChild(int handle) -> int */
zend_long phpgtk_gtkwidget_get_last_child(zval *handle);
/*@zep Gtk\GtkWidget getLayoutManager(int handle) -> int */
zend_long phpgtk_gtkwidget_get_layout_manager(zval *handle);
/*@zep Gtk\GtkWidget getLimitEvents(int handle) -> bool */
zend_long phpgtk_gtkwidget_get_limit_events(zval *handle);
/*@zep Gtk\GtkWidget getMapped(int handle) -> bool */
zend_long phpgtk_gtkwidget_get_mapped(zval *handle);
/*@zep Gtk\GtkWidget getMarginBottom(int handle) -> int */
zend_long phpgtk_gtkwidget_get_margin_bottom(zval *handle);
/*@zep Gtk\GtkWidget getMarginEnd(int handle) -> int */
zend_long phpgtk_gtkwidget_get_margin_end(zval *handle);
/*@zep Gtk\GtkWidget getMarginStart(int handle) -> int */
zend_long phpgtk_gtkwidget_get_margin_start(zval *handle);
/*@zep Gtk\GtkWidget getMarginTop(int handle) -> int */
zend_long phpgtk_gtkwidget_get_margin_top(zval *handle);
/*@zep Gtk\GtkWidget getName(int handle) -> string */
void phpgtk_gtkwidget_get_name(zval *return_value, zval *handle);
/*@zep Gtk\GtkWidget getNative(int handle) -> int */
zend_long phpgtk_gtkwidget_get_native(zval *handle);
/*@zep Gtk\GtkWidget getNextSibling(int handle) -> int */
zend_long phpgtk_gtkwidget_get_next_sibling(zval *handle);
/*@zep Gtk\GtkWidget getOpacity(int handle) -> double */
double phpgtk_gtkwidget_get_opacity(zval *handle);
/*@zep Gtk\GtkWidget getOverflow(int handle) -> int */
zend_long phpgtk_gtkwidget_get_overflow(zval *handle);
/*@zep Gtk\GtkWidget getPangoContext(int handle) -> int */
zend_long phpgtk_gtkwidget_get_pango_context(zval *handle);
/*@zep Gtk\GtkWidget getParent(int handle) -> int */
zend_long phpgtk_gtkwidget_get_parent(zval *handle);
/*@zep Gtk\GtkWidget getPreferredSize(int handle) -> array */
void phpgtk_gtkwidget_get_preferred_size(zval *return_value, zval *handle);
/*@zep Gtk\GtkWidget getPrevSibling(int handle) -> int */
zend_long phpgtk_gtkwidget_get_prev_sibling(zval *handle);
/*@zep Gtk\GtkWidget getPrimaryClipboard(int handle) -> int */
zend_long phpgtk_gtkwidget_get_primary_clipboard(zval *handle);
/*@zep Gtk\GtkWidget getRealized(int handle) -> bool */
zend_long phpgtk_gtkwidget_get_realized(zval *handle);
/*@zep Gtk\GtkWidget getReceivesDefault(int handle) -> bool */
zend_long phpgtk_gtkwidget_get_receives_default(zval *handle);
/*@zep Gtk\GtkWidget getRequestMode(int handle) -> int */
zend_long phpgtk_gtkwidget_get_request_mode(zval *handle);
/*@zep Gtk\GtkWidget getRoot(int handle) -> int */
zend_long phpgtk_gtkwidget_get_root(zval *handle);
/*@zep Gtk\GtkWidget getScaleFactor(int handle) -> int */
zend_long phpgtk_gtkwidget_get_scale_factor(zval *handle);
/*@zep Gtk\GtkWidget getSensitive(int handle) -> bool */
zend_long phpgtk_gtkwidget_get_sensitive(zval *handle);
/*@zep Gtk\GtkWidget getSettings(int handle) -> int */
zend_long phpgtk_gtkwidget_get_settings(zval *handle);
/*@zep Gtk\GtkWidget getSize(int handle, int orientation) -> int */
zend_long phpgtk_gtkwidget_get_size(zval *handle, zval *orientation);
/*@zep Gtk\GtkWidget getSizeRequest(int handle) -> array */
void phpgtk_gtkwidget_get_size_request(zval *return_value, zval *handle);
/*@zep Gtk\GtkWidget getStateFlags(int handle) -> int */
zend_long phpgtk_gtkwidget_get_state_flags(zval *handle);
/*@reserved Gtk\GtkWidget gtk_widget_get_style_context(self) — deprecated */
/*@zep Gtk\GtkWidget getTemplateChild(int handle, int widgetType, string name) -> int */
zend_long phpgtk_gtkwidget_get_template_child(zval *handle, zval *widgetType, zval *name);
/*@zep Gtk\GtkWidget getTooltipMarkup(int handle) -> var */
void phpgtk_gtkwidget_get_tooltip_markup(zval *return_value, zval *handle);
/*@zep Gtk\GtkWidget getTooltipText(int handle) -> var */
void phpgtk_gtkwidget_get_tooltip_text(zval *return_value, zval *handle);
/*@zep Gtk\GtkWidget getValign(int handle) -> int */
zend_long phpgtk_gtkwidget_get_valign(zval *handle);
/*@zep Gtk\GtkWidget getVexpand(int handle) -> bool */
zend_long phpgtk_gtkwidget_get_vexpand(zval *handle);
/*@zep Gtk\GtkWidget getVexpandSet(int handle) -> bool */
zend_long phpgtk_gtkwidget_get_vexpand_set(zval *handle);
/*@zep Gtk\GtkWidget getVisible(int handle) -> bool */
zend_long phpgtk_gtkwidget_get_visible(zval *handle);
/*@zep Gtk\GtkWidget getWidth(int handle) -> int */
zend_long phpgtk_gtkwidget_get_width(zval *handle);
/*@zep Gtk\GtkWidget grabFocus(int handle) -> bool */
zend_long phpgtk_gtkwidget_grab_focus(zval *handle);
/*@zep Gtk\GtkWidget hasCssClass(int handle, string cssClass) -> bool */
zend_long phpgtk_gtkwidget_has_css_class(zval *handle, zval *cssClass);
/*@zep Gtk\GtkWidget hasDefault(int handle) -> bool */
zend_long phpgtk_gtkwidget_has_default(zval *handle);
/*@zep Gtk\GtkWidget hasFocus(int handle) -> bool */
zend_long phpgtk_gtkwidget_has_focus(zval *handle);
/*@zep Gtk\GtkWidget hasVisibleFocus(int handle) -> bool */
zend_long phpgtk_gtkwidget_has_visible_focus(zval *handle);
/*@reserved Gtk\GtkWidget gtk_widget_hide(self) — deprecated */
/*@zep Gtk\GtkWidget inDestruction(int handle) -> bool */
zend_long phpgtk_gtkwidget_in_destruction(zval *handle);
/*@zep Gtk\GtkWidget initTemplate(int handle) -> void */
void phpgtk_gtkwidget_init_template(zval *handle);
/*@zep Gtk\GtkWidget insertActionGroup(int handle, string name, int group) -> void */
void phpgtk_gtkwidget_insert_action_group(zval *handle, zval *name, zval *group);
/*@zep Gtk\GtkWidget insertAfter(int handle, int parent, int previousSibling) -> void */
void phpgtk_gtkwidget_insert_after(zval *handle, zval *parent, zval *previousSibling);
/*@zep Gtk\GtkWidget insertBefore(int handle, int parent, int nextSibling) -> void */
void phpgtk_gtkwidget_insert_before(zval *handle, zval *parent, zval *nextSibling);
/*@zep Gtk\GtkWidget isAncestor(int handle, int ancestor) -> bool */
zend_long phpgtk_gtkwidget_is_ancestor(zval *handle, zval *ancestor);
/*@zep Gtk\GtkWidget isDrawable(int handle) -> bool */
zend_long phpgtk_gtkwidget_is_drawable(zval *handle);
/*@zep Gtk\GtkWidget isFocus(int handle) -> bool */
zend_long phpgtk_gtkwidget_is_focus(zval *handle);
/*@zep Gtk\GtkWidget isSensitive(int handle) -> bool */
zend_long phpgtk_gtkwidget_is_sensitive(zval *handle);
/*@zep Gtk\GtkWidget isVisible(int handle) -> bool */
zend_long phpgtk_gtkwidget_is_visible(zval *handle);
/*@zep Gtk\GtkWidget keynavFailed(int handle, int direction) -> bool */
zend_long phpgtk_gtkwidget_keynav_failed(zval *handle, zval *direction);
/*@zep Gtk\GtkWidget listMnemonicLabels(int handle) -> array */
void phpgtk_gtkwidget_list_mnemonic_labels(zval *return_value, zval *handle);
/*@zep Gtk\GtkWidget map(int handle) -> void */
void phpgtk_gtkwidget_map(zval *handle);
/*@zep Gtk\GtkWidget measure(int handle, int orientation, int forSize) -> array */
void phpgtk_gtkwidget_measure(zval *return_value, zval *handle, zval *orientation, zval *forSize);
/*@zep Gtk\GtkWidget mnemonicActivate(int handle, bool groupCycling) -> bool */
zend_long phpgtk_gtkwidget_mnemonic_activate(zval *handle, zval *groupCycling);
/*@zep Gtk\GtkWidget observeChildren(int handle) -> int */
zend_long phpgtk_gtkwidget_observe_children(zval *handle);
/*@zep Gtk\GtkWidget observeControllers(int handle) -> int */
zend_long phpgtk_gtkwidget_observe_controllers(zval *handle);
/*@zep Gtk\GtkWidget pick(int handle, double x, double y, int flags) -> int */
zend_long phpgtk_gtkwidget_pick(zval *handle, zval *x, zval *y, zval *flags);
/*@zep Gtk\GtkWidget queueAllocate(int handle) -> void */
void phpgtk_gtkwidget_queue_allocate(zval *handle);
/*@zep Gtk\GtkWidget queueDraw(int handle) -> void */
void phpgtk_gtkwidget_queue_draw(zval *handle);
/*@zep Gtk\GtkWidget queueResize(int handle) -> void */
void phpgtk_gtkwidget_queue_resize(zval *handle);
/*@zep Gtk\GtkWidget realize(int handle) -> void */
void phpgtk_gtkwidget_realize(zval *handle);
/*@zep Gtk\GtkWidget removeController(int handle, int controller) -> void */
void phpgtk_gtkwidget_remove_controller(zval *handle, zval *controller);
/*@zep Gtk\GtkWidget removeCssClass(int handle, string cssClass) -> void */
void phpgtk_gtkwidget_remove_css_class(zval *handle, zval *cssClass);
/*@zep Gtk\GtkWidget removeMnemonicLabel(int handle, int label) -> void */
void phpgtk_gtkwidget_remove_mnemonic_label(zval *handle, zval *label);
/*@zep Gtk\GtkWidget removeTickCallback(int handle, int id) -> void */
void phpgtk_gtkwidget_remove_tick_callback(zval *handle, zval *id);
/*@zep Gtk\GtkWidget setCanFocus(int handle, bool canFocus) -> void */
void phpgtk_gtkwidget_set_can_focus(zval *handle, zval *canFocus);
/*@zep Gtk\GtkWidget setCanTarget(int handle, bool canTarget) -> void */
void phpgtk_gtkwidget_set_can_target(zval *handle, zval *canTarget);
/*@zep Gtk\GtkWidget setChildVisible(int handle, bool childVisible) -> void */
void phpgtk_gtkwidget_set_child_visible(zval *handle, zval *childVisible);
/*@zep Gtk\GtkWidget setCssClasses(int handle, array classes) -> void */
void phpgtk_gtkwidget_set_css_classes(zval *handle, zval *classes);
/*@zep Gtk\GtkWidget setCursor(int handle, int cursor) -> void */
void phpgtk_gtkwidget_set_cursor(zval *handle, zval *cursor);
/*@zep Gtk\GtkWidget setCursorFromName(int handle, var name) -> void */
void phpgtk_gtkwidget_set_cursor_from_name(zval *handle, zval *name);
/*@zep Gtk\GtkWidget setDirection(int handle, int dir) -> void */
void phpgtk_gtkwidget_set_direction(zval *handle, zval *dir);
/*@zep Gtk\GtkWidget setFocusChild(int handle, int child) -> void */
void phpgtk_gtkwidget_set_focus_child(zval *handle, zval *child);
/*@zep Gtk\GtkWidget setFocusOnClick(int handle, bool focusOnClick) -> void */
void phpgtk_gtkwidget_set_focus_on_click(zval *handle, zval *focusOnClick);
/*@zep Gtk\GtkWidget setFocusable(int handle, bool focusable) -> void */
void phpgtk_gtkwidget_set_focusable(zval *handle, zval *focusable);
/*@zep Gtk\GtkWidget setFontMap(int handle, int fontMap) -> void */
void phpgtk_gtkwidget_set_font_map(zval *handle, zval *fontMap);
/*@reserved Gtk\GtkWidget gtk_widget_set_font_options(self, cairo_font_options_t* options) — deprecated */
/*@zep Gtk\GtkWidget setHalign(int handle, int align) -> void */
void phpgtk_gtkwidget_set_halign(zval *handle, zval *align);
/*@zep Gtk\GtkWidget setHasTooltip(int handle, bool hasTooltip) -> void */
void phpgtk_gtkwidget_set_has_tooltip(zval *handle, zval *hasTooltip);
/*@zep Gtk\GtkWidget setHexpand(int handle, bool expand) -> void */
void phpgtk_gtkwidget_set_hexpand(zval *handle, zval *expand);
/*@zep Gtk\GtkWidget setHexpandSet(int handle, bool set) -> void */
void phpgtk_gtkwidget_set_hexpand_set(zval *handle, zval *set);
/*@zep Gtk\GtkWidget setLayoutManager(int handle, int layoutManager) -> void */
void phpgtk_gtkwidget_set_layout_manager(zval *handle, zval *layoutManager);
/*@zep Gtk\GtkWidget setLimitEvents(int handle, bool limitEvents) -> void */
void phpgtk_gtkwidget_set_limit_events(zval *handle, zval *limitEvents);
/*@zep Gtk\GtkWidget setMarginBottom(int handle, int margin) -> void */
void phpgtk_gtkwidget_set_margin_bottom(zval *handle, zval *margin);
/*@zep Gtk\GtkWidget setMarginEnd(int handle, int margin) -> void */
void phpgtk_gtkwidget_set_margin_end(zval *handle, zval *margin);
/*@zep Gtk\GtkWidget setMarginStart(int handle, int margin) -> void */
void phpgtk_gtkwidget_set_margin_start(zval *handle, zval *margin);
/*@zep Gtk\GtkWidget setMarginTop(int handle, int margin) -> void */
void phpgtk_gtkwidget_set_margin_top(zval *handle, zval *margin);
/*@zep Gtk\GtkWidget setName(int handle, string name) -> void */
void phpgtk_gtkwidget_set_name(zval *handle, zval *name);
/*@zep Gtk\GtkWidget setOpacity(int handle, double opacity) -> void */
void phpgtk_gtkwidget_set_opacity(zval *handle, zval *opacity);
/*@zep Gtk\GtkWidget setOverflow(int handle, int overflow) -> void */
void phpgtk_gtkwidget_set_overflow(zval *handle, zval *overflow);
/*@zep Gtk\GtkWidget setParent(int handle, int parent) -> void */
void phpgtk_gtkwidget_set_parent(zval *handle, zval *parent);
/*@zep Gtk\GtkWidget setReceivesDefault(int handle, bool receivesDefault) -> void */
void phpgtk_gtkwidget_set_receives_default(zval *handle, zval *receivesDefault);
/*@zep Gtk\GtkWidget setSensitive(int handle, bool sensitive) -> void */
void phpgtk_gtkwidget_set_sensitive(zval *handle, zval *sensitive);
/*@zep Gtk\GtkWidget setSizeRequest(int handle, int width, int height) -> void */
void phpgtk_gtkwidget_set_size_request(zval *handle, zval *width, zval *height);
/*@zep Gtk\GtkWidget setStateFlags(int handle, int flags, bool clear) -> void */
void phpgtk_gtkwidget_set_state_flags(zval *handle, zval *flags, zval *clear);
/*@zep Gtk\GtkWidget setTooltipMarkup(int handle, var markup) -> void */
void phpgtk_gtkwidget_set_tooltip_markup(zval *handle, zval *markup);
/*@zep Gtk\GtkWidget setTooltipText(int handle, var text) -> void */
void phpgtk_gtkwidget_set_tooltip_text(zval *handle, zval *text);
/*@zep Gtk\GtkWidget setValign(int handle, int align) -> void */
void phpgtk_gtkwidget_set_valign(zval *handle, zval *align);
/*@zep Gtk\GtkWidget setVexpand(int handle, bool expand) -> void */
void phpgtk_gtkwidget_set_vexpand(zval *handle, zval *expand);
/*@zep Gtk\GtkWidget setVexpandSet(int handle, bool set) -> void */
void phpgtk_gtkwidget_set_vexpand_set(zval *handle, zval *set);
/*@zep Gtk\GtkWidget setVisible(int handle, bool visible) -> void */
void phpgtk_gtkwidget_set_visible(zval *handle, zval *visible);
/*@zep Gtk\GtkWidget shouldLayout(int handle) -> bool */
zend_long phpgtk_gtkwidget_should_layout(zval *handle);
/*@reserved Gtk\GtkWidget gtk_widget_show(self) — deprecated */
/*@zep Gtk\GtkWidget sizeAllocate(int handle, int allocationX, int allocationY, int allocationWidth, int allocationHeight, int baseline) -> void */
void phpgtk_gtkwidget_size_allocate(zval *handle, zval *allocationX, zval *allocationY, zval *allocationWidth, zval *allocationHeight, zval *baseline);
/*@zep Gtk\GtkWidget snapshotChild(int handle, int child, int snapshot) -> void */
void phpgtk_gtkwidget_snapshot_child(zval *handle, zval *child, zval *snapshot);
/*@reserved Gtk\GtkWidget gtk_widget_translate_coordinates(self, GtkWidget* dest_widget, double src_x, double src_y, double* dest_x, double* dest_y) — deprecated */
/*@zep Gtk\GtkWidget triggerTooltipQuery(int handle) -> void */
void phpgtk_gtkwidget_trigger_tooltip_query(zval *handle);
/*@zep Gtk\GtkWidget unmap(int handle) -> void */
void phpgtk_gtkwidget_unmap(zval *handle);
/*@zep Gtk\GtkWidget unparent(int handle) -> void */
void phpgtk_gtkwidget_unparent(zval *handle);
/*@zep Gtk\GtkWidget unrealize(int handle) -> void */
void phpgtk_gtkwidget_unrealize(zval *handle);
/*@zep Gtk\GtkWidget unsetStateFlags(int handle, int flags) -> void */
void phpgtk_gtkwidget_unset_state_flags(zval *handle, zval *flags);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_WIDGET_H */
