
extern zend_class_entry *gtk_gtk_fontdialog_gtkfontdialog_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_FontDialog_GtkFontDialog);

PHP_METHOD(Gtk_GTK_FontDialog_GtkFontDialog, gtkFontDialogNew);
PHP_METHOD(Gtk_GTK_FontDialog_GtkFontDialog, gtkFontDialogSetTitle);
PHP_METHOD(Gtk_GTK_FontDialog_GtkFontDialog, gtkFontDialogSetModal);
PHP_METHOD(Gtk_GTK_FontDialog_GtkFontDialog, gtkFontDialogChooseFont);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_fontdialog_gtkfontdialog_gtkfontdialognew, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_fontdialog_gtkfontdialog_gtkfontdialogsettitle, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, dialog, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, title, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_fontdialog_gtkfontdialog_gtkfontdialogsetmodal, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, dialog, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, modal, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_fontdialog_gtkfontdialog_gtkfontdialogchoosefont, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, dialog, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, parent, IS_LONG, 0)
	ZEND_ARG_INFO(0, callback)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_fontdialog_gtkfontdialog_method_entry) {
	PHP_ME(Gtk_GTK_FontDialog_GtkFontDialog, gtkFontDialogNew, arginfo_gtk_gtk_fontdialog_gtkfontdialog_gtkfontdialognew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_FontDialog_GtkFontDialog, gtkFontDialogSetTitle, arginfo_gtk_gtk_fontdialog_gtkfontdialog_gtkfontdialogsettitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_FontDialog_GtkFontDialog, gtkFontDialogSetModal, arginfo_gtk_gtk_fontdialog_gtkfontdialog_gtkfontdialogsetmodal, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_FontDialog_GtkFontDialog, gtkFontDialogChooseFont, arginfo_gtk_gtk_fontdialog_gtkfontdialog_gtkfontdialogchoosefont, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
