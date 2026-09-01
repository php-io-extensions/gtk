
extern zend_class_entry *gtk_gtk_gtkvideo_gtkvideo_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkVideo_GtkVideo);

PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, new_);
PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, newForFile);
PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, newForFilename);
PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, newForMediaStream);
PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, newForResource);
PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, getAutoplay);
PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, getFile);
PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, getGraphicsOffload);
PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, getLoop);
PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, getMediaStream);
PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, setAutoplay);
PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, setFile);
PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, setFilename);
PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, setGraphicsOffload);
PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, setLoop);
PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, setMediaStream);
PHP_METHOD(Gtk_Gtk_GtkVideo_GtkVideo, setResource);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkvideo_gtkvideo_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkvideo_gtkvideo_newforfile, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, file, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkvideo_gtkvideo_newforfilename, 0, 1, IS_LONG, 0)
	ZEND_ARG_INFO(0, filename)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkvideo_gtkvideo_newformediastream, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, stream, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkvideo_gtkvideo_newforresource, 0, 1, IS_LONG, 0)
	ZEND_ARG_INFO(0, resourcePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkvideo_gtkvideo_getautoplay, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkvideo_gtkvideo_getfile, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkvideo_gtkvideo_getgraphicsoffload, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkvideo_gtkvideo_getloop, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkvideo_gtkvideo_getmediastream, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkvideo_gtkvideo_setautoplay, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, autoplay, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkvideo_gtkvideo_setfile, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, file, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkvideo_gtkvideo_setfilename, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, filename)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkvideo_gtkvideo_setgraphicsoffload, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, enabled, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkvideo_gtkvideo_setloop, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, loop_, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkvideo_gtkvideo_setmediastream, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, stream, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkvideo_gtkvideo_setresource, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, resourcePath)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkvideo_gtkvideo_method_entry) {
	PHP_ME(Gtk_Gtk_GtkVideo_GtkVideo, new_, arginfo_gtk_gtk_gtkvideo_gtkvideo_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkVideo_GtkVideo, newForFile, arginfo_gtk_gtk_gtkvideo_gtkvideo_newforfile, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkVideo_GtkVideo, newForFilename, arginfo_gtk_gtk_gtkvideo_gtkvideo_newforfilename, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkVideo_GtkVideo, newForMediaStream, arginfo_gtk_gtk_gtkvideo_gtkvideo_newformediastream, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkVideo_GtkVideo, newForResource, arginfo_gtk_gtk_gtkvideo_gtkvideo_newforresource, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkVideo_GtkVideo, getAutoplay, arginfo_gtk_gtk_gtkvideo_gtkvideo_getautoplay, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkVideo_GtkVideo, getFile, arginfo_gtk_gtk_gtkvideo_gtkvideo_getfile, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkVideo_GtkVideo, getGraphicsOffload, arginfo_gtk_gtk_gtkvideo_gtkvideo_getgraphicsoffload, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkVideo_GtkVideo, getLoop, arginfo_gtk_gtk_gtkvideo_gtkvideo_getloop, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkVideo_GtkVideo, getMediaStream, arginfo_gtk_gtk_gtkvideo_gtkvideo_getmediastream, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkVideo_GtkVideo, setAutoplay, arginfo_gtk_gtk_gtkvideo_gtkvideo_setautoplay, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkVideo_GtkVideo, setFile, arginfo_gtk_gtk_gtkvideo_gtkvideo_setfile, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkVideo_GtkVideo, setFilename, arginfo_gtk_gtk_gtkvideo_gtkvideo_setfilename, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkVideo_GtkVideo, setGraphicsOffload, arginfo_gtk_gtk_gtkvideo_gtkvideo_setgraphicsoffload, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkVideo_GtkVideo, setLoop, arginfo_gtk_gtk_gtkvideo_gtkvideo_setloop, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkVideo_GtkVideo, setMediaStream, arginfo_gtk_gtk_gtkvideo_gtkvideo_setmediastream, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkVideo_GtkVideo, setResource, arginfo_gtk_gtk_gtkvideo_gtkvideo_setresource, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
