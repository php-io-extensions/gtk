
extern zend_class_entry *gtk_gtk_gtkswitch_gtkswitch_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkSwitch_GtkSwitch);

PHP_METHOD(Gtk_Gtk_GtkSwitch_GtkSwitch, new_);
PHP_METHOD(Gtk_Gtk_GtkSwitch_GtkSwitch, getActive);
PHP_METHOD(Gtk_Gtk_GtkSwitch_GtkSwitch, getState);
PHP_METHOD(Gtk_Gtk_GtkSwitch_GtkSwitch, setActive);
PHP_METHOD(Gtk_Gtk_GtkSwitch_GtkSwitch, setState);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkswitch_gtkswitch_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkswitch_gtkswitch_getactive, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkswitch_gtkswitch_getstate, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkswitch_gtkswitch_setactive, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, isActive, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkswitch_gtkswitch_setstate, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, state, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkswitch_gtkswitch_method_entry) {
	PHP_ME(Gtk_Gtk_GtkSwitch_GtkSwitch, new_, arginfo_gtk_gtk_gtkswitch_gtkswitch_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSwitch_GtkSwitch, getActive, arginfo_gtk_gtk_gtkswitch_gtkswitch_getactive, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSwitch_GtkSwitch, getState, arginfo_gtk_gtk_gtkswitch_gtkswitch_getstate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSwitch_GtkSwitch, setActive, arginfo_gtk_gtk_gtkswitch_gtkswitch_setactive, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSwitch_GtkSwitch, setState, arginfo_gtk_gtk_gtkswitch_gtkswitch_setstate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
