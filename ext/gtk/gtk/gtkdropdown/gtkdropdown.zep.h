
extern zend_class_entry *gtk_gtk_gtkdropdown_gtkdropdown_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkDropDown_GtkDropDown);

PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, new_);
PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, newFromStrings);
PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, getEnableSearch);
PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, getFactory);
PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, getHeaderFactory);
PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, getListFactory);
PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, getModel);
PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, getSearchMatchMode);
PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, getSelected);
PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, getSelectedItem);
PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, getShowArrow);
PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, setEnableSearch);
PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, setFactory);
PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, setHeaderFactory);
PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, setListFactory);
PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, setModel);
PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, setSearchMatchMode);
PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, setSelected);
PHP_METHOD(Gtk_Gtk_GtkDropDown_GtkDropDown, setShowArrow);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkdropdown_gtkdropdown_new_, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, model, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkdropdown_gtkdropdown_newfromstrings, 0, 1, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, strings, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkdropdown_gtkdropdown_getenablesearch, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkdropdown_gtkdropdown_getfactory, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkdropdown_gtkdropdown_getheaderfactory, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkdropdown_gtkdropdown_getlistfactory, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkdropdown_gtkdropdown_getmodel, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkdropdown_gtkdropdown_getsearchmatchmode, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkdropdown_gtkdropdown_getselected, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkdropdown_gtkdropdown_getselecteditem, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkdropdown_gtkdropdown_getshowarrow, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkdropdown_gtkdropdown_setenablesearch, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, enableSearch, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkdropdown_gtkdropdown_setfactory, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, factory, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkdropdown_gtkdropdown_setheaderfactory, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, factory, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkdropdown_gtkdropdown_setlistfactory, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, factory, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkdropdown_gtkdropdown_setmodel, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, model, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkdropdown_gtkdropdown_setsearchmatchmode, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, searchMatchMode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkdropdown_gtkdropdown_setselected, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkdropdown_gtkdropdown_setshowarrow, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, showArrow, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkdropdown_gtkdropdown_method_entry) {
	PHP_ME(Gtk_Gtk_GtkDropDown_GtkDropDown, new_, arginfo_gtk_gtk_gtkdropdown_gtkdropdown_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkDropDown_GtkDropDown, newFromStrings, arginfo_gtk_gtk_gtkdropdown_gtkdropdown_newfromstrings, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkDropDown_GtkDropDown, getEnableSearch, arginfo_gtk_gtk_gtkdropdown_gtkdropdown_getenablesearch, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkDropDown_GtkDropDown, getFactory, arginfo_gtk_gtk_gtkdropdown_gtkdropdown_getfactory, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkDropDown_GtkDropDown, getHeaderFactory, arginfo_gtk_gtk_gtkdropdown_gtkdropdown_getheaderfactory, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkDropDown_GtkDropDown, getListFactory, arginfo_gtk_gtk_gtkdropdown_gtkdropdown_getlistfactory, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkDropDown_GtkDropDown, getModel, arginfo_gtk_gtk_gtkdropdown_gtkdropdown_getmodel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkDropDown_GtkDropDown, getSearchMatchMode, arginfo_gtk_gtk_gtkdropdown_gtkdropdown_getsearchmatchmode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkDropDown_GtkDropDown, getSelected, arginfo_gtk_gtk_gtkdropdown_gtkdropdown_getselected, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkDropDown_GtkDropDown, getSelectedItem, arginfo_gtk_gtk_gtkdropdown_gtkdropdown_getselecteditem, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkDropDown_GtkDropDown, getShowArrow, arginfo_gtk_gtk_gtkdropdown_gtkdropdown_getshowarrow, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkDropDown_GtkDropDown, setEnableSearch, arginfo_gtk_gtk_gtkdropdown_gtkdropdown_setenablesearch, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkDropDown_GtkDropDown, setFactory, arginfo_gtk_gtk_gtkdropdown_gtkdropdown_setfactory, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkDropDown_GtkDropDown, setHeaderFactory, arginfo_gtk_gtk_gtkdropdown_gtkdropdown_setheaderfactory, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkDropDown_GtkDropDown, setListFactory, arginfo_gtk_gtk_gtkdropdown_gtkdropdown_setlistfactory, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkDropDown_GtkDropDown, setModel, arginfo_gtk_gtk_gtkdropdown_gtkdropdown_setmodel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkDropDown_GtkDropDown, setSearchMatchMode, arginfo_gtk_gtk_gtkdropdown_gtkdropdown_setsearchmatchmode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkDropDown_GtkDropDown, setSelected, arginfo_gtk_gtk_gtkdropdown_gtkdropdown_setselected, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkDropDown_GtkDropDown, setShowArrow, arginfo_gtk_gtk_gtkdropdown_gtkdropdown_setshowarrow, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
