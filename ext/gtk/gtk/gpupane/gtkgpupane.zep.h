
extern zend_class_entry *gtk_gtk_gpupane_gtkgpupane_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_GpuPane_GtkGpuPane);

PHP_METHOD(Gtk_GTK_GpuPane_GtkGpuPane, gtkGpuPaneNew);
PHP_METHOD(Gtk_GTK_GpuPane_GtkGpuPane, gtkGpuPaneNative);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gpupane_gtkgpupane_gtkgpupanenew, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gpupane_gtkgpupane_gtkgpupanenative, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, pane, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gpupane_gtkgpupane_method_entry) {
	PHP_ME(Gtk_GTK_GpuPane_GtkGpuPane, gtkGpuPaneNew, arginfo_gtk_gtk_gpupane_gtkgpupane_gtkgpupanenew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_GpuPane_GtkGpuPane, gtkGpuPaneNative, arginfo_gtk_gtk_gpupane_gtkgpupane_gtkgpupanenative, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
