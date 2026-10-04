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
	zend_string *bytes;

	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
		Z_PARAM_OBJ_OF_CLASS(format_object, phpgtk_ce_GdkMemoryFormat)
		Z_PARAM_STR(bytes)
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
	if ((zend_long) ZSTR_LEN(bytes) < stride * (height - 1) + width * pixel) {
		zend_argument_value_error(4, "must hold every row (" ZEND_LONG_FMT " bytes), " ZEND_LONG_FMT " given", stride * (height - 1) + width * pixel, (zend_long) ZSTR_LEN(bytes));
		RETURN_THROWS();
	}

	GBytes *copy = g_bytes_new(ZSTR_VAL(bytes), ZSTR_LEN(bytes));
	GdkTexture *texture = gdk_memory_texture_new((int) width, (int) height, (GdkMemoryFormat) format, copy, (gsize) stride);
	g_bytes_unref(copy);

	phpgtk_box_gobject_full(return_value, texture);
}
