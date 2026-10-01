/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 1648d6d8a3891d8004535d101cfa2d3336613ef5 */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkApplication_new, 0, 2, GtkApplication, 0)
	ZEND_ARG_TYPE_INFO(0, applicationId, IS_STRING, 1)
	ZEND_ARG_OBJ_TYPE_MASK(0, flags, GApplicationFlags, MAY_BE_LONG, NULL)
ZEND_END_ARG_INFO()

ZEND_METHOD(GtkApplication, new);

static const zend_function_entry class_GtkApplication_methods[] = {
	ZEND_ME(GtkApplication, new, arginfo_class_GtkApplication_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_GtkApplication(zend_class_entry *class_entry_GApplication)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkApplication", class_GtkApplication_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GApplication, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
