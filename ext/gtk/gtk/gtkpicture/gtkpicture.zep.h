
extern zend_class_entry *gtk_gtk_gtkpicture_gtkpicture_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkPicture_GtkPicture);

PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, new_);
PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, newForFile);
PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, newForFilename);
PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, newForPaintable);
PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, newForResource);
PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, getAlternativeText);
PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, getCanShrink);
PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, getContentFit);
PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, getFile);
PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, getPaintable);
PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, setAlternativeText);
PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, setCanShrink);
PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, setContentFit);
PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, setFile);
PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, setFilename);
PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, setPaintable);
PHP_METHOD(Gtk_Gtk_GtkPicture_GtkPicture, setResource);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpicture_gtkpicture_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpicture_gtkpicture_newforfile, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, file, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpicture_gtkpicture_newforfilename, 0, 1, IS_LONG, 0)
	ZEND_ARG_INFO(0, filename)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpicture_gtkpicture_newforpaintable, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, paintable, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpicture_gtkpicture_newforresource, 0, 1, IS_LONG, 0)
	ZEND_ARG_INFO(0, resourcePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkpicture_gtkpicture_getalternativetext, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpicture_gtkpicture_getcanshrink, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpicture_gtkpicture_getcontentfit, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpicture_gtkpicture_getfile, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpicture_gtkpicture_getpaintable, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpicture_gtkpicture_setalternativetext, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, alternativeText)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpicture_gtkpicture_setcanshrink, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, canShrink, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpicture_gtkpicture_setcontentfit, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, contentFit, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpicture_gtkpicture_setfile, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, file, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpicture_gtkpicture_setfilename, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, filename)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpicture_gtkpicture_setpaintable, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, paintable, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkpicture_gtkpicture_setresource, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, resourcePath)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkpicture_gtkpicture_method_entry) {
	PHP_ME(Gtk_Gtk_GtkPicture_GtkPicture, new_, arginfo_gtk_gtk_gtkpicture_gtkpicture_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPicture_GtkPicture, newForFile, arginfo_gtk_gtk_gtkpicture_gtkpicture_newforfile, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPicture_GtkPicture, newForFilename, arginfo_gtk_gtk_gtkpicture_gtkpicture_newforfilename, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPicture_GtkPicture, newForPaintable, arginfo_gtk_gtk_gtkpicture_gtkpicture_newforpaintable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPicture_GtkPicture, newForResource, arginfo_gtk_gtk_gtkpicture_gtkpicture_newforresource, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPicture_GtkPicture, getAlternativeText, arginfo_gtk_gtk_gtkpicture_gtkpicture_getalternativetext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPicture_GtkPicture, getCanShrink, arginfo_gtk_gtk_gtkpicture_gtkpicture_getcanshrink, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPicture_GtkPicture, getContentFit, arginfo_gtk_gtk_gtkpicture_gtkpicture_getcontentfit, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPicture_GtkPicture, getFile, arginfo_gtk_gtk_gtkpicture_gtkpicture_getfile, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPicture_GtkPicture, getPaintable, arginfo_gtk_gtk_gtkpicture_gtkpicture_getpaintable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPicture_GtkPicture, setAlternativeText, arginfo_gtk_gtk_gtkpicture_gtkpicture_setalternativetext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPicture_GtkPicture, setCanShrink, arginfo_gtk_gtk_gtkpicture_gtkpicture_setcanshrink, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPicture_GtkPicture, setContentFit, arginfo_gtk_gtk_gtkpicture_gtkpicture_setcontentfit, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPicture_GtkPicture, setFile, arginfo_gtk_gtk_gtkpicture_gtkpicture_setfile, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPicture_GtkPicture, setFilename, arginfo_gtk_gtk_gtkpicture_gtkpicture_setfilename, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPicture_GtkPicture, setPaintable, arginfo_gtk_gtk_gtkpicture_gtkpicture_setpaintable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkPicture_GtkPicture, setResource, arginfo_gtk_gtk_gtkpicture_gtkpicture_setresource, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
