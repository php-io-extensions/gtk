
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
#include "src/gtk-stack.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkStack_GtkStack)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkStack, GtkStack, gtk_gtk, gtkstack_gtkstack, gtk_gtk_gtkstack_gtkstack_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, new_)
{

	RETURN_LONG(phpgtk_gtkstack_new());
}

PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, addChild)
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
	RETURN_LONG(phpgtk_gtkstack_add_child(&_0, &_1));
}

PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, addNamed)
{
	zval *handle_param = NULL, *child_param = NULL, *name = NULL, name_sub, _0, _1;
	zend_long handle, child;

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
		Z_PARAM_ZVAL(name)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &child_param, &name);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	RETURN_LONG(phpgtk_gtkstack_add_named(&_0, &_1, name));
}

PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, addTitled)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval title;
	zval *handle_param = NULL, *child_param = NULL, *name = NULL, name_sub, *title_param = NULL, _0, _1;
	zend_long handle, child;

	ZVAL_UNDEF(&name_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&title);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
		Z_PARAM_ZVAL(name)
		Z_PARAM_STR(title)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 4, 0, &handle_param, &child_param, &name, &title_param);
	zephir_get_strval(&title, title_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	RETURN_MM_LONG(phpgtk_gtkstack_add_titled(&_0, &_1, name, &title));
}

PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, getChildByName)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name;
	zval *handle_param = NULL, *name_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&name);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &name_param);
	zephir_get_strval(&name, name_param);
	ZVAL_LONG(&_0, handle);
	RETURN_MM_LONG(phpgtk_gtkstack_get_child_by_name(&_0, &name));
}

PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, getHhomogeneous)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkstack_get_hhomogeneous(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, getInterpolateSize)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkstack_get_interpolate_size(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, getPage)
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
	RETURN_LONG(phpgtk_gtkstack_get_page(&_0, &_1));
}

PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, getPages)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkstack_get_pages(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, getTransitionDuration)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkstack_get_transition_duration(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, getTransitionRunning)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkstack_get_transition_running(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, getTransitionType)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkstack_get_transition_type(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, getVhomogeneous)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtkstack_get_vhomogeneous(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, getVisibleChild)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtkstack_get_visible_child(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, getVisibleChildName)
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
	phpgtk_gtkstack_get_visible_child_name(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, remove)
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
	phpgtk_gtkstack_remove(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, setHhomogeneous)
{
	zend_bool hhomogeneous;
	zval *handle_param = NULL, *hhomogeneous_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(hhomogeneous)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &hhomogeneous_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (hhomogeneous ? 1 : 0));
	phpgtk_gtkstack_set_hhomogeneous(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, setInterpolateSize)
{
	zend_bool interpolateSize;
	zval *handle_param = NULL, *interpolateSize_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(interpolateSize)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &interpolateSize_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (interpolateSize ? 1 : 0));
	phpgtk_gtkstack_set_interpolate_size(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, setTransitionDuration)
{
	zval *handle_param = NULL, *duration_param = NULL, _0, _1;
	zend_long handle, duration;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(duration)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &duration_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, duration);
	phpgtk_gtkstack_set_transition_duration(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, setTransitionType)
{
	zval *handle_param = NULL, *transition_param = NULL, _0, _1;
	zend_long handle, transition;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(transition)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &transition_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, transition);
	phpgtk_gtkstack_set_transition_type(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, setVhomogeneous)
{
	zend_bool vhomogeneous;
	zval *handle_param = NULL, *vhomogeneous_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(vhomogeneous)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &vhomogeneous_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (vhomogeneous ? 1 : 0));
	phpgtk_gtkstack_set_vhomogeneous(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, setVisibleChild)
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
	phpgtk_gtkstack_set_visible_child(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, setVisibleChildFull)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name;
	zval *handle_param = NULL, *name_param = NULL, *transition_param = NULL, _0, _1;
	zend_long handle, transition;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&name);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(name)
		Z_PARAM_LONG(transition)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &handle_param, &name_param, &transition_param);
	zephir_get_strval(&name, name_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, transition);
	phpgtk_gtkstack_set_visible_child_full(&_0, &name, &_1);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, setVisibleChildName)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval name;
	zval *handle_param = NULL, *name_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&name);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &name_param);
	zephir_get_strval(&name, name_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtkstack_set_visible_child_name(&_0, &name);
	ZEPHIR_MM_RESTORE();
}

