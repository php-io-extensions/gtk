#include "runtime.h"
#include "../stubs/GDateTime_arginfo.h"

void phpgtk_register_GDateTime(void)
{
	phpgtk_ce_GDateTime = register_class_GDateTime();
	phpgtk_object_setup(phpgtk_ce_GDateTime);
}

#define THIS_DATE_TIME ((GDateTime *) PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

ZEND_METHOD(GDateTime, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
}

ZEND_METHOD(GDateTime, newLocal)
{
	zend_long year;
	zend_long month;
	zend_long day;
	zend_long hour;
	zend_long minute;
	double seconds;
	GDateTime *date_time;

	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_LONG(year)
		Z_PARAM_LONG(month)
		Z_PARAM_LONG(day)
		Z_PARAM_LONG(hour)
		Z_PARAM_LONG(minute)
		Z_PARAM_DOUBLE(seconds)
	ZEND_PARSE_PARAMETERS_END();

	if (!phpgtk_long_in_range(year, G_MININT, G_MAXINT, 1) || !phpgtk_long_in_range(month, G_MININT, G_MAXINT, 2)
			|| !phpgtk_long_in_range(day, G_MININT, G_MAXINT, 3) || !phpgtk_long_in_range(hour, G_MININT, G_MAXINT, 4)
			|| !phpgtk_long_in_range(minute, G_MININT, G_MAXINT, 5)) {
		RETURN_THROWS();
	}

	date_time = g_date_time_new_local((gint) year, (gint) month, (gint) day, (gint) hour, (gint) minute, (gdouble) seconds);
	if (date_time == NULL) {
		zend_value_error("GDateTime::newLocal(): the date and time are not valid");
		RETURN_THROWS();
	}

	phpgtk_box_date_time(return_value, date_time);
}

ZEND_METHOD(GDateTime, getYear)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG(g_date_time_get_year(THIS_DATE_TIME));
}

ZEND_METHOD(GDateTime, getMonth)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG(g_date_time_get_month(THIS_DATE_TIME));
}

ZEND_METHOD(GDateTime, getDayOfMonth)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG(g_date_time_get_day_of_month(THIS_DATE_TIME));
}

ZEND_METHOD(GDateTime, toUnix)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG((zend_long) g_date_time_to_unix(THIS_DATE_TIME));
}
