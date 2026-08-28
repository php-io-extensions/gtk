
extern zend_class_entry *gtk_gtk_gtkcenterbox_gtkcenterbox_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkCenterBox_GtkCenterBox);

PHP_METHOD(Gtk_Gtk_GtkCenterBox_GtkCenterBox, new_);
PHP_METHOD(Gtk_Gtk_GtkCenterBox_GtkCenterBox, getBaselinePosition);
PHP_METHOD(Gtk_Gtk_GtkCenterBox_GtkCenterBox, getCenterWidget);
PHP_METHOD(Gtk_Gtk_GtkCenterBox_GtkCenterBox, getEndWidget);
PHP_METHOD(Gtk_Gtk_GtkCenterBox_GtkCenterBox, getShrinkCenterLast);
PHP_METHOD(Gtk_Gtk_GtkCenterBox_GtkCenterBox, getStartWidget);
PHP_METHOD(Gtk_Gtk_GtkCenterBox_GtkCenterBox, setBaselinePosition);
PHP_METHOD(Gtk_Gtk_GtkCenterBox_GtkCenterBox, setCenterWidget);
PHP_METHOD(Gtk_Gtk_GtkCenterBox_GtkCenterBox, setEndWidget);
PHP_METHOD(Gtk_Gtk_GtkCenterBox_GtkCenterBox, setShrinkCenterLast);
PHP_METHOD(Gtk_Gtk_GtkCenterBox_GtkCenterBox, setStartWidget);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcenterbox_gtkcenterbox_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcenterbox_gtkcenterbox_getbaselineposition, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcenterbox_gtkcenterbox_getcenterwidget, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcenterbox_gtkcenterbox_getendwidget, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcenterbox_gtkcenterbox_getshrinkcenterlast, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcenterbox_gtkcenterbox_getstartwidget, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcenterbox_gtkcenterbox_setbaselineposition, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcenterbox_gtkcenterbox_setcenterwidget, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcenterbox_gtkcenterbox_setendwidget, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcenterbox_gtkcenterbox_setshrinkcenterlast, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, shrinkCenterLast, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcenterbox_gtkcenterbox_setstartwidget, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkcenterbox_gtkcenterbox_method_entry) {
	PHP_ME(Gtk_Gtk_GtkCenterBox_GtkCenterBox, new_, arginfo_gtk_gtk_gtkcenterbox_gtkcenterbox_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCenterBox_GtkCenterBox, getBaselinePosition, arginfo_gtk_gtk_gtkcenterbox_gtkcenterbox_getbaselineposition, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCenterBox_GtkCenterBox, getCenterWidget, arginfo_gtk_gtk_gtkcenterbox_gtkcenterbox_getcenterwidget, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCenterBox_GtkCenterBox, getEndWidget, arginfo_gtk_gtk_gtkcenterbox_gtkcenterbox_getendwidget, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCenterBox_GtkCenterBox, getShrinkCenterLast, arginfo_gtk_gtk_gtkcenterbox_gtkcenterbox_getshrinkcenterlast, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCenterBox_GtkCenterBox, getStartWidget, arginfo_gtk_gtk_gtkcenterbox_gtkcenterbox_getstartwidget, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCenterBox_GtkCenterBox, setBaselinePosition, arginfo_gtk_gtk_gtkcenterbox_gtkcenterbox_setbaselineposition, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCenterBox_GtkCenterBox, setCenterWidget, arginfo_gtk_gtk_gtkcenterbox_gtkcenterbox_setcenterwidget, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCenterBox_GtkCenterBox, setEndWidget, arginfo_gtk_gtk_gtkcenterbox_gtkcenterbox_setendwidget, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCenterBox_GtkCenterBox, setShrinkCenterLast, arginfo_gtk_gtk_gtkcenterbox_gtkcenterbox_setshrinkcenterlast, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCenterBox_GtkCenterBox, setStartWidget, arginfo_gtk_gtk_gtkcenterbox_gtkcenterbox_setstartwidget, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
