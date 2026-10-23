#include "runtime.h"
#include "../stubs/GtkDialogs_arginfo.h"

void phpgtk_register_GtkDialogs(void)
{
	/* GFile is an interface, which the GType walk never visits: each type a GFile arrives as maps here. */
	phpgtk_ce_GFile = register_class_GFile(phpgtk_ce_GObject);
	phpgtk_object_setup(phpgtk_ce_GFile);
	phpgtk_map_gtype("GLocalFile", phpgtk_ce_GFile);
	phpgtk_map_gtype("GDaemonFile", phpgtk_ce_GFile);
	phpgtk_map_gtype("GDummyFile", phpgtk_ce_GFile);

	phpgtk_ce_GListStore = register_class_GListStore(phpgtk_ce_GObject, phpgtk_ce_GListModel);
	phpgtk_object_setup(phpgtk_ce_GListStore);
	phpgtk_map_gtype("GListStore", phpgtk_ce_GListStore);

	phpgtk_ce_GdkClipboard = register_class_GdkClipboard(phpgtk_ce_GObject);
	phpgtk_object_setup(phpgtk_ce_GdkClipboard);
	phpgtk_map_gtype("GdkClipboard", phpgtk_ce_GdkClipboard);

	phpgtk_ce_GtkAlertDialog = register_class_GtkAlertDialog(phpgtk_ce_GObject);
	phpgtk_object_setup(phpgtk_ce_GtkAlertDialog);
	phpgtk_map_gtype("GtkAlertDialog", phpgtk_ce_GtkAlertDialog);

	phpgtk_ce_GtkFileDialog = register_class_GtkFileDialog(phpgtk_ce_GObject);
	phpgtk_object_setup(phpgtk_ce_GtkFileDialog);
	phpgtk_map_gtype("GtkFileDialog", phpgtk_ce_GtkFileDialog);

	phpgtk_ce_GtkFileLauncher = register_class_GtkFileLauncher(phpgtk_ce_GObject);
	phpgtk_object_setup(phpgtk_ce_GtkFileLauncher);
	phpgtk_map_gtype("GtkFileLauncher", phpgtk_ce_GtkFileLauncher);

	/* GTK registers a GType on first use; g_object_new_with_properties() finds GtkAlertDialog by name. */
	g_type_ensure(GTK_TYPE_ALERT_DIALOG);
}

#define THIS_PTR PHPGTK_PTR(Z_OBJ_P(ZEND_THIS))

/*
 * The three arguments every async call takes: (?GtkWindow $parent, ?GCancellable $cancellable,
 * ?callable $callback). A null callback is GIO's fire and forget: no callback, no record.
 */
#define PHPGTK_ASYNC_ARGS \
	zend_object *parent = NULL; \
	zend_object *cancellable = NULL; \
	zval *callback; \
	ZEND_PARSE_PARAMETERS_START(3, 3) \
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(parent, phpgtk_ce_GtkWindow) \
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(cancellable, phpgtk_ce_GCancellable) \
		Z_PARAM_ZVAL(callback) \
	ZEND_PARSE_PARAMETERS_END(); \
	PHPGTK_REQUIRE_MAIN_THREAD(); \
	if (Z_TYPE_P(callback) != IS_NULL && !phpgtk_require_callable(callback, 3)) { \
		RETURN_THROWS(); \
	}

#define PHPGTK_ASYNC_PASS \
	parent != NULL ? GTK_WINDOW(PHPGTK_PTR(parent)) : NULL, \
	cancellable != NULL ? G_CANCELLABLE(PHPGTK_PTR(cancellable)) : NULL, \
	Z_TYPE_P(callback) != IS_NULL ? phpgtk_async_ready : NULL, \
	Z_TYPE_P(callback) != IS_NULL ? phpgtk_callout_new(callback) : NULL

/* A …Finish(GAsyncResult $result) that returns a (transfer full) object, or throws its GError. */
#define PHPGTK_FINISH_OBJECT(klass, name, call, cast) \
ZEND_METHOD(klass, name) \
{ \
	zend_object *result; \
	GError *error = NULL; \
	ZEND_PARSE_PARAMETERS_START(1, 1) \
		Z_PARAM_OBJ_OF_CLASS(result, phpgtk_ce_GAsyncResult) \
	ZEND_PARSE_PARAMETERS_END(); \
	PHPGTK_REQUIRE_MAIN_THREAD(); \
	gpointer object = call(cast(THIS_PTR), G_ASYNC_RESULT(PHPGTK_PTR(result)), &error); \
	if (object == NULL) { \
		phpgtk_throw_gerror(error); \
		g_clear_error(&error); \
		RETURN_THROWS(); \
	} \
	phpgtk_box_gobject_full(return_value, object); \
}

/* ---- GFile ------------------------------------------------------------- */

ZEND_METHOD(GFile, newForPath)
{
	zend_string *path;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_PATH_STR(path)
	ZEND_PARSE_PARAMETERS_END();

	phpgtk_box_gobject_full(return_value, g_file_new_for_path(ZSTR_VAL(path)));
}

ZEND_METHOD(GFile, getPath)
{
	ZEND_PARSE_PARAMETERS_NONE();

	char *path = g_file_get_path(G_FILE(THIS_PTR));
	phpgtk_return_string(return_value, path);
	g_free(path);
}

/* ---- GdkClipboard ------------------------------------------------------ */

ZEND_METHOD(GdkClipboard, setText)
{
	zend_string *text;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(text)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	gdk_clipboard_set_text(GDK_CLIPBOARD(THIS_PTR), ZSTR_VAL(text));
}

/* ---- GtkAlertDialog ---------------------------------------------------- */

#define THIS_ALERT GTK_ALERT_DIALOG(THIS_PTR)

ZEND_METHOD(GtkAlertDialog, setMessage)
{
	zend_string *message;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(message)
	ZEND_PARSE_PARAMETERS_END();

	gtk_alert_dialog_set_message(THIS_ALERT, ZSTR_VAL(message));
}

ZEND_METHOD(GtkAlertDialog, setDetail)
{
	zend_string *detail;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(detail)
	ZEND_PARSE_PARAMETERS_END();

	gtk_alert_dialog_set_detail(THIS_ALERT, ZSTR_VAL(detail));
}

ZEND_METHOD(GtkAlertDialog, setButtons)
{
	HashTable *labels;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ARRAY_HT(labels)
	ZEND_PARSE_PARAMETERS_END();

	const char **array = phpgtk_string_array(labels, 1);
	if (array == NULL) {
		RETURN_THROWS();
	}
	gtk_alert_dialog_set_buttons(THIS_ALERT, array);
	efree(array);
}

ZEND_METHOD(GtkAlertDialog, setDefaultButton)
{
	zend_long button;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(button)
	ZEND_PARSE_PARAMETERS_END();

	gtk_alert_dialog_set_default_button(THIS_ALERT, (int) button);
}

ZEND_METHOD(GtkAlertDialog, setCancelButton)
{
	zend_long button;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(button)
	ZEND_PARSE_PARAMETERS_END();

	gtk_alert_dialog_set_cancel_button(THIS_ALERT, (int) button);
}

ZEND_METHOD(GtkAlertDialog, setModal)
{
	bool modal;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(modal)
	ZEND_PARSE_PARAMETERS_END();

	gtk_alert_dialog_set_modal(THIS_ALERT, modal);
}

ZEND_METHOD(GtkAlertDialog, choose)
{
	PHPGTK_ASYNC_ARGS
	gtk_alert_dialog_choose(THIS_ALERT, PHPGTK_ASYNC_PASS);
}

ZEND_METHOD(GtkAlertDialog, chooseFinish)
{
	zend_object *result;
	GError *error = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(result, phpgtk_ce_GAsyncResult)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	int button = gtk_alert_dialog_choose_finish(THIS_ALERT, G_ASYNC_RESULT(PHPGTK_PTR(result)), &error);
	if (error != NULL) {
		phpgtk_throw_gerror(error);
		g_error_free(error);
		RETURN_THROWS();
	}

	RETURN_LONG(button);
}

/* ---- GtkFileDialog ----------------------------------------------------- */

#define THIS_FILE_DIALOG GTK_FILE_DIALOG(THIS_PTR)

ZEND_METHOD(GtkFileDialog, new)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();

	phpgtk_box_gobject_full(return_value, gtk_file_dialog_new());
}

ZEND_METHOD(GtkFileDialog, setTitle)
{
	zend_string *title;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(title)
	ZEND_PARSE_PARAMETERS_END();

	gtk_file_dialog_set_title(THIS_FILE_DIALOG, ZSTR_VAL(title));
}

ZEND_METHOD(GtkFileDialog, setInitialFolder)
{
	zend_object *folder = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(folder, phpgtk_ce_GFile)
	ZEND_PARSE_PARAMETERS_END();

	gtk_file_dialog_set_initial_folder(THIS_FILE_DIALOG, folder != NULL ? G_FILE(PHPGTK_PTR(folder)) : NULL);
}

ZEND_METHOD(GtkFileDialog, setInitialName)
{
	zend_string *name = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR_OR_NULL(name)
	ZEND_PARSE_PARAMETERS_END();

	gtk_file_dialog_set_initial_name(THIS_FILE_DIALOG, name != NULL ? ZSTR_VAL(name) : NULL);
}

ZEND_METHOD(GtkFileDialog, setModal)
{
	bool modal;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(modal)
	ZEND_PARSE_PARAMETERS_END();

	gtk_file_dialog_set_modal(THIS_FILE_DIALOG, modal);
}

ZEND_METHOD(GtkFileDialog, open)
{
	PHPGTK_ASYNC_ARGS
	gtk_file_dialog_open(THIS_FILE_DIALOG, PHPGTK_ASYNC_PASS);
}

ZEND_METHOD(GtkFileDialog, openMultiple)
{
	PHPGTK_ASYNC_ARGS
	gtk_file_dialog_open_multiple(THIS_FILE_DIALOG, PHPGTK_ASYNC_PASS);
}

ZEND_METHOD(GtkFileDialog, selectFolder)
{
	PHPGTK_ASYNC_ARGS
	gtk_file_dialog_select_folder(THIS_FILE_DIALOG, PHPGTK_ASYNC_PASS);
}

ZEND_METHOD(GtkFileDialog, save)
{
	PHPGTK_ASYNC_ARGS
	gtk_file_dialog_save(THIS_FILE_DIALOG, PHPGTK_ASYNC_PASS);
}

PHPGTK_FINISH_OBJECT(GtkFileDialog, openFinish, gtk_file_dialog_open_finish, GTK_FILE_DIALOG)
PHPGTK_FINISH_OBJECT(GtkFileDialog, openMultipleFinish, gtk_file_dialog_open_multiple_finish, GTK_FILE_DIALOG)
PHPGTK_FINISH_OBJECT(GtkFileDialog, selectFolderFinish, gtk_file_dialog_select_folder_finish, GTK_FILE_DIALOG)
PHPGTK_FINISH_OBJECT(GtkFileDialog, saveFinish, gtk_file_dialog_save_finish, GTK_FILE_DIALOG)

/* ---- GtkFileLauncher --------------------------------------------------- */

#define THIS_FILE_LAUNCHER GTK_FILE_LAUNCHER(THIS_PTR)

ZEND_METHOD(GtkFileLauncher, new)
{
	zend_object *file = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(file, phpgtk_ce_GFile)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	phpgtk_box_gobject_full(return_value, gtk_file_launcher_new(file != NULL ? G_FILE(PHPGTK_PTR(file)) : NULL));
}

ZEND_METHOD(GtkFileLauncher, launch)
{
	PHPGTK_ASYNC_ARGS
	gtk_file_launcher_launch(THIS_FILE_LAUNCHER, PHPGTK_ASYNC_PASS);
}

ZEND_METHOD(GtkFileLauncher, launchFinish)
{
	zend_object *result;
	GError *error = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(result, phpgtk_ce_GAsyncResult)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	if (!gtk_file_launcher_launch_finish(THIS_FILE_LAUNCHER, G_ASYNC_RESULT(PHPGTK_PTR(result)), &error)) {
		if (error != NULL) {
			phpgtk_throw_gerror(error);
			g_error_free(error);
			RETURN_THROWS();
		}
		RETURN_FALSE;
	}

	RETURN_TRUE;
}
