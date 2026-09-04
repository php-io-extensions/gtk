
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
#include "src/gtk-text-buffer.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkTextBuffer, GtkTextBuffer, gtk_gtk, gtktextbuffer_gtktextbuffer, gtk_gtk_gtktextbuffer_gtktextbuffer_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, new_)
{
	zval *table_param = NULL, _0;
	zend_long table;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(table)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &table_param);
	ZVAL_LONG(&_0, table);
	RETURN_LONG(phpgtk_gtktextbuffer_new(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, addSelectionClipboard)
{
	zval *handle_param = NULL, *clipboard_param = NULL, _0, _1;
	zend_long handle, clipboard;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(clipboard)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &clipboard_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, clipboard);
	phpgtk_gtktextbuffer_add_selection_clipboard(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, beginIrreversibleAction)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtktextbuffer_begin_irreversible_action(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, beginUserAction)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtktextbuffer_begin_user_action(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, copyClipboard)
{
	zval *handle_param = NULL, *clipboard_param = NULL, _0, _1;
	zend_long handle, clipboard;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(clipboard)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &clipboard_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, clipboard);
	phpgtk_gtktextbuffer_copy_clipboard(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, cutClipboard)
{
	zend_bool defaultEditable;
	zval *handle_param = NULL, *clipboard_param = NULL, *defaultEditable_param = NULL, _0, _1, _2;
	zend_long handle, clipboard;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(clipboard)
		Z_PARAM_BOOL(defaultEditable)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &clipboard_param, &defaultEditable_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, clipboard);
	ZVAL_BOOL(&_2, (defaultEditable ? 1 : 0));
	phpgtk_gtktextbuffer_cut_clipboard(&_0, &_1, &_2);
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, deleteMark)
{
	zval *handle_param = NULL, *mark_param = NULL, _0, _1;
	zend_long handle, mark;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(mark)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &mark_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, mark);
	phpgtk_gtktextbuffer_delete_mark(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, deleteMarkByName)
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
	phpgtk_gtktextbuffer_delete_mark_by_name(&_0, &name);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, deleteSelection)
{
	zend_bool interactive, defaultEditable;
	zval *handle_param = NULL, *interactive_param = NULL, *defaultEditable_param = NULL, _0, _1, _2;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(interactive)
		Z_PARAM_BOOL(defaultEditable)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(3, 0, &handle_param, &interactive_param, &defaultEditable_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (interactive ? 1 : 0));
	ZVAL_BOOL(&_2, (defaultEditable ? 1 : 0));
	r = phpgtk_gtktextbuffer_delete_selection(&_0, &_1, &_2);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, endIrreversibleAction)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtktextbuffer_end_irreversible_action(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, endUserAction)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtktextbuffer_end_user_action(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getCanRedo)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtktextbuffer_get_can_redo(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getCanUndo)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtktextbuffer_get_can_undo(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getCharCount)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtktextbuffer_get_char_count(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getEnableUndo)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtktextbuffer_get_enable_undo(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getHasSelection)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtktextbuffer_get_has_selection(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getInsert)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtktextbuffer_get_insert(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getLineCount)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtktextbuffer_get_line_count(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getMark)
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
	RETURN_MM_LONG(phpgtk_gtktextbuffer_get_mark(&_0, &name));
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getMaxUndoLevels)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtktextbuffer_get_max_undo_levels(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getModified)
{
	zval *handle_param = NULL, _0;
	zend_long handle, r = 0;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	r = phpgtk_gtktextbuffer_get_modified(&_0);
	RETURN_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getSelectionBound)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtktextbuffer_get_selection_bound(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getTagTable)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtktextbuffer_get_tag_table(&_0));
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, getText)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool includeHiddenChars;
	zval *handle_param = NULL, *startOffset_param = NULL, *endOffset_param = NULL, *includeHiddenChars_param = NULL, result, _0, _1, _2, _3;
	zend_long handle, startOffset, endOffset;

	ZVAL_UNDEF(&result);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(startOffset)
		Z_PARAM_LONG(endOffset)
		Z_PARAM_BOOL(includeHiddenChars)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 4, 0, &handle_param, &startOffset_param, &endOffset_param, &includeHiddenChars_param);
	ZEPHIR_INIT_VAR(&result);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, startOffset);
	ZVAL_LONG(&_2, endOffset);
	ZVAL_BOOL(&_3, (includeHiddenChars ? 1 : 0));
	phpgtk_gtktextbuffer_get_text(&result, &_0, &_1, &_2, &_3);
	RETURN_CCTOR(&result);
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, insertAtCursor)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval text;
	zval *handle_param = NULL, *text_param = NULL, *len_param = NULL, _0, _1;
	zend_long handle, len;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&text);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(text)
		Z_PARAM_LONG(len)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &handle_param, &text_param, &len_param);
	zephir_get_strval(&text, text_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, len);
	phpgtk_gtktextbuffer_insert_at_cursor(&_0, &text, &_1);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, insertInteractiveAtCursor)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool defaultEditable;
	zval text;
	zval *handle_param = NULL, *text_param = NULL, *len_param = NULL, *defaultEditable_param = NULL, _0, _1, _2;
	zend_long handle, len, r = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&text);
	ZEND_PARSE_PARAMETERS_START(4, 4)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(text)
		Z_PARAM_LONG(len)
		Z_PARAM_BOOL(defaultEditable)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 4, 0, &handle_param, &text_param, &len_param, &defaultEditable_param);
	zephir_get_strval(&text, text_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, len);
	ZVAL_BOOL(&_2, (defaultEditable ? 1 : 0));
	r = phpgtk_gtktextbuffer_insert_interactive_at_cursor(&_0, &text, &_1, &_2);
	RETURN_MM_BOOL(r == 1);
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, redo)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtktextbuffer_redo(&_0);
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, removeCommitNotify)
{
	zval *handle_param = NULL, *commitNotifyHandler_param = NULL, _0, _1;
	zend_long handle, commitNotifyHandler;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(commitNotifyHandler)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &commitNotifyHandler_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, commitNotifyHandler);
	phpgtk_gtktextbuffer_remove_commit_notify(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, removeSelectionClipboard)
{
	zval *handle_param = NULL, *clipboard_param = NULL, _0, _1;
	zend_long handle, clipboard;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(clipboard)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &clipboard_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, clipboard);
	phpgtk_gtktextbuffer_remove_selection_clipboard(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, setEnableUndo)
{
	zend_bool enableUndo;
	zval *handle_param = NULL, *enableUndo_param = NULL, _0, _1;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_BOOL(enableUndo)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &enableUndo_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_BOOL(&_1, (enableUndo ? 1 : 0));
	phpgtk_gtktextbuffer_set_enable_undo(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, setMaxUndoLevels)
{
	zval *handle_param = NULL, *maxUndoLevels_param = NULL, _0, _1;
	zend_long handle, maxUndoLevels;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(handle)
		Z_PARAM_LONG(maxUndoLevels)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &handle_param, &maxUndoLevels_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, maxUndoLevels);
	phpgtk_gtktextbuffer_set_max_undo_levels(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, setModified)
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
	phpgtk_gtktextbuffer_set_modified(&_0, &_1);
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, setText)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval text;
	zval *handle_param = NULL, *text_param = NULL, *len_param = NULL, _0, _1;
	zend_long handle, len;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&text);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(handle)
		Z_PARAM_STR(text)
		Z_PARAM_LONG(len)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &handle_param, &text_param, &len_param);
	zephir_get_strval(&text, text_param);
	ZVAL_LONG(&_0, handle);
	ZVAL_LONG(&_1, len);
	phpgtk_gtktextbuffer_set_text(&_0, &text, &_1);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer, undo)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	phpgtk_gtktextbuffer_undo(&_0);
}

