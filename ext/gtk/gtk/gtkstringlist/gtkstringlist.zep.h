
extern zend_class_entry *gtk_gtk_gtkstringlist_gtkstringlist_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkStringList_GtkStringList);

PHP_METHOD(Gtk_Gtk_GtkStringList_GtkStringList, new_);
PHP_METHOD(Gtk_Gtk_GtkStringList_GtkStringList, append);
PHP_METHOD(Gtk_Gtk_GtkStringList_GtkStringList, find);
PHP_METHOD(Gtk_Gtk_GtkStringList_GtkStringList, getString);
PHP_METHOD(Gtk_Gtk_GtkStringList_GtkStringList, remove);
PHP_METHOD(Gtk_Gtk_GtkStringList_GtkStringList, splice);
PHP_METHOD(Gtk_Gtk_GtkStringList_GtkStringList, take);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstringlist_gtkstringlist_new_, 0, 1, IS_LONG, 0)
	ZEND_ARG_INFO(0, strings)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstringlist_gtkstringlist_append, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, string_, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstringlist_gtkstringlist_find, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, string_, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkstringlist_gtkstringlist_getstring, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstringlist_gtkstringlist_remove, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstringlist_gtkstringlist_splice, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, nRemovals, IS_LONG, 0)
	ZEND_ARG_INFO(0, additions)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstringlist_gtkstringlist_take, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, string_, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkstringlist_gtkstringlist_method_entry) {
	PHP_ME(Gtk_Gtk_GtkStringList_GtkStringList, new_, arginfo_gtk_gtk_gtkstringlist_gtkstringlist_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStringList_GtkStringList, append, arginfo_gtk_gtk_gtkstringlist_gtkstringlist_append, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStringList_GtkStringList, find, arginfo_gtk_gtk_gtkstringlist_gtkstringlist_find, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStringList_GtkStringList, getString, arginfo_gtk_gtk_gtkstringlist_gtkstringlist_getstring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStringList_GtkStringList, remove, arginfo_gtk_gtk_gtkstringlist_gtkstringlist_remove, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStringList_GtkStringList, splice, arginfo_gtk_gtk_gtkstringlist_gtkstringlist_splice, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStringList_GtkStringList, take, arginfo_gtk_gtk_gtkstringlist_gtkstringlist_take, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
