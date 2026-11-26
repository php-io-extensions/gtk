/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 6449f7695ce91602d9b9f250d69f6c44b485a564 */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkConstraintLayout_new, 0, 0, GtkConstraintLayout, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkConstraintLayout_addConstraint, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, constraint, GtkConstraint, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkConstraintLayout_addGuide, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, guide, GtkConstraintGuide, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkConstraint_new, 0, 8, GtkConstraint, 0)
	ZEND_ARG_OBJ_INFO(0, target, GtkConstraintTarget, 1)
	ZEND_ARG_OBJ_INFO(0, targetAttribute, GtkConstraintAttribute, 0)
	ZEND_ARG_OBJ_INFO(0, relation, GtkConstraintRelation, 0)
	ZEND_ARG_OBJ_INFO(0, source, GtkConstraintTarget, 1)
	ZEND_ARG_OBJ_INFO(0, sourceAttribute, GtkConstraintAttribute, 0)
	ZEND_ARG_TYPE_INFO(0, multiplier, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, constant, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, strength, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkConstraintGuide_new, 0, 0, GtkConstraintGuide, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkConstraintGuide_setNatSize, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkConstraintGuide_setMaxSize arginfo_class_GtkConstraintGuide_setNatSize

ZEND_METHOD(GtkConstraintLayout, new);
ZEND_METHOD(GtkConstraintLayout, addConstraint);
ZEND_METHOD(GtkConstraintLayout, addGuide);
ZEND_METHOD(GtkConstraint, new);
ZEND_METHOD(GtkConstraintGuide, new);
ZEND_METHOD(GtkConstraintGuide, setNatSize);
ZEND_METHOD(GtkConstraintGuide, setMaxSize);

static const zend_function_entry class_GtkConstraintLayout_methods[] = {
	ZEND_ME(GtkConstraintLayout, new, arginfo_class_GtkConstraintLayout_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkConstraintLayout, addConstraint, arginfo_class_GtkConstraintLayout_addConstraint, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkConstraintLayout, addGuide, arginfo_class_GtkConstraintLayout_addGuide, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkConstraint_methods[] = {
	ZEND_ME(GtkConstraint, new, arginfo_class_GtkConstraint_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkConstraintGuide_methods[] = {
	ZEND_ME(GtkConstraintGuide, new, arginfo_class_GtkConstraintGuide_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkConstraintGuide, setNatSize, arginfo_class_GtkConstraintGuide_setNatSize, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkConstraintGuide, setMaxSize, arginfo_class_GtkConstraintGuide_setMaxSize, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_GtkConstraintAttribute(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GtkConstraintAttribute", IS_LONG, NULL);

	zval enum_case_NONE_value;
	ZVAL_LONG(&enum_case_NONE_value, 0);
	zend_enum_add_case_cstr(class_entry, "NONE", &enum_case_NONE_value);

	zval enum_case_LEFT_value;
	ZVAL_LONG(&enum_case_LEFT_value, 1);
	zend_enum_add_case_cstr(class_entry, "LEFT", &enum_case_LEFT_value);

	zval enum_case_RIGHT_value;
	ZVAL_LONG(&enum_case_RIGHT_value, 2);
	zend_enum_add_case_cstr(class_entry, "RIGHT", &enum_case_RIGHT_value);

	zval enum_case_TOP_value;
	ZVAL_LONG(&enum_case_TOP_value, 3);
	zend_enum_add_case_cstr(class_entry, "TOP", &enum_case_TOP_value);

	zval enum_case_BOTTOM_value;
	ZVAL_LONG(&enum_case_BOTTOM_value, 4);
	zend_enum_add_case_cstr(class_entry, "BOTTOM", &enum_case_BOTTOM_value);

	zval enum_case_START_value;
	ZVAL_LONG(&enum_case_START_value, 5);
	zend_enum_add_case_cstr(class_entry, "START", &enum_case_START_value);

	zval enum_case_END_value;
	ZVAL_LONG(&enum_case_END_value, 6);
	zend_enum_add_case_cstr(class_entry, "END", &enum_case_END_value);

	zval enum_case_WIDTH_value;
	ZVAL_LONG(&enum_case_WIDTH_value, 7);
	zend_enum_add_case_cstr(class_entry, "WIDTH", &enum_case_WIDTH_value);

	zval enum_case_HEIGHT_value;
	ZVAL_LONG(&enum_case_HEIGHT_value, 8);
	zend_enum_add_case_cstr(class_entry, "HEIGHT", &enum_case_HEIGHT_value);

	zval enum_case_CENTER_X_value;
	ZVAL_LONG(&enum_case_CENTER_X_value, 9);
	zend_enum_add_case_cstr(class_entry, "CENTER_X", &enum_case_CENTER_X_value);

	zval enum_case_CENTER_Y_value;
	ZVAL_LONG(&enum_case_CENTER_Y_value, 10);
	zend_enum_add_case_cstr(class_entry, "CENTER_Y", &enum_case_CENTER_Y_value);

	zval enum_case_BASELINE_value;
	ZVAL_LONG(&enum_case_BASELINE_value, 11);
	zend_enum_add_case_cstr(class_entry, "BASELINE", &enum_case_BASELINE_value);

	return class_entry;
}

static zend_class_entry *register_class_GtkConstraintRelation(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GtkConstraintRelation", IS_LONG, NULL);

	zval enum_case_LE_value;
	ZVAL_LONG(&enum_case_LE_value, -1);
	zend_enum_add_case_cstr(class_entry, "LE", &enum_case_LE_value);

	zval enum_case_EQ_value;
	ZVAL_LONG(&enum_case_EQ_value, 0);
	zend_enum_add_case_cstr(class_entry, "EQ", &enum_case_EQ_value);

	zval enum_case_GE_value;
	ZVAL_LONG(&enum_case_GE_value, 1);
	zend_enum_add_case_cstr(class_entry, "GE", &enum_case_GE_value);

	return class_entry;
}

static zend_class_entry *register_class_GtkConstraintStrength(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GtkConstraintStrength", IS_LONG, NULL);

	zval enum_case_REQUIRED_value;
	ZVAL_LONG(&enum_case_REQUIRED_value, 1001001000);
	zend_enum_add_case_cstr(class_entry, "REQUIRED", &enum_case_REQUIRED_value);

	zval enum_case_STRONG_value;
	ZVAL_LONG(&enum_case_STRONG_value, 1000000000);
	zend_enum_add_case_cstr(class_entry, "STRONG", &enum_case_STRONG_value);

	zval enum_case_MEDIUM_value;
	ZVAL_LONG(&enum_case_MEDIUM_value, 1000);
	zend_enum_add_case_cstr(class_entry, "MEDIUM", &enum_case_MEDIUM_value);

	zval enum_case_WEAK_value;
	ZVAL_LONG(&enum_case_WEAK_value, 1);
	zend_enum_add_case_cstr(class_entry, "WEAK", &enum_case_WEAK_value);

	return class_entry;
}

static zend_class_entry *register_class_GtkLayoutManager(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkLayoutManager", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkConstraintLayout(zend_class_entry *class_entry_GtkLayoutManager)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkConstraintLayout", class_GtkConstraintLayout_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkLayoutManager, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkConstraint(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkConstraint", class_GtkConstraint_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkConstraintGuide(zend_class_entry *class_entry_GObject, zend_class_entry *class_entry_GtkConstraintTarget)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkConstraintGuide", class_GtkConstraintGuide_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);
	zend_class_implements(class_entry, 1, class_entry_GtkConstraintTarget);

	return class_entry;
}
