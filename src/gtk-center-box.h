#ifndef PHP_GTK_GTK_CENTER_BOX_H
#define PHP_GTK_GTK_CENTER_BOX_H

/*
 * GtkCenterBox — Wave A7. Every gir constructor/method/function is bound
 * or reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkCenterBox new() -> int */
zend_long phpgtk_gtkcenterbox_new(void);
/*@zep Gtk\GtkCenterBox getBaselinePosition(int handle) -> int */
zend_long phpgtk_gtkcenterbox_get_baseline_position(zval *handle);
/*@zep Gtk\GtkCenterBox getCenterWidget(int handle) -> int */
zend_long phpgtk_gtkcenterbox_get_center_widget(zval *handle);
/*@zep Gtk\GtkCenterBox getEndWidget(int handle) -> int */
zend_long phpgtk_gtkcenterbox_get_end_widget(zval *handle);
/*@zep Gtk\GtkCenterBox getShrinkCenterLast(int handle) -> bool */
zend_long phpgtk_gtkcenterbox_get_shrink_center_last(zval *handle);
/*@zep Gtk\GtkCenterBox getStartWidget(int handle) -> int */
zend_long phpgtk_gtkcenterbox_get_start_widget(zval *handle);
/*@zep Gtk\GtkCenterBox setBaselinePosition(int handle, int position) -> void */
void phpgtk_gtkcenterbox_set_baseline_position(zval *handle, zval *position);
/*@zep Gtk\GtkCenterBox setCenterWidget(int handle, int child) -> void */
void phpgtk_gtkcenterbox_set_center_widget(zval *handle, zval *child);
/*@zep Gtk\GtkCenterBox setEndWidget(int handle, int child) -> void */
void phpgtk_gtkcenterbox_set_end_widget(zval *handle, zval *child);
/*@zep Gtk\GtkCenterBox setShrinkCenterLast(int handle, bool shrinkCenterLast) -> void */
void phpgtk_gtkcenterbox_set_shrink_center_last(zval *handle, zval *shrinkCenterLast);
/*@zep Gtk\GtkCenterBox setStartWidget(int handle, int child) -> void */
void phpgtk_gtkcenterbox_set_start_widget(zval *handle, zval *child);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_CENTER_BOX_H */
