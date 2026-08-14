
extern zend_class_entry *gtk_gtk_glarea_gtkglarea_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_GLArea_GtkGLArea);

PHP_METHOD(Gtk_GTK_GLArea_GtkGLArea, gtkGLAreaNew);
PHP_METHOD(Gtk_GTK_GLArea_GtkGLArea, gtkGLAreaMakeCurrent);
PHP_METHOD(Gtk_GTK_GLArea_GtkGLArea, gtkGLAreaQueueRender);
PHP_METHOD(Gtk_GTK_GLArea_GtkGLArea, gtkGLAreaSetAutoRender);
PHP_METHOD(Gtk_GTK_GLArea_GtkGLArea, gtkGLAreaGetError);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_glarea_gtkglarea_gtkglareanew, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_glarea_gtkglarea_gtkglareamakecurrent, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, area, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_glarea_gtkglarea_gtkglareaqueuerender, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, area, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_glarea_gtkglarea_gtkglareasetautorender, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, area, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, autoRender, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_glarea_gtkglarea_gtkglareageterror, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, area, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_glarea_gtkglarea_method_entry) {
	PHP_ME(Gtk_GTK_GLArea_GtkGLArea, gtkGLAreaNew, arginfo_gtk_gtk_glarea_gtkglarea_gtkglareanew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_GLArea_GtkGLArea, gtkGLAreaMakeCurrent, arginfo_gtk_gtk_glarea_gtkglarea_gtkglareamakecurrent, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_GLArea_GtkGLArea, gtkGLAreaQueueRender, arginfo_gtk_gtk_glarea_gtkglarea_gtkglareaqueuerender, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_GLArea_GtkGLArea, gtkGLAreaSetAutoRender, arginfo_gtk_gtk_glarea_gtkglarea_gtkglareasetautorender, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_GLArea_GtkGLArea, gtkGLAreaGetError, arginfo_gtk_gtk_glarea_gtkglarea_gtkglareageterror, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
