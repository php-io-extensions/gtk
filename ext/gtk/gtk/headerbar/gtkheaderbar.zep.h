
extern zend_class_entry *gtk_gtk_headerbar_gtkheaderbar_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_HeaderBar_GtkHeaderBar);

PHP_METHOD(Gtk_GTK_HeaderBar_GtkHeaderBar, gtkHeaderBarNew);
PHP_METHOD(Gtk_GTK_HeaderBar_GtkHeaderBar, gtkHeaderBarSetTitleWidget);
PHP_METHOD(Gtk_GTK_HeaderBar_GtkHeaderBar, gtkHeaderBarGetTitleWidget);
PHP_METHOD(Gtk_GTK_HeaderBar_GtkHeaderBar, gtkHeaderBarPackStart);
PHP_METHOD(Gtk_GTK_HeaderBar_GtkHeaderBar, gtkHeaderBarPackEnd);
PHP_METHOD(Gtk_GTK_HeaderBar_GtkHeaderBar, gtkHeaderBarRemove);
PHP_METHOD(Gtk_GTK_HeaderBar_GtkHeaderBar, gtkHeaderBarSetShowTitleButtons);
PHP_METHOD(Gtk_GTK_HeaderBar_GtkHeaderBar, gtkHeaderBarGetShowTitleButtons);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_headerbar_gtkheaderbar_gtkheaderbarnew, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_headerbar_gtkheaderbar_gtkheaderbarsettitlewidget, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, bar, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, titleWidget, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_headerbar_gtkheaderbar_gtkheaderbargettitlewidget, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, bar, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_headerbar_gtkheaderbar_gtkheaderbarpackstart, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, bar, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_headerbar_gtkheaderbar_gtkheaderbarpackend, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, bar, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_headerbar_gtkheaderbar_gtkheaderbarremove, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, bar, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_headerbar_gtkheaderbar_gtkheaderbarsetshowtitlebuttons, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, bar, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, show, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_headerbar_gtkheaderbar_gtkheaderbargetshowtitlebuttons, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, bar, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_headerbar_gtkheaderbar_method_entry) {
	PHP_ME(Gtk_GTK_HeaderBar_GtkHeaderBar, gtkHeaderBarNew, arginfo_gtk_gtk_headerbar_gtkheaderbar_gtkheaderbarnew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_HeaderBar_GtkHeaderBar, gtkHeaderBarSetTitleWidget, arginfo_gtk_gtk_headerbar_gtkheaderbar_gtkheaderbarsettitlewidget, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_HeaderBar_GtkHeaderBar, gtkHeaderBarGetTitleWidget, arginfo_gtk_gtk_headerbar_gtkheaderbar_gtkheaderbargettitlewidget, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_HeaderBar_GtkHeaderBar, gtkHeaderBarPackStart, arginfo_gtk_gtk_headerbar_gtkheaderbar_gtkheaderbarpackstart, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_HeaderBar_GtkHeaderBar, gtkHeaderBarPackEnd, arginfo_gtk_gtk_headerbar_gtkheaderbar_gtkheaderbarpackend, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_HeaderBar_GtkHeaderBar, gtkHeaderBarRemove, arginfo_gtk_gtk_headerbar_gtkheaderbar_gtkheaderbarremove, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_HeaderBar_GtkHeaderBar, gtkHeaderBarSetShowTitleButtons, arginfo_gtk_gtk_headerbar_gtkheaderbar_gtkheaderbarsetshowtitlebuttons, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_HeaderBar_GtkHeaderBar, gtkHeaderBarGetShowTitleButtons, arginfo_gtk_gtk_headerbar_gtkheaderbar_gtkheaderbargetshowtitlebuttons, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
