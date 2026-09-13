
extern zend_class_entry *gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn);

PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, new_);
PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, getColumnView);
PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, getExpand);
PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, getFactory);
PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, getFixedWidth);
PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, getHeaderMenu);
PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, getId);
PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, getResizable);
PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, getTitle);
PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, getVisible);
PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, setExpand);
PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, setFactory);
PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, setFixedWidth);
PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, setHeaderMenu);
PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, setId);
PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, setResizable);
PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, setTitle);
PHP_METHOD(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, setVisible);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_new_, 0, 2, IS_LONG, 0)
	ZEND_ARG_INFO(0, title)
	ZEND_ARG_TYPE_INFO(0, factory, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_getcolumnview, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_getexpand, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_getfactory, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_getfixedwidth, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_getheadermenu, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_getid, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_getresizable, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_gettitle, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_getvisible, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_setexpand, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, expand, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_setfactory, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, factory, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_setfixedwidth, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fixedWidth, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_setheadermenu, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, menu, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_setid, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, id)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_setresizable, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, resizable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_settitle, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, title)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_setvisible, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, visible, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_method_entry) {
	PHP_ME(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, new_, arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, getColumnView, arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_getcolumnview, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, getExpand, arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_getexpand, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, getFactory, arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_getfactory, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, getFixedWidth, arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_getfixedwidth, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, getHeaderMenu, arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_getheadermenu, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, getId, arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_getid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, getResizable, arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_getresizable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, getTitle, arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_gettitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, getVisible, arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_getvisible, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, setExpand, arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_setexpand, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, setFactory, arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_setfactory, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, setFixedWidth, arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_setfixedwidth, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, setHeaderMenu, arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_setheadermenu, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, setId, arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_setid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, setResizable, arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_setresizable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, setTitle, arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_settitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkColumnViewColumn_GtkColumnViewColumn, setVisible, arginfo_gtk_gtk_gtkcolumnviewcolumn_gtkcolumnviewcolumn_setvisible, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
