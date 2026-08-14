
extern zend_class_entry *gtk_gtk_paned_gtkpaned_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_Paned_GtkPaned);

PHP_METHOD(Gtk_GTK_Paned_GtkPaned, gtkPanedNew);
PHP_METHOD(Gtk_GTK_Paned_GtkPaned, gtkPanedSetStartChild);
PHP_METHOD(Gtk_GTK_Paned_GtkPaned, gtkPanedSetEndChild);
PHP_METHOD(Gtk_GTK_Paned_GtkPaned, gtkPanedGetStartChild);
PHP_METHOD(Gtk_GTK_Paned_GtkPaned, gtkPanedGetEndChild);
PHP_METHOD(Gtk_GTK_Paned_GtkPaned, gtkPanedSetPosition);
PHP_METHOD(Gtk_GTK_Paned_GtkPaned, gtkPanedGetPosition);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_paned_gtkpaned_gtkpanednew, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, orientation, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_paned_gtkpaned_gtkpanedsetstartchild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, paned, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_paned_gtkpaned_gtkpanedsetendchild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, paned, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_paned_gtkpaned_gtkpanedgetstartchild, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, paned, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_paned_gtkpaned_gtkpanedgetendchild, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, paned, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_paned_gtkpaned_gtkpanedsetposition, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, paned, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_paned_gtkpaned_gtkpanedgetposition, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, paned, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_paned_gtkpaned_method_entry) {
	PHP_ME(Gtk_GTK_Paned_GtkPaned, gtkPanedNew, arginfo_gtk_gtk_paned_gtkpaned_gtkpanednew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Paned_GtkPaned, gtkPanedSetStartChild, arginfo_gtk_gtk_paned_gtkpaned_gtkpanedsetstartchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Paned_GtkPaned, gtkPanedSetEndChild, arginfo_gtk_gtk_paned_gtkpaned_gtkpanedsetendchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Paned_GtkPaned, gtkPanedGetStartChild, arginfo_gtk_gtk_paned_gtkpaned_gtkpanedgetstartchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Paned_GtkPaned, gtkPanedGetEndChild, arginfo_gtk_gtk_paned_gtkpaned_gtkpanedgetendchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Paned_GtkPaned, gtkPanedSetPosition, arginfo_gtk_gtk_paned_gtkpaned_gtkpanedsetposition, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Paned_GtkPaned, gtkPanedGetPosition, arginfo_gtk_gtk_paned_gtkpaned_gtkpanedgetposition, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
