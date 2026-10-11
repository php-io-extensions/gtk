/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 41fc80f8f0bb807cf841d2bfa0dbae5827276749 */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GCancellable_new, 0, 0, GCancellable, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GCancellable_cancel, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GCancellable_isCancelled, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkUriLauncher_new, 0, 1, GtkUriLauncher, 0)
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkUriLauncher_getUri, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkUriLauncher_setUri, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkUriLauncher_launch, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, parent, GtkWindow, 1)
	ZEND_ARG_OBJ_INFO(0, cancellable, GCancellable, 1)
	ZEND_ARG_TYPE_INFO(0, callback, IS_CALLABLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkUriLauncher_launchFinish, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, result, GAsyncResult, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(GCancellable, new);
ZEND_METHOD(GCancellable, cancel);
ZEND_METHOD(GCancellable, isCancelled);
ZEND_METHOD(GtkUriLauncher, new);
ZEND_METHOD(GtkUriLauncher, getUri);
ZEND_METHOD(GtkUriLauncher, setUri);
ZEND_METHOD(GtkUriLauncher, launch);
ZEND_METHOD(GtkUriLauncher, launchFinish);

static const zend_function_entry class_GCancellable_methods[] = {
	ZEND_ME(GCancellable, new, arginfo_class_GCancellable_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GCancellable, cancel, arginfo_class_GCancellable_cancel, ZEND_ACC_PUBLIC)
	ZEND_ME(GCancellable, isCancelled, arginfo_class_GCancellable_isCancelled, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkUriLauncher_methods[] = {
	ZEND_ME(GtkUriLauncher, new, arginfo_class_GtkUriLauncher_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkUriLauncher, getUri, arginfo_class_GtkUriLauncher_getUri, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkUriLauncher, setUri, arginfo_class_GtkUriLauncher_setUri, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkUriLauncher, launch, arginfo_class_GtkUriLauncher_launch, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkUriLauncher, launchFinish, arginfo_class_GtkUriLauncher_launchFinish, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_GCancellable(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GCancellable", class_GCancellable_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GAsyncResult(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GAsyncResult", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkUriLauncher(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkUriLauncher", class_GtkUriLauncher_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
