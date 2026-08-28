
extern zend_class_entry *gtk_gtk_gtkactionable_gtkactionable_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkActionable_GtkActionable);

PHP_METHOD(Gtk_Gtk_GtkActionable_GtkActionable, getActionName);
PHP_METHOD(Gtk_Gtk_GtkActionable_GtkActionable, setActionName);
PHP_METHOD(Gtk_Gtk_GtkActionable_GtkActionable, setDetailedActionName);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkactionable_gtkactionable_getactionname, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkactionable_gtkactionable_setactionname, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, actionName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkactionable_gtkactionable_setdetailedactionname, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, detailedActionName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkactionable_gtkactionable_method_entry) {
	PHP_ME(Gtk_Gtk_GtkActionable_GtkActionable, getActionName, arginfo_gtk_gtk_gtkactionable_gtkactionable_getactionname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkActionable_GtkActionable, setActionName, arginfo_gtk_gtk_gtkactionable_gtkactionable_setactionname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkActionable_GtkActionable, setDetailedActionName, arginfo_gtk_gtk_gtkactionable_gtkactionable_setdetailedactionname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
