
extern zend_class_entry *gtk_gtk_gtkrevealer_gtkrevealer_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkRevealer_GtkRevealer);

PHP_METHOD(Gtk_Gtk_GtkRevealer_GtkRevealer, new_);
PHP_METHOD(Gtk_Gtk_GtkRevealer_GtkRevealer, getChild);
PHP_METHOD(Gtk_Gtk_GtkRevealer_GtkRevealer, getChildRevealed);
PHP_METHOD(Gtk_Gtk_GtkRevealer_GtkRevealer, getRevealChild);
PHP_METHOD(Gtk_Gtk_GtkRevealer_GtkRevealer, getTransitionDuration);
PHP_METHOD(Gtk_Gtk_GtkRevealer_GtkRevealer, getTransitionType);
PHP_METHOD(Gtk_Gtk_GtkRevealer_GtkRevealer, setChild);
PHP_METHOD(Gtk_Gtk_GtkRevealer_GtkRevealer, setRevealChild);
PHP_METHOD(Gtk_Gtk_GtkRevealer_GtkRevealer, setTransitionDuration);
PHP_METHOD(Gtk_Gtk_GtkRevealer_GtkRevealer, setTransitionType);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkrevealer_gtkrevealer_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkrevealer_gtkrevealer_getchild, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkrevealer_gtkrevealer_getchildrevealed, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkrevealer_gtkrevealer_getrevealchild, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkrevealer_gtkrevealer_gettransitionduration, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkrevealer_gtkrevealer_gettransitiontype, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkrevealer_gtkrevealer_setchild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkrevealer_gtkrevealer_setrevealchild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, revealChild, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkrevealer_gtkrevealer_settransitionduration, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, duration, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkrevealer_gtkrevealer_settransitiontype, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, transition, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkrevealer_gtkrevealer_method_entry) {
	PHP_ME(Gtk_Gtk_GtkRevealer_GtkRevealer, new_, arginfo_gtk_gtk_gtkrevealer_gtkrevealer_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkRevealer_GtkRevealer, getChild, arginfo_gtk_gtk_gtkrevealer_gtkrevealer_getchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkRevealer_GtkRevealer, getChildRevealed, arginfo_gtk_gtk_gtkrevealer_gtkrevealer_getchildrevealed, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkRevealer_GtkRevealer, getRevealChild, arginfo_gtk_gtk_gtkrevealer_gtkrevealer_getrevealchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkRevealer_GtkRevealer, getTransitionDuration, arginfo_gtk_gtk_gtkrevealer_gtkrevealer_gettransitionduration, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkRevealer_GtkRevealer, getTransitionType, arginfo_gtk_gtk_gtkrevealer_gtkrevealer_gettransitiontype, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkRevealer_GtkRevealer, setChild, arginfo_gtk_gtk_gtkrevealer_gtkrevealer_setchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkRevealer_GtkRevealer, setRevealChild, arginfo_gtk_gtk_gtkrevealer_gtkrevealer_setrevealchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkRevealer_GtkRevealer, setTransitionDuration, arginfo_gtk_gtk_gtkrevealer_gtkrevealer_settransitionduration, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkRevealer_GtkRevealer, setTransitionType, arginfo_gtk_gtk_gtkrevealer_gtkrevealer_settransitiontype, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
