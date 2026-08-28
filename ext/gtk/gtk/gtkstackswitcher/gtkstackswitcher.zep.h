
extern zend_class_entry *gtk_gtk_gtkstackswitcher_gtkstackswitcher_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkStackSwitcher_GtkStackSwitcher);

PHP_METHOD(Gtk_Gtk_GtkStackSwitcher_GtkStackSwitcher, new_);
PHP_METHOD(Gtk_Gtk_GtkStackSwitcher_GtkStackSwitcher, getStack);
PHP_METHOD(Gtk_Gtk_GtkStackSwitcher_GtkStackSwitcher, setStack);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstackswitcher_gtkstackswitcher_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstackswitcher_gtkstackswitcher_getstack, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstackswitcher_gtkstackswitcher_setstack, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, stack, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkstackswitcher_gtkstackswitcher_method_entry) {
	PHP_ME(Gtk_Gtk_GtkStackSwitcher_GtkStackSwitcher, new_, arginfo_gtk_gtk_gtkstackswitcher_gtkstackswitcher_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStackSwitcher_GtkStackSwitcher, getStack, arginfo_gtk_gtk_gtkstackswitcher_gtkstackswitcher_getstack, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStackSwitcher_GtkStackSwitcher, setStack, arginfo_gtk_gtk_gtkstackswitcher_gtkstackswitcher_setstack, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
