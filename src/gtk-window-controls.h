#ifndef PHP_GTK_GTK_WINDOW_CONTROLS_H
#define PHP_GTK_GTK_WINDOW_CONTROLS_H

/*
 * GtkWindowControls — Wave B6. Every gir
 * constructor/method/function is bound or reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkWindowControls new_(int side) -> int */
zend_long phpgtk_gtkwindowcontrols_new(zval *side);
/*@zep Gtk\GtkWindowControls getDecorationLayout(int handle) -> var */
void phpgtk_gtkwindowcontrols_get_decoration_layout(zval *return_value, zval *handle);
/*@zep Gtk\GtkWindowControls getEmpty(int handle) -> bool */
zend_long phpgtk_gtkwindowcontrols_get_empty(zval *handle);
/*@zep Gtk\GtkWindowControls getSide(int handle) -> int */
zend_long phpgtk_gtkwindowcontrols_get_side(zval *handle);
/*@zep Gtk\GtkWindowControls getUseNativeControls(int handle) -> bool */
zend_long phpgtk_gtkwindowcontrols_get_use_native_controls(zval *handle);
/*@zep Gtk\GtkWindowControls setDecorationLayout(int handle, var layout) -> void */
void phpgtk_gtkwindowcontrols_set_decoration_layout(zval *handle, zval *layout);
/*@zep Gtk\GtkWindowControls setSide(int handle, int side) -> void */
void phpgtk_gtkwindowcontrols_set_side(zval *handle, zval *side);
/*@zep Gtk\GtkWindowControls setUseNativeControls(int handle, bool setting) -> void */
void phpgtk_gtkwindowcontrols_set_use_native_controls(zval *handle, zval *setting);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_WINDOW_CONTROLS_H */
