
extern zend_class_entry *gtk_gtk_gtkpopovermenubar_gtkpopovermenubar_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkPopoverMenuBar_GtkPopoverMenuBar);

PHP_METHOD(Gtk_Gtk_GtkPopoverMenuBar_GtkPopoverMenuBar, newFromModel);
PHP_METHOD(Gtk_Gtk_GtkPopoverMenuBar_GtkPopoverMenuBar, addChild);
PHP_METHOD(Gtk_Gtk_GtkPopoverMenuBar_GtkPopoverMenuBar, getMenuModel);
PHP_METHOD(Gtk_Gtk_GtkPopoverMenuBar_GtkPopoverMenuBar, removeChild);
PHP_METHOD(Gtk_Gtk_GtkPopoverMenuBar_GtkPopoverMenuBar, setMenuModel);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopovermenubar_gtkpopovermenubar_newfrommodel, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, model, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopovermenubar_gtkpopovermenubar_addchild, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopovermenubar_gtkpopovermenubar_getmenumodel, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopovermenubar_gtkpopovermenubar_removechild, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopovermenubar_gtkpopovermenubar_setmenumodel, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, model, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkpopovermenubar_gtkpopovermenubar_method_entry) {
	PHP_ME(Gtk_Gtk_GtkPopoverMenuBar_GtkPopoverMenuBar, newFromModel, arginfo_gtk_gtk_gtkpopovermenubar_gtkpopovermenubar_newfrommodel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPopoverMenuBar_GtkPopoverMenuBar, addChild, arginfo_gtk_gtk_gtkpopovermenubar_gtkpopovermenubar_addchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPopoverMenuBar_GtkPopoverMenuBar, getMenuModel, arginfo_gtk_gtk_gtkpopovermenubar_gtkpopovermenubar_getmenumodel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPopoverMenuBar_GtkPopoverMenuBar, removeChild, arginfo_gtk_gtk_gtkpopovermenubar_gtkpopovermenubar_removechild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPopoverMenuBar_GtkPopoverMenuBar, setMenuModel, arginfo_gtk_gtk_gtkpopovermenubar_gtkpopovermenubar_setmenumodel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
