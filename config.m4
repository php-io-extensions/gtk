PHP_ARG_ENABLE([gtk],
  [whether to enable gtk support],
  [AS_HELP_STRING([--enable-gtk], [Enable GTK 4 bindings])],
  [no])

if test "$PHP_GTK" != "no"; then
  PKG_CHECK_MODULES([GTK], [gtk4 >= 4.10 glib-2.0 >= 2.74 gio-unix-2.0])
  PHP_EVAL_INCLINE([$GTK_CFLAGS])
  PHP_EVAL_LIBLINE([$GTK_LIBS], [GTK_SHARED_LIBADD])
  PHP_SUBST([GTK_SHARED_LIBADD])

  PHP_NEW_EXTENSION([gtk],
    [src/gtk.c src/runtime.c src/GObject.c src/GApplication.c src/GtkApplication.c src/GMainContext.c src/GVariant.c src/GtkWidget.c src/GtkWindow.c src/GMenu.c src/GAction.c],
    [$ext_shared],, [-DZEND_ENABLE_STATIC_TSRMLS_CACHE=1])
  PHP_ADD_BUILD_DIR([$ext_builddir/src])
fi
