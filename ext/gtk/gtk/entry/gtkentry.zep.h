
extern zend_class_entry *gtk_gtk_entry_gtkentry_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_Entry_GtkEntry);

PHP_METHOD(Gtk_GTK_Entry_GtkEntry, gtkEntryNew);
PHP_METHOD(Gtk_GTK_Entry_GtkEntry, gtkEntrySetText);
PHP_METHOD(Gtk_GTK_Entry_GtkEntry, gtkEntryGetText);
PHP_METHOD(Gtk_GTK_Entry_GtkEntry, gtkEntrySetPlaceholderText);
PHP_METHOD(Gtk_GTK_Entry_GtkEntry, gtkEntryGetPlaceholderText);
PHP_METHOD(Gtk_GTK_Entry_GtkEntry, gtkEntrySetVisibility);
PHP_METHOD(Gtk_GTK_Entry_GtkEntry, gtkEntryGetVisibility);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_entry_gtkentry_gtkentrynew, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_entry_gtkentry_gtkentrysettext, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, entry, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_entry_gtkentry_gtkentrygettext, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, entry, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_entry_gtkentry_gtkentrysetplaceholdertext, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, entry, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_entry_gtkentry_gtkentrygetplaceholdertext, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, entry, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_entry_gtkentry_gtkentrysetvisibility, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, entry, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, visible, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_entry_gtkentry_gtkentrygetvisibility, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, entry, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_entry_gtkentry_method_entry) {
	PHP_ME(Gtk_GTK_Entry_GtkEntry, gtkEntryNew, arginfo_gtk_gtk_entry_gtkentry_gtkentrynew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Entry_GtkEntry, gtkEntrySetText, arginfo_gtk_gtk_entry_gtkentry_gtkentrysettext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Entry_GtkEntry, gtkEntryGetText, arginfo_gtk_gtk_entry_gtkentry_gtkentrygettext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Entry_GtkEntry, gtkEntrySetPlaceholderText, arginfo_gtk_gtk_entry_gtkentry_gtkentrysetplaceholdertext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Entry_GtkEntry, gtkEntryGetPlaceholderText, arginfo_gtk_gtk_entry_gtkentry_gtkentrygetplaceholdertext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Entry_GtkEntry, gtkEntrySetVisibility, arginfo_gtk_gtk_entry_gtkentry_gtkentrysetvisibility, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Entry_GtkEntry, gtkEntryGetVisibility, arginfo_gtk_gtk_entry_gtkentry_gtkentrygetvisibility, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
