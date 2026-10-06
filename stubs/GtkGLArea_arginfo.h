/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 8bebf06017763be5b0bf084db53f45acda39240b */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkGLArea_new, 0, 0, GtkGLArea, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkGLArea_getContext, 0, 0, GdkGLContext, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkGLArea_makeCurrent, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkGLArea_attachBuffers arginfo_class_GtkGLArea_makeCurrent

#define arginfo_class_GtkGLArea_queueRender arginfo_class_GtkGLArea_makeCurrent

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkGLArea_getAutoRender, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkGLArea_setAutoRender, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, autoRender, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkGLArea_getHasDepthBuffer arginfo_class_GtkGLArea_getAutoRender

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkGLArea_setHasDepthBuffer, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, hasDepthBuffer, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkGLArea_getHasStencilBuffer arginfo_class_GtkGLArea_getAutoRender

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkGLArea_setHasStencilBuffer, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, hasStencilBuffer, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkGLArea_setAllowedApis, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, apis, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkGLArea_getAllowedApis, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkGLArea_setRequiredVersion, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, major, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, minor, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkGLArea_getError, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_METHOD(GtkGLArea, new);
ZEND_METHOD(GtkGLArea, getContext);
ZEND_METHOD(GtkGLArea, makeCurrent);
ZEND_METHOD(GtkGLArea, attachBuffers);
ZEND_METHOD(GtkGLArea, queueRender);
ZEND_METHOD(GtkGLArea, getAutoRender);
ZEND_METHOD(GtkGLArea, setAutoRender);
ZEND_METHOD(GtkGLArea, getHasDepthBuffer);
ZEND_METHOD(GtkGLArea, setHasDepthBuffer);
ZEND_METHOD(GtkGLArea, getHasStencilBuffer);
ZEND_METHOD(GtkGLArea, setHasStencilBuffer);
ZEND_METHOD(GtkGLArea, setAllowedApis);
ZEND_METHOD(GtkGLArea, getAllowedApis);
ZEND_METHOD(GtkGLArea, setRequiredVersion);
ZEND_METHOD(GtkGLArea, getError);

static const zend_function_entry class_GtkGLArea_methods[] = {
	ZEND_ME(GtkGLArea, new, arginfo_class_GtkGLArea_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkGLArea, getContext, arginfo_class_GtkGLArea_getContext, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkGLArea, makeCurrent, arginfo_class_GtkGLArea_makeCurrent, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkGLArea, attachBuffers, arginfo_class_GtkGLArea_attachBuffers, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkGLArea, queueRender, arginfo_class_GtkGLArea_queueRender, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkGLArea, getAutoRender, arginfo_class_GtkGLArea_getAutoRender, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkGLArea, setAutoRender, arginfo_class_GtkGLArea_setAutoRender, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkGLArea, getHasDepthBuffer, arginfo_class_GtkGLArea_getHasDepthBuffer, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkGLArea, setHasDepthBuffer, arginfo_class_GtkGLArea_setHasDepthBuffer, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkGLArea, getHasStencilBuffer, arginfo_class_GtkGLArea_getHasStencilBuffer, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkGLArea, setHasStencilBuffer, arginfo_class_GtkGLArea_setHasStencilBuffer, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkGLArea, setAllowedApis, arginfo_class_GtkGLArea_setAllowedApis, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkGLArea, getAllowedApis, arginfo_class_GtkGLArea_getAllowedApis, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkGLArea, setRequiredVersion, arginfo_class_GtkGLArea_setRequiredVersion, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkGLArea, getError, arginfo_class_GtkGLArea_getError, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_GtkGLArea(zend_class_entry *class_entry_GtkWidget)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkGLArea", class_GtkGLArea_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkWidget, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
