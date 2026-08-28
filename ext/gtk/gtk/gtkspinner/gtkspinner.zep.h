
extern zend_class_entry *gtk_gtk_gtkspinner_gtkspinner_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkSpinner_GtkSpinner);

PHP_METHOD(Gtk_Gtk_GtkSpinner_GtkSpinner, new_);
PHP_METHOD(Gtk_Gtk_GtkSpinner_GtkSpinner, getSpinning);
PHP_METHOD(Gtk_Gtk_GtkSpinner_GtkSpinner, setSpinning);
PHP_METHOD(Gtk_Gtk_GtkSpinner_GtkSpinner, start);
PHP_METHOD(Gtk_Gtk_GtkSpinner_GtkSpinner, stop);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkspinner_gtkspinner_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkspinner_gtkspinner_getspinning, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkspinner_gtkspinner_setspinning, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, spinning, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkspinner_gtkspinner_start, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkspinner_gtkspinner_stop, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkspinner_gtkspinner_method_entry) {
	PHP_ME(Gtk_Gtk_GtkSpinner_GtkSpinner, new_, arginfo_gtk_gtk_gtkspinner_gtkspinner_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSpinner_GtkSpinner, getSpinning, arginfo_gtk_gtk_gtkspinner_gtkspinner_getspinning, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSpinner_GtkSpinner, setSpinning, arginfo_gtk_gtk_gtkspinner_gtkspinner_setspinning, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSpinner_GtkSpinner, start, arginfo_gtk_gtk_gtkspinner_gtkspinner_start, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSpinner_GtkSpinner, stop, arginfo_gtk_gtk_gtkspinner_gtkspinner_stop, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
