/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 82b174de56131e88751637bbac74c6bcccbc4290 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_GObject___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GObject_typeName, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GObject_pointer, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(GObject, __construct);
ZEND_METHOD(GObject, typeName);
ZEND_METHOD(GObject, pointer);

static const zend_function_entry class_GObject_methods[] = {
	ZEND_ME(GObject, __construct, arginfo_class_GObject___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(GObject, typeName, arginfo_class_GObject_typeName, ZEND_ACC_PUBLIC)
	ZEND_ME(GObject, pointer, arginfo_class_GObject_pointer, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_GObject(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GObject", class_GObject_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
