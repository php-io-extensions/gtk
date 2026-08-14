namespace Gtk\GTK\SearchEntry;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

class GtkSearchEntry
{
    public static function gtkSearchEntryNew() -> int
    {
        int handle;
        %{
            GtkWidget *entry;

            php_gtk_set_last_error(NULL);
            entry = gtk_search_entry_new();
            if (entry == NULL) {
                php_gtk_set_last_error("gtk_search_entry_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) entry;
            }
        }%
        return handle;
    }

    public static function gtkSearchEntrySetText(int entry, string text) -> void
    {
        %{
            GtkEditable *editable = GTK_EDITABLE((void *)(uintptr_t) entry);
            if (editable != NULL) {
                gtk_editable_set_text(editable, Z_STRVAL(text));
            }
        }%
    }

    public static function gtkSearchEntryGetText(int entry) -> string
    {
        string result;
        %{
            GtkEditable *editable = GTK_EDITABLE((void *)(uintptr_t) entry);
            const char *text = NULL;
            if (editable != NULL) {
                text = gtk_editable_get_text(editable);
            }
            ZVAL_STRING(&result, text ? text : "");
        }%
        return result;
    }
}
