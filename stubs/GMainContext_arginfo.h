/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 23c44da25003db6aa276c121f497877ad6993292 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_GMainContext___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GMainContext_default, 0, 0, GMainContext, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GMainContext_getThreadDefault, 0, 0, GMainContext, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GMainContext_iteration, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, mayBlock, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GMainContext_pending, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GMainContext_wakeup, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GMainContext_acquire arginfo_class_GMainContext_pending

#define arginfo_class_GMainContext_release arginfo_class_GMainContext_wakeup

#define arginfo_class_GMainContext_isOwner arginfo_class_GMainContext_pending

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GMainContext_pointer, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(GMainContext, __construct);
ZEND_METHOD(GMainContext, default);
ZEND_METHOD(GMainContext, getThreadDefault);
ZEND_METHOD(GMainContext, iteration);
ZEND_METHOD(GMainContext, pending);
ZEND_METHOD(GMainContext, wakeup);
ZEND_METHOD(GMainContext, acquire);
ZEND_METHOD(GMainContext, release);
ZEND_METHOD(GMainContext, isOwner);
ZEND_METHOD(GMainContext, pointer);

static const zend_function_entry class_GMainContext_methods[] = {
	ZEND_ME(GMainContext, __construct, arginfo_class_GMainContext___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(GMainContext, default, arginfo_class_GMainContext_default, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GMainContext, getThreadDefault, arginfo_class_GMainContext_getThreadDefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GMainContext, iteration, arginfo_class_GMainContext_iteration, ZEND_ACC_PUBLIC)
	ZEND_ME(GMainContext, pending, arginfo_class_GMainContext_pending, ZEND_ACC_PUBLIC)
	ZEND_ME(GMainContext, wakeup, arginfo_class_GMainContext_wakeup, ZEND_ACC_PUBLIC)
	ZEND_ME(GMainContext, acquire, arginfo_class_GMainContext_acquire, ZEND_ACC_PUBLIC)
	ZEND_ME(GMainContext, release, arginfo_class_GMainContext_release, ZEND_ACC_PUBLIC)
	ZEND_ME(GMainContext, isOwner, arginfo_class_GMainContext_isOwner, ZEND_ACC_PUBLIC)
	ZEND_ME(GMainContext, pointer, arginfo_class_GMainContext_pointer, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_GMainContext(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GMainContext", class_GMainContext_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
