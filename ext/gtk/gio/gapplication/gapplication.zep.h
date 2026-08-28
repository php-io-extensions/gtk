
extern zend_class_entry *gtk_gio_gapplication_gapplication_ce;

ZEPHIR_INIT_CLASS(Gtk_Gio_GApplication_GApplication);

PHP_METHOD(Gtk_Gio_GApplication_GApplication, new_);
PHP_METHOD(Gtk_Gio_GApplication_GApplication, getDefault);
PHP_METHOD(Gtk_Gio_GApplication_GApplication, idIsValid);
PHP_METHOD(Gtk_Gio_GApplication_GApplication, activate);
PHP_METHOD(Gtk_Gio_GApplication_GApplication, addMainOption);
PHP_METHOD(Gtk_Gio_GApplication_GApplication, getApplicationId);
PHP_METHOD(Gtk_Gio_GApplication_GApplication, getDbusConnection);
PHP_METHOD(Gtk_Gio_GApplication_GApplication, getDbusObjectPath);
PHP_METHOD(Gtk_Gio_GApplication_GApplication, getFlags);
PHP_METHOD(Gtk_Gio_GApplication_GApplication, getInactivityTimeout);
PHP_METHOD(Gtk_Gio_GApplication_GApplication, getIsBusy);
PHP_METHOD(Gtk_Gio_GApplication_GApplication, getIsRegistered);
PHP_METHOD(Gtk_Gio_GApplication_GApplication, getIsRemote);
PHP_METHOD(Gtk_Gio_GApplication_GApplication, getResourceBasePath);
PHP_METHOD(Gtk_Gio_GApplication_GApplication, getVersion);
PHP_METHOD(Gtk_Gio_GApplication_GApplication, hold);
PHP_METHOD(Gtk_Gio_GApplication_GApplication, markBusy);
PHP_METHOD(Gtk_Gio_GApplication_GApplication, open);
PHP_METHOD(Gtk_Gio_GApplication_GApplication, quit);
PHP_METHOD(Gtk_Gio_GApplication_GApplication, release);
PHP_METHOD(Gtk_Gio_GApplication_GApplication, run);
PHP_METHOD(Gtk_Gio_GApplication_GApplication, sendNotification);
PHP_METHOD(Gtk_Gio_GApplication_GApplication, setApplicationId);
PHP_METHOD(Gtk_Gio_GApplication_GApplication, setDefault);
PHP_METHOD(Gtk_Gio_GApplication_GApplication, setFlags);
PHP_METHOD(Gtk_Gio_GApplication_GApplication, setInactivityTimeout);
PHP_METHOD(Gtk_Gio_GApplication_GApplication, setOptionContextDescription);
PHP_METHOD(Gtk_Gio_GApplication_GApplication, setOptionContextParameterString);
PHP_METHOD(Gtk_Gio_GApplication_GApplication, setOptionContextSummary);
PHP_METHOD(Gtk_Gio_GApplication_GApplication, setResourceBasePath);
PHP_METHOD(Gtk_Gio_GApplication_GApplication, setVersion);
PHP_METHOD(Gtk_Gio_GApplication_GApplication, unmarkBusy);
PHP_METHOD(Gtk_Gio_GApplication_GApplication, withdrawNotification);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gapplication_gapplication_new_, 0, 2, IS_LONG, 0)
	ZEND_ARG_INFO(0, applicationId)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gapplication_gapplication_getdefault, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gapplication_gapplication_idisvalid, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, applicationId, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gapplication_gapplication_activate, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gapplication_gapplication_addmainoption, 0, 7, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, longName, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, shortName, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, arg, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, description, IS_STRING, 0)
	ZEND_ARG_INFO(0, argDescription)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gio_gapplication_gapplication_getapplicationid, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gapplication_gapplication_getdbusconnection, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gio_gapplication_gapplication_getdbusobjectpath, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gapplication_gapplication_getflags, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gapplication_gapplication_getinactivitytimeout, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gapplication_gapplication_getisbusy, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gapplication_gapplication_getisregistered, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gapplication_gapplication_getisremote, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gio_gapplication_gapplication_getresourcebasepath, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gio_gapplication_gapplication_getversion, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gapplication_gapplication_hold, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gapplication_gapplication_markbusy, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gapplication_gapplication_open, 0, 4, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, files, 0)
	ZEND_ARG_TYPE_INFO(0, nFiles, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, hint, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gapplication_gapplication_quit, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gapplication_gapplication_release, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gapplication_gapplication_run, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, argc, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, argv, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gapplication_gapplication_sendnotification, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, id)
	ZEND_ARG_TYPE_INFO(0, notification, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gapplication_gapplication_setapplicationid, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, applicationId)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gapplication_gapplication_setdefault, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gapplication_gapplication_setflags, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gapplication_gapplication_setinactivitytimeout, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, inactivityTimeout, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gapplication_gapplication_setoptioncontextdescription, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, description)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gapplication_gapplication_setoptioncontextparameterstring, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, parameterString)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gapplication_gapplication_setoptioncontextsummary, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, summary)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gapplication_gapplication_setresourcebasepath, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, resourcePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gapplication_gapplication_setversion, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, version, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gapplication_gapplication_unmarkbusy, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gio_gapplication_gapplication_withdrawnotification, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, id, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gio_gapplication_gapplication_method_entry) {
	PHP_ME(Gtk_Gio_GApplication_GApplication, new_, arginfo_gtk_gio_gapplication_gapplication_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GApplication_GApplication, getDefault, arginfo_gtk_gio_gapplication_gapplication_getdefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GApplication_GApplication, idIsValid, arginfo_gtk_gio_gapplication_gapplication_idisvalid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GApplication_GApplication, activate, arginfo_gtk_gio_gapplication_gapplication_activate, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GApplication_GApplication, addMainOption, arginfo_gtk_gio_gapplication_gapplication_addmainoption, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GApplication_GApplication, getApplicationId, arginfo_gtk_gio_gapplication_gapplication_getapplicationid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GApplication_GApplication, getDbusConnection, arginfo_gtk_gio_gapplication_gapplication_getdbusconnection, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GApplication_GApplication, getDbusObjectPath, arginfo_gtk_gio_gapplication_gapplication_getdbusobjectpath, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GApplication_GApplication, getFlags, arginfo_gtk_gio_gapplication_gapplication_getflags, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GApplication_GApplication, getInactivityTimeout, arginfo_gtk_gio_gapplication_gapplication_getinactivitytimeout, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GApplication_GApplication, getIsBusy, arginfo_gtk_gio_gapplication_gapplication_getisbusy, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GApplication_GApplication, getIsRegistered, arginfo_gtk_gio_gapplication_gapplication_getisregistered, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GApplication_GApplication, getIsRemote, arginfo_gtk_gio_gapplication_gapplication_getisremote, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GApplication_GApplication, getResourceBasePath, arginfo_gtk_gio_gapplication_gapplication_getresourcebasepath, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GApplication_GApplication, getVersion, arginfo_gtk_gio_gapplication_gapplication_getversion, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GApplication_GApplication, hold, arginfo_gtk_gio_gapplication_gapplication_hold, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GApplication_GApplication, markBusy, arginfo_gtk_gio_gapplication_gapplication_markbusy, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GApplication_GApplication, open, arginfo_gtk_gio_gapplication_gapplication_open, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GApplication_GApplication, quit, arginfo_gtk_gio_gapplication_gapplication_quit, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GApplication_GApplication, release, arginfo_gtk_gio_gapplication_gapplication_release, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GApplication_GApplication, run, arginfo_gtk_gio_gapplication_gapplication_run, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GApplication_GApplication, sendNotification, arginfo_gtk_gio_gapplication_gapplication_sendnotification, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GApplication_GApplication, setApplicationId, arginfo_gtk_gio_gapplication_gapplication_setapplicationid, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GApplication_GApplication, setDefault, arginfo_gtk_gio_gapplication_gapplication_setdefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GApplication_GApplication, setFlags, arginfo_gtk_gio_gapplication_gapplication_setflags, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GApplication_GApplication, setInactivityTimeout, arginfo_gtk_gio_gapplication_gapplication_setinactivitytimeout, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GApplication_GApplication, setOptionContextDescription, arginfo_gtk_gio_gapplication_gapplication_setoptioncontextdescription, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GApplication_GApplication, setOptionContextParameterString, arginfo_gtk_gio_gapplication_gapplication_setoptioncontextparameterstring, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GApplication_GApplication, setOptionContextSummary, arginfo_gtk_gio_gapplication_gapplication_setoptioncontextsummary, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GApplication_GApplication, setResourceBasePath, arginfo_gtk_gio_gapplication_gapplication_setresourcebasepath, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GApplication_GApplication, setVersion, arginfo_gtk_gio_gapplication_gapplication_setversion, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GApplication_GApplication, unmarkBusy, arginfo_gtk_gio_gapplication_gapplication_unmarkbusy, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gio_GApplication_GApplication, withdrawNotification, arginfo_gtk_gio_gapplication_gapplication_withdrawnotification, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
