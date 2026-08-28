
extern zend_class_entry *gtk_gtk_gtkscale_gtkscale_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkScale_GtkScale);

PHP_METHOD(Gtk_Gtk_GtkScale_GtkScale, new_);
PHP_METHOD(Gtk_Gtk_GtkScale_GtkScale, newWithRange);
PHP_METHOD(Gtk_Gtk_GtkScale_GtkScale, addMark);
PHP_METHOD(Gtk_Gtk_GtkScale_GtkScale, clearMarks);
PHP_METHOD(Gtk_Gtk_GtkScale_GtkScale, getDigits);
PHP_METHOD(Gtk_Gtk_GtkScale_GtkScale, getDrawValue);
PHP_METHOD(Gtk_Gtk_GtkScale_GtkScale, getHasOrigin);
PHP_METHOD(Gtk_Gtk_GtkScale_GtkScale, getLayout);
PHP_METHOD(Gtk_Gtk_GtkScale_GtkScale, getLayoutOffsets);
PHP_METHOD(Gtk_Gtk_GtkScale_GtkScale, getValuePos);
PHP_METHOD(Gtk_Gtk_GtkScale_GtkScale, setDigits);
PHP_METHOD(Gtk_Gtk_GtkScale_GtkScale, setDrawValue);
PHP_METHOD(Gtk_Gtk_GtkScale_GtkScale, setHasOrigin);
PHP_METHOD(Gtk_Gtk_GtkScale_GtkScale, setValuePos);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscale_gtkscale_new_, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, orientation, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, adjustment, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscale_gtkscale_newwithrange, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, orientation, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, min, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, max, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, step, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscale_gtkscale_addmark, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
	ZEND_ARG_INFO(0, markup)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscale_gtkscale_clearmarks, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscale_gtkscale_getdigits, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscale_gtkscale_getdrawvalue, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscale_gtkscale_gethasorigin, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscale_gtkscale_getlayout, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscale_gtkscale_getlayoutoffsets, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscale_gtkscale_getvaluepos, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscale_gtkscale_setdigits, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, digits, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscale_gtkscale_setdrawvalue, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, drawValue, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscale_gtkscale_sethasorigin, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, hasOrigin, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscale_gtkscale_setvaluepos, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pos, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkscale_gtkscale_method_entry) {
	PHP_ME(Gtk_Gtk_GtkScale_GtkScale, new_, arginfo_gtk_gtk_gtkscale_gtkscale_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScale_GtkScale, newWithRange, arginfo_gtk_gtk_gtkscale_gtkscale_newwithrange, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScale_GtkScale, addMark, arginfo_gtk_gtk_gtkscale_gtkscale_addmark, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScale_GtkScale, clearMarks, arginfo_gtk_gtk_gtkscale_gtkscale_clearmarks, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScale_GtkScale, getDigits, arginfo_gtk_gtk_gtkscale_gtkscale_getdigits, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScale_GtkScale, getDrawValue, arginfo_gtk_gtk_gtkscale_gtkscale_getdrawvalue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScale_GtkScale, getHasOrigin, arginfo_gtk_gtk_gtkscale_gtkscale_gethasorigin, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScale_GtkScale, getLayout, arginfo_gtk_gtk_gtkscale_gtkscale_getlayout, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScale_GtkScale, getLayoutOffsets, arginfo_gtk_gtk_gtkscale_gtkscale_getlayoutoffsets, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScale_GtkScale, getValuePos, arginfo_gtk_gtk_gtkscale_gtkscale_getvaluepos, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScale_GtkScale, setDigits, arginfo_gtk_gtk_gtkscale_gtkscale_setdigits, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScale_GtkScale, setDrawValue, arginfo_gtk_gtk_gtkscale_gtkscale_setdrawvalue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScale_GtkScale, setHasOrigin, arginfo_gtk_gtk_gtkscale_gtkscale_sethasorigin, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScale_GtkScale, setValuePos, arginfo_gtk_gtk_gtkscale_gtkscale_setvaluepos, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
