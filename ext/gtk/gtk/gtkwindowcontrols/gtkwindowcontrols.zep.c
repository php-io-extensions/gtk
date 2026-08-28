
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
#include "src/gtk-window-controls.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkWindowControls_GtkWindowControls)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkWindowControls, GtkWindowControls, gtk_gtk, gtkwindowcontrols_gtkwindowcontrols, gtk_gtk_gtkwindowcontrols_gtkwindowcontrols_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkWindowControls_GtkWindowControls, new_)
{
	zval *side_param = NULL, _0;
	zend_long side;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(side)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &side_param);
	ZVAL_LONG(&_0, side);
	RETURN_LONG(phpgtk_gtkwindowcontrols_new(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWindowControls_GtkWindowControls, getDecorationLayout)
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
	phpgtk_gtkwindowcontrols_get_decoration_layout(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkWindowControls_GtkWindowControls, getEmpty)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwindowcontrols_get_empty(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWindowControls_GtkWindowControls, getSide)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwindowcontrols_get_side(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWindowControls_GtkWindowControls, getUseNativeControls)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwindowcontrols_get_use_native_controls(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWindowControls_GtkWindowControls, setDecorationLayout)
{
	zval *handle_param = NULL, *layout = NULL, layout_sub, _0;
	zend_long handle;

	ZVAL_UNDEF(&layout_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(layout)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &layout);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkwindowcontrols_set_decoration_layout(&_0, layout);
}

PHP_METHOD(Gtk_Gtk_GtkWindowControls_GtkWindowControls, setSide)
{
	zval *handle_param = NULL, *side_param = NULL, _0, _1;
	zend_long handle, side;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(side)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &side_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, side);
	phpgtk_gtkwindowcontrols_set_side(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWindowControls_GtkWindowControls, setUseNativeControls)
{
	zend_bool setting;
	zval *handle_param = NULL, *setting_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(setting)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &setting_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (setting ? 1 : 0));
	phpgtk_gtkwindowcontrols_set_use_native_controls(&_0, &_1);
}

