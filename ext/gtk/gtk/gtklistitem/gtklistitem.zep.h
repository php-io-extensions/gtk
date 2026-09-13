
extern zend_class_entry *gtk_gtk_gtklistitem_gtklistitem_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkListItem_GtkListItem);

PHP_METHOD(Gtk_Gtk_GtkListItem_GtkListItem, getAccessibleDescription);
PHP_METHOD(Gtk_Gtk_GtkListItem_GtkListItem, getAccessibleLabel);
PHP_METHOD(Gtk_Gtk_GtkListItem_GtkListItem, getActivatable);
PHP_METHOD(Gtk_Gtk_GtkListItem_GtkListItem, getChild);
PHP_METHOD(Gtk_Gtk_GtkListItem_GtkListItem, getFocusable);
PHP_METHOD(Gtk_Gtk_GtkListItem_GtkListItem, getItem);
PHP_METHOD(Gtk_Gtk_GtkListItem_GtkListItem, getPosition);
PHP_METHOD(Gtk_Gtk_GtkListItem_GtkListItem, getSelectable);
PHP_METHOD(Gtk_Gtk_GtkListItem_GtkListItem, getSelected);
PHP_METHOD(Gtk_Gtk_GtkListItem_GtkListItem, setAccessibleDescription);
PHP_METHOD(Gtk_Gtk_GtkListItem_GtkListItem, setAccessibleLabel);
PHP_METHOD(Gtk_Gtk_GtkListItem_GtkListItem, setActivatable);
PHP_METHOD(Gtk_Gtk_GtkListItem_GtkListItem, setChild);
PHP_METHOD(Gtk_Gtk_GtkListItem_GtkListItem, setFocusable);
PHP_METHOD(Gtk_Gtk_GtkListItem_GtkListItem, setSelectable);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistitem_gtklistitem_getaccessibledescription, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistitem_gtklistitem_getaccessiblelabel, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistitem_gtklistitem_getactivatable, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistitem_gtklistitem_getchild, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistitem_gtklistitem_getfocusable, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistitem_gtklistitem_getitem, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistitem_gtklistitem_getposition, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistitem_gtklistitem_getselectable, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistitem_gtklistitem_getselected, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistitem_gtklistitem_setaccessibledescription, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, description, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistitem_gtklistitem_setaccessiblelabel, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistitem_gtklistitem_setactivatable, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, activatable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistitem_gtklistitem_setchild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistitem_gtklistitem_setfocusable, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, focusable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtklistitem_gtklistitem_setselectable, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, selectable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtklistitem_gtklistitem_method_entry) {
	PHP_ME(Gtk_Gtk_GtkListItem_GtkListItem, getAccessibleDescription, arginfo_gtk_gtk_gtklistitem_gtklistitem_getaccessibledescription, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListItem_GtkListItem, getAccessibleLabel, arginfo_gtk_gtk_gtklistitem_gtklistitem_getaccessiblelabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListItem_GtkListItem, getActivatable, arginfo_gtk_gtk_gtklistitem_gtklistitem_getactivatable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListItem_GtkListItem, getChild, arginfo_gtk_gtk_gtklistitem_gtklistitem_getchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListItem_GtkListItem, getFocusable, arginfo_gtk_gtk_gtklistitem_gtklistitem_getfocusable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListItem_GtkListItem, getItem, arginfo_gtk_gtk_gtklistitem_gtklistitem_getitem, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListItem_GtkListItem, getPosition, arginfo_gtk_gtk_gtklistitem_gtklistitem_getposition, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListItem_GtkListItem, getSelectable, arginfo_gtk_gtk_gtklistitem_gtklistitem_getselectable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListItem_GtkListItem, getSelected, arginfo_gtk_gtk_gtklistitem_gtklistitem_getselected, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListItem_GtkListItem, setAccessibleDescription, arginfo_gtk_gtk_gtklistitem_gtklistitem_setaccessibledescription, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListItem_GtkListItem, setAccessibleLabel, arginfo_gtk_gtk_gtklistitem_gtklistitem_setaccessiblelabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListItem_GtkListItem, setActivatable, arginfo_gtk_gtk_gtklistitem_gtklistitem_setactivatable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListItem_GtkListItem, setChild, arginfo_gtk_gtk_gtklistitem_gtklistitem_setchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListItem_GtkListItem, setFocusable, arginfo_gtk_gtk_gtklistitem_gtklistitem_setfocusable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkListItem_GtkListItem, setSelectable, arginfo_gtk_gtk_gtklistitem_gtklistitem_setselectable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
