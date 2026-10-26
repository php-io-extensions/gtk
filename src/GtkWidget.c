#include <limits.h>

#include "runtime.h"
#include "../stubs/GtkWidget_arginfo.h"

ZEND_METHOD(GtkNative, getForSurface);
ZEND_METHOD(GtkNative, realize);
ZEND_METHOD(GtkNative, unrealize);
ZEND_METHOD(GtkNative, getSurface);
ZEND_METHOD(GtkNative, getSurfaceTransform); /* GtkWindow.c */
ZEND_METHOD(GtkRoot, getDisplay);
ZEND_METHOD(GtkRoot, setFocus);
ZEND_METHOD(GtkRoot, getFocus);

static zend_class_entry *phpgtk_ce_GtkDirectionType;

static const phpgtk_interface_method phpgtk_GtkNative_bodies[] = {
	{"getForSurface", zim_GtkNative_getForSurface},
	{"realize", zim_GtkNative_realize},
	{"unrealize", zim_GtkNative_unrealize},
	{"getSurface", zim_GtkNative_getSurface},
	{"getSurfaceTransform", zim_GtkNative_getSurfaceTransform},
	{NULL, NULL},
};

static const phpgtk_interface_method phpgtk_GtkRoot_bodies[] = {
	{"getDisplay", zim_GtkRoot_getDisplay},
	{"setFocus", zim_GtkRoot_setFocus},
	{"getFocus", zim_GtkRoot_getFocus},
	{NULL, NULL},
};

void phpgtk_register_GtkWidget(void)
{
	phpgtk_ce_GtkOrientation = register_class_GtkOrientation();
	phpgtk_ce_GtkAlign = register_class_GtkAlign();
	phpgtk_ce_GtkDirectionType = register_class_GtkDirectionType();
	phpgtk_ce_GraphenePoint = register_class_GraphenePoint();
	phpgtk_ce_GrapheneSize = register_class_GrapheneSize();
	phpgtk_ce_GrapheneRect = register_class_GrapheneRect();

	phpgtk_ce_GtkNative = register_class_GtkNative();
	phpgtk_interface_bodies(phpgtk_ce_GtkNative, phpgtk_GtkNative_bodies);
	phpgtk_ce_GtkNative->interface_gets_implemented = phpgtk_interface_native_only;
	phpgtk_ce_GtkRoot = register_class_GtkRoot();
	phpgtk_interface_bodies(phpgtk_ce_GtkRoot, phpgtk_GtkRoot_bodies);
	phpgtk_ce_GtkRoot->interface_gets_implemented = phpgtk_interface_native_only;

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

	phpgtk_ce_GtkPositionType = register_class_GtkPositionType();
	phpgtk_ce_GtkPopover = register_class_GtkPopover(phpgtk_ce_GtkWidget, phpgtk_ce_GtkNative);
	phpgtk_object_setup(phpgtk_ce_GtkPopover);
	phpgtk_map_gtype("GtkPopover", phpgtk_ce_GtkPopover);

	phpgtk_ce_GtkPopoverMenu = register_class_GtkPopoverMenu(phpgtk_ce_GtkPopover);
	phpgtk_object_setup(phpgtk_ce_GtkPopoverMenu);
	phpgtk_map_gtype("GtkPopoverMenu", phpgtk_ce_GtkPopoverMenu);
}

#define THIS_WIDGET GTK_WIDGET(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

ZEND_METHOD(GtkWidget, show)
{
	ZEND_PARSE_PARAMETERS_NONE();

	/* Deprecated in GTK 4.10, still in its headers. */
	G_GNUC_BEGIN_IGNORE_DEPRECATIONS
	gtk_widget_show(THIS_WIDGET);
	G_GNUC_END_IGNORE_DEPRECATIONS
}

ZEND_METHOD(GtkWidget, hide)
{
	ZEND_PARSE_PARAMETERS_NONE();

	/* Deprecated in GTK 4.10, still in its headers. */
	G_GNUC_BEGIN_IGNORE_DEPRECATIONS
	gtk_widget_hide(THIS_WIDGET);
	G_GNUC_END_IGNORE_DEPRECATIONS
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

ZEND_METHOD(GtkWidget, activateActionVariant)
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

	if (!phpgtk_long_in_range(width, G_MININT, G_MAXINT, 1) || !phpgtk_long_in_range(height, G_MININT, G_MAXINT, 2)) {
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

ZEND_METHOD(GtkWidget, getScaleFactor)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG(gtk_widget_get_scale_factor(THIS_WIDGET));
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

ZEND_METHOD(GtkWidget, grabFocus)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_BOOL(gtk_widget_grab_focus(THIS_WIDGET));
}

ZEND_METHOD(GtkWidget, childFocus)
{
	zend_object *direction;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(direction, phpgtk_ce_GtkDirectionType)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_BOOL(gtk_widget_child_focus(THIS_WIDGET, (GtkDirectionType) phpgtk_enum_value(direction, GTK_DIR_TAB_FORWARD)));
}

ZEND_METHOD(GtkWidget, hasFocus)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_BOOL(gtk_widget_has_focus(THIS_WIDGET));
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
	if (!phpgtk_long_in_range(margin, G_MININT, G_MAXINT, 1)) { \
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

ZEND_METHOD(GtkWidget, addController)
{
	zend_object *controller;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(controller, phpgtk_ce_GtkEventController)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	/* gtk_widget_add_controller() takes the caller's reference; the PHP object keeps its own. */
	gtk_widget_add_controller(THIS_WIDGET, GTK_EVENT_CONTROLLER(g_object_ref(PHPGTK_PTR(controller))));
}

ZEND_METHOD(GtkWidget, computePoint)
{
	zend_object *target;
	zend_object *point;
	zval *out_point_ref;
	graphene_point_t out = GRAPHENE_POINT_INIT_ZERO;
	zval boxed;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJ_OF_CLASS(target, phpgtk_ce_GtkWidget)
		Z_PARAM_OBJ_OF_CLASS(point, phpgtk_ce_GraphenePoint)
		Z_PARAM_ZVAL(out_point_ref)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	graphene_point_t in = phpgtk_graphene_point_from(point);
	gboolean computed = gtk_widget_compute_point(THIS_WIDGET, GTK_WIDGET(PHPGTK_PTR(target)), &in, &out);

	phpgtk_graphene_point_to(&boxed, &out);
	ZEND_TRY_ASSIGN_REF_TMP(out_point_ref, &boxed);
	RETURN_BOOL(computed);
}

ZEND_METHOD(GtkWidget, pick)
{
	double x;
	double y;
	zend_long flags;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_DOUBLE(x)
		Z_PARAM_DOUBLE(y)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	phpgtk_box_gobject(return_value, gtk_widget_pick(THIS_WIDGET, x, y, (GtkPickFlags) flags));
}

ZEND_METHOD(GtkWidget, removeController)
{
	zend_object *controller;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(controller, phpgtk_ce_GtkEventController)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	gtk_widget_remove_controller(THIS_WIDGET, GTK_EVENT_CONTROLLER(PHPGTK_PTR(controller)));
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

	if (!phpgtk_long_in_range(for_size, G_MININT, G_MAXINT, 2)) {
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
	zval *out_bounds_ref;
	graphene_rect_t bounds = GRAPHENE_RECT_INIT_ZERO;
	zval boxed;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS(target, phpgtk_ce_GtkWidget)
		Z_PARAM_ZVAL(out_bounds_ref)
	ZEND_PARSE_PARAMETERS_END();

	gboolean computed = gtk_widget_compute_bounds(THIS_WIDGET, GTK_WIDGET(PHPGTK_PTR(target)), &bounds);

	phpgtk_graphene_rect_to(&boxed, &bounds);
	ZEND_TRY_ASSIGN_REF_TMP(out_bounds_ref, &boxed);
	RETURN_BOOL(computed);
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

ZEND_METHOD(GtkWidget, getDisplay)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_widget_get_display(THIS_WIDGET));
}

ZEND_METHOD(GtkWidget, getRoot)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_widget_get_root(THIS_WIDGET));
}

/* ---- GraphenePoint ----------------------------------------------------- */

ZEND_METHOD(GraphenePoint, __construct)
{
	double x, y;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_DOUBLE(x)
		Z_PARAM_DOUBLE(y)
	ZEND_PARSE_PARAMETERS_END();

	ZVAL_DOUBLE(OBJ_PROP_NUM(Z_OBJ_P(ZEND_THIS), 0), x);
	ZVAL_DOUBLE(OBJ_PROP_NUM(Z_OBJ_P(ZEND_THIS), 1), y);
}

/* The struct a GraphenePoint object holds: x, y. */
graphene_point_t phpgtk_graphene_point_from(zend_object *point)
{
	graphene_point_t out = GRAPHENE_POINT_INIT((float) zval_get_double(OBJ_PROP_NUM(point, 0)), (float) zval_get_double(OBJ_PROP_NUM(point, 1)));

	return out;
}

void phpgtk_graphene_point_to(zval *rv, const graphene_point_t *point)
{
	object_init_ex(rv, phpgtk_ce_GraphenePoint);
	ZVAL_DOUBLE(OBJ_PROP_NUM(Z_OBJ_P(rv), 0), point->x);
	ZVAL_DOUBLE(OBJ_PROP_NUM(Z_OBJ_P(rv), 1), point->y);
}

/* ---- GrapheneSize / GrapheneRect --------------------------------------- */

ZEND_METHOD(GrapheneSize, __construct)
{
	double width, height;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_DOUBLE(width)
		Z_PARAM_DOUBLE(height)
	ZEND_PARSE_PARAMETERS_END();

	ZVAL_DOUBLE(OBJ_PROP_NUM(Z_OBJ_P(ZEND_THIS), 0), width);
	ZVAL_DOUBLE(OBJ_PROP_NUM(Z_OBJ_P(ZEND_THIS), 1), height);
}

ZEND_METHOD(GrapheneRect, __construct)
{
	zend_object *origin;
	zend_object *size;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS(origin, phpgtk_ce_GraphenePoint)
		Z_PARAM_OBJ_OF_CLASS(size, phpgtk_ce_GrapheneSize)
	ZEND_PARSE_PARAMETERS_END();

	/* A second __construct() call replaces the fields it set before. */
	zval *origin_slot = OBJ_PROP_NUM(Z_OBJ_P(ZEND_THIS), 0);
	zval *size_slot = OBJ_PROP_NUM(Z_OBJ_P(ZEND_THIS), 1);
	zval_ptr_dtor(origin_slot);
	ZVAL_OBJ_COPY(origin_slot, origin);
	zval_ptr_dtor(size_slot);
	ZVAL_OBJ_COPY(size_slot, size);
}

/* A new GrapheneRect holding a new GraphenePoint origin and GrapheneSize size. */
void phpgtk_graphene_rect_to(zval *rv, const graphene_rect_t *rect)
{
	zval origin, size;

	phpgtk_graphene_point_to(&origin, &rect->origin);
	object_init_ex(&size, phpgtk_ce_GrapheneSize);
	ZVAL_DOUBLE(OBJ_PROP_NUM(Z_OBJ(size), 0), rect->size.width);
	ZVAL_DOUBLE(OBJ_PROP_NUM(Z_OBJ(size), 1), rect->size.height);

	object_init_ex(rv, phpgtk_ce_GrapheneRect);
	ZVAL_COPY_VALUE(OBJ_PROP_NUM(Z_OBJ_P(rv), 0), &origin);
	ZVAL_COPY_VALUE(OBJ_PROP_NUM(Z_OBJ_P(rv), 1), &size);
}

/* ---- GtkNative / GtkRoot ----------------------------------------------- */

/* $this's native object, implementing GtkNative (GtkWindow, GtkPopover) or GtkRoot (GtkWindow). */
#define THIS_NATIVE GTK_NATIVE(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))
#define THIS_ROOT GTK_ROOT(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

ZEND_METHOD(GtkNative, getForSurface)
{
	zend_object *surface;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(surface, phpgtk_ce_GdkSurface)
	ZEND_PARSE_PARAMETERS_END();

	phpgtk_box_gobject(return_value, gtk_native_get_for_surface(GDK_SURFACE(PHPGTK_PTR(surface))));
}

ZEND_METHOD(GtkNative, realize)
{
	ZEND_PARSE_PARAMETERS_NONE();

	gtk_native_realize(THIS_NATIVE);
}

ZEND_METHOD(GtkNative, unrealize)
{
	ZEND_PARSE_PARAMETERS_NONE();

	gtk_native_unrealize(THIS_NATIVE);
}

ZEND_METHOD(GtkNative, getSurface)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_native_get_surface(THIS_NATIVE));
}

ZEND_METHOD(GtkRoot, getDisplay)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_root_get_display(THIS_ROOT));
}

ZEND_METHOD(GtkRoot, setFocus)
{
	zend_object *focus = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(focus, phpgtk_ce_GtkWidget)
	ZEND_PARSE_PARAMETERS_END();

	gtk_root_set_focus(THIS_ROOT, focus != NULL ? GTK_WIDGET(PHPGTK_PTR(focus)) : NULL);
}

ZEND_METHOD(GtkRoot, getFocus)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_root_get_focus(THIS_ROOT));
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

/* GTK asserts the child's parent: NULL for an insert, this box for a remove or a move. */
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

#define PHPGTK_BOX_SIBLING_METHOD(name, call) \
ZEND_METHOD(GtkBox, name) \
{ \
	zend_object *child; \
	zend_object *sibling = NULL; \
	ZEND_PARSE_PARAMETERS_START(2, 2) \
		Z_PARAM_OBJ_OF_CLASS(child, phpgtk_ce_GtkWidget) \
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(sibling, phpgtk_ce_GtkWidget) \
	ZEND_PARSE_PARAMETERS_END(); \
	call(THIS_BOX, GTK_WIDGET(PHPGTK_PTR(child)), (GtkWidget *) PHPGTK_OPTIONAL_PTR(sibling)); \
}

PHPGTK_BOX_SIBLING_METHOD(insertChildAfter, gtk_box_insert_child_after)
PHPGTK_BOX_SIBLING_METHOD(reorderChildAfter, gtk_box_reorder_child_after)

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

	/* All four are ints; GTK judges a parented child and a span below 1 (criticals). */
	if (!phpgtk_long_in_range(column, G_MININT, G_MAXINT, 2)
			|| !phpgtk_long_in_range(row, G_MININT, G_MAXINT, 3)
			|| !phpgtk_long_in_range(width, G_MININT, G_MAXINT, 4)
			|| !phpgtk_long_in_range(height, G_MININT, G_MAXINT, 5)) {
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

	/* A spacing is a guint; GTK judges one past G_MAXINT16 (a critical). */
	if (!phpgtk_long_in_range(spacing, 0, (zend_long) G_MAXUINT, 1)) {
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

	if (!phpgtk_long_in_range(spacing, 0, (zend_long) G_MAXUINT, 1)) {
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

/* GTK asserts the child's parent: NULL for put, this fixed for move. */
#define PHPGTK_FIXED_POSITION_METHOD(name, call) \
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
	call(THIS_FIXED, GTK_WIDGET(PHPGTK_PTR(child)), x, y); \
}

PHPGTK_FIXED_POSITION_METHOD(put, gtk_fixed_put)
PHPGTK_FIXED_POSITION_METHOD(move, gtk_fixed_move)

ZEND_METHOD(GtkFixed, remove)
{
	zend_object *child;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(child, phpgtk_ce_GtkWidget)
	ZEND_PARSE_PARAMETERS_END();

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

	/* GTK leaves x and y unwritten (with a critical) for a widget that is not its child: they answer 0.0. */
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

/* ---- GtkPopover --------------------------------------------------------- */

#define THIS_POPOVER GTK_POPOVER(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

ZEND_METHOD(GtkPopover, setParent)
{
	zend_object *parent;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(parent, phpgtk_ce_GtkWidget)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	gtk_widget_set_parent(GTK_WIDGET(THIS_POPOVER), GTK_WIDGET(PHPGTK_PTR(parent)));
}

ZEND_METHOD(GtkPopover, unparent)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();

	gtk_widget_unparent(GTK_WIDGET(THIS_POPOVER));
}

ZEND_METHOD(GtkPopover, setPointingTo)
{
	zend_object *rectangle = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(rectangle, phpgtk_ce_GdkRectangle)
	ZEND_PARSE_PARAMETERS_END();

	if (rectangle == NULL) {
		gtk_popover_set_pointing_to(THIS_POPOVER, NULL);
		return;
	}

	zend_long x = zval_get_long(OBJ_PROP_NUM(rectangle, 0));
	zend_long y = zval_get_long(OBJ_PROP_NUM(rectangle, 1));
	zend_long width = zval_get_long(OBJ_PROP_NUM(rectangle, 2));
	zend_long height = zval_get_long(OBJ_PROP_NUM(rectangle, 3));

	/* Each field is an int; GTK stores the rectangle as given. */
	if (x < INT_MIN || x > INT_MAX || y < INT_MIN || y > INT_MAX || width < INT_MIN || width > INT_MAX || height < INT_MIN || height > INT_MAX) {
		zend_value_error("GtkPopover::setPointingTo(): the rectangle must fit a GdkRectangle, with no negative size");
		RETURN_THROWS();
	}

	GdkRectangle rect = { (int) x, (int) y, (int) width, (int) height };
	gtk_popover_set_pointing_to(THIS_POPOVER, &rect);
}

ZEND_METHOD(GtkPopover, getPointingTo)
{
	zval *rect_ref;
	GdkRectangle rect = { 0, 0, 0, 0 };
	zval boxed;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(rect_ref)
	ZEND_PARSE_PARAMETERS_END();

	/* With no rectangle set, GTK measures the parent: with none, a critical, FALSE and a zeroed rectangle. */
	gboolean set = gtk_popover_get_pointing_to(THIS_POPOVER, &rect);

	phpgtk_rectangle_to(&boxed, &rect);
	ZEND_TRY_ASSIGN_REF_TMP(rect_ref, &boxed);
	RETURN_BOOL(set);
}

ZEND_METHOD(GtkPopover, setHasArrow)
{
	bool has_arrow;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(has_arrow)
	ZEND_PARSE_PARAMETERS_END();

	gtk_popover_set_has_arrow(THIS_POPOVER, has_arrow);
}

ZEND_METHOD(GtkPopover, getHasArrow)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_BOOL(gtk_popover_get_has_arrow(THIS_POPOVER));
}

ZEND_METHOD(GtkPopover, new)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();
	PHPGTK_REQUIRE_INITIALIZED(); /* binding:gtk-initialized-popover */

	phpgtk_box_gobject(return_value, gtk_popover_new());
}

ZEND_METHOD(GtkPopover, setChild)
{
	zend_object *child = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(child, phpgtk_ce_GtkWidget)
	ZEND_PARSE_PARAMETERS_END();

	gtk_popover_set_child(THIS_POPOVER, child != NULL ? GTK_WIDGET(PHPGTK_PTR(child)) : NULL);
}

ZEND_METHOD(GtkPopover, getChild)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_popover_get_child(THIS_POPOVER));
}

ZEND_METHOD(GtkPopover, setAutohide)
{
	bool autohide;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(autohide)
	ZEND_PARSE_PARAMETERS_END();

	gtk_popover_set_autohide(THIS_POPOVER, autohide);
}

ZEND_METHOD(GtkPopover, getAutohide)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_BOOL(gtk_popover_get_autohide(THIS_POPOVER));
}

ZEND_METHOD(GtkPopover, setPosition)
{
	zend_object *position;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(position, phpgtk_ce_GtkPositionType)
	ZEND_PARSE_PARAMETERS_END();

	gtk_popover_set_position(THIS_POPOVER, (GtkPositionType) phpgtk_enum_value(position, 0));
}

ZEND_METHOD(GtkPopover, getPosition)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_return_enum(return_value, phpgtk_ce_GtkPositionType, gtk_popover_get_position(THIS_POPOVER));
}

ZEND_METHOD(GtkPopover, popup)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();

	gtk_popover_popup(THIS_POPOVER);
}

ZEND_METHOD(GtkPopover, popdown)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();

	gtk_popover_popdown(THIS_POPOVER);
}

/* ---- GtkPopoverMenu ----------------------------------------------------- */

ZEND_METHOD(GtkPopoverMenu, newFromModel)
{
	zend_object *model = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(model, phpgtk_ce_GMenuModel)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();
	PHPGTK_REQUIRE_INITIALIZED();

	phpgtk_box_gobject(return_value, gtk_popover_menu_new_from_model((GMenuModel *) PHPGTK_OPTIONAL_PTR(model)));
}

ZEND_METHOD(GtkPopoverMenu, getMenuModel)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_popover_menu_get_menu_model(GTK_POPOVER_MENU(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))));
}
