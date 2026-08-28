#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "gtk-about-dialog.h"
#include "phpgtk-support.h"

zend_long phpgtk_gtkaboutdialog_new(void)
{
    return phpgtk_handle_register(gtk_about_dialog_new());
}

void phpgtk_gtkaboutdialog_add_credit_section(zval *handle, zval *sectionName, zval *people)
{
    GtkAboutDialog *self = PHPGTK_ARG_AS(GtkAboutDialog, GTK_TYPE_ABOUT_DIALOG, handle);

    if (self == NULL) {
        return;
    }

    char **peopleStrv = phpgtk_zval_to_strv(people);
    gtk_about_dialog_add_credit_section(self, phpgtk_arg_string(sectionName), (const char **) peopleStrv);
    phpgtk_strv_free(peopleStrv);
}

void phpgtk_gtkaboutdialog_get_artists(zval *return_value, zval *handle)
{
    GtkAboutDialog *self = PHPGTK_ARG_AS(GtkAboutDialog, GTK_TYPE_ABOUT_DIALOG, handle);

    if (self == NULL) {
        array_init(return_value); return;
    }

    phpgtk_ret_strv(return_value, gtk_about_dialog_get_artists(self));
}

void phpgtk_gtkaboutdialog_get_authors(zval *return_value, zval *handle)
{
    GtkAboutDialog *self = PHPGTK_ARG_AS(GtkAboutDialog, GTK_TYPE_ABOUT_DIALOG, handle);

    if (self == NULL) {
        array_init(return_value); return;
    }

    phpgtk_ret_strv(return_value, gtk_about_dialog_get_authors(self));
}

void phpgtk_gtkaboutdialog_get_comments(zval *return_value, zval *handle)
{
    GtkAboutDialog *self = PHPGTK_ARG_AS(GtkAboutDialog, GTK_TYPE_ABOUT_DIALOG, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_about_dialog_get_comments(self));
}

void phpgtk_gtkaboutdialog_get_copyright(zval *return_value, zval *handle)
{
    GtkAboutDialog *self = PHPGTK_ARG_AS(GtkAboutDialog, GTK_TYPE_ABOUT_DIALOG, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_about_dialog_get_copyright(self));
}

void phpgtk_gtkaboutdialog_get_documenters(zval *return_value, zval *handle)
{
    GtkAboutDialog *self = PHPGTK_ARG_AS(GtkAboutDialog, GTK_TYPE_ABOUT_DIALOG, handle);

    if (self == NULL) {
        array_init(return_value); return;
    }

    phpgtk_ret_strv(return_value, gtk_about_dialog_get_documenters(self));
}

void phpgtk_gtkaboutdialog_get_license(zval *return_value, zval *handle)
{
    GtkAboutDialog *self = PHPGTK_ARG_AS(GtkAboutDialog, GTK_TYPE_ABOUT_DIALOG, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_about_dialog_get_license(self));
}

zend_long phpgtk_gtkaboutdialog_get_license_type(zval *handle)
{
    GtkAboutDialog *self = PHPGTK_ARG_AS(GtkAboutDialog, GTK_TYPE_ABOUT_DIALOG, handle);

    if (self == NULL) {
        return 0;
    }

    return (zend_long) gtk_about_dialog_get_license_type(self);
}

zend_long phpgtk_gtkaboutdialog_get_logo(zval *handle)
{
    GtkAboutDialog *self = PHPGTK_ARG_AS(GtkAboutDialog, GTK_TYPE_ABOUT_DIALOG, handle);

    if (self == NULL) {
        return 0;
    }

    return phpgtk_handle_register(gtk_about_dialog_get_logo(self));
}

void phpgtk_gtkaboutdialog_get_logo_icon_name(zval *return_value, zval *handle)
{
    GtkAboutDialog *self = PHPGTK_ARG_AS(GtkAboutDialog, GTK_TYPE_ABOUT_DIALOG, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_about_dialog_get_logo_icon_name(self));
}

void phpgtk_gtkaboutdialog_get_program_name(zval *return_value, zval *handle)
{
    GtkAboutDialog *self = PHPGTK_ARG_AS(GtkAboutDialog, GTK_TYPE_ABOUT_DIALOG, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_about_dialog_get_program_name(self));
}

void phpgtk_gtkaboutdialog_get_system_information(zval *return_value, zval *handle)
{
    GtkAboutDialog *self = PHPGTK_ARG_AS(GtkAboutDialog, GTK_TYPE_ABOUT_DIALOG, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_about_dialog_get_system_information(self));
}

void phpgtk_gtkaboutdialog_get_translator_credits(zval *return_value, zval *handle)
{
    GtkAboutDialog *self = PHPGTK_ARG_AS(GtkAboutDialog, GTK_TYPE_ABOUT_DIALOG, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_about_dialog_get_translator_credits(self));
}

void phpgtk_gtkaboutdialog_get_version(zval *return_value, zval *handle)
{
    GtkAboutDialog *self = PHPGTK_ARG_AS(GtkAboutDialog, GTK_TYPE_ABOUT_DIALOG, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_about_dialog_get_version(self));
}

void phpgtk_gtkaboutdialog_get_website(zval *return_value, zval *handle)
{
    GtkAboutDialog *self = PHPGTK_ARG_AS(GtkAboutDialog, GTK_TYPE_ABOUT_DIALOG, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_about_dialog_get_website(self));
}

void phpgtk_gtkaboutdialog_get_website_label(zval *return_value, zval *handle)
{
    GtkAboutDialog *self = PHPGTK_ARG_AS(GtkAboutDialog, GTK_TYPE_ABOUT_DIALOG, handle);

    if (self == NULL) {
        ZVAL_NULL(return_value); return;
    }

    phpgtk_ret_string(return_value, gtk_about_dialog_get_website_label(self));
}

zend_long phpgtk_gtkaboutdialog_get_wrap_license(zval *handle)
{
    GtkAboutDialog *self = PHPGTK_ARG_AS(GtkAboutDialog, GTK_TYPE_ABOUT_DIALOG, handle);

    if (self == NULL) {
        return 0;
    }

    return gtk_about_dialog_get_wrap_license(self) ? 1 : 0;
}

void phpgtk_gtkaboutdialog_set_artists(zval *handle, zval *artists)
{
    GtkAboutDialog *self = PHPGTK_ARG_AS(GtkAboutDialog, GTK_TYPE_ABOUT_DIALOG, handle);

    if (self == NULL) {
        return;
    }

    char **artistsStrv = phpgtk_zval_to_strv(artists);
    gtk_about_dialog_set_artists(self, (const char **) artistsStrv);
    phpgtk_strv_free(artistsStrv);
}

void phpgtk_gtkaboutdialog_set_authors(zval *handle, zval *authors)
{
    GtkAboutDialog *self = PHPGTK_ARG_AS(GtkAboutDialog, GTK_TYPE_ABOUT_DIALOG, handle);

    if (self == NULL) {
        return;
    }

    char **authorsStrv = phpgtk_zval_to_strv(authors);
    gtk_about_dialog_set_authors(self, (const char **) authorsStrv);
    phpgtk_strv_free(authorsStrv);
}

void phpgtk_gtkaboutdialog_set_comments(zval *handle, zval *comments)
{
    GtkAboutDialog *self = PHPGTK_ARG_AS(GtkAboutDialog, GTK_TYPE_ABOUT_DIALOG, handle);

    if (self == NULL) {
        return;
    }

    gtk_about_dialog_set_comments(self, phpgtk_arg_string(comments));
}

void phpgtk_gtkaboutdialog_set_copyright(zval *handle, zval *copyright)
{
    GtkAboutDialog *self = PHPGTK_ARG_AS(GtkAboutDialog, GTK_TYPE_ABOUT_DIALOG, handle);

    if (self == NULL) {
        return;
    }

    gtk_about_dialog_set_copyright(self, phpgtk_arg_string(copyright));
}

void phpgtk_gtkaboutdialog_set_documenters(zval *handle, zval *documenters)
{
    GtkAboutDialog *self = PHPGTK_ARG_AS(GtkAboutDialog, GTK_TYPE_ABOUT_DIALOG, handle);

    if (self == NULL) {
        return;
    }

    char **documentersStrv = phpgtk_zval_to_strv(documenters);
    gtk_about_dialog_set_documenters(self, (const char **) documentersStrv);
    phpgtk_strv_free(documentersStrv);
}

void phpgtk_gtkaboutdialog_set_license(zval *handle, zval *license)
{
    GtkAboutDialog *self = PHPGTK_ARG_AS(GtkAboutDialog, GTK_TYPE_ABOUT_DIALOG, handle);

    if (self == NULL) {
        return;
    }

    gtk_about_dialog_set_license(self, phpgtk_arg_string(license));
}

void phpgtk_gtkaboutdialog_set_license_type(zval *handle, zval *licenseType)
{
    GtkAboutDialog *self = PHPGTK_ARG_AS(GtkAboutDialog, GTK_TYPE_ABOUT_DIALOG, handle);

    if (self == NULL) {
        return;
    }

    gtk_about_dialog_set_license_type(self, (GtkLicense) phpgtk_arg_long(licenseType));
}

void phpgtk_gtkaboutdialog_set_logo(zval *handle, zval *logo)
{
    GtkAboutDialog *self = PHPGTK_ARG_AS(GtkAboutDialog, GTK_TYPE_ABOUT_DIALOG, handle);

    if (self == NULL) {
        return;
    }

    gtk_about_dialog_set_logo(self, phpgtk_arg_object(logo));
}

void phpgtk_gtkaboutdialog_set_logo_icon_name(zval *handle, zval *iconName)
{
    GtkAboutDialog *self = PHPGTK_ARG_AS(GtkAboutDialog, GTK_TYPE_ABOUT_DIALOG, handle);

    if (self == NULL) {
        return;
    }

    gtk_about_dialog_set_logo_icon_name(self, phpgtk_arg_string(iconName));
}

void phpgtk_gtkaboutdialog_set_program_name(zval *handle, zval *name)
{
    GtkAboutDialog *self = PHPGTK_ARG_AS(GtkAboutDialog, GTK_TYPE_ABOUT_DIALOG, handle);

    if (self == NULL) {
        return;
    }

    gtk_about_dialog_set_program_name(self, phpgtk_arg_string(name));
}

void phpgtk_gtkaboutdialog_set_system_information(zval *handle, zval *systemInformation)
{
    GtkAboutDialog *self = PHPGTK_ARG_AS(GtkAboutDialog, GTK_TYPE_ABOUT_DIALOG, handle);

    if (self == NULL) {
        return;
    }

    gtk_about_dialog_set_system_information(self, phpgtk_arg_string(systemInformation));
}

void phpgtk_gtkaboutdialog_set_translator_credits(zval *handle, zval *translatorCredits)
{
    GtkAboutDialog *self = PHPGTK_ARG_AS(GtkAboutDialog, GTK_TYPE_ABOUT_DIALOG, handle);

    if (self == NULL) {
        return;
    }

    gtk_about_dialog_set_translator_credits(self, phpgtk_arg_string(translatorCredits));
}

void phpgtk_gtkaboutdialog_set_version(zval *handle, zval *version)
{
    GtkAboutDialog *self = PHPGTK_ARG_AS(GtkAboutDialog, GTK_TYPE_ABOUT_DIALOG, handle);

    if (self == NULL) {
        return;
    }

    gtk_about_dialog_set_version(self, phpgtk_arg_string(version));
}

void phpgtk_gtkaboutdialog_set_website(zval *handle, zval *website)
{
    GtkAboutDialog *self = PHPGTK_ARG_AS(GtkAboutDialog, GTK_TYPE_ABOUT_DIALOG, handle);

    if (self == NULL) {
        return;
    }

    gtk_about_dialog_set_website(self, phpgtk_arg_string(website));
}

void phpgtk_gtkaboutdialog_set_website_label(zval *handle, zval *websiteLabel)
{
    GtkAboutDialog *self = PHPGTK_ARG_AS(GtkAboutDialog, GTK_TYPE_ABOUT_DIALOG, handle);

    if (self == NULL) {
        return;
    }

    gtk_about_dialog_set_website_label(self, phpgtk_arg_string(websiteLabel));
}

void phpgtk_gtkaboutdialog_set_wrap_license(zval *handle, zval *wrapLicense)
{
    GtkAboutDialog *self = PHPGTK_ARG_AS(GtkAboutDialog, GTK_TYPE_ABOUT_DIALOG, handle);

    if (self == NULL) {
        return;
    }

    gtk_about_dialog_set_wrap_license(self, phpgtk_arg_bool(wrapLicense));
}

