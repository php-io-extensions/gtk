/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: d28c84cec27e40871130ec6b3768931158e32698 */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GFile_newForPath, 0, 1, GFile, 0)
	ZEND_ARG_TYPE_INFO(0, path, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GFile_getPath, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GListStore_new, 0, 1, GListStore, 1)
	ZEND_ARG_TYPE_INFO(0, itemType, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GListStore_append, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, item, GObject, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkClipboard_setText, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkClipboard_readTextAsync, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, cancellable, GCancellable, 1)
	ZEND_ARG_TYPE_INFO(0, callback, IS_CALLABLE, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkClipboard_readTextFinish, 0, 1, IS_STRING, 1)
	ZEND_ARG_OBJ_INFO(0, result, GAsyncResult, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GdkClipboard_getFormats, 0, 0, GdkContentFormats, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_GdkContentFormats___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkContentFormats_containMimeType, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, mimeType, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkFileFilter_new, 0, 0, GtkFileFilter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkFileFilter_setName, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkFileFilter_getName arginfo_class_GFile_getPath

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkFileFilter_addPattern, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, pattern, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkAlertDialog_setMessage, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, message, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkAlertDialog_setDetail, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, detail, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkAlertDialog_setButtons, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, labels, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkAlertDialog_setDefaultButton, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, button, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkAlertDialog_setCancelButton arginfo_class_GtkAlertDialog_setDefaultButton

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkAlertDialog_setModal, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, modal, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkAlertDialog_choose, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, parent, GtkWindow, 1)
	ZEND_ARG_OBJ_INFO(0, cancellable, GCancellable, 1)
	ZEND_ARG_TYPE_INFO(0, callback, IS_CALLABLE, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkAlertDialog_chooseFinish, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, result, GAsyncResult, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkFileDialog_new, 0, 0, GtkFileDialog, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkFileDialog_setTitle, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, title, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkFileDialog_setInitialFolder, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, folder, GFile, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkFileDialog_setInitialName arginfo_class_GtkFileFilter_setName

#define arginfo_class_GtkFileDialog_setModal arginfo_class_GtkAlertDialog_setModal

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkFileDialog_setFilters, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, filters, GListModel, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkFileDialog_getFilters, 0, 0, GListModel, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkFileDialog_open arginfo_class_GtkAlertDialog_choose

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkFileDialog_openFinish, 0, 1, GFile, 0)
	ZEND_ARG_OBJ_INFO(0, result, GAsyncResult, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkFileDialog_openMultiple arginfo_class_GtkAlertDialog_choose

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkFileDialog_openMultipleFinish, 0, 1, GListModel, 0)
	ZEND_ARG_OBJ_INFO(0, result, GAsyncResult, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkFileDialog_selectFolder arginfo_class_GtkAlertDialog_choose

#define arginfo_class_GtkFileDialog_selectFolderFinish arginfo_class_GtkFileDialog_openFinish

#define arginfo_class_GtkFileDialog_save arginfo_class_GtkAlertDialog_choose

#define arginfo_class_GtkFileDialog_saveFinish arginfo_class_GtkFileDialog_openFinish

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkFileLauncher_new, 0, 1, GtkFileLauncher, 0)
	ZEND_ARG_OBJ_INFO(0, file, GFile, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkFileLauncher_launch arginfo_class_GtkAlertDialog_choose

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkFileLauncher_launchFinish, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, result, GAsyncResult, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(GFile, newForPath);
ZEND_METHOD(GFile, getPath);
ZEND_METHOD(GListStore, new);
ZEND_METHOD(GListStore, append);
ZEND_METHOD(GdkClipboard, setText);
ZEND_METHOD(GdkClipboard, readTextAsync);
ZEND_METHOD(GdkClipboard, readTextFinish);
ZEND_METHOD(GdkClipboard, getFormats);
ZEND_METHOD(GdkContentFormats, __construct);
ZEND_METHOD(GdkContentFormats, containMimeType);
ZEND_METHOD(GtkFileFilter, new);
ZEND_METHOD(GtkFileFilter, setName);
ZEND_METHOD(GtkFileFilter, getName);
ZEND_METHOD(GtkFileFilter, addPattern);
ZEND_METHOD(GtkAlertDialog, setMessage);
ZEND_METHOD(GtkAlertDialog, setDetail);
ZEND_METHOD(GtkAlertDialog, setButtons);
ZEND_METHOD(GtkAlertDialog, setDefaultButton);
ZEND_METHOD(GtkAlertDialog, setCancelButton);
ZEND_METHOD(GtkAlertDialog, setModal);
ZEND_METHOD(GtkAlertDialog, choose);
ZEND_METHOD(GtkAlertDialog, chooseFinish);
ZEND_METHOD(GtkFileDialog, new);
ZEND_METHOD(GtkFileDialog, setTitle);
ZEND_METHOD(GtkFileDialog, setInitialFolder);
ZEND_METHOD(GtkFileDialog, setInitialName);
ZEND_METHOD(GtkFileDialog, setModal);
ZEND_METHOD(GtkFileDialog, setFilters);
ZEND_METHOD(GtkFileDialog, getFilters);
ZEND_METHOD(GtkFileDialog, open);
ZEND_METHOD(GtkFileDialog, openFinish);
ZEND_METHOD(GtkFileDialog, openMultiple);
ZEND_METHOD(GtkFileDialog, openMultipleFinish);
ZEND_METHOD(GtkFileDialog, selectFolder);
ZEND_METHOD(GtkFileDialog, selectFolderFinish);
ZEND_METHOD(GtkFileDialog, save);
ZEND_METHOD(GtkFileDialog, saveFinish);
ZEND_METHOD(GtkFileLauncher, new);
ZEND_METHOD(GtkFileLauncher, launch);
ZEND_METHOD(GtkFileLauncher, launchFinish);

static const zend_function_entry class_GFile_methods[] = {
	ZEND_ME(GFile, newForPath, arginfo_class_GFile_newForPath, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GFile, getPath, arginfo_class_GFile_getPath, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GListStore_methods[] = {
	ZEND_ME(GListStore, new, arginfo_class_GListStore_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GListStore, append, arginfo_class_GListStore_append, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GdkClipboard_methods[] = {
	ZEND_ME(GdkClipboard, setText, arginfo_class_GdkClipboard_setText, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkClipboard, readTextAsync, arginfo_class_GdkClipboard_readTextAsync, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkClipboard, readTextFinish, arginfo_class_GdkClipboard_readTextFinish, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkClipboard, getFormats, arginfo_class_GdkClipboard_getFormats, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GdkContentFormats_methods[] = {
	ZEND_ME(GdkContentFormats, __construct, arginfo_class_GdkContentFormats___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(GdkContentFormats, containMimeType, arginfo_class_GdkContentFormats_containMimeType, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkFileFilter_methods[] = {
	ZEND_ME(GtkFileFilter, new, arginfo_class_GtkFileFilter_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkFileFilter, setName, arginfo_class_GtkFileFilter_setName, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkFileFilter, getName, arginfo_class_GtkFileFilter_getName, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkFileFilter, addPattern, arginfo_class_GtkFileFilter_addPattern, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkAlertDialog_methods[] = {
	ZEND_ME(GtkAlertDialog, setMessage, arginfo_class_GtkAlertDialog_setMessage, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkAlertDialog, setDetail, arginfo_class_GtkAlertDialog_setDetail, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkAlertDialog, setButtons, arginfo_class_GtkAlertDialog_setButtons, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkAlertDialog, setDefaultButton, arginfo_class_GtkAlertDialog_setDefaultButton, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkAlertDialog, setCancelButton, arginfo_class_GtkAlertDialog_setCancelButton, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkAlertDialog, setModal, arginfo_class_GtkAlertDialog_setModal, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkAlertDialog, choose, arginfo_class_GtkAlertDialog_choose, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkAlertDialog, chooseFinish, arginfo_class_GtkAlertDialog_chooseFinish, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkFileDialog_methods[] = {
	ZEND_ME(GtkFileDialog, new, arginfo_class_GtkFileDialog_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkFileDialog, setTitle, arginfo_class_GtkFileDialog_setTitle, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkFileDialog, setInitialFolder, arginfo_class_GtkFileDialog_setInitialFolder, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkFileDialog, setInitialName, arginfo_class_GtkFileDialog_setInitialName, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkFileDialog, setModal, arginfo_class_GtkFileDialog_setModal, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkFileDialog, setFilters, arginfo_class_GtkFileDialog_setFilters, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkFileDialog, getFilters, arginfo_class_GtkFileDialog_getFilters, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkFileDialog, open, arginfo_class_GtkFileDialog_open, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkFileDialog, openFinish, arginfo_class_GtkFileDialog_openFinish, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkFileDialog, openMultiple, arginfo_class_GtkFileDialog_openMultiple, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkFileDialog, openMultipleFinish, arginfo_class_GtkFileDialog_openMultipleFinish, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkFileDialog, selectFolder, arginfo_class_GtkFileDialog_selectFolder, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkFileDialog, selectFolderFinish, arginfo_class_GtkFileDialog_selectFolderFinish, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkFileDialog, save, arginfo_class_GtkFileDialog_save, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkFileDialog, saveFinish, arginfo_class_GtkFileDialog_saveFinish, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkFileLauncher_methods[] = {
	ZEND_ME(GtkFileLauncher, new, arginfo_class_GtkFileLauncher_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkFileLauncher, launch, arginfo_class_GtkFileLauncher_launch, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkFileLauncher, launchFinish, arginfo_class_GtkFileLauncher_launchFinish, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_GFile(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GFile", class_GFile_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GListStore(zend_class_entry *class_entry_GObject, zend_class_entry *class_entry_GListModel)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GListStore", class_GListStore_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);
	zend_class_implements(class_entry, 1, class_entry_GListModel);

	return class_entry;
}

static zend_class_entry *register_class_GdkClipboard(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GdkClipboard", class_GdkClipboard_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GdkContentFormats(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GdkContentFormats", class_GdkContentFormats_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkFileFilter(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkFileFilter", class_GtkFileFilter_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkAlertDialog(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkAlertDialog", class_GtkAlertDialog_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkFileDialog(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkFileDialog", class_GtkFileDialog_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkFileLauncher(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkFileLauncher", class_GtkFileLauncher_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
