
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
#include "src/gdk-gl-context.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gdk_GdkGLContext_GdkGLContext)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gdk\\GdkGLContext, GdkGLContext, gtk, gdk_gdkglcontext_gdkglcontext, gtk_gdk_gdkglcontext_gdkglcontext_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, getAllowedApis)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gdkglcontext_get_allowed_apis(&_0));
}

PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, getApi)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gdkglcontext_get_api(&_0));
}

PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, getDebugEnabled)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gdkglcontext_get_debug_enabled(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, getDisplay)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gdkglcontext_get_display(&_0));
}

PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, getForwardCompatible)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gdkglcontext_get_forward_compatible(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, getRequiredVersion)
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
	phpgtk_gdkglcontext_get_required_version(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, getSurface)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gdkglcontext_get_surface(&_0));
}

PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, getUseEs)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gdkglcontext_get_use_es(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, getVersion)
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
	phpgtk_gdkglcontext_get_version(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, isLegacy)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gdkglcontext_is_legacy(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, isShared)
{
	zval *handle_param = NULL, *other_param = NULL, _0, _1;
	zend_long handle, other, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(other)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &other_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, other);
	r = phpgtk_gdkglcontext_is_shared(&_0, &_1);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, makeCurrent)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gdkglcontext_make_current(&_0);
}

PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, setAllowedApis)
{
	zval *handle_param = NULL, *apis_param = NULL, _0, _1;
	zend_long handle, apis;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(apis)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &apis_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, apis);
	phpgtk_gdkglcontext_set_allowed_apis(&_0, &_1);
}

PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, setDebugEnabled)
{
	zend_bool enabled;
	zval *handle_param = NULL, *enabled_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(enabled)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &enabled_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (enabled ? 1 : 0));
	phpgtk_gdkglcontext_set_debug_enabled(&_0, &_1);
}

PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, setForwardCompatible)
{
	zend_bool compatible;
	zval *handle_param = NULL, *compatible_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(compatible)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &compatible_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (compatible ? 1 : 0));
	phpgtk_gdkglcontext_set_forward_compatible(&_0, &_1);
}

PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, setRequiredVersion)
{
	zval *handle_param = NULL, *major_param = NULL, *minor_param = NULL, _0, _1, _2;
	zend_long handle, major, minor;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(major)
		Z_PARAM_LONG(minor)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &major_param, &minor_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, major);
	ZVAL_LONG(&_2, minor);
	phpgtk_gdkglcontext_set_required_version(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, setUseEs)
{
	zval *handle_param = NULL, *useEs_param = NULL, _0, _1;
	zend_long handle, useEs;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(useEs)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &useEs_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, useEs);
	phpgtk_gdkglcontext_set_use_es(&_0, &_1);
}

PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, clearCurrent)
{

	phpgtk_gdkglcontext_clear_current();
}

PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, getCurrent)
{

	RETURN_LONG(phpgtk_gdkglcontext_get_current());
}

