namespace Gtk\GTK\DropDown;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
extern char **php_gtk_zval_to_strv(zval *arr);
extern void php_gtk_strv_free(char **strv);
}%

class GtkDropDown
{
    public static function gtkDropDownNewFromStrings(array labels) -> int
    {
        int handle;
        %{
            GtkWidget *drop;
            char **strv;

            php_gtk_set_last_error(NULL);
            strv = php_gtk_zval_to_strv(&labels);
            drop = gtk_drop_down_new_from_strings((const char * const *) strv);
            php_gtk_strv_free(strv);
            if (drop == NULL) {
                php_gtk_set_last_error("gtk_drop_down_new_from_strings returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) drop;
            }
        }%
        return handle;
    }

    public static function gtkDropDownSetSelected(int drop, int selected) -> void
    {
        %{
            GtkDropDown *dd = GTK_DROP_DOWN((void *)(uintptr_t) drop);
            if (dd != NULL) {
                gtk_drop_down_set_selected(dd, (guint) selected);
            }
        }%
    }

    public static function gtkDropDownGetSelected(int drop) -> int
    {
        int selected;
        %{
            GtkDropDown *dd = GTK_DROP_DOWN((void *)(uintptr_t) drop);
            selected = dd != NULL ? (zend_long) gtk_drop_down_get_selected(dd) : 0;
        }%
        return selected;
    }
}
