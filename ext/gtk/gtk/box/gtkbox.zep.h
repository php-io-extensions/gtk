
extern zend_class_entry *gtk_gtk_box_gtkbox_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_Box_GtkBox);

PHP_METHOD(Gtk_GTK_Box_GtkBox, gtkBoxNew);
PHP_METHOD(Gtk_GTK_Box_GtkBox, gtkBoxAppend);
PHP_METHOD(Gtk_GTK_Box_GtkBox, gtkBoxRemove);
PHP_METHOD(Gtk_GTK_Box_GtkBox, gtkBoxSetSpacing);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_box_gtkbox_gtkboxnew, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, orientation, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, spacing, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_box_gtkbox_gtkboxappend, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, box, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_box_gtkbox_gtkboxremove, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, box, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_box_gtkbox_gtkboxsetspacing, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, box, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, spacing, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_box_gtkbox_method_entry) {
	PHP_ME(Gtk_GTK_Box_GtkBox, gtkBoxNew, arginfo_gtk_gtk_box_gtkbox_gtkboxnew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Box_GtkBox, gtkBoxAppend, arginfo_gtk_gtk_box_gtkbox_gtkboxappend, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Box_GtkBox, gtkBoxRemove, arginfo_gtk_gtk_box_gtkbox_gtkboxremove, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Box_GtkBox, gtkBoxSetSpacing, arginfo_gtk_gtk_box_gtkbox_gtkboxsetspacing, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
