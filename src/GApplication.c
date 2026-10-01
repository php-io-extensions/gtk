#include "runtime.h"
#include "../stubs/GApplication_arginfo.h"

void phpgtk_register_GApplication(void)
{
	phpgtk_ce_GApplicationFlags = register_class_GApplicationFlags();
	phpgtk_ce_GApplication = register_class_GApplication(phpgtk_ce_GObject);
	phpgtk_object_setup(phpgtk_ce_GApplication);
	phpgtk_map_gtype("GApplication", phpgtk_ce_GApplication);
}

#define THIS_APP G_APPLICATION(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

ZEND_METHOD(GApplication, idIsValid)
{
	zend_string *application_id;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(application_id)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_BOOL(g_application_id_is_valid(ZSTR_VAL(application_id)));
}

ZEND_METHOD(GApplication, getApplicationId)
{
	ZEND_PARSE_PARAMETERS_NONE();

	const char *id = g_application_get_application_id(THIS_APP);

	if (id == NULL) {
		RETURN_NULL();
	}

	RETURN_STRING(id);
}

ZEND_METHOD(GApplication, getFlags)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG((zend_long) g_application_get_flags(THIS_APP));
}

ZEND_METHOD(GApplication, getIsRegistered)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_BOOL(g_application_get_is_registered(THIS_APP));
}

ZEND_METHOD(GApplication, getIsRemote)
{
	ZEND_PARSE_PARAMETERS_NONE();

	if (!g_application_get_is_registered(THIS_APP)) {
		zend_throw_exception(phpgtk_ce_GtkException, "GApplication::getIsRemote() needs a registered application", 0);
		RETURN_THROWS();
	}

	RETURN_BOOL(g_application_get_is_remote(THIS_APP));
}

ZEND_METHOD(GApplication, register)
{
	GError *error = NULL;

	ZEND_PARSE_PARAMETERS_NONE();

	if (!g_application_register(THIS_APP, NULL, &error)) {
		if (error != NULL) {
			phpgtk_throw_gerror(error);
			g_error_free(error);
			RETURN_THROWS();
		}
		RETURN_FALSE;
	}

	RETURN_TRUE;
}

ZEND_METHOD(GApplication, activate)
{
	ZEND_PARSE_PARAMETERS_NONE();

	g_application_activate(THIS_APP);
}

ZEND_METHOD(GApplication, hold)
{
	ZEND_PARSE_PARAMETERS_NONE();

	g_application_hold(THIS_APP);
}

ZEND_METHOD(GApplication, release)
{
	ZEND_PARSE_PARAMETERS_NONE();

	g_application_release(THIS_APP);
}

ZEND_METHOD(GApplication, quit)
{
	ZEND_PARSE_PARAMETERS_NONE();

	g_application_quit(THIS_APP);
}

ZEND_METHOD(GApplication, run)
{
	HashTable *argv_ht = NULL;

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		Z_PARAM_ARRAY_HT(argv_ht)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	int argc = argv_ht != NULL ? (int) zend_hash_num_elements(argv_ht) : 0;
	char **argv = ecalloc((size_t) argc + 1, sizeof(char *));
	zend_string **held = ecalloc((size_t) argc + 1, sizeof(zend_string *));
	zval *arg;
	int i = 0;

	if (argv_ht != NULL) {
		ZEND_HASH_FOREACH_VAL(argv_ht, arg) {
			held[i] = zval_try_get_string(arg);
			if (held[i] == NULL) {
				goto cleanup;
			}
			argv[i] = ZSTR_VAL(held[i]);
			i++;
		} ZEND_HASH_FOREACH_END();
	}

	RETVAL_LONG(g_application_run(THIS_APP, argc, argc > 0 ? argv : NULL));

cleanup:
	for (int j = 0; j < i; j++) {
		zend_string_release(held[j]);
	}
	efree(held);
	efree(argv);
}
