
extern zend_class_entry *gtk_gtk_gtkeditable_gtkeditable_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkEditable_GtkEditable);

PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, delegateGetAccessiblePlatformState);
PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, deleteSelection);
PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, deleteText);
PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, finishDelegate);
PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, getAlignment);
PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, getChars);
PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, getDelegate);
PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, getEditable);
PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, getEnableUndo);
PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, getMaxWidthChars);
PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, getPosition);
PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, getSelectionBounds);
PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, getText);
PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, getWidthChars);
PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, initDelegate);
PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, insertText);
PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, selectRegion);
PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, setAlignment);
PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, setEditable);
PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, setEnableUndo);
PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, setMaxWidthChars);
PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, setPosition);
PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, setText);
PHP_METHOD(Gtk_Gtk_GtkEditable_GtkEditable, setWidthChars);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkeditable_gtkeditable_delegategetaccessibleplatformstate, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, state, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkeditable_gtkeditable_deleteselection, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkeditable_gtkeditable_deletetext, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, startPos, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, endPos, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkeditable_gtkeditable_finishdelegate, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkeditable_gtkeditable_getalignment, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkeditable_gtkeditable_getchars, 0, 0, 3)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, startPos, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, endPos, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkeditable_gtkeditable_getdelegate, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkeditable_gtkeditable_geteditable, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkeditable_gtkeditable_getenableundo, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkeditable_gtkeditable_getmaxwidthchars, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkeditable_gtkeditable_getposition, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkeditable_gtkeditable_getselectionbounds, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkeditable_gtkeditable_gettext, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkeditable_gtkeditable_getwidthchars, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkeditable_gtkeditable_initdelegate, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkeditable_gtkeditable_inserttext, 0, 4, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, length, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkeditable_gtkeditable_selectregion, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, startPos, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, endPos, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkeditable_gtkeditable_setalignment, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, xalign, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkeditable_gtkeditable_seteditable, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, isEditable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkeditable_gtkeditable_setenableundo, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, enableUndo, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkeditable_gtkeditable_setmaxwidthchars, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, nChars, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkeditable_gtkeditable_setposition, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkeditable_gtkeditable_settext, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkeditable_gtkeditable_setwidthchars, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, nChars, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkeditable_gtkeditable_method_entry) {
	PHP_ME(Gtk_Gtk_GtkEditable_GtkEditable, delegateGetAccessiblePlatformState, arginfo_gtk_gtk_gtkeditable_gtkeditable_delegategetaccessibleplatformstate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEditable_GtkEditable, deleteSelection, arginfo_gtk_gtk_gtkeditable_gtkeditable_deleteselection, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEditable_GtkEditable, deleteText, arginfo_gtk_gtk_gtkeditable_gtkeditable_deletetext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEditable_GtkEditable, finishDelegate, arginfo_gtk_gtk_gtkeditable_gtkeditable_finishdelegate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEditable_GtkEditable, getAlignment, arginfo_gtk_gtk_gtkeditable_gtkeditable_getalignment, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEditable_GtkEditable, getChars, arginfo_gtk_gtk_gtkeditable_gtkeditable_getchars, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEditable_GtkEditable, getDelegate, arginfo_gtk_gtk_gtkeditable_gtkeditable_getdelegate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEditable_GtkEditable, getEditable, arginfo_gtk_gtk_gtkeditable_gtkeditable_geteditable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEditable_GtkEditable, getEnableUndo, arginfo_gtk_gtk_gtkeditable_gtkeditable_getenableundo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEditable_GtkEditable, getMaxWidthChars, arginfo_gtk_gtk_gtkeditable_gtkeditable_getmaxwidthchars, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEditable_GtkEditable, getPosition, arginfo_gtk_gtk_gtkeditable_gtkeditable_getposition, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEditable_GtkEditable, getSelectionBounds, arginfo_gtk_gtk_gtkeditable_gtkeditable_getselectionbounds, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEditable_GtkEditable, getText, arginfo_gtk_gtk_gtkeditable_gtkeditable_gettext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEditable_GtkEditable, getWidthChars, arginfo_gtk_gtk_gtkeditable_gtkeditable_getwidthchars, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEditable_GtkEditable, initDelegate, arginfo_gtk_gtk_gtkeditable_gtkeditable_initdelegate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEditable_GtkEditable, insertText, arginfo_gtk_gtk_gtkeditable_gtkeditable_inserttext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEditable_GtkEditable, selectRegion, arginfo_gtk_gtk_gtkeditable_gtkeditable_selectregion, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEditable_GtkEditable, setAlignment, arginfo_gtk_gtk_gtkeditable_gtkeditable_setalignment, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEditable_GtkEditable, setEditable, arginfo_gtk_gtk_gtkeditable_gtkeditable_seteditable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEditable_GtkEditable, setEnableUndo, arginfo_gtk_gtk_gtkeditable_gtkeditable_setenableundo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEditable_GtkEditable, setMaxWidthChars, arginfo_gtk_gtk_gtkeditable_gtkeditable_setmaxwidthchars, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEditable_GtkEditable, setPosition, arginfo_gtk_gtk_gtkeditable_gtkeditable_setposition, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEditable_GtkEditable, setText, arginfo_gtk_gtk_gtkeditable_gtkeditable_settext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEditable_GtkEditable, setWidthChars, arginfo_gtk_gtk_gtkeditable_gtkeditable_setwidthchars, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
