#ifndef PHP_GTK_GTK_CALENDAR_H
#define PHP_GTK_GTK_CALENDAR_H

/*
 * GtkCalendar — Wave C. Every gir constructor/method/function is bound
 * or reserved. get_date / select_day stay reserved (GDateTime*); the
 * int year/month/day accessors cover the day-picker surface. Month is
 * 0-based, as GTK reports it.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkCalendar new() -> int */
zend_long phpgtk_gtkcalendar_new(void);
/*@zep Gtk\GtkCalendar clearMarks(int handle) -> void */
void phpgtk_gtkcalendar_clear_marks(zval *handle);
/*@reserved Gtk\GtkCalendar gtk_calendar_get_date() — GDateTime* */
/*@zep Gtk\GtkCalendar getDay(int handle) -> int */
zend_long phpgtk_gtkcalendar_get_day(zval *handle);
/*@zep Gtk\GtkCalendar getDayIsMarked(int handle, int day) -> bool */
zend_long phpgtk_gtkcalendar_get_day_is_marked(zval *handle, zval *day);
/*@zep Gtk\GtkCalendar getMonth(int handle) -> int */
zend_long phpgtk_gtkcalendar_get_month(zval *handle);
/*@zep Gtk\GtkCalendar getShowDayNames(int handle) -> bool */
zend_long phpgtk_gtkcalendar_get_show_day_names(zval *handle);
/*@zep Gtk\GtkCalendar getShowHeading(int handle) -> bool */
zend_long phpgtk_gtkcalendar_get_show_heading(zval *handle);
/*@zep Gtk\GtkCalendar getShowWeekNumbers(int handle) -> bool */
zend_long phpgtk_gtkcalendar_get_show_week_numbers(zval *handle);
/*@zep Gtk\GtkCalendar getYear(int handle) -> int */
zend_long phpgtk_gtkcalendar_get_year(zval *handle);
/*@zep Gtk\GtkCalendar markDay(int handle, int day) -> void */
void phpgtk_gtkcalendar_mark_day(zval *handle, zval *day);
/*@reserved Gtk\GtkCalendar gtk_calendar_select_day(GDateTime* date) — GDateTime* */
/*@zep Gtk\GtkCalendar setDay(int handle, int day) -> void */
void phpgtk_gtkcalendar_set_day(zval *handle, zval *day);
/*@zep Gtk\GtkCalendar setMonth(int handle, int month) -> void */
void phpgtk_gtkcalendar_set_month(zval *handle, zval *month);
/*@zep Gtk\GtkCalendar setShowDayNames(int handle, bool value) -> void */
void phpgtk_gtkcalendar_set_show_day_names(zval *handle, zval *value);
/*@zep Gtk\GtkCalendar setShowHeading(int handle, bool value) -> void */
void phpgtk_gtkcalendar_set_show_heading(zval *handle, zval *value);
/*@zep Gtk\GtkCalendar setShowWeekNumbers(int handle, bool value) -> void */
void phpgtk_gtkcalendar_set_show_week_numbers(zval *handle, zval *value);
/*@zep Gtk\GtkCalendar setYear(int handle, int year) -> void */
void phpgtk_gtkcalendar_set_year(zval *handle, zval *year);
/*@zep Gtk\GtkCalendar unmarkDay(int handle, int day) -> void */
void phpgtk_gtkcalendar_unmark_day(zval *handle, zval *day);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_CALENDAR_H */
