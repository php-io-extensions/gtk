
extern zend_class_entry *gtk_gdk_gdkkeyval_gdkkeyval_ce;

ZEPHIR_INIT_CLASS(Gtk_Gdk_GdkKeyval_GdkKeyval);

PHP_METHOD(Gtk_Gdk_GdkKeyval_GdkKeyval, convertCase);
PHP_METHOD(Gtk_Gdk_GdkKeyval_GdkKeyval, fromName);
PHP_METHOD(Gtk_Gdk_GdkKeyval_GdkKeyval, isLower);
PHP_METHOD(Gtk_Gdk_GdkKeyval_GdkKeyval, isUpper);
PHP_METHOD(Gtk_Gdk_GdkKeyval_GdkKeyval, name);
PHP_METHOD(Gtk_Gdk_GdkKeyval_GdkKeyval, toLower);
PHP_METHOD(Gtk_Gdk_GdkKeyval_GdkKeyval, toUnicode);
PHP_METHOD(Gtk_Gdk_GdkKeyval_GdkKeyval, toUpper);
PHP_METHOD(Gtk_Gdk_GdkKeyval_GdkKeyval, fromUnicode);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gdk_gdkkeyval_gdkkeyval_convertcase, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, symbol, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gdk_gdkkeyval_gdkkeyval_fromname, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gdk_gdkkeyval_gdkkeyval_islower, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, keyval, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gdk_gdkkeyval_gdkkeyval_isupper, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, keyval, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gdk_gdkkeyval_gdkkeyval_name, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, keyval, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gdk_gdkkeyval_gdkkeyval_tolower, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, keyval, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gdk_gdkkeyval_gdkkeyval_tounicode, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, keyval, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gdk_gdkkeyval_gdkkeyval_toupper, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, keyval, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gdk_gdkkeyval_gdkkeyval_fromunicode, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, wc, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gdk_gdkkeyval_gdkkeyval_method_entry) {
	PHP_ME(Gtk_Gdk_GdkKeyval_GdkKeyval, convertCase, arginfo_gtk_gdk_gdkkeyval_gdkkeyval_convertcase, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gdk_GdkKeyval_GdkKeyval, fromName, arginfo_gtk_gdk_gdkkeyval_gdkkeyval_fromname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gdk_GdkKeyval_GdkKeyval, isLower, arginfo_gtk_gdk_gdkkeyval_gdkkeyval_islower, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gdk_GdkKeyval_GdkKeyval, isUpper, arginfo_gtk_gdk_gdkkeyval_gdkkeyval_isupper, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gdk_GdkKeyval_GdkKeyval, name, arginfo_gtk_gdk_gdkkeyval_gdkkeyval_name, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gdk_GdkKeyval_GdkKeyval, toLower, arginfo_gtk_gdk_gdkkeyval_gdkkeyval_tolower, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gdk_GdkKeyval_GdkKeyval, toUnicode, arginfo_gtk_gdk_gdkkeyval_gdkkeyval_tounicode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gdk_GdkKeyval_GdkKeyval, toUpper, arginfo_gtk_gdk_gdkkeyval_gdkkeyval_toupper, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gdk_GdkKeyval_GdkKeyval, fromUnicode, arginfo_gtk_gdk_gdkkeyval_gdkkeyval_fromunicode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
