
extern zend_class_entry *gtk_gtk_gtkseparator_gtkseparator_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkSeparator_GtkSeparator);

PHP_METHOD(Gtk_Gtk_GtkSeparator_GtkSeparator, new_);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkseparator_gtkseparator_new_, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, orientation, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkseparator_gtkseparator_method_entry) {
	PHP_ME(Gtk_Gtk_GtkSeparator_GtkSeparator, new_, arginfo_gtk_gtk_gtkseparator_gtkseparator_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
