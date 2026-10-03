#include "runtime.h"
#include "../stubs/GdkSurface_arginfo.h"

void phpgtk_register_GdkSurface(void)
{
	phpgtk_ce_GdkSurface = register_class_GdkSurface(phpgtk_ce_GObject);
	phpgtk_object_setup(phpgtk_ce_GdkSurface);
	phpgtk_map_gtype("GdkSurface", phpgtk_ce_GdkSurface);
}

#define THIS_SURFACE GDK_SURFACE(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

ZEND_METHOD(GdkSurface, getWidth)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG(gdk_surface_get_width(THIS_SURFACE));
}

ZEND_METHOD(GdkSurface, getHeight)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG(gdk_surface_get_height(THIS_SURFACE));
}
