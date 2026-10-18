#include "runtime.h"
#include "../stubs/GtkColumnView_arginfo.h"

ZEND_METHOD(GtkSelectionModel, isSelected);
ZEND_METHOD(GtkSelectionModel, selectItem);
ZEND_METHOD(GtkSelectionModel, unselectItem);
ZEND_METHOD(GtkSelectionModel, selectRange);
ZEND_METHOD(GtkSelectionModel, unselectRange);
ZEND_METHOD(GtkSelectionModel, selectAll);
ZEND_METHOD(GtkSelectionModel, unselectAll);
ZEND_METHOD(GtkSelectionModel, selectionChanged);

static const phpgtk_interface_method phpgtk_GtkSelectionModel_bodies[] = {
	{"isSelected", zim_GtkSelectionModel_isSelected},
	{"selectItem", zim_GtkSelectionModel_selectItem},
	{"unselectItem", zim_GtkSelectionModel_unselectItem},
	{"selectRange", zim_GtkSelectionModel_selectRange},
	{"unselectRange", zim_GtkSelectionModel_unselectRange},
	{"selectAll", zim_GtkSelectionModel_selectAll},
	{"unselectAll", zim_GtkSelectionModel_unselectAll},
	{"selectionChanged", zim_GtkSelectionModel_selectionChanged},
	{NULL, NULL},
};

void phpgtk_register_GtkColumnView(void)
{
	/* GListModel's methods are copied in with their bodies: GListModel was registered first (GAction.c). */
	phpgtk_ce_GtkSelectionModel = register_class_GtkSelectionModel(phpgtk_ce_GListModel);
	phpgtk_interface_bodies(phpgtk_ce_GtkSelectionModel, phpgtk_GtkSelectionModel_bodies);
	phpgtk_ce_GtkSelectionModel->interface_gets_implemented = phpgtk_interface_native_only;

	phpgtk_ce_GtkListItemFactory = register_class_GtkListItemFactory(phpgtk_ce_GObject);
	phpgtk_object_setup(phpgtk_ce_GtkListItemFactory);
	phpgtk_map_gtype("GtkListItemFactory", phpgtk_ce_GtkListItemFactory);

	phpgtk_ce_GtkSignalListItemFactory = register_class_GtkSignalListItemFactory(phpgtk_ce_GtkListItemFactory);
	phpgtk_object_setup(phpgtk_ce_GtkSignalListItemFactory);
	phpgtk_map_gtype("GtkSignalListItemFactory", phpgtk_ce_GtkSignalListItemFactory);

	phpgtk_ce_GtkListItem = register_class_GtkListItem(phpgtk_ce_GObject);
	phpgtk_object_setup(phpgtk_ce_GtkListItem);
	phpgtk_map_gtype("GtkListItem", phpgtk_ce_GtkListItem);

	phpgtk_ce_GtkColumnViewColumn = register_class_GtkColumnViewColumn(phpgtk_ce_GObject);
	phpgtk_object_setup(phpgtk_ce_GtkColumnViewColumn);
	phpgtk_map_gtype("GtkColumnViewColumn", phpgtk_ce_GtkColumnViewColumn);

	phpgtk_ce_GtkColumnView = register_class_GtkColumnView(phpgtk_ce_GtkWidget);
	phpgtk_object_setup(phpgtk_ce_GtkColumnView);
	phpgtk_map_gtype("GtkColumnView", phpgtk_ce_GtkColumnView);

	phpgtk_ce_GtkSingleSelection = register_class_GtkSingleSelection(phpgtk_ce_GObject, phpgtk_ce_GtkSelectionModel);
	phpgtk_object_setup(phpgtk_ce_GtkSingleSelection);
	phpgtk_map_gtype("GtkSingleSelection", phpgtk_ce_GtkSingleSelection);
}

#define THIS(cast) cast(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

/* ---- GtkSelectionModel ------------------------------------------------- */

/* $this's native object, implementing GtkSelectionModel (GtkSingleSelection). */
#define THIS_SELECTION_MODEL GTK_SELECTION_MODEL(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

ZEND_METHOD(GtkSelectionModel, isSelected)
{
	zend_long position;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_BOOL(gtk_selection_model_is_selected(THIS_SELECTION_MODEL, (guint) position));
}

ZEND_METHOD(GtkSelectionModel, selectItem)
{
	zend_long position;
	bool unselect_rest;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(position)
		Z_PARAM_BOOL(unselect_rest)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_BOOL(gtk_selection_model_select_item(THIS_SELECTION_MODEL, (guint) position, unselect_rest));
}

ZEND_METHOD(GtkSelectionModel, unselectItem)
{
	zend_long position;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_BOOL(gtk_selection_model_unselect_item(THIS_SELECTION_MODEL, (guint) position));
}

ZEND_METHOD(GtkSelectionModel, selectRange)
{
	zend_long position, n_items;
	bool unselect_rest;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_LONG(position)
		Z_PARAM_LONG(n_items)
		Z_PARAM_BOOL(unselect_rest)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_BOOL(gtk_selection_model_select_range(THIS_SELECTION_MODEL, (guint) position, (guint) n_items, unselect_rest));
}

ZEND_METHOD(GtkSelectionModel, unselectRange)
{
	zend_long position, n_items;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(position)
		Z_PARAM_LONG(n_items)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_BOOL(gtk_selection_model_unselect_range(THIS_SELECTION_MODEL, (guint) position, (guint) n_items));
}

ZEND_METHOD(GtkSelectionModel, selectAll)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_BOOL(gtk_selection_model_select_all(THIS_SELECTION_MODEL));
}

ZEND_METHOD(GtkSelectionModel, unselectAll)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_BOOL(gtk_selection_model_unselect_all(THIS_SELECTION_MODEL));
}

ZEND_METHOD(GtkSelectionModel, selectionChanged)
{
	zend_long position, n_items;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(position)
		Z_PARAM_LONG(n_items)
	ZEND_PARSE_PARAMETERS_END();

	gtk_selection_model_selection_changed(THIS_SELECTION_MODEL, (guint) position, (guint) n_items);
}

/* The model arguments GTK asserts on: refused here with the interface named. */
static bool phpgtk_require_selection_model(zend_object *model, uint32_t arg_num)
{
	if (model != NULL && !GTK_IS_SELECTION_MODEL(PHPGTK_PTR(model))) {
		zend_argument_value_error(arg_num, "must be a GtkSelectionModel, %s is not", G_OBJECT_TYPE_NAME(PHPGTK_PTR(model)));
		return false;
	}

	return true;
}

static bool phpgtk_require_list_model(zend_object *model, uint32_t arg_num)
{
	if (model != NULL && !G_IS_LIST_MODEL(PHPGTK_PTR(model))) {
		zend_argument_value_error(arg_num, "must be a GListModel, %s is not", G_OBJECT_TYPE_NAME(PHPGTK_PTR(model)));
		return false;
	}

	return true;
}

/* ---- GtkSignalListItemFactory ------------------------------------------ */

ZEND_METHOD(GtkSignalListItemFactory, new)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();

	phpgtk_box_gobject_full(return_value, gtk_signal_list_item_factory_new());
}

/* ---- GtkListItem ------------------------------------------------------- */

ZEND_METHOD(GtkListItem, getPosition)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG((zend_long) gtk_list_item_get_position(THIS(GTK_LIST_ITEM)));
}

ZEND_METHOD(GtkListItem, getItem)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_list_item_get_item(THIS(GTK_LIST_ITEM)));
}

ZEND_METHOD(GtkListItem, getChild)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_list_item_get_child(THIS(GTK_LIST_ITEM)));
}

ZEND_METHOD(GtkListItem, setChild)
{
	zend_object *child = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(child, phpgtk_ce_GtkWidget)
	ZEND_PARSE_PARAMETERS_END();

	gtk_list_item_set_child(THIS(GTK_LIST_ITEM), (GtkWidget *) PHPGTK_OPTIONAL_PTR(child));
}

/* ---- GtkColumnViewColumn ----------------------------------------------- */

ZEND_METHOD(GtkColumnViewColumn, new)
{
	zend_string *title = NULL;
	zend_object *factory = NULL;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR_OR_NULL(title)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(factory, phpgtk_ce_GtkListItemFactory)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	/* The factory argument is (transfer full); PHP keeps its own reference, so the column gets a new one. */
	phpgtk_box_gobject_full(return_value, gtk_column_view_column_new(
		title != NULL ? ZSTR_VAL(title) : NULL,
		factory != NULL ? g_object_ref(GTK_LIST_ITEM_FACTORY(PHPGTK_PTR(factory))) : NULL));
}

ZEND_METHOD(GtkColumnViewColumn, getTitle)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_return_string(return_value, gtk_column_view_column_get_title(THIS(GTK_COLUMN_VIEW_COLUMN)));
}

ZEND_METHOD(GtkColumnViewColumn, setTitle)
{
	zend_string *title = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR_OR_NULL(title)
	ZEND_PARSE_PARAMETERS_END();

	gtk_column_view_column_set_title(THIS(GTK_COLUMN_VIEW_COLUMN), title != NULL ? ZSTR_VAL(title) : NULL);
}

ZEND_METHOD(GtkColumnViewColumn, setExpand)
{
	bool expand;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(expand)
	ZEND_PARSE_PARAMETERS_END();

	gtk_column_view_column_set_expand(THIS(GTK_COLUMN_VIEW_COLUMN), expand);
}

ZEND_METHOD(GtkColumnViewColumn, setResizable)
{
	bool resizable;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(resizable)
	ZEND_PARSE_PARAMETERS_END();

	gtk_column_view_column_set_resizable(THIS(GTK_COLUMN_VIEW_COLUMN), resizable);
}

/* ---- GtkColumnView ----------------------------------------------------- */

ZEND_METHOD(GtkColumnView, new)
{
	zend_object *model = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(model, phpgtk_ce_GObject)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();
	PHPGTK_REQUIRE_INITIALIZED();

	if (!phpgtk_require_selection_model(model, 1)) {
		RETURN_THROWS();
	}

	/* The model argument is (transfer full); the view gets its own reference. */
	phpgtk_box_gobject(return_value, gtk_column_view_new(
		model != NULL ? g_object_ref(GTK_SELECTION_MODEL(PHPGTK_PTR(model))) : NULL));
}

ZEND_METHOD(GtkColumnView, appendColumn)
{
	zend_object *column;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(column, phpgtk_ce_GtkColumnViewColumn)
	ZEND_PARSE_PARAMETERS_END();

	gtk_column_view_append_column(THIS(GTK_COLUMN_VIEW), GTK_COLUMN_VIEW_COLUMN(PHPGTK_PTR(column)));
}

ZEND_METHOD(GtkColumnView, removeColumn)
{
	zend_object *column;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(column, phpgtk_ce_GtkColumnViewColumn)
	ZEND_PARSE_PARAMETERS_END();

	gtk_column_view_remove_column(THIS(GTK_COLUMN_VIEW), GTK_COLUMN_VIEW_COLUMN(PHPGTK_PTR(column)));
}

ZEND_METHOD(GtkColumnView, getModel)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_column_view_get_model(THIS(GTK_COLUMN_VIEW)));
}

ZEND_METHOD(GtkColumnView, setModel)
{
	zend_object *model = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(model, phpgtk_ce_GObject)
	ZEND_PARSE_PARAMETERS_END();

	if (!phpgtk_require_selection_model(model, 1)) {
		RETURN_THROWS();
	}

	gtk_column_view_set_model(THIS(GTK_COLUMN_VIEW), (GtkSelectionModel *) PHPGTK_OPTIONAL_PTR(model));
}

ZEND_METHOD(GtkColumnView, setShowRowSeparators)
{
	bool show;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(show)
	ZEND_PARSE_PARAMETERS_END();

	gtk_column_view_set_show_row_separators(THIS(GTK_COLUMN_VIEW), show);
}

ZEND_METHOD(GtkColumnView, setShowColumnSeparators)
{
	bool show;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(show)
	ZEND_PARSE_PARAMETERS_END();

	gtk_column_view_set_show_column_separators(THIS(GTK_COLUMN_VIEW), show);
}

/* ---- GtkSingleSelection ------------------------------------------------ */

ZEND_METHOD(GtkSingleSelection, new)
{
	zend_object *model = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(model, phpgtk_ce_GObject)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	if (!phpgtk_require_list_model(model, 1)) {
		RETURN_THROWS();
	}

	/* The model argument is (transfer full); the selection gets its own reference. */
	phpgtk_box_gobject_full(return_value, gtk_single_selection_new(
		model != NULL ? g_object_ref(G_LIST_MODEL(PHPGTK_PTR(model))) : NULL));
}

ZEND_METHOD(GtkSingleSelection, getSelected)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG((zend_long) gtk_single_selection_get_selected(THIS(GTK_SINGLE_SELECTION)));
}

ZEND_METHOD(GtkSingleSelection, setSelected)
{
	zend_long position;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();

	if (!phpgtk_long_in_range(position, 0, (zend_long) G_MAXUINT, 1)) {
		RETURN_THROWS();
	}

	gtk_single_selection_set_selected(THIS(GTK_SINGLE_SELECTION), (guint) position);
}

ZEND_METHOD(GtkSingleSelection, getSelectedItem)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_single_selection_get_selected_item(THIS(GTK_SINGLE_SELECTION)));
}

ZEND_METHOD(GtkSingleSelection, setAutoselect)
{
	bool autoselect;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(autoselect)
	ZEND_PARSE_PARAMETERS_END();

	gtk_single_selection_set_autoselect(THIS(GTK_SINGLE_SELECTION), autoselect);
}

ZEND_METHOD(GtkSingleSelection, setCanUnselect)
{
	bool can_unselect;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(can_unselect)
	ZEND_PARSE_PARAMETERS_END();

	gtk_single_selection_set_can_unselect(THIS(GTK_SINGLE_SELECTION), can_unselect);
}

ZEND_METHOD(GtkSingleSelection, getModel)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_single_selection_get_model(THIS(GTK_SINGLE_SELECTION)));
}
