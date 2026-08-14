
extern zend_class_entry *gtk_gtk_stringlist_gtkstringlist_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_StringList_GtkStringList);

PHP_METHOD(Gtk_GTK_StringList_GtkStringList, gtkStringListNew);
PHP_METHOD(Gtk_GTK_StringList_GtkStringList, gtkStringListAppend);
PHP_METHOD(Gtk_GTK_StringList_GtkStringList, gtkStringListRemove);
PHP_METHOD(Gtk_GTK_StringList_GtkStringList, gtkStringListGetString);
PHP_METHOD(Gtk_GTK_StringList_GtkStringList, gtkStringListGetNItems);
PHP_METHOD(Gtk_GTK_StringList_GtkStringList, gtkStringObjectGetString);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_stringlist_gtkstringlist_gtkstringlistnew, 0, 1, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, strings, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_stringlist_gtkstringlist_gtkstringlistappend, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, list, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_stringlist_gtkstringlist_gtkstringlistremove, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, list, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_stringlist_gtkstringlist_gtkstringlistgetstring, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, list, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_stringlist_gtkstringlist_gtkstringlistgetnitems, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, list, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_stringlist_gtkstringlist_gtkstringobjectgetstring, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, item, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_stringlist_gtkstringlist_method_entry) {
	PHP_ME(Gtk_GTK_StringList_GtkStringList, gtkStringListNew, arginfo_gtk_gtk_stringlist_gtkstringlist_gtkstringlistnew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_StringList_GtkStringList, gtkStringListAppend, arginfo_gtk_gtk_stringlist_gtkstringlist_gtkstringlistappend, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_StringList_GtkStringList, gtkStringListRemove, arginfo_gtk_gtk_stringlist_gtkstringlist_gtkstringlistremove, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_StringList_GtkStringList, gtkStringListGetString, arginfo_gtk_gtk_stringlist_gtkstringlist_gtkstringlistgetstring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_StringList_GtkStringList, gtkStringListGetNItems, arginfo_gtk_gtk_stringlist_gtkstringlist_gtkstringlistgetnitems, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_StringList_GtkStringList, gtkStringObjectGetString, arginfo_gtk_gtk_stringlist_gtkstringlist_gtkstringobjectgetstring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
