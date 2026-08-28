#ifndef PHP_GTK_GTK_HEADER_BAR_H
#define PHP_GTK_GTK_HEADER_BAR_H

/*
 * GtkHeaderBar — Wave B6. Every gir
 * constructor/method/function is bound or reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkHeaderBar new_() -> int */
zend_long phpgtk_gtkheaderbar_new(void);
/*@zep Gtk\GtkHeaderBar getDecorationLayout(int handle) -> var */
void phpgtk_gtkheaderbar_get_decoration_layout(zval *return_value, zval *handle);
/*@zep Gtk\GtkHeaderBar getShowTitleButtons(int handle) -> bool */
zend_long phpgtk_gtkheaderbar_get_show_title_buttons(zval *handle);
/*@zep Gtk\GtkHeaderBar getTitleWidget(int handle) -> int */
zend_long phpgtk_gtkheaderbar_get_title_widget(zval *handle);
/*@zep Gtk\GtkHeaderBar getUseNativeControls(int handle) -> bool */
zend_long phpgtk_gtkheaderbar_get_use_native_controls(zval *handle);
/*@zep Gtk\GtkHeaderBar packEnd(int handle, int child) -> void */
void phpgtk_gtkheaderbar_pack_end(zval *handle, zval *child);
/*@zep Gtk\GtkHeaderBar packStart(int handle, int child) -> void */
void phpgtk_gtkheaderbar_pack_start(zval *handle, zval *child);
/*@zep Gtk\GtkHeaderBar remove(int handle, int child) -> void */
void phpgtk_gtkheaderbar_remove(zval *handle, zval *child);
/*@zep Gtk\GtkHeaderBar setDecorationLayout(int handle, var layout) -> void */
void phpgtk_gtkheaderbar_set_decoration_layout(zval *handle, zval *layout);
/*@zep Gtk\GtkHeaderBar setShowTitleButtons(int handle, bool setting) -> void */
void phpgtk_gtkheaderbar_set_show_title_buttons(zval *handle, zval *setting);
/*@zep Gtk\GtkHeaderBar setTitleWidget(int handle, int titleWidget) -> void */
void phpgtk_gtkheaderbar_set_title_widget(zval *handle, zval *titleWidget);
/*@zep Gtk\GtkHeaderBar setUseNativeControls(int handle, bool setting) -> void */
void phpgtk_gtkheaderbar_set_use_native_controls(zval *handle, zval *setting);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_HEADER_BAR_H */
