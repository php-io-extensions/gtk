<?php
/*
 * Wave C demo: GtkCalendar plus the GtkColumnView family, proven live
 * against real GTK in one scene.
 *
 * Calendar: set/get year-month-day (month is 0-based) and day-selected.
 * ColumnView: two columns over a GtkStringList of row placeholders;
 * each column has its own GtkSignalListItemFactory (setup → GtkLabel,
 * bind → PHP-side cell via GtkListItem::getPosition). Selection is a
 * GtkSingleSelection; notify::selected fires when a row is chosen.
 * GtkNoSelection is constructed to complete the family.
 *
 * Needs the box's logged-in seat. Prints WAVE_C_OK when everything held.
 *
 * Run on the Linux box: php examples/wave_c.php
 */

declare(strict_types=1);

use Gtk\Bridge\Bridge;
use Gtk\Gio\GListModel\GListModel;
use Gtk\Gtk\GtkBox\GtkBox;
use Gtk\Gtk\GtkCalendar\GtkCalendar;
use Gtk\Gtk\GtkColumnView\GtkColumnView;
use Gtk\Gtk\GtkColumnViewColumn\GtkColumnViewColumn;
use Gtk\Gtk\GtkLabel\GtkLabel;
use Gtk\Gtk\GtkListItem\GtkListItem;
use Gtk\Gtk\GtkNoSelection\GtkNoSelection;
use Gtk\Gtk\GtkSelectionModel\GtkSelectionModel;
use Gtk\Gtk\GtkSignalListItemFactory\GtkSignalListItemFactory;
use Gtk\Gtk\GtkSingleSelection\GtkSingleSelection;
use Gtk\Gtk\GtkStringList\GtkStringList;
use Gtk\Gtk\GtkStringObject\GtkStringObject;
use Gtk\Gtk\GtkWidget\GtkWidget;
use Gtk\Gtk\GtkWindow\GtkWindow;

const VERTICAL = 1;

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
    fwrite(STDERR, "wave_c: the gtk extension is not loaded\n");
    exit(1);
}

check(Bridge::init(), 'INIT_OK', 'gtk_init_check failed — run from the logged-in seat');
if ($failures > 0) {
    exit(1);
}

$rows = [
    ['alpha', 'one'],
    ['beta', 'two'],
    ['gamma', 'three'],
];

$calendar = GtkCalendar::new_();
$stringList = GtkStringList::new_(['0', '1', '2']);
$selection = GtkSingleSelection::new_($stringList);
$none = GtkNoSelection::new_(0);
$view = GtkColumnView::new_($selection);

$setups = 0;
$binds = 0;
$boundCells = [];

$makeFactory = static function (int $col) use ($rows, &$setups, &$binds, &$boundCells): int {
    $factory = GtkSignalListItemFactory::new_();
    Bridge::connect($factory, 'setup', function (int $emitter, int $listItem) use (&$setups): void {
        $setups++;
        GtkListItem::setChild($listItem, GtkLabel::new_(''));
    });
    Bridge::connect($factory, 'bind', function (int $emitter, int $listItem) use ($col, $rows, &$binds, &$boundCells): void {
        $binds++;
        $position = GtkListItem::getPosition($listItem);
        $child = GtkListItem::getChild($listItem);
        $text = $rows[$position][$col] ?? '';
        GtkLabel::setText($child, $text);
        $boundCells[$col][$position] = $text;
    });

    return $factory;
};

$nameCol = GtkColumnViewColumn::new_('Name', $makeFactory(0));
$valCol = GtkColumnViewColumn::new_('Value', $makeFactory(1));
GtkColumnView::appendColumn($view, $nameCol);
GtkColumnView::appendColumn($view, $valCol);

check(
    $calendar !== 0
    && $stringList !== 0
    && $selection !== 0
    && $none !== 0
    && $view !== 0
    && $nameCol !== 0
    && $valCol !== 0,
    'CONSTRUCT_OK',
    'a Wave C constructor returned 0'
);

GtkCalendar::setYear($calendar, 2024);
GtkCalendar::setMonth($calendar, 8);
GtkCalendar::setDay($calendar, 12);
$daySelected = 0;
Bridge::connect($calendar, 'day-selected', function () use (&$daySelected): void {
    $daySelected++;
});
GtkCalendar::setDay($calendar, 13);
GtkCalendar::markDay($calendar, 13);
check(
    GtkCalendar::getYear($calendar) === 2024
    && GtkCalendar::getMonth($calendar) === 8
    && GtkCalendar::getDay($calendar) === 13
    && GtkCalendar::getDayIsMarked($calendar, 13)
    && $daySelected >= 1,
    'CALENDAR_OK',
    "y/m/d=" . GtkCalendar::getYear($calendar) . '/' . GtkCalendar::getMonth($calendar) . '/' . GtkCalendar::getDay($calendar)
        . " day-selected={$daySelected}"
);

GtkSingleSelection::setAutoselect($selection, false);
GtkSingleSelection::setCanUnselect($selection, true);
check(
    GtkColumnView::getModel($view) === $selection
    && GtkColumnViewColumn::getTitle($nameCol) === 'Name'
    && GtkColumnViewColumn::getTitle($valCol) === 'Value'
    && GtkColumnViewColumn::getColumnView($nameCol) === $view
    && GListModel::getNItems(GtkColumnView::getColumns($view)) === 2
    && GtkSingleSelection::getModel($selection) === $stringList
    && GtkNoSelection::getModel($none) === 0
    && !GtkSingleSelection::getAutoselect($selection)
    && GtkSingleSelection::getCanUnselect($selection),
    'TABLE_OK',
    'column view / selection identity broke'
);

$selectedNotes = 0;
Bridge::connect($selection, 'notify::selected', function () use (&$selectedNotes): void {
    $selectedNotes++;
});

$win = GtkWindow::new_();
GtkWindow::setTitle($win, 'gtk wave c');
GtkWindow::setDefaultSize($win, 640, 480);
$box = GtkBox::new_(VERTICAL, 8);
GtkBox::append($box, $calendar);
GtkBox::append($box, $view);
GtkWindow::setChild($win, $box);
GtkWindow::present($win);

$deadline = microtime(true) + 3.0;
while (!GtkWidget::getVisible($win) && microtime(true) < $deadline) {
    Bridge::pump(50);
}
check(GtkWidget::getVisible($win), 'PRESENT_OK', 'window never became visible');

$deadline = microtime(true) + 3.0;
while (($setups < 2 || $binds < 2) && microtime(true) < $deadline) {
    Bridge::pump(50);
}
check(
    $setups >= 2
    && $binds >= 2
    && ($boundCells[0][0] ?? null) === 'alpha'
    && ($boundCells[1][0] ?? null) === 'one',
    'FACTORY_OK',
    "setups={$setups} binds={$binds} cells=" . json_encode($boundCells)
);

GtkSingleSelection::setSelected($selection, 1);
Bridge::pump(100);
check(
    GtkSingleSelection::getSelected($selection) === 1
    && GtkSelectionModel::isSelected($selection, 1)
    && $selectedNotes >= 1
    && GtkStringObject::getString(GtkSingleSelection::getSelectedItem($selection)) === '1',
    'SELECT_OK',
    "selected=" . GtkSingleSelection::getSelected($selection) . " notify={$selectedNotes}"
);

Bridge::connect($win, 'close-request', fn (): bool => false);
GtkWindow::close($win);
Bridge::pump(200);
Bridge::release($win);

if ($failures > 0) {
    fwrite(STDERR, "wave_c: {$failures} failure(s)\n");
    exit(1);
}

echo "WAVE_C_OK\n";
