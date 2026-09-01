#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-style-context.h"
#include "phpgtk-support.h"

void phpgtk_stylecontext_add_provider_for_display(zval *display, zval *provider, zval *priority)
{
    GdkDisplay *d = PHPGTK_ARG_AS(GdkDisplay, GDK_TYPE_DISPLAY, display);
    GtkCssProvider *p = PHPGTK_ARG_AS(GtkCssProvider, GTK_TYPE_CSS_PROVIDER, provider);
    if (d == NULL || p == NULL) return;
    gtk_style_context_add_provider_for_display(d, GTK_STYLE_PROVIDER(p), (guint) phpgtk_arg_long(priority));
}

void phpgtk_stylecontext_remove_provider_for_display(zval *display, zval *provider)
{
    GdkDisplay *d = PHPGTK_ARG_AS(GdkDisplay, GDK_TYPE_DISPLAY, display);
    GtkCssProvider *p = PHPGTK_ARG_AS(GtkCssProvider, GTK_TYPE_CSS_PROVIDER, provider);
    if (d == NULL || p == NULL) return;
    gtk_style_context_remove_provider_for_display(d, GTK_STYLE_PROVIDER(p));
}
