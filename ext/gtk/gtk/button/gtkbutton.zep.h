
extern zend_class_entry *gtk_gtk_button_gtkbutton_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_Button_GtkButton);

PHP_METHOD(Gtk_GTK_Button_GtkButton, gtkButtonNew);
PHP_METHOD(Gtk_GTK_Button_GtkButton, gtkButtonNewWithLabel);
PHP_METHOD(Gtk_GTK_Button_GtkButton, gtkButtonSetLabel);
PHP_METHOD(Gtk_GTK_Button_GtkButton, gtkButtonGetLabel);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_button_gtkbutton_gtkbuttonnew, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_button_gtkbutton_gtkbuttonnewwithlabel, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_button_gtkbutton_gtkbuttonsetlabel, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, button, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_button_gtkbutton_gtkbuttongetlabel, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, button, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_button_gtkbutton_method_entry) {
	PHP_ME(Gtk_GTK_Button_GtkButton, gtkButtonNew, arginfo_gtk_gtk_button_gtkbutton_gtkbuttonnew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Button_GtkButton, gtkButtonNewWithLabel, arginfo_gtk_gtk_button_gtkbutton_gtkbuttonnewwithlabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Button_GtkButton, gtkButtonSetLabel, arginfo_gtk_gtk_button_gtkbutton_gtkbuttonsetlabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Button_GtkButton, gtkButtonGetLabel, arginfo_gtk_gtk_button_gtkbutton_gtkbuttongetlabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
