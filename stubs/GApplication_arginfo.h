/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 06323b2b7c26194197170548431481505f467f03 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GApplication_idIsValid, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, applicationId, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GApplication_getApplicationId, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GApplication_getFlags, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GApplication_getIsRegistered, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GApplication_getIsRemote arginfo_class_GApplication_getIsRegistered

#define arginfo_class_GApplication_register arginfo_class_GApplication_getIsRegistered

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GApplication_activate, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GApplication_hold arginfo_class_GApplication_activate

#define arginfo_class_GApplication_release arginfo_class_GApplication_activate

#define arginfo_class_GApplication_quit arginfo_class_GApplication_activate

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GApplication_run, 0, 0, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, argv, IS_ARRAY, 0, "[]")
ZEND_END_ARG_INFO()

ZEND_METHOD(GApplication, idIsValid);
ZEND_METHOD(GApplication, getApplicationId);
ZEND_METHOD(GApplication, getFlags);
ZEND_METHOD(GApplication, getIsRegistered);
ZEND_METHOD(GApplication, getIsRemote);
ZEND_METHOD(GApplication, register);
ZEND_METHOD(GApplication, activate);
ZEND_METHOD(GApplication, hold);
ZEND_METHOD(GApplication, release);
ZEND_METHOD(GApplication, quit);
ZEND_METHOD(GApplication, run);

static const zend_function_entry class_GApplication_methods[] = {
	ZEND_ME(GApplication, idIsValid, arginfo_class_GApplication_idIsValid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GApplication, getApplicationId, arginfo_class_GApplication_getApplicationId, ZEND_ACC_PUBLIC)
	ZEND_ME(GApplication, getFlags, arginfo_class_GApplication_getFlags, ZEND_ACC_PUBLIC)
	ZEND_ME(GApplication, getIsRegistered, arginfo_class_GApplication_getIsRegistered, ZEND_ACC_PUBLIC)
	ZEND_ME(GApplication, getIsRemote, arginfo_class_GApplication_getIsRemote, ZEND_ACC_PUBLIC)
	ZEND_ME(GApplication, register, arginfo_class_GApplication_register, ZEND_ACC_PUBLIC)
	ZEND_ME(GApplication, activate, arginfo_class_GApplication_activate, ZEND_ACC_PUBLIC)
	ZEND_ME(GApplication, hold, arginfo_class_GApplication_hold, ZEND_ACC_PUBLIC)
	ZEND_ME(GApplication, release, arginfo_class_GApplication_release, ZEND_ACC_PUBLIC)
	ZEND_ME(GApplication, quit, arginfo_class_GApplication_quit, ZEND_ACC_PUBLIC)
	ZEND_ME(GApplication, run, arginfo_class_GApplication_run, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_GApplicationFlags(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GApplicationFlags", IS_LONG, NULL);

	zval enum_case_DEFAULT_FLAGS_value;
	ZVAL_LONG(&enum_case_DEFAULT_FLAGS_value, 0);
	zend_enum_add_case_cstr(class_entry, "DEFAULT_FLAGS", &enum_case_DEFAULT_FLAGS_value);

	zval enum_case_IS_SERVICE_value;
	ZVAL_LONG(&enum_case_IS_SERVICE_value, 1);
	zend_enum_add_case_cstr(class_entry, "IS_SERVICE", &enum_case_IS_SERVICE_value);

	zval enum_case_IS_LAUNCHER_value;
	ZVAL_LONG(&enum_case_IS_LAUNCHER_value, 2);
	zend_enum_add_case_cstr(class_entry, "IS_LAUNCHER", &enum_case_IS_LAUNCHER_value);

	zval enum_case_HANDLES_OPEN_value;
	ZVAL_LONG(&enum_case_HANDLES_OPEN_value, 4);
	zend_enum_add_case_cstr(class_entry, "HANDLES_OPEN", &enum_case_HANDLES_OPEN_value);

	zval enum_case_HANDLES_COMMAND_LINE_value;
	ZVAL_LONG(&enum_case_HANDLES_COMMAND_LINE_value, 8);
	zend_enum_add_case_cstr(class_entry, "HANDLES_COMMAND_LINE", &enum_case_HANDLES_COMMAND_LINE_value);

	zval enum_case_SEND_ENVIRONMENT_value;
	ZVAL_LONG(&enum_case_SEND_ENVIRONMENT_value, 16);
	zend_enum_add_case_cstr(class_entry, "SEND_ENVIRONMENT", &enum_case_SEND_ENVIRONMENT_value);

	zval enum_case_NON_UNIQUE_value;
	ZVAL_LONG(&enum_case_NON_UNIQUE_value, 32);
	zend_enum_add_case_cstr(class_entry, "NON_UNIQUE", &enum_case_NON_UNIQUE_value);

	zval enum_case_CAN_OVERRIDE_APP_ID_value;
	ZVAL_LONG(&enum_case_CAN_OVERRIDE_APP_ID_value, 64);
	zend_enum_add_case_cstr(class_entry, "CAN_OVERRIDE_APP_ID", &enum_case_CAN_OVERRIDE_APP_ID_value);

	zval enum_case_ALLOW_REPLACEMENT_value;
	ZVAL_LONG(&enum_case_ALLOW_REPLACEMENT_value, 128);
	zend_enum_add_case_cstr(class_entry, "ALLOW_REPLACEMENT", &enum_case_ALLOW_REPLACEMENT_value);

	zval enum_case_REPLACE_value;
	ZVAL_LONG(&enum_case_REPLACE_value, 256);
	zend_enum_add_case_cstr(class_entry, "REPLACE", &enum_case_REPLACE_value);

	return class_entry;
}

static zend_class_entry *register_class_GApplication(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GApplication", class_GApplication_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
