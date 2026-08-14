
extern zend_class_entry *gtk_gtk_gtkglib_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_GtkGLib);

PHP_METHOD(Gtk_GTK_GtkGLib, gObjectRef);
PHP_METHOD(Gtk_GTK_GtkGLib, gObjectUnref);
PHP_METHOD(Gtk_GTK_GtkGLib, gSignalConnect);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkglib_gobjectref, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, instance, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkglib_gobjectunref, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, instance, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkglib_gsignalconnect, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, instance, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, signal, IS_STRING, 0)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkglib_method_entry) {
	PHP_ME(Gtk_GTK_GtkGLib, gObjectRef, arginfo_gtk_gtk_gtkglib_gobjectref, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_GtkGLib, gObjectUnref, arginfo_gtk_gtk_gtkglib_gobjectunref, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_GtkGLib, gSignalConnect, arginfo_gtk_gtk_gtkglib_gsignalconnect, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
