
extern zend_class_entry *gtk_gtk_gtksearchentry_gtksearchentry_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry);

PHP_METHOD(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry, new_);
PHP_METHOD(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry, getInputHints);
PHP_METHOD(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry, getInputPurpose);
PHP_METHOD(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry, getKeyCaptureWidget);
PHP_METHOD(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry, getPlaceholderText);
PHP_METHOD(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry, getSearchDelay);
PHP_METHOD(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry, setInputHints);
PHP_METHOD(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry, setInputPurpose);
PHP_METHOD(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry, setKeyCaptureWidget);
PHP_METHOD(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry, setPlaceholderText);
PHP_METHOD(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry, setSearchDelay);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtksearchentry_gtksearchentry_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtksearchentry_gtksearchentry_getinputhints, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtksearchentry_gtksearchentry_getinputpurpose, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtksearchentry_gtksearchentry_getkeycapturewidget, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtksearchentry_gtksearchentry_getplaceholdertext, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtksearchentry_gtksearchentry_getsearchdelay, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtksearchentry_gtksearchentry_setinputhints, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, hints, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtksearchentry_gtksearchentry_setinputpurpose, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, purpose, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtksearchentry_gtksearchentry_setkeycapturewidget, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, widget, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtksearchentry_gtksearchentry_setplaceholdertext, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtksearchentry_gtksearchentry_setsearchdelay, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, delay, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtksearchentry_gtksearchentry_method_entry) {
	PHP_ME(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry, new_, arginfo_gtk_gtk_gtksearchentry_gtksearchentry_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry, getInputHints, arginfo_gtk_gtk_gtksearchentry_gtksearchentry_getinputhints, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry, getInputPurpose, arginfo_gtk_gtk_gtksearchentry_gtksearchentry_getinputpurpose, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry, getKeyCaptureWidget, arginfo_gtk_gtk_gtksearchentry_gtksearchentry_getkeycapturewidget, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry, getPlaceholderText, arginfo_gtk_gtk_gtksearchentry_gtksearchentry_getplaceholdertext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry, getSearchDelay, arginfo_gtk_gtk_gtksearchentry_gtksearchentry_getsearchdelay, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry, setInputHints, arginfo_gtk_gtk_gtksearchentry_gtksearchentry_setinputhints, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry, setInputPurpose, arginfo_gtk_gtk_gtksearchentry_gtksearchentry_setinputpurpose, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry, setKeyCaptureWidget, arginfo_gtk_gtk_gtksearchentry_gtksearchentry_setkeycapturewidget, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry, setPlaceholderText, arginfo_gtk_gtk_gtksearchentry_gtksearchentry_setplaceholdertext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry, setSearchDelay, arginfo_gtk_gtk_gtksearchentry_gtksearchentry_setsearchdelay, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
