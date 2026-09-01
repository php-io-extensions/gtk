#ifndef PHP_GTK_STYLE_CONTEXT_H
#define PHP_GTK_STYLE_CONTEXT_H

/*
 * GtkStyleContext — bound for its two non-deprecated statics, which are
 * how a CSS provider reaches a display. Everything instance-level is
 * deprecated since 4.10 in favour of widget CSS classes (already bound on
 * GtkWidget) and is reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@reserved Gtk\GtkStyleContext property "display" — deprecated class; Bridge::getProperty/setProperty */
/*@zep Gtk\GtkStyleContext addProviderForDisplay(int display, int provider, int priority) -> void */
void phpgtk_stylecontext_add_provider_for_display(zval *display, zval *provider, zval *priority);
/*@zep Gtk\GtkStyleContext removeProviderForDisplay(int display, int provider) -> void */
void phpgtk_stylecontext_remove_provider_for_display(zval *display, zval *provider);
/*@reserved Gtk\GtkStyleContext gtk_style_context_add_class(self, class_name) — deprecated 4.10, GtkWidget::addCssClass */
/*@reserved Gtk\GtkStyleContext gtk_style_context_add_provider(self, provider, priority) — deprecated 4.10, use addProviderForDisplay */
/*@reserved Gtk\GtkStyleContext gtk_style_context_get_border(self, border) — deprecated 4.10 */
/*@reserved Gtk\GtkStyleContext gtk_style_context_get_color(self, color) — deprecated 4.10 */
/*@reserved Gtk\GtkStyleContext gtk_style_context_get_display(self) — deprecated 4.10 */
/*@reserved Gtk\GtkStyleContext gtk_style_context_get_margin(self, margin) — deprecated 4.10 */
/*@reserved Gtk\GtkStyleContext gtk_style_context_get_padding(self, padding) — deprecated 4.10 */
/*@reserved Gtk\GtkStyleContext gtk_style_context_get_scale(self) — deprecated 4.10 */
/*@reserved Gtk\GtkStyleContext gtk_style_context_get_state(self) — deprecated 4.10 */
/*@reserved Gtk\GtkStyleContext gtk_style_context_has_class(self, class_name) — deprecated 4.10, GtkWidget::getCssClasses */
/*@reserved Gtk\GtkStyleContext gtk_style_context_lookup_color(self, color_name, color) — deprecated 4.10 */
/*@reserved Gtk\GtkStyleContext gtk_style_context_remove_class(self, class_name) — deprecated 4.10, GtkWidget::removeCssClass */
/*@reserved Gtk\GtkStyleContext gtk_style_context_remove_provider(self, provider) — deprecated 4.10 */
/*@reserved Gtk\GtkStyleContext gtk_style_context_restore(self) — deprecated 4.10 */
/*@reserved Gtk\GtkStyleContext gtk_style_context_save(self) — deprecated 4.10 */
/*@reserved Gtk\GtkStyleContext gtk_style_context_set_display(self, display) — deprecated 4.10 */
/*@reserved Gtk\GtkStyleContext gtk_style_context_set_scale(self, scale) — deprecated 4.10 */
/*@reserved Gtk\GtkStyleContext gtk_style_context_set_state(self, flags) — deprecated 4.10 */
/*@reserved Gtk\GtkStyleContext gtk_style_context_to_string(self, flags) — deprecated 4.10 */

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_STYLE_CONTEXT_H */
