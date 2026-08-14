
extern zend_class_entry *gtk_gtk_label_gtklabel_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_Label_GtkLabel);

PHP_METHOD(Gtk_GTK_Label_GtkLabel, gtkLabelNew);
PHP_METHOD(Gtk_GTK_Label_GtkLabel, gtkLabelSetText);
PHP_METHOD(Gtk_GTK_Label_GtkLabel, gtkLabelGetText);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_label_gtklabel_gtklabelnew, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_label_gtklabel_gtklabelsettext, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, label, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_label_gtklabel_gtklabelgettext, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, label, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_label_gtklabel_method_entry) {
	PHP_ME(Gtk_GTK_Label_GtkLabel, gtkLabelNew, arginfo_gtk_gtk_label_gtklabel_gtklabelnew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Label_GtkLabel, gtkLabelSetText, arginfo_gtk_gtk_label_gtklabel_gtklabelsettext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Label_GtkLabel, gtkLabelGetText, arginfo_gtk_gtk_label_gtklabel_gtklabelgettext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
