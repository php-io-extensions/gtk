#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-notebook-page.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtknotebookpage_get_child(zval *handle)
{
    GtkNotebookPage *self = PHPGTK_ARG_AS(GtkNotebookPage, GTK_TYPE_NOTEBOOK_PAGE, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_notebook_page_get_child(self));
}
