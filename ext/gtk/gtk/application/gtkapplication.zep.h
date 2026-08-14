
extern zend_class_entry *gtk_gtk_application_gtkapplication_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_Application_GtkApplication);

PHP_METHOD(Gtk_GTK_Application_GtkApplication, gtkApplicationNew);
PHP_METHOD(Gtk_GTK_Application_GtkApplication, gtkApplicationRun);
PHP_METHOD(Gtk_GTK_Application_GtkApplication, gtkApplicationQuit);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_application_gtkapplication_gtkapplicationnew, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, applicationId, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_application_gtkapplication_gtkapplicationrun, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, app, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_application_gtkapplication_gtkapplicationquit, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, app, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_application_gtkapplication_method_entry) {
	PHP_ME(Gtk_GTK_Application_GtkApplication, gtkApplicationNew, arginfo_gtk_gtk_application_gtkapplication_gtkapplicationnew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Application_GtkApplication, gtkApplicationRun, arginfo_gtk_gtk_application_gtkapplication_gtkapplicationrun, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Application_GtkApplication, gtkApplicationQuit, arginfo_gtk_gtk_application_gtkapplication_gtkapplicationquit, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
