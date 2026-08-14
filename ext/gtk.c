
/* This file was generated automatically by Zephir do not modify it! */

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include <php.h>

#include "php_ext.h"
#include "gtk.h"

#include <ext/standard/info.h>

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/globals.h"
#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"



zend_class_entry *gtk_gtk_alertdialog_gtkalertdialog_ce;
zend_class_entry *gtk_gtk_application_gtkapplication_ce;
zend_class_entry *gtk_gtk_box_gtkbox_ce;
zend_class_entry *gtk_gtk_button_gtkbutton_ce;
zend_class_entry *gtk_gtk_centerbox_gtkcenterbox_ce;
zend_class_entry *gtk_gtk_checkbutton_gtkcheckbutton_ce;
zend_class_entry *gtk_gtk_colordialog_gtkcolordialog_ce;
zend_class_entry *gtk_gtk_dropdown_gtkdropdown_ce;
zend_class_entry *gtk_gtk_entry_gtkentry_ce;
zend_class_entry *gtk_gtk_filedialog_gtkfiledialog_ce;
zend_class_entry *gtk_gtk_fontdialog_gtkfontdialog_ce;
zend_class_entry *gtk_gtk_glarea_gtkglarea_ce;
zend_class_entry *gtk_gtk_gpupane_gtkgpupane_ce;
zend_class_entry *gtk_gtk_grid_gtkgrid_ce;
zend_class_entry *gtk_gtk_gtk_ce;
zend_class_entry *gtk_gtk_gtkerror_ce;
zend_class_entry *gtk_gtk_gtkglib_ce;
zend_class_entry *gtk_gtk_gtkswitch_gtkswitch_ce;
zend_class_entry *gtk_gtk_headerbar_gtkheaderbar_ce;
zend_class_entry *gtk_gtk_image_gtkimage_ce;
zend_class_entry *gtk_gtk_label_gtklabel_ce;
zend_class_entry *gtk_gtk_listbox_gtklistbox_ce;
zend_class_entry *gtk_gtk_listitem_gtklistitem_ce;
zend_class_entry *gtk_gtk_listview_gtklistview_ce;
zend_class_entry *gtk_gtk_menubutton_gtkmenubutton_ce;
zend_class_entry *gtk_gtk_notebook_gtknotebook_ce;
zend_class_entry *gtk_gtk_overlay_gtkoverlay_ce;
zend_class_entry *gtk_gtk_paned_gtkpaned_ce;
zend_class_entry *gtk_gtk_passwordentry_gtkpasswordentry_ce;
zend_class_entry *gtk_gtk_picture_gtkpicture_ce;
zend_class_entry *gtk_gtk_popover_gtkpopover_ce;
zend_class_entry *gtk_gtk_progressbar_gtkprogressbar_ce;
zend_class_entry *gtk_gtk_scale_gtkscale_ce;
zend_class_entry *gtk_gtk_scrolledwindow_gtkscrolledwindow_ce;
zend_class_entry *gtk_gtk_searchentry_gtksearchentry_ce;
zend_class_entry *gtk_gtk_separator_gtkseparator_ce;
zend_class_entry *gtk_gtk_singleselection_gtksingleselection_ce;
zend_class_entry *gtk_gtk_spinbutton_gtkspinbutton_ce;
zend_class_entry *gtk_gtk_spinner_gtkspinner_ce;
zend_class_entry *gtk_gtk_stack_gtkstack_ce;
zend_class_entry *gtk_gtk_stringlist_gtkstringlist_ce;
zend_class_entry *gtk_gtk_textview_gtktextview_ce;
zend_class_entry *gtk_gtk_togglebutton_gtktogglebutton_ce;
zend_class_entry *gtk_gtk_widget_gtkwidget_ce;
zend_class_entry *gtk_gtk_window_gtkwindow_ce;

ZEND_DECLARE_MODULE_GLOBALS(gtk)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(gtk)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Gtk_GTK_AlertDialog_GtkAlertDialog);
	ZEPHIR_INIT(Gtk_GTK_Application_GtkApplication);
	ZEPHIR_INIT(Gtk_GTK_Box_GtkBox);
	ZEPHIR_INIT(Gtk_GTK_Button_GtkButton);
	ZEPHIR_INIT(Gtk_GTK_CenterBox_GtkCenterBox);
	ZEPHIR_INIT(Gtk_GTK_CheckButton_GtkCheckButton);
	ZEPHIR_INIT(Gtk_GTK_ColorDialog_GtkColorDialog);
	ZEPHIR_INIT(Gtk_GTK_DropDown_GtkDropDown);
	ZEPHIR_INIT(Gtk_GTK_Entry_GtkEntry);
	ZEPHIR_INIT(Gtk_GTK_FileDialog_GtkFileDialog);
	ZEPHIR_INIT(Gtk_GTK_FontDialog_GtkFontDialog);
	ZEPHIR_INIT(Gtk_GTK_GLArea_GtkGLArea);
	ZEPHIR_INIT(Gtk_GTK_GpuPane_GtkGpuPane);
	ZEPHIR_INIT(Gtk_GTK_Grid_GtkGrid);
	ZEPHIR_INIT(Gtk_GTK_Gtk);
	ZEPHIR_INIT(Gtk_GTK_GtkError);
	ZEPHIR_INIT(Gtk_GTK_GtkGLib);
	ZEPHIR_INIT(Gtk_GTK_GtkSwitch_GtkSwitch);
	ZEPHIR_INIT(Gtk_GTK_HeaderBar_GtkHeaderBar);
	ZEPHIR_INIT(Gtk_GTK_Image_GtkImage);
	ZEPHIR_INIT(Gtk_GTK_Label_GtkLabel);
	ZEPHIR_INIT(Gtk_GTK_ListBox_GtkListBox);
	ZEPHIR_INIT(Gtk_GTK_ListItem_GtkListItem);
	ZEPHIR_INIT(Gtk_GTK_ListView_GtkListView);
	ZEPHIR_INIT(Gtk_GTK_MenuButton_GtkMenuButton);
	ZEPHIR_INIT(Gtk_GTK_Notebook_GtkNotebook);
	ZEPHIR_INIT(Gtk_GTK_Overlay_GtkOverlay);
	ZEPHIR_INIT(Gtk_GTK_Paned_GtkPaned);
	ZEPHIR_INIT(Gtk_GTK_PasswordEntry_GtkPasswordEntry);
	ZEPHIR_INIT(Gtk_GTK_Picture_GtkPicture);
	ZEPHIR_INIT(Gtk_GTK_Popover_GtkPopover);
	ZEPHIR_INIT(Gtk_GTK_ProgressBar_GtkProgressBar);
	ZEPHIR_INIT(Gtk_GTK_Scale_GtkScale);
	ZEPHIR_INIT(Gtk_GTK_ScrolledWindow_GtkScrolledWindow);
	ZEPHIR_INIT(Gtk_GTK_SearchEntry_GtkSearchEntry);
	ZEPHIR_INIT(Gtk_GTK_Separator_GtkSeparator);
	ZEPHIR_INIT(Gtk_GTK_SingleSelection_GtkSingleSelection);
	ZEPHIR_INIT(Gtk_GTK_SpinButton_GtkSpinButton);
	ZEPHIR_INIT(Gtk_GTK_Spinner_GtkSpinner);
	ZEPHIR_INIT(Gtk_GTK_Stack_GtkStack);
	ZEPHIR_INIT(Gtk_GTK_StringList_GtkStringList);
	ZEPHIR_INIT(Gtk_GTK_TextView_GtkTextView);
	ZEPHIR_INIT(Gtk_GTK_ToggleButton_GtkToggleButton);
	ZEPHIR_INIT(Gtk_GTK_Widget_GtkWidget);
	ZEPHIR_INIT(Gtk_GTK_Window_GtkWindow);
	
	return SUCCESS;
}

#ifndef ZEPHIR_RELEASE
static PHP_MSHUTDOWN_FUNCTION(gtk)
{
	
	zephir_deinitialize_memory();
	UNREGISTER_INI_ENTRIES();
	return SUCCESS;
}
#endif

/**
 * Initialize globals on each request or each thread started
 */
static void php_zephir_init_globals(zend_gtk_globals *gtk_globals)
{
	gtk_globals->initialized = 0;

	/* Cache Enabled */
	gtk_globals->cache_enabled = 1;

	/* Recursive Lock */
	gtk_globals->recursive_lock = 0;

	/* Static cache */
	memset(gtk_globals->scache, '\0', sizeof(zephir_fcall_cache_entry*) * ZEPHIR_MAX_CACHE_SLOTS);

	
	
}

/**
 * Initialize globals only on each thread started
 */
static void php_zephir_init_module_globals(zend_gtk_globals *gtk_globals)
{
	
}

static PHP_RINIT_FUNCTION(gtk)
{
	zend_gtk_globals *gtk_globals_ptr;
	gtk_globals_ptr = ZEPHIR_VGLOBAL;

	php_zephir_init_globals(gtk_globals_ptr);
	zephir_initialize_memory(gtk_globals_ptr);

	
	return SUCCESS;
}

static PHP_RSHUTDOWN_FUNCTION(gtk)
{
	
	zephir_deinitialize_memory();
	return SUCCESS;
}



static PHP_MINFO_FUNCTION(gtk)
{
	php_info_print_box_start(0);
	php_printf("%s", PHP_GTK_DESCRIPTION);
	php_info_print_box_end();

	php_info_print_table_start();
	php_info_print_table_header(2, PHP_GTK_NAME, "enabled");
	php_info_print_table_row(2, "Author", PHP_GTK_AUTHOR);
	php_info_print_table_row(2, "Version", PHP_GTK_VERSION);
	php_info_print_table_row(2, "Build Date", __DATE__ " " __TIME__ );
	php_info_print_table_row(2, "Powered by Zephir", "Version " PHP_GTK_ZEPVERSION);
	php_info_print_table_end();
	
	DISPLAY_INI_ENTRIES();
}

static PHP_GINIT_FUNCTION(gtk)
{
#if defined(COMPILE_DL_GTK) && defined(ZTS)
	ZEND_TSRMLS_CACHE_UPDATE();
#endif

	php_zephir_init_globals(gtk_globals);
	php_zephir_init_module_globals(gtk_globals);
}

static PHP_GSHUTDOWN_FUNCTION(gtk)
{
	
}


zend_function_entry php_gtk_functions[] = {
	ZEND_FE_END

};

static const zend_module_dep php_gtk_deps[] = {
	
	ZEND_MOD_END
};

zend_module_entry gtk_module_entry = {
	STANDARD_MODULE_HEADER_EX,
	NULL,
	php_gtk_deps,
	PHP_GTK_EXTNAME,
	php_gtk_functions,
	PHP_MINIT(gtk),
#ifndef ZEPHIR_RELEASE
	PHP_MSHUTDOWN(gtk),
#else
	NULL,
#endif
	PHP_RINIT(gtk),
	PHP_RSHUTDOWN(gtk),
	PHP_MINFO(gtk),
	PHP_GTK_VERSION,
	ZEND_MODULE_GLOBALS(gtk),
	PHP_GINIT(gtk),
	PHP_GSHUTDOWN(gtk),
#ifdef ZEPHIR_POST_REQUEST
	PHP_PRSHUTDOWN(gtk),
#else
	NULL,
#endif
	STANDARD_MODULE_PROPERTIES_EX
};

/* implement standard "stub" routine to introduce ourselves to Zend */
#ifdef COMPILE_DL_GTK
# ifdef ZTS
ZEND_TSRMLS_CACHE_DEFINE()
# endif
ZEND_GET_MODULE(gtk)
#endif
