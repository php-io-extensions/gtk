/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: bb768b12e381d9b198e72e7edaf15a1b11662527 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWidget_show, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkWidget_hide arginfo_class_GtkWidget_show

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWidget_getVisible, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkWidget_getRealized arginfo_class_GtkWidget_getVisible

#define arginfo_class_GtkWidget_getMapped arginfo_class_GtkWidget_getVisible

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWidget_setVisible, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, visible, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkWidget_getHexpand arginfo_class_GtkWidget_getVisible

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWidget_setHexpand, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, expand, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkWidget_getVexpand arginfo_class_GtkWidget_getVisible

#define arginfo_class_GtkWidget_setVexpand arginfo_class_GtkWidget_setHexpand

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkWidget_getParent, 0, 0, GtkWidget, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWidget_insertActionGroup, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, group, GObject, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWidget_activateAction, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, args, GVariant, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkBox_new, 0, 2, GtkBox, 0)
	ZEND_ARG_OBJ_INFO(0, orientation, GtkOrientation, 0)
	ZEND_ARG_TYPE_INFO(0, spacing, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkBox_append, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, child, GtkWidget, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkBox_prepend arginfo_class_GtkBox_append

#define arginfo_class_GtkBox_remove arginfo_class_GtkBox_append

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkPopoverMenuBar_newFromModel, 0, 1, GtkPopoverMenuBar, 0)
	ZEND_ARG_OBJ_INFO(0, model, GMenuModel, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkPopoverMenuBar_getMenuModel, 0, 0, GMenuModel, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkPopoverMenuBar_setMenuModel, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, model, GMenuModel, 1)
ZEND_END_ARG_INFO()

ZEND_METHOD(GtkWidget, show);
ZEND_METHOD(GtkWidget, hide);
ZEND_METHOD(GtkWidget, getVisible);
ZEND_METHOD(GtkWidget, getRealized);
ZEND_METHOD(GtkWidget, getMapped);
ZEND_METHOD(GtkWidget, setVisible);
ZEND_METHOD(GtkWidget, getHexpand);
ZEND_METHOD(GtkWidget, setHexpand);
ZEND_METHOD(GtkWidget, getVexpand);
ZEND_METHOD(GtkWidget, setVexpand);
ZEND_METHOD(GtkWidget, getParent);
ZEND_METHOD(GtkWidget, insertActionGroup);
ZEND_METHOD(GtkWidget, activateAction);
ZEND_METHOD(GtkBox, new);
ZEND_METHOD(GtkBox, append);
ZEND_METHOD(GtkBox, prepend);
ZEND_METHOD(GtkBox, remove);
ZEND_METHOD(GtkPopoverMenuBar, newFromModel);
ZEND_METHOD(GtkPopoverMenuBar, getMenuModel);
ZEND_METHOD(GtkPopoverMenuBar, setMenuModel);

static const zend_function_entry class_GtkWidget_methods[] = {
	ZEND_ME(GtkWidget, show, arginfo_class_GtkWidget_show, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, hide, arginfo_class_GtkWidget_hide, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, getVisible, arginfo_class_GtkWidget_getVisible, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, getRealized, arginfo_class_GtkWidget_getRealized, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, getMapped, arginfo_class_GtkWidget_getMapped, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, setVisible, arginfo_class_GtkWidget_setVisible, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, getHexpand, arginfo_class_GtkWidget_getHexpand, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, setHexpand, arginfo_class_GtkWidget_setHexpand, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, getVexpand, arginfo_class_GtkWidget_getVexpand, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, setVexpand, arginfo_class_GtkWidget_setVexpand, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, getParent, arginfo_class_GtkWidget_getParent, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, insertActionGroup, arginfo_class_GtkWidget_insertActionGroup, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, activateAction, arginfo_class_GtkWidget_activateAction, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkBox_methods[] = {
	ZEND_ME(GtkBox, new, arginfo_class_GtkBox_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkBox, append, arginfo_class_GtkBox_append, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkBox, prepend, arginfo_class_GtkBox_prepend, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkBox, remove, arginfo_class_GtkBox_remove, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkPopoverMenuBar_methods[] = {
	ZEND_ME(GtkPopoverMenuBar, newFromModel, arginfo_class_GtkPopoverMenuBar_newFromModel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkPopoverMenuBar, getMenuModel, arginfo_class_GtkPopoverMenuBar_getMenuModel, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPopoverMenuBar, setMenuModel, arginfo_class_GtkPopoverMenuBar_setMenuModel, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_GtkOrientation(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GtkOrientation", IS_LONG, NULL);

	zval enum_case_HORIZONTAL_value;
	ZVAL_LONG(&enum_case_HORIZONTAL_value, 0);
	zend_enum_add_case_cstr(class_entry, "HORIZONTAL", &enum_case_HORIZONTAL_value);

	zval enum_case_VERTICAL_value;
	ZVAL_LONG(&enum_case_VERTICAL_value, 1);
	zend_enum_add_case_cstr(class_entry, "VERTICAL", &enum_case_VERTICAL_value);

	return class_entry;
}

static zend_class_entry *register_class_GtkWidget(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkWidget", class_GtkWidget_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkBox(zend_class_entry *class_entry_GtkWidget)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkBox", class_GtkBox_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkWidget, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkPopoverMenuBar(zend_class_entry *class_entry_GtkWidget)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkPopoverMenuBar", class_GtkPopoverMenuBar_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkWidget, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
