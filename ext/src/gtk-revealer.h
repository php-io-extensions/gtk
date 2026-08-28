#ifndef PHP_GTK_GTK_REVEALER_H
#define PHP_GTK_GTK_REVEALER_H

/*
 * GtkRevealer — Wave A8. Every gir constructor/method/function is bound
 * or reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkRevealer new() -> int */
zend_long phpgtk_gtkrevealer_new(void);
/*@zep Gtk\GtkRevealer getChild(int handle) -> int */
zend_long phpgtk_gtkrevealer_get_child(zval *handle);
/*@zep Gtk\GtkRevealer getChildRevealed(int handle) -> bool */
zend_long phpgtk_gtkrevealer_get_child_revealed(zval *handle);
/*@zep Gtk\GtkRevealer getRevealChild(int handle) -> bool */
zend_long phpgtk_gtkrevealer_get_reveal_child(zval *handle);
/*@zep Gtk\GtkRevealer getTransitionDuration(int handle) -> int */
zend_long phpgtk_gtkrevealer_get_transition_duration(zval *handle);
/*@zep Gtk\GtkRevealer getTransitionType(int handle) -> int */
zend_long phpgtk_gtkrevealer_get_transition_type(zval *handle);
/*@zep Gtk\GtkRevealer setChild(int handle, int child) -> void */
void phpgtk_gtkrevealer_set_child(zval *handle, zval *child);
/*@zep Gtk\GtkRevealer setRevealChild(int handle, bool revealChild) -> void */
void phpgtk_gtkrevealer_set_reveal_child(zval *handle, zval *revealChild);
/*@zep Gtk\GtkRevealer setTransitionDuration(int handle, int duration) -> void */
void phpgtk_gtkrevealer_set_transition_duration(zval *handle, zval *duration);
/*@zep Gtk\GtkRevealer setTransitionType(int handle, int transition) -> void */
void phpgtk_gtkrevealer_set_transition_type(zval *handle, zval *transition);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_REVEALER_H */
