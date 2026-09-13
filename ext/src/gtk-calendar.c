#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-calendar.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkcalendar_new(void)
{
    return phpgtk_handle_register(gtk_calendar_new());
}

void phpgtk_gtkcalendar_clear_marks(zval *handle)
{
    GtkCalendar *self = PHPGTK_ARG_AS(GtkCalendar, GTK_TYPE_CALENDAR, handle);

    if (self == NULL) {
        return;
    }

    gtk_calendar_clear_marks(self);
}

zend_long phpgtk_gtkcalendar_get_day(zval *handle)
{
    GtkCalendar *self = PHPGTK_ARG_AS(GtkCalendar, GTK_TYPE_CALENDAR, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_calendar_get_day(self);
}

zend_long phpgtk_gtkcalendar_get_day_is_marked(zval *handle, zval *day)
{
    GtkCalendar *self = PHPGTK_ARG_AS(GtkCalendar, GTK_TYPE_CALENDAR, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_calendar_get_day_is_marked(self, (guint) phpgtk_arg_long(day)) ? 1 : 0;
}

zend_long phpgtk_gtkcalendar_get_month(zval *handle)
{
    GtkCalendar *self = PHPGTK_ARG_AS(GtkCalendar, GTK_TYPE_CALENDAR, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_calendar_get_month(self);
}

zend_long phpgtk_gtkcalendar_get_show_day_names(zval *handle)
{
    GtkCalendar *self = PHPGTK_ARG_AS(GtkCalendar, GTK_TYPE_CALENDAR, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_calendar_get_show_day_names(self) ? 1 : 0;
}

zend_long phpgtk_gtkcalendar_get_show_heading(zval *handle)
{
    GtkCalendar *self = PHPGTK_ARG_AS(GtkCalendar, GTK_TYPE_CALENDAR, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_calendar_get_show_heading(self) ? 1 : 0;
}

zend_long phpgtk_gtkcalendar_get_show_week_numbers(zval *handle)
{
    GtkCalendar *self = PHPGTK_ARG_AS(GtkCalendar, GTK_TYPE_CALENDAR, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_calendar_get_show_week_numbers(self) ? 1 : 0;
}

zend_long phpgtk_gtkcalendar_get_year(zval *handle)
{
    GtkCalendar *self = PHPGTK_ARG_AS(GtkCalendar, GTK_TYPE_CALENDAR, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_calendar_get_year(self);
}

void phpgtk_gtkcalendar_mark_day(zval *handle, zval *day)
{
    GtkCalendar *self = PHPGTK_ARG_AS(GtkCalendar, GTK_TYPE_CALENDAR, handle);

    if (self == NULL) {
        return;
    }

    gtk_calendar_mark_day(self, (guint) phpgtk_arg_long(day));
}

void phpgtk_gtkcalendar_set_day(zval *handle, zval *day)
{
    GtkCalendar *self = PHPGTK_ARG_AS(GtkCalendar, GTK_TYPE_CALENDAR, handle);

    if (self == NULL) {
        return;
    }

    gtk_calendar_set_day(self, (int) phpgtk_arg_long(day));
}

void phpgtk_gtkcalendar_set_month(zval *handle, zval *month)
{
    GtkCalendar *self = PHPGTK_ARG_AS(GtkCalendar, GTK_TYPE_CALENDAR, handle);

    if (self == NULL) {
        return;
    }

    gtk_calendar_set_month(self, (int) phpgtk_arg_long(month));
}

void phpgtk_gtkcalendar_set_show_day_names(zval *handle, zval *value)
{
    GtkCalendar *self = PHPGTK_ARG_AS(GtkCalendar, GTK_TYPE_CALENDAR, handle);

    if (self == NULL) {
        return;
    }

    gtk_calendar_set_show_day_names(self, phpgtk_arg_bool(value));
}

void phpgtk_gtkcalendar_set_show_heading(zval *handle, zval *value)
{
    GtkCalendar *self = PHPGTK_ARG_AS(GtkCalendar, GTK_TYPE_CALENDAR, handle);

    if (self == NULL) {
        return;
    }

    gtk_calendar_set_show_heading(self, phpgtk_arg_bool(value));
}

void phpgtk_gtkcalendar_set_show_week_numbers(zval *handle, zval *value)
{
    GtkCalendar *self = PHPGTK_ARG_AS(GtkCalendar, GTK_TYPE_CALENDAR, handle);

    if (self == NULL) {
        return;
    }

    gtk_calendar_set_show_week_numbers(self, phpgtk_arg_bool(value));
}

void phpgtk_gtkcalendar_set_year(zval *handle, zval *year)
{
    GtkCalendar *self = PHPGTK_ARG_AS(GtkCalendar, GTK_TYPE_CALENDAR, handle);

    if (self == NULL) {
        return;
    }

    gtk_calendar_set_year(self, (int) phpgtk_arg_long(year));
}

void phpgtk_gtkcalendar_unmark_day(zval *handle, zval *day)
{
    GtkCalendar *self = PHPGTK_ARG_AS(GtkCalendar, GTK_TYPE_CALENDAR, handle);

    if (self == NULL) {
        return;
    }

    gtk_calendar_unmark_day(self, (guint) phpgtk_arg_long(day));
}
