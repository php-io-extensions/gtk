#ifndef PHP_GTK_GTK_MEDIA_FILE_H
#define PHP_GTK_GTK_MEDIA_FILE_H

/*
 * GtkMediaFile — video wave. Every gir constructor/method/function is
 * bound or reserved. The open/close virtuals are for implementations and
 * are not gir methods. Playback goes through the inherited GtkMediaStream
 * surface; this class only owns what is being played.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkMediaFile new() -> int */
zend_long phpgtk_gtkmediafile_new(void);
/*@zep Gtk\GtkMediaFile newForFile(int file) -> int */
zend_long phpgtk_gtkmediafile_new_for_file(zval *file);
/*@zep Gtk\GtkMediaFile newForFilename(var filename) -> int */
zend_long phpgtk_gtkmediafile_new_for_filename(zval *filename);
/*@zep Gtk\GtkMediaFile newForInputStream(int stream) -> int */
zend_long phpgtk_gtkmediafile_new_for_input_stream(zval *stream);
/*@zep Gtk\GtkMediaFile newForResource(var resourcePath) -> int */
zend_long phpgtk_gtkmediafile_new_for_resource(zval *resourcePath);
/*@zep Gtk\GtkMediaFile clear(int handle) -> void */
void phpgtk_gtkmediafile_clear(zval *handle);
/*@zep Gtk\GtkMediaFile getFile(int handle) -> int */
zend_long phpgtk_gtkmediafile_get_file(zval *handle);
/*@zep Gtk\GtkMediaFile getInputStream(int handle) -> int */
zend_long phpgtk_gtkmediafile_get_input_stream(zval *handle);
/*@zep Gtk\GtkMediaFile setFile(int handle, int file) -> void */
void phpgtk_gtkmediafile_set_file(zval *handle, zval *file);
/*@zep Gtk\GtkMediaFile setFilename(int handle, var filename) -> void */
void phpgtk_gtkmediafile_set_filename(zval *handle, zval *filename);
/*@zep Gtk\GtkMediaFile setInputStream(int handle, int stream) -> void */
void phpgtk_gtkmediafile_set_input_stream(zval *handle, zval *stream);
/*@zep Gtk\GtkMediaFile setResource(int handle, var resourcePath) -> void */
void phpgtk_gtkmediafile_set_resource(zval *handle, zval *resourcePath);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_MEDIA_FILE_H */
