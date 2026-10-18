/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 9b268c46845a1c50feced65edb550b9237e2b51b */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_GObject___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GObject_typeName, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GObject_pointer, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GParamSpec___construct arginfo_class_GObject___construct

#define arginfo_class_GParamSpec_getName arginfo_class_GObject_typeName

#define arginfo_class_GParamSpec_getNick arginfo_class_GObject_typeName

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GParamSpec_getBlurb, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_GParamSpec_getValueType arginfo_class_GObject_typeName

ZEND_METHOD(GObject, __construct);
ZEND_METHOD(GObject, typeName);
ZEND_METHOD(GObject, pointer);
ZEND_METHOD(GParamSpec, __construct);
ZEND_METHOD(GParamSpec, getName);
ZEND_METHOD(GParamSpec, getNick);
ZEND_METHOD(GParamSpec, getBlurb);
ZEND_METHOD(GParamSpec, getValueType);

static const zend_function_entry class_GObject_methods[] = {
	ZEND_ME(GObject, __construct, arginfo_class_GObject___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(GObject, typeName, arginfo_class_GObject_typeName, ZEND_ACC_PUBLIC)
	ZEND_ME(GObject, pointer, arginfo_class_GObject_pointer, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GParamSpec_methods[] = {
	ZEND_ME(GParamSpec, __construct, arginfo_class_GParamSpec___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(GParamSpec, getName, arginfo_class_GParamSpec_getName, ZEND_ACC_PUBLIC)
	ZEND_ME(GParamSpec, getNick, arginfo_class_GParamSpec_getNick, ZEND_ACC_PUBLIC)
	ZEND_ME(GParamSpec, getBlurb, arginfo_class_GParamSpec_getBlurb, ZEND_ACC_PUBLIC)
	ZEND_ME(GParamSpec, getValueType, arginfo_class_GParamSpec_getValueType, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_GObject(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GObject", class_GObject_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GParamSpec(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GParamSpec", class_GParamSpec_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
