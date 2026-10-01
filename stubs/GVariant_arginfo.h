/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: a214cde8c8d0729c63aa54631a133d34f33a5f05 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_GVariant___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GVariant_newBoolean, 0, 1, GVariant, 0)
	ZEND_ARG_TYPE_INFO(0, value, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GVariant_newString, 0, 1, GVariant, 0)
	ZEND_ARG_TYPE_INFO(0, string, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GVariant_newInt32, 0, 1, GVariant, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GVariant_newDouble, 0, 1, GVariant, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GVariant_getBoolean, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GVariant_getString, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GVariant_getInt32, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GVariant_getDouble, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GVariant_getTypeString arginfo_class_GVariant_getString

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GVariant_isOfType, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, type, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GVariant_print, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, typeAnnotate, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(GVariant, __construct);
ZEND_METHOD(GVariant, newBoolean);
ZEND_METHOD(GVariant, newString);
ZEND_METHOD(GVariant, newInt32);
ZEND_METHOD(GVariant, newDouble);
ZEND_METHOD(GVariant, getBoolean);
ZEND_METHOD(GVariant, getString);
ZEND_METHOD(GVariant, getInt32);
ZEND_METHOD(GVariant, getDouble);
ZEND_METHOD(GVariant, getTypeString);
ZEND_METHOD(GVariant, isOfType);
ZEND_METHOD(GVariant, print);

static const zend_function_entry class_GVariant_methods[] = {
	ZEND_ME(GVariant, __construct, arginfo_class_GVariant___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(GVariant, newBoolean, arginfo_class_GVariant_newBoolean, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GVariant, newString, arginfo_class_GVariant_newString, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GVariant, newInt32, arginfo_class_GVariant_newInt32, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GVariant, newDouble, arginfo_class_GVariant_newDouble, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GVariant, getBoolean, arginfo_class_GVariant_getBoolean, ZEND_ACC_PUBLIC)
	ZEND_ME(GVariant, getString, arginfo_class_GVariant_getString, ZEND_ACC_PUBLIC)
	ZEND_ME(GVariant, getInt32, arginfo_class_GVariant_getInt32, ZEND_ACC_PUBLIC)
	ZEND_ME(GVariant, getDouble, arginfo_class_GVariant_getDouble, ZEND_ACC_PUBLIC)
	ZEND_ME(GVariant, getTypeString, arginfo_class_GVariant_getTypeString, ZEND_ACC_PUBLIC)
	ZEND_ME(GVariant, isOfType, arginfo_class_GVariant_isOfType, ZEND_ACC_PUBLIC)
	ZEND_ME(GVariant, print, arginfo_class_GVariant_print, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_GVariant(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GVariant", class_GVariant_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
