#ifndef PHP_GTK_GTK_ABOUT_DIALOG_H
#define PHP_GTK_GTK_ABOUT_DIALOG_H

/*
 * GtkAboutDialog — Wave B6. Every gir
 * constructor/method/function is bound or reserved.
 */

#include "php.h"

#ifdef __cplusplus
extern "C" {
#endif

/*@zep Gtk\GtkAboutDialog new_() -> int */
zend_long phpgtk_gtkaboutdialog_new(void);
/*@zep Gtk\GtkAboutDialog addCreditSection(int handle, string sectionName, array people) -> void */
void phpgtk_gtkaboutdialog_add_credit_section(zval *handle, zval *sectionName, zval *people);
/*@zep Gtk\GtkAboutDialog getArtists(int handle) -> array */
void phpgtk_gtkaboutdialog_get_artists(zval *return_value, zval *handle);
/*@zep Gtk\GtkAboutDialog getAuthors(int handle) -> array */
void phpgtk_gtkaboutdialog_get_authors(zval *return_value, zval *handle);
/*@zep Gtk\GtkAboutDialog getComments(int handle) -> var */
void phpgtk_gtkaboutdialog_get_comments(zval *return_value, zval *handle);
/*@zep Gtk\GtkAboutDialog getCopyright(int handle) -> var */
void phpgtk_gtkaboutdialog_get_copyright(zval *return_value, zval *handle);
/*@zep Gtk\GtkAboutDialog getDocumenters(int handle) -> array */
void phpgtk_gtkaboutdialog_get_documenters(zval *return_value, zval *handle);
/*@zep Gtk\GtkAboutDialog getLicense(int handle) -> var */
void phpgtk_gtkaboutdialog_get_license(zval *return_value, zval *handle);
/*@zep Gtk\GtkAboutDialog getLicenseType(int handle) -> int */
zend_long phpgtk_gtkaboutdialog_get_license_type(zval *handle);
/*@zep Gtk\GtkAboutDialog getLogo(int handle) -> int */
zend_long phpgtk_gtkaboutdialog_get_logo(zval *handle);
/*@zep Gtk\GtkAboutDialog getLogoIconName(int handle) -> var */
void phpgtk_gtkaboutdialog_get_logo_icon_name(zval *return_value, zval *handle);
/*@zep Gtk\GtkAboutDialog getProgramName(int handle) -> var */
void phpgtk_gtkaboutdialog_get_program_name(zval *return_value, zval *handle);
/*@zep Gtk\GtkAboutDialog getSystemInformation(int handle) -> var */
void phpgtk_gtkaboutdialog_get_system_information(zval *return_value, zval *handle);
/*@zep Gtk\GtkAboutDialog getTranslatorCredits(int handle) -> var */
void phpgtk_gtkaboutdialog_get_translator_credits(zval *return_value, zval *handle);
/*@zep Gtk\GtkAboutDialog getVersion(int handle) -> var */
void phpgtk_gtkaboutdialog_get_version(zval *return_value, zval *handle);
/*@zep Gtk\GtkAboutDialog getWebsite(int handle) -> var */
void phpgtk_gtkaboutdialog_get_website(zval *return_value, zval *handle);
/*@zep Gtk\GtkAboutDialog getWebsiteLabel(int handle) -> var */
void phpgtk_gtkaboutdialog_get_website_label(zval *return_value, zval *handle);
/*@zep Gtk\GtkAboutDialog getWrapLicense(int handle) -> bool */
zend_long phpgtk_gtkaboutdialog_get_wrap_license(zval *handle);
/*@zep Gtk\GtkAboutDialog setArtists(int handle, array artists) -> void */
void phpgtk_gtkaboutdialog_set_artists(zval *handle, zval *artists);
/*@zep Gtk\GtkAboutDialog setAuthors(int handle, array authors) -> void */
void phpgtk_gtkaboutdialog_set_authors(zval *handle, zval *authors);
/*@zep Gtk\GtkAboutDialog setComments(int handle, var comments) -> void */
void phpgtk_gtkaboutdialog_set_comments(zval *handle, zval *comments);
/*@zep Gtk\GtkAboutDialog setCopyright(int handle, var copyright) -> void */
void phpgtk_gtkaboutdialog_set_copyright(zval *handle, zval *copyright);
/*@zep Gtk\GtkAboutDialog setDocumenters(int handle, array documenters) -> void */
void phpgtk_gtkaboutdialog_set_documenters(zval *handle, zval *documenters);
/*@zep Gtk\GtkAboutDialog setLicense(int handle, var license) -> void */
void phpgtk_gtkaboutdialog_set_license(zval *handle, zval *license);
/*@zep Gtk\GtkAboutDialog setLicenseType(int handle, int licenseType) -> void */
void phpgtk_gtkaboutdialog_set_license_type(zval *handle, zval *licenseType);
/*@zep Gtk\GtkAboutDialog setLogo(int handle, int logo) -> void */
void phpgtk_gtkaboutdialog_set_logo(zval *handle, zval *logo);
/*@zep Gtk\GtkAboutDialog setLogoIconName(int handle, var iconName) -> void */
void phpgtk_gtkaboutdialog_set_logo_icon_name(zval *handle, zval *iconName);
/*@zep Gtk\GtkAboutDialog setProgramName(int handle, var name) -> void */
void phpgtk_gtkaboutdialog_set_program_name(zval *handle, zval *name);
/*@zep Gtk\GtkAboutDialog setSystemInformation(int handle, var systemInformation) -> void */
void phpgtk_gtkaboutdialog_set_system_information(zval *handle, zval *systemInformation);
/*@zep Gtk\GtkAboutDialog setTranslatorCredits(int handle, var translatorCredits) -> void */
void phpgtk_gtkaboutdialog_set_translator_credits(zval *handle, zval *translatorCredits);
/*@zep Gtk\GtkAboutDialog setVersion(int handle, var version) -> void */
void phpgtk_gtkaboutdialog_set_version(zval *handle, zval *version);
/*@zep Gtk\GtkAboutDialog setWebsite(int handle, var website) -> void */
void phpgtk_gtkaboutdialog_set_website(zval *handle, zval *website);
/*@zep Gtk\GtkAboutDialog setWebsiteLabel(int handle, string websiteLabel) -> void */
void phpgtk_gtkaboutdialog_set_website_label(zval *handle, zval *websiteLabel);
/*@zep Gtk\GtkAboutDialog setWrapLicense(int handle, bool wrapLicense) -> void */
void phpgtk_gtkaboutdialog_set_wrap_license(zval *handle, zval *wrapLicense);

#ifdef __cplusplus
}
#endif

#endif /* PHP_GTK_GTK_ABOUT_DIALOG_H */
