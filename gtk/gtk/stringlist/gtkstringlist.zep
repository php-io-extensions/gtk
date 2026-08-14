namespace Gtk\GTK\StringList;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
extern char **php_gtk_zval_to_strv(zval *arr);
extern void php_gtk_strv_free(char **strv);
}%

class GtkStringList
{
    public static function gtkStringListNew(array strings) -> int
    {
        int handle;
        %{
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
        }%
        return handle;
    }

    public static function gtkStringListAppend(int list, string value) -> void
    {
        %{
            GtkStringList *sl = GTK_STRING_LIST((void *)(uintptr_t) list);
            if (sl != NULL) {
                gtk_string_list_append(sl, Z_STRVAL(value));
            }
        }%
    }

    public static function gtkStringListRemove(int list, int position) -> void
    {
        %{
            GtkStringList *sl = GTK_STRING_LIST((void *)(uintptr_t) list);
            if (sl != NULL) {
                gtk_string_list_remove(sl, (guint) position);
            }
        }%
    }

    public static function gtkStringListGetString(int list, int position) -> string
    {
        string result;
        %{
            GtkStringList *sl = GTK_STRING_LIST((void *)(uintptr_t) list);
            const char *value = NULL;
            if (sl != NULL) {
                value = gtk_string_list_get_string(sl, (guint) position);
            }
            ZVAL_STRING(&result, value ? value : "");
        }%
        return result;
    }

    public static function gtkStringListGetNItems(int list) -> int
    {
        int count;
        %{
            GListModel *model = G_LIST_MODEL((void *)(uintptr_t) list);
            count = model != NULL ? (zend_long) g_list_model_get_n_items(model) : 0;
        }%
        return count;
    }

    public static function gtkStringObjectGetString(int item) -> string
    {
        string result;
        %{
            GtkStringObject *obj = GTK_STRING_OBJECT((void *)(uintptr_t) item);
            const char *value = NULL;
            if (obj != NULL) {
                value = gtk_string_object_get_string(obj);
            }
            ZVAL_STRING(&result, value ? value : "");
        }%
        return result;
    }
}
