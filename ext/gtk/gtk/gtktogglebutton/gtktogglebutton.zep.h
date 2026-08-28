
extern zend_class_entry *gtk_gtk_gtktogglebutton_gtktogglebutton_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkToggleButton_GtkToggleButton);

PHP_METHOD(Gtk_Gtk_GtkToggleButton_GtkToggleButton, new_);
PHP_METHOD(Gtk_Gtk_GtkToggleButton_GtkToggleButton, newWithLabel);
PHP_METHOD(Gtk_Gtk_GtkToggleButton_GtkToggleButton, newWithMnemonic);
PHP_METHOD(Gtk_Gtk_GtkToggleButton_GtkToggleButton, getActive);
PHP_METHOD(Gtk_Gtk_GtkToggleButton_GtkToggleButton, setActive);
PHP_METHOD(Gtk_Gtk_GtkToggleButton_GtkToggleButton, setGroup);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktogglebutton_gtktogglebutton_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktogglebutton_gtktogglebutton_newwithlabel, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktogglebutton_gtktogglebutton_newwithmnemonic, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktogglebutton_gtktogglebutton_getactive, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktogglebutton_gtktogglebutton_setactive, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, isActive, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktogglebutton_gtktogglebutton_setgroup, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, group, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtktogglebutton_gtktogglebutton_method_entry) {
	PHP_ME(Gtk_Gtk_GtkToggleButton_GtkToggleButton, new_, arginfo_gtk_gtk_gtktogglebutton_gtktogglebutton_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkToggleButton_GtkToggleButton, newWithLabel, arginfo_gtk_gtk_gtktogglebutton_gtktogglebutton_newwithlabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkToggleButton_GtkToggleButton, newWithMnemonic, arginfo_gtk_gtk_gtktogglebutton_gtktogglebutton_newwithmnemonic, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkToggleButton_GtkToggleButton, getActive, arginfo_gtk_gtk_gtktogglebutton_gtktogglebutton_getactive, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkToggleButton_GtkToggleButton, setActive, arginfo_gtk_gtk_gtktogglebutton_gtktogglebutton_setactive, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkToggleButton_GtkToggleButton, setGroup, arginfo_gtk_gtk_gtktogglebutton_gtktogglebutton_setgroup, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
