
extern zend_class_entry *gtk_gtk_gtkframe_gtkframe_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkFrame_GtkFrame);

PHP_METHOD(Gtk_Gtk_GtkFrame_GtkFrame, new_);
PHP_METHOD(Gtk_Gtk_GtkFrame_GtkFrame, getChild);
PHP_METHOD(Gtk_Gtk_GtkFrame_GtkFrame, getLabel);
PHP_METHOD(Gtk_Gtk_GtkFrame_GtkFrame, getLabelAlign);
PHP_METHOD(Gtk_Gtk_GtkFrame_GtkFrame, getLabelWidget);
PHP_METHOD(Gtk_Gtk_GtkFrame_GtkFrame, setChild);
PHP_METHOD(Gtk_Gtk_GtkFrame_GtkFrame, setLabel);
PHP_METHOD(Gtk_Gtk_GtkFrame_GtkFrame, setLabelAlign);
PHP_METHOD(Gtk_Gtk_GtkFrame_GtkFrame, setLabelWidget);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkframe_gtkframe_new_, 0, 1, IS_LONG, 0)
	ZEND_ARG_INFO(0, label)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkframe_gtkframe_getchild, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkframe_gtkframe_getlabel, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkframe_gtkframe_getlabelalign, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkframe_gtkframe_getlabelwidget, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkframe_gtkframe_setchild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkframe_gtkframe_setlabel, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, label)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkframe_gtkframe_setlabelalign, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, xalign, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkframe_gtkframe_setlabelwidget, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, labelWidget, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkframe_gtkframe_method_entry) {
	PHP_ME(Gtk_Gtk_GtkFrame_GtkFrame, new_, arginfo_gtk_gtk_gtkframe_gtkframe_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFrame_GtkFrame, getChild, arginfo_gtk_gtk_gtkframe_gtkframe_getchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFrame_GtkFrame, getLabel, arginfo_gtk_gtk_gtkframe_gtkframe_getlabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFrame_GtkFrame, getLabelAlign, arginfo_gtk_gtk_gtkframe_gtkframe_getlabelalign, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFrame_GtkFrame, getLabelWidget, arginfo_gtk_gtk_gtkframe_gtkframe_getlabelwidget, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFrame_GtkFrame, setChild, arginfo_gtk_gtk_gtkframe_gtkframe_setchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFrame_GtkFrame, setLabel, arginfo_gtk_gtk_gtkframe_gtkframe_setlabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFrame_GtkFrame, setLabelAlign, arginfo_gtk_gtk_gtkframe_gtkframe_setlabelalign, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFrame_GtkFrame, setLabelWidget, arginfo_gtk_gtk_gtkframe_gtkframe_setlabelwidget, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
