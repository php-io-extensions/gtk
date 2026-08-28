
extern zend_class_entry *gtk_gtk_gtkpaned_gtkpaned_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkPaned_GtkPaned);

PHP_METHOD(Gtk_Gtk_GtkPaned_GtkPaned, new_);
PHP_METHOD(Gtk_Gtk_GtkPaned_GtkPaned, getEndChild);
PHP_METHOD(Gtk_Gtk_GtkPaned_GtkPaned, getPosition);
PHP_METHOD(Gtk_Gtk_GtkPaned_GtkPaned, getResizeEndChild);
PHP_METHOD(Gtk_Gtk_GtkPaned_GtkPaned, getResizeStartChild);
PHP_METHOD(Gtk_Gtk_GtkPaned_GtkPaned, getShrinkEndChild);
PHP_METHOD(Gtk_Gtk_GtkPaned_GtkPaned, getShrinkStartChild);
PHP_METHOD(Gtk_Gtk_GtkPaned_GtkPaned, getStartChild);
PHP_METHOD(Gtk_Gtk_GtkPaned_GtkPaned, getWideHandle);
PHP_METHOD(Gtk_Gtk_GtkPaned_GtkPaned, setEndChild);
PHP_METHOD(Gtk_Gtk_GtkPaned_GtkPaned, setPosition);
PHP_METHOD(Gtk_Gtk_GtkPaned_GtkPaned, setResizeEndChild);
PHP_METHOD(Gtk_Gtk_GtkPaned_GtkPaned, setResizeStartChild);
PHP_METHOD(Gtk_Gtk_GtkPaned_GtkPaned, setShrinkEndChild);
PHP_METHOD(Gtk_Gtk_GtkPaned_GtkPaned, setShrinkStartChild);
PHP_METHOD(Gtk_Gtk_GtkPaned_GtkPaned, setStartChild);
PHP_METHOD(Gtk_Gtk_GtkPaned_GtkPaned, setWideHandle);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpaned_gtkpaned_new_, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, orientation, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpaned_gtkpaned_getendchild, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpaned_gtkpaned_getposition, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpaned_gtkpaned_getresizeendchild, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpaned_gtkpaned_getresizestartchild, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpaned_gtkpaned_getshrinkendchild, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpaned_gtkpaned_getshrinkstartchild, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpaned_gtkpaned_getstartchild, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpaned_gtkpaned_getwidehandle, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpaned_gtkpaned_setendchild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpaned_gtkpaned_setposition, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpaned_gtkpaned_setresizeendchild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, resize, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpaned_gtkpaned_setresizestartchild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, resize, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpaned_gtkpaned_setshrinkendchild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, resize, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpaned_gtkpaned_setshrinkstartchild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, resize, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpaned_gtkpaned_setstartchild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpaned_gtkpaned_setwidehandle, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, wide, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkpaned_gtkpaned_method_entry) {
	PHP_ME(Gtk_Gtk_GtkPaned_GtkPaned, new_, arginfo_gtk_gtk_gtkpaned_gtkpaned_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPaned_GtkPaned, getEndChild, arginfo_gtk_gtk_gtkpaned_gtkpaned_getendchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPaned_GtkPaned, getPosition, arginfo_gtk_gtk_gtkpaned_gtkpaned_getposition, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPaned_GtkPaned, getResizeEndChild, arginfo_gtk_gtk_gtkpaned_gtkpaned_getresizeendchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPaned_GtkPaned, getResizeStartChild, arginfo_gtk_gtk_gtkpaned_gtkpaned_getresizestartchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPaned_GtkPaned, getShrinkEndChild, arginfo_gtk_gtk_gtkpaned_gtkpaned_getshrinkendchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPaned_GtkPaned, getShrinkStartChild, arginfo_gtk_gtk_gtkpaned_gtkpaned_getshrinkstartchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPaned_GtkPaned, getStartChild, arginfo_gtk_gtk_gtkpaned_gtkpaned_getstartchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPaned_GtkPaned, getWideHandle, arginfo_gtk_gtk_gtkpaned_gtkpaned_getwidehandle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPaned_GtkPaned, setEndChild, arginfo_gtk_gtk_gtkpaned_gtkpaned_setendchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPaned_GtkPaned, setPosition, arginfo_gtk_gtk_gtkpaned_gtkpaned_setposition, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPaned_GtkPaned, setResizeEndChild, arginfo_gtk_gtk_gtkpaned_gtkpaned_setresizeendchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPaned_GtkPaned, setResizeStartChild, arginfo_gtk_gtk_gtkpaned_gtkpaned_setresizestartchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPaned_GtkPaned, setShrinkEndChild, arginfo_gtk_gtk_gtkpaned_gtkpaned_setshrinkendchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPaned_GtkPaned, setShrinkStartChild, arginfo_gtk_gtk_gtkpaned_gtkpaned_setshrinkstartchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPaned_GtkPaned, setStartChild, arginfo_gtk_gtk_gtkpaned_gtkpaned_setstartchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPaned_GtkPaned, setWideHandle, arginfo_gtk_gtk_gtkpaned_gtkpaned_setwidehandle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
