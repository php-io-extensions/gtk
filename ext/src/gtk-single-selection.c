#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-single-selection.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtksingleselection_new(zval *model)
{
    return phpgtk_handle_register_take(gtk_single_selection_new(phpgtk_arg_object_give(model)));
}

zend_long phpgtk_gtksingleselection_get_autoselect(zval *handle)
{
    GtkSingleSelection *self = PHPGTK_ARG_AS(GtkSingleSelection, GTK_TYPE_SINGLE_SELECTION, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_single_selection_get_autoselect(self) ? 1 : 0;
}

zend_long phpgtk_gtksingleselection_get_can_unselect(zval *handle)
{
    GtkSingleSelection *self = PHPGTK_ARG_AS(GtkSingleSelection, GTK_TYPE_SINGLE_SELECTION, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_single_selection_get_can_unselect(self) ? 1 : 0;
}

zend_long phpgtk_gtksingleselection_get_model(zval *handle)
{
    GtkSingleSelection *self = PHPGTK_ARG_AS(GtkSingleSelection, GTK_TYPE_SINGLE_SELECTION, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_single_selection_get_model(self));
}

zend_long phpgtk_gtksingleselection_get_selected(zval *handle)
{
    GtkSingleSelection *self = PHPGTK_ARG_AS(GtkSingleSelection, GTK_TYPE_SINGLE_SELECTION, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_single_selection_get_selected(self);
}

zend_long phpgtk_gtksingleselection_get_selected_item(zval *handle)
{
    GtkSingleSelection *self = PHPGTK_ARG_AS(GtkSingleSelection, GTK_TYPE_SINGLE_SELECTION, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_single_selection_get_selected_item(self));
}

void phpgtk_gtksingleselection_set_autoselect(zval *handle, zval *autoselect)
{
    GtkSingleSelection *self = PHPGTK_ARG_AS(GtkSingleSelection, GTK_TYPE_SINGLE_SELECTION, handle);

    if (self == NULL) {
        return;
    }

    gtk_single_selection_set_autoselect(self, phpgtk_arg_bool(autoselect));
}

void phpgtk_gtksingleselection_set_can_unselect(zval *handle, zval *canUnselect)
{
    GtkSingleSelection *self = PHPGTK_ARG_AS(GtkSingleSelection, GTK_TYPE_SINGLE_SELECTION, handle);

    if (self == NULL) {
        return;
    }

    gtk_single_selection_set_can_unselect(self, phpgtk_arg_bool(canUnselect));
}

void phpgtk_gtksingleselection_set_model(zval *handle, zval *model)
{
    GtkSingleSelection *self = PHPGTK_ARG_AS(GtkSingleSelection, GTK_TYPE_SINGLE_SELECTION, handle);

    if (self == NULL) {
        return;
    }

    gtk_single_selection_set_model(self, phpgtk_arg_object(model));
}

void phpgtk_gtksingleselection_set_selected(zval *handle, zval *position)
{
    GtkSingleSelection *self = PHPGTK_ARG_AS(GtkSingleSelection, GTK_TYPE_SINGLE_SELECTION, handle);

    if (self == NULL) {
        return;
    }

    gtk_single_selection_set_selected(self, (guint) phpgtk_arg_long(position));
}
