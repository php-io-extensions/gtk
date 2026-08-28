
extern zend_class_entry *gtk_gio_gmenumodel_gmenumodel_ce;

ZEPHIR_INIT_CLASS(Gtk_Gio_GMenuModel_GMenuModel);

PHP_METHOD(Gtk_Gio_GMenuModel_GMenuModel, getItemLink);
PHP_METHOD(Gtk_Gio_GMenuModel_GMenuModel, getNItems);
PHP_METHOD(Gtk_Gio_GMenuModel_GMenuModel, isMutable);
PHP_METHOD(Gtk_Gio_GMenuModel_GMenuModel, itemsChanged);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gmenumodel_gmenumodel_getitemlink, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, itemIndex, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, link, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gmenumodel_gmenumodel_getnitems, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gmenumodel_gmenumodel_ismutable, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gmenumodel_gmenumodel_itemschanged, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, removed, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, added, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gio_gmenumodel_gmenumodel_method_entry) {
	PHP_ME(Gtk_Gio_GMenuModel_GMenuModel, getItemLink, arginfo_gtk_gio_gmenumodel_gmenumodel_getitemlink, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GMenuModel_GMenuModel, getNItems, arginfo_gtk_gio_gmenumodel_gmenumodel_getnitems, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GMenuModel_GMenuModel, isMutable, arginfo_gtk_gio_gmenumodel_gmenumodel_ismutable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GMenuModel_GMenuModel, itemsChanged, arginfo_gtk_gio_gmenumodel_gmenumodel_itemschanged, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
