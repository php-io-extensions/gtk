#include "runtime.h"
#include "php_network.h"

#if __has_include("ext/sockets/php_sockets.h")
# include "ext/sockets/php_sockets.h"
# define PHPGTK_HAVE_SOCKETS 1
#endif

#ifdef __APPLE__
# include <pthread.h>
#else
# include <sys/syscall.h>
# include <unistd.h>
#endif

static zend_object_handlers phpgtk_handlers;

/* GType name => PHP class, for boxing an instance as its nearest bound class. */
static HashTable phpgtk_gtypes;
static bool phpgtk_gtypes_ready = false;

static zend_object *phpgtk_create_object(zend_class_entry *ce)
{
	phpgtk_object *intern = zend_object_alloc(sizeof(phpgtk_object), ce);

	zend_object_std_init(&intern->std, ce);
	object_properties_init(&intern->std, ce);
	intern->std.handlers = &phpgtk_handlers;

	return &intern->std;
}

static void phpgtk_free_object(zend_object *object)
{
	phpgtk_object *intern = phpgtk_object_from(object);

	if (intern->ptr != NULL) {
		zend_hash_index_del(&PHPGTK_G(boxes), (zend_ulong) (uintptr_t) intern->ptr);

		switch (intern->kind) {
			case PHPGTK_GOBJECT:
				g_object_unref(intern->ptr);
				break;
			case PHPGTK_MAIN_CONTEXT:
				g_main_context_unref((GMainContext *) intern->ptr);
				break;
			case PHPGTK_VARIANT:
				g_variant_unref((GVariant *) intern->ptr);
				break;
			case PHPGTK_DATE_TIME:
				g_date_time_unref((GDateTime *) intern->ptr);
				break;
			case PHPGTK_DMABUF_FORMATS:
#if GTK_CHECK_VERSION(4, 14, 0)
				gdk_dmabuf_formats_unref((GdkDmabufFormats *) intern->ptr);
#endif
				break;
		}

		intern->ptr = NULL;
	}

	zend_object_std_dtor(object);
}

void phpgtk_object_setup(zend_class_entry *ce)
{
	static bool handlers_ready = false;

	if (!handlers_ready) {
		memcpy(&phpgtk_handlers, zend_get_std_object_handlers(), sizeof(zend_object_handlers));
		phpgtk_handlers.offset = XtOffsetOf(phpgtk_object, std);
		phpgtk_handlers.free_obj = phpgtk_free_object;
		phpgtk_handlers.clone_obj = NULL;
		phpgtk_handlers.compare = zend_objects_not_comparable;
		handlers_ready = true;
	}

	ce->create_object = phpgtk_create_object;
	ce->default_object_handlers = &phpgtk_handlers;
}

void phpgtk_map_gtype(const char *type_name, zend_class_entry *ce)
{
	if (!phpgtk_gtypes_ready) {
		zend_hash_init(&phpgtk_gtypes, 16, NULL, NULL, 1);
		phpgtk_gtypes_ready = true;
	}

	zend_hash_str_update_ptr(&phpgtk_gtypes, type_name, strlen(type_name), ce);
}

static bool phpgtk_box_existing(zval *rv, const void *ptr)
{
	zend_object *existing = zend_hash_index_find_ptr(&PHPGTK_G(boxes), (zend_ulong) (uintptr_t) ptr);

	if (existing == NULL) {
		return false;
	}

	ZVAL_OBJ_COPY(rv, existing);
	return true;
}

static void phpgtk_box_new(zval *rv, zend_class_entry *ce, void *referenced, phpgtk_kind kind)
{
	zend_object *object = phpgtk_create_object(ce);
	phpgtk_object *intern = phpgtk_object_from(object);

	intern->ptr = referenced;
	intern->kind = kind;
	zend_hash_index_add_new_ptr(&PHPGTK_G(boxes), (zend_ulong) (uintptr_t) referenced, object);

	ZVAL_OBJ(rv, object);
}

/* Takes PHP's own reference (sinking a floating one); the caller keeps whatever it held. */
void phpgtk_box_gobject(zval *rv, gpointer object)
{
	if (object == NULL) {
		ZVAL_NULL(rv);
		return;
	}

	if (phpgtk_box_existing(rv, object)) {
		return;
	}

	zend_class_entry *ce = phpgtk_ce_GObject;

	for (GType type = G_OBJECT_TYPE(object); type != 0; type = g_type_parent(type)) {
		const char *name = g_type_name(type);
		zend_class_entry *mapped = zend_hash_str_find_ptr(&phpgtk_gtypes, name, strlen(name));

		if (mapped != NULL) {
			ce = mapped;
			break;
		}
	}

	phpgtk_box_new(rv, ce, g_object_ref_sink(object), PHPGTK_GOBJECT);
}

void phpgtk_box_main_context(zval *rv, GMainContext *context)
{
	if (context == NULL) {
		ZVAL_NULL(rv);
		return;
	}

	if (phpgtk_box_existing(rv, context)) {
		return;
	}

	phpgtk_box_new(rv, phpgtk_ce_GMainContext, g_main_context_ref(context), PHPGTK_MAIN_CONTEXT);
}

/* Takes PHP's own reference, sinking a floating one (g_variant_new_*() returns floating references). */
void phpgtk_box_variant(zval *rv, GVariant *variant)
{
	if (variant == NULL) {
		ZVAL_NULL(rv);
		return;
	}

	if (phpgtk_box_existing(rv, variant)) {
		return;
	}

	phpgtk_box_new(rv, phpgtk_ce_GVariant, g_variant_ref_sink(variant), PHPGTK_VARIANT);
}

/* Takes ownership of the reference handed in (g_date_time_new_*() and gtk_calendar_get_date() return new ones). */
void phpgtk_box_date_time(zval *rv, GDateTime *date_time)
{
	if (date_time == NULL) {
		ZVAL_NULL(rv);
		return;
	}

	if (phpgtk_box_existing(rv, date_time)) {
		g_date_time_unref(date_time);
		return;
	}

	phpgtk_box_new(rv, phpgtk_ce_GDateTime, date_time, PHPGTK_DATE_TIME);
}

#if GTK_CHECK_VERSION(4, 14, 0)
/* Takes PHP's own reference; the caller keeps whatever it held (gdk_display_get_dmabuf_formats() is transfer none). */
void phpgtk_box_dmabuf_formats(zval *rv, GdkDmabufFormats *formats)
{
	if (formats == NULL) {
		ZVAL_NULL(rv);
		return;
	}

	if (phpgtk_box_existing(rv, formats)) {
		return;
	}

	phpgtk_box_new(rv, phpgtk_ce_GdkDmabufFormats, gdk_dmabuf_formats_ref(formats), PHPGTK_DMABUF_FORMATS);
}
#endif

/* A (transfer full) return: PHP's reference replaces the one the call handed us. */
void phpgtk_box_gobject_full(zval *rv, gpointer object)
{
	phpgtk_box_gobject(rv, object);
	if (object != NULL) {
		g_object_unref(object);
	}
}

void phpgtk_box_variant_full(zval *rv, GVariant *variant)
{
	phpgtk_box_variant(rv, variant);
	if (variant != NULL) {
		g_variant_unref(variant);
	}
}

void phpgtk_return_string(zval *rv, const char *str)
{
	if (str == NULL) {
		ZVAL_NULL(rv);
	} else {
		ZVAL_STRING(rv, str);
	}
}

/* g_action_parse_detailed_name() writes through every out-parameter, so each gets a real slot. */
bool phpgtk_is_detailed_action(const char *detailed)
{
	gchar *name = NULL;
	GVariant *target = NULL;
	GError *error = NULL;
	gboolean valid = g_action_parse_detailed_name(detailed, &name, &target, &error);

	g_free(name);
	if (target != NULL) {
		g_variant_unref(target);
	}
	if (error != NULL) {
		g_error_free(error);
	}

	return valid;
}

bool phpgtk_long_in_range(zend_long value, zend_long min, zend_long max, uint32_t arg_num)
{
	if (value < min || value > max) {
		zend_argument_value_error(arg_num, "must be between " ZEND_LONG_FMT " and " ZEND_LONG_FMT, min, max);
		return false;
	}

	return true;
}

bool phpgtk_require_parent(GtkWidget *child, GtkWidget *expected_parent, uint32_t arg_num)
{
	GtkWidget *parent = gtk_widget_get_parent(child);

	if (parent == expected_parent) {
		return true;
	}

	if (expected_parent == NULL) {
		zend_argument_value_error(arg_num, "already has a parent (%s)", G_OBJECT_TYPE_NAME(parent));
	} else if (parent == NULL) {
		zend_argument_value_error(arg_num, "is not a child of this %s", G_OBJECT_TYPE_NAME(expected_parent));
	} else {
		zend_argument_value_error(arg_num, "is a child of another %s", G_OBJECT_TYPE_NAME(parent));
	}

	return false;
}

zend_long phpgtk_enum_value(zend_object *obj_or_null, zend_long fallback)
{
	return obj_or_null != NULL ? Z_LVAL_P(zend_enum_fetch_case_value(obj_or_null)) : fallback;
}

/* A native enum value as the PHP enum case; a value the stub does not declare is an extension bug, reported as such. */
void phpgtk_return_enum(zval *rv, zend_class_entry *ce, zend_long value)
{
	zend_object *case_object = NULL;

	if (zend_enum_get_case_by_value(&case_object, ce, value, NULL, true) == FAILURE || case_object == NULL) {
		zend_throw_exception_ex(phpgtk_ce_GtkException, 0, "%s has no case for native value " ZEND_LONG_FMT, ZSTR_VAL(ce->name), value);
		ZVAL_NULL(rv);
		return;
	}

	ZVAL_OBJ_COPY(rv, case_object);
}

bool phpgtk_fd_from_zval(zval *zfd, uint32_t arg_num, int *fd)
{
	switch (Z_TYPE_P(zfd)) {
		case IS_LONG:
			if (Z_LVAL_P(zfd) < 0 || Z_LVAL_P(zfd) > INT_MAX) {
				zend_argument_value_error(arg_num, "must be a valid file descriptor");
				return false;
			}
			*fd = (int) Z_LVAL_P(zfd);
			return true;

		case IS_RESOURCE: {
			php_stream *stream = (php_stream *) zend_fetch_resource2_ex(
				zfd, NULL, php_file_le_stream(), php_file_le_pstream()
			);
			php_socket_t stream_fd = -1;

			if (stream == NULL) {
				zend_argument_type_error(arg_num, "must be a valid stream resource");
				return false;
			}

			if (php_stream_cast(stream, PHP_STREAM_AS_FD_FOR_SELECT | PHP_STREAM_CAST_INTERNAL,
					(void **) &stream_fd, 0) != SUCCESS || stream_fd < 0) {
				zend_argument_value_error(arg_num, "must be a stream backed by a file descriptor");
				return false;
			}

			*fd = (int) stream_fd;
			return true;
		}

#ifdef PHPGTK_HAVE_SOCKETS
		case IS_OBJECT: {
			/* Resolved by name so gtk.so never links against ext/sockets symbols. */
			zend_class_entry *socket_class = zend_hash_str_find_ptr(CG(class_table), "socket", sizeof("socket") - 1);

			if (socket_class != NULL && Z_OBJCE_P(zfd) == socket_class) {
				php_socket *socket = Z_SOCKET_P(zfd);

				if (socket->bsd_socket < 0) {
					zend_argument_value_error(arg_num, "has already been closed");
					return false;
				}

				*fd = (int) socket->bsd_socket;
				return true;
			}
			break;
		}
#endif
	}

	zend_argument_type_error(arg_num, "must be of type Socket|resource|int, %s given", zend_zval_value_name(zfd));
	return false;
}

/* A signal parameter as PHP sees it: objects boxed, enums and flags as ints, pointers and boxed types as addresses. */
void phpgtk_gvalue_to_zval(zval *rv, const GValue *value)
{
	switch (G_TYPE_FUNDAMENTAL(G_VALUE_TYPE(value))) {
		case G_TYPE_BOOLEAN: ZVAL_BOOL(rv, g_value_get_boolean(value)); return;
		case G_TYPE_CHAR:    ZVAL_LONG(rv, g_value_get_schar(value)); return;
		case G_TYPE_UCHAR:   ZVAL_LONG(rv, g_value_get_uchar(value)); return;
		case G_TYPE_INT:     ZVAL_LONG(rv, g_value_get_int(value)); return;
		case G_TYPE_UINT:    ZVAL_LONG(rv, (zend_long) g_value_get_uint(value)); return;
		case G_TYPE_LONG:    ZVAL_LONG(rv, g_value_get_long(value)); return;
		case G_TYPE_ULONG:   ZVAL_LONG(rv, (zend_long) g_value_get_ulong(value)); return;
		case G_TYPE_INT64:   ZVAL_LONG(rv, g_value_get_int64(value)); return;
		case G_TYPE_UINT64:  ZVAL_LONG(rv, (zend_long) g_value_get_uint64(value)); return;
		case G_TYPE_FLOAT:   ZVAL_DOUBLE(rv, g_value_get_float(value)); return;
		case G_TYPE_DOUBLE:  ZVAL_DOUBLE(rv, g_value_get_double(value)); return;
		case G_TYPE_ENUM:    ZVAL_LONG(rv, g_value_get_enum(value)); return;
		case G_TYPE_FLAGS:   ZVAL_LONG(rv, (zend_long) g_value_get_flags(value)); return;
		case G_TYPE_POINTER: ZVAL_LONG(rv, (zend_long) (uintptr_t) g_value_get_pointer(value)); return;
		case G_TYPE_BOXED:   ZVAL_LONG(rv, (zend_long) (uintptr_t) g_value_get_boxed(value)); return;

		case G_TYPE_STRING: {
			const char *str = g_value_get_string(value);
			if (str == NULL) {
				ZVAL_NULL(rv);
			} else {
				ZVAL_STRING(rv, str);
			}
			return;
		}

		case G_TYPE_OBJECT:
		case G_TYPE_INTERFACE:
			phpgtk_box_gobject(rv, g_value_get_object(value));
			return;

		case G_TYPE_VARIANT:
			phpgtk_box_variant(rv, g_value_get_variant(value));
			return;
	}

	ZVAL_NULL(rv);
}

/* A handler's PHP return value into the signal's already-typed return GValue. */
void phpgtk_zval_to_gvalue(GValue *value, zval *zv)
{
	switch (G_TYPE_FUNDAMENTAL(G_VALUE_TYPE(value))) {
		case G_TYPE_BOOLEAN: g_value_set_boolean(value, zend_is_true(zv)); return;
		case G_TYPE_CHAR:    g_value_set_schar(value, (gint8) zval_get_long(zv)); return;
		case G_TYPE_UCHAR:   g_value_set_uchar(value, (guchar) zval_get_long(zv)); return;
		case G_TYPE_INT:     g_value_set_int(value, (gint) zval_get_long(zv)); return;
		case G_TYPE_UINT:    g_value_set_uint(value, (guint) zval_get_long(zv)); return;
		case G_TYPE_LONG:    g_value_set_long(value, (glong) zval_get_long(zv)); return;
		case G_TYPE_ULONG:   g_value_set_ulong(value, (gulong) zval_get_long(zv)); return;
		case G_TYPE_INT64:   g_value_set_int64(value, (gint64) zval_get_long(zv)); return;
		case G_TYPE_UINT64:  g_value_set_uint64(value, (guint64) zval_get_long(zv)); return;
		case G_TYPE_FLOAT:   g_value_set_float(value, (gfloat) zval_get_double(zv)); return;
		case G_TYPE_DOUBLE:  g_value_set_double(value, zval_get_double(zv)); return;
		case G_TYPE_ENUM:    g_value_set_enum(value, (gint) zval_get_long(zv)); return;
		case G_TYPE_FLAGS:   g_value_set_flags(value, (guint) zval_get_long(zv)); return;

		case G_TYPE_STRING:
			if (Z_TYPE_P(zv) == IS_NULL) {
				g_value_set_string(value, NULL);
			} else {
				zend_string *str = zval_get_string(zv);
				g_value_set_string(value, ZSTR_VAL(str));
				zend_string_release(str);
			}
			return;

		case G_TYPE_OBJECT:
			if (Z_TYPE_P(zv) == IS_OBJECT && instanceof_function(Z_OBJCE_P(zv), phpgtk_ce_GObject)) {
				g_value_set_object(value, PHPGTK_PTR(Z_OBJ_P(zv)));
			} else {
				g_value_set_object(value, NULL);
			}
			return;
	}
}

/* A GError as a GError exception object, not thrown: message, code and domain filled. */
void phpgtk_gerror_object(zval *rv, const GError *error)
{
	const char *domain = g_quark_to_string(error->domain);

	object_init_ex(rv, phpgtk_ce_GError);
	zend_update_property_string(phpgtk_ce_GError, Z_OBJ_P(rv), "message", sizeof("message") - 1, error->message != NULL ? error->message : "");
	zend_update_property_long(phpgtk_ce_GError, Z_OBJ_P(rv), "code", sizeof("code") - 1, error->code);
	zend_update_property_string(phpgtk_ce_GError, Z_OBJ_P(rv), "domain", sizeof("domain") - 1, domain != NULL ? domain : "");
}

void phpgtk_throw_gerror(GError *error)
{
	zval exception;

	if (EG(exception) != NULL) {
		return;
	}

	phpgtk_gerror_object(&exception, error);
	zend_throw_exception_object(&exception);
}

bool phpgtk_on_main_thread(void)
{
#ifdef __APPLE__
	return pthread_main_np() != 0;
#else
	return (pid_t) syscall(SYS_gettid) == getpid();
#endif
}

phpgtk_callout *phpgtk_callout_new(zval *callable)
{
	phpgtk_callout *callout = pecalloc(1, sizeof(phpgtk_callout), 1);

	ZVAL_COPY(&callout->callable, callable);
	callout->refcount = 1;

	callout->next = PHPGTK_G(callouts);
	if (callout->next != NULL) {
		callout->next->prev = callout;
	}
	PHPGTK_G(callouts) = callout;

	return callout;
}

static void phpgtk_callout_unlink(phpgtk_callout *callout)
{
	if (callout->prev != NULL) {
		callout->prev->next = callout->next;
	} else if (PHPGTK_G(callouts) == callout) {
		PHPGTK_G(callouts) = callout->next;
	}

	if (callout->next != NULL) {
		callout->next->prev = callout->prev;
	}

	callout->prev = callout->next = NULL;
}

void phpgtk_callout_retain(phpgtk_callout *callout)
{
	callout->refcount++;
}

void phpgtk_callout_release(phpgtk_callout *callout)
{
	if (--callout->refcount > 0) {
		return;
	}

	if (!Z_ISUNDEF(callout->callable)) {
		phpgtk_callout_unlink(callout);
		zval_ptr_dtor(&callout->callable);
		ZVAL_UNDEF(&callout->callable);
	}

	pefree(callout, 1);
}

/* Calls the PHP callable; false when it did not run (detached, or an exception already pending). */
bool phpgtk_callout_invoke(phpgtk_callout *callout, uint32_t argc, zval *argv, zval *retval)
{
	ZVAL_UNDEF(retval);

	if (Z_ISUNDEF(callout->callable) || EG(exception) != NULL) {
		return false;
	}

	zval callable;
	bool called;

	/* The callable may remove its own source or disconnect its own handler, so hold both. */
	phpgtk_callout_retain(callout);
	ZVAL_COPY(&callable, &callout->callable);

	called = call_user_function(NULL, NULL, &callable, retval, argc, argv) == SUCCESS && EG(exception) == NULL;

	zval_ptr_dtor(&callable);
	phpgtk_callout_release(callout);

	return called;
}

/*
 * At request end every source and handler still attached is removed and its
 * callable freed while the engine can still free it. GLib's destroy notify or
 * closure finalizer then frees the record.
 */
void phpgtk_callouts_detach_all(void)
{
	while (PHPGTK_G(callouts) != NULL) {
		phpgtk_callout *callout = PHPGTK_G(callouts);
		zval callable;

		ZVAL_COPY_VALUE(&callable, &callout->callable);
		ZVAL_UNDEF(&callout->callable);
		phpgtk_callout_unlink(callout);

		phpgtk_callout_retain(callout);
		if (callout->source_id != 0) {
			g_source_remove(callout->source_id);
		} else if (callout->instance != NULL && g_signal_handler_is_connected(callout->instance, callout->handler_id)) {
			g_signal_handler_disconnect(callout->instance, callout->handler_id);
		}
		phpgtk_callout_release(callout);

		zval_ptr_dtor(&callable);
	}
}
