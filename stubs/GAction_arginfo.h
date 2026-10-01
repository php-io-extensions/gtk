/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: fb6236f5c423540b73a3391c1c62b58488d46605 */

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

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GSimpleAction_setState, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, value, GVariant, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GSimpleAction_getName, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GSimpleAction_getEnabled, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GSimpleAction_getState, 0, 0, GVariant, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GSimpleAction_activate, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, parameter, GVariant, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_GSimpleAction_changeState arginfo_class_GSimpleAction_setState

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GSimpleActionGroup_new, 0, 0, GSimpleActionGroup, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GSimpleActionGroup_addAction, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, action, GSimpleAction, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GSimpleActionGroup_removeAction, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, actionName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GSimpleActionGroup_lookupAction, 0, 1, GSimpleAction, 1)
	ZEND_ARG_TYPE_INFO(0, actionName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GSimpleActionGroup_hasAction, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, actionName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GSimpleActionGroup_listActions, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GSimpleActionGroup_activateAction, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, actionName, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, parameter, GVariant, 1)
ZEND_END_ARG_INFO()

ZEND_METHOD(GSimpleAction, new);
ZEND_METHOD(GSimpleAction, newStateful);
ZEND_METHOD(GSimpleAction, setEnabled);
ZEND_METHOD(GSimpleAction, setState);
ZEND_METHOD(GSimpleAction, getName);
ZEND_METHOD(GSimpleAction, getEnabled);
ZEND_METHOD(GSimpleAction, getState);
ZEND_METHOD(GSimpleAction, activate);
ZEND_METHOD(GSimpleAction, changeState);
ZEND_METHOD(GSimpleActionGroup, new);
ZEND_METHOD(GSimpleActionGroup, addAction);
ZEND_METHOD(GSimpleActionGroup, removeAction);
ZEND_METHOD(GSimpleActionGroup, lookupAction);
ZEND_METHOD(GSimpleActionGroup, hasAction);
ZEND_METHOD(GSimpleActionGroup, listActions);
ZEND_METHOD(GSimpleActionGroup, activateAction);

static const zend_function_entry class_GSimpleAction_methods[] = {
	ZEND_ME(GSimpleAction, new, arginfo_class_GSimpleAction_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GSimpleAction, newStateful, arginfo_class_GSimpleAction_newStateful, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GSimpleAction, setEnabled, arginfo_class_GSimpleAction_setEnabled, ZEND_ACC_PUBLIC)
	ZEND_ME(GSimpleAction, setState, arginfo_class_GSimpleAction_setState, ZEND_ACC_PUBLIC)
	ZEND_ME(GSimpleAction, getName, arginfo_class_GSimpleAction_getName, ZEND_ACC_PUBLIC)
	ZEND_ME(GSimpleAction, getEnabled, arginfo_class_GSimpleAction_getEnabled, ZEND_ACC_PUBLIC)
	ZEND_ME(GSimpleAction, getState, arginfo_class_GSimpleAction_getState, ZEND_ACC_PUBLIC)
	ZEND_ME(GSimpleAction, activate, arginfo_class_GSimpleAction_activate, ZEND_ACC_PUBLIC)
	ZEND_ME(GSimpleAction, changeState, arginfo_class_GSimpleAction_changeState, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GSimpleActionGroup_methods[] = {
	ZEND_ME(GSimpleActionGroup, new, arginfo_class_GSimpleActionGroup_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GSimpleActionGroup, addAction, arginfo_class_GSimpleActionGroup_addAction, ZEND_ACC_PUBLIC)
	ZEND_ME(GSimpleActionGroup, removeAction, arginfo_class_GSimpleActionGroup_removeAction, ZEND_ACC_PUBLIC)
	ZEND_ME(GSimpleActionGroup, lookupAction, arginfo_class_GSimpleActionGroup_lookupAction, ZEND_ACC_PUBLIC)
	ZEND_ME(GSimpleActionGroup, hasAction, arginfo_class_GSimpleActionGroup_hasAction, ZEND_ACC_PUBLIC)
	ZEND_ME(GSimpleActionGroup, listActions, arginfo_class_GSimpleActionGroup_listActions, ZEND_ACC_PUBLIC)
	ZEND_ME(GSimpleActionGroup, activateAction, arginfo_class_GSimpleActionGroup_activateAction, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_GSimpleAction(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GSimpleAction", class_GSimpleAction_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GSimpleActionGroup(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GSimpleActionGroup", class_GSimpleActionGroup_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
