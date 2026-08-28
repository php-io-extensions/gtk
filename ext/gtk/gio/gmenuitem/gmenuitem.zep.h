
extern zend_class_entry *gtk_gio_gmenuitem_gmenuitem_ce;

ZEPHIR_INIT_CLASS(Gtk_Gio_GMenuItem_GMenuItem);

PHP_METHOD(Gtk_Gio_GMenuItem_GMenuItem, new_);
PHP_METHOD(Gtk_Gio_GMenuItem_GMenuItem, newFromModel);
PHP_METHOD(Gtk_Gio_GMenuItem_GMenuItem, newSection);
PHP_METHOD(Gtk_Gio_GMenuItem_GMenuItem, newSubmenu);
PHP_METHOD(Gtk_Gio_GMenuItem_GMenuItem, getLink);
PHP_METHOD(Gtk_Gio_GMenuItem_GMenuItem, setDetailedAction);
PHP_METHOD(Gtk_Gio_GMenuItem_GMenuItem, setIcon);
PHP_METHOD(Gtk_Gio_GMenuItem_GMenuItem, setLabel);
PHP_METHOD(Gtk_Gio_GMenuItem_GMenuItem, setLink);
PHP_METHOD(Gtk_Gio_GMenuItem_GMenuItem, setSection);
PHP_METHOD(Gtk_Gio_GMenuItem_GMenuItem, setSubmenu);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gmenuitem_gmenuitem_new_, 0, 2, IS_LONG, 0)
	ZEND_ARG_INFO(0, label)
	ZEND_ARG_INFO(0, detailedAction)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gmenuitem_gmenuitem_newfrommodel, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, model, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, itemIndex, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gmenuitem_gmenuitem_newsection, 0, 2, IS_LONG, 0)
	ZEND_ARG_INFO(0, label)
	ZEND_ARG_TYPE_INFO(0, section, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gmenuitem_gmenuitem_newsubmenu, 0, 2, IS_LONG, 0)
	ZEND_ARG_INFO(0, label)
	ZEND_ARG_TYPE_INFO(0, submenu, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gmenuitem_gmenuitem_getlink, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, link, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gmenuitem_gmenuitem_setdetailedaction, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, detailedAction, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gmenuitem_gmenuitem_seticon, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, icon, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gmenuitem_gmenuitem_setlabel, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, label)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gmenuitem_gmenuitem_setlink, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, link, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, model, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gmenuitem_gmenuitem_setsection, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, section, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gmenuitem_gmenuitem_setsubmenu, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, submenu, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gio_gmenuitem_gmenuitem_method_entry) {
	PHP_ME(Gtk_Gio_GMenuItem_GMenuItem, new_, arginfo_gtk_gio_gmenuitem_gmenuitem_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GMenuItem_GMenuItem, newFromModel, arginfo_gtk_gio_gmenuitem_gmenuitem_newfrommodel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GMenuItem_GMenuItem, newSection, arginfo_gtk_gio_gmenuitem_gmenuitem_newsection, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GMenuItem_GMenuItem, newSubmenu, arginfo_gtk_gio_gmenuitem_gmenuitem_newsubmenu, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GMenuItem_GMenuItem, getLink, arginfo_gtk_gio_gmenuitem_gmenuitem_getlink, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GMenuItem_GMenuItem, setDetailedAction, arginfo_gtk_gio_gmenuitem_gmenuitem_setdetailedaction, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GMenuItem_GMenuItem, setIcon, arginfo_gtk_gio_gmenuitem_gmenuitem_seticon, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GMenuItem_GMenuItem, setLabel, arginfo_gtk_gio_gmenuitem_gmenuitem_setlabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GMenuItem_GMenuItem, setLink, arginfo_gtk_gio_gmenuitem_gmenuitem_setlink, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GMenuItem_GMenuItem, setSection, arginfo_gtk_gio_gmenuitem_gmenuitem_setsection, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GMenuItem_GMenuItem, setSubmenu, arginfo_gtk_gio_gmenuitem_gmenuitem_setsubmenu, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
