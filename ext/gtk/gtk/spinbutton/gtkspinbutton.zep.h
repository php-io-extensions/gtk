
extern zend_class_entry *gtk_gtk_spinbutton_gtkspinbutton_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_SpinButton_GtkSpinButton);

PHP_METHOD(Gtk_GTK_SpinButton_GtkSpinButton, gtkSpinButtonNewWithRange);
PHP_METHOD(Gtk_GTK_SpinButton_GtkSpinButton, gtkSpinButtonSetValue);
PHP_METHOD(Gtk_GTK_SpinButton_GtkSpinButton, gtkSpinButtonGetValue);
PHP_METHOD(Gtk_GTK_SpinButton_GtkSpinButton, gtkSpinButtonGetValueAsInt);
PHP_METHOD(Gtk_GTK_SpinButton_GtkSpinButton, gtkSpinButtonSetDigits);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_spinbutton_gtkspinbutton_gtkspinbuttonnewwithrange, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, min, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, max, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, step, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_spinbutton_gtkspinbutton_gtkspinbuttonsetvalue, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, spin, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_spinbutton_gtkspinbutton_gtkspinbuttongetvalue, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, spin, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_spinbutton_gtkspinbutton_gtkspinbuttongetvalueasint, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, spin, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_spinbutton_gtkspinbutton_gtkspinbuttonsetdigits, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, spin, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, digits, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_spinbutton_gtkspinbutton_method_entry) {
	PHP_ME(Gtk_GTK_SpinButton_GtkSpinButton, gtkSpinButtonNewWithRange, arginfo_gtk_gtk_spinbutton_gtkspinbutton_gtkspinbuttonnewwithrange, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_SpinButton_GtkSpinButton, gtkSpinButtonSetValue, arginfo_gtk_gtk_spinbutton_gtkspinbutton_gtkspinbuttonsetvalue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_SpinButton_GtkSpinButton, gtkSpinButtonGetValue, arginfo_gtk_gtk_spinbutton_gtkspinbutton_gtkspinbuttongetvalue, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_SpinButton_GtkSpinButton, gtkSpinButtonGetValueAsInt, arginfo_gtk_gtk_spinbutton_gtkspinbutton_gtkspinbuttongetvalueasint, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_SpinButton_GtkSpinButton, gtkSpinButtonSetDigits, arginfo_gtk_gtk_spinbutton_gtkspinbutton_gtkspinbuttonsetdigits, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
