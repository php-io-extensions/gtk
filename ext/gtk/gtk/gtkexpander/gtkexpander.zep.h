
extern zend_class_entry *gtk_gtk_gtkexpander_gtkexpander_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkExpander_GtkExpander);

PHP_METHOD(Gtk_Gtk_GtkExpander_GtkExpander, new_);
PHP_METHOD(Gtk_Gtk_GtkExpander_GtkExpander, newWithMnemonic);
PHP_METHOD(Gtk_Gtk_GtkExpander_GtkExpander, getChild);
PHP_METHOD(Gtk_Gtk_GtkExpander_GtkExpander, getExpanded);
PHP_METHOD(Gtk_Gtk_GtkExpander_GtkExpander, getLabel);
PHP_METHOD(Gtk_Gtk_GtkExpander_GtkExpander, getLabelWidget);
PHP_METHOD(Gtk_Gtk_GtkExpander_GtkExpander, getResizeToplevel);
PHP_METHOD(Gtk_Gtk_GtkExpander_GtkExpander, getUseMarkup);
PHP_METHOD(Gtk_Gtk_GtkExpander_GtkExpander, getUseUnderline);
PHP_METHOD(Gtk_Gtk_GtkExpander_GtkExpander, setChild);
PHP_METHOD(Gtk_Gtk_GtkExpander_GtkExpander, setExpanded);
PHP_METHOD(Gtk_Gtk_GtkExpander_GtkExpander, setLabel);
PHP_METHOD(Gtk_Gtk_GtkExpander_GtkExpander, setLabelWidget);
PHP_METHOD(Gtk_Gtk_GtkExpander_GtkExpander, setResizeToplevel);
PHP_METHOD(Gtk_Gtk_GtkExpander_GtkExpander, setUseMarkup);
PHP_METHOD(Gtk_Gtk_GtkExpander_GtkExpander, setUseUnderline);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkexpander_gtkexpander_new_, 0, 1, IS_LONG, 0)
	ZEND_ARG_INFO(0, label)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkexpander_gtkexpander_newwithmnemonic, 0, 1, IS_LONG, 0)
	ZEND_ARG_INFO(0, label)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkexpander_gtkexpander_getchild, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkexpander_gtkexpander_getexpanded, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkexpander_gtkexpander_getlabel, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkexpander_gtkexpander_getlabelwidget, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkexpander_gtkexpander_getresizetoplevel, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkexpander_gtkexpander_getusemarkup, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkexpander_gtkexpander_getuseunderline, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkexpander_gtkexpander_setchild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkexpander_gtkexpander_setexpanded, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, expanded, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkexpander_gtkexpander_setlabel, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, label)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkexpander_gtkexpander_setlabelwidget, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, labelWidget, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkexpander_gtkexpander_setresizetoplevel, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, resizeToplevel, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkexpander_gtkexpander_setusemarkup, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, useMarkup, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkexpander_gtkexpander_setuseunderline, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, useUnderline, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkexpander_gtkexpander_method_entry) {
	PHP_ME(Gtk_Gtk_GtkExpander_GtkExpander, new_, arginfo_gtk_gtk_gtkexpander_gtkexpander_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkExpander_GtkExpander, newWithMnemonic, arginfo_gtk_gtk_gtkexpander_gtkexpander_newwithmnemonic, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkExpander_GtkExpander, getChild, arginfo_gtk_gtk_gtkexpander_gtkexpander_getchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkExpander_GtkExpander, getExpanded, arginfo_gtk_gtk_gtkexpander_gtkexpander_getexpanded, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkExpander_GtkExpander, getLabel, arginfo_gtk_gtk_gtkexpander_gtkexpander_getlabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkExpander_GtkExpander, getLabelWidget, arginfo_gtk_gtk_gtkexpander_gtkexpander_getlabelwidget, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkExpander_GtkExpander, getResizeToplevel, arginfo_gtk_gtk_gtkexpander_gtkexpander_getresizetoplevel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkExpander_GtkExpander, getUseMarkup, arginfo_gtk_gtk_gtkexpander_gtkexpander_getusemarkup, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkExpander_GtkExpander, getUseUnderline, arginfo_gtk_gtk_gtkexpander_gtkexpander_getuseunderline, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkExpander_GtkExpander, setChild, arginfo_gtk_gtk_gtkexpander_gtkexpander_setchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkExpander_GtkExpander, setExpanded, arginfo_gtk_gtk_gtkexpander_gtkexpander_setexpanded, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkExpander_GtkExpander, setLabel, arginfo_gtk_gtk_gtkexpander_gtkexpander_setlabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkExpander_GtkExpander, setLabelWidget, arginfo_gtk_gtk_gtkexpander_gtkexpander_setlabelwidget, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkExpander_GtkExpander, setResizeToplevel, arginfo_gtk_gtk_gtkexpander_gtkexpander_setresizetoplevel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkExpander_GtkExpander, setUseMarkup, arginfo_gtk_gtk_gtkexpander_gtkexpander_setusemarkup, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkExpander_GtkExpander, setUseUnderline, arginfo_gtk_gtk_gtkexpander_gtkexpander_setuseunderline, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
