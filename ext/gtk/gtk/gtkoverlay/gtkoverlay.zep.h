
extern zend_class_entry *gtk_gtk_gtkoverlay_gtkoverlay_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkOverlay_GtkOverlay);

PHP_METHOD(Gtk_Gtk_GtkOverlay_GtkOverlay, new_);
PHP_METHOD(Gtk_Gtk_GtkOverlay_GtkOverlay, addOverlay);
PHP_METHOD(Gtk_Gtk_GtkOverlay_GtkOverlay, getChild);
PHP_METHOD(Gtk_Gtk_GtkOverlay_GtkOverlay, getClipOverlay);
PHP_METHOD(Gtk_Gtk_GtkOverlay_GtkOverlay, getMeasureOverlay);
PHP_METHOD(Gtk_Gtk_GtkOverlay_GtkOverlay, removeOverlay);
PHP_METHOD(Gtk_Gtk_GtkOverlay_GtkOverlay, setChild);
PHP_METHOD(Gtk_Gtk_GtkOverlay_GtkOverlay, setClipOverlay);
PHP_METHOD(Gtk_Gtk_GtkOverlay_GtkOverlay, setMeasureOverlay);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkoverlay_gtkoverlay_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkoverlay_gtkoverlay_addoverlay, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, widget, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkoverlay_gtkoverlay_getchild, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkoverlay_gtkoverlay_getclipoverlay, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, widget, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkoverlay_gtkoverlay_getmeasureoverlay, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, widget, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkoverlay_gtkoverlay_removeoverlay, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, widget, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkoverlay_gtkoverlay_setchild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkoverlay_gtkoverlay_setclipoverlay, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, widget, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, clipOverlay, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkoverlay_gtkoverlay_setmeasureoverlay, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, widget, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, measure, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkoverlay_gtkoverlay_method_entry) {
	PHP_ME(Gtk_Gtk_GtkOverlay_GtkOverlay, new_, arginfo_gtk_gtk_gtkoverlay_gtkoverlay_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkOverlay_GtkOverlay, addOverlay, arginfo_gtk_gtk_gtkoverlay_gtkoverlay_addoverlay, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkOverlay_GtkOverlay, getChild, arginfo_gtk_gtk_gtkoverlay_gtkoverlay_getchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkOverlay_GtkOverlay, getClipOverlay, arginfo_gtk_gtk_gtkoverlay_gtkoverlay_getclipoverlay, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkOverlay_GtkOverlay, getMeasureOverlay, arginfo_gtk_gtk_gtkoverlay_gtkoverlay_getmeasureoverlay, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkOverlay_GtkOverlay, removeOverlay, arginfo_gtk_gtk_gtkoverlay_gtkoverlay_removeoverlay, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkOverlay_GtkOverlay, setChild, arginfo_gtk_gtk_gtkoverlay_gtkoverlay_setchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkOverlay_GtkOverlay, setClipOverlay, arginfo_gtk_gtk_gtkoverlay_gtkoverlay_setclipoverlay, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkOverlay_GtkOverlay, setMeasureOverlay, arginfo_gtk_gtk_gtkoverlay_gtkoverlay_setmeasureoverlay, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
