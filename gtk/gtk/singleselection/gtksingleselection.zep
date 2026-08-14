namespace Gtk\GTK\SingleSelection;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

class GtkSingleSelection
{
    public static function gtkSingleSelectionNew(int model) -> int
    {
        int handle;
        %{
            GtkSingleSelection *sel;
            GListModel *list = G_LIST_MODEL((void *)(uintptr_t) model);

            php_gtk_set_last_error(NULL);
            sel = gtk_single_selection_new(list);
            if (sel == NULL) {
                php_gtk_set_last_error("gtk_single_selection_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) sel;
            }
        }%
        return handle;
    }

    public static function gtkSingleSelectionSetSelected(int selection, int position) -> void
    {
        %{
            GtkSingleSelection *sel = GTK_SINGLE_SELECTION((void *)(uintptr_t) selection);
            if (sel != NULL) {
                gtk_single_selection_set_selected(sel, (guint) position);
            }
        }%
    }

    public static function gtkSingleSelectionGetSelected(int selection) -> int
    {
        int position;
        %{
            GtkSingleSelection *sel = GTK_SINGLE_SELECTION((void *)(uintptr_t) selection);
            position = sel != NULL ? (zend_long) gtk_single_selection_get_selected(sel) : 0;
        }%
        return position;
    }

    public static function gtkSingleSelectionGetModel(int selection) -> int
    {
        int handle;
        %{
            GtkSingleSelection *sel = GTK_SINGLE_SELECTION((void *)(uintptr_t) selection);
            GListModel *model = NULL;
            if (sel != NULL) {
                model = gtk_single_selection_get_model(sel);
            }
            handle = (zend_long)(uintptr_t) model;
        }%
        return handle;
    }
}
