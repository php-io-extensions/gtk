
extern zend_class_entry *gtk_gtk_gtkcssprovider_gtkcssprovider_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkCssProvider_GtkCssProvider);

PHP_METHOD(Gtk_Gtk_GtkCssProvider_GtkCssProvider, new_);
PHP_METHOD(Gtk_Gtk_GtkCssProvider_GtkCssProvider, loadFromString);
PHP_METHOD(Gtk_Gtk_GtkCssProvider_GtkCssProvider, loadFromPath);
PHP_METHOD(Gtk_Gtk_GtkCssProvider_GtkCssProvider, toString);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcssprovider_gtkcssprovider_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcssprovider_gtkcssprovider_loadfromstring, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, css, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcssprovider_gtkcssprovider_loadfrompath, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkcssprovider_gtkcssprovider_tostring, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkcssprovider_gtkcssprovider_method_entry) {
	PHP_ME(Gtk_Gtk_GtkCssProvider_GtkCssProvider, new_, arginfo_gtk_gtk_gtkcssprovider_gtkcssprovider_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCssProvider_GtkCssProvider, loadFromString, arginfo_gtk_gtk_gtkcssprovider_gtkcssprovider_loadfromstring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCssProvider_GtkCssProvider, loadFromPath, arginfo_gtk_gtk_gtkcssprovider_gtkcssprovider_loadfrompath, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkCssProvider_GtkCssProvider, toString, arginfo_gtk_gtk_gtkcssprovider_gtkcssprovider_tostring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
