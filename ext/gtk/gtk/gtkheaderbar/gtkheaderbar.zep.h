
extern zend_class_entry *gtk_gtk_gtkheaderbar_gtkheaderbar_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkHeaderBar_GtkHeaderBar);

PHP_METHOD(Gtk_Gtk_GtkHeaderBar_GtkHeaderBar, new_);
PHP_METHOD(Gtk_Gtk_GtkHeaderBar_GtkHeaderBar, getDecorationLayout);
PHP_METHOD(Gtk_Gtk_GtkHeaderBar_GtkHeaderBar, getShowTitleButtons);
PHP_METHOD(Gtk_Gtk_GtkHeaderBar_GtkHeaderBar, getTitleWidget);
PHP_METHOD(Gtk_Gtk_GtkHeaderBar_GtkHeaderBar, getUseNativeControls);
PHP_METHOD(Gtk_Gtk_GtkHeaderBar_GtkHeaderBar, packEnd);
PHP_METHOD(Gtk_Gtk_GtkHeaderBar_GtkHeaderBar, packStart);
PHP_METHOD(Gtk_Gtk_GtkHeaderBar_GtkHeaderBar, remove);
PHP_METHOD(Gtk_Gtk_GtkHeaderBar_GtkHeaderBar, setDecorationLayout);
PHP_METHOD(Gtk_Gtk_GtkHeaderBar_GtkHeaderBar, setShowTitleButtons);
PHP_METHOD(Gtk_Gtk_GtkHeaderBar_GtkHeaderBar, setTitleWidget);
PHP_METHOD(Gtk_Gtk_GtkHeaderBar_GtkHeaderBar, setUseNativeControls);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkheaderbar_gtkheaderbar_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkheaderbar_gtkheaderbar_getdecorationlayout, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkheaderbar_gtkheaderbar_getshowtitlebuttons, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkheaderbar_gtkheaderbar_gettitlewidget, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkheaderbar_gtkheaderbar_getusenativecontrols, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkheaderbar_gtkheaderbar_packend, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkheaderbar_gtkheaderbar_packstart, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkheaderbar_gtkheaderbar_remove, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkheaderbar_gtkheaderbar_setdecorationlayout, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, layout)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkheaderbar_gtkheaderbar_setshowtitlebuttons, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, setting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkheaderbar_gtkheaderbar_settitlewidget, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, titleWidget, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkheaderbar_gtkheaderbar_setusenativecontrols, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, setting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkheaderbar_gtkheaderbar_method_entry) {
	PHP_ME(Gtk_Gtk_GtkHeaderBar_GtkHeaderBar, new_, arginfo_gtk_gtk_gtkheaderbar_gtkheaderbar_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkHeaderBar_GtkHeaderBar, getDecorationLayout, arginfo_gtk_gtk_gtkheaderbar_gtkheaderbar_getdecorationlayout, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkHeaderBar_GtkHeaderBar, getShowTitleButtons, arginfo_gtk_gtk_gtkheaderbar_gtkheaderbar_getshowtitlebuttons, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkHeaderBar_GtkHeaderBar, getTitleWidget, arginfo_gtk_gtk_gtkheaderbar_gtkheaderbar_gettitlewidget, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkHeaderBar_GtkHeaderBar, getUseNativeControls, arginfo_gtk_gtk_gtkheaderbar_gtkheaderbar_getusenativecontrols, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkHeaderBar_GtkHeaderBar, packEnd, arginfo_gtk_gtk_gtkheaderbar_gtkheaderbar_packend, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkHeaderBar_GtkHeaderBar, packStart, arginfo_gtk_gtk_gtkheaderbar_gtkheaderbar_packstart, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkHeaderBar_GtkHeaderBar, remove, arginfo_gtk_gtk_gtkheaderbar_gtkheaderbar_remove, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkHeaderBar_GtkHeaderBar, setDecorationLayout, arginfo_gtk_gtk_gtkheaderbar_gtkheaderbar_setdecorationlayout, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkHeaderBar_GtkHeaderBar, setShowTitleButtons, arginfo_gtk_gtk_gtkheaderbar_gtkheaderbar_setshowtitlebuttons, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkHeaderBar_GtkHeaderBar, setTitleWidget, arginfo_gtk_gtk_gtkheaderbar_gtkheaderbar_settitlewidget, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkHeaderBar_GtkHeaderBar, setUseNativeControls, arginfo_gtk_gtk_gtkheaderbar_gtkheaderbar_setusenativecontrols, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
