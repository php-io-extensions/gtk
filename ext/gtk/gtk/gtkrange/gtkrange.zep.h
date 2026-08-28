
extern zend_class_entry *gtk_gtk_gtkrange_gtkrange_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkRange_GtkRange);

PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, getAdjustment);
PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, getFillLevel);
PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, getFlippable);
PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, getInverted);
PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, getRangeRect);
PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, getRestrictToFillLevel);
PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, getRoundDigits);
PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, getShowFillLevel);
PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, getSliderRange);
PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, getSliderSizeFixed);
PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, getValue);
PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, setAdjustment);
PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, setFillLevel);
PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, setFlippable);
PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, setIncrements);
PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, setInverted);
PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, setRange);
PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, setRestrictToFillLevel);
PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, setRoundDigits);
PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, setShowFillLevel);
PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, setSliderSizeFixed);
PHP_METHOD(Gtk_Gtk_GtkRange_GtkRange, setValue);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkrange_gtkrange_getadjustment, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkrange_gtkrange_getfilllevel, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkrange_gtkrange_getflippable, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkrange_gtkrange_getinverted, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkrange_gtkrange_getrangerect, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkrange_gtkrange_getrestricttofilllevel, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkrange_gtkrange_getrounddigits, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkrange_gtkrange_getshowfilllevel, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkrange_gtkrange_getsliderrange, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkrange_gtkrange_getslidersizefixed, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkrange_gtkrange_getvalue, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkrange_gtkrange_setadjustment, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, adjustment, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkrange_gtkrange_setfilllevel, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fillLevel, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkrange_gtkrange_setflippable, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, flippable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkrange_gtkrange_setincrements, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, step, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, page, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkrange_gtkrange_setinverted, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, setting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkrange_gtkrange_setrange, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, min, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, max, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkrange_gtkrange_setrestricttofilllevel, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, restrictToFillLevel, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkrange_gtkrange_setrounddigits, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, roundDigits, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkrange_gtkrange_setshowfilllevel, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, showFillLevel, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkrange_gtkrange_setslidersizefixed, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, sizeFixed, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkrange_gtkrange_setvalue, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkrange_gtkrange_method_entry) {
	PHP_ME(Gtk_Gtk_GtkRange_GtkRange, getAdjustment, arginfo_gtk_gtk_gtkrange_gtkrange_getadjustment, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkRange_GtkRange, getFillLevel, arginfo_gtk_gtk_gtkrange_gtkrange_getfilllevel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkRange_GtkRange, getFlippable, arginfo_gtk_gtk_gtkrange_gtkrange_getflippable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkRange_GtkRange, getInverted, arginfo_gtk_gtk_gtkrange_gtkrange_getinverted, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkRange_GtkRange, getRangeRect, arginfo_gtk_gtk_gtkrange_gtkrange_getrangerect, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkRange_GtkRange, getRestrictToFillLevel, arginfo_gtk_gtk_gtkrange_gtkrange_getrestricttofilllevel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkRange_GtkRange, getRoundDigits, arginfo_gtk_gtk_gtkrange_gtkrange_getrounddigits, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkRange_GtkRange, getShowFillLevel, arginfo_gtk_gtk_gtkrange_gtkrange_getshowfilllevel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkRange_GtkRange, getSliderRange, arginfo_gtk_gtk_gtkrange_gtkrange_getsliderrange, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkRange_GtkRange, getSliderSizeFixed, arginfo_gtk_gtk_gtkrange_gtkrange_getslidersizefixed, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkRange_GtkRange, getValue, arginfo_gtk_gtk_gtkrange_gtkrange_getvalue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkRange_GtkRange, setAdjustment, arginfo_gtk_gtk_gtkrange_gtkrange_setadjustment, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkRange_GtkRange, setFillLevel, arginfo_gtk_gtk_gtkrange_gtkrange_setfilllevel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkRange_GtkRange, setFlippable, arginfo_gtk_gtk_gtkrange_gtkrange_setflippable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkRange_GtkRange, setIncrements, arginfo_gtk_gtk_gtkrange_gtkrange_setincrements, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkRange_GtkRange, setInverted, arginfo_gtk_gtk_gtkrange_gtkrange_setinverted, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkRange_GtkRange, setRange, arginfo_gtk_gtk_gtkrange_gtkrange_setrange, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkRange_GtkRange, setRestrictToFillLevel, arginfo_gtk_gtk_gtkrange_gtkrange_setrestricttofilllevel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkRange_GtkRange, setRoundDigits, arginfo_gtk_gtk_gtkrange_gtkrange_setrounddigits, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkRange_GtkRange, setShowFillLevel, arginfo_gtk_gtk_gtkrange_gtkrange_setshowfilllevel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkRange_GtkRange, setSliderSizeFixed, arginfo_gtk_gtk_gtkrange_gtkrange_setslidersizefixed, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkRange_GtkRange, setValue, arginfo_gtk_gtk_gtkrange_gtkrange_setvalue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
