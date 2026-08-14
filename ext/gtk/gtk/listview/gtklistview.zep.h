
extern zend_class_entry *gtk_gtk_listview_gtklistview_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_ListView_GtkListView);

PHP_METHOD(Gtk_GTK_ListView_GtkListView, gtkListViewNew);
PHP_METHOD(Gtk_GTK_ListView_GtkListView, gtkListViewSetModel);
PHP_METHOD(Gtk_GTK_ListView_GtkListView, gtkListViewGetModel);
PHP_METHOD(Gtk_GTK_ListView_GtkListView, gtkListViewSetFactory);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_listview_gtklistview_gtklistviewnew, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, model, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, factory, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_listview_gtklistview_gtklistviewsetmodel, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, view, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, model, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_listview_gtklistview_gtklistviewgetmodel, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, view, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_listview_gtklistview_gtklistviewsetfactory, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, view, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, factory, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_listview_gtklistview_method_entry) {
	PHP_ME(Gtk_GTK_ListView_GtkListView, gtkListViewNew, arginfo_gtk_gtk_listview_gtklistview_gtklistviewnew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_ListView_GtkListView, gtkListViewSetModel, arginfo_gtk_gtk_listview_gtklistview_gtklistviewsetmodel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_ListView_GtkListView, gtkListViewGetModel, arginfo_gtk_gtk_listview_gtklistview_gtklistviewgetmodel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_ListView_GtkListView, gtkListViewSetFactory, arginfo_gtk_gtk_listview_gtklistview_gtklistviewsetfactory, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
