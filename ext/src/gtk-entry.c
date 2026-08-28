#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-entry.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkentry_new(void)
{
    return phpgtk_handle_register(gtk_entry_new());
}

zend_long phpgtk_gtkentry_new_with_buffer(zval *buffer)
{
    return phpgtk_handle_register(gtk_entry_new_with_buffer(phpgtk_arg_object(buffer)));
}

zend_long phpgtk_gtkentry_get_activates_default(zval *handle)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_entry_get_activates_default(self) ? 1 : 0;
}

double phpgtk_gtkentry_get_alignment(zval *handle)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return 0.0;
    }

    return (double) gtk_entry_get_alignment(self);
}

zend_long phpgtk_gtkentry_get_buffer(zval *handle)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_entry_get_buffer(self));
}

zend_long phpgtk_gtkentry_get_current_icon_drag_source(zval *handle)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_entry_get_current_icon_drag_source(self);
}

zend_long phpgtk_gtkentry_get_extra_menu(zval *handle)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_entry_get_extra_menu(self));
}

zend_long phpgtk_gtkentry_get_has_frame(zval *handle)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_entry_get_has_frame(self) ? 1 : 0;
}

zend_long phpgtk_gtkentry_get_icon_activatable(zval *handle, zval *iconPos)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_entry_get_icon_activatable(self, (GtkEntryIconPosition) phpgtk_arg_long(iconPos)) ? 1 : 0;
}

void phpgtk_gtkentry_get_icon_area(zval *return_value, zval *handle, zval *iconPos)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);
    GdkRectangle icon_area;

    if (self == NULL) {
        array_init(return_value); return;
    }

    gtk_entry_get_icon_area(self, (GtkEntryIconPosition) phpgtk_arg_long(iconPos), &icon_area);
    phpgtk_ret_rectangle(return_value, &icon_area);
}

zend_long phpgtk_gtkentry_get_icon_at_pos(zval *handle, zval *x, zval *y)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_entry_get_icon_at_pos(self, (int) phpgtk_arg_long(x), (int) phpgtk_arg_long(y));
}

zend_long phpgtk_gtkentry_get_icon_gicon(zval *handle, zval *iconPos)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_entry_get_icon_gicon(self, (GtkEntryIconPosition) phpgtk_arg_long(iconPos)));
}

void phpgtk_gtkentry_get_icon_name(zval *return_value, zval *handle, zval *iconPos)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_entry_get_icon_name(self, (GtkEntryIconPosition) phpgtk_arg_long(iconPos)));
}

zend_long phpgtk_gtkentry_get_icon_paintable(zval *handle, zval *iconPos)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_entry_get_icon_paintable(self, (GtkEntryIconPosition) phpgtk_arg_long(iconPos)));
}

zend_long phpgtk_gtkentry_get_icon_sensitive(zval *handle, zval *iconPos)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_entry_get_icon_sensitive(self, (GtkEntryIconPosition) phpgtk_arg_long(iconPos)) ? 1 : 0;
}

zend_long phpgtk_gtkentry_get_icon_storage_type(zval *handle, zval *iconPos)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_entry_get_icon_storage_type(self, (GtkEntryIconPosition) phpgtk_arg_long(iconPos));
}

void phpgtk_gtkentry_get_icon_tooltip_markup(zval *return_value, zval *handle, zval *iconPos)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string_take(return_value, gtk_entry_get_icon_tooltip_markup(self, (GtkEntryIconPosition) phpgtk_arg_long(iconPos)));
}

void phpgtk_gtkentry_get_icon_tooltip_text(zval *return_value, zval *handle, zval *iconPos)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string_take(return_value, gtk_entry_get_icon_tooltip_text(self, (GtkEntryIconPosition) phpgtk_arg_long(iconPos)));
}

zend_long phpgtk_gtkentry_get_input_hints(zval *handle)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_entry_get_input_hints(self);
}

zend_long phpgtk_gtkentry_get_input_purpose(zval *handle)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_entry_get_input_purpose(self);
}

zend_long phpgtk_gtkentry_get_invisible_char(zval *handle)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_entry_get_invisible_char(self);
}

zend_long phpgtk_gtkentry_get_max_length(zval *handle)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_entry_get_max_length(self);
}

zend_long phpgtk_gtkentry_get_overwrite_mode(zval *handle)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_entry_get_overwrite_mode(self) ? 1 : 0;
}

void phpgtk_gtkentry_get_placeholder_text(zval *return_value, zval *handle)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_entry_get_placeholder_text(self));
}

double phpgtk_gtkentry_get_progress_fraction(zval *handle)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return 0.0;
    }

    return gtk_entry_get_progress_fraction(self);
}

double phpgtk_gtkentry_get_progress_pulse_step(zval *handle)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return 0.0;
    }

    return gtk_entry_get_progress_pulse_step(self);
}

zend_long phpgtk_gtkentry_get_text_length(zval *handle)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_entry_get_text_length(self);
}

zend_long phpgtk_gtkentry_get_visibility(zval *handle)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_entry_get_visibility(self) ? 1 : 0;
}

zend_long phpgtk_gtkentry_grab_focus_without_selecting(zval *handle)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_entry_grab_focus_without_selecting(self) ? 1 : 0;
}

void phpgtk_gtkentry_progress_pulse(zval *handle)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return;
    }

    gtk_entry_progress_pulse(self);
}

void phpgtk_gtkentry_reset_im_context(zval *handle)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return;
    }

    gtk_entry_reset_im_context(self);
}

void phpgtk_gtkentry_set_activates_default(zval *handle, zval *setting)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return;
    }

    gtk_entry_set_activates_default(self, phpgtk_arg_bool(setting));
}

void phpgtk_gtkentry_set_alignment(zval *handle, zval *xalign)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return;
    }

    gtk_entry_set_alignment(self, (float) phpgtk_arg_double(xalign));
}

void phpgtk_gtkentry_set_buffer(zval *handle, zval *buffer)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return;
    }

    gtk_entry_set_buffer(self, phpgtk_arg_object(buffer));
}

void phpgtk_gtkentry_set_extra_menu(zval *handle, zval *model)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return;
    }

    gtk_entry_set_extra_menu(self, phpgtk_arg_object(model));
}

void phpgtk_gtkentry_set_has_frame(zval *handle, zval *setting)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return;
    }

    gtk_entry_set_has_frame(self, phpgtk_arg_bool(setting));
}

void phpgtk_gtkentry_set_icon_activatable(zval *handle, zval *iconPos, zval *activatable)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return;
    }

    gtk_entry_set_icon_activatable(self, (GtkEntryIconPosition) phpgtk_arg_long(iconPos), phpgtk_arg_bool(activatable));
}

void phpgtk_gtkentry_set_icon_from_gicon(zval *handle, zval *iconPos, zval *icon)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return;
    }

    gtk_entry_set_icon_from_gicon(self, (GtkEntryIconPosition) phpgtk_arg_long(iconPos), phpgtk_arg_object(icon));
}

void phpgtk_gtkentry_set_icon_from_icon_name(zval *handle, zval *iconPos, zval *iconName)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return;
    }

    gtk_entry_set_icon_from_icon_name(self, (GtkEntryIconPosition) phpgtk_arg_long(iconPos), phpgtk_arg_string(iconName));
}

void phpgtk_gtkentry_set_icon_from_paintable(zval *handle, zval *iconPos, zval *paintable)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return;
    }

    gtk_entry_set_icon_from_paintable(self, (GtkEntryIconPosition) phpgtk_arg_long(iconPos), phpgtk_arg_object(paintable));
}

void phpgtk_gtkentry_set_icon_sensitive(zval *handle, zval *iconPos, zval *sensitive)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return;
    }

    gtk_entry_set_icon_sensitive(self, (GtkEntryIconPosition) phpgtk_arg_long(iconPos), phpgtk_arg_bool(sensitive));
}

void phpgtk_gtkentry_set_icon_tooltip_markup(zval *handle, zval *iconPos, zval *tooltip)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return;
    }

    gtk_entry_set_icon_tooltip_markup(self, (GtkEntryIconPosition) phpgtk_arg_long(iconPos), phpgtk_arg_string(tooltip));
}

void phpgtk_gtkentry_set_icon_tooltip_text(zval *handle, zval *iconPos, zval *tooltip)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return;
    }

    gtk_entry_set_icon_tooltip_text(self, (GtkEntryIconPosition) phpgtk_arg_long(iconPos), phpgtk_arg_string(tooltip));
}

void phpgtk_gtkentry_set_input_hints(zval *handle, zval *hints)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return;
    }

    gtk_entry_set_input_hints(self, (GtkInputHints) phpgtk_arg_long(hints));
}

void phpgtk_gtkentry_set_input_purpose(zval *handle, zval *purpose)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return;
    }

    gtk_entry_set_input_purpose(self, (GtkInputPurpose) phpgtk_arg_long(purpose));
}

void phpgtk_gtkentry_set_invisible_char(zval *handle, zval *ch)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return;
    }

    gtk_entry_set_invisible_char(self, (gunichar) phpgtk_arg_long(ch));
}

void phpgtk_gtkentry_set_max_length(zval *handle, zval *max)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return;
    }

    gtk_entry_set_max_length(self, (int) phpgtk_arg_long(max));
}

void phpgtk_gtkentry_set_overwrite_mode(zval *handle, zval *overwrite)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return;
    }

    gtk_entry_set_overwrite_mode(self, phpgtk_arg_bool(overwrite));
}

void phpgtk_gtkentry_set_placeholder_text(zval *handle, zval *text)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return;
    }

    gtk_entry_set_placeholder_text(self, phpgtk_arg_string(text));
}

void phpgtk_gtkentry_set_progress_fraction(zval *handle, zval *fraction)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return;
    }

    gtk_entry_set_progress_fraction(self, phpgtk_arg_double(fraction));
}

void phpgtk_gtkentry_set_progress_pulse_step(zval *handle, zval *fraction)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return;
    }

    gtk_entry_set_progress_pulse_step(self, phpgtk_arg_double(fraction));
}

void phpgtk_gtkentry_set_visibility(zval *handle, zval *visible)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return;
    }

    gtk_entry_set_visibility(self, phpgtk_arg_bool(visible));
}

void phpgtk_gtkentry_unset_invisible_char(zval *handle)
{
    GtkEntry *self = PHPGTK_ARG_AS(GtkEntry, GTK_TYPE_ENTRY, handle);

    if (self == NULL) {
        return;
    }

    gtk_entry_unset_invisible_char(self);
}
