
extern zend_class_entry *gtk_gtk_gtknoselection_gtknoselection_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkNoSelection_GtkNoSelection);

PHP_METHOD(Gtk_Gtk_GtkNoSelection_GtkNoSelection, new_);
PHP_METHOD(Gtk_Gtk_GtkNoSelection_GtkNoSelection, getModel);
PHP_METHOD(Gtk_Gtk_GtkNoSelection_GtkNoSelection, setModel);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknoselection_gtknoselection_new_, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, model, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknoselection_gtknoselection_getmodel, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknoselection_gtknoselection_setmodel, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, model, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtknoselection_gtknoselection_method_entry) {
	PHP_ME(Gtk_Gtk_GtkNoSelection_GtkNoSelection, new_, arginfo_gtk_gtk_gtknoselection_gtknoselection_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNoSelection_GtkNoSelection, getModel, arginfo_gtk_gtk_gtknoselection_gtknoselection_getmodel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkNoSelection_GtkNoSelection, setModel, arginfo_gtk_gtk_gtknoselection_gtknoselection_setmodel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
