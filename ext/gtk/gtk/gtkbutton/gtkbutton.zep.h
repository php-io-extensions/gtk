
extern zend_class_entry *gtk_gtk_gtkbutton_gtkbutton_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkButton_GtkButton);

PHP_METHOD(Gtk_Gtk_GtkButton_GtkButton, new_);
PHP_METHOD(Gtk_Gtk_GtkButton_GtkButton, newFromIconName);
PHP_METHOD(Gtk_Gtk_GtkButton_GtkButton, newWithLabel);
PHP_METHOD(Gtk_Gtk_GtkButton_GtkButton, newWithMnemonic);
PHP_METHOD(Gtk_Gtk_GtkButton_GtkButton, getCanShrink);
PHP_METHOD(Gtk_Gtk_GtkButton_GtkButton, getChild);
PHP_METHOD(Gtk_Gtk_GtkButton_GtkButton, getHasFrame);
PHP_METHOD(Gtk_Gtk_GtkButton_GtkButton, getIconName);
PHP_METHOD(Gtk_Gtk_GtkButton_GtkButton, getLabel);
PHP_METHOD(Gtk_Gtk_GtkButton_GtkButton, getUseUnderline);
PHP_METHOD(Gtk_Gtk_GtkButton_GtkButton, setCanShrink);
PHP_METHOD(Gtk_Gtk_GtkButton_GtkButton, setChild);
PHP_METHOD(Gtk_Gtk_GtkButton_GtkButton, setHasFrame);
PHP_METHOD(Gtk_Gtk_GtkButton_GtkButton, setIconName);
PHP_METHOD(Gtk_Gtk_GtkButton_GtkButton, setLabel);
PHP_METHOD(Gtk_Gtk_GtkButton_GtkButton, setUseUnderline);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkbutton_gtkbutton_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkbutton_gtkbutton_newfromiconname, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, iconName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkbutton_gtkbutton_newwithlabel, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkbutton_gtkbutton_newwithmnemonic, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkbutton_gtkbutton_getcanshrink, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkbutton_gtkbutton_getchild, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkbutton_gtkbutton_gethasframe, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkbutton_gtkbutton_geticonname, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkbutton_gtkbutton_getlabel, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkbutton_gtkbutton_getuseunderline, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkbutton_gtkbutton_setcanshrink, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, canShrink, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkbutton_gtkbutton_setchild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkbutton_gtkbutton_sethasframe, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, hasFrame, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkbutton_gtkbutton_seticonname, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, iconName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkbutton_gtkbutton_setlabel, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkbutton_gtkbutton_setuseunderline, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, useUnderline, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkbutton_gtkbutton_method_entry) {
	PHP_ME(Gtk_Gtk_GtkButton_GtkButton, new_, arginfo_gtk_gtk_gtkbutton_gtkbutton_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkButton_GtkButton, newFromIconName, arginfo_gtk_gtk_gtkbutton_gtkbutton_newfromiconname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkButton_GtkButton, newWithLabel, arginfo_gtk_gtk_gtkbutton_gtkbutton_newwithlabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkButton_GtkButton, newWithMnemonic, arginfo_gtk_gtk_gtkbutton_gtkbutton_newwithmnemonic, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkButton_GtkButton, getCanShrink, arginfo_gtk_gtk_gtkbutton_gtkbutton_getcanshrink, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkButton_GtkButton, getChild, arginfo_gtk_gtk_gtkbutton_gtkbutton_getchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkButton_GtkButton, getHasFrame, arginfo_gtk_gtk_gtkbutton_gtkbutton_gethasframe, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkButton_GtkButton, getIconName, arginfo_gtk_gtk_gtkbutton_gtkbutton_geticonname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkButton_GtkButton, getLabel, arginfo_gtk_gtk_gtkbutton_gtkbutton_getlabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkButton_GtkButton, getUseUnderline, arginfo_gtk_gtk_gtkbutton_gtkbutton_getuseunderline, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkButton_GtkButton, setCanShrink, arginfo_gtk_gtk_gtkbutton_gtkbutton_setcanshrink, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkButton_GtkButton, setChild, arginfo_gtk_gtk_gtkbutton_gtkbutton_setchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkButton_GtkButton, setHasFrame, arginfo_gtk_gtk_gtkbutton_gtkbutton_sethasframe, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkButton_GtkButton, setIconName, arginfo_gtk_gtk_gtkbutton_gtkbutton_seticonname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkButton_GtkButton, setLabel, arginfo_gtk_gtk_gtkbutton_gtkbutton_setlabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkButton_GtkButton, setUseUnderline, arginfo_gtk_gtk_gtkbutton_gtkbutton_setuseunderline, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
