
extern zend_class_entry *gtk_gio_gsimpleaction_gsimpleaction_ce;

ZEPHIR_INIT_CLASS(Gtk_Gio_GSimpleAction_GSimpleAction);

PHP_METHOD(Gtk_Gio_GSimpleAction_GSimpleAction, new_);
PHP_METHOD(Gtk_Gio_GSimpleAction_GSimpleAction, setEnabled);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gsimpleaction_gsimpleaction_new_, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gsimpleaction_gsimpleaction_setenabled, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, enabled, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gio_gsimpleaction_gsimpleaction_method_entry) {
	PHP_ME(Gtk_Gio_GSimpleAction_GSimpleAction, new_, arginfo_gtk_gio_gsimpleaction_gsimpleaction_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GSimpleAction_GSimpleAction, setEnabled, arginfo_gtk_gio_gsimpleaction_gsimpleaction_setenabled, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
