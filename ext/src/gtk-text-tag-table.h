#ifndef PHP_GTK_GTK_TEXT_TAG_TABLE_H
#define PHP_GTK_GTK_TEXT_TAG_TABLE_H

/*
 * GtkTextTagTable — Wave B8. Every gir
 * constructor/method/function is bound or reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkTextTagTable new_() -> int */
zend_long phpgtk_gtktexttagtable_new(void);
/*@zep Gtk\GtkTextTagTable add(int handle, int tag) -> bool */
zend_long phpgtk_gtktexttagtable_add(zval *handle, zval *tag);
/*@reserved Gtk\GtkTextTagTable gtk_text_tag_table_foreach(GtkTextTagTableForeach func, gpointer data) — non-signal callback */
/*@zep Gtk\GtkTextTagTable getSize(int handle) -> int */
zend_long phpgtk_gtktexttagtable_get_size(zval *handle);
/*@zep Gtk\GtkTextTagTable lookup(int handle, string name) -> int */
zend_long phpgtk_gtktexttagtable_lookup(zval *handle, zval *name);
/*@zep Gtk\GtkTextTagTable remove(int handle, int tag) -> void */
void phpgtk_gtktexttagtable_remove(zval *handle, zval *tag);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_TEXT_TAG_TABLE_H */
