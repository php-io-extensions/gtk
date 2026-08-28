#ifndef PHP_GTK_GTK_SEARCH_ENTRY_H
#define PHP_GTK_GTK_SEARCH_ENTRY_H

/*
 * GtkSearchEntry — Wave A3. Every gir constructor/method/function is bound
 * or reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@reserved Gtk\GtkSearchEntry property "activates-default" — no C accessor; use Bridge::getProperty/setProperty */

/*@zep Gtk\GtkSearchEntry new() -> int */
zend_long phpgtk_gtksearchentry_new(void);
/*@zep Gtk\GtkSearchEntry getInputHints(int handle) -> int */
zend_long phpgtk_gtksearchentry_get_input_hints(zval *handle);
/*@zep Gtk\GtkSearchEntry getInputPurpose(int handle) -> int */
zend_long phpgtk_gtksearchentry_get_input_purpose(zval *handle);
/*@zep Gtk\GtkSearchEntry getKeyCaptureWidget(int handle) -> int */
zend_long phpgtk_gtksearchentry_get_key_capture_widget(zval *handle);
/*@zep Gtk\GtkSearchEntry getPlaceholderText(int handle) -> var */
void phpgtk_gtksearchentry_get_placeholder_text(zval *return_value, zval *handle);
/*@zep Gtk\GtkSearchEntry getSearchDelay(int handle) -> int */
zend_long phpgtk_gtksearchentry_get_search_delay(zval *handle);
/*@zep Gtk\GtkSearchEntry setInputHints(int handle, int hints) -> void */
void phpgtk_gtksearchentry_set_input_hints(zval *handle, zval *hints);
/*@zep Gtk\GtkSearchEntry setInputPurpose(int handle, int purpose) -> void */
void phpgtk_gtksearchentry_set_input_purpose(zval *handle, zval *purpose);
/*@zep Gtk\GtkSearchEntry setKeyCaptureWidget(int handle, int widget) -> void */
void phpgtk_gtksearchentry_set_key_capture_widget(zval *handle, zval *widget);
/*@zep Gtk\GtkSearchEntry setPlaceholderText(int handle, var text) -> void */
void phpgtk_gtksearchentry_set_placeholder_text(zval *handle, zval *text);
/*@zep Gtk\GtkSearchEntry setSearchDelay(int handle, int delay) -> void */
void phpgtk_gtksearchentry_set_search_delay(zval *handle, zval *delay);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_SEARCH_ENTRY_H */
