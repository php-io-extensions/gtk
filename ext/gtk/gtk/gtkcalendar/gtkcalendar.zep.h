
extern zend_class_entry *gtk_gtk_gtkcalendar_gtkcalendar_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkCalendar_GtkCalendar);

PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, new_);
PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, clearMarks);
PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, getDay);
PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, getDayIsMarked);
PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, getMonth);
PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, getShowDayNames);
PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, getShowHeading);
PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, getShowWeekNumbers);
PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, getYear);
PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, markDay);
PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, setDay);
PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, setMonth);
PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, setShowDayNames);
PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, setShowHeading);
PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, setShowWeekNumbers);
PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, setYear);
PHP_METHOD(Gtk_Gtk_GtkCalendar_GtkCalendar, unmarkDay);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcalendar_gtkcalendar_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcalendar_gtkcalendar_clearmarks, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcalendar_gtkcalendar_getday, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcalendar_gtkcalendar_getdayismarked, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, day, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcalendar_gtkcalendar_getmonth, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcalendar_gtkcalendar_getshowdaynames, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcalendar_gtkcalendar_getshowheading, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcalendar_gtkcalendar_getshowweeknumbers, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcalendar_gtkcalendar_getyear, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcalendar_gtkcalendar_markday, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, day, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcalendar_gtkcalendar_setday, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, day, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcalendar_gtkcalendar_setmonth, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, month, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcalendar_gtkcalendar_setshowdaynames, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcalendar_gtkcalendar_setshowheading, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcalendar_gtkcalendar_setshowweeknumbers, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcalendar_gtkcalendar_setyear, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, year, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcalendar_gtkcalendar_unmarkday, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, day, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkcalendar_gtkcalendar_method_entry) {
	PHP_ME(Gtk_Gtk_GtkCalendar_GtkCalendar, new_, arginfo_gtk_gtk_gtkcalendar_gtkcalendar_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCalendar_GtkCalendar, clearMarks, arginfo_gtk_gtk_gtkcalendar_gtkcalendar_clearmarks, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCalendar_GtkCalendar, getDay, arginfo_gtk_gtk_gtkcalendar_gtkcalendar_getday, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCalendar_GtkCalendar, getDayIsMarked, arginfo_gtk_gtk_gtkcalendar_gtkcalendar_getdayismarked, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCalendar_GtkCalendar, getMonth, arginfo_gtk_gtk_gtkcalendar_gtkcalendar_getmonth, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCalendar_GtkCalendar, getShowDayNames, arginfo_gtk_gtk_gtkcalendar_gtkcalendar_getshowdaynames, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCalendar_GtkCalendar, getShowHeading, arginfo_gtk_gtk_gtkcalendar_gtkcalendar_getshowheading, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCalendar_GtkCalendar, getShowWeekNumbers, arginfo_gtk_gtk_gtkcalendar_gtkcalendar_getshowweeknumbers, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCalendar_GtkCalendar, getYear, arginfo_gtk_gtk_gtkcalendar_gtkcalendar_getyear, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCalendar_GtkCalendar, markDay, arginfo_gtk_gtk_gtkcalendar_gtkcalendar_markday, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCalendar_GtkCalendar, setDay, arginfo_gtk_gtk_gtkcalendar_gtkcalendar_setday, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCalendar_GtkCalendar, setMonth, arginfo_gtk_gtk_gtkcalendar_gtkcalendar_setmonth, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCalendar_GtkCalendar, setShowDayNames, arginfo_gtk_gtk_gtkcalendar_gtkcalendar_setshowdaynames, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCalendar_GtkCalendar, setShowHeading, arginfo_gtk_gtk_gtkcalendar_gtkcalendar_setshowheading, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCalendar_GtkCalendar, setShowWeekNumbers, arginfo_gtk_gtk_gtkcalendar_gtkcalendar_setshowweeknumbers, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCalendar_GtkCalendar, setYear, arginfo_gtk_gtk_gtkcalendar_gtkcalendar_setyear, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCalendar_GtkCalendar, unmarkDay, arginfo_gtk_gtk_gtkcalendar_gtkcalendar_unmarkday, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
