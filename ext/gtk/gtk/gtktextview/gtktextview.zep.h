
extern zend_class_entry *gtk_gtk_gtktextview_gtktextview_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkTextView_GtkTextView);

PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, new_);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, newWithBuffer);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, addChildAtAnchor);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, addOverlay);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, bufferToWindowCoords);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getAcceptsTab);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getBottomMargin);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getBuffer);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getCursorVisible);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getEditable);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getExtraMenu);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getGutter);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getIndent);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getInputHints);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getInputPurpose);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getJustification);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getLeftMargin);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getLtrContext);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getMonospace);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getOverwrite);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getPixelsAboveLines);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getPixelsBelowLines);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getPixelsInsideWrap);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getRightMargin);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getRtlContext);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getTopMargin);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getVisibleOffset);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getVisibleRect);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, getWrapMode);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, imContextFilterKeypress);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, moveMarkOnscreen);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, moveOverlay);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, placeCursorOnscreen);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, remove);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, resetCursorBlink);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, resetImContext);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, scrollMarkOnscreen);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, scrollToMark);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setAcceptsTab);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setBottomMargin);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setBuffer);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setCursorVisible);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setEditable);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setExtraMenu);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setGutter);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setIndent);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setInputHints);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setInputPurpose);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setJustification);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setLeftMargin);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setMonospace);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setOverwrite);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setPixelsAboveLines);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setPixelsBelowLines);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setPixelsInsideWrap);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setRightMargin);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setTopMargin);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, setWrapMode);
PHP_METHOD(Gtk_Gtk_GtkTextView_GtkTextView, windowToBufferCoords);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_newwithbuffer, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, buffer, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_addchildatanchor, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, anchor, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_addoverlay, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, xpos, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ypos, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_buffertowindowcoords, 0, 4, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, win, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, bufferX, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, bufferY, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_getacceptstab, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_getbottommargin, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_getbuffer, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_getcursorvisible, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_geteditable, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_getextramenu, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_getgutter, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, win, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_getindent, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_getinputhints, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_getinputpurpose, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_getjustification, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_getleftmargin, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_getltrcontext, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_getmonospace, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_getoverwrite, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_getpixelsabovelines, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_getpixelsbelowlines, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_getpixelsinsidewrap, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_getrightmargin, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_getrtlcontext, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_gettopmargin, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_getvisibleoffset, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_getvisiblerect, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_getwrapmode, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_imcontextfilterkeypress, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, event, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_movemarkonscreen, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, mark, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_moveoverlay, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, xpos, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ypos, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_placecursoronscreen, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_remove, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_resetcursorblink, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_resetimcontext, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_scrollmarkonscreen, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, mark, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_scrolltomark, 0, 6, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, mark, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, withinMargin, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, useAlign, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, xalign, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, yalign, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_setacceptstab, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, acceptsTab, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_setbottommargin, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, bottomMargin, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_setbuffer, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, buffer, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_setcursorvisible, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, setting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_seteditable, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, setting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_setextramenu, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, model, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_setgutter, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, win, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, widget, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_setindent, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, indent, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_setinputhints, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, hints, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_setinputpurpose, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, purpose, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_setjustification, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, justification, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_setleftmargin, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, leftMargin, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_setmonospace, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, monospace, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_setoverwrite, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, overwrite, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_setpixelsabovelines, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pixelsAboveLines, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_setpixelsbelowlines, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pixelsBelowLines, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_setpixelsinsidewrap, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pixelsInsideWrap, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_setrightmargin, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, rightMargin, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_settopmargin, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, topMargin, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_setwrapmode, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, wrapMode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextview_gtktextview_windowtobuffercoords, 0, 4, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, win, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, windowX, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, windowY, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtktextview_gtktextview_method_entry) {
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, new_, arginfo_gtk_gtk_gtktextview_gtktextview_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, newWithBuffer, arginfo_gtk_gtk_gtktextview_gtktextview_newwithbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, addChildAtAnchor, arginfo_gtk_gtk_gtktextview_gtktextview_addchildatanchor, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, addOverlay, arginfo_gtk_gtk_gtktextview_gtktextview_addoverlay, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, bufferToWindowCoords, arginfo_gtk_gtk_gtktextview_gtktextview_buffertowindowcoords, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, getAcceptsTab, arginfo_gtk_gtk_gtktextview_gtktextview_getacceptstab, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, getBottomMargin, arginfo_gtk_gtk_gtktextview_gtktextview_getbottommargin, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, getBuffer, arginfo_gtk_gtk_gtktextview_gtktextview_getbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, getCursorVisible, arginfo_gtk_gtk_gtktextview_gtktextview_getcursorvisible, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, getEditable, arginfo_gtk_gtk_gtktextview_gtktextview_geteditable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, getExtraMenu, arginfo_gtk_gtk_gtktextview_gtktextview_getextramenu, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, getGutter, arginfo_gtk_gtk_gtktextview_gtktextview_getgutter, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, getIndent, arginfo_gtk_gtk_gtktextview_gtktextview_getindent, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, getInputHints, arginfo_gtk_gtk_gtktextview_gtktextview_getinputhints, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, getInputPurpose, arginfo_gtk_gtk_gtktextview_gtktextview_getinputpurpose, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, getJustification, arginfo_gtk_gtk_gtktextview_gtktextview_getjustification, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, getLeftMargin, arginfo_gtk_gtk_gtktextview_gtktextview_getleftmargin, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, getLtrContext, arginfo_gtk_gtk_gtktextview_gtktextview_getltrcontext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, getMonospace, arginfo_gtk_gtk_gtktextview_gtktextview_getmonospace, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, getOverwrite, arginfo_gtk_gtk_gtktextview_gtktextview_getoverwrite, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, getPixelsAboveLines, arginfo_gtk_gtk_gtktextview_gtktextview_getpixelsabovelines, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, getPixelsBelowLines, arginfo_gtk_gtk_gtktextview_gtktextview_getpixelsbelowlines, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, getPixelsInsideWrap, arginfo_gtk_gtk_gtktextview_gtktextview_getpixelsinsidewrap, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, getRightMargin, arginfo_gtk_gtk_gtktextview_gtktextview_getrightmargin, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, getRtlContext, arginfo_gtk_gtk_gtktextview_gtktextview_getrtlcontext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, getTopMargin, arginfo_gtk_gtk_gtktextview_gtktextview_gettopmargin, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, getVisibleOffset, arginfo_gtk_gtk_gtktextview_gtktextview_getvisibleoffset, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, getVisibleRect, arginfo_gtk_gtk_gtktextview_gtktextview_getvisiblerect, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, getWrapMode, arginfo_gtk_gtk_gtktextview_gtktextview_getwrapmode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, imContextFilterKeypress, arginfo_gtk_gtk_gtktextview_gtktextview_imcontextfilterkeypress, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, moveMarkOnscreen, arginfo_gtk_gtk_gtktextview_gtktextview_movemarkonscreen, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, moveOverlay, arginfo_gtk_gtk_gtktextview_gtktextview_moveoverlay, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, placeCursorOnscreen, arginfo_gtk_gtk_gtktextview_gtktextview_placecursoronscreen, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, remove, arginfo_gtk_gtk_gtktextview_gtktextview_remove, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, resetCursorBlink, arginfo_gtk_gtk_gtktextview_gtktextview_resetcursorblink, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, resetImContext, arginfo_gtk_gtk_gtktextview_gtktextview_resetimcontext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, scrollMarkOnscreen, arginfo_gtk_gtk_gtktextview_gtktextview_scrollmarkonscreen, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, scrollToMark, arginfo_gtk_gtk_gtktextview_gtktextview_scrolltomark, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, setAcceptsTab, arginfo_gtk_gtk_gtktextview_gtktextview_setacceptstab, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, setBottomMargin, arginfo_gtk_gtk_gtktextview_gtktextview_setbottommargin, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, setBuffer, arginfo_gtk_gtk_gtktextview_gtktextview_setbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, setCursorVisible, arginfo_gtk_gtk_gtktextview_gtktextview_setcursorvisible, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, setEditable, arginfo_gtk_gtk_gtktextview_gtktextview_seteditable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, setExtraMenu, arginfo_gtk_gtk_gtktextview_gtktextview_setextramenu, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, setGutter, arginfo_gtk_gtk_gtktextview_gtktextview_setgutter, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, setIndent, arginfo_gtk_gtk_gtktextview_gtktextview_setindent, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, setInputHints, arginfo_gtk_gtk_gtktextview_gtktextview_setinputhints, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, setInputPurpose, arginfo_gtk_gtk_gtktextview_gtktextview_setinputpurpose, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, setJustification, arginfo_gtk_gtk_gtktextview_gtktextview_setjustification, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, setLeftMargin, arginfo_gtk_gtk_gtktextview_gtktextview_setleftmargin, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, setMonospace, arginfo_gtk_gtk_gtktextview_gtktextview_setmonospace, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, setOverwrite, arginfo_gtk_gtk_gtktextview_gtktextview_setoverwrite, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, setPixelsAboveLines, arginfo_gtk_gtk_gtktextview_gtktextview_setpixelsabovelines, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, setPixelsBelowLines, arginfo_gtk_gtk_gtktextview_gtktextview_setpixelsbelowlines, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, setPixelsInsideWrap, arginfo_gtk_gtk_gtktextview_gtktextview_setpixelsinsidewrap, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, setRightMargin, arginfo_gtk_gtk_gtktextview_gtktextview_setrightmargin, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, setTopMargin, arginfo_gtk_gtk_gtktextview_gtktextview_settopmargin, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, setWrapMode, arginfo_gtk_gtk_gtktextview_gtktextview_setwrapmode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextView_GtkTextView, windowToBufferCoords, arginfo_gtk_gtk_gtktextview_gtktextview_windowtobuffercoords, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
