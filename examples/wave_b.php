<?php
/*
 * Wave B demo: every Wave B class proven live against real GTK in one scene.
 * 28 constructible classes are built directly; the seven non-constructibles
 * are exercised through their homes — GListModel via GtkStringList/GListStore,
 * GAction via GSimpleAction, GActionMap via GtkApplicationWindow, GMenuModel
 * via GMenu, GtkActionable via GtkButton, GtkNotebookPage via
 * GtkNotebook::getPage, GtkStackPage via GtkStack::getPage.
 *
 * Needs the box's logged-in seat. Prints WAVE_B_OK when everything held.
 *
 * Run on the Linux box: php examples/wave_b.php
 */

declare(strict_types=1);

use Gtk\Bridge\Bridge;
use Gtk\Gio\GAction\GAction;
use Gtk\Gio\GActionMap\GActionMap;
use Gtk\Gio\GListModel\GListModel;
use Gtk\Gio\GListStore\GListStore;
use Gtk\Gio\GMenu\GMenu;
use Gtk\Gio\GMenuItem\GMenuItem;
use Gtk\Gio\GMenuModel\GMenuModel;
use Gtk\Gio\GSimpleAction\GSimpleAction;
use Gtk\Gtk\GtkAboutDialog\GtkAboutDialog;
use Gtk\Gtk\GtkActionable\GtkActionable;
use Gtk\Gtk\GtkApplication\GtkApplication;
use Gtk\Gtk\GtkApplicationWindow\GtkApplicationWindow;
use Gtk\Gtk\GtkBox\GtkBox;
use Gtk\Gtk\GtkButton\GtkButton;
use Gtk\Gtk\GtkDropDown\GtkDropDown;
use Gtk\Gtk\GtkFlowBox\GtkFlowBox;
use Gtk\Gtk\GtkFlowBoxChild\GtkFlowBoxChild;
use Gtk\Gtk\GtkHeaderBar\GtkHeaderBar;
use Gtk\Gtk\GtkLabel\GtkLabel;
use Gtk\Gtk\GtkListBox\GtkListBox;
use Gtk\Gtk\GtkListBoxRow\GtkListBoxRow;
use Gtk\Gtk\GtkNotebook\GtkNotebook;
use Gtk\Gtk\GtkNotebookPage\GtkNotebookPage;
use Gtk\Gtk\GtkPaned\GtkPaned;
use Gtk\Gtk\GtkPopover\GtkPopover;
use Gtk\Gtk\GtkPopoverMenu\GtkPopoverMenu;
use Gtk\Gtk\GtkPopoverMenuBar\GtkPopoverMenuBar;
use Gtk\Gtk\GtkStack\GtkStack;
use Gtk\Gtk\GtkStackPage\GtkStackPage;
use Gtk\Gtk\GtkStackSidebar\GtkStackSidebar;
use Gtk\Gtk\GtkStackSwitcher\GtkStackSwitcher;
use Gtk\Gtk\GtkStringList\GtkStringList;
use Gtk\Gtk\GtkStringObject\GtkStringObject;
use Gtk\Gtk\GtkTextBuffer\GtkTextBuffer;
use Gtk\Gtk\GtkTextMark\GtkTextMark;
use Gtk\Gtk\GtkTextTag\GtkTextTag;
use Gtk\Gtk\GtkTextTagTable\GtkTextTagTable;
use Gtk\Gtk\GtkTextView\GtkTextView;
use Gtk\Gtk\GtkWidget\GtkWidget;
use Gtk\Gtk\GtkWindow\GtkWindow;
use Gtk\Gtk\GtkWindowControls\GtkWindowControls;

// Enum values used here (enums live downstream in jovian/gtk):
// GtkOrientation HORIZONTAL=0/VERTICAL=1, GtkPackType START=0,
// GtkWrapMode WORD=2.
const HORIZONTAL = 0;
const VERTICAL = 1;
const PACK_START = 0;
const WRAP_WORD = 2;

$failures = 0;

function check(bool $ok, string $marker, string $detail = ''): void
{
    global $failures;
    if ($ok) {
        echo "{$marker}\n";
        return;
    }
    $failures++;
    fwrite(STDERR, "FAIL {$marker}" . ($detail === '' ? '' : " — {$detail}") . "\n");
}

if (!extension_loaded('gtk')) {
    fwrite(STDERR, "wave_b: the gtk extension is not loaded\n");
    exit(1);
}

check(Bridge::init(), 'INIT_OK', 'gtk_init_check failed — run from the logged-in seat');
if ($failures > 0) {
    exit(1);
}

// ---- construct every constructible Wave B class ---------------------------

$stringList = GtkStringList::new_(['alpha', 'beta']);
$stringObj = GtkStringObject::new_('gamma');
$listStore = GListStore::new_(Bridge::typeFromName('GtkStringObject'));
$action = GSimpleAction::new_('hello');
$menu = GMenu::new_();
$menuItem = GMenuItem::new_('Quit', 'app.quit');
$dropdown = GtkDropDown::newFromStrings(['one', 'two', 'three']);
$dropdownBare = GtkDropDown::new_(0);
$listBox = GtkListBox::new_();
$listRow = GtkListBoxRow::new_();
$flowBox = GtkFlowBox::new_();
$flowChild = GtkFlowBoxChild::new_();
$notebook = GtkNotebook::new_();
$stack = GtkStack::new_();
$switcher = GtkStackSwitcher::new_();
$sidebar = GtkStackSidebar::new_();
$paned = GtkPaned::new_(HORIZONTAL);
$header = GtkHeaderBar::new_();
$controls = GtkWindowControls::new_(PACK_START);
// The Bridge never calls g_application_run/register (remote-instance
// segfault avoidance), so constructing a GtkApplicationWindow prints a
// GTK CRITICAL about GApplication::startup on stderr. The construction
// and the window's GActionMap still work — measured 4.18.6 behaviour.
$app = GtkApplication::new_('com.projectsaturn.wave_b', 0);
$appWin = GtkApplicationWindow::new_($app);
$about = GtkAboutDialog::new_();
$popover = GtkPopover::new_();
$popMenu = GtkPopoverMenu::newFromModel($menu);
// A menubar renders only submenus at its top level — plain items there draw
// "Don't know how to handle this item" warnings. Give it a wrapper menu.
$barMenu = GMenu::new_();
$popMenuBar = GtkPopoverMenuBar::newFromModel($barMenu);
$tagTable = GtkTextTagTable::new_();
$tag = GtkTextTag::new_('emphasis');
$buffer = GtkTextBuffer::new_($tagTable);
$mark = GtkTextMark::new_('bookmark', true);
$textView = GtkTextView::newWithBuffer($buffer);

$constructed = [
    'GtkStringList' => $stringList, 'GtkStringObject' => $stringObj,
    'GListStore' => $listStore, 'GSimpleAction' => $action, 'GMenu' => $menu,
    'GMenuItem' => $menuItem, 'GtkDropDown' => $dropdown,
    'GtkListBox' => $listBox, 'GtkListBoxRow' => $listRow,
    'GtkFlowBox' => $flowBox, 'GtkFlowBoxChild' => $flowChild,
    'GtkNotebook' => $notebook, 'GtkStack' => $stack,
    'GtkStackSwitcher' => $switcher, 'GtkStackSidebar' => $sidebar,
    'GtkPaned' => $paned, 'GtkHeaderBar' => $header,
    'GtkWindowControls' => $controls, 'GtkApplicationWindow' => $appWin,
    'GtkAboutDialog' => $about, 'GtkPopover' => $popover,
    'GtkPopoverMenu' => $popMenu, 'GtkPopoverMenuBar' => $popMenuBar,
    'GtkTextTagTable' => $tagTable, 'GtkTextTag' => $tag,
    'GtkTextBuffer' => $buffer, 'GtkTextMark' => $mark,
    'GtkTextView' => $textView,
];
$broken = [];
foreach ($constructed as $type => $handle) {
    if ($handle === 0 || Bridge::typeName($handle) !== $type) {
        $broken[] = $type;
    }
}
check($broken === [], 'CONSTRUCT_OK', 'not constructed/registered: ' . implode(', ', $broken));

// ---- GListModel through GtkStringList: live items-changed -----------------

$modelChanges = 0;
Bridge::connect($stringList, 'items-changed', function () use (&$modelChanges): void {
    $modelChanges++;
});
GtkStringList::append($stringList, 'gamma');
$item0 = GListModel::getItem($stringList, 0);
check(
    $modelChanges === 1
    && GListModel::getNItems($stringList) === 3
    && GtkStringList::getString($stringList, 2) === 'gamma'
    && Bridge::typeName($item0) === 'GtkStringObject'
    && GtkStringObject::getString($item0) === 'alpha',
    'STRINGLIST_OK',
    "changes={$modelChanges}"
);

// ---- GListStore of GtkStringObject -----------------------------------------

GListStore::append($listStore, $stringObj);
GListStore::append($listStore, GtkStringObject::new_('delta'));
$found = GListStore::find($listStore, $stringObj);
check(
    GListModel::getNItems($listStore) === 2
    && GListModel::getItemType($listStore) === Bridge::typeFromName('GtkStringObject')
    && $found['position'] === 0
    && GListModel::getObject($listStore, 0) === $stringObj,
    'LISTSTORE_OK',
    'GListStore round-trip broke'
);

// ---- GAction through GSimpleAction, GActionMap through GtkApplicationWindow -

GActionMap::addAction($appWin, $action);
$lookedUp = GActionMap::lookupAction($appWin, 'hello');
GSimpleAction::setEnabled($action, false);
$disabled = !GAction::getEnabled($action);
GSimpleAction::setEnabled($action, true);
GActionMap::removeAction($appWin, 'hello');
check(
    GAction::getName($action) === 'hello'
    && GAction::nameIsValid('hello')
    && !GAction::nameIsValid('no spaces allowed')
    && $lookedUp === $action
    && $disabled
    && GAction::getEnabled($action)
    && GActionMap::lookupAction($appWin, 'hello') === 0,
    'ACTIONS_OK',
    'action / action-map plumbing broke'
);

// ---- GMenuModel through GMenu ------------------------------------------------

GMenu::append($menu, 'Say Hello', 'win.hello');
GMenu::appendItem($menu, $menuItem);
$submenu = GMenu::new_();
GMenu::append($submenu, 'Deeper', 'win.deeper');
GMenu::appendSubmenu($menu, 'More', $submenu);
GMenu::appendSubmenu($barMenu, 'File', $menu); // menubar top level: submenus only
$wasMutable = GMenuModel::isMutable($menu);
GMenu::freeze($menu);
check(
    GMenuModel::getNItems($menu) === 3
    && GMenuModel::getItemLink($menu, 2, 'submenu') === $submenu
    && $wasMutable
    && !GMenuModel::isMutable($menu),
    'MENUS_OK',
    'menu model round-trip broke'
);

// ---- GtkActionable through GtkButton ------------------------------------------

$actionBtn = GtkButton::newWithLabel('do the thing');
GtkActionable::setActionName($actionBtn, 'win.hello');
check(
    GtkActionable::getActionName($actionBtn) === 'win.hello',
    'ACTIONABLE_OK',
    'actionable name round-trip broke'
);

// ---- GtkDropDown over its string model ----------------------------------------

GtkDropDown::setSelected($dropdown, 2);
$selectedItem = GtkDropDown::getSelectedItem($dropdown);
check(
    Bridge::typeName(GtkDropDown::getModel($dropdown)) === 'GtkStringList'
    && GtkDropDown::getSelected($dropdown) === 2
    && GtkStringObject::getString($selectedItem) === 'three'
    && GtkDropDown::getModel($dropdownBare) === 0,
    'DROPDOWN_OK',
    'dropdown selection broke'
);

// ---- GtkListBox: rows + synchronous row-selected -------------------------------

GtkListBoxRow::setChild($listRow, GtkLabel::new_('row zero'));
GtkListBox::append($listBox, $listRow);
GtkListBox::append($listBox, GtkLabel::new_('row one')); // auto-wrapped in a row

$selected = 0;
Bridge::connect($listBox, 'row-selected', function () use (&$selected): void {
    $selected++;
});
GtkListBox::selectRow($listBox, $listRow);
check(
    GtkListBox::getRowAtIndex($listBox, 0) === $listRow
    && GtkListBoxRow::getIndex($listRow) === 0
    && $selected === 1
    && GtkListBox::getSelectedRow($listBox) === $listRow
    && GtkListBoxRow::isSelected($listRow),
    'LISTBOX_OK',
    "row-selected fired {$selected} times"
);

// ---- GtkFlowBox ------------------------------------------------------------------

GtkFlowBoxChild::setChild($flowChild, GtkLabel::new_('cell zero'));
GtkFlowBox::append($flowBox, $flowChild);
GtkFlowBox::append($flowBox, GtkLabel::new_('cell one'));
GtkFlowBox::selectChild($flowBox, $flowChild);
check(
    GtkFlowBox::getChildAtIndex($flowBox, 0) === $flowChild
    && GtkFlowBoxChild::getIndex($flowChild) === 0
    && GtkFlowBoxChild::isSelected($flowChild),
    'FLOWBOX_OK',
    'flow box round-trip broke'
);

// ---- text model: table + tag + buffer + marks --------------------------------------

GtkTextTagTable::add($tagTable, $tag);
GtkTextBuffer::setText($buffer, 'hello wave b', -1);
$insertMark = GtkTextBuffer::getInsert($buffer);
check(
    GtkTextTagTable::lookup($tagTable, 'emphasis') === $tag
    && GtkTextTagTable::getSize($tagTable) === 1
    && GtkTextBuffer::getTagTable($buffer) === $tagTable
    && GtkTextBuffer::getCharCount($buffer) === 12
    && GtkTextBuffer::getLineCount($buffer) === 1
    && !GtkTextBuffer::getHasSelection($buffer)
    && Bridge::typeName($insertMark) === 'GtkTextMark'
    && GtkTextMark::getName($insertMark) === 'insert'
    && GtkTextMark::getBuffer($insertMark) === $buffer
    && GtkTextMark::getName($mark) === 'bookmark'
    && GtkTextMark::getLeftGravity($mark)
    && GtkTextTag::getPriority($tag) === 0,
    'TEXTMODEL_OK',
    'buffer/tag/table/mark round-trip broke'
);

// ---- text view over the same buffer --------------------------------------------------

GtkTextView::setWrapMode($textView, WRAP_WORD);
GtkTextView::setMonospace($textView, true);
GtkTextView::setEditable($textView, false);
check(
    GtkTextView::getBuffer($textView) === $buffer
    && GtkTextView::getWrapMode($textView) === WRAP_WORD
    && GtkTextView::getMonospace($textView)
    && !GtkTextView::getEditable($textView),
    'TEXTVIEW_OK',
    'text view round-trip broke'
);

// ---- assemble the scene ----------------------------------------------------------------

$win = GtkWindow::new_();
GtkWindow::setTitle($win, 'gtk wave b');
GtkWindow::setDefaultSize($win, 760, 540);

// Empty window controls may warn "min width -6" after present on some
// seats — a GTK layout quirk, not a binding bug.
GtkHeaderBar::packStart($header, $controls);
GtkHeaderBar::setTitleWidget($header, GtkLabel::new_('Wave B'));
GtkHeaderBar::packEnd($header, $actionBtn);
GtkWindow::setTitlebar($win, $header);

// stack with two titled children + switcher and sidebar wired to it
GtkStack::addTitled($stack, GtkLabel::new_('first page'), 'first', 'First');
GtkStack::addTitled($stack, GtkLabel::new_('second page'), 'second', 'Second');
GtkStackSwitcher::setStack($switcher, $stack);
GtkStackSidebar::setStack($sidebar, $stack);

$stackBox = GtkBox::new_(VERTICAL, 6);
GtkBox::append($stackBox, $switcher);
GtkBox::append($stackBox, $stack);

// paned: listbox | flowbox
GtkPaned::setStartChild($paned, $listBox);
GtkPaned::setEndChild($paned, $flowBox);
GtkPaned::setPosition($paned, 200);

// notebook pages: stack box, paned, text view, dropdown + menubar
$menuBox = GtkBox::new_(VERTICAL, 6);
GtkBox::append($menuBox, $popMenuBar);
GtkBox::append($menuBox, $dropdown);

GtkNotebook::appendPage($notebook, $stackBox, GtkLabel::new_('Stack'));
GtkNotebook::appendPage($notebook, $paned, GtkLabel::new_('Paned'));
GtkNotebook::appendPage($notebook, $textView, GtkLabel::new_('Text'));
GtkNotebook::appendPage($notebook, $menuBox, GtkLabel::new_('Menus'));
GtkWindow::setChild($win, $notebook);

// ---- GtkNotebookPage / GtkStackPage: the obtain-only classes ----------------------------

$nbPage = GtkNotebook::getPage($notebook, $paned);
$stPage = GtkStack::getPage($stack, GtkStack::getChildByName($stack, 'first'));
GtkStack::setVisibleChildName($stack, 'second');
GtkNotebook::setCurrentPage($notebook, 1);
check(
    Bridge::typeName($nbPage) === 'GtkNotebookPage'
    && GtkNotebookPage::getChild($nbPage) === $paned
    && GtkNotebook::getNPages($notebook) === 4
    && GtkNotebook::getCurrentPage($notebook) === 1
    && GtkNotebook::pageNum($notebook, $textView) === 2
    && Bridge::typeName($stPage) === 'GtkStackPage'
    && GtkStackPage::getTitle($stPage) === 'First'
    && GtkStack::getVisibleChildName($stack) === 'second'
    && GtkStackSwitcher::getStack($switcher) === $stack
    && GtkStackSidebar::getStack($sidebar) === $stack
    && GtkPaned::getStartChild($paned) === $listBox
    && GtkPaned::getEndChild($paned) === $flowBox
    && GtkPaned::getPosition($paned) === 200,
    'PAGES_OK',
    'notebook/stack pages or paned broke'
);

// ---- window chrome + about dialog (configured, not presented) ----------------------------

GtkAboutDialog::setProgramName($about, 'Wave B Demo');
GtkAboutDialog::setVersion($about, '0.8.0');
GtkAboutDialog::setAuthors($about, ['Angel Gonzalez', 'Claude']);
GtkAboutDialog::setWebsite($about, 'https://projectsaturnstudios.com');
GtkApplicationWindow::setShowMenubar($appWin, true);
check(
    GtkWindowControls::getSide($controls) === PACK_START
    && GtkHeaderBar::getTitleWidget($header) !== 0
    && GtkAboutDialog::getProgramName($about) === 'Wave B Demo'
    && GtkAboutDialog::getAuthors($about) === ['Angel Gonzalez', 'Claude']
    && GtkAboutDialog::getWebsite($about) === 'https://projectsaturnstudios.com'
    && GtkApplicationWindow::getShowMenubar($appWin),
    'CHROME_OK',
    'header bar / about dialog round-trip broke'
);

// ---- present, then run the live parts ------------------------------------------------------

GtkWindow::present($win);
$deadline = microtime(true) + 3.0;
while (!GtkWidget::getVisible($win) && microtime(true) < $deadline) {
    Bridge::pump(50);
}
check(GtkWidget::getVisible($win), 'PRESENT_OK', 'window never became visible');

// Popovers: parent onto the header-bar button, pop up through the pump, pop down.
GtkPopover::setChild($popover, GtkLabel::new_('popped'));
GtkWidget::setParent($popover, $actionBtn);
GtkPopover::popup($popover);
$deadline = microtime(true) + 3.0;
while (!GtkWidget::getVisible($popover) && microtime(true) < $deadline) {
    Bridge::pump(50);
}
$popped = GtkWidget::getVisible($popover);
GtkPopover::popdown($popover);
Bridge::pump(100);
check(
    $popped
    && GtkPopoverMenu::getMenuModel($popMenu) === $menu
    && GtkPopoverMenuBar::getMenuModel($popMenuBar) === $barMenu,
    'POPOVER_OK',
    'popover never mapped or menu-model identity broke'
);

// ---- teardown ---------------------------------------------------------------------------------

Bridge::connect($win, 'close-request', fn (): bool => false);
GtkWindow::close($win);
Bridge::pump(200);
Bridge::release($win);

if ($failures > 0) {
    fwrite(STDERR, "wave_b: {$failures} failure(s)\n");
    exit(1);
}

echo "WAVE_B_OK\n";
