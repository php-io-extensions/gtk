
extern zend_class_entry *gtk_gtk_gtknotebook_gtknotebook_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkNotebook_GtkNotebook);

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, new_);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, appendPage);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, appendPageMenu);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, detachTab);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getActionWidget);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getCurrentPage);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getGroupName);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getMenuLabel);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getMenuLabelText);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getNPages);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getNthPage);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getPage);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getPages);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getScrollable);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getShowBorder);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getShowTabs);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getTabDetachable);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getTabLabel);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getTabLabelText);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getTabPos);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getTabReorderable);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, insertPage);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, insertPageMenu);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, nextPage);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, pageNum);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, popupDisable);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, popupEnable);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, prependPage);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, prependPageMenu);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, prevPage);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, removePage);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, reorderChild);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, setActionWidget);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, setCurrentPage);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, setGroupName);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, setMenuLabel);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, setMenuLabelText);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, setScrollable);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, setShowBorder);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, setShowTabs);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, setTabDetachable);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, setTabLabel);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, setTabLabelText);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, setTabPos);
PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, setTabReorderable);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_appendpage, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, tabLabel, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_appendpagemenu, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, tabLabel, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, menuLabel, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_detachtab, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_getactionwidget, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, packType, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_getcurrentpage, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_getgroupname, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_getmenulabel, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_getmenulabeltext, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_getnpages, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_getnthpage, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pageNum, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_getpage, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_getpages, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_getscrollable, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_getshowborder, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_getshowtabs, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_gettabdetachable, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_gettablabel, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_gettablabeltext, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_gettabpos, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_gettabreorderable, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_insertpage, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, tabLabel, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_insertpagemenu, 0, 5, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, tabLabel, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, menuLabel, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_nextpage, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_pagenum, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_popupdisable, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_popupenable, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_prependpage, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, tabLabel, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_prependpagemenu, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, tabLabel, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, menuLabel, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_prevpage, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_removepage, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pageNum, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_reorderchild, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_setactionwidget, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, widget, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, packType, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_setcurrentpage, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pageNum, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_setgroupname, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, groupName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_setmenulabel, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, menuLabel, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_setmenulabeltext, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, menuText, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_setscrollable, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, scrollable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_setshowborder, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, showBorder, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_setshowtabs, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, showTabs, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_settabdetachable, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, detachable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_settablabel, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, tabLabel, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_settablabeltext, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, tabText, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_settabpos, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pos, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebook_gtknotebook_settabreorderable, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, reorderable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtknotebook_gtknotebook_method_entry) {
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, new_, arginfo_gtk_gtk_gtknotebook_gtknotebook_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, appendPage, arginfo_gtk_gtk_gtknotebook_gtknotebook_appendpage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, appendPageMenu, arginfo_gtk_gtk_gtknotebook_gtknotebook_appendpagemenu, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, detachTab, arginfo_gtk_gtk_gtknotebook_gtknotebook_detachtab, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, getActionWidget, arginfo_gtk_gtk_gtknotebook_gtknotebook_getactionwidget, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, getCurrentPage, arginfo_gtk_gtk_gtknotebook_gtknotebook_getcurrentpage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, getGroupName, arginfo_gtk_gtk_gtknotebook_gtknotebook_getgroupname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, getMenuLabel, arginfo_gtk_gtk_gtknotebook_gtknotebook_getmenulabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, getMenuLabelText, arginfo_gtk_gtk_gtknotebook_gtknotebook_getmenulabeltext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, getNPages, arginfo_gtk_gtk_gtknotebook_gtknotebook_getnpages, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, getNthPage, arginfo_gtk_gtk_gtknotebook_gtknotebook_getnthpage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, getPage, arginfo_gtk_gtk_gtknotebook_gtknotebook_getpage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, getPages, arginfo_gtk_gtk_gtknotebook_gtknotebook_getpages, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, getScrollable, arginfo_gtk_gtk_gtknotebook_gtknotebook_getscrollable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, getShowBorder, arginfo_gtk_gtk_gtknotebook_gtknotebook_getshowborder, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, getShowTabs, arginfo_gtk_gtk_gtknotebook_gtknotebook_getshowtabs, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, getTabDetachable, arginfo_gtk_gtk_gtknotebook_gtknotebook_gettabdetachable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, getTabLabel, arginfo_gtk_gtk_gtknotebook_gtknotebook_gettablabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, getTabLabelText, arginfo_gtk_gtk_gtknotebook_gtknotebook_gettablabeltext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, getTabPos, arginfo_gtk_gtk_gtknotebook_gtknotebook_gettabpos, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, getTabReorderable, arginfo_gtk_gtk_gtknotebook_gtknotebook_gettabreorderable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, insertPage, arginfo_gtk_gtk_gtknotebook_gtknotebook_insertpage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, insertPageMenu, arginfo_gtk_gtk_gtknotebook_gtknotebook_insertpagemenu, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, nextPage, arginfo_gtk_gtk_gtknotebook_gtknotebook_nextpage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, pageNum, arginfo_gtk_gtk_gtknotebook_gtknotebook_pagenum, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, popupDisable, arginfo_gtk_gtk_gtknotebook_gtknotebook_popupdisable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, popupEnable, arginfo_gtk_gtk_gtknotebook_gtknotebook_popupenable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, prependPage, arginfo_gtk_gtk_gtknotebook_gtknotebook_prependpage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, prependPageMenu, arginfo_gtk_gtk_gtknotebook_gtknotebook_prependpagemenu, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, prevPage, arginfo_gtk_gtk_gtknotebook_gtknotebook_prevpage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, removePage, arginfo_gtk_gtk_gtknotebook_gtknotebook_removepage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, reorderChild, arginfo_gtk_gtk_gtknotebook_gtknotebook_reorderchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, setActionWidget, arginfo_gtk_gtk_gtknotebook_gtknotebook_setactionwidget, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, setCurrentPage, arginfo_gtk_gtk_gtknotebook_gtknotebook_setcurrentpage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, setGroupName, arginfo_gtk_gtk_gtknotebook_gtknotebook_setgroupname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, setMenuLabel, arginfo_gtk_gtk_gtknotebook_gtknotebook_setmenulabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, setMenuLabelText, arginfo_gtk_gtk_gtknotebook_gtknotebook_setmenulabeltext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, setScrollable, arginfo_gtk_gtk_gtknotebook_gtknotebook_setscrollable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, setShowBorder, arginfo_gtk_gtk_gtknotebook_gtknotebook_setshowborder, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, setShowTabs, arginfo_gtk_gtk_gtknotebook_gtknotebook_setshowtabs, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, setTabDetachable, arginfo_gtk_gtk_gtknotebook_gtknotebook_settabdetachable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, setTabLabel, arginfo_gtk_gtk_gtknotebook_gtknotebook_settablabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, setTabLabelText, arginfo_gtk_gtk_gtknotebook_gtknotebook_settablabeltext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, setTabPos, arginfo_gtk_gtk_gtknotebook_gtknotebook_settabpos, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNotebook_GtkNotebook, setTabReorderable, arginfo_gtk_gtk_gtknotebook_gtknotebook_settabreorderable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
