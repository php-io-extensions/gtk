#ifndef PHP_GTK_GTK_VIEWPORT_H
#define PHP_GTK_GTK_VIEWPORT_H

/*
 * GtkViewport — Wave A8. Every gir constructor/method/function is bound
 * or reserved. scroll_to takes GtkScrollInfo* and stays reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkViewport new(int hadjustment, int vadjustment) -> int */
zend_long phpgtk_gtkviewport_new(zval *hadjustment, zval *vadjustment);
/*@zep Gtk\GtkViewport getChild(int handle) -> int */
zend_long phpgtk_gtkviewport_get_child(zval *handle);
/*@zep Gtk\GtkViewport getScrollToFocus(int handle) -> bool */
zend_long phpgtk_gtkviewport_get_scroll_to_focus(zval *handle);
/*@reserved Gtk\GtkViewport gtk_viewport_scroll_to(GtkViewport* self, GtkWidget* descendant, GtkScrollInfo* scroll) — GtkScrollInfo* boxed */
/*@zep Gtk\GtkViewport setChild(int handle, int child) -> void */
void phpgtk_gtkviewport_set_child(zval *handle, zval *child);
/*@zep Gtk\GtkViewport setScrollToFocus(int handle, bool scrollToFocus) -> void */
void phpgtk_gtkviewport_set_scroll_to_focus(zval *handle, zval *scrollToFocus);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_VIEWPORT_H */
