
extern zend_class_entry *gtk_gtk_gtkgrid_gtkgrid_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkGrid_GtkGrid);

PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, new_);
PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, attach);
PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, attachNextTo);
PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, getBaselineRow);
PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, getChildAt);
PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, getColumnHomogeneous);
PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, getColumnSpacing);
PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, getRowBaselinePosition);
PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, getRowHomogeneous);
PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, getRowSpacing);
PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, insertColumn);
PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, insertNextTo);
PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, insertRow);
PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, queryChild);
PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, remove);
PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, removeColumn);
PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, removeRow);
PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, setBaselineRow);
PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, setColumnHomogeneous);
PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, setColumnSpacing);
PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, setRowBaselinePosition);
PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, setRowHomogeneous);
PHP_METHOD(Gtk_Gtk_GtkGrid_GtkGrid, setRowSpacing);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgrid_gtkgrid_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgrid_gtkgrid_attach, 0, 6, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, column, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, row, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgrid_gtkgrid_attachnextto, 0, 6, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, sibling, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, side, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgrid_gtkgrid_getbaselinerow, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgrid_gtkgrid_getchildat, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, column, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, row, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgrid_gtkgrid_getcolumnhomogeneous, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgrid_gtkgrid_getcolumnspacing, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgrid_gtkgrid_getrowbaselineposition, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, row, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgrid_gtkgrid_getrowhomogeneous, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgrid_gtkgrid_getrowspacing, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgrid_gtkgrid_insertcolumn, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgrid_gtkgrid_insertnextto, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, sibling, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, side, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgrid_gtkgrid_insertrow, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgrid_gtkgrid_querychild, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgrid_gtkgrid_remove, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgrid_gtkgrid_removecolumn, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgrid_gtkgrid_removerow, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgrid_gtkgrid_setbaselinerow, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, row, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgrid_gtkgrid_setcolumnhomogeneous, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, homogeneous, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgrid_gtkgrid_setcolumnspacing, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, spacing, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgrid_gtkgrid_setrowbaselineposition, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, row, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pos, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgrid_gtkgrid_setrowhomogeneous, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, homogeneous, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgrid_gtkgrid_setrowspacing, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, spacing, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkgrid_gtkgrid_method_entry) {
	PHP_ME(Gtk_Gtk_GtkGrid_GtkGrid, new_, arginfo_gtk_gtk_gtkgrid_gtkgrid_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGrid_GtkGrid, attach, arginfo_gtk_gtk_gtkgrid_gtkgrid_attach, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGrid_GtkGrid, attachNextTo, arginfo_gtk_gtk_gtkgrid_gtkgrid_attachnextto, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGrid_GtkGrid, getBaselineRow, arginfo_gtk_gtk_gtkgrid_gtkgrid_getbaselinerow, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGrid_GtkGrid, getChildAt, arginfo_gtk_gtk_gtkgrid_gtkgrid_getchildat, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGrid_GtkGrid, getColumnHomogeneous, arginfo_gtk_gtk_gtkgrid_gtkgrid_getcolumnhomogeneous, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGrid_GtkGrid, getColumnSpacing, arginfo_gtk_gtk_gtkgrid_gtkgrid_getcolumnspacing, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGrid_GtkGrid, getRowBaselinePosition, arginfo_gtk_gtk_gtkgrid_gtkgrid_getrowbaselineposition, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGrid_GtkGrid, getRowHomogeneous, arginfo_gtk_gtk_gtkgrid_gtkgrid_getrowhomogeneous, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGrid_GtkGrid, getRowSpacing, arginfo_gtk_gtk_gtkgrid_gtkgrid_getrowspacing, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGrid_GtkGrid, insertColumn, arginfo_gtk_gtk_gtkgrid_gtkgrid_insertcolumn, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGrid_GtkGrid, insertNextTo, arginfo_gtk_gtk_gtkgrid_gtkgrid_insertnextto, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGrid_GtkGrid, insertRow, arginfo_gtk_gtk_gtkgrid_gtkgrid_insertrow, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGrid_GtkGrid, queryChild, arginfo_gtk_gtk_gtkgrid_gtkgrid_querychild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGrid_GtkGrid, remove, arginfo_gtk_gtk_gtkgrid_gtkgrid_remove, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGrid_GtkGrid, removeColumn, arginfo_gtk_gtk_gtkgrid_gtkgrid_removecolumn, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGrid_GtkGrid, removeRow, arginfo_gtk_gtk_gtkgrid_gtkgrid_removerow, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGrid_GtkGrid, setBaselineRow, arginfo_gtk_gtk_gtkgrid_gtkgrid_setbaselinerow, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGrid_GtkGrid, setColumnHomogeneous, arginfo_gtk_gtk_gtkgrid_gtkgrid_setcolumnhomogeneous, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGrid_GtkGrid, setColumnSpacing, arginfo_gtk_gtk_gtkgrid_gtkgrid_setcolumnspacing, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGrid_GtkGrid, setRowBaselinePosition, arginfo_gtk_gtk_gtkgrid_gtkgrid_setrowbaselineposition, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGrid_GtkGrid, setRowHomogeneous, arginfo_gtk_gtk_gtkgrid_gtkgrid_setrowhomogeneous, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGrid_GtkGrid, setRowSpacing, arginfo_gtk_gtk_gtkgrid_gtkgrid_setrowspacing, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
