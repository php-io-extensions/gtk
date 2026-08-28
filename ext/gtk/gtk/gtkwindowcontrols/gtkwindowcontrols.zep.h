
extern zend_class_entry *gtk_gtk_gtkwindowcontrols_gtkwindowcontrols_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkWindowControls_GtkWindowControls);

PHP_METHOD(Gtk_Gtk_GtkWindowControls_GtkWindowControls, new_);
PHP_METHOD(Gtk_Gtk_GtkWindowControls_GtkWindowControls, getDecorationLayout);
PHP_METHOD(Gtk_Gtk_GtkWindowControls_GtkWindowControls, getEmpty);
PHP_METHOD(Gtk_Gtk_GtkWindowControls_GtkWindowControls, getSide);
PHP_METHOD(Gtk_Gtk_GtkWindowControls_GtkWindowControls, getUseNativeControls);
PHP_METHOD(Gtk_Gtk_GtkWindowControls_GtkWindowControls, setDecorationLayout);
PHP_METHOD(Gtk_Gtk_GtkWindowControls_GtkWindowControls, setSide);
PHP_METHOD(Gtk_Gtk_GtkWindowControls_GtkWindowControls, setUseNativeControls);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindowcontrols_gtkwindowcontrols_new_, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, side, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkwindowcontrols_gtkwindowcontrols_getdecorationlayout, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindowcontrols_gtkwindowcontrols_getempty, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindowcontrols_gtkwindowcontrols_getside, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindowcontrols_gtkwindowcontrols_getusenativecontrols, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindowcontrols_gtkwindowcontrols_setdecorationlayout, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, layout)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindowcontrols_gtkwindowcontrols_setside, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, side, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindowcontrols_gtkwindowcontrols_setusenativecontrols, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, setting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkwindowcontrols_gtkwindowcontrols_method_entry) {
	PHP_ME(Gtk_Gtk_GtkWindowControls_GtkWindowControls, new_, arginfo_gtk_gtk_gtkwindowcontrols_gtkwindowcontrols_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindowControls_GtkWindowControls, getDecorationLayout, arginfo_gtk_gtk_gtkwindowcontrols_gtkwindowcontrols_getdecorationlayout, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindowControls_GtkWindowControls, getEmpty, arginfo_gtk_gtk_gtkwindowcontrols_gtkwindowcontrols_getempty, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindowControls_GtkWindowControls, getSide, arginfo_gtk_gtk_gtkwindowcontrols_gtkwindowcontrols_getside, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindowControls_GtkWindowControls, getUseNativeControls, arginfo_gtk_gtk_gtkwindowcontrols_gtkwindowcontrols_getusenativecontrols, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindowControls_GtkWindowControls, setDecorationLayout, arginfo_gtk_gtk_gtkwindowcontrols_gtkwindowcontrols_setdecorationlayout, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindowControls_GtkWindowControls, setSide, arginfo_gtk_gtk_gtkwindowcontrols_gtkwindowcontrols_setside, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindowControls_GtkWindowControls, setUseNativeControls, arginfo_gtk_gtk_gtkwindowcontrols_gtkwindowcontrols_setusenativecontrols, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
