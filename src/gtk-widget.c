#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-widget.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkwidget_get_default_direction(void)
{
    return (zend_long) gtk_widget_get_default_direction();
}

void phpgtk_gtkwidget_set_default_direction(zval *dir)
{
    gtk_widget_set_default_direction((GtkTextDirection) phpgtk_arg_long(dir));
}

void phpgtk_gtkwidget_action_set_enabled(zval *handle, zval *actionName, zval *enabled)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_action_set_enabled(self, phpgtk_arg_string(actionName), phpgtk_arg_bool(enabled));
}

zend_long phpgtk_gtkwidget_activate(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_activate(self) ? 1 : 0;
}

void phpgtk_gtkwidget_activate_default(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_activate_default(self);
}

void phpgtk_gtkwidget_add_controller(zval *handle, zval *controller)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_add_controller(self, phpgtk_arg_object_give(controller));
}

void phpgtk_gtkwidget_add_css_class(zval *handle, zval *cssClass)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_add_css_class(self, phpgtk_arg_string(cssClass));
}

void phpgtk_gtkwidget_add_mnemonic_label(zval *handle, zval *label)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_add_mnemonic_label(self, phpgtk_arg_object(label));
}

zend_long phpgtk_gtkwidget_child_focus(zval *handle, zval *direction)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_child_focus(self, (GtkDirectionType) phpgtk_arg_long(direction)) ? 1 : 0;
}

void phpgtk_gtkwidget_compute_bounds(zval *return_value, zval *handle, zval *target)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    graphene_rect_t out_bounds;

    if (!gtk_widget_compute_bounds(self, phpgtk_arg_object(target), &out_bounds)) {
        ZVAL_NULL(return_value);
        return;
    }
    phpgtk_ret_graphene_rect(return_value, &out_bounds);
}

zend_long phpgtk_gtkwidget_compute_expand(zval *handle, zval *orientation)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_compute_expand(self, (GtkOrientation) phpgtk_arg_long(orientation)) ? 1 : 0;
}

void phpgtk_gtkwidget_compute_point(zval *return_value, zval *handle, zval *target, zval *pointX, zval *pointY)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    graphene_point_t c_point;
    graphene_point_t out_point;

    c_point.x = (float) phpgtk_arg_double(pointX);
    c_point.y = (float) phpgtk_arg_double(pointY);
    if (!gtk_widget_compute_point(self, phpgtk_arg_object(target), &c_point, &out_point)) {
        ZVAL_NULL(return_value);
        return;
    }
    phpgtk_ret_graphene_point(return_value, &out_point);
}

zend_long phpgtk_gtkwidget_contains(zval *handle, zval *x, zval *y)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_contains(self, phpgtk_arg_double(x), phpgtk_arg_double(y)) ? 1 : 0;
}

zend_long phpgtk_gtkwidget_create_pango_context(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register_take(gtk_widget_create_pango_context(self));
}

zend_long phpgtk_gtkwidget_create_pango_layout(zval *handle, zval *text)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register_take(gtk_widget_create_pango_layout(self, phpgtk_arg_string(text)));
}

void phpgtk_gtkwidget_dispose_template(zval *handle, zval *widgetType)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_dispose_template(self, (GType) phpgtk_arg_long(widgetType));
}

zend_long phpgtk_gtkwidget_drag_check_threshold(zval *handle, zval *startX, zval *startY, zval *currentX, zval *currentY)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_drag_check_threshold(self, phpgtk_arg_long(startX), phpgtk_arg_long(startY), phpgtk_arg_long(currentX), phpgtk_arg_long(currentY)) ? 1 : 0;
}

void phpgtk_gtkwidget_error_bell(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_error_bell(self);
}

zend_long phpgtk_gtkwidget_get_ancestor(zval *handle, zval *widgetType)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_widget_get_ancestor(self, (GType) phpgtk_arg_long(widgetType)));
}

zend_long phpgtk_gtkwidget_get_baseline(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_widget_get_baseline(self);
}

zend_long phpgtk_gtkwidget_get_can_focus(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_get_can_focus(self) ? 1 : 0;
}

zend_long phpgtk_gtkwidget_get_can_target(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_get_can_target(self) ? 1 : 0;
}

zend_long phpgtk_gtkwidget_get_child_visible(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_get_child_visible(self) ? 1 : 0;
}

zend_long phpgtk_gtkwidget_get_clipboard(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_widget_get_clipboard(self));
}

void phpgtk_gtkwidget_get_color(zval *return_value, zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        array_init(return_value); return;
    }

    GdkRGBA color;

    gtk_widget_get_color(self, &color);
    phpgtk_ret_rgba(return_value, &color);
}

void phpgtk_gtkwidget_get_css_classes(zval *return_value, zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        array_init(return_value); return;
    }

    phpgtk_ret_strv_take(return_value, gtk_widget_get_css_classes(self));
}

void phpgtk_gtkwidget_get_css_name(zval *return_value, zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_widget_get_css_name(self));
}

zend_long phpgtk_gtkwidget_get_cursor(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_widget_get_cursor(self));
}

zend_long phpgtk_gtkwidget_get_direction(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_widget_get_direction(self);
}

zend_long phpgtk_gtkwidget_get_display(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_widget_get_display(self));
}

zend_long phpgtk_gtkwidget_get_first_child(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_widget_get_first_child(self));
}

zend_long phpgtk_gtkwidget_get_focus_child(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_widget_get_focus_child(self));
}

zend_long phpgtk_gtkwidget_get_focus_on_click(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_get_focus_on_click(self) ? 1 : 0;
}

zend_long phpgtk_gtkwidget_get_focusable(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_get_focusable(self) ? 1 : 0;
}

zend_long phpgtk_gtkwidget_get_font_map(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_widget_get_font_map(self));
}

zend_long phpgtk_gtkwidget_get_frame_clock(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_widget_get_frame_clock(self));
}

zend_long phpgtk_gtkwidget_get_halign(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_widget_get_halign(self);
}

zend_long phpgtk_gtkwidget_get_has_tooltip(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_get_has_tooltip(self) ? 1 : 0;
}

zend_long phpgtk_gtkwidget_get_height(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_widget_get_height(self);
}

zend_long phpgtk_gtkwidget_get_hexpand(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_get_hexpand(self) ? 1 : 0;
}

zend_long phpgtk_gtkwidget_get_hexpand_set(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_get_hexpand_set(self) ? 1 : 0;
}

zend_long phpgtk_gtkwidget_get_last_child(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_widget_get_last_child(self));
}

zend_long phpgtk_gtkwidget_get_layout_manager(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_widget_get_layout_manager(self));
}

zend_long phpgtk_gtkwidget_get_limit_events(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_get_limit_events(self) ? 1 : 0;
}

zend_long phpgtk_gtkwidget_get_mapped(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_get_mapped(self) ? 1 : 0;
}

zend_long phpgtk_gtkwidget_get_margin_bottom(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_widget_get_margin_bottom(self);
}

zend_long phpgtk_gtkwidget_get_margin_end(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_widget_get_margin_end(self);
}

zend_long phpgtk_gtkwidget_get_margin_start(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_widget_get_margin_start(self);
}

zend_long phpgtk_gtkwidget_get_margin_top(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_widget_get_margin_top(self);
}

void phpgtk_gtkwidget_get_name(zval *return_value, zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_widget_get_name(self));
}

zend_long phpgtk_gtkwidget_get_native(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_widget_get_native(self));
}

zend_long phpgtk_gtkwidget_get_next_sibling(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_widget_get_next_sibling(self));
}

double phpgtk_gtkwidget_get_opacity(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0.0;
    }

    return gtk_widget_get_opacity(self);
}

zend_long phpgtk_gtkwidget_get_overflow(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_widget_get_overflow(self);
}

zend_long phpgtk_gtkwidget_get_pango_context(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_widget_get_pango_context(self));
}

zend_long phpgtk_gtkwidget_get_parent(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_widget_get_parent(self));
}

void phpgtk_gtkwidget_get_preferred_size(zval *return_value, zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        array_init(return_value); return;
    }

    GtkRequisition minimum_size;
    GtkRequisition natural_size;

    gtk_widget_get_preferred_size(self, &minimum_size, &natural_size);
    array_init(return_value);
    {
        zval _tmp_minimum_size;
        phpgtk_ret_requisition(&_tmp_minimum_size, &minimum_size);
        add_assoc_zval(return_value, "minimum_size", &_tmp_minimum_size);
    }
    {
        zval _tmp_natural_size;
        phpgtk_ret_requisition(&_tmp_natural_size, &natural_size);
        add_assoc_zval(return_value, "natural_size", &_tmp_natural_size);
    }
}

zend_long phpgtk_gtkwidget_get_prev_sibling(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_widget_get_prev_sibling(self));
}

zend_long phpgtk_gtkwidget_get_primary_clipboard(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_widget_get_primary_clipboard(self));
}

zend_long phpgtk_gtkwidget_get_realized(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_get_realized(self) ? 1 : 0;
}

zend_long phpgtk_gtkwidget_get_receives_default(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_get_receives_default(self) ? 1 : 0;
}

zend_long phpgtk_gtkwidget_get_request_mode(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_widget_get_request_mode(self);
}

zend_long phpgtk_gtkwidget_get_root(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_widget_get_root(self));
}

zend_long phpgtk_gtkwidget_get_scale_factor(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_widget_get_scale_factor(self);
}

zend_long phpgtk_gtkwidget_get_sensitive(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_get_sensitive(self) ? 1 : 0;
}

zend_long phpgtk_gtkwidget_get_settings(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_widget_get_settings(self));
}

zend_long phpgtk_gtkwidget_get_size(zval *handle, zval *orientation)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_widget_get_size(self, (GtkOrientation) phpgtk_arg_long(orientation));
}

void phpgtk_gtkwidget_get_size_request(zval *return_value, zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        array_init(return_value); return;
    }

    int width = 0;
    int height = 0;

    gtk_widget_get_size_request(self, &width, &height);
    array_init(return_value);
    add_assoc_long(return_value, "width", width);
    add_assoc_long(return_value, "height", height);
}

zend_long phpgtk_gtkwidget_get_state_flags(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_widget_get_state_flags(self);
}

zend_long phpgtk_gtkwidget_get_template_child(zval *handle, zval *widgetType, zval *name)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_widget_get_template_child(self, (GType) phpgtk_arg_long(widgetType), phpgtk_arg_string(name)));
}

void phpgtk_gtkwidget_get_tooltip_markup(zval *return_value, zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_widget_get_tooltip_markup(self));
}

void phpgtk_gtkwidget_get_tooltip_text(zval *return_value, zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_widget_get_tooltip_text(self));
}

zend_long phpgtk_gtkwidget_get_valign(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_widget_get_valign(self);
}

zend_long phpgtk_gtkwidget_get_vexpand(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_get_vexpand(self) ? 1 : 0;
}

zend_long phpgtk_gtkwidget_get_vexpand_set(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_get_vexpand_set(self) ? 1 : 0;
}

zend_long phpgtk_gtkwidget_get_visible(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_get_visible(self) ? 1 : 0;
}

zend_long phpgtk_gtkwidget_get_width(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_widget_get_width(self);
}

zend_long phpgtk_gtkwidget_grab_focus(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_grab_focus(self) ? 1 : 0;
}

zend_long phpgtk_gtkwidget_has_css_class(zval *handle, zval *cssClass)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_has_css_class(self, phpgtk_arg_string(cssClass)) ? 1 : 0;
}

zend_long phpgtk_gtkwidget_has_default(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_has_default(self) ? 1 : 0;
}

zend_long phpgtk_gtkwidget_has_focus(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_has_focus(self) ? 1 : 0;
}

zend_long phpgtk_gtkwidget_has_visible_focus(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_has_visible_focus(self) ? 1 : 0;
}

zend_long phpgtk_gtkwidget_in_destruction(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_in_destruction(self) ? 1 : 0;
}

void phpgtk_gtkwidget_init_template(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_init_template(self);
}

void phpgtk_gtkwidget_insert_action_group(zval *handle, zval *name, zval *group)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_insert_action_group(self, phpgtk_arg_string(name), phpgtk_arg_object(group));
}

void phpgtk_gtkwidget_insert_after(zval *handle, zval *parent, zval *previousSibling)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_insert_after(self, phpgtk_arg_object(parent), phpgtk_arg_object(previousSibling));
}

void phpgtk_gtkwidget_insert_before(zval *handle, zval *parent, zval *nextSibling)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_insert_before(self, phpgtk_arg_object(parent), phpgtk_arg_object(nextSibling));
}

zend_long phpgtk_gtkwidget_is_ancestor(zval *handle, zval *ancestor)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_is_ancestor(self, phpgtk_arg_object(ancestor)) ? 1 : 0;
}

zend_long phpgtk_gtkwidget_is_drawable(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_is_drawable(self) ? 1 : 0;
}

zend_long phpgtk_gtkwidget_is_focus(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_is_focus(self) ? 1 : 0;
}

zend_long phpgtk_gtkwidget_is_sensitive(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_is_sensitive(self) ? 1 : 0;
}

zend_long phpgtk_gtkwidget_is_visible(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_is_visible(self) ? 1 : 0;
}

zend_long phpgtk_gtkwidget_keynav_failed(zval *handle, zval *direction)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_keynav_failed(self, (GtkDirectionType) phpgtk_arg_long(direction)) ? 1 : 0;
}

void phpgtk_gtkwidget_list_mnemonic_labels(zval *return_value, zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        array_init(return_value); return;
    }

    phpgtk_ret_object_glist(return_value, gtk_widget_list_mnemonic_labels(self), TRUE, FALSE);
}

void phpgtk_gtkwidget_map(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_map(self);
}

void phpgtk_gtkwidget_measure(zval *return_value, zval *handle, zval *orientation, zval *forSize)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        array_init(return_value); return;
    }

    int minimum = 0;
    int natural = 0;
    int minimum_baseline = 0;
    int natural_baseline = 0;

    gtk_widget_measure(self, (GtkOrientation) phpgtk_arg_long(orientation), phpgtk_arg_long(forSize), &minimum, &natural, &minimum_baseline, &natural_baseline);
    array_init(return_value);
    add_assoc_long(return_value, "minimum", minimum);
    add_assoc_long(return_value, "natural", natural);
    add_assoc_long(return_value, "minimum_baseline", minimum_baseline);
    add_assoc_long(return_value, "natural_baseline", natural_baseline);
}

zend_long phpgtk_gtkwidget_mnemonic_activate(zval *handle, zval *groupCycling)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_mnemonic_activate(self, phpgtk_arg_bool(groupCycling)) ? 1 : 0;
}

zend_long phpgtk_gtkwidget_observe_children(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register_take(gtk_widget_observe_children(self));
}

zend_long phpgtk_gtkwidget_observe_controllers(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register_take(gtk_widget_observe_controllers(self));
}

zend_long phpgtk_gtkwidget_pick(zval *handle, zval *x, zval *y, zval *flags)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_widget_pick(self, phpgtk_arg_double(x), phpgtk_arg_double(y), (GtkPickFlags) phpgtk_arg_long(flags)));
}

void phpgtk_gtkwidget_queue_allocate(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_queue_allocate(self);
}

void phpgtk_gtkwidget_queue_draw(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_queue_draw(self);
}

void phpgtk_gtkwidget_queue_resize(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_queue_resize(self);
}

void phpgtk_gtkwidget_realize(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_realize(self);
}

void phpgtk_gtkwidget_remove_controller(zval *handle, zval *controller)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_remove_controller(self, phpgtk_arg_object(controller));
}

void phpgtk_gtkwidget_remove_css_class(zval *handle, zval *cssClass)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_remove_css_class(self, phpgtk_arg_string(cssClass));
}

void phpgtk_gtkwidget_remove_mnemonic_label(zval *handle, zval *label)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_remove_mnemonic_label(self, phpgtk_arg_object(label));
}

void phpgtk_gtkwidget_remove_tick_callback(zval *handle, zval *id)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_remove_tick_callback(self, (guint) phpgtk_arg_long(id));
}

void phpgtk_gtkwidget_set_can_focus(zval *handle, zval *canFocus)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_can_focus(self, phpgtk_arg_bool(canFocus));
}

void phpgtk_gtkwidget_set_can_target(zval *handle, zval *canTarget)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_can_target(self, phpgtk_arg_bool(canTarget));
}

void phpgtk_gtkwidget_set_child_visible(zval *handle, zval *childVisible)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_child_visible(self, phpgtk_arg_bool(childVisible));
}

void phpgtk_gtkwidget_set_css_classes(zval *handle, zval *classes)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    char **c_classes = phpgtk_zval_to_strv(classes);

    gtk_widget_set_css_classes(self, c_classes);
    phpgtk_strv_free(c_classes);
}

void phpgtk_gtkwidget_set_cursor(zval *handle, zval *cursor)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_cursor(self, phpgtk_arg_object(cursor));
}

void phpgtk_gtkwidget_set_cursor_from_name(zval *handle, zval *name)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_cursor_from_name(self, phpgtk_arg_string(name));
}

void phpgtk_gtkwidget_set_direction(zval *handle, zval *dir)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_direction(self, (GtkTextDirection) phpgtk_arg_long(dir));
}

void phpgtk_gtkwidget_set_focus_child(zval *handle, zval *child)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_focus_child(self, phpgtk_arg_object(child));
}

void phpgtk_gtkwidget_set_focus_on_click(zval *handle, zval *focusOnClick)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_focus_on_click(self, phpgtk_arg_bool(focusOnClick));
}

void phpgtk_gtkwidget_set_focusable(zval *handle, zval *focusable)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_focusable(self, phpgtk_arg_bool(focusable));
}

void phpgtk_gtkwidget_set_font_map(zval *handle, zval *fontMap)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_font_map(self, phpgtk_arg_object(fontMap));
}

void phpgtk_gtkwidget_set_halign(zval *handle, zval *align)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_halign(self, (GtkAlign) phpgtk_arg_long(align));
}

void phpgtk_gtkwidget_set_has_tooltip(zval *handle, zval *hasTooltip)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_has_tooltip(self, phpgtk_arg_bool(hasTooltip));
}

void phpgtk_gtkwidget_set_hexpand(zval *handle, zval *expand)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_hexpand(self, phpgtk_arg_bool(expand));
}

void phpgtk_gtkwidget_set_hexpand_set(zval *handle, zval *set)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_hexpand_set(self, phpgtk_arg_bool(set));
}

void phpgtk_gtkwidget_set_layout_manager(zval *handle, zval *layoutManager)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_layout_manager(self, phpgtk_arg_object_give(layoutManager));
}

void phpgtk_gtkwidget_set_limit_events(zval *handle, zval *limitEvents)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_limit_events(self, phpgtk_arg_bool(limitEvents));
}

void phpgtk_gtkwidget_set_margin_bottom(zval *handle, zval *margin)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_margin_bottom(self, phpgtk_arg_long(margin));
}

void phpgtk_gtkwidget_set_margin_end(zval *handle, zval *margin)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_margin_end(self, phpgtk_arg_long(margin));
}

void phpgtk_gtkwidget_set_margin_start(zval *handle, zval *margin)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_margin_start(self, phpgtk_arg_long(margin));
}

void phpgtk_gtkwidget_set_margin_top(zval *handle, zval *margin)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_margin_top(self, phpgtk_arg_long(margin));
}

void phpgtk_gtkwidget_set_name(zval *handle, zval *name)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_name(self, phpgtk_arg_string(name));
}

void phpgtk_gtkwidget_set_opacity(zval *handle, zval *opacity)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_opacity(self, phpgtk_arg_double(opacity));
}

void phpgtk_gtkwidget_set_overflow(zval *handle, zval *overflow)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_overflow(self, (GtkOverflow) phpgtk_arg_long(overflow));
}

void phpgtk_gtkwidget_set_parent(zval *handle, zval *parent)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_parent(self, phpgtk_arg_object(parent));
}

void phpgtk_gtkwidget_set_receives_default(zval *handle, zval *receivesDefault)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_receives_default(self, phpgtk_arg_bool(receivesDefault));
}

void phpgtk_gtkwidget_set_sensitive(zval *handle, zval *sensitive)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_sensitive(self, phpgtk_arg_bool(sensitive));
}

void phpgtk_gtkwidget_set_size_request(zval *handle, zval *width, zval *height)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_size_request(self, phpgtk_arg_long(width), phpgtk_arg_long(height));
}

void phpgtk_gtkwidget_set_state_flags(zval *handle, zval *flags, zval *clear)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_state_flags(self, (GtkStateFlags) phpgtk_arg_long(flags), phpgtk_arg_bool(clear));
}

void phpgtk_gtkwidget_set_tooltip_markup(zval *handle, zval *markup)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_tooltip_markup(self, phpgtk_arg_string(markup));
}

void phpgtk_gtkwidget_set_tooltip_text(zval *handle, zval *text)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_tooltip_text(self, phpgtk_arg_string(text));
}

void phpgtk_gtkwidget_set_valign(zval *handle, zval *align)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_valign(self, (GtkAlign) phpgtk_arg_long(align));
}

void phpgtk_gtkwidget_set_vexpand(zval *handle, zval *expand)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_vexpand(self, phpgtk_arg_bool(expand));
}

void phpgtk_gtkwidget_set_vexpand_set(zval *handle, zval *set)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_vexpand_set(self, phpgtk_arg_bool(set));
}

void phpgtk_gtkwidget_set_visible(zval *handle, zval *visible)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_set_visible(self, phpgtk_arg_bool(visible));
}

zend_long phpgtk_gtkwidget_should_layout(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_widget_should_layout(self) ? 1 : 0;
}

void phpgtk_gtkwidget_size_allocate(zval *handle, zval *allocationX, zval *allocationY, zval *allocationWidth, zval *allocationHeight, zval *baseline)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    GtkAllocation c_allocation;

    c_allocation.x = (int) phpgtk_arg_long(allocationX);
    c_allocation.y = (int) phpgtk_arg_long(allocationY);
    c_allocation.width = (int) phpgtk_arg_long(allocationWidth);
    c_allocation.height = (int) phpgtk_arg_long(allocationHeight);
    gtk_widget_size_allocate(self, &c_allocation, phpgtk_arg_long(baseline));
}

void phpgtk_gtkwidget_snapshot_child(zval *handle, zval *child, zval *snapshot)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_snapshot_child(self, phpgtk_arg_object(child), phpgtk_arg_object(snapshot));
}

void phpgtk_gtkwidget_trigger_tooltip_query(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_trigger_tooltip_query(self);
}

void phpgtk_gtkwidget_unmap(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_unmap(self);
}

void phpgtk_gtkwidget_unparent(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_unparent(self);
}

void phpgtk_gtkwidget_unrealize(zval *handle)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_unrealize(self);
}

void phpgtk_gtkwidget_unset_state_flags(zval *handle, zval *flags)
{
    GtkWidget *self = PHPGTK_ARG_AS(GtkWidget, GTK_TYPE_WIDGET, handle);

    if (self == NULL) {
        return;
    }

    gtk_widget_unset_state_flags(self, (GtkStateFlags) phpgtk_arg_long(flags));
}
