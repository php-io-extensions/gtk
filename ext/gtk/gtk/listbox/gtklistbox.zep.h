
extern zend_class_entry *gtk_gtk_listbox_gtklistbox_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_ListBox_GtkListBox);

PHP_METHOD(Gtk_GTK_ListBox_GtkListBox, gtkListBoxNew);
PHP_METHOD(Gtk_GTK_ListBox_GtkListBox, gtkListBoxAppend);
PHP_METHOD(Gtk_GTK_ListBox_GtkListBox, gtkListBoxRemove);
PHP_METHOD(Gtk_GTK_ListBox_GtkListBox, gtkListBoxGetSelectedRow);
PHP_METHOD(Gtk_GTK_ListBox_GtkListBox, gtkListBoxSelectRow);
PHP_METHOD(Gtk_GTK_ListBox_GtkListBox, gtkListBoxGetRowAtIndex);
PHP_METHOD(Gtk_GTK_ListBox_GtkListBox, gtkListBoxRowGetIndex);
PHP_METHOD(Gtk_GTK_ListBox_GtkListBox, gtkListBoxRowGetChild);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_listbox_gtklistbox_gtklistboxnew, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_listbox_gtklistbox_gtklistboxappend, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, box, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_listbox_gtklistbox_gtklistboxremove, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, box, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_listbox_gtklistbox_gtklistboxgetselectedrow, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, box, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_listbox_gtklistbox_gtklistboxselectrow, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, box, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, row, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_listbox_gtklistbox_gtklistboxgetrowatindex, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, box, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, index, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_listbox_gtklistbox_gtklistboxrowgetindex, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, row, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_listbox_gtklistbox_gtklistboxrowgetchild, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, row, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_listbox_gtklistbox_method_entry) {
	PHP_ME(Gtk_GTK_ListBox_GtkListBox, gtkListBoxNew, arginfo_gtk_gtk_listbox_gtklistbox_gtklistboxnew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_ListBox_GtkListBox, gtkListBoxAppend, arginfo_gtk_gtk_listbox_gtklistbox_gtklistboxappend, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_ListBox_GtkListBox, gtkListBoxRemove, arginfo_gtk_gtk_listbox_gtklistbox_gtklistboxremove, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_ListBox_GtkListBox, gtkListBoxGetSelectedRow, arginfo_gtk_gtk_listbox_gtklistbox_gtklistboxgetselectedrow, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_ListBox_GtkListBox, gtkListBoxSelectRow, arginfo_gtk_gtk_listbox_gtklistbox_gtklistboxselectrow, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_ListBox_GtkListBox, gtkListBoxGetRowAtIndex, arginfo_gtk_gtk_listbox_gtklistbox_gtklistboxgetrowatindex, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_ListBox_GtkListBox, gtkListBoxRowGetIndex, arginfo_gtk_gtk_listbox_gtklistbox_gtklistboxrowgetindex, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_ListBox_GtkListBox, gtkListBoxRowGetChild, arginfo_gtk_gtk_listbox_gtklistbox_gtklistboxrowgetchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
