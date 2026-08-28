
extern zend_class_entry *gtk_gtk_gtkfixed_gtkfixed_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkFixed_GtkFixed);

PHP_METHOD(Gtk_Gtk_GtkFixed_GtkFixed, new_);
PHP_METHOD(Gtk_Gtk_GtkFixed_GtkFixed, getChildPosition);
PHP_METHOD(Gtk_Gtk_GtkFixed_GtkFixed, move);
PHP_METHOD(Gtk_Gtk_GtkFixed_GtkFixed, put);
PHP_METHOD(Gtk_Gtk_GtkFixed_GtkFixed, remove);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkfixed_gtkfixed_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkfixed_gtkfixed_getchildposition, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, widget, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkfixed_gtkfixed_move, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, widget, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkfixed_gtkfixed_put, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, widget, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkfixed_gtkfixed_remove, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, widget, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkfixed_gtkfixed_method_entry) {
	PHP_ME(Gtk_Gtk_GtkFixed_GtkFixed, new_, arginfo_gtk_gtk_gtkfixed_gtkfixed_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFixed_GtkFixed, getChildPosition, arginfo_gtk_gtk_gtkfixed_gtkfixed_getchildposition, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFixed_GtkFixed, move, arginfo_gtk_gtk_gtkfixed_gtkfixed_move, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFixed_GtkFixed, put, arginfo_gtk_gtk_gtkfixed_gtkfixed_put, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFixed_GtkFixed, remove, arginfo_gtk_gtk_gtkfixed_gtkfixed_remove, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
