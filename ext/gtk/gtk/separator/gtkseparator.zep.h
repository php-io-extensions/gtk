
extern zend_class_entry *gtk_gtk_separator_gtkseparator_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_Separator_GtkSeparator);

PHP_METHOD(Gtk_GTK_Separator_GtkSeparator, gtkSeparatorNew);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_separator_gtkseparator_gtkseparatornew, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, orientation, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_separator_gtkseparator_method_entry) {
	PHP_ME(Gtk_GTK_Separator_GtkSeparator, gtkSeparatorNew, arginfo_gtk_gtk_separator_gtkseparator_gtkseparatornew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
