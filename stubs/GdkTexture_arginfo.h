/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: bd6f2090000a4c755a84c6cc0a7525e486cfcd78 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkTexture_getWidth, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GdkTexture_getHeight arginfo_class_GdkTexture_getWidth

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GdkMemoryTexture_new, 0, 5, GdkMemoryTexture, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, format, GdkMemoryFormat, 0)
	ZEND_ARG_TYPE_MASK(0, bytes, MAY_BE_STRING|MAY_BE_LONG, NULL)
	ZEND_ARG_TYPE_INFO(0, stride, IS_LONG, 0)
ZEND_END_ARG_INFO()

#if GTK_CHECK_VERSION(4, 16, 0)
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GdkMemoryTextureBuilder_new, 0, 0, GdkMemoryTextureBuilder, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkMemoryTextureBuilder_setBytes, 0, 1, IS_STATIC, 0)
	ZEND_ARG_TYPE_MASK(0, bytes, MAY_BE_STRING|MAY_BE_LONG, NULL)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, length, IS_LONG, 1, "null")
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkMemoryTextureBuilder_setWidth, 0, 1, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkMemoryTextureBuilder_setHeight, 0, 1, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkMemoryTextureBuilder_setFormat, 0, 1, IS_STATIC, 0)
	ZEND_ARG_OBJ_INFO(0, format, GdkMemoryFormat, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkMemoryTextureBuilder_setStride, 0, 1, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, stride, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkMemoryTextureBuilder_setUpdateTexture, 0, 1, IS_STATIC, 0)
	ZEND_ARG_OBJ_INFO(0, texture, GdkTexture, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkMemoryTextureBuilder_setUpdateRegion, 0, 1, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, rects, IS_ARRAY, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GdkMemoryTextureBuilder_build, 0, 0, GdkTexture, 1)
ZEND_END_ARG_INFO()
#endif

#if GTK_CHECK_VERSION(4, 14, 0)
ZEND_BEGIN_ARG_INFO_EX(arginfo_class_GdkDmabufFormats___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkDmabufFormats_getNFormats, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkDmabufFormats_getFormat, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, idx, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkDmabufFormats_contains, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, fourcc, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, modifier, IS_LONG, 0)
ZEND_END_ARG_INFO()
#endif

#if GTK_CHECK_VERSION(4, 14, 0) && defined(__linux__)
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GdkDmabufTextureBuilder_new, 0, 0, GdkDmabufTextureBuilder, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkDmabufTextureBuilder_setDisplay, 0, 1, IS_STATIC, 0)
	ZEND_ARG_OBJ_INFO(0, display, GdkDisplay, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkDmabufTextureBuilder_setWidth, 0, 1, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkDmabufTextureBuilder_setHeight, 0, 1, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkDmabufTextureBuilder_setFourcc, 0, 1, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, fourcc, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkDmabufTextureBuilder_setModifier, 0, 1, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, modifier, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkDmabufTextureBuilder_setPremultiplied, 0, 1, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, premultiplied, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkDmabufTextureBuilder_setNPlanes, 0, 1, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, n_planes, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkDmabufTextureBuilder_setFd, 0, 2, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, plane, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fd, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkDmabufTextureBuilder_setStride, 0, 2, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, plane, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, stride, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkDmabufTextureBuilder_setOffset, 0, 2, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, plane, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkDmabufTextureBuilder_setUpdateTexture, 0, 1, IS_STATIC, 0)
	ZEND_ARG_OBJ_INFO(0, texture, GdkTexture, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkDmabufTextureBuilder_setUpdateRegion, 0, 1, IS_STATIC, 0)
	ZEND_ARG_TYPE_INFO(0, rects, IS_ARRAY, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GdkDmabufTextureBuilder_build, 0, 0, GdkTexture, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, destroy, IS_CALLABLE, 1, "null")
ZEND_END_ARG_INFO()
#endif

ZEND_METHOD(GdkTexture, getWidth);
ZEND_METHOD(GdkTexture, getHeight);
ZEND_METHOD(GdkMemoryTexture, new);
#if GTK_CHECK_VERSION(4, 16, 0)
ZEND_METHOD(GdkMemoryTextureBuilder, new);
ZEND_METHOD(GdkMemoryTextureBuilder, setBytes);
ZEND_METHOD(GdkMemoryTextureBuilder, setWidth);
ZEND_METHOD(GdkMemoryTextureBuilder, setHeight);
ZEND_METHOD(GdkMemoryTextureBuilder, setFormat);
ZEND_METHOD(GdkMemoryTextureBuilder, setStride);
ZEND_METHOD(GdkMemoryTextureBuilder, setUpdateTexture);
ZEND_METHOD(GdkMemoryTextureBuilder, setUpdateRegion);
ZEND_METHOD(GdkMemoryTextureBuilder, build);
#endif
#if GTK_CHECK_VERSION(4, 14, 0)
ZEND_METHOD(GdkDmabufFormats, __construct);
ZEND_METHOD(GdkDmabufFormats, getNFormats);
ZEND_METHOD(GdkDmabufFormats, getFormat);
ZEND_METHOD(GdkDmabufFormats, contains);
#endif
#if GTK_CHECK_VERSION(4, 14, 0) && defined(__linux__)
ZEND_METHOD(GdkDmabufTextureBuilder, new);
ZEND_METHOD(GdkDmabufTextureBuilder, setDisplay);
ZEND_METHOD(GdkDmabufTextureBuilder, setWidth);
ZEND_METHOD(GdkDmabufTextureBuilder, setHeight);
ZEND_METHOD(GdkDmabufTextureBuilder, setFourcc);
ZEND_METHOD(GdkDmabufTextureBuilder, setModifier);
ZEND_METHOD(GdkDmabufTextureBuilder, setPremultiplied);
ZEND_METHOD(GdkDmabufTextureBuilder, setNPlanes);
ZEND_METHOD(GdkDmabufTextureBuilder, setFd);
ZEND_METHOD(GdkDmabufTextureBuilder, setStride);
ZEND_METHOD(GdkDmabufTextureBuilder, setOffset);
ZEND_METHOD(GdkDmabufTextureBuilder, setUpdateTexture);
ZEND_METHOD(GdkDmabufTextureBuilder, setUpdateRegion);
ZEND_METHOD(GdkDmabufTextureBuilder, build);
#endif

static const zend_function_entry class_GdkTexture_methods[] = {
	ZEND_ME(GdkTexture, getWidth, arginfo_class_GdkTexture_getWidth, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkTexture, getHeight, arginfo_class_GdkTexture_getHeight, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GdkMemoryTexture_methods[] = {
	ZEND_ME(GdkMemoryTexture, new, arginfo_class_GdkMemoryTexture_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

#if GTK_CHECK_VERSION(4, 16, 0)
static const zend_function_entry class_GdkMemoryTextureBuilder_methods[] = {
	ZEND_ME(GdkMemoryTextureBuilder, new, arginfo_class_GdkMemoryTextureBuilder_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GdkMemoryTextureBuilder, setBytes, arginfo_class_GdkMemoryTextureBuilder_setBytes, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkMemoryTextureBuilder, setWidth, arginfo_class_GdkMemoryTextureBuilder_setWidth, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkMemoryTextureBuilder, setHeight, arginfo_class_GdkMemoryTextureBuilder_setHeight, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkMemoryTextureBuilder, setFormat, arginfo_class_GdkMemoryTextureBuilder_setFormat, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkMemoryTextureBuilder, setStride, arginfo_class_GdkMemoryTextureBuilder_setStride, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkMemoryTextureBuilder, setUpdateTexture, arginfo_class_GdkMemoryTextureBuilder_setUpdateTexture, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkMemoryTextureBuilder, setUpdateRegion, arginfo_class_GdkMemoryTextureBuilder_setUpdateRegion, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkMemoryTextureBuilder, build, arginfo_class_GdkMemoryTextureBuilder_build, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};
#endif

#if GTK_CHECK_VERSION(4, 14, 0)
static const zend_function_entry class_GdkDmabufFormats_methods[] = {
	ZEND_ME(GdkDmabufFormats, __construct, arginfo_class_GdkDmabufFormats___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(GdkDmabufFormats, getNFormats, arginfo_class_GdkDmabufFormats_getNFormats, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkDmabufFormats, getFormat, arginfo_class_GdkDmabufFormats_getFormat, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkDmabufFormats, contains, arginfo_class_GdkDmabufFormats_contains, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};
#endif

#if GTK_CHECK_VERSION(4, 14, 0) && defined(__linux__)
static const zend_function_entry class_GdkDmabufTextureBuilder_methods[] = {
	ZEND_ME(GdkDmabufTextureBuilder, new, arginfo_class_GdkDmabufTextureBuilder_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GdkDmabufTextureBuilder, setDisplay, arginfo_class_GdkDmabufTextureBuilder_setDisplay, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkDmabufTextureBuilder, setWidth, arginfo_class_GdkDmabufTextureBuilder_setWidth, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkDmabufTextureBuilder, setHeight, arginfo_class_GdkDmabufTextureBuilder_setHeight, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkDmabufTextureBuilder, setFourcc, arginfo_class_GdkDmabufTextureBuilder_setFourcc, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkDmabufTextureBuilder, setModifier, arginfo_class_GdkDmabufTextureBuilder_setModifier, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkDmabufTextureBuilder, setPremultiplied, arginfo_class_GdkDmabufTextureBuilder_setPremultiplied, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkDmabufTextureBuilder, setNPlanes, arginfo_class_GdkDmabufTextureBuilder_setNPlanes, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkDmabufTextureBuilder, setFd, arginfo_class_GdkDmabufTextureBuilder_setFd, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkDmabufTextureBuilder, setStride, arginfo_class_GdkDmabufTextureBuilder_setStride, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkDmabufTextureBuilder, setOffset, arginfo_class_GdkDmabufTextureBuilder_setOffset, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkDmabufTextureBuilder, setUpdateTexture, arginfo_class_GdkDmabufTextureBuilder_setUpdateTexture, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkDmabufTextureBuilder, setUpdateRegion, arginfo_class_GdkDmabufTextureBuilder_setUpdateRegion, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkDmabufTextureBuilder, build, arginfo_class_GdkDmabufTextureBuilder_build, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};
#endif

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

#if GTK_CHECK_VERSION(4, 16, 0)
static zend_class_entry *register_class_GdkMemoryTextureBuilder(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GdkMemoryTextureBuilder", class_GdkMemoryTextureBuilder_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
#endif

#if GTK_CHECK_VERSION(4, 14, 0)
static zend_class_entry *register_class_GdkDmabufFormats(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GdkDmabufFormats", class_GdkDmabufFormats_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
#endif

#if GTK_CHECK_VERSION(4, 14, 0) && defined(__linux__)
static zend_class_entry *register_class_GdkDmabufTextureBuilder(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GdkDmabufTextureBuilder", class_GdkDmabufTextureBuilder_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
#endif
