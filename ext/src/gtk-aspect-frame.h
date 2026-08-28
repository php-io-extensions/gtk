#ifndef PHP_GTK_GTK_ASPECT_FRAME_H
#define PHP_GTK_GTK_ASPECT_FRAME_H

/*
 * GtkAspectFrame — Wave A7. Every gir constructor/method/function is bound
 * or reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkAspectFrame new(double xalign, double yalign, double ratio, bool obeyChild) -> int */
zend_long phpgtk_gtkaspectframe_new(zval *xalign, zval *yalign, zval *ratio, zval *obeyChild);
/*@zep Gtk\GtkAspectFrame getChild(int handle) -> int */
zend_long phpgtk_gtkaspectframe_get_child(zval *handle);
/*@zep Gtk\GtkAspectFrame getObeyChild(int handle) -> bool */
zend_long phpgtk_gtkaspectframe_get_obey_child(zval *handle);
/*@zep Gtk\GtkAspectFrame getRatio(int handle) -> double */
double phpgtk_gtkaspectframe_get_ratio(zval *handle);
/*@zep Gtk\GtkAspectFrame getXalign(int handle) -> double */
double phpgtk_gtkaspectframe_get_xalign(zval *handle);
/*@zep Gtk\GtkAspectFrame getYalign(int handle) -> double */
double phpgtk_gtkaspectframe_get_yalign(zval *handle);
/*@zep Gtk\GtkAspectFrame setChild(int handle, int child) -> void */
void phpgtk_gtkaspectframe_set_child(zval *handle, zval *child);
/*@zep Gtk\GtkAspectFrame setObeyChild(int handle, bool obeyChild) -> void */
void phpgtk_gtkaspectframe_set_obey_child(zval *handle, zval *obeyChild);
/*@zep Gtk\GtkAspectFrame setRatio(int handle, double ratio) -> void */
void phpgtk_gtkaspectframe_set_ratio(zval *handle, zval *ratio);
/*@zep Gtk\GtkAspectFrame setXalign(int handle, double xalign) -> void */
void phpgtk_gtkaspectframe_set_xalign(zval *handle, zval *xalign);
/*@zep Gtk\GtkAspectFrame setYalign(int handle, double yalign) -> void */
void phpgtk_gtkaspectframe_set_yalign(zval *handle, zval *yalign);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_ASPECT_FRAME_H */
