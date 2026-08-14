PHP_ARG_ENABLE(gtk, whether to enable gtk, [ --enable-gtk   Enable Gtk])

if test "$PHP_GTK" = "yes"; then

	dnl GCC 14+ promotes long-standing warnings to errors; Zephir-generated C
	dnl trips some of them. Demote back to warnings.
	CFLAGS="$CFLAGS -Wno-error=incompatible-pointer-types -Wno-error=int-conversion -Wno-error=implicit-function-declaration -Wno-error=implicit-int"

	AC_PATH_PROG(PKG_CONFIG, pkg-config, no)
	if test "x$PKG_CONFIG" = "xno"; then
		AC_MSG_RESULT([pkg-config not found])
		AC_MSG_ERROR([Please reinstall the pkg-config distribution])
	fi

	AC_MSG_CHECKING([for gtk4])
	if $PKG_CONFIG --exists gtk4; then
		PHP_GTK4_VERSION=`$PKG_CONFIG gtk4 --modversion`
		PHP_GTK4_PREFIX=`$PKG_CONFIG gtk4 --variable=prefix`

		if $PKG_CONFIG --atleast-version=4.10.0 gtk4; then
			AC_MSG_RESULT([found version $PHP_GTK4_VERSION, under $PHP_GTK4_PREFIX])
			PHP_GTK4_LIBS=`$PKG_CONFIG gtk4 --libs`
			PHP_GTK4_INCS=`$PKG_CONFIG gtk4 --cflags`

			PHP_EVAL_LIBLINE($PHP_GTK4_LIBS, GTK_SHARED_LIBADD)
			PHP_EVAL_INCLINE($PHP_GTK4_INCS)
			if $PKG_CONFIG --exists x11; then
				PHP_EVAL_LIBLINE(`$PKG_CONFIG x11 --libs`, GTK_SHARED_LIBADD)
				PHP_EVAL_INCLINE(`$PKG_CONFIG x11 --cflags`)
			fi
			if $PKG_CONFIG --exists xcomposite; then
				PHP_EVAL_LIBLINE(`$PKG_CONFIG xcomposite --libs`, GTK_SHARED_LIBADD)
				PHP_EVAL_INCLINE(`$PKG_CONFIG xcomposite --cflags`)
			fi
		else
			AC_MSG_ERROR(Requested 'gtk4 >= 4.10.0' but version of gtk4 is $PHP_GTK4_VERSION)
		fi
	else
		AC_MSG_ERROR(Unable to find gtk4 installation (pkg-config gtk4))
	fi

	AC_DEFINE(HAVE_GTK, 1, [Whether you have Gtk])
	gtk_sources="gtk.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c gtk/gtk/alertdialog/gtkalertdialog.zep.c
	gtk/gtk/application/gtkapplication.zep.c
	gtk/gtk/box/gtkbox.zep.c
	gtk/gtk/button/gtkbutton.zep.c
	gtk/gtk/centerbox/gtkcenterbox.zep.c
	gtk/gtk/checkbutton/gtkcheckbutton.zep.c
	gtk/gtk/colordialog/gtkcolordialog.zep.c
	gtk/gtk/dropdown/gtkdropdown.zep.c
	gtk/gtk/entry/gtkentry.zep.c
	gtk/gtk/filedialog/gtkfiledialog.zep.c
	gtk/gtk/fontdialog/gtkfontdialog.zep.c
	gtk/gtk/glarea/gtkglarea.zep.c
	gtk/gtk/gpupane/gtkgpupane.zep.c
	gtk/gtk/grid/gtkgrid.zep.c
	gtk/gtk/gtkglib.zep.c
	gtk/gtk/gtk.zep.c
	gtk/gtk/gtkerror.zep.c
	gtk/gtk/gtkswitch/gtkswitch.zep.c
	gtk/gtk/headerbar/gtkheaderbar.zep.c
	gtk/gtk/image/gtkimage.zep.c
	gtk/gtk/label/gtklabel.zep.c
	gtk/gtk/listbox/gtklistbox.zep.c
	gtk/gtk/listitem/gtklistitem.zep.c
	gtk/gtk/listview/gtklistview.zep.c
	gtk/gtk/menubutton/gtkmenubutton.zep.c
	gtk/gtk/notebook/gtknotebook.zep.c
	gtk/gtk/overlay/gtkoverlay.zep.c
	gtk/gtk/paned/gtkpaned.zep.c
	gtk/gtk/passwordentry/gtkpasswordentry.zep.c
	gtk/gtk/picture/gtkpicture.zep.c
	gtk/gtk/popover/gtkpopover.zep.c
	gtk/gtk/progressbar/gtkprogressbar.zep.c
	gtk/gtk/scale/gtkscale.zep.c
	gtk/gtk/scrolledwindow/gtkscrolledwindow.zep.c
	gtk/gtk/searchentry/gtksearchentry.zep.c
	gtk/gtk/separator/gtkseparator.zep.c
	gtk/gtk/singleselection/gtksingleselection.zep.c
	gtk/gtk/spinbutton/gtkspinbutton.zep.c
	gtk/gtk/spinner/gtkspinner.zep.c
	gtk/gtk/stack/gtkstack.zep.c
	gtk/gtk/stringlist/gtkstringlist.zep.c
	gtk/gtk/textview/gtktextview.zep.c
	gtk/gtk/togglebutton/gtktogglebutton.zep.c
	gtk/gtk/widget/gtkwidget.zep.c
	gtk/gtk/window/gtkwindow.zep.c "
	PHP_NEW_EXTENSION(gtk, $gtk_sources, $ext_shared,, $PHP_GTK4_INCS )
	PHP_ADD_BUILD_DIR([$ext_builddir/kernel/])
	for dir in "gtk/gtk" "gtk/gtk/alertdialog" "gtk/gtk/application" "gtk/gtk/box" "gtk/gtk/button" "gtk/gtk/centerbox" "gtk/gtk/checkbutton" "gtk/gtk/colordialog" "gtk/gtk/dropdown" "gtk/gtk/entry" "gtk/gtk/filedialog" "gtk/gtk/fontdialog" "gtk/gtk/glarea" "gtk/gtk/gpupane" "gtk/gtk/grid" "gtk/gtk/gtkswitch" "gtk/gtk/headerbar" "gtk/gtk/image" "gtk/gtk/label" "gtk/gtk/listbox" "gtk/gtk/listitem" "gtk/gtk/listview" "gtk/gtk/menubutton" "gtk/gtk/notebook" "gtk/gtk/overlay" "gtk/gtk/paned" "gtk/gtk/passwordentry" "gtk/gtk/picture" "gtk/gtk/popover" "gtk/gtk/progressbar" "gtk/gtk/scale" "gtk/gtk/scrolledwindow" "gtk/gtk/searchentry" "gtk/gtk/separator" "gtk/gtk/singleselection" "gtk/gtk/spinbutton" "gtk/gtk/spinner" "gtk/gtk/stack" "gtk/gtk/stringlist" "gtk/gtk/textview" "gtk/gtk/togglebutton" "gtk/gtk/widget" "gtk/gtk/window"; do
		PHP_ADD_BUILD_DIR([$ext_builddir/$dir])
	done

	PHP_SUBST(GTK_SHARED_LIBADD)

	old_CPPFLAGS=$CPPFLAGS
	CPPFLAGS="$CPPFLAGS $INCLUDES"

	AC_CHECK_DECL(
		[HAVE_BUNDLED_PCRE],
		[
			AC_CHECK_HEADERS(
				[ext/pcre/php_pcre.h],
				[
					PHP_ADD_EXTENSION_DEP([gtk], [pcre])
					AC_DEFINE([ZEPHIR_USE_PHP_PCRE], [1], [Whether PHP pcre extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	AC_CHECK_DECL(
		[HAVE_JSON],
		[
			AC_CHECK_HEADERS(
				[ext/json/php_json.h],
				[
					PHP_ADD_EXTENSION_DEP([gtk], [json])
					AC_DEFINE([ZEPHIR_USE_PHP_JSON], [1], [Whether PHP json extension is present at compile time])
				],
				,
				[[#include "main/php.h"]]
			)
		],
		,
		[[#include "php_config.h"]]
	)

	CPPFLAGS=$old_CPPFLAGS

	PHP_INSTALL_HEADERS([ext/gtk], [php_GTK.h])

fi
