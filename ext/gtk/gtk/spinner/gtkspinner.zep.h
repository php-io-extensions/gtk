
extern zend_class_entry *gtk_gtk_spinner_gtkspinner_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_Spinner_GtkSpinner);

PHP_METHOD(Gtk_GTK_Spinner_GtkSpinner, gtkSpinnerNew);
PHP_METHOD(Gtk_GTK_Spinner_GtkSpinner, gtkSpinnerStart);
PHP_METHOD(Gtk_GTK_Spinner_GtkSpinner, gtkSpinnerStop);
PHP_METHOD(Gtk_GTK_Spinner_GtkSpinner, gtkSpinnerSetSpinning);
PHP_METHOD(Gtk_GTK_Spinner_GtkSpinner, gtkSpinnerGetSpinning);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_spinner_gtkspinner_gtkspinnernew, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_spinner_gtkspinner_gtkspinnerstart, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, spinner, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_spinner_gtkspinner_gtkspinnerstop, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, spinner, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_spinner_gtkspinner_gtkspinnersetspinning, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, spinner, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, spinning, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_spinner_gtkspinner_gtkspinnergetspinning, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, spinner, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_spinner_gtkspinner_method_entry) {
	PHP_ME(Gtk_GTK_Spinner_GtkSpinner, gtkSpinnerNew, arginfo_gtk_gtk_spinner_gtkspinner_gtkspinnernew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Spinner_GtkSpinner, gtkSpinnerStart, arginfo_gtk_gtk_spinner_gtkspinner_gtkspinnerstart, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Spinner_GtkSpinner, gtkSpinnerStop, arginfo_gtk_gtk_spinner_gtkspinner_gtkspinnerstop, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Spinner_GtkSpinner, gtkSpinnerSetSpinning, arginfo_gtk_gtk_spinner_gtkspinner_gtkspinnersetspinning, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Spinner_GtkSpinner, gtkSpinnerGetSpinning, arginfo_gtk_gtk_spinner_gtkspinner_gtkspinnergetspinning, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
