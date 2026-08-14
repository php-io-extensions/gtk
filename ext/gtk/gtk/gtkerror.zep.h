
extern zend_class_entry *gtk_gtk_gtkerror_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_GtkError);

PHP_METHOD(Gtk_GTK_GtkError, gtkLastMessage);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkerror_gtklastmessage, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkerror_method_entry) {
	PHP_ME(Gtk_GTK_GtkError, gtkLastMessage, arginfo_gtk_gtk_gtkerror_gtklastmessage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
