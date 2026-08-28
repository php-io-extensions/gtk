
extern zend_class_entry *gtk_gtk_gtktexttag_gtktexttag_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkTextTag_GtkTextTag);

PHP_METHOD(Gtk_Gtk_GtkTextTag_GtkTextTag, new_);
PHP_METHOD(Gtk_Gtk_GtkTextTag_GtkTextTag, changed);
PHP_METHOD(Gtk_Gtk_GtkTextTag_GtkTextTag, getPriority);
PHP_METHOD(Gtk_Gtk_GtkTextTag_GtkTextTag, setPriority);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktexttag_gtktexttag_new_, 0, 1, IS_LONG, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktexttag_gtktexttag_changed, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, sizeChanged, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktexttag_gtktexttag_getpriority, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtktexttag_gtktexttag_setpriority, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, priority, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtktexttag_gtktexttag_method_entry) {
	PHP_ME(Gtk_Gtk_GtkTextTag_GtkTextTag, new_, arginfo_gtk_gtk_gtktexttag_gtktexttag_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextTag_GtkTextTag, changed, arginfo_gtk_gtk_gtktexttag_gtktexttag_changed, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextTag_GtkTextTag, getPriority, arginfo_gtk_gtk_gtktexttag_gtktexttag_getpriority, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkTextTag_GtkTextTag, setPriority, arginfo_gtk_gtk_gtktexttag_gtktexttag_setpriority, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
