
extern zend_class_entry *gtk_gtk_gtkorientable_gtkorientable_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkOrientable_GtkOrientable);

PHP_METHOD(Gtk_Gtk_GtkOrientable_GtkOrientable, getOrientation);
PHP_METHOD(Gtk_Gtk_GtkOrientable_GtkOrientable, setOrientation);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkorientable_gtkorientable_getorientation, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkorientable_gtkorientable_setorientation, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, orientation, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkorientable_gtkorientable_method_entry) {
	PHP_ME(Gtk_Gtk_GtkOrientable_GtkOrientable, getOrientation, arginfo_gtk_gtk_gtkorientable_gtkorientable_getorientation, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkOrientable_GtkOrientable, setOrientation, arginfo_gtk_gtk_gtkorientable_gtkorientable_setorientation, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
