#include "runtime.h"
#include "../stubs/GMenu_arginfo.h"

void phpgtk_register_GMenu(void)
{
	phpgtk_ce_GMenuModel = register_class_GMenuModel(phpgtk_ce_GObject);
	phpgtk_object_setup(phpgtk_ce_GMenuModel);
	phpgtk_map_gtype("GMenuModel", phpgtk_ce_GMenuModel);

	phpgtk_ce_GMenu = register_class_GMenu(phpgtk_ce_GMenuModel);
	phpgtk_object_setup(phpgtk_ce_GMenu);
	phpgtk_map_gtype("GMenu", phpgtk_ce_GMenu);

	phpgtk_ce_GMenuItem = register_class_GMenuItem(phpgtk_ce_GObject);
	phpgtk_object_setup(phpgtk_ce_GMenuItem);
	phpgtk_map_gtype("GMenuItem", phpgtk_ce_GMenuItem);
}

#define THIS_MODEL G_MENU_MODEL(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))
#define THIS_MENU G_MENU(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))
#define THIS_ITEM G_MENU_ITEM(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))
#define OPTIONAL_STR(zs) ((zs) != NULL ? ZSTR_VAL(zs) : NULL)

/* A detailed action name GLib would reject with a critical warning is refused here instead. */
static bool phpgtk_valid_detailed_action(zend_string *detailed, uint32_t arg_num)
{
	if (detailed != NULL && !phpgtk_is_detailed_action(ZSTR_VAL(detailed))) {
		zend_argument_value_error(arg_num, "must be a valid detailed action name");
		return false;
	}

	return true;
}

/* ---- GMenuModel -------------------------------------------------------- */

ZEND_METHOD(GMenuModel, getNItems)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG(g_menu_model_get_n_items(THIS_MODEL));
}

ZEND_METHOD(GMenuModel, isMutable)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_BOOL(g_menu_model_is_mutable(THIS_MODEL));
}

/* ---- GMenu ------------------------------------------------------------- */

ZEND_METHOD(GMenu, new)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject_full(return_value, g_menu_new());
}

ZEND_METHOD(GMenu, append)
{
	zend_string *label = NULL;
	zend_string *action = NULL;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR_OR_NULL(label)
		Z_PARAM_STR_OR_NULL(action)
	ZEND_PARSE_PARAMETERS_END();

	if (!phpgtk_valid_detailed_action(action, 2)) {
		RETURN_THROWS();
	}

	g_menu_append(THIS_MENU, OPTIONAL_STR(label), OPTIONAL_STR(action));
}

ZEND_METHOD(GMenu, appendItem)
{
	zend_object *item;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(item, phpgtk_ce_GMenuItem)
	ZEND_PARSE_PARAMETERS_END();

	g_menu_append_item(THIS_MENU, G_MENU_ITEM(PHPGTK_PTR(item)));
}

ZEND_METHOD(GMenu, appendSection)
{
	zend_string *label = NULL;
	zend_object *section;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR_OR_NULL(label)
		Z_PARAM_OBJ_OF_CLASS(section, phpgtk_ce_GMenuModel)
	ZEND_PARSE_PARAMETERS_END();

	g_menu_append_section(THIS_MENU, OPTIONAL_STR(label), G_MENU_MODEL(PHPGTK_PTR(section)));
}

ZEND_METHOD(GMenu, appendSubmenu)
{
	zend_string *label = NULL;
	zend_object *submenu;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR_OR_NULL(label)
		Z_PARAM_OBJ_OF_CLASS(submenu, phpgtk_ce_GMenuModel)
	ZEND_PARSE_PARAMETERS_END();

	g_menu_append_submenu(THIS_MENU, OPTIONAL_STR(label), G_MENU_MODEL(PHPGTK_PTR(submenu)));
}

ZEND_METHOD(GMenu, prepend)
{
	zend_string *label = NULL;
	zend_string *action = NULL;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR_OR_NULL(label)
		Z_PARAM_STR_OR_NULL(action)
	ZEND_PARSE_PARAMETERS_END();

	if (!phpgtk_valid_detailed_action(action, 2)) {
		RETURN_THROWS();
	}

	g_menu_prepend(THIS_MENU, OPTIONAL_STR(label), OPTIONAL_STR(action));
}

ZEND_METHOD(GMenu, insert)
{
	zend_long position;
	zend_string *label = NULL;
	zend_string *action = NULL;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(position)
		Z_PARAM_STR_OR_NULL(label)
		Z_PARAM_STR_OR_NULL(action)
	ZEND_PARSE_PARAMETERS_END();

	if (!phpgtk_valid_detailed_action(action, 3)) {
		RETURN_THROWS();
	}

	g_menu_insert(THIS_MENU, (gint) position, OPTIONAL_STR(label), OPTIONAL_STR(action));
}

ZEND_METHOD(GMenu, remove)
{
	zend_long position;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();

	if (position < 0 || position >= g_menu_model_get_n_items(G_MENU_MODEL(THIS_MENU))) {
		zend_argument_value_error(1, "must be the position of an item in the menu");
		RETURN_THROWS();
	}

	g_menu_remove(THIS_MENU, (gint) position);
}

ZEND_METHOD(GMenu, removeAll)
{
	ZEND_PARSE_PARAMETERS_NONE();

	g_menu_remove_all(THIS_MENU);
}

ZEND_METHOD(GMenu, freeze)
{
	ZEND_PARSE_PARAMETERS_NONE();

	g_menu_freeze(THIS_MENU);
}

/* ---- GMenuItem --------------------------------------------------------- */

ZEND_METHOD(GMenuItem, new)
{
	zend_string *label = NULL;
	zend_string *action = NULL;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR_OR_NULL(label)
		Z_PARAM_STR_OR_NULL(action)
	ZEND_PARSE_PARAMETERS_END();

	if (!phpgtk_valid_detailed_action(action, 2)) {
		RETURN_THROWS();
	}

	phpgtk_box_gobject_full(return_value, g_menu_item_new(OPTIONAL_STR(label), OPTIONAL_STR(action)));
}

ZEND_METHOD(GMenuItem, setLabel)
{
	zend_string *label = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR_OR_NULL(label)
	ZEND_PARSE_PARAMETERS_END();

	g_menu_item_set_label(THIS_ITEM, OPTIONAL_STR(label));
}

ZEND_METHOD(GMenuItem, setDetailedAction)
{
	zend_string *action;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(action)
	ZEND_PARSE_PARAMETERS_END();

	if (!phpgtk_valid_detailed_action(action, 1)) {
		RETURN_THROWS();
	}

	g_menu_item_set_detailed_action(THIS_ITEM, ZSTR_VAL(action));
}

ZEND_METHOD(GMenuItem, setActionAndTargetValue)
{
	zend_string *action = NULL;
	zend_object *target = NULL;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR_OR_NULL(action)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(target, phpgtk_ce_GVariant)
	ZEND_PARSE_PARAMETERS_END();

	g_menu_item_set_action_and_target_value(THIS_ITEM, OPTIONAL_STR(action), (GVariant *) PHPGTK_OPTIONAL_PTR(target));
}

ZEND_METHOD(GMenuItem, setAttributeValue)
{
	zend_string *attribute;
	zend_object *value = NULL;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(attribute)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(value, phpgtk_ce_GVariant)
	ZEND_PARSE_PARAMETERS_END();

	g_menu_item_set_attribute_value(THIS_ITEM, ZSTR_VAL(attribute), (GVariant *) PHPGTK_OPTIONAL_PTR(value));
}

ZEND_METHOD(GMenuItem, getAttributeValue)
{
	zend_string *attribute;
	zend_string *expected = NULL;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(attribute)
		Z_PARAM_STR_OR_NULL(expected)
	ZEND_PARSE_PARAMETERS_END();

	if (expected != NULL && !g_variant_type_string_is_valid(ZSTR_VAL(expected))) {
		zend_argument_value_error(2, "must be a valid GVariant type string");
		RETURN_THROWS();
	}

	phpgtk_box_variant_full(return_value, g_menu_item_get_attribute_value(THIS_ITEM, ZSTR_VAL(attribute),
		expected != NULL ? G_VARIANT_TYPE(ZSTR_VAL(expected)) : NULL));
}

ZEND_METHOD(GMenuItem, setSubmenu)
{
	zend_object *submenu = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(submenu, phpgtk_ce_GMenuModel)
	ZEND_PARSE_PARAMETERS_END();

	g_menu_item_set_submenu(THIS_ITEM, (GMenuModel *) PHPGTK_OPTIONAL_PTR(submenu));
}

ZEND_METHOD(GMenuItem, setSection)
{
	zend_object *section = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(section, phpgtk_ce_GMenuModel)
	ZEND_PARSE_PARAMETERS_END();

	g_menu_item_set_section(THIS_ITEM, (GMenuModel *) PHPGTK_OPTIONAL_PTR(section));
}
