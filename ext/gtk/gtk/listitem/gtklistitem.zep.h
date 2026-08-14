
extern zend_class_entry *gtk_gtk_listitem_gtklistitem_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_ListItem_GtkListItem);

PHP_METHOD(Gtk_GTK_ListItem_GtkListItem, gtkSignalListItemFactoryNew);
PHP_METHOD(Gtk_GTK_ListItem_GtkListItem, gtkListItemSetChild);
PHP_METHOD(Gtk_GTK_ListItem_GtkListItem, gtkListItemGetChild);
PHP_METHOD(Gtk_GTK_ListItem_GtkListItem, gtkListItemGetItem);
PHP_METHOD(Gtk_GTK_ListItem_GtkListItem, gtkListItemGetPosition);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_listitem_gtklistitem_gtksignallistitemfactorynew, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_listitem_gtklistitem_gtklistitemsetchild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, item, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_listitem_gtklistitem_gtklistitemgetchild, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, item, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_listitem_gtklistitem_gtklistitemgetitem, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, item, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_listitem_gtklistitem_gtklistitemgetposition, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, item, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_listitem_gtklistitem_method_entry) {
	PHP_ME(Gtk_GTK_ListItem_GtkListItem, gtkSignalListItemFactoryNew, arginfo_gtk_gtk_listitem_gtklistitem_gtksignallistitemfactorynew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_ListItem_GtkListItem, gtkListItemSetChild, arginfo_gtk_gtk_listitem_gtklistitem_gtklistitemsetchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_ListItem_GtkListItem, gtkListItemGetChild, arginfo_gtk_gtk_listitem_gtklistitem_gtklistitemgetchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_ListItem_GtkListItem, gtkListItemGetItem, arginfo_gtk_gtk_listitem_gtklistitem_gtklistitemgetitem, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_ListItem_GtkListItem, gtkListItemGetPosition, arginfo_gtk_gtk_listitem_gtklistitem_gtklistitemgetposition, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
