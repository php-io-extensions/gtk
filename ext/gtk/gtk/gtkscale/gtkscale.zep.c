
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
#include "src/gtk-scale.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkScale_GtkScale)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkScale, GtkScale, gtk_gtk, gtkscale_gtkscale, gtk_gtk_gtkscale_gtkscale_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkScale_GtkScale, new_)
{
	zval *orientation_param = NULL, *adjustment_param = NULL, _0, _1;
	zend_long orientation, adjustment;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(orientation)
		Z_PARAM_LONG(adjustment)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &orientation_param, &adjustment_param);
	ZVAL_LONG(&_0, orientation);
	ZVAL_LONG(&_1, adjustment);
	RETURN_LONG(phpgtk_gtkscale_new(&_0, &_1));
}

PHP_METHOD(Gtk_Gtk_GtkScale_GtkScale, newWithRange)
{
	double min, max, step;
	zval *orientation_param = NULL, *min_param = NULL, *max_param = NULL, *step_param = NULL, _0, _1, _2, _3;
	zend_long orientation;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(orientation)
		Z_PARAM_ZVAL(min)
		Z_PARAM_ZVAL(max)
		Z_PARAM_ZVAL(step)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &orientation_param, &min_param, &max_param, &step_param);
	min = zephir_get_doubleval(min_param);
	max = zephir_get_doubleval(max_param);
	step = zephir_get_doubleval(step_param);
	ZVAL_LONG(&_0, orientation);
	ZVAL_DOUBLE(&_1, min);
	ZVAL_DOUBLE(&_2, max);
	ZVAL_DOUBLE(&_3, step);
	RETURN_LONG(phpgtk_gtkscale_new_with_range(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Gtk_Gtk_GtkScale_GtkScale, addMark)
{
	double value;
	zval *handle_param = NULL, *value_param = NULL, *position_param = NULL, *markup = NULL, markup_sub, _0, _1, _2;
	zend_long handle, position;

	ZVAL_UNDEF(&markup_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(value)
		Z_PARAM_LONG(position)
		Z_PARAM_ZVAL(markup)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &handle_param, &value_param, &position_param, &markup);
	value = zephir_get_doubleval(value_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_DOUBLE(&_1, value);
	ZVAL_LONG(&_2, position);
	phpgtk_gtkscale_add_mark(&_0, &_1, &_2, markup);
}

PHP_METHOD(Gtk_Gtk_GtkScale_GtkScale, clearMarks)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkscale_clear_marks(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkScale_GtkScale, getDigits)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkscale_get_digits(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkScale_GtkScale, getDrawValue)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkscale_get_draw_value(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkScale_GtkScale, getHasOrigin)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkscale_get_has_origin(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkScale_GtkScale, getLayout)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkscale_get_layout(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkScale_GtkScale, getLayoutOffsets)
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
	phpgtk_gtkscale_get_layout_offsets(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkScale_GtkScale, getValuePos)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkscale_get_value_pos(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkScale_GtkScale, setDigits)
{
	zval *handle_param = NULL, *digits_param = NULL, _0, _1;
	zend_long handle, digits;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(digits)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &digits_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, digits);
	phpgtk_gtkscale_set_digits(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkScale_GtkScale, setDrawValue)
{
	zend_bool drawValue;
	zval *handle_param = NULL, *drawValue_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(drawValue)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &drawValue_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (drawValue ? 1 : 0));
	phpgtk_gtkscale_set_draw_value(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkScale_GtkScale, setHasOrigin)
{
	zend_bool hasOrigin;
	zval *handle_param = NULL, *hasOrigin_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(hasOrigin)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &hasOrigin_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (hasOrigin ? 1 : 0));
	phpgtk_gtkscale_set_has_origin(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkScale_GtkScale, setValuePos)
{
	zval *handle_param = NULL, *pos_param = NULL, _0, _1;
	zend_long handle, pos;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(pos)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &pos_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, pos);
	phpgtk_gtkscale_set_value_pos(&_0, &_1);
}

