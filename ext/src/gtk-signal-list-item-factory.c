#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-signal-list-item-factory.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtksignallistitemfactory_new(void)
{
    return phpgtk_handle_register_take(gtk_signal_list_item_factory_new());
}
