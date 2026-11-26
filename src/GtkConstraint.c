#include "runtime.h"
#include "../stubs/GtkConstraint_arginfo.h"

static zend_class_entry *phpgtk_ce_GtkConstraintAttribute;
static zend_class_entry *phpgtk_ce_GtkConstraintRelation;
static zend_class_entry *phpgtk_ce_GtkConstraintStrength;

void phpgtk_register_GtkConstraint(void)
{
	phpgtk_ce_GtkConstraintAttribute = register_class_GtkConstraintAttribute();
	phpgtk_ce_GtkConstraintRelation = register_class_GtkConstraintRelation();
	phpgtk_ce_GtkConstraintStrength = register_class_GtkConstraintStrength();

	phpgtk_ce_GtkLayoutManager = register_class_GtkLayoutManager(phpgtk_ce_GObject);
	phpgtk_object_setup(phpgtk_ce_GtkLayoutManager);
	phpgtk_map_gtype("GtkLayoutManager", phpgtk_ce_GtkLayoutManager);

	phpgtk_ce_GtkConstraintLayout = register_class_GtkConstraintLayout(phpgtk_ce_GtkLayoutManager);
	phpgtk_object_setup(phpgtk_ce_GtkConstraintLayout);
	phpgtk_map_gtype("GtkConstraintLayout", phpgtk_ce_GtkConstraintLayout);

	phpgtk_ce_GtkConstraint = register_class_GtkConstraint(phpgtk_ce_GObject);
	phpgtk_object_setup(phpgtk_ce_GtkConstraint);
	phpgtk_map_gtype("GtkConstraint", phpgtk_ce_GtkConstraint);

	phpgtk_ce_GtkConstraintGuide = register_class_GtkConstraintGuide(phpgtk_ce_GObject, phpgtk_ce_GtkConstraintTarget);
	phpgtk_object_setup(phpgtk_ce_GtkConstraintGuide);
	phpgtk_map_gtype("GtkConstraintGuide", phpgtk_ce_GtkConstraintGuide);
}

#define THIS(cast) cast(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

/* ---- GtkConstraintLayout ----------------------------------------------- */

ZEND_METHOD(GtkConstraintLayout, new)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();

	phpgtk_box_gobject_full(return_value, gtk_constraint_layout_new());
}

ZEND_METHOD(GtkConstraintLayout, addConstraint)
{
	zend_object *constraint;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(constraint, phpgtk_ce_GtkConstraint)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	/* gtk_constraint_layout_add_constraint() takes the caller's reference; the PHP object keeps its own. */
	gtk_constraint_layout_add_constraint(THIS(GTK_CONSTRAINT_LAYOUT), GTK_CONSTRAINT(g_object_ref(PHPGTK_PTR(constraint))));
}

ZEND_METHOD(GtkConstraintLayout, addGuide)
{
	zend_object *guide;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(guide, phpgtk_ce_GtkConstraintGuide)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	/* gtk_constraint_layout_add_guide() takes the caller's reference; the PHP object keeps its own. */
	gtk_constraint_layout_add_guide(THIS(GTK_CONSTRAINT_LAYOUT), GTK_CONSTRAINT_GUIDE(g_object_ref(PHPGTK_PTR(guide))));
}

/* ---- GtkConstraint ----------------------------------------------------- */

ZEND_METHOD(GtkConstraint, new)
{
	zend_object *target, *target_attribute, *relation, *source, *source_attribute;
	double multiplier, constant;
	zend_long strength;

	ZEND_PARSE_PARAMETERS_START(8, 8)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(target, phpgtk_ce_GtkConstraintTarget)
		Z_PARAM_OBJ_OF_CLASS(target_attribute, phpgtk_ce_GtkConstraintAttribute)
		Z_PARAM_OBJ_OF_CLASS(relation, phpgtk_ce_GtkConstraintRelation)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(source, phpgtk_ce_GtkConstraintTarget)
		Z_PARAM_OBJ_OF_CLASS(source_attribute, phpgtk_ce_GtkConstraintAttribute)
		Z_PARAM_DOUBLE(multiplier)
		Z_PARAM_DOUBLE(constant)
		Z_PARAM_LONG(strength)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	phpgtk_box_gobject_full(return_value, gtk_constraint_new(
		PHPGTK_OPTIONAL_PTR(target),
		(GtkConstraintAttribute) phpgtk_enum_value(target_attribute, 0),
		(GtkConstraintRelation) phpgtk_enum_value(relation, 0),
		PHPGTK_OPTIONAL_PTR(source),
		(GtkConstraintAttribute) phpgtk_enum_value(source_attribute, 0),
		multiplier, constant, (int) strength));
}

/* ---- GtkConstraintGuide ------------------------------------------------ */

ZEND_METHOD(GtkConstraintGuide, new)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();

	phpgtk_box_gobject_full(return_value, gtk_constraint_guide_new());
}

ZEND_METHOD(GtkConstraintGuide, setNatSize)
{
	zend_long width, height;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();

	gtk_constraint_guide_set_nat_size(THIS(GTK_CONSTRAINT_GUIDE), (int) width, (int) height);
}

ZEND_METHOD(GtkConstraintGuide, setMaxSize)
{
	zend_long width, height;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(width)
		Z_PARAM_LONG(height)
	ZEND_PARSE_PARAMETERS_END();

	gtk_constraint_guide_set_max_size(THIS(GTK_CONSTRAINT_GUIDE), (int) width, (int) height);
}
