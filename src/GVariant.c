#include "runtime.h"
#include "../stubs/GVariant_arginfo.h"

void phpgtk_register_GVariant(void)
{
	phpgtk_ce_GVariant = register_class_GVariant();
	phpgtk_object_setup(phpgtk_ce_GVariant);
}

#define THIS_VARIANT ((GVariant *) PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

ZEND_METHOD(GVariant, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
}

ZEND_METHOD(GVariant, newBoolean)
{
	bool value;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(value)
	ZEND_PARSE_PARAMETERS_END();

	phpgtk_box_variant(return_value, g_variant_new_boolean(value));
}

ZEND_METHOD(GVariant, newString)
{
	zend_string *string;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(string)
	ZEND_PARSE_PARAMETERS_END();

	phpgtk_box_variant(return_value, g_variant_new_string(ZSTR_VAL(string)));
}

ZEND_METHOD(GVariant, newInt32)
{
	zend_long value;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(value)
	ZEND_PARSE_PARAMETERS_END();

	if (value < G_MININT32 || value > G_MAXINT32) {
		zend_argument_value_error(1, "must fit in 32 bits");
		RETURN_THROWS();
	}

	phpgtk_box_variant(return_value, g_variant_new_int32((gint32) value));
}

ZEND_METHOD(GVariant, newDouble)
{
	double value;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_DOUBLE(value)
	ZEND_PARSE_PARAMETERS_END();

	phpgtk_box_variant(return_value, g_variant_new_double(value));
}

ZEND_METHOD(GVariant, getBoolean)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_BOOL(g_variant_get_boolean(THIS_VARIANT));
}

ZEND_METHOD(GVariant, getString)
{
	ZEND_PARSE_PARAMETERS_NONE();

	const gchar *string = g_variant_get_string(THIS_VARIANT, NULL);
	if (string == NULL) {
		RETURN_NULL();
	}
	RETURN_STRING(string);
}

ZEND_METHOD(GVariant, getInt32)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG(g_variant_get_int32(THIS_VARIANT));
}

ZEND_METHOD(GVariant, getDouble)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_DOUBLE(g_variant_get_double(THIS_VARIANT));
}

ZEND_METHOD(GVariant, getTypeString)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_STRING(g_variant_get_type_string(THIS_VARIANT));
}

ZEND_METHOD(GVariant, isOfType)
{
	zend_string *type;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_BOOL(g_variant_is_of_type(THIS_VARIANT, G_VARIANT_TYPE(ZSTR_VAL(type))));
}

ZEND_METHOD(GVariant, print)
{
	bool type_annotate;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(type_annotate)
	ZEND_PARSE_PARAMETERS_END();

	gchar *printed = g_variant_print(THIS_VARIANT, type_annotate);
	RETVAL_STRING(printed);
	g_free(printed);
}
