#include "runtime.h"
#include "../stubs/Pango_arginfo.h"

_Static_assert(PANGO_TAB_LEFT == 0 && PANGO_TAB_RIGHT == 1 && PANGO_TAB_CENTER == 2 && PANGO_TAB_DECIMAL == 3,
	"PangoTabAlign values differ from the stub's PangoTabAlign enum");

void phpgtk_register_Pango(int module_number)
{
	register_Pango_symbols(module_number);

	phpgtk_ce_PangoTabAlign = register_class_PangoTabAlign();

	phpgtk_ce_PangoLanguage = register_class_PangoLanguage();
	phpgtk_object_setup(phpgtk_ce_PangoLanguage);
	phpgtk_ce_PangoFontDescription = register_class_PangoFontDescription();
	phpgtk_object_setup(phpgtk_ce_PangoFontDescription);
	phpgtk_ce_PangoFontMetrics = register_class_PangoFontMetrics();
	phpgtk_object_setup(phpgtk_ce_PangoFontMetrics);
	phpgtk_ce_PangoTabArray = register_class_PangoTabArray();
	phpgtk_object_setup(phpgtk_ce_PangoTabArray);

#define PHPGTK_PANGO_CLASS(name) \
	phpgtk_ce_##name = register_class_##name(phpgtk_ce_GObject); \
	phpgtk_object_setup(phpgtk_ce_##name); \
	phpgtk_map_gtype(#name, phpgtk_ce_##name)

	PHPGTK_PANGO_CLASS(PangoContext);
	PHPGTK_PANGO_CLASS(PangoFont);
	PHPGTK_PANGO_CLASS(PangoFontFace);
	PHPGTK_PANGO_CLASS(PangoFontFamily);

#undef PHPGTK_PANGO_CLASS
}

#define THIS_PTR PHPGTK_PTR(Z_OBJ_P(ZEND_THIS))

/* ---- PangoLanguage ----------------------------------------------------- */

ZEND_METHOD(PangoLanguage, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
}

ZEND_METHOD(PangoLanguage, fromString)
{
	zend_string *language = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR_OR_NULL(language)
	ZEND_PARSE_PARAMETERS_END();

	phpgtk_box_language(return_value, pango_language_from_string(language != NULL ? ZSTR_VAL(language) : NULL));
}

ZEND_METHOD(PangoLanguage, toString)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_STRING(pango_language_to_string((PangoLanguage *) THIS_PTR));
}

/* ---- PangoFontDescription ---------------------------------------------- */

ZEND_METHOD(PangoFontDescription, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
}

ZEND_METHOD(PangoFontDescription, fromString)
{
	zend_string *str;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(str)
	ZEND_PARSE_PARAMETERS_END();

	phpgtk_box_font_description_full(return_value, pango_font_description_from_string(ZSTR_VAL(str)));
}

/* ---- PangoContext ------------------------------------------------------ */

ZEND_METHOD(PangoContext, getMetrics)
{
	zend_object *desc = NULL;
	zend_object *language = NULL;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(desc, phpgtk_ce_PangoFontDescription)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(language, phpgtk_ce_PangoLanguage)
	ZEND_PARSE_PARAMETERS_END();

	phpgtk_box_font_metrics_full(return_value, pango_context_get_metrics(PANGO_CONTEXT(THIS_PTR),
		(const PangoFontDescription *) PHPGTK_OPTIONAL_PTR(desc), (PangoLanguage *) PHPGTK_OPTIONAL_PTR(language)));
}

ZEND_METHOD(PangoContext, loadFont)
{
	zend_object *desc;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(desc, phpgtk_ce_PangoFontDescription)
	ZEND_PARSE_PARAMETERS_END();

	phpgtk_box_gobject_full(return_value, pango_context_load_font(PANGO_CONTEXT(THIS_PTR), (const PangoFontDescription *) PHPGTK_PTR(desc)));
}

/* ---- PangoFontMetrics -------------------------------------------------- */

ZEND_METHOD(PangoFontMetrics, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
}

ZEND_METHOD(PangoFontMetrics, getAscent)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG(pango_font_metrics_get_ascent((PangoFontMetrics *) THIS_PTR));
}

ZEND_METHOD(PangoFontMetrics, getDescent)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG(pango_font_metrics_get_descent((PangoFontMetrics *) THIS_PTR));
}

ZEND_METHOD(PangoFontMetrics, getHeight)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG(pango_font_metrics_get_height((PangoFontMetrics *) THIS_PTR));
}

ZEND_METHOD(PangoFontMetrics, getApproximateCharWidth)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG(pango_font_metrics_get_approximate_char_width((PangoFontMetrics *) THIS_PTR));
}

/* ---- PangoFont, PangoFontFace, PangoFontFamily ------------------------- */

ZEND_METHOD(PangoFont, getFace)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, pango_font_get_face(PANGO_FONT(THIS_PTR)));
}

ZEND_METHOD(PangoFontFace, getFamily)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, pango_font_face_get_family(PANGO_FONT_FACE(THIS_PTR)));
}

ZEND_METHOD(PangoFontFamily, isMonospace)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_BOOL(pango_font_family_is_monospace(PANGO_FONT_FAMILY(THIS_PTR)));
}

/* ---- PangoTabArray ----------------------------------------------------- */

ZEND_METHOD(PangoTabArray, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
}

ZEND_METHOD(PangoTabArray, new)
{
	zend_long initial_size;
	bool positions_in_pixels;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(initial_size)
		Z_PARAM_BOOL(positions_in_pixels)
	ZEND_PARSE_PARAMETERS_END();

	phpgtk_box_tab_array_full(return_value, pango_tab_array_new((gint) initial_size, positions_in_pixels));
}

ZEND_METHOD(PangoTabArray, setTab)
{
	zend_long tab_index, location;
	zend_object *alignment;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(tab_index)
		Z_PARAM_OBJ_OF_CLASS(alignment, phpgtk_ce_PangoTabAlign)
		Z_PARAM_LONG(location)
	ZEND_PARSE_PARAMETERS_END();

	pango_tab_array_set_tab((PangoTabArray *) THIS_PTR, (gint) tab_index,
		(PangoTabAlign) phpgtk_enum_value(alignment, PANGO_TAB_LEFT), (gint) location);
}

ZEND_METHOD(PangoTabArray, getTab)
{
	zend_long tab_index;
	zval *alignment_ref, *location_ref;
	PangoTabAlign alignment = PANGO_TAB_LEFT;
	gint location = 0;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(tab_index)
		Z_PARAM_ZVAL(alignment_ref)
		Z_PARAM_ZVAL(location_ref)
	ZEND_PARSE_PARAMETERS_END();

	pango_tab_array_get_tab((PangoTabArray *) THIS_PTR, (gint) tab_index, &alignment, &location);

	zval boxed;
	phpgtk_return_enum(&boxed, phpgtk_ce_PangoTabAlign, (zend_long) alignment);
	ZEND_TRY_ASSIGN_REF_TMP(alignment_ref, &boxed);
	ZEND_TRY_ASSIGN_REF_LONG(location_ref, location);
}

ZEND_METHOD(PangoTabArray, getPositionsInPixels)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_BOOL(pango_tab_array_get_positions_in_pixels((PangoTabArray *) THIS_PTR));
}
