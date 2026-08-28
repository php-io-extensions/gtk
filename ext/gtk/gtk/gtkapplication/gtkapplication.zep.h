
extern zend_class_entry *gtk_gtk_gtkapplication_gtkapplication_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkApplication_GtkApplication);

PHP_METHOD(Gtk_Gtk_GtkApplication_GtkApplication, new_);
PHP_METHOD(Gtk_Gtk_GtkApplication_GtkApplication, addWindow);
PHP_METHOD(Gtk_Gtk_GtkApplication_GtkApplication, getAccelsForAction);
PHP_METHOD(Gtk_Gtk_GtkApplication_GtkApplication, getActionsForAccel);
PHP_METHOD(Gtk_Gtk_GtkApplication_GtkApplication, getActiveWindow);
PHP_METHOD(Gtk_Gtk_GtkApplication_GtkApplication, getMenuById);
PHP_METHOD(Gtk_Gtk_GtkApplication_GtkApplication, getMenubar);
PHP_METHOD(Gtk_Gtk_GtkApplication_GtkApplication, getWindowById);
PHP_METHOD(Gtk_Gtk_GtkApplication_GtkApplication, getWindows);
PHP_METHOD(Gtk_Gtk_GtkApplication_GtkApplication, inhibit);
PHP_METHOD(Gtk_Gtk_GtkApplication_GtkApplication, listActionDescriptions);
PHP_METHOD(Gtk_Gtk_GtkApplication_GtkApplication, removeWindow);
PHP_METHOD(Gtk_Gtk_GtkApplication_GtkApplication, setAccelsForAction);
PHP_METHOD(Gtk_Gtk_GtkApplication_GtkApplication, setMenubar);
PHP_METHOD(Gtk_Gtk_GtkApplication_GtkApplication, uninhibit);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkapplication_gtkapplication_new_, 0, 2, IS_LONG, 0)
	ZEND_ARG_INFO(0, applicationId)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkapplication_gtkapplication_addwindow, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, window, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkapplication_gtkapplication_getaccelsforaction, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, detailedActionName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkapplication_gtkapplication_getactionsforaccel, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, accel, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkapplication_gtkapplication_getactivewindow, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkapplication_gtkapplication_getmenubyid, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkapplication_gtkapplication_getmenubar, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkapplication_gtkapplication_getwindowbyid, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, id, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkapplication_gtkapplication_getwindows, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkapplication_gtkapplication_inhibit, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, window, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
	ZEND_ARG_INFO(0, reason)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkapplication_gtkapplication_listactiondescriptions, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkapplication_gtkapplication_removewindow, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, window, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkapplication_gtkapplication_setaccelsforaction, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, detailedActionName, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, accels, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkapplication_gtkapplication_setmenubar, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, menubar, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkapplication_gtkapplication_uninhibit, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, cookie, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkapplication_gtkapplication_method_entry) {
	PHP_ME(Gtk_Gtk_GtkApplication_GtkApplication, new_, arginfo_gtk_gtk_gtkapplication_gtkapplication_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkApplication_GtkApplication, addWindow, arginfo_gtk_gtk_gtkapplication_gtkapplication_addwindow, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkApplication_GtkApplication, getAccelsForAction, arginfo_gtk_gtk_gtkapplication_gtkapplication_getaccelsforaction, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkApplication_GtkApplication, getActionsForAccel, arginfo_gtk_gtk_gtkapplication_gtkapplication_getactionsforaccel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkApplication_GtkApplication, getActiveWindow, arginfo_gtk_gtk_gtkapplication_gtkapplication_getactivewindow, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkApplication_GtkApplication, getMenuById, arginfo_gtk_gtk_gtkapplication_gtkapplication_getmenubyid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkApplication_GtkApplication, getMenubar, arginfo_gtk_gtk_gtkapplication_gtkapplication_getmenubar, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkApplication_GtkApplication, getWindowById, arginfo_gtk_gtk_gtkapplication_gtkapplication_getwindowbyid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkApplication_GtkApplication, getWindows, arginfo_gtk_gtk_gtkapplication_gtkapplication_getwindows, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkApplication_GtkApplication, inhibit, arginfo_gtk_gtk_gtkapplication_gtkapplication_inhibit, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkApplication_GtkApplication, listActionDescriptions, arginfo_gtk_gtk_gtkapplication_gtkapplication_listactiondescriptions, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkApplication_GtkApplication, removeWindow, arginfo_gtk_gtk_gtkapplication_gtkapplication_removewindow, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkApplication_GtkApplication, setAccelsForAction, arginfo_gtk_gtk_gtkapplication_gtkapplication_setaccelsforaction, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkApplication_GtkApplication, setMenubar, arginfo_gtk_gtk_gtkapplication_gtkapplication_setmenubar, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkApplication_GtkApplication, uninhibit, arginfo_gtk_gtk_gtkapplication_gtkapplication_uninhibit, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
