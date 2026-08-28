
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
#include "src/gtk-picture.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkPicture_GtkPicture)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkPicture, GtkPicture, gtk_gtk, gtkpicture_gtkpicture, gtk_gtk_gtkpicture_gtkpicture_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, new_)
{

	RETURN_LONG(phpgtk_gtkpicture_new());
}

PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, newForFile)
{
	zval *file_param = NULL, _0;
	zend_long file;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(file)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &file_param);
	ZVAL_LONG(&_0, file);
	RETURN_LONG(phpgtk_gtkpicture_new_for_file(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, newForFilename)
{
	zval *filename = NULL, filename_sub;

	ZVAL_UNDEF(&filename_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(filename)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &filename);
	RETURN_LONG(phpgtk_gtkpicture_new_for_filename(filename));
}

PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, newForPaintable)
{
	zval *paintable_param = NULL, _0;
	zend_long paintable;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(paintable)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &paintable_param);
	ZVAL_LONG(&_0, paintable);
	RETURN_LONG(phpgtk_gtkpicture_new_for_paintable(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, newForResource)
{
	zval *resourcePath = NULL, resourcePath_sub;

	ZVAL_UNDEF(&resourcePath_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(resourcePath)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &resourcePath);
	RETURN_LONG(phpgtk_gtkpicture_new_for_resource(resourcePath));
}

PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, getAlternativeText)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *handle_param = NULL, result, _0;
	zend_long handle;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &handle_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkpicture_get_alternative_text(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, getCanShrink)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkpicture_get_can_shrink(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, getContentFit)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkpicture_get_content_fit(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, getFile)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkpicture_get_file(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, getPaintable)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkpicture_get_paintable(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, setAlternativeText)
{
	zval *handle_param = NULL, *alternativeText = NULL, alternativeText_sub, _0;
	zend_long handle;

	ZVAL_UNDEF(&alternativeText_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(alternativeText)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &alternativeText);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkpicture_set_alternative_text(&_0, alternativeText);
}

PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, setCanShrink)
{
	zend_bool canShrink;
	zval *handle_param = NULL, *canShrink_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(canShrink)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &canShrink_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (canShrink ? 1 : 0));
	phpgtk_gtkpicture_set_can_shrink(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, setContentFit)
{
	zval *handle_param = NULL, *contentFit_param = NULL, _0, _1;
	zend_long handle, contentFit;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(contentFit)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &contentFit_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, contentFit);
	phpgtk_gtkpicture_set_content_fit(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, setFile)
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
	phpgtk_gtkpicture_set_file(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, setFilename)
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
	phpgtk_gtkpicture_set_filename(&_0, filename);
}

PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, setPaintable)
{
	zval *handle_param = NULL, *paintable_param = NULL, _0, _1;
	zend_long handle, paintable;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(paintable)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &paintable_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, paintable);
	phpgtk_gtkpicture_set_paintable(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, setResource)
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
	phpgtk_gtkpicture_set_resource(&_0, resourcePath);
}

