
extern zend_class_entry *gtk_gtk_scale_gtkscale_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_Scale_GtkScale);

PHP_METHOD(Gtk_GTK_Scale_GtkScale, gtkScaleNewWithRange);
PHP_METHOD(Gtk_GTK_Scale_GtkScale, gtkScaleSetValue);
PHP_METHOD(Gtk_GTK_Scale_GtkScale, gtkScaleGetValue);
PHP_METHOD(Gtk_GTK_Scale_GtkScale, gtkScaleSetDrawValue);
PHP_METHOD(Gtk_GTK_Scale_GtkScale, gtkScaleSetDigits);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_scale_gtkscale_gtkscalenewwithrange, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, orientation, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, min, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, max, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, step, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_scale_gtkscale_gtkscalesetvalue, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, scale, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_scale_gtkscale_gtkscalegetvalue, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, scale, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_scale_gtkscale_gtkscalesetdrawvalue, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, scale, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, drawValue, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_scale_gtkscale_gtkscalesetdigits, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, scale, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, digits, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_scale_gtkscale_method_entry) {
	PHP_ME(Gtk_GTK_Scale_GtkScale, gtkScaleNewWithRange, arginfo_gtk_gtk_scale_gtkscale_gtkscalenewwithrange, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Scale_GtkScale, gtkScaleSetValue, arginfo_gtk_gtk_scale_gtkscale_gtkscalesetvalue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Scale_GtkScale, gtkScaleGetValue, arginfo_gtk_gtk_scale_gtkscale_gtkscalegetvalue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Scale_GtkScale, gtkScaleSetDrawValue, arginfo_gtk_gtk_scale_gtkscale_gtkscalesetdrawvalue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Scale_GtkScale, gtkScaleSetDigits, arginfo_gtk_gtk_scale_gtkscale_gtkscalesetdigits, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
