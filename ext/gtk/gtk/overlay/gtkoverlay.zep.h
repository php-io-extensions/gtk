
extern zend_class_entry *gtk_gtk_overlay_gtkoverlay_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_Overlay_GtkOverlay);

PHP_METHOD(Gtk_GTK_Overlay_GtkOverlay, gtkOverlayNew);
PHP_METHOD(Gtk_GTK_Overlay_GtkOverlay, gtkOverlaySetChild);
PHP_METHOD(Gtk_GTK_Overlay_GtkOverlay, gtkOverlayGetChild);
PHP_METHOD(Gtk_GTK_Overlay_GtkOverlay, gtkOverlayAddOverlay);
PHP_METHOD(Gtk_GTK_Overlay_GtkOverlay, gtkOverlayRemoveOverlay);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_overlay_gtkoverlay_gtkoverlaynew, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_overlay_gtkoverlay_gtkoverlaysetchild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, overlay, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_overlay_gtkoverlay_gtkoverlaygetchild, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, overlay, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_overlay_gtkoverlay_gtkoverlayaddoverlay, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, overlay, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_overlay_gtkoverlay_gtkoverlayremoveoverlay, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, overlay, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_overlay_gtkoverlay_method_entry) {
	PHP_ME(Gtk_GTK_Overlay_GtkOverlay, gtkOverlayNew, arginfo_gtk_gtk_overlay_gtkoverlay_gtkoverlaynew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Overlay_GtkOverlay, gtkOverlaySetChild, arginfo_gtk_gtk_overlay_gtkoverlay_gtkoverlaysetchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Overlay_GtkOverlay, gtkOverlayGetChild, arginfo_gtk_gtk_overlay_gtkoverlay_gtkoverlaygetchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Overlay_GtkOverlay, gtkOverlayAddOverlay, arginfo_gtk_gtk_overlay_gtkoverlay_gtkoverlayaddoverlay, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Overlay_GtkOverlay, gtkOverlayRemoveOverlay, arginfo_gtk_gtk_overlay_gtkoverlay_gtkoverlayremoveoverlay, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
