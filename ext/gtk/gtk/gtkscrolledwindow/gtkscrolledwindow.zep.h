
extern zend_class_entry *gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow);

PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, new_);
PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getChild);
PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getHadjustment);
PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getHasFrame);
PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getHscrollbar);
PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getKineticScrolling);
PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getMaxContentHeight);
PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getMaxContentWidth);
PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getMinContentHeight);
PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getMinContentWidth);
PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getOverlayScrolling);
PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getPlacement);
PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getPolicy);
PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getPropagateNaturalHeight);
PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getPropagateNaturalWidth);
PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getVadjustment);
PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getVscrollbar);
PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setChild);
PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setHadjustment);
PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setHasFrame);
PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setKineticScrolling);
PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setMaxContentHeight);
PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setMaxContentWidth);
PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setMinContentHeight);
PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setMinContentWidth);
PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setOverlayScrolling);
PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setPlacement);
PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setPolicy);
PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setPropagateNaturalHeight);
PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setPropagateNaturalWidth);
PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setVadjustment);
PHP_METHOD(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, unsetPlacement);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_getchild, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_gethadjustment, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_gethasframe, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_gethscrollbar, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_getkineticscrolling, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_getmaxcontentheight, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_getmaxcontentwidth, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_getmincontentheight, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_getmincontentwidth, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_getoverlayscrolling, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_getplacement, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_getpolicy, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_getpropagatenaturalheight, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_getpropagatenaturalwidth, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_getvadjustment, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_getvscrollbar, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_setchild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_sethadjustment, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, hadjustment, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_sethasframe, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, hasFrame, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_setkineticscrolling, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, kineticScrolling, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_setmaxcontentheight, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_setmaxcontentwidth, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_setmincontentheight, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_setmincontentwidth, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_setoverlayscrolling, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, overlayScrolling, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_setplacement, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, windowPlacement, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_setpolicy, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, hscrollbarPolicy, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, vscrollbarPolicy, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_setpropagatenaturalheight, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, propagate, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_setpropagatenaturalwidth, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, propagate, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_setvadjustment, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, vadjustment, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_unsetplacement, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_method_entry) {
	PHP_ME(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, new_, arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getChild, arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_getchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getHadjustment, arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_gethadjustment, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getHasFrame, arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_gethasframe, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getHscrollbar, arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_gethscrollbar, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getKineticScrolling, arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_getkineticscrolling, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getMaxContentHeight, arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_getmaxcontentheight, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getMaxContentWidth, arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_getmaxcontentwidth, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getMinContentHeight, arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_getmincontentheight, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getMinContentWidth, arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_getmincontentwidth, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getOverlayScrolling, arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_getoverlayscrolling, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getPlacement, arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_getplacement, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getPolicy, arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_getpolicy, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getPropagateNaturalHeight, arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_getpropagatenaturalheight, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getPropagateNaturalWidth, arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_getpropagatenaturalwidth, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getVadjustment, arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_getvadjustment, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, getVscrollbar, arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_getvscrollbar, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setChild, arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_setchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setHadjustment, arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_sethadjustment, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setHasFrame, arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_sethasframe, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setKineticScrolling, arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_setkineticscrolling, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setMaxContentHeight, arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_setmaxcontentheight, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setMaxContentWidth, arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_setmaxcontentwidth, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setMinContentHeight, arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_setmincontentheight, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setMinContentWidth, arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_setmincontentwidth, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setOverlayScrolling, arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_setoverlayscrolling, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setPlacement, arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_setplacement, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setPolicy, arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_setpolicy, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setPropagateNaturalHeight, arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_setpropagatenaturalheight, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setPropagateNaturalWidth, arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_setpropagatenaturalwidth, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, setVadjustment, arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_setvadjustment, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow, unsetPlacement, arginfo_gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_unsetplacement, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
