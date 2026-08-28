
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
#include "src/gtk-adjustment.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkAdjustment_GtkAdjustment)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkAdjustment, GtkAdjustment, gtk_gtk, gtkadjustment_gtkadjustment, gtk_gtk_gtkadjustment_gtkadjustment_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkAdjustment_GtkAdjustment, new_)
{
	zval *value_param = NULL, *lower_param = NULL, *upper_param = NULL, *stepIncrement_param = NULL, *pageIncrement_param = NULL, *pageSize_param = NULL, _0, _1, _2, _3, _4, _5;
	double value, lower, upper, stepIncrement, pageIncrement, pageSize;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_ZVAL(value)
		Z_PARAM_ZVAL(lower)
		Z_PARAM_ZVAL(upper)
		Z_PARAM_ZVAL(stepIncrement)
		Z_PARAM_ZVAL(pageIncrement)
		Z_PARAM_ZVAL(pageSize)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(6, 0, &value_param, &lower_param, &upper_param, &stepIncrement_param, &pageIncrement_param, &pageSize_param);
	value = zephir_get_doubleval(value_param);
	lower = zephir_get_doubleval(lower_param);
	upper = zephir_get_doubleval(upper_param);
	stepIncrement = zephir_get_doubleval(stepIncrement_param);
	pageIncrement = zephir_get_doubleval(pageIncrement_param);
	pageSize = zephir_get_doubleval(pageSize_param);
	ZVAL_DOUBLE(&_0, value);
	ZVAL_DOUBLE(&_1, lower);
	ZVAL_DOUBLE(&_2, upper);
	ZVAL_DOUBLE(&_3, stepIncrement);
	ZVAL_DOUBLE(&_4, pageIncrement);
	ZVAL_DOUBLE(&_5, pageSize);
	RETURN_LONG(phpgtk_gtkadjustment_new(&_0, &_1, &_2, &_3, &_4, &_5));
}

PHP_METHOD(Gtk_Gtk_GtkAdjustment_GtkAdjustment, clampPage)
{
	double lower, upper;
	zval *handle_param = NULL, *lower_param = NULL, *upper_param = NULL, _0, _1, _2;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(lower)
		Z_PARAM_ZVAL(upper)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &lower_param, &upper_param);
	lower = zephir_get_doubleval(lower_param);
	upper = zephir_get_doubleval(upper_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_DOUBLE(&_1, lower);
	ZVAL_DOUBLE(&_2, upper);
	phpgtk_gtkadjustment_clamp_page(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkAdjustment_GtkAdjustment, configure)
{
	double value, lower, upper, stepIncrement, pageIncrement, pageSize;
	zval *handle_param = NULL, *value_param = NULL, *lower_param = NULL, *upper_param = NULL, *stepIncrement_param = NULL, *pageIncrement_param = NULL, *pageSize_param = NULL, _0, _1, _2, _3, _4, _5, _6;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(value)
		Z_PARAM_ZVAL(lower)
		Z_PARAM_ZVAL(upper)
		Z_PARAM_ZVAL(stepIncrement)
		Z_PARAM_ZVAL(pageIncrement)
		Z_PARAM_ZVAL(pageSize)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(7, 0, &handle_param, &value_param, &lower_param, &upper_param, &stepIncrement_param, &pageIncrement_param, &pageSize_param);
	value = zephir_get_doubleval(value_param);
	lower = zephir_get_doubleval(lower_param);
	upper = zephir_get_doubleval(upper_param);
	stepIncrement = zephir_get_doubleval(stepIncrement_param);
	pageIncrement = zephir_get_doubleval(pageIncrement_param);
	pageSize = zephir_get_doubleval(pageSize_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_DOUBLE(&_1, value);
	ZVAL_DOUBLE(&_2, lower);
	ZVAL_DOUBLE(&_3, upper);
	ZVAL_DOUBLE(&_4, stepIncrement);
	ZVAL_DOUBLE(&_5, pageIncrement);
	ZVAL_DOUBLE(&_6, pageSize);
	phpgtk_gtkadjustment_configure(&_0, &_1, &_2, &_3, &_4, &_5, &_6);
}

PHP_METHOD(Gtk_Gtk_GtkAdjustment_GtkAdjustment, getLower)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_DOUBLE(phpgtk_gtkadjustment_get_lower(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkAdjustment_GtkAdjustment, getMinimumIncrement)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_DOUBLE(phpgtk_gtkadjustment_get_minimum_increment(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkAdjustment_GtkAdjustment, getPageIncrement)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_DOUBLE(phpgtk_gtkadjustment_get_page_increment(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkAdjustment_GtkAdjustment, getPageSize)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_DOUBLE(phpgtk_gtkadjustment_get_page_size(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkAdjustment_GtkAdjustment, getStepIncrement)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_DOUBLE(phpgtk_gtkadjustment_get_step_increment(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkAdjustment_GtkAdjustment, getUpper)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_DOUBLE(phpgtk_gtkadjustment_get_upper(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkAdjustment_GtkAdjustment, getValue)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_DOUBLE(phpgtk_gtkadjustment_get_value(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkAdjustment_GtkAdjustment, setLower)
{
	double lower;
	zval *handle_param = NULL, *lower_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(lower)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &lower_param);
	lower = zephir_get_doubleval(lower_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_DOUBLE(&_1, lower);
	phpgtk_gtkadjustment_set_lower(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkAdjustment_GtkAdjustment, setPageIncrement)
{
	double pageIncrement;
	zval *handle_param = NULL, *pageIncrement_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(pageIncrement)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &pageIncrement_param);
	pageIncrement = zephir_get_doubleval(pageIncrement_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_DOUBLE(&_1, pageIncrement);
	phpgtk_gtkadjustment_set_page_increment(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkAdjustment_GtkAdjustment, setPageSize)
{
	double pageSize;
	zval *handle_param = NULL, *pageSize_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(pageSize)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &pageSize_param);
	pageSize = zephir_get_doubleval(pageSize_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_DOUBLE(&_1, pageSize);
	phpgtk_gtkadjustment_set_page_size(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkAdjustment_GtkAdjustment, setStepIncrement)
{
	double stepIncrement;
	zval *handle_param = NULL, *stepIncrement_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(stepIncrement)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &stepIncrement_param);
	stepIncrement = zephir_get_doubleval(stepIncrement_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_DOUBLE(&_1, stepIncrement);
	phpgtk_gtkadjustment_set_step_increment(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkAdjustment_GtkAdjustment, setUpper)
{
	double upper;
	zval *handle_param = NULL, *upper_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(upper)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &upper_param);
	upper = zephir_get_doubleval(upper_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_DOUBLE(&_1, upper);
	phpgtk_gtkadjustment_set_upper(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkAdjustment_GtkAdjustment, setValue)
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
	phpgtk_gtkadjustment_set_value(&_0, &_1);
}

