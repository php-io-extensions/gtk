
extern zend_class_entry *gtk_gtk_gtkaboutdialog_gtkaboutdialog_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog);

PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, new_);
PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, addCreditSection);
PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, getArtists);
PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, getAuthors);
PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, getComments);
PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, getCopyright);
PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, getDocumenters);
PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, getLicense);
PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, getLicenseType);
PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, getLogo);
PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, getLogoIconName);
PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, getProgramName);
PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, getSystemInformation);
PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, getTranslatorCredits);
PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, getVersion);
PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, getWebsite);
PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, getWebsiteLabel);
PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, getWrapLicense);
PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, setArtists);
PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, setAuthors);
PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, setComments);
PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, setCopyright);
PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, setDocumenters);
PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, setLicense);
PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, setLicenseType);
PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, setLogo);
PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, setLogoIconName);
PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, setProgramName);
PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, setSystemInformation);
PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, setTranslatorCredits);
PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, setVersion);
PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, setWebsite);
PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, setWebsiteLabel);
PHP_METHOD(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, setWrapLicense);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_addcreditsection, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, sectionName, IS_STRING, 0)
	ZEND_ARG_ARRAY_INFO(0, people, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_getartists, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_getauthors, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_getcomments, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_getcopyright, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_getdocumenters, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_getlicense, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_getlicensetype, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_getlogo, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_getlogoiconname, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_getprogramname, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_getsysteminformation, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_gettranslatorcredits, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_getversion, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_getwebsite, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_getwebsitelabel, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_getwraplicense, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_setartists, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, artists, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_setauthors, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, authors, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_setcomments, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, comments)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_setcopyright, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, copyright)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_setdocumenters, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_ARRAY_INFO(0, documenters, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_setlicense, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, license)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_setlicensetype, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, licenseType, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_setlogo, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, logo, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_setlogoiconname, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, iconName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_setprogramname, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, name)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_setsysteminformation, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, systemInformation)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_settranslatorcredits, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, translatorCredits)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_setversion, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, version)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_setwebsite, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, website)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_setwebsitelabel, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, websiteLabel, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_setwraplicense, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, wrapLicense, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkaboutdialog_gtkaboutdialog_method_entry) {
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, new_, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, addCreditSection, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_addcreditsection, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, getArtists, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_getartists, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, getAuthors, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_getauthors, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, getComments, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_getcomments, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, getCopyright, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_getcopyright, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, getDocumenters, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_getdocumenters, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, getLicense, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_getlicense, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, getLicenseType, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_getlicensetype, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, getLogo, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_getlogo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, getLogoIconName, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_getlogoiconname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, getProgramName, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_getprogramname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, getSystemInformation, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_getsysteminformation, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, getTranslatorCredits, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_gettranslatorcredits, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, getVersion, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_getversion, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, getWebsite, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_getwebsite, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, getWebsiteLabel, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_getwebsitelabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, getWrapLicense, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_getwraplicense, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, setArtists, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_setartists, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, setAuthors, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_setauthors, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, setComments, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_setcomments, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, setCopyright, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_setcopyright, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, setDocumenters, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_setdocumenters, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, setLicense, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_setlicense, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, setLicenseType, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_setlicensetype, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, setLogo, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_setlogo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, setLogoIconName, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_setlogoiconname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, setProgramName, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_setprogramname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, setSystemInformation, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_setsysteminformation, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, setTranslatorCredits, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_settranslatorcredits, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, setVersion, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_setversion, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, setWebsite, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_setwebsite, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, setWebsiteLabel, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_setwebsitelabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog, setWrapLicense, arginfo_gtk_gtk_gtkaboutdialog_gtkaboutdialog_setwraplicense, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
