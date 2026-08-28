
extern zend_class_entry *gtk_gtk_gtkbox_gtkbox_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkBox_GtkBox);

PHP_METHOD(Gtk_Gtk_GtkBox_GtkBox, new_);
PHP_METHOD(Gtk_Gtk_GtkBox_GtkBox, append);
PHP_METHOD(Gtk_Gtk_GtkBox_GtkBox, getBaselineChild);
PHP_METHOD(Gtk_Gtk_GtkBox_GtkBox, getBaselinePosition);
PHP_METHOD(Gtk_Gtk_GtkBox_GtkBox, getHomogeneous);
PHP_METHOD(Gtk_Gtk_GtkBox_GtkBox, getSpacing);
PHP_METHOD(Gtk_Gtk_GtkBox_GtkBox, insertChildAfter);
PHP_METHOD(Gtk_Gtk_GtkBox_GtkBox, prepend);
PHP_METHOD(Gtk_Gtk_GtkBox_GtkBox, remove);
PHP_METHOD(Gtk_Gtk_GtkBox_GtkBox, reorderChildAfter);
PHP_METHOD(Gtk_Gtk_GtkBox_GtkBox, setBaselineChild);
PHP_METHOD(Gtk_Gtk_GtkBox_GtkBox, setBaselinePosition);
PHP_METHOD(Gtk_Gtk_GtkBox_GtkBox, setHomogeneous);
PHP_METHOD(Gtk_Gtk_GtkBox_GtkBox, setSpacing);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkbox_gtkbox_new_, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, orientation, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, spacing, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkbox_gtkbox_append, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkbox_gtkbox_getbaselinechild, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkbox_gtkbox_getbaselineposition, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkbox_gtkbox_gethomogeneous, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkbox_gtkbox_getspacing, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkbox_gtkbox_insertchildafter, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, sibling, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkbox_gtkbox_prepend, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkbox_gtkbox_remove, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkbox_gtkbox_reorderchildafter, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, sibling, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkbox_gtkbox_setbaselinechild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkbox_gtkbox_setbaselineposition, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkbox_gtkbox_sethomogeneous, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, homogeneous, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkbox_gtkbox_setspacing, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, spacing, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkbox_gtkbox_method_entry) {
	PHP_ME(Gtk_Gtk_GtkBox_GtkBox, new_, arginfo_gtk_gtk_gtkbox_gtkbox_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkBox_GtkBox, append, arginfo_gtk_gtk_gtkbox_gtkbox_append, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkBox_GtkBox, getBaselineChild, arginfo_gtk_gtk_gtkbox_gtkbox_getbaselinechild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkBox_GtkBox, getBaselinePosition, arginfo_gtk_gtk_gtkbox_gtkbox_getbaselineposition, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkBox_GtkBox, getHomogeneous, arginfo_gtk_gtk_gtkbox_gtkbox_gethomogeneous, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkBox_GtkBox, getSpacing, arginfo_gtk_gtk_gtkbox_gtkbox_getspacing, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkBox_GtkBox, insertChildAfter, arginfo_gtk_gtk_gtkbox_gtkbox_insertchildafter, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkBox_GtkBox, prepend, arginfo_gtk_gtk_gtkbox_gtkbox_prepend, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkBox_GtkBox, remove, arginfo_gtk_gtk_gtkbox_gtkbox_remove, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkBox_GtkBox, reorderChildAfter, arginfo_gtk_gtk_gtkbox_gtkbox_reorderchildafter, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkBox_GtkBox, setBaselineChild, arginfo_gtk_gtk_gtkbox_gtkbox_setbaselinechild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkBox_GtkBox, setBaselinePosition, arginfo_gtk_gtk_gtkbox_gtkbox_setbaselineposition, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkBox_GtkBox, setHomogeneous, arginfo_gtk_gtk_gtkbox_gtkbox_sethomogeneous, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkBox_GtkBox, setSpacing, arginfo_gtk_gtk_gtkbox_gtkbox_setspacing, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
