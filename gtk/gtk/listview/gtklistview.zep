namespace Gtk\GTK\ListView;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

class GtkListView
{
    public static function gtkListViewNew(int model, int factory) -> int
    {
        int handle;
        %{
            GtkWidget *view;
            GtkSelectionModel *sel = GTK_SELECTION_MODEL((void *)(uintptr_t) model);
            GtkListItemFactory *fac = GTK_LIST_ITEM_FACTORY((void *)(uintptr_t) factory);

            php_gtk_set_last_error(NULL);
            view = gtk_list_view_new(sel, fac);
            if (view == NULL) {
                php_gtk_set_last_error("gtk_list_view_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) view;
            }
        }%
        return handle;
    }

    public static function gtkListViewSetModel(int view, int model) -> void
    {
        %{
            GtkListView *lv = GTK_LIST_VIEW((void *)(uintptr_t) view);
            GtkSelectionModel *sel = GTK_SELECTION_MODEL((void *)(uintptr_t) model);
            if (lv != NULL) {
                gtk_list_view_set_model(lv, sel);
            }
        }%
    }

    public static function gtkListViewGetModel(int view) -> int
    {
        int handle;
        %{
            GtkListView *lv = GTK_LIST_VIEW((void *)(uintptr_t) view);
            GtkSelectionModel *sel = NULL;
            if (lv != NULL) {
                sel = gtk_list_view_get_model(lv);
            }
            handle = (zend_long)(uintptr_t) sel;
        }%
        return handle;
    }

    public static function gtkListViewSetFactory(int view, int factory) -> void
    {
        %{
            GtkListView *lv = GTK_LIST_VIEW((void *)(uintptr_t) view);
            GtkListItemFactory *fac = GTK_LIST_ITEM_FACTORY((void *)(uintptr_t) factory);
            if (lv != NULL) {
                gtk_list_view_set_factory(lv, fac);
            }
        }%
    }
}
