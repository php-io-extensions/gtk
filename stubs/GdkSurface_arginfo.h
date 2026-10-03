/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 2ab02eed823c59fac0921875e4c0f4810cd3872a */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkSurface_getWidth, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GdkSurface_getHeight arginfo_class_GdkSurface_getWidth

ZEND_METHOD(GdkSurface, getWidth);
ZEND_METHOD(GdkSurface, getHeight);

static const zend_function_entry class_GdkSurface_methods[] = {
	ZEND_ME(GdkSurface, getWidth, arginfo_class_GdkSurface_getWidth, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkSurface, getHeight, arginfo_class_GdkSurface_getHeight, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_GdkSurface(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GdkSurface", class_GdkSurface_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
