
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
#include "src/gtk-level-bar.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkLevelBar_GtkLevelBar)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkLevelBar, GtkLevelBar, gtk_gtk, gtklevelbar_gtklevelbar, gtk_gtk_gtklevelbar_gtklevelbar_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkLevelBar_GtkLevelBar, new_)
{

	RETURN_LONG(phpgtk_gtklevelbar_new());
}

PHP_METHOD(Gtk_Gtk_GtkLevelBar_GtkLevelBar, newForInterval)
{
	zval *minValue_param = NULL, *maxValue_param = NULL, _0, _1;
	double minValue, maxValue;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(minValue)
		Z_PARAM_ZVAL(maxValue)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &minValue_param, &maxValue_param);
	minValue = zephir_get_doubleval(minValue_param);
	maxValue = zephir_get_doubleval(maxValue_param);
	ZVAL_DOUBLE(&_0, minValue);
	ZVAL_DOUBLE(&_1, maxValue);
	RETURN_LONG(phpgtk_gtklevelbar_new_for_interval(&_0, &_1));
}

PHP_METHOD(Gtk_Gtk_GtkLevelBar_GtkLevelBar, addOffsetValue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	double value;
	zval name;
	zval *handle_param = NULL, *name_param = NULL, *value_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&name);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(name)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &handle_param, &name_param, &value_param);
	zephir_get_strval(&name, name_param);
	value = zephir_get_doubleval(value_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_DOUBLE(&_1, value);
	phpgtk_gtklevelbar_add_offset_value(&_0, &name, &_1);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_Gtk_GtkLevelBar_GtkLevelBar, getInverted)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtklevelbar_get_inverted(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkLevelBar_GtkLevelBar, getMaxValue)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_DOUBLE(phpgtk_gtklevelbar_get_max_value(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkLevelBar_GtkLevelBar, getMinValue)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_DOUBLE(phpgtk_gtklevelbar_get_min_value(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkLevelBar_GtkLevelBar, getMode)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtklevelbar_get_mode(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkLevelBar_GtkLevelBar, getOffsetValue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *handle_param = NULL, *name = NULL, name_sub, result, _0;
	zend_long handle;

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &name);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtklevelbar_get_offset_value(&result, &_0, name);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkLevelBar_GtkLevelBar, getValue)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_DOUBLE(phpgtk_gtklevelbar_get_value(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkLevelBar_GtkLevelBar, removeOffsetValue)
{
	zval *handle_param = NULL, *name = NULL, name_sub, _0;
	zend_long handle;

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &name);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtklevelbar_remove_offset_value(&_0, name);
}

PHP_METHOD(Gtk_Gtk_GtkLevelBar_GtkLevelBar, setInverted)
{
	zend_bool inverted;
	zval *handle_param = NULL, *inverted_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(inverted)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &inverted_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (inverted ? 1 : 0));
	phpgtk_gtklevelbar_set_inverted(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkLevelBar_GtkLevelBar, setMaxValue)
{
	double value;
	zval *handle_param = NULL, *value_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &value_param);
	value = zephir_get_doubleval(value_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_DOUBLE(&_1, value);
	phpgtk_gtklevelbar_set_max_value(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkLevelBar_GtkLevelBar, setMinValue)
{
	double value;
	zval *handle_param = NULL, *value_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &value_param);
	value = zephir_get_doubleval(value_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_DOUBLE(&_1, value);
	phpgtk_gtklevelbar_set_min_value(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkLevelBar_GtkLevelBar, setMode)
{
	zval *handle_param = NULL, *mode_param = NULL, _0, _1;
	zend_long handle, mode;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(mode)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &mode_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, mode);
	phpgtk_gtklevelbar_set_mode(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkLevelBar_GtkLevelBar, setValue)
{
	double value;
	zval *handle_param = NULL, *value_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &value_param);
	value = zephir_get_doubleval(value_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_DOUBLE(&_1, value);
	phpgtk_gtklevelbar_set_value(&_0, &_1);
}

