/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 00b687557bfaa6b66a3456c93aed390aa76332d8 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GAction_nameIsValid, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, actionName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GAction_printDetailedName, 0, 2, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, actionName, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, targetValue, GVariant, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GAction_getName, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GAction_getParameterType, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_GAction_getStateType arginfo_class_GAction_getParameterType

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GAction_getStateHint, 0, 0, GVariant, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GAction_getEnabled, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GAction_getState arginfo_class_GAction_getStateHint

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GAction_changeState, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, value, GVariant, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GAction_activate, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, parameter, GVariant, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GActionMap_lookupAction, 0, 1, GAction, 1)
	ZEND_ARG_TYPE_INFO(0, actionName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GActionMap_addAction, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, action, GAction, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GActionMap_removeAction, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, actionName, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GActionGroup_hasAction arginfo_class_GAction_nameIsValid

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GActionGroup_listActions, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GActionGroup_getActionEnabled arginfo_class_GAction_nameIsValid

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GActionGroup_getActionParameterType, 0, 1, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, actionName, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GActionGroup_getActionStateType arginfo_class_GActionGroup_getActionParameterType

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GActionGroup_getActionStateHint, 0, 1, GVariant, 1)
	ZEND_ARG_TYPE_INFO(0, actionName, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GActionGroup_getActionState arginfo_class_GActionGroup_getActionStateHint

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GActionGroup_changeActionState, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, actionName, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, value, GVariant, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GActionGroup_activateAction, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, actionName, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, parameter, GVariant, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_GActionGroup_actionAdded arginfo_class_GActionMap_removeAction

#define arginfo_class_GActionGroup_actionRemoved arginfo_class_GActionMap_removeAction

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GActionGroup_actionEnabledChanged, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, actionName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, enabled, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GActionGroup_actionStateChanged, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, actionName, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, state, GVariant, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GListModel_getNItems, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GListModel_getItem, 0, 1, GObject, 1)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GListModel_getObject arginfo_class_GListModel_getItem

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GListModel_itemsChanged, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, removed, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, added, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GSimpleAction_new, 0, 2, GSimpleAction, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, parameterType, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GSimpleAction_newStateful, 0, 3, GSimpleAction, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, parameterType, IS_STRING, 1)
	ZEND_ARG_OBJ_INFO(0, state, GVariant, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GSimpleAction_setEnabled, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, enabled, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GSimpleAction_setState arginfo_class_GAction_changeState

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GSimpleActionGroup_new, 0, 0, GSimpleActionGroup, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(GSimpleAction, new);
ZEND_METHOD(GSimpleAction, newStateful);
ZEND_METHOD(GSimpleAction, setEnabled);
ZEND_METHOD(GSimpleAction, setState);
ZEND_METHOD(GSimpleActionGroup, new);

static const zend_function_entry class_GAction_methods[] = {
	ZEND_RAW_FENTRY("nameIsValid", NULL, arginfo_class_GAction_nameIsValid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("printDetailedName", NULL, arginfo_class_GAction_printDetailedName, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("getName", NULL, arginfo_class_GAction_getName, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("getParameterType", NULL, arginfo_class_GAction_getParameterType, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("getStateType", NULL, arginfo_class_GAction_getStateType, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("getStateHint", NULL, arginfo_class_GAction_getStateHint, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("getEnabled", NULL, arginfo_class_GAction_getEnabled, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("getState", NULL, arginfo_class_GAction_getState, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("changeState", NULL, arginfo_class_GAction_changeState, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("activate", NULL, arginfo_class_GAction_activate, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_FE_END
};

static const zend_function_entry class_GActionMap_methods[] = {
	ZEND_RAW_FENTRY("lookupAction", NULL, arginfo_class_GActionMap_lookupAction, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("addAction", NULL, arginfo_class_GActionMap_addAction, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("removeAction", NULL, arginfo_class_GActionMap_removeAction, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_FE_END
};

static const zend_function_entry class_GActionGroup_methods[] = {
	ZEND_RAW_FENTRY("hasAction", NULL, arginfo_class_GActionGroup_hasAction, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("listActions", NULL, arginfo_class_GActionGroup_listActions, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("getActionEnabled", NULL, arginfo_class_GActionGroup_getActionEnabled, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("getActionParameterType", NULL, arginfo_class_GActionGroup_getActionParameterType, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("getActionStateType", NULL, arginfo_class_GActionGroup_getActionStateType, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("getActionStateHint", NULL, arginfo_class_GActionGroup_getActionStateHint, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("getActionState", NULL, arginfo_class_GActionGroup_getActionState, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("changeActionState", NULL, arginfo_class_GActionGroup_changeActionState, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("activateAction", NULL, arginfo_class_GActionGroup_activateAction, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("actionAdded", NULL, arginfo_class_GActionGroup_actionAdded, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("actionRemoved", NULL, arginfo_class_GActionGroup_actionRemoved, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("actionEnabledChanged", NULL, arginfo_class_GActionGroup_actionEnabledChanged, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("actionStateChanged", NULL, arginfo_class_GActionGroup_actionStateChanged, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_FE_END
};

static const zend_function_entry class_GListModel_methods[] = {
	ZEND_RAW_FENTRY("getNItems", NULL, arginfo_class_GListModel_getNItems, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("getItem", NULL, arginfo_class_GListModel_getItem, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("getObject", NULL, arginfo_class_GListModel_getObject, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("itemsChanged", NULL, arginfo_class_GListModel_itemsChanged, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_FE_END
};

static const zend_function_entry class_GSimpleAction_methods[] = {
	ZEND_ME(GSimpleAction, new, arginfo_class_GSimpleAction_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GSimpleAction, newStateful, arginfo_class_GSimpleAction_newStateful, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GSimpleAction, setEnabled, arginfo_class_GSimpleAction_setEnabled, ZEND_ACC_PUBLIC)
	ZEND_ME(GSimpleAction, setState, arginfo_class_GSimpleAction_setState, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GSimpleActionGroup_methods[] = {
	ZEND_ME(GSimpleActionGroup, new, arginfo_class_GSimpleActionGroup_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_GAction(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GAction", class_GAction_methods);
	class_entry = zend_register_internal_interface(&ce);

	return class_entry;
}

static zend_class_entry *register_class_GActionMap(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GActionMap", class_GActionMap_methods);
	class_entry = zend_register_internal_interface(&ce);

	return class_entry;
}

static zend_class_entry *register_class_GActionGroup(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GActionGroup", class_GActionGroup_methods);
	class_entry = zend_register_internal_interface(&ce);

	return class_entry;
}

static zend_class_entry *register_class_GListModel(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GListModel", class_GListModel_methods);
	class_entry = zend_register_internal_interface(&ce);

	return class_entry;
}

static zend_class_entry *register_class_GSimpleAction(zend_class_entry *class_entry_GObject, zend_class_entry *class_entry_GAction)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GSimpleAction", class_GSimpleAction_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);
	zend_class_implements(class_entry, 1, class_entry_GAction);

	return class_entry;
}

static zend_class_entry *register_class_GSimpleActionGroup(zend_class_entry *class_entry_GObject, zend_class_entry *class_entry_GActionGroup, zend_class_entry *class_entry_GActionMap)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GSimpleActionGroup", class_GSimpleActionGroup_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);
	zend_class_implements(class_entry, 2, class_entry_GActionGroup, class_entry_GActionMap);

	return class_entry;
}
