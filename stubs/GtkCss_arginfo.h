/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 4081c5822a37ee5acf0662033e404d9c81e85f24 */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkCssProvider_new, 0, 0, GtkCssProvider, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkCssProvider_loadFromString, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, css, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GdkDisplay_getDefault, 0, 0, GdkDisplay, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkDisplay_sync, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#if GTK_CHECK_VERSION(4, 14, 0)
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GdkDisplay_getDmabufFormats, 0, 0, GdkDmabufFormats, 0)
ZEND_END_ARG_INFO()
#endif

ZEND_METHOD(GtkCssProvider, new);
ZEND_METHOD(GtkCssProvider, loadFromString);
ZEND_METHOD(GdkDisplay, getDefault);
ZEND_METHOD(GdkDisplay, sync);
#if GTK_CHECK_VERSION(4, 14, 0)
ZEND_METHOD(GdkDisplay, getDmabufFormats);
#endif

static const zend_function_entry class_GtkCssProvider_methods[] = {
	ZEND_ME(GtkCssProvider, new, arginfo_class_GtkCssProvider_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkCssProvider, loadFromString, arginfo_class_GtkCssProvider_loadFromString, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GdkDisplay_methods[] = {
	ZEND_ME(GdkDisplay, getDefault, arginfo_class_GdkDisplay_getDefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GdkDisplay, sync, arginfo_class_GdkDisplay_sync, ZEND_ACC_PUBLIC)
#if GTK_CHECK_VERSION(4, 14, 0)
	ZEND_ME(GdkDisplay, getDmabufFormats, arginfo_class_GdkDisplay_getDmabufFormats, ZEND_ACC_PUBLIC)
#endif
	ZEND_FE_END
};

static zend_class_entry *register_class_GtkStyleProvider(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkStyleProvider", NULL);
	class_entry = zend_register_internal_interface(&ce);

	return class_entry;
}

static zend_class_entry *register_class_GtkCssProvider(zend_class_entry *class_entry_GObject, zend_class_entry *class_entry_GtkStyleProvider)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkCssProvider", class_GtkCssProvider_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);
	zend_class_implements(class_entry, 1, class_entry_GtkStyleProvider);

	return class_entry;
}

static zend_class_entry *register_class_GdkDisplay(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GdkDisplay", class_GdkDisplay_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
