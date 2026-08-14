
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"

#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
extern char **php_gtk_zval_to_strv(zval *arr);
extern void php_gtk_strv_free(char **strv);



ZEPHIR_INIT_CLASS(Gtk_GTK_StringList_GtkStringList)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\StringList, GtkStringList, gtk, gtk_stringlist_gtkstringlist, gtk_gtk_stringlist_gtkstringlist_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_StringList_GtkStringList, gtkStringListNew)
{
	zend_long handle = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *strings_param = NULL;
	zval strings;

	ZVAL_UNDEF(&strings);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(strings, strings_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &strings_param);
	zephir_get_arrval(&strings, strings_param);
	
            GtkStringList *list;
            char **strv;

            php_gtk_set_last_error(NULL);
            strv = php_gtk_zval_to_strv(&strings);
            list = gtk_string_list_new((const char * const *) strv);
            php_gtk_strv_free(strv);
            if (list == NULL) {
                php_gtk_set_last_error("gtk_string_list_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) list;
            }
        
	RETURN_MM_LONG(handle);
}

PHP_METHOD(Gtk_GTK_StringList_GtkStringList, gtkStringListAppend)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval value;
	zval *list_param = NULL, *value_param = NULL;
	zend_long list;

	ZVAL_UNDEF(&value);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(list)
		Z_PARAM_ZVAL(value_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &list_param, &value_param);
	zephir_get_strval(&value, value_param);
	
            GtkStringList *sl = GTK_STRING_LIST((void *)(uintptr_t) list);
            if (sl != NULL) {
                gtk_string_list_append(sl, Z_STRVAL(value));
            }
        
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_GTK_StringList_GtkStringList, gtkStringListRemove)
{
	zval *list_param = NULL, *position_param = NULL;
	zend_long list, position;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(list)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &list_param, &position_param);
	
            GtkStringList *sl = GTK_STRING_LIST((void *)(uintptr_t) list);
            if (sl != NULL) {
                gtk_string_list_remove(sl, (guint) position);
            }
        
}

PHP_METHOD(Gtk_GTK_StringList_GtkStringList, gtkStringListGetString)
{
	zval result;
	zval *list_param = NULL, *position_param = NULL;
	zend_long list, position;

	ZVAL_UNDEF(&result);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(list)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &list_param, &position_param);
	
            GtkStringList *sl = GTK_STRING_LIST((void *)(uintptr_t) list);
            const char *value = NULL;
            if (sl != NULL) {
                value = gtk_string_list_get_string(sl, (guint) position);
            }
            ZVAL_STRING(&result, value ? value : "");
        
	RETURN_CTORW(&result);
}

PHP_METHOD(Gtk_GTK_StringList_GtkStringList, gtkStringListGetNItems)
{
	zval *list_param = NULL;
	zend_long list, count = 0;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(list)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &list_param);
	
            GListModel *model = G_LIST_MODEL((void *)(uintptr_t) list);
            count = model != NULL ? (zend_long) g_list_model_get_n_items(model) : 0;
        
	RETURN_LONG(count);
}

PHP_METHOD(Gtk_GTK_StringList_GtkStringList, gtkStringObjectGetString)
{
	zval result;
	zval *item_param = NULL;
	zend_long item;

	ZVAL_UNDEF(&result);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(item)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &item_param);
	
            GtkStringObject *obj = GTK_STRING_OBJECT((void *)(uintptr_t) item);
            const char *value = NULL;
            if (obj != NULL) {
                value = gtk_string_object_get_string(obj);
            }
            ZVAL_STRING(&result, value ? value : "");
        
	RETURN_CTORW(&result);
}

