
extern zend_class_entry *gtk_gtk_gtkpasswordentry_gtkpasswordentry_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkPasswordEntry_GtkPasswordEntry);

PHP_METHOD(Gtk_Gtk_GtkPasswordEntry_GtkPasswordEntry, new_);
PHP_METHOD(Gtk_Gtk_GtkPasswordEntry_GtkPasswordEntry, getExtraMenu);
PHP_METHOD(Gtk_Gtk_GtkPasswordEntry_GtkPasswordEntry, getShowPeekIcon);
PHP_METHOD(Gtk_Gtk_GtkPasswordEntry_GtkPasswordEntry, setExtraMenu);
PHP_METHOD(Gtk_Gtk_GtkPasswordEntry_GtkPasswordEntry, setShowPeekIcon);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpasswordentry_gtkpasswordentry_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpasswordentry_gtkpasswordentry_getextramenu, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpasswordentry_gtkpasswordentry_getshowpeekicon, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpasswordentry_gtkpasswordentry_setextramenu, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, model, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpasswordentry_gtkpasswordentry_setshowpeekicon, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, showPeekIcon, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkpasswordentry_gtkpasswordentry_method_entry) {
	PHP_ME(Gtk_Gtk_GtkPasswordEntry_GtkPasswordEntry, new_, arginfo_gtk_gtk_gtkpasswordentry_gtkpasswordentry_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPasswordEntry_GtkPasswordEntry, getExtraMenu, arginfo_gtk_gtk_gtkpasswordentry_gtkpasswordentry_getextramenu, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPasswordEntry_GtkPasswordEntry, getShowPeekIcon, arginfo_gtk_gtk_gtkpasswordentry_gtkpasswordentry_getshowpeekicon, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPasswordEntry_GtkPasswordEntry, setExtraMenu, arginfo_gtk_gtk_gtkpasswordentry_gtkpasswordentry_setextramenu, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPasswordEntry_GtkPasswordEntry, setShowPeekIcon, arginfo_gtk_gtk_gtkpasswordentry_gtkpasswordentry_setshowpeekicon, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
