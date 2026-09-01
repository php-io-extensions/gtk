
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
#include "src/gtk-media-file.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkMediaFile_GtkMediaFile)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkMediaFile, GtkMediaFile, gtk_gtk, gtkmediafile_gtkmediafile, gtk_gtk_gtkmediafile_gtkmediafile_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkMediaFile_GtkMediaFile, new_)
{

	RETURN_LONG(phpgtk_gtkmediafile_new());
}

PHP_METHOD(Gtk_Gtk_GtkMediaFile_GtkMediaFile, newForFile)
{
	zval *file_param = NULL, _0;
	zend_long file;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(file)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &file_param);
	ZVAL_LONG(&_0, file);
	RETURN_LONG(phpgtk_gtkmediafile_new_for_file(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkMediaFile_GtkMediaFile, newForFilename)
{
	zval *filename = NULL, filename_sub;

	ZVAL_UNDEF(&filename_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(filename)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &filename);
	RETURN_LONG(phpgtk_gtkmediafile_new_for_filename(filename));
}

PHP_METHOD(Gtk_Gtk_GtkMediaFile_GtkMediaFile, newForInputStream)
{
	zval *stream_param = NULL, _0;
	zend_long stream;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(stream)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &stream_param);
	ZVAL_LONG(&_0, stream);
	RETURN_LONG(phpgtk_gtkmediafile_new_for_input_stream(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkMediaFile_GtkMediaFile, newForResource)
{
	zval *resourcePath = NULL, resourcePath_sub;

	ZVAL_UNDEF(&resourcePath_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(resourcePath)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &resourcePath);
	RETURN_LONG(phpgtk_gtkmediafile_new_for_resource(resourcePath));
}

PHP_METHOD(Gtk_Gtk_GtkMediaFile_GtkMediaFile, clear)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkmediafile_clear(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkMediaFile_GtkMediaFile, getFile)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkmediafile_get_file(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkMediaFile_GtkMediaFile, getInputStream)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkmediafile_get_input_stream(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkMediaFile_GtkMediaFile, setFile)
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
	phpgtk_gtkmediafile_set_file(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkMediaFile_GtkMediaFile, setFilename)
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
	phpgtk_gtkmediafile_set_filename(&_0, filename);
}

PHP_METHOD(Gtk_Gtk_GtkMediaFile_GtkMediaFile, setInputStream)
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
	phpgtk_gtkmediafile_set_input_stream(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkMediaFile_GtkMediaFile, setResource)
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
	phpgtk_gtkmediafile_set_resource(&_0, resourcePath);
}

