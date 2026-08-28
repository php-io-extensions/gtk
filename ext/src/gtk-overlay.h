#ifndef PHP_GTK_GTK_OVERLAY_H
#define PHP_GTK_GTK_OVERLAY_H

/*
 * GtkOverlay — Wave A7. Every gir constructor/method/function is bound
 * or reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkOverlay new() -> int */
zend_long phpgtk_gtkoverlay_new(void);
/*@zep Gtk\GtkOverlay addOverlay(int handle, int widget) -> void */
void phpgtk_gtkoverlay_add_overlay(zval *handle, zval *widget);
/*@zep Gtk\GtkOverlay getChild(int handle) -> int */
zend_long phpgtk_gtkoverlay_get_child(zval *handle);
/*@zep Gtk\GtkOverlay getClipOverlay(int handle, int widget) -> bool */
zend_long phpgtk_gtkoverlay_get_clip_overlay(zval *handle, zval *widget);
/*@zep Gtk\GtkOverlay getMeasureOverlay(int handle, int widget) -> bool */
zend_long phpgtk_gtkoverlay_get_measure_overlay(zval *handle, zval *widget);
/*@zep Gtk\GtkOverlay removeOverlay(int handle, int widget) -> void */
void phpgtk_gtkoverlay_remove_overlay(zval *handle, zval *widget);
/*@zep Gtk\GtkOverlay setChild(int handle, int child) -> void */
void phpgtk_gtkoverlay_set_child(zval *handle, zval *child);
/*@zep Gtk\GtkOverlay setClipOverlay(int handle, int widget, bool clipOverlay) -> void */
void phpgtk_gtkoverlay_set_clip_overlay(zval *handle, zval *widget, zval *clipOverlay);
/*@zep Gtk\GtkOverlay setMeasureOverlay(int handle, int widget, bool measure) -> void */
void phpgtk_gtkoverlay_set_measure_overlay(zval *handle, zval *widget, zval *measure);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_OVERLAY_H */
