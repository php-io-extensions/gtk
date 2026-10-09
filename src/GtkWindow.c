#include "runtime.h"
#include "../stubs/GtkWindow_arginfo.h"

void phpgtk_register_GtkWindow(void)
{
	phpgtk_ce_GtkWindow = register_class_GtkWindow(phpgtk_ce_GtkWidget);
	phpgtk_object_setup(phpgtk_ce_GtkWindow);
	phpgtk_map_gtype("GtkWindow", phpgtk_ce_GtkWindow);

	phpgtk_ce_GtkApplicationWindow = register_class_GtkApplicationWindow(phpgtk_ce_GtkWindow);
	phpgtk_object_setup(phpgtk_ce_GtkApplicationWindow);
	phpgtk_map_gtype("GtkApplicationWindow", phpgtk_ce_GtkApplicationWindow);

	phpgtk_ce_GtkAboutDialog = register_class_GtkAboutDialog(phpgtk_ce_GtkWindow);
	phpgtk_object_setup(phpgtk_ce_GtkAboutDialog);
	phpgtk_map_gtype("GtkAboutDialog", phpgtk_ce_GtkAboutDialog);
}

#define THIS_WINDOW GTK_WINDOW(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

/* A nullable-string setter: one call taking the object and a const char *. */
#define PHPGTK_NULLABLE_STRING_SETTER(cls, name, call, cast) \
ZEND_METHOD(cls, name) \
{ \
	zend_string *value = NULL; \
	ZEND_PARSE_PARAMETERS_START(1, 1) \
		Z_PARAM_STR_OR_NULL(value) \
	ZEND_PARSE_PARAMETERS_END(); \
	call(cast(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS))), value != NULL ? ZSTR_VAL(value) : NULL); \
}

#define PHPGTK_STRING_GETTER(cls, name, call, cast) \
ZEND_METHOD(cls, name) \
{ \
	ZEND_PARSE_PARAMETERS_NONE(); \
	phpgtk_return_string(return_value, call(cast(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS))))); \
}

#define PHPGTK_BOOL_GETTER(cls, name, call, cast) \
ZEND_METHOD(cls, name) \
{ \
	ZEND_PARSE_PARAMETERS_NONE(); \
	RETURN_BOOL(call(cast(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS))))); \
}

#define PHPGTK_BOOL_SETTER(cls, name, call, cast) \
ZEND_METHOD(cls, name) \
{ \
	bool value; \
	ZEND_PARSE_PARAMETERS_START(1, 1) \
		Z_PARAM_BOOL(value) \
	ZEND_PARSE_PARAMETERS_END(); \
	call(cast(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS))), value); \
}

#define PHPGTK_VOID_CALL(cls, name, call, cast) \
ZEND_METHOD(cls, name) \
{ \
	ZEND_PARSE_PARAMETERS_NONE(); \
	call(cast(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))); \
}

/* ---- GtkWindow --------------------------------------------------------- */

ZEND_METHOD(GtkWindow, new)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();
	PHPGTK_REQUIRE_INITIALIZED();

	/* (transfer none): GTK keeps the toplevel; PHP takes its own reference. */
	phpgtk_box_gobject(return_value, gtk_window_new());
}

PHPGTK_STRING_GETTER(GtkWindow, getTitle, gtk_window_get_title, GTK_WINDOW)
PHPGTK_NULLABLE_STRING_SETTER(GtkWindow, setTitle, gtk_window_set_title, GTK_WINDOW)

ZEND_METHOD(GtkWindow, getDefaultSize)
{
	int width = 0;
	int height = 0;

	ZEND_PARSE_PARAMETERS_NONE();

	gtk_window_get_default_size(THIS_WINDOW, &width, &height);

	array_init_size(return_value, 2);
	add_next_index_long(return_value, width);
	add_next_index_long(return_value, height);
}

ZEND_METHOD(GtkWindow, getSurfaceTransform)
{
	double x;
	double y;

	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();

	gtk_native_get_surface_transform(GTK_NATIVE(THIS_WINDOW), &x, &y);
	array_init_size(return_value, 2);
	add_next_index_double(return_value, x);
	add_next_index_double(return_value, y);
}

ZEND_METHOD(GtkWindow, setDefaultSize)
{
	zend_long width;
	zend_long height;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();

	gtk_window_set_default_size(THIS_WINDOW, (int) width, (int) height);
}

ZEND_METHOD(GtkWindow, getChild)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_window_get_child(THIS_WINDOW));
}

ZEND_METHOD(GtkWindow, setChild)
{
	zend_object *child = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(child, phpgtk_ce_GtkWidget)
	ZEND_PARSE_PARAMETERS_END();

	gtk_window_set_child(THIS_WINDOW, child != NULL ? GTK_WIDGET(PHPGTK_PTR(child)) : NULL);
}

ZEND_METHOD(GtkWindow, present)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();

	gtk_window_present(THIS_WINDOW);
}

PHPGTK_VOID_CALL(GtkWindow, close, gtk_window_close, GTK_WINDOW)
PHPGTK_VOID_CALL(GtkWindow, destroy, gtk_window_destroy, GTK_WINDOW)
PHPGTK_BOOL_GETTER(GtkWindow, isActive, gtk_window_is_active, GTK_WINDOW)

ZEND_METHOD(GtkWindow, getTransientFor)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_window_get_transient_for(THIS_WINDOW));
}

ZEND_METHOD(GtkWindow, setTransientFor)
{
	zend_object *parent = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(parent, phpgtk_ce_GtkWindow)
	ZEND_PARSE_PARAMETERS_END();

	gtk_window_set_transient_for(THIS_WINDOW, parent != NULL ? GTK_WINDOW(PHPGTK_PTR(parent)) : NULL);
}

ZEND_METHOD(GtkWindow, getApplication)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_window_get_application(THIS_WINDOW));
}

ZEND_METHOD(GtkWindow, setApplication)
{
	zend_object *application = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(application, phpgtk_ce_GtkApplication)
	ZEND_PARSE_PARAMETERS_END();

	gtk_window_set_application(THIS_WINDOW, application != NULL ? GTK_APPLICATION(PHPGTK_PTR(application)) : NULL);
}

PHPGTK_BOOL_GETTER(GtkWindow, getModal, gtk_window_get_modal, GTK_WINDOW)
PHPGTK_BOOL_SETTER(GtkWindow, setModal, gtk_window_set_modal, GTK_WINDOW)
PHPGTK_BOOL_GETTER(GtkWindow, getHideOnClose, gtk_window_get_hide_on_close, GTK_WINDOW)
PHPGTK_BOOL_SETTER(GtkWindow, setHideOnClose, gtk_window_set_hide_on_close, GTK_WINDOW)

/* ---- GtkApplicationWindow ---------------------------------------------- */

ZEND_METHOD(GtkApplicationWindow, new)
{
	zend_object *application = NULL;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(application, phpgtk_ce_GtkApplication)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();
	PHPGTK_REQUIRE_INITIALIZED();

	if (application == NULL) {
		zend_argument_value_error(1, "must be a GtkApplication: gtk_application_window_new() requires one");
		RETURN_THROWS();
	}

	phpgtk_box_gobject(return_value, gtk_application_window_new(GTK_APPLICATION(PHPGTK_PTR(application))));
}

PHPGTK_BOOL_GETTER(GtkApplicationWindow, getShowMenubar, gtk_application_window_get_show_menubar, GTK_APPLICATION_WINDOW)
PHPGTK_BOOL_SETTER(GtkApplicationWindow, setShowMenubar, gtk_application_window_set_show_menubar, GTK_APPLICATION_WINDOW)

ZEND_METHOD(GtkApplicationWindow, getId)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG((zend_long) gtk_application_window_get_id(GTK_APPLICATION_WINDOW(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))));
}

/* ---- GtkAboutDialog ---------------------------------------------------- */

ZEND_METHOD(GtkAboutDialog, new)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();
	PHPGTK_REQUIRE_INITIALIZED();

	phpgtk_box_gobject(return_value, gtk_about_dialog_new());
}

PHPGTK_STRING_GETTER(GtkAboutDialog, getProgramName, gtk_about_dialog_get_program_name, GTK_ABOUT_DIALOG)
PHPGTK_NULLABLE_STRING_SETTER(GtkAboutDialog, setProgramName, gtk_about_dialog_set_program_name, GTK_ABOUT_DIALOG)
PHPGTK_STRING_GETTER(GtkAboutDialog, getVersion, gtk_about_dialog_get_version, GTK_ABOUT_DIALOG)
PHPGTK_NULLABLE_STRING_SETTER(GtkAboutDialog, setVersion, gtk_about_dialog_set_version, GTK_ABOUT_DIALOG)
PHPGTK_STRING_GETTER(GtkAboutDialog, getCopyright, gtk_about_dialog_get_copyright, GTK_ABOUT_DIALOG)
PHPGTK_NULLABLE_STRING_SETTER(GtkAboutDialog, setCopyright, gtk_about_dialog_set_copyright, GTK_ABOUT_DIALOG)
PHPGTK_STRING_GETTER(GtkAboutDialog, getComments, gtk_about_dialog_get_comments, GTK_ABOUT_DIALOG)
PHPGTK_NULLABLE_STRING_SETTER(GtkAboutDialog, setComments, gtk_about_dialog_set_comments, GTK_ABOUT_DIALOG)
PHPGTK_STRING_GETTER(GtkAboutDialog, getWebsite, gtk_about_dialog_get_website, GTK_ABOUT_DIALOG)
PHPGTK_NULLABLE_STRING_SETTER(GtkAboutDialog, setWebsite, gtk_about_dialog_set_website, GTK_ABOUT_DIALOG)
