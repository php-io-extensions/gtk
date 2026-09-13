
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
#include "src/gtk-gl-area.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkGLArea_GtkGLArea)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkGLArea, GtkGLArea, gtk_gtk, gtkglarea_gtkglarea, gtk_gtk_gtkglarea_gtkglarea_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkGLArea_GtkGLArea, new_)
{

	RETURN_LONG(phpgtk_gtkglarea_new());
}

PHP_METHOD(Gtk_Gtk_GtkGLArea_GtkGLArea, attachBuffers)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkglarea_attach_buffers(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkGLArea_GtkGLArea, getAllowedApis)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkglarea_get_allowed_apis(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkGLArea_GtkGLArea, getApi)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkglarea_get_api(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkGLArea_GtkGLArea, getAutoRender)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkglarea_get_auto_render(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkGLArea_GtkGLArea, getContext)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkglarea_get_context(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkGLArea_GtkGLArea, getHasDepthBuffer)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkglarea_get_has_depth_buffer(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkGLArea_GtkGLArea, getHasStencilBuffer)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkglarea_get_has_stencil_buffer(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkGLArea_GtkGLArea, getRequiredVersion)
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
	phpgtk_gtkglarea_get_required_version(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkGLArea_GtkGLArea, makeCurrent)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkglarea_make_current(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkGLArea_GtkGLArea, queueRender)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkglarea_queue_render(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkGLArea_GtkGLArea, setAllowedApis)
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
	phpgtk_gtkglarea_set_allowed_apis(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkGLArea_GtkGLArea, setAutoRender)
{
	zend_bool autoRender;
	zval *handle_param = NULL, *autoRender_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(autoRender)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &autoRender_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (autoRender ? 1 : 0));
	phpgtk_gtkglarea_set_auto_render(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkGLArea_GtkGLArea, setHasDepthBuffer)
{
	zend_bool hasDepthBuffer;
	zval *handle_param = NULL, *hasDepthBuffer_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(hasDepthBuffer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &hasDepthBuffer_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (hasDepthBuffer ? 1 : 0));
	phpgtk_gtkglarea_set_has_depth_buffer(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkGLArea_GtkGLArea, setHasStencilBuffer)
{
	zend_bool hasStencilBuffer;
	zval *handle_param = NULL, *hasStencilBuffer_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(hasStencilBuffer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &hasStencilBuffer_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (hasStencilBuffer ? 1 : 0));
	phpgtk_gtkglarea_set_has_stencil_buffer(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkGLArea_GtkGLArea, setRequiredVersion)
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
	phpgtk_gtkglarea_set_required_version(&_0, &_1, &_2);
}

