/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: d2167fd7a2ef98442ce0ea5c510edf632ee5091b */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkTexture_getWidth, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GdkTexture_getHeight arginfo_class_GdkTexture_getWidth

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GdkMemoryTexture_new, 0, 5, GdkMemoryTexture, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, format, GdkMemoryFormat, 0)
	ZEND_ARG_TYPE_INFO(0, bytes, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, stride, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(GdkTexture, getWidth);
ZEND_METHOD(GdkTexture, getHeight);
ZEND_METHOD(GdkMemoryTexture, new);

static const zend_function_entry class_GdkTexture_methods[] = {
	ZEND_ME(GdkTexture, getWidth, arginfo_class_GdkTexture_getWidth, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkTexture, getHeight, arginfo_class_GdkTexture_getHeight, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GdkMemoryTexture_methods[] = {
	ZEND_ME(GdkMemoryTexture, new, arginfo_class_GdkMemoryTexture_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_GdkMemoryFormat(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GdkMemoryFormat", IS_LONG, NULL);

	zval enum_case_B8G8R8A8_PREMULTIPLIED_value;
	ZVAL_LONG(&enum_case_B8G8R8A8_PREMULTIPLIED_value, 0);
	zend_enum_add_case_cstr(class_entry, "B8G8R8A8_PREMULTIPLIED", &enum_case_B8G8R8A8_PREMULTIPLIED_value);

	zval enum_case_A8R8G8B8_PREMULTIPLIED_value;
	ZVAL_LONG(&enum_case_A8R8G8B8_PREMULTIPLIED_value, 1);
	zend_enum_add_case_cstr(class_entry, "A8R8G8B8_PREMULTIPLIED", &enum_case_A8R8G8B8_PREMULTIPLIED_value);

	zval enum_case_R8G8B8A8_PREMULTIPLIED_value;
	ZVAL_LONG(&enum_case_R8G8B8A8_PREMULTIPLIED_value, 2);
	zend_enum_add_case_cstr(class_entry, "R8G8B8A8_PREMULTIPLIED", &enum_case_R8G8B8A8_PREMULTIPLIED_value);

	zval enum_case_B8G8R8A8_value;
	ZVAL_LONG(&enum_case_B8G8R8A8_value, 3);
	zend_enum_add_case_cstr(class_entry, "B8G8R8A8", &enum_case_B8G8R8A8_value);

	zval enum_case_A8R8G8B8_value;
	ZVAL_LONG(&enum_case_A8R8G8B8_value, 4);
	zend_enum_add_case_cstr(class_entry, "A8R8G8B8", &enum_case_A8R8G8B8_value);

	zval enum_case_R8G8B8A8_value;
	ZVAL_LONG(&enum_case_R8G8B8A8_value, 5);
	zend_enum_add_case_cstr(class_entry, "R8G8B8A8", &enum_case_R8G8B8A8_value);

	zval enum_case_A8B8G8R8_value;
	ZVAL_LONG(&enum_case_A8B8G8R8_value, 6);
	zend_enum_add_case_cstr(class_entry, "A8B8G8R8", &enum_case_A8B8G8R8_value);

	zval enum_case_R8G8B8_value;
	ZVAL_LONG(&enum_case_R8G8B8_value, 7);
	zend_enum_add_case_cstr(class_entry, "R8G8B8", &enum_case_R8G8B8_value);

	zval enum_case_B8G8R8_value;
	ZVAL_LONG(&enum_case_B8G8R8_value, 8);
	zend_enum_add_case_cstr(class_entry, "B8G8R8", &enum_case_B8G8R8_value);

	zval enum_case_A8B8G8R8_PREMULTIPLIED_value;
	ZVAL_LONG(&enum_case_A8B8G8R8_PREMULTIPLIED_value, 28);
	zend_enum_add_case_cstr(class_entry, "A8B8G8R8_PREMULTIPLIED", &enum_case_A8B8G8R8_PREMULTIPLIED_value);

	zval enum_case_B8G8R8X8_value;
	ZVAL_LONG(&enum_case_B8G8R8X8_value, 29);
	zend_enum_add_case_cstr(class_entry, "B8G8R8X8", &enum_case_B8G8R8X8_value);

	zval enum_case_X8R8G8B8_value;
	ZVAL_LONG(&enum_case_X8R8G8B8_value, 30);
	zend_enum_add_case_cstr(class_entry, "X8R8G8B8", &enum_case_X8R8G8B8_value);

	zval enum_case_R8G8B8X8_value;
	ZVAL_LONG(&enum_case_R8G8B8X8_value, 31);
	zend_enum_add_case_cstr(class_entry, "R8G8B8X8", &enum_case_R8G8B8X8_value);

	zval enum_case_X8B8G8R8_value;
	ZVAL_LONG(&enum_case_X8B8G8R8_value, 32);
	zend_enum_add_case_cstr(class_entry, "X8B8G8R8", &enum_case_X8B8G8R8_value);

	return class_entry;
}

static zend_class_entry *register_class_GdkTexture(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GdkTexture", class_GdkTexture_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GdkMemoryTexture(zend_class_entry *class_entry_GdkTexture)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GdkMemoryTexture", class_GdkMemoryTexture_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GdkTexture, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
