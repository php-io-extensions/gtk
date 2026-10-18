#include "runtime.h"
#include "../stubs/GdkTexture_arginfo.h"

ZEND_METHOD(GdkPaintable, getCurrentImage);
ZEND_METHOD(GdkPaintable, getFlags);
ZEND_METHOD(GdkPaintable, getIntrinsicWidth);
ZEND_METHOD(GdkPaintable, getIntrinsicHeight);
ZEND_METHOD(GdkPaintable, getIntrinsicAspectRatio);
ZEND_METHOD(GdkPaintable, computeConcreteSize);
ZEND_METHOD(GdkPaintable, invalidateContents);
ZEND_METHOD(GdkPaintable, invalidateSize);

static const phpgtk_interface_method phpgtk_GdkPaintable_bodies[] = {
	{"getCurrentImage", zim_GdkPaintable_getCurrentImage},
	{"getFlags", zim_GdkPaintable_getFlags},
	{"getIntrinsicWidth", zim_GdkPaintable_getIntrinsicWidth},
	{"getIntrinsicHeight", zim_GdkPaintable_getIntrinsicHeight},
	{"getIntrinsicAspectRatio", zim_GdkPaintable_getIntrinsicAspectRatio},
	{"computeConcreteSize", zim_GdkPaintable_computeConcreteSize},
	{"invalidateContents", zim_GdkPaintable_invalidateContents},
	{"invalidateSize", zim_GdkPaintable_invalidateSize},
	{NULL, NULL},
};

void phpgtk_register_GdkTexture(void)
{
	phpgtk_ce_GdkMemoryFormat = register_class_GdkMemoryFormat();

	phpgtk_ce_GdkPaintable = register_class_GdkPaintable();
	phpgtk_interface_bodies(phpgtk_ce_GdkPaintable, phpgtk_GdkPaintable_bodies);
	phpgtk_ce_GdkPaintable->interface_gets_implemented = phpgtk_interface_native_only;

	phpgtk_ce_GdkRectangle = register_class_GdkRectangle();

	phpgtk_ce_CairoRegion = register_class_CairoRegion();
	phpgtk_object_setup(phpgtk_ce_CairoRegion);

	phpgtk_ce_GBytes = register_class_GBytes();
	phpgtk_object_setup(phpgtk_ce_GBytes);

	phpgtk_ce_GdkTexture = register_class_GdkTexture(phpgtk_ce_GObject, phpgtk_ce_GdkPaintable);
	phpgtk_object_setup(phpgtk_ce_GdkTexture);
	phpgtk_map_gtype("GdkTexture", phpgtk_ce_GdkTexture);

	phpgtk_ce_GdkMemoryTexture = register_class_GdkMemoryTexture(phpgtk_ce_GdkTexture);
	phpgtk_object_setup(phpgtk_ce_GdkMemoryTexture);
	phpgtk_map_gtype("GdkMemoryTexture", phpgtk_ce_GdkMemoryTexture);

#if GTK_CHECK_VERSION(4, 16, 0)
	phpgtk_ce_GdkMemoryTextureBuilder = register_class_GdkMemoryTextureBuilder(phpgtk_ce_GObject);
	phpgtk_object_setup(phpgtk_ce_GdkMemoryTextureBuilder);
	phpgtk_map_gtype("GdkMemoryTextureBuilder", phpgtk_ce_GdkMemoryTextureBuilder);
#endif

#if GTK_CHECK_VERSION(4, 14, 0)
	phpgtk_ce_GdkDmabufFormats = register_class_GdkDmabufFormats();
	phpgtk_object_setup(phpgtk_ce_GdkDmabufFormats);
#endif

#if GTK_CHECK_VERSION(4, 14, 0) && defined(__linux__)
	phpgtk_ce_GdkDmabufTextureBuilder = register_class_GdkDmabufTextureBuilder(phpgtk_ce_GObject);
	phpgtk_object_setup(phpgtk_ce_GdkDmabufTextureBuilder);
	phpgtk_map_gtype("GdkDmabufTextureBuilder", phpgtk_ce_GdkDmabufTextureBuilder);
#endif
}

/* ---- GdkPaintable ------------------------------------------------------ */

/* $this's native object, implementing GdkPaintable (GdkTexture, GtkMediaStream). */
#define THIS_PAINTABLE GDK_PAINTABLE(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

ZEND_METHOD(GdkPaintable, getCurrentImage)
{
	ZEND_PARSE_PARAMETERS_NONE();

	/* (transfer full): PHP's reference replaces the one the call returned. */
	phpgtk_box_gobject_full(return_value, gdk_paintable_get_current_image(THIS_PAINTABLE));
}

ZEND_METHOD(GdkPaintable, getFlags)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG((zend_long) gdk_paintable_get_flags(THIS_PAINTABLE));
}

ZEND_METHOD(GdkPaintable, getIntrinsicWidth)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG(gdk_paintable_get_intrinsic_width(THIS_PAINTABLE));
}

ZEND_METHOD(GdkPaintable, getIntrinsicHeight)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG(gdk_paintable_get_intrinsic_height(THIS_PAINTABLE));
}

ZEND_METHOD(GdkPaintable, getIntrinsicAspectRatio)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_DOUBLE(gdk_paintable_get_intrinsic_aspect_ratio(THIS_PAINTABLE));
}

ZEND_METHOD(GdkPaintable, computeConcreteSize)
{
	double specified_width, specified_height, default_width, default_height;
	zval *concrete_width_ref, *concrete_height_ref;
	double concrete_width = 0.0;
	double concrete_height = 0.0;

	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_DOUBLE(specified_width)
		Z_PARAM_DOUBLE(specified_height)
		Z_PARAM_DOUBLE(default_width)
		Z_PARAM_DOUBLE(default_height)
		Z_PARAM_ZVAL(concrete_width_ref)
		Z_PARAM_ZVAL(concrete_height_ref)
	ZEND_PARSE_PARAMETERS_END();

	gdk_paintable_compute_concrete_size(THIS_PAINTABLE, specified_width, specified_height, default_width, default_height,
		&concrete_width, &concrete_height);

	ZEND_TRY_ASSIGN_REF_DOUBLE(concrete_width_ref, concrete_width);
	ZEND_TRY_ASSIGN_REF_DOUBLE(concrete_height_ref, concrete_height);
}

ZEND_METHOD(GdkPaintable, invalidateContents)
{
	ZEND_PARSE_PARAMETERS_NONE();

	gdk_paintable_invalidate_contents(THIS_PAINTABLE);
}

ZEND_METHOD(GdkPaintable, invalidateSize)
{
	ZEND_PARSE_PARAMETERS_NONE();

	gdk_paintable_invalidate_size(THIS_PAINTABLE);
}

/* ---- GdkRectangle ------------------------------------------------------ */

/* The struct a GdkRectangle object holds, its fields in declaration order: x, y, width, height. */
cairo_rectangle_int_t phpgtk_rectangle_from(zend_object *rectangle)
{
	cairo_rectangle_int_t out = {
		.x = (int) zval_get_long(OBJ_PROP_NUM(rectangle, 0)),
		.y = (int) zval_get_long(OBJ_PROP_NUM(rectangle, 1)),
		.width = (int) zval_get_long(OBJ_PROP_NUM(rectangle, 2)),
		.height = (int) zval_get_long(OBJ_PROP_NUM(rectangle, 3)),
	};

	return out;
}

void phpgtk_rectangle_to(zval *rv, const cairo_rectangle_int_t *rectangle)
{
	object_init_ex(rv, phpgtk_ce_GdkRectangle);
	ZVAL_LONG(OBJ_PROP_NUM(Z_OBJ_P(rv), 0), rectangle->x);
	ZVAL_LONG(OBJ_PROP_NUM(Z_OBJ_P(rv), 1), rectangle->y);
	ZVAL_LONG(OBJ_PROP_NUM(Z_OBJ_P(rv), 2), rectangle->width);
	ZVAL_LONG(OBJ_PROP_NUM(Z_OBJ_P(rv), 3), rectangle->height);
}

ZEND_METHOD(GdkRectangle, __construct)
{
	zend_long x, y, width, height;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(x)
		Z_PARAM_LONG(y)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();

	ZVAL_LONG(OBJ_PROP_NUM(Z_OBJ_P(ZEND_THIS), 0), x);
	ZVAL_LONG(OBJ_PROP_NUM(Z_OBJ_P(ZEND_THIS), 1), y);
	ZVAL_LONG(OBJ_PROP_NUM(Z_OBJ_P(ZEND_THIS), 2), width);
	ZVAL_LONG(OBJ_PROP_NUM(Z_OBJ_P(ZEND_THIS), 3), height);
}

/* ---- CairoRegion ------------------------------------------------------- */

#define THIS_REGION ((cairo_region_t *) PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

ZEND_METHOD(CairoRegion, createRectangle)
{
	zend_object *rectangle;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(rectangle, phpgtk_ce_GdkRectangle)
	ZEND_PARSE_PARAMETERS_END();

	cairo_rectangle_int_t rect = phpgtk_rectangle_from(rectangle);

	phpgtk_box_cairo_region_full(return_value, cairo_region_create_rectangle(&rect));
}

ZEND_METHOD(CairoRegion, getRectangle)
{
	zend_long nth;
	cairo_rectangle_int_t rect;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(nth)
	ZEND_PARSE_PARAMETERS_END();

	if (!phpgtk_long_in_range(nth, INT_MIN, INT_MAX, 1)) {
		RETURN_THROWS();
	}
	/* cairo reads the nth box without a bound: an index outside the region's rectangles reads past its boxes. */
	int count = cairo_region_num_rectangles(THIS_REGION);
	if (!PHPGTK_PROBE_OFF("cairo-region-nth") && (nth < 0 || nth >= count)) {
		zend_argument_value_error(1, "must be the index of one of the region's %d rectangles", count); /* binding:cairo-region-nth */
		RETURN_THROWS();
	}

	cairo_region_get_rectangle(THIS_REGION, (int) nth, &rect);
	phpgtk_rectangle_to(return_value, &rect);
}

ZEND_METHOD(CairoRegion, unionRectangle)
{
	zend_object *rectangle;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(rectangle, phpgtk_ce_GdkRectangle)
	ZEND_PARSE_PARAMETERS_END();

	cairo_rectangle_int_t rect = phpgtk_rectangle_from(rectangle);

	RETURN_LONG((zend_long) cairo_region_union_rectangle(THIS_REGION, &rect));
}

ZEND_METHOD(CairoRegion, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
}

ZEND_METHOD(CairoRegion, create)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_cairo_region_full(return_value, cairo_region_create());
}

ZEND_METHOD(CairoRegion, numRectangles)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG(cairo_region_num_rectangles(THIS_REGION));
}

/* ---- GBytes ------------------------------------------------------------ */

#define THIS_BYTES ((GBytes *) PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

ZEND_METHOD(GBytes, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
}

ZEND_METHOD(GBytes, new)
{
	zend_string *string = NULL;
	zend_long address = 0;
	zend_long size;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR_OR_LONG(string, address)
		Z_PARAM_LONG(size)
	ZEND_PARSE_PARAMETERS_END();

	/* The size is a gsize. */
	if (!phpgtk_long_in_range(size, 0, ZEND_LONG_MAX, 2)) {
		RETURN_THROWS();
	}

	if (string != NULL) {
		/* g_bytes_new() copies $size bytes from the string: past its length it reads past the string. */
		if (!PHPGTK_PROBE_OFF("gbytes-string-length") && ((size_t) size > ZSTR_LEN(string))) {
			zend_argument_value_error(2, "must not exceed the %zu bytes of $data", ZSTR_LEN(string)); /* binding:gbytes-string-length */
			RETURN_THROWS();
		}
		phpgtk_box_bytes_full(return_value, g_bytes_new(ZSTR_VAL(string), (gsize) size));
		return;
	}

	/* The address is trusted, as every pointer hand-off is: g_bytes_new() copies $size bytes from it. */
	phpgtk_box_bytes_full(return_value, g_bytes_new((gconstpointer) (uintptr_t) address, (gsize) size));
}

ZEND_METHOD(GBytes, getSize)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG((zend_long) g_bytes_get_size(THIS_BYTES));
}

ZEND_METHOD(GBytes, getData)
{
	gsize size = 0;

	ZEND_PARSE_PARAMETERS_NONE();

	gconstpointer data = g_bytes_get_data(THIS_BYTES, &size);

	if (data == NULL) {
		RETURN_EMPTY_STRING();
	}

	RETURN_STRINGL((const char *) data, size);
}

/* ---- GdkTexture -------------------------------------------------------- */

ZEND_METHOD(GdkTexture, getWidth)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG(gdk_texture_get_width(GDK_TEXTURE(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))));
}

ZEND_METHOD(GdkTexture, getHeight)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG(gdk_texture_get_height(GDK_TEXTURE(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))));
}

ZEND_METHOD(GdkMemoryTexture, new)
{
	zend_long width, height, stride;
	zend_object *format_object;
	zend_object *bytes;

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
		Z_PARAM_OBJ_OF_CLASS(format_object, phpgtk_ce_GdkMemoryFormat)
		Z_PARAM_OBJ_OF_CLASS(bytes, phpgtk_ce_GBytes)
		Z_PARAM_LONG(stride)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	/* width and height are ints, stride a gsize. GDK judges the sizes against the bytes: a critical and NULL. */
	if (!phpgtk_long_in_range(width, G_MININT, G_MAXINT, 1)
			|| !phpgtk_long_in_range(height, G_MININT, G_MAXINT, 2)
			|| !phpgtk_long_in_range(stride, 0, ZEND_LONG_MAX, 5)) {
		RETURN_THROWS();
	}

	phpgtk_box_gobject_full(return_value, gdk_memory_texture_new((int) width, (int) height,
		(GdkMemoryFormat) phpgtk_enum_value(format_object, 0), (GBytes *) PHPGTK_PTR(bytes), (gsize) stride));
}

#if GTK_CHECK_VERSION(4, 16, 0)

#define THIS_BUILDER GDK_MEMORY_TEXTURE_BUILDER(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

ZEND_METHOD(GdkMemoryTextureBuilder, new)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();

	/* The class is compiled against 4.16 headers; the GTK actually running may be older. */
	if (!PHPGTK_PROBE_OFF("gtk-version-4-16") && (gtk_check_version(4, 16, 0) != NULL)) {
		zend_value_error("GdkMemoryTextureBuilder needs GTK 4.16 or newer, this is %u.%u", gtk_get_major_version(), gtk_get_minor_version()); /* binding:gtk-version-4-16 */
		RETURN_THROWS();
	}

	phpgtk_box_gobject_full(return_value, gdk_memory_texture_builder_new());
}

ZEND_METHOD(GdkMemoryTextureBuilder, setBytes)
{
	zend_object *bytes;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(bytes, phpgtk_ce_GBytes)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	/* set_bytes takes its own reference. */
	gdk_memory_texture_builder_set_bytes(THIS_BUILDER, (GBytes *) PHPGTK_PTR(bytes));
}

ZEND_METHOD(GdkMemoryTextureBuilder, setWidth)
{
	zend_long width;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(width)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	if (!phpgtk_long_in_range(width, G_MININT, G_MAXINT, 1)) {
		RETURN_THROWS();
	}
	gdk_memory_texture_builder_set_width(THIS_BUILDER, (int) width);
}

ZEND_METHOD(GdkMemoryTextureBuilder, setHeight)
{
	zend_long height;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	if (!phpgtk_long_in_range(height, G_MININT, G_MAXINT, 1)) {
		RETURN_THROWS();
	}
	gdk_memory_texture_builder_set_height(THIS_BUILDER, (int) height);
}

ZEND_METHOD(GdkMemoryTextureBuilder, setFormat)
{
	zend_object *format_object;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(format_object, phpgtk_ce_GdkMemoryFormat)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	gdk_memory_texture_builder_set_format(THIS_BUILDER, (GdkMemoryFormat) phpgtk_enum_value(format_object, 0));
}

ZEND_METHOD(GdkMemoryTextureBuilder, setStride)
{
	zend_long stride;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(stride)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	if (stride < 0) {
		zend_argument_value_error(1, "must not be negative");
		RETURN_THROWS();
	}

	gdk_memory_texture_builder_set_stride(THIS_BUILDER, (gsize) stride);
}

ZEND_METHOD(GdkMemoryTextureBuilder, setUpdateTexture)
{
	zend_object *texture;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(texture, phpgtk_ce_GdkTexture)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	gdk_memory_texture_builder_set_update_texture(THIS_BUILDER, GDK_TEXTURE(PHPGTK_OPTIONAL_PTR(texture)));
}

ZEND_METHOD(GdkMemoryTextureBuilder, setUpdateRegion)
{
	zend_object *region = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(region, phpgtk_ce_CairoRegion)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	gdk_memory_texture_builder_set_update_region(THIS_BUILDER, (cairo_region_t *) PHPGTK_OPTIONAL_PTR(region));
}

ZEND_METHOD(GdkMemoryTextureBuilder, build)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();

	/* build() answers NULL with a critical warning when width, height, format, stride or bytes is unset; NULL reaches PHP as null. */
	phpgtk_box_gobject_full(return_value, gdk_memory_texture_builder_build(THIS_BUILDER));
}

#endif

#if GTK_CHECK_VERSION(4, 14, 0)

#define THIS_DMABUF_FORMATS ((GdkDmabufFormats *) PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

ZEND_METHOD(GdkDmabufFormats, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
}

ZEND_METHOD(GdkDmabufFormats, getNFormats)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG((zend_long) gdk_dmabuf_formats_get_n_formats(THIS_DMABUF_FORMATS));
}

ZEND_METHOD(GdkDmabufFormats, getFormat)
{
	zend_long idx;
	/* GDK leaves both unwritten for an index past its formats (with a critical): they answer 0. */
	guint32 fourcc = 0;
	guint64 modifier = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(idx)
	ZEND_PARSE_PARAMETERS_END();

	/* The index is a gsize: a negative one has no native form. */
	if (!phpgtk_long_in_range(idx, 0, ZEND_LONG_MAX, 1)) {
		RETURN_THROWS();
	}
	gdk_dmabuf_formats_get_format(THIS_DMABUF_FORMATS, (gsize) idx, &fourcc, &modifier);

	array_init_size(return_value, 2);
	add_next_index_long(return_value, (zend_long) fourcc);
	add_next_index_long(return_value, (zend_long) modifier);
}

ZEND_METHOD(GdkDmabufFormats, contains)
{
	zend_long fourcc, modifier;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(fourcc)
		Z_PARAM_LONG(modifier)
	ZEND_PARSE_PARAMETERS_END();

	if (!phpgtk_long_in_range(fourcc, 0, (zend_long) G_MAXUINT32, 1)) {
		RETURN_THROWS();
	}
	RETURN_BOOL(gdk_dmabuf_formats_contains(THIS_DMABUF_FORMATS, (guint32) fourcc, (guint64) modifier));
}

#endif

#if GTK_CHECK_VERSION(4, 14, 0) && defined(__linux__)

#define THIS_DMABUF_BUILDER GDK_DMABUF_TEXTURE_BUILDER(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

/* A plane is an unsigned int: one outside it has no native form, and GDK judges the rest (its setters document plane < 4). */
static bool phpgtk_dmabuf_plane(zend_long plane)
{
	return phpgtk_long_in_range(plane, 0, (zend_long) G_MAXUINT, 1);
}

ZEND_METHOD(GdkDmabufTextureBuilder, new)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();

	/* The class is compiled against 4.14 headers; the GTK actually running may be older. */
	if (!PHPGTK_PROBE_OFF("gtk-version-4-14-dmabuf-builder") && gtk_check_version(4, 14, 0) != NULL) {
		zend_value_error("GdkDmabufTextureBuilder needs GTK 4.14 or newer, this is %u.%u", gtk_get_major_version(), gtk_get_minor_version()); /* binding:gtk-version-4-14-dmabuf-builder */
		RETURN_THROWS();
	}

	phpgtk_box_gobject_full(return_value, gdk_dmabuf_texture_builder_new());
}

ZEND_METHOD(GdkDmabufTextureBuilder, setDisplay)
{
	zend_object *display;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(display, phpgtk_ce_GdkDisplay)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	gdk_dmabuf_texture_builder_set_display(THIS_DMABUF_BUILDER, GDK_DISPLAY(PHPGTK_PTR(display)));
}

/* Each setter takes an unsigned int (setFourcc a guint32, the same width). */
#define PHPGTK_DMABUF_UINT_SETTER(method, setter) \
ZEND_METHOD(GdkDmabufTextureBuilder, method) \
{ \
	zend_long value; \
\
	ZEND_PARSE_PARAMETERS_START(1, 1) \
		Z_PARAM_LONG(value) \
	ZEND_PARSE_PARAMETERS_END(); \
	PHPGTK_REQUIRE_MAIN_THREAD(); \
\
	if (!phpgtk_long_in_range(value, 0, (zend_long) G_MAXUINT, 1)) { \
		RETURN_THROWS(); \
	} \
	setter(THIS_DMABUF_BUILDER, (guint) value); \
}

PHPGTK_DMABUF_UINT_SETTER(setWidth, gdk_dmabuf_texture_builder_set_width)
PHPGTK_DMABUF_UINT_SETTER(setHeight, gdk_dmabuf_texture_builder_set_height)
PHPGTK_DMABUF_UINT_SETTER(setFourcc, gdk_dmabuf_texture_builder_set_fourcc)
PHPGTK_DMABUF_UINT_SETTER(setNPlanes, gdk_dmabuf_texture_builder_set_n_planes)

ZEND_METHOD(GdkDmabufTextureBuilder, setModifier)
{
	zend_long modifier;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(modifier)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	/* A modifier is a guint64: a negative PHP int is its two's-complement bits (DRM_FORMAT_MOD_INVALID is -1). */
	gdk_dmabuf_texture_builder_set_modifier(THIS_DMABUF_BUILDER, (guint64) modifier);
}

ZEND_METHOD(GdkDmabufTextureBuilder, setPremultiplied)
{
	bool premultiplied;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(premultiplied)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	gdk_dmabuf_texture_builder_set_premultiplied(THIS_DMABUF_BUILDER, premultiplied);
}

#define PHPGTK_DMABUF_PLANE_SETTER(method, setter, type) \
ZEND_METHOD(GdkDmabufTextureBuilder, method) \
{ \
	zend_long plane, value; \
\
	ZEND_PARSE_PARAMETERS_START(2, 2) \
		Z_PARAM_LONG(plane) \
		Z_PARAM_LONG(value) \
	ZEND_PARSE_PARAMETERS_END(); \
	PHPGTK_REQUIRE_MAIN_THREAD(); \
\
	if (!phpgtk_dmabuf_plane(plane)) { \
		RETURN_THROWS(); \
	} \
	if (!phpgtk_long_in_range(value, 0, (zend_long) G_MAXUINT, 2)) { \
		RETURN_THROWS(); \
	} \
	setter(THIS_DMABUF_BUILDER, (unsigned int) plane, (type) value); \
}

PHPGTK_DMABUF_PLANE_SETTER(setStride, gdk_dmabuf_texture_builder_set_stride, unsigned int)
PHPGTK_DMABUF_PLANE_SETTER(setOffset, gdk_dmabuf_texture_builder_set_offset, unsigned int)

ZEND_METHOD(GdkDmabufTextureBuilder, setFd)
{
	zend_long plane, fd;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(plane)
		Z_PARAM_LONG(fd)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	if (!phpgtk_dmabuf_plane(plane)) {
		RETURN_THROWS();
	}
	/* An fd is an int, borrowed as it is (-1 is GTK's own "unset") and judged by build(). */
	if (!phpgtk_long_in_range(fd, G_MININT, G_MAXINT, 2)) {
		RETURN_THROWS();
	}
	gdk_dmabuf_texture_builder_set_fd(THIS_DMABUF_BUILDER, (unsigned int) plane, (int) fd);
}

ZEND_METHOD(GdkDmabufTextureBuilder, setUpdateTexture)
{
	zend_object *texture;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(texture, phpgtk_ce_GdkTexture)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	gdk_dmabuf_texture_builder_set_update_texture(THIS_DMABUF_BUILDER, GDK_TEXTURE(PHPGTK_OPTIONAL_PTR(texture)));
}

ZEND_METHOD(GdkDmabufTextureBuilder, setUpdateRegion)
{
	zend_object *region = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(region, phpgtk_ce_CairoRegion)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	gdk_dmabuf_texture_builder_set_update_region(THIS_DMABUF_BUILDER, (cairo_region_t *) PHPGTK_OPTIONAL_PTR(region));
}

/* The texture is finalized: GTK is done with the fds. The callable runs once and goes. */
static void phpgtk_dmabuf_texture_destroyed(gpointer data)
{
	phpgtk_callout *callout = (phpgtk_callout *) data;

	/* Finalized on another thread: the callable is not entered there, and the release leaves it to its own thread. */
	if (!phpgtk_callout_foreign(callout)) {
		zval retval;

		phpgtk_callout_invoke(callout, 0, NULL, &retval);
		zval_ptr_dtor(&retval);
	}
	phpgtk_callout_release(callout);
}

ZEND_METHOD(GdkDmabufTextureBuilder, build)
{
	GError *error = NULL;
	zval *destroy = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL_OR_NULL(destroy)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	if (destroy != NULL && !zend_is_callable(destroy, 0, NULL)) {
		zend_argument_type_error(1, "must be a valid callback or null");
		RETURN_THROWS();
	}

	/* The fds stay the caller's, borrowed while the texture lives; $destroy says when it no longer does. */
	phpgtk_callout *callout = destroy != NULL ? phpgtk_callout_new(destroy) : NULL;
	GdkTexture *texture = gdk_dmabuf_texture_builder_build(THIS_DMABUF_BUILDER,
		callout != NULL ? phpgtk_dmabuf_texture_destroyed : NULL, callout, &error);
	if (texture == NULL) {
		/* GTK calls the destroy notify only for a texture it made. */
		if (callout != NULL) {
			phpgtk_callout_release(callout);
		}
		if (error != NULL) {
			phpgtk_throw_gerror(error);
			g_error_free(error);
			RETURN_THROWS();
		}
		RETURN_NULL();
	}

	phpgtk_box_gobject_full(return_value, texture);
}

#endif
