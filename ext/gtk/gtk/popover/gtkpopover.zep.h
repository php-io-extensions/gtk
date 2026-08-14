
extern zend_class_entry *gtk_gtk_popover_gtkpopover_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_Popover_GtkPopover);

PHP_METHOD(Gtk_GTK_Popover_GtkPopover, gtkPopoverNew);
PHP_METHOD(Gtk_GTK_Popover_GtkPopover, gtkPopoverSetChild);
PHP_METHOD(Gtk_GTK_Popover_GtkPopover, gtkPopoverGetChild);
PHP_METHOD(Gtk_GTK_Popover_GtkPopover, gtkPopoverPopup);
PHP_METHOD(Gtk_GTK_Popover_GtkPopover, gtkPopoverPopdown);
PHP_METHOD(Gtk_GTK_Popover_GtkPopover, gtkPopoverSetAutohide);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_popover_gtkpopover_gtkpopovernew, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_popover_gtkpopover_gtkpopoversetchild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, popover, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_popover_gtkpopover_gtkpopovergetchild, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, popover, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_popover_gtkpopover_gtkpopoverpopup, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, popover, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_popover_gtkpopover_gtkpopoverpopdown, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, popover, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_popover_gtkpopover_gtkpopoversetautohide, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, popover, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, autohide, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_popover_gtkpopover_method_entry) {
	PHP_ME(Gtk_GTK_Popover_GtkPopover, gtkPopoverNew, arginfo_gtk_gtk_popover_gtkpopover_gtkpopovernew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Popover_GtkPopover, gtkPopoverSetChild, arginfo_gtk_gtk_popover_gtkpopover_gtkpopoversetchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Popover_GtkPopover, gtkPopoverGetChild, arginfo_gtk_gtk_popover_gtkpopover_gtkpopovergetchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Popover_GtkPopover, gtkPopoverPopup, arginfo_gtk_gtk_popover_gtkpopover_gtkpopoverpopup, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Popover_GtkPopover, gtkPopoverPopdown, arginfo_gtk_gtk_popover_gtkpopover_gtkpopoverpopdown, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Popover_GtkPopover, gtkPopoverSetAutohide, arginfo_gtk_gtk_popover_gtkpopover_gtkpopoversetautohide, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
