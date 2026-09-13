
extern zend_class_entry *gtk_gtk_gtkcolumnview_gtkcolumnview_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkColumnView_GtkColumnView);

PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, new_);
PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, appendColumn);
PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, getColumns);
PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, getEnableRubberband);
PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, getHeaderFactory);
PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, getModel);
PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, getReorderable);
PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, getRowFactory);
PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, getShowColumnSeparators);
PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, getShowRowSeparators);
PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, getSingleClickActivate);
PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, getTabBehavior);
PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, insertColumn);
PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, removeColumn);
PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, setEnableRubberband);
PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, setHeaderFactory);
PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, setModel);
PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, setReorderable);
PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, setRowFactory);
PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, setShowColumnSeparators);
PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, setShowRowSeparators);
PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, setSingleClickActivate);
PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, setTabBehavior);
PHP_METHOD(Gtk_Gtk_GtkColumnView_GtkColumnView, sortByColumn);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_new_, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, model, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_appendcolumn, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, column, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_getcolumns, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_getenablerubberband, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_getheaderfactory, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_getmodel, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_getreorderable, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_getrowfactory, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_getshowcolumnseparators, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_getshowrowseparators, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_getsingleclickactivate, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_gettabbehavior, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_insertcolumn, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, column, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_removecolumn, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, column, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_setenablerubberband, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, enableRubberband, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_setheaderfactory, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, factory, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_setmodel, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, model, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_setreorderable, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, reorderable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_setrowfactory, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, factory, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_setshowcolumnseparators, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, showColumnSeparators, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_setshowrowseparators, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, showRowSeparators, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_setsingleclickactivate, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, singleClickActivate, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_settabbehavior, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, tabBehavior, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_sortbycolumn, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, column, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, direction, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkcolumnview_gtkcolumnview_method_entry) {
	PHP_ME(Gtk_Gtk_GtkColumnView_GtkColumnView, new_, arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnView_GtkColumnView, appendColumn, arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_appendcolumn, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnView_GtkColumnView, getColumns, arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_getcolumns, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnView_GtkColumnView, getEnableRubberband, arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_getenablerubberband, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnView_GtkColumnView, getHeaderFactory, arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_getheaderfactory, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnView_GtkColumnView, getModel, arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_getmodel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnView_GtkColumnView, getReorderable, arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_getreorderable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnView_GtkColumnView, getRowFactory, arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_getrowfactory, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnView_GtkColumnView, getShowColumnSeparators, arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_getshowcolumnseparators, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnView_GtkColumnView, getShowRowSeparators, arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_getshowrowseparators, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnView_GtkColumnView, getSingleClickActivate, arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_getsingleclickactivate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnView_GtkColumnView, getTabBehavior, arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_gettabbehavior, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnView_GtkColumnView, insertColumn, arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_insertcolumn, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnView_GtkColumnView, removeColumn, arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_removecolumn, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnView_GtkColumnView, setEnableRubberband, arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_setenablerubberband, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnView_GtkColumnView, setHeaderFactory, arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_setheaderfactory, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnView_GtkColumnView, setModel, arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_setmodel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnView_GtkColumnView, setReorderable, arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_setreorderable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnView_GtkColumnView, setRowFactory, arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_setrowfactory, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnView_GtkColumnView, setShowColumnSeparators, arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_setshowcolumnseparators, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnView_GtkColumnView, setShowRowSeparators, arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_setshowrowseparators, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnView_GtkColumnView, setSingleClickActivate, arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_setsingleclickactivate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnView_GtkColumnView, setTabBehavior, arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_settabbehavior, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnView_GtkColumnView, sortByColumn, arginfo_gtk_gtk_gtkcolumnview_gtkcolumnview_sortbycolumn, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
