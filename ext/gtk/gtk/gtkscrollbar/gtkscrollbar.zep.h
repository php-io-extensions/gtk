
extern zend_class_entry *gtk_gtk_gtkscrollbar_gtkscrollbar_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkScrollbar_GtkScrollbar);

PHP_METHOD(Gtk_Gtk_GtkScrollbar_GtkScrollbar, new_);
PHP_METHOD(Gtk_Gtk_GtkScrollbar_GtkScrollbar, getAdjustment);
PHP_METHOD(Gtk_Gtk_GtkScrollbar_GtkScrollbar, setAdjustment);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrollbar_gtkscrollbar_new_, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, orientation, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, adjustment, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrollbar_gtkscrollbar_getadjustment, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrollbar_gtkscrollbar_setadjustment, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, adjustment, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkscrollbar_gtkscrollbar_method_entry) {
	PHP_ME(Gtk_Gtk_GtkScrollbar_GtkScrollbar, new_, arginfo_gtk_gtk_gtkscrollbar_gtkscrollbar_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrollbar_GtkScrollbar, getAdjustment, arginfo_gtk_gtk_gtkscrollbar_gtkscrollbar_getadjustment, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrollbar_GtkScrollbar, setAdjustment, arginfo_gtk_gtk_gtkscrollbar_gtkscrollbar_setadjustment, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
