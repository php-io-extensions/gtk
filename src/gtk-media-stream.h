#ifndef PHP_GTK_GTK_MEDIA_STREAM_H
#define PHP_GTK_GTK_MEDIA_STREAM_H

/*
 * GtkMediaStream — video wave. Every gir constructor/method/function is
 * bound or reserved. The class is abstract: instances are obtained from
 * GtkMediaFile constructors or GtkVideo::getMediaStream, never built.
 * The printf-style error raisers and the GError surface stay reserved;
 * the deprecated 4.4 names (ended/prepared/unprepared) stay reserved in
 * favour of their stream_* replacements.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@reserved Gtk\GtkMediaStream gtk_media_stream_ended(GtkMediaStream* self) — deprecated */
/*@reserved Gtk\GtkMediaStream gtk_media_stream_error(GtkMediaStream* self, domain, code, format, ...) — varargs */
/*@reserved Gtk\GtkMediaStream gtk_media_stream_error_valist(GtkMediaStream* self, domain, code, format, va_list args) — va_list */
/*@reserved Gtk\GtkMediaStream gtk_media_stream_gerror(GtkMediaStream* self, GError* error) — GError */
/*@zep Gtk\GtkMediaStream getDuration(int handle) -> int */
zend_long phpgtk_gtkmediastream_get_duration(zval *handle);
/*@zep Gtk\GtkMediaStream getEnded(int handle) -> bool */
zend_long phpgtk_gtkmediastream_get_ended(zval *handle);
/*@reserved Gtk\GtkMediaStream gtk_media_stream_get_error(GtkMediaStream* self) — GError* return */
/*@zep Gtk\GtkMediaStream getLoop(int handle) -> bool */
zend_long phpgtk_gtkmediastream_get_loop(zval *handle);
/*@zep Gtk\GtkMediaStream getMuted(int handle) -> bool */
zend_long phpgtk_gtkmediastream_get_muted(zval *handle);
/*@zep Gtk\GtkMediaStream getPlaying(int handle) -> bool */
zend_long phpgtk_gtkmediastream_get_playing(zval *handle);
/*@zep Gtk\GtkMediaStream getTimestamp(int handle) -> int */
zend_long phpgtk_gtkmediastream_get_timestamp(zval *handle);
/*@zep Gtk\GtkMediaStream getVolume(int handle) -> double */
double phpgtk_gtkmediastream_get_volume(zval *handle);
/*@zep Gtk\GtkMediaStream hasAudio(int handle) -> bool */
zend_long phpgtk_gtkmediastream_has_audio(zval *handle);
/*@zep Gtk\GtkMediaStream hasVideo(int handle) -> bool */
zend_long phpgtk_gtkmediastream_has_video(zval *handle);
/*@zep Gtk\GtkMediaStream isPrepared(int handle) -> bool */
zend_long phpgtk_gtkmediastream_is_prepared(zval *handle);
/*@zep Gtk\GtkMediaStream isSeekable(int handle) -> bool */
zend_long phpgtk_gtkmediastream_is_seekable(zval *handle);
/*@zep Gtk\GtkMediaStream isSeeking(int handle) -> bool */
zend_long phpgtk_gtkmediastream_is_seeking(zval *handle);
/*@zep Gtk\GtkMediaStream pause(int handle) -> void */
void phpgtk_gtkmediastream_pause(zval *handle);
/*@zep Gtk\GtkMediaStream play(int handle) -> void */
void phpgtk_gtkmediastream_play(zval *handle);
/*@reserved Gtk\GtkMediaStream gtk_media_stream_prepared(GtkMediaStream* self, has_audio, has_video, seekable, duration) — deprecated */
/*@zep Gtk\GtkMediaStream realize(int handle, int surface) -> void */
void phpgtk_gtkmediastream_realize(zval *handle, zval *surface);
/*@zep Gtk\GtkMediaStream seek(int handle, int timestamp) -> void */
void phpgtk_gtkmediastream_seek(zval *handle, zval *timestamp);
/*@zep Gtk\GtkMediaStream seekFailed(int handle) -> void */
void phpgtk_gtkmediastream_seek_failed(zval *handle);
/*@zep Gtk\GtkMediaStream seekSuccess(int handle) -> void */
void phpgtk_gtkmediastream_seek_success(zval *handle);
/*@zep Gtk\GtkMediaStream setLoop(int handle, bool loop) -> void */
void phpgtk_gtkmediastream_set_loop(zval *handle, zval *loop);
/*@zep Gtk\GtkMediaStream setMuted(int handle, bool muted) -> void */
void phpgtk_gtkmediastream_set_muted(zval *handle, zval *muted);
/*@zep Gtk\GtkMediaStream setPlaying(int handle, bool playing) -> void */
void phpgtk_gtkmediastream_set_playing(zval *handle, zval *playing);
/*@zep Gtk\GtkMediaStream setVolume(int handle, double volume) -> void */
void phpgtk_gtkmediastream_set_volume(zval *handle, zval *volume);
/*@zep Gtk\GtkMediaStream streamEnded(int handle) -> void */
void phpgtk_gtkmediastream_stream_ended(zval *handle);
/*@zep Gtk\GtkMediaStream streamPrepared(int handle, bool hasAudio, bool hasVideo, bool seekable, int duration) -> void */
void phpgtk_gtkmediastream_stream_prepared(zval *handle, zval *hasAudio, zval *hasVideo, zval *seekable, zval *duration);
/*@zep Gtk\GtkMediaStream streamUnprepared(int handle) -> void */
void phpgtk_gtkmediastream_stream_unprepared(zval *handle);
/*@reserved Gtk\GtkMediaStream gtk_media_stream_unprepared(GtkMediaStream* self) — deprecated */
/*@zep Gtk\GtkMediaStream unrealize(int handle, int surface) -> void */
void phpgtk_gtkmediastream_unrealize(zval *handle, zval *surface);
/*@zep Gtk\GtkMediaStream update(int handle, int timestamp) -> void */
void phpgtk_gtkmediastream_update(zval *handle, zval *timestamp);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_MEDIA_STREAM_H */
