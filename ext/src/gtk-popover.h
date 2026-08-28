#ifndef PHP_GTK_GTK_POPOVER_H
#define PHP_GTK_GTK_POPOVER_H

/*
 * GtkPopover — Wave B7. Every gir
 * constructor/method/function is bound or reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@reserved Gtk\GtkPopover property "default-widget" — no dedicated C accessor; use Bridge::getProperty/setProperty */

/*@zep Gtk\GtkPopover new_() -> int */
zend_long phpgtk_gtkpopover_new(void);
/*@zep Gtk\GtkPopover getAutohide(int handle) -> bool */
zend_long phpgtk_gtkpopover_get_autohide(zval *handle);
/*@zep Gtk\GtkPopover getCascadePopdown(int handle) -> bool */
zend_long phpgtk_gtkpopover_get_cascade_popdown(zval *handle);
/*@zep Gtk\GtkPopover getChild(int handle) -> int */
zend_long phpgtk_gtkpopover_get_child(zval *handle);
/*@zep Gtk\GtkPopover getHasArrow(int handle) -> bool */
zend_long phpgtk_gtkpopover_get_has_arrow(zval *handle);
/*@zep Gtk\GtkPopover getMnemonicsVisible(int handle) -> bool */
zend_long phpgtk_gtkpopover_get_mnemonics_visible(zval *handle);
/*@zep Gtk\GtkPopover getOffset(int handle) -> array */
void phpgtk_gtkpopover_get_offset(zval *return_value, zval *handle);
/*@zep Gtk\GtkPopover getPointingTo(int handle) -> array */
void phpgtk_gtkpopover_get_pointing_to(zval *return_value, zval *handle);
/*@zep Gtk\GtkPopover getPosition(int handle) -> int */
zend_long phpgtk_gtkpopover_get_position(zval *handle);
/*@zep Gtk\GtkPopover popdown(int handle) -> void */
void phpgtk_gtkpopover_popdown(zval *handle);
/*@zep Gtk\GtkPopover popup(int handle) -> void */
void phpgtk_gtkpopover_popup(zval *handle);
/*@zep Gtk\GtkPopover present(int handle) -> void */
void phpgtk_gtkpopover_present(zval *handle);
/*@zep Gtk\GtkPopover setAutohide(int handle, bool autohide) -> void */
void phpgtk_gtkpopover_set_autohide(zval *handle, zval *autohide);
/*@zep Gtk\GtkPopover setCascadePopdown(int handle, bool cascadePopdown) -> void */
void phpgtk_gtkpopover_set_cascade_popdown(zval *handle, zval *cascadePopdown);
/*@zep Gtk\GtkPopover setChild(int handle, int child) -> void */
void phpgtk_gtkpopover_set_child(zval *handle, zval *child);
/*@zep Gtk\GtkPopover setDefaultWidget(int handle, int widget) -> void */
void phpgtk_gtkpopover_set_default_widget(zval *handle, zval *widget);
/*@zep Gtk\GtkPopover setHasArrow(int handle, bool hasArrow) -> void */
void phpgtk_gtkpopover_set_has_arrow(zval *handle, zval *hasArrow);
/*@zep Gtk\GtkPopover setMnemonicsVisible(int handle, bool mnemonicsVisible) -> void */
void phpgtk_gtkpopover_set_mnemonics_visible(zval *handle, zval *mnemonicsVisible);
/*@zep Gtk\GtkPopover setOffset(int handle, int xOffset, int yOffset) -> void */
void phpgtk_gtkpopover_set_offset(zval *handle, zval *xOffset, zval *yOffset);
/*@zep Gtk\GtkPopover setPointingTo(int handle, double x, double y, double width, double height) -> void */
void phpgtk_gtkpopover_set_pointing_to(zval *handle, zval *x, zval *y, zval *width, zval *height);
/*@zep Gtk\GtkPopover setPosition(int handle, int position) -> void */
void phpgtk_gtkpopover_set_position(zval *handle, zval *position);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_POPOVER_H */
