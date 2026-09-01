
extern zend_class_entry *gtk_gtk_gtkstylecontext_gtkstylecontext_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkStyleContext_GtkStyleContext);

PHP_METHOD(Gtk_Gtk_GtkStyleContext_GtkStyleContext, addProviderForDisplay);
PHP_METHOD(Gtk_Gtk_GtkStyleContext_GtkStyleContext, removeProviderForDisplay);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstylecontext_gtkstylecontext_addproviderfordisplay, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, display, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, provider, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, priority, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstylecontext_gtkstylecontext_removeproviderfordisplay, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, display, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, provider, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkstylecontext_gtkstylecontext_method_entry) {
	PHP_ME(Gtk_Gtk_GtkStyleContext_GtkStyleContext, addProviderForDisplay, arginfo_gtk_gtk_gtkstylecontext_gtkstylecontext_addproviderfordisplay, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStyleContext_GtkStyleContext, removeProviderForDisplay, arginfo_gtk_gtk_gtkstylecontext_gtkstylecontext_removeproviderfordisplay, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
