#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gio-gsimpleactiongroup.h"
#include "phpgtk-support.h"

zend_long phpgtk_gsimpleactiongroup_new(void)
{
    return phpgtk_handle_register_take(g_simple_action_group_new());
}
