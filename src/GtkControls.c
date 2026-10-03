#include "runtime.h"
#include "../stubs/GtkControls_arginfo.h"

void phpgtk_register_GtkControls(void)
{
	phpgtk_ce_PangoEllipsizeMode = register_class_PangoEllipsizeMode();
	phpgtk_ce_GtkJustification = register_class_GtkJustification();
	phpgtk_ce_GtkWrapMode = register_class_GtkWrapMode();
	phpgtk_ce_GtkContentFit = register_class_GtkContentFit();
	phpgtk_ce_GtkPolicyType = register_class_GtkPolicyType();

#define PHPGTK_WIDGET_CLASS(name, parent) \
	phpgtk_ce_##name = register_class_##name(parent); \
	phpgtk_object_setup(phpgtk_ce_##name); \
	phpgtk_map_gtype(#name, phpgtk_ce_##name)

	PHPGTK_WIDGET_CLASS(GtkLabel, phpgtk_ce_GtkWidget);
	PHPGTK_WIDGET_CLASS(GtkButton, phpgtk_ce_GtkWidget);
	PHPGTK_WIDGET_CLASS(GtkCheckButton, phpgtk_ce_GtkWidget);
	PHPGTK_WIDGET_CLASS(GtkSwitch, phpgtk_ce_GtkWidget);
	PHPGTK_WIDGET_CLASS(GtkToggleButton, phpgtk_ce_GtkButton);
	PHPGTK_WIDGET_CLASS(GtkEntryBuffer, phpgtk_ce_GObject);
	PHPGTK_WIDGET_CLASS(GtkEntry, phpgtk_ce_GtkWidget);
	PHPGTK_WIDGET_CLASS(GtkTextBuffer, phpgtk_ce_GObject);
	PHPGTK_WIDGET_CLASS(GtkTextView, phpgtk_ce_GtkWidget);
	PHPGTK_WIDGET_CLASS(GtkScale, phpgtk_ce_GtkWidget);
	PHPGTK_WIDGET_CLASS(GtkStringList, phpgtk_ce_GObject);
	PHPGTK_WIDGET_CLASS(GtkStringObject, phpgtk_ce_GObject);
	PHPGTK_WIDGET_CLASS(GtkDropDown, phpgtk_ce_GtkWidget);
	PHPGTK_WIDGET_CLASS(GtkCalendar, phpgtk_ce_GtkWidget);
	PHPGTK_WIDGET_CLASS(GtkProgressBar, phpgtk_ce_GtkWidget);
	PHPGTK_WIDGET_CLASS(GtkSpinner, phpgtk_ce_GtkWidget);
	PHPGTK_WIDGET_CLASS(GtkPicture, phpgtk_ce_GtkWidget);
	PHPGTK_WIDGET_CLASS(GtkSeparator, phpgtk_ce_GtkWidget);
	PHPGTK_WIDGET_CLASS(GtkScrolledWindow, phpgtk_ce_GtkWidget);

#undef PHPGTK_WIDGET_CLASS
}

#define THIS(cast) cast(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

/* One-call getters and setters. */
#define PHPGTK_GET_BOOL(klass, name, cast, call) \
ZEND_METHOD(klass, name) { ZEND_PARSE_PARAMETERS_NONE(); RETURN_BOOL(call(THIS(cast))); }

#define PHPGTK_SET_BOOL(klass, name, cast, call) \
ZEND_METHOD(klass, name) \
{ \
	bool value; \
	ZEND_PARSE_PARAMETERS_START(1, 1) \
		Z_PARAM_BOOL(value) \
	ZEND_PARSE_PARAMETERS_END(); \
	call(THIS(cast), value); \
}

#define PHPGTK_GET_STRING(klass, name, cast, call) \
ZEND_METHOD(klass, name) { ZEND_PARSE_PARAMETERS_NONE(); phpgtk_return_string(return_value, call(THIS(cast))); }

#define PHPGTK_SET_STRING(klass, name, cast, call) \
ZEND_METHOD(klass, name) \
{ \
	zend_string *value; \
	ZEND_PARSE_PARAMETERS_START(1, 1) \
		Z_PARAM_STR(value) \
	ZEND_PARSE_PARAMETERS_END(); \
	call(THIS(cast), ZSTR_VAL(value)); \
}

#define PHPGTK_SET_STRING_OR_NULL(klass, name, cast, call) \
ZEND_METHOD(klass, name) \
{ \
	zend_string *value = NULL; \
	ZEND_PARSE_PARAMETERS_START(1, 1) \
		Z_PARAM_STR_OR_NULL(value) \
	ZEND_PARSE_PARAMETERS_END(); \
	call(THIS(cast), value != NULL ? ZSTR_VAL(value) : NULL); \
}

#define PHPGTK_GET_DOUBLE(klass, name, cast, call) \
ZEND_METHOD(klass, name) { ZEND_PARSE_PARAMETERS_NONE(); RETURN_DOUBLE((double) call(THIS(cast))); }

#define PHPGTK_SET_DOUBLE(klass, name, cast, call) \
ZEND_METHOD(klass, name) \
{ \
	double value; \
	ZEND_PARSE_PARAMETERS_START(1, 1) \
		Z_PARAM_DOUBLE(value) \
	ZEND_PARSE_PARAMETERS_END(); \
	call(THIS(cast), value); \
}

#define PHPGTK_SET_ENUM(klass, name, cast, call, enum_ce, native) \
ZEND_METHOD(klass, name) \
{ \
	zend_object *value; \
	ZEND_PARSE_PARAMETERS_START(1, 1) \
		Z_PARAM_OBJ_OF_CLASS(value, enum_ce) \
	ZEND_PARSE_PARAMETERS_END(); \
	call(THIS(cast), (native) phpgtk_enum_value(value, 0)); \
}

#define PHPGTK_NEW_WITH_LABEL(klass, call) \
ZEND_METHOD(klass, newWithLabel) \
{ \
	zend_string *label; \
	ZEND_PARSE_PARAMETERS_START(1, 1) \
		Z_PARAM_STR(label) \
	ZEND_PARSE_PARAMETERS_END(); \
	PHPGTK_REQUIRE_MAIN_THREAD(); \
	PHPGTK_REQUIRE_INITIALIZED(); \
	phpgtk_box_gobject(return_value, call(ZSTR_VAL(label))); \
}

#define PHPGTK_NEW_PLAIN(klass, call) \
ZEND_METHOD(klass, new) \
{ \
	ZEND_PARSE_PARAMETERS_NONE(); \
	PHPGTK_REQUIRE_MAIN_THREAD(); \
	PHPGTK_REQUIRE_INITIALIZED(); \
	phpgtk_box_gobject(return_value, call()); \
}

/* ---- GtkLabel ---------------------------------------------------------- */

ZEND_METHOD(GtkLabel, new)
{
	zend_string *str = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR_OR_NULL(str)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();
	PHPGTK_REQUIRE_INITIALIZED();

	phpgtk_box_gobject(return_value, gtk_label_new(str != NULL ? ZSTR_VAL(str) : NULL));
}

PHPGTK_GET_STRING(GtkLabel, getText, GTK_LABEL, gtk_label_get_text)
PHPGTK_SET_STRING(GtkLabel, setText, GTK_LABEL, gtk_label_set_text)
PHPGTK_GET_BOOL(GtkLabel, getWrap, GTK_LABEL, gtk_label_get_wrap)
PHPGTK_SET_BOOL(GtkLabel, setWrap, GTK_LABEL, gtk_label_set_wrap)
PHPGTK_SET_ENUM(GtkLabel, setEllipsize, GTK_LABEL, gtk_label_set_ellipsize, phpgtk_ce_PangoEllipsizeMode, PangoEllipsizeMode)
PHPGTK_GET_DOUBLE(GtkLabel, getXalign, GTK_LABEL, gtk_label_get_xalign)
PHPGTK_SET_DOUBLE(GtkLabel, setXalign, GTK_LABEL, gtk_label_set_xalign)
PHPGTK_SET_ENUM(GtkLabel, setJustify, GTK_LABEL, gtk_label_set_justify, phpgtk_ce_GtkJustification, GtkJustification)

/* ---- GtkButton --------------------------------------------------------- */

PHPGTK_NEW_WITH_LABEL(GtkButton, gtk_button_new_with_label)
PHPGTK_GET_STRING(GtkButton, getLabel, GTK_BUTTON, gtk_button_get_label)
PHPGTK_SET_STRING(GtkButton, setLabel, GTK_BUTTON, gtk_button_set_label)

/* ---- GtkCheckButton ---------------------------------------------------- */

PHPGTK_NEW_WITH_LABEL(GtkCheckButton, gtk_check_button_new_with_label)
PHPGTK_GET_BOOL(GtkCheckButton, getActive, GTK_CHECK_BUTTON, gtk_check_button_get_active)
PHPGTK_SET_BOOL(GtkCheckButton, setActive, GTK_CHECK_BUTTON, gtk_check_button_set_active)
PHPGTK_GET_STRING(GtkCheckButton, getLabel, GTK_CHECK_BUTTON, gtk_check_button_get_label)
PHPGTK_SET_STRING_OR_NULL(GtkCheckButton, setLabel, GTK_CHECK_BUTTON, gtk_check_button_set_label)

/* ---- GtkSwitch --------------------------------------------------------- */

PHPGTK_NEW_PLAIN(GtkSwitch, gtk_switch_new)
PHPGTK_GET_BOOL(GtkSwitch, getActive, GTK_SWITCH, gtk_switch_get_active)
PHPGTK_SET_BOOL(GtkSwitch, setActive, GTK_SWITCH, gtk_switch_set_active)

/* ---- GtkToggleButton --------------------------------------------------- */

PHPGTK_NEW_WITH_LABEL(GtkToggleButton, gtk_toggle_button_new_with_label)
PHPGTK_GET_BOOL(GtkToggleButton, getActive, GTK_TOGGLE_BUTTON, gtk_toggle_button_get_active)
PHPGTK_SET_BOOL(GtkToggleButton, setActive, GTK_TOGGLE_BUTTON, gtk_toggle_button_set_active)

/* ---- GtkEntryBuffer ---------------------------------------------------- */

PHPGTK_GET_STRING(GtkEntryBuffer, getText, GTK_ENTRY_BUFFER, gtk_entry_buffer_get_text)

ZEND_METHOD(GtkEntryBuffer, setText)
{
	zend_string *chars;
	zend_long n_chars = -1;

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(chars)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(n_chars)
	ZEND_PARSE_PARAMETERS_END();

	/* GTK walks n_chars UTF-8 characters and copies that many bytes: a count past the end reads past the string. */
	if (!g_utf8_validate(ZSTR_VAL(chars), (gssize) ZSTR_LEN(chars), NULL)) {
		zend_argument_value_error(1, "must be valid UTF-8");
		RETURN_THROWS();
	}
	if (n_chars != -1 && !phpgtk_long_in_range(n_chars, 0, (zend_long) g_utf8_strlen(ZSTR_VAL(chars), (gssize) ZSTR_LEN(chars)), 2)) {
		RETURN_THROWS();
	}

	gtk_entry_buffer_set_text(THIS(GTK_ENTRY_BUFFER), ZSTR_VAL(chars), (int) n_chars);
}

/* ---- GtkEntry ---------------------------------------------------------- */

PHPGTK_NEW_PLAIN(GtkEntry, gtk_entry_new)

ZEND_METHOD(GtkEntry, getBuffer)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_entry_get_buffer(THIS(GTK_ENTRY)));
}

PHPGTK_GET_STRING(GtkEntry, getPlaceholderText, GTK_ENTRY, gtk_entry_get_placeholder_text)
PHPGTK_SET_STRING_OR_NULL(GtkEntry, setPlaceholderText, GTK_ENTRY, gtk_entry_set_placeholder_text)
PHPGTK_GET_BOOL(GtkEntry, getVisibility, GTK_ENTRY, gtk_entry_get_visibility)
PHPGTK_SET_BOOL(GtkEntry, setVisibility, GTK_ENTRY, gtk_entry_set_visibility)

/* ---- GtkTextBuffer ----------------------------------------------------- */

ZEND_METHOD(GtkTextBuffer, setText)
{
	zend_string *text;
	zend_long len = -1;

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(text)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(len)
	ZEND_PARSE_PARAMETERS_END();

	/* len is in bytes; GTK asserts the text is valid UTF-8 over that length. */
	if (len != -1 && !phpgtk_long_in_range(len, 0, (zend_long) ZSTR_LEN(text), 2)) {
		RETURN_THROWS();
	}
	if (!g_utf8_validate(ZSTR_VAL(text), len == -1 ? (gssize) ZSTR_LEN(text) : (gssize) len, NULL)) {
		zend_argument_value_error(1, "must be valid UTF-8");
		RETURN_THROWS();
	}

	gtk_text_buffer_set_text(THIS(GTK_TEXT_BUFFER), ZSTR_VAL(text), (int) len);
}

ZEND_METHOD(GtkTextBuffer, getText)
{
	zend_long start_offset;
	zend_long end_offset;
	bool include_hidden = false;
	GtkTextIter start;
	GtkTextIter end;
	gchar *text;

	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_LONG(start_offset)
		Z_PARAM_LONG(end_offset)
		Z_PARAM_OPTIONAL
		Z_PARAM_BOOL(include_hidden)
	ZEND_PARSE_PARAMETERS_END();

	if (!phpgtk_long_in_range(start_offset, -1, G_MAXINT, 1) || !phpgtk_long_in_range(end_offset, -1, G_MAXINT, 2)) {
		RETURN_THROWS();
	}

	gtk_text_buffer_get_iter_at_offset(THIS(GTK_TEXT_BUFFER), &start, (int) start_offset);
	gtk_text_buffer_get_iter_at_offset(THIS(GTK_TEXT_BUFFER), &end, end_offset < 0 ? G_MAXINT : (int) end_offset);

	text = gtk_text_buffer_get_text(THIS(GTK_TEXT_BUFFER), &start, &end, include_hidden);
	phpgtk_return_string(return_value, text);
	g_free(text);
}

ZEND_METHOD(GtkTextBuffer, beginUserAction)
{
	ZEND_PARSE_PARAMETERS_NONE();

	gtk_text_buffer_begin_user_action(THIS(GTK_TEXT_BUFFER));
}

ZEND_METHOD(GtkTextBuffer, endUserAction)
{
	ZEND_PARSE_PARAMETERS_NONE();

	gtk_text_buffer_end_user_action(THIS(GTK_TEXT_BUFFER));
}

/* ---- GtkTextView ------------------------------------------------------- */

PHPGTK_NEW_PLAIN(GtkTextView, gtk_text_view_new)

ZEND_METHOD(GtkTextView, getBuffer)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_text_view_get_buffer(THIS(GTK_TEXT_VIEW)));
}

PHPGTK_GET_BOOL(GtkTextView, getEditable, GTK_TEXT_VIEW, gtk_text_view_get_editable)
PHPGTK_SET_BOOL(GtkTextView, setEditable, GTK_TEXT_VIEW, gtk_text_view_set_editable)
PHPGTK_SET_ENUM(GtkTextView, setWrapMode, GTK_TEXT_VIEW, gtk_text_view_set_wrap_mode, phpgtk_ce_GtkWrapMode, GtkWrapMode)

/* ---- GtkScale ---------------------------------------------------------- */

ZEND_METHOD(GtkScale, newWithRange)
{
	zend_object *orientation;
	double min;
	double max;
	double step;

	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_OBJ_OF_CLASS(orientation, phpgtk_ce_GtkOrientation)
		Z_PARAM_DOUBLE(min)
		Z_PARAM_DOUBLE(max)
		Z_PARAM_DOUBLE(step)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();
	PHPGTK_REQUIRE_INITIALIZED();

	/* GTK asserts min < max and step != 0, then returns NULL, which would come back as a null GtkScale. */
	if (!(min < max)) {
		zend_argument_value_error(2, "must be below the maximum");
		RETURN_THROWS();
	}
	if (step == 0.0) {
		zend_argument_value_error(4, "must not be zero");
		RETURN_THROWS();
	}

	phpgtk_box_gobject(return_value, gtk_scale_new_with_range((GtkOrientation) phpgtk_enum_value(orientation, 0), min, max, step));
}

PHPGTK_GET_DOUBLE(GtkScale, getValue, GTK_RANGE, gtk_range_get_value)
PHPGTK_SET_DOUBLE(GtkScale, setValue, GTK_RANGE, gtk_range_set_value)

ZEND_METHOD(GtkScale, setRange)
{
	double min;
	double max;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_DOUBLE(min)
		Z_PARAM_DOUBLE(max)
	ZEND_PARSE_PARAMETERS_END();

	if (!(min < max)) {
		zend_argument_value_error(1, "must be below the maximum");
		RETURN_THROWS();
	}

	gtk_range_set_range(THIS(GTK_RANGE), min, max);
}

ZEND_METHOD(GtkScale, setIncrements)
{
	double step;
	double page;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_DOUBLE(step)
		Z_PARAM_DOUBLE(page)
	ZEND_PARSE_PARAMETERS_END();

	gtk_range_set_increments(THIS(GTK_RANGE), step, page);
}

PHPGTK_SET_BOOL(GtkScale, setDrawValue, GTK_SCALE, gtk_scale_set_draw_value)
PHPGTK_GET_BOOL(GtkScale, getDrawValue, GTK_SCALE, gtk_scale_get_draw_value)

/* ---- string arrays ----------------------------------------------------- */

/* A PHP list of strings as a NULL-terminated const char *[]; NULL (with an error thrown) on a non-string element. */
static const char **phpgtk_string_array(HashTable *strings, uint32_t arg_num)
{
	const char **out = safe_emalloc(zend_hash_num_elements(strings) + 1, sizeof(const char *), 0);
	size_t i = 0;
	zval *entry;

	ZEND_HASH_FOREACH_VAL(strings, entry) {
		ZVAL_DEREF(entry);
		if (Z_TYPE_P(entry) != IS_STRING) {
			efree(out);
			zend_argument_type_error(arg_num, "must contain only strings, %s given", zend_zval_value_name(entry));
			return NULL;
		}
		out[i++] = Z_STRVAL_P(entry);
	} ZEND_HASH_FOREACH_END();
	out[i] = NULL;

	return out;
}

/* ---- GtkStringList ----------------------------------------------------- */

ZEND_METHOD(GtkStringList, new)
{
	HashTable *strings;
	const char **array;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY_HT(strings)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	array = phpgtk_string_array(strings, 1);
	if (array == NULL) {
		RETURN_THROWS();
	}

	phpgtk_box_gobject_full(return_value, gtk_string_list_new(array));
	efree(array);
}

PHPGTK_SET_STRING(GtkStringList, append, GTK_STRING_LIST, gtk_string_list_append)

ZEND_METHOD(GtkStringList, remove)
{
	zend_long position;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();

	if (position < 0 || position >= (zend_long) g_list_model_get_n_items(G_LIST_MODEL(THIS(GTK_STRING_LIST)))) {
		zend_argument_value_error(1, "must be a position in the list");
		RETURN_THROWS();
	}

	gtk_string_list_remove(THIS(GTK_STRING_LIST), (guint) position);
}

ZEND_METHOD(GtkStringList, splice)
{
	zend_long position;
	zend_long n_removals;
	HashTable *additions;
	const char **array;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(position)
		Z_PARAM_LONG(n_removals)
		Z_PARAM_ARRAY_HT(additions)
	ZEND_PARSE_PARAMETERS_END();

	zend_long n_items = (zend_long) g_list_model_get_n_items(G_LIST_MODEL(THIS(GTK_STRING_LIST)));

	/* GTK asserts position + n_removals <= n_items. */
	if (!phpgtk_long_in_range(position, 0, n_items, 1) || !phpgtk_long_in_range(n_removals, 0, n_items - position, 2)) {
		RETURN_THROWS();
	}

	array = phpgtk_string_array(additions, 3);
	if (array == NULL) {
		RETURN_THROWS();
	}

	gtk_string_list_splice(THIS(GTK_STRING_LIST), (guint) position, (guint) n_removals, array);
	efree(array);
}

ZEND_METHOD(GtkStringList, getString)
{
	zend_long position;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();

	if (position < 0 || position >= (zend_long) g_list_model_get_n_items(G_LIST_MODEL(THIS(GTK_STRING_LIST)))) {
		RETURN_NULL();
	}

	phpgtk_return_string(return_value, gtk_string_list_get_string(THIS(GTK_STRING_LIST), (guint) position));
}

ZEND_METHOD(GtkStringList, getNItems)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG((zend_long) g_list_model_get_n_items(G_LIST_MODEL(THIS(GTK_STRING_LIST))));
}

/* ---- GtkStringObject --------------------------------------------------- */

PHPGTK_GET_STRING(GtkStringObject, getString, GTK_STRING_OBJECT, gtk_string_object_get_string)

/* ---- GtkDropDown ------------------------------------------------------- */

ZEND_METHOD(GtkDropDown, newFromStrings)
{
	HashTable *strings;
	const char **array;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY_HT(strings)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();
	PHPGTK_REQUIRE_INITIALIZED();

	array = phpgtk_string_array(strings, 1);
	if (array == NULL) {
		RETURN_THROWS();
	}

	phpgtk_box_gobject(return_value, gtk_drop_down_new_from_strings(array));
	efree(array);
}

ZEND_METHOD(GtkDropDown, getSelected)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG((zend_long) gtk_drop_down_get_selected(THIS(GTK_DROP_DOWN)));
}

ZEND_METHOD(GtkDropDown, setSelected)
{
	zend_long position;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();

	if (!phpgtk_long_in_range(position, 0, (zend_long) G_MAXUINT, 1)) {
		RETURN_THROWS();
	}

	gtk_drop_down_set_selected(THIS(GTK_DROP_DOWN), (guint) position);
}

ZEND_METHOD(GtkDropDown, getSelectedItem)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_drop_down_get_selected_item(THIS(GTK_DROP_DOWN)));
}

ZEND_METHOD(GtkDropDown, setModel)
{
	zend_object *model = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(model, phpgtk_ce_GObject)
	ZEND_PARSE_PARAMETERS_END();

	if (model != NULL && !G_IS_LIST_MODEL(PHPGTK_PTR(model))) {
		zend_argument_type_error(1, "must implement GListModel, %s does not", G_OBJECT_TYPE_NAME(PHPGTK_PTR(model)));
		RETURN_THROWS();
	}

	gtk_drop_down_set_model(THIS(GTK_DROP_DOWN), (GListModel *) PHPGTK_OPTIONAL_PTR(model));
}

/* ---- GtkCalendar ------------------------------------------------------- */

PHPGTK_NEW_PLAIN(GtkCalendar, gtk_calendar_new)

ZEND_METHOD(GtkCalendar, getDate)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_date_time(return_value, gtk_calendar_get_date(THIS(GTK_CALENDAR)));
}

ZEND_METHOD(GtkCalendar, selectDay)
{
	zend_object *date;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(date, phpgtk_ce_GDateTime)
	ZEND_PARSE_PARAMETERS_END();

	/* 4.20 deprecates this for gtk_calendar_set_date(), which 4.18 lacks; this one call serves both. */
	G_GNUC_BEGIN_IGNORE_DEPRECATIONS
	gtk_calendar_select_day(THIS(GTK_CALENDAR), (GDateTime *) PHPGTK_PTR(date));
	G_GNUC_END_IGNORE_DEPRECATIONS
}

/* ---- GtkProgressBar ---------------------------------------------------- */

PHPGTK_NEW_PLAIN(GtkProgressBar, gtk_progress_bar_new)
PHPGTK_GET_DOUBLE(GtkProgressBar, getFraction, GTK_PROGRESS_BAR, gtk_progress_bar_get_fraction)
PHPGTK_SET_DOUBLE(GtkProgressBar, setFraction, GTK_PROGRESS_BAR, gtk_progress_bar_set_fraction)
PHPGTK_SET_DOUBLE(GtkProgressBar, setPulseStep, GTK_PROGRESS_BAR, gtk_progress_bar_set_pulse_step)

ZEND_METHOD(GtkProgressBar, pulse)
{
	ZEND_PARSE_PARAMETERS_NONE();

	gtk_progress_bar_pulse(THIS(GTK_PROGRESS_BAR));
}

/* ---- GtkSpinner -------------------------------------------------------- */

PHPGTK_NEW_PLAIN(GtkSpinner, gtk_spinner_new)
PHPGTK_GET_BOOL(GtkSpinner, getSpinning, GTK_SPINNER, gtk_spinner_get_spinning)
PHPGTK_SET_BOOL(GtkSpinner, setSpinning, GTK_SPINNER, gtk_spinner_set_spinning)

/* ---- GtkPicture -------------------------------------------------------- */

PHPGTK_NEW_PLAIN(GtkPicture, gtk_picture_new)

ZEND_METHOD(GtkPicture, newForFilename)
{
	zend_string *filename;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();
	PHPGTK_REQUIRE_INITIALIZED();

	phpgtk_box_gobject(return_value, gtk_picture_new_for_filename(ZSTR_VAL(filename)));
}

PHPGTK_SET_STRING_OR_NULL(GtkPicture, setFilename, GTK_PICTURE, gtk_picture_set_filename)

ZEND_METHOD(GtkPicture, getContentFit)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_return_enum(return_value, phpgtk_ce_GtkContentFit, (zend_long) gtk_picture_get_content_fit(THIS(GTK_PICTURE)));
}

PHPGTK_SET_ENUM(GtkPicture, setContentFit, GTK_PICTURE, gtk_picture_set_content_fit, phpgtk_ce_GtkContentFit, GtkContentFit)

ZEND_METHOD(GtkPicture, getPaintable)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_picture_get_paintable(THIS(GTK_PICTURE)));
}

/* ---- GtkSeparator ------------------------------------------------------ */

ZEND_METHOD(GtkSeparator, new)
{
	zend_object *orientation;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(orientation, phpgtk_ce_GtkOrientation)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();
	PHPGTK_REQUIRE_INITIALIZED();

	phpgtk_box_gobject(return_value, gtk_separator_new((GtkOrientation) phpgtk_enum_value(orientation, 0)));
}

/* ---- GtkScrolledWindow ------------------------------------------------- */

PHPGTK_NEW_PLAIN(GtkScrolledWindow, gtk_scrolled_window_new)

ZEND_METHOD(GtkScrolledWindow, getChild)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_scrolled_window_get_child(THIS(GTK_SCROLLED_WINDOW)));
}

ZEND_METHOD(GtkScrolledWindow, setChild)
{
	zend_object *child = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(child, phpgtk_ce_GtkWidget)
	ZEND_PARSE_PARAMETERS_END();

	gtk_scrolled_window_set_child(THIS(GTK_SCROLLED_WINDOW), (GtkWidget *) PHPGTK_OPTIONAL_PTR(child));
}

ZEND_METHOD(GtkScrolledWindow, setPolicy)
{
	zend_object *hscrollbar_policy;
	zend_object *vscrollbar_policy;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS(hscrollbar_policy, phpgtk_ce_GtkPolicyType)
		Z_PARAM_OBJ_OF_CLASS(vscrollbar_policy, phpgtk_ce_GtkPolicyType)
	ZEND_PARSE_PARAMETERS_END();

	gtk_scrolled_window_set_policy(THIS(GTK_SCROLLED_WINDOW),
		(GtkPolicyType) phpgtk_enum_value(hscrollbar_policy, 0), (GtkPolicyType) phpgtk_enum_value(vscrollbar_policy, 0));
}
