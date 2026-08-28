
extern zend_class_entry *gtk_gtk_gtkspinbutton_gtkspinbutton_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkSpinButton_GtkSpinButton);

PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, new_);
PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, newWithRange);
PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, configure);
PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getActivatesDefault);
PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getAdjustment);
PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getClimbRate);
PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getDigits);
PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getIncrements);
PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getNumeric);
PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getRange);
PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getSnapToTicks);
PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getUpdatePolicy);
PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getValue);
PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getValueAsInt);
PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getWrap);
PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, setActivatesDefault);
PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, setAdjustment);
PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, setClimbRate);
PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, setDigits);
PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, setIncrements);
PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, setNumeric);
PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, setRange);
PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, setSnapToTicks);
PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, setUpdatePolicy);
PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, setValue);
PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, setWrap);
PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, spin);
PHP_METHOD(Gtk_Gtk_GtkSpinButton_GtkSpinButton, update);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_new_, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, adjustment, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, climbRate, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, digits, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_newwithrange, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, min, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, max, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, step, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_configure, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, adjustment, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, climbRate, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, digits, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_getactivatesdefault, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_getadjustment, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_getclimbrate, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_getdigits, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_getincrements, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_getnumeric, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_getrange, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_getsnaptoticks, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_getupdatepolicy, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_getvalue, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_getvalueasint, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_getwrap, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_setactivatesdefault, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, activatesDefault, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_setadjustment, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, adjustment, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_setclimbrate, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, climbRate, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_setdigits, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, digits, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_setincrements, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, step, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, page, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_setnumeric, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, numeric, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_setrange, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, min, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, max, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_setsnaptoticks, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, snapToTicks, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_setupdatepolicy, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, policy, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_setvalue, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_setwrap, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, wrap, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_spin, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, direction, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, increment, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_update, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkspinbutton_gtkspinbutton_method_entry) {
	PHP_ME(Gtk_Gtk_GtkSpinButton_GtkSpinButton, new_, arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSpinButton_GtkSpinButton, newWithRange, arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_newwithrange, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSpinButton_GtkSpinButton, configure, arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_configure, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getActivatesDefault, arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_getactivatesdefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getAdjustment, arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_getadjustment, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getClimbRate, arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_getclimbrate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getDigits, arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_getdigits, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getIncrements, arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_getincrements, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getNumeric, arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_getnumeric, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getRange, arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_getrange, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getSnapToTicks, arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_getsnaptoticks, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getUpdatePolicy, arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_getupdatepolicy, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getValue, arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_getvalue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getValueAsInt, arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_getvalueasint, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSpinButton_GtkSpinButton, getWrap, arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_getwrap, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSpinButton_GtkSpinButton, setActivatesDefault, arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_setactivatesdefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSpinButton_GtkSpinButton, setAdjustment, arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_setadjustment, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSpinButton_GtkSpinButton, setClimbRate, arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_setclimbrate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSpinButton_GtkSpinButton, setDigits, arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_setdigits, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSpinButton_GtkSpinButton, setIncrements, arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_setincrements, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSpinButton_GtkSpinButton, setNumeric, arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_setnumeric, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSpinButton_GtkSpinButton, setRange, arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_setrange, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSpinButton_GtkSpinButton, setSnapToTicks, arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_setsnaptoticks, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSpinButton_GtkSpinButton, setUpdatePolicy, arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_setupdatepolicy, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSpinButton_GtkSpinButton, setValue, arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_setvalue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSpinButton_GtkSpinButton, setWrap, arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_setwrap, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSpinButton_GtkSpinButton, spin, arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_spin, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSpinButton_GtkSpinButton, update, arginfo_gtk_gtk_gtkspinbutton_gtkspinbutton_update, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
