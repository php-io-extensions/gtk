#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-editable.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkeditable_delegate_get_accessible_platform_state(zval *handle, zval *state)
{
    GtkEditable *self = PHPGTK_ARG_AS(GtkEditable, GTK_TYPE_EDITABLE, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_editable_delegate_get_accessible_platform_state(self, (GtkAccessiblePlatformState) phpgtk_arg_long(state)) ? 1 : 0;
}

void phpgtk_gtkeditable_delete_selection(zval *handle)
{
    GtkEditable *self = PHPGTK_ARG_AS(GtkEditable, GTK_TYPE_EDITABLE, handle);

    if (self == NULL) {
        return;
    }

    gtk_editable_delete_selection(self);
}

void phpgtk_gtkeditable_delete_text(zval *handle, zval *startPos, zval *endPos)
{
    GtkEditable *self = PHPGTK_ARG_AS(GtkEditable, GTK_TYPE_EDITABLE, handle);

    if (self == NULL) {
        return;
    }

    gtk_editable_delete_text(self, (int) phpgtk_arg_long(startPos), (int) phpgtk_arg_long(endPos));
}

void phpgtk_gtkeditable_finish_delegate(zval *handle)
{
    GtkEditable *self = PHPGTK_ARG_AS(GtkEditable, GTK_TYPE_EDITABLE, handle);

    if (self == NULL) {
        return;
    }

    gtk_editable_finish_delegate(self);
}

double phpgtk_gtkeditable_get_alignment(zval *handle)
{
    GtkEditable *self = PHPGTK_ARG_AS(GtkEditable, GTK_TYPE_EDITABLE, handle);

    if (self == NULL) {
        return 0.0;
    }

    return (double) gtk_editable_get_alignment(self);
}

void phpgtk_gtkeditable_get_chars(zval *return_value, zval *handle, zval *startPos, zval *endPos)
{
    GtkEditable *self = PHPGTK_ARG_AS(GtkEditable, GTK_TYPE_EDITABLE, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string_take(return_value, gtk_editable_get_chars(self, (int) phpgtk_arg_long(startPos), (int) phpgtk_arg_long(endPos)));
}

zend_long phpgtk_gtkeditable_get_delegate(zval *handle)
{
    GtkEditable *self = PHPGTK_ARG_AS(GtkEditable, GTK_TYPE_EDITABLE, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_editable_get_delegate(self));
}

zend_long phpgtk_gtkeditable_get_editable(zval *handle)
{
    GtkEditable *self = PHPGTK_ARG_AS(GtkEditable, GTK_TYPE_EDITABLE, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_editable_get_editable(self) ? 1 : 0;
}

zend_long phpgtk_gtkeditable_get_enable_undo(zval *handle)
{
    GtkEditable *self = PHPGTK_ARG_AS(GtkEditable, GTK_TYPE_EDITABLE, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_editable_get_enable_undo(self) ? 1 : 0;
}

zend_long phpgtk_gtkeditable_get_max_width_chars(zval *handle)
{
    GtkEditable *self = PHPGTK_ARG_AS(GtkEditable, GTK_TYPE_EDITABLE, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_editable_get_max_width_chars(self);
}

zend_long phpgtk_gtkeditable_get_position(zval *handle)
{
    GtkEditable *self = PHPGTK_ARG_AS(GtkEditable, GTK_TYPE_EDITABLE, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_editable_get_position(self);
}

void phpgtk_gtkeditable_get_selection_bounds(zval *return_value, zval *handle)
{
    GtkEditable *self = PHPGTK_ARG_AS(GtkEditable, GTK_TYPE_EDITABLE, handle);
    int start_pos = 0;
    int end_pos = 0;

    if (self == NULL) {
        array_init(return_value); return;
    }

    gtk_editable_get_selection_bounds(self, &start_pos, &end_pos);
    array_init(return_value);
    add_assoc_long(return_value, "start_pos", start_pos);
    add_assoc_long(return_value, "end_pos", end_pos);
}

void phpgtk_gtkeditable_get_text(zval *return_value, zval *handle)
{
    GtkEditable *self = PHPGTK_ARG_AS(GtkEditable, GTK_TYPE_EDITABLE, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_editable_get_text(self));
}

zend_long phpgtk_gtkeditable_get_width_chars(zval *handle)
{
    GtkEditable *self = PHPGTK_ARG_AS(GtkEditable, GTK_TYPE_EDITABLE, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_editable_get_width_chars(self);
}

void phpgtk_gtkeditable_init_delegate(zval *handle)
{
    GtkEditable *self = PHPGTK_ARG_AS(GtkEditable, GTK_TYPE_EDITABLE, handle);

    if (self == NULL) {
        return;
    }

    gtk_editable_init_delegate(self);
}

void phpgtk_gtkeditable_insert_text(zval *return_value, zval *handle, zval *text, zval *length, zval *position)
{
    GtkEditable *self = PHPGTK_ARG_AS(GtkEditable, GTK_TYPE_EDITABLE, handle);
    int pos;

    if (self == NULL) {
        array_init(return_value); return;
    }

    pos = (int) phpgtk_arg_long(position);
    gtk_editable_insert_text(self, phpgtk_arg_string(text), (int) phpgtk_arg_long(length), &pos);
    array_init(return_value);
    add_assoc_long(return_value, "position", pos);
}

void phpgtk_gtkeditable_select_region(zval *handle, zval *startPos, zval *endPos)
{
    GtkEditable *self = PHPGTK_ARG_AS(GtkEditable, GTK_TYPE_EDITABLE, handle);

    if (self == NULL) {
        return;
    }

    gtk_editable_select_region(self, (int) phpgtk_arg_long(startPos), (int) phpgtk_arg_long(endPos));
}

void phpgtk_gtkeditable_set_alignment(zval *handle, zval *xalign)
{
    GtkEditable *self = PHPGTK_ARG_AS(GtkEditable, GTK_TYPE_EDITABLE, handle);

    if (self == NULL) {
        return;
    }

    gtk_editable_set_alignment(self, (float) phpgtk_arg_double(xalign));
}

void phpgtk_gtkeditable_set_editable(zval *handle, zval *isEditable)
{
    GtkEditable *self = PHPGTK_ARG_AS(GtkEditable, GTK_TYPE_EDITABLE, handle);

    if (self == NULL) {
        return;
    }

    gtk_editable_set_editable(self, phpgtk_arg_bool(isEditable));
}

void phpgtk_gtkeditable_set_enable_undo(zval *handle, zval *enableUndo)
{
    GtkEditable *self = PHPGTK_ARG_AS(GtkEditable, GTK_TYPE_EDITABLE, handle);

    if (self == NULL) {
        return;
    }

    gtk_editable_set_enable_undo(self, phpgtk_arg_bool(enableUndo));
}

void phpgtk_gtkeditable_set_max_width_chars(zval *handle, zval *nChars)
{
    GtkEditable *self = PHPGTK_ARG_AS(GtkEditable, GTK_TYPE_EDITABLE, handle);

    if (self == NULL) {
        return;
    }

    gtk_editable_set_max_width_chars(self, (int) phpgtk_arg_long(nChars));
}

void phpgtk_gtkeditable_set_position(zval *handle, zval *position)
{
    GtkEditable *self = PHPGTK_ARG_AS(GtkEditable, GTK_TYPE_EDITABLE, handle);

    if (self == NULL) {
        return;
    }

    gtk_editable_set_position(self, (int) phpgtk_arg_long(position));
}

void phpgtk_gtkeditable_set_text(zval *handle, zval *text)
{
    GtkEditable *self = PHPGTK_ARG_AS(GtkEditable, GTK_TYPE_EDITABLE, handle);

    if (self == NULL) {
        return;
    }

    gtk_editable_set_text(self, phpgtk_arg_string(text));
}

void phpgtk_gtkeditable_set_width_chars(zval *handle, zval *nChars)
{
    GtkEditable *self = PHPGTK_ARG_AS(GtkEditable, GTK_TYPE_EDITABLE, handle);

    if (self == NULL) {
        return;
    }

    gtk_editable_set_width_chars(self, (int) phpgtk_arg_long(nChars));
}
