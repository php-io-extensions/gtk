
extern zend_class_entry *gtk_gtk_gtktexttagtable_gtktexttagtable_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkTextTagTable_GtkTextTagTable);

PHP_METHOD(Gtk_Gtk_GtkTextTagTable_GtkTextTagTable, new_);
PHP_METHOD(Gtk_Gtk_GtkTextTagTable_GtkTextTagTable, add);
PHP_METHOD(Gtk_Gtk_GtkTextTagTable_GtkTextTagTable, getSize);
PHP_METHOD(Gtk_Gtk_GtkTextTagTable_GtkTextTagTable, lookup);
PHP_METHOD(Gtk_Gtk_GtkTextTagTable_GtkTextTagTable, remove);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktexttagtable_gtktexttagtable_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktexttagtable_gtktexttagtable_add, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, tag, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktexttagtable_gtktexttagtable_getsize, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktexttagtable_gtktexttagtable_lookup, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktexttagtable_gtktexttagtable_remove, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, tag, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtktexttagtable_gtktexttagtable_method_entry) {
	PHP_ME(Gtk_Gtk_GtkTextTagTable_GtkTextTagTable, new_, arginfo_gtk_gtk_gtktexttagtable_gtktexttagtable_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextTagTable_GtkTextTagTable, add, arginfo_gtk_gtk_gtktexttagtable_gtktexttagtable_add, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextTagTable_GtkTextTagTable, getSize, arginfo_gtk_gtk_gtktexttagtable_gtktexttagtable_getsize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextTagTable_GtkTextTagTable, lookup, arginfo_gtk_gtk_gtktexttagtable_gtktexttagtable_lookup, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextTagTable_GtkTextTagTable, remove, arginfo_gtk_gtk_gtktexttagtable_gtktexttagtable_remove, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
