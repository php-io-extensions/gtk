#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-text-view.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtktextview_new(void)
{
    return phpgtk_handle_register(gtk_text_view_new());
}

zend_long phpgtk_gtktextview_new_with_buffer(zval *buffer)
{
    return phpgtk_handle_register(gtk_text_view_new_with_buffer(phpgtk_arg_object(buffer)));
}

void phpgtk_gtktextview_add_child_at_anchor(zval *handle, zval *child, zval *anchor)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_view_add_child_at_anchor(self, phpgtk_arg_object(child), phpgtk_arg_object(anchor));
}

void phpgtk_gtktextview_add_overlay(zval *handle, zval *child, zval *xpos, zval *ypos)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_view_add_overlay(self, phpgtk_arg_object(child), (int) phpgtk_arg_long(xpos), (int) phpgtk_arg_long(ypos));
}

void phpgtk_gtktextview_buffer_to_window_coords(zval *return_value, zval *handle, zval *win, zval *bufferX, zval *bufferY)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    int window_x = 0;
    int window_y = 0;

    if (self == NULL) {
        array_init(return_value); return;
    }

    gtk_text_view_buffer_to_window_coords(self, (GtkTextWindowType) phpgtk_arg_long(win), (int) phpgtk_arg_long(bufferX), (int) phpgtk_arg_long(bufferY), &window_x, &window_y);
    array_init(return_value);
    add_assoc_long(return_value, "window_x", window_x);
    add_assoc_long(return_value, "window_y", window_y);
}

zend_long phpgtk_gtktextview_get_accepts_tab(zval *handle)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_text_view_get_accepts_tab(self) ? 1 : 0;
}

zend_long phpgtk_gtktextview_get_bottom_margin(zval *handle)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_text_view_get_bottom_margin(self);
}

zend_long phpgtk_gtktextview_get_buffer(zval *handle)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_text_view_get_buffer(self));
}

zend_long phpgtk_gtktextview_get_cursor_visible(zval *handle)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_text_view_get_cursor_visible(self) ? 1 : 0;
}

zend_long phpgtk_gtktextview_get_editable(zval *handle)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_text_view_get_editable(self) ? 1 : 0;
}

zend_long phpgtk_gtktextview_get_extra_menu(zval *handle)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_text_view_get_extra_menu(self));
}

zend_long phpgtk_gtktextview_get_gutter(zval *handle, zval *win)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_text_view_get_gutter(self, (GtkTextWindowType) phpgtk_arg_long(win)));
}

zend_long phpgtk_gtktextview_get_indent(zval *handle)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_text_view_get_indent(self);
}

zend_long phpgtk_gtktextview_get_input_hints(zval *handle)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_text_view_get_input_hints(self);
}

zend_long phpgtk_gtktextview_get_input_purpose(zval *handle)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_text_view_get_input_purpose(self);
}

zend_long phpgtk_gtktextview_get_justification(zval *handle)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_text_view_get_justification(self);
}

zend_long phpgtk_gtktextview_get_left_margin(zval *handle)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_text_view_get_left_margin(self);
}

zend_long phpgtk_gtktextview_get_ltr_context(zval *handle)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_text_view_get_ltr_context(self));
}

zend_long phpgtk_gtktextview_get_monospace(zval *handle)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_text_view_get_monospace(self) ? 1 : 0;
}

zend_long phpgtk_gtktextview_get_overwrite(zval *handle)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_text_view_get_overwrite(self) ? 1 : 0;
}

zend_long phpgtk_gtktextview_get_pixels_above_lines(zval *handle)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_text_view_get_pixels_above_lines(self);
}

zend_long phpgtk_gtktextview_get_pixels_below_lines(zval *handle)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_text_view_get_pixels_below_lines(self);
}

zend_long phpgtk_gtktextview_get_pixels_inside_wrap(zval *handle)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_text_view_get_pixels_inside_wrap(self);
}

zend_long phpgtk_gtktextview_get_right_margin(zval *handle)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_text_view_get_right_margin(self);
}

zend_long phpgtk_gtktextview_get_rtl_context(zval *handle)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_text_view_get_rtl_context(self));
}

zend_long phpgtk_gtktextview_get_top_margin(zval *handle)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_text_view_get_top_margin(self);
}

void phpgtk_gtktextview_get_visible_offset(zval *return_value, zval *handle)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    double x_offset = 0.0;
    double y_offset = 0.0;

    if (self == NULL) {
        array_init(return_value); return;
    }

    gtk_text_view_get_visible_offset(self, &x_offset, &y_offset);
    array_init(return_value);
    add_assoc_double(return_value, "x_offset", x_offset);
    add_assoc_double(return_value, "y_offset", y_offset);
}

void phpgtk_gtktextview_get_visible_rect(zval *return_value, zval *handle)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    GdkRectangle visible_rect;

    if (self == NULL) {
        array_init(return_value); return;
    }

    gtk_text_view_get_visible_rect(self, &visible_rect);
    array_init(return_value);
    add_assoc_long(return_value, "x", visible_rect.x);
    add_assoc_long(return_value, "y", visible_rect.y);
    add_assoc_long(return_value, "width", visible_rect.width);
    add_assoc_long(return_value, "height", visible_rect.height);
}

zend_long phpgtk_gtktextview_get_wrap_mode(zval *handle)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_text_view_get_wrap_mode(self);
}

zend_long phpgtk_gtktextview_im_context_filter_keypress(zval *handle, zval *event)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_text_view_im_context_filter_keypress(self, phpgtk_arg_object(event)) ? 1 : 0;
}

zend_long phpgtk_gtktextview_move_mark_onscreen(zval *handle, zval *mark)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_text_view_move_mark_onscreen(self, phpgtk_arg_object(mark)) ? 1 : 0;
}

void phpgtk_gtktextview_move_overlay(zval *handle, zval *child, zval *xpos, zval *ypos)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_view_move_overlay(self, phpgtk_arg_object(child), (int) phpgtk_arg_long(xpos), (int) phpgtk_arg_long(ypos));
}

zend_long phpgtk_gtktextview_place_cursor_onscreen(zval *handle)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_text_view_place_cursor_onscreen(self) ? 1 : 0;
}

void phpgtk_gtktextview_remove(zval *handle, zval *child)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_view_remove(self, phpgtk_arg_object(child));
}

void phpgtk_gtktextview_reset_cursor_blink(zval *handle)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_view_reset_cursor_blink(self);
}

void phpgtk_gtktextview_reset_im_context(zval *handle)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_view_reset_im_context(self);
}

void phpgtk_gtktextview_scroll_mark_onscreen(zval *handle, zval *mark)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_view_scroll_mark_onscreen(self, phpgtk_arg_object(mark));
}

void phpgtk_gtktextview_scroll_to_mark(zval *handle, zval *mark, zval *withinMargin, zval *useAlign, zval *xalign, zval *yalign)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_view_scroll_to_mark(self, phpgtk_arg_object(mark), phpgtk_arg_double(withinMargin), phpgtk_arg_bool(useAlign), phpgtk_arg_double(xalign), phpgtk_arg_double(yalign));
}

void phpgtk_gtktextview_set_accepts_tab(zval *handle, zval *acceptsTab)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_view_set_accepts_tab(self, phpgtk_arg_bool(acceptsTab));
}

void phpgtk_gtktextview_set_bottom_margin(zval *handle, zval *bottomMargin)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_view_set_bottom_margin(self, (int) phpgtk_arg_long(bottomMargin));
}

void phpgtk_gtktextview_set_buffer(zval *handle, zval *buffer)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_view_set_buffer(self, phpgtk_arg_object(buffer));
}

void phpgtk_gtktextview_set_cursor_visible(zval *handle, zval *setting)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_view_set_cursor_visible(self, phpgtk_arg_bool(setting));
}

void phpgtk_gtktextview_set_editable(zval *handle, zval *setting)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_view_set_editable(self, phpgtk_arg_bool(setting));
}

void phpgtk_gtktextview_set_extra_menu(zval *handle, zval *model)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_view_set_extra_menu(self, phpgtk_arg_object(model));
}

void phpgtk_gtktextview_set_gutter(zval *handle, zval *win, zval *widget)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_view_set_gutter(self, (GtkTextWindowType) phpgtk_arg_long(win), phpgtk_arg_object(widget));
}

void phpgtk_gtktextview_set_indent(zval *handle, zval *indent)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_view_set_indent(self, (int) phpgtk_arg_long(indent));
}

void phpgtk_gtktextview_set_input_hints(zval *handle, zval *hints)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_view_set_input_hints(self, (GtkInputHints) phpgtk_arg_long(hints));
}

void phpgtk_gtktextview_set_input_purpose(zval *handle, zval *purpose)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_view_set_input_purpose(self, (GtkInputPurpose) phpgtk_arg_long(purpose));
}

void phpgtk_gtktextview_set_justification(zval *handle, zval *justification)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_view_set_justification(self, (GtkJustification) phpgtk_arg_long(justification));
}

void phpgtk_gtktextview_set_left_margin(zval *handle, zval *leftMargin)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_view_set_left_margin(self, (int) phpgtk_arg_long(leftMargin));
}

void phpgtk_gtktextview_set_monospace(zval *handle, zval *monospace)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_view_set_monospace(self, phpgtk_arg_bool(monospace));
}

void phpgtk_gtktextview_set_overwrite(zval *handle, zval *overwrite)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_view_set_overwrite(self, phpgtk_arg_bool(overwrite));
}

void phpgtk_gtktextview_set_pixels_above_lines(zval *handle, zval *pixelsAboveLines)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_view_set_pixels_above_lines(self, (int) phpgtk_arg_long(pixelsAboveLines));
}

void phpgtk_gtktextview_set_pixels_below_lines(zval *handle, zval *pixelsBelowLines)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_view_set_pixels_below_lines(self, (int) phpgtk_arg_long(pixelsBelowLines));
}

void phpgtk_gtktextview_set_pixels_inside_wrap(zval *handle, zval *pixelsInsideWrap)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_view_set_pixels_inside_wrap(self, (int) phpgtk_arg_long(pixelsInsideWrap));
}

void phpgtk_gtktextview_set_right_margin(zval *handle, zval *rightMargin)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_view_set_right_margin(self, (int) phpgtk_arg_long(rightMargin));
}

void phpgtk_gtktextview_set_top_margin(zval *handle, zval *topMargin)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_view_set_top_margin(self, (int) phpgtk_arg_long(topMargin));
}

void phpgtk_gtktextview_set_wrap_mode(zval *handle, zval *wrapMode)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    if (self == NULL) {
        return;
    }

    gtk_text_view_set_wrap_mode(self, (GtkWrapMode) phpgtk_arg_long(wrapMode));
}

void phpgtk_gtktextview_window_to_buffer_coords(zval *return_value, zval *handle, zval *win, zval *windowX, zval *windowY)
{
    GtkTextView *self = PHPGTK_ARG_AS(GtkTextView, GTK_TYPE_TEXT_VIEW, handle);

    int buffer_x = 0;
    int buffer_y = 0;

    if (self == NULL) {
        array_init(return_value); return;
    }

    gtk_text_view_window_to_buffer_coords(self, (GtkTextWindowType) phpgtk_arg_long(win), (int) phpgtk_arg_long(windowX), (int) phpgtk_arg_long(windowY), &buffer_x, &buffer_y);
    array_init(return_value);
    add_assoc_long(return_value, "buffer_x", buffer_x);
    add_assoc_long(return_value, "buffer_y", buffer_y);
}

