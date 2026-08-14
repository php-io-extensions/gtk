namespace Gtk\GTK\Entry;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

/**
 * GtkEntry — new, text get/set (GtkEditable), placeholder, visibility.
 */
class GtkEntry
{
    public static function gtkEntryNew() -> int
    {
        int handle;
        %{
            GtkWidget *entry;

            php_gtk_set_last_error(NULL);
            entry = gtk_entry_new();
            if (entry == NULL) {
                php_gtk_set_last_error("gtk_entry_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) entry;
            }
        }%
        return handle;
    }

    public static function gtkEntrySetText(int entry, string text) -> void
    {
        %{
            GtkEditable *editable = GTK_EDITABLE((void *)(uintptr_t) entry);
            if (editable != NULL) {
                gtk_editable_set_text(editable, Z_STRVAL(text));
            }
        }%
    }

    public static function gtkEntryGetText(int entry) -> string
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

    public static function gtkEntrySetPlaceholderText(int entry, string text) -> void
    {
        %{
            GtkEntry *ent = GTK_ENTRY((void *)(uintptr_t) entry);
            if (ent != NULL) {
                gtk_entry_set_placeholder_text(ent, Z_STRVAL(text));
            }
        }%
    }

    public static function gtkEntryGetPlaceholderText(int entry) -> string
    {
        string result;
        %{
            GtkEntry *ent = GTK_ENTRY((void *)(uintptr_t) entry);
            const char *text = NULL;
            if (ent != NULL) {
                text = gtk_entry_get_placeholder_text(ent);
            }
            ZVAL_STRING(&result, text ? text : "");
        }%
        return result;
    }

    public static function gtkEntrySetVisibility(int entry, bool visible) -> void
    {
        %{
            GtkEntry *ent = GTK_ENTRY((void *)(uintptr_t) entry);
            if (ent != NULL) {
                gtk_entry_set_visibility(ent, visible ? TRUE : FALSE);
            }
        }%
    }

    public static function gtkEntryGetVisibility(int entry) -> bool
    {
        bool visible;
        %{
            GtkEntry *ent = GTK_ENTRY((void *)(uintptr_t) entry);
            visible = (ent != NULL && gtk_entry_get_visibility(ent)) ? true : false;
        }%
        return visible;
    }
}
