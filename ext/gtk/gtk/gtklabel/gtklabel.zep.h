
extern zend_class_entry *gtk_gtk_gtklabel_gtklabel_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkLabel_GtkLabel);

PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, new_);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, newWithMnemonic);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, getCurrentUri);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, getEllipsize);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, getExtraMenu);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, getJustify);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, getLabel);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, getLayout);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, getLayoutOffsets);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, getLines);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, getMaxWidthChars);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, getMnemonicKeyval);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, getMnemonicWidget);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, getNaturalWrapMode);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, getSelectable);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, getSelectionBounds);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, getSingleLineMode);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, getText);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, getUseMarkup);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, getUseUnderline);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, getWidthChars);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, getWrap);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, getWrapMode);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, getXalign);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, getYalign);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, selectRegion);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, setEllipsize);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, setExtraMenu);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, setJustify);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, setLabel);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, setLines);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, setMarkup);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, setMarkupWithMnemonic);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, setMaxWidthChars);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, setMnemonicWidget);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, setNaturalWrapMode);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, setSelectable);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, setSingleLineMode);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, setText);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, setTextWithMnemonic);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, setUseMarkup);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, setUseUnderline);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, setWidthChars);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, setWrap);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, setWrapMode);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, setXalign);
PHP_METHOD(Gtk_Gtk_GtkLabel_GtkLabel, setYalign);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_new_, 0, 1, IS_LONG, 0)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_newwithmnemonic, 0, 1, IS_LONG, 0)
	ZEND_ARG_INFO(0, str)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_getcurrenturi, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_getellipsize, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_getextramenu, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_getjustify, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_getlabel, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_getlayout, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_getlayoutoffsets, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_getlines, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_getmaxwidthchars, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_getmnemonickeyval, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_getmnemonicwidget, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_getnaturalwrapmode, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_getselectable, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_getselectionbounds, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_getsinglelinemode, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_gettext, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_getusemarkup, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_getuseunderline, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_getwidthchars, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_getwrap, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_getwrapmode, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_getxalign, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_getyalign, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_selectregion, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, startOffset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, endOffset, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_setellipsize, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_setextramenu, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, model, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_setjustify, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, jtype, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_setlabel, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, str, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_setlines, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, lines, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_setmarkup, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, str, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_setmarkupwithmnemonic, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, str, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_setmaxwidthchars, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, nChars, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_setmnemonicwidget, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, widget, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_setnaturalwrapmode, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, wrapMode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_setselectable, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, setting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_setsinglelinemode, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, singleLineMode, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_settext, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, str, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_settextwithmnemonic, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, str, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_setusemarkup, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, setting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_setuseunderline, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, setting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_setwidthchars, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, nChars, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_setwrap, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, wrap, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_setwrapmode, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, wrapMode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_setxalign, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, xalign, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklabel_gtklabel_setyalign, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, yalign, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtklabel_gtklabel_method_entry) {
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, new_, arginfo_gtk_gtk_gtklabel_gtklabel_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, newWithMnemonic, arginfo_gtk_gtk_gtklabel_gtklabel_newwithmnemonic, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, getCurrentUri, arginfo_gtk_gtk_gtklabel_gtklabel_getcurrenturi, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, getEllipsize, arginfo_gtk_gtk_gtklabel_gtklabel_getellipsize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, getExtraMenu, arginfo_gtk_gtk_gtklabel_gtklabel_getextramenu, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, getJustify, arginfo_gtk_gtk_gtklabel_gtklabel_getjustify, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, getLabel, arginfo_gtk_gtk_gtklabel_gtklabel_getlabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, getLayout, arginfo_gtk_gtk_gtklabel_gtklabel_getlayout, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, getLayoutOffsets, arginfo_gtk_gtk_gtklabel_gtklabel_getlayoutoffsets, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, getLines, arginfo_gtk_gtk_gtklabel_gtklabel_getlines, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, getMaxWidthChars, arginfo_gtk_gtk_gtklabel_gtklabel_getmaxwidthchars, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, getMnemonicKeyval, arginfo_gtk_gtk_gtklabel_gtklabel_getmnemonickeyval, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, getMnemonicWidget, arginfo_gtk_gtk_gtklabel_gtklabel_getmnemonicwidget, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, getNaturalWrapMode, arginfo_gtk_gtk_gtklabel_gtklabel_getnaturalwrapmode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, getSelectable, arginfo_gtk_gtk_gtklabel_gtklabel_getselectable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, getSelectionBounds, arginfo_gtk_gtk_gtklabel_gtklabel_getselectionbounds, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, getSingleLineMode, arginfo_gtk_gtk_gtklabel_gtklabel_getsinglelinemode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, getText, arginfo_gtk_gtk_gtklabel_gtklabel_gettext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, getUseMarkup, arginfo_gtk_gtk_gtklabel_gtklabel_getusemarkup, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, getUseUnderline, arginfo_gtk_gtk_gtklabel_gtklabel_getuseunderline, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, getWidthChars, arginfo_gtk_gtk_gtklabel_gtklabel_getwidthchars, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, getWrap, arginfo_gtk_gtk_gtklabel_gtklabel_getwrap, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, getWrapMode, arginfo_gtk_gtk_gtklabel_gtklabel_getwrapmode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, getXalign, arginfo_gtk_gtk_gtklabel_gtklabel_getxalign, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, getYalign, arginfo_gtk_gtk_gtklabel_gtklabel_getyalign, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, selectRegion, arginfo_gtk_gtk_gtklabel_gtklabel_selectregion, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, setEllipsize, arginfo_gtk_gtk_gtklabel_gtklabel_setellipsize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, setExtraMenu, arginfo_gtk_gtk_gtklabel_gtklabel_setextramenu, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, setJustify, arginfo_gtk_gtk_gtklabel_gtklabel_setjustify, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, setLabel, arginfo_gtk_gtk_gtklabel_gtklabel_setlabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, setLines, arginfo_gtk_gtk_gtklabel_gtklabel_setlines, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, setMarkup, arginfo_gtk_gtk_gtklabel_gtklabel_setmarkup, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, setMarkupWithMnemonic, arginfo_gtk_gtk_gtklabel_gtklabel_setmarkupwithmnemonic, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, setMaxWidthChars, arginfo_gtk_gtk_gtklabel_gtklabel_setmaxwidthchars, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, setMnemonicWidget, arginfo_gtk_gtk_gtklabel_gtklabel_setmnemonicwidget, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, setNaturalWrapMode, arginfo_gtk_gtk_gtklabel_gtklabel_setnaturalwrapmode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, setSelectable, arginfo_gtk_gtk_gtklabel_gtklabel_setselectable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, setSingleLineMode, arginfo_gtk_gtk_gtklabel_gtklabel_setsinglelinemode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, setText, arginfo_gtk_gtk_gtklabel_gtklabel_settext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, setTextWithMnemonic, arginfo_gtk_gtk_gtklabel_gtklabel_settextwithmnemonic, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, setUseMarkup, arginfo_gtk_gtk_gtklabel_gtklabel_setusemarkup, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, setUseUnderline, arginfo_gtk_gtk_gtklabel_gtklabel_setuseunderline, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, setWidthChars, arginfo_gtk_gtk_gtklabel_gtklabel_setwidthchars, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, setWrap, arginfo_gtk_gtk_gtklabel_gtklabel_setwrap, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, setWrapMode, arginfo_gtk_gtk_gtklabel_gtklabel_setwrapmode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, setXalign, arginfo_gtk_gtk_gtklabel_gtklabel_setxalign, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkLabel_GtkLabel, setYalign, arginfo_gtk_gtk_gtklabel_gtklabel_setyalign, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
