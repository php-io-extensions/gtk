#include "runtime.h"
#include "../stubs/GdkTexture_arginfo.h"

void phpgtk_register_GdkTexture(void)
{
	phpgtk_ce_GdkMemoryFormat = register_class_GdkMemoryFormat();

	phpgtk_ce_GdkTexture = register_class_GdkTexture(phpgtk_ce_GObject);
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
}

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
	zend_string *bytes = NULL;
	zend_long address = 0;

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
		Z_PARAM_OBJ_OF_CLASS(format_object, phpgtk_ce_GdkMemoryFormat)
		Z_PARAM_STR_OR_LONG(bytes, address)
		Z_PARAM_LONG(stride)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	zend_long format = phpgtk_enum_value(format_object, 0);
	/* GDK_MEMORY_R8G8B8 and _B8G8R8 take three bytes a pixel; every other layout bound here takes four. */
	zend_long pixel = format == 7 || format == 8 ? 3 : 4;

	/* Refused here: GDK answers each of these with a critical warning and NULL. */
	if (width < 1 || width > G_MAXINT) {
		zend_argument_value_error(1, "must be between 1 and %d", G_MAXINT);
		RETURN_THROWS();
	}
	if (height < 1 || height > G_MAXINT) {
		zend_argument_value_error(2, "must be between 1 and %d", G_MAXINT);
		RETURN_THROWS();
	}
	/* The X8 layouts are values 29 to 32, added in GTK 4.14: an older GTK does not know them. */
	if (format >= 29 && gtk_check_version(4, 14, 0) != NULL) {
		zend_argument_value_error(3, "needs GTK 4.14 or newer, this is %u.%u", gtk_get_major_version(), gtk_get_minor_version());
		RETURN_THROWS();
	}
	if (stride < width * pixel) {
		zend_argument_value_error(5, "must hold a row: at least " ZEND_LONG_FMT " bytes", width * pixel);
		RETURN_THROWS();
	}

	GBytes *copy;
	if (bytes != NULL) {
		if ((zend_long) ZSTR_LEN(bytes) < stride * (height - 1) + width * pixel) {
			zend_argument_value_error(4, "must hold every row (" ZEND_LONG_FMT " bytes), " ZEND_LONG_FMT " given", stride * (height - 1) + width * pixel, (zend_long) ZSTR_LEN(bytes));
			RETURN_THROWS();
		}
		copy = g_bytes_new(ZSTR_VAL(bytes), ZSTR_LEN(bytes));
	} else {
		if (address == 0) {
			zend_argument_value_error(4, "must not be a null address");
			RETURN_THROWS();
		}
		/* The address is trusted: an ext-fb buffer's pointer(), holding the rows the width, height and stride name. */
		copy = g_bytes_new((const void *) (uintptr_t) address, (gsize) (stride * (height - 1) + width * pixel));
	}

	GdkTexture *texture = gdk_memory_texture_new((int) width, (int) height, (GdkMemoryFormat) format, copy, (gsize) stride);
	g_bytes_unref(copy);

	phpgtk_box_gobject_full(return_value, texture);
}

#if GTK_CHECK_VERSION(4, 16, 0)

#define THIS_BUILDER GDK_MEMORY_TEXTURE_BUILDER(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

ZEND_METHOD(GdkMemoryTextureBuilder, new)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();

	/* The class is compiled against 4.16 headers; the GTK actually running may be older. */
	if (gtk_check_version(4, 16, 0) != NULL) {
		zend_value_error("GdkMemoryTextureBuilder needs GTK 4.16 or newer, this is %u.%u", gtk_get_major_version(), gtk_get_minor_version());
		RETURN_THROWS();
	}

	phpgtk_box_gobject_full(return_value, gdk_memory_texture_builder_new());
}

ZEND_METHOD(GdkMemoryTextureBuilder, setBytes)
{
	zend_string *bytes = NULL;
	zend_long address = 0;
	zend_long length = 0;
	bool length_null = true;

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR_OR_LONG(bytes, address)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG_OR_NULL(length, length_null)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	GBytes *copy;
	if (bytes != NULL) {
		if (!length_null) {
			zend_argument_value_error(2, "must be null when $bytes is a string");
			RETURN_THROWS();
		}
		copy = g_bytes_new(ZSTR_VAL(bytes), ZSTR_LEN(bytes));
	} else {
		if (address == 0) {
			zend_argument_value_error(1, "must not be a null address");
			RETURN_THROWS();
		}
		if (length_null || length < 0) {
			zend_argument_value_error(2, "must be the byte count to read at the address $bytes");
			RETURN_THROWS();
		}
		/* The address is trusted: an ext-fb buffer's pointer() with its size(). */
		copy = g_bytes_new((const void *) (uintptr_t) address, (gsize) length);
	}

	/* set_bytes keeps its own reference; the copy made here is let go after. */
	gdk_memory_texture_builder_set_bytes(THIS_BUILDER, copy);
	g_bytes_unref(copy);

	RETURN_COPY(ZEND_THIS);
}

ZEND_METHOD(GdkMemoryTextureBuilder, setWidth)
{
	zend_long width;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(width)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	if (width < 0) {
		zend_argument_value_error(1, "must not be negative");
		RETURN_THROWS();
	}

	gdk_memory_texture_builder_set_width(THIS_BUILDER, (int) width);

	RETURN_COPY(ZEND_THIS);
}

ZEND_METHOD(GdkMemoryTextureBuilder, setHeight)
{
	zend_long height;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	if (height < 0) {
		zend_argument_value_error(1, "must not be negative");
		RETURN_THROWS();
	}

	gdk_memory_texture_builder_set_height(THIS_BUILDER, (int) height);

	RETURN_COPY(ZEND_THIS);
}

ZEND_METHOD(GdkMemoryTextureBuilder, setFormat)
{
	zend_object *format_object;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(format_object, phpgtk_ce_GdkMemoryFormat)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	gdk_memory_texture_builder_set_format(THIS_BUILDER, (GdkMemoryFormat) phpgtk_enum_value(format_object, 0));

	RETURN_COPY(ZEND_THIS);
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

	RETURN_COPY(ZEND_THIS);
}

ZEND_METHOD(GdkMemoryTextureBuilder, setUpdateTexture)
{
	zend_object *texture;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(texture, phpgtk_ce_GdkTexture)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	gdk_memory_texture_builder_set_update_texture(THIS_BUILDER, GDK_TEXTURE(PHPGTK_OPTIONAL_PTR(texture)));

	RETURN_COPY(ZEND_THIS);
}

ZEND_METHOD(GdkMemoryTextureBuilder, setUpdateRegion)
{
	HashTable *rects = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY_HT_OR_NULL(rects)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	if (rects == NULL) {
		gdk_memory_texture_builder_set_update_region(THIS_BUILDER, NULL);
		RETURN_COPY(ZEND_THIS);
	}

	cairo_region_t *region = cairo_region_create();
	zval *rect;
	ZEND_HASH_FOREACH_VAL(rects, rect) {
		zval *x = Z_TYPE_P(rect) == IS_ARRAY ? zend_hash_index_find(Z_ARRVAL_P(rect), 0) : NULL;
		zval *y = x != NULL && Z_TYPE_P(x) == IS_LONG ? zend_hash_index_find(Z_ARRVAL_P(rect), 1) : NULL;
		zval *w = y != NULL && Z_TYPE_P(y) == IS_LONG ? zend_hash_index_find(Z_ARRVAL_P(rect), 2) : NULL;
		zval *h = w != NULL && Z_TYPE_P(w) == IS_LONG ? zend_hash_index_find(Z_ARRVAL_P(rect), 3) : NULL;

		if (h == NULL || Z_TYPE_P(h) != IS_LONG) {
			cairo_region_destroy(region);
			zend_argument_value_error(1, "each rect is [x, y, width, height], four integers");
			RETURN_THROWS();
		}

		cairo_rectangle_int_t rectangle = {
			.x = (int) Z_LVAL_P(x),
			.y = (int) Z_LVAL_P(y),
			.width = (int) Z_LVAL_P(w),
			.height = (int) Z_LVAL_P(h),
		};
		cairo_region_union_rectangle(region, &rectangle);
	} ZEND_HASH_FOREACH_END();

	/* set_update_region keeps its own reference; the region built here is let go after. */
	gdk_memory_texture_builder_set_update_region(THIS_BUILDER, region);
	cairo_region_destroy(region);

	RETURN_COPY(ZEND_THIS);
}

ZEND_METHOD(GdkMemoryTextureBuilder, build)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();

	/* build() answers NULL with a critical warning when width, height, format, stride or bytes is unset; NULL reaches PHP as null. */
	phpgtk_box_gobject_full(return_value, gdk_memory_texture_builder_build(THIS_BUILDER));
}

#endif
