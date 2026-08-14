
extern zend_class_entry *gtk_gtk_alertdialog_gtkalertdialog_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_AlertDialog_GtkAlertDialog);

PHP_METHOD(Gtk_GTK_AlertDialog_GtkAlertDialog, gtkAlertDialogNew);
PHP_METHOD(Gtk_GTK_AlertDialog_GtkAlertDialog, gtkAlertDialogSetDetail);
PHP_METHOD(Gtk_GTK_AlertDialog_GtkAlertDialog, gtkAlertDialogSetButtons);
PHP_METHOD(Gtk_GTK_AlertDialog_GtkAlertDialog, gtkAlertDialogSetModal);
PHP_METHOD(Gtk_GTK_AlertDialog_GtkAlertDialog, gtkAlertDialogShow);
PHP_METHOD(Gtk_GTK_AlertDialog_GtkAlertDialog, gtkAlertDialogChoose);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_alertdialog_gtkalertdialog_gtkalertdialognew, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_alertdialog_gtkalertdialog_gtkalertdialogsetdetail, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, dialog, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, detail, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_alertdialog_gtkalertdialog_gtkalertdialogsetbuttons, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, dialog, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, labels, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_alertdialog_gtkalertdialog_gtkalertdialogsetmodal, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, dialog, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, modal, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_alertdialog_gtkalertdialog_gtkalertdialogshow, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, dialog, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, parent, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_alertdialog_gtkalertdialog_gtkalertdialogchoose, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, dialog, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, parent, IS_LONG, 0)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_alertdialog_gtkalertdialog_method_entry) {
	PHP_ME(Gtk_GTK_AlertDialog_GtkAlertDialog, gtkAlertDialogNew, arginfo_gtk_gtk_alertdialog_gtkalertdialog_gtkalertdialognew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_AlertDialog_GtkAlertDialog, gtkAlertDialogSetDetail, arginfo_gtk_gtk_alertdialog_gtkalertdialog_gtkalertdialogsetdetail, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_AlertDialog_GtkAlertDialog, gtkAlertDialogSetButtons, arginfo_gtk_gtk_alertdialog_gtkalertdialog_gtkalertdialogsetbuttons, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_AlertDialog_GtkAlertDialog, gtkAlertDialogSetModal, arginfo_gtk_gtk_alertdialog_gtkalertdialog_gtkalertdialogsetmodal, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_AlertDialog_GtkAlertDialog, gtkAlertDialogShow, arginfo_gtk_gtk_alertdialog_gtkalertdialog_gtkalertdialogshow, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_AlertDialog_GtkAlertDialog, gtkAlertDialogChoose, arginfo_gtk_gtk_alertdialog_gtkalertdialog_gtkalertdialogchoose, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
