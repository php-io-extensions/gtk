
extern zend_class_entry *gtk_gtk_menubutton_gtkmenubutton_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_MenuButton_GtkMenuButton);

PHP_METHOD(Gtk_GTK_MenuButton_GtkMenuButton, gtkMenuButtonNew);
PHP_METHOD(Gtk_GTK_MenuButton_GtkMenuButton, gtkMenuButtonSetLabel);
PHP_METHOD(Gtk_GTK_MenuButton_GtkMenuButton, gtkMenuButtonGetLabel);
PHP_METHOD(Gtk_GTK_MenuButton_GtkMenuButton, gtkMenuButtonSetPopover);
PHP_METHOD(Gtk_GTK_MenuButton_GtkMenuButton, gtkMenuButtonGetPopover);
PHP_METHOD(Gtk_GTK_MenuButton_GtkMenuButton, gtkMenuButtonPopup);
PHP_METHOD(Gtk_GTK_MenuButton_GtkMenuButton, gtkMenuButtonPopdown);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_menubutton_gtkmenubutton_gtkmenubuttonnew, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_menubutton_gtkmenubutton_gtkmenubuttonsetlabel, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, button, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_menubutton_gtkmenubutton_gtkmenubuttongetlabel, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, button, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_menubutton_gtkmenubutton_gtkmenubuttonsetpopover, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, button, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, popover, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_menubutton_gtkmenubutton_gtkmenubuttongetpopover, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, button, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_menubutton_gtkmenubutton_gtkmenubuttonpopup, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, button, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_menubutton_gtkmenubutton_gtkmenubuttonpopdown, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, button, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_menubutton_gtkmenubutton_method_entry) {
	PHP_ME(Gtk_GTK_MenuButton_GtkMenuButton, gtkMenuButtonNew, arginfo_gtk_gtk_menubutton_gtkmenubutton_gtkmenubuttonnew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_MenuButton_GtkMenuButton, gtkMenuButtonSetLabel, arginfo_gtk_gtk_menubutton_gtkmenubutton_gtkmenubuttonsetlabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_MenuButton_GtkMenuButton, gtkMenuButtonGetLabel, arginfo_gtk_gtk_menubutton_gtkmenubutton_gtkmenubuttongetlabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_MenuButton_GtkMenuButton, gtkMenuButtonSetPopover, arginfo_gtk_gtk_menubutton_gtkmenubutton_gtkmenubuttonsetpopover, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_MenuButton_GtkMenuButton, gtkMenuButtonGetPopover, arginfo_gtk_gtk_menubutton_gtkmenubutton_gtkmenubuttongetpopover, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_MenuButton_GtkMenuButton, gtkMenuButtonPopup, arginfo_gtk_gtk_menubutton_gtkmenubutton_gtkmenubuttonpopup, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_MenuButton_GtkMenuButton, gtkMenuButtonPopdown, arginfo_gtk_gtk_menubutton_gtkmenubutton_gtkmenubuttonpopdown, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
