#ifndef PHP_GTK_GTK_ENTRY_BUFFER_H
#define PHP_GTK_GTK_ENTRY_BUFFER_H

/*
 * GtkEntryBuffer — Wave A1. Every gir constructor/method/function is bound
 * or reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkEntryBuffer new(var initialChars, int nInitialChars) -> int */
zend_long phpgtk_gtkentrybuffer_new(zval *initialChars, zval *nInitialChars);
/*@zep Gtk\GtkEntryBuffer deleteText(int handle, int position, int nChars) -> int */
zend_long phpgtk_gtkentrybuffer_delete_text(zval *handle, zval *position, zval *nChars);
/*@zep Gtk\GtkEntryBuffer emitDeletedText(int handle, int position, int nChars) -> void */
void phpgtk_gtkentrybuffer_emit_deleted_text(zval *handle, zval *position, zval *nChars);
/*@zep Gtk\GtkEntryBuffer emitInsertedText(int handle, int position, string chars, int nChars) -> void */
void phpgtk_gtkentrybuffer_emit_inserted_text(zval *handle, zval *position, zval *chars, zval *nChars);
/*@zep Gtk\GtkEntryBuffer getBytes(int handle) -> int */
zend_long phpgtk_gtkentrybuffer_get_bytes(zval *handle);
/*@zep Gtk\GtkEntryBuffer getLength(int handle) -> int */
zend_long phpgtk_gtkentrybuffer_get_length(zval *handle);
/*@zep Gtk\GtkEntryBuffer getMaxLength(int handle) -> int */
zend_long phpgtk_gtkentrybuffer_get_max_length(zval *handle);
/*@zep Gtk\GtkEntryBuffer getText(int handle) -> var */
void phpgtk_gtkentrybuffer_get_text(zval *return_value, zval *handle);
/*@zep Gtk\GtkEntryBuffer insertText(int handle, int position, string chars, int nChars) -> int */
zend_long phpgtk_gtkentrybuffer_insert_text(zval *handle, zval *position, zval *chars, zval *nChars);
/*@zep Gtk\GtkEntryBuffer setMaxLength(int handle, int maxLength) -> void */
void phpgtk_gtkentrybuffer_set_max_length(zval *handle, zval *maxLength);
/*@zep Gtk\GtkEntryBuffer setText(int handle, string chars, int nChars) -> void */
void phpgtk_gtkentrybuffer_set_text(zval *handle, zval *chars, zval *nChars);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_ENTRY_BUFFER_H */
