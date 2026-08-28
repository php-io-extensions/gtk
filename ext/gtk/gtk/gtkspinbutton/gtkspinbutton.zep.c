
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
#include "src/gtk-spin-button.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkSpinButton_GtkSpinButton)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkSpinButton, GtkSpinButton, gtk_gtk, gtkspinbutton_gtkspinbutton, gtk_gtk_gtkspinbutton_gtkspinbutton_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, new_)
{
	double climbRate;
	zval *adjustment_param = NULL, *climbRate_param = NULL, *digits_param = NULL, _0, _1, _2;
	zend_long adjustment, digits;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(adjustment)
		Z_PARAM_ZVAL(climbRate)
		Z_PARAM_LONG(digits)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &adjustment_param, &climbRate_param, &digits_param);
	climbRate = zephir_get_doubleval(climbRate_param);
	ZVAL_LONG(&_0, adjustment);
	ZVAL_DOUBLE(&_1, climbRate);
	ZVAL_LONG(&_2, digits);
	RETURN_LONG(phpgtk_gtkspinbutton_new(&_0, &_1, &_2));
}

PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, newWithRange)
{
	zval *min_param = NULL, *max_param = NULL, *step_param = NULL, _0, _1, _2;
	double min, max, step;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ZVAL(min)
		Z_PARAM_ZVAL(max)
		Z_PARAM_ZVAL(step)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &min_param, &max_param, &step_param);
	min = zephir_get_doubleval(min_param);
	max = zephir_get_doubleval(max_param);
	step = zephir_get_doubleval(step_param);
	ZVAL_DOUBLE(&_0, min);
	ZVAL_DOUBLE(&_1, max);
	ZVAL_DOUBLE(&_2, step);
	RETURN_LONG(phpgtk_gtkspinbutton_new_with_range(&_0, &_1, &_2));
}

PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, configure)
{
	double climbRate;
	zval *handle_param = NULL, *adjustment_param = NULL, *climbRate_param = NULL, *digits_param = NULL, _0, _1, _2, _3;
	zend_long handle, adjustment, digits;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(adjustment)
		Z_PARAM_ZVAL(climbRate)
		Z_PARAM_LONG(digits)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &handle_param, &adjustment_param, &climbRate_param, &digits_param);
	climbRate = zephir_get_doubleval(climbRate_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, adjustment);
	ZVAL_DOUBLE(&_2, climbRate);
	ZVAL_LONG(&_3, digits);
	phpgtk_gtkspinbutton_configure(&_0, &_1, &_2, &_3);
}

PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getActivatesDefault)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkspinbutton_get_activates_default(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getAdjustment)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkspinbutton_get_adjustment(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getClimbRate)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_DOUBLE(phpgtk_gtkspinbutton_get_climb_rate(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getDigits)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkspinbutton_get_digits(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getIncrements)
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
	phpgtk_gtkspinbutton_get_increments(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getNumeric)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkspinbutton_get_numeric(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getRange)
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
	phpgtk_gtkspinbutton_get_range(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getSnapToTicks)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkspinbutton_get_snap_to_ticks(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getUpdatePolicy)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkspinbutton_get_update_policy(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getValue)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_DOUBLE(phpgtk_gtkspinbutton_get_value(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getValueAsInt)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkspinbutton_get_value_as_int(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getWrap)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkspinbutton_get_wrap(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, setActivatesDefault)
{
	zend_bool activatesDefault;
	zval *handle_param = NULL, *activatesDefault_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(activatesDefault)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &activatesDefault_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (activatesDefault ? 1 : 0));
	phpgtk_gtkspinbutton_set_activates_default(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, setAdjustment)
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
	phpgtk_gtkspinbutton_set_adjustment(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, setClimbRate)
{
	double climbRate;
	zval *handle_param = NULL, *climbRate_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(climbRate)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &climbRate_param);
	climbRate = zephir_get_doubleval(climbRate_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_DOUBLE(&_1, climbRate);
	phpgtk_gtkspinbutton_set_climb_rate(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, setDigits)
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
	phpgtk_gtkspinbutton_set_digits(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, setIncrements)
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
	phpgtk_gtkspinbutton_set_increments(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, setNumeric)
{
	zend_bool numeric;
	zval *handle_param = NULL, *numeric_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(numeric)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &numeric_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (numeric ? 1 : 0));
	phpgtk_gtkspinbutton_set_numeric(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, setRange)
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
	phpgtk_gtkspinbutton_set_range(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, setSnapToTicks)
{
	zend_bool snapToTicks;
	zval *handle_param = NULL, *snapToTicks_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(snapToTicks)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &snapToTicks_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (snapToTicks ? 1 : 0));
	phpgtk_gtkspinbutton_set_snap_to_ticks(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, setUpdatePolicy)
{
	zval *handle_param = NULL, *policy_param = NULL, _0, _1;
	zend_long handle, policy;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(policy)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &policy_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, policy);
	phpgtk_gtkspinbutton_set_update_policy(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, setValue)
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
	phpgtk_gtkspinbutton_set_value(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, setWrap)
{
	zend_bool wrap;
	zval *handle_param = NULL, *wrap_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(wrap)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &wrap_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (wrap ? 1 : 0));
	phpgtk_gtkspinbutton_set_wrap(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, spin)
{
	double increment;
	zval *handle_param = NULL, *direction_param = NULL, *increment_param = NULL, _0, _1, _2;
	zend_long handle, direction;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(direction)
		Z_PARAM_ZVAL(increment)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &direction_param, &increment_param);
	increment = zephir_get_doubleval(increment_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, direction);
	ZVAL_DOUBLE(&_2, increment);
	phpgtk_gtkspinbutton_spin(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, update)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkspinbutton_update(&_0);
}

