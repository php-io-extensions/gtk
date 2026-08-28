
extern zend_class_entry *gtk_gtk_gtkprogressbar_gtkprogressbar_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkProgressBar_GtkProgressBar);

PHP_METHOD(Gtk_Gtk_GtkProgressBar_GtkProgressBar, new_);
PHP_METHOD(Gtk_Gtk_GtkProgressBar_GtkProgressBar, getEllipsize);
PHP_METHOD(Gtk_Gtk_GtkProgressBar_GtkProgressBar, getFraction);
PHP_METHOD(Gtk_Gtk_GtkProgressBar_GtkProgressBar, getInverted);
PHP_METHOD(Gtk_Gtk_GtkProgressBar_GtkProgressBar, getPulseStep);
PHP_METHOD(Gtk_Gtk_GtkProgressBar_GtkProgressBar, getShowText);
PHP_METHOD(Gtk_Gtk_GtkProgressBar_GtkProgressBar, getText);
PHP_METHOD(Gtk_Gtk_GtkProgressBar_GtkProgressBar, pulse);
PHP_METHOD(Gtk_Gtk_GtkProgressBar_GtkProgressBar, setEllipsize);
PHP_METHOD(Gtk_Gtk_GtkProgressBar_GtkProgressBar, setFraction);
PHP_METHOD(Gtk_Gtk_GtkProgressBar_GtkProgressBar, setInverted);
PHP_METHOD(Gtk_Gtk_GtkProgressBar_GtkProgressBar, setPulseStep);
PHP_METHOD(Gtk_Gtk_GtkProgressBar_GtkProgressBar, setShowText);
PHP_METHOD(Gtk_Gtk_GtkProgressBar_GtkProgressBar, setText);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkprogressbar_gtkprogressbar_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkprogressbar_gtkprogressbar_getellipsize, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkprogressbar_gtkprogressbar_getfraction, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkprogressbar_gtkprogressbar_getinverted, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkprogressbar_gtkprogressbar_getpulsestep, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkprogressbar_gtkprogressbar_getshowtext, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkprogressbar_gtkprogressbar_gettext, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkprogressbar_gtkprogressbar_pulse, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkprogressbar_gtkprogressbar_setellipsize, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, mode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkprogressbar_gtkprogressbar_setfraction, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fraction, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkprogressbar_gtkprogressbar_setinverted, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, inverted, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkprogressbar_gtkprogressbar_setpulsestep, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fraction, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkprogressbar_gtkprogressbar_setshowtext, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, showText, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkprogressbar_gtkprogressbar_settext, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkprogressbar_gtkprogressbar_method_entry) {
	PHP_ME(Gtk_Gtk_GtkProgressBar_GtkProgressBar, new_, arginfo_gtk_gtk_gtkprogressbar_gtkprogressbar_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkProgressBar_GtkProgressBar, getEllipsize, arginfo_gtk_gtk_gtkprogressbar_gtkprogressbar_getellipsize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkProgressBar_GtkProgressBar, getFraction, arginfo_gtk_gtk_gtkprogressbar_gtkprogressbar_getfraction, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkProgressBar_GtkProgressBar, getInverted, arginfo_gtk_gtk_gtkprogressbar_gtkprogressbar_getinverted, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkProgressBar_GtkProgressBar, getPulseStep, arginfo_gtk_gtk_gtkprogressbar_gtkprogressbar_getpulsestep, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkProgressBar_GtkProgressBar, getShowText, arginfo_gtk_gtk_gtkprogressbar_gtkprogressbar_getshowtext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkProgressBar_GtkProgressBar, getText, arginfo_gtk_gtk_gtkprogressbar_gtkprogressbar_gettext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkProgressBar_GtkProgressBar, pulse, arginfo_gtk_gtk_gtkprogressbar_gtkprogressbar_pulse, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkProgressBar_GtkProgressBar, setEllipsize, arginfo_gtk_gtk_gtkprogressbar_gtkprogressbar_setellipsize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkProgressBar_GtkProgressBar, setFraction, arginfo_gtk_gtk_gtkprogressbar_gtkprogressbar_setfraction, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkProgressBar_GtkProgressBar, setInverted, arginfo_gtk_gtk_gtkprogressbar_gtkprogressbar_setinverted, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkProgressBar_GtkProgressBar, setPulseStep, arginfo_gtk_gtk_gtkprogressbar_gtkprogressbar_setpulsestep, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkProgressBar_GtkProgressBar, setShowText, arginfo_gtk_gtk_gtkprogressbar_gtkprogressbar_setshowtext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkProgressBar_GtkProgressBar, setText, arginfo_gtk_gtk_gtkprogressbar_gtkprogressbar_settext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
