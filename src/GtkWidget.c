#include "runtime.h"
#include "../stubs/GtkWidget_arginfo.h"

void phpgtk_register_GtkWidget(void)
{
	phpgtk_ce_GtkOrientation = register_class_GtkOrientation();
	phpgtk_ce_GtkAlign = register_class_GtkAlign();

	phpgtk_ce_GtkWidget = register_class_GtkWidget(phpgtk_ce_GObject);
	phpgtk_object_setup(phpgtk_ce_GtkWidget);
	phpgtk_map_gtype("GtkWidget", phpgtk_ce_GtkWidget);

	phpgtk_ce_GtkBox = register_class_GtkBox(phpgtk_ce_GtkWidget);
	phpgtk_object_setup(phpgtk_ce_GtkBox);
	phpgtk_map_gtype("GtkBox", phpgtk_ce_GtkBox);

	phpgtk_ce_GtkGrid = register_class_GtkGrid(phpgtk_ce_GtkWidget);
	phpgtk_object_setup(phpgtk_ce_GtkGrid);
	phpgtk_map_gtype("GtkGrid", phpgtk_ce_GtkGrid);

	phpgtk_ce_GtkFixed = register_class_GtkFixed(phpgtk_ce_GtkWidget);
	phpgtk_object_setup(phpgtk_ce_GtkFixed);
	phpgtk_map_gtype("GtkFixed", phpgtk_ce_GtkFixed);

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

ZEND_METHOD(GtkWidget, activate)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_BOOL(gtk_widget_activate(THIS_WIDGET));
}

ZEND_METHOD(GtkWidget, getHalign)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_return_enum(return_value, phpgtk_ce_GtkAlign, (zend_long) gtk_widget_get_halign(THIS_WIDGET));
}

ZEND_METHOD(GtkWidget, setHalign)
{
	zend_object *align;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(align, phpgtk_ce_GtkAlign)
	ZEND_PARSE_PARAMETERS_END();

	gtk_widget_set_halign(THIS_WIDGET, (GtkAlign) phpgtk_enum_value(align, 0));
}

ZEND_METHOD(GtkWidget, getValign)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_return_enum(return_value, phpgtk_ce_GtkAlign, (zend_long) gtk_widget_get_valign(THIS_WIDGET));
}

ZEND_METHOD(GtkWidget, setValign)
{
	zend_object *align;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(align, phpgtk_ce_GtkAlign)
	ZEND_PARSE_PARAMETERS_END();

	gtk_widget_set_valign(THIS_WIDGET, (GtkAlign) phpgtk_enum_value(align, 0));
}

ZEND_METHOD(GtkWidget, setSizeRequest)
{
	zend_long width;
	zend_long height;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();

	if (!phpgtk_long_in_range(width, -1, G_MAXINT, 1) || !phpgtk_long_in_range(height, -1, G_MAXINT, 2)) {
		RETURN_THROWS();
	}

	gtk_widget_set_size_request(THIS_WIDGET, (int) width, (int) height);
}

ZEND_METHOD(GtkWidget, getSizeRequest)
{
	int width = -1;
	int height = -1;

	ZEND_PARSE_PARAMETERS_NONE();

	gtk_widget_get_size_request(THIS_WIDGET, &width, &height);

	array_init_size(return_value, 2);
	add_next_index_long(return_value, width);
	add_next_index_long(return_value, height);
}

ZEND_METHOD(GtkWidget, getWidth)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG(gtk_widget_get_width(THIS_WIDGET));
}

ZEND_METHOD(GtkWidget, getHeight)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG(gtk_widget_get_height(THIS_WIDGET));
}

ZEND_METHOD(GtkWidget, getSensitive)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_BOOL(gtk_widget_get_sensitive(THIS_WIDGET));
}

ZEND_METHOD(GtkWidget, getColor)
{
	GdkRGBA color;

	ZEND_PARSE_PARAMETERS_NONE();

	gtk_widget_get_color(THIS_WIDGET, &color);

	array_init_size(return_value, 4);
	add_next_index_double(return_value, color.red);
	add_next_index_double(return_value, color.green);
	add_next_index_double(return_value, color.blue);
	add_next_index_double(return_value, color.alpha);
}

ZEND_METHOD(GtkWidget, isSensitive)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_BOOL(gtk_widget_is_sensitive(THIS_WIDGET));
}

ZEND_METHOD(GtkWidget, setSensitive)
{
	bool sensitive;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(sensitive)
	ZEND_PARSE_PARAMETERS_END();

	gtk_widget_set_sensitive(THIS_WIDGET, sensitive);
}

/* GTK stores margins as gint16 and asserts the value fits. */
#define PHPGTK_WIDGET_MARGIN_METHOD(name, call) \
ZEND_METHOD(GtkWidget, name) \
{ \
	zend_long margin; \
	ZEND_PARSE_PARAMETERS_START(1, 1) \
		Z_PARAM_LONG(margin) \
	ZEND_PARSE_PARAMETERS_END(); \
	if (!phpgtk_long_in_range(margin, G_MININT16, G_MAXINT16, 1)) { \
		RETURN_THROWS(); \
	} \
	call(THIS_WIDGET, (int) margin); \
}

PHPGTK_WIDGET_MARGIN_METHOD(setMarginStart, gtk_widget_set_margin_start)
PHPGTK_WIDGET_MARGIN_METHOD(setMarginEnd, gtk_widget_set_margin_end)
PHPGTK_WIDGET_MARGIN_METHOD(setMarginTop, gtk_widget_set_margin_top)
PHPGTK_WIDGET_MARGIN_METHOD(setMarginBottom, gtk_widget_set_margin_bottom)

ZEND_METHOD(GtkWidget, addCssClass)
{
	zend_string *css_class;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(css_class)
	ZEND_PARSE_PARAMETERS_END();

	gtk_widget_add_css_class(THIS_WIDGET, ZSTR_VAL(css_class));
}

ZEND_METHOD(GtkWidget, removeCssClass)
{
	zend_string *css_class;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(css_class)
	ZEND_PARSE_PARAMETERS_END();

	gtk_widget_remove_css_class(THIS_WIDGET, ZSTR_VAL(css_class));
}

ZEND_METHOD(GtkWidget, hasCssClass)
{
	zend_string *css_class;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(css_class)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_BOOL(gtk_widget_has_css_class(THIS_WIDGET, ZSTR_VAL(css_class)));
}

ZEND_METHOD(GtkWidget, measure)
{
	zend_object *orientation;
	zend_long for_size;
	int minimum = 0;
	int natural = 0;
	int minimum_baseline = -1;
	int natural_baseline = -1;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS(orientation, phpgtk_ce_GtkOrientation)
		Z_PARAM_LONG(for_size)
	ZEND_PARSE_PARAMETERS_END();

	if (!phpgtk_long_in_range(for_size, -1, G_MAXINT, 2)) {
		RETURN_THROWS();
	}

	gtk_widget_measure(THIS_WIDGET, (GtkOrientation) phpgtk_enum_value(orientation, 0), (int) for_size,
		&minimum, &natural, &minimum_baseline, &natural_baseline);

	array_init_size(return_value, 4);
	add_assoc_long(return_value, "minimum", minimum);
	add_assoc_long(return_value, "natural", natural);
	add_assoc_long(return_value, "minimumBaseline", minimum_baseline);
	add_assoc_long(return_value, "naturalBaseline", natural_baseline);
}

ZEND_METHOD(GtkWidget, getNative)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_widget_get_native(THIS_WIDGET));
}

ZEND_METHOD(GtkWidget, computeBounds)
{
	zend_object *target;
	graphene_rect_t bounds;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(target, phpgtk_ce_GtkWidget)
	ZEND_PARSE_PARAMETERS_END();

	if (!gtk_widget_compute_bounds(THIS_WIDGET, GTK_WIDGET(PHPGTK_PTR(target)), &bounds)) {
		RETURN_NULL();
	}

	array_init_size(return_value, 4);
	add_next_index_double(return_value, bounds.origin.x);
	add_next_index_double(return_value, bounds.origin.y);
	add_next_index_double(return_value, bounds.size.width);
	add_next_index_double(return_value, bounds.size.height);
}

ZEND_METHOD(GtkWidget, getFirstChild)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_widget_get_first_child(THIS_WIDGET));
}

ZEND_METHOD(GtkWidget, getNextSibling)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_widget_get_next_sibling(THIS_WIDGET));
}

ZEND_METHOD(GtkWidget, getRoot)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_widget_get_root(THIS_WIDGET));
}

ZEND_METHOD(GtkWidget, getSurface)
{
	ZEND_PARSE_PARAMETERS_NONE();

	if (!GTK_IS_NATIVE(THIS_WIDGET)) {
		RETURN_NULL();
	}

	phpgtk_box_gobject(return_value, gtk_native_get_surface(GTK_NATIVE(THIS_WIDGET)));
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

/* Inserts need an unparented child, removes need our own child: GTK asserts both. */
#define PHPGTK_BOX_CHILD_METHOD(name, call, expected_parent) \
ZEND_METHOD(GtkBox, name) \
{ \
	zend_object *child; \
	ZEND_PARSE_PARAMETERS_START(1, 1) \
		Z_PARAM_OBJ_OF_CLASS(child, phpgtk_ce_GtkWidget) \
	ZEND_PARSE_PARAMETERS_END(); \
	if (!phpgtk_require_parent(GTK_WIDGET(PHPGTK_PTR(child)), expected_parent, 1)) { \
		RETURN_THROWS(); \
	} \
	call(THIS_BOX, GTK_WIDGET(PHPGTK_PTR(child))); \
}

PHPGTK_BOX_CHILD_METHOD(append, gtk_box_append, NULL)
PHPGTK_BOX_CHILD_METHOD(prepend, gtk_box_prepend, NULL)
PHPGTK_BOX_CHILD_METHOD(remove, gtk_box_remove, GTK_WIDGET(THIS_BOX))

#define PHPGTK_BOX_SIBLING_METHOD(name, call, child_parent) \
ZEND_METHOD(GtkBox, name) \
{ \
	zend_object *child; \
	zend_object *sibling = NULL; \
	ZEND_PARSE_PARAMETERS_START(2, 2) \
		Z_PARAM_OBJ_OF_CLASS(child, phpgtk_ce_GtkWidget) \
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(sibling, phpgtk_ce_GtkWidget) \
	ZEND_PARSE_PARAMETERS_END(); \
	if (!phpgtk_require_parent(GTK_WIDGET(PHPGTK_PTR(child)), child_parent, 1)) { \
		RETURN_THROWS(); \
	} \
	if (sibling != NULL && !phpgtk_require_parent(GTK_WIDGET(PHPGTK_PTR(sibling)), GTK_WIDGET(THIS_BOX), 2)) { \
		RETURN_THROWS(); \
	} \
	call(THIS_BOX, GTK_WIDGET(PHPGTK_PTR(child)), (GtkWidget *) PHPGTK_OPTIONAL_PTR(sibling)); \
}

PHPGTK_BOX_SIBLING_METHOD(insertChildAfter, gtk_box_insert_child_after, NULL)
PHPGTK_BOX_SIBLING_METHOD(reorderChildAfter, gtk_box_reorder_child_after, GTK_WIDGET(THIS_BOX))

ZEND_METHOD(GtkBox, getSpacing)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG(gtk_box_get_spacing(THIS_BOX));
}

ZEND_METHOD(GtkBox, setSpacing)
{
	zend_long spacing;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(spacing)
	ZEND_PARSE_PARAMETERS_END();

	gtk_box_set_spacing(THIS_BOX, (int) spacing);
}

ZEND_METHOD(GtkBox, getHomogeneous)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_BOOL(gtk_box_get_homogeneous(THIS_BOX));
}

ZEND_METHOD(GtkBox, setHomogeneous)
{
	bool homogeneous;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(homogeneous)
	ZEND_PARSE_PARAMETERS_END();

	gtk_box_set_homogeneous(THIS_BOX, homogeneous);
}

/* ---- GtkGrid ----------------------------------------------------------- */

#define THIS_GRID GTK_GRID(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

ZEND_METHOD(GtkGrid, new)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();
	PHPGTK_REQUIRE_INITIALIZED();

	phpgtk_box_gobject(return_value, gtk_grid_new());
}

ZEND_METHOD(GtkGrid, attach)
{
	zend_object *child;
	zend_long column;
	zend_long row;
	zend_long width;
	zend_long height;

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_OBJ_OF_CLASS(child, phpgtk_ce_GtkWidget)
		Z_PARAM_LONG(column)
		Z_PARAM_LONG(row)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();

	if (!phpgtk_require_parent(GTK_WIDGET(PHPGTK_PTR(child)), NULL, 1)
			|| !phpgtk_long_in_range(column, G_MININT, G_MAXINT, 2)
			|| !phpgtk_long_in_range(row, G_MININT, G_MAXINT, 3)
			|| !phpgtk_long_in_range(width, 1, G_MAXINT, 4)
			|| !phpgtk_long_in_range(height, 1, G_MAXINT, 5)) {
		RETURN_THROWS();
	}

	gtk_grid_attach(THIS_GRID, GTK_WIDGET(PHPGTK_PTR(child)), (int) column, (int) row, (int) width, (int) height);
}

ZEND_METHOD(GtkGrid, remove)
{
	zend_object *child;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(child, phpgtk_ce_GtkWidget)
	ZEND_PARSE_PARAMETERS_END();

	if (!phpgtk_require_parent(GTK_WIDGET(PHPGTK_PTR(child)), GTK_WIDGET(THIS_GRID), 1)) {
		RETURN_THROWS();
	}

	gtk_grid_remove(THIS_GRID, GTK_WIDGET(PHPGTK_PTR(child)));
}

ZEND_METHOD(GtkGrid, getChildAt)
{
	zend_long column;
	zend_long row;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(column)
		Z_PARAM_LONG(row)
	ZEND_PARSE_PARAMETERS_END();

	if (!phpgtk_long_in_range(column, G_MININT, G_MAXINT, 1) || !phpgtk_long_in_range(row, G_MININT, G_MAXINT, 2)) {
		RETURN_THROWS();
	}

	phpgtk_box_gobject(return_value, gtk_grid_get_child_at(THIS_GRID, (int) column, (int) row));
}

ZEND_METHOD(GtkGrid, getRowSpacing)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG(gtk_grid_get_row_spacing(THIS_GRID));
}

ZEND_METHOD(GtkGrid, setRowSpacing)
{
	zend_long spacing;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(spacing)
	ZEND_PARSE_PARAMETERS_END();

	/* GTK asserts spacing <= G_MAXINT16; a negative long would wrap to a huge guint. */
	if (!phpgtk_long_in_range(spacing, 0, G_MAXINT16, 1)) {
		RETURN_THROWS();
	}

	gtk_grid_set_row_spacing(THIS_GRID, (guint) spacing);
}

ZEND_METHOD(GtkGrid, getColumnSpacing)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG(gtk_grid_get_column_spacing(THIS_GRID));
}

ZEND_METHOD(GtkGrid, setColumnSpacing)
{
	zend_long spacing;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(spacing)
	ZEND_PARSE_PARAMETERS_END();

	if (!phpgtk_long_in_range(spacing, 0, G_MAXINT16, 1)) {
		RETURN_THROWS();
	}

	gtk_grid_set_column_spacing(THIS_GRID, (guint) spacing);
}

/* ---- GtkFixed ---------------------------------------------------------- */

#define THIS_FIXED GTK_FIXED(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

ZEND_METHOD(GtkFixed, new)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();
	PHPGTK_REQUIRE_INITIALIZED();

	phpgtk_box_gobject(return_value, gtk_fixed_new());
}

/* put needs an unparented child, move needs our own child: GTK asserts both. */
#define PHPGTK_FIXED_POSITION_METHOD(name, call, expected_parent) \
ZEND_METHOD(GtkFixed, name) \
{ \
	zend_object *child; \
	double x; \
	double y; \
	ZEND_PARSE_PARAMETERS_START(3, 3) \
		Z_PARAM_OBJ_OF_CLASS(child, phpgtk_ce_GtkWidget) \
		Z_PARAM_DOUBLE(x) \
		Z_PARAM_DOUBLE(y) \
	ZEND_PARSE_PARAMETERS_END(); \
	if (!phpgtk_require_parent(GTK_WIDGET(PHPGTK_PTR(child)), expected_parent, 1)) { \
		RETURN_THROWS(); \
	} \
	call(THIS_FIXED, GTK_WIDGET(PHPGTK_PTR(child)), x, y); \
}

PHPGTK_FIXED_POSITION_METHOD(put, gtk_fixed_put, NULL)
PHPGTK_FIXED_POSITION_METHOD(move, gtk_fixed_move, GTK_WIDGET(THIS_FIXED))

ZEND_METHOD(GtkFixed, remove)
{
	zend_object *child;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(child, phpgtk_ce_GtkWidget)
	ZEND_PARSE_PARAMETERS_END();

	if (!phpgtk_require_parent(GTK_WIDGET(PHPGTK_PTR(child)), GTK_WIDGET(THIS_FIXED), 1)) {
		RETURN_THROWS();
	}

	gtk_fixed_remove(THIS_FIXED, GTK_WIDGET(PHPGTK_PTR(child)));
}

ZEND_METHOD(GtkFixed, getChildPosition)
{
	zend_object *child;
	double x = 0.0;
	double y = 0.0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(child, phpgtk_ce_GtkWidget)
	ZEND_PARSE_PARAMETERS_END();

	if (!phpgtk_require_parent(GTK_WIDGET(PHPGTK_PTR(child)), GTK_WIDGET(THIS_FIXED), 1)) {
		RETURN_THROWS();
	}

	gtk_fixed_get_child_position(THIS_FIXED, GTK_WIDGET(PHPGTK_PTR(child)), &x, &y);

	array_init_size(return_value, 2);
	add_next_index_double(return_value, x);
	add_next_index_double(return_value, y);
}

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
