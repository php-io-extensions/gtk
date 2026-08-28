#ifndef PHP_GTK_GTK_TEXT_MARK_H
#define PHP_GTK_GTK_TEXT_MARK_H

/*
 * GtkTextMark — Wave B8. Every gir
 * constructor/method/function is bound or reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkTextMark new_(var name, bool leftGravity) -> int */
zend_long phpgtk_gtktextmark_new(zval *name, zval *leftGravity);
/*@zep Gtk\GtkTextMark getBuffer(int handle) -> int */
zend_long phpgtk_gtktextmark_get_buffer(zval *handle);
/*@zep Gtk\GtkTextMark getDeleted(int handle) -> bool */
zend_long phpgtk_gtktextmark_get_deleted(zval *handle);
/*@zep Gtk\GtkTextMark getLeftGravity(int handle) -> bool */
zend_long phpgtk_gtktextmark_get_left_gravity(zval *handle);
/*@zep Gtk\GtkTextMark getName(int handle) -> var */
void phpgtk_gtktextmark_get_name(zval *return_value, zval *handle);
/*@zep Gtk\GtkTextMark getVisible(int handle) -> bool */
zend_long phpgtk_gtktextmark_get_visible(zval *handle);
/*@zep Gtk\GtkTextMark setVisible(int handle, bool setting) -> void */
void phpgtk_gtktextmark_set_visible(zval *handle, zval *setting);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_TEXT_MARK_H */
