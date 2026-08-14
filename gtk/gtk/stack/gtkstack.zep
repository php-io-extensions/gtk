namespace Gtk\GTK\Stack;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

class GtkStack
{
    public static function gtkStackNew() -> int
    {
        int handle;
        %{
            GtkWidget *stack;

            php_gtk_set_last_error(NULL);
            stack = gtk_stack_new();
            if (stack == NULL) {
                php_gtk_set_last_error("gtk_stack_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) stack;
            }
        }%
        return handle;
    }

    public static function gtkStackAddChild(int stack, int child) -> void
    {
        %{
            GtkStack *st = GTK_STACK((void *)(uintptr_t) stack);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (st != NULL && widget != NULL) {
                gtk_stack_add_child(st, widget);
            }
        }%
    }

    public static function gtkStackAddTitled(int stack, int child, string name, string title) -> void
    {
        %{
            GtkStack *st = GTK_STACK((void *)(uintptr_t) stack);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (st != NULL && widget != NULL) {
                gtk_stack_add_titled(st, widget, Z_STRVAL(name), Z_STRVAL(title));
            }
        }%
    }

    public static function gtkStackRemove(int stack, int child) -> void
    {
        %{
            GtkStack *st = GTK_STACK((void *)(uintptr_t) stack);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (st != NULL && widget != NULL) {
                gtk_stack_remove(st, widget);
            }
        }%
    }

    public static function gtkStackSetVisibleChild(int stack, int child) -> void
    {
        %{
            GtkStack *st = GTK_STACK((void *)(uintptr_t) stack);
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) child);
            if (st != NULL && widget != NULL) {
                gtk_stack_set_visible_child(st, widget);
            }
        }%
    }

    public static function gtkStackGetVisibleChild(int stack) -> int
    {
        int handle;
        %{
            GtkStack *st = GTK_STACK((void *)(uintptr_t) stack);
            GtkWidget *child = NULL;
            if (st != NULL) {
                child = gtk_stack_get_visible_child(st);
            }
            handle = (zend_long)(uintptr_t) child;
        }%
        return handle;
    }

    public static function gtkStackSetVisibleChildName(int stack, string name) -> void
    {
        %{
            GtkStack *st = GTK_STACK((void *)(uintptr_t) stack);
            if (st != NULL) {
                gtk_stack_set_visible_child_name(st, Z_STRVAL(name));
            }
        }%
    }

    public static function gtkStackGetVisibleChildName(int stack) -> string
    {
        string result;
        %{
            GtkStack *st = GTK_STACK((void *)(uintptr_t) stack);
            const char *name = NULL;
            if (st != NULL) {
                name = gtk_stack_get_visible_child_name(st);
            }
            ZVAL_STRING(&result, name ? name : "");
        }%
        return result;
    }
}
