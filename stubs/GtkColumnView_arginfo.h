/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: d08399191ad171b58b3fb8025add3c37540d88a7 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkSelectionModel_isSelected, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkSelectionModel_selectItem, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, unselectRest, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkSelectionModel_unselectItem arginfo_class_GtkSelectionModel_isSelected

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkSelectionModel_selectRange, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, nItems, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, unselectRest, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkSelectionModel_unselectRange, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, nItems, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkSelectionModel_selectAll, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkSelectionModel_unselectAll arginfo_class_GtkSelectionModel_selectAll

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkSelectionModel_selectionChanged, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, nItems, IS_LONG, 0)
ZEND_END_ARG_INFO()

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
	ZEND_ARG_OBJ_INFO(0, factory, GtkListItemFactory, 1)
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
	ZEND_ARG_OBJ_INFO(0, model, GtkSelectionModel, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkColumnView_appendColumn, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, column, GtkColumnViewColumn, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkColumnView_removeColumn arginfo_class_GtkColumnView_appendColumn

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkColumnView_getModel, 0, 0, GtkSelectionModel, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkColumnView_setModel, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, model, GtkSelectionModel, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkColumnView_setShowRowSeparators, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, showRowSeparators, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkColumnView_setShowColumnSeparators, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, showColumnSeparators, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkColumnView_scrollTo, 0, 4, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, pos, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, column, GtkColumnViewColumn, 1)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, scroll, GtkScrollInfo, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkTreeListModel_new, 0, 4, GtkTreeListModel, 0)
	ZEND_ARG_OBJ_INFO(0, root, GListModel, 0)
	ZEND_ARG_TYPE_INFO(0, passthrough, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, autoexpand, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, createFunc, IS_CALLABLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkTreeListModel_getRow, 0, 1, GtkTreeListRow, 1)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkTreeListModel_getChildRow arginfo_class_GtkTreeListModel_getRow

#define arginfo_class_GtkTreeListRow_getItem arginfo_class_GtkListItem_getItem

#define arginfo_class_GtkTreeListRow_getExpanded arginfo_class_GtkSelectionModel_selectAll

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkTreeListRow_setExpanded, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, expanded, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkTreeListRow_isExpandable arginfo_class_GtkSelectionModel_selectAll

#define arginfo_class_GtkTreeListRow_getDepth arginfo_class_GtkListItem_getPosition

#define arginfo_class_GtkTreeListRow_getPosition arginfo_class_GtkListItem_getPosition

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkTreeListRow_getParent, 0, 0, GtkTreeListRow, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkTreeListRow_getChildRow arginfo_class_GtkTreeListModel_getRow

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkTreeExpander_new, 0, 0, GtkTreeExpander, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkTreeExpander_getChild arginfo_class_GtkListItem_getChild

#define arginfo_class_GtkTreeExpander_setChild arginfo_class_GtkListItem_setChild

#define arginfo_class_GtkTreeExpander_getListRow arginfo_class_GtkTreeListRow_getParent

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkTreeExpander_setListRow, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, listRow, GtkTreeListRow, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_GtkScrollInfo___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkScrollInfo_new, 0, 0, GtkScrollInfo, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkScrollInfo_getEnableHorizontal arginfo_class_GtkSelectionModel_selectAll

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkScrollInfo_setEnableHorizontal, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, horizontal, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkScrollInfo_getEnableVertical arginfo_class_GtkSelectionModel_selectAll

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkScrollInfo_setEnableVertical, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, vertical, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkSingleSelection_new, 0, 1, GtkSingleSelection, 0)
	ZEND_ARG_OBJ_INFO(0, model, GListModel, 1)
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

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkSingleSelection_getModel, 0, 0, GListModel, 1)
ZEND_END_ARG_INFO()

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
ZEND_METHOD(GtkColumnView, scrollTo);
ZEND_METHOD(GtkTreeListModel, new);
ZEND_METHOD(GtkTreeListModel, getRow);
ZEND_METHOD(GtkTreeListModel, getChildRow);
ZEND_METHOD(GtkTreeListRow, getItem);
ZEND_METHOD(GtkTreeListRow, getExpanded);
ZEND_METHOD(GtkTreeListRow, setExpanded);
ZEND_METHOD(GtkTreeListRow, isExpandable);
ZEND_METHOD(GtkTreeListRow, getDepth);
ZEND_METHOD(GtkTreeListRow, getPosition);
ZEND_METHOD(GtkTreeListRow, getParent);
ZEND_METHOD(GtkTreeListRow, getChildRow);
ZEND_METHOD(GtkTreeExpander, new);
ZEND_METHOD(GtkTreeExpander, getChild);
ZEND_METHOD(GtkTreeExpander, setChild);
ZEND_METHOD(GtkTreeExpander, getListRow);
ZEND_METHOD(GtkTreeExpander, setListRow);
ZEND_METHOD(GtkScrollInfo, __construct);
ZEND_METHOD(GtkScrollInfo, new);
ZEND_METHOD(GtkScrollInfo, getEnableHorizontal);
ZEND_METHOD(GtkScrollInfo, setEnableHorizontal);
ZEND_METHOD(GtkScrollInfo, getEnableVertical);
ZEND_METHOD(GtkScrollInfo, setEnableVertical);
ZEND_METHOD(GtkSingleSelection, new);
ZEND_METHOD(GtkSingleSelection, getSelected);
ZEND_METHOD(GtkSingleSelection, setSelected);
ZEND_METHOD(GtkSingleSelection, getSelectedItem);
ZEND_METHOD(GtkSingleSelection, setAutoselect);
ZEND_METHOD(GtkSingleSelection, setCanUnselect);
ZEND_METHOD(GtkSingleSelection, getModel);

static const zend_function_entry class_GtkSelectionModel_methods[] = {
	ZEND_RAW_FENTRY("isSelected", NULL, arginfo_class_GtkSelectionModel_isSelected, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("selectItem", NULL, arginfo_class_GtkSelectionModel_selectItem, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("unselectItem", NULL, arginfo_class_GtkSelectionModel_unselectItem, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("selectRange", NULL, arginfo_class_GtkSelectionModel_selectRange, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("unselectRange", NULL, arginfo_class_GtkSelectionModel_unselectRange, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("selectAll", NULL, arginfo_class_GtkSelectionModel_selectAll, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("unselectAll", NULL, arginfo_class_GtkSelectionModel_unselectAll, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("selectionChanged", NULL, arginfo_class_GtkSelectionModel_selectionChanged, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_FE_END
};

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
	ZEND_ME(GtkColumnView, scrollTo, arginfo_class_GtkColumnView_scrollTo, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkTreeListModel_methods[] = {
	ZEND_ME(GtkTreeListModel, new, arginfo_class_GtkTreeListModel_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkTreeListModel, getRow, arginfo_class_GtkTreeListModel_getRow, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTreeListModel, getChildRow, arginfo_class_GtkTreeListModel_getChildRow, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkTreeListRow_methods[] = {
	ZEND_ME(GtkTreeListRow, getItem, arginfo_class_GtkTreeListRow_getItem, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTreeListRow, getExpanded, arginfo_class_GtkTreeListRow_getExpanded, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTreeListRow, setExpanded, arginfo_class_GtkTreeListRow_setExpanded, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTreeListRow, isExpandable, arginfo_class_GtkTreeListRow_isExpandable, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTreeListRow, getDepth, arginfo_class_GtkTreeListRow_getDepth, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTreeListRow, getPosition, arginfo_class_GtkTreeListRow_getPosition, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTreeListRow, getParent, arginfo_class_GtkTreeListRow_getParent, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTreeListRow, getChildRow, arginfo_class_GtkTreeListRow_getChildRow, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkTreeExpander_methods[] = {
	ZEND_ME(GtkTreeExpander, new, arginfo_class_GtkTreeExpander_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkTreeExpander, getChild, arginfo_class_GtkTreeExpander_getChild, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTreeExpander, setChild, arginfo_class_GtkTreeExpander_setChild, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTreeExpander, getListRow, arginfo_class_GtkTreeExpander_getListRow, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTreeExpander, setListRow, arginfo_class_GtkTreeExpander_setListRow, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkScrollInfo_methods[] = {
	ZEND_ME(GtkScrollInfo, __construct, arginfo_class_GtkScrollInfo___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(GtkScrollInfo, new, arginfo_class_GtkScrollInfo_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkScrollInfo, getEnableHorizontal, arginfo_class_GtkScrollInfo_getEnableHorizontal, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkScrollInfo, setEnableHorizontal, arginfo_class_GtkScrollInfo_setEnableHorizontal, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkScrollInfo, getEnableVertical, arginfo_class_GtkScrollInfo_getEnableVertical, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkScrollInfo, setEnableVertical, arginfo_class_GtkScrollInfo_setEnableVertical, ZEND_ACC_PUBLIC)
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

static zend_class_entry *register_class_GtkSelectionModel(zend_class_entry *class_entry_GListModel)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkSelectionModel", class_GtkSelectionModel_methods);
	class_entry = zend_register_internal_interface(&ce);
	zend_class_implements(class_entry, 1, class_entry_GListModel);

	return class_entry;
}

static zend_class_entry *register_class_GtkListItemFactory(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkListItemFactory", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkSignalListItemFactory(zend_class_entry *class_entry_GtkListItemFactory)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkSignalListItemFactory", class_GtkSignalListItemFactory_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkListItemFactory, ZEND_ACC_NOT_SERIALIZABLE);

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

static zend_class_entry *register_class_GtkTreeListModel(zend_class_entry *class_entry_GObject, zend_class_entry *class_entry_GListModel)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkTreeListModel", class_GtkTreeListModel_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);
	zend_class_implements(class_entry, 1, class_entry_GListModel);

	return class_entry;
}

static zend_class_entry *register_class_GtkTreeListRow(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkTreeListRow", class_GtkTreeListRow_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkTreeExpander(zend_class_entry *class_entry_GtkWidget)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkTreeExpander", class_GtkTreeExpander_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkWidget, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkScrollInfo(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkScrollInfo", class_GtkScrollInfo_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkSingleSelection(zend_class_entry *class_entry_GObject, zend_class_entry *class_entry_GtkSelectionModel)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkSingleSelection", class_GtkSingleSelection_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);
	zend_class_implements(class_entry, 1, class_entry_GtkSelectionModel);

	return class_entry;
}
