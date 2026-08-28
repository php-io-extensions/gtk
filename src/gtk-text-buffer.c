#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-text-buffer.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtktextbuffer_new(zval *table)
{
    GtkTextBuffer *created = gtk_text_buffer_new(phpgtk_arg_object(table));
    return phpgtk_handle_register_take(created);
}

void phpgtk_gtktextbuffer_add_selection_clipboard(zval *handle, zval *clipboard)
{
    GtkTextBuffer *self = PHPGTK_ARG_AS(GtkTextBuffer, GTK_TYPE_TEXT_BUFFER, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_buffer_add_selection_clipboard(self, phpgtk_arg_object(clipboard));
}

void phpgtk_gtktextbuffer_begin_irreversible_action(zval *handle)
{
    GtkTextBuffer *self = PHPGTK_ARG_AS(GtkTextBuffer, GTK_TYPE_TEXT_BUFFER, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_buffer_begin_irreversible_action(self);
}

void phpgtk_gtktextbuffer_begin_user_action(zval *handle)
{
    GtkTextBuffer *self = PHPGTK_ARG_AS(GtkTextBuffer, GTK_TYPE_TEXT_BUFFER, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_buffer_begin_user_action(self);
}

void phpgtk_gtktextbuffer_copy_clipboard(zval *handle, zval *clipboard)
{
    GtkTextBuffer *self = PHPGTK_ARG_AS(GtkTextBuffer, GTK_TYPE_TEXT_BUFFER, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_buffer_copy_clipboard(self, phpgtk_arg_object(clipboard));
}

void phpgtk_gtktextbuffer_cut_clipboard(zval *handle, zval *clipboard, zval *defaultEditable)
{
    GtkTextBuffer *self = PHPGTK_ARG_AS(GtkTextBuffer, GTK_TYPE_TEXT_BUFFER, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_buffer_cut_clipboard(self, phpgtk_arg_object(clipboard), phpgtk_arg_bool(defaultEditable));
}

void phpgtk_gtktextbuffer_delete_mark(zval *handle, zval *mark)
{
    GtkTextBuffer *self = PHPGTK_ARG_AS(GtkTextBuffer, GTK_TYPE_TEXT_BUFFER, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_buffer_delete_mark(self, phpgtk_arg_object(mark));
}

void phpgtk_gtktextbuffer_delete_mark_by_name(zval *handle, zval *name)
{
    GtkTextBuffer *self = PHPGTK_ARG_AS(GtkTextBuffer, GTK_TYPE_TEXT_BUFFER, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_buffer_delete_mark_by_name(self, phpgtk_arg_string(name));
}

zend_long phpgtk_gtktextbuffer_delete_selection(zval *handle, zval *interactive, zval *defaultEditable)
{
    GtkTextBuffer *self = PHPGTK_ARG_AS(GtkTextBuffer, GTK_TYPE_TEXT_BUFFER, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_text_buffer_delete_selection(self, phpgtk_arg_bool(interactive), phpgtk_arg_bool(defaultEditable)) ? 1 : 0;
}

void phpgtk_gtktextbuffer_end_irreversible_action(zval *handle)
{
    GtkTextBuffer *self = PHPGTK_ARG_AS(GtkTextBuffer, GTK_TYPE_TEXT_BUFFER, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_buffer_end_irreversible_action(self);
}

void phpgtk_gtktextbuffer_end_user_action(zval *handle)
{
    GtkTextBuffer *self = PHPGTK_ARG_AS(GtkTextBuffer, GTK_TYPE_TEXT_BUFFER, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_buffer_end_user_action(self);
}

zend_long phpgtk_gtktextbuffer_get_can_redo(zval *handle)
{
    GtkTextBuffer *self = PHPGTK_ARG_AS(GtkTextBuffer, GTK_TYPE_TEXT_BUFFER, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_text_buffer_get_can_redo(self) ? 1 : 0;
}

zend_long phpgtk_gtktextbuffer_get_can_undo(zval *handle)
{
    GtkTextBuffer *self = PHPGTK_ARG_AS(GtkTextBuffer, GTK_TYPE_TEXT_BUFFER, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_text_buffer_get_can_undo(self) ? 1 : 0;
}

zend_long phpgtk_gtktextbuffer_get_char_count(zval *handle)
{
    GtkTextBuffer *self = PHPGTK_ARG_AS(GtkTextBuffer, GTK_TYPE_TEXT_BUFFER, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_text_buffer_get_char_count(self);
}

zend_long phpgtk_gtktextbuffer_get_enable_undo(zval *handle)
{
    GtkTextBuffer *self = PHPGTK_ARG_AS(GtkTextBuffer, GTK_TYPE_TEXT_BUFFER, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_text_buffer_get_enable_undo(self) ? 1 : 0;
}

zend_long phpgtk_gtktextbuffer_get_has_selection(zval *handle)
{
    GtkTextBuffer *self = PHPGTK_ARG_AS(GtkTextBuffer, GTK_TYPE_TEXT_BUFFER, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_text_buffer_get_has_selection(self) ? 1 : 0;
}

zend_long phpgtk_gtktextbuffer_get_insert(zval *handle)
{
    GtkTextBuffer *self = PHPGTK_ARG_AS(GtkTextBuffer, GTK_TYPE_TEXT_BUFFER, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_text_buffer_get_insert(self));
}

zend_long phpgtk_gtktextbuffer_get_line_count(zval *handle)
{
    GtkTextBuffer *self = PHPGTK_ARG_AS(GtkTextBuffer, GTK_TYPE_TEXT_BUFFER, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_text_buffer_get_line_count(self);
}

zend_long phpgtk_gtktextbuffer_get_mark(zval *handle, zval *name)
{
    GtkTextBuffer *self = PHPGTK_ARG_AS(GtkTextBuffer, GTK_TYPE_TEXT_BUFFER, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_text_buffer_get_mark(self, phpgtk_arg_string(name)));
}

zend_long phpgtk_gtktextbuffer_get_max_undo_levels(zval *handle)
{
    GtkTextBuffer *self = PHPGTK_ARG_AS(GtkTextBuffer, GTK_TYPE_TEXT_BUFFER, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_text_buffer_get_max_undo_levels(self);
}

zend_long phpgtk_gtktextbuffer_get_modified(zval *handle)
{
    GtkTextBuffer *self = PHPGTK_ARG_AS(GtkTextBuffer, GTK_TYPE_TEXT_BUFFER, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_text_buffer_get_modified(self) ? 1 : 0;
}

zend_long phpgtk_gtktextbuffer_get_selection_bound(zval *handle)
{
    GtkTextBuffer *self = PHPGTK_ARG_AS(GtkTextBuffer, GTK_TYPE_TEXT_BUFFER, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_text_buffer_get_selection_bound(self));
}

zend_long phpgtk_gtktextbuffer_get_tag_table(zval *handle)
{
    GtkTextBuffer *self = PHPGTK_ARG_AS(GtkTextBuffer, GTK_TYPE_TEXT_BUFFER, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_text_buffer_get_tag_table(self));
}

void phpgtk_gtktextbuffer_insert_at_cursor(zval *handle, zval *text, zval *len)
{
    GtkTextBuffer *self = PHPGTK_ARG_AS(GtkTextBuffer, GTK_TYPE_TEXT_BUFFER, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_buffer_insert_at_cursor(self, phpgtk_arg_string(text), (int) phpgtk_arg_long(len));
}

zend_long phpgtk_gtktextbuffer_insert_interactive_at_cursor(zval *handle, zval *text, zval *len, zval *defaultEditable)
{
    GtkTextBuffer *self = PHPGTK_ARG_AS(GtkTextBuffer, GTK_TYPE_TEXT_BUFFER, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_text_buffer_insert_interactive_at_cursor(self, phpgtk_arg_string(text), (int) phpgtk_arg_long(len), phpgtk_arg_bool(defaultEditable)) ? 1 : 0;
}

void phpgtk_gtktextbuffer_redo(zval *handle)
{
    GtkTextBuffer *self = PHPGTK_ARG_AS(GtkTextBuffer, GTK_TYPE_TEXT_BUFFER, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_buffer_redo(self);
}

void phpgtk_gtktextbuffer_remove_commit_notify(zval *handle, zval *commitNotifyHandler)
{
    GtkTextBuffer *self = PHPGTK_ARG_AS(GtkTextBuffer, GTK_TYPE_TEXT_BUFFER, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_buffer_remove_commit_notify(self, (guint) phpgtk_arg_long(commitNotifyHandler));
}

void phpgtk_gtktextbuffer_remove_selection_clipboard(zval *handle, zval *clipboard)
{
    GtkTextBuffer *self = PHPGTK_ARG_AS(GtkTextBuffer, GTK_TYPE_TEXT_BUFFER, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_buffer_remove_selection_clipboard(self, phpgtk_arg_object(clipboard));
}

void phpgtk_gtktextbuffer_set_enable_undo(zval *handle, zval *enableUndo)
{
    GtkTextBuffer *self = PHPGTK_ARG_AS(GtkTextBuffer, GTK_TYPE_TEXT_BUFFER, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_buffer_set_enable_undo(self, phpgtk_arg_bool(enableUndo));
}

void phpgtk_gtktextbuffer_set_max_undo_levels(zval *handle, zval *maxUndoLevels)
{
    GtkTextBuffer *self = PHPGTK_ARG_AS(GtkTextBuffer, GTK_TYPE_TEXT_BUFFER, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_buffer_set_max_undo_levels(self, (guint) phpgtk_arg_long(maxUndoLevels));
}

void phpgtk_gtktextbuffer_set_modified(zval *handle, zval *setting)
{
    GtkTextBuffer *self = PHPGTK_ARG_AS(GtkTextBuffer, GTK_TYPE_TEXT_BUFFER, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_buffer_set_modified(self, phpgtk_arg_bool(setting));
}

void phpgtk_gtktextbuffer_set_text(zval *handle, zval *text, zval *len)
{
    GtkTextBuffer *self = PHPGTK_ARG_AS(GtkTextBuffer, GTK_TYPE_TEXT_BUFFER, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_buffer_set_text(self, phpgtk_arg_string(text), (int) phpgtk_arg_long(len));
}

void phpgtk_gtktextbuffer_undo(zval *handle)
{
    GtkTextBuffer *self = PHPGTK_ARG_AS(GtkTextBuffer, GTK_TYPE_TEXT_BUFFER, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_buffer_undo(self);
}

