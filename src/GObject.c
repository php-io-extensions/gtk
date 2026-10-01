#include "runtime.h"
#include "../stubs/GObject_arginfo.h"

void phpgtk_register_GObject(void)
{
	phpgtk_ce_GObject = register_class_GObject();
	phpgtk_object_setup(phpgtk_ce_GObject);
	phpgtk_map_gtype("GObject", phpgtk_ce_GObject);
}

ZEND_METHOD(GObject, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
}

ZEND_METHOD(GObject, typeName)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_STRING(G_OBJECT_TYPE_NAME(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS))));
}

ZEND_METHOD(GObject, pointer)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG((zend_long) (uintptr_t) PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)));
}
