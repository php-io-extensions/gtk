
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
#include "src/gtk-calendar.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkCalendar_GtkCalendar)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkCalendar, GtkCalendar, gtk_gtk, gtkcalendar_gtkcalendar, gtk_gtk_gtkcalendar_gtkcalendar_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, new_)
{

	RETURN_LONG(phpgtk_gtkcalendar_new());
}

PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, clearMarks)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkcalendar_clear_marks(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, getDay)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkcalendar_get_day(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, getDayIsMarked)
{
	zval *handle_param = NULL, *day_param = NULL, _0, _1;
	zend_long handle, day, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(day)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &day_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, day);
	r = phpgtk_gtkcalendar_get_day_is_marked(&_0, &_1);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, getMonth)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkcalendar_get_month(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, getShowDayNames)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkcalendar_get_show_day_names(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, getShowHeading)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkcalendar_get_show_heading(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, getShowWeekNumbers)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkcalendar_get_show_week_numbers(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, getYear)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkcalendar_get_year(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, markDay)
{
	zval *handle_param = NULL, *day_param = NULL, _0, _1;
	zend_long handle, day;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(day)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &day_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, day);
	phpgtk_gtkcalendar_mark_day(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, setDay)
{
	zval *handle_param = NULL, *day_param = NULL, _0, _1;
	zend_long handle, day;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(day)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &day_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, day);
	phpgtk_gtkcalendar_set_day(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, setMonth)
{
	zval *handle_param = NULL, *month_param = NULL, _0, _1;
	zend_long handle, month;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(month)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &month_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, month);
	phpgtk_gtkcalendar_set_month(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, setShowDayNames)
{
	zend_bool value;
	zval *handle_param = NULL, *value_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &value_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (value ? 1 : 0));
	phpgtk_gtkcalendar_set_show_day_names(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, setShowHeading)
{
	zend_bool value;
	zval *handle_param = NULL, *value_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &value_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (value ? 1 : 0));
	phpgtk_gtkcalendar_set_show_heading(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, setShowWeekNumbers)
{
	zend_bool value;
	zval *handle_param = NULL, *value_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(value)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &value_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (value ? 1 : 0));
	phpgtk_gtkcalendar_set_show_week_numbers(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, setYear)
{
	zval *handle_param = NULL, *year_param = NULL, _0, _1;
	zend_long handle, year;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(year)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &year_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, year);
	phpgtk_gtkcalendar_set_year(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, unmarkDay)
{
	zval *handle_param = NULL, *day_param = NULL, _0, _1;
	zend_long handle, day;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(day)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &day_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, day);
	phpgtk_gtkcalendar_unmark_day(&_0, &_1);
}

