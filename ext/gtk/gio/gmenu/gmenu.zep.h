
extern zend_class_entry *gtk_gio_gmenu_gmenu_ce;

ZEPHIR_INIT_CLASS(Gtk_Gio_GMenu_GMenu);

PHP_METHOD(Gtk_Gio_GMenu_GMenu, new_);
PHP_METHOD(Gtk_Gio_GMenu_GMenu, append);
PHP_METHOD(Gtk_Gio_GMenu_GMenu, appendItem);
PHP_METHOD(Gtk_Gio_GMenu_GMenu, appendSection);
PHP_METHOD(Gtk_Gio_GMenu_GMenu, appendSubmenu);
PHP_METHOD(Gtk_Gio_GMenu_GMenu, freeze);
PHP_METHOD(Gtk_Gio_GMenu_GMenu, insert);
PHP_METHOD(Gtk_Gio_GMenu_GMenu, insertItem);
PHP_METHOD(Gtk_Gio_GMenu_GMenu, insertSection);
PHP_METHOD(Gtk_Gio_GMenu_GMenu, insertSubmenu);
PHP_METHOD(Gtk_Gio_GMenu_GMenu, prepend);
PHP_METHOD(Gtk_Gio_GMenu_GMenu, prependItem);
PHP_METHOD(Gtk_Gio_GMenu_GMenu, prependSection);
PHP_METHOD(Gtk_Gio_GMenu_GMenu, prependSubmenu);
PHP_METHOD(Gtk_Gio_GMenu_GMenu, remove);
PHP_METHOD(Gtk_Gio_GMenu_GMenu, removeAll);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gmenu_gmenu_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gmenu_gmenu_append, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, label)
	ZEND_ARG_INFO(0, detailedAction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gmenu_gmenu_appenditem, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, item, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gmenu_gmenu_appendsection, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, label)
	ZEND_ARG_TYPE_INFO(0, section, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gmenu_gmenu_appendsubmenu, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, label)
	ZEND_ARG_TYPE_INFO(0, submenu, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gmenu_gmenu_freeze, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gmenu_gmenu_insert, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
	ZEND_ARG_INFO(0, label)
	ZEND_ARG_INFO(0, detailedAction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gmenu_gmenu_insertitem, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, item, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gmenu_gmenu_insertsection, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
	ZEND_ARG_INFO(0, label)
	ZEND_ARG_TYPE_INFO(0, section, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gmenu_gmenu_insertsubmenu, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
	ZEND_ARG_INFO(0, label)
	ZEND_ARG_TYPE_INFO(0, submenu, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gmenu_gmenu_prepend, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, label)
	ZEND_ARG_INFO(0, detailedAction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gmenu_gmenu_prependitem, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, item, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gmenu_gmenu_prependsection, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, label)
	ZEND_ARG_TYPE_INFO(0, section, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gmenu_gmenu_prependsubmenu, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, label)
	ZEND_ARG_TYPE_INFO(0, submenu, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gmenu_gmenu_remove, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gmenu_gmenu_removeall, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gio_gmenu_gmenu_method_entry) {
	PHP_ME(Gtk_Gio_GMenu_GMenu, new_, arginfo_gtk_gio_gmenu_gmenu_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GMenu_GMenu, append, arginfo_gtk_gio_gmenu_gmenu_append, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GMenu_GMenu, appendItem, arginfo_gtk_gio_gmenu_gmenu_appenditem, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GMenu_GMenu, appendSection, arginfo_gtk_gio_gmenu_gmenu_appendsection, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GMenu_GMenu, appendSubmenu, arginfo_gtk_gio_gmenu_gmenu_appendsubmenu, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GMenu_GMenu, freeze, arginfo_gtk_gio_gmenu_gmenu_freeze, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GMenu_GMenu, insert, arginfo_gtk_gio_gmenu_gmenu_insert, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GMenu_GMenu, insertItem, arginfo_gtk_gio_gmenu_gmenu_insertitem, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GMenu_GMenu, insertSection, arginfo_gtk_gio_gmenu_gmenu_insertsection, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GMenu_GMenu, insertSubmenu, arginfo_gtk_gio_gmenu_gmenu_insertsubmenu, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GMenu_GMenu, prepend, arginfo_gtk_gio_gmenu_gmenu_prepend, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GMenu_GMenu, prependItem, arginfo_gtk_gio_gmenu_gmenu_prependitem, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GMenu_GMenu, prependSection, arginfo_gtk_gio_gmenu_gmenu_prependsection, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GMenu_GMenu, prependSubmenu, arginfo_gtk_gio_gmenu_gmenu_prependsubmenu, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GMenu_GMenu, remove, arginfo_gtk_gio_gmenu_gmenu_remove, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GMenu_GMenu, removeAll, arginfo_gtk_gio_gmenu_gmenu_removeall, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
