#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-notebook.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtknotebook_new(void)
{
    return phpgtk_handle_register(gtk_notebook_new());
}

zend_long phpgtk_gtknotebook_append_page(zval *handle, zval *child, zval *tabLabel)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_notebook_append_page(self, phpgtk_arg_object(child), phpgtk_arg_object(tabLabel));
}

zend_long phpgtk_gtknotebook_append_page_menu(zval *handle, zval *child, zval *tabLabel, zval *menuLabel)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_notebook_append_page_menu(self, phpgtk_arg_object(child), phpgtk_arg_object(tabLabel), phpgtk_arg_object(menuLabel));
}

void phpgtk_gtknotebook_detach_tab(zval *handle, zval *child)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return;
    }

    gtk_notebook_detach_tab(self, phpgtk_arg_object(child));
}

zend_long phpgtk_gtknotebook_get_action_widget(zval *handle, zval *packType)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_notebook_get_action_widget(self, (GtkPackType) phpgtk_arg_long(packType)));
}

zend_long phpgtk_gtknotebook_get_current_page(zval *handle)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_notebook_get_current_page(self);
}

void phpgtk_gtknotebook_get_group_name(zval *return_value, zval *handle)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_notebook_get_group_name(self));
}

zend_long phpgtk_gtknotebook_get_menu_label(zval *handle, zval *child)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_notebook_get_menu_label(self, phpgtk_arg_object(child)));
}

void phpgtk_gtknotebook_get_menu_label_text(zval *return_value, zval *handle, zval *child)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_notebook_get_menu_label_text(self, phpgtk_arg_object(child)));
}

zend_long phpgtk_gtknotebook_get_n_pages(zval *handle)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_notebook_get_n_pages(self);
}

zend_long phpgtk_gtknotebook_get_nth_page(zval *handle, zval *pageNum)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_notebook_get_nth_page(self, phpgtk_arg_long(pageNum)));
}

zend_long phpgtk_gtknotebook_get_page(zval *handle, zval *child)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_notebook_get_page(self, phpgtk_arg_object(child)));
}

zend_long phpgtk_gtknotebook_get_pages(zval *handle)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register_take(gtk_notebook_get_pages(self));
}

zend_long phpgtk_gtknotebook_get_scrollable(zval *handle)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_notebook_get_scrollable(self) ? 1 : 0;
}

zend_long phpgtk_gtknotebook_get_show_border(zval *handle)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_notebook_get_show_border(self) ? 1 : 0;
}

zend_long phpgtk_gtknotebook_get_show_tabs(zval *handle)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_notebook_get_show_tabs(self) ? 1 : 0;
}

zend_long phpgtk_gtknotebook_get_tab_detachable(zval *handle, zval *child)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_notebook_get_tab_detachable(self, phpgtk_arg_object(child)) ? 1 : 0;
}

zend_long phpgtk_gtknotebook_get_tab_label(zval *handle, zval *child)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_notebook_get_tab_label(self, phpgtk_arg_object(child)));
}

void phpgtk_gtknotebook_get_tab_label_text(zval *return_value, zval *handle, zval *child)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_notebook_get_tab_label_text(self, phpgtk_arg_object(child)));
}

zend_long phpgtk_gtknotebook_get_tab_pos(zval *handle)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_notebook_get_tab_pos(self);
}

zend_long phpgtk_gtknotebook_get_tab_reorderable(zval *handle, zval *child)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_notebook_get_tab_reorderable(self, phpgtk_arg_object(child)) ? 1 : 0;
}

zend_long phpgtk_gtknotebook_insert_page(zval *handle, zval *child, zval *tabLabel, zval *position)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_notebook_insert_page(self, phpgtk_arg_object(child), phpgtk_arg_object(tabLabel), phpgtk_arg_long(position));
}

zend_long phpgtk_gtknotebook_insert_page_menu(zval *handle, zval *child, zval *tabLabel, zval *menuLabel, zval *position)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_notebook_insert_page_menu(self, phpgtk_arg_object(child), phpgtk_arg_object(tabLabel), phpgtk_arg_object(menuLabel), phpgtk_arg_long(position));
}

void phpgtk_gtknotebook_next_page(zval *handle)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return;
    }

    gtk_notebook_next_page(self);
}

zend_long phpgtk_gtknotebook_page_num(zval *handle, zval *child)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_notebook_page_num(self, phpgtk_arg_object(child));
}

void phpgtk_gtknotebook_popup_disable(zval *handle)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return;
    }

    gtk_notebook_popup_disable(self);
}

void phpgtk_gtknotebook_popup_enable(zval *handle)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return;
    }

    gtk_notebook_popup_enable(self);
}

zend_long phpgtk_gtknotebook_prepend_page(zval *handle, zval *child, zval *tabLabel)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_notebook_prepend_page(self, phpgtk_arg_object(child), phpgtk_arg_object(tabLabel));
}

zend_long phpgtk_gtknotebook_prepend_page_menu(zval *handle, zval *child, zval *tabLabel, zval *menuLabel)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_notebook_prepend_page_menu(self, phpgtk_arg_object(child), phpgtk_arg_object(tabLabel), phpgtk_arg_object(menuLabel));
}

void phpgtk_gtknotebook_prev_page(zval *handle)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return;
    }

    gtk_notebook_prev_page(self);
}

void phpgtk_gtknotebook_remove_page(zval *handle, zval *pageNum)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return;
    }

    gtk_notebook_remove_page(self, phpgtk_arg_long(pageNum));
}

void phpgtk_gtknotebook_reorder_child(zval *handle, zval *child, zval *position)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return;
    }

    gtk_notebook_reorder_child(self, phpgtk_arg_object(child), phpgtk_arg_long(position));
}

void phpgtk_gtknotebook_set_action_widget(zval *handle, zval *widget, zval *packType)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return;
    }

    gtk_notebook_set_action_widget(self, phpgtk_arg_object(widget), (GtkPackType) phpgtk_arg_long(packType));
}

void phpgtk_gtknotebook_set_current_page(zval *handle, zval *pageNum)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return;
    }

    gtk_notebook_set_current_page(self, phpgtk_arg_long(pageNum));
}

void phpgtk_gtknotebook_set_group_name(zval *handle, zval *groupName)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return;
    }

    gtk_notebook_set_group_name(self, phpgtk_arg_string(groupName));
}

void phpgtk_gtknotebook_set_menu_label(zval *handle, zval *child, zval *menuLabel)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return;
    }

    gtk_notebook_set_menu_label(self, phpgtk_arg_object(child), phpgtk_arg_object(menuLabel));
}

void phpgtk_gtknotebook_set_menu_label_text(zval *handle, zval *child, zval *menuText)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return;
    }

    gtk_notebook_set_menu_label_text(self, phpgtk_arg_object(child), phpgtk_arg_string(menuText));
}

void phpgtk_gtknotebook_set_scrollable(zval *handle, zval *scrollable)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return;
    }

    gtk_notebook_set_scrollable(self, phpgtk_arg_bool(scrollable));
}

void phpgtk_gtknotebook_set_show_border(zval *handle, zval *showBorder)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return;
    }

    gtk_notebook_set_show_border(self, phpgtk_arg_bool(showBorder));
}

void phpgtk_gtknotebook_set_show_tabs(zval *handle, zval *showTabs)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return;
    }

    gtk_notebook_set_show_tabs(self, phpgtk_arg_bool(showTabs));
}

void phpgtk_gtknotebook_set_tab_detachable(zval *handle, zval *child, zval *detachable)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return;
    }

    gtk_notebook_set_tab_detachable(self, phpgtk_arg_object(child), phpgtk_arg_bool(detachable));
}

void phpgtk_gtknotebook_set_tab_label(zval *handle, zval *child, zval *tabLabel)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return;
    }

    gtk_notebook_set_tab_label(self, phpgtk_arg_object(child), phpgtk_arg_object(tabLabel));
}

void phpgtk_gtknotebook_set_tab_label_text(zval *handle, zval *child, zval *tabText)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return;
    }

    gtk_notebook_set_tab_label_text(self, phpgtk_arg_object(child), phpgtk_arg_string(tabText));
}

void phpgtk_gtknotebook_set_tab_pos(zval *handle, zval *pos)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return;
    }

    gtk_notebook_set_tab_pos(self, (GtkPositionType) phpgtk_arg_long(pos));
}

void phpgtk_gtknotebook_set_tab_reorderable(zval *handle, zval *child, zval *reorderable)
{
    GtkNotebook *self = PHPGTK_ARG_AS(GtkNotebook, GTK_TYPE_NOTEBOOK, handle);

    if (self == NULL) {
        return;
    }

    gtk_notebook_set_tab_reorderable(self, phpgtk_arg_object(child), phpgtk_arg_bool(reorderable));
}
