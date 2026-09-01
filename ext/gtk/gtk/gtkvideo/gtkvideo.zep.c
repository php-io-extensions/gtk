
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
#include "src/gtk-video.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkVideo_GtkVideo)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkVideo, GtkVideo, gtk_gtk, gtkvideo_gtkvideo, gtk_gtk_gtkvideo_gtkvideo_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, new_)
{

	RETURN_LONG(phpgtk_gtkvideo_new());
}

PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, newForFile)
{
	zval *file_param = NULL, _0;
	zend_long file;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(file)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &file_param);
	ZVAL_LONG(&_0, file);
	RETURN_LONG(phpgtk_gtkvideo_new_for_file(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, newForFilename)
{
	zval *filename = NULL, filename_sub;

	ZVAL_UNDEF(&filename_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(filename)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &filename);
	RETURN_LONG(phpgtk_gtkvideo_new_for_filename(filename));
}

PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, newForMediaStream)
{
	zval *stream_param = NULL, _0;
	zend_long stream;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(stream)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &stream_param);
	ZVAL_LONG(&_0, stream);
	RETURN_LONG(phpgtk_gtkvideo_new_for_media_stream(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, newForResource)
{
	zval *resourcePath = NULL, resourcePath_sub;

	ZVAL_UNDEF(&resourcePath_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(resourcePath)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &resourcePath);
	RETURN_LONG(phpgtk_gtkvideo_new_for_resource(resourcePath));
}

PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, getAutoplay)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkvideo_get_autoplay(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, getFile)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkvideo_get_file(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, getGraphicsOffload)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkvideo_get_graphics_offload(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, getLoop)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkvideo_get_loop(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, getMediaStream)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkvideo_get_media_stream(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, setAutoplay)
{
	zend_bool autoplay;
	zval *handle_param = NULL, *autoplay_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(autoplay)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &autoplay_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (autoplay ? 1 : 0));
	phpgtk_gtkvideo_set_autoplay(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, setFile)
{
	zval *handle_param = NULL, *file_param = NULL, _0, _1;
	zend_long handle, file;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(file)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &file_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, file);
	phpgtk_gtkvideo_set_file(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, setFilename)
{
	zval *handle_param = NULL, *filename = NULL, filename_sub, _0;
	zend_long handle;

	ZVAL_UNDEF(&filename_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(filename)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &filename);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkvideo_set_filename(&_0, filename);
}

PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, setGraphicsOffload)
{
	zval *handle_param = NULL, *enabled_param = NULL, _0, _1;
	zend_long handle, enabled;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(enabled)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &enabled_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, enabled);
	phpgtk_gtkvideo_set_graphics_offload(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, setLoop)
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
	phpgtk_gtkvideo_set_loop(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, setMediaStream)
{
	zval *handle_param = NULL, *stream_param = NULL, _0, _1;
	zend_long handle, stream;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(stream)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &stream_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, stream);
	phpgtk_gtkvideo_set_media_stream(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, setResource)
{
	zval *handle_param = NULL, *resourcePath = NULL, resourcePath_sub, _0;
	zend_long handle;

	ZVAL_UNDEF(&resourcePath_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(resourcePath)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &resourcePath);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkvideo_set_resource(&_0, resourcePath);
}

