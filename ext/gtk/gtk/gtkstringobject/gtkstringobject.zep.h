
extern zend_class_entry *gtk_gtk_gtkstringobject_gtkstringobject_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkStringObject_GtkStringObject);

PHP_METHOD(Gtk_Gtk_GtkStringObject_GtkStringObject, new_);
PHP_METHOD(Gtk_Gtk_GtkStringObject_GtkStringObject, getString);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstringobject_gtkstringobject_new_, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, string_, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkstringobject_gtkstringobject_getstring, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkstringobject_gtkstringobject_method_entry) {
	PHP_ME(Gtk_Gtk_GtkStringObject_GtkStringObject, new_, arginfo_gtk_gtk_gtkstringobject_gtkstringobject_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStringObject_GtkStringObject, getString, arginfo_gtk_gtk_gtkstringobject_gtkstringobject_getstring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
