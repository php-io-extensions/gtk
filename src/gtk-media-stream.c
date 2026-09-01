#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-media-stream.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkmediastream_get_duration(zval *handle)
{
    GtkMediaStream *self = PHPGTK_ARG_AS(GtkMediaStream, GTK_TYPE_MEDIA_STREAM, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_media_stream_get_duration(self);
}

zend_long phpgtk_gtkmediastream_get_ended(zval *handle)
{
    GtkMediaStream *self = PHPGTK_ARG_AS(GtkMediaStream, GTK_TYPE_MEDIA_STREAM, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_media_stream_get_ended(self) ? 1 : 0;
}

zend_long phpgtk_gtkmediastream_get_loop(zval *handle)
{
    GtkMediaStream *self = PHPGTK_ARG_AS(GtkMediaStream, GTK_TYPE_MEDIA_STREAM, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_media_stream_get_loop(self) ? 1 : 0;
}

zend_long phpgtk_gtkmediastream_get_muted(zval *handle)
{
    GtkMediaStream *self = PHPGTK_ARG_AS(GtkMediaStream, GTK_TYPE_MEDIA_STREAM, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_media_stream_get_muted(self) ? 1 : 0;
}

zend_long phpgtk_gtkmediastream_get_playing(zval *handle)
{
    GtkMediaStream *self = PHPGTK_ARG_AS(GtkMediaStream, GTK_TYPE_MEDIA_STREAM, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_media_stream_get_playing(self) ? 1 : 0;
}

zend_long phpgtk_gtkmediastream_get_timestamp(zval *handle)
{
    GtkMediaStream *self = PHPGTK_ARG_AS(GtkMediaStream, GTK_TYPE_MEDIA_STREAM, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_media_stream_get_timestamp(self);
}

double phpgtk_gtkmediastream_get_volume(zval *handle)
{
    GtkMediaStream *self = PHPGTK_ARG_AS(GtkMediaStream, GTK_TYPE_MEDIA_STREAM, handle);

    if (self == NULL) {
        return 0.0;
    }

    return gtk_media_stream_get_volume(self);
}

zend_long phpgtk_gtkmediastream_has_audio(zval *handle)
{
    GtkMediaStream *self = PHPGTK_ARG_AS(GtkMediaStream, GTK_TYPE_MEDIA_STREAM, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_media_stream_has_audio(self) ? 1 : 0;
}

zend_long phpgtk_gtkmediastream_has_video(zval *handle)
{
    GtkMediaStream *self = PHPGTK_ARG_AS(GtkMediaStream, GTK_TYPE_MEDIA_STREAM, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_media_stream_has_video(self) ? 1 : 0;
}

zend_long phpgtk_gtkmediastream_is_prepared(zval *handle)
{
    GtkMediaStream *self = PHPGTK_ARG_AS(GtkMediaStream, GTK_TYPE_MEDIA_STREAM, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_media_stream_is_prepared(self) ? 1 : 0;
}

zend_long phpgtk_gtkmediastream_is_seekable(zval *handle)
{
    GtkMediaStream *self = PHPGTK_ARG_AS(GtkMediaStream, GTK_TYPE_MEDIA_STREAM, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_media_stream_is_seekable(self) ? 1 : 0;
}

zend_long phpgtk_gtkmediastream_is_seeking(zval *handle)
{
    GtkMediaStream *self = PHPGTK_ARG_AS(GtkMediaStream, GTK_TYPE_MEDIA_STREAM, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_media_stream_is_seeking(self) ? 1 : 0;
}

void phpgtk_gtkmediastream_pause(zval *handle)
{
    GtkMediaStream *self = PHPGTK_ARG_AS(GtkMediaStream, GTK_TYPE_MEDIA_STREAM, handle);

    if (self == NULL) {
        return;
    }

    gtk_media_stream_pause(self);
}

void phpgtk_gtkmediastream_play(zval *handle)
{
    GtkMediaStream *self = PHPGTK_ARG_AS(GtkMediaStream, GTK_TYPE_MEDIA_STREAM, handle);

    if (self == NULL) {
        return;
    }

    gtk_media_stream_play(self);
}

void phpgtk_gtkmediastream_realize(zval *handle, zval *surface)
{
    GtkMediaStream *self = PHPGTK_ARG_AS(GtkMediaStream, GTK_TYPE_MEDIA_STREAM, handle);

    if (self == NULL) {
        return;
    }

    gtk_media_stream_realize(self, phpgtk_arg_object(surface));
}

void phpgtk_gtkmediastream_seek(zval *handle, zval *timestamp)
{
    GtkMediaStream *self = PHPGTK_ARG_AS(GtkMediaStream, GTK_TYPE_MEDIA_STREAM, handle);

    if (self == NULL) {
        return;
    }

    gtk_media_stream_seek(self, (gint64) phpgtk_arg_long(timestamp));
}

void phpgtk_gtkmediastream_seek_failed(zval *handle)
{
    GtkMediaStream *self = PHPGTK_ARG_AS(GtkMediaStream, GTK_TYPE_MEDIA_STREAM, handle);

    if (self == NULL) {
        return;
    }

    gtk_media_stream_seek_failed(self);
}

void phpgtk_gtkmediastream_seek_success(zval *handle)
{
    GtkMediaStream *self = PHPGTK_ARG_AS(GtkMediaStream, GTK_TYPE_MEDIA_STREAM, handle);

    if (self == NULL) {
        return;
    }

    gtk_media_stream_seek_success(self);
}

void phpgtk_gtkmediastream_set_loop(zval *handle, zval *loop)
{
    GtkMediaStream *self = PHPGTK_ARG_AS(GtkMediaStream, GTK_TYPE_MEDIA_STREAM, handle);

    if (self == NULL) {
        return;
    }

    gtk_media_stream_set_loop(self, phpgtk_arg_bool(loop));
}

void phpgtk_gtkmediastream_set_muted(zval *handle, zval *muted)
{
    GtkMediaStream *self = PHPGTK_ARG_AS(GtkMediaStream, GTK_TYPE_MEDIA_STREAM, handle);

    if (self == NULL) {
        return;
    }

    gtk_media_stream_set_muted(self, phpgtk_arg_bool(muted));
}

void phpgtk_gtkmediastream_set_playing(zval *handle, zval *playing)
{
    GtkMediaStream *self = PHPGTK_ARG_AS(GtkMediaStream, GTK_TYPE_MEDIA_STREAM, handle);

    if (self == NULL) {
        return;
    }

    gtk_media_stream_set_playing(self, phpgtk_arg_bool(playing));
}

void phpgtk_gtkmediastream_set_volume(zval *handle, zval *volume)
{
    GtkMediaStream *self = PHPGTK_ARG_AS(GtkMediaStream, GTK_TYPE_MEDIA_STREAM, handle);

    if (self == NULL) {
        return;
    }

    gtk_media_stream_set_volume(self, phpgtk_arg_double(volume));
}

void phpgtk_gtkmediastream_stream_ended(zval *handle)
{
    GtkMediaStream *self = PHPGTK_ARG_AS(GtkMediaStream, GTK_TYPE_MEDIA_STREAM, handle);

    if (self == NULL) {
        return;
    }

    gtk_media_stream_stream_ended(self);
}

void phpgtk_gtkmediastream_stream_prepared(zval *handle, zval *hasAudio, zval *hasVideo, zval *seekable, zval *duration)
{
    GtkMediaStream *self = PHPGTK_ARG_AS(GtkMediaStream, GTK_TYPE_MEDIA_STREAM, handle);

    if (self == NULL) {
        return;
    }

    gtk_media_stream_stream_prepared(
        self,
        phpgtk_arg_bool(hasAudio),
        phpgtk_arg_bool(hasVideo),
        phpgtk_arg_bool(seekable),
        (gint64) phpgtk_arg_long(duration)
    );
}

void phpgtk_gtkmediastream_stream_unprepared(zval *handle)
{
    GtkMediaStream *self = PHPGTK_ARG_AS(GtkMediaStream, GTK_TYPE_MEDIA_STREAM, handle);

    if (self == NULL) {
        return;
    }

    gtk_media_stream_stream_unprepared(self);
}

void phpgtk_gtkmediastream_unrealize(zval *handle, zval *surface)
{
    GtkMediaStream *self = PHPGTK_ARG_AS(GtkMediaStream, GTK_TYPE_MEDIA_STREAM, handle);

    if (self == NULL) {
        return;
    }

    gtk_media_stream_unrealize(self, phpgtk_arg_object(surface));
}

void phpgtk_gtkmediastream_update(zval *handle, zval *timestamp)
{
    GtkMediaStream *self = PHPGTK_ARG_AS(GtkMediaStream, GTK_TYPE_MEDIA_STREAM, handle);

    if (self == NULL) {
        return;
    }

    gtk_media_stream_update(self, (gint64) phpgtk_arg_long(timestamp));
}
