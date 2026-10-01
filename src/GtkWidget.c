#include "runtime.h"
#include "../stubs/GtkWidget_arginfo.h"

void phpgtk_register_GtkWidget(void)
{
	phpgtk_ce_GtkOrientation = register_class_GtkOrientation();

	phpgtk_ce_GtkWidget = register_class_GtkWidget(phpgtk_ce_GObject);
	phpgtk_object_setup(phpgtk_ce_GtkWidget);
	phpgtk_map_gtype("GtkWidget", phpgtk_ce_GtkWidget);

	phpgtk_ce_GtkBox = register_class_GtkBox(phpgtk_ce_GtkWidget);
	phpgtk_object_setup(phpgtk_ce_GtkBox);
	phpgtk_map_gtype("GtkBox", phpgtk_ce_GtkBox);

	phpgtk_ce_GtkPopoverMenuBar = register_class_GtkPopoverMenuBar(phpgtk_ce_GtkWidget);
	phpgtk_object_setup(phpgtk_ce_GtkPopoverMenuBar);
	phpgtk_map_gtype("GtkPopoverMenuBar", phpgtk_ce_GtkPopoverMenuBar);
}

#define THIS_WIDGET GTK_WIDGET(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

ZEND_METHOD(GtkWidget, show)
{
	ZEND_PARSE_PARAMETERS_NONE();

	gtk_widget_set_visible(THIS_WIDGET, TRUE);
}

ZEND_METHOD(GtkWidget, hide)
{
	ZEND_PARSE_PARAMETERS_NONE();

	gtk_widget_set_visible(THIS_WIDGET, FALSE);
}

ZEND_METHOD(GtkWidget, getVisible)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_BOOL(gtk_widget_get_visible(THIS_WIDGET));
}

ZEND_METHOD(GtkWidget, getRealized)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_BOOL(gtk_widget_get_realized(THIS_WIDGET));
}

ZEND_METHOD(GtkWidget, getMapped)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_BOOL(gtk_widget_get_mapped(THIS_WIDGET));
}

ZEND_METHOD(GtkWidget, setVisible)
{
	bool visible;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(visible)
	ZEND_PARSE_PARAMETERS_END();

	gtk_widget_set_visible(THIS_WIDGET, visible);
}

ZEND_METHOD(GtkWidget, getHexpand)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_BOOL(gtk_widget_get_hexpand(THIS_WIDGET));
}

ZEND_METHOD(GtkWidget, setHexpand)
{
	bool expand;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(expand)
	ZEND_PARSE_PARAMETERS_END();

	gtk_widget_set_hexpand(THIS_WIDGET, expand);
}

ZEND_METHOD(GtkWidget, getVexpand)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_BOOL(gtk_widget_get_vexpand(THIS_WIDGET));
}

ZEND_METHOD(GtkWidget, setVexpand)
{
	bool expand;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(expand)
	ZEND_PARSE_PARAMETERS_END();

	gtk_widget_set_vexpand(THIS_WIDGET, expand);
}

ZEND_METHOD(GtkWidget, getParent)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_widget_get_parent(THIS_WIDGET));
}

ZEND_METHOD(GtkWidget, insertActionGroup)
{
	zend_string *name;
	zend_object *group = NULL;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(group, phpgtk_ce_GObject)
	ZEND_PARSE_PARAMETERS_END();

	if (group != NULL && !G_IS_ACTION_GROUP(PHPGTK_PTR(group))) {
		zend_argument_type_error(2, "must implement GActionGroup, %s does not", G_OBJECT_TYPE_NAME(PHPGTK_PTR(group)));
		RETURN_THROWS();
	}

	gtk_widget_insert_action_group(THIS_WIDGET, ZSTR_VAL(name), group != NULL ? G_ACTION_GROUP(PHPGTK_PTR(group)) : NULL);
}

ZEND_METHOD(GtkWidget, activateAction)
{
	zend_string *name;
	zend_object *args = NULL;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(args, phpgtk_ce_GVariant)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_BOOL(gtk_widget_activate_action_variant(THIS_WIDGET, ZSTR_VAL(name), (GVariant *) PHPGTK_OPTIONAL_PTR(args)));
}

/* ---- GtkBox ------------------------------------------------------------ */

#define THIS_BOX GTK_BOX(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

ZEND_METHOD(GtkBox, new)
{
	zend_object *orientation;
	zend_long spacing;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS(orientation, phpgtk_ce_GtkOrientation)
		Z_PARAM_LONG(spacing)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();
	PHPGTK_REQUIRE_INITIALIZED();

	phpgtk_box_gobject(return_value, gtk_box_new((GtkOrientation) phpgtk_enum_value(orientation, 0), (int) spacing));
}

#define PHPGTK_BOX_CHILD_METHOD(name, call) \
ZEND_METHOD(GtkBox, name) \
{ \
	zend_object *child; \
	ZEND_PARSE_PARAMETERS_START(1, 1) \
		Z_PARAM_OBJ_OF_CLASS(child, phpgtk_ce_GtkWidget) \
	ZEND_PARSE_PARAMETERS_END(); \
	call(THIS_BOX, GTK_WIDGET(PHPGTK_PTR(child))); \
}

PHPGTK_BOX_CHILD_METHOD(append, gtk_box_append)
PHPGTK_BOX_CHILD_METHOD(prepend, gtk_box_prepend)
PHPGTK_BOX_CHILD_METHOD(remove, gtk_box_remove)

/* ---- GtkPopoverMenuBar ------------------------------------------------- */

#define THIS_BAR GTK_POPOVER_MENU_BAR(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

ZEND_METHOD(GtkPopoverMenuBar, newFromModel)
{
	zend_object *model = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(model, phpgtk_ce_GMenuModel)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();
	PHPGTK_REQUIRE_INITIALIZED();

	phpgtk_box_gobject(return_value, gtk_popover_menu_bar_new_from_model((GMenuModel *) PHPGTK_OPTIONAL_PTR(model)));
}

ZEND_METHOD(GtkPopoverMenuBar, getMenuModel)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_popover_menu_bar_get_menu_model(THIS_BAR));
}

ZEND_METHOD(GtkPopoverMenuBar, setMenuModel)
{
	zend_object *model = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(model, phpgtk_ce_GMenuModel)
	ZEND_PARSE_PARAMETERS_END();

	gtk_popover_menu_bar_set_menu_model(THIS_BAR, (GMenuModel *) PHPGTK_OPTIONAL_PTR(model));
}
