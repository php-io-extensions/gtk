PHP_ARG_ENABLE(gtk, whether to enable gtk, [ --enable-gtk   Enable Gtk])

if test "$PHP_GTK" = "yes"; then

	
	AC_PATH_PROG(PKG_CONFIG, pkg-config, no)
	if test "x$PKG_CONFIG" = "xno"; then
		AC_MSG_RESULT([pkg-config not found])
		AC_MSG_ERROR([Please reinstall the pkg-config distribution])
	fi


	AC_MSG_CHECKING([for gtk4])
	if $PKG_CONFIG --exists gtk4; then
		PHP_GTK4_VERSION=`$PKG_CONFIG gtk4 --modversion`
		PHP_GTK4_PREFIX=`$PKG_CONFIG gtk4 --variable=prefix`

		if $PKG_CONFIG --atleast-version=4.18.0 gtk4; then
			AC_MSG_RESULT([found version $PHP_GTK4_VERSION, under $PHP_GTK4_PREFIX])
			PHP_GTK4_LIBS=`$PKG_CONFIG gtk4 --libs`
			PHP_GTK4_INCS=`$PKG_CONFIG gtk4 --cflags`

			PHP_EVAL_LIBLINE($PHP_GTK4_LIBS, GTK_SHARED_LIBADD)
			PHP_EVAL_INCLINE($PHP_GTK4_INCS)
		else
			AC_MSG_ERROR(Requested 'gtk4 >= 4.18.0' but version of gtk4 is $PHP_GTK4_VERSION)
		fi
	else
		AC_MSG_ERROR(Unable to find gtk4 installation)
	fi



	if ! test "x" = "x"; then
		PHP_EVAL_LIBLINE(, GTK_SHARED_LIBADD)
	fi

	AC_DEFINE(HAVE_GTK, 1, [Whether you have Gtk])
	gtk_sources="gtk.c kernel/main.c kernel/memory.c kernel/exception.c kernel/debug.c kernel/backtrace.c kernel/object.c kernel/array.c kernel/string.c kernel/fcall.c kernel/require.c kernel/file.c kernel/operators.c kernel/math.c kernel/concat.c kernel/variables.c kernel/filter.c kernel/iterator.c kernel/time.c kernel/exit.c gtk/bridge/bridge.zep.c
	gtk/gio/gaction/gaction.zep.c
	gtk/gio/gactionmap/gactionmap.zep.c
	gtk/gio/gapplication/gapplication.zep.c
	gtk/gio/glistmodel/glistmodel.zep.c
	gtk/gio/gliststore/gliststore.zep.c
	gtk/gio/gmenu/gmenu.zep.c
	gtk/gio/gmenuitem/gmenuitem.zep.c
	gtk/gio/gmenumodel/gmenumodel.zep.c
	gtk/gio/gsimpleaction/gsimpleaction.zep.c
	gtk/gio/gsimpleactiongroup/gsimpleactiongroup.zep.c
	gtk/gtk/gtkaboutdialog/gtkaboutdialog.zep.c
	gtk/gtk/gtkactionable/gtkactionable.zep.c
	gtk/gtk/gtkadjustment/gtkadjustment.zep.c
	gtk/gtk/gtkapplication/gtkapplication.zep.c
	gtk/gtk/gtkapplicationwindow/gtkapplicationwindow.zep.c
	gtk/gtk/gtkaspectframe/gtkaspectframe.zep.c
	gtk/gtk/gtkbox/gtkbox.zep.c
	gtk/gtk/gtkbutton/gtkbutton.zep.c
	gtk/gtk/gtkcenterbox/gtkcenterbox.zep.c
	gtk/gtk/gtkcheckbutton/gtkcheckbutton.zep.c
	gtk/gtk/gtkcssprovider/gtkcssprovider.zep.c
	gtk/gtk/gtkdropdown/gtkdropdown.zep.c
	gtk/gtk/gtkeditable/gtkeditable.zep.c
	gtk/gtk/gtkentry/gtkentry.zep.c
	gtk/gtk/gtkentrybuffer/gtkentrybuffer.zep.c
	gtk/gtk/gtkexpander/gtkexpander.zep.c
	gtk/gtk/gtkfixed/gtkfixed.zep.c
	gtk/gtk/gtkflowbox/gtkflowbox.zep.c
	gtk/gtk/gtkflowboxchild/gtkflowboxchild.zep.c
	gtk/gtk/gtkframe/gtkframe.zep.c
	gtk/gtk/gtkgrid/gtkgrid.zep.c
	gtk/gtk/gtkheaderbar/gtkheaderbar.zep.c
	gtk/gtk/gtkimage/gtkimage.zep.c
	gtk/gtk/gtklabel/gtklabel.zep.c
	gtk/gtk/gtklevelbar/gtklevelbar.zep.c
	gtk/gtk/gtklistbox/gtklistbox.zep.c
	gtk/gtk/gtklistboxrow/gtklistboxrow.zep.c
	gtk/gtk/gtkmediafile/gtkmediafile.zep.c
	gtk/gtk/gtkmediastream/gtkmediastream.zep.c
	gtk/gtk/gtknotebook/gtknotebook.zep.c
	gtk/gtk/gtknotebookpage/gtknotebookpage.zep.c
	gtk/gtk/gtkorientable/gtkorientable.zep.c
	gtk/gtk/gtkoverlay/gtkoverlay.zep.c
	gtk/gtk/gtkpaned/gtkpaned.zep.c
	gtk/gtk/gtkpasswordentry/gtkpasswordentry.zep.c
	gtk/gtk/gtkpicture/gtkpicture.zep.c
	gtk/gtk/gtkpopover/gtkpopover.zep.c
	gtk/gtk/gtkpopovermenu/gtkpopovermenu.zep.c
	gtk/gtk/gtkpopovermenubar/gtkpopovermenubar.zep.c
	gtk/gtk/gtkprogressbar/gtkprogressbar.zep.c
	gtk/gtk/gtkrange/gtkrange.zep.c
	gtk/gtk/gtkrevealer/gtkrevealer.zep.c
	gtk/gtk/gtkscale/gtkscale.zep.c
	gtk/gtk/gtkscrollable/gtkscrollable.zep.c
	gtk/gtk/gtkscrollbar/gtkscrollbar.zep.c
	gtk/gtk/gtkscrolledwindow/gtkscrolledwindow.zep.c
	gtk/gtk/gtksearchentry/gtksearchentry.zep.c
	gtk/gtk/gtkseparator/gtkseparator.zep.c
	gtk/gtk/gtkspinbutton/gtkspinbutton.zep.c
	gtk/gtk/gtkspinner/gtkspinner.zep.c
	gtk/gtk/gtkstack/gtkstack.zep.c
	gtk/gtk/gtkstackpage/gtkstackpage.zep.c
	gtk/gtk/gtkstacksidebar/gtkstacksidebar.zep.c
	gtk/gtk/gtkstackswitcher/gtkstackswitcher.zep.c
	gtk/gtk/gtkstringlist/gtkstringlist.zep.c
	gtk/gtk/gtkstringobject/gtkstringobject.zep.c
	gtk/gtk/gtkstylecontext/gtkstylecontext.zep.c
	gtk/gtk/gtkswitch/gtkswitch.zep.c
	gtk/gtk/gtktext/gtktext.zep.c
	gtk/gtk/gtktextbuffer/gtktextbuffer.zep.c
	gtk/gtk/gtktextmark/gtktextmark.zep.c
	gtk/gtk/gtktexttag/gtktexttag.zep.c
	gtk/gtk/gtktexttagtable/gtktexttagtable.zep.c
	gtk/gtk/gtktextview/gtktextview.zep.c
	gtk/gtk/gtktogglebutton/gtktogglebutton.zep.c
	gtk/gtk/gtkvideo/gtkvideo.zep.c
	gtk/gtk/gtkviewport/gtkviewport.zep.c
	gtk/gtk/gtkwidget/gtkwidget.zep.c
	gtk/gtk/gtkwindow/gtkwindow.zep.c
	gtk/gtk/gtkwindowcontrols/gtkwindowcontrols.zep.c src/phpgtk-support.c
	src/phpgtk-bridge.c
	src/gtk-widget.c
	src/gtk-window.c
	src/gtk-button.c
	src/gtk-box.c
	src/gtk-orientable.c
	src/gtk-application.c
	src/gio-gapplication.c
	src/gio-gsimpleactiongroup.c
	src/gtk-adjustment.c
	src/gtk-editable.c
	src/gtk-entry-buffer.c
	src/gtk-entry.c
	src/gtk-text.c
	src/gtk-password-entry.c
	src/gtk-search-entry.c
	src/gtk-toggle-button.c
	src/gtk-check-button.c
	src/gtk-switch.c
	src/gtk-range.c
	src/gtk-scale.c
	src/gtk-scrollbar.c
	src/gtk-spin-button.c
	src/gtk-label.c
	src/gtk-image.c
	src/gtk-picture.c
	src/gtk-spinner.c
	src/gtk-progress-bar.c
	src/gtk-level-bar.c
	src/gtk-separator.c
	src/gtk-frame.c
	src/gtk-aspect-frame.c
	src/gtk-center-box.c
	src/gtk-grid.c
	src/gtk-fixed.c
	src/gtk-overlay.c
	src/gtk-scrollable.c
	src/gtk-viewport.c
	src/gtk-scrolled-window.c
	src/gtk-expander.c
	src/gtk-revealer.c
	src/gio-glistmodel.c
	src/gio-gliststore.c
	src/gtk-string-object.c
	src/gtk-string-list.c
	src/gio-gaction.c
	src/gio-gactionmap.c
	src/gio-gsimpleaction.c
	src/gio-gmenumodel.c
	src/gio-gmenu.c
	src/gio-gmenuitem.c
	src/gtk-actionable.c
	src/gtk-drop-down.c
	src/gtk-list-box.c
	src/gtk-list-box-row.c
	src/gtk-flow-box.c
	src/gtk-flow-box-child.c
	src/gtk-notebook.c
	src/gtk-notebook-page.c
	src/gtk-stack.c
	src/gtk-stack-page.c
	src/gtk-stack-switcher.c
	src/gtk-stack-sidebar.c
	src/gtk-paned.c
	src/gtk-header-bar.c
	src/gtk-window-controls.c
	src/gtk-application-window.c
	src/gtk-about-dialog.c
	src/gtk-popover.c
	src/gtk-popover-menu.c
	src/gtk-popover-menu-bar.c
	src/gtk-text-buffer.c
	src/gtk-text-tag.c
	src/gtk-text-tag-table.c
	src/gtk-text-mark.c
	src/gtk-text-view.c
	src/gtk-css-provider.c
	src/gtk-style-context.c
	src/gtk-media-stream.c
	src/gtk-media-file.c
	src/gtk-video.c"
	PHP_NEW_EXTENSION(gtk, $gtk_sources, $ext_shared,, -Wno-error=incompatible-pointer-types $PHP_GTK4_INCS )
	PHP_ADD_BUILD_DIR([$ext_builddir/kernel/])
	for dir in "gtk/bridge gtk/gio/gaction gtk/gio/gactionmap gtk/gio/gapplication gtk/gio/glistmodel gtk/gio/gliststore gtk/gio/gmenu gtk/gio/gmenuitem gtk/gio/gmenumodel gtk/gio/gsimpleaction gtk/gio/gsimpleactiongroup gtk/gtk/gtkaboutdialog gtk/gtk/gtkactionable gtk/gtk/gtkadjustment gtk/gtk/gtkapplication gtk/gtk/gtkapplicationwindow gtk/gtk/gtkaspectframe gtk/gtk/gtkbox gtk/gtk/gtkbutton gtk/gtk/gtkcenterbox gtk/gtk/gtkcheckbutton gtk/gtk/gtkcssprovider gtk/gtk/gtkdropdown gtk/gtk/gtkeditable gtk/gtk/gtkentry gtk/gtk/gtkentrybuffer gtk/gtk/gtkexpander gtk/gtk/gtkfixed gtk/gtk/gtkflowbox gtk/gtk/gtkflowboxchild gtk/gtk/gtkframe gtk/gtk/gtkgrid gtk/gtk/gtkheaderbar gtk/gtk/gtkimage gtk/gtk/gtklabel gtk/gtk/gtklevelbar gtk/gtk/gtklistbox gtk/gtk/gtklistboxrow gtk/gtk/gtkmediafile gtk/gtk/gtkmediastream gtk/gtk/gtknotebook gtk/gtk/gtknotebookpage gtk/gtk/gtkorientable gtk/gtk/gtkoverlay gtk/gtk/gtkpaned gtk/gtk/gtkpasswordentry gtk/gtk/gtkpicture gtk/gtk/gtkpopover gtk/gtk/gtkpopovermenu gtk/gtk/gtkpopovermenubar gtk/gtk/gtkprogressbar gtk/gtk/gtkrange gtk/gtk/gtkrevealer gtk/gtk/gtkscale gtk/gtk/gtkscrollable gtk/gtk/gtkscrollbar gtk/gtk/gtkscrolledwindow gtk/gtk/gtksearchentry gtk/gtk/gtkseparator gtk/gtk/gtkspinbutton gtk/gtk/gtkspinner gtk/gtk/gtkstack gtk/gtk/gtkstackpage gtk/gtk/gtkstacksidebar gtk/gtk/gtkstackswitcher gtk/gtk/gtkstringlist gtk/gtk/gtkstringobject gtk/gtk/gtkstylecontext gtk/gtk/gtkswitch gtk/gtk/gtktext gtk/gtk/gtktextbuffer gtk/gtk/gtktextmark gtk/gtk/gtktexttag gtk/gtk/gtktexttagtable gtk/gtk/gtktextview gtk/gtk/gtktogglebutton gtk/gtk/gtkvideo gtk/gtk/gtkviewport gtk/gtk/gtkwidget gtk/gtk/gtkwindow gtk/gtk/gtkwindowcontrols"; do
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
