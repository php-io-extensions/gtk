
extern zend_class_entry *gtk_gtk_gtktextmark_gtktextmark_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkTextMark_GtkTextMark);

PHP_METHOD(Gtk_Gtk_GtkTextMark_GtkTextMark, new_);
PHP_METHOD(Gtk_Gtk_GtkTextMark_GtkTextMark, getBuffer);
PHP_METHOD(Gtk_Gtk_GtkTextMark_GtkTextMark, getDeleted);
PHP_METHOD(Gtk_Gtk_GtkTextMark_GtkTextMark, getLeftGravity);
PHP_METHOD(Gtk_Gtk_GtkTextMark_GtkTextMark, getName);
PHP_METHOD(Gtk_Gtk_GtkTextMark_GtkTextMark, getVisible);
PHP_METHOD(Gtk_Gtk_GtkTextMark_GtkTextMark, setVisible);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextmark_gtktextmark_new_, 0, 2, IS_LONG, 0)
	ZEND_ARG_INFO(0, name)
	ZEND_ARG_TYPE_INFO(0, leftGravity, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextmark_gtktextmark_getbuffer, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextmark_gtktextmark_getdeleted, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextmark_gtktextmark_getleftgravity, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtktextmark_gtktextmark_getname, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextmark_gtktextmark_getvisible, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktextmark_gtktextmark_setvisible, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, setting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtktextmark_gtktextmark_method_entry) {
	PHP_ME(Gtk_Gtk_GtkTextMark_GtkTextMark, new_, arginfo_gtk_gtk_gtktextmark_gtktextmark_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextMark_GtkTextMark, getBuffer, arginfo_gtk_gtk_gtktextmark_gtktextmark_getbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextMark_GtkTextMark, getDeleted, arginfo_gtk_gtk_gtktextmark_gtktextmark_getdeleted, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextMark_GtkTextMark, getLeftGravity, arginfo_gtk_gtk_gtktextmark_gtktextmark_getleftgravity, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextMark_GtkTextMark, getName, arginfo_gtk_gtk_gtktextmark_gtktextmark_getname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextMark_GtkTextMark, getVisible, arginfo_gtk_gtk_gtktextmark_gtktextmark_getvisible, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextMark_GtkTextMark, setVisible, arginfo_gtk_gtk_gtktextmark_gtktextmark_setvisible, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
