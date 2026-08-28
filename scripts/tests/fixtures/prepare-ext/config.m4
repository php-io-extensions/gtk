PHP_ARG_ENABLE(gtk, whether to enable gtk, [ --enable-gtk   Enable gtk])

if test "$PHP_GTK" = "yes"; then
	AC_DEFINE(HAVE_GTK, 1, [Whether you have gtk])
	gtk_sources="gtk.c kernel/main.c gtk/bridge/bridge.zep.c"
	PHP_NEW_EXTENSION(gtk, $gtk_sources, $ext_shared,,)
	PHP_SUBST(GTK_SHARED_LIBADD)
fi
