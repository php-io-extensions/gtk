
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "src/gtk-media-stream.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkMediaStream_GtkMediaStream)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkMediaStream, GtkMediaStream, gtk_gtk, gtkmediastream_gtkmediastream, gtk_gtk_gtkmediastream_gtkmediastream_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, getDuration)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkmediastream_get_duration(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, getEnded)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkmediastream_get_ended(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, getLoop)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkmediastream_get_loop(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, getMuted)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkmediastream_get_muted(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, getPlaying)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkmediastream_get_playing(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, getTimestamp)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkmediastream_get_timestamp(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, getVolume)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_DOUBLE(phpgtk_gtkmediastream_get_volume(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, hasAudio)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkmediastream_has_audio(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, hasVideo)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkmediastream_has_video(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, isPrepared)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkmediastream_is_prepared(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, isSeekable)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkmediastream_is_seekable(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, isSeeking)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkmediastream_is_seeking(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, pause)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkmediastream_pause(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, play)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkmediastream_play(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, realize)
{
	zval *handle_param = NULL, *surface_param = NULL, _0, _1;
	zend_long handle, surface;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(surface)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &surface_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, surface);
	phpgtk_gtkmediastream_realize(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, seek)
{
	zval *handle_param = NULL, *timestamp_param = NULL, _0, _1;
	zend_long handle, timestamp;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(timestamp)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &timestamp_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, timestamp);
	phpgtk_gtkmediastream_seek(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, seekFailed)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkmediastream_seek_failed(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, seekSuccess)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkmediastream_seek_success(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, setLoop)
{
	zend_bool loop_;
	zval *handle_param = NULL, *loop__param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(loop_)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &loop__param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (loop_ ? 1 : 0));
	phpgtk_gtkmediastream_set_loop(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, setMuted)
{
	zend_bool muted;
	zval *handle_param = NULL, *muted_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(muted)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &muted_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (muted ? 1 : 0));
	phpgtk_gtkmediastream_set_muted(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, setPlaying)
{
	zend_bool playing;
	zval *handle_param = NULL, *playing_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(playing)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &playing_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (playing ? 1 : 0));
	phpgtk_gtkmediastream_set_playing(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, setVolume)
{
	double volume;
	zval *handle_param = NULL, *volume_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(volume)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &volume_param);
	volume = zephir_get_doubleval(volume_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_DOUBLE(&_1, volume);
	phpgtk_gtkmediastream_set_volume(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, streamEnded)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkmediastream_stream_ended(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, streamPrepared)
{
	zend_bool hasAudio, hasVideo, seekable;
	zval *handle_param = NULL, *hasAudio_param = NULL, *hasVideo_param = NULL, *seekable_param = NULL, *duration_param = NULL, _0, _1, _2, _3, _4;
	zend_long handle, duration;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(hasAudio)
		Z_PARAM_BOOL(hasVideo)
		Z_PARAM_BOOL(seekable)
		Z_PARAM_LONG(duration)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &handle_param, &hasAudio_param, &hasVideo_param, &seekable_param, &duration_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (hasAudio ? 1 : 0));
	ZVAL_BOOL(&_2, (hasVideo ? 1 : 0));
	ZVAL_BOOL(&_3, (seekable ? 1 : 0));
	ZVAL_LONG(&_4, duration);
	phpgtk_gtkmediastream_stream_prepared(&_0, &_1, &_2, &_3, &_4);
}

PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, streamUnprepared)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkmediastream_stream_unprepared(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, unrealize)
{
	zval *handle_param = NULL, *surface_param = NULL, _0, _1;
	zend_long handle, surface;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(surface)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &surface_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, surface);
	phpgtk_gtkmediastream_unrealize(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, update)
{
	zval *handle_param = NULL, *timestamp_param = NULL, _0, _1;
	zend_long handle, timestamp;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(timestamp)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &timestamp_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, timestamp);
	phpgtk_gtkmediastream_update(&_0, &_1);
}

