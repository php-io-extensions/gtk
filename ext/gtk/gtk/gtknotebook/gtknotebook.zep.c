
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
#include "src/gtk-notebook.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/memory.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkNotebook_GtkNotebook)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkNotebook, GtkNotebook, gtk_gtk, gtknotebook_gtknotebook, gtk_gtk_gtknotebook_gtknotebook_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, new_)
{

	RETURN_LONG(phpgtk_gtknotebook_new());
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, appendPage)
{
	zval *handle_param = NULL, *child_param = NULL, *tabLabel_param = NULL, _0, _1, _2;
	zend_long handle, child, tabLabel;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
		Z_PARAM_LONG(tabLabel)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &child_param, &tabLabel_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	ZVAL_LONG(&_2, tabLabel);
	RETURN_LONG(phpgtk_gtknotebook_append_page(&_0, &_1, &_2));
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, appendPageMenu)
{
	zval *handle_param = NULL, *child_param = NULL, *tabLabel_param = NULL, *menuLabel_param = NULL, _0, _1, _2, _3;
	zend_long handle, child, tabLabel, menuLabel;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
		Z_PARAM_LONG(tabLabel)
		Z_PARAM_LONG(menuLabel)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &handle_param, &child_param, &tabLabel_param, &menuLabel_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	ZVAL_LONG(&_2, tabLabel);
	ZVAL_LONG(&_3, menuLabel);
	RETURN_LONG(phpgtk_gtknotebook_append_page_menu(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, detachTab)
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
	phpgtk_gtknotebook_detach_tab(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getActionWidget)
{
	zval *handle_param = NULL, *packType_param = NULL, _0, _1;
	zend_long handle, packType;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(packType)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &packType_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, packType);
	RETURN_LONG(phpgtk_gtknotebook_get_action_widget(&_0, &_1));
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getCurrentPage)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtknotebook_get_current_page(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getGroupName)
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
	phpgtk_gtknotebook_get_group_name(&result, &_0);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getMenuLabel)
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
	RETURN_LONG(phpgtk_gtknotebook_get_menu_label(&_0, &_1));
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getMenuLabelText)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *handle_param = NULL, *child_param = NULL, result, _0, _1;
	zend_long handle, child;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &child_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	phpgtk_gtknotebook_get_menu_label_text(&result, &_0, &_1);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getNPages)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtknotebook_get_n_pages(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getNthPage)
{
	zval *handle_param = NULL, *pageNum_param = NULL, _0, _1;
	zend_long handle, pageNum;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(pageNum)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &pageNum_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, pageNum);
	RETURN_LONG(phpgtk_gtknotebook_get_nth_page(&_0, &_1));
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getPage)
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
	RETURN_LONG(phpgtk_gtknotebook_get_page(&_0, &_1));
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getPages)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtknotebook_get_pages(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getScrollable)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtknotebook_get_scrollable(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getShowBorder)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtknotebook_get_show_border(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getShowTabs)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtknotebook_get_show_tabs(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getTabDetachable)
{
	zval *handle_param = NULL, *child_param = NULL, _0, _1;
	zend_long handle, child, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &child_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	r = phpgtk_gtknotebook_get_tab_detachable(&_0, &_1);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getTabLabel)
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
	RETURN_LONG(phpgtk_gtknotebook_get_tab_label(&_0, &_1));
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getTabLabelText)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *handle_param = NULL, *child_param = NULL, result, _0, _1;
	zend_long handle, child;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &handle_param, &child_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	phpgtk_gtknotebook_get_tab_label_text(&result, &_0, &_1);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getTabPos)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtknotebook_get_tab_pos(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, getTabReorderable)
{
	zval *handle_param = NULL, *child_param = NULL, _0, _1;
	zend_long handle, child, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &child_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	r = phpgtk_gtknotebook_get_tab_reorderable(&_0, &_1);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, insertPage)
{
	zval *handle_param = NULL, *child_param = NULL, *tabLabel_param = NULL, *position_param = NULL, _0, _1, _2, _3;
	zend_long handle, child, tabLabel, position;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
		Z_PARAM_LONG(tabLabel)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &handle_param, &child_param, &tabLabel_param, &position_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	ZVAL_LONG(&_2, tabLabel);
	ZVAL_LONG(&_3, position);
	RETURN_LONG(phpgtk_gtknotebook_insert_page(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, insertPageMenu)
{
	zval *handle_param = NULL, *child_param = NULL, *tabLabel_param = NULL, *menuLabel_param = NULL, *position_param = NULL, _0, _1, _2, _3, _4;
	zend_long handle, child, tabLabel, menuLabel, position;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZEND_PARSE_PARAMETERS_START(5, 5)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
		Z_PARAM_LONG(tabLabel)
		Z_PARAM_LONG(menuLabel)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(5, 0, &handle_param, &child_param, &tabLabel_param, &menuLabel_param, &position_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	ZVAL_LONG(&_2, tabLabel);
	ZVAL_LONG(&_3, menuLabel);
	ZVAL_LONG(&_4, position);
	RETURN_LONG(phpgtk_gtknotebook_insert_page_menu(&_0, &_1, &_2, &_3, &_4));
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, nextPage)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtknotebook_next_page(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, pageNum)
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
	RETURN_LONG(phpgtk_gtknotebook_page_num(&_0, &_1));
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, popupDisable)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtknotebook_popup_disable(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, popupEnable)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtknotebook_popup_enable(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, prependPage)
{
	zval *handle_param = NULL, *child_param = NULL, *tabLabel_param = NULL, _0, _1, _2;
	zend_long handle, child, tabLabel;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
		Z_PARAM_LONG(tabLabel)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &child_param, &tabLabel_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	ZVAL_LONG(&_2, tabLabel);
	RETURN_LONG(phpgtk_gtknotebook_prepend_page(&_0, &_1, &_2));
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, prependPageMenu)
{
	zval *handle_param = NULL, *child_param = NULL, *tabLabel_param = NULL, *menuLabel_param = NULL, _0, _1, _2, _3;
	zend_long handle, child, tabLabel, menuLabel;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
		Z_PARAM_LONG(tabLabel)
		Z_PARAM_LONG(menuLabel)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(4, 0, &handle_param, &child_param, &tabLabel_param, &menuLabel_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	ZVAL_LONG(&_2, tabLabel);
	ZVAL_LONG(&_3, menuLabel);
	RETURN_LONG(phpgtk_gtknotebook_prepend_page_menu(&_0, &_1, &_2, &_3));
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, prevPage)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtknotebook_prev_page(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, removePage)
{
	zval *handle_param = NULL, *pageNum_param = NULL, _0, _1;
	zend_long handle, pageNum;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(pageNum)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &pageNum_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, pageNum);
	phpgtk_gtknotebook_remove_page(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, reorderChild)
{
	zval *handle_param = NULL, *child_param = NULL, *position_param = NULL, _0, _1, _2;
	zend_long handle, child, position;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &child_param, &position_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	ZVAL_LONG(&_2, position);
	phpgtk_gtknotebook_reorder_child(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, setActionWidget)
{
	zval *handle_param = NULL, *widget_param = NULL, *packType_param = NULL, _0, _1, _2;
	zend_long handle, widget, packType;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(widget)
		Z_PARAM_LONG(packType)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &widget_param, &packType_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, widget);
	ZVAL_LONG(&_2, packType);
	phpgtk_gtknotebook_set_action_widget(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, setCurrentPage)
{
	zval *handle_param = NULL, *pageNum_param = NULL, _0, _1;
	zend_long handle, pageNum;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(pageNum)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &pageNum_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, pageNum);
	phpgtk_gtknotebook_set_current_page(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, setGroupName)
{
	zval *handle_param = NULL, *groupName = NULL, groupName_sub, _0;
	zend_long handle;

	ZVAL_UNDEF(&groupName_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_ZVAL(groupName)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &groupName);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtknotebook_set_group_name(&_0, groupName);
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, setMenuLabel)
{
	zval *handle_param = NULL, *child_param = NULL, *menuLabel_param = NULL, _0, _1, _2;
	zend_long handle, child, menuLabel;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
		Z_PARAM_LONG(menuLabel)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &child_param, &menuLabel_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	ZVAL_LONG(&_2, menuLabel);
	phpgtk_gtknotebook_set_menu_label(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, setMenuLabelText)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval menuText;
	zval *handle_param = NULL, *child_param = NULL, *menuText_param = NULL, _0, _1;
	zend_long handle, child;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&menuText);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
		Z_PARAM_STR(menuText)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &handle_param, &child_param, &menuText_param);
	zephir_get_strval(&menuText, menuText_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	phpgtk_gtknotebook_set_menu_label_text(&_0, &_1, &menuText);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, setScrollable)
{
	zend_bool scrollable;
	zval *handle_param = NULL, *scrollable_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(scrollable)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &scrollable_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (scrollable ? 1 : 0));
	phpgtk_gtknotebook_set_scrollable(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, setShowBorder)
{
	zend_bool showBorder;
	zval *handle_param = NULL, *showBorder_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(showBorder)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &showBorder_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (showBorder ? 1 : 0));
	phpgtk_gtknotebook_set_show_border(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, setShowTabs)
{
	zend_bool showTabs;
	zval *handle_param = NULL, *showTabs_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(showTabs)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &showTabs_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (showTabs ? 1 : 0));
	phpgtk_gtknotebook_set_show_tabs(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, setTabDetachable)
{
	zend_bool detachable;
	zval *handle_param = NULL, *child_param = NULL, *detachable_param = NULL, _0, _1, _2;
	zend_long handle, child;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
		Z_PARAM_BOOL(detachable)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &child_param, &detachable_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	ZVAL_BOOL(&_2, (detachable ? 1 : 0));
	phpgtk_gtknotebook_set_tab_detachable(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, setTabLabel)
{
	zval *handle_param = NULL, *child_param = NULL, *tabLabel_param = NULL, _0, _1, _2;
	zend_long handle, child, tabLabel;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
		Z_PARAM_LONG(tabLabel)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &child_param, &tabLabel_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	ZVAL_LONG(&_2, tabLabel);
	phpgtk_gtknotebook_set_tab_label(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, setTabLabelText)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval tabText;
	zval *handle_param = NULL, *child_param = NULL, *tabText_param = NULL, _0, _1;
	zend_long handle, child;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&tabText);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
		Z_PARAM_STR(tabText)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &handle_param, &child_param, &tabText_param);
	zephir_get_strval(&tabText, tabText_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	phpgtk_gtknotebook_set_tab_label_text(&_0, &_1, &tabText);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, setTabPos)
{
	zval *handle_param = NULL, *pos_param = NULL, _0, _1;
	zend_long handle, pos;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(pos)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &pos_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, pos);
	phpgtk_gtknotebook_set_tab_pos(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkNotebook_GtkNotebook, setTabReorderable)
{
	zend_bool reorderable;
	zval *handle_param = NULL, *child_param = NULL, *reorderable_param = NULL, _0, _1, _2;
	zend_long handle, child;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(child)
		Z_PARAM_BOOL(reorderable)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &child_param, &reorderable_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, child);
	ZVAL_BOOL(&_2, (reorderable ? 1 : 0));
	phpgtk_gtknotebook_set_tab_reorderable(&_0, &_1, &_2);
}

