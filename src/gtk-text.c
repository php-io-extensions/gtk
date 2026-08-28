#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-text.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtktext_new(void)
{
    return phpgtk_handle_register(gtk_text_new());
}

zend_long phpgtk_gtktext_new_with_buffer(zval *buffer)
{
    return phpgtk_handle_register(gtk_text_new_with_buffer(phpgtk_arg_object(buffer)));
}

void phpgtk_gtktext_compute_cursor_extents(zval *return_value, zval *handle, zval *position)
{
    GtkText *self = PHPGTK_ARG_AS(GtkText, GTK_TYPE_TEXT, handle);
    graphene_rect_t strong;
    graphene_rect_t weak;

    if (self == NULL) {
        array_init(return_value); return;
    }

    gtk_text_compute_cursor_extents(self, (gsize) phpgtk_arg_long(position), &strong, &weak);
    array_init(return_value);
    {
        zval _tmp_strong;
        phpgtk_ret_graphene_rect(&_tmp_strong, &strong);
        add_assoc_zval(return_value, "strong", &_tmp_strong);
    }
    {
        zval _tmp_weak;
        phpgtk_ret_graphene_rect(&_tmp_weak, &weak);
        add_assoc_zval(return_value, "weak", &_tmp_weak);
    }
}

zend_long phpgtk_gtktext_get_activates_default(zval *handle)
{
    GtkText *self = PHPGTK_ARG_AS(GtkText, GTK_TYPE_TEXT, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_text_get_activates_default(self) ? 1 : 0;
}

zend_long phpgtk_gtktext_get_buffer(zval *handle)
{
    GtkText *self = PHPGTK_ARG_AS(GtkText, GTK_TYPE_TEXT, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_text_get_buffer(self));
}

zend_long phpgtk_gtktext_get_enable_emoji_completion(zval *handle)
{
    GtkText *self = PHPGTK_ARG_AS(GtkText, GTK_TYPE_TEXT, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_text_get_enable_emoji_completion(self) ? 1 : 0;
}

zend_long phpgtk_gtktext_get_extra_menu(zval *handle)
{
    GtkText *self = PHPGTK_ARG_AS(GtkText, GTK_TYPE_TEXT, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_text_get_extra_menu(self));
}

zend_long phpgtk_gtktext_get_input_hints(zval *handle)
{
    GtkText *self = PHPGTK_ARG_AS(GtkText, GTK_TYPE_TEXT, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_text_get_input_hints(self);
}

zend_long phpgtk_gtktext_get_input_purpose(zval *handle)
{
    GtkText *self = PHPGTK_ARG_AS(GtkText, GTK_TYPE_TEXT, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_text_get_input_purpose(self);
}

zend_long phpgtk_gtktext_get_invisible_char(zval *handle)
{
    GtkText *self = PHPGTK_ARG_AS(GtkText, GTK_TYPE_TEXT, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_text_get_invisible_char(self);
}

zend_long phpgtk_gtktext_get_max_length(zval *handle)
{
    GtkText *self = PHPGTK_ARG_AS(GtkText, GTK_TYPE_TEXT, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_text_get_max_length(self);
}

zend_long phpgtk_gtktext_get_overwrite_mode(zval *handle)
{
    GtkText *self = PHPGTK_ARG_AS(GtkText, GTK_TYPE_TEXT, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_text_get_overwrite_mode(self) ? 1 : 0;
}

void phpgtk_gtktext_get_placeholder_text(zval *return_value, zval *handle)
{
    GtkText *self = PHPGTK_ARG_AS(GtkText, GTK_TYPE_TEXT, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_text_get_placeholder_text(self));
}

zend_long phpgtk_gtktext_get_propagate_text_width(zval *handle)
{
    GtkText *self = PHPGTK_ARG_AS(GtkText, GTK_TYPE_TEXT, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_text_get_propagate_text_width(self) ? 1 : 0;
}

zend_long phpgtk_gtktext_get_text_length(zval *handle)
{
    GtkText *self = PHPGTK_ARG_AS(GtkText, GTK_TYPE_TEXT, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_text_get_text_length(self);
}

zend_long phpgtk_gtktext_get_truncate_multiline(zval *handle)
{
    GtkText *self = PHPGTK_ARG_AS(GtkText, GTK_TYPE_TEXT, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_text_get_truncate_multiline(self) ? 1 : 0;
}

zend_long phpgtk_gtktext_get_visibility(zval *handle)
{
    GtkText *self = PHPGTK_ARG_AS(GtkText, GTK_TYPE_TEXT, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_text_get_visibility(self) ? 1 : 0;
}

zend_long phpgtk_gtktext_grab_focus_without_selecting(zval *handle)
{
    GtkText *self = PHPGTK_ARG_AS(GtkText, GTK_TYPE_TEXT, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_text_grab_focus_without_selecting(self) ? 1 : 0;
}

void phpgtk_gtktext_set_activates_default(zval *handle, zval *activates)
{
    GtkText *self = PHPGTK_ARG_AS(GtkText, GTK_TYPE_TEXT, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_set_activates_default(self, phpgtk_arg_bool(activates));
}

void phpgtk_gtktext_set_buffer(zval *handle, zval *buffer)
{
    GtkText *self = PHPGTK_ARG_AS(GtkText, GTK_TYPE_TEXT, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_set_buffer(self, phpgtk_arg_object(buffer));
}

void phpgtk_gtktext_set_enable_emoji_completion(zval *handle, zval *enableEmojiCompletion)
{
    GtkText *self = PHPGTK_ARG_AS(GtkText, GTK_TYPE_TEXT, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_set_enable_emoji_completion(self, phpgtk_arg_bool(enableEmojiCompletion));
}

void phpgtk_gtktext_set_extra_menu(zval *handle, zval *model)
{
    GtkText *self = PHPGTK_ARG_AS(GtkText, GTK_TYPE_TEXT, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_set_extra_menu(self, phpgtk_arg_object(model));
}

void phpgtk_gtktext_set_input_hints(zval *handle, zval *hints)
{
    GtkText *self = PHPGTK_ARG_AS(GtkText, GTK_TYPE_TEXT, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_set_input_hints(self, (GtkInputHints) phpgtk_arg_long(hints));
}

void phpgtk_gtktext_set_input_purpose(zval *handle, zval *purpose)
{
    GtkText *self = PHPGTK_ARG_AS(GtkText, GTK_TYPE_TEXT, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_set_input_purpose(self, (GtkInputPurpose) phpgtk_arg_long(purpose));
}

void phpgtk_gtktext_set_invisible_char(zval *handle, zval *ch)
{
    GtkText *self = PHPGTK_ARG_AS(GtkText, GTK_TYPE_TEXT, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_set_invisible_char(self, (gunichar) phpgtk_arg_long(ch));
}

void phpgtk_gtktext_set_max_length(zval *handle, zval *length)
{
    GtkText *self = PHPGTK_ARG_AS(GtkText, GTK_TYPE_TEXT, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_set_max_length(self, (int) phpgtk_arg_long(length));
}

void phpgtk_gtktext_set_overwrite_mode(zval *handle, zval *overwrite)
{
    GtkText *self = PHPGTK_ARG_AS(GtkText, GTK_TYPE_TEXT, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_set_overwrite_mode(self, phpgtk_arg_bool(overwrite));
}

void phpgtk_gtktext_set_placeholder_text(zval *handle, zval *text)
{
    GtkText *self = PHPGTK_ARG_AS(GtkText, GTK_TYPE_TEXT, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_set_placeholder_text(self, phpgtk_arg_string(text));
}

void phpgtk_gtktext_set_propagate_text_width(zval *handle, zval *propagateTextWidth)
{
    GtkText *self = PHPGTK_ARG_AS(GtkText, GTK_TYPE_TEXT, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_set_propagate_text_width(self, phpgtk_arg_bool(propagateTextWidth));
}

void phpgtk_gtktext_set_truncate_multiline(zval *handle, zval *truncateMultiline)
{
    GtkText *self = PHPGTK_ARG_AS(GtkText, GTK_TYPE_TEXT, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_set_truncate_multiline(self, phpgtk_arg_bool(truncateMultiline));
}

void phpgtk_gtktext_set_visibility(zval *handle, zval *visible)
{
    GtkText *self = PHPGTK_ARG_AS(GtkText, GTK_TYPE_TEXT, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_set_visibility(self, phpgtk_arg_bool(visible));
}

void phpgtk_gtktext_unset_invisible_char(zval *handle)
{
    GtkText *self = PHPGTK_ARG_AS(GtkText, GTK_TYPE_TEXT, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_unset_invisible_char(self);
}
