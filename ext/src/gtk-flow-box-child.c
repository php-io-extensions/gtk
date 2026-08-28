#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-flow-box-child.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkflowboxchild_new(void)
{
    return phpgtk_handle_register(gtk_flow_box_child_new());
}

void phpgtk_gtkflowboxchild_changed(zval *handle)
{
    GtkFlowBoxChild *self = PHPGTK_ARG_AS(GtkFlowBoxChild, GTK_TYPE_FLOW_BOX_CHILD, handle);

    if (self == NULL) {
        return;
    }

    gtk_flow_box_child_changed(self);
}

zend_long phpgtk_gtkflowboxchild_get_child(zval *handle)
{
    GtkFlowBoxChild *self = PHPGTK_ARG_AS(GtkFlowBoxChild, GTK_TYPE_FLOW_BOX_CHILD, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_flow_box_child_get_child(self));
}

zend_long phpgtk_gtkflowboxchild_get_index(zval *handle)
{
    GtkFlowBoxChild *self = PHPGTK_ARG_AS(GtkFlowBoxChild, GTK_TYPE_FLOW_BOX_CHILD, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_flow_box_child_get_index(self);
}

zend_long phpgtk_gtkflowboxchild_is_selected(zval *handle)
{
    GtkFlowBoxChild *self = PHPGTK_ARG_AS(GtkFlowBoxChild, GTK_TYPE_FLOW_BOX_CHILD, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_flow_box_child_is_selected(self) ? 1 : 0;
}

void phpgtk_gtkflowboxchild_set_child(zval *handle, zval *child)
{
    GtkFlowBoxChild *self = PHPGTK_ARG_AS(GtkFlowBoxChild, GTK_TYPE_FLOW_BOX_CHILD, handle);

    if (self == NULL) {
        return;
    }

    gtk_flow_box_child_set_child(self, phpgtk_arg_object(child));
}
