#include "runtime.h"
#include "../stubs/GSettings_arginfo.h"

void phpgtk_register_GSettings(void)
{
	phpgtk_ce_GSettingsSchemaSource = register_class_GSettingsSchemaSource();
	phpgtk_object_setup(phpgtk_ce_GSettingsSchemaSource);

	phpgtk_ce_GSettingsSchema = register_class_GSettingsSchema();
	phpgtk_object_setup(phpgtk_ce_GSettingsSchema);

	phpgtk_ce_GSettings = register_class_GSettings(phpgtk_ce_GObject);
	phpgtk_object_setup(phpgtk_ce_GSettings);
	phpgtk_map_gtype("GSettings", phpgtk_ce_GSettings);
}

#define THIS_SOURCE ((GSettingsSchemaSource *) PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))
#define THIS_SCHEMA ((GSettingsSchema *) PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))
#define THIS_SETTINGS G_SETTINGS(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

/* ---- GSettingsSchemaSource --------------------------------------------- */

ZEND_METHOD(GSettingsSchemaSource, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
}

ZEND_METHOD(GSettingsSchemaSource, getDefault)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_settings_schema_source(return_value, g_settings_schema_source_get_default());
}

ZEND_METHOD(GSettingsSchemaSource, lookup)
{
	zend_string *schema_id;
	bool recursive;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(schema_id)
		Z_PARAM_BOOL(recursive)
	ZEND_PARSE_PARAMETERS_END();

	phpgtk_box_settings_schema_full(return_value, g_settings_schema_source_lookup(THIS_SOURCE, ZSTR_VAL(schema_id), recursive));
}

/* ---- GSettingsSchema --------------------------------------------------- */

ZEND_METHOD(GSettingsSchema, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
}

ZEND_METHOD(GSettingsSchema, hasKey)
{
	zend_string *name;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_BOOL(g_settings_schema_has_key(THIS_SCHEMA, ZSTR_VAL(name)));
}

/* ---- GSettings --------------------------------------------------------- */

/* Whether the settings' schema has the key: every g_settings_get_*() answers a key it lacks with g_error(). */
static bool phpgtk_settings_has_key(GSettings *settings, zend_string *key)
{
	GSettingsSchema *schema = NULL;
	bool known;

	g_object_get(settings, "settings-schema", &schema, NULL);
	known = schema != NULL && g_settings_schema_has_key(schema, ZSTR_VAL(key));
	if (schema != NULL) {
		g_settings_schema_unref(schema);
	}

	return known;
}

ZEND_METHOD(GSettings, new)
{
	zend_string *schema_id;
	GSettingsSchemaSource *source;
	GSettingsSchema *schema = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(schema_id)
	ZEND_PARSE_PARAMETERS_END();

	/* g_settings_new() looks the id up this way, and answers a miss with g_error(). */
	source = g_settings_schema_source_get_default();
	if (source != NULL) {
		schema = g_settings_schema_source_lookup(source, ZSTR_VAL(schema_id), TRUE);
	}

	if (!PHPGTK_PROBE_OFF("gsettings-schema-installed") && (schema == NULL)) {
		zend_argument_value_error(1, "must name an installed schema, \"%s\" is not", ZSTR_VAL(schema_id)); /* binding:gsettings-schema-installed */
		RETURN_THROWS();
	}

	/* g_settings_new() has no path argument, and answers a schema without one with g_error(). */
	if (!PHPGTK_PROBE_OFF("gsettings-schema-path") && (schema != NULL && g_settings_schema_get_path(schema) == NULL)) {
		g_settings_schema_unref(schema);
		zend_argument_value_error(1, "must name a schema with a path, \"%s\" has none", ZSTR_VAL(schema_id)); /* binding:gsettings-schema-path */
		RETURN_THROWS();
	}

	if (schema != NULL) {
		g_settings_schema_unref(schema);
	}

	phpgtk_box_gobject_full(return_value, g_settings_new(ZSTR_VAL(schema_id)));
}

ZEND_METHOD(GSettings, getBoolean)
{
	zend_string *key;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();

	if (!PHPGTK_PROBE_OFF("gsettings-key-in-schema-boolean") && (!phpgtk_settings_has_key(THIS_SETTINGS, key))) {
		zend_argument_value_error(1, "must be a key of the schema, \"%s\" is not", ZSTR_VAL(key)); /* binding:gsettings-key-in-schema-boolean */
		RETURN_THROWS();
	}

	RETURN_BOOL(g_settings_get_boolean(THIS_SETTINGS, ZSTR_VAL(key)));
}

ZEND_METHOD(GSettings, getInt)
{
	zend_string *key;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();

	if (!PHPGTK_PROBE_OFF("gsettings-key-in-schema-int") && (!phpgtk_settings_has_key(THIS_SETTINGS, key))) {
		zend_argument_value_error(1, "must be a key of the schema, \"%s\" is not", ZSTR_VAL(key)); /* binding:gsettings-key-in-schema-int */
		RETURN_THROWS();
	}

	RETURN_LONG(g_settings_get_int(THIS_SETTINGS, ZSTR_VAL(key)));
}

ZEND_METHOD(GSettings, getUint)
{
	zend_string *key;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();

	if (!PHPGTK_PROBE_OFF("gsettings-key-in-schema-uint") && (!phpgtk_settings_has_key(THIS_SETTINGS, key))) {
		zend_argument_value_error(1, "must be a key of the schema, \"%s\" is not", ZSTR_VAL(key)); /* binding:gsettings-key-in-schema-uint */
		RETURN_THROWS();
	}

	RETURN_LONG(g_settings_get_uint(THIS_SETTINGS, ZSTR_VAL(key)));
}

ZEND_METHOD(GSettings, getDouble)
{
	zend_string *key;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();

	if (!PHPGTK_PROBE_OFF("gsettings-key-in-schema-double") && (!phpgtk_settings_has_key(THIS_SETTINGS, key))) {
		zend_argument_value_error(1, "must be a key of the schema, \"%s\" is not", ZSTR_VAL(key)); /* binding:gsettings-key-in-schema-double */
		RETURN_THROWS();
	}

	RETURN_DOUBLE(g_settings_get_double(THIS_SETTINGS, ZSTR_VAL(key)));
}

ZEND_METHOD(GSettings, getString)
{
	zend_string *key;
	gchar *value;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(key)
	ZEND_PARSE_PARAMETERS_END();

	if (!PHPGTK_PROBE_OFF("gsettings-key-in-schema-string") && (!phpgtk_settings_has_key(THIS_SETTINGS, key))) {
		zend_argument_value_error(1, "must be a key of the schema, \"%s\" is not", ZSTR_VAL(key)); /* binding:gsettings-key-in-schema-string */
		RETURN_THROWS();
	}

	value = g_settings_get_string(THIS_SETTINGS, ZSTR_VAL(key));
	phpgtk_return_string(return_value, value);
	g_free(value);
}
