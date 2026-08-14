
extern zend_class_entry *gtk_gtk_stack_gtkstack_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_Stack_GtkStack);

PHP_METHOD(Gtk_GTK_Stack_GtkStack, gtkStackNew);
PHP_METHOD(Gtk_GTK_Stack_GtkStack, gtkStackAddChild);
PHP_METHOD(Gtk_GTK_Stack_GtkStack, gtkStackAddTitled);
PHP_METHOD(Gtk_GTK_Stack_GtkStack, gtkStackRemove);
PHP_METHOD(Gtk_GTK_Stack_GtkStack, gtkStackSetVisibleChild);
PHP_METHOD(Gtk_GTK_Stack_GtkStack, gtkStackGetVisibleChild);
PHP_METHOD(Gtk_GTK_Stack_GtkStack, gtkStackSetVisibleChildName);
PHP_METHOD(Gtk_GTK_Stack_GtkStack, gtkStackGetVisibleChildName);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_stack_gtkstack_gtkstacknew, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_stack_gtkstack_gtkstackaddchild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, stack, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_stack_gtkstack_gtkstackaddtitled, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, stack, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, title, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_stack_gtkstack_gtkstackremove, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, stack, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_stack_gtkstack_gtkstacksetvisiblechild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, stack, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_stack_gtkstack_gtkstackgetvisiblechild, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, stack, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_stack_gtkstack_gtkstacksetvisiblechildname, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, stack, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_stack_gtkstack_gtkstackgetvisiblechildname, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, stack, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_stack_gtkstack_method_entry) {
	PHP_ME(Gtk_GTK_Stack_GtkStack, gtkStackNew, arginfo_gtk_gtk_stack_gtkstack_gtkstacknew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Stack_GtkStack, gtkStackAddChild, arginfo_gtk_gtk_stack_gtkstack_gtkstackaddchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Stack_GtkStack, gtkStackAddTitled, arginfo_gtk_gtk_stack_gtkstack_gtkstackaddtitled, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Stack_GtkStack, gtkStackRemove, arginfo_gtk_gtk_stack_gtkstack_gtkstackremove, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Stack_GtkStack, gtkStackSetVisibleChild, arginfo_gtk_gtk_stack_gtkstack_gtkstacksetvisiblechild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Stack_GtkStack, gtkStackGetVisibleChild, arginfo_gtk_gtk_stack_gtkstack_gtkstackgetvisiblechild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Stack_GtkStack, gtkStackSetVisibleChildName, arginfo_gtk_gtk_stack_gtkstack_gtkstacksetvisiblechildname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_Stack_GtkStack, gtkStackGetVisibleChildName, arginfo_gtk_gtk_stack_gtkstack_gtkstackgetvisiblechildname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
