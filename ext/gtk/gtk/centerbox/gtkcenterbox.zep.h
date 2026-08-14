
extern zend_class_entry *gtk_gtk_centerbox_gtkcenterbox_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_CenterBox_GtkCenterBox);

PHP_METHOD(Gtk_GTK_CenterBox_GtkCenterBox, gtkCenterBoxNew);
PHP_METHOD(Gtk_GTK_CenterBox_GtkCenterBox, gtkCenterBoxSetStartWidget);
PHP_METHOD(Gtk_GTK_CenterBox_GtkCenterBox, gtkCenterBoxSetCenterWidget);
PHP_METHOD(Gtk_GTK_CenterBox_GtkCenterBox, gtkCenterBoxSetEndWidget);
PHP_METHOD(Gtk_GTK_CenterBox_GtkCenterBox, gtkCenterBoxGetStartWidget);
PHP_METHOD(Gtk_GTK_CenterBox_GtkCenterBox, gtkCenterBoxGetCenterWidget);
PHP_METHOD(Gtk_GTK_CenterBox_GtkCenterBox, gtkCenterBoxGetEndWidget);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_centerbox_gtkcenterbox_gtkcenterboxnew, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_centerbox_gtkcenterbox_gtkcenterboxsetstartwidget, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, box, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_centerbox_gtkcenterbox_gtkcenterboxsetcenterwidget, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, box, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_centerbox_gtkcenterbox_gtkcenterboxsetendwidget, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, box, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_centerbox_gtkcenterbox_gtkcenterboxgetstartwidget, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, box, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_centerbox_gtkcenterbox_gtkcenterboxgetcenterwidget, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, box, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_centerbox_gtkcenterbox_gtkcenterboxgetendwidget, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, box, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_centerbox_gtkcenterbox_method_entry) {
	PHP_ME(Gtk_GTK_CenterBox_GtkCenterBox, gtkCenterBoxNew, arginfo_gtk_gtk_centerbox_gtkcenterbox_gtkcenterboxnew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_CenterBox_GtkCenterBox, gtkCenterBoxSetStartWidget, arginfo_gtk_gtk_centerbox_gtkcenterbox_gtkcenterboxsetstartwidget, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_CenterBox_GtkCenterBox, gtkCenterBoxSetCenterWidget, arginfo_gtk_gtk_centerbox_gtkcenterbox_gtkcenterboxsetcenterwidget, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_CenterBox_GtkCenterBox, gtkCenterBoxSetEndWidget, arginfo_gtk_gtk_centerbox_gtkcenterbox_gtkcenterboxsetendwidget, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_CenterBox_GtkCenterBox, gtkCenterBoxGetStartWidget, arginfo_gtk_gtk_centerbox_gtkcenterbox_gtkcenterboxgetstartwidget, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_CenterBox_GtkCenterBox, gtkCenterBoxGetCenterWidget, arginfo_gtk_gtk_centerbox_gtkcenterbox_gtkcenterboxgetcenterwidget, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_CenterBox_GtkCenterBox, gtkCenterBoxGetEndWidget, arginfo_gtk_gtk_centerbox_gtkcenterbox_gtkcenterboxgetendwidget, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
