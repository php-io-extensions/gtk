#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-center-box.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkcenterbox_new(void)
{
    return phpgtk_handle_register(gtk_center_box_new());
}

zend_long phpgtk_gtkcenterbox_get_baseline_position(zval *handle)
{
    GtkCenterBox *self = PHPGTK_ARG_AS(GtkCenterBox, GTK_TYPE_CENTER_BOX, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_center_box_get_baseline_position(self);
}

zend_long phpgtk_gtkcenterbox_get_center_widget(zval *handle)
{
    GtkCenterBox *self = PHPGTK_ARG_AS(GtkCenterBox, GTK_TYPE_CENTER_BOX, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_center_box_get_center_widget(self));
}

zend_long phpgtk_gtkcenterbox_get_end_widget(zval *handle)
{
    GtkCenterBox *self = PHPGTK_ARG_AS(GtkCenterBox, GTK_TYPE_CENTER_BOX, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_center_box_get_end_widget(self));
}

zend_long phpgtk_gtkcenterbox_get_shrink_center_last(zval *handle)
{
    GtkCenterBox *self = PHPGTK_ARG_AS(GtkCenterBox, GTK_TYPE_CENTER_BOX, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_center_box_get_shrink_center_last(self) ? 1 : 0;
}

zend_long phpgtk_gtkcenterbox_get_start_widget(zval *handle)
{
    GtkCenterBox *self = PHPGTK_ARG_AS(GtkCenterBox, GTK_TYPE_CENTER_BOX, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_center_box_get_start_widget(self));
}

void phpgtk_gtkcenterbox_set_baseline_position(zval *handle, zval *position)
{
    GtkCenterBox *self = PHPGTK_ARG_AS(GtkCenterBox, GTK_TYPE_CENTER_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_center_box_set_baseline_position(self, (GtkBaselinePosition) phpgtk_arg_long(position));
}

void phpgtk_gtkcenterbox_set_center_widget(zval *handle, zval *child)
{
    GtkCenterBox *self = PHPGTK_ARG_AS(GtkCenterBox, GTK_TYPE_CENTER_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_center_box_set_center_widget(self, phpgtk_arg_object(child));
}

void phpgtk_gtkcenterbox_set_end_widget(zval *handle, zval *child)
{
    GtkCenterBox *self = PHPGTK_ARG_AS(GtkCenterBox, GTK_TYPE_CENTER_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_center_box_set_end_widget(self, phpgtk_arg_object(child));
}

void phpgtk_gtkcenterbox_set_shrink_center_last(zval *handle, zval *shrinkCenterLast)
{
    GtkCenterBox *self = PHPGTK_ARG_AS(GtkCenterBox, GTK_TYPE_CENTER_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_center_box_set_shrink_center_last(self, phpgtk_arg_bool(shrinkCenterLast));
}

void phpgtk_gtkcenterbox_set_start_widget(zval *handle, zval *child)
{
    GtkCenterBox *self = PHPGTK_ARG_AS(GtkCenterBox, GTK_TYPE_CENTER_BOX, handle);

    if (self == NULL) {
        return;
    }

    gtk_center_box_set_start_widget(self, phpgtk_arg_object(child));
}
