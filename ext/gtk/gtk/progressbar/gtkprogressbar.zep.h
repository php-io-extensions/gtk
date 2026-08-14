
extern zend_class_entry *gtk_gtk_progressbar_gtkprogressbar_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_ProgressBar_GtkProgressBar);

PHP_METHOD(Gtk_GTK_ProgressBar_GtkProgressBar, gtkProgressBarNew);
PHP_METHOD(Gtk_GTK_ProgressBar_GtkProgressBar, gtkProgressBarSetFraction);
PHP_METHOD(Gtk_GTK_ProgressBar_GtkProgressBar, gtkProgressBarGetFraction);
PHP_METHOD(Gtk_GTK_ProgressBar_GtkProgressBar, gtkProgressBarSetText);
PHP_METHOD(Gtk_GTK_ProgressBar_GtkProgressBar, gtkProgressBarGetText);
PHP_METHOD(Gtk_GTK_ProgressBar_GtkProgressBar, gtkProgressBarSetShowText);
PHP_METHOD(Gtk_GTK_ProgressBar_GtkProgressBar, gtkProgressBarPulse);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_progressbar_gtkprogressbar_gtkprogressbarnew, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_progressbar_gtkprogressbar_gtkprogressbarsetfraction, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, bar, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fraction, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_progressbar_gtkprogressbar_gtkprogressbargetfraction, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, bar, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_progressbar_gtkprogressbar_gtkprogressbarsettext, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, bar, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_progressbar_gtkprogressbar_gtkprogressbargettext, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, bar, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_progressbar_gtkprogressbar_gtkprogressbarsetshowtext, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, bar, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, showText, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_progressbar_gtkprogressbar_gtkprogressbarpulse, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, bar, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_progressbar_gtkprogressbar_method_entry) {
	PHP_ME(Gtk_GTK_ProgressBar_GtkProgressBar, gtkProgressBarNew, arginfo_gtk_gtk_progressbar_gtkprogressbar_gtkprogressbarnew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_ProgressBar_GtkProgressBar, gtkProgressBarSetFraction, arginfo_gtk_gtk_progressbar_gtkprogressbar_gtkprogressbarsetfraction, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_ProgressBar_GtkProgressBar, gtkProgressBarGetFraction, arginfo_gtk_gtk_progressbar_gtkprogressbar_gtkprogressbargetfraction, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_ProgressBar_GtkProgressBar, gtkProgressBarSetText, arginfo_gtk_gtk_progressbar_gtkprogressbar_gtkprogressbarsettext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_ProgressBar_GtkProgressBar, gtkProgressBarGetText, arginfo_gtk_gtk_progressbar_gtkprogressbar_gtkprogressbargettext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_ProgressBar_GtkProgressBar, gtkProgressBarSetShowText, arginfo_gtk_gtk_progressbar_gtkprogressbar_gtkprogressbarsetshowtext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_ProgressBar_GtkProgressBar, gtkProgressBarPulse, arginfo_gtk_gtk_progressbar_gtkprogressbar_gtkprogressbarpulse, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
