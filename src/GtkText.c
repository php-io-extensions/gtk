#include "runtime.h"
#include "../stubs/GtkText_arginfo.h"

void phpgtk_register_GtkText(void)
{
	phpgtk_ce_GtkTextIter = register_class_GtkTextIter();
	phpgtk_object_setup(phpgtk_ce_GtkTextIter);

#define PHPGTK_TEXT_CLASS(name) \
	phpgtk_ce_##name = register_class_##name(phpgtk_ce_GObject); \
	phpgtk_object_setup(phpgtk_ce_##name); \
	phpgtk_map_gtype(#name, phpgtk_ce_##name)

	PHPGTK_TEXT_CLASS(GtkTextMark);
	PHPGTK_TEXT_CLASS(GtkTextTag);
	PHPGTK_TEXT_CLASS(GtkTextTagTable);
	PHPGTK_TEXT_CLASS(GtkAdjustment);

#undef PHPGTK_TEXT_CLASS
}

/* The receiving iter, refused (GtkException) once its buffer's text changed. */
#define FRESH_THIS_ITER() \
	GtkTextIter *iter = phpgtk_fresh_iter(Z_OBJ_P(ZEND_THIS)); \
	if (iter == NULL) { \
		RETURN_THROWS(); \
	}
#define THIS_TABLE GTK_TEXT_TAG_TABLE(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))
#define THIS_ADJUSTMENT GTK_ADJUSTMENT(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

/* ---- GtkTextIter ------------------------------------------------------- */

ZEND_METHOD(GtkTextIter, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
}

ZEND_METHOD(GtkTextIter, getLine)
{
	ZEND_PARSE_PARAMETERS_NONE();

	FRESH_THIS_ITER();
	RETURN_LONG(gtk_text_iter_get_line(iter));
}

ZEND_METHOD(GtkTextIter, getLineOffset)
{
	ZEND_PARSE_PARAMETERS_NONE();

	FRESH_THIS_ITER();
	RETURN_LONG(gtk_text_iter_get_line_offset(iter));
}

ZEND_METHOD(GtkTextIter, getOffset)
{
	ZEND_PARSE_PARAMETERS_NONE();

	FRESH_THIS_ITER();
	RETURN_LONG(gtk_text_iter_get_offset(iter));
}

ZEND_METHOD(GtkTextIter, hasTag)
{
	zend_object *tag;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(tag, phpgtk_ce_GtkTextTag)
	ZEND_PARSE_PARAMETERS_END();

	FRESH_THIS_ITER();
	RETURN_BOOL(gtk_text_iter_has_tag(iter, GTK_TEXT_TAG(PHPGTK_PTR(tag))));
}

ZEND_METHOD(GtkTextIter, getTags)
{
	ZEND_PARSE_PARAMETERS_NONE();

	FRESH_THIS_ITER();
	GSList *tags = gtk_text_iter_get_tags(iter);
	array_init_size(return_value, g_slist_length(tags));
	for (GSList *node = tags; node != NULL; node = node->next) {
		zval boxed;
		phpgtk_box_gobject(&boxed, node->data);
		add_next_index_zval(return_value, &boxed);
	}
	g_slist_free(tags);
}

/* ---- GtkTextTag -------------------------------------------------------- */

ZEND_METHOD(GtkTextTag, new)
{
	zend_string *name = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	phpgtk_box_gobject_full(return_value, gtk_text_tag_new(name != NULL ? ZSTR_VAL(name) : NULL));
}

/* ---- GtkTextTagTable --------------------------------------------------- */

ZEND_METHOD(GtkTextTagTable, add)
{
	zend_object *tag_obj;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(tag_obj, phpgtk_ce_GtkTextTag)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	RETURN_BOOL(gtk_text_tag_table_add(THIS_TABLE, GTK_TEXT_TAG(PHPGTK_PTR(tag_obj))));
}

ZEND_METHOD(GtkTextTagTable, remove)
{
	zend_object *tag_obj;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(tag_obj, phpgtk_ce_GtkTextTag)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	gtk_text_tag_table_remove(THIS_TABLE, GTK_TEXT_TAG(PHPGTK_PTR(tag_obj)));
}

ZEND_METHOD(GtkTextTagTable, lookup)
{
	zend_string *name;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();

	phpgtk_box_gobject(return_value, gtk_text_tag_table_lookup(THIS_TABLE, ZSTR_VAL(name)));
}

/* ---- GtkAdjustment ----------------------------------------------------- */

ZEND_METHOD(GtkAdjustment, new)
{
	double value, lower, upper, step, page, page_size;

	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_DOUBLE(value)
		Z_PARAM_DOUBLE(lower)
		Z_PARAM_DOUBLE(upper)
		Z_PARAM_DOUBLE(step)
		Z_PARAM_DOUBLE(page)
		Z_PARAM_DOUBLE(page_size)
	ZEND_PARSE_PARAMETERS_END();

	phpgtk_box_gobject(return_value, gtk_adjustment_new(value, lower, upper, step, page, page_size));
}

ZEND_METHOD(GtkAdjustment, configure)
{
	double value, lower, upper, step, page, page_size;

	ZEND_PARSE_PARAMETERS_START(6, 6)
		Z_PARAM_DOUBLE(value)
		Z_PARAM_DOUBLE(lower)
		Z_PARAM_DOUBLE(upper)
		Z_PARAM_DOUBLE(step)
		Z_PARAM_DOUBLE(page)
		Z_PARAM_DOUBLE(page_size)
	ZEND_PARSE_PARAMETERS_END();

	gtk_adjustment_configure(THIS_ADJUSTMENT, value, lower, upper, step, page, page_size);
}

ZEND_METHOD(GtkAdjustment, getValue) { ZEND_PARSE_PARAMETERS_NONE(); RETURN_DOUBLE(gtk_adjustment_get_value(THIS_ADJUSTMENT)); }
ZEND_METHOD(GtkAdjustment, getLower) { ZEND_PARSE_PARAMETERS_NONE(); RETURN_DOUBLE(gtk_adjustment_get_lower(THIS_ADJUSTMENT)); }
ZEND_METHOD(GtkAdjustment, getUpper) { ZEND_PARSE_PARAMETERS_NONE(); RETURN_DOUBLE(gtk_adjustment_get_upper(THIS_ADJUSTMENT)); }
ZEND_METHOD(GtkAdjustment, getPageSize) { ZEND_PARSE_PARAMETERS_NONE(); RETURN_DOUBLE(gtk_adjustment_get_page_size(THIS_ADJUSTMENT)); }

ZEND_METHOD(GtkAdjustment, setValue)
{
	double value;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_DOUBLE(value)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	gtk_adjustment_set_value(THIS_ADJUSTMENT, value);
}
