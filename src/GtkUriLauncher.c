#include "runtime.h"
#include "../stubs/GtkUriLauncher_arginfo.h"

void phpgtk_register_GtkUriLauncher(void)
{
	phpgtk_ce_GCancellable = register_class_GCancellable(phpgtk_ce_GObject);
	phpgtk_object_setup(phpgtk_ce_GCancellable);
	phpgtk_map_gtype("GCancellable", phpgtk_ce_GCancellable);

	/* GAsyncResult is an interface, which the GType walk never visits; GIO's results are GTasks. */
	phpgtk_ce_GAsyncResult = register_class_GAsyncResult(phpgtk_ce_GObject);
	phpgtk_object_setup(phpgtk_ce_GAsyncResult);
	phpgtk_map_gtype("GTask", phpgtk_ce_GAsyncResult);

	phpgtk_ce_GtkUriLauncher = register_class_GtkUriLauncher(phpgtk_ce_GObject);
	phpgtk_object_setup(phpgtk_ce_GtkUriLauncher);
	phpgtk_map_gtype("GtkUriLauncher", phpgtk_ce_GtkUriLauncher);
}

#define THIS_CANCELLABLE G_CANCELLABLE(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))
#define THIS_LAUNCHER GTK_URI_LAUNCHER(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

/* ---- GCancellable ------------------------------------------------------ */

ZEND_METHOD(GCancellable, new)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject_full(return_value, g_cancellable_new());
}

ZEND_METHOD(GCancellable, cancel)
{
	ZEND_PARSE_PARAMETERS_NONE();

	g_cancellable_cancel(THIS_CANCELLABLE);
}

ZEND_METHOD(GCancellable, isCancelled)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_BOOL(g_cancellable_is_cancelled(THIS_CANCELLABLE));
}

/* ---- GtkUriLauncher ---------------------------------------------------- */

ZEND_METHOD(GtkUriLauncher, new)
{
	zend_string *uri = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR_OR_NULL(uri)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	phpgtk_box_gobject_full(return_value, gtk_uri_launcher_new(uri != NULL ? ZSTR_VAL(uri) : NULL));
}

ZEND_METHOD(GtkUriLauncher, getUri)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_return_string(return_value, gtk_uri_launcher_get_uri(THIS_LAUNCHER));
}

ZEND_METHOD(GtkUriLauncher, setUri)
{
	zend_string *uri = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR_OR_NULL(uri)
	ZEND_PARSE_PARAMETERS_END();

	gtk_uri_launcher_set_uri(THIS_LAUNCHER, uri != NULL ? ZSTR_VAL(uri) : NULL);
}

/*
 * GIO calls this once. Past request end the callable is detached (UNDEF): nothing is boxed then,
 * and the record is freed here.
 */
static void phpgtk_uri_launched(GObject *source, GAsyncResult *result, gpointer data)
{
	phpgtk_callout *callout = (phpgtk_callout *) data;

	if (!Z_ISUNDEF(callout->callable) && !phpgtk_callout_foreign(callout)) {
		zval argv[2];
		zval retval;

		phpgtk_box_gobject(&argv[0], source);
		phpgtk_box_gobject(&argv[1], result);
		phpgtk_callout_invoke(callout, 2, argv, &retval);
		zval_ptr_dtor(&retval);
		zval_ptr_dtor(&argv[0]);
		zval_ptr_dtor(&argv[1]);
	}
	phpgtk_callout_release(callout);
}

ZEND_METHOD(GtkUriLauncher, launch)
{
	zend_object *parent = NULL;
	zend_object *cancellable = NULL;
	zval *callback;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(parent, phpgtk_ce_GtkWindow)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(cancellable, phpgtk_ce_GCancellable)
		Z_PARAM_ZVAL(callback)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	if (Z_TYPE_P(callback) != IS_NULL && !zend_is_callable(callback, 0, NULL)) {
		zend_argument_type_error(3, "must be a valid callback");
		RETURN_THROWS();
	}

	/* A null callback is GIO's fire and forget: no callback, no record. */
	gtk_uri_launcher_launch(THIS_LAUNCHER,
		parent != NULL ? GTK_WINDOW(PHPGTK_PTR(parent)) : NULL,
		cancellable != NULL ? G_CANCELLABLE(PHPGTK_PTR(cancellable)) : NULL,
		Z_TYPE_P(callback) != IS_NULL ? phpgtk_uri_launched : NULL,
		Z_TYPE_P(callback) != IS_NULL ? phpgtk_callout_new(callback) : NULL);
}

ZEND_METHOD(GtkUriLauncher, launchFinish)
{
	zend_object *result;
	GError *error = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(result, phpgtk_ce_GAsyncResult)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	if (!gtk_uri_launcher_launch_finish(THIS_LAUNCHER, G_ASYNC_RESULT(PHPGTK_PTR(result)), &error)) {
		if (error != NULL) {
			phpgtk_throw_gerror(error);
			g_error_free(error);
			RETURN_THROWS();
		}
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
