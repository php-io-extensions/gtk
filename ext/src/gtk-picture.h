#ifndef PHP_GTK_GTK_PICTURE_H
#define PHP_GTK_GTK_PICTURE_H

/*
 * GtkPicture — Wave A5. Every gir constructor/method/function is bound
 * or reserved. Deprecated pixbuf and keep-aspect-ratio members stay reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkPicture new() -> int */
zend_long phpgtk_gtkpicture_new(void);
/*@zep Gtk\GtkPicture newForFile(int file) -> int */
zend_long phpgtk_gtkpicture_new_for_file(zval *file);
/*@zep Gtk\GtkPicture newForFilename(var filename) -> int */
zend_long phpgtk_gtkpicture_new_for_filename(zval *filename);
/*@zep Gtk\GtkPicture newForPaintable(int paintable) -> int */
zend_long phpgtk_gtkpicture_new_for_paintable(zval *paintable);
/*@reserved Gtk\GtkPicture gtk_picture_new_for_pixbuf(GdkPixbuf* pixbuf) — deprecated */
/*@zep Gtk\GtkPicture newForResource(var resourcePath) -> int */
zend_long phpgtk_gtkpicture_new_for_resource(zval *resourcePath);
/*@zep Gtk\GtkPicture getAlternativeText(int handle) -> var */
void phpgtk_gtkpicture_get_alternative_text(zval *return_value, zval *handle);
/*@zep Gtk\GtkPicture getCanShrink(int handle) -> bool */
zend_long phpgtk_gtkpicture_get_can_shrink(zval *handle);
/*@zep Gtk\GtkPicture getContentFit(int handle) -> int */
zend_long phpgtk_gtkpicture_get_content_fit(zval *handle);
/*@zep Gtk\GtkPicture getFile(int handle) -> int */
zend_long phpgtk_gtkpicture_get_file(zval *handle);
/*@reserved Gtk\GtkPicture gtk_picture_get_keep_aspect_ratio(GtkPicture* self) — deprecated */
/*@zep Gtk\GtkPicture getPaintable(int handle) -> int */
zend_long phpgtk_gtkpicture_get_paintable(zval *handle);
/*@zep Gtk\GtkPicture setAlternativeText(int handle, var alternativeText) -> void */
void phpgtk_gtkpicture_set_alternative_text(zval *handle, zval *alternativeText);
/*@zep Gtk\GtkPicture setCanShrink(int handle, bool canShrink) -> void */
void phpgtk_gtkpicture_set_can_shrink(zval *handle, zval *canShrink);
/*@zep Gtk\GtkPicture setContentFit(int handle, int contentFit) -> void */
void phpgtk_gtkpicture_set_content_fit(zval *handle, zval *contentFit);
/*@zep Gtk\GtkPicture setFile(int handle, int file) -> void */
void phpgtk_gtkpicture_set_file(zval *handle, zval *file);
/*@zep Gtk\GtkPicture setFilename(int handle, var filename) -> void */
void phpgtk_gtkpicture_set_filename(zval *handle, zval *filename);
/*@reserved Gtk\GtkPicture gtk_picture_set_keep_aspect_ratio(GtkPicture* self, keep_aspect_ratio) — deprecated */
/*@zep Gtk\GtkPicture setPaintable(int handle, int paintable) -> void */
void phpgtk_gtkpicture_set_paintable(zval *handle, zval *paintable);
/*@reserved Gtk\GtkPicture gtk_picture_set_pixbuf(GtkPicture* self, GdkPixbuf* pixbuf) — deprecated */
/*@zep Gtk\GtkPicture setResource(int handle, var resourcePath) -> void */
void phpgtk_gtkpicture_set_resource(zval *handle, zval *resourcePath);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_PICTURE_H */
