#ifndef PHP_GTK_GTK_VIDEO_H
#define PHP_GTK_GTK_VIDEO_H

/*
 * GtkVideo — video wave. Every gir constructor/method/function is bound
 * or reserved. Playback needs a GTK media backend at runtime
 * (libgtk-4-media-gstreamer); without one the widget shows a broken-media
 * icon rather than failing the call.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkVideo new() -> int */
zend_long phpgtk_gtkvideo_new(void);
/*@zep Gtk\GtkVideo newForFile(int file) -> int */
zend_long phpgtk_gtkvideo_new_for_file(zval *file);
/*@zep Gtk\GtkVideo newForFilename(var filename) -> int */
zend_long phpgtk_gtkvideo_new_for_filename(zval *filename);
/*@zep Gtk\GtkVideo newForMediaStream(int stream) -> int */
zend_long phpgtk_gtkvideo_new_for_media_stream(zval *stream);
/*@zep Gtk\GtkVideo newForResource(var resourcePath) -> int */
zend_long phpgtk_gtkvideo_new_for_resource(zval *resourcePath);
/*@zep Gtk\GtkVideo getAutoplay(int handle) -> bool */
zend_long phpgtk_gtkvideo_get_autoplay(zval *handle);
/*@zep Gtk\GtkVideo getFile(int handle) -> int */
zend_long phpgtk_gtkvideo_get_file(zval *handle);
/*@zep Gtk\GtkVideo getGraphicsOffload(int handle) -> int */
zend_long phpgtk_gtkvideo_get_graphics_offload(zval *handle);
/*@zep Gtk\GtkVideo getLoop(int handle) -> bool */
zend_long phpgtk_gtkvideo_get_loop(zval *handle);
/*@zep Gtk\GtkVideo getMediaStream(int handle) -> int */
zend_long phpgtk_gtkvideo_get_media_stream(zval *handle);
/*@zep Gtk\GtkVideo setAutoplay(int handle, bool autoplay) -> void */
void phpgtk_gtkvideo_set_autoplay(zval *handle, zval *autoplay);
/*@zep Gtk\GtkVideo setFile(int handle, int file) -> void */
void phpgtk_gtkvideo_set_file(zval *handle, zval *file);
/*@zep Gtk\GtkVideo setFilename(int handle, var filename) -> void */
void phpgtk_gtkvideo_set_filename(zval *handle, zval *filename);
/*@zep Gtk\GtkVideo setGraphicsOffload(int handle, int enabled) -> void */
void phpgtk_gtkvideo_set_graphics_offload(zval *handle, zval *enabled);
/*@zep Gtk\GtkVideo setLoop(int handle, bool loop) -> void */
void phpgtk_gtkvideo_set_loop(zval *handle, zval *loop);
/*@zep Gtk\GtkVideo setMediaStream(int handle, int stream) -> void */
void phpgtk_gtkvideo_set_media_stream(zval *handle, zval *stream);
/*@zep Gtk\GtkVideo setResource(int handle, var resourcePath) -> void */
void phpgtk_gtkvideo_set_resource(zval *handle, zval *resourcePath);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_VIDEO_H */
