
extern zend_class_entry *gtk_gtk_gtklevelbar_gtklevelbar_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkLevelBar_GtkLevelBar);

PHP_METHOD(Gtk_Gtk_GtkLevelBar_GtkLevelBar, new_);
PHP_METHOD(Gtk_Gtk_GtkLevelBar_GtkLevelBar, newForInterval);
PHP_METHOD(Gtk_Gtk_GtkLevelBar_GtkLevelBar, addOffsetValue);
PHP_METHOD(Gtk_Gtk_GtkLevelBar_GtkLevelBar, getInverted);
PHP_METHOD(Gtk_Gtk_GtkLevelBar_GtkLevelBar, getMaxValue);
PHP_METHOD(Gtk_Gtk_GtkLevelBar_GtkLevelBar, getMinValue);
PHP_METHOD(Gtk_Gtk_GtkLevelBar_GtkLevelBar, getMode);
PHP_METHOD(Gtk_Gtk_GtkLevelBar_GtkLevelBar, getOffsetValue);
PHP_METHOD(Gtk_Gtk_GtkLevelBar_GtkLevelBar, getValue);
PHP_METHOD(Gtk_Gtk_GtkLevelBar_GtkLevelBar, removeOffsetValue);
PHP_METHOD(Gtk_Gtk_GtkLevelBar_GtkLevelBar, setInverted);
PHP_METHOD(Gtk_Gtk_GtkLevelBar_GtkLevelBar, setMaxValue);
PHP_METHOD(Gtk_Gtk_GtkLevelBar_GtkLevelBar, setMinValue);
PHP_METHOD(Gtk_Gtk_GtkLevelBar_GtkLevelBar, setMode);
PHP_METHOD(Gtk_Gtk_GtkLevelBar_GtkLevelBar, setValue);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklevelbar_gtklevelbar_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklevelbar_gtklevelbar_newforinterval, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, minValue, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, maxValue, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklevelbar_gtklevelbar_addoffsetvalue, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklevelbar_gtklevelbar_getinverted, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklevelbar_gtklevelbar_getmaxvalue, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklevelbar_gtklevelbar_getminvalue, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklevelbar_gtklevelbar_getmode, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklevelbar_gtklevelbar_getoffsetvalue, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklevelbar_gtklevelbar_getvalue, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklevelbar_gtklevelbar_removeoffsetvalue, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklevelbar_gtklevelbar_setinverted, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, inverted, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklevelbar_gtklevelbar_setmaxvalue, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklevelbar_gtklevelbar_setminvalue, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklevelbar_gtklevelbar_setmode, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklevelbar_gtklevelbar_setvalue, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtklevelbar_gtklevelbar_method_entry) {
	PHP_ME(Gtk_Gtk_GtkLevelBar_GtkLevelBar, new_, arginfo_gtk_gtk_gtklevelbar_gtklevelbar_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLevelBar_GtkLevelBar, newForInterval, arginfo_gtk_gtk_gtklevelbar_gtklevelbar_newforinterval, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLevelBar_GtkLevelBar, addOffsetValue, arginfo_gtk_gtk_gtklevelbar_gtklevelbar_addoffsetvalue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLevelBar_GtkLevelBar, getInverted, arginfo_gtk_gtk_gtklevelbar_gtklevelbar_getinverted, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLevelBar_GtkLevelBar, getMaxValue, arginfo_gtk_gtk_gtklevelbar_gtklevelbar_getmaxvalue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLevelBar_GtkLevelBar, getMinValue, arginfo_gtk_gtk_gtklevelbar_gtklevelbar_getminvalue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLevelBar_GtkLevelBar, getMode, arginfo_gtk_gtk_gtklevelbar_gtklevelbar_getmode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLevelBar_GtkLevelBar, getOffsetValue, arginfo_gtk_gtk_gtklevelbar_gtklevelbar_getoffsetvalue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLevelBar_GtkLevelBar, getValue, arginfo_gtk_gtk_gtklevelbar_gtklevelbar_getvalue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLevelBar_GtkLevelBar, removeOffsetValue, arginfo_gtk_gtk_gtklevelbar_gtklevelbar_removeoffsetvalue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLevelBar_GtkLevelBar, setInverted, arginfo_gtk_gtk_gtklevelbar_gtklevelbar_setinverted, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLevelBar_GtkLevelBar, setMaxValue, arginfo_gtk_gtk_gtklevelbar_gtklevelbar_setmaxvalue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLevelBar_GtkLevelBar, setMinValue, arginfo_gtk_gtk_gtklevelbar_gtklevelbar_setminvalue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLevelBar_GtkLevelBar, setMode, arginfo_gtk_gtk_gtklevelbar_gtklevelbar_setmode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLevelBar_GtkLevelBar, setValue, arginfo_gtk_gtk_gtklevelbar_gtklevelbar_setvalue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
