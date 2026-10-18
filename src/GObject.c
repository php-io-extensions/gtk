#include "runtime.h"
#include "../stubs/GObject_arginfo.h"

void phpgtk_register_GObject(void)
{
	phpgtk_ce_GObject = register_class_GObject();
	phpgtk_object_setup(phpgtk_ce_GObject);
	phpgtk_map_gtype("GObject", phpgtk_ce_GObject);

	phpgtk_ce_GParamSpec = register_class_GParamSpec();
	phpgtk_object_setup(phpgtk_ce_GParamSpec);
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

/* ---- GParamSpec -------------------------------------------------------- */

#define THIS_PSPEC ((GParamSpec *) PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

ZEND_METHOD(GParamSpec, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
}

ZEND_METHOD(GParamSpec, getName)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_STRING(g_param_spec_get_name(THIS_PSPEC));
}

ZEND_METHOD(GParamSpec, getNick)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_STRING(g_param_spec_get_nick(THIS_PSPEC));
}

ZEND_METHOD(GParamSpec, getBlurb)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_return_string(return_value, g_param_spec_get_blurb(THIS_PSPEC));
}

ZEND_METHOD(GParamSpec, getValueType)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_STRING(g_type_name(G_PARAM_SPEC_VALUE_TYPE(THIS_PSPEC)));
}
