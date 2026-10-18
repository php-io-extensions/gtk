#include "runtime.h"
#include "../stubs/GtkControls_arginfo.h"

void phpgtk_register_GtkControls(void)
{
	phpgtk_ce_PangoEllipsizeMode = register_class_PangoEllipsizeMode();
	phpgtk_ce_GtkJustification = register_class_GtkJustification();
	phpgtk_ce_GtkWrapMode = register_class_GtkWrapMode();
	phpgtk_ce_GtkContentFit = register_class_GtkContentFit();
	phpgtk_ce_GtkPolicyType = register_class_GtkPolicyType();

/* The parent class, then the interfaces the class implements. */
#define PHPGTK_WIDGET_CLASS(name, ...) \
	phpgtk_ce_##name = register_class_##name(__VA_ARGS__); \
	phpgtk_object_setup(phpgtk_ce_##name); \
	phpgtk_map_gtype(#name, phpgtk_ce_##name)

	PHPGTK_WIDGET_CLASS(GtkLabel, phpgtk_ce_GtkWidget);
	PHPGTK_WIDGET_CLASS(GtkButton, phpgtk_ce_GtkWidget);
	PHPGTK_WIDGET_CLASS(GtkLinkButton, phpgtk_ce_GtkButton);
	PHPGTK_WIDGET_CLASS(GtkCheckButton, phpgtk_ce_GtkWidget);
	PHPGTK_WIDGET_CLASS(GtkSwitch, phpgtk_ce_GtkWidget);
	PHPGTK_WIDGET_CLASS(GtkToggleButton, phpgtk_ce_GtkButton);
	PHPGTK_WIDGET_CLASS(GtkEntryBuffer, phpgtk_ce_GObject);
	PHPGTK_WIDGET_CLASS(GtkEntry, phpgtk_ce_GtkWidget);
	PHPGTK_WIDGET_CLASS(GtkTextBuffer, phpgtk_ce_GObject);
	PHPGTK_WIDGET_CLASS(GtkTextView, phpgtk_ce_GtkWidget);
	PHPGTK_WIDGET_CLASS(GtkScale, phpgtk_ce_GtkWidget);
	PHPGTK_WIDGET_CLASS(GtkStringList, phpgtk_ce_GObject, phpgtk_ce_GListModel);
	PHPGTK_WIDGET_CLASS(GtkStringObject, phpgtk_ce_GObject);
	PHPGTK_WIDGET_CLASS(GtkDropDown, phpgtk_ce_GtkWidget);
	PHPGTK_WIDGET_CLASS(GtkCalendar, phpgtk_ce_GtkWidget);
	PHPGTK_WIDGET_CLASS(GtkProgressBar, phpgtk_ce_GtkWidget);
	PHPGTK_WIDGET_CLASS(GtkSpinner, phpgtk_ce_GtkWidget);
	PHPGTK_WIDGET_CLASS(GtkPicture, phpgtk_ce_GtkWidget);
	PHPGTK_WIDGET_CLASS(GtkSeparator, phpgtk_ce_GtkWidget);
	PHPGTK_WIDGET_CLASS(GtkScrolledWindow, phpgtk_ce_GtkWidget);
	PHPGTK_WIDGET_CLASS(GtkPaned, phpgtk_ce_GtkWidget);
	PHPGTK_WIDGET_CLASS(GtkNotebook, phpgtk_ce_GtkWidget);

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

ZEND_METHOD(GtkLabel, setMarkup)
{
	zend_string *str;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(str)
	ZEND_PARSE_PARAMETERS_END();

	gtk_label_set_markup(THIS(GTK_LABEL), ZSTR_VAL(str));
}
PHPGTK_GET_BOOL(GtkLabel, getUseMarkup, GTK_LABEL, gtk_label_get_use_markup)
PHPGTK_SET_BOOL(GtkLabel, setUseMarkup, GTK_LABEL, gtk_label_set_use_markup)
PHPGTK_GET_STRING(GtkLabel, getCurrentUri, GTK_LABEL, gtk_label_get_current_uri)

/* ---- GtkButton --------------------------------------------------------- */

PHPGTK_NEW_WITH_LABEL(GtkButton, gtk_button_new_with_label)
PHPGTK_GET_STRING(GtkButton, getLabel, GTK_BUTTON, gtk_button_get_label)
PHPGTK_SET_STRING(GtkButton, setLabel, GTK_BUTTON, gtk_button_set_label)

/* ---- GtkLinkButton ----------------------------------------------------- */

ZEND_METHOD(GtkLinkButton, new)
{
	zend_string *uri;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(uri)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();
	PHPGTK_REQUIRE_INITIALIZED();

	phpgtk_box_gobject(return_value, gtk_link_button_new(ZSTR_VAL(uri)));
}

ZEND_METHOD(GtkLinkButton, newWithLabel)
{
	zend_string *uri;
	zend_string *label = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(uri)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(label)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();
	PHPGTK_REQUIRE_INITIALIZED();

	phpgtk_box_gobject(return_value, gtk_link_button_new_with_label(ZSTR_VAL(uri), label != NULL ? ZSTR_VAL(label) : NULL));
}

PHPGTK_GET_STRING(GtkLinkButton, getUri, GTK_LINK_BUTTON, gtk_link_button_get_uri)
PHPGTK_SET_STRING(GtkLinkButton, setUri, GTK_LINK_BUTTON, gtk_link_button_set_uri)
PHPGTK_GET_BOOL(GtkLinkButton, getVisited, GTK_LINK_BUTTON, gtk_link_button_get_visited)
PHPGTK_SET_BOOL(GtkLinkButton, setVisited, GTK_LINK_BUTTON, gtk_link_button_set_visited)

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
	zend_long n_chars;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(chars)
		Z_PARAM_LONG(n_chars)
	ZEND_PARSE_PARAMETERS_END();

	if (!phpgtk_long_in_range(n_chars, G_MININT, G_MAXINT, 2)) {
		RETURN_THROWS();
	}
	/* GTK walks n_chars characters from the string's start without a bound: past its characters it reads past the string. */
	glong length = g_utf8_strlen(ZSTR_VAL(chars), (gssize) ZSTR_LEN(chars));
	if (!PHPGTK_PROBE_OFF("entry-set-text-nchars") && (n_chars > length)) {
		zend_argument_value_error(2, "must not exceed the %ld characters of $chars", length); /* binding:entry-set-text-nchars */
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
	zend_long len;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(text)
		Z_PARAM_LONG(len)
	ZEND_PARSE_PARAMETERS_END();

	if (!phpgtk_long_in_range(len, G_MININT, G_MAXINT, 2)) {
		RETURN_THROWS();
	}

	gtk_text_buffer_set_text(THIS(GTK_TEXT_BUFFER), ZSTR_VAL(text), (int) len);
}

ZEND_METHOD(GtkTextBuffer, getText)
{
	zend_object *start_obj;
	zend_object *end_obj;
	bool include_hidden;
	gchar *text;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJ_OF_CLASS(start_obj, phpgtk_ce_GtkTextIter)
		Z_PARAM_OBJ_OF_CLASS(end_obj, phpgtk_ce_GtkTextIter)
		Z_PARAM_BOOL(include_hidden)
	ZEND_PARSE_PARAMETERS_END();

	/* GTK checks a stale or foreign iter itself here: a warning or critical, and NULL. */
	text = gtk_text_buffer_get_text(THIS(GTK_TEXT_BUFFER), &PHPGTK_ITER_BOX(start_obj)->iter, &PHPGTK_ITER_BOX(end_obj)->iter, include_hidden);
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

#define THIS_BUFFER GTK_TEXT_BUFFER(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

/* An iter argument: GtkException once its buffer's text changed (GTK only logs a critical, or crashes).
 * Another buffer's iter goes to GTK, which answers it with a critical. */
static GtkTextIter *phpgtk_buffer_iter(GtkTextBuffer *buffer, zend_object *iter_obj, uint32_t arg_num)
{
	return phpgtk_fresh_iter(iter_obj);
}

ZEND_METHOD(GtkTextBuffer, getTagTable)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_text_buffer_get_tag_table(THIS_BUFFER));
}

/* GTK writes the iter either way: past the last line it is the buffer's end, past the line's end the line's end. */
ZEND_METHOD(GtkTextBuffer, getIterAtLine)
{
	zval *iter_ref;
	zend_long line_number;
	GtkTextIter iter;
	zval boxed;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(iter_ref)
		Z_PARAM_LONG(line_number)
	ZEND_PARSE_PARAMETERS_END();
	if (!phpgtk_long_in_range(line_number, G_MININT, G_MAXINT, 2)) {
		RETURN_THROWS();
	}

	gboolean found = gtk_text_buffer_get_iter_at_line(THIS_BUFFER, &iter, (int) line_number);

	phpgtk_box_text_iter(&boxed, &iter);
	ZEND_TRY_ASSIGN_REF_TMP(iter_ref, &boxed);
	RETURN_BOOL(found);
}

ZEND_METHOD(GtkTextBuffer, getIterAtLineOffset)
{
	zval *iter_ref;
	zend_long line_number, char_offset;
	GtkTextIter iter;
	zval boxed;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ZVAL(iter_ref)
		Z_PARAM_LONG(line_number)
		Z_PARAM_LONG(char_offset)
	ZEND_PARSE_PARAMETERS_END();
	if (!phpgtk_long_in_range(line_number, G_MININT, G_MAXINT, 2) || !phpgtk_long_in_range(char_offset, G_MININT, G_MAXINT, 3)) {
		RETURN_THROWS();
	}
	/* A negative char_offset is a Gtk-ERROR ("Char offset -1 is off the end of the line"), which traps the process. */
	if (!PHPGTK_PROBE_OFF("text-iter-line-offset-negative") && char_offset < 0) {
		zend_argument_value_error(3, "must be greater than or equal to 0"); /* binding:text-iter-line-offset-negative */
		RETURN_THROWS();
	}

	gboolean found = gtk_text_buffer_get_iter_at_line_offset(THIS_BUFFER, &iter, (int) line_number, (int) char_offset);

	phpgtk_box_text_iter(&boxed, &iter);
	ZEND_TRY_ASSIGN_REF_TMP(iter_ref, &boxed);
	RETURN_BOOL(found);
}

ZEND_METHOD(GtkTextBuffer, getIterAtOffset)
{
	zend_long char_offset;
	GtkTextIter iter;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(char_offset)
	ZEND_PARSE_PARAMETERS_END();

	gtk_text_buffer_get_iter_at_offset(THIS_BUFFER, &iter, (int) char_offset);
	phpgtk_box_text_iter(return_value, &iter);
}

ZEND_METHOD(GtkTextBuffer, getStartIter)
{
	GtkTextIter iter;

	ZEND_PARSE_PARAMETERS_NONE();

	gtk_text_buffer_get_start_iter(THIS_BUFFER, &iter);
	phpgtk_box_text_iter(return_value, &iter);
}

ZEND_METHOD(GtkTextBuffer, getEndIter)
{
	GtkTextIter iter;

	ZEND_PARSE_PARAMETERS_NONE();

	gtk_text_buffer_get_end_iter(THIS_BUFFER, &iter);
	phpgtk_box_text_iter(return_value, &iter);
}

/* applyTag and removeTag: a tag of this buffer's table between two of its iters. */
static void phpgtk_buffer_tag(INTERNAL_FUNCTION_PARAMETERS, bool apply)
{
	zend_object *tag_obj, *start_obj, *end_obj;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJ_OF_CLASS(tag_obj, phpgtk_ce_GtkTextTag)
		Z_PARAM_OBJ_OF_CLASS(start_obj, phpgtk_ce_GtkTextIter)
		Z_PARAM_OBJ_OF_CLASS(end_obj, phpgtk_ce_GtkTextIter)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	GtkTextBuffer *buffer = THIS_BUFFER;
	GtkTextTag *tag = GTK_TEXT_TAG(PHPGTK_PTR(tag_obj));
	GtkTextIter *start = phpgtk_buffer_iter(buffer, start_obj, 2);
	GtkTextIter *end = start != NULL ? phpgtk_buffer_iter(buffer, end_obj, 3) : NULL;
	if (end == NULL) {
		RETURN_THROWS();
	}

	if (apply) {
		gtk_text_buffer_apply_tag(buffer, tag, start, end);
	} else {
		gtk_text_buffer_remove_tag(buffer, tag, start, end);
	}
}

ZEND_METHOD(GtkTextBuffer, applyTag) { phpgtk_buffer_tag(INTERNAL_FUNCTION_PARAM_PASSTHRU, true); }
ZEND_METHOD(GtkTextBuffer, removeTag) { phpgtk_buffer_tag(INTERNAL_FUNCTION_PARAM_PASSTHRU, false); }

ZEND_METHOD(GtkTextBuffer, getSelectionBounds)
{
	zval *start_ref, *end_ref;
	GtkTextIter start, end;
	zval boxed;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(start_ref)
		Z_PARAM_ZVAL(end_ref)
	ZEND_PARSE_PARAMETERS_END();

	/* GTK sets both iters either way: with nothing selected, both are the insert mark's. */
	gboolean selected = gtk_text_buffer_get_selection_bounds(THIS_BUFFER, &start, &end);

	phpgtk_box_text_iter(&boxed, &start);
	ZEND_TRY_ASSIGN_REF_TMP(start_ref, &boxed);
	phpgtk_box_text_iter(&boxed, &end);
	ZEND_TRY_ASSIGN_REF_TMP(end_ref, &boxed);
	RETURN_BOOL(selected);
}

ZEND_METHOD(GtkTextBuffer, selectRange)
{
	zend_object *ins_obj, *bound_obj;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS(ins_obj, phpgtk_ce_GtkTextIter)
		Z_PARAM_OBJ_OF_CLASS(bound_obj, phpgtk_ce_GtkTextIter)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	GtkTextIter *ins = phpgtk_buffer_iter(THIS_BUFFER, ins_obj, 1);
	GtkTextIter *bound = ins != NULL ? phpgtk_buffer_iter(THIS_BUFFER, bound_obj, 2) : NULL;
	if (bound == NULL) {
		RETURN_THROWS();
	}
	gtk_text_buffer_select_range(THIS_BUFFER, ins, bound);
}

ZEND_METHOD(GtkTextBuffer, getInsert)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_text_buffer_get_insert(THIS_BUFFER));
}

ZEND_METHOD(GtkTextBuffer, getIterAtMark)
{
	zend_object *mark_obj;
	GtkTextIter iter;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(mark_obj, phpgtk_ce_GtkTextMark)
	ZEND_PARSE_PARAMETERS_END();

	GtkTextMark *mark = GTK_TEXT_MARK(PHPGTK_PTR(mark_obj));
	/* A deleted mark's iter GTK leaves unwritten (a critical), and boxing it reads that garbage. For another buffer's
	 * live mark it writes this buffer's tree over that buffer's lines, which the iter outlives once that buffer goes. */
	if (!PHPGTK_PROBE_OFF("text-iter-foreign-mark") && (gtk_text_mark_get_buffer(mark) != THIS_BUFFER)) {
		zend_argument_value_error(1, "must be a mark of this buffer"); /* binding:text-iter-foreign-mark */
		RETURN_THROWS();
	}
	gtk_text_buffer_get_iter_at_mark(THIS_BUFFER, &iter, mark);
	phpgtk_box_text_iter(return_value, &iter);
}

ZEND_METHOD(GtkTextBuffer, getLineCount)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG(gtk_text_buffer_get_line_count(THIS_BUFFER));
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

PHPGTK_GET_BOOL(GtkTextView, getMonospace, GTK_TEXT_VIEW, gtk_text_view_get_monospace)
PHPGTK_SET_BOOL(GtkTextView, setMonospace, GTK_TEXT_VIEW, gtk_text_view_set_monospace)
PHPGTK_GET_BOOL(GtkTextView, getCursorVisible, GTK_TEXT_VIEW, gtk_text_view_get_cursor_visible)
PHPGTK_SET_BOOL(GtkTextView, setCursorVisible, GTK_TEXT_VIEW, gtk_text_view_set_cursor_visible)

ZEND_METHOD(GtkTextView, getLineYrange)
{
	zend_object *iter_obj;
	zval *y_ref, *height_ref;
	int y = 0, height = 0;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJ_OF_CLASS(iter_obj, phpgtk_ce_GtkTextIter)
		Z_PARAM_ZVAL(y_ref)
		Z_PARAM_ZVAL(height_ref)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	GtkTextIter *iter = phpgtk_buffer_iter(gtk_text_view_get_buffer(THIS(GTK_TEXT_VIEW)), iter_obj, 1);
	if (iter == NULL) {
		RETURN_THROWS();
	}
	gtk_text_view_get_line_yrange(THIS(GTK_TEXT_VIEW), iter, &y, &height);
	ZEND_TRY_ASSIGN_REF_LONG(y_ref, y);
	ZEND_TRY_ASSIGN_REF_LONG(height_ref, height);
}

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

	/* GTK asserts min < max and step != 0, then returns NULL: null here. */
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

	/* A position is a guint; GTK judges it against the list. */
	if (!phpgtk_long_in_range(position, 0, (zend_long) G_MAXUINT, 1)) {
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

	/* Both are guints; GTK judges them against the list (a critical when position + n_removals passes its end). */
	if (!phpgtk_long_in_range(position, 0, (zend_long) G_MAXUINT, 1) || !phpgtk_long_in_range(n_removals, 0, (zend_long) G_MAXUINT, 2)) {
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

	/* A position is a guint; GTK answers one past the list with NULL. */
	if (!phpgtk_long_in_range(position, 0, (zend_long) G_MAXUINT, 1)) {
		RETURN_THROWS();
	}

	phpgtk_return_string(return_value, gtk_string_list_get_string(THIS(GTK_STRING_LIST), (guint) position));
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

ZEND_METHOD(GtkPicture, setPaintable)
{
	zend_object *paintable = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(paintable, phpgtk_ce_GObject)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	if (paintable != NULL && !GDK_IS_PAINTABLE(PHPGTK_PTR(paintable))) {
		zend_argument_type_error(1, "must be a GdkPaintable, %s given", ZSTR_VAL(paintable->ce->name));
		RETURN_THROWS();
	}

	gtk_picture_set_paintable(THIS(GTK_PICTURE), paintable != NULL ? GDK_PAINTABLE(PHPGTK_PTR(paintable)) : NULL);
}

PHPGTK_GET_BOOL(GtkPicture, getCanShrink, GTK_PICTURE, gtk_picture_get_can_shrink)
PHPGTK_SET_BOOL(GtkPicture, setCanShrink, GTK_PICTURE, gtk_picture_set_can_shrink)

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

ZEND_METHOD(GtkScrolledWindow, getHadjustment)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_scrolled_window_get_hadjustment(THIS(GTK_SCROLLED_WINDOW)));
}

ZEND_METHOD(GtkScrolledWindow, getVadjustment)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_scrolled_window_get_vadjustment(THIS(GTK_SCROLLED_WINDOW)));
}

/* ---- GtkPaned ---------------------------------------------------------- */

ZEND_METHOD(GtkPaned, new)
{
	zend_object *orientation;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(orientation, phpgtk_ce_GtkOrientation)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();
	PHPGTK_REQUIRE_INITIALIZED();

	phpgtk_box_gobject(return_value, gtk_paned_new((GtkOrientation) phpgtk_enum_value(orientation, 0)));
}

/* GTK asserts a new start/end child is unparented, unless it already fills that slot. */
#define PHPGTK_PANED_CHILD(get_name, set_name, get_call, set_call) \
ZEND_METHOD(GtkPaned, get_name) \
{ \
	ZEND_PARSE_PARAMETERS_NONE(); \
	phpgtk_box_gobject(return_value, get_call(THIS(GTK_PANED))); \
} \
ZEND_METHOD(GtkPaned, set_name) \
{ \
	zend_object *child = NULL; \
	ZEND_PARSE_PARAMETERS_START(1, 1) \
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(child, phpgtk_ce_GtkWidget) \
	ZEND_PARSE_PARAMETERS_END(); \
	set_call(THIS(GTK_PANED), (GtkWidget *) PHPGTK_OPTIONAL_PTR(child)); \
}

PHPGTK_PANED_CHILD(getStartChild, setStartChild, gtk_paned_get_start_child, gtk_paned_set_start_child)
PHPGTK_PANED_CHILD(getEndChild, setEndChild, gtk_paned_get_end_child, gtk_paned_set_end_child)

ZEND_METHOD(GtkPaned, getPosition)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG(gtk_paned_get_position(THIS(GTK_PANED)));
}

ZEND_METHOD(GtkPaned, setPosition)
{
	zend_long position;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	if (!phpgtk_long_in_range(position, INT_MIN, INT_MAX, 1)) {
		RETURN_THROWS();
	}

	gtk_paned_set_position(THIS(GTK_PANED), (int) position);
}

PHPGTK_GET_BOOL(GtkPaned, getResizeStartChild, GTK_PANED, gtk_paned_get_resize_start_child)
PHPGTK_SET_BOOL(GtkPaned, setResizeStartChild, GTK_PANED, gtk_paned_set_resize_start_child)
PHPGTK_GET_BOOL(GtkPaned, getResizeEndChild, GTK_PANED, gtk_paned_get_resize_end_child)
PHPGTK_SET_BOOL(GtkPaned, setResizeEndChild, GTK_PANED, gtk_paned_set_resize_end_child)
PHPGTK_GET_BOOL(GtkPaned, getShrinkStartChild, GTK_PANED, gtk_paned_get_shrink_start_child)
PHPGTK_SET_BOOL(GtkPaned, setShrinkStartChild, GTK_PANED, gtk_paned_set_shrink_start_child)
PHPGTK_GET_BOOL(GtkPaned, getShrinkEndChild, GTK_PANED, gtk_paned_get_shrink_end_child)
PHPGTK_SET_BOOL(GtkPaned, setShrinkEndChild, GTK_PANED, gtk_paned_set_shrink_end_child)
PHPGTK_GET_BOOL(GtkPaned, getWideHandle, GTK_PANED, gtk_paned_get_wide_handle)
PHPGTK_SET_BOOL(GtkPaned, setWideHandle, GTK_PANED, gtk_paned_set_wide_handle)

/* ---- GtkNotebook ------------------------------------------------------- */

PHPGTK_NEW_PLAIN(GtkNotebook, gtk_notebook_new)

ZEND_METHOD(GtkNotebook, appendPage)
{
	zend_object *child;
	zend_object *label = NULL;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS(child, phpgtk_ce_GtkWidget)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(label, phpgtk_ce_GtkWidget)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG(gtk_notebook_append_page(THIS(GTK_NOTEBOOK), GTK_WIDGET(PHPGTK_PTR(child)), (GtkWidget *) PHPGTK_OPTIONAL_PTR(label)));
}

/* A page number argument: GTK takes an int. */
#define PHPGTK_NOTEBOOK_PAGE_ARG(page) \
	if (!phpgtk_long_in_range(page, INT_MIN, INT_MAX, 1)) { \
		RETURN_THROWS(); \
	}

ZEND_METHOD(GtkNotebook, removePage)
{
	zend_long page;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(page)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_NOTEBOOK_PAGE_ARG(page)

	gtk_notebook_remove_page(THIS(GTK_NOTEBOOK), (int) page);
}

ZEND_METHOD(GtkNotebook, pageNum)
{
	zend_object *child;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(child, phpgtk_ce_GtkWidget)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG(gtk_notebook_page_num(THIS(GTK_NOTEBOOK), GTK_WIDGET(PHPGTK_PTR(child))));
}

ZEND_METHOD(GtkNotebook, getNPages)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG(gtk_notebook_get_n_pages(THIS(GTK_NOTEBOOK)));
}

ZEND_METHOD(GtkNotebook, getCurrentPage)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG(gtk_notebook_get_current_page(THIS(GTK_NOTEBOOK)));
}

ZEND_METHOD(GtkNotebook, setCurrentPage)
{
	zend_long page;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(page)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_NOTEBOOK_PAGE_ARG(page)

	gtk_notebook_set_current_page(THIS(GTK_NOTEBOOK), (int) page);
}

ZEND_METHOD(GtkNotebook, getNthPage)
{
	zend_long page;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(page)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_NOTEBOOK_PAGE_ARG(page)

	phpgtk_box_gobject(return_value, gtk_notebook_get_nth_page(THIS(GTK_NOTEBOOK), (int) page));
}

ZEND_METHOD(GtkNotebook, setTabLabelText)
{
	zend_object *child;
	zend_string *text;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS(child, phpgtk_ce_GtkWidget)
		Z_PARAM_STR(text)
	ZEND_PARSE_PARAMETERS_END();

	gtk_notebook_set_tab_label_text(THIS(GTK_NOTEBOOK), GTK_WIDGET(PHPGTK_PTR(child)), ZSTR_VAL(text));
}

ZEND_METHOD(GtkNotebook, getTabLabelText)
{
	zend_object *child;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(child, phpgtk_ce_GtkWidget)
	ZEND_PARSE_PARAMETERS_END();

	phpgtk_return_string(return_value, gtk_notebook_get_tab_label_text(THIS(GTK_NOTEBOOK), GTK_WIDGET(PHPGTK_PTR(child))));
}

PHPGTK_GET_BOOL(GtkNotebook, getShowTabs, GTK_NOTEBOOK, gtk_notebook_get_show_tabs)
PHPGTK_SET_BOOL(GtkNotebook, setShowTabs, GTK_NOTEBOOK, gtk_notebook_set_show_tabs)
PHPGTK_GET_BOOL(GtkNotebook, getScrollable, GTK_NOTEBOOK, gtk_notebook_get_scrollable)
PHPGTK_SET_BOOL(GtkNotebook, setScrollable, GTK_NOTEBOOK, gtk_notebook_set_scrollable)
