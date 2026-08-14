
extern zend_class_entry *gtk_gtk_gtkswitch_gtkswitch_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_GtkSwitch_GtkSwitch);

PHP_METHOD(Gtk_GTK_GtkSwitch_GtkSwitch, gtkSwitchNew);
PHP_METHOD(Gtk_GTK_GtkSwitch_GtkSwitch, gtkSwitchSetActive);
PHP_METHOD(Gtk_GTK_GtkSwitch_GtkSwitch, gtkSwitchGetActive);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkswitch_gtkswitch_gtkswitchnew, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkswitch_gtkswitch_gtkswitchsetactive, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, sw, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, active, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkswitch_gtkswitch_gtkswitchgetactive, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, sw, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkswitch_gtkswitch_method_entry) {
	PHP_ME(Gtk_GTK_GtkSwitch_GtkSwitch, gtkSwitchNew, arginfo_gtk_gtk_gtkswitch_gtkswitch_gtkswitchnew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_GtkSwitch_GtkSwitch, gtkSwitchSetActive, arginfo_gtk_gtk_gtkswitch_gtkswitch_gtkswitchsetactive, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_GtkSwitch_GtkSwitch, gtkSwitchGetActive, arginfo_gtk_gtk_gtkswitch_gtkswitch_gtkswitchgetactive, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
