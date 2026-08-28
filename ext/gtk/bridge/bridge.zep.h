
extern zend_class_entry *gtk_bridge_bridge_ce;

ZEPHIR_INIT_CLASS(Gtk_Bridge_Bridge);

PHP_METHOD(Gtk_Bridge_Bridge, init);
PHP_METHOD(Gtk_Bridge_Bridge, retain);
PHP_METHOD(Gtk_Bridge_Bridge, release);
PHP_METHOD(Gtk_Bridge_Bridge, isValid);
PHP_METHOD(Gtk_Bridge_Bridge, typeName);
PHP_METHOD(Gtk_Bridge_Bridge, isA);
PHP_METHOD(Gtk_Bridge_Bridge, typeFromName);
PHP_METHOD(Gtk_Bridge_Bridge, pump);
PHP_METHOD(Gtk_Bridge_Bridge, connect);
PHP_METHOD(Gtk_Bridge_Bridge, disconnect);
PHP_METHOD(Gtk_Bridge_Bridge, getProperty);
PHP_METHOD(Gtk_Bridge_Bridge, setProperty);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_bridge_bridge_init, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_bridge_bridge_retain, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_bridge_bridge_release, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_bridge_bridge_isvalid, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_bridge_bridge_typename, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_bridge_bridge_isa, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, typeName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_bridge_bridge_typefromname, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, typeName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_bridge_bridge_pump, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, timeoutMs, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_bridge_bridge_connect, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, signal, IS_STRING, 0)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_bridge_bridge_disconnect, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handlerId, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_bridge_bridge_getproperty, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_bridge_bridge_setproperty, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_bridge_bridge_method_entry) {
	PHP_ME(Gtk_Bridge_Bridge, init, arginfo_gtk_bridge_bridge_init, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Bridge_Bridge, retain, arginfo_gtk_bridge_bridge_retain, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Bridge_Bridge, release, arginfo_gtk_bridge_bridge_release, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Bridge_Bridge, isValid, arginfo_gtk_bridge_bridge_isvalid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Bridge_Bridge, typeName, arginfo_gtk_bridge_bridge_typename, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Bridge_Bridge, isA, arginfo_gtk_bridge_bridge_isa, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Bridge_Bridge, typeFromName, arginfo_gtk_bridge_bridge_typefromname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Bridge_Bridge, pump, arginfo_gtk_bridge_bridge_pump, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Bridge_Bridge, connect, arginfo_gtk_bridge_bridge_connect, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Bridge_Bridge, disconnect, arginfo_gtk_bridge_bridge_disconnect, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Bridge_Bridge, getProperty, arginfo_gtk_bridge_bridge_getproperty, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Bridge_Bridge, setProperty, arginfo_gtk_bridge_bridge_setproperty, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
