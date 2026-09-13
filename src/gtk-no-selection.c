#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-no-selection.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtknoselection_new(zval *model)
{
    return phpgtk_handle_register_take(gtk_no_selection_new(phpgtk_arg_object_give(model)));
}

zend_long phpgtk_gtknoselection_get_model(zval *handle)
{
    GtkNoSelection *self = PHPGTK_ARG_AS(GtkNoSelection, GTK_TYPE_NO_SELECTION, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_no_selection_get_model(self));
}

void phpgtk_gtknoselection_set_model(zval *handle, zval *model)
{
    GtkNoSelection *self = PHPGTK_ARG_AS(GtkNoSelection, GTK_TYPE_NO_SELECTION, handle);

    if (self == NULL) {
        return;
    }

    gtk_no_selection_set_model(self, phpgtk_arg_object(model));
}
