
extern zend_class_entry *gtk_gtk_gtkstackpage_gtkstackpage_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkStackPage_GtkStackPage);

PHP_METHOD(Gtk_Gtk_GtkStackPage_GtkStackPage, getChild);
PHP_METHOD(Gtk_Gtk_GtkStackPage_GtkStackPage, getIconName);
PHP_METHOD(Gtk_Gtk_GtkStackPage_GtkStackPage, getName);
PHP_METHOD(Gtk_Gtk_GtkStackPage_GtkStackPage, getNeedsAttention);
PHP_METHOD(Gtk_Gtk_GtkStackPage_GtkStackPage, getTitle);
PHP_METHOD(Gtk_Gtk_GtkStackPage_GtkStackPage, getUseUnderline);
PHP_METHOD(Gtk_Gtk_GtkStackPage_GtkStackPage, getVisible);
PHP_METHOD(Gtk_Gtk_GtkStackPage_GtkStackPage, setIconName);
PHP_METHOD(Gtk_Gtk_GtkStackPage_GtkStackPage, setName);
PHP_METHOD(Gtk_Gtk_GtkStackPage_GtkStackPage, setNeedsAttention);
PHP_METHOD(Gtk_Gtk_GtkStackPage_GtkStackPage, setTitle);
PHP_METHOD(Gtk_Gtk_GtkStackPage_GtkStackPage, setUseUnderline);
PHP_METHOD(Gtk_Gtk_GtkStackPage_GtkStackPage, setVisible);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstackpage_gtkstackpage_getchild, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkstackpage_gtkstackpage_geticonname, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkstackpage_gtkstackpage_getname, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstackpage_gtkstackpage_getneedsattention, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkstackpage_gtkstackpage_gettitle, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstackpage_gtkstackpage_getuseunderline, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstackpage_gtkstackpage_getvisible, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstackpage_gtkstackpage_seticonname, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, setting, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstackpage_gtkstackpage_setname, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, setting, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstackpage_gtkstackpage_setneedsattention, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, setting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstackpage_gtkstackpage_settitle, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, setting, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstackpage_gtkstackpage_setuseunderline, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, setting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkstackpage_gtkstackpage_setvisible, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, visible, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkstackpage_gtkstackpage_method_entry) {
	PHP_ME(Gtk_Gtk_GtkStackPage_GtkStackPage, getChild, arginfo_gtk_gtk_gtkstackpage_gtkstackpage_getchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStackPage_GtkStackPage, getIconName, arginfo_gtk_gtk_gtkstackpage_gtkstackpage_geticonname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStackPage_GtkStackPage, getName, arginfo_gtk_gtk_gtkstackpage_gtkstackpage_getname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStackPage_GtkStackPage, getNeedsAttention, arginfo_gtk_gtk_gtkstackpage_gtkstackpage_getneedsattention, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStackPage_GtkStackPage, getTitle, arginfo_gtk_gtk_gtkstackpage_gtkstackpage_gettitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStackPage_GtkStackPage, getUseUnderline, arginfo_gtk_gtk_gtkstackpage_gtkstackpage_getuseunderline, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStackPage_GtkStackPage, getVisible, arginfo_gtk_gtk_gtkstackpage_gtkstackpage_getvisible, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStackPage_GtkStackPage, setIconName, arginfo_gtk_gtk_gtkstackpage_gtkstackpage_seticonname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStackPage_GtkStackPage, setName, arginfo_gtk_gtk_gtkstackpage_gtkstackpage_setname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStackPage_GtkStackPage, setNeedsAttention, arginfo_gtk_gtk_gtkstackpage_gtkstackpage_setneedsattention, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStackPage_GtkStackPage, setTitle, arginfo_gtk_gtk_gtkstackpage_gtkstackpage_settitle, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStackPage_GtkStackPage, setUseUnderline, arginfo_gtk_gtk_gtkstackpage_gtkstackpage_setuseunderline, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkStackPage_GtkStackPage, setVisible, arginfo_gtk_gtk_gtkstackpage_gtkstackpage_setvisible, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
