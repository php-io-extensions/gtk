<?php
/**
 * gtk extension — headless proof (no window, no display seat required).
 *
 * Usage:
 *   php examples/proof_of_work.php
 */

declare(strict_types=1);

use Gtk\GTK\Gtk;
use Gtk\GTK\AlertDialog\GtkAlertDialog;
use Gtk\GTK\CenterBox\GtkCenterBox;
use Gtk\GTK\CheckButton\GtkCheckButton;
use Gtk\GTK\ColorDialog\GtkColorDialog;
use Gtk\GTK\DropDown\GtkDropDown;
use Gtk\GTK\Entry\GtkEntry;
use Gtk\GTK\FileDialog\GtkFileDialog;
use Gtk\GTK\FontDialog\GtkFontDialog;
use Gtk\GTK\Grid\GtkGrid;
use Gtk\GTK\GtkSwitch\GtkSwitch;
use Gtk\GTK\HeaderBar\GtkHeaderBar;
use Gtk\GTK\Image\GtkImage;
use Gtk\GTK\Label\GtkLabel;
use Gtk\GTK\ListBox\GtkListBox;
use Gtk\GTK\ListItem\GtkListItem;
use Gtk\GTK\ListView\GtkListView;
use Gtk\GTK\MenuButton\GtkMenuButton;
use Gtk\GTK\Notebook\GtkNotebook;
use Gtk\GTK\Overlay\GtkOverlay;
use Gtk\GTK\Paned\GtkPaned;
use Gtk\GTK\PasswordEntry\GtkPasswordEntry;
use Gtk\GTK\Picture\GtkPicture;
use Gtk\GTK\Popover\GtkPopover;
use Gtk\GTK\ProgressBar\GtkProgressBar;
use Gtk\GTK\Scale\GtkScale;
use Gtk\GTK\ScrolledWindow\GtkScrolledWindow;
use Gtk\GTK\SearchEntry\GtkSearchEntry;
use Gtk\GTK\Separator\GtkSeparator;
use Gtk\GTK\SingleSelection\GtkSingleSelection;
use Gtk\GTK\SpinButton\GtkSpinButton;
use Gtk\GTK\Spinner\GtkSpinner;
use Gtk\GTK\Stack\GtkStack;
use Gtk\GTK\StringList\GtkStringList;
use Gtk\GTK\TextView\GtkTextView;
use Gtk\GTK\ToggleButton\GtkToggleButton;

function pass(string $label): void
{
    echo "  [PASS] {$label}\n";
}

function fail(string $label, string $detail = ''): void
{
    $msg = "  [FAIL] {$label}";
    if ($detail !== '') {
        $msg .= ": {$detail}";
    }
    echo $msg . "\n";
}

echo "gtk extension proof-of-work\n";

if (! extension_loaded('gtk')) {
    fail('extension_loaded(gtk)');
    exit(1);
}
pass('extension_loaded(gtk)');

$major = Gtk::gtkGetMajorVersion();
$minor = Gtk::gtkGetMinorVersion();
$micro = Gtk::gtkGetMicroVersion();

if ($major < 4) {
    fail('gtkGetMajorVersion', (string) $major);
    exit(1);
}
pass("gtk version {$major}.{$minor}.{$micro}");

$classes = [
    GtkAlertDialog::class => ['gtkAlertDialogNew', 'gtkAlertDialogSetDetail', 'gtkAlertDialogSetButtons', 'gtkAlertDialogSetModal', 'gtkAlertDialogShow', 'gtkAlertDialogChoose'],
    GtkCenterBox::class => ['gtkCenterBoxNew', 'gtkCenterBoxSetStartWidget', 'gtkCenterBoxSetCenterWidget', 'gtkCenterBoxSetEndWidget', 'gtkCenterBoxGetStartWidget', 'gtkCenterBoxGetCenterWidget', 'gtkCenterBoxGetEndWidget'],
    GtkCheckButton::class => ['gtkCheckButtonNew', 'gtkCheckButtonNewWithLabel', 'gtkCheckButtonSetLabel', 'gtkCheckButtonGetLabel', 'gtkCheckButtonSetActive', 'gtkCheckButtonGetActive'],
    GtkColorDialog::class => ['gtkColorDialogNew', 'gtkColorDialogSetTitle', 'gtkColorDialogSetModal', 'gtkColorDialogChooseRgba'],
    GtkDropDown::class => ['gtkDropDownNewFromStrings', 'gtkDropDownSetSelected', 'gtkDropDownGetSelected'],
    GtkEntry::class => ['gtkEntryNew', 'gtkEntrySetText', 'gtkEntryGetText', 'gtkEntrySetPlaceholderText', 'gtkEntryGetPlaceholderText', 'gtkEntrySetVisibility', 'gtkEntryGetVisibility'],
    GtkFileDialog::class => ['gtkFileDialogNew', 'gtkFileDialogSetTitle', 'gtkFileDialogGetTitle', 'gtkFileDialogSetInitialName', 'gtkFileDialogOpen', 'gtkFileDialogSave', 'gtkFileDialogSelectFolder'],
    GtkFontDialog::class => ['gtkFontDialogNew', 'gtkFontDialogSetTitle', 'gtkFontDialogSetModal', 'gtkFontDialogChooseFont'],
    GtkGrid::class => ['gtkGridNew', 'gtkGridAttach', 'gtkGridRemove', 'gtkGridSetRowSpacing', 'gtkGridSetColumnSpacing', 'gtkGridSetRowHomogeneous', 'gtkGridSetColumnHomogeneous'],
    GtkSwitch::class => ['gtkSwitchNew', 'gtkSwitchSetActive', 'gtkSwitchGetActive'],
    GtkHeaderBar::class => ['gtkHeaderBarNew', 'gtkHeaderBarSetTitleWidget', 'gtkHeaderBarGetTitleWidget', 'gtkHeaderBarPackStart', 'gtkHeaderBarPackEnd', 'gtkHeaderBarRemove', 'gtkHeaderBarSetShowTitleButtons', 'gtkHeaderBarGetShowTitleButtons'],
    GtkImage::class => ['gtkImageNew', 'gtkImageNewFromFile', 'gtkImageSetFromFile', 'gtkImageSetFromIconName', 'gtkImageClear', 'gtkImageSetPixelSize'],
    GtkLabel::class => ['gtkLabelNew', 'gtkLabelSetText', 'gtkLabelGetText'],
    GtkListBox::class => ['gtkListBoxNew', 'gtkListBoxAppend', 'gtkListBoxRemove', 'gtkListBoxGetSelectedRow', 'gtkListBoxSelectRow', 'gtkListBoxGetRowAtIndex', 'gtkListBoxRowGetIndex', 'gtkListBoxRowGetChild'],
    GtkListItem::class => ['gtkSignalListItemFactoryNew', 'gtkListItemSetChild', 'gtkListItemGetChild', 'gtkListItemGetItem', 'gtkListItemGetPosition'],
    GtkListView::class => ['gtkListViewNew', 'gtkListViewSetModel', 'gtkListViewGetModel', 'gtkListViewSetFactory'],
    GtkMenuButton::class => ['gtkMenuButtonNew', 'gtkMenuButtonSetLabel', 'gtkMenuButtonGetLabel', 'gtkMenuButtonSetPopover', 'gtkMenuButtonGetPopover', 'gtkMenuButtonPopup', 'gtkMenuButtonPopdown'],
    GtkNotebook::class => ['gtkNotebookNew', 'gtkNotebookAppendPage', 'gtkNotebookRemovePage', 'gtkNotebookGetNPages', 'gtkNotebookSetCurrentPage', 'gtkNotebookGetCurrentPage', 'gtkNotebookSetTabLabelText'],
    GtkOverlay::class => ['gtkOverlayNew', 'gtkOverlaySetChild', 'gtkOverlayGetChild', 'gtkOverlayAddOverlay', 'gtkOverlayRemoveOverlay'],
    GtkPaned::class => ['gtkPanedNew', 'gtkPanedSetStartChild', 'gtkPanedSetEndChild', 'gtkPanedGetStartChild', 'gtkPanedGetEndChild', 'gtkPanedSetPosition', 'gtkPanedGetPosition'],
    GtkPasswordEntry::class => ['gtkPasswordEntryNew', 'gtkPasswordEntrySetText', 'gtkPasswordEntryGetText', 'gtkPasswordEntrySetShowPeekIcon', 'gtkPasswordEntryGetShowPeekIcon'],
    GtkPicture::class => ['gtkPictureNew', 'gtkPictureNewForFilename', 'gtkPictureSetFilename', 'gtkPictureSetCanShrink'],
    GtkPopover::class => ['gtkPopoverNew', 'gtkPopoverSetChild', 'gtkPopoverGetChild', 'gtkPopoverPopup', 'gtkPopoverPopdown', 'gtkPopoverSetAutohide'],
    GtkProgressBar::class => ['gtkProgressBarNew', 'gtkProgressBarSetFraction', 'gtkProgressBarGetFraction', 'gtkProgressBarSetText', 'gtkProgressBarGetText', 'gtkProgressBarSetShowText', 'gtkProgressBarPulse'],
    GtkScale::class => ['gtkScaleNewWithRange', 'gtkScaleSetValue', 'gtkScaleGetValue', 'gtkScaleSetDrawValue', 'gtkScaleSetDigits'],
    GtkScrolledWindow::class => ['gtkScrolledWindowNew', 'gtkScrolledWindowSetChild', 'gtkScrolledWindowGetChild', 'gtkScrolledWindowSetPolicy', 'gtkScrolledWindowSetMinContentHeight', 'gtkScrolledWindowSetMinContentWidth'],
    GtkSearchEntry::class => ['gtkSearchEntryNew', 'gtkSearchEntrySetText', 'gtkSearchEntryGetText'],
    GtkSeparator::class => ['gtkSeparatorNew'],
    GtkSingleSelection::class => ['gtkSingleSelectionNew', 'gtkSingleSelectionSetSelected', 'gtkSingleSelectionGetSelected', 'gtkSingleSelectionGetModel'],
    GtkSpinButton::class => ['gtkSpinButtonNewWithRange', 'gtkSpinButtonSetValue', 'gtkSpinButtonGetValue', 'gtkSpinButtonGetValueAsInt', 'gtkSpinButtonSetDigits'],
    GtkSpinner::class => ['gtkSpinnerNew', 'gtkSpinnerStart', 'gtkSpinnerStop', 'gtkSpinnerSetSpinning', 'gtkSpinnerGetSpinning'],
    GtkStack::class => ['gtkStackNew', 'gtkStackAddChild', 'gtkStackAddTitled', 'gtkStackRemove', 'gtkStackSetVisibleChild', 'gtkStackGetVisibleChild', 'gtkStackSetVisibleChildName', 'gtkStackGetVisibleChildName'],
    GtkStringList::class => ['gtkStringListNew', 'gtkStringListAppend', 'gtkStringListRemove', 'gtkStringListGetString', 'gtkStringListGetNItems', 'gtkStringObjectGetString'],
    GtkTextView::class => ['gtkTextViewNew', 'gtkTextViewGetBuffer', 'gtkTextViewSetText', 'gtkTextViewGetText', 'gtkTextViewSetEditable', 'gtkTextViewGetEditable', 'gtkTextViewSetWrapMode', 'gtkTextViewGetWrapMode'],
    GtkToggleButton::class => ['gtkToggleButtonNew', 'gtkToggleButtonNewWithLabel', 'gtkToggleButtonSetActive', 'gtkToggleButtonGetActive', 'gtkToggleButtonSetLabel', 'gtkToggleButtonGetLabel'],
];

foreach ($classes as $class => $methods) {
    if (! class_exists($class)) {
        fail('class_exists', $class);
        exit(1);
    }
    pass('class_exists '.$class);
    foreach ($methods as $method) {
        if (! method_exists($class, $method)) {
            fail('method_exists', $class.'::'.$method);
            exit(1);
        }
        pass($class.'::'.$method);
    }
}

echo "\nOK\n";
exit(0);
