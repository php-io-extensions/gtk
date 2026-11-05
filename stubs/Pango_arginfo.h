/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: a5a3cba64a248fbca767b5a7f1a99f3a6f0c6d39 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_PangoLanguage___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_PangoLanguage_fromString, 0, 1, PangoLanguage, 1)
	ZEND_ARG_TYPE_INFO(0, language, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_PangoLanguage_toString, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_PangoFontDescription___construct arginfo_class_PangoLanguage___construct

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_PangoFontDescription_fromString, 0, 1, PangoFontDescription, 0)
	ZEND_ARG_TYPE_INFO(0, str, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_PangoContext_getMetrics, 0, 2, PangoFontMetrics, 0)
	ZEND_ARG_OBJ_INFO(0, desc, PangoFontDescription, 1)
	ZEND_ARG_OBJ_INFO(0, language, PangoLanguage, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_PangoContext_loadFont, 0, 1, PangoFont, 1)
	ZEND_ARG_OBJ_INFO(0, desc, PangoFontDescription, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_PangoFontMetrics___construct arginfo_class_PangoLanguage___construct

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_PangoFontMetrics_getAscent, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_PangoFontMetrics_getDescent arginfo_class_PangoFontMetrics_getAscent

#define arginfo_class_PangoFontMetrics_getHeight arginfo_class_PangoFontMetrics_getAscent

#define arginfo_class_PangoFontMetrics_getApproximateCharWidth arginfo_class_PangoFontMetrics_getAscent

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_PangoFont_getFace, 0, 0, PangoFontFace, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_PangoFontFace_getFamily, 0, 0, PangoFontFamily, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_PangoFontFamily_isMonospace, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_PangoTabArray___construct arginfo_class_PangoLanguage___construct

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_PangoTabArray_new, 0, 2, PangoTabArray, 0)
	ZEND_ARG_TYPE_INFO(0, initialSize, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, positionsInPixels, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_PangoTabArray_setTab, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, tabIndex, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, alignment, PangoTabAlign, 0)
	ZEND_ARG_TYPE_INFO(0, location, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_PangoTabArray_getTab, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, tabIndex, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(1, alignment, PangoTabAlign, 1)
	ZEND_ARG_TYPE_INFO(1, location, IS_LONG, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_PangoTabArray_getPositionsInPixels arginfo_class_PangoFontFamily_isMonospace

ZEND_METHOD(PangoLanguage, __construct);
ZEND_METHOD(PangoLanguage, fromString);
ZEND_METHOD(PangoLanguage, toString);
ZEND_METHOD(PangoFontDescription, __construct);
ZEND_METHOD(PangoFontDescription, fromString);
ZEND_METHOD(PangoContext, getMetrics);
ZEND_METHOD(PangoContext, loadFont);
ZEND_METHOD(PangoFontMetrics, __construct);
ZEND_METHOD(PangoFontMetrics, getAscent);
ZEND_METHOD(PangoFontMetrics, getDescent);
ZEND_METHOD(PangoFontMetrics, getHeight);
ZEND_METHOD(PangoFontMetrics, getApproximateCharWidth);
ZEND_METHOD(PangoFont, getFace);
ZEND_METHOD(PangoFontFace, getFamily);
ZEND_METHOD(PangoFontFamily, isMonospace);
ZEND_METHOD(PangoTabArray, __construct);
ZEND_METHOD(PangoTabArray, new);
ZEND_METHOD(PangoTabArray, setTab);
ZEND_METHOD(PangoTabArray, getTab);
ZEND_METHOD(PangoTabArray, getPositionsInPixels);

static const zend_function_entry class_PangoLanguage_methods[] = {
	ZEND_ME(PangoLanguage, __construct, arginfo_class_PangoLanguage___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(PangoLanguage, fromString, arginfo_class_PangoLanguage_fromString, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(PangoLanguage, toString, arginfo_class_PangoLanguage_toString, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_PangoFontDescription_methods[] = {
	ZEND_ME(PangoFontDescription, __construct, arginfo_class_PangoFontDescription___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(PangoFontDescription, fromString, arginfo_class_PangoFontDescription_fromString, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_PangoContext_methods[] = {
	ZEND_ME(PangoContext, getMetrics, arginfo_class_PangoContext_getMetrics, ZEND_ACC_PUBLIC)
	ZEND_ME(PangoContext, loadFont, arginfo_class_PangoContext_loadFont, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_PangoFontMetrics_methods[] = {
	ZEND_ME(PangoFontMetrics, __construct, arginfo_class_PangoFontMetrics___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(PangoFontMetrics, getAscent, arginfo_class_PangoFontMetrics_getAscent, ZEND_ACC_PUBLIC)
	ZEND_ME(PangoFontMetrics, getDescent, arginfo_class_PangoFontMetrics_getDescent, ZEND_ACC_PUBLIC)
	ZEND_ME(PangoFontMetrics, getHeight, arginfo_class_PangoFontMetrics_getHeight, ZEND_ACC_PUBLIC)
	ZEND_ME(PangoFontMetrics, getApproximateCharWidth, arginfo_class_PangoFontMetrics_getApproximateCharWidth, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_PangoFont_methods[] = {
	ZEND_ME(PangoFont, getFace, arginfo_class_PangoFont_getFace, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_PangoFontFace_methods[] = {
	ZEND_ME(PangoFontFace, getFamily, arginfo_class_PangoFontFace_getFamily, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_PangoFontFamily_methods[] = {
	ZEND_ME(PangoFontFamily, isMonospace, arginfo_class_PangoFontFamily_isMonospace, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_PangoTabArray_methods[] = {
	ZEND_ME(PangoTabArray, __construct, arginfo_class_PangoTabArray___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(PangoTabArray, new, arginfo_class_PangoTabArray_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(PangoTabArray, setTab, arginfo_class_PangoTabArray_setTab, ZEND_ACC_PUBLIC)
	ZEND_ME(PangoTabArray, getTab, arginfo_class_PangoTabArray_getTab, ZEND_ACC_PUBLIC)
	ZEND_ME(PangoTabArray, getPositionsInPixels, arginfo_class_PangoTabArray_getPositionsInPixels, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static void register_Pango_symbols(int module_number)
{
	REGISTER_LONG_CONSTANT("PANGO_SCALE", PANGO_SCALE, CONST_PERSISTENT);
}

static zend_class_entry *register_class_PangoTabAlign(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("PangoTabAlign", IS_LONG, NULL);

	zval enum_case_LEFT_value;
	ZVAL_LONG(&enum_case_LEFT_value, 0);
	zend_enum_add_case_cstr(class_entry, "LEFT", &enum_case_LEFT_value);

	zval enum_case_RIGHT_value;
	ZVAL_LONG(&enum_case_RIGHT_value, 1);
	zend_enum_add_case_cstr(class_entry, "RIGHT", &enum_case_RIGHT_value);

	zval enum_case_CENTER_value;
	ZVAL_LONG(&enum_case_CENTER_value, 2);
	zend_enum_add_case_cstr(class_entry, "CENTER", &enum_case_CENTER_value);

	zval enum_case_DECIMAL_value;
	ZVAL_LONG(&enum_case_DECIMAL_value, 3);
	zend_enum_add_case_cstr(class_entry, "DECIMAL", &enum_case_DECIMAL_value);

	return class_entry;
}

static zend_class_entry *register_class_PangoLanguage(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "PangoLanguage", class_PangoLanguage_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_PangoFontDescription(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "PangoFontDescription", class_PangoFontDescription_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_PangoContext(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "PangoContext", class_PangoContext_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_PangoFontMetrics(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "PangoFontMetrics", class_PangoFontMetrics_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_PangoFont(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "PangoFont", class_PangoFont_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_PangoFontFace(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "PangoFontFace", class_PangoFontFace_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_PangoFontFamily(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "PangoFontFamily", class_PangoFontFamily_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_PangoTabArray(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "PangoTabArray", class_PangoTabArray_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
