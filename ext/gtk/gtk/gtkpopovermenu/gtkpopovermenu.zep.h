
extern zend_class_entry *gtk_gtk_gtkpopovermenu_gtkpopovermenu_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkPopoverMenu_GtkPopoverMenu);

PHP_METHOD(Gtk_Gtk_GtkPopoverMenu_GtkPopoverMenu, newFromModel);
PHP_METHOD(Gtk_Gtk_GtkPopoverMenu_GtkPopoverMenu, newFromModelFull);
PHP_METHOD(Gtk_Gtk_GtkPopoverMenu_GtkPopoverMenu, addChild);
PHP_METHOD(Gtk_Gtk_GtkPopoverMenu_GtkPopoverMenu, getFlags);
PHP_METHOD(Gtk_Gtk_GtkPopoverMenu_GtkPopoverMenu, getMenuModel);
PHP_METHOD(Gtk_Gtk_GtkPopoverMenu_GtkPopoverMenu, removeChild);
PHP_METHOD(Gtk_Gtk_GtkPopoverMenu_GtkPopoverMenu, setFlags);
PHP_METHOD(Gtk_Gtk_GtkPopoverMenu_GtkPopoverMenu, setMenuModel);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopovermenu_gtkpopovermenu_newfrommodel, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, model, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopovermenu_gtkpopovermenu_newfrommodelfull, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, model, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopovermenu_gtkpopovermenu_addchild, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopovermenu_gtkpopovermenu_getflags, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopovermenu_gtkpopovermenu_getmenumodel, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopovermenu_gtkpopovermenu_removechild, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopovermenu_gtkpopovermenu_setflags, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopovermenu_gtkpopovermenu_setmenumodel, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, model, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkpopovermenu_gtkpopovermenu_method_entry) {
	PHP_ME(Gtk_Gtk_GtkPopoverMenu_GtkPopoverMenu, newFromModel, arginfo_gtk_gtk_gtkpopovermenu_gtkpopovermenu_newfrommodel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPopoverMenu_GtkPopoverMenu, newFromModelFull, arginfo_gtk_gtk_gtkpopovermenu_gtkpopovermenu_newfrommodelfull, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPopoverMenu_GtkPopoverMenu, addChild, arginfo_gtk_gtk_gtkpopovermenu_gtkpopovermenu_addchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPopoverMenu_GtkPopoverMenu, getFlags, arginfo_gtk_gtk_gtkpopovermenu_gtkpopovermenu_getflags, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPopoverMenu_GtkPopoverMenu, getMenuModel, arginfo_gtk_gtk_gtkpopovermenu_gtkpopovermenu_getmenumodel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPopoverMenu_GtkPopoverMenu, removeChild, arginfo_gtk_gtk_gtkpopovermenu_gtkpopovermenu_removechild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPopoverMenu_GtkPopoverMenu, setFlags, arginfo_gtk_gtk_gtkpopovermenu_gtkpopovermenu_setflags, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPopoverMenu_GtkPopoverMenu, setMenuModel, arginfo_gtk_gtk_gtkpopovermenu_gtkpopovermenu_setmenumodel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
