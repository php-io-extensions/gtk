namespace Gtk\GTK\Notebook;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

class GtkNotebook
{
    public static function gtkNotebookNew() -> int
    {
        int handle;
        %{
            GtkWidget *nb;

            php_gtk_set_last_error(NULL);
            nb = gtk_notebook_new();
            if (nb == NULL) {
                php_gtk_set_last_error("gtk_notebook_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) nb;
            }
        }%
        return handle;
    }

    public static function gtkNotebookAppendPage(int notebook, int child, int tabLabel) -> int
    {
        int page;
        %{
            GtkNotebook *nb = GTK_NOTEBOOK((void *)(uintptr_t) notebook);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            GtkWidget *tab = GTK_WIDGET((void *)(uintptr_t) tabLabel);
            page = -1;
            if (nb != NULL && widget != NULL) {
                page = (zend_long) gtk_notebook_append_page(nb, widget, tab);
            }
        }%
        return page;
    }

    public static function gtkNotebookRemovePage(int notebook, int pageNum) -> void
    {
        %{
            GtkNotebook *nb = GTK_NOTEBOOK((void *)(uintptr_t) notebook);
            if (nb != NULL) {
                gtk_notebook_remove_page(nb, (int) pageNum);
            }
        }%
    }

    public static function gtkNotebookGetNPages(int notebook) -> int
    {
        int pages;
        %{
            GtkNotebook *nb = GTK_NOTEBOOK((void *)(uintptr_t) notebook);
            pages = nb != NULL ? (zend_long) gtk_notebook_get_n_pages(nb) : 0;
        }%
        return pages;
    }

    public static function gtkNotebookSetCurrentPage(int notebook, int pageNum) -> void
    {
        %{
            GtkNotebook *nb = GTK_NOTEBOOK((void *)(uintptr_t) notebook);
            if (nb != NULL) {
                gtk_notebook_set_current_page(nb, (int) pageNum);
            }
        }%
    }

    public static function gtkNotebookGetCurrentPage(int notebook) -> int
    {
        int page;
        %{
            GtkNotebook *nb = GTK_NOTEBOOK((void *)(uintptr_t) notebook);
            page = nb != NULL ? (zend_long) gtk_notebook_get_current_page(nb) : -1;
        }%
        return page;
    }

    public static function gtkNotebookSetTabLabelText(int notebook, int child, string text) -> void
    {
        %{
            GtkNotebook *nb = GTK_NOTEBOOK((void *)(uintptr_t) notebook);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (nb != NULL && widget != NULL) {
                gtk_notebook_set_tab_label_text(nb, widget, Z_STRVAL(text));
            }
        }%
    }
}
