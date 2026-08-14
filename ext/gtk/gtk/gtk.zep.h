
extern zend_class_entry *gtk_gtk_gtk_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_Gtk);

PHP_METHOD(Gtk_GTK_Gtk, gtkInitCheck);
PHP_METHOD(Gtk_GTK_Gtk, gtkGetMajorVersion);
PHP_METHOD(Gtk_GTK_Gtk, gtkGetMinorVersion);
PHP_METHOD(Gtk_GTK_Gtk, gtkGetMicroVersion);
PHP_METHOD(Gtk_GTK_Gtk, gtkGetBinaryAge);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtk_gtkinitcheck, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtk_gtkgetmajorversion, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtk_gtkgetminorversion, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtk_gtkgetmicroversion, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtk_gtkgetbinaryage, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtk_method_entry) {
	PHP_ME(Gtk_GTK_Gtk, gtkInitCheck, arginfo_gtk_gtk_gtk_gtkinitcheck, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Gtk, gtkGetMajorVersion, arginfo_gtk_gtk_gtk_gtkgetmajorversion, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Gtk, gtkGetMinorVersion, arginfo_gtk_gtk_gtk_gtkgetminorversion, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Gtk, gtkGetMicroVersion, arginfo_gtk_gtk_gtk_gtkgetmicroversion, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Gtk, gtkGetBinaryAge, arginfo_gtk_gtk_gtk_gtkgetbinaryage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
