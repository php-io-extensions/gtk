
extern zend_class_entry *gtk_gtk_gtklistbox_gtklistbox_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkListBox_GtkListBox);

PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, new_);
PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, append);
PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, dragHighlightRow);
PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, dragUnhighlightRow);
PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, getActivateOnSingleClick);
PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, getAdjustment);
PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, getRowAtIndex);
PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, getRowAtY);
PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, getSelectedRow);
PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, getSelectedRows);
PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, getSelectionMode);
PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, getShowSeparators);
PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, getTabBehavior);
PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, insert);
PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, invalidateFilter);
PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, invalidateHeaders);
PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, invalidateSort);
PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, prepend);
PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, remove);
PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, removeAll);
PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, selectAll);
PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, selectRow);
PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, setActivateOnSingleClick);
PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, setAdjustment);
PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, setPlaceholder);
PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, setSelectionMode);
PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, setShowSeparators);
PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, setTabBehavior);
PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, unselectAll);
PHP_METHOD(Gtk_Gtk_GtkListBox_GtkListBox, unselectRow);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistbox_gtklistbox_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistbox_gtklistbox_append, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistbox_gtklistbox_draghighlightrow, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, row, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistbox_gtklistbox_dragunhighlightrow, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistbox_gtklistbox_getactivateonsingleclick, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistbox_gtklistbox_getadjustment, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistbox_gtklistbox_getrowatindex, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistbox_gtklistbox_getrowaty, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistbox_gtklistbox_getselectedrow, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistbox_gtklistbox_getselectedrows, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistbox_gtklistbox_getselectionmode, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistbox_gtklistbox_getshowseparators, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistbox_gtklistbox_gettabbehavior, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistbox_gtklistbox_insert, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistbox_gtklistbox_invalidatefilter, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistbox_gtklistbox_invalidateheaders, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistbox_gtklistbox_invalidatesort, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistbox_gtklistbox_prepend, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistbox_gtklistbox_remove, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistbox_gtklistbox_removeall, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistbox_gtklistbox_selectall, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistbox_gtklistbox_selectrow, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, row, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistbox_gtklistbox_setactivateonsingleclick, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, single, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistbox_gtklistbox_setadjustment, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, adjustment, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistbox_gtklistbox_setplaceholder, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, placeholder, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistbox_gtklistbox_setselectionmode, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistbox_gtklistbox_setshowseparators, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, showSeparators, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistbox_gtklistbox_settabbehavior, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, behavior, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistbox_gtklistbox_unselectall, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistbox_gtklistbox_unselectrow, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, row, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtklistbox_gtklistbox_method_entry) {
	PHP_ME(Gtk_Gtk_GtkListBox_GtkListBox, new_, arginfo_gtk_gtk_gtklistbox_gtklistbox_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBox_GtkListBox, append, arginfo_gtk_gtk_gtklistbox_gtklistbox_append, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBox_GtkListBox, dragHighlightRow, arginfo_gtk_gtk_gtklistbox_gtklistbox_draghighlightrow, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBox_GtkListBox, dragUnhighlightRow, arginfo_gtk_gtk_gtklistbox_gtklistbox_dragunhighlightrow, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBox_GtkListBox, getActivateOnSingleClick, arginfo_gtk_gtk_gtklistbox_gtklistbox_getactivateonsingleclick, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBox_GtkListBox, getAdjustment, arginfo_gtk_gtk_gtklistbox_gtklistbox_getadjustment, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBox_GtkListBox, getRowAtIndex, arginfo_gtk_gtk_gtklistbox_gtklistbox_getrowatindex, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBox_GtkListBox, getRowAtY, arginfo_gtk_gtk_gtklistbox_gtklistbox_getrowaty, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBox_GtkListBox, getSelectedRow, arginfo_gtk_gtk_gtklistbox_gtklistbox_getselectedrow, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBox_GtkListBox, getSelectedRows, arginfo_gtk_gtk_gtklistbox_gtklistbox_getselectedrows, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBox_GtkListBox, getSelectionMode, arginfo_gtk_gtk_gtklistbox_gtklistbox_getselectionmode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBox_GtkListBox, getShowSeparators, arginfo_gtk_gtk_gtklistbox_gtklistbox_getshowseparators, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBox_GtkListBox, getTabBehavior, arginfo_gtk_gtk_gtklistbox_gtklistbox_gettabbehavior, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBox_GtkListBox, insert, arginfo_gtk_gtk_gtklistbox_gtklistbox_insert, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBox_GtkListBox, invalidateFilter, arginfo_gtk_gtk_gtklistbox_gtklistbox_invalidatefilter, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBox_GtkListBox, invalidateHeaders, arginfo_gtk_gtk_gtklistbox_gtklistbox_invalidateheaders, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBox_GtkListBox, invalidateSort, arginfo_gtk_gtk_gtklistbox_gtklistbox_invalidatesort, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBox_GtkListBox, prepend, arginfo_gtk_gtk_gtklistbox_gtklistbox_prepend, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBox_GtkListBox, remove, arginfo_gtk_gtk_gtklistbox_gtklistbox_remove, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBox_GtkListBox, removeAll, arginfo_gtk_gtk_gtklistbox_gtklistbox_removeall, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBox_GtkListBox, selectAll, arginfo_gtk_gtk_gtklistbox_gtklistbox_selectall, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBox_GtkListBox, selectRow, arginfo_gtk_gtk_gtklistbox_gtklistbox_selectrow, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBox_GtkListBox, setActivateOnSingleClick, arginfo_gtk_gtk_gtklistbox_gtklistbox_setactivateonsingleclick, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBox_GtkListBox, setAdjustment, arginfo_gtk_gtk_gtklistbox_gtklistbox_setadjustment, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBox_GtkListBox, setPlaceholder, arginfo_gtk_gtk_gtklistbox_gtklistbox_setplaceholder, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBox_GtkListBox, setSelectionMode, arginfo_gtk_gtk_gtklistbox_gtklistbox_setselectionmode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBox_GtkListBox, setShowSeparators, arginfo_gtk_gtk_gtklistbox_gtklistbox_setshowseparators, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBox_GtkListBox, setTabBehavior, arginfo_gtk_gtk_gtklistbox_gtklistbox_settabbehavior, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBox_GtkListBox, unselectAll, arginfo_gtk_gtk_gtklistbox_gtklistbox_unselectall, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBox_GtkListBox, unselectRow, arginfo_gtk_gtk_gtklistbox_gtklistbox_unselectrow, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
