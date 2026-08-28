#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-label.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtklabel_new(zval *str)
{
    return phpgtk_handle_register(gtk_label_new(phpgtk_arg_string(str)));
}

zend_long phpgtk_gtklabel_new_with_mnemonic(zval *str)
{
    return phpgtk_handle_register(gtk_label_new_with_mnemonic(phpgtk_arg_string(str)));
}

void phpgtk_gtklabel_get_current_uri(zval *return_value, zval *handle)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_label_get_current_uri(self));
}

zend_long phpgtk_gtklabel_get_ellipsize(zval *handle)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_label_get_ellipsize(self);
}

zend_long phpgtk_gtklabel_get_extra_menu(zval *handle)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_label_get_extra_menu(self));
}

zend_long phpgtk_gtklabel_get_justify(zval *handle)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_label_get_justify(self);
}

void phpgtk_gtklabel_get_label(zval *return_value, zval *handle)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_label_get_label(self));
}

zend_long phpgtk_gtklabel_get_layout(zval *handle)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_label_get_layout(self));
}

void phpgtk_gtklabel_get_layout_offsets(zval *return_value, zval *handle)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);
    int x = 0;
    int y = 0;

    if (self == NULL) {
        array_init(return_value); return;
    }

    gtk_label_get_layout_offsets(self, &x, &y);
    array_init(return_value);
    add_assoc_long(return_value, "x", x);
    add_assoc_long(return_value, "y", y);
}

zend_long phpgtk_gtklabel_get_lines(zval *handle)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_label_get_lines(self);
}

zend_long phpgtk_gtklabel_get_max_width_chars(zval *handle)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_label_get_max_width_chars(self);
}

zend_long phpgtk_gtklabel_get_mnemonic_keyval(zval *handle)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_label_get_mnemonic_keyval(self);
}

zend_long phpgtk_gtklabel_get_mnemonic_widget(zval *handle)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_label_get_mnemonic_widget(self));
}

zend_long phpgtk_gtklabel_get_natural_wrap_mode(zval *handle)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_label_get_natural_wrap_mode(self);
}

zend_long phpgtk_gtklabel_get_selectable(zval *handle)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_label_get_selectable(self) ? 1 : 0;
}

void phpgtk_gtklabel_get_selection_bounds(zval *return_value, zval *handle)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);
    int start = 0;
    int end = 0;

    if (self == NULL) {
        array_init(return_value); return;
    }

    gtk_label_get_selection_bounds(self, &start, &end);
    array_init(return_value);
    add_assoc_long(return_value, "start", start);
    add_assoc_long(return_value, "end", end);
}

zend_long phpgtk_gtklabel_get_single_line_mode(zval *handle)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_label_get_single_line_mode(self) ? 1 : 0;
}

void phpgtk_gtklabel_get_text(zval *return_value, zval *handle)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_label_get_text(self));
}

zend_long phpgtk_gtklabel_get_use_markup(zval *handle)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_label_get_use_markup(self) ? 1 : 0;
}

zend_long phpgtk_gtklabel_get_use_underline(zval *handle)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_label_get_use_underline(self) ? 1 : 0;
}

zend_long phpgtk_gtklabel_get_width_chars(zval *handle)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_label_get_width_chars(self);
}

zend_long phpgtk_gtklabel_get_wrap(zval *handle)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_label_get_wrap(self) ? 1 : 0;
}

zend_long phpgtk_gtklabel_get_wrap_mode(zval *handle)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_label_get_wrap_mode(self);
}

double phpgtk_gtklabel_get_xalign(zval *handle)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return 0.0;
    }

    return (double) gtk_label_get_xalign(self);
}

double phpgtk_gtklabel_get_yalign(zval *handle)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return 0.0;
    }

    return (double) gtk_label_get_yalign(self);
}

void phpgtk_gtklabel_select_region(zval *handle, zval *startOffset, zval *endOffset)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return;
    }

    gtk_label_select_region(self, (int) phpgtk_arg_long(startOffset), (int) phpgtk_arg_long(endOffset));
}

void phpgtk_gtklabel_set_ellipsize(zval *handle, zval *mode)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return;
    }

    gtk_label_set_ellipsize(self, (PangoEllipsizeMode) phpgtk_arg_long(mode));
}

void phpgtk_gtklabel_set_extra_menu(zval *handle, zval *model)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return;
    }

    gtk_label_set_extra_menu(self, phpgtk_arg_object(model));
}

void phpgtk_gtklabel_set_justify(zval *handle, zval *jtype)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return;
    }

    gtk_label_set_justify(self, (GtkJustification) phpgtk_arg_long(jtype));
}

void phpgtk_gtklabel_set_label(zval *handle, zval *str)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return;
    }

    gtk_label_set_label(self, phpgtk_arg_string(str));
}

void phpgtk_gtklabel_set_lines(zval *handle, zval *lines)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return;
    }

    gtk_label_set_lines(self, (int) phpgtk_arg_long(lines));
}

void phpgtk_gtklabel_set_markup(zval *handle, zval *str)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return;
    }

    gtk_label_set_markup(self, phpgtk_arg_string(str));
}

void phpgtk_gtklabel_set_markup_with_mnemonic(zval *handle, zval *str)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return;
    }

    gtk_label_set_markup_with_mnemonic(self, phpgtk_arg_string(str));
}

void phpgtk_gtklabel_set_max_width_chars(zval *handle, zval *nChars)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return;
    }

    gtk_label_set_max_width_chars(self, (int) phpgtk_arg_long(nChars));
}

void phpgtk_gtklabel_set_mnemonic_widget(zval *handle, zval *widget)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return;
    }

    gtk_label_set_mnemonic_widget(self, phpgtk_arg_object(widget));
}

void phpgtk_gtklabel_set_natural_wrap_mode(zval *handle, zval *wrapMode)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return;
    }

    gtk_label_set_natural_wrap_mode(self, (GtkNaturalWrapMode) phpgtk_arg_long(wrapMode));
}

void phpgtk_gtklabel_set_selectable(zval *handle, zval *setting)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return;
    }

    gtk_label_set_selectable(self, phpgtk_arg_bool(setting));
}

void phpgtk_gtklabel_set_single_line_mode(zval *handle, zval *singleLineMode)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return;
    }

    gtk_label_set_single_line_mode(self, phpgtk_arg_bool(singleLineMode));
}

void phpgtk_gtklabel_set_text(zval *handle, zval *str)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return;
    }

    gtk_label_set_text(self, phpgtk_arg_string(str));
}

void phpgtk_gtklabel_set_text_with_mnemonic(zval *handle, zval *str)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return;
    }

    gtk_label_set_text_with_mnemonic(self, phpgtk_arg_string(str));
}

void phpgtk_gtklabel_set_use_markup(zval *handle, zval *setting)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return;
    }

    gtk_label_set_use_markup(self, phpgtk_arg_bool(setting));
}

void phpgtk_gtklabel_set_use_underline(zval *handle, zval *setting)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return;
    }

    gtk_label_set_use_underline(self, phpgtk_arg_bool(setting));
}

void phpgtk_gtklabel_set_width_chars(zval *handle, zval *nChars)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return;
    }

    gtk_label_set_width_chars(self, (int) phpgtk_arg_long(nChars));
}

void phpgtk_gtklabel_set_wrap(zval *handle, zval *wrap)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return;
    }

    gtk_label_set_wrap(self, phpgtk_arg_bool(wrap));
}

void phpgtk_gtklabel_set_wrap_mode(zval *handle, zval *wrapMode)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return;
    }

    gtk_label_set_wrap_mode(self, (PangoWrapMode) phpgtk_arg_long(wrapMode));
}

void phpgtk_gtklabel_set_xalign(zval *handle, zval *xalign)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return;
    }

    gtk_label_set_xalign(self, (float) phpgtk_arg_double(xalign));
}

void phpgtk_gtklabel_set_yalign(zval *handle, zval *yalign)
{
    GtkLabel *self = PHPGTK_ARG_AS(GtkLabel, GTK_TYPE_LABEL, handle);

    if (self == NULL) {
        return;
    }

    gtk_label_set_yalign(self, (float) phpgtk_arg_double(yalign));
}
