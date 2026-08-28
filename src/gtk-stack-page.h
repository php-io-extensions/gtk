#ifndef PHP_GTK_GTK_STACK_PAGE_H
#define PHP_GTK_GTK_STACK_PAGE_H

/*
 * GtkStackPage — Wave B5. Every gir
 * constructor/method/function is bound or reserved. Obtain-only: no gir constructor; get via GtkStack::addChild / addNamed / addTitled / getPage.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkStackPage getChild(int handle) -> int */
zend_long phpgtk_gtkstackpage_get_child(zval *handle);
/*@zep Gtk\GtkStackPage getIconName(int handle) -> var */
void phpgtk_gtkstackpage_get_icon_name(zval *return_value, zval *handle);
/*@zep Gtk\GtkStackPage getName(int handle) -> var */
void phpgtk_gtkstackpage_get_name(zval *return_value, zval *handle);
/*@zep Gtk\GtkStackPage getNeedsAttention(int handle) -> bool */
zend_long phpgtk_gtkstackpage_get_needs_attention(zval *handle);
/*@zep Gtk\GtkStackPage getTitle(int handle) -> var */
void phpgtk_gtkstackpage_get_title(zval *return_value, zval *handle);
/*@zep Gtk\GtkStackPage getUseUnderline(int handle) -> bool */
zend_long phpgtk_gtkstackpage_get_use_underline(zval *handle);
/*@zep Gtk\GtkStackPage getVisible(int handle) -> bool */
zend_long phpgtk_gtkstackpage_get_visible(zval *handle);
/*@zep Gtk\GtkStackPage setIconName(int handle, string setting) -> void */
void phpgtk_gtkstackpage_set_icon_name(zval *handle, zval *setting);
/*@zep Gtk\GtkStackPage setName(int handle, string setting) -> void */
void phpgtk_gtkstackpage_set_name(zval *handle, zval *setting);
/*@zep Gtk\GtkStackPage setNeedsAttention(int handle, bool setting) -> void */
void phpgtk_gtkstackpage_set_needs_attention(zval *handle, zval *setting);
/*@zep Gtk\GtkStackPage setTitle(int handle, string setting) -> void */
void phpgtk_gtkstackpage_set_title(zval *handle, zval *setting);
/*@zep Gtk\GtkStackPage setUseUnderline(int handle, bool setting) -> void */
void phpgtk_gtkstackpage_set_use_underline(zval *handle, zval *setting);
/*@zep Gtk\GtkStackPage setVisible(int handle, bool visible) -> void */
void phpgtk_gtkstackpage_set_visible(zval *handle, zval *visible);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_STACK_PAGE_H */
