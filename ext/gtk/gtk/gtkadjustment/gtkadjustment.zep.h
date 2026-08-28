
extern zend_class_entry *gtk_gtk_gtkadjustment_gtkadjustment_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkAdjustment_GtkAdjustment);

PHP_METHOD(Gtk_Gtk_GtkAdjustment_GtkAdjustment, new_);
PHP_METHOD(Gtk_Gtk_GtkAdjustment_GtkAdjustment, clampPage);
PHP_METHOD(Gtk_Gtk_GtkAdjustment_GtkAdjustment, configure);
PHP_METHOD(Gtk_Gtk_GtkAdjustment_GtkAdjustment, getLower);
PHP_METHOD(Gtk_Gtk_GtkAdjustment_GtkAdjustment, getMinimumIncrement);
PHP_METHOD(Gtk_Gtk_GtkAdjustment_GtkAdjustment, getPageIncrement);
PHP_METHOD(Gtk_Gtk_GtkAdjustment_GtkAdjustment, getPageSize);
PHP_METHOD(Gtk_Gtk_GtkAdjustment_GtkAdjustment, getStepIncrement);
PHP_METHOD(Gtk_Gtk_GtkAdjustment_GtkAdjustment, getUpper);
PHP_METHOD(Gtk_Gtk_GtkAdjustment_GtkAdjustment, getValue);
PHP_METHOD(Gtk_Gtk_GtkAdjustment_GtkAdjustment, setLower);
PHP_METHOD(Gtk_Gtk_GtkAdjustment_GtkAdjustment, setPageIncrement);
PHP_METHOD(Gtk_Gtk_GtkAdjustment_GtkAdjustment, setPageSize);
PHP_METHOD(Gtk_Gtk_GtkAdjustment_GtkAdjustment, setStepIncrement);
PHP_METHOD(Gtk_Gtk_GtkAdjustment_GtkAdjustment, setUpper);
PHP_METHOD(Gtk_Gtk_GtkAdjustment_GtkAdjustment, setValue);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkadjustment_gtkadjustment_new_, 0, 6, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, lower, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, upper, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, stepIncrement, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, pageIncrement, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, pageSize, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkadjustment_gtkadjustment_clamppage, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, lower, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, upper, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkadjustment_gtkadjustment_configure, 0, 7, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, lower, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, upper, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, stepIncrement, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, pageIncrement, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, pageSize, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkadjustment_gtkadjustment_getlower, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkadjustment_gtkadjustment_getminimumincrement, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkadjustment_gtkadjustment_getpageincrement, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkadjustment_gtkadjustment_getpagesize, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkadjustment_gtkadjustment_getstepincrement, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkadjustment_gtkadjustment_getupper, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkadjustment_gtkadjustment_getvalue, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkadjustment_gtkadjustment_setlower, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, lower, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkadjustment_gtkadjustment_setpageincrement, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pageIncrement, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkadjustment_gtkadjustment_setpagesize, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pageSize, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkadjustment_gtkadjustment_setstepincrement, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, stepIncrement, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkadjustment_gtkadjustment_setupper, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, upper, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkadjustment_gtkadjustment_setvalue, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkadjustment_gtkadjustment_method_entry) {
	PHP_ME(Gtk_Gtk_GtkAdjustment_GtkAdjustment, new_, arginfo_gtk_gtk_gtkadjustment_gtkadjustment_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAdjustment_GtkAdjustment, clampPage, arginfo_gtk_gtk_gtkadjustment_gtkadjustment_clamppage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAdjustment_GtkAdjustment, configure, arginfo_gtk_gtk_gtkadjustment_gtkadjustment_configure, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAdjustment_GtkAdjustment, getLower, arginfo_gtk_gtk_gtkadjustment_gtkadjustment_getlower, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAdjustment_GtkAdjustment, getMinimumIncrement, arginfo_gtk_gtk_gtkadjustment_gtkadjustment_getminimumincrement, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAdjustment_GtkAdjustment, getPageIncrement, arginfo_gtk_gtk_gtkadjustment_gtkadjustment_getpageincrement, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAdjustment_GtkAdjustment, getPageSize, arginfo_gtk_gtk_gtkadjustment_gtkadjustment_getpagesize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAdjustment_GtkAdjustment, getStepIncrement, arginfo_gtk_gtk_gtkadjustment_gtkadjustment_getstepincrement, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAdjustment_GtkAdjustment, getUpper, arginfo_gtk_gtk_gtkadjustment_gtkadjustment_getupper, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAdjustment_GtkAdjustment, getValue, arginfo_gtk_gtk_gtkadjustment_gtkadjustment_getvalue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAdjustment_GtkAdjustment, setLower, arginfo_gtk_gtk_gtkadjustment_gtkadjustment_setlower, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAdjustment_GtkAdjustment, setPageIncrement, arginfo_gtk_gtk_gtkadjustment_gtkadjustment_setpageincrement, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAdjustment_GtkAdjustment, setPageSize, arginfo_gtk_gtk_gtkadjustment_gtkadjustment_setpagesize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAdjustment_GtkAdjustment, setStepIncrement, arginfo_gtk_gtk_gtkadjustment_gtkadjustment_setstepincrement, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAdjustment_GtkAdjustment, setUpper, arginfo_gtk_gtk_gtkadjustment_gtkadjustment_setupper, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAdjustment_GtkAdjustment, setValue, arginfo_gtk_gtk_gtkadjustment_gtkadjustment_setvalue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
