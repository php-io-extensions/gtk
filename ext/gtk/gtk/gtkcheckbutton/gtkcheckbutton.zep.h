
extern zend_class_entry *gtk_gtk_gtkcheckbutton_gtkcheckbutton_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkCheckButton_GtkCheckButton);

PHP_METHOD(Gtk_Gtk_GtkCheckButton_GtkCheckButton, new_);
PHP_METHOD(Gtk_Gtk_GtkCheckButton_GtkCheckButton, newWithLabel);
PHP_METHOD(Gtk_Gtk_GtkCheckButton_GtkCheckButton, newWithMnemonic);
PHP_METHOD(Gtk_Gtk_GtkCheckButton_GtkCheckButton, getActive);
PHP_METHOD(Gtk_Gtk_GtkCheckButton_GtkCheckButton, getChild);
PHP_METHOD(Gtk_Gtk_GtkCheckButton_GtkCheckButton, getInconsistent);
PHP_METHOD(Gtk_Gtk_GtkCheckButton_GtkCheckButton, getLabel);
PHP_METHOD(Gtk_Gtk_GtkCheckButton_GtkCheckButton, getUseUnderline);
PHP_METHOD(Gtk_Gtk_GtkCheckButton_GtkCheckButton, setActive);
PHP_METHOD(Gtk_Gtk_GtkCheckButton_GtkCheckButton, setChild);
PHP_METHOD(Gtk_Gtk_GtkCheckButton_GtkCheckButton, setGroup);
PHP_METHOD(Gtk_Gtk_GtkCheckButton_GtkCheckButton, setInconsistent);
PHP_METHOD(Gtk_Gtk_GtkCheckButton_GtkCheckButton, setLabel);
PHP_METHOD(Gtk_Gtk_GtkCheckButton_GtkCheckButton, setUseUnderline);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcheckbutton_gtkcheckbutton_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcheckbutton_gtkcheckbutton_newwithlabel, 0, 1, IS_LONG, 0)
	ZEND_ARG_INFO(0, label)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcheckbutton_gtkcheckbutton_newwithmnemonic, 0, 1, IS_LONG, 0)
	ZEND_ARG_INFO(0, label)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcheckbutton_gtkcheckbutton_getactive, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcheckbutton_gtkcheckbutton_getchild, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcheckbutton_gtkcheckbutton_getinconsistent, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkcheckbutton_gtkcheckbutton_getlabel, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcheckbutton_gtkcheckbutton_getuseunderline, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcheckbutton_gtkcheckbutton_setactive, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, setting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcheckbutton_gtkcheckbutton_setchild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcheckbutton_gtkcheckbutton_setgroup, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, group, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcheckbutton_gtkcheckbutton_setinconsistent, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, inconsistent, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcheckbutton_gtkcheckbutton_setlabel, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, label)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcheckbutton_gtkcheckbutton_setuseunderline, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, setting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkcheckbutton_gtkcheckbutton_method_entry) {
	PHP_ME(Gtk_Gtk_GtkCheckButton_GtkCheckButton, new_, arginfo_gtk_gtk_gtkcheckbutton_gtkcheckbutton_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCheckButton_GtkCheckButton, newWithLabel, arginfo_gtk_gtk_gtkcheckbutton_gtkcheckbutton_newwithlabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCheckButton_GtkCheckButton, newWithMnemonic, arginfo_gtk_gtk_gtkcheckbutton_gtkcheckbutton_newwithmnemonic, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCheckButton_GtkCheckButton, getActive, arginfo_gtk_gtk_gtkcheckbutton_gtkcheckbutton_getactive, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCheckButton_GtkCheckButton, getChild, arginfo_gtk_gtk_gtkcheckbutton_gtkcheckbutton_getchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCheckButton_GtkCheckButton, getInconsistent, arginfo_gtk_gtk_gtkcheckbutton_gtkcheckbutton_getinconsistent, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCheckButton_GtkCheckButton, getLabel, arginfo_gtk_gtk_gtkcheckbutton_gtkcheckbutton_getlabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCheckButton_GtkCheckButton, getUseUnderline, arginfo_gtk_gtk_gtkcheckbutton_gtkcheckbutton_getuseunderline, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCheckButton_GtkCheckButton, setActive, arginfo_gtk_gtk_gtkcheckbutton_gtkcheckbutton_setactive, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCheckButton_GtkCheckButton, setChild, arginfo_gtk_gtk_gtkcheckbutton_gtkcheckbutton_setchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCheckButton_GtkCheckButton, setGroup, arginfo_gtk_gtk_gtkcheckbutton_gtkcheckbutton_setgroup, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCheckButton_GtkCheckButton, setInconsistent, arginfo_gtk_gtk_gtkcheckbutton_gtkcheckbutton_setinconsistent, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCheckButton_GtkCheckButton, setLabel, arginfo_gtk_gtk_gtkcheckbutton_gtkcheckbutton_setlabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCheckButton_GtkCheckButton, setUseUnderline, arginfo_gtk_gtk_gtkcheckbutton_gtkcheckbutton_setuseunderline, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
