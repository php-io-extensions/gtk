
extern zend_class_entry *gtk_gtk_gtkmediafile_gtkmediafile_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkMediaFile_GtkMediaFile);

PHP_METHOD(Gtk_Gtk_GtkMediaFile_GtkMediaFile, new_);
PHP_METHOD(Gtk_Gtk_GtkMediaFile_GtkMediaFile, newForFile);
PHP_METHOD(Gtk_Gtk_GtkMediaFile_GtkMediaFile, newForFilename);
PHP_METHOD(Gtk_Gtk_GtkMediaFile_GtkMediaFile, newForInputStream);
PHP_METHOD(Gtk_Gtk_GtkMediaFile_GtkMediaFile, newForResource);
PHP_METHOD(Gtk_Gtk_GtkMediaFile_GtkMediaFile, clear);
PHP_METHOD(Gtk_Gtk_GtkMediaFile_GtkMediaFile, getFile);
PHP_METHOD(Gtk_Gtk_GtkMediaFile_GtkMediaFile, getInputStream);
PHP_METHOD(Gtk_Gtk_GtkMediaFile_GtkMediaFile, setFile);
PHP_METHOD(Gtk_Gtk_GtkMediaFile_GtkMediaFile, setFilename);
PHP_METHOD(Gtk_Gtk_GtkMediaFile_GtkMediaFile, setInputStream);
PHP_METHOD(Gtk_Gtk_GtkMediaFile_GtkMediaFile, setResource);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediafile_gtkmediafile_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediafile_gtkmediafile_newforfile, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, file, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediafile_gtkmediafile_newforfilename, 0, 1, IS_LONG, 0)
	ZEND_ARG_INFO(0, filename)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediafile_gtkmediafile_newforinputstream, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, stream, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediafile_gtkmediafile_newforresource, 0, 1, IS_LONG, 0)
	ZEND_ARG_INFO(0, resourcePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediafile_gtkmediafile_clear, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediafile_gtkmediafile_getfile, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediafile_gtkmediafile_getinputstream, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediafile_gtkmediafile_setfile, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, file, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediafile_gtkmediafile_setfilename, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, filename)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediafile_gtkmediafile_setinputstream, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, stream, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediafile_gtkmediafile_setresource, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, resourcePath)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkmediafile_gtkmediafile_method_entry) {
	PHP_ME(Gtk_Gtk_GtkMediaFile_GtkMediaFile, new_, arginfo_gtk_gtk_gtkmediafile_gtkmediafile_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaFile_GtkMediaFile, newForFile, arginfo_gtk_gtk_gtkmediafile_gtkmediafile_newforfile, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaFile_GtkMediaFile, newForFilename, arginfo_gtk_gtk_gtkmediafile_gtkmediafile_newforfilename, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaFile_GtkMediaFile, newForInputStream, arginfo_gtk_gtk_gtkmediafile_gtkmediafile_newforinputstream, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaFile_GtkMediaFile, newForResource, arginfo_gtk_gtk_gtkmediafile_gtkmediafile_newforresource, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaFile_GtkMediaFile, clear, arginfo_gtk_gtk_gtkmediafile_gtkmediafile_clear, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaFile_GtkMediaFile, getFile, arginfo_gtk_gtk_gtkmediafile_gtkmediafile_getfile, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaFile_GtkMediaFile, getInputStream, arginfo_gtk_gtk_gtkmediafile_gtkmediafile_getinputstream, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaFile_GtkMediaFile, setFile, arginfo_gtk_gtk_gtkmediafile_gtkmediafile_setfile, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaFile_GtkMediaFile, setFilename, arginfo_gtk_gtk_gtkmediafile_gtkmediafile_setfilename, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaFile_GtkMediaFile, setInputStream, arginfo_gtk_gtk_gtkmediafile_gtkmediafile_setinputstream, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaFile_GtkMediaFile, setResource, arginfo_gtk_gtk_gtkmediafile_gtkmediafile_setresource, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
