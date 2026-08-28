
extern zend_class_entry *gtk_gio_gactionmap_gactionmap_ce;

ZEPHIR_INIT_CLASS(Gtk_Gio_GActionMap_GActionMap);

PHP_METHOD(Gtk_Gio_GActionMap_GActionMap, addAction);
PHP_METHOD(Gtk_Gio_GActionMap_GActionMap, lookupAction);
PHP_METHOD(Gtk_Gio_GActionMap_GActionMap, removeAction);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gactionmap_gactionmap_addaction, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, action, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gactionmap_gactionmap_lookupaction, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, actionName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gactionmap_gactionmap_removeaction, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, actionName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gio_gactionmap_gactionmap_method_entry) {
	PHP_ME(Gtk_Gio_GActionMap_GActionMap, addAction, arginfo_gtk_gio_gactionmap_gactionmap_addaction, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GActionMap_GActionMap, lookupAction, arginfo_gtk_gio_gactionmap_gactionmap_lookupaction, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GActionMap_GActionMap, removeAction, arginfo_gtk_gio_gactionmap_gactionmap_removeaction, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
