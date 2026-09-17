
extern zend_class_entry *gtk_gtk_gtkgesture_gtkgesture_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkGesture_GtkGesture);

PHP_METHOD(Gtk_Gtk_GtkGesture_GtkGesture, getBoundingBox);
PHP_METHOD(Gtk_Gtk_GtkGesture_GtkGesture, getBoundingBoxCenter);
PHP_METHOD(Gtk_Gtk_GtkGesture_GtkGesture, getDevice);
PHP_METHOD(Gtk_Gtk_GtkGesture_GtkGesture, getGroup);
PHP_METHOD(Gtk_Gtk_GtkGesture_GtkGesture, group);
PHP_METHOD(Gtk_Gtk_GtkGesture_GtkGesture, isActive);
PHP_METHOD(Gtk_Gtk_GtkGesture_GtkGesture, isGroupedWith);
PHP_METHOD(Gtk_Gtk_GtkGesture_GtkGesture, isRecognized);
PHP_METHOD(Gtk_Gtk_GtkGesture_GtkGesture, setState);
PHP_METHOD(Gtk_Gtk_GtkGesture_GtkGesture, ungroup);

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkgesture_gtkgesture_getboundingbox, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkgesture_gtkgesture_getboundingboxcenter, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgesture_gtkgesture_getdevice, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgesture_gtkgesture_getgroup, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgesture_gtkgesture_group, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, gesture, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgesture_gtkgesture_isactive, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgesture_gtkgesture_isgroupedwith, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, other, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgesture_gtkgesture_isrecognized, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgesture_gtkgesture_setstate, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, state, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkgesture_gtkgesture_ungroup, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkgesture_gtkgesture_method_entry) {
	PHP_ME(Gtk_Gtk_GtkGesture_GtkGesture, getBoundingBox, arginfo_gtk_gtk_gtkgesture_gtkgesture_getboundingbox, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGesture_GtkGesture, getBoundingBoxCenter, arginfo_gtk_gtk_gtkgesture_gtkgesture_getboundingboxcenter, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGesture_GtkGesture, getDevice, arginfo_gtk_gtk_gtkgesture_gtkgesture_getdevice, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGesture_GtkGesture, getGroup, arginfo_gtk_gtk_gtkgesture_gtkgesture_getgroup, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGesture_GtkGesture, group, arginfo_gtk_gtk_gtkgesture_gtkgesture_group, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGesture_GtkGesture, isActive, arginfo_gtk_gtk_gtkgesture_gtkgesture_isactive, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGesture_GtkGesture, isGroupedWith, arginfo_gtk_gtk_gtkgesture_gtkgesture_isgroupedwith, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGesture_GtkGesture, isRecognized, arginfo_gtk_gtk_gtkgesture_gtkgesture_isrecognized, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGesture_GtkGesture, setState, arginfo_gtk_gtk_gtkgesture_gtkgesture_setstate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkGesture_GtkGesture, ungroup, arginfo_gtk_gtk_gtkgesture_gtkgesture_ungroup, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
