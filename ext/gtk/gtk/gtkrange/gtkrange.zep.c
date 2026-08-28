
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
#include "src/gtk-range.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkRange_GtkRange)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkRange, GtkRange, gtk_gtk, gtkrange_gtkrange, gtk_gtk_gtkrange_gtkrange_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, getAdjustment)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkrange_get_adjustment(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, getFillLevel)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_DOUBLE(phpgtk_gtkrange_get_fill_level(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, getFlippable)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkrange_get_flippable(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, getInverted)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkrange_get_inverted(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, getRangeRect)
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
	phpgtk_gtkrange_get_range_rect(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, getRestrictToFillLevel)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkrange_get_restrict_to_fill_level(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, getRoundDigits)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkrange_get_round_digits(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, getShowFillLevel)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkrange_get_show_fill_level(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, getSliderRange)
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
	phpgtk_gtkrange_get_slider_range(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, getSliderSizeFixed)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkrange_get_slider_size_fixed(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, getValue)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_DOUBLE(phpgtk_gtkrange_get_value(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, setAdjustment)
{
	zval *handle_param = NULL, *adjustment_param = NULL, _0, _1;
	zend_long handle, adjustment;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(adjustment)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &adjustment_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, adjustment);
	phpgtk_gtkrange_set_adjustment(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, setFillLevel)
{
	double fillLevel;
	zval *handle_param = NULL, *fillLevel_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(fillLevel)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &fillLevel_param);
	fillLevel = zephir_get_doubleval(fillLevel_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_DOUBLE(&_1, fillLevel);
	phpgtk_gtkrange_set_fill_level(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, setFlippable)
{
	zend_bool flippable;
	zval *handle_param = NULL, *flippable_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(flippable)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &flippable_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (flippable ? 1 : 0));
	phpgtk_gtkrange_set_flippable(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, setIncrements)
{
	double step, page;
	zval *handle_param = NULL, *step_param = NULL, *page_param = NULL, _0, _1, _2;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(step)
		Z_PARAM_ZVAL(page)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &step_param, &page_param);
	step = zephir_get_doubleval(step_param);
	page = zephir_get_doubleval(page_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_DOUBLE(&_1, step);
	ZVAL_DOUBLE(&_2, page);
	phpgtk_gtkrange_set_increments(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, setInverted)
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
	phpgtk_gtkrange_set_inverted(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, setRange)
{
	double min, max;
	zval *handle_param = NULL, *min_param = NULL, *max_param = NULL, _0, _1, _2;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(min)
		Z_PARAM_ZVAL(max)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &min_param, &max_param);
	min = zephir_get_doubleval(min_param);
	max = zephir_get_doubleval(max_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_DOUBLE(&_1, min);
	ZVAL_DOUBLE(&_2, max);
	phpgtk_gtkrange_set_range(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, setRestrictToFillLevel)
{
	zend_bool restrictToFillLevel;
	zval *handle_param = NULL, *restrictToFillLevel_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(restrictToFillLevel)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &restrictToFillLevel_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (restrictToFillLevel ? 1 : 0));
	phpgtk_gtkrange_set_restrict_to_fill_level(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, setRoundDigits)
{
	zval *handle_param = NULL, *roundDigits_param = NULL, _0, _1;
	zend_long handle, roundDigits;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(roundDigits)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &roundDigits_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, roundDigits);
	phpgtk_gtkrange_set_round_digits(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, setShowFillLevel)
{
	zend_bool showFillLevel;
	zval *handle_param = NULL, *showFillLevel_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(showFillLevel)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &showFillLevel_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (showFillLevel ? 1 : 0));
	phpgtk_gtkrange_set_show_fill_level(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, setSliderSizeFixed)
{
	zend_bool sizeFixed;
	zval *handle_param = NULL, *sizeFixed_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(sizeFixed)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &sizeFixed_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (sizeFixed ? 1 : 0));
	phpgtk_gtkrange_set_slider_size_fixed(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, setValue)
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
	phpgtk_gtkrange_set_value(&_0, &_1);
}

