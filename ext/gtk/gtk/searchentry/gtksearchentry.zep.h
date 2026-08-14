
extern zend_class_entry *gtk_gtk_searchentry_gtksearchentry_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_SearchEntry_GtkSearchEntry);

PHP_METHOD(Gtk_GTK_SearchEntry_GtkSearchEntry, gtkSearchEntryNew);
PHP_METHOD(Gtk_GTK_SearchEntry_GtkSearchEntry, gtkSearchEntrySetText);
PHP_METHOD(Gtk_GTK_SearchEntry_GtkSearchEntry, gtkSearchEntryGetText);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_searchentry_gtksearchentry_gtksearchentrynew, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_searchentry_gtksearchentry_gtksearchentrysettext, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, entry, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_searchentry_gtksearchentry_gtksearchentrygettext, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, entry, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_searchentry_gtksearchentry_method_entry) {
	PHP_ME(Gtk_GTK_SearchEntry_GtkSearchEntry, gtkSearchEntryNew, arginfo_gtk_gtk_searchentry_gtksearchentry_gtksearchentrynew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_SearchEntry_GtkSearchEntry, gtkSearchEntrySetText, arginfo_gtk_gtk_searchentry_gtksearchentry_gtksearchentrysettext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_SearchEntry_GtkSearchEntry, gtkSearchEntryGetText, arginfo_gtk_gtk_searchentry_gtksearchentry_gtksearchentrygettext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
