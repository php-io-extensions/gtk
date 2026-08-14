
extern zend_class_entry *gtk_gtk_checkbutton_gtkcheckbutton_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_CheckButton_GtkCheckButton);

PHP_METHOD(Gtk_GTK_CheckButton_GtkCheckButton, gtkCheckButtonNew);
PHP_METHOD(Gtk_GTK_CheckButton_GtkCheckButton, gtkCheckButtonNewWithLabel);
PHP_METHOD(Gtk_GTK_CheckButton_GtkCheckButton, gtkCheckButtonSetLabel);
PHP_METHOD(Gtk_GTK_CheckButton_GtkCheckButton, gtkCheckButtonGetLabel);
PHP_METHOD(Gtk_GTK_CheckButton_GtkCheckButton, gtkCheckButtonSetActive);
PHP_METHOD(Gtk_GTK_CheckButton_GtkCheckButton, gtkCheckButtonGetActive);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_checkbutton_gtkcheckbutton_gtkcheckbuttonnew, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_checkbutton_gtkcheckbutton_gtkcheckbuttonnewwithlabel, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_checkbutton_gtkcheckbutton_gtkcheckbuttonsetlabel, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, button, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_checkbutton_gtkcheckbutton_gtkcheckbuttongetlabel, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, button, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_checkbutton_gtkcheckbutton_gtkcheckbuttonsetactive, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, button, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, active, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_checkbutton_gtkcheckbutton_gtkcheckbuttongetactive, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, button, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_checkbutton_gtkcheckbutton_method_entry) {
	PHP_ME(Gtk_GTK_CheckButton_GtkCheckButton, gtkCheckButtonNew, arginfo_gtk_gtk_checkbutton_gtkcheckbutton_gtkcheckbuttonnew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_CheckButton_GtkCheckButton, gtkCheckButtonNewWithLabel, arginfo_gtk_gtk_checkbutton_gtkcheckbutton_gtkcheckbuttonnewwithlabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_CheckButton_GtkCheckButton, gtkCheckButtonSetLabel, arginfo_gtk_gtk_checkbutton_gtkcheckbutton_gtkcheckbuttonsetlabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_CheckButton_GtkCheckButton, gtkCheckButtonGetLabel, arginfo_gtk_gtk_checkbutton_gtkcheckbutton_gtkcheckbuttongetlabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_CheckButton_GtkCheckButton, gtkCheckButtonSetActive, arginfo_gtk_gtk_checkbutton_gtkcheckbutton_gtkcheckbuttonsetactive, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_CheckButton_GtkCheckButton, gtkCheckButtonGetActive, arginfo_gtk_gtk_checkbutton_gtkcheckbutton_gtkcheckbuttongetactive, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
