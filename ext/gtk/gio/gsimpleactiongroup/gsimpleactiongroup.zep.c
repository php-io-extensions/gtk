
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "src/gio-gsimpleactiongroup.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gio_GSimpleActionGroup_GSimpleActionGroup)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gio\\GSimpleActionGroup, GSimpleActionGroup, gtk, gio_gsimpleactiongroup_gsimpleactiongroup, gtk_gio_gsimpleactiongroup_gsimpleactiongroup_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gio_GSimpleActionGroup_GSimpleActionGroup, new_)
{

	RETURN_LONG(phpgtk_gsimpleactiongroup_new());
}

