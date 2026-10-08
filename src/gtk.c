/*
 * gtk: 1:1 bindings of GTK 4 and the GLib main loop GTK runs on. Functions
 * keep their C names; functions on a type are methods of the class named
 * after it.
 */

#include "runtime.h"
#include "ext/standard/info.h"
#include "ext/spl/spl_exceptions.h"
#include "../stubs/gtk_arginfo.h"

/* GIOCondition is backed by the host's poll(2) bits; the enum in the stub carries the POSIX values. */
_Static_assert(G_IO_IN == 1 && G_IO_PRI == 2 && G_IO_OUT == 4 && G_IO_ERR == 8 && G_IO_HUP == 16 && G_IO_NVAL == 32,
	"GIOCondition values differ from the stub's GIOCondition enum");

ZEND_DECLARE_MODULE_GLOBALS(gtk)

zend_class_entry *phpgtk_ce_GtkException;
zend_class_entry *phpgtk_ce_GError;
zend_class_entry *phpgtk_ce_GIOCondition;
zend_class_entry *phpgtk_ce_GObject;
zend_class_entry *phpgtk_ce_GApplication;
zend_class_entry *phpgtk_ce_GApplicationFlags;
zend_class_entry *phpgtk_ce_GtkApplication;
zend_class_entry *phpgtk_ce_GMainContext;
zend_class_entry *phpgtk_ce_GtkOrientation;
zend_class_entry *phpgtk_ce_GtkAlign;
zend_class_entry *phpgtk_ce_GtkWidget;
zend_class_entry *phpgtk_ce_GtkBox;
zend_class_entry *phpgtk_ce_GtkGrid;
zend_class_entry *phpgtk_ce_GtkFixed;
zend_class_entry *phpgtk_ce_GtkCssProvider;
zend_class_entry *phpgtk_ce_GdkDisplay;
zend_class_entry *phpgtk_ce_GdkSurface;
zend_class_entry *phpgtk_ce_GdkGLAPI;
zend_class_entry *phpgtk_ce_GdkGLContext;
zend_class_entry *phpgtk_ce_GtkGLArea;
zend_class_entry *phpgtk_ce_GdkMemoryFormat;
zend_class_entry *phpgtk_ce_GdkTexture;
zend_class_entry *phpgtk_ce_GdkMemoryTexture;
zend_class_entry *phpgtk_ce_GdkMemoryTextureBuilder;
zend_class_entry *phpgtk_ce_GdkDmabufTextureBuilder;
zend_class_entry *phpgtk_ce_GdkDmabufFormats;
zend_class_entry *phpgtk_ce_PangoEllipsizeMode;
zend_class_entry *phpgtk_ce_GtkJustification;
zend_class_entry *phpgtk_ce_GtkWrapMode;
zend_class_entry *phpgtk_ce_GtkLabel;
zend_class_entry *phpgtk_ce_GtkButton;
zend_class_entry *phpgtk_ce_GtkCheckButton;
zend_class_entry *phpgtk_ce_GtkSwitch;
zend_class_entry *phpgtk_ce_GtkToggleButton;
zend_class_entry *phpgtk_ce_GtkEntryBuffer;
zend_class_entry *phpgtk_ce_GtkEntry;
zend_class_entry *phpgtk_ce_GtkTextBuffer;
zend_class_entry *phpgtk_ce_GtkTextView;
zend_class_entry *phpgtk_ce_GtkScale;
zend_class_entry *phpgtk_ce_GtkContentFit;
zend_class_entry *phpgtk_ce_GtkPolicyType;
zend_class_entry *phpgtk_ce_GtkStringList;
zend_class_entry *phpgtk_ce_GtkStringObject;
zend_class_entry *phpgtk_ce_GtkDropDown;
zend_class_entry *phpgtk_ce_GtkCalendar;
zend_class_entry *phpgtk_ce_GtkProgressBar;
zend_class_entry *phpgtk_ce_GtkSpinner;
zend_class_entry *phpgtk_ce_GtkPicture;
zend_class_entry *phpgtk_ce_GtkSeparator;
zend_class_entry *phpgtk_ce_GtkScrolledWindow;
zend_class_entry *phpgtk_ce_GtkSignalListItemFactory;
zend_class_entry *phpgtk_ce_GtkListItem;
zend_class_entry *phpgtk_ce_GtkColumnViewColumn;
zend_class_entry *phpgtk_ce_GtkColumnView;
zend_class_entry *phpgtk_ce_GtkSingleSelection;
zend_class_entry *phpgtk_ce_GtkMediaStream;
zend_class_entry *phpgtk_ce_GtkMediaFile;
zend_class_entry *phpgtk_ce_GtkVideo;
zend_class_entry *phpgtk_ce_GtkPopoverMenuBar;
zend_class_entry *phpgtk_ce_GtkWindow;
zend_class_entry *phpgtk_ce_GtkApplicationWindow;
zend_class_entry *phpgtk_ce_GtkAboutDialog;
zend_class_entry *phpgtk_ce_GMenuModel;
zend_class_entry *phpgtk_ce_GMenu;
zend_class_entry *phpgtk_ce_GMenuItem;
zend_class_entry *phpgtk_ce_GSimpleAction;
zend_class_entry *phpgtk_ce_GSimpleActionGroup;
zend_class_entry *phpgtk_ce_GVariant;
zend_class_entry *phpgtk_ce_GDateTime;

/* ---- sources ---------------------------------------------------------- */

static gboolean phpgtk_source_func(gpointer data)
{
	zval retval;
	gboolean keep = G_SOURCE_REMOVE;

	if (phpgtk_callout_invoke((phpgtk_callout *) data, 0, NULL, &retval)) {
		keep = zend_is_true(&retval) ? G_SOURCE_CONTINUE : G_SOURCE_REMOVE;
	}
	zval_ptr_dtor(&retval);

	return keep;
}

static gboolean phpgtk_unix_fd_func(gint fd, GIOCondition condition, gpointer data)
{
	zval argv[2];
	zval retval;
	gboolean keep = G_SOURCE_REMOVE;

	ZVAL_LONG(&argv[0], fd);
	ZVAL_LONG(&argv[1], (zend_long) condition);

	if (phpgtk_callout_invoke((phpgtk_callout *) data, 2, argv, &retval)) {
		keep = zend_is_true(&retval) ? G_SOURCE_CONTINUE : G_SOURCE_REMOVE;
	}
	zval_ptr_dtor(&retval);

	return keep;
}

static void phpgtk_source_destroy(gpointer data)
{
	phpgtk_callout_release((phpgtk_callout *) data);
}

static bool phpgtk_require_callable(zval *callable, uint32_t arg_num)
{
	if (!zend_is_callable(callable, 0, NULL)) {
		zend_argument_type_error(arg_num, "must be a valid callback");
		return false;
	}

	return true;
}

ZEND_FUNCTION(g_timeout_add)
{
	zend_long interval;
	zval *function;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(interval)
		Z_PARAM_ZVAL(function)
	ZEND_PARSE_PARAMETERS_END();

	if (interval < 0 || interval > G_MAXUINT) {
		zend_argument_value_error(1, "must be between 0 and %u", G_MAXUINT);
		RETURN_THROWS();
	}
	if (!phpgtk_require_callable(function, 2)) {
		RETURN_THROWS();
	}

	phpgtk_callout *callout = phpgtk_callout_new(function);
	callout->source_id = g_timeout_add_full(G_PRIORITY_DEFAULT, (guint) interval, phpgtk_source_func, callout, phpgtk_source_destroy);

	RETURN_LONG((zend_long) callout->source_id);
}

ZEND_FUNCTION(g_idle_add)
{
	zval *function;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(function)
	ZEND_PARSE_PARAMETERS_END();

	if (!phpgtk_require_callable(function, 1)) {
		RETURN_THROWS();
	}

	phpgtk_callout *callout = phpgtk_callout_new(function);
	callout->source_id = g_idle_add_full(G_PRIORITY_DEFAULT_IDLE, phpgtk_source_func, callout, phpgtk_source_destroy);

	RETURN_LONG((zend_long) callout->source_id);
}

ZEND_FUNCTION(g_unix_fd_add)
{
	zval *zfd;
	zend_object *condition_case = NULL;
	zend_long condition_long = 0;
	zval *function;
	int fd;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_ZVAL(zfd)
		Z_PARAM_OBJ_OF_CLASS_OR_LONG(condition_case, phpgtk_ce_GIOCondition, condition_long)
		Z_PARAM_ZVAL(function)
	ZEND_PARSE_PARAMETERS_END();

	if (!phpgtk_fd_from_zval(zfd, 1, &fd) || !phpgtk_require_callable(function, 3)) {
		RETURN_THROWS();
	}

	phpgtk_callout *callout = phpgtk_callout_new(function);
	callout->source_id = g_unix_fd_add_full(G_PRIORITY_DEFAULT, fd,
		(GIOCondition) phpgtk_enum_value(condition_case, condition_long),
		phpgtk_unix_fd_func, callout, phpgtk_source_destroy);

	RETURN_LONG((zend_long) callout->source_id);
}

ZEND_FUNCTION(g_source_remove)
{
	zend_long tag;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(tag)
	ZEND_PARSE_PARAMETERS_END();

	if (tag <= 0 || tag > G_MAXUINT || g_main_context_find_source_by_id(NULL, (guint) tag) == NULL) {
		RETURN_FALSE;
	}

	RETURN_BOOL(g_source_remove((guint) tag));
}

/* ---- signals ---------------------------------------------------------- */

static void phpgtk_closure_marshal(GClosure *closure, GValue *return_value, guint n_param_values,
	const GValue *param_values, gpointer invocation_hint, gpointer marshal_data)
{
	phpgtk_callout *callout = (phpgtk_callout *) closure->data;
	zval *argv = n_param_values > 0 ? safe_emalloc(n_param_values, sizeof(zval), 0) : NULL;
	zval retval;

	for (guint i = 0; i < n_param_values; i++) {
		phpgtk_gvalue_to_zval(&argv[i], &param_values[i]);
	}

	if (phpgtk_callout_invoke(callout, n_param_values, argv, &retval)
			&& return_value != NULL && G_VALUE_TYPE(return_value) != G_TYPE_INVALID) {
		phpgtk_zval_to_gvalue(return_value, &retval);
	}
	zval_ptr_dtor(&retval);

	for (guint i = 0; i < n_param_values; i++) {
		zval_ptr_dtor(&argv[i]);
	}
	if (argv != NULL) {
		efree(argv);
	}
}

static void phpgtk_closure_finalize(gpointer data, GClosure *closure)
{
	phpgtk_callout_release((phpgtk_callout *) data);
}

ZEND_FUNCTION(g_signal_connect)
{
	zend_object *instance;
	zend_string *detailed_signal;
	zval *handler;
	guint signal_id;
	GQuark detail;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJ_OF_CLASS(instance, phpgtk_ce_GObject)
		Z_PARAM_STR(detailed_signal)
		Z_PARAM_ZVAL(handler)
	ZEND_PARSE_PARAMETERS_END();

	GObject *object = (GObject *) PHPGTK_PTR(instance);

	if (!g_signal_parse_name(ZSTR_VAL(detailed_signal), G_OBJECT_TYPE(object), &signal_id, &detail, TRUE)) {
		zend_argument_value_error(2, "is not a signal of %s", G_OBJECT_TYPE_NAME(object));
		RETURN_THROWS();
	}
	if (!phpgtk_require_callable(handler, 3)) {
		RETURN_THROWS();
	}

	phpgtk_callout *callout = phpgtk_callout_new(handler);
	GClosure *closure = g_closure_new_simple(sizeof(GClosure), callout);

	g_closure_set_marshal(closure, phpgtk_closure_marshal);
	g_closure_add_finalize_notifier(closure, callout, phpgtk_closure_finalize);

	callout->instance = object;
	callout->handler_id = g_signal_connect_closure_by_id(object, signal_id, detail, closure, FALSE);

	RETURN_LONG((zend_long) callout->handler_id);
}

/* One PHP value into a signal parameter of type $type, checked against the type first. */
static bool phpgtk_signal_param(GValue *value, GType type, zval *param, uint32_t arg_num, const char *signal)
{
	ZVAL_DEREF(param);

	switch (G_TYPE_FUNDAMENTAL(type)) {
		case G_TYPE_BOOLEAN:
			if (Z_TYPE_P(param) != IS_TRUE && Z_TYPE_P(param) != IS_FALSE) {
				zend_argument_type_error(arg_num, "must be of type bool for %s, %s given", signal, zend_zval_value_name(param));
				return false;
			}
			break;

		case G_TYPE_CHAR: case G_TYPE_UCHAR: case G_TYPE_INT: case G_TYPE_UINT: case G_TYPE_LONG:
		case G_TYPE_ULONG: case G_TYPE_INT64: case G_TYPE_UINT64: case G_TYPE_ENUM: case G_TYPE_FLAGS:
			/* Only an int-backed enum has a case value to fetch; a pure enum has no value slot. */
			if (Z_TYPE_P(param) == IS_OBJECT && (Z_OBJCE_P(param)->ce_flags & ZEND_ACC_ENUM)
					&& Z_OBJCE_P(param)->enum_backing_type == IS_LONG) {
				g_value_init(value, type);
				zval as_long;
				ZVAL_LONG(&as_long, Z_LVAL_P(zend_enum_fetch_case_value(Z_OBJ_P(param))));
				phpgtk_zval_to_gvalue(value, &as_long);
				return true;
			}
			if (Z_TYPE_P(param) != IS_LONG) {
				zend_argument_type_error(arg_num, "must be of type int for %s, %s given", signal, zend_zval_value_name(param));
				return false;
			}
			break;

		case G_TYPE_FLOAT: case G_TYPE_DOUBLE:
			if (Z_TYPE_P(param) != IS_LONG && Z_TYPE_P(param) != IS_DOUBLE) {
				zend_argument_type_error(arg_num, "must be of type float for %s, %s given", signal, zend_zval_value_name(param));
				return false;
			}
			break;

		case G_TYPE_STRING:
			if (Z_TYPE_P(param) != IS_STRING && Z_TYPE_P(param) != IS_NULL) {
				zend_argument_type_error(arg_num, "must be of type ?string for %s, %s given", signal, zend_zval_value_name(param));
				return false;
			}
			break;

		case G_TYPE_OBJECT:
		case G_TYPE_INTERFACE:
			g_value_init(value, type);
			if (Z_TYPE_P(param) == IS_NULL) {
				return true;
			}
			if (Z_TYPE_P(param) != IS_OBJECT || !instanceof_function(Z_OBJCE_P(param), phpgtk_ce_GObject)
					|| !g_type_is_a(G_OBJECT_TYPE(PHPGTK_PTR(Z_OBJ_P(param))), type)) {
				g_value_unset(value);
				zend_argument_type_error(arg_num, "must be a %s or null for %s, %s given", g_type_name(type), signal, zend_zval_value_name(param));
				return false;
			}
			g_value_set_object(value, PHPGTK_PTR(Z_OBJ_P(param)));
			return true;

		default:
			zend_argument_value_error(arg_num, "is a %s parameter of %s, which g_signal_emit_by_name() cannot pass", g_type_name(type), signal);
			return false;
	}

	g_value_init(value, type);
	phpgtk_zval_to_gvalue(value, param);
	return true;
}

ZEND_FUNCTION(g_signal_emit_by_name)
{
	zend_object *instance;
	zend_string *detailed_signal;
	zval *params = NULL;
	uint32_t param_count = 0;
	guint signal_id;
	GQuark detail;
	GSignalQuery query;

	ZEND_PARSE_PARAMETERS_START(2, -1)
		Z_PARAM_OBJ_OF_CLASS(instance, phpgtk_ce_GObject)
		Z_PARAM_STR(detailed_signal)
		Z_PARAM_VARIADIC('*', params, param_count)
	ZEND_PARSE_PARAMETERS_END();

	GObject *object = (GObject *) PHPGTK_PTR(instance);

	if (!g_signal_parse_name(ZSTR_VAL(detailed_signal), G_OBJECT_TYPE(object), &signal_id, &detail, TRUE)) {
		zend_argument_value_error(2, "is not a signal of %s", G_OBJECT_TYPE_NAME(object));
		RETURN_THROWS();
	}

	g_signal_query(signal_id, &query);
	if (param_count != query.n_params) {
		zend_argument_count_error("g_signal_emit_by_name(): %s takes %u parameters, %u given",
			ZSTR_VAL(detailed_signal), query.n_params, param_count);
		RETURN_THROWS();
	}

	GValue *values = ecalloc(param_count + 1, sizeof(GValue));
	g_value_init(&values[0], G_OBJECT_TYPE(object));
	g_value_set_object(&values[0], object);

	uint32_t filled = 0;
	for (; filled < param_count; filled++) {
		GType type = query.param_types[filled] & ~G_SIGNAL_TYPE_STATIC_SCOPE;
		if (!phpgtk_signal_param(&values[filled + 1], type, &params[filled], filled + 3, ZSTR_VAL(detailed_signal))) {
			break;
		}
	}

	if (filled == param_count) {
		GType return_type = query.return_type & ~G_SIGNAL_TYPE_STATIC_SCOPE;
		GValue result = G_VALUE_INIT;

		if (return_type != G_TYPE_NONE) {
			g_value_init(&result, return_type);
		}
		g_signal_emitv(values, signal_id, detail, return_type != G_TYPE_NONE ? &result : NULL);
		if (return_type != G_TYPE_NONE) {
			phpgtk_gvalue_to_zval(return_value, &result);
			g_value_unset(&result);
		}
	}

	for (uint32_t i = 0; i <= filled && i <= param_count; i++) {
		if (G_IS_VALUE(&values[i])) {
			g_value_unset(&values[i]);
		}
	}
	efree(values);

	if (filled != param_count) {
		RETURN_THROWS();
	}
}

ZEND_FUNCTION(g_signal_handler_disconnect)
{
	zend_object *instance;
	zend_long handler_id;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS(instance, phpgtk_ce_GObject)
		Z_PARAM_LONG(handler_id)
	ZEND_PARSE_PARAMETERS_END();

	if (!g_signal_handler_is_connected(PHPGTK_PTR(instance), (gulong) handler_id)) {
		zend_argument_value_error(2, "is not a handler connected to this instance");
		RETURN_THROWS();
	}

	g_signal_handler_disconnect(PHPGTK_PTR(instance), (gulong) handler_id);
}

ZEND_FUNCTION(g_signal_handler_is_connected)
{
	zend_object *instance;
	zend_long handler_id;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS(instance, phpgtk_ce_GObject)
		Z_PARAM_LONG(handler_id)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_BOOL(g_signal_handler_is_connected(PHPGTK_PTR(instance), (gulong) handler_id));
}

/* ---- GTK -------------------------------------------------------------- */

ZEND_FUNCTION(gtk_init)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();

	gtk_init();
}

ZEND_FUNCTION(gtk_init_check)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();

	RETURN_BOOL(gtk_init_check());
}

ZEND_FUNCTION(gtk_is_initialized)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_BOOL(gtk_is_initialized());
}

ZEND_FUNCTION(gtk_get_major_version)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG(gtk_get_major_version());
}

ZEND_FUNCTION(gtk_get_minor_version)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG(gtk_get_minor_version());
}

ZEND_FUNCTION(gtk_get_micro_version)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG(gtk_get_micro_version());
}

/* ---- module ----------------------------------------------------------- */

static PHP_GINIT_FUNCTION(gtk)
{
#if defined(COMPILE_DL_GTK) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	zend_hash_init(&gtk_globals->boxes, 32, NULL, NULL, 1);
	gtk_globals->callouts = NULL;
}

static PHP_GSHUTDOWN_FUNCTION(gtk)
{
	zend_hash_destroy(&gtk_globals->boxes);
}

PHP_MINIT_FUNCTION(gtk)
{
	register_gtk_symbols(module_number);

	phpgtk_ce_GIOCondition = register_class_GIOCondition();
	phpgtk_ce_GtkException = register_class_GtkException(spl_ce_RuntimeException);
	phpgtk_ce_GError = register_class_GError(spl_ce_RuntimeException);

	phpgtk_register_GObject();
	phpgtk_register_GApplication();
	phpgtk_register_GtkApplication();
	phpgtk_register_GMainContext();
	phpgtk_register_GVariant();
	phpgtk_register_GDateTime();
	phpgtk_register_GtkCss();
	phpgtk_register_GdkSurface();
	phpgtk_register_GdkTexture();
	phpgtk_register_GtkWidget();
	phpgtk_register_GtkControls();
	phpgtk_register_GdkGLContext();
	phpgtk_register_GtkGLArea();
	phpgtk_register_GtkColumnView();
	phpgtk_register_GtkVideo();
	phpgtk_register_GtkWindow();
	phpgtk_register_GMenu();
	phpgtk_register_GAction();

	return SUCCESS;
}

PHP_RINIT_FUNCTION(gtk)
{
#if defined(COMPILE_DL_GTK) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif
	return SUCCESS;
}

PHP_RSHUTDOWN_FUNCTION(gtk)
{
	phpgtk_callouts_detach_all();
	return SUCCESS;
}

PHP_MINFO_FUNCTION(gtk)
{
	char gtk_version[32];
	char glib_version[32];

	snprintf(gtk_version, sizeof(gtk_version), "%u.%u.%u (built %d.%d.%d)",
		gtk_get_major_version(), gtk_get_minor_version(), gtk_get_micro_version(),
		GTK_MAJOR_VERSION, GTK_MINOR_VERSION, GTK_MICRO_VERSION);
	snprintf(glib_version, sizeof(glib_version), "%u.%u.%u (built %d.%d.%d)",
		glib_major_version, glib_minor_version, glib_micro_version,
		GLIB_MAJOR_VERSION, GLIB_MINOR_VERSION, GLIB_MICRO_VERSION);

	php_info_print_table_start();
	php_info_print_table_row(2, "gtk support", "enabled");
	php_info_print_table_row(2, "Version", PHP_GTK_VERSION);
	php_info_print_table_row(2, "GTK", gtk_version);
	php_info_print_table_row(2, "GLib", glib_version);
	php_info_print_table_end();
}

zend_module_entry gtk_module_entry = {
	STANDARD_MODULE_HEADER,
	"gtk",
	ext_functions,
	PHP_MINIT(gtk),
	NULL,
	PHP_RINIT(gtk),
	PHP_RSHUTDOWN(gtk),
	PHP_MINFO(gtk),
	PHP_GTK_VERSION,
	PHP_MODULE_GLOBALS(gtk),
	PHP_GINIT(gtk),
	PHP_GSHUTDOWN(gtk),
	NULL,
	STANDARD_MODULE_PROPERTIES_EX
};

#ifdef COMPILE_DL_GTK
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(gtk)
#endif
