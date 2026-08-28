
extern zend_class_entry *gtk_gtk_gtkentrybuffer_gtkentrybuffer_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer);

PHP_METHOD(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer, new_);
PHP_METHOD(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer, deleteText);
PHP_METHOD(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer, emitDeletedText);
PHP_METHOD(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer, emitInsertedText);
PHP_METHOD(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer, getBytes);
PHP_METHOD(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer, getLength);
PHP_METHOD(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer, getMaxLength);
PHP_METHOD(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer, getText);
PHP_METHOD(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer, insertText);
PHP_METHOD(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer, setMaxLength);
PHP_METHOD(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer, setText);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentrybuffer_gtkentrybuffer_new_, 0, 2, IS_LONG, 0)
	ZEND_ARG_INFO(0, initialChars)
	ZEND_ARG_TYPE_INFO(0, nInitialChars, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentrybuffer_gtkentrybuffer_deletetext, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, nChars, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentrybuffer_gtkentrybuffer_emitdeletedtext, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, nChars, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentrybuffer_gtkentrybuffer_emitinsertedtext, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, chars, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, nChars, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentrybuffer_gtkentrybuffer_getbytes, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentrybuffer_gtkentrybuffer_getlength, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentrybuffer_gtkentrybuffer_getmaxlength, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkentrybuffer_gtkentrybuffer_gettext, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentrybuffer_gtkentrybuffer_inserttext, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, chars, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, nChars, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentrybuffer_gtkentrybuffer_setmaxlength, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, maxLength, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentrybuffer_gtkentrybuffer_settext, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, chars, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, nChars, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkentrybuffer_gtkentrybuffer_method_entry) {
	PHP_ME(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer, new_, arginfo_gtk_gtk_gtkentrybuffer_gtkentrybuffer_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer, deleteText, arginfo_gtk_gtk_gtkentrybuffer_gtkentrybuffer_deletetext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer, emitDeletedText, arginfo_gtk_gtk_gtkentrybuffer_gtkentrybuffer_emitdeletedtext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer, emitInsertedText, arginfo_gtk_gtk_gtkentrybuffer_gtkentrybuffer_emitinsertedtext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer, getBytes, arginfo_gtk_gtk_gtkentrybuffer_gtkentrybuffer_getbytes, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer, getLength, arginfo_gtk_gtk_gtkentrybuffer_gtkentrybuffer_getlength, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer, getMaxLength, arginfo_gtk_gtk_gtkentrybuffer_gtkentrybuffer_getmaxlength, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer, getText, arginfo_gtk_gtk_gtkentrybuffer_gtkentrybuffer_gettext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer, insertText, arginfo_gtk_gtk_gtkentrybuffer_gtkentrybuffer_inserttext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer, setMaxLength, arginfo_gtk_gtk_gtkentrybuffer_gtkentrybuffer_setmaxlength, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer, setText, arginfo_gtk_gtk_gtkentrybuffer_gtkentrybuffer_settext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
