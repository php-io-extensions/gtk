
extern zend_class_entry *gtk_gtk_gtkviewport_gtkviewport_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkViewport_GtkViewport);

PHP_METHOD(Gtk_Gtk_GtkViewport_GtkViewport, new_);
PHP_METHOD(Gtk_Gtk_GtkViewport_GtkViewport, getChild);
PHP_METHOD(Gtk_Gtk_GtkViewport_GtkViewport, getScrollToFocus);
PHP_METHOD(Gtk_Gtk_GtkViewport_GtkViewport, setChild);
PHP_METHOD(Gtk_Gtk_GtkViewport_GtkViewport, setScrollToFocus);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkviewport_gtkviewport_new_, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, hadjustment, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, vadjustment, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkviewport_gtkviewport_getchild, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkviewport_gtkviewport_getscrolltofocus, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkviewport_gtkviewport_setchild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkviewport_gtkviewport_setscrolltofocus, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, scrollToFocus, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkviewport_gtkviewport_method_entry) {
	PHP_ME(Gtk_Gtk_GtkViewport_GtkViewport, new_, arginfo_gtk_gtk_gtkviewport_gtkviewport_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkViewport_GtkViewport, getChild, arginfo_gtk_gtk_gtkviewport_gtkviewport_getchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkViewport_GtkViewport, getScrollToFocus, arginfo_gtk_gtk_gtkviewport_gtkviewport_getscrolltofocus, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkViewport_GtkViewport, setChild, arginfo_gtk_gtk_gtkviewport_gtkviewport_setchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkViewport_GtkViewport, setScrollToFocus, arginfo_gtk_gtk_gtkviewport_gtkviewport_setscrolltofocus, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
