
extern zend_class_entry *gtk_gio_gaction_gaction_ce;

ZEPHIR_INIT_CLASS(Gtk_Gio_GAction_GAction);

PHP_METHOD(Gtk_Gio_GAction_GAction, nameIsValid);
PHP_METHOD(Gtk_Gio_GAction_GAction, getEnabled);
PHP_METHOD(Gtk_Gio_GAction_GAction, getName);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gaction_gaction_nameisvalid, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, actionName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gaction_gaction_getenabled, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gio_gaction_gaction_getname, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gio_gaction_gaction_method_entry) {
	PHP_ME(Gtk_Gio_GAction_GAction, nameIsValid, arginfo_gtk_gio_gaction_gaction_nameisvalid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GAction_GAction, getEnabled, arginfo_gtk_gio_gaction_gaction_getenabled, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GAction_GAction, getName, arginfo_gtk_gio_gaction_gaction_getname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
