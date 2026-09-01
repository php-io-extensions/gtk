#ifndef PHP_GTK_CSS_PROVIDER_H
#define PHP_GTK_CSS_PROVIDER_H

/*
 * GtkCssProvider — the styling path GTK actually intends: CSS loaded into
 * a provider, attached to a display, selected by widget CSS classes.
 * Every gir constructor/method/function is bound or reserved. The
 * parsing-error signal comes through Bridge::connect like any signal.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkCssProvider new() -> int */
zend_long phpgtk_cssprovider_new(void);
/*@zep Gtk\GtkCssProvider loadFromString(int handle, string css) -> void */
void phpgtk_cssprovider_load_from_string(zval *handle, zval *css);
/*@zep Gtk\GtkCssProvider loadFromPath(int handle, string path) -> void */
void phpgtk_cssprovider_load_from_path(zval *handle, zval *path);
/*@zep Gtk\GtkCssProvider toString(int handle) -> string */
void phpgtk_cssprovider_to_string(zval *return_value, zval *handle);
/*@reserved Gtk\GtkCssProvider gtk_css_provider_load_from_bytes(self, bytes) — GBytes* */
/*@reserved Gtk\GtkCssProvider gtk_css_provider_load_from_data(self, data, length) — deprecated 4.12, use load_from_string */
/*@reserved Gtk\GtkCssProvider gtk_css_provider_load_from_file(self, file) — GFile* */
/*@reserved Gtk\GtkCssProvider gtk_css_provider_load_from_resource(self, resource_path) — GResource path, no resource bundle in PHPland */
/*@reserved Gtk\GtkCssProvider gtk_css_provider_load_named(self, name, variant) — theme loading, not app styling */

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_CSS_PROVIDER_H */
