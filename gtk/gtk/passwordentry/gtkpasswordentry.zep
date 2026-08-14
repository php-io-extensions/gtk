namespace Gtk\GTK\PasswordEntry;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

class GtkPasswordEntry
{
    public static function gtkPasswordEntryNew() -> int
    {
        int handle;
        %{
            GtkWidget *entry;

            php_gtk_set_last_error(NULL);
            entry = gtk_password_entry_new();
            if (entry == NULL) {
                php_gtk_set_last_error("gtk_password_entry_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) entry;
            }
        }%
        return handle;
    }

    public static function gtkPasswordEntrySetText(int entry, string text) -> void
    {
        %{
            GtkEditable *editable = GTK_EDITABLE((void *)(uintptr_t) entry);
            if (editable != NULL) {
                gtk_editable_set_text(editable, Z_STRVAL(text));
            }
        }%
    }

    public static function gtkPasswordEntryGetText(int entry) -> string
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

    public static function gtkPasswordEntrySetShowPeekIcon(int entry, bool showPeek) -> void
    {
        %{
            GtkPasswordEntry *pe = GTK_PASSWORD_ENTRY((void *)(uintptr_t) entry);
            if (pe != NULL) {
                gtk_password_entry_set_show_peek_icon(pe, showPeek ? TRUE : FALSE);
            }
        }%
    }

    public static function gtkPasswordEntryGetShowPeekIcon(int entry) -> bool
    {
        bool showPeek;
        %{
            GtkPasswordEntry *pe = GTK_PASSWORD_ENTRY((void *)(uintptr_t) entry);
            showPeek = (pe != NULL && gtk_password_entry_get_show_peek_icon(pe)) ? true : false;
        }%
        return showPeek;
    }
}
