
extern zend_class_entry *gtk_gtk_gtknotebookpage_gtknotebookpage_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkNotebookPage_GtkNotebookPage);

PHP_METHOD(Gtk_Gtk_GtkNotebookPage_GtkNotebookPage, getChild);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtknotebookpage_gtknotebookpage_getchild, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtknotebookpage_gtknotebookpage_method_entry) {
	PHP_ME(Gtk_Gtk_GtkNotebookPage_GtkNotebookPage, getChild, arginfo_gtk_gtk_gtknotebookpage_gtknotebookpage_getchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
