/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 7bc56e87804888ec270891ffa862259f33e2fce7 */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkWindow_new, 0, 0, GtkWindow, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWindow_getTitle, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWindow_setTitle, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, title, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWindow_getDefaultSize, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWindow_setDefaultSize, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkWindow_getSurfaceTransform arginfo_class_GtkWindow_getDefaultSize

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkWindow_getChild, 0, 0, GtkWidget, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWindow_setChild, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, child, GtkWidget, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWindow_present, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkWindow_close arginfo_class_GtkWindow_present

#define arginfo_class_GtkWindow_destroy arginfo_class_GtkWindow_present

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWindow_isActive, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkWindow_getTransientFor, 0, 0, GtkWindow, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWindow_setTransientFor, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, parent, GtkWindow, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkWindow_getApplication, 0, 0, GtkApplication, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWindow_setApplication, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, application, GtkApplication, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkWindow_getModal arginfo_class_GtkWindow_isActive

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWindow_setModal, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, modal, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkWindow_getHideOnClose arginfo_class_GtkWindow_isActive

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWindow_setHideOnClose, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, setting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkApplicationWindow_new, 0, 0, GtkApplicationWindow, 0)
	ZEND_ARG_OBJ_INFO_WITH_DEFAULT_VALUE(0, application, GtkApplication, 1, "null")
ZEND_END_ARG_INFO()

#define arginfo_class_GtkApplicationWindow_getShowMenubar arginfo_class_GtkWindow_isActive

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkApplicationWindow_setShowMenubar, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, showMenubar, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkApplicationWindow_getId, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkAboutDialog_new, 0, 0, GtkAboutDialog, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkAboutDialog_getProgramName arginfo_class_GtkWindow_getTitle

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkAboutDialog_setProgramName, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkAboutDialog_getVersion arginfo_class_GtkWindow_getTitle

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkAboutDialog_setVersion, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, version, IS_STRING, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkAboutDialog_getCopyright arginfo_class_GtkWindow_getTitle

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkAboutDialog_setCopyright, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, copyright, IS_STRING, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkAboutDialog_getComments arginfo_class_GtkWindow_getTitle

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkAboutDialog_setComments, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, comments, IS_STRING, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkAboutDialog_getWebsite arginfo_class_GtkWindow_getTitle

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkAboutDialog_setWebsite, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, website, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_METHOD(GtkWindow, new);
ZEND_METHOD(GtkWindow, getTitle);
ZEND_METHOD(GtkWindow, setTitle);
ZEND_METHOD(GtkWindow, getDefaultSize);
ZEND_METHOD(GtkWindow, setDefaultSize);
ZEND_METHOD(GtkWindow, getSurfaceTransform);
ZEND_METHOD(GtkWindow, getChild);
ZEND_METHOD(GtkWindow, setChild);
ZEND_METHOD(GtkWindow, present);
ZEND_METHOD(GtkWindow, close);
ZEND_METHOD(GtkWindow, destroy);
ZEND_METHOD(GtkWindow, isActive);
ZEND_METHOD(GtkWindow, getTransientFor);
ZEND_METHOD(GtkWindow, setTransientFor);
ZEND_METHOD(GtkWindow, getApplication);
ZEND_METHOD(GtkWindow, setApplication);
ZEND_METHOD(GtkWindow, getModal);
ZEND_METHOD(GtkWindow, setModal);
ZEND_METHOD(GtkWindow, getHideOnClose);
ZEND_METHOD(GtkWindow, setHideOnClose);
ZEND_METHOD(GtkApplicationWindow, new);
ZEND_METHOD(GtkApplicationWindow, getShowMenubar);
ZEND_METHOD(GtkApplicationWindow, setShowMenubar);
ZEND_METHOD(GtkApplicationWindow, getId);
ZEND_METHOD(GtkAboutDialog, new);
ZEND_METHOD(GtkAboutDialog, getProgramName);
ZEND_METHOD(GtkAboutDialog, setProgramName);
ZEND_METHOD(GtkAboutDialog, getVersion);
ZEND_METHOD(GtkAboutDialog, setVersion);
ZEND_METHOD(GtkAboutDialog, getCopyright);
ZEND_METHOD(GtkAboutDialog, setCopyright);
ZEND_METHOD(GtkAboutDialog, getComments);
ZEND_METHOD(GtkAboutDialog, setComments);
ZEND_METHOD(GtkAboutDialog, getWebsite);
ZEND_METHOD(GtkAboutDialog, setWebsite);

static const zend_function_entry class_GtkWindow_methods[] = {
	ZEND_ME(GtkWindow, new, arginfo_class_GtkWindow_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkWindow, getTitle, arginfo_class_GtkWindow_getTitle, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWindow, setTitle, arginfo_class_GtkWindow_setTitle, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWindow, getDefaultSize, arginfo_class_GtkWindow_getDefaultSize, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWindow, setDefaultSize, arginfo_class_GtkWindow_setDefaultSize, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWindow, getSurfaceTransform, arginfo_class_GtkWindow_getSurfaceTransform, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWindow, getChild, arginfo_class_GtkWindow_getChild, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWindow, setChild, arginfo_class_GtkWindow_setChild, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWindow, present, arginfo_class_GtkWindow_present, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWindow, close, arginfo_class_GtkWindow_close, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWindow, destroy, arginfo_class_GtkWindow_destroy, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWindow, isActive, arginfo_class_GtkWindow_isActive, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWindow, getTransientFor, arginfo_class_GtkWindow_getTransientFor, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWindow, setTransientFor, arginfo_class_GtkWindow_setTransientFor, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWindow, getApplication, arginfo_class_GtkWindow_getApplication, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWindow, setApplication, arginfo_class_GtkWindow_setApplication, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWindow, getModal, arginfo_class_GtkWindow_getModal, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWindow, setModal, arginfo_class_GtkWindow_setModal, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWindow, getHideOnClose, arginfo_class_GtkWindow_getHideOnClose, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWindow, setHideOnClose, arginfo_class_GtkWindow_setHideOnClose, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkApplicationWindow_methods[] = {
	ZEND_ME(GtkApplicationWindow, new, arginfo_class_GtkApplicationWindow_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkApplicationWindow, getShowMenubar, arginfo_class_GtkApplicationWindow_getShowMenubar, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkApplicationWindow, setShowMenubar, arginfo_class_GtkApplicationWindow_setShowMenubar, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkApplicationWindow, getId, arginfo_class_GtkApplicationWindow_getId, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkAboutDialog_methods[] = {
	ZEND_ME(GtkAboutDialog, new, arginfo_class_GtkAboutDialog_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkAboutDialog, getProgramName, arginfo_class_GtkAboutDialog_getProgramName, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkAboutDialog, setProgramName, arginfo_class_GtkAboutDialog_setProgramName, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkAboutDialog, getVersion, arginfo_class_GtkAboutDialog_getVersion, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkAboutDialog, setVersion, arginfo_class_GtkAboutDialog_setVersion, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkAboutDialog, getCopyright, arginfo_class_GtkAboutDialog_getCopyright, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkAboutDialog, setCopyright, arginfo_class_GtkAboutDialog_setCopyright, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkAboutDialog, getComments, arginfo_class_GtkAboutDialog_getComments, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkAboutDialog, setComments, arginfo_class_GtkAboutDialog_setComments, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkAboutDialog, getWebsite, arginfo_class_GtkAboutDialog_getWebsite, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkAboutDialog, setWebsite, arginfo_class_GtkAboutDialog_setWebsite, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_GtkWindow(zend_class_entry *class_entry_GtkWidget)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkWindow", class_GtkWindow_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkWidget, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkApplicationWindow(zend_class_entry *class_entry_GtkWindow)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkApplicationWindow", class_GtkApplicationWindow_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkWindow, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkAboutDialog(zend_class_entry *class_entry_GtkWindow)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkAboutDialog", class_GtkAboutDialog_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkWindow, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
