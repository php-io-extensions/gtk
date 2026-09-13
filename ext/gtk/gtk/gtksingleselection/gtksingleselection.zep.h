
extern zend_class_entry *gtk_gtk_gtksingleselection_gtksingleselection_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkSingleSelection_GtkSingleSelection);

PHP_METHOD(Gtk_Gtk_GtkSingleSelection_GtkSingleSelection, new_);
PHP_METHOD(Gtk_Gtk_GtkSingleSelection_GtkSingleSelection, getAutoselect);
PHP_METHOD(Gtk_Gtk_GtkSingleSelection_GtkSingleSelection, getCanUnselect);
PHP_METHOD(Gtk_Gtk_GtkSingleSelection_GtkSingleSelection, getModel);
PHP_METHOD(Gtk_Gtk_GtkSingleSelection_GtkSingleSelection, getSelected);
PHP_METHOD(Gtk_Gtk_GtkSingleSelection_GtkSingleSelection, getSelectedItem);
PHP_METHOD(Gtk_Gtk_GtkSingleSelection_GtkSingleSelection, setAutoselect);
PHP_METHOD(Gtk_Gtk_GtkSingleSelection_GtkSingleSelection, setCanUnselect);
PHP_METHOD(Gtk_Gtk_GtkSingleSelection_GtkSingleSelection, setModel);
PHP_METHOD(Gtk_Gtk_GtkSingleSelection_GtkSingleSelection, setSelected);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtksingleselection_gtksingleselection_new_, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, model, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtksingleselection_gtksingleselection_getautoselect, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtksingleselection_gtksingleselection_getcanunselect, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtksingleselection_gtksingleselection_getmodel, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtksingleselection_gtksingleselection_getselected, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtksingleselection_gtksingleselection_getselecteditem, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtksingleselection_gtksingleselection_setautoselect, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, autoselect, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtksingleselection_gtksingleselection_setcanunselect, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, canUnselect, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtksingleselection_gtksingleselection_setmodel, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, model, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtksingleselection_gtksingleselection_setselected, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtksingleselection_gtksingleselection_method_entry) {
	PHP_ME(Gtk_Gtk_GtkSingleSelection_GtkSingleSelection, new_, arginfo_gtk_gtk_gtksingleselection_gtksingleselection_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSingleSelection_GtkSingleSelection, getAutoselect, arginfo_gtk_gtk_gtksingleselection_gtksingleselection_getautoselect, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSingleSelection_GtkSingleSelection, getCanUnselect, arginfo_gtk_gtk_gtksingleselection_gtksingleselection_getcanunselect, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSingleSelection_GtkSingleSelection, getModel, arginfo_gtk_gtk_gtksingleselection_gtksingleselection_getmodel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSingleSelection_GtkSingleSelection, getSelected, arginfo_gtk_gtk_gtksingleselection_gtksingleselection_getselected, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSingleSelection_GtkSingleSelection, getSelectedItem, arginfo_gtk_gtk_gtksingleselection_gtksingleselection_getselecteditem, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSingleSelection_GtkSingleSelection, setAutoselect, arginfo_gtk_gtk_gtksingleselection_gtksingleselection_setautoselect, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSingleSelection_GtkSingleSelection, setCanUnselect, arginfo_gtk_gtk_gtksingleselection_gtksingleselection_setcanunselect, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSingleSelection_GtkSingleSelection, setModel, arginfo_gtk_gtk_gtksingleselection_gtksingleselection_setmodel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSingleSelection_GtkSingleSelection, setSelected, arginfo_gtk_gtk_gtksingleselection_gtksingleselection_setselected, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
