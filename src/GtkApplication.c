#include "runtime.h"
#include "../stubs/GtkApplication_arginfo.h"

void phpgtk_register_GtkApplication(void)
{
	phpgtk_ce_GtkApplication = register_class_GtkApplication(phpgtk_ce_GApplication);
	phpgtk_object_setup(phpgtk_ce_GtkApplication);
	phpgtk_map_gtype("GtkApplication", phpgtk_ce_GtkApplication);
}

ZEND_METHOD(GtkApplication, new)
{
	zend_string *application_id = NULL;
	zend_object *flags_case = NULL;
	zend_long flags_long = 0;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR_OR_NULL(application_id)
		Z_PARAM_OBJ_OF_CLASS_OR_LONG(flags_case, phpgtk_ce_GApplicationFlags, flags_long)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	if (application_id != NULL && !g_application_id_is_valid(ZSTR_VAL(application_id))) {
		zend_argument_value_error(1, "must be a valid application id (see GApplication::idIsValid())");
		RETURN_THROWS();
	}

	GtkApplication *app = gtk_application_new(
		application_id != NULL ? ZSTR_VAL(application_id) : NULL,
		(GApplicationFlags) phpgtk_enum_value(flags_case, flags_long)
	);

	phpgtk_box_gobject(return_value, app);
	g_object_unref(app);
}
