#include "runtime.h"
#include "../stubs/GAction_arginfo.h"

void phpgtk_register_GAction(void)
{
	phpgtk_ce_GSimpleAction = register_class_GSimpleAction(phpgtk_ce_GObject);
	phpgtk_object_setup(phpgtk_ce_GSimpleAction);
	phpgtk_map_gtype("GSimpleAction", phpgtk_ce_GSimpleAction);

	phpgtk_ce_GSimpleActionGroup = register_class_GSimpleActionGroup(phpgtk_ce_GObject);
	phpgtk_object_setup(phpgtk_ce_GSimpleActionGroup);
	phpgtk_map_gtype("GSimpleActionGroup", phpgtk_ce_GSimpleActionGroup);
}

#define THIS_ACTION G_SIMPLE_ACTION(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

/* An action name or parameter type GLib would reject with a critical warning is refused here instead. */
static bool phpgtk_valid_action(zend_string *name, zend_string *parameter_type)
{
	if (!g_action_name_is_valid(ZSTR_VAL(name))) {
		zend_argument_value_error(1, "must be a valid action name");
		return false;
	}

	if (parameter_type != NULL && !g_variant_type_string_is_valid(ZSTR_VAL(parameter_type))) {
		zend_argument_value_error(2, "must be a valid GVariant type string");
		return false;
	}

	return true;
}

/* A parameter or state the action would reject with a critical warning is refused here instead. */
static bool phpgtk_matches_type(const GVariantType *expected, GVariant *given, uint32_t arg_num, const char *what)
{
	if (expected == NULL && given == NULL) {
		return true;
	}

	if (expected == NULL || given == NULL || !g_variant_is_of_type(given, expected)) {
		zend_argument_value_error(arg_num, "must be %s", what);
		return false;
	}

	return true;
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

	if (!phpgtk_valid_action(name, parameter_type)) {
		RETURN_THROWS();
	}

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

	if (!phpgtk_valid_action(name, parameter_type)) {
		RETURN_THROWS();
	}

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

	if (!phpgtk_matches_type(g_action_get_state_type(G_ACTION(THIS_ACTION)), (GVariant *) PHPGTK_PTR(value), 1, "of the action's state type")) {
		RETURN_THROWS();
	}

	g_simple_action_set_state(THIS_ACTION, (GVariant *) PHPGTK_PTR(value));
}

ZEND_METHOD(GSimpleAction, getName)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_STRING(g_action_get_name(G_ACTION(THIS_ACTION)));
}

ZEND_METHOD(GSimpleAction, getEnabled)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_BOOL(g_action_get_enabled(G_ACTION(THIS_ACTION)));
}

ZEND_METHOD(GSimpleAction, getState)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_variant_full(return_value, g_action_get_state(G_ACTION(THIS_ACTION)));
}

ZEND_METHOD(GSimpleAction, activate)
{
	zend_object *parameter = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(parameter, phpgtk_ce_GVariant)
	ZEND_PARSE_PARAMETERS_END();

	if (!phpgtk_matches_type(g_action_get_parameter_type(G_ACTION(THIS_ACTION)), (GVariant *) PHPGTK_OPTIONAL_PTR(parameter), 1,
			"null for an action without a parameter, or of its parameter type")) {
		RETURN_THROWS();
	}

	g_action_activate(G_ACTION(THIS_ACTION), (GVariant *) PHPGTK_OPTIONAL_PTR(parameter));
}

ZEND_METHOD(GSimpleAction, changeState)
{
	zend_object *value;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(value, phpgtk_ce_GVariant)
	ZEND_PARSE_PARAMETERS_END();

	if (!phpgtk_matches_type(g_action_get_state_type(G_ACTION(THIS_ACTION)), (GVariant *) PHPGTK_PTR(value), 1, "of the action's state type")) {
		RETURN_THROWS();
	}

	g_action_change_state(G_ACTION(THIS_ACTION), (GVariant *) PHPGTK_PTR(value));
}

/* ---- GSimpleActionGroup ------------------------------------------------ */

ZEND_METHOD(GSimpleActionGroup, new)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject_full(return_value, g_simple_action_group_new());
}

ZEND_METHOD(GSimpleActionGroup, addAction)
{
	phpgtk_action_map_add_action(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}

ZEND_METHOD(GSimpleActionGroup, removeAction)
{
	phpgtk_action_map_remove_action(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}

ZEND_METHOD(GSimpleActionGroup, lookupAction)
{
	phpgtk_action_map_lookup_action(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}

ZEND_METHOD(GSimpleActionGroup, hasAction)
{
	phpgtk_action_group_has_action(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}

ZEND_METHOD(GSimpleActionGroup, listActions)
{
	phpgtk_action_group_list_actions(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}

ZEND_METHOD(GSimpleActionGroup, activateAction)
{
	phpgtk_action_group_activate_action(INTERNAL_FUNCTION_PARAM_PASSTHRU);
}

/* ---- GActionMap / GActionGroup ----------------------------------------- */

/* $this's native object, implementing GActionMap and GActionGroup (GSimpleActionGroup, GApplication). */
#define THIS_MAP G_ACTION_MAP(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))
#define THIS_ACTION_GROUP G_ACTION_GROUP(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

void phpgtk_action_map_add_action(INTERNAL_FUNCTION_PARAMETERS)
{
	zend_object *action;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(action, phpgtk_ce_GSimpleAction)
	ZEND_PARSE_PARAMETERS_END();

	g_action_map_add_action(THIS_MAP, G_ACTION(PHPGTK_PTR(action)));
}

void phpgtk_action_map_remove_action(INTERNAL_FUNCTION_PARAMETERS)
{
	zend_string *name;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();

	g_action_map_remove_action(THIS_MAP, ZSTR_VAL(name));
}

void phpgtk_action_map_lookup_action(INTERNAL_FUNCTION_PARAMETERS)
{
	zend_string *name;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();

	phpgtk_box_gobject(return_value, g_action_map_lookup_action(THIS_MAP, ZSTR_VAL(name)));
}

void phpgtk_action_group_has_action(INTERNAL_FUNCTION_PARAMETERS)
{
	zend_string *name;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_BOOL(g_action_group_has_action(THIS_ACTION_GROUP, ZSTR_VAL(name)));
}

void phpgtk_action_group_list_actions(INTERNAL_FUNCTION_PARAMETERS)
{
	ZEND_PARSE_PARAMETERS_NONE();

	gchar **names = g_action_group_list_actions(THIS_ACTION_GROUP);

	array_init(return_value);
	for (gchar **name = names; name != NULL && *name != NULL; name++) {
		add_next_index_string(return_value, *name);
	}
	g_strfreev(names);
}

void phpgtk_action_group_activate_action(INTERNAL_FUNCTION_PARAMETERS)
{
	zend_string *name;
	zend_object *parameter = NULL;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(parameter, phpgtk_ce_GVariant)
	ZEND_PARSE_PARAMETERS_END();

	GAction *action = g_action_map_lookup_action(THIS_MAP, ZSTR_VAL(name));
	if (action == NULL) {
		zend_argument_value_error(1, "names no action in this group");
		RETURN_THROWS();
	}

	if (!phpgtk_matches_type(g_action_get_parameter_type(action), (GVariant *) PHPGTK_OPTIONAL_PTR(parameter), 2,
			"null for an action without a parameter, or of its parameter type")) {
		RETURN_THROWS();
	}

	g_action_group_activate_action(THIS_ACTION_GROUP, ZSTR_VAL(name), (GVariant *) PHPGTK_OPTIONAL_PTR(parameter));
}
