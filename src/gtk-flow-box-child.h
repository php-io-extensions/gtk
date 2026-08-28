#ifndef PHP_GTK_GTK_FLOW_BOX_CHILD_H
#define PHP_GTK_GTK_FLOW_BOX_CHILD_H

/*
 * GtkFlowBoxChild — Wave B4. Every gir
 * constructor/method/function is bound or reserved. Every gir constructor/method/function is bound or reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkFlowBoxChild new() -> int */
zend_long phpgtk_gtkflowboxchild_new(void);
/*@zep Gtk\GtkFlowBoxChild changed(int handle) -> void */
void phpgtk_gtkflowboxchild_changed(zval *handle);
/*@zep Gtk\GtkFlowBoxChild getChild(int handle) -> int */
zend_long phpgtk_gtkflowboxchild_get_child(zval *handle);
/*@zep Gtk\GtkFlowBoxChild getIndex(int handle) -> int */
zend_long phpgtk_gtkflowboxchild_get_index(zval *handle);
/*@zep Gtk\GtkFlowBoxChild isSelected(int handle) -> bool */
zend_long phpgtk_gtkflowboxchild_is_selected(zval *handle);
/*@zep Gtk\GtkFlowBoxChild setChild(int handle, int child) -> void */
void phpgtk_gtkflowboxchild_set_child(zval *handle, zval *child);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_FLOW_BOX_CHILD_H */
