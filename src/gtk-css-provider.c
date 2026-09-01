#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-css-provider.h"
#include "phpgtk-support.h"

zend_long phpgtk_cssprovider_new(void)
{
    return phpgtk_handle_register_take(gtk_css_provider_new());
}

void phpgtk_cssprovider_load_from_string(zval *handle, zval *css)
{
    GtkCssProvider *p = PHPGTK_ARG_AS(GtkCssProvider, GTK_TYPE_CSS_PROVIDER, handle);
    if (p == NULL) return;
    gtk_css_provider_load_from_string(p, phpgtk_arg_string(css));
}

void phpgtk_cssprovider_load_from_path(zval *handle, zval *path)
{
    GtkCssProvider *p = PHPGTK_ARG_AS(GtkCssProvider, GTK_TYPE_CSS_PROVIDER, handle);
    if (p == NULL) return;
    gtk_css_provider_load_from_path(p, phpgtk_arg_string(path));
}

void phpgtk_cssprovider_to_string(zval *return_value, zval *handle)
{
    GtkCssProvider *p = PHPGTK_ARG_AS(GtkCssProvider, GTK_TYPE_CSS_PROVIDER, handle);
    if (p == NULL) { ZVAL_EMPTY_STRING(return_value); return; }
    char *s = gtk_css_provider_to_string(p);
    ZVAL_STRING(return_value, s != NULL ? s : "");
    g_free(s);
}
