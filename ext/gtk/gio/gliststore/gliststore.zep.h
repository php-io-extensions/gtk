
extern zend_class_entry *gtk_gio_gliststore_gliststore_ce;

ZEPHIR_INIT_CLASS(Gtk_Gio_GListStore_GListStore);

PHP_METHOD(Gtk_Gio_GListStore_GListStore, new_);
PHP_METHOD(Gtk_Gio_GListStore_GListStore, append);
PHP_METHOD(Gtk_Gio_GListStore_GListStore, find);
PHP_METHOD(Gtk_Gio_GListStore_GListStore, insert);
PHP_METHOD(Gtk_Gio_GListStore_GListStore, remove);
PHP_METHOD(Gtk_Gio_GListStore_GListStore, removeAll);
PHP_METHOD(Gtk_Gio_GListStore_GListStore, splice);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gliststore_gliststore_new_, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, itemType, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gliststore_gliststore_append, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, item, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gliststore_gliststore_find, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, item, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gliststore_gliststore_insert, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, item, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gliststore_gliststore_remove, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gliststore_gliststore_removeall, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gliststore_gliststore_splice, 0, 5, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, nRemovals, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, additions, 0)
	ZEND_ARG_TYPE_INFO(0, nAdditions, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gio_gliststore_gliststore_method_entry) {
	PHP_ME(Gtk_Gio_GListStore_GListStore, new_, arginfo_gtk_gio_gliststore_gliststore_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GListStore_GListStore, append, arginfo_gtk_gio_gliststore_gliststore_append, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GListStore_GListStore, find, arginfo_gtk_gio_gliststore_gliststore_find, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GListStore_GListStore, insert, arginfo_gtk_gio_gliststore_gliststore_insert, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GListStore_GListStore, remove, arginfo_gtk_gio_gliststore_gliststore_remove, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GListStore_GListStore, removeAll, arginfo_gtk_gio_gliststore_gliststore_removeall, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GListStore_GListStore, splice, arginfo_gtk_gio_gliststore_gliststore_splice, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
