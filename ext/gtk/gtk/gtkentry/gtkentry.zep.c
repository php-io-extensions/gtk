
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
#include "src/gtk-entry.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkEntry_GtkEntry)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkEntry, GtkEntry, gtk_gtk, gtkentry_gtkentry, gtk_gtk_gtkentry_gtkentry_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, new_)
{

	RETURN_LONG(phpgtk_gtkentry_new());
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, newWithBuffer)
{
	zval *buffer_param = NULL, _0;
	zend_long buffer;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(buffer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &buffer_param);
	ZVAL_LONG(&_0, buffer);
	RETURN_LONG(phpgtk_gtkentry_new_with_buffer(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getActivatesDefault)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkentry_get_activates_default(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getAlignment)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_DOUBLE(phpgtk_gtkentry_get_alignment(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getBuffer)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkentry_get_buffer(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getCurrentIconDragSource)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkentry_get_current_icon_drag_source(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getExtraMenu)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkentry_get_extra_menu(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getHasFrame)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkentry_get_has_frame(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getIconActivatable)
{
	zval *handle_param = NULL, *iconPos_param = NULL, _0, _1;
	zend_long handle, iconPos, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(iconPos)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &iconPos_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, iconPos);
	r = phpgtk_gtkentry_get_icon_activatable(&_0, &_1);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getIconArea)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *handle_param = NULL, *iconPos_param = NULL, result, _0, _1;
	zend_long handle, iconPos;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(iconPos)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &iconPos_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, iconPos);
	phpgtk_gtkentry_get_icon_area(&result, &_0, &_1);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getIconAtPos)
{
	zval *handle_param = NULL, *x_param = NULL, *y_param = NULL, _0, _1, _2;
	zend_long handle, x, y;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(x)
		Z_PARAM_LONG(y)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &x_param, &y_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, x);
	ZVAL_LONG(&_2, y);
	RETURN_LONG(phpgtk_gtkentry_get_icon_at_pos(&_0, &_1, &_2));
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getIconGicon)
{
	zval *handle_param = NULL, *iconPos_param = NULL, _0, _1;
	zend_long handle, iconPos;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(iconPos)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &iconPos_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, iconPos);
	RETURN_LONG(phpgtk_gtkentry_get_icon_gicon(&_0, &_1));
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getIconName)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *handle_param = NULL, *iconPos_param = NULL, result, _0, _1;
	zend_long handle, iconPos;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(iconPos)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &iconPos_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, iconPos);
	phpgtk_gtkentry_get_icon_name(&result, &_0, &_1);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getIconPaintable)
{
	zval *handle_param = NULL, *iconPos_param = NULL, _0, _1;
	zend_long handle, iconPos;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(iconPos)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &iconPos_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, iconPos);
	RETURN_LONG(phpgtk_gtkentry_get_icon_paintable(&_0, &_1));
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getIconSensitive)
{
	zval *handle_param = NULL, *iconPos_param = NULL, _0, _1;
	zend_long handle, iconPos, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(iconPos)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &iconPos_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, iconPos);
	r = phpgtk_gtkentry_get_icon_sensitive(&_0, &_1);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getIconStorageType)
{
	zval *handle_param = NULL, *iconPos_param = NULL, _0, _1;
	zend_long handle, iconPos;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(iconPos)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &iconPos_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, iconPos);
	RETURN_LONG(phpgtk_gtkentry_get_icon_storage_type(&_0, &_1));
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getIconTooltipMarkup)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *handle_param = NULL, *iconPos_param = NULL, result, _0, _1;
	zend_long handle, iconPos;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(iconPos)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &iconPos_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, iconPos);
	phpgtk_gtkentry_get_icon_tooltip_markup(&result, &_0, &_1);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getIconTooltipText)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *handle_param = NULL, *iconPos_param = NULL, result, _0, _1;
	zend_long handle, iconPos;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(iconPos)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &iconPos_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, iconPos);
	phpgtk_gtkentry_get_icon_tooltip_text(&result, &_0, &_1);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getInputHints)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkentry_get_input_hints(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getInputPurpose)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkentry_get_input_purpose(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getInvisibleChar)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkentry_get_invisible_char(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getMaxLength)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkentry_get_max_length(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getOverwriteMode)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkentry_get_overwrite_mode(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getPlaceholderText)
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
	phpgtk_gtkentry_get_placeholder_text(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getProgressFraction)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_DOUBLE(phpgtk_gtkentry_get_progress_fraction(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getProgressPulseStep)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_DOUBLE(phpgtk_gtkentry_get_progress_pulse_step(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getTextLength)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkentry_get_text_length(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getVisibility)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkentry_get_visibility(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, grabFocusWithoutSelecting)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkentry_grab_focus_without_selecting(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, progressPulse)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkentry_progress_pulse(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, resetImContext)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkentry_reset_im_context(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setActivatesDefault)
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
	phpgtk_gtkentry_set_activates_default(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setAlignment)
{
	double xalign;
	zval *handle_param = NULL, *xalign_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(xalign)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &xalign_param);
	xalign = zephir_get_doubleval(xalign_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_DOUBLE(&_1, xalign);
	phpgtk_gtkentry_set_alignment(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setBuffer)
{
	zval *handle_param = NULL, *buffer_param = NULL, _0, _1;
	zend_long handle, buffer;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(buffer)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &buffer_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, buffer);
	phpgtk_gtkentry_set_buffer(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setExtraMenu)
{
	zval *handle_param = NULL, *model_param = NULL, _0, _1;
	zend_long handle, model;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(model)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &model_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, model);
	phpgtk_gtkentry_set_extra_menu(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setHasFrame)
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
	phpgtk_gtkentry_set_has_frame(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setIconActivatable)
{
	zend_bool activatable;
	zval *handle_param = NULL, *iconPos_param = NULL, *activatable_param = NULL, _0, _1, _2;
	zend_long handle, iconPos;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(iconPos)
		Z_PARAM_BOOL(activatable)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &iconPos_param, &activatable_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, iconPos);
	ZVAL_BOOL(&_2, (activatable ? 1 : 0));
	phpgtk_gtkentry_set_icon_activatable(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setIconFromGicon)
{
	zval *handle_param = NULL, *iconPos_param = NULL, *icon_param = NULL, _0, _1, _2;
	zend_long handle, iconPos, icon;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(iconPos)
		Z_PARAM_LONG(icon)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &iconPos_param, &icon_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, iconPos);
	ZVAL_LONG(&_2, icon);
	phpgtk_gtkentry_set_icon_from_gicon(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setIconFromIconName)
{
	zval *handle_param = NULL, *iconPos_param = NULL, *iconName = NULL, iconName_sub, _0, _1;
	zend_long handle, iconPos;

	ZVAL_UNDEF(&iconName_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(iconPos)
		Z_PARAM_ZVAL(iconName)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &iconPos_param, &iconName);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, iconPos);
	phpgtk_gtkentry_set_icon_from_icon_name(&_0, &_1, iconName);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setIconFromPaintable)
{
	zval *handle_param = NULL, *iconPos_param = NULL, *paintable_param = NULL, _0, _1, _2;
	zend_long handle, iconPos, paintable;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(iconPos)
		Z_PARAM_LONG(paintable)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &iconPos_param, &paintable_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, iconPos);
	ZVAL_LONG(&_2, paintable);
	phpgtk_gtkentry_set_icon_from_paintable(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setIconSensitive)
{
	zend_bool sensitive;
	zval *handle_param = NULL, *iconPos_param = NULL, *sensitive_param = NULL, _0, _1, _2;
	zend_long handle, iconPos;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(iconPos)
		Z_PARAM_BOOL(sensitive)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &iconPos_param, &sensitive_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, iconPos);
	ZVAL_BOOL(&_2, (sensitive ? 1 : 0));
	phpgtk_gtkentry_set_icon_sensitive(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setIconTooltipMarkup)
{
	zval *handle_param = NULL, *iconPos_param = NULL, *tooltip = NULL, tooltip_sub, _0, _1;
	zend_long handle, iconPos;

	ZVAL_UNDEF(&tooltip_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(iconPos)
		Z_PARAM_ZVAL(tooltip)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &iconPos_param, &tooltip);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, iconPos);
	phpgtk_gtkentry_set_icon_tooltip_markup(&_0, &_1, tooltip);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setIconTooltipText)
{
	zval *handle_param = NULL, *iconPos_param = NULL, *tooltip = NULL, tooltip_sub, _0, _1;
	zend_long handle, iconPos;

	ZVAL_UNDEF(&tooltip_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(iconPos)
		Z_PARAM_ZVAL(tooltip)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &iconPos_param, &tooltip);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, iconPos);
	phpgtk_gtkentry_set_icon_tooltip_text(&_0, &_1, tooltip);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setInputHints)
{
	zval *handle_param = NULL, *hints_param = NULL, _0, _1;
	zend_long handle, hints;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(hints)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &hints_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, hints);
	phpgtk_gtkentry_set_input_hints(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setInputPurpose)
{
	zval *handle_param = NULL, *purpose_param = NULL, _0, _1;
	zend_long handle, purpose;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(purpose)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &purpose_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, purpose);
	phpgtk_gtkentry_set_input_purpose(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setInvisibleChar)
{
	zval *handle_param = NULL, *ch_param = NULL, _0, _1;
	zend_long handle, ch;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(ch)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &ch_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, ch);
	phpgtk_gtkentry_set_invisible_char(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setMaxLength)
{
	zval *handle_param = NULL, *max_param = NULL, _0, _1;
	zend_long handle, max;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(max)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &max_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, max);
	phpgtk_gtkentry_set_max_length(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setOverwriteMode)
{
	zend_bool overwrite;
	zval *handle_param = NULL, *overwrite_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(overwrite)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &overwrite_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (overwrite ? 1 : 0));
	phpgtk_gtkentry_set_overwrite_mode(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setPlaceholderText)
{
	zval *handle_param = NULL, *text = NULL, text_sub, _0;
	zend_long handle;

	ZVAL_UNDEF(&text_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(text)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &text);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkentry_set_placeholder_text(&_0, text);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setProgressFraction)
{
	double fraction;
	zval *handle_param = NULL, *fraction_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(fraction)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &fraction_param);
	fraction = zephir_get_doubleval(fraction_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_DOUBLE(&_1, fraction);
	phpgtk_gtkentry_set_progress_fraction(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setProgressPulseStep)
{
	double fraction;
	zval *handle_param = NULL, *fraction_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(fraction)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &fraction_param);
	fraction = zephir_get_doubleval(fraction_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_DOUBLE(&_1, fraction);
	phpgtk_gtkentry_set_progress_pulse_step(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setVisibility)
{
	zend_bool visible;
	zval *handle_param = NULL, *visible_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(visible)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &visible_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (visible ? 1 : 0));
	phpgtk_gtkentry_set_visibility(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, unsetInvisibleChar)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkentry_unset_invisible_char(&_0);
}

