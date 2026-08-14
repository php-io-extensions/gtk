namespace Gtk\GTK\ListItem;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

class GtkListItem
{
    public static function gtkSignalListItemFactoryNew() -> int
    {
        int handle;
        %{
            GtkListItemFactory *factory;

            php_gtk_set_last_error(NULL);
            factory = gtk_signal_list_item_factory_new();
            if (factory == NULL) {
                php_gtk_set_last_error("gtk_signal_list_item_factory_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) factory;
            }
        }%
        return handle;
    }

    public static function gtkListItemSetChild(int item, int child) -> void
    {
        %{
            GtkListItem *li = GTK_LIST_ITEM((void *)(uintptr_t) item);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (li != NULL) {
                gtk_list_item_set_child(li, widget);
            }
        }%
    }

    public static function gtkListItemGetChild(int item) -> int
    {
        int handle;
        %{
            GtkListItem *li = GTK_LIST_ITEM((void *)(uintptr_t) item);
            GtkWidget *child = NULL;
            if (li != NULL) {
                child = gtk_list_item_get_child(li);
            }
            handle = (zend_long)(uintptr_t) child;
        }%
        return handle;
    }

    public static function gtkListItemGetItem(int item) -> int
    {
        int handle;
        %{
            GtkListItem *li = GTK_LIST_ITEM((void *)(uintptr_t) item);
            gpointer obj = NULL;
            if (li != NULL) {
                obj = gtk_list_item_get_item(li);
            }
            handle = (zend_long)(uintptr_t) obj;
        }%
        return handle;
    }

    public static function gtkListItemGetPosition(int item) -> int
    {
        int position;
        %{
            GtkListItem *li = GTK_LIST_ITEM((void *)(uintptr_t) item);
            position = li != NULL ? (zend_long) gtk_list_item_get_position(li) : 0;
        }%
        return position;
    }
}
