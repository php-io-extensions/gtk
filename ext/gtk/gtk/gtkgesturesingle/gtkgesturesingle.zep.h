
extern zend_class_entry *gtk_gtk_gtkgesturesingle_gtkgesturesingle_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkGestureSingle_GtkGestureSingle);

PHP_METHOD(Gtk_Gtk_GtkGestureSingle_GtkGestureSingle, getButton);
PHP_METHOD(Gtk_Gtk_GtkGestureSingle_GtkGestureSingle, getCurrentButton);
PHP_METHOD(Gtk_Gtk_GtkGestureSingle_GtkGestureSingle, getExclusive);
PHP_METHOD(Gtk_Gtk_GtkGestureSingle_GtkGestureSingle, getTouchOnly);
PHP_METHOD(Gtk_Gtk_GtkGestureSingle_GtkGestureSingle, setButton);
PHP_METHOD(Gtk_Gtk_GtkGestureSingle_GtkGestureSingle, setExclusive);
PHP_METHOD(Gtk_Gtk_GtkGestureSingle_GtkGestureSingle, setTouchOnly);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgesturesingle_gtkgesturesingle_getbutton, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgesturesingle_gtkgesturesingle_getcurrentbutton, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgesturesingle_gtkgesturesingle_getexclusive, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgesturesingle_gtkgesturesingle_gettouchonly, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgesturesingle_gtkgesturesingle_setbutton, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, button, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgesturesingle_gtkgesturesingle_setexclusive, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, exclusive, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgesturesingle_gtkgesturesingle_settouchonly, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, touchOnly, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkgesturesingle_gtkgesturesingle_method_entry) {
	PHP_ME(Gtk_Gtk_GtkGestureSingle_GtkGestureSingle, getButton, arginfo_gtk_gtk_gtkgesturesingle_gtkgesturesingle_getbutton, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGestureSingle_GtkGestureSingle, getCurrentButton, arginfo_gtk_gtk_gtkgesturesingle_gtkgesturesingle_getcurrentbutton, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGestureSingle_GtkGestureSingle, getExclusive, arginfo_gtk_gtk_gtkgesturesingle_gtkgesturesingle_getexclusive, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGestureSingle_GtkGestureSingle, getTouchOnly, arginfo_gtk_gtk_gtkgesturesingle_gtkgesturesingle_gettouchonly, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGestureSingle_GtkGestureSingle, setButton, arginfo_gtk_gtk_gtkgesturesingle_gtkgesturesingle_setbutton, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGestureSingle_GtkGestureSingle, setExclusive, arginfo_gtk_gtk_gtkgesturesingle_gtkgesturesingle_setexclusive, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGestureSingle_GtkGestureSingle, setTouchOnly, arginfo_gtk_gtk_gtkgesturesingle_gtkgesturesingle_settouchonly, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
