#include "runtime.h"
#include "../stubs/GtkApplication_arginfo.h"

void phpgtk_register_GtkApplication(void)
{
	phpgtk_ce_GtkApplication = register_class_GtkApplication(phpgtk_ce_GApplication);
	phpgtk_object_setup(phpgtk_ce_GtkApplication);
	phpgtk_map_gtype("GtkApplication", phpgtk_ce_GtkApplication);
}

ZEND_METHOD(GtkApplication, new)
{
	zend_string *application_id = NULL;
	zend_object *flags_case = NULL;
	zend_long flags_long = 0;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR_OR_NULL(application_id)
		Z_PARAM_OBJ_OF_CLASS_OR_LONG(flags_case, phpgtk_ce_GApplicationFlags, flags_long)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	if (application_id != NULL && !g_application_id_is_valid(ZSTR_VAL(application_id))) {
		zend_argument_value_error(1, "must be a valid application id (see GApplication::idIsValid())");
		RETURN_THROWS();
	}

	GtkApplication *app = gtk_application_new(
		application_id != NULL ? ZSTR_VAL(application_id) : NULL,
		(GApplicationFlags) phpgtk_enum_value(flags_case, flags_long)
	);

	phpgtk_box_gobject(return_value, app);
	g_object_unref(app);
}

#define THIS_GTK_APP GTK_APPLICATION(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

ZEND_METHOD(GtkApplication, addWindow)
{
	zend_object *window;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(window, phpgtk_ce_GtkWindow)
	ZEND_PARSE_PARAMETERS_END();

	gtk_application_add_window(THIS_GTK_APP, GTK_WINDOW(PHPGTK_PTR(window)));
}

ZEND_METHOD(GtkApplication, removeWindow)
{
	zend_object *window;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(window, phpgtk_ce_GtkWindow)
	ZEND_PARSE_PARAMETERS_END();

	gtk_application_remove_window(THIS_GTK_APP, GTK_WINDOW(PHPGTK_PTR(window)));
}

ZEND_METHOD(GtkApplication, getActiveWindow)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_application_get_active_window(THIS_GTK_APP));
}

ZEND_METHOD(GtkApplication, getWindows)
{
	ZEND_PARSE_PARAMETERS_NONE();

	array_init(return_value);
	for (GList *node = gtk_application_get_windows(THIS_GTK_APP); node != NULL; node = node->next) {
		zval boxed;
		phpgtk_box_gobject(&boxed, node->data);
		add_next_index_zval(return_value, &boxed);
	}
}

ZEND_METHOD(GtkApplication, getMenubar)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_application_get_menubar(THIS_GTK_APP));
}

ZEND_METHOD(GtkApplication, setMenubar)
{
	zend_object *menubar = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(menubar, phpgtk_ce_GMenuModel)
	ZEND_PARSE_PARAMETERS_END();

	gtk_application_set_menubar(THIS_GTK_APP, (GMenuModel *) PHPGTK_OPTIONAL_PTR(menubar));
}

ZEND_METHOD(GtkApplication, setAccelsForAction)
{
	zend_string *action;
	HashTable *accels_ht;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(action)
		Z_PARAM_ARRAY_HT(accels_ht)
	ZEND_PARSE_PARAMETERS_END();

	if (!phpgtk_is_detailed_action(ZSTR_VAL(action))) {
		zend_argument_value_error(1, "must be a valid detailed action name");
		RETURN_THROWS();
	}

	uint32_t count = zend_hash_num_elements(accels_ht);
	const gchar **accels = ecalloc(count + 1, sizeof(gchar *));
	zend_string **held = ecalloc(count + 1, sizeof(zend_string *));
	uint32_t i = 0;
	zval *accel;
	bool failed = false;

	ZEND_HASH_FOREACH_VAL(accels_ht, accel) {
		held[i] = zval_try_get_string(accel);
		if (held[i] == NULL) {
			failed = true;
			break;
		}
		guint key = 0;
		GdkModifierType mods = 0;
		if (!gtk_accelerator_parse(ZSTR_VAL(held[i]), &key, &mods)) {
			zend_argument_value_error(2, "holds \"%s\", which is not an accelerator", ZSTR_VAL(held[i]));
			i++;
			failed = true;
			break;
		}
		accels[i] = ZSTR_VAL(held[i]);
		i++;
	} ZEND_HASH_FOREACH_END();

	if (!failed) {
		gtk_application_set_accels_for_action(THIS_GTK_APP, ZSTR_VAL(action), accels);
	}

	for (uint32_t j = 0; j < i; j++) {
		if (held[j] != NULL) {
			zend_string_release(held[j]);
		}
	}
	efree(held);
	efree(accels);

	if (failed) {
		RETURN_THROWS();
	}
}

ZEND_METHOD(GtkApplication, getAccelsForAction)
{
	zend_string *action;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(action)
	ZEND_PARSE_PARAMETERS_END();

	gchar **accels = gtk_application_get_accels_for_action(THIS_GTK_APP, ZSTR_VAL(action));

	array_init(return_value);
	for (gchar **accel = accels; accel != NULL && *accel != NULL; accel++) {
		add_next_index_string(return_value, *accel);
	}
	g_strfreev(accels);
}
