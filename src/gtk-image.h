#ifndef PHP_GTK_GTK_IMAGE_H
#define PHP_GTK_GTK_IMAGE_H

/*
 * GtkImage — Wave A5. Every gir constructor/method/function is bound
 * or reserved. Deprecated pixbuf members stay reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@reserved Gtk\GtkImage property "file" — no C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkImage property "resource" — no C accessor; use Bridge::getProperty/setProperty */
/*@reserved Gtk\GtkImage property "use-fallback" — no C accessor; use Bridge::getProperty/setProperty */

/*@zep Gtk\GtkImage new() -> int */
zend_long phpgtk_gtkimage_new(void);
/*@zep Gtk\GtkImage newFromFile(string filename) -> int */
zend_long phpgtk_gtkimage_new_from_file(zval *filename);
/*@zep Gtk\GtkImage newFromGicon(int icon) -> int */
zend_long phpgtk_gtkimage_new_from_gicon(zval *icon);
/*@zep Gtk\GtkImage newFromIconName(var iconName) -> int */
zend_long phpgtk_gtkimage_new_from_icon_name(zval *iconName);
/*@zep Gtk\GtkImage newFromPaintable(int paintable) -> int */
zend_long phpgtk_gtkimage_new_from_paintable(zval *paintable);
/*@reserved Gtk\GtkImage gtk_image_new_from_pixbuf(GdkPixbuf* pixbuf) — deprecated */
/*@zep Gtk\GtkImage newFromResource(string resourcePath) -> int */
zend_long phpgtk_gtkimage_new_from_resource(zval *resourcePath);
/*@zep Gtk\GtkImage clear(int handle) -> void */
void phpgtk_gtkimage_clear(zval *handle);
/*@zep Gtk\GtkImage getGicon(int handle) -> int */
zend_long phpgtk_gtkimage_get_gicon(zval *handle);
/*@zep Gtk\GtkImage getIconName(int handle) -> var */
void phpgtk_gtkimage_get_icon_name(zval *return_value, zval *handle);
/*@zep Gtk\GtkImage getIconSize(int handle) -> int */
zend_long phpgtk_gtkimage_get_icon_size(zval *handle);
/*@zep Gtk\GtkImage getPaintable(int handle) -> int */
zend_long phpgtk_gtkimage_get_paintable(zval *handle);
/*@zep Gtk\GtkImage getPixelSize(int handle) -> int */
zend_long phpgtk_gtkimage_get_pixel_size(zval *handle);
/*@zep Gtk\GtkImage getStorageType(int handle) -> int */
zend_long phpgtk_gtkimage_get_storage_type(zval *handle);
/*@zep Gtk\GtkImage setFromFile(int handle, var filename) -> void */
void phpgtk_gtkimage_set_from_file(zval *handle, zval *filename);
/*@zep Gtk\GtkImage setFromGicon(int handle, int icon) -> void */
void phpgtk_gtkimage_set_from_gicon(zval *handle, zval *icon);
/*@zep Gtk\GtkImage setFromIconName(int handle, var iconName) -> void */
void phpgtk_gtkimage_set_from_icon_name(zval *handle, zval *iconName);
/*@zep Gtk\GtkImage setFromPaintable(int handle, int paintable) -> void */
void phpgtk_gtkimage_set_from_paintable(zval *handle, zval *paintable);
/*@reserved Gtk\GtkImage gtk_image_set_from_pixbuf(GtkImage* image, GdkPixbuf* pixbuf) — deprecated */
/*@zep Gtk\GtkImage setFromResource(int handle, var resourcePath) -> void */
void phpgtk_gtkimage_set_from_resource(zval *handle, zval *resourcePath);
/*@zep Gtk\GtkImage setIconSize(int handle, int iconSize) -> void */
void phpgtk_gtkimage_set_icon_size(zval *handle, zval *iconSize);
/*@zep Gtk\GtkImage setPixelSize(int handle, int pixelSize) -> void */
void phpgtk_gtkimage_set_pixel_size(zval *handle, zval *pixelSize);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_IMAGE_H */
