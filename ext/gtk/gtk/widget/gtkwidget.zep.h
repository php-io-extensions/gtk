
extern zend_class_entry *gtk_gtk_widget_gtkwidget_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_Widget_GtkWidget);

PHP_METHOD(Gtk_GTK_Widget_GtkWidget, gtkWidgetSetVisible);
PHP_METHOD(Gtk_GTK_Widget_GtkWidget, gtkWidgetGetVisible);
PHP_METHOD(Gtk_GTK_Widget_GtkWidget, gtkWidgetSetHexpand);
PHP_METHOD(Gtk_GTK_Widget_GtkWidget, gtkWidgetSetVexpand);
PHP_METHOD(Gtk_GTK_Widget_GtkWidget, gtkWidgetSetHalign);
PHP_METHOD(Gtk_GTK_Widget_GtkWidget, gtkWidgetSetValign);
PHP_METHOD(Gtk_GTK_Widget_GtkWidget, gtkWidgetGetHalign);
PHP_METHOD(Gtk_GTK_Widget_GtkWidget, gtkWidgetGetValign);
PHP_METHOD(Gtk_GTK_Widget_GtkWidget, gtkWidgetSetSizeRequest);
PHP_METHOD(Gtk_GTK_Widget_GtkWidget, gtkWidgetGetWidth);
PHP_METHOD(Gtk_GTK_Widget_GtkWidget, gtkWidgetGetHeight);
PHP_METHOD(Gtk_GTK_Widget_GtkWidget, gtkWidgetQueueDraw);
PHP_METHOD(Gtk_GTK_Widget_GtkWidget, gtkWidgetAddTickCallback);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_widget_gtkwidget_gtkwidgetsetvisible, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, widget, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, visible, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_widget_gtkwidget_gtkwidgetgetvisible, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, widget, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_widget_gtkwidget_gtkwidgetsethexpand, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, widget, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, expand, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_widget_gtkwidget_gtkwidgetsetvexpand, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, widget, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, expand, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_widget_gtkwidget_gtkwidgetsethalign, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, widget, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, align, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_widget_gtkwidget_gtkwidgetsetvalign, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, widget, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, align, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_widget_gtkwidget_gtkwidgetgethalign, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, widget, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_widget_gtkwidget_gtkwidgetgetvalign, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, widget, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_widget_gtkwidget_gtkwidgetsetsizerequest, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, widget, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_widget_gtkwidget_gtkwidgetgetwidth, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, widget, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_widget_gtkwidget_gtkwidgetgetheight, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, widget, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_widget_gtkwidget_gtkwidgetqueuedraw, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, widget, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_widget_gtkwidget_gtkwidgetaddtickcallback, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, widget, IS_LONG, 0)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_widget_gtkwidget_method_entry) {
	PHP_ME(Gtk_GTK_Widget_GtkWidget, gtkWidgetSetVisible, arginfo_gtk_gtk_widget_gtkwidget_gtkwidgetsetvisible, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Widget_GtkWidget, gtkWidgetGetVisible, arginfo_gtk_gtk_widget_gtkwidget_gtkwidgetgetvisible, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Widget_GtkWidget, gtkWidgetSetHexpand, arginfo_gtk_gtk_widget_gtkwidget_gtkwidgetsethexpand, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Widget_GtkWidget, gtkWidgetSetVexpand, arginfo_gtk_gtk_widget_gtkwidget_gtkwidgetsetvexpand, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Widget_GtkWidget, gtkWidgetSetHalign, arginfo_gtk_gtk_widget_gtkwidget_gtkwidgetsethalign, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Widget_GtkWidget, gtkWidgetSetValign, arginfo_gtk_gtk_widget_gtkwidget_gtkwidgetsetvalign, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Widget_GtkWidget, gtkWidgetGetHalign, arginfo_gtk_gtk_widget_gtkwidget_gtkwidgetgethalign, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Widget_GtkWidget, gtkWidgetGetValign, arginfo_gtk_gtk_widget_gtkwidget_gtkwidgetgetvalign, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Widget_GtkWidget, gtkWidgetSetSizeRequest, arginfo_gtk_gtk_widget_gtkwidget_gtkwidgetsetsizerequest, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Widget_GtkWidget, gtkWidgetGetWidth, arginfo_gtk_gtk_widget_gtkwidget_gtkwidgetgetwidth, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Widget_GtkWidget, gtkWidgetGetHeight, arginfo_gtk_gtk_widget_gtkwidget_gtkwidgetgetheight, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Widget_GtkWidget, gtkWidgetQueueDraw, arginfo_gtk_gtk_widget_gtkwidget_gtkwidgetqueuedraw, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Widget_GtkWidget, gtkWidgetAddTickCallback, arginfo_gtk_gtk_widget_gtkwidget_gtkwidgetaddtickcallback, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
