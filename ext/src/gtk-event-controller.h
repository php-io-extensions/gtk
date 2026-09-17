#ifndef PHP_GTK_GTK_EVENT_CONTROLLER_H
#define PHP_GTK_GTK_EVENT_CONTROLLER_H

/*
 * GtkEventController — input wave. Every gir constructor/method/function is
 * bound or reserved. Abstract: construct a concrete controller
 * (GtkEventControllerKey / Motion / Scroll, GtkGestureClick) and attach it
 * with GtkWidget::addController.
 *
 * get_current_event is reserved: GdkEvent is a fundamental, non-GObject
 * type the handle registry cannot hold. set_static_name is reserved: it
 * requires a string that outlives the controller, which a PHP string does
 * not guarantee; setName covers the property.
 *
 * getCurrentEventState is a GdkModifierType flags int; getCurrentEventTime
 * is the event timestamp in ms (guint32). getCurrentEventDevice hands back
 * a GdkDevice handle.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@reserved Gtk\GtkEventController gtk_event_controller_get_current_event(GtkEventController* controller) — GdkEvent* is a non-GObject fundamental type */
/*@zep Gtk\GtkEventController getCurrentEventDevice(int handle) -> int */
zend_long phpgtk_gtkeventcontroller_get_current_event_device(zval *handle);
/*@zep Gtk\GtkEventController getCurrentEventState(int handle) -> int */
zend_long phpgtk_gtkeventcontroller_get_current_event_state(zval *handle);
/*@zep Gtk\GtkEventController getCurrentEventTime(int handle) -> int */
zend_long phpgtk_gtkeventcontroller_get_current_event_time(zval *handle);
/*@zep Gtk\GtkEventController getName(int handle) -> var */
void phpgtk_gtkeventcontroller_get_name(zval *return_value, zval *handle);
/*@zep Gtk\GtkEventController getPropagationLimit(int handle) -> int */
zend_long phpgtk_gtkeventcontroller_get_propagation_limit(zval *handle);
/*@zep Gtk\GtkEventController getPropagationPhase(int handle) -> int */
zend_long phpgtk_gtkeventcontroller_get_propagation_phase(zval *handle);
/*@zep Gtk\GtkEventController getWidget(int handle) -> int */
zend_long phpgtk_gtkeventcontroller_get_widget(zval *handle);
/*@zep Gtk\GtkEventController reset(int handle) -> void */
void phpgtk_gtkeventcontroller_reset(zval *handle);
/*@zep Gtk\GtkEventController setName(int handle, var name) -> void */
void phpgtk_gtkeventcontroller_set_name(zval *handle, zval *name);
/*@zep Gtk\GtkEventController setPropagationLimit(int handle, int limit) -> void */
void phpgtk_gtkeventcontroller_set_propagation_limit(zval *handle, zval *limit);
/*@zep Gtk\GtkEventController setPropagationPhase(int handle, int phase) -> void */
void phpgtk_gtkeventcontroller_set_propagation_phase(zval *handle, zval *phase);
/*@reserved Gtk\GtkEventController gtk_event_controller_set_static_name(GtkEventController* controller, const char* name) — needs a string outliving the controller; setName covers it */

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_EVENT_CONTROLLER_H */
