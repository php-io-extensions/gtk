namespace Gtk\GTK\ListBox;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

class GtkListBox
{
    public static function gtkListBoxNew() -> int
    {
        int handle;
        %{
            GtkWidget *box;

            php_gtk_set_last_error(NULL);
            box = gtk_list_box_new();
            if (box == NULL) {
                php_gtk_set_last_error("gtk_list_box_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) box;
            }
        }%
        return handle;
    }

    public static function gtkListBoxAppend(int box, int child) -> void
    {
        %{
            GtkListBox *lb = GTK_LIST_BOX((void *)(uintptr_t) box);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (lb != NULL && widget != NULL) {
                gtk_list_box_append(lb, widget);
            }
        }%
    }

    public static function gtkListBoxRemove(int box, int child) -> void
    {
        %{
            GtkListBox *lb = GTK_LIST_BOX((void *)(uintptr_t) box);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (lb != NULL && widget != NULL) {
                gtk_list_box_remove(lb, widget);
            }
        }%
    }

    public static function gtkListBoxGetSelectedRow(int box) -> int
    {
        int handle;
        %{
            GtkListBox *lb = GTK_LIST_BOX((void *)(uintptr_t) box);
            GtkListBoxRow *row = NULL;
            if (lb != NULL) {
                row = gtk_list_box_get_selected_row(lb);
            }
            handle = (zend_long)(uintptr_t) row;
        }%
        return handle;
    }

    public static function gtkListBoxSelectRow(int box, int row) -> void
    {
        %{
            GtkListBox *lb = GTK_LIST_BOX((void *)(uintptr_t) box);
            GtkListBoxRow *r = GTK_LIST_BOX_ROW((void *)(uintptr_t) row);
            if (lb != NULL) {
                gtk_list_box_select_row(lb, r);
            }
        }%
    }

    public static function gtkListBoxGetRowAtIndex(int box, int index) -> int
    {
        int handle;
        %{
            GtkListBox *lb = GTK_LIST_BOX((void *)(uintptr_t) box);
            GtkListBoxRow *row = NULL;
            if (lb != NULL) {
                row = gtk_list_box_get_row_at_index(lb, (int) index);
            }
            handle = (zend_long)(uintptr_t) row;
        }%
        return handle;
    }

    public static function gtkListBoxRowGetIndex(int row) -> int
    {
        int index;
        %{
            GtkListBoxRow *r = GTK_LIST_BOX_ROW((void *)(uintptr_t) row);
            index = r != NULL ? (zend_long) gtk_list_box_row_get_index(r) : -1;
        }%
        return index;
    }

    public static function gtkListBoxRowGetChild(int row) -> int
    {
        int handle;
        %{
            GtkListBoxRow *r = GTK_LIST_BOX_ROW((void *)(uintptr_t) row);
            GtkWidget *child = NULL;
            if (r != NULL) {
                child = gtk_list_box_row_get_child(r);
            }
            handle = (zend_long)(uintptr_t) child;
        }%
        return handle;
    }
}
