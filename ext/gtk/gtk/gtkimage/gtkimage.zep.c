
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
#include "src/gtk-image.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkImage_GtkImage)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkImage, GtkImage, gtk_gtk, gtkimage_gtkimage, gtk_gtk_gtkimage_gtkimage_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, new_)
{

	RETURN_LONG(phpgtk_gtkimage_new());
}

PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, newFromFile)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *filename_param = NULL;
	zval filename;

	ZVAL_UNDEF(&filename);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &filename_param);
	zephir_get_strval(&filename, filename_param);
	RETURN_MM_LONG(phpgtk_gtkimage_new_from_file(&filename));
}

PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, newFromGicon)
{
	zval *icon_param = NULL, _0;
	zend_long icon;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(icon)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &icon_param);
	ZVAL_LONG(&_0, icon);
	RETURN_LONG(phpgtk_gtkimage_new_from_gicon(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, newFromIconName)
{
	zval *iconName = NULL, iconName_sub;

	ZVAL_UNDEF(&iconName_sub);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(iconName)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &iconName);
	RETURN_LONG(phpgtk_gtkimage_new_from_icon_name(iconName));
}

PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, newFromPaintable)
{
	zval *paintable_param = NULL, _0;
	zend_long paintable;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(paintable)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &paintable_param);
	ZVAL_LONG(&_0, paintable);
	RETURN_LONG(phpgtk_gtkimage_new_from_paintable(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, newFromResource)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *resourcePath_param = NULL;
	zval resourcePath;

	ZVAL_UNDEF(&resourcePath);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(resourcePath)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &resourcePath_param);
	zephir_get_strval(&resourcePath, resourcePath_param);
	RETURN_MM_LONG(phpgtk_gtkimage_new_from_resource(&resourcePath));
}

PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, clear)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkimage_clear(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, getGicon)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkimage_get_gicon(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, getIconName)
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
	phpgtk_gtkimage_get_icon_name(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, getIconSize)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkimage_get_icon_size(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, getPaintable)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkimage_get_paintable(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, getPixelSize)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkimage_get_pixel_size(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, getStorageType)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkimage_get_storage_type(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, setFromFile)
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
	phpgtk_gtkimage_set_from_file(&_0, filename);
}

PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, setFromGicon)
{
	zval *handle_param = NULL, *icon_param = NULL, _0, _1;
	zend_long handle, icon;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(icon)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &icon_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, icon);
	phpgtk_gtkimage_set_from_gicon(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, setFromIconName)
{
	zval *handle_param = NULL, *iconName = NULL, iconName_sub, _0;
	zend_long handle;

	ZVAL_UNDEF(&iconName_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(iconName)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &iconName);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkimage_set_from_icon_name(&_0, iconName);
}

PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, setFromPaintable)
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
	phpgtk_gtkimage_set_from_paintable(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, setFromResource)
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
	phpgtk_gtkimage_set_from_resource(&_0, resourcePath);
}

PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, setIconSize)
{
	zval *handle_param = NULL, *iconSize_param = NULL, _0, _1;
	zend_long handle, iconSize;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(iconSize)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &iconSize_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, iconSize);
	phpgtk_gtkimage_set_icon_size(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, setPixelSize)
{
	zval *handle_param = NULL, *pixelSize_param = NULL, _0, _1;
	zend_long handle, pixelSize;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(pixelSize)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &pixelSize_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, pixelSize);
	phpgtk_gtkimage_set_pixel_size(&_0, &_1);
}

