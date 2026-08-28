
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
#include "src/gio-gmenuitem.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"


ZEPHIR_INIT_CLASS(Gtk_Gio_GMenuItem_GMenuItem)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gio\\GMenuItem, GMenuItem, gtk, gio_gmenuitem_gmenuitem, gtk_gio_gmenuitem_gmenuitem_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gio_GMenuItem_GMenuItem, new_)
{
	zval *label = NULL, label_sub, *detailedAction = NULL, detailedAction_sub;

	ZVAL_UNDEF(&label_sub);
	ZVAL_UNDEF(&detailedAction_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(label)
		Z_PARAM_ZVAL(detailedAction)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &label, &detailedAction);
	RETURN_LONG(phpgtk_gmenuitem_new(label, detailedAction));
}

PHP_METHOD(Gtk_Gio_GMenuItem_GMenuItem, newFromModel)
{
	zval *model_param = NULL, *itemIndex_param = NULL, _0, _1;
	zend_long model, itemIndex;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(model)
		Z_PARAM_LONG(itemIndex)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &model_param, &itemIndex_param);
	ZVAL_LONG(&_0, model);
	ZVAL_LONG(&_1, itemIndex);
	RETURN_LONG(phpgtk_gmenuitem_new_from_model(&_0, &_1));
}

PHP_METHOD(Gtk_Gio_GMenuItem_GMenuItem, newSection)
{
	zend_long section;
	zval *label = NULL, label_sub, *section_param = NULL, _0;

	ZVAL_UNDEF(&label_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(label)
		Z_PARAM_LONG(section)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &label, &section_param);
	ZVAL_LONG(&_0, section);
	RETURN_LONG(phpgtk_gmenuitem_new_section(label, &_0));
}

PHP_METHOD(Gtk_Gio_GMenuItem_GMenuItem, newSubmenu)
{
	zend_long submenu;
	zval *label = NULL, label_sub, *submenu_param = NULL, _0;

	ZVAL_UNDEF(&label_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(label)
		Z_PARAM_LONG(submenu)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &label, &submenu_param);
	ZVAL_LONG(&_0, submenu);
	RETURN_LONG(phpgtk_gmenuitem_new_submenu(label, &_0));
}

PHP_METHOD(Gtk_Gio_GMenuItem_GMenuItem, getLink)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval link;
	zval *handle_param = NULL, *link_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&link);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(link)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &link_param);
	zephir_get_strval(&link, link_param);
	ZVAL_LONG(&_0, handle);
	RETURN_MM_LONG(phpgtk_gmenuitem_get_link(&_0, &link));
}

PHP_METHOD(Gtk_Gio_GMenuItem_GMenuItem, setDetailedAction)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval detailedAction;
	zval *handle_param = NULL, *detailedAction_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&detailedAction);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(detailedAction)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &detailedAction_param);
	zephir_get_strval(&detailedAction, detailedAction_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gmenuitem_set_detailed_action(&_0, &detailedAction);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_Gio_GMenuItem_GMenuItem, setIcon)
{
	zval *handle_param = NULL, *icon_param = NULL, _0, _1;
	zend_long handle, icon;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(icon)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &icon_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, icon);
	phpgtk_gmenuitem_set_icon(&_0, &_1);
}

PHP_METHOD(Gtk_Gio_GMenuItem_GMenuItem, setLabel)
{
	zval *handle_param = NULL, *label = NULL, label_sub, _0;
	zend_long handle;

	ZVAL_UNDEF(&label_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(label)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &label);
	ZVAL_LONG(&_0, handle);
	phpgtk_gmenuitem_set_label(&_0, label);
}

PHP_METHOD(Gtk_Gio_GMenuItem_GMenuItem, setLink)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval link;
	zval *handle_param = NULL, *link_param = NULL, *model_param = NULL, _0, _1;
	zend_long handle, model;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&link);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(link)
		Z_PARAM_LONG(model)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &handle_param, &link_param, &model_param);
	zephir_get_strval(&link, link_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, model);
	phpgtk_gmenuitem_set_link(&_0, &link, &_1);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_Gio_GMenuItem_GMenuItem, setSection)
{
	zval *handle_param = NULL, *section_param = NULL, _0, _1;
	zend_long handle, section;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(section)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &section_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, section);
	phpgtk_gmenuitem_set_section(&_0, &_1);
}

PHP_METHOD(Gtk_Gio_GMenuItem_GMenuItem, setSubmenu)
{
	zval *handle_param = NULL, *submenu_param = NULL, _0, _1;
	zend_long handle, submenu;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(submenu)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &submenu_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, submenu);
	phpgtk_gmenuitem_set_submenu(&_0, &_1);
}

