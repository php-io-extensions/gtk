/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 9fe3cb0bcc924ca5d27dc3d95b930570d106930e */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkGLContext_makeCurrent, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GdkGLContext_clearCurrent arginfo_class_GdkGLContext_makeCurrent

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GdkGLContext_getCurrent, 0, 0, GdkGLContext, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_GdkGLContext_realize arginfo_class_GdkGLContext_makeCurrent

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkGLContext_getUseEs, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkGLContext_getVersion, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GdkGLContext_getApi, 0, 0, GdkGLAPI, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(GdkGLContext, makeCurrent);
ZEND_METHOD(GdkGLContext, clearCurrent);
ZEND_METHOD(GdkGLContext, getCurrent);
ZEND_METHOD(GdkGLContext, realize);
ZEND_METHOD(GdkGLContext, getUseEs);
ZEND_METHOD(GdkGLContext, getVersion);
ZEND_METHOD(GdkGLContext, getApi);

static const zend_function_entry class_GdkGLContext_methods[] = {
	ZEND_ME(GdkGLContext, makeCurrent, arginfo_class_GdkGLContext_makeCurrent, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkGLContext, clearCurrent, arginfo_class_GdkGLContext_clearCurrent, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GdkGLContext, getCurrent, arginfo_class_GdkGLContext_getCurrent, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GdkGLContext, realize, arginfo_class_GdkGLContext_realize, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkGLContext, getUseEs, arginfo_class_GdkGLContext_getUseEs, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkGLContext, getVersion, arginfo_class_GdkGLContext_getVersion, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkGLContext, getApi, arginfo_class_GdkGLContext_getApi, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_GdkGLAPI(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GdkGLAPI", IS_LONG, NULL);

	zval enum_case_GL_value;
	ZVAL_LONG(&enum_case_GL_value, 1);
	zend_enum_add_case_cstr(class_entry, "GL", &enum_case_GL_value);

	zval enum_case_GLES_value;
	ZVAL_LONG(&enum_case_GLES_value, 2);
	zend_enum_add_case_cstr(class_entry, "GLES", &enum_case_GLES_value);

	return class_entry;
}

static zend_class_entry *register_class_GdkGLContext(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GdkGLContext", class_GdkGLContext_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
