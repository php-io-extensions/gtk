/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: b4ccd815cd426a23187a7d333291f8e689315da6 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GMenuModel_getNItems, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GMenuModel_isMutable, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GMenu_new, 0, 0, GMenu, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GMenu_append, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, detailedAction, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GMenu_appendItem, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, item, GMenuItem, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GMenu_appendSection, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 1)
	ZEND_ARG_OBJ_INFO(0, section, GMenuModel, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GMenu_appendSubmenu, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 1)
	ZEND_ARG_OBJ_INFO(0, submenu, GMenuModel, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GMenu_prepend arginfo_class_GMenu_append

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GMenu_insert, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, detailedAction, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GMenu_remove, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GMenu_removeAll, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GMenu_freeze arginfo_class_GMenu_removeAll

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GMenuItem_new, 0, 2, GMenuItem, 0)
	ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, detailedAction, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GMenuItem_setLabel, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GMenuItem_setDetailedAction, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, detailedAction, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GMenuItem_setActionAndTargetValue, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, action, IS_STRING, 1)
	ZEND_ARG_OBJ_INFO(0, targetValue, GVariant, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GMenuItem_setAttributeValue, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, attribute, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, value, GVariant, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GMenuItem_getAttributeValue, 0, 2, GVariant, 1)
	ZEND_ARG_TYPE_INFO(0, attribute, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, expectedType, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GMenuItem_setSubmenu, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, submenu, GMenuModel, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GMenuItem_setSection, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, section, GMenuModel, 1)
ZEND_END_ARG_INFO()

ZEND_METHOD(GMenuModel, getNItems);
ZEND_METHOD(GMenuModel, isMutable);
ZEND_METHOD(GMenu, new);
ZEND_METHOD(GMenu, append);
ZEND_METHOD(GMenu, appendItem);
ZEND_METHOD(GMenu, appendSection);
ZEND_METHOD(GMenu, appendSubmenu);
ZEND_METHOD(GMenu, prepend);
ZEND_METHOD(GMenu, insert);
ZEND_METHOD(GMenu, remove);
ZEND_METHOD(GMenu, removeAll);
ZEND_METHOD(GMenu, freeze);
ZEND_METHOD(GMenuItem, new);
ZEND_METHOD(GMenuItem, setLabel);
ZEND_METHOD(GMenuItem, setDetailedAction);
ZEND_METHOD(GMenuItem, setActionAndTargetValue);
ZEND_METHOD(GMenuItem, setAttributeValue);
ZEND_METHOD(GMenuItem, getAttributeValue);
ZEND_METHOD(GMenuItem, setSubmenu);
ZEND_METHOD(GMenuItem, setSection);

static const zend_function_entry class_GMenuModel_methods[] = {
	ZEND_ME(GMenuModel, getNItems, arginfo_class_GMenuModel_getNItems, ZEND_ACC_PUBLIC)
	ZEND_ME(GMenuModel, isMutable, arginfo_class_GMenuModel_isMutable, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GMenu_methods[] = {
	ZEND_ME(GMenu, new, arginfo_class_GMenu_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GMenu, append, arginfo_class_GMenu_append, ZEND_ACC_PUBLIC)
	ZEND_ME(GMenu, appendItem, arginfo_class_GMenu_appendItem, ZEND_ACC_PUBLIC)
	ZEND_ME(GMenu, appendSection, arginfo_class_GMenu_appendSection, ZEND_ACC_PUBLIC)
	ZEND_ME(GMenu, appendSubmenu, arginfo_class_GMenu_appendSubmenu, ZEND_ACC_PUBLIC)
	ZEND_ME(GMenu, prepend, arginfo_class_GMenu_prepend, ZEND_ACC_PUBLIC)
	ZEND_ME(GMenu, insert, arginfo_class_GMenu_insert, ZEND_ACC_PUBLIC)
	ZEND_ME(GMenu, remove, arginfo_class_GMenu_remove, ZEND_ACC_PUBLIC)
	ZEND_ME(GMenu, removeAll, arginfo_class_GMenu_removeAll, ZEND_ACC_PUBLIC)
	ZEND_ME(GMenu, freeze, arginfo_class_GMenu_freeze, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GMenuItem_methods[] = {
	ZEND_ME(GMenuItem, new, arginfo_class_GMenuItem_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GMenuItem, setLabel, arginfo_class_GMenuItem_setLabel, ZEND_ACC_PUBLIC)
	ZEND_ME(GMenuItem, setDetailedAction, arginfo_class_GMenuItem_setDetailedAction, ZEND_ACC_PUBLIC)
	ZEND_ME(GMenuItem, setActionAndTargetValue, arginfo_class_GMenuItem_setActionAndTargetValue, ZEND_ACC_PUBLIC)
	ZEND_ME(GMenuItem, setAttributeValue, arginfo_class_GMenuItem_setAttributeValue, ZEND_ACC_PUBLIC)
	ZEND_ME(GMenuItem, getAttributeValue, arginfo_class_GMenuItem_getAttributeValue, ZEND_ACC_PUBLIC)
	ZEND_ME(GMenuItem, setSubmenu, arginfo_class_GMenuItem_setSubmenu, ZEND_ACC_PUBLIC)
	ZEND_ME(GMenuItem, setSection, arginfo_class_GMenuItem_setSection, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_GMenuModel(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GMenuModel", class_GMenuModel_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GMenu(zend_class_entry *class_entry_GMenuModel)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GMenu", class_GMenu_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GMenuModel, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GMenuItem(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GMenuItem", class_GMenuItem_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
