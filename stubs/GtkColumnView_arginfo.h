/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 4227dbb948c003a1c7b6ea89b5da342a8052c17d */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkSignalListItemFactory_new, 0, 0, GtkSignalListItemFactory, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkListItem_getPosition, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkListItem_getItem, 0, 0, GObject, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkListItem_getChild, 0, 0, GtkWidget, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkListItem_setChild, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, child, GtkWidget, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkColumnViewColumn_new, 0, 2, GtkColumnViewColumn, 0)
	ZEND_ARG_TYPE_INFO(0, title, IS_STRING, 1)
	ZEND_ARG_OBJ_INFO(0, factory, GtkSignalListItemFactory, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkColumnViewColumn_getTitle, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkColumnViewColumn_setTitle, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, title, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkColumnViewColumn_setExpand, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, expand, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkColumnViewColumn_setResizable, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, resizable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkColumnView_new, 0, 1, GtkColumnView, 0)
	ZEND_ARG_OBJ_INFO(0, model, GObject, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkColumnView_appendColumn, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, column, GtkColumnViewColumn, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkColumnView_removeColumn arginfo_class_GtkColumnView_appendColumn

#define arginfo_class_GtkColumnView_getModel arginfo_class_GtkListItem_getItem

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkColumnView_setModel, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, model, GObject, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkColumnView_setShowRowSeparators, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, showRowSeparators, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkColumnView_setShowColumnSeparators, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, showColumnSeparators, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkSingleSelection_new, 0, 1, GtkSingleSelection, 0)
	ZEND_ARG_OBJ_INFO(0, model, GObject, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkSingleSelection_getSelected arginfo_class_GtkListItem_getPosition

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkSingleSelection_setSelected, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkSingleSelection_getSelectedItem arginfo_class_GtkListItem_getItem

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkSingleSelection_setAutoselect, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, autoselect, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkSingleSelection_setCanUnselect, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, canUnselect, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkSingleSelection_getModel arginfo_class_GtkListItem_getItem

ZEND_METHOD(GtkSignalListItemFactory, new);
ZEND_METHOD(GtkListItem, getPosition);
ZEND_METHOD(GtkListItem, getItem);
ZEND_METHOD(GtkListItem, getChild);
ZEND_METHOD(GtkListItem, setChild);
ZEND_METHOD(GtkColumnViewColumn, new);
ZEND_METHOD(GtkColumnViewColumn, getTitle);
ZEND_METHOD(GtkColumnViewColumn, setTitle);
ZEND_METHOD(GtkColumnViewColumn, setExpand);
ZEND_METHOD(GtkColumnViewColumn, setResizable);
ZEND_METHOD(GtkColumnView, new);
ZEND_METHOD(GtkColumnView, appendColumn);
ZEND_METHOD(GtkColumnView, removeColumn);
ZEND_METHOD(GtkColumnView, getModel);
ZEND_METHOD(GtkColumnView, setModel);
ZEND_METHOD(GtkColumnView, setShowRowSeparators);
ZEND_METHOD(GtkColumnView, setShowColumnSeparators);
ZEND_METHOD(GtkSingleSelection, new);
ZEND_METHOD(GtkSingleSelection, getSelected);
ZEND_METHOD(GtkSingleSelection, setSelected);
ZEND_METHOD(GtkSingleSelection, getSelectedItem);
ZEND_METHOD(GtkSingleSelection, setAutoselect);
ZEND_METHOD(GtkSingleSelection, setCanUnselect);
ZEND_METHOD(GtkSingleSelection, getModel);

static const zend_function_entry class_GtkSignalListItemFactory_methods[] = {
	ZEND_ME(GtkSignalListItemFactory, new, arginfo_class_GtkSignalListItemFactory_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkListItem_methods[] = {
	ZEND_ME(GtkListItem, getPosition, arginfo_class_GtkListItem_getPosition, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkListItem, getItem, arginfo_class_GtkListItem_getItem, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkListItem, getChild, arginfo_class_GtkListItem_getChild, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkListItem, setChild, arginfo_class_GtkListItem_setChild, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkColumnViewColumn_methods[] = {
	ZEND_ME(GtkColumnViewColumn, new, arginfo_class_GtkColumnViewColumn_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkColumnViewColumn, getTitle, arginfo_class_GtkColumnViewColumn_getTitle, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkColumnViewColumn, setTitle, arginfo_class_GtkColumnViewColumn_setTitle, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkColumnViewColumn, setExpand, arginfo_class_GtkColumnViewColumn_setExpand, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkColumnViewColumn, setResizable, arginfo_class_GtkColumnViewColumn_setResizable, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkColumnView_methods[] = {
	ZEND_ME(GtkColumnView, new, arginfo_class_GtkColumnView_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkColumnView, appendColumn, arginfo_class_GtkColumnView_appendColumn, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkColumnView, removeColumn, arginfo_class_GtkColumnView_removeColumn, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkColumnView, getModel, arginfo_class_GtkColumnView_getModel, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkColumnView, setModel, arginfo_class_GtkColumnView_setModel, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkColumnView, setShowRowSeparators, arginfo_class_GtkColumnView_setShowRowSeparators, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkColumnView, setShowColumnSeparators, arginfo_class_GtkColumnView_setShowColumnSeparators, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkSingleSelection_methods[] = {
	ZEND_ME(GtkSingleSelection, new, arginfo_class_GtkSingleSelection_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkSingleSelection, getSelected, arginfo_class_GtkSingleSelection_getSelected, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkSingleSelection, setSelected, arginfo_class_GtkSingleSelection_setSelected, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkSingleSelection, getSelectedItem, arginfo_class_GtkSingleSelection_getSelectedItem, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkSingleSelection, setAutoselect, arginfo_class_GtkSingleSelection_setAutoselect, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkSingleSelection, setCanUnselect, arginfo_class_GtkSingleSelection_setCanUnselect, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkSingleSelection, getModel, arginfo_class_GtkSingleSelection_getModel, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_GtkSignalListItemFactory(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkSignalListItemFactory", class_GtkSignalListItemFactory_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkListItem(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkListItem", class_GtkListItem_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkColumnViewColumn(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkColumnViewColumn", class_GtkColumnViewColumn_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkColumnView(zend_class_entry *class_entry_GtkWidget)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkColumnView", class_GtkColumnView_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkWidget, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkSingleSelection(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkSingleSelection", class_GtkSingleSelection_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
