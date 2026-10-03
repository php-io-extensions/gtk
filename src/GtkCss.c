#include "runtime.h"
#include "../stubs/GtkCss_arginfo.h"

void phpgtk_register_GtkCss(void)
{
	phpgtk_ce_GtkCssProvider = register_class_GtkCssProvider(phpgtk_ce_GObject);
	phpgtk_object_setup(phpgtk_ce_GtkCssProvider);
	phpgtk_map_gtype("GtkCssProvider", phpgtk_ce_GtkCssProvider);

	phpgtk_ce_GdkDisplay = register_class_GdkDisplay(phpgtk_ce_GObject);
	phpgtk_object_setup(phpgtk_ce_GdkDisplay);
	phpgtk_map_gtype("GdkDisplay", phpgtk_ce_GdkDisplay);
}

/* ---- GtkCssProvider ---------------------------------------------------- */

#define THIS_PROVIDER GTK_CSS_PROVIDER(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

ZEND_METHOD(GtkCssProvider, new)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();

	phpgtk_box_gobject_full(return_value, gtk_css_provider_new());
}

ZEND_METHOD(GtkCssProvider, loadFromString)
{
	zend_string *css;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(css)
	ZEND_PARSE_PARAMETERS_END();

	gtk_css_provider_load_from_string(THIS_PROVIDER, ZSTR_VAL(css));
}

/* ---- GdkDisplay -------------------------------------------------------- */

ZEND_METHOD(GdkDisplay, getDefault)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();

	phpgtk_box_gobject(return_value, gdk_display_get_default());
}

/* ---- style context functions (declared in gtk.stub.php) --------------- */

ZEND_FUNCTION(gtk_style_context_add_provider_for_display)
{
	zend_object *display;
	zend_object *provider;
	zend_long priority;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJ_OF_CLASS(display, phpgtk_ce_GdkDisplay)
		Z_PARAM_OBJ_OF_CLASS(provider, phpgtk_ce_GtkCssProvider)
		Z_PARAM_LONG(priority)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	gtk_style_context_add_provider_for_display(GDK_DISPLAY(PHPGTK_PTR(display)), GTK_STYLE_PROVIDER(PHPGTK_PTR(provider)), (guint) priority);
}

ZEND_FUNCTION(gtk_style_context_remove_provider_for_display)
{
	zend_object *display;
	zend_object *provider;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS(display, phpgtk_ce_GdkDisplay)
		Z_PARAM_OBJ_OF_CLASS(provider, phpgtk_ce_GtkCssProvider)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	gtk_style_context_remove_provider_for_display(GDK_DISPLAY(PHPGTK_PTR(display)), GTK_STYLE_PROVIDER(PHPGTK_PTR(provider)));
}
