
extern zend_class_entry *gtk_gtk_notebook_gtknotebook_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_Notebook_GtkNotebook);

PHP_METHOD(Gtk_GTK_Notebook_GtkNotebook, gtkNotebookNew);
PHP_METHOD(Gtk_GTK_Notebook_GtkNotebook, gtkNotebookAppendPage);
PHP_METHOD(Gtk_GTK_Notebook_GtkNotebook, gtkNotebookRemovePage);
PHP_METHOD(Gtk_GTK_Notebook_GtkNotebook, gtkNotebookGetNPages);
PHP_METHOD(Gtk_GTK_Notebook_GtkNotebook, gtkNotebookSetCurrentPage);
PHP_METHOD(Gtk_GTK_Notebook_GtkNotebook, gtkNotebookGetCurrentPage);
PHP_METHOD(Gtk_GTK_Notebook_GtkNotebook, gtkNotebookSetTabLabelText);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_notebook_gtknotebook_gtknotebooknew, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_notebook_gtknotebook_gtknotebookappendpage, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, notebook, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, tabLabel, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_notebook_gtknotebook_gtknotebookremovepage, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, notebook, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pageNum, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_notebook_gtknotebook_gtknotebookgetnpages, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, notebook, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_notebook_gtknotebook_gtknotebooksetcurrentpage, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, notebook, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pageNum, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_notebook_gtknotebook_gtknotebookgetcurrentpage, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, notebook, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_notebook_gtknotebook_gtknotebooksettablabeltext, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, notebook, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_notebook_gtknotebook_method_entry) {
	PHP_ME(Gtk_GTK_Notebook_GtkNotebook, gtkNotebookNew, arginfo_gtk_gtk_notebook_gtknotebook_gtknotebooknew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Notebook_GtkNotebook, gtkNotebookAppendPage, arginfo_gtk_gtk_notebook_gtknotebook_gtknotebookappendpage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Notebook_GtkNotebook, gtkNotebookRemovePage, arginfo_gtk_gtk_notebook_gtknotebook_gtknotebookremovepage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Notebook_GtkNotebook, gtkNotebookGetNPages, arginfo_gtk_gtk_notebook_gtknotebook_gtknotebookgetnpages, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Notebook_GtkNotebook, gtkNotebookSetCurrentPage, arginfo_gtk_gtk_notebook_gtknotebook_gtknotebooksetcurrentpage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Notebook_GtkNotebook, gtkNotebookGetCurrentPage, arginfo_gtk_gtk_notebook_gtknotebook_gtknotebookgetcurrentpage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Notebook_GtkNotebook, gtkNotebookSetTabLabelText, arginfo_gtk_gtk_notebook_gtknotebook_gtknotebooksettablabeltext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
