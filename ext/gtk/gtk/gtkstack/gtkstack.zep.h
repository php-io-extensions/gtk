
extern zend_class_entry *gtk_gtk_gtkstack_gtkstack_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkStack_GtkStack);

PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, new_);
PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, addChild);
PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, addNamed);
PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, addTitled);
PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, getChildByName);
PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, getHhomogeneous);
PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, getInterpolateSize);
PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, getPage);
PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, getPages);
PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, getTransitionDuration);
PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, getTransitionRunning);
PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, getTransitionType);
PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, getVhomogeneous);
PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, getVisibleChild);
PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, getVisibleChildName);
PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, remove);
PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, setHhomogeneous);
PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, setInterpolateSize);
PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, setTransitionDuration);
PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, setTransitionType);
PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, setVhomogeneous);
PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, setVisibleChild);
PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, setVisibleChildFull);
PHP_METHOD(Gtk_Gtk_GtkStack_GtkStack, setVisibleChildName);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstack_gtkstack_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstack_gtkstack_addchild, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstack_gtkstack_addnamed, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstack_gtkstack_addtitled, 0, 4, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_TYPE_INFO(0, title, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstack_gtkstack_getchildbyname, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstack_gtkstack_gethhomogeneous, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstack_gtkstack_getinterpolatesize, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstack_gtkstack_getpage, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstack_gtkstack_getpages, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstack_gtkstack_gettransitionduration, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstack_gtkstack_gettransitionrunning, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstack_gtkstack_gettransitiontype, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstack_gtkstack_getvhomogeneous, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstack_gtkstack_getvisiblechild, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkstack_gtkstack_getvisiblechildname, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstack_gtkstack_remove, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstack_gtkstack_sethhomogeneous, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, hhomogeneous, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstack_gtkstack_setinterpolatesize, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, interpolateSize, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstack_gtkstack_settransitionduration, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, duration, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstack_gtkstack_settransitiontype, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, transition, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstack_gtkstack_setvhomogeneous, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, vhomogeneous, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstack_gtkstack_setvisiblechild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstack_gtkstack_setvisiblechildfull, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, transition, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstack_gtkstack_setvisiblechildname, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkstack_gtkstack_method_entry) {
	PHP_ME(Gtk_Gtk_GtkStack_GtkStack, new_, arginfo_gtk_gtk_gtkstack_gtkstack_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStack_GtkStack, addChild, arginfo_gtk_gtk_gtkstack_gtkstack_addchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStack_GtkStack, addNamed, arginfo_gtk_gtk_gtkstack_gtkstack_addnamed, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStack_GtkStack, addTitled, arginfo_gtk_gtk_gtkstack_gtkstack_addtitled, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStack_GtkStack, getChildByName, arginfo_gtk_gtk_gtkstack_gtkstack_getchildbyname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStack_GtkStack, getHhomogeneous, arginfo_gtk_gtk_gtkstack_gtkstack_gethhomogeneous, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStack_GtkStack, getInterpolateSize, arginfo_gtk_gtk_gtkstack_gtkstack_getinterpolatesize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStack_GtkStack, getPage, arginfo_gtk_gtk_gtkstack_gtkstack_getpage, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStack_GtkStack, getPages, arginfo_gtk_gtk_gtkstack_gtkstack_getpages, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStack_GtkStack, getTransitionDuration, arginfo_gtk_gtk_gtkstack_gtkstack_gettransitionduration, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStack_GtkStack, getTransitionRunning, arginfo_gtk_gtk_gtkstack_gtkstack_gettransitionrunning, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStack_GtkStack, getTransitionType, arginfo_gtk_gtk_gtkstack_gtkstack_gettransitiontype, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStack_GtkStack, getVhomogeneous, arginfo_gtk_gtk_gtkstack_gtkstack_getvhomogeneous, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStack_GtkStack, getVisibleChild, arginfo_gtk_gtk_gtkstack_gtkstack_getvisiblechild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStack_GtkStack, getVisibleChildName, arginfo_gtk_gtk_gtkstack_gtkstack_getvisiblechildname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStack_GtkStack, remove, arginfo_gtk_gtk_gtkstack_gtkstack_remove, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStack_GtkStack, setHhomogeneous, arginfo_gtk_gtk_gtkstack_gtkstack_sethhomogeneous, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStack_GtkStack, setInterpolateSize, arginfo_gtk_gtk_gtkstack_gtkstack_setinterpolatesize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStack_GtkStack, setTransitionDuration, arginfo_gtk_gtk_gtkstack_gtkstack_settransitionduration, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStack_GtkStack, setTransitionType, arginfo_gtk_gtk_gtkstack_gtkstack_settransitiontype, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStack_GtkStack, setVhomogeneous, arginfo_gtk_gtk_gtkstack_gtkstack_setvhomogeneous, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStack_GtkStack, setVisibleChild, arginfo_gtk_gtk_gtkstack_gtkstack_setvisiblechild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStack_GtkStack, setVisibleChildFull, arginfo_gtk_gtk_gtkstack_gtkstack_setvisiblechildfull, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStack_GtkStack, setVisibleChildName, arginfo_gtk_gtk_gtkstack_gtkstack_setvisiblechildname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
