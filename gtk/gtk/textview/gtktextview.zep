namespace Gtk\GTK\TextView;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

class GtkTextView
{
    public static function gtkTextViewNew() -> int
    {
        int handle;
        %{
            GtkWidget *view;

            php_gtk_set_last_error(NULL);
            view = gtk_text_view_new();
            if (view == NULL) {
                php_gtk_set_last_error("gtk_text_view_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) view;
            }
        }%
        return handle;
    }

    public static function gtkTextViewGetBuffer(int view) -> int
    {
        int handle;
        %{
            GtkTextView *tv = GTK_TEXT_VIEW((void *)(uintptr_t) view);
            GtkTextBuffer *buf = NULL;
            if (tv != NULL) {
                buf = gtk_text_view_get_buffer(tv);
            }
            handle = (zend_long)(uintptr_t) buf;
        }%
        return handle;
    }

    public static function gtkTextViewSetText(int view, string text) -> void
    {
        %{
            GtkTextView *tv = GTK_TEXT_VIEW((void *)(uintptr_t) view);
            GtkTextBuffer *buf;
            if (tv != NULL) {
                buf = gtk_text_view_get_buffer(tv);
                if (buf != NULL) {
                    gtk_text_buffer_set_text(buf, Z_STRVAL(text), -1);
                }
            }
        }%
    }

    public static function gtkTextViewGetText(int view) -> string
    {
        string result;
        %{
            GtkTextView *tv = GTK_TEXT_VIEW((void *)(uintptr_t) view);
            GtkTextBuffer *buf = NULL;
            GtkTextIter start;
            GtkTextIter end;
            char *text = NULL;
            if (tv != NULL) {
                buf = gtk_text_view_get_buffer(tv);
            }
            if (buf != NULL) {
                gtk_text_buffer_get_bounds(buf, &start, &end);
                text = gtk_text_buffer_get_text(buf, &start, &end, FALSE);
            }
            ZVAL_STRING(&result, text ? text : "");
            if (text != NULL) {
                g_free(text);
            }
        }%
        return result;
    }

    public static function gtkTextViewSetEditable(int view, bool editable) -> void
    {
        %{
            GtkTextView *tv = GTK_TEXT_VIEW((void *)(uintptr_t) view);
            if (tv != NULL) {
                gtk_text_view_set_editable(tv, editable ? TRUE : FALSE);
            }
        }%
    }

    public static function gtkTextViewGetEditable(int view) -> bool
    {
        bool editable;
        %{
            GtkTextView *tv = GTK_TEXT_VIEW((void *)(uintptr_t) view);
            editable = (tv != NULL && gtk_text_view_get_editable(tv)) ? true : false;
        }%
        return editable;
    }

    public static function gtkTextViewSetWrapMode(int view, int wrapMode) -> void
    {
        %{
            GtkTextView *tv = GTK_TEXT_VIEW((void *)(uintptr_t) view);
            if (tv != NULL) {
                gtk_text_view_set_wrap_mode(tv, (GtkWrapMode) wrapMode);
            }
        }%
    }

    public static function gtkTextViewGetWrapMode(int view) -> int
    {
        int wrapMode;
        %{
            GtkTextView *tv = GTK_TEXT_VIEW((void *)(uintptr_t) view);
            wrapMode = tv != NULL ? (zend_long) gtk_text_view_get_wrap_mode(tv) : 0;
        }%
        return wrapMode;
    }
}
