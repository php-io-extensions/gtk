
extern zend_class_entry *gtk_gtk_gtkimage_gtkimage_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkImage_GtkImage);

PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, new_);
PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, newFromFile);
PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, newFromGicon);
PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, newFromIconName);
PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, newFromPaintable);
PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, newFromResource);
PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, clear);
PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, getGicon);
PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, getIconName);
PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, getIconSize);
PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, getPaintable);
PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, getPixelSize);
PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, getStorageType);
PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, setFromFile);
PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, setFromGicon);
PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, setFromIconName);
PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, setFromPaintable);
PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, setFromResource);
PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, setIconSize);
PHP_METHOD(Gtk_Gtk_GtkImage_GtkImage, setPixelSize);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkimage_gtkimage_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkimage_gtkimage_newfromfile, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkimage_gtkimage_newfromgicon, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, icon, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkimage_gtkimage_newfromiconname, 0, 1, IS_LONG, 0)
	ZEND_ARG_INFO(0, iconName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkimage_gtkimage_newfrompaintable, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, paintable, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkimage_gtkimage_newfromresource, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, resourcePath, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkimage_gtkimage_clear, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkimage_gtkimage_getgicon, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkimage_gtkimage_geticonname, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkimage_gtkimage_geticonsize, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkimage_gtkimage_getpaintable, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkimage_gtkimage_getpixelsize, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkimage_gtkimage_getstoragetype, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkimage_gtkimage_setfromfile, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, filename)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkimage_gtkimage_setfromgicon, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, icon, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkimage_gtkimage_setfromiconname, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, iconName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkimage_gtkimage_setfrompaintable, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, paintable, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkimage_gtkimage_setfromresource, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, resourcePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkimage_gtkimage_seticonsize, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, iconSize, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkimage_gtkimage_setpixelsize, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, pixelSize, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkimage_gtkimage_method_entry) {
	PHP_ME(Gtk_Gtk_GtkImage_GtkImage, new_, arginfo_gtk_gtk_gtkimage_gtkimage_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkImage_GtkImage, newFromFile, arginfo_gtk_gtk_gtkimage_gtkimage_newfromfile, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkImage_GtkImage, newFromGicon, arginfo_gtk_gtk_gtkimage_gtkimage_newfromgicon, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkImage_GtkImage, newFromIconName, arginfo_gtk_gtk_gtkimage_gtkimage_newfromiconname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkImage_GtkImage, newFromPaintable, arginfo_gtk_gtk_gtkimage_gtkimage_newfrompaintable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkImage_GtkImage, newFromResource, arginfo_gtk_gtk_gtkimage_gtkimage_newfromresource, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkImage_GtkImage, clear, arginfo_gtk_gtk_gtkimage_gtkimage_clear, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkImage_GtkImage, getGicon, arginfo_gtk_gtk_gtkimage_gtkimage_getgicon, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkImage_GtkImage, getIconName, arginfo_gtk_gtk_gtkimage_gtkimage_geticonname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkImage_GtkImage, getIconSize, arginfo_gtk_gtk_gtkimage_gtkimage_geticonsize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkImage_GtkImage, getPaintable, arginfo_gtk_gtk_gtkimage_gtkimage_getpaintable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkImage_GtkImage, getPixelSize, arginfo_gtk_gtk_gtkimage_gtkimage_getpixelsize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkImage_GtkImage, getStorageType, arginfo_gtk_gtk_gtkimage_gtkimage_getstoragetype, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkImage_GtkImage, setFromFile, arginfo_gtk_gtk_gtkimage_gtkimage_setfromfile, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkImage_GtkImage, setFromGicon, arginfo_gtk_gtk_gtkimage_gtkimage_setfromgicon, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkImage_GtkImage, setFromIconName, arginfo_gtk_gtk_gtkimage_gtkimage_setfromiconname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkImage_GtkImage, setFromPaintable, arginfo_gtk_gtk_gtkimage_gtkimage_setfrompaintable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkImage_GtkImage, setFromResource, arginfo_gtk_gtk_gtkimage_gtkimage_setfromresource, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkImage_GtkImage, setIconSize, arginfo_gtk_gtk_gtkimage_gtkimage_seticonsize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkImage_GtkImage, setPixelSize, arginfo_gtk_gtk_gtkimage_gtkimage_setpixelsize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
