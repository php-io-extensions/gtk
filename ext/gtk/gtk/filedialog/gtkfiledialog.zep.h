
extern zend_class_entry *gtk_gtk_filedialog_gtkfiledialog_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_FileDialog_GtkFileDialog);

PHP_METHOD(Gtk_GTK_FileDialog_GtkFileDialog, gtkFileDialogNew);
PHP_METHOD(Gtk_GTK_FileDialog_GtkFileDialog, gtkFileDialogSetTitle);
PHP_METHOD(Gtk_GTK_FileDialog_GtkFileDialog, gtkFileDialogGetTitle);
PHP_METHOD(Gtk_GTK_FileDialog_GtkFileDialog, gtkFileDialogSetInitialName);
PHP_METHOD(Gtk_GTK_FileDialog_GtkFileDialog, gtkFileDialogOpen);
PHP_METHOD(Gtk_GTK_FileDialog_GtkFileDialog, gtkFileDialogSave);
PHP_METHOD(Gtk_GTK_FileDialog_GtkFileDialog, gtkFileDialogSelectFolder);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_filedialog_gtkfiledialog_gtkfiledialognew, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_filedialog_gtkfiledialog_gtkfiledialogsettitle, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, dialog, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, title, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_filedialog_gtkfiledialog_gtkfiledialoggettitle, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, dialog, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_filedialog_gtkfiledialog_gtkfiledialogsetinitialname, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, dialog, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_filedialog_gtkfiledialog_gtkfiledialogopen, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, dialog, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, parent, IS_LONG, 0)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_filedialog_gtkfiledialog_gtkfiledialogsave, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, dialog, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, parent, IS_LONG, 0)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_filedialog_gtkfiledialog_gtkfiledialogselectfolder, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, dialog, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, parent, IS_LONG, 0)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_filedialog_gtkfiledialog_method_entry) {
	PHP_ME(Gtk_GTK_FileDialog_GtkFileDialog, gtkFileDialogNew, arginfo_gtk_gtk_filedialog_gtkfiledialog_gtkfiledialognew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_FileDialog_GtkFileDialog, gtkFileDialogSetTitle, arginfo_gtk_gtk_filedialog_gtkfiledialog_gtkfiledialogsettitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_FileDialog_GtkFileDialog, gtkFileDialogGetTitle, arginfo_gtk_gtk_filedialog_gtkfiledialog_gtkfiledialoggettitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_FileDialog_GtkFileDialog, gtkFileDialogSetInitialName, arginfo_gtk_gtk_filedialog_gtkfiledialog_gtkfiledialogsetinitialname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_FileDialog_GtkFileDialog, gtkFileDialogOpen, arginfo_gtk_gtk_filedialog_gtkfiledialog_gtkfiledialogopen, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_FileDialog_GtkFileDialog, gtkFileDialogSave, arginfo_gtk_gtk_filedialog_gtkfiledialog_gtkfiledialogsave, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_FileDialog_GtkFileDialog, gtkFileDialogSelectFolder, arginfo_gtk_gtk_filedialog_gtkfiledialog_gtkfiledialogselectfolder, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
