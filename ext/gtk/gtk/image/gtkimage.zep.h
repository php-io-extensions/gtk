
extern zend_class_entry *gtk_gtk_image_gtkimage_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_Image_GtkImage);

PHP_METHOD(Gtk_GTK_Image_GtkImage, gtkImageNew);
PHP_METHOD(Gtk_GTK_Image_GtkImage, gtkImageNewFromFile);
PHP_METHOD(Gtk_GTK_Image_GtkImage, gtkImageSetFromFile);
PHP_METHOD(Gtk_GTK_Image_GtkImage, gtkImageSetFromIconName);
PHP_METHOD(Gtk_GTK_Image_GtkImage, gtkImageClear);
PHP_METHOD(Gtk_GTK_Image_GtkImage, gtkImageSetPixelSize);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_image_gtkimage_gtkimagenew, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_image_gtkimage_gtkimagenewfromfile, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_image_gtkimage_gtkimagesetfromfile, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, image, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_image_gtkimage_gtkimagesetfromiconname, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, image, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, iconName, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_image_gtkimage_gtkimageclear, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, image, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_image_gtkimage_gtkimagesetpixelsize, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, image, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, size, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_image_gtkimage_method_entry) {
	PHP_ME(Gtk_GTK_Image_GtkImage, gtkImageNew, arginfo_gtk_gtk_image_gtkimage_gtkimagenew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Image_GtkImage, gtkImageNewFromFile, arginfo_gtk_gtk_image_gtkimage_gtkimagenewfromfile, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Image_GtkImage, gtkImageSetFromFile, arginfo_gtk_gtk_image_gtkimage_gtkimagesetfromfile, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Image_GtkImage, gtkImageSetFromIconName, arginfo_gtk_gtk_image_gtkimage_gtkimagesetfromiconname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Image_GtkImage, gtkImageClear, arginfo_gtk_gtk_image_gtkimage_gtkimageclear, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Image_GtkImage, gtkImageSetPixelSize, arginfo_gtk_gtk_image_gtkimage_gtkimagesetpixelsize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
