#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-selection-model.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkselectionmodel_is_selected(zval *handle, zval *position)
{
    GtkSelectionModel *self = PHPGTK_ARG_AS(GtkSelectionModel, GTK_TYPE_SELECTION_MODEL, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_selection_model_is_selected(self, (guint) phpgtk_arg_long(position)) ? 1 : 0;
}

zend_long phpgtk_gtkselectionmodel_select_all(zval *handle)
{
    GtkSelectionModel *self = PHPGTK_ARG_AS(GtkSelectionModel, GTK_TYPE_SELECTION_MODEL, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_selection_model_select_all(self) ? 1 : 0;
}

zend_long phpgtk_gtkselectionmodel_select_item(zval *handle, zval *position, zval *unselectRest)
{
    GtkSelectionModel *self = PHPGTK_ARG_AS(GtkSelectionModel, GTK_TYPE_SELECTION_MODEL, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_selection_model_select_item(self, (guint) phpgtk_arg_long(position), phpgtk_arg_bool(unselectRest)) ? 1 : 0;
}

zend_long phpgtk_gtkselectionmodel_select_range(zval *handle, zval *position, zval *nItems, zval *unselectRest)
{
    GtkSelectionModel *self = PHPGTK_ARG_AS(GtkSelectionModel, GTK_TYPE_SELECTION_MODEL, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_selection_model_select_range(self, (guint) phpgtk_arg_long(position), (guint) phpgtk_arg_long(nItems), phpgtk_arg_bool(unselectRest)) ? 1 : 0;
}

void phpgtk_gtkselectionmodel_selection_changed(zval *handle, zval *position, zval *nItems)
{
    GtkSelectionModel *self = PHPGTK_ARG_AS(GtkSelectionModel, GTK_TYPE_SELECTION_MODEL, handle);

    if (self == NULL) {
        return;
    }

    gtk_selection_model_selection_changed(self, (guint) phpgtk_arg_long(position), (guint) phpgtk_arg_long(nItems));
}

zend_long phpgtk_gtkselectionmodel_unselect_all(zval *handle)
{
    GtkSelectionModel *self = PHPGTK_ARG_AS(GtkSelectionModel, GTK_TYPE_SELECTION_MODEL, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_selection_model_unselect_all(self) ? 1 : 0;
}

zend_long phpgtk_gtkselectionmodel_unselect_item(zval *handle, zval *position)
{
    GtkSelectionModel *self = PHPGTK_ARG_AS(GtkSelectionModel, GTK_TYPE_SELECTION_MODEL, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_selection_model_unselect_item(self, (guint) phpgtk_arg_long(position)) ? 1 : 0;
}

zend_long phpgtk_gtkselectionmodel_unselect_range(zval *handle, zval *position, zval *nItems)
{
    GtkSelectionModel *self = PHPGTK_ARG_AS(GtkSelectionModel, GTK_TYPE_SELECTION_MODEL, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_selection_model_unselect_range(self, (guint) phpgtk_arg_long(position), (guint) phpgtk_arg_long(nItems)) ? 1 : 0;
}
