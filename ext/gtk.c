
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



zend_class_entry *gtk_bridge_bridge_ce;
zend_class_entry *gtk_gio_gaction_gaction_ce;
zend_class_entry *gtk_gio_gactionmap_gactionmap_ce;
zend_class_entry *gtk_gio_gapplication_gapplication_ce;
zend_class_entry *gtk_gio_glistmodel_glistmodel_ce;
zend_class_entry *gtk_gio_gliststore_gliststore_ce;
zend_class_entry *gtk_gio_gmenu_gmenu_ce;
zend_class_entry *gtk_gio_gmenuitem_gmenuitem_ce;
zend_class_entry *gtk_gio_gmenumodel_gmenumodel_ce;
zend_class_entry *gtk_gio_gsimpleaction_gsimpleaction_ce;
zend_class_entry *gtk_gtk_gtkaboutdialog_gtkaboutdialog_ce;
zend_class_entry *gtk_gtk_gtkactionable_gtkactionable_ce;
zend_class_entry *gtk_gtk_gtkadjustment_gtkadjustment_ce;
zend_class_entry *gtk_gtk_gtkapplication_gtkapplication_ce;
zend_class_entry *gtk_gtk_gtkapplicationwindow_gtkapplicationwindow_ce;
zend_class_entry *gtk_gtk_gtkaspectframe_gtkaspectframe_ce;
zend_class_entry *gtk_gtk_gtkbox_gtkbox_ce;
zend_class_entry *gtk_gtk_gtkbutton_gtkbutton_ce;
zend_class_entry *gtk_gtk_gtkcenterbox_gtkcenterbox_ce;
zend_class_entry *gtk_gtk_gtkcheckbutton_gtkcheckbutton_ce;
zend_class_entry *gtk_gtk_gtkdropdown_gtkdropdown_ce;
zend_class_entry *gtk_gtk_gtkeditable_gtkeditable_ce;
zend_class_entry *gtk_gtk_gtkentry_gtkentry_ce;
zend_class_entry *gtk_gtk_gtkentrybuffer_gtkentrybuffer_ce;
zend_class_entry *gtk_gtk_gtkexpander_gtkexpander_ce;
zend_class_entry *gtk_gtk_gtkfixed_gtkfixed_ce;
zend_class_entry *gtk_gtk_gtkflowbox_gtkflowbox_ce;
zend_class_entry *gtk_gtk_gtkflowboxchild_gtkflowboxchild_ce;
zend_class_entry *gtk_gtk_gtkframe_gtkframe_ce;
zend_class_entry *gtk_gtk_gtkgrid_gtkgrid_ce;
zend_class_entry *gtk_gtk_gtkheaderbar_gtkheaderbar_ce;
zend_class_entry *gtk_gtk_gtkimage_gtkimage_ce;
zend_class_entry *gtk_gtk_gtklabel_gtklabel_ce;
zend_class_entry *gtk_gtk_gtklevelbar_gtklevelbar_ce;
zend_class_entry *gtk_gtk_gtklistbox_gtklistbox_ce;
zend_class_entry *gtk_gtk_gtklistboxrow_gtklistboxrow_ce;
zend_class_entry *gtk_gtk_gtknotebook_gtknotebook_ce;
zend_class_entry *gtk_gtk_gtknotebookpage_gtknotebookpage_ce;
zend_class_entry *gtk_gtk_gtkorientable_gtkorientable_ce;
zend_class_entry *gtk_gtk_gtkoverlay_gtkoverlay_ce;
zend_class_entry *gtk_gtk_gtkpaned_gtkpaned_ce;
zend_class_entry *gtk_gtk_gtkpasswordentry_gtkpasswordentry_ce;
zend_class_entry *gtk_gtk_gtkpicture_gtkpicture_ce;
zend_class_entry *gtk_gtk_gtkpopover_gtkpopover_ce;
zend_class_entry *gtk_gtk_gtkpopovermenu_gtkpopovermenu_ce;
zend_class_entry *gtk_gtk_gtkpopovermenubar_gtkpopovermenubar_ce;
zend_class_entry *gtk_gtk_gtkprogressbar_gtkprogressbar_ce;
zend_class_entry *gtk_gtk_gtkrange_gtkrange_ce;
zend_class_entry *gtk_gtk_gtkrevealer_gtkrevealer_ce;
zend_class_entry *gtk_gtk_gtkscale_gtkscale_ce;
zend_class_entry *gtk_gtk_gtkscrollable_gtkscrollable_ce;
zend_class_entry *gtk_gtk_gtkscrollbar_gtkscrollbar_ce;
zend_class_entry *gtk_gtk_gtkscrolledwindow_gtkscrolledwindow_ce;
zend_class_entry *gtk_gtk_gtksearchentry_gtksearchentry_ce;
zend_class_entry *gtk_gtk_gtkseparator_gtkseparator_ce;
zend_class_entry *gtk_gtk_gtkspinbutton_gtkspinbutton_ce;
zend_class_entry *gtk_gtk_gtkspinner_gtkspinner_ce;
zend_class_entry *gtk_gtk_gtkstack_gtkstack_ce;
zend_class_entry *gtk_gtk_gtkstackpage_gtkstackpage_ce;
zend_class_entry *gtk_gtk_gtkstacksidebar_gtkstacksidebar_ce;
zend_class_entry *gtk_gtk_gtkstackswitcher_gtkstackswitcher_ce;
zend_class_entry *gtk_gtk_gtkstringlist_gtkstringlist_ce;
zend_class_entry *gtk_gtk_gtkstringobject_gtkstringobject_ce;
zend_class_entry *gtk_gtk_gtkswitch_gtkswitch_ce;
zend_class_entry *gtk_gtk_gtktext_gtktext_ce;
zend_class_entry *gtk_gtk_gtktextbuffer_gtktextbuffer_ce;
zend_class_entry *gtk_gtk_gtktextmark_gtktextmark_ce;
zend_class_entry *gtk_gtk_gtktexttag_gtktexttag_ce;
zend_class_entry *gtk_gtk_gtktexttagtable_gtktexttagtable_ce;
zend_class_entry *gtk_gtk_gtktextview_gtktextview_ce;
zend_class_entry *gtk_gtk_gtktogglebutton_gtktogglebutton_ce;
zend_class_entry *gtk_gtk_gtkviewport_gtkviewport_ce;
zend_class_entry *gtk_gtk_gtkwidget_gtkwidget_ce;
zend_class_entry *gtk_gtk_gtkwindow_gtkwindow_ce;
zend_class_entry *gtk_gtk_gtkwindowcontrols_gtkwindowcontrols_ce;

ZEND_DECLARE_MODULE_GLOBALS(gtk)

PHP_INI_BEGIN()
	
PHP_INI_END()

static PHP_MINIT_FUNCTION(gtk)
{
	REGISTER_INI_ENTRIES();
	zephir_module_init();
	ZEPHIR_INIT(Gtk_Bridge_Bridge);
	ZEPHIR_INIT(Gtk_Gio_GActionMap_GActionMap);
	ZEPHIR_INIT(Gtk_Gio_GAction_GAction);
	ZEPHIR_INIT(Gtk_Gio_GApplication_GApplication);
	ZEPHIR_INIT(Gtk_Gio_GListModel_GListModel);
	ZEPHIR_INIT(Gtk_Gio_GListStore_GListStore);
	ZEPHIR_INIT(Gtk_Gio_GMenuItem_GMenuItem);
	ZEPHIR_INIT(Gtk_Gio_GMenuModel_GMenuModel);
	ZEPHIR_INIT(Gtk_Gio_GMenu_GMenu);
	ZEPHIR_INIT(Gtk_Gio_GSimpleAction_GSimpleAction);
	ZEPHIR_INIT(Gtk_Gtk_GtkAboutDialog_GtkAboutDialog);
	ZEPHIR_INIT(Gtk_Gtk_GtkActionable_GtkActionable);
	ZEPHIR_INIT(Gtk_Gtk_GtkAdjustment_GtkAdjustment);
	ZEPHIR_INIT(Gtk_Gtk_GtkApplicationWindow_GtkApplicationWindow);
	ZEPHIR_INIT(Gtk_Gtk_GtkApplication_GtkApplication);
	ZEPHIR_INIT(Gtk_Gtk_GtkAspectFrame_GtkAspectFrame);
	ZEPHIR_INIT(Gtk_Gtk_GtkBox_GtkBox);
	ZEPHIR_INIT(Gtk_Gtk_GtkButton_GtkButton);
	ZEPHIR_INIT(Gtk_Gtk_GtkCenterBox_GtkCenterBox);
	ZEPHIR_INIT(Gtk_Gtk_GtkCheckButton_GtkCheckButton);
	ZEPHIR_INIT(Gtk_Gtk_GtkDropDown_GtkDropDown);
	ZEPHIR_INIT(Gtk_Gtk_GtkEditable_GtkEditable);
	ZEPHIR_INIT(Gtk_Gtk_GtkEntryBuffer_GtkEntryBuffer);
	ZEPHIR_INIT(Gtk_Gtk_GtkEntry_GtkEntry);
	ZEPHIR_INIT(Gtk_Gtk_GtkExpander_GtkExpander);
	ZEPHIR_INIT(Gtk_Gtk_GtkFixed_GtkFixed);
	ZEPHIR_INIT(Gtk_Gtk_GtkFlowBoxChild_GtkFlowBoxChild);
	ZEPHIR_INIT(Gtk_Gtk_GtkFlowBox_GtkFlowBox);
	ZEPHIR_INIT(Gtk_Gtk_GtkFrame_GtkFrame);
	ZEPHIR_INIT(Gtk_Gtk_GtkGrid_GtkGrid);
	ZEPHIR_INIT(Gtk_Gtk_GtkHeaderBar_GtkHeaderBar);
	ZEPHIR_INIT(Gtk_Gtk_GtkImage_GtkImage);
	ZEPHIR_INIT(Gtk_Gtk_GtkLabel_GtkLabel);
	ZEPHIR_INIT(Gtk_Gtk_GtkLevelBar_GtkLevelBar);
	ZEPHIR_INIT(Gtk_Gtk_GtkListBoxRow_GtkListBoxRow);
	ZEPHIR_INIT(Gtk_Gtk_GtkListBox_GtkListBox);
	ZEPHIR_INIT(Gtk_Gtk_GtkNotebookPage_GtkNotebookPage);
	ZEPHIR_INIT(Gtk_Gtk_GtkNotebook_GtkNotebook);
	ZEPHIR_INIT(Gtk_Gtk_GtkOrientable_GtkOrientable);
	ZEPHIR_INIT(Gtk_Gtk_GtkOverlay_GtkOverlay);
	ZEPHIR_INIT(Gtk_Gtk_GtkPaned_GtkPaned);
	ZEPHIR_INIT(Gtk_Gtk_GtkPasswordEntry_GtkPasswordEntry);
	ZEPHIR_INIT(Gtk_Gtk_GtkPicture_GtkPicture);
	ZEPHIR_INIT(Gtk_Gtk_GtkPopoverMenuBar_GtkPopoverMenuBar);
	ZEPHIR_INIT(Gtk_Gtk_GtkPopoverMenu_GtkPopoverMenu);
	ZEPHIR_INIT(Gtk_Gtk_GtkPopover_GtkPopover);
	ZEPHIR_INIT(Gtk_Gtk_GtkProgressBar_GtkProgressBar);
	ZEPHIR_INIT(Gtk_Gtk_GtkRange_GtkRange);
	ZEPHIR_INIT(Gtk_Gtk_GtkRevealer_GtkRevealer);
	ZEPHIR_INIT(Gtk_Gtk_GtkScale_GtkScale);
	ZEPHIR_INIT(Gtk_Gtk_GtkScrollable_GtkScrollable);
	ZEPHIR_INIT(Gtk_Gtk_GtkScrollbar_GtkScrollbar);
	ZEPHIR_INIT(Gtk_Gtk_GtkScrolledWindow_GtkScrolledWindow);
	ZEPHIR_INIT(Gtk_Gtk_GtkSearchEntry_GtkSearchEntry);
	ZEPHIR_INIT(Gtk_Gtk_GtkSeparator_GtkSeparator);
	ZEPHIR_INIT(Gtk_Gtk_GtkSpinButton_GtkSpinButton);
	ZEPHIR_INIT(Gtk_Gtk_GtkSpinner_GtkSpinner);
	ZEPHIR_INIT(Gtk_Gtk_GtkStackPage_GtkStackPage);
	ZEPHIR_INIT(Gtk_Gtk_GtkStackSidebar_GtkStackSidebar);
	ZEPHIR_INIT(Gtk_Gtk_GtkStackSwitcher_GtkStackSwitcher);
	ZEPHIR_INIT(Gtk_Gtk_GtkStack_GtkStack);
	ZEPHIR_INIT(Gtk_Gtk_GtkStringList_GtkStringList);
	ZEPHIR_INIT(Gtk_Gtk_GtkStringObject_GtkStringObject);
	ZEPHIR_INIT(Gtk_Gtk_GtkSwitch_GtkSwitch);
	ZEPHIR_INIT(Gtk_Gtk_GtkTextBuffer_GtkTextBuffer);
	ZEPHIR_INIT(Gtk_Gtk_GtkTextMark_GtkTextMark);
	ZEPHIR_INIT(Gtk_Gtk_GtkTextTagTable_GtkTextTagTable);
	ZEPHIR_INIT(Gtk_Gtk_GtkTextTag_GtkTextTag);
	ZEPHIR_INIT(Gtk_Gtk_GtkTextView_GtkTextView);
	ZEPHIR_INIT(Gtk_Gtk_GtkText_GtkText);
	ZEPHIR_INIT(Gtk_Gtk_GtkToggleButton_GtkToggleButton);
	ZEPHIR_INIT(Gtk_Gtk_GtkViewport_GtkViewport);
	ZEPHIR_INIT(Gtk_Gtk_GtkWidget_GtkWidget);
	ZEPHIR_INIT(Gtk_Gtk_GtkWindowControls_GtkWindowControls);
	ZEPHIR_INIT(Gtk_Gtk_GtkWindow_GtkWindow);
	
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
