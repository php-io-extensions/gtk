
extern zend_class_entry *gtk_gtk_gtkpopover_gtkpopover_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkPopover_GtkPopover);

PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, new_);
PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, getAutohide);
PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, getCascadePopdown);
PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, getChild);
PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, getHasArrow);
PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, getMnemonicsVisible);
PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, getOffset);
PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, getPointingTo);
PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, getPosition);
PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, popdown);
PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, popup);
PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, present);
PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, setAutohide);
PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, setCascadePopdown);
PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, setChild);
PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, setDefaultWidget);
PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, setHasArrow);
PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, setMnemonicsVisible);
PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, setOffset);
PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, setPointingTo);
PHP_METHOD(Gtk_Gtk_GtkPopover_GtkPopover, setPosition);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopover_gtkpopover_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopover_gtkpopover_getautohide, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopover_gtkpopover_getcascadepopdown, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopover_gtkpopover_getchild, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopover_gtkpopover_gethasarrow, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopover_gtkpopover_getmnemonicsvisible, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopover_gtkpopover_getoffset, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopover_gtkpopover_getpointingto, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopover_gtkpopover_getposition, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopover_gtkpopover_popdown, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopover_gtkpopover_popup, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopover_gtkpopover_present, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopover_gtkpopover_setautohide, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, autohide, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopover_gtkpopover_setcascadepopdown, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, cascadePopdown, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopover_gtkpopover_setchild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopover_gtkpopover_setdefaultwidget, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, widget, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopover_gtkpopover_sethasarrow, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, hasArrow, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopover_gtkpopover_setmnemonicsvisible, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, mnemonicsVisible, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopover_gtkpopover_setoffset, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, xOffset, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, yOffset, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopover_gtkpopover_setpointingto, 0, 5, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpopover_gtkpopover_setposition, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkpopover_gtkpopover_method_entry) {
	PHP_ME(Gtk_Gtk_GtkPopover_GtkPopover, new_, arginfo_gtk_gtk_gtkpopover_gtkpopover_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPopover_GtkPopover, getAutohide, arginfo_gtk_gtk_gtkpopover_gtkpopover_getautohide, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPopover_GtkPopover, getCascadePopdown, arginfo_gtk_gtk_gtkpopover_gtkpopover_getcascadepopdown, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPopover_GtkPopover, getChild, arginfo_gtk_gtk_gtkpopover_gtkpopover_getchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPopover_GtkPopover, getHasArrow, arginfo_gtk_gtk_gtkpopover_gtkpopover_gethasarrow, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPopover_GtkPopover, getMnemonicsVisible, arginfo_gtk_gtk_gtkpopover_gtkpopover_getmnemonicsvisible, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPopover_GtkPopover, getOffset, arginfo_gtk_gtk_gtkpopover_gtkpopover_getoffset, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPopover_GtkPopover, getPointingTo, arginfo_gtk_gtk_gtkpopover_gtkpopover_getpointingto, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPopover_GtkPopover, getPosition, arginfo_gtk_gtk_gtkpopover_gtkpopover_getposition, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPopover_GtkPopover, popdown, arginfo_gtk_gtk_gtkpopover_gtkpopover_popdown, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPopover_GtkPopover, popup, arginfo_gtk_gtk_gtkpopover_gtkpopover_popup, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPopover_GtkPopover, present, arginfo_gtk_gtk_gtkpopover_gtkpopover_present, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPopover_GtkPopover, setAutohide, arginfo_gtk_gtk_gtkpopover_gtkpopover_setautohide, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPopover_GtkPopover, setCascadePopdown, arginfo_gtk_gtk_gtkpopover_gtkpopover_setcascadepopdown, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPopover_GtkPopover, setChild, arginfo_gtk_gtk_gtkpopover_gtkpopover_setchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPopover_GtkPopover, setDefaultWidget, arginfo_gtk_gtk_gtkpopover_gtkpopover_setdefaultwidget, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPopover_GtkPopover, setHasArrow, arginfo_gtk_gtk_gtkpopover_gtkpopover_sethasarrow, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPopover_GtkPopover, setMnemonicsVisible, arginfo_gtk_gtk_gtkpopover_gtkpopover_setmnemonicsvisible, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPopover_GtkPopover, setOffset, arginfo_gtk_gtk_gtkpopover_gtkpopover_setoffset, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPopover_GtkPopover, setPointingTo, arginfo_gtk_gtk_gtkpopover_gtkpopover_setpointingto, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPopover_GtkPopover, setPosition, arginfo_gtk_gtk_gtkpopover_gtkpopover_setposition, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
