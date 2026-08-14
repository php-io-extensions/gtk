
extern zend_class_entry *gtk_gtk_dropdown_gtkdropdown_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_DropDown_GtkDropDown);

PHP_METHOD(Gtk_GTK_DropDown_GtkDropDown, gtkDropDownNewFromStrings);
PHP_METHOD(Gtk_GTK_DropDown_GtkDropDown, gtkDropDownSetSelected);
PHP_METHOD(Gtk_GTK_DropDown_GtkDropDown, gtkDropDownGetSelected);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_dropdown_gtkdropdown_gtkdropdownnewfromstrings, 0, 1, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, labels, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_dropdown_gtkdropdown_gtkdropdownsetselected, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, drop, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, selected, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_dropdown_gtkdropdown_gtkdropdowngetselected, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, drop, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_dropdown_gtkdropdown_method_entry) {
	PHP_ME(Gtk_GTK_DropDown_GtkDropDown, gtkDropDownNewFromStrings, arginfo_gtk_gtk_dropdown_gtkdropdown_gtkdropdownnewfromstrings, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_DropDown_GtkDropDown, gtkDropDownSetSelected, arginfo_gtk_gtk_dropdown_gtkdropdown_gtkdropdownsetselected, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_DropDown_GtkDropDown, gtkDropDownGetSelected, arginfo_gtk_gtk_dropdown_gtkdropdown_gtkdropdowngetselected, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
