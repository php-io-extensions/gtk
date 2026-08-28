
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
#include "src/gtk-application.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkApplication_GtkApplication)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkApplication, GtkApplication, gtk_gtk, gtkapplication_gtkapplication, gtk_gtk_gtkapplication_gtkapplication_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkApplication_GtkApplication, new_)
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
	RETURN_LONG(phpgtk_gtkapplication_new(applicationId, &_0));
}

PHP_METHOD(Gtk_Gtk_GtkApplication_GtkApplication, addWindow)
{
	zval *handle_param = NULL, *window_param = NULL, _0, _1;
	zend_long handle, window;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(window)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &window_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, window);
	phpgtk_gtkapplication_add_window(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkApplication_GtkApplication, getAccelsForAction)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval detailedActionName;
	zval *handle_param = NULL, *detailedActionName_param = NULL, result, _0;
	zend_long handle;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&detailedActionName);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(detailedActionName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &detailedActionName_param);
	zephir_get_strval(&detailedActionName, detailedActionName_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkapplication_get_accels_for_action(&result, &_0, &detailedActionName);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkApplication_GtkApplication, getActionsForAccel)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval accel;
	zval *handle_param = NULL, *accel_param = NULL, result, _0;
	zend_long handle;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&accel);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(accel)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &accel_param);
	zephir_get_strval(&accel, accel_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkapplication_get_actions_for_accel(&result, &_0, &accel);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkApplication_GtkApplication, getActiveWindow)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkapplication_get_active_window(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkApplication_GtkApplication, getMenuById)
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
	RETURN_MM_LONG(phpgtk_gtkapplication_get_menu_by_id(&_0, &id));
}

PHP_METHOD(Gtk_Gtk_GtkApplication_GtkApplication, getMenubar)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkapplication_get_menubar(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkApplication_GtkApplication, getWindowById)
{
	zval *handle_param = NULL, *id_param = NULL, _0, _1;
	zend_long handle, id;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(id)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &id_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, id);
	RETURN_LONG(phpgtk_gtkapplication_get_window_by_id(&_0, &_1));
}

PHP_METHOD(Gtk_Gtk_GtkApplication_GtkApplication, getWindows)
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
	phpgtk_gtkapplication_get_windows(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkApplication_GtkApplication, inhibit)
{
	zval *handle_param = NULL, *window_param = NULL, *flags_param = NULL, *reason = NULL, reason_sub, _0, _1, _2;
	zend_long handle, window, flags;

	ZVAL_UNDEF(&reason_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(window)
		Z_PARAM_LONG(flags)
		Z_PARAM_ZVAL(reason)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &handle_param, &window_param, &flags_param, &reason);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, window);
	ZVAL_LONG(&_2, flags);
	RETURN_LONG(phpgtk_gtkapplication_inhibit(&_0, &_1, &_2, reason));
}

PHP_METHOD(Gtk_Gtk_GtkApplication_GtkApplication, listActionDescriptions)
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
	phpgtk_gtkapplication_list_action_descriptions(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkApplication_GtkApplication, removeWindow)
{
	zval *handle_param = NULL, *window_param = NULL, _0, _1;
	zend_long handle, window;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(window)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &window_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, window);
	phpgtk_gtkapplication_remove_window(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkApplication_GtkApplication, setAccelsForAction)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval accels;
	zval detailedActionName;
	zval *handle_param = NULL, *detailedActionName_param = NULL, *accels_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&detailedActionName);
	ZVAL_UNDEF(&accels);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(detailedActionName)
		Z_PARAM_ARRAY(accels)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &handle_param, &detailedActionName_param, &accels_param);
	zephir_get_strval(&detailedActionName, detailedActionName_param);
	zephir_get_arrval(&accels, accels_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkapplication_set_accels_for_action(&_0, &detailedActionName, &accels);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_Gtk_GtkApplication_GtkApplication, setMenubar)
{
	zval *handle_param = NULL, *menubar_param = NULL, _0, _1;
	zend_long handle, menubar;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(menubar)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &menubar_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, menubar);
	phpgtk_gtkapplication_set_menubar(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkApplication_GtkApplication, uninhibit)
{
	zval *handle_param = NULL, *cookie_param = NULL, _0, _1;
	zend_long handle, cookie;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(cookie)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &cookie_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, cookie);
	phpgtk_gtkapplication_uninhibit(&_0, &_1);
}

