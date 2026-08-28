
extern zend_class_entry *gtk_gtk_gtklistboxrow_gtklistboxrow_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow);

PHP_METHOD(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, new_);
PHP_METHOD(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, changed);
PHP_METHOD(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, getActivatable);
PHP_METHOD(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, getChild);
PHP_METHOD(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, getHeader);
PHP_METHOD(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, getIndex);
PHP_METHOD(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, getSelectable);
PHP_METHOD(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, isSelected);
PHP_METHOD(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, setActivatable);
PHP_METHOD(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, setChild);
PHP_METHOD(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, setHeader);
PHP_METHOD(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, setSelectable);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistboxrow_gtklistboxrow_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistboxrow_gtklistboxrow_changed, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistboxrow_gtklistboxrow_getactivatable, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistboxrow_gtklistboxrow_getchild, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistboxrow_gtklistboxrow_getheader, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistboxrow_gtklistboxrow_getindex, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistboxrow_gtklistboxrow_getselectable, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistboxrow_gtklistboxrow_isselected, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistboxrow_gtklistboxrow_setactivatable, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, activatable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistboxrow_gtklistboxrow_setchild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistboxrow_gtklistboxrow_setheader, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, header, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistboxrow_gtklistboxrow_setselectable, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, selectable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtklistboxrow_gtklistboxrow_method_entry) {
	PHP_ME(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, new_, arginfo_gtk_gtk_gtklistboxrow_gtklistboxrow_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, changed, arginfo_gtk_gtk_gtklistboxrow_gtklistboxrow_changed, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, getActivatable, arginfo_gtk_gtk_gtklistboxrow_gtklistboxrow_getactivatable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, getChild, arginfo_gtk_gtk_gtklistboxrow_gtklistboxrow_getchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, getHeader, arginfo_gtk_gtk_gtklistboxrow_gtklistboxrow_getheader, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, getIndex, arginfo_gtk_gtk_gtklistboxrow_gtklistboxrow_getindex, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, getSelectable, arginfo_gtk_gtk_gtklistboxrow_gtklistboxrow_getselectable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, isSelected, arginfo_gtk_gtk_gtklistboxrow_gtklistboxrow_isselected, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, setActivatable, arginfo_gtk_gtk_gtklistboxrow_gtklistboxrow_setactivatable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, setChild, arginfo_gtk_gtk_gtklistboxrow_gtklistboxrow_setchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, setHeader, arginfo_gtk_gtk_gtklistboxrow_gtklistboxrow_setheader, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow, setSelectable, arginfo_gtk_gtk_gtklistboxrow_gtklistboxrow_setselectable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
