
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
#include "src/gtk-window.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkWindow_GtkWindow)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkWindow, GtkWindow, gtk_gtk, gtkwindow_gtkwindow, gtk_gtk_gtkwindow_gtkwindow_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, new_)
{

	RETURN_LONG(phpgtk_gtkwindow_new());
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getDefaultIconName)
{
	zval result;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;

	ZVAL_UNDEF(&result);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&result);
	phpgtk_gtkwindow_get_default_icon_name(&result);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getToplevels)
{

	RETURN_LONG(phpgtk_gtkwindow_get_toplevels());
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, listToplevels)
{
	zval result;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;

	ZVAL_UNDEF(&result);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&result);
	phpgtk_gtkwindow_list_toplevels(&result);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setAutoStartupNotification)
{
	zval *setting_param = NULL, _0;
	zend_bool setting;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(setting)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &setting_param);
	ZVAL_BOOL(&_0, (setting ? 1 : 0));
	phpgtk_gtkwindow_set_auto_startup_notification(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setDefaultIconName)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *name_param = NULL;
	zval name;

	ZVAL_UNDEF(&name);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &name_param);
	zephir_get_strval(&name, name_param);
	phpgtk_gtkwindow_set_default_icon_name(&name);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setInteractiveDebugging)
{
	zval *enable_param = NULL, _0;
	zend_bool enable;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(enable)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &enable_param);
	ZVAL_BOOL(&_0, (enable ? 1 : 0));
	phpgtk_gtkwindow_set_interactive_debugging(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, close)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkwindow_close(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, destroy)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkwindow_destroy(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, fullscreen)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkwindow_fullscreen(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, fullscreenOnMonitor)
{
	zval *handle_param = NULL, *monitor_param = NULL, _0, _1;
	zend_long handle, monitor;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(monitor)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &monitor_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, monitor);
	phpgtk_gtkwindow_fullscreen_on_monitor(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getApplication)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwindow_get_application(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getChild)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwindow_get_child(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getDecorated)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwindow_get_decorated(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getDefaultSize)
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
	phpgtk_gtkwindow_get_default_size(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getDefaultWidget)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwindow_get_default_widget(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getDeletable)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwindow_get_deletable(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getDestroyWithParent)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwindow_get_destroy_with_parent(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getFocus)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwindow_get_focus(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getFocusVisible)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwindow_get_focus_visible(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getGroup)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwindow_get_group(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getHandleMenubarAccel)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwindow_get_handle_menubar_accel(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getHideOnClose)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwindow_get_hide_on_close(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getIconName)
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
	phpgtk_gtkwindow_get_icon_name(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getMnemonicsVisible)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwindow_get_mnemonics_visible(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getModal)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwindow_get_modal(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getResizable)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwindow_get_resizable(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getTitle)
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
	phpgtk_gtkwindow_get_title(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getTitlebar)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwindow_get_titlebar(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, getTransientFor)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkwindow_get_transient_for(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, hasGroup)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwindow_has_group(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, isActive)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwindow_is_active(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, isFullscreen)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwindow_is_fullscreen(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, isMaximized)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwindow_is_maximized(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, isSuspended)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkwindow_is_suspended(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, maximize)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkwindow_maximize(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, minimize)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkwindow_minimize(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, present)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkwindow_present(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setApplication)
{
	zval *handle_param = NULL, *application_param = NULL, _0, _1;
	zend_long handle, application;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(application)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &application_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, application);
	phpgtk_gtkwindow_set_application(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setChild)
{
	zval *handle_param = NULL, *child_param = NULL, _0, _1;
	zend_long handle, child;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &child_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	phpgtk_gtkwindow_set_child(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setDecorated)
{
	zend_bool setting;
	zval *handle_param = NULL, *setting_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(setting)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &setting_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (setting ? 1 : 0));
	phpgtk_gtkwindow_set_decorated(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setDefaultSize)
{
	zval *handle_param = NULL, *width_param = NULL, *height_param = NULL, _0, _1, _2;
	zend_long handle, width, height;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &width_param, &height_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, width);
	ZVAL_LONG(&_2, height);
	phpgtk_gtkwindow_set_default_size(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setDefaultWidget)
{
	zval *handle_param = NULL, *defaultWidget_param = NULL, _0, _1;
	zend_long handle, defaultWidget;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(defaultWidget)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &defaultWidget_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, defaultWidget);
	phpgtk_gtkwindow_set_default_widget(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setDeletable)
{
	zend_bool setting;
	zval *handle_param = NULL, *setting_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(setting)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &setting_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (setting ? 1 : 0));
	phpgtk_gtkwindow_set_deletable(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setDestroyWithParent)
{
	zend_bool setting;
	zval *handle_param = NULL, *setting_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(setting)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &setting_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (setting ? 1 : 0));
	phpgtk_gtkwindow_set_destroy_with_parent(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setDisplay)
{
	zval *handle_param = NULL, *display_param = NULL, _0, _1;
	zend_long handle, display;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(display)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &display_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, display);
	phpgtk_gtkwindow_set_display(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setFocus)
{
	zval *handle_param = NULL, *focus_param = NULL, _0, _1;
	zend_long handle, focus;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(focus)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &focus_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, focus);
	phpgtk_gtkwindow_set_focus(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setFocusVisible)
{
	zend_bool setting;
	zval *handle_param = NULL, *setting_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(setting)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &setting_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (setting ? 1 : 0));
	phpgtk_gtkwindow_set_focus_visible(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setHandleMenubarAccel)
{
	zend_bool handleMenubarAccel;
	zval *handle_param = NULL, *handleMenubarAccel_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(handleMenubarAccel)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &handleMenubarAccel_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (handleMenubarAccel ? 1 : 0));
	phpgtk_gtkwindow_set_handle_menubar_accel(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setHideOnClose)
{
	zend_bool setting;
	zval *handle_param = NULL, *setting_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(setting)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &setting_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (setting ? 1 : 0));
	phpgtk_gtkwindow_set_hide_on_close(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setIconName)
{
	zval *handle_param = NULL, *name = NULL, name_sub, _0;
	zend_long handle;

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &name);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkwindow_set_icon_name(&_0, name);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setMnemonicsVisible)
{
	zend_bool setting;
	zval *handle_param = NULL, *setting_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(setting)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &setting_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (setting ? 1 : 0));
	phpgtk_gtkwindow_set_mnemonics_visible(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setModal)
{
	zend_bool modal;
	zval *handle_param = NULL, *modal_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(modal)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &modal_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (modal ? 1 : 0));
	phpgtk_gtkwindow_set_modal(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setResizable)
{
	zend_bool resizable;
	zval *handle_param = NULL, *resizable_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(resizable)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &resizable_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (resizable ? 1 : 0));
	phpgtk_gtkwindow_set_resizable(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setStartupId)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval startupId;
	zval *handle_param = NULL, *startupId_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&startupId);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(startupId)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &startupId_param);
	zephir_get_strval(&startupId, startupId_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkwindow_set_startup_id(&_0, &startupId);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setTitle)
{
	zval *handle_param = NULL, *title = NULL, title_sub, _0;
	zend_long handle;

	ZVAL_UNDEF(&title_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(title)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &title);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkwindow_set_title(&_0, title);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setTitlebar)
{
	zval *handle_param = NULL, *titlebar_param = NULL, _0, _1;
	zend_long handle, titlebar;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(titlebar)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &titlebar_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, titlebar);
	phpgtk_gtkwindow_set_titlebar(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, setTransientFor)
{
	zval *handle_param = NULL, *parent_param = NULL, _0, _1;
	zend_long handle, parent;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(parent)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &parent_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, parent);
	phpgtk_gtkwindow_set_transient_for(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, unfullscreen)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkwindow_unfullscreen(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, unmaximize)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkwindow_unmaximize(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkWindow_GtkWindow, unminimize)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkwindow_unminimize(&_0);
}

