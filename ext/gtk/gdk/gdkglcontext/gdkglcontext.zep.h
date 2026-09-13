
extern zend_class_entry *gtk_gdk_gdkglcontext_gdkglcontext_ce;

ZEPHIR_INIT_CLASS(Gtk_Gdk_GdkGLContext_GdkGLContext);

PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, getAllowedApis);
PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, getApi);
PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, getDebugEnabled);
PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, getDisplay);
PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, getForwardCompatible);
PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, getRequiredVersion);
PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, getSurface);
PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, getUseEs);
PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, getVersion);
PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, isLegacy);
PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, isShared);
PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, makeCurrent);
PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, setAllowedApis);
PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, setDebugEnabled);
PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, setForwardCompatible);
PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, setRequiredVersion);
PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, setUseEs);
PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, clearCurrent);
PHP_METHOD(Gtk_Gdk_GdkGLContext_GdkGLContext, getCurrent);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gdk_gdkglcontext_gdkglcontext_getallowedapis, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gdk_gdkglcontext_gdkglcontext_getapi, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gdk_gdkglcontext_gdkglcontext_getdebugenabled, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gdk_gdkglcontext_gdkglcontext_getdisplay, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gdk_gdkglcontext_gdkglcontext_getforwardcompatible, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gdk_gdkglcontext_gdkglcontext_getrequiredversion, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gdk_gdkglcontext_gdkglcontext_getsurface, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gdk_gdkglcontext_gdkglcontext_getusees, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gdk_gdkglcontext_gdkglcontext_getversion, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gdk_gdkglcontext_gdkglcontext_islegacy, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gdk_gdkglcontext_gdkglcontext_isshared, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, other, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gdk_gdkglcontext_gdkglcontext_makecurrent, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gdk_gdkglcontext_gdkglcontext_setallowedapis, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, apis, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gdk_gdkglcontext_gdkglcontext_setdebugenabled, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, enabled, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gdk_gdkglcontext_gdkglcontext_setforwardcompatible, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, compatible, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gdk_gdkglcontext_gdkglcontext_setrequiredversion, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, major, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, minor, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gdk_gdkglcontext_gdkglcontext_setusees, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, useEs, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gdk_gdkglcontext_gdkglcontext_clearcurrent, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gdk_gdkglcontext_gdkglcontext_getcurrent, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gdk_gdkglcontext_gdkglcontext_method_entry) {
	PHP_ME(Gtk_Gdk_GdkGLContext_GdkGLContext, getAllowedApis, arginfo_gtk_gdk_gdkglcontext_gdkglcontext_getallowedapis, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gdk_GdkGLContext_GdkGLContext, getApi, arginfo_gtk_gdk_gdkglcontext_gdkglcontext_getapi, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gdk_GdkGLContext_GdkGLContext, getDebugEnabled, arginfo_gtk_gdk_gdkglcontext_gdkglcontext_getdebugenabled, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gdk_GdkGLContext_GdkGLContext, getDisplay, arginfo_gtk_gdk_gdkglcontext_gdkglcontext_getdisplay, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gdk_GdkGLContext_GdkGLContext, getForwardCompatible, arginfo_gtk_gdk_gdkglcontext_gdkglcontext_getforwardcompatible, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gdk_GdkGLContext_GdkGLContext, getRequiredVersion, arginfo_gtk_gdk_gdkglcontext_gdkglcontext_getrequiredversion, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gdk_GdkGLContext_GdkGLContext, getSurface, arginfo_gtk_gdk_gdkglcontext_gdkglcontext_getsurface, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gdk_GdkGLContext_GdkGLContext, getUseEs, arginfo_gtk_gdk_gdkglcontext_gdkglcontext_getusees, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gdk_GdkGLContext_GdkGLContext, getVersion, arginfo_gtk_gdk_gdkglcontext_gdkglcontext_getversion, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gdk_GdkGLContext_GdkGLContext, isLegacy, arginfo_gtk_gdk_gdkglcontext_gdkglcontext_islegacy, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gdk_GdkGLContext_GdkGLContext, isShared, arginfo_gtk_gdk_gdkglcontext_gdkglcontext_isshared, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gdk_GdkGLContext_GdkGLContext, makeCurrent, arginfo_gtk_gdk_gdkglcontext_gdkglcontext_makecurrent, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gdk_GdkGLContext_GdkGLContext, setAllowedApis, arginfo_gtk_gdk_gdkglcontext_gdkglcontext_setallowedapis, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gdk_GdkGLContext_GdkGLContext, setDebugEnabled, arginfo_gtk_gdk_gdkglcontext_gdkglcontext_setdebugenabled, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gdk_GdkGLContext_GdkGLContext, setForwardCompatible, arginfo_gtk_gdk_gdkglcontext_gdkglcontext_setforwardcompatible, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gdk_GdkGLContext_GdkGLContext, setRequiredVersion, arginfo_gtk_gdk_gdkglcontext_gdkglcontext_setrequiredversion, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gdk_GdkGLContext_GdkGLContext, setUseEs, arginfo_gtk_gdk_gdkglcontext_gdkglcontext_setusees, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gdk_GdkGLContext_GdkGLContext, clearCurrent, arginfo_gtk_gdk_gdkglcontext_gdkglcontext_clearcurrent, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gdk_GdkGLContext_GdkGLContext, getCurrent, arginfo_gtk_gdk_gdkglcontext_gdkglcontext_getcurrent, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
