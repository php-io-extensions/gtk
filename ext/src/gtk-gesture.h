#ifndef PHP_GTK_GTK_GESTURE_H
#define PHP_GTK_GTK_GESTURE_H

/*
 * GtkGesture — input wave. Every gir constructor/method/function is bound
 * or reserved. Abstract: construct a concrete gesture (GtkGestureClick).
 *
 * GdkEventSequence* members are reserved: the sequence is an opaque boxed
 * pointer the handle registry cannot hold (signals still deliver it as a
 * raw pointer int). GdkEvent* members are reserved: non-GObject
 * fundamental. set_sequence_state is deprecated since 4.10; setState is
 * its replacement. n-points has no C accessor: Bridge::getProperty.
 *
 * getBoundingBox returns a GdkRectangle {x, y, width, height} and
 * getBoundingBoxCenter returns {x, y}; both return null when GTK reports
 * FALSE (no active points). getGroup is a container-owned GList of
 * gesture handles. setState takes GtkEventSequenceState.
 * getBoundingBoxCenter belongs inside a gesture handler: on an idle gesture
 * GTK 4.18.6 inspects a NULL last event and prints Gdk-CRITICALs before
 * returning FALSE.
 *
 * Signals are Bridge territory (Bridge::connect): begin / end / cancel /
 * update (sequence), sequence-state-changed (sequence, state).
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkGesture getBoundingBox(int handle) -> var */
void phpgtk_gtkgesture_get_bounding_box(zval *return_value, zval *handle);
/*@zep Gtk\GtkGesture getBoundingBoxCenter(int handle) -> var */
void phpgtk_gtkgesture_get_bounding_box_center(zval *return_value, zval *handle);
/*@zep Gtk\GtkGesture getDevice(int handle) -> int */
zend_long phpgtk_gtkgesture_get_device(zval *handle);
/*@zep Gtk\GtkGesture getGroup(int handle) -> array */
void phpgtk_gtkgesture_get_group(zval *return_value, zval *handle);
/*@reserved Gtk\GtkGesture gtk_gesture_get_last_event(GtkGesture* gesture, GdkEventSequence* sequence) — GdkEvent* / GdkEventSequence* */
/*@reserved Gtk\GtkGesture gtk_gesture_get_last_updated_sequence(GtkGesture* gesture) — GdkEventSequence* */
/*@reserved Gtk\GtkGesture gtk_gesture_get_point(GtkGesture* gesture, GdkEventSequence* sequence, double* x, double* y) — GdkEventSequence* */
/*@reserved Gtk\GtkGesture gtk_gesture_get_sequence_state(GtkGesture* gesture, GdkEventSequence* sequence) — GdkEventSequence* */
/*@reserved Gtk\GtkGesture gtk_gesture_get_sequences(GtkGesture* gesture) — GList of GdkEventSequence* */
/*@zep Gtk\GtkGesture group(int handle, int gesture) -> void */
void phpgtk_gtkgesture_group(zval *handle, zval *gesture);
/*@reserved Gtk\GtkGesture gtk_gesture_handles_sequence(GtkGesture* gesture, GdkEventSequence* sequence) — GdkEventSequence* */
/*@zep Gtk\GtkGesture isActive(int handle) -> bool */
zend_long phpgtk_gtkgesture_is_active(zval *handle);
/*@zep Gtk\GtkGesture isGroupedWith(int handle, int other) -> bool */
zend_long phpgtk_gtkgesture_is_grouped_with(zval *handle, zval *other);
/*@zep Gtk\GtkGesture isRecognized(int handle) -> bool */
zend_long phpgtk_gtkgesture_is_recognized(zval *handle);
/*@reserved Gtk\GtkGesture gtk_gesture_set_sequence_state(GtkGesture* gesture, GdkEventSequence* sequence, GtkEventSequenceState state) — deprecated 4.10 */
/*@zep Gtk\GtkGesture setState(int handle, int state) -> bool */
zend_long phpgtk_gtkgesture_set_state(zval *handle, zval *state);
/*@zep Gtk\GtkGesture ungroup(int handle) -> void */
void phpgtk_gtkgesture_ungroup(zval *handle);
/*@reserved Gtk\GtkGesture property "n-points" — no C accessor; Bridge::getProperty */

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_GESTURE_H */
