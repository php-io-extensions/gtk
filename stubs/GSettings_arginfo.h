/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 5411141b4cfa4813dab40d6b3ac85dbf3e1993eb */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_GSettingsSchemaSource___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GSettingsSchemaSource_getDefault, 0, 0, GSettingsSchemaSource, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GSettingsSchemaSource_lookup, 0, 2, GSettingsSchema, 1)
	ZEND_ARG_TYPE_INFO(0, schemaId, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, recursive, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GSettingsSchema___construct arginfo_class_GSettingsSchemaSource___construct

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GSettingsSchema_hasKey, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GSettings_new, 0, 1, GSettings, 0)
	ZEND_ARG_TYPE_INFO(0, schemaId, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GSettings_getBoolean, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GSettings_getInt, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GSettings_getUint arginfo_class_GSettings_getInt

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GSettings_getDouble, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GSettings_getString, 0, 1, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, key, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(GSettingsSchemaSource, __construct);
ZEND_METHOD(GSettingsSchemaSource, getDefault);
ZEND_METHOD(GSettingsSchemaSource, lookup);
ZEND_METHOD(GSettingsSchema, __construct);
ZEND_METHOD(GSettingsSchema, hasKey);
ZEND_METHOD(GSettings, new);
ZEND_METHOD(GSettings, getBoolean);
ZEND_METHOD(GSettings, getInt);
ZEND_METHOD(GSettings, getUint);
ZEND_METHOD(GSettings, getDouble);
ZEND_METHOD(GSettings, getString);

static const zend_function_entry class_GSettingsSchemaSource_methods[] = {
	ZEND_ME(GSettingsSchemaSource, __construct, arginfo_class_GSettingsSchemaSource___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(GSettingsSchemaSource, getDefault, arginfo_class_GSettingsSchemaSource_getDefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GSettingsSchemaSource, lookup, arginfo_class_GSettingsSchemaSource_lookup, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GSettingsSchema_methods[] = {
	ZEND_ME(GSettingsSchema, __construct, arginfo_class_GSettingsSchema___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(GSettingsSchema, hasKey, arginfo_class_GSettingsSchema_hasKey, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GSettings_methods[] = {
	ZEND_ME(GSettings, new, arginfo_class_GSettings_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GSettings, getBoolean, arginfo_class_GSettings_getBoolean, ZEND_ACC_PUBLIC)
	ZEND_ME(GSettings, getInt, arginfo_class_GSettings_getInt, ZEND_ACC_PUBLIC)
	ZEND_ME(GSettings, getUint, arginfo_class_GSettings_getUint, ZEND_ACC_PUBLIC)
	ZEND_ME(GSettings, getDouble, arginfo_class_GSettings_getDouble, ZEND_ACC_PUBLIC)
	ZEND_ME(GSettings, getString, arginfo_class_GSettings_getString, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_GSettingsSchemaSource(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GSettingsSchemaSource", class_GSettingsSchemaSource_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GSettingsSchema(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GSettingsSchema", class_GSettingsSchema_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GSettings(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GSettings", class_GSettings_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
