
extern zend_class_entry *gtk_gtk_grid_gtkgrid_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_Grid_GtkGrid);

PHP_METHOD(Gtk_GTK_Grid_GtkGrid, gtkGridNew);
PHP_METHOD(Gtk_GTK_Grid_GtkGrid, gtkGridAttach);
PHP_METHOD(Gtk_GTK_Grid_GtkGrid, gtkGridRemove);
PHP_METHOD(Gtk_GTK_Grid_GtkGrid, gtkGridSetRowSpacing);
PHP_METHOD(Gtk_GTK_Grid_GtkGrid, gtkGridSetColumnSpacing);
PHP_METHOD(Gtk_GTK_Grid_GtkGrid, gtkGridSetRowHomogeneous);
PHP_METHOD(Gtk_GTK_Grid_GtkGrid, gtkGridSetColumnHomogeneous);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_grid_gtkgrid_gtkgridnew, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_grid_gtkgrid_gtkgridattach, 0, 6, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, grid, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, column, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, row, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_grid_gtkgrid_gtkgridremove, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, grid, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_grid_gtkgrid_gtkgridsetrowspacing, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, grid, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, spacing, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_grid_gtkgrid_gtkgridsetcolumnspacing, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, grid, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, spacing, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_grid_gtkgrid_gtkgridsetrowhomogeneous, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, grid, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, homogeneous, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_grid_gtkgrid_gtkgridsetcolumnhomogeneous, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, grid, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, homogeneous, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_grid_gtkgrid_method_entry) {
	PHP_ME(Gtk_GTK_Grid_GtkGrid, gtkGridNew, arginfo_gtk_gtk_grid_gtkgrid_gtkgridnew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Grid_GtkGrid, gtkGridAttach, arginfo_gtk_gtk_grid_gtkgrid_gtkgridattach, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Grid_GtkGrid, gtkGridRemove, arginfo_gtk_gtk_grid_gtkgrid_gtkgridremove, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Grid_GtkGrid, gtkGridSetRowSpacing, arginfo_gtk_gtk_grid_gtkgrid_gtkgridsetrowspacing, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Grid_GtkGrid, gtkGridSetColumnSpacing, arginfo_gtk_gtk_grid_gtkgrid_gtkgridsetcolumnspacing, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Grid_GtkGrid, gtkGridSetRowHomogeneous, arginfo_gtk_gtk_grid_gtkgrid_gtkgridsetrowhomogeneous, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Grid_GtkGrid, gtkGridSetColumnHomogeneous, arginfo_gtk_gtk_grid_gtkgrid_gtkgridsetcolumnhomogeneous, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
