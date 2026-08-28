
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
#include "src/gtk-notebook-page.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"


ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkNotebookPage_GtkNotebookPage)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\Gtk\\GtkNotebookPage, GtkNotebookPage, gtk_gtk, gtknotebookpage_gtknotebookpage, gtk_gtk_gtknotebookpage_gtknotebookpage_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_Gtk_GtkNotebookPage_GtkNotebookPage, getChild)
{
	zval *handle_param = NULL, _0;
	zend_long handle;

	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(handle)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &handle_param);
	ZVAL_LONG(&_0, handle);
	RETURN_LONG(phpgtk_gtknotebookpage_get_child(&_0));
}

