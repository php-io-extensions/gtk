#ifndef PHP_GTK_GTK_STACK_H
#define PHP_GTK_GTK_STACK_H

/*
 * GtkStack — Wave B5. Every gir
 * constructor/method/function is bound or reserved. get_pages is transfer-full. add_* / get_page return obtain-only GtkStackPage handles.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkStack new() -> int */
zend_long phpgtk_gtkstack_new(void);
/*@zep Gtk\GtkStack addChild(int handle, int child) -> int */
zend_long phpgtk_gtkstack_add_child(zval *handle, zval *child);
/*@zep Gtk\GtkStack addNamed(int handle, int child, var name) -> int */
zend_long phpgtk_gtkstack_add_named(zval *handle, zval *child, zval *name);
/*@zep Gtk\GtkStack addTitled(int handle, int child, var name, string title) -> int */
zend_long phpgtk_gtkstack_add_titled(zval *handle, zval *child, zval *name, zval *title);
/*@zep Gtk\GtkStack getChildByName(int handle, string name) -> int */
zend_long phpgtk_gtkstack_get_child_by_name(zval *handle, zval *name);
/*@zep Gtk\GtkStack getHhomogeneous(int handle) -> bool */
zend_long phpgtk_gtkstack_get_hhomogeneous(zval *handle);
/*@zep Gtk\GtkStack getInterpolateSize(int handle) -> bool */
zend_long phpgtk_gtkstack_get_interpolate_size(zval *handle);
/*@zep Gtk\GtkStack getPage(int handle, int child) -> int */
zend_long phpgtk_gtkstack_get_page(zval *handle, zval *child);
/*@zep Gtk\GtkStack getPages(int handle) -> int */
zend_long phpgtk_gtkstack_get_pages(zval *handle);
/*@zep Gtk\GtkStack getTransitionDuration(int handle) -> int */
zend_long phpgtk_gtkstack_get_transition_duration(zval *handle);
/*@zep Gtk\GtkStack getTransitionRunning(int handle) -> bool */
zend_long phpgtk_gtkstack_get_transition_running(zval *handle);
/*@zep Gtk\GtkStack getTransitionType(int handle) -> int */
zend_long phpgtk_gtkstack_get_transition_type(zval *handle);
/*@zep Gtk\GtkStack getVhomogeneous(int handle) -> bool */
zend_long phpgtk_gtkstack_get_vhomogeneous(zval *handle);
/*@zep Gtk\GtkStack getVisibleChild(int handle) -> int */
zend_long phpgtk_gtkstack_get_visible_child(zval *handle);
/*@zep Gtk\GtkStack getVisibleChildName(int handle) -> var */
void phpgtk_gtkstack_get_visible_child_name(zval *return_value, zval *handle);
/*@zep Gtk\GtkStack remove(int handle, int child) -> void */
void phpgtk_gtkstack_remove(zval *handle, zval *child);
/*@zep Gtk\GtkStack setHhomogeneous(int handle, bool hhomogeneous) -> void */
void phpgtk_gtkstack_set_hhomogeneous(zval *handle, zval *hhomogeneous);
/*@zep Gtk\GtkStack setInterpolateSize(int handle, bool interpolateSize) -> void */
void phpgtk_gtkstack_set_interpolate_size(zval *handle, zval *interpolateSize);
/*@zep Gtk\GtkStack setTransitionDuration(int handle, int duration) -> void */
void phpgtk_gtkstack_set_transition_duration(zval *handle, zval *duration);
/*@zep Gtk\GtkStack setTransitionType(int handle, int transition) -> void */
void phpgtk_gtkstack_set_transition_type(zval *handle, zval *transition);
/*@zep Gtk\GtkStack setVhomogeneous(int handle, bool vhomogeneous) -> void */
void phpgtk_gtkstack_set_vhomogeneous(zval *handle, zval *vhomogeneous);
/*@zep Gtk\GtkStack setVisibleChild(int handle, int child) -> void */
void phpgtk_gtkstack_set_visible_child(zval *handle, zval *child);
/*@zep Gtk\GtkStack setVisibleChildFull(int handle, string name, int transition) -> void */
void phpgtk_gtkstack_set_visible_child_full(zval *handle, zval *name, zval *transition);
/*@zep Gtk\GtkStack setVisibleChildName(int handle, string name) -> void */
void phpgtk_gtkstack_set_visible_child_name(zval *handle, zval *name);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_STACK_H */
