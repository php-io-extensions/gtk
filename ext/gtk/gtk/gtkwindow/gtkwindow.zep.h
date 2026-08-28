
extern zend_class_entry *gtk_gtk_gtkwindow_gtkwindow_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkWindow_GtkWindow);

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, new_);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getDefaultIconName);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getToplevels);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, listToplevels);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setAutoStartupNotification);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setDefaultIconName);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setInteractiveDebugging);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, close);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, destroy);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, fullscreen);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, fullscreenOnMonitor);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getApplication);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getChild);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getDecorated);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getDefaultSize);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getDefaultWidget);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getDeletable);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getDestroyWithParent);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getFocus);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getFocusVisible);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getGroup);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getHandleMenubarAccel);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getHideOnClose);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getIconName);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getMnemonicsVisible);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getModal);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getResizable);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getTitle);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getTitlebar);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getTransientFor);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, hasGroup);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, isActive);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, isFullscreen);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, isMaximized);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, isSuspended);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, maximize);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, minimize);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, present);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setApplication);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setChild);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setDecorated);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setDefaultSize);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setDefaultWidget);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setDeletable);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setDestroyWithParent);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setDisplay);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setFocus);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setFocusVisible);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setHandleMenubarAccel);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setHideOnClose);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setIconName);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setMnemonicsVisible);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setModal);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setResizable);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setStartupId);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setTitle);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setTitlebar);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setTransientFor);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, unfullscreen);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, unmaximize);
PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, unminimize);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_getdefaulticonname, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_gettoplevels, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_listtoplevels, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_setautostartupnotification, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, setting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_setdefaulticonname, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_setinteractivedebugging, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, enable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_close, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_destroy, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_fullscreen, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_fullscreenonmonitor, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, monitor, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_getapplication, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_getchild, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_getdecorated, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_getdefaultsize, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_getdefaultwidget, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_getdeletable, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_getdestroywithparent, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_getfocus, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_getfocusvisible, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_getgroup, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_gethandlemenubaraccel, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_gethideonclose, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_geticonname, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_getmnemonicsvisible, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_getmodal, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_getresizable, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_gettitle, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_gettitlebar, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_gettransientfor, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_hasgroup, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_isactive, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_isfullscreen, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_ismaximized, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_issuspended, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_maximize, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_minimize, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_present, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_setapplication, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, application, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_setchild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_setdecorated, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, setting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_setdefaultsize, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_setdefaultwidget, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, defaultWidget, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_setdeletable, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, setting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_setdestroywithparent, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, setting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_setdisplay, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, display, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_setfocus, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, focus, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_setfocusvisible, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, setting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_sethandlemenubaraccel, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handleMenubarAccel, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_sethideonclose, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, setting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_seticonname, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_setmnemonicsvisible, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, setting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_setmodal, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, modal, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_setresizable, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, resizable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_setstartupid, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, startupId, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_settitle, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, title)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_settitlebar, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, titlebar, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_settransientfor, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, parent, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_unfullscreen, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_unmaximize, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkwindow_gtkwindow_unminimize, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkwindow_gtkwindow_method_entry) {
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, new_, arginfo_gtk_gtk_gtkwindow_gtkwindow_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, getDefaultIconName, arginfo_gtk_gtk_gtkwindow_gtkwindow_getdefaulticonname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, getToplevels, arginfo_gtk_gtk_gtkwindow_gtkwindow_gettoplevels, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, listToplevels, arginfo_gtk_gtk_gtkwindow_gtkwindow_listtoplevels, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, setAutoStartupNotification, arginfo_gtk_gtk_gtkwindow_gtkwindow_setautostartupnotification, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, setDefaultIconName, arginfo_gtk_gtk_gtkwindow_gtkwindow_setdefaulticonname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, setInteractiveDebugging, arginfo_gtk_gtk_gtkwindow_gtkwindow_setinteractivedebugging, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, close, arginfo_gtk_gtk_gtkwindow_gtkwindow_close, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, destroy, arginfo_gtk_gtk_gtkwindow_gtkwindow_destroy, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, fullscreen, arginfo_gtk_gtk_gtkwindow_gtkwindow_fullscreen, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, fullscreenOnMonitor, arginfo_gtk_gtk_gtkwindow_gtkwindow_fullscreenonmonitor, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, getApplication, arginfo_gtk_gtk_gtkwindow_gtkwindow_getapplication, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, getChild, arginfo_gtk_gtk_gtkwindow_gtkwindow_getchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, getDecorated, arginfo_gtk_gtk_gtkwindow_gtkwindow_getdecorated, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, getDefaultSize, arginfo_gtk_gtk_gtkwindow_gtkwindow_getdefaultsize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, getDefaultWidget, arginfo_gtk_gtk_gtkwindow_gtkwindow_getdefaultwidget, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, getDeletable, arginfo_gtk_gtk_gtkwindow_gtkwindow_getdeletable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, getDestroyWithParent, arginfo_gtk_gtk_gtkwindow_gtkwindow_getdestroywithparent, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, getFocus, arginfo_gtk_gtk_gtkwindow_gtkwindow_getfocus, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, getFocusVisible, arginfo_gtk_gtk_gtkwindow_gtkwindow_getfocusvisible, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, getGroup, arginfo_gtk_gtk_gtkwindow_gtkwindow_getgroup, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, getHandleMenubarAccel, arginfo_gtk_gtk_gtkwindow_gtkwindow_gethandlemenubaraccel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, getHideOnClose, arginfo_gtk_gtk_gtkwindow_gtkwindow_gethideonclose, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, getIconName, arginfo_gtk_gtk_gtkwindow_gtkwindow_geticonname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, getMnemonicsVisible, arginfo_gtk_gtk_gtkwindow_gtkwindow_getmnemonicsvisible, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, getModal, arginfo_gtk_gtk_gtkwindow_gtkwindow_getmodal, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, getResizable, arginfo_gtk_gtk_gtkwindow_gtkwindow_getresizable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, getTitle, arginfo_gtk_gtk_gtkwindow_gtkwindow_gettitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, getTitlebar, arginfo_gtk_gtk_gtkwindow_gtkwindow_gettitlebar, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, getTransientFor, arginfo_gtk_gtk_gtkwindow_gtkwindow_gettransientfor, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, hasGroup, arginfo_gtk_gtk_gtkwindow_gtkwindow_hasgroup, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, isActive, arginfo_gtk_gtk_gtkwindow_gtkwindow_isactive, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, isFullscreen, arginfo_gtk_gtk_gtkwindow_gtkwindow_isfullscreen, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, isMaximized, arginfo_gtk_gtk_gtkwindow_gtkwindow_ismaximized, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, isSuspended, arginfo_gtk_gtk_gtkwindow_gtkwindow_issuspended, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, maximize, arginfo_gtk_gtk_gtkwindow_gtkwindow_maximize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, minimize, arginfo_gtk_gtk_gtkwindow_gtkwindow_minimize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, present, arginfo_gtk_gtk_gtkwindow_gtkwindow_present, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, setApplication, arginfo_gtk_gtk_gtkwindow_gtkwindow_setapplication, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, setChild, arginfo_gtk_gtk_gtkwindow_gtkwindow_setchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, setDecorated, arginfo_gtk_gtk_gtkwindow_gtkwindow_setdecorated, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, setDefaultSize, arginfo_gtk_gtk_gtkwindow_gtkwindow_setdefaultsize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, setDefaultWidget, arginfo_gtk_gtk_gtkwindow_gtkwindow_setdefaultwidget, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, setDeletable, arginfo_gtk_gtk_gtkwindow_gtkwindow_setdeletable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, setDestroyWithParent, arginfo_gtk_gtk_gtkwindow_gtkwindow_setdestroywithparent, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, setDisplay, arginfo_gtk_gtk_gtkwindow_gtkwindow_setdisplay, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, setFocus, arginfo_gtk_gtk_gtkwindow_gtkwindow_setfocus, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, setFocusVisible, arginfo_gtk_gtk_gtkwindow_gtkwindow_setfocusvisible, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, setHandleMenubarAccel, arginfo_gtk_gtk_gtkwindow_gtkwindow_sethandlemenubaraccel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, setHideOnClose, arginfo_gtk_gtk_gtkwindow_gtkwindow_sethideonclose, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, setIconName, arginfo_gtk_gtk_gtkwindow_gtkwindow_seticonname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, setMnemonicsVisible, arginfo_gtk_gtk_gtkwindow_gtkwindow_setmnemonicsvisible, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, setModal, arginfo_gtk_gtk_gtkwindow_gtkwindow_setmodal, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, setResizable, arginfo_gtk_gtk_gtkwindow_gtkwindow_setresizable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, setStartupId, arginfo_gtk_gtk_gtkwindow_gtkwindow_setstartupid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, setTitle, arginfo_gtk_gtk_gtkwindow_gtkwindow_settitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, setTitlebar, arginfo_gtk_gtk_gtkwindow_gtkwindow_settitlebar, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, setTransientFor, arginfo_gtk_gtk_gtkwindow_gtkwindow_settransientfor, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, unfullscreen, arginfo_gtk_gtk_gtkwindow_gtkwindow_unfullscreen, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, unmaximize, arginfo_gtk_gtk_gtkwindow_gtkwindow_unmaximize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkWindow_GtkWindow, unminimize, arginfo_gtk_gtk_gtkwindow_gtkwindow_unminimize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
