
extern zend_class_entry *gtk_gtk_window_gtkwindow_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_Window_GtkWindow);

PHP_METHOD(Gtk_GTK_Window_GtkWindow, gtkWindowNew);
PHP_METHOD(Gtk_GTK_Window_GtkWindow, gtkApplicationWindowNew);
PHP_METHOD(Gtk_GTK_Window_GtkWindow, gtkWindowSetTitle);
PHP_METHOD(Gtk_GTK_Window_GtkWindow, gtkWindowGetTitle);
PHP_METHOD(Gtk_GTK_Window_GtkWindow, gtkWindowSetDefaultSize);
PHP_METHOD(Gtk_GTK_Window_GtkWindow, gtkWindowGetDefaultSize);
PHP_METHOD(Gtk_GTK_Window_GtkWindow, gtkWindowSetChild);
PHP_METHOD(Gtk_GTK_Window_GtkWindow, gtkWindowGetChild);
PHP_METHOD(Gtk_GTK_Window_GtkWindow, gtkWindowPresent);
PHP_METHOD(Gtk_GTK_Window_GtkWindow, gtkWindowClose);
PHP_METHOD(Gtk_GTK_Window_GtkWindow, gtkWindowDestroy);
PHP_METHOD(Gtk_GTK_Window_GtkWindow, gtkWindowSetTitlebar);
PHP_METHOD(Gtk_GTK_Window_GtkWindow, gtkWindowGetTitlebar);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_window_gtkwindow_gtkwindownew, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_window_gtkwindow_gtkapplicationwindownew, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, app, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_window_gtkwindow_gtkwindowsettitle, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, window, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, title, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_window_gtkwindow_gtkwindowgettitle, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, window, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_window_gtkwindow_gtkwindowsetdefaultsize, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, window, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_window_gtkwindow_gtkwindowgetdefaultsize, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, window, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_window_gtkwindow_gtkwindowsetchild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, window, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_window_gtkwindow_gtkwindowgetchild, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, window, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_window_gtkwindow_gtkwindowpresent, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, window, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_window_gtkwindow_gtkwindowclose, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, window, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_window_gtkwindow_gtkwindowdestroy, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, window, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_window_gtkwindow_gtkwindowsettitlebar, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, window, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, titlebar, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_window_gtkwindow_gtkwindowgettitlebar, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, window, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_window_gtkwindow_method_entry) {
	PHP_ME(Gtk_GTK_Window_GtkWindow, gtkWindowNew, arginfo_gtk_gtk_window_gtkwindow_gtkwindownew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Window_GtkWindow, gtkApplicationWindowNew, arginfo_gtk_gtk_window_gtkwindow_gtkapplicationwindownew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Window_GtkWindow, gtkWindowSetTitle, arginfo_gtk_gtk_window_gtkwindow_gtkwindowsettitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Window_GtkWindow, gtkWindowGetTitle, arginfo_gtk_gtk_window_gtkwindow_gtkwindowgettitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Window_GtkWindow, gtkWindowSetDefaultSize, arginfo_gtk_gtk_window_gtkwindow_gtkwindowsetdefaultsize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Window_GtkWindow, gtkWindowGetDefaultSize, arginfo_gtk_gtk_window_gtkwindow_gtkwindowgetdefaultsize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Window_GtkWindow, gtkWindowSetChild, arginfo_gtk_gtk_window_gtkwindow_gtkwindowsetchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Window_GtkWindow, gtkWindowGetChild, arginfo_gtk_gtk_window_gtkwindow_gtkwindowgetchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Window_GtkWindow, gtkWindowPresent, arginfo_gtk_gtk_window_gtkwindow_gtkwindowpresent, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Window_GtkWindow, gtkWindowClose, arginfo_gtk_gtk_window_gtkwindow_gtkwindowclose, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Window_GtkWindow, gtkWindowDestroy, arginfo_gtk_gtk_window_gtkwindow_gtkwindowdestroy, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Window_GtkWindow, gtkWindowSetTitlebar, arginfo_gtk_gtk_window_gtkwindow_gtkwindowsettitlebar, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Window_GtkWindow, gtkWindowGetTitlebar, arginfo_gtk_gtk_window_gtkwindow_gtkwindowgettitlebar, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
