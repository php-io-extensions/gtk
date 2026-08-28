#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-entry-buffer.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkentrybuffer_new(zval *initialChars, zval *nInitialChars)
{
    return phpgtk_handle_register_take(gtk_entry_buffer_new(phpgtk_arg_string(initialChars), (int) phpgtk_arg_long(nInitialChars)));
}

zend_long phpgtk_gtkentrybuffer_delete_text(zval *handle, zval *position, zval *nChars)
{
    GtkEntryBuffer *self = PHPGTK_ARG_AS(GtkEntryBuffer, GTK_TYPE_ENTRY_BUFFER, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_entry_buffer_delete_text(self, (guint) phpgtk_arg_long(position), (int) phpgtk_arg_long(nChars));
}

void phpgtk_gtkentrybuffer_emit_deleted_text(zval *handle, zval *position, zval *nChars)
{
    GtkEntryBuffer *self = PHPGTK_ARG_AS(GtkEntryBuffer, GTK_TYPE_ENTRY_BUFFER, handle);

    if (self == NULL) {
        return;
    }

    gtk_entry_buffer_emit_deleted_text(self, (guint) phpgtk_arg_long(position), (guint) phpgtk_arg_long(nChars));
}

void phpgtk_gtkentrybuffer_emit_inserted_text(zval *handle, zval *position, zval *chars, zval *nChars)
{
    GtkEntryBuffer *self = PHPGTK_ARG_AS(GtkEntryBuffer, GTK_TYPE_ENTRY_BUFFER, handle);

    if (self == NULL) {
        return;
    }

    gtk_entry_buffer_emit_inserted_text(self, (guint) phpgtk_arg_long(position), phpgtk_arg_string(chars), (guint) phpgtk_arg_long(nChars));
}

zend_long phpgtk_gtkentrybuffer_get_bytes(zval *handle)
{
    GtkEntryBuffer *self = PHPGTK_ARG_AS(GtkEntryBuffer, GTK_TYPE_ENTRY_BUFFER, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_entry_buffer_get_bytes(self);
}

zend_long phpgtk_gtkentrybuffer_get_length(zval *handle)
{
    GtkEntryBuffer *self = PHPGTK_ARG_AS(GtkEntryBuffer, GTK_TYPE_ENTRY_BUFFER, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_entry_buffer_get_length(self);
}

zend_long phpgtk_gtkentrybuffer_get_max_length(zval *handle)
{
    GtkEntryBuffer *self = PHPGTK_ARG_AS(GtkEntryBuffer, GTK_TYPE_ENTRY_BUFFER, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_entry_buffer_get_max_length(self);
}

void phpgtk_gtkentrybuffer_get_text(zval *return_value, zval *handle)
{
    GtkEntryBuffer *self = PHPGTK_ARG_AS(GtkEntryBuffer, GTK_TYPE_ENTRY_BUFFER, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_entry_buffer_get_text(self));
}

zend_long phpgtk_gtkentrybuffer_insert_text(zval *handle, zval *position, zval *chars, zval *nChars)
{
    GtkEntryBuffer *self = PHPGTK_ARG_AS(GtkEntryBuffer, GTK_TYPE_ENTRY_BUFFER, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_entry_buffer_insert_text(self, (guint) phpgtk_arg_long(position), phpgtk_arg_string(chars), (int) phpgtk_arg_long(nChars));
}

void phpgtk_gtkentrybuffer_set_max_length(zval *handle, zval *maxLength)
{
    GtkEntryBuffer *self = PHPGTK_ARG_AS(GtkEntryBuffer, GTK_TYPE_ENTRY_BUFFER, handle);

    if (self == NULL) {
        return;
    }

    gtk_entry_buffer_set_max_length(self, (int) phpgtk_arg_long(maxLength));
}

void phpgtk_gtkentrybuffer_set_text(zval *handle, zval *chars, zval *nChars)
{
    GtkEntryBuffer *self = PHPGTK_ARG_AS(GtkEntryBuffer, GTK_TYPE_ENTRY_BUFFER, handle);

    if (self == NULL) {
        return;
    }

    gtk_entry_buffer_set_text(self, phpgtk_arg_string(chars), (int) phpgtk_arg_long(nChars));
}
