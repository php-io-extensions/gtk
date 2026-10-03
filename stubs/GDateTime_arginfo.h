/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 07aa69be389f572591045c5465baf4993bf47ffa */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_GDateTime___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GDateTime_newLocal, 0, 6, GDateTime, 0)
	ZEND_ARG_TYPE_INFO(0, year, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, month, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, day, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, hour, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, minute, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, seconds, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GDateTime_getYear, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GDateTime_getMonth arginfo_class_GDateTime_getYear

#define arginfo_class_GDateTime_getDayOfMonth arginfo_class_GDateTime_getYear

#define arginfo_class_GDateTime_toUnix arginfo_class_GDateTime_getYear

ZEND_METHOD(GDateTime, __construct);
ZEND_METHOD(GDateTime, newLocal);
ZEND_METHOD(GDateTime, getYear);
ZEND_METHOD(GDateTime, getMonth);
ZEND_METHOD(GDateTime, getDayOfMonth);
ZEND_METHOD(GDateTime, toUnix);

static const zend_function_entry class_GDateTime_methods[] = {
	ZEND_ME(GDateTime, __construct, arginfo_class_GDateTime___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(GDateTime, newLocal, arginfo_class_GDateTime_newLocal, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GDateTime, getYear, arginfo_class_GDateTime_getYear, ZEND_ACC_PUBLIC)
	ZEND_ME(GDateTime, getMonth, arginfo_class_GDateTime_getMonth, ZEND_ACC_PUBLIC)
	ZEND_ME(GDateTime, getDayOfMonth, arginfo_class_GDateTime_getDayOfMonth, ZEND_ACC_PUBLIC)
	ZEND_ME(GDateTime, toUnix, arginfo_class_GDateTime_toUnix, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_GDateTime(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GDateTime", class_GDateTime_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
