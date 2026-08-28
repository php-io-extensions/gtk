
extern zend_class_entry *gtk_gtk_gtkflowbox_gtkflowbox_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkFlowBox_GtkFlowBox);

PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, new_);
PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, append);
PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, getActivateOnSingleClick);
PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, getChildAtIndex);
PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, getChildAtPos);
PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, getColumnSpacing);
PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, getHomogeneous);
PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, getMaxChildrenPerLine);
PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, getMinChildrenPerLine);
PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, getRowSpacing);
PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, getSelectedChildren);
PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, getSelectionMode);
PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, insert);
PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, invalidateFilter);
PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, invalidateSort);
PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, prepend);
PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, remove);
PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, removeAll);
PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, selectAll);
PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, selectChild);
PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, setActivateOnSingleClick);
PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, setColumnSpacing);
PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, setHadjustment);
PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, setHomogeneous);
PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, setMaxChildrenPerLine);
PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, setMinChildrenPerLine);
PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, setRowSpacing);
PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, setSelectionMode);
PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, setVadjustment);
PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, unselectAll);
PHP_METHOD(Gtk_Gtk_GtkFlowBox_GtkFlowBox, unselectChild);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowbox_gtkflowbox_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowbox_gtkflowbox_append, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowbox_gtkflowbox_getactivateonsingleclick, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowbox_gtkflowbox_getchildatindex, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, idx, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowbox_gtkflowbox_getchildatpos, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowbox_gtkflowbox_getcolumnspacing, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowbox_gtkflowbox_gethomogeneous, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowbox_gtkflowbox_getmaxchildrenperline, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowbox_gtkflowbox_getminchildrenperline, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowbox_gtkflowbox_getrowspacing, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowbox_gtkflowbox_getselectedchildren, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowbox_gtkflowbox_getselectionmode, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowbox_gtkflowbox_insert, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, widget, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowbox_gtkflowbox_invalidatefilter, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowbox_gtkflowbox_invalidatesort, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowbox_gtkflowbox_prepend, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowbox_gtkflowbox_remove, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, widget, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowbox_gtkflowbox_removeall, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowbox_gtkflowbox_selectall, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowbox_gtkflowbox_selectchild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowbox_gtkflowbox_setactivateonsingleclick, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, single, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowbox_gtkflowbox_setcolumnspacing, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, spacing, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowbox_gtkflowbox_sethadjustment, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, adjustment, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowbox_gtkflowbox_sethomogeneous, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, homogeneous, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowbox_gtkflowbox_setmaxchildrenperline, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, nChildren, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowbox_gtkflowbox_setminchildrenperline, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, nChildren, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowbox_gtkflowbox_setrowspacing, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, spacing, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowbox_gtkflowbox_setselectionmode, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowbox_gtkflowbox_setvadjustment, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, adjustment, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowbox_gtkflowbox_unselectall, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowbox_gtkflowbox_unselectchild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkflowbox_gtkflowbox_method_entry) {
	PHP_ME(Gtk_Gtk_GtkFlowBox_GtkFlowBox, new_, arginfo_gtk_gtk_gtkflowbox_gtkflowbox_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBox_GtkFlowBox, append, arginfo_gtk_gtk_gtkflowbox_gtkflowbox_append, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBox_GtkFlowBox, getActivateOnSingleClick, arginfo_gtk_gtk_gtkflowbox_gtkflowbox_getactivateonsingleclick, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBox_GtkFlowBox, getChildAtIndex, arginfo_gtk_gtk_gtkflowbox_gtkflowbox_getchildatindex, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBox_GtkFlowBox, getChildAtPos, arginfo_gtk_gtk_gtkflowbox_gtkflowbox_getchildatpos, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBox_GtkFlowBox, getColumnSpacing, arginfo_gtk_gtk_gtkflowbox_gtkflowbox_getcolumnspacing, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBox_GtkFlowBox, getHomogeneous, arginfo_gtk_gtk_gtkflowbox_gtkflowbox_gethomogeneous, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBox_GtkFlowBox, getMaxChildrenPerLine, arginfo_gtk_gtk_gtkflowbox_gtkflowbox_getmaxchildrenperline, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBox_GtkFlowBox, getMinChildrenPerLine, arginfo_gtk_gtk_gtkflowbox_gtkflowbox_getminchildrenperline, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBox_GtkFlowBox, getRowSpacing, arginfo_gtk_gtk_gtkflowbox_gtkflowbox_getrowspacing, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBox_GtkFlowBox, getSelectedChildren, arginfo_gtk_gtk_gtkflowbox_gtkflowbox_getselectedchildren, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBox_GtkFlowBox, getSelectionMode, arginfo_gtk_gtk_gtkflowbox_gtkflowbox_getselectionmode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBox_GtkFlowBox, insert, arginfo_gtk_gtk_gtkflowbox_gtkflowbox_insert, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBox_GtkFlowBox, invalidateFilter, arginfo_gtk_gtk_gtkflowbox_gtkflowbox_invalidatefilter, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBox_GtkFlowBox, invalidateSort, arginfo_gtk_gtk_gtkflowbox_gtkflowbox_invalidatesort, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBox_GtkFlowBox, prepend, arginfo_gtk_gtk_gtkflowbox_gtkflowbox_prepend, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBox_GtkFlowBox, remove, arginfo_gtk_gtk_gtkflowbox_gtkflowbox_remove, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBox_GtkFlowBox, removeAll, arginfo_gtk_gtk_gtkflowbox_gtkflowbox_removeall, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBox_GtkFlowBox, selectAll, arginfo_gtk_gtk_gtkflowbox_gtkflowbox_selectall, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBox_GtkFlowBox, selectChild, arginfo_gtk_gtk_gtkflowbox_gtkflowbox_selectchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBox_GtkFlowBox, setActivateOnSingleClick, arginfo_gtk_gtk_gtkflowbox_gtkflowbox_setactivateonsingleclick, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBox_GtkFlowBox, setColumnSpacing, arginfo_gtk_gtk_gtkflowbox_gtkflowbox_setcolumnspacing, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBox_GtkFlowBox, setHadjustment, arginfo_gtk_gtk_gtkflowbox_gtkflowbox_sethadjustment, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBox_GtkFlowBox, setHomogeneous, arginfo_gtk_gtk_gtkflowbox_gtkflowbox_sethomogeneous, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBox_GtkFlowBox, setMaxChildrenPerLine, arginfo_gtk_gtk_gtkflowbox_gtkflowbox_setmaxchildrenperline, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBox_GtkFlowBox, setMinChildrenPerLine, arginfo_gtk_gtk_gtkflowbox_gtkflowbox_setminchildrenperline, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBox_GtkFlowBox, setRowSpacing, arginfo_gtk_gtk_gtkflowbox_gtkflowbox_setrowspacing, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBox_GtkFlowBox, setSelectionMode, arginfo_gtk_gtk_gtkflowbox_gtkflowbox_setselectionmode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBox_GtkFlowBox, setVadjustment, arginfo_gtk_gtk_gtkflowbox_gtkflowbox_setvadjustment, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBox_GtkFlowBox, unselectAll, arginfo_gtk_gtk_gtkflowbox_gtkflowbox_unselectall, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBox_GtkFlowBox, unselectChild, arginfo_gtk_gtk_gtkflowbox_gtkflowbox_unselectchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
