
extern zend_class_entry *gtk_gtk_picture_gtkpicture_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_Picture_GtkPicture);

PHP_METHOD(Gtk_GTK_Picture_GtkPicture, gtkPictureNew);
PHP_METHOD(Gtk_GTK_Picture_GtkPicture, gtkPictureNewForFilename);
PHP_METHOD(Gtk_GTK_Picture_GtkPicture, gtkPictureSetFilename);
PHP_METHOD(Gtk_GTK_Picture_GtkPicture, gtkPictureSetCanShrink);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_picture_gtkpicture_gtkpicturenew, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_picture_gtkpicture_gtkpicturenewforfilename, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_picture_gtkpicture_gtkpicturesetfilename, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, picture, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_picture_gtkpicture_gtkpicturesetcanshrink, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, picture, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, canShrink, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_picture_gtkpicture_method_entry) {
	PHP_ME(Gtk_GTK_Picture_GtkPicture, gtkPictureNew, arginfo_gtk_gtk_picture_gtkpicture_gtkpicturenew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Picture_GtkPicture, gtkPictureNewForFilename, arginfo_gtk_gtk_picture_gtkpicture_gtkpicturenewforfilename, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Picture_GtkPicture, gtkPictureSetFilename, arginfo_gtk_gtk_picture_gtkpicture_gtkpicturesetfilename, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Picture_GtkPicture, gtkPictureSetCanShrink, arginfo_gtk_gtk_picture_gtkpicture_gtkpicturesetcanshrink, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
