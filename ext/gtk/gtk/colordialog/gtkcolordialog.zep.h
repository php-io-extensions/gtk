
extern zend_class_entry *gtk_gtk_colordialog_gtkcolordialog_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_ColorDialog_GtkColorDialog);

PHP_METHOD(Gtk_GTK_ColorDialog_GtkColorDialog, gtkColorDialogNew);
PHP_METHOD(Gtk_GTK_ColorDialog_GtkColorDialog, gtkColorDialogSetTitle);
PHP_METHOD(Gtk_GTK_ColorDialog_GtkColorDialog, gtkColorDialogSetModal);
PHP_METHOD(Gtk_GTK_ColorDialog_GtkColorDialog, gtkColorDialogChooseRgba);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_colordialog_gtkcolordialog_gtkcolordialognew, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_colordialog_gtkcolordialog_gtkcolordialogsettitle, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, dialog, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, title, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_colordialog_gtkcolordialog_gtkcolordialogsetmodal, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, dialog, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, modal, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_colordialog_gtkcolordialog_gtkcolordialogchoosergba, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, dialog, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, parent, IS_LONG, 0)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_colordialog_gtkcolordialog_method_entry) {
	PHP_ME(Gtk_GTK_ColorDialog_GtkColorDialog, gtkColorDialogNew, arginfo_gtk_gtk_colordialog_gtkcolordialog_gtkcolordialognew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_ColorDialog_GtkColorDialog, gtkColorDialogSetTitle, arginfo_gtk_gtk_colordialog_gtkcolordialog_gtkcolordialogsettitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_ColorDialog_GtkColorDialog, gtkColorDialogSetModal, arginfo_gtk_gtk_colordialog_gtkcolordialog_gtkcolordialogsetmodal, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_ColorDialog_GtkColorDialog, gtkColorDialogChooseRgba, arginfo_gtk_gtk_colordialog_gtkcolordialog_gtkcolordialogchoosergba, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
