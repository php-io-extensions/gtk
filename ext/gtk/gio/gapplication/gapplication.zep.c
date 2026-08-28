
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "src/gio-gapplication.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gio_GApplication_GApplication)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gio\\GApplication, GApplication, gtk, gio_gapplication_gapplication, gtk_gio_gapplication_gapplication_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gio_GApplication_GApplication, new_)
{
	zend_long flags;
	zval *applicationId = NULL, applicationId_sub, *flags_param = NULL, _0;

	ZVAL_UNDEF(&applicationId_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(applicationId)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &applicationId, &flags_param);
	ZVAL_LONG(&_0, flags);
	RETURN_LONG(phpgtk_gapplication_new(applicationId, &_0));
}

PHP_METHOD(Gtk_Gio_GApplication_GApplication, getDefault)
{

	RETURN_LONG(phpgtk_gapplication_get_default());
}

PHP_METHOD(Gtk_Gio_GApplication_GApplication, idIsValid)
{
	zend_long r = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *applicationId_param = NULL;
	zval applicationId;

	ZVAL_UNDEF(&applicationId);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(applicationId)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &applicationId_param);
	zephir_get_strval(&applicationId, applicationId_param);
	r = phpgtk_gapplication_id_is_valid(&applicationId);
	RETURN_MM_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gio_GApplication_GApplication, activate)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gapplication_activate(&_0);
}

PHP_METHOD(Gtk_Gio_GApplication_GApplication, addMainOption)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval longName, description;
	zval *handle_param = NULL, *longName_param = NULL, *shortName_param = NULL, *flags_param = NULL, *arg_param = NULL, *description_param = NULL, *argDescription = NULL, argDescription_sub, _0, _1, _2, _3;
	zend_long handle, shortName, flags, arg;

	ZVAL_UNDEF(&argDescription_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&longName);
	ZVAL_UNDEF(&description);
	ZEND_PARSE_PARAMETERS_START(7, 7)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(longName)
		Z_PARAM_LONG(shortName)
		Z_PARAM_LONG(flags)
		Z_PARAM_LONG(arg)
		Z_PARAM_STR(description)
		Z_PARAM_ZVAL(argDescription)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 7, 0, &handle_param, &longName_param, &shortName_param, &flags_param, &arg_param, &description_param, &argDescription);
	zephir_get_strval(&longName, longName_param);
	zephir_get_strval(&description, description_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, shortName);
	ZVAL_LONG(&_2, flags);
	ZVAL_LONG(&_3, arg);
	phpgtk_gapplication_add_main_option(&_0, &longName, &_1, &_2, &_3, &description, argDescription);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_Gio_GApplication_GApplication, getApplicationId)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *handle_param = NULL, result, _0;
	zend_long handle;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &handle_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, handle);
	phpgtk_gapplication_get_application_id(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gio_GApplication_GApplication, getDbusConnection)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gapplication_get_dbus_connection(&_0));
}

PHP_METHOD(Gtk_Gio_GApplication_GApplication, getDbusObjectPath)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *handle_param = NULL, result, _0;
	zend_long handle;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &handle_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, handle);
	phpgtk_gapplication_get_dbus_object_path(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gio_GApplication_GApplication, getFlags)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gapplication_get_flags(&_0));
}

PHP_METHOD(Gtk_Gio_GApplication_GApplication, getInactivityTimeout)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gapplication_get_inactivity_timeout(&_0));
}

PHP_METHOD(Gtk_Gio_GApplication_GApplication, getIsBusy)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gapplication_get_is_busy(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gio_GApplication_GApplication, getIsRegistered)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gapplication_get_is_registered(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gio_GApplication_GApplication, getIsRemote)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gapplication_get_is_remote(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gio_GApplication_GApplication, getResourceBasePath)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *handle_param = NULL, result, _0;
	zend_long handle;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &handle_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, handle);
	phpgtk_gapplication_get_resource_base_path(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gio_GApplication_GApplication, getVersion)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *handle_param = NULL, result, _0;
	zend_long handle;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &handle_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, handle);
	phpgtk_gapplication_get_version(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gio_GApplication_GApplication, hold)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gapplication_hold(&_0);
}

PHP_METHOD(Gtk_Gio_GApplication_GApplication, markBusy)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gapplication_mark_busy(&_0);
}

PHP_METHOD(Gtk_Gio_GApplication_GApplication, open)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval hint;
	zval files;
	zval *handle_param = NULL, *files_param = NULL, *nFiles_param = NULL, *hint_param = NULL, _0, _1;
	zend_long handle, nFiles;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&files);
	ZVAL_UNDEF(&hint);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(handle)
		Z_PARAM_ARRAY(files)
		Z_PARAM_LONG(nFiles)
		Z_PARAM_STR(hint)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 4, 0, &handle_param, &files_param, &nFiles_param, &hint_param);
	zephir_get_arrval(&files, files_param);
	zephir_get_strval(&hint, hint_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, nFiles);
	phpgtk_gapplication_open(&_0, &files, &_1, &hint);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_Gio_GApplication_GApplication, quit)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gapplication_quit(&_0);
}

PHP_METHOD(Gtk_Gio_GApplication_GApplication, release)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gapplication_release(&_0);
}

PHP_METHOD(Gtk_Gio_GApplication_GApplication, run)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval argv;
	zval *handle_param = NULL, *argc_param = NULL, *argv_param = NULL, _0, _1;
	zend_long handle, argc;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&argv);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(argc)
		Z_PARAM_ARRAY(argv)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &handle_param, &argc_param, &argv_param);
	zephir_get_arrval(&argv, argv_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, argc);
	RETURN_MM_LONG(phpgtk_gapplication_run(&_0, &_1, &argv));
}

PHP_METHOD(Gtk_Gio_GApplication_GApplication, sendNotification)
{
	zval *handle_param = NULL, *id = NULL, id_sub, *notification_param = NULL, _0, _1;
	zend_long handle, notification;

	ZVAL_UNDEF(&id_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(id)
		Z_PARAM_LONG(notification)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &id, &notification_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, notification);
	phpgtk_gapplication_send_notification(&_0, id, &_1);
}

PHP_METHOD(Gtk_Gio_GApplication_GApplication, setApplicationId)
{
	zval *handle_param = NULL, *applicationId = NULL, applicationId_sub, _0;
	zend_long handle;

	ZVAL_UNDEF(&applicationId_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(applicationId)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &applicationId);
	ZVAL_LONG(&_0, handle);
	phpgtk_gapplication_set_application_id(&_0, applicationId);
}

PHP_METHOD(Gtk_Gio_GApplication_GApplication, setDefault)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gapplication_set_default(&_0);
}

PHP_METHOD(Gtk_Gio_GApplication_GApplication, setFlags)
{
	zval *handle_param = NULL, *flags_param = NULL, _0, _1;
	zend_long handle, flags;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &flags_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, flags);
	phpgtk_gapplication_set_flags(&_0, &_1);
}

PHP_METHOD(Gtk_Gio_GApplication_GApplication, setInactivityTimeout)
{
	zval *handle_param = NULL, *inactivityTimeout_param = NULL, _0, _1;
	zend_long handle, inactivityTimeout;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(inactivityTimeout)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &inactivityTimeout_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, inactivityTimeout);
	phpgtk_gapplication_set_inactivity_timeout(&_0, &_1);
}

PHP_METHOD(Gtk_Gio_GApplication_GApplication, setOptionContextDescription)
{
	zval *handle_param = NULL, *description = NULL, description_sub, _0;
	zend_long handle;

	ZVAL_UNDEF(&description_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(description)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &description);
	ZVAL_LONG(&_0, handle);
	phpgtk_gapplication_set_option_context_description(&_0, description);
}

PHP_METHOD(Gtk_Gio_GApplication_GApplication, setOptionContextParameterString)
{
	zval *handle_param = NULL, *parameterString = NULL, parameterString_sub, _0;
	zend_long handle;

	ZVAL_UNDEF(&parameterString_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(parameterString)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &parameterString);
	ZVAL_LONG(&_0, handle);
	phpgtk_gapplication_set_option_context_parameter_string(&_0, parameterString);
}

PHP_METHOD(Gtk_Gio_GApplication_GApplication, setOptionContextSummary)
{
	zval *handle_param = NULL, *summary = NULL, summary_sub, _0;
	zend_long handle;

	ZVAL_UNDEF(&summary_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(summary)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &summary);
	ZVAL_LONG(&_0, handle);
	phpgtk_gapplication_set_option_context_summary(&_0, summary);
}

PHP_METHOD(Gtk_Gio_GApplication_GApplication, setResourceBasePath)
{
	zval *handle_param = NULL, *resourcePath = NULL, resourcePath_sub, _0;
	zend_long handle;

	ZVAL_UNDEF(&resourcePath_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(resourcePath)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &resourcePath);
	ZVAL_LONG(&_0, handle);
	phpgtk_gapplication_set_resource_base_path(&_0, resourcePath);
}

PHP_METHOD(Gtk_Gio_GApplication_GApplication, setVersion)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval version;
	zval *handle_param = NULL, *version_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&version);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(version)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &version_param);
	zephir_get_strval(&version, version_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gapplication_set_version(&_0, &version);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_Gio_GApplication_GApplication, unmarkBusy)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gapplication_unmark_busy(&_0);
}

PHP_METHOD(Gtk_Gio_GApplication_GApplication, withdrawNotification)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval id;
	zval *handle_param = NULL, *id_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&id);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(id)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &id_param);
	zephir_get_strval(&id, id_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gapplication_withdraw_notification(&_0, &id);
	ZEPHIR_MM_RESTORE();
}

