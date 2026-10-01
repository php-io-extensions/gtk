/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 5f744d06a82756332a7c5b11f1db97b8beb1195d */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkApplication_new, 0, 2, GtkApplication, 0)
	ZEND_ARG_TYPE_INFO(0, applicationId, IS_STRING, 1)
	ZEND_ARG_OBJ_TYPE_MASK(0, flags, GApplicationFlags, MAY_BE_LONG, NULL)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkApplication_addWindow, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, window, GtkWindow, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkApplication_removeWindow arginfo_class_GtkApplication_addWindow

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkApplication_getActiveWindow, 0, 0, GtkWindow, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkApplication_getWindows, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkApplication_getMenubar, 0, 0, GMenuModel, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkApplication_setMenubar, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, menubar, GMenuModel, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkApplication_setAccelsForAction, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, detailedActionName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, accels, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkApplication_getAccelsForAction, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, detailedActionName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(GtkApplication, new);
ZEND_METHOD(GtkApplication, addWindow);
ZEND_METHOD(GtkApplication, removeWindow);
ZEND_METHOD(GtkApplication, getActiveWindow);
ZEND_METHOD(GtkApplication, getWindows);
ZEND_METHOD(GtkApplication, getMenubar);
ZEND_METHOD(GtkApplication, setMenubar);
ZEND_METHOD(GtkApplication, setAccelsForAction);
ZEND_METHOD(GtkApplication, getAccelsForAction);

static const zend_function_entry class_GtkApplication_methods[] = {
	ZEND_ME(GtkApplication, new, arginfo_class_GtkApplication_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkApplication, addWindow, arginfo_class_GtkApplication_addWindow, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkApplication, removeWindow, arginfo_class_GtkApplication_removeWindow, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkApplication, getActiveWindow, arginfo_class_GtkApplication_getActiveWindow, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkApplication, getWindows, arginfo_class_GtkApplication_getWindows, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkApplication, getMenubar, arginfo_class_GtkApplication_getMenubar, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkApplication, setMenubar, arginfo_class_GtkApplication_setMenubar, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkApplication, setAccelsForAction, arginfo_class_GtkApplication_setAccelsForAction, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkApplication, getAccelsForAction, arginfo_class_GtkApplication_getAccelsForAction, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_GtkApplication(zend_class_entry *class_entry_GApplication)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkApplication", class_GtkApplication_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GApplication, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
