
extern zend_class_entry *gtk_gtk_gtktext_gtktext_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkText_GtkText);

PHP_METHOD(Gtk_Gtk_GtkText_GtkText, new_);
PHP_METHOD(Gtk_Gtk_GtkText_GtkText, newWithBuffer);
PHP_METHOD(Gtk_Gtk_GtkText_GtkText, computeCursorExtents);
PHP_METHOD(Gtk_Gtk_GtkText_GtkText, getActivatesDefault);
PHP_METHOD(Gtk_Gtk_GtkText_GtkText, getBuffer);
PHP_METHOD(Gtk_Gtk_GtkText_GtkText, getEnableEmojiCompletion);
PHP_METHOD(Gtk_Gtk_GtkText_GtkText, getExtraMenu);
PHP_METHOD(Gtk_Gtk_GtkText_GtkText, getInputHints);
PHP_METHOD(Gtk_Gtk_GtkText_GtkText, getInputPurpose);
PHP_METHOD(Gtk_Gtk_GtkText_GtkText, getInvisibleChar);
PHP_METHOD(Gtk_Gtk_GtkText_GtkText, getMaxLength);
PHP_METHOD(Gtk_Gtk_GtkText_GtkText, getOverwriteMode);
PHP_METHOD(Gtk_Gtk_GtkText_GtkText, getPlaceholderText);
PHP_METHOD(Gtk_Gtk_GtkText_GtkText, getPropagateTextWidth);
PHP_METHOD(Gtk_Gtk_GtkText_GtkText, getTextLength);
PHP_METHOD(Gtk_Gtk_GtkText_GtkText, getTruncateMultiline);
PHP_METHOD(Gtk_Gtk_GtkText_GtkText, getVisibility);
PHP_METHOD(Gtk_Gtk_GtkText_GtkText, grabFocusWithoutSelecting);
PHP_METHOD(Gtk_Gtk_GtkText_GtkText, setActivatesDefault);
PHP_METHOD(Gtk_Gtk_GtkText_GtkText, setBuffer);
PHP_METHOD(Gtk_Gtk_GtkText_GtkText, setEnableEmojiCompletion);
PHP_METHOD(Gtk_Gtk_GtkText_GtkText, setExtraMenu);
PHP_METHOD(Gtk_Gtk_GtkText_GtkText, setInputHints);
PHP_METHOD(Gtk_Gtk_GtkText_GtkText, setInputPurpose);
PHP_METHOD(Gtk_Gtk_GtkText_GtkText, setInvisibleChar);
PHP_METHOD(Gtk_Gtk_GtkText_GtkText, setMaxLength);
PHP_METHOD(Gtk_Gtk_GtkText_GtkText, setOverwriteMode);
PHP_METHOD(Gtk_Gtk_GtkText_GtkText, setPlaceholderText);
PHP_METHOD(Gtk_Gtk_GtkText_GtkText, setPropagateTextWidth);
PHP_METHOD(Gtk_Gtk_GtkText_GtkText, setTruncateMultiline);
PHP_METHOD(Gtk_Gtk_GtkText_GtkText, setVisibility);
PHP_METHOD(Gtk_Gtk_GtkText_GtkText, unsetInvisibleChar);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktext_gtktext_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktext_gtktext_newwithbuffer, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, buffer, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktext_gtktext_computecursorextents, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktext_gtktext_getactivatesdefault, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktext_gtktext_getbuffer, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktext_gtktext_getenableemojicompletion, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktext_gtktext_getextramenu, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktext_gtktext_getinputhints, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktext_gtktext_getinputpurpose, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktext_gtktext_getinvisiblechar, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktext_gtktext_getmaxlength, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktext_gtktext_getoverwritemode, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtktext_gtktext_getplaceholdertext, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktext_gtktext_getpropagatetextwidth, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktext_gtktext_gettextlength, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktext_gtktext_gettruncatemultiline, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktext_gtktext_getvisibility, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktext_gtktext_grabfocuswithoutselecting, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktext_gtktext_setactivatesdefault, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, activates, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktext_gtktext_setbuffer, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, buffer, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktext_gtktext_setenableemojicompletion, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, enableEmojiCompletion, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktext_gtktext_setextramenu, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, model, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktext_gtktext_setinputhints, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, hints, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktext_gtktext_setinputpurpose, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, purpose, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktext_gtktext_setinvisiblechar, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ch, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktext_gtktext_setmaxlength, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, length, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktext_gtktext_setoverwritemode, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, overwrite, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktext_gtktext_setplaceholdertext, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktext_gtktext_setpropagatetextwidth, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, propagateTextWidth, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktext_gtktext_settruncatemultiline, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, truncateMultiline, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktext_gtktext_setvisibility, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, visible, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktext_gtktext_unsetinvisiblechar, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtktext_gtktext_method_entry) {
	PHP_ME(Gtk_Gtk_GtkText_GtkText, new_, arginfo_gtk_gtk_gtktext_gtktext_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkText_GtkText, newWithBuffer, arginfo_gtk_gtk_gtktext_gtktext_newwithbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkText_GtkText, computeCursorExtents, arginfo_gtk_gtk_gtktext_gtktext_computecursorextents, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkText_GtkText, getActivatesDefault, arginfo_gtk_gtk_gtktext_gtktext_getactivatesdefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkText_GtkText, getBuffer, arginfo_gtk_gtk_gtktext_gtktext_getbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkText_GtkText, getEnableEmojiCompletion, arginfo_gtk_gtk_gtktext_gtktext_getenableemojicompletion, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkText_GtkText, getExtraMenu, arginfo_gtk_gtk_gtktext_gtktext_getextramenu, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkText_GtkText, getInputHints, arginfo_gtk_gtk_gtktext_gtktext_getinputhints, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkText_GtkText, getInputPurpose, arginfo_gtk_gtk_gtktext_gtktext_getinputpurpose, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkText_GtkText, getInvisibleChar, arginfo_gtk_gtk_gtktext_gtktext_getinvisiblechar, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkText_GtkText, getMaxLength, arginfo_gtk_gtk_gtktext_gtktext_getmaxlength, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkText_GtkText, getOverwriteMode, arginfo_gtk_gtk_gtktext_gtktext_getoverwritemode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkText_GtkText, getPlaceholderText, arginfo_gtk_gtk_gtktext_gtktext_getplaceholdertext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkText_GtkText, getPropagateTextWidth, arginfo_gtk_gtk_gtktext_gtktext_getpropagatetextwidth, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkText_GtkText, getTextLength, arginfo_gtk_gtk_gtktext_gtktext_gettextlength, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkText_GtkText, getTruncateMultiline, arginfo_gtk_gtk_gtktext_gtktext_gettruncatemultiline, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkText_GtkText, getVisibility, arginfo_gtk_gtk_gtktext_gtktext_getvisibility, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkText_GtkText, grabFocusWithoutSelecting, arginfo_gtk_gtk_gtktext_gtktext_grabfocuswithoutselecting, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkText_GtkText, setActivatesDefault, arginfo_gtk_gtk_gtktext_gtktext_setactivatesdefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkText_GtkText, setBuffer, arginfo_gtk_gtk_gtktext_gtktext_setbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkText_GtkText, setEnableEmojiCompletion, arginfo_gtk_gtk_gtktext_gtktext_setenableemojicompletion, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkText_GtkText, setExtraMenu, arginfo_gtk_gtk_gtktext_gtktext_setextramenu, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkText_GtkText, setInputHints, arginfo_gtk_gtk_gtktext_gtktext_setinputhints, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkText_GtkText, setInputPurpose, arginfo_gtk_gtk_gtktext_gtktext_setinputpurpose, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkText_GtkText, setInvisibleChar, arginfo_gtk_gtk_gtktext_gtktext_setinvisiblechar, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkText_GtkText, setMaxLength, arginfo_gtk_gtk_gtktext_gtktext_setmaxlength, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkText_GtkText, setOverwriteMode, arginfo_gtk_gtk_gtktext_gtktext_setoverwritemode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkText_GtkText, setPlaceholderText, arginfo_gtk_gtk_gtktext_gtktext_setplaceholdertext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkText_GtkText, setPropagateTextWidth, arginfo_gtk_gtk_gtktext_gtktext_setpropagatetextwidth, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkText_GtkText, setTruncateMultiline, arginfo_gtk_gtk_gtktext_gtktext_settruncatemultiline, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkText_GtkText, setVisibility, arginfo_gtk_gtk_gtktext_gtktext_setvisibility, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkText_GtkText, unsetInvisibleChar, arginfo_gtk_gtk_gtktext_gtktext_unsetinvisiblechar, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
