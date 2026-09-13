
extern zend_class_entry *gtk_gtk_gtkselectionmodel_gtkselectionmodel_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkSelectionModel_GtkSelectionModel);

PHP_METHOD(Gtk_Gtk_GtkSelectionModel_GtkSelectionModel, isSelected);
PHP_METHOD(Gtk_Gtk_GtkSelectionModel_GtkSelectionModel, selectAll);
PHP_METHOD(Gtk_Gtk_GtkSelectionModel_GtkSelectionModel, selectItem);
PHP_METHOD(Gtk_Gtk_GtkSelectionModel_GtkSelectionModel, selectRange);
PHP_METHOD(Gtk_Gtk_GtkSelectionModel_GtkSelectionModel, selectionChanged);
PHP_METHOD(Gtk_Gtk_GtkSelectionModel_GtkSelectionModel, unselectAll);
PHP_METHOD(Gtk_Gtk_GtkSelectionModel_GtkSelectionModel, unselectItem);
PHP_METHOD(Gtk_Gtk_GtkSelectionModel_GtkSelectionModel, unselectRange);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkselectionmodel_gtkselectionmodel_isselected, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkselectionmodel_gtkselectionmodel_selectall, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkselectionmodel_gtkselectionmodel_selectitem, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, unselectRest, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkselectionmodel_gtkselectionmodel_selectrange, 0, 4, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, nItems, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, unselectRest, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkselectionmodel_gtkselectionmodel_selectionchanged, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, nItems, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkselectionmodel_gtkselectionmodel_unselectall, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkselectionmodel_gtkselectionmodel_unselectitem, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkselectionmodel_gtkselectionmodel_unselectrange, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, nItems, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkselectionmodel_gtkselectionmodel_method_entry) {
	PHP_ME(Gtk_Gtk_GtkSelectionModel_GtkSelectionModel, isSelected, arginfo_gtk_gtk_gtkselectionmodel_gtkselectionmodel_isselected, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSelectionModel_GtkSelectionModel, selectAll, arginfo_gtk_gtk_gtkselectionmodel_gtkselectionmodel_selectall, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSelectionModel_GtkSelectionModel, selectItem, arginfo_gtk_gtk_gtkselectionmodel_gtkselectionmodel_selectitem, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSelectionModel_GtkSelectionModel, selectRange, arginfo_gtk_gtk_gtkselectionmodel_gtkselectionmodel_selectrange, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSelectionModel_GtkSelectionModel, selectionChanged, arginfo_gtk_gtk_gtkselectionmodel_gtkselectionmodel_selectionchanged, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSelectionModel_GtkSelectionModel, unselectAll, arginfo_gtk_gtk_gtkselectionmodel_gtkselectionmodel_unselectall, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSelectionModel_GtkSelectionModel, unselectItem, arginfo_gtk_gtk_gtkselectionmodel_gtkselectionmodel_unselectitem, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSelectionModel_GtkSelectionModel, unselectRange, arginfo_gtk_gtk_gtkselectionmodel_gtkselectionmodel_unselectrange, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
