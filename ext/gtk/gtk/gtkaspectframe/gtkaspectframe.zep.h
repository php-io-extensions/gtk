
extern zend_class_entry *gtk_gtk_gtkaspectframe_gtkaspectframe_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame);

PHP_METHOD(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame, new_);
PHP_METHOD(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame, getChild);
PHP_METHOD(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame, getObeyChild);
PHP_METHOD(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame, getRatio);
PHP_METHOD(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame, getXalign);
PHP_METHOD(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame, getYalign);
PHP_METHOD(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame, setChild);
PHP_METHOD(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame, setObeyChild);
PHP_METHOD(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame, setRatio);
PHP_METHOD(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame, setXalign);
PHP_METHOD(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame, setYalign);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaspectframe_gtkaspectframe_new_, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, xalign, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, yalign, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, ratio, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, obeyChild, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaspectframe_gtkaspectframe_getchild, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaspectframe_gtkaspectframe_getobeychild, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaspectframe_gtkaspectframe_getratio, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaspectframe_gtkaspectframe_getxalign, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaspectframe_gtkaspectframe_getyalign, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaspectframe_gtkaspectframe_setchild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaspectframe_gtkaspectframe_setobeychild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, obeyChild, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaspectframe_gtkaspectframe_setratio, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ratio, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaspectframe_gtkaspectframe_setxalign, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, xalign, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaspectframe_gtkaspectframe_setyalign, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, yalign, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkaspectframe_gtkaspectframe_method_entry) {
	PHP_ME(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame, new_, arginfo_gtk_gtk_gtkaspectframe_gtkaspectframe_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame, getChild, arginfo_gtk_gtk_gtkaspectframe_gtkaspectframe_getchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame, getObeyChild, arginfo_gtk_gtk_gtkaspectframe_gtkaspectframe_getobeychild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame, getRatio, arginfo_gtk_gtk_gtkaspectframe_gtkaspectframe_getratio, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame, getXalign, arginfo_gtk_gtk_gtkaspectframe_gtkaspectframe_getxalign, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame, getYalign, arginfo_gtk_gtk_gtkaspectframe_gtkaspectframe_getyalign, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame, setChild, arginfo_gtk_gtk_gtkaspectframe_gtkaspectframe_setchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame, setObeyChild, arginfo_gtk_gtk_gtkaspectframe_gtkaspectframe_setobeychild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame, setRatio, arginfo_gtk_gtk_gtkaspectframe_gtkaspectframe_setratio, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame, setXalign, arginfo_gtk_gtk_gtkaspectframe_gtkaspectframe_setxalign, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame, setYalign, arginfo_gtk_gtk_gtkaspectframe_gtkaspectframe_setyalign, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
