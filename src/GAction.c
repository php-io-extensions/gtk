#include "runtime.h"
#include "../stubs/GAction_arginfo.h"

ZEND_METHOD(GAction, nameIsValid);
ZEND_METHOD(GAction, printDetailedName);
ZEND_METHOD(GAction, getName);
ZEND_METHOD(GAction, getParameterType);
ZEND_METHOD(GAction, getStateType);
ZEND_METHOD(GAction, getStateHint);
ZEND_METHOD(GAction, getEnabled);
ZEND_METHOD(GAction, getState);
ZEND_METHOD(GAction, changeState);
ZEND_METHOD(GAction, activate);
ZEND_METHOD(GActionMap, lookupAction);
ZEND_METHOD(GActionMap, addAction);
ZEND_METHOD(GActionMap, removeAction);
ZEND_METHOD(GActionGroup, hasAction);
ZEND_METHOD(GActionGroup, listActions);
ZEND_METHOD(GActionGroup, getActionEnabled);
ZEND_METHOD(GActionGroup, getActionParameterType);
ZEND_METHOD(GActionGroup, getActionStateType);
ZEND_METHOD(GActionGroup, getActionStateHint);
ZEND_METHOD(GActionGroup, getActionState);
ZEND_METHOD(GActionGroup, changeActionState);
ZEND_METHOD(GActionGroup, activateAction);
ZEND_METHOD(GActionGroup, actionAdded);
ZEND_METHOD(GActionGroup, actionRemoved);
ZEND_METHOD(GActionGroup, actionEnabledChanged);
ZEND_METHOD(GActionGroup, actionStateChanged);
ZEND_METHOD(GListModel, getNItems);
ZEND_METHOD(GListModel, getItem);
ZEND_METHOD(GListModel, getObject);
ZEND_METHOD(GListModel, itemsChanged);

static const phpgtk_interface_method phpgtk_GAction_bodies[] = {
	{"nameIsValid", zim_GAction_nameIsValid},
	{"printDetailedName", zim_GAction_printDetailedName},
	{"getName", zim_GAction_getName},
	{"getParameterType", zim_GAction_getParameterType},
	{"getStateType", zim_GAction_getStateType},
	{"getStateHint", zim_GAction_getStateHint},
	{"getEnabled", zim_GAction_getEnabled},
	{"getState", zim_GAction_getState},
	{"changeState", zim_GAction_changeState},
	{"activate", zim_GAction_activate},
	{NULL, NULL},
};

static const phpgtk_interface_method phpgtk_GActionMap_bodies[] = {
	{"lookupAction", zim_GActionMap_lookupAction},
	{"addAction", zim_GActionMap_addAction},
	{"removeAction", zim_GActionMap_removeAction},
	{NULL, NULL},
};

static const phpgtk_interface_method phpgtk_GActionGroup_bodies[] = {
	{"hasAction", zim_GActionGroup_hasAction},
	{"listActions", zim_GActionGroup_listActions},
	{"getActionEnabled", zim_GActionGroup_getActionEnabled},
	{"getActionParameterType", zim_GActionGroup_getActionParameterType},
	{"getActionStateType", zim_GActionGroup_getActionStateType},
	{"getActionStateHint", zim_GActionGroup_getActionStateHint},
	{"getActionState", zim_GActionGroup_getActionState},
	{"changeActionState", zim_GActionGroup_changeActionState},
	{"activateAction", zim_GActionGroup_activateAction},
	{"actionAdded", zim_GActionGroup_actionAdded},
	{"actionRemoved", zim_GActionGroup_actionRemoved},
	{"actionEnabledChanged", zim_GActionGroup_actionEnabledChanged},
	{"actionStateChanged", zim_GActionGroup_actionStateChanged},
	{NULL, NULL},
};

static const phpgtk_interface_method phpgtk_GListModel_bodies[] = {
	{"getNItems", zim_GListModel_getNItems},
	{"getItem", zim_GListModel_getItem},
	{"getObject", zim_GListModel_getObject},
	{"itemsChanged", zim_GListModel_itemsChanged},
	{NULL, NULL},
};

void phpgtk_register_GAction(void)
{
	phpgtk_ce_GAction = register_class_GAction();
	phpgtk_interface_bodies(phpgtk_ce_GAction, phpgtk_GAction_bodies);
	phpgtk_ce_GAction->interface_gets_implemented = phpgtk_interface_native_only;

	phpgtk_ce_GActionMap = register_class_GActionMap();
	phpgtk_interface_bodies(phpgtk_ce_GActionMap, phpgtk_GActionMap_bodies);
	phpgtk_ce_GActionMap->interface_gets_implemented = phpgtk_interface_native_only;

	phpgtk_ce_GActionGroup = register_class_GActionGroup();
	phpgtk_interface_bodies(phpgtk_ce_GActionGroup, phpgtk_GActionGroup_bodies);
	phpgtk_ce_GActionGroup->interface_gets_implemented = phpgtk_interface_native_only;

	phpgtk_ce_GListModel = register_class_GListModel();
	phpgtk_interface_bodies(phpgtk_ce_GListModel, phpgtk_GListModel_bodies);
	phpgtk_ce_GListModel->interface_gets_implemented = phpgtk_interface_native_only;

	phpgtk_ce_GSimpleAction = register_class_GSimpleAction(phpgtk_ce_GObject, phpgtk_ce_GAction);
	phpgtk_object_setup(phpgtk_ce_GSimpleAction);
	phpgtk_map_gtype("GSimpleAction", phpgtk_ce_GSimpleAction);

	phpgtk_ce_GSimpleActionGroup = register_class_GSimpleActionGroup(phpgtk_ce_GObject, phpgtk_ce_GActionGroup, phpgtk_ce_GActionMap);
	phpgtk_object_setup(phpgtk_ce_GSimpleActionGroup);
	phpgtk_map_gtype("GSimpleActionGroup", phpgtk_ce_GSimpleActionGroup);
}

#define THIS_ACTION G_SIMPLE_ACTION(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

/* A const GVariantType * as its type string (not NUL-terminated natively), NULL as null. */
static void phpgtk_return_variant_type(zval *rv, const GVariantType *type)
{
	if (type == NULL) {
		ZVAL_NULL(rv);
		return;
	}

	ZVAL_STRINGL(rv, g_variant_type_peek_string(type), g_variant_type_get_string_length(type));
}

/* ---- GSimpleAction ----------------------------------------------------- */

ZEND_METHOD(GSimpleAction, new)
{
	zend_string *name;
	zend_string *parameter_type = NULL;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_STR_OR_NULL(parameter_type)
	ZEND_PARSE_PARAMETERS_END();

	phpgtk_box_gobject_full(return_value, g_simple_action_new(ZSTR_VAL(name),
		parameter_type != NULL ? G_VARIANT_TYPE(ZSTR_VAL(parameter_type)) : NULL));
}

ZEND_METHOD(GSimpleAction, newStateful)
{
	zend_string *name;
	zend_string *parameter_type = NULL;
	zend_object *state;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(name)
		Z_PARAM_STR_OR_NULL(parameter_type)
		Z_PARAM_OBJ_OF_CLASS(state, phpgtk_ce_GVariant)
	ZEND_PARSE_PARAMETERS_END();

	phpgtk_box_gobject_full(return_value, g_simple_action_new_stateful(ZSTR_VAL(name),
		parameter_type != NULL ? G_VARIANT_TYPE(ZSTR_VAL(parameter_type)) : NULL,
		(GVariant *) PHPGTK_PTR(state)));
}

ZEND_METHOD(GSimpleAction, setEnabled)
{
	bool enabled;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(enabled)
	ZEND_PARSE_PARAMETERS_END();

	g_simple_action_set_enabled(THIS_ACTION, enabled);
}

ZEND_METHOD(GSimpleAction, setState)
{
	zend_object *value;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(value, phpgtk_ce_GVariant)
	ZEND_PARSE_PARAMETERS_END();

	g_simple_action_set_state(THIS_ACTION, (GVariant *) PHPGTK_PTR(value));
}

/* ---- GSimpleActionGroup ------------------------------------------------ */

ZEND_METHOD(GSimpleActionGroup, new)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject_full(return_value, g_simple_action_group_new());
}

/* ---- GAction ----------------------------------------------------------- */

/* $this's native object, implementing GAction (GSimpleAction). */
#undef THIS_ACTION
#define THIS_ACTION G_ACTION(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

ZEND_METHOD(GAction, nameIsValid)
{
	zend_string *action_name;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(action_name)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_BOOL(g_action_name_is_valid(ZSTR_VAL(action_name)));
}

ZEND_METHOD(GAction, printDetailedName)
{
	zend_string *action_name;
	zend_object *target_value = NULL;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(action_name)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(target_value, phpgtk_ce_GVariant)
	ZEND_PARSE_PARAMETERS_END();

	gchar *detailed = g_action_print_detailed_name(ZSTR_VAL(action_name), (GVariant *) PHPGTK_OPTIONAL_PTR(target_value));

	RETVAL_STRING(detailed);
	g_free(detailed);
}

ZEND_METHOD(GAction, getName)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_STRING(g_action_get_name(G_ACTION(THIS_ACTION)));
}

ZEND_METHOD(GAction, getParameterType)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_return_variant_type(return_value, g_action_get_parameter_type(THIS_ACTION));
}

ZEND_METHOD(GAction, getStateType)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_return_variant_type(return_value, g_action_get_state_type(THIS_ACTION));
}

ZEND_METHOD(GAction, getStateHint)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_variant_full(return_value, g_action_get_state_hint(THIS_ACTION));
}

ZEND_METHOD(GAction, getEnabled)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_BOOL(g_action_get_enabled(G_ACTION(THIS_ACTION)));
}

ZEND_METHOD(GAction, getState)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_variant_full(return_value, g_action_get_state(G_ACTION(THIS_ACTION)));
}

ZEND_METHOD(GAction, activate)
{
	zend_object *parameter = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(parameter, phpgtk_ce_GVariant)
	ZEND_PARSE_PARAMETERS_END();

	g_action_activate(G_ACTION(THIS_ACTION), (GVariant *) PHPGTK_OPTIONAL_PTR(parameter));
}

ZEND_METHOD(GAction, changeState)
{
	zend_object *value;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(value, phpgtk_ce_GVariant)
	ZEND_PARSE_PARAMETERS_END();

	g_action_change_state(G_ACTION(THIS_ACTION), (GVariant *) PHPGTK_PTR(value));
}

/* ---- GActionMap / GActionGroup ----------------------------------------- */

/* $this's native object, implementing GActionMap and GActionGroup (GSimpleActionGroup, GApplication, GtkApplicationWindow). */
#define THIS_MAP G_ACTION_MAP(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))
#define THIS_ACTION_GROUP G_ACTION_GROUP(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

ZEND_METHOD(GActionMap, addAction)
{
	zend_object *action;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(action, phpgtk_ce_GAction)
	ZEND_PARSE_PARAMETERS_END();

	g_action_map_add_action(THIS_MAP, G_ACTION(PHPGTK_PTR(action)));
}

ZEND_METHOD(GActionMap, removeAction)
{
	zend_string *name;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();

	g_action_map_remove_action(THIS_MAP, ZSTR_VAL(name));
}

ZEND_METHOD(GActionMap, lookupAction)
{
	zend_string *name;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();

	phpgtk_box_gobject(return_value, g_action_map_lookup_action(THIS_MAP, ZSTR_VAL(name)));
}

ZEND_METHOD(GActionGroup, hasAction)
{
	zend_string *name;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_BOOL(g_action_group_has_action(THIS_ACTION_GROUP, ZSTR_VAL(name)));
}

ZEND_METHOD(GActionGroup, listActions)
{
	ZEND_PARSE_PARAMETERS_NONE();

	gchar **names = g_action_group_list_actions(THIS_ACTION_GROUP);

	array_init(return_value);
	for (gchar **name = names; name != NULL && *name != NULL; name++) {
		add_next_index_string(return_value, *name);
	}
	g_strfreev(names);
}

ZEND_METHOD(GActionGroup, getActionEnabled)
{
	zend_string *name;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_BOOL(g_action_group_get_action_enabled(THIS_ACTION_GROUP, ZSTR_VAL(name)));
}

ZEND_METHOD(GActionGroup, getActionParameterType)
{
	zend_string *name;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();

	phpgtk_return_variant_type(return_value, g_action_group_get_action_parameter_type(THIS_ACTION_GROUP, ZSTR_VAL(name)));
}

ZEND_METHOD(GActionGroup, getActionStateType)
{
	zend_string *name;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();

	phpgtk_return_variant_type(return_value, g_action_group_get_action_state_type(THIS_ACTION_GROUP, ZSTR_VAL(name)));
}

ZEND_METHOD(GActionGroup, getActionStateHint)
{
	zend_string *name;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();

	phpgtk_box_variant_full(return_value, g_action_group_get_action_state_hint(THIS_ACTION_GROUP, ZSTR_VAL(name)));
}

ZEND_METHOD(GActionGroup, getActionState)
{
	zend_string *name;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();

	phpgtk_box_variant_full(return_value, g_action_group_get_action_state(THIS_ACTION_GROUP, ZSTR_VAL(name)));
}

ZEND_METHOD(GActionGroup, changeActionState)
{
	zend_string *name;
	zend_object *value;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OBJ_OF_CLASS(value, phpgtk_ce_GVariant)
	ZEND_PARSE_PARAMETERS_END();

	g_action_group_change_action_state(THIS_ACTION_GROUP, ZSTR_VAL(name), (GVariant *) PHPGTK_PTR(value));
}

ZEND_METHOD(GActionGroup, activateAction)
{
	zend_string *name;
	zend_object *parameter = NULL;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(parameter, phpgtk_ce_GVariant)
	ZEND_PARSE_PARAMETERS_END();

	g_action_group_activate_action(THIS_ACTION_GROUP, ZSTR_VAL(name), (GVariant *) PHPGTK_OPTIONAL_PTR(parameter));
}

ZEND_METHOD(GActionGroup, actionAdded)
{
	zend_string *name;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();

	g_action_group_action_added(THIS_ACTION_GROUP, ZSTR_VAL(name));
}

ZEND_METHOD(GActionGroup, actionRemoved)
{
	zend_string *name;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();

	g_action_group_action_removed(THIS_ACTION_GROUP, ZSTR_VAL(name));
}

ZEND_METHOD(GActionGroup, actionEnabledChanged)
{
	zend_string *name;
	bool enabled;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_BOOL(enabled)
	ZEND_PARSE_PARAMETERS_END();

	g_action_group_action_enabled_changed(THIS_ACTION_GROUP, ZSTR_VAL(name), enabled);
}

ZEND_METHOD(GActionGroup, actionStateChanged)
{
	zend_string *name;
	zend_object *state;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OBJ_OF_CLASS(state, phpgtk_ce_GVariant)
	ZEND_PARSE_PARAMETERS_END();

	g_action_group_action_state_changed(THIS_ACTION_GROUP, ZSTR_VAL(name), (GVariant *) PHPGTK_PTR(state));
}

/* ---- GListModel -------------------------------------------------------- */

/* $this's native object, implementing GListModel (GtkStringList, GtkSingleSelection). */
#define THIS_LIST G_LIST_MODEL(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

ZEND_METHOD(GListModel, getNItems)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG((zend_long) g_list_model_get_n_items(THIS_LIST));
}

ZEND_METHOD(GListModel, getItem)
{
	zend_long position;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();

	/* (transfer full): PHP's reference replaces the one the call returned. */
	phpgtk_box_gobject_full(return_value, g_list_model_get_item(THIS_LIST, (guint) position));
}

ZEND_METHOD(GListModel, getObject)
{
	zend_long position;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();

	phpgtk_box_gobject_full(return_value, g_list_model_get_object(THIS_LIST, (guint) position));
}

ZEND_METHOD(GListModel, itemsChanged)
{
	zend_long position, removed, added;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(position)
		Z_PARAM_LONG(removed)
		Z_PARAM_LONG(added)
	ZEND_PARSE_PARAMETERS_END();

	g_list_model_items_changed(THIS_LIST, (guint) position, (guint) removed, (guint) added);
}
