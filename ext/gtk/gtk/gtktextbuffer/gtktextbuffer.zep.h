
extern zend_class_entry *gtk_gtk_gtktextbuffer_gtktextbuffer_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer);

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, new_);
PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, addSelectionClipboard);
PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, beginIrreversibleAction);
PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, beginUserAction);
PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, copyClipboard);
PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, cutClipboard);
PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, deleteMark);
PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, deleteMarkByName);
PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, deleteSelection);
PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, endIrreversibleAction);
PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, endUserAction);
PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getCanRedo);
PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getCanUndo);
PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getCharCount);
PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getEnableUndo);
PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getHasSelection);
PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getInsert);
PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getLineCount);
PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getMark);
PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getMaxUndoLevels);
PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getModified);
PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getSelectionBound);
PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getTagTable);
PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, insertAtCursor);
PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, insertInteractiveAtCursor);
PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, redo);
PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, removeCommitNotify);
PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, removeSelectionClipboard);
PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, setEnableUndo);
PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, setMaxUndoLevels);
PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, setModified);
PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, setText);
PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, undo);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_new_, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, table, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_addselectionclipboard, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, clipboard, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_beginirreversibleaction, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_beginuseraction, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_copyclipboard, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, clipboard, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_cutclipboard, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, clipboard, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, defaultEditable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_deletemark, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, mark, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_deletemarkbyname, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_deleteselection, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, interactive, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, defaultEditable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_endirreversibleaction, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_enduseraction, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_getcanredo, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_getcanundo, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_getcharcount, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_getenableundo, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_gethasselection, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_getinsert, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_getlinecount, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_getmark, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_getmaxundolevels, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_getmodified, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_getselectionbound, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_gettagtable, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_insertatcursor, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, len, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_insertinteractiveatcursor, 0, 4, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, len, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, defaultEditable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_redo, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_removecommitnotify, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, commitNotifyHandler, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_removeselectionclipboard, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, clipboard, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_setenableundo, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, enableUndo, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_setmaxundolevels, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, maxUndoLevels, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_setmodified, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, setting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_settext, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, len, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_undo, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtktextbuffer_gtktextbuffer_method_entry) {
	PHP_ME(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, new_, arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, addSelectionClipboard, arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_addselectionclipboard, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, beginIrreversibleAction, arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_beginirreversibleaction, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, beginUserAction, arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_beginuseraction, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, copyClipboard, arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_copyclipboard, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, cutClipboard, arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_cutclipboard, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, deleteMark, arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_deletemark, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, deleteMarkByName, arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_deletemarkbyname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, deleteSelection, arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_deleteselection, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, endIrreversibleAction, arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_endirreversibleaction, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, endUserAction, arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_enduseraction, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getCanRedo, arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_getcanredo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getCanUndo, arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_getcanundo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getCharCount, arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_getcharcount, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getEnableUndo, arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_getenableundo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getHasSelection, arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_gethasselection, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getInsert, arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_getinsert, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getLineCount, arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_getlinecount, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getMark, arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_getmark, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getMaxUndoLevels, arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_getmaxundolevels, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getModified, arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_getmodified, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getSelectionBound, arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_getselectionbound, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getTagTable, arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_gettagtable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, insertAtCursor, arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_insertatcursor, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, insertInteractiveAtCursor, arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_insertinteractiveatcursor, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, redo, arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_redo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, removeCommitNotify, arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_removecommitnotify, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, removeSelectionClipboard, arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_removeselectionclipboard, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, setEnableUndo, arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_setenableundo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, setMaxUndoLevels, arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_setmaxundolevels, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, setModified, arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_setmodified, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, setText, arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_settext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, undo, arginfo_gtk_gtk_gtktextbuffer_gtktextbuffer_undo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
