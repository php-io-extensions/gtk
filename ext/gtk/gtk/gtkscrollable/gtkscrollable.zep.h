
extern zend_class_entry *gtk_gtk_gtkscrollable_gtkscrollable_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkScrollable_GtkScrollable);

PHP_METHOD(Gtk_Gtk_GtkScrollable_GtkScrollable, getBorder);
PHP_METHOD(Gtk_Gtk_GtkScrollable_GtkScrollable, getHadjustment);
PHP_METHOD(Gtk_Gtk_GtkScrollable_GtkScrollable, getHscrollPolicy);
PHP_METHOD(Gtk_Gtk_GtkScrollable_GtkScrollable, getVadjustment);
PHP_METHOD(Gtk_Gtk_GtkScrollable_GtkScrollable, getVscrollPolicy);
PHP_METHOD(Gtk_Gtk_GtkScrollable_GtkScrollable, setHadjustment);
PHP_METHOD(Gtk_Gtk_GtkScrollable_GtkScrollable, setHscrollPolicy);
PHP_METHOD(Gtk_Gtk_GtkScrollable_GtkScrollable, setVadjustment);
PHP_METHOD(Gtk_Gtk_GtkScrollable_GtkScrollable, setVscrollPolicy);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrollable_gtkscrollable_getborder, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrollable_gtkscrollable_gethadjustment, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrollable_gtkscrollable_gethscrollpolicy, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrollable_gtkscrollable_getvadjustment, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrollable_gtkscrollable_getvscrollpolicy, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrollable_gtkscrollable_sethadjustment, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, hadjustment, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrollable_gtkscrollable_sethscrollpolicy, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, policy, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrollable_gtkscrollable_setvadjustment, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, vadjustment, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkscrollable_gtkscrollable_setvscrollpolicy, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, policy, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkscrollable_gtkscrollable_method_entry) {
	PHP_ME(Gtk_Gtk_GtkScrollable_GtkScrollable, getBorder, arginfo_gtk_gtk_gtkscrollable_gtkscrollable_getborder, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrollable_GtkScrollable, getHadjustment, arginfo_gtk_gtk_gtkscrollable_gtkscrollable_gethadjustment, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrollable_GtkScrollable, getHscrollPolicy, arginfo_gtk_gtk_gtkscrollable_gtkscrollable_gethscrollpolicy, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrollable_GtkScrollable, getVadjustment, arginfo_gtk_gtk_gtkscrollable_gtkscrollable_getvadjustment, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrollable_GtkScrollable, getVscrollPolicy, arginfo_gtk_gtk_gtkscrollable_gtkscrollable_getvscrollpolicy, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrollable_GtkScrollable, setHadjustment, arginfo_gtk_gtk_gtkscrollable_gtkscrollable_sethadjustment, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrollable_GtkScrollable, setHscrollPolicy, arginfo_gtk_gtk_gtkscrollable_gtkscrollable_sethscrollpolicy, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrollable_GtkScrollable, setVadjustment, arginfo_gtk_gtk_gtkscrollable_gtkscrollable_setvadjustment, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkScrollable_GtkScrollable, setVscrollPolicy, arginfo_gtk_gtk_gtkscrollable_gtkscrollable_setvscrollpolicy, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
