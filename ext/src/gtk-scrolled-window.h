#ifndef PHP_GTK_GTK_SCROLLED_WINDOW_H
#define PHP_GTK_GTK_SCROLLED_WINDOW_H

/*
 * GtkScrolledWindow — Wave A8. Every gir constructor/method/function is
 * bound or reserved. get_policy's out-params are {hscrollbar_policy,
 * vscrollbar_policy}. The hscrollbar-policy / vscrollbar-policy properties
 * have no dedicated C accessors (covered by get/set_policy) so they are
 * reserved as properties.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@reserved Gtk\GtkScrolledWindow property "hscrollbar-policy" — no dedicated C accessor; use getPolicy/setPolicy or Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkScrolledWindow property "vscrollbar-policy" — no dedicated C accessor; use getPolicy/setPolicy or Bridge::getProperty/setProperty */

/*@zep Gtk\GtkScrolledWindow new() -> int */
zend_long phpgtk_gtkscrolledwindow_new(void);
/*@zep Gtk\GtkScrolledWindow getChild(int handle) -> int */
zend_long phpgtk_gtkscrolledwindow_get_child(zval *handle);
/*@zep Gtk\GtkScrolledWindow getHadjustment(int handle) -> int */
zend_long phpgtk_gtkscrolledwindow_get_hadjustment(zval *handle);
/*@zep Gtk\GtkScrolledWindow getHasFrame(int handle) -> bool */
zend_long phpgtk_gtkscrolledwindow_get_has_frame(zval *handle);
/*@zep Gtk\GtkScrolledWindow getHscrollbar(int handle) -> int */
zend_long phpgtk_gtkscrolledwindow_get_hscrollbar(zval *handle);
/*@zep Gtk\GtkScrolledWindow getKineticScrolling(int handle) -> bool */
zend_long phpgtk_gtkscrolledwindow_get_kinetic_scrolling(zval *handle);
/*@zep Gtk\GtkScrolledWindow getMaxContentHeight(int handle) -> int */
zend_long phpgtk_gtkscrolledwindow_get_max_content_height(zval *handle);
/*@zep Gtk\GtkScrolledWindow getMaxContentWidth(int handle) -> int */
zend_long phpgtk_gtkscrolledwindow_get_max_content_width(zval *handle);
/*@zep Gtk\GtkScrolledWindow getMinContentHeight(int handle) -> int */
zend_long phpgtk_gtkscrolledwindow_get_min_content_height(zval *handle);
/*@zep Gtk\GtkScrolledWindow getMinContentWidth(int handle) -> int */
zend_long phpgtk_gtkscrolledwindow_get_min_content_width(zval *handle);
/*@zep Gtk\GtkScrolledWindow getOverlayScrolling(int handle) -> bool */
zend_long phpgtk_gtkscrolledwindow_get_overlay_scrolling(zval *handle);
/*@zep Gtk\GtkScrolledWindow getPlacement(int handle) -> int */
zend_long phpgtk_gtkscrolledwindow_get_placement(zval *handle);
/*@zep Gtk\GtkScrolledWindow getPolicy(int handle) -> array */
void phpgtk_gtkscrolledwindow_get_policy(zval *return_value, zval *handle);
/*@zep Gtk\GtkScrolledWindow getPropagateNaturalHeight(int handle) -> bool */
zend_long phpgtk_gtkscrolledwindow_get_propagate_natural_height(zval *handle);
/*@zep Gtk\GtkScrolledWindow getPropagateNaturalWidth(int handle) -> bool */
zend_long phpgtk_gtkscrolledwindow_get_propagate_natural_width(zval *handle);
/*@zep Gtk\GtkScrolledWindow getVadjustment(int handle) -> int */
zend_long phpgtk_gtkscrolledwindow_get_vadjustment(zval *handle);
/*@zep Gtk\GtkScrolledWindow getVscrollbar(int handle) -> int */
zend_long phpgtk_gtkscrolledwindow_get_vscrollbar(zval *handle);
/*@zep Gtk\GtkScrolledWindow setChild(int handle, int child) -> void */
void phpgtk_gtkscrolledwindow_set_child(zval *handle, zval *child);
/*@zep Gtk\GtkScrolledWindow setHadjustment(int handle, int hadjustment) -> void */
void phpgtk_gtkscrolledwindow_set_hadjustment(zval *handle, zval *hadjustment);
/*@zep Gtk\GtkScrolledWindow setHasFrame(int handle, bool hasFrame) -> void */
void phpgtk_gtkscrolledwindow_set_has_frame(zval *handle, zval *hasFrame);
/*@zep Gtk\GtkScrolledWindow setKineticScrolling(int handle, bool kineticScrolling) -> void */
void phpgtk_gtkscrolledwindow_set_kinetic_scrolling(zval *handle, zval *kineticScrolling);
/*@zep Gtk\GtkScrolledWindow setMaxContentHeight(int handle, int height) -> void */
void phpgtk_gtkscrolledwindow_set_max_content_height(zval *handle, zval *height);
/*@zep Gtk\GtkScrolledWindow setMaxContentWidth(int handle, int width) -> void */
void phpgtk_gtkscrolledwindow_set_max_content_width(zval *handle, zval *width);
/*@zep Gtk\GtkScrolledWindow setMinContentHeight(int handle, int height) -> void */
void phpgtk_gtkscrolledwindow_set_min_content_height(zval *handle, zval *height);
/*@zep Gtk\GtkScrolledWindow setMinContentWidth(int handle, int width) -> void */
void phpgtk_gtkscrolledwindow_set_min_content_width(zval *handle, zval *width);
/*@zep Gtk\GtkScrolledWindow setOverlayScrolling(int handle, bool overlayScrolling) -> void */
void phpgtk_gtkscrolledwindow_set_overlay_scrolling(zval *handle, zval *overlayScrolling);
/*@zep Gtk\GtkScrolledWindow setPlacement(int handle, int windowPlacement) -> void */
void phpgtk_gtkscrolledwindow_set_placement(zval *handle, zval *windowPlacement);
/*@zep Gtk\GtkScrolledWindow setPolicy(int handle, int hscrollbarPolicy, int vscrollbarPolicy) -> void */
void phpgtk_gtkscrolledwindow_set_policy(zval *handle, zval *hscrollbarPolicy, zval *vscrollbarPolicy);
/*@zep Gtk\GtkScrolledWindow setPropagateNaturalHeight(int handle, bool propagate) -> void */
void phpgtk_gtkscrolledwindow_set_propagate_natural_height(zval *handle, zval *propagate);
/*@zep Gtk\GtkScrolledWindow setPropagateNaturalWidth(int handle, bool propagate) -> void */
void phpgtk_gtkscrolledwindow_set_propagate_natural_width(zval *handle, zval *propagate);
/*@zep Gtk\GtkScrolledWindow setVadjustment(int handle, int vadjustment) -> void */
void phpgtk_gtkscrolledwindow_set_vadjustment(zval *handle, zval *vadjustment);
/*@zep Gtk\GtkScrolledWindow unsetPlacement(int handle) -> void */
void phpgtk_gtkscrolledwindow_unset_placement(zval *handle);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_SCROLLED_WINDOW_H */
