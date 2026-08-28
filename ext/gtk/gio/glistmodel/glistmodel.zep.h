
extern zend_class_entry *gtk_gio_glistmodel_glistmodel_ce;

ZEPHIR_INIT_CLASS(Gtk_Gio_GListModel_GListModel);

PHP_METHOD(Gtk_Gio_GListModel_GListModel, getItem);
PHP_METHOD(Gtk_Gio_GListModel_GListModel, getItemType);
PHP_METHOD(Gtk_Gio_GListModel_GListModel, getNItems);
PHP_METHOD(Gtk_Gio_GListModel_GListModel, getObject);
PHP_METHOD(Gtk_Gio_GListModel_GListModel, itemsChanged);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_glistmodel_glistmodel_getitem, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_glistmodel_glistmodel_getitemtype, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_glistmodel_glistmodel_getnitems, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_glistmodel_glistmodel_getobject, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_glistmodel_glistmodel_itemschanged, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, removed, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, added, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gio_glistmodel_glistmodel_method_entry) {
	PHP_ME(Gtk_Gio_GListModel_GListModel, getItem, arginfo_gtk_gio_glistmodel_glistmodel_getitem, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GListModel_GListModel, getItemType, arginfo_gtk_gio_glistmodel_glistmodel_getitemtype, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GListModel_GListModel, getNItems, arginfo_gtk_gio_glistmodel_glistmodel_getnitems, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GListModel_GListModel, getObject, arginfo_gtk_gio_glistmodel_glistmodel_getobject, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GListModel_GListModel, itemsChanged, arginfo_gtk_gio_glistmodel_glistmodel_itemschanged, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
