#include "runtime.h"
#include "../stubs/GtkGLArea_arginfo.h"

void phpgtk_register_GtkGLArea(void)
{
	phpgtk_ce_GtkGLArea = register_class_GtkGLArea(phpgtk_ce_GtkWidget);
	phpgtk_object_setup(phpgtk_ce_GtkGLArea);
	phpgtk_map_gtype("GtkGLArea", phpgtk_ce_GtkGLArea);
}

#define THIS_AREA GTK_GL_AREA(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

ZEND_METHOD(GtkGLArea, new)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();
	PHPGTK_REQUIRE_INITIALIZED();

	phpgtk_box_gobject(return_value, gtk_gl_area_new());
}

ZEND_METHOD(GtkGLArea, getContext)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_gl_area_get_context(THIS_AREA));
}

ZEND_METHOD(GtkGLArea, makeCurrent)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();

	gtk_gl_area_make_current(THIS_AREA);
}

ZEND_METHOD(GtkGLArea, attachBuffers)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();

	gtk_gl_area_attach_buffers(THIS_AREA);
}

ZEND_METHOD(GtkGLArea, queueRender)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();

	gtk_gl_area_queue_render(THIS_AREA);
}

#define PHPGTK_AREA_BOOL(getter, setter, get_call, set_call) \
ZEND_METHOD(GtkGLArea, getter) \
{ \
	ZEND_PARSE_PARAMETERS_NONE(); \
	RETURN_BOOL(get_call(THIS_AREA)); \
} \
ZEND_METHOD(GtkGLArea, setter) \
{ \
	bool value; \
	ZEND_PARSE_PARAMETERS_START(1, 1) \
		Z_PARAM_BOOL(value) \
	ZEND_PARSE_PARAMETERS_END(); \
	PHPGTK_REQUIRE_MAIN_THREAD(); \
	set_call(THIS_AREA, value); \
}

PHPGTK_AREA_BOOL(getAutoRender, setAutoRender, gtk_gl_area_get_auto_render, gtk_gl_area_set_auto_render)
PHPGTK_AREA_BOOL(getHasDepthBuffer, setHasDepthBuffer, gtk_gl_area_get_has_depth_buffer, gtk_gl_area_set_has_depth_buffer)
PHPGTK_AREA_BOOL(getHasStencilBuffer, setHasStencilBuffer, gtk_gl_area_get_has_stencil_buffer, gtk_gl_area_set_has_stencil_buffer)

ZEND_METHOD(GtkGLArea, setAllowedApis)
{
	zend_long apis;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(apis)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	if (apis < 0 || apis > (GDK_GL_API_GL | GDK_GL_API_GLES)) {
		zend_argument_value_error(1, "must be GdkGLAPI flags (GL = 1, GLES = 2)");
		RETURN_THROWS();
	}
	gtk_gl_area_set_allowed_apis(THIS_AREA, (GdkGLAPI) apis);
}

ZEND_METHOD(GtkGLArea, getAllowedApis)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG((zend_long) gtk_gl_area_get_allowed_apis(THIS_AREA));
}

ZEND_METHOD(GtkGLArea, setRequiredVersion)
{
	zend_long major, minor;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(major)
		Z_PARAM_LONG(minor)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	gtk_gl_area_set_required_version(THIS_AREA, (int) major, (int) minor);
}

ZEND_METHOD(GtkGLArea, getError)
{
	GError *error;

	ZEND_PARSE_PARAMETERS_NONE();

	error = gtk_gl_area_get_error(THIS_AREA);
	if (error == NULL) {
		RETURN_NULL();
	}
	phpgtk_return_string(return_value, error->message);
}
