
extern zend_class_entry *gtk_gtk_gtkglarea_gtkglarea_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkGLArea_GtkGLArea);

PHP_METHOD(Gtk_Gtk_GtkGLArea_GtkGLArea, new_);
PHP_METHOD(Gtk_Gtk_GtkGLArea_GtkGLArea, attachBuffers);
PHP_METHOD(Gtk_Gtk_GtkGLArea_GtkGLArea, getAllowedApis);
PHP_METHOD(Gtk_Gtk_GtkGLArea_GtkGLArea, getApi);
PHP_METHOD(Gtk_Gtk_GtkGLArea_GtkGLArea, getAutoRender);
PHP_METHOD(Gtk_Gtk_GtkGLArea_GtkGLArea, getContext);
PHP_METHOD(Gtk_Gtk_GtkGLArea_GtkGLArea, getHasDepthBuffer);
PHP_METHOD(Gtk_Gtk_GtkGLArea_GtkGLArea, getHasStencilBuffer);
PHP_METHOD(Gtk_Gtk_GtkGLArea_GtkGLArea, getRequiredVersion);
PHP_METHOD(Gtk_Gtk_GtkGLArea_GtkGLArea, makeCurrent);
PHP_METHOD(Gtk_Gtk_GtkGLArea_GtkGLArea, queueRender);
PHP_METHOD(Gtk_Gtk_GtkGLArea_GtkGLArea, setAllowedApis);
PHP_METHOD(Gtk_Gtk_GtkGLArea_GtkGLArea, setAutoRender);
PHP_METHOD(Gtk_Gtk_GtkGLArea_GtkGLArea, setHasDepthBuffer);
PHP_METHOD(Gtk_Gtk_GtkGLArea_GtkGLArea, setHasStencilBuffer);
PHP_METHOD(Gtk_Gtk_GtkGLArea_GtkGLArea, setRequiredVersion);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkglarea_gtkglarea_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkglarea_gtkglarea_attachbuffers, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkglarea_gtkglarea_getallowedapis, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkglarea_gtkglarea_getapi, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkglarea_gtkglarea_getautorender, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkglarea_gtkglarea_getcontext, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkglarea_gtkglarea_gethasdepthbuffer, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkglarea_gtkglarea_gethasstencilbuffer, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkglarea_gtkglarea_getrequiredversion, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkglarea_gtkglarea_makecurrent, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkglarea_gtkglarea_queuerender, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkglarea_gtkglarea_setallowedapis, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, apis, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkglarea_gtkglarea_setautorender, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, autoRender, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkglarea_gtkglarea_sethasdepthbuffer, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, hasDepthBuffer, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkglarea_gtkglarea_sethasstencilbuffer, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, hasStencilBuffer, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkglarea_gtkglarea_setrequiredversion, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, major, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, minor, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkglarea_gtkglarea_method_entry) {
	PHP_ME(Gtk_Gtk_GtkGLArea_GtkGLArea, new_, arginfo_gtk_gtk_gtkglarea_gtkglarea_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGLArea_GtkGLArea, attachBuffers, arginfo_gtk_gtk_gtkglarea_gtkglarea_attachbuffers, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGLArea_GtkGLArea, getAllowedApis, arginfo_gtk_gtk_gtkglarea_gtkglarea_getallowedapis, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGLArea_GtkGLArea, getApi, arginfo_gtk_gtk_gtkglarea_gtkglarea_getapi, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGLArea_GtkGLArea, getAutoRender, arginfo_gtk_gtk_gtkglarea_gtkglarea_getautorender, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGLArea_GtkGLArea, getContext, arginfo_gtk_gtk_gtkglarea_gtkglarea_getcontext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGLArea_GtkGLArea, getHasDepthBuffer, arginfo_gtk_gtk_gtkglarea_gtkglarea_gethasdepthbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGLArea_GtkGLArea, getHasStencilBuffer, arginfo_gtk_gtk_gtkglarea_gtkglarea_gethasstencilbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGLArea_GtkGLArea, getRequiredVersion, arginfo_gtk_gtk_gtkglarea_gtkglarea_getrequiredversion, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGLArea_GtkGLArea, makeCurrent, arginfo_gtk_gtk_gtkglarea_gtkglarea_makecurrent, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGLArea_GtkGLArea, queueRender, arginfo_gtk_gtk_gtkglarea_gtkglarea_queuerender, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGLArea_GtkGLArea, setAllowedApis, arginfo_gtk_gtk_gtkglarea_gtkglarea_setallowedapis, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGLArea_GtkGLArea, setAutoRender, arginfo_gtk_gtk_gtkglarea_gtkglarea_setautorender, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGLArea_GtkGLArea, setHasDepthBuffer, arginfo_gtk_gtk_gtkglarea_gtkglarea_sethasdepthbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGLArea_GtkGLArea, setHasStencilBuffer, arginfo_gtk_gtk_gtkglarea_gtkglarea_sethasstencilbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGLArea_GtkGLArea, setRequiredVersion, arginfo_gtk_gtk_gtkglarea_gtkglarea_setrequiredversion, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
