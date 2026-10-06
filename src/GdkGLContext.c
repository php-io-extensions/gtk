#include "runtime.h"
#include "../stubs/GdkGLContext_arginfo.h"

void phpgtk_register_GdkGLContext(void)
{
	phpgtk_ce_GdkGLAPI = register_class_GdkGLAPI();
	phpgtk_ce_GdkGLContext = register_class_GdkGLContext(phpgtk_ce_GObject);
	phpgtk_object_setup(phpgtk_ce_GdkGLContext);
	phpgtk_map_gtype("GdkGLContext", phpgtk_ce_GdkGLContext);
}

#define THIS_CONTEXT GDK_GL_CONTEXT(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

ZEND_METHOD(GdkGLContext, makeCurrent)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();

	gdk_gl_context_make_current(THIS_CONTEXT);
}

ZEND_METHOD(GdkGLContext, clearCurrent)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();

	gdk_gl_context_clear_current();
}

ZEND_METHOD(GdkGLContext, getCurrent)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();

	phpgtk_box_gobject(return_value, gdk_gl_context_get_current());
}

ZEND_METHOD(GdkGLContext, realize)
{
	GError *error = NULL;

	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();

	if (!gdk_gl_context_realize(THIS_CONTEXT, &error)) {
		phpgtk_throw_gerror(error);
	}
}

ZEND_METHOD(GdkGLContext, getUseEs)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_BOOL(gdk_gl_context_get_use_es(THIS_CONTEXT));
}

ZEND_METHOD(GdkGLContext, getVersion)
{
	int major = 0, minor = 0;

	ZEND_PARSE_PARAMETERS_NONE();

	gdk_gl_context_get_version(THIS_CONTEXT, &major, &minor);
	array_init_size(return_value, 2);
	add_next_index_long(return_value, major);
	add_next_index_long(return_value, minor);
}

ZEND_METHOD(GdkGLContext, getApi)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_return_enum(return_value, phpgtk_ce_GdkGLAPI, (zend_long) gdk_gl_context_get_api(THIS_CONTEXT));
}
