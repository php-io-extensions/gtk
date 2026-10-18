/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 6d9fd89d6dac75de7b3a2dfb7d5e1a72458eb16c */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GdkPaintable_getCurrentImage, 0, 0, GdkPaintable, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkPaintable_getFlags, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GdkPaintable_getIntrinsicWidth arginfo_class_GdkPaintable_getFlags

#define arginfo_class_GdkPaintable_getIntrinsicHeight arginfo_class_GdkPaintable_getFlags

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkPaintable_getIntrinsicAspectRatio, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkPaintable_computeConcreteSize, 0, 6, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, specifiedWidth, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, specifiedHeight, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, defaultWidth, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, defaultHeight, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(1, concreteWidth, IS_DOUBLE, 1)
	ZEND_ARG_TYPE_INFO(1, concreteHeight, IS_DOUBLE, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkPaintable_invalidateContents, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GdkPaintable_invalidateSize arginfo_class_GdkPaintable_invalidateContents

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_GdkRectangle___construct, 0, 0, 4)
	ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_CairoRegion___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_CairoRegion_create, 0, 0, CairoRegion, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_CairoRegion_createRectangle, 0, 1, CairoRegion, 0)
	ZEND_ARG_OBJ_INFO(0, rectangle, GdkRectangle, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_CairoRegion_numRectangles arginfo_class_GdkPaintable_getFlags

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_CairoRegion_getRectangle, 0, 1, GdkRectangle, 0)
	ZEND_ARG_TYPE_INFO(0, nth, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_CairoRegion_unionRectangle, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, rectangle, GdkRectangle, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GBytes___construct arginfo_class_CairoRegion___construct

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GBytes_new, 0, 2, GBytes, 1)
	ZEND_ARG_TYPE_MASK(0, data, MAY_BE_STRING|MAY_BE_LONG, NULL)
	ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GBytes_getSize arginfo_class_GdkPaintable_getFlags

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GBytes_getData, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GdkTexture_getWidth arginfo_class_GdkPaintable_getFlags

#define arginfo_class_GdkTexture_getHeight arginfo_class_GdkPaintable_getFlags

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GdkMemoryTexture_new, 0, 5, GdkMemoryTexture, 1)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, format, GdkMemoryFormat, 0)
	ZEND_ARG_OBJ_INFO(0, bytes, GBytes, 0)
	ZEND_ARG_TYPE_INFO(0, stride, IS_LONG, 0)
ZEND_END_ARG_INFO()

#if GTK_CHECK_VERSION(4, 16, 0)
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GdkMemoryTextureBuilder_new, 0, 0, GdkMemoryTextureBuilder, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkMemoryTextureBuilder_setBytes, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, bytes, GBytes, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkMemoryTextureBuilder_setWidth, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkMemoryTextureBuilder_setHeight, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkMemoryTextureBuilder_setFormat, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, format, GdkMemoryFormat, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkMemoryTextureBuilder_setStride, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, stride, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkMemoryTextureBuilder_setUpdateTexture, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, texture, GdkTexture, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkMemoryTextureBuilder_setUpdateRegion, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, region, CairoRegion, 1)
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

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkDmabufTextureBuilder_setDisplay, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, display, GdkDisplay, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkDmabufTextureBuilder_setWidth, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkDmabufTextureBuilder_setHeight, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkDmabufTextureBuilder_setFourcc, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, fourcc, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkDmabufTextureBuilder_setModifier, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, modifier, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkDmabufTextureBuilder_setPremultiplied, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, premultiplied, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkDmabufTextureBuilder_setNPlanes, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, n_planes, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkDmabufTextureBuilder_setFd, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, plane, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fd, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkDmabufTextureBuilder_setStride, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, plane, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, stride, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkDmabufTextureBuilder_setOffset, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, plane, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, offset, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkDmabufTextureBuilder_setUpdateTexture, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, texture, GdkTexture, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkDmabufTextureBuilder_setUpdateRegion, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, region, CairoRegion, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GdkDmabufTextureBuilder_build, 0, 1, GdkTexture, 1)
	ZEND_ARG_TYPE_INFO(0, destroy, IS_CALLABLE, 1)
ZEND_END_ARG_INFO()
#endif

ZEND_METHOD(GdkRectangle, __construct);
ZEND_METHOD(CairoRegion, __construct);
ZEND_METHOD(CairoRegion, create);
ZEND_METHOD(CairoRegion, createRectangle);
ZEND_METHOD(CairoRegion, numRectangles);
ZEND_METHOD(CairoRegion, getRectangle);
ZEND_METHOD(CairoRegion, unionRectangle);
ZEND_METHOD(GBytes, __construct);
ZEND_METHOD(GBytes, new);
ZEND_METHOD(GBytes, getSize);
ZEND_METHOD(GBytes, getData);
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

static const zend_function_entry class_GdkPaintable_methods[] = {
	ZEND_RAW_FENTRY("getCurrentImage", NULL, arginfo_class_GdkPaintable_getCurrentImage, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("getFlags", NULL, arginfo_class_GdkPaintable_getFlags, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("getIntrinsicWidth", NULL, arginfo_class_GdkPaintable_getIntrinsicWidth, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("getIntrinsicHeight", NULL, arginfo_class_GdkPaintable_getIntrinsicHeight, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("getIntrinsicAspectRatio", NULL, arginfo_class_GdkPaintable_getIntrinsicAspectRatio, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("computeConcreteSize", NULL, arginfo_class_GdkPaintable_computeConcreteSize, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("invalidateContents", NULL, arginfo_class_GdkPaintable_invalidateContents, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("invalidateSize", NULL, arginfo_class_GdkPaintable_invalidateSize, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_FE_END
};

static const zend_function_entry class_GdkRectangle_methods[] = {
	ZEND_ME(GdkRectangle, __construct, arginfo_class_GdkRectangle___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_CairoRegion_methods[] = {
	ZEND_ME(CairoRegion, __construct, arginfo_class_CairoRegion___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(CairoRegion, create, arginfo_class_CairoRegion_create, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(CairoRegion, createRectangle, arginfo_class_CairoRegion_createRectangle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(CairoRegion, numRectangles, arginfo_class_CairoRegion_numRectangles, ZEND_ACC_PUBLIC)
	ZEND_ME(CairoRegion, getRectangle, arginfo_class_CairoRegion_getRectangle, ZEND_ACC_PUBLIC)
	ZEND_ME(CairoRegion, unionRectangle, arginfo_class_CairoRegion_unionRectangle, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GBytes_methods[] = {
	ZEND_ME(GBytes, __construct, arginfo_class_GBytes___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(GBytes, new, arginfo_class_GBytes_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GBytes, getSize, arginfo_class_GBytes_getSize, ZEND_ACC_PUBLIC)
	ZEND_ME(GBytes, getData, arginfo_class_GBytes_getData, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

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

static zend_class_entry *register_class_GdkPaintable(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GdkPaintable", class_GdkPaintable_methods);
	class_entry = zend_register_internal_interface(&ce);

	return class_entry;
}

static zend_class_entry *register_class_GdkRectangle(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GdkRectangle", class_GdkRectangle_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_x_default_value;
	ZVAL_UNDEF(&property_x_default_value);
	zend_string *property_x_name = zend_string_init("x", sizeof("x") - 1, 1);
	zend_declare_typed_property(class_entry, property_x_name, &property_x_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_x_name);

	zval property_y_default_value;
	ZVAL_UNDEF(&property_y_default_value);
	zend_string *property_y_name = zend_string_init("y", sizeof("y") - 1, 1);
	zend_declare_typed_property(class_entry, property_y_name, &property_y_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_y_name);

	zval property_width_default_value;
	ZVAL_UNDEF(&property_width_default_value);
	zend_string *property_width_name = zend_string_init("width", sizeof("width") - 1, 1);
	zend_declare_typed_property(class_entry, property_width_name, &property_width_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_width_name);

	zval property_height_default_value;
	ZVAL_UNDEF(&property_height_default_value);
	zend_string *property_height_name = zend_string_init("height", sizeof("height") - 1, 1);
	zend_declare_typed_property(class_entry, property_height_name, &property_height_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_LONG));
	zend_string_release(property_height_name);

	return class_entry;
}

static zend_class_entry *register_class_CairoRegion(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "CairoRegion", class_CairoRegion_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GBytes(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GBytes", class_GBytes_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GdkTexture(zend_class_entry *class_entry_GObject, zend_class_entry *class_entry_GdkPaintable)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GdkTexture", class_GdkTexture_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);
	zend_class_implements(class_entry, 1, class_entry_GdkPaintable);

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
