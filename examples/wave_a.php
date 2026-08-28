<?php
/*
 * Wave A demo: every Wave A class proven live against real GTK in one scene.
 * 29 constructible classes are built directly; the three non-constructibles
 * are exercised through implementors — GtkEditable via GtkEntry/GtkSearchEntry,
 * GtkRange via GtkScale, GtkScrollable via GtkViewport.
 *
 * Needs the box's logged-in seat. Prints WAVE_A_OK when everything held.
 *
 * Run on the Linux box: php examples/wave_a.php
 */

declare(strict_types=1);

use Gtk\Bridge\Bridge;
use Gtk\Gtk\GtkAdjustment\GtkAdjustment;
use Gtk\Gtk\GtkAspectFrame\GtkAspectFrame;
use Gtk\Gtk\GtkBox\GtkBox;
use Gtk\Gtk\GtkCenterBox\GtkCenterBox;
use Gtk\Gtk\GtkCheckButton\GtkCheckButton;
use Gtk\Gtk\GtkEditable\GtkEditable;
use Gtk\Gtk\GtkEntry\GtkEntry;
use Gtk\Gtk\GtkEntryBuffer\GtkEntryBuffer;
use Gtk\Gtk\GtkExpander\GtkExpander;
use Gtk\Gtk\GtkFixed\GtkFixed;
use Gtk\Gtk\GtkFrame\GtkFrame;
use Gtk\Gtk\GtkGrid\GtkGrid;
use Gtk\Gtk\GtkImage\GtkImage;
use Gtk\Gtk\GtkLabel\GtkLabel;
use Gtk\Gtk\GtkLevelBar\GtkLevelBar;
use Gtk\Gtk\GtkOverlay\GtkOverlay;
use Gtk\Gtk\GtkPasswordEntry\GtkPasswordEntry;
use Gtk\Gtk\GtkPicture\GtkPicture;
use Gtk\Gtk\GtkProgressBar\GtkProgressBar;
use Gtk\Gtk\GtkRange\GtkRange;
use Gtk\Gtk\GtkRevealer\GtkRevealer;
use Gtk\Gtk\GtkScale\GtkScale;
use Gtk\Gtk\GtkScrollable\GtkScrollable;
use Gtk\Gtk\GtkScrollbar\GtkScrollbar;
use Gtk\Gtk\GtkScrolledWindow\GtkScrolledWindow;
use Gtk\Gtk\GtkSearchEntry\GtkSearchEntry;
use Gtk\Gtk\GtkSeparator\GtkSeparator;
use Gtk\Gtk\GtkSpinButton\GtkSpinButton;
use Gtk\Gtk\GtkSpinner\GtkSpinner;
use Gtk\Gtk\GtkSwitch\GtkSwitch;
use Gtk\Gtk\GtkText\GtkText;
use Gtk\Gtk\GtkToggleButton\GtkToggleButton;
use Gtk\Gtk\GtkViewport\GtkViewport;
use Gtk\Gtk\GtkWidget\GtkWidget;
use Gtk\Gtk\GtkWindow\GtkWindow;

// GtkOrientation / GtkPositionType values (enums live downstream in jovian/gtk).
const HORIZONTAL = 0;
const VERTICAL = 1;
const POS_BOTTOM = 3;

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
    fwrite(STDERR, "wave_a: the gtk extension is not loaded\n");
    exit(1);
}

check(Bridge::init(), 'INIT_OK', 'gtk_init_check failed — run from the logged-in seat');
if ($failures > 0) {
    exit(1);
}

// ---- construct every constructible Wave A class --------------------------

$adjustment = GtkAdjustment::new_(50.0, 0.0, 100.0, 1.0, 10.0, 0.0);
$buffer = GtkEntryBuffer::new_('wave a', -1);

$label = GtkLabel::new_('Wave A');
$image = GtkImage::newFromIconName('face-smile');
$picture = GtkPicture::new_();
$spinner = GtkSpinner::new_();
$progress = GtkProgressBar::new_();
$level = GtkLevelBar::newForInterval(0.0, 10.0);
$entry = GtkEntry::newWithBuffer($buffer);
$text = GtkText::newWithBuffer($buffer);
$password = GtkPasswordEntry::new_();
$search = GtkSearchEntry::new_();
$toggle = GtkToggleButton::newWithLabel('toggle');
$checkBtn = GtkCheckButton::newWithLabel('check');
$switch = GtkSwitch::new_();
$spin = GtkSpinButton::newWithRange(0.0, 10.0, 1.0);
$scale = GtkScale::new_(HORIZONTAL, $adjustment);
$scrollbar = GtkScrollbar::new_(HORIZONTAL, $adjustment);
$frame = GtkFrame::new_('frame');
$aspect = GtkAspectFrame::new_(0.5, 0.5, 1.5, false);
$separator = GtkSeparator::new_(HORIZONTAL);
$centerBox = GtkCenterBox::new_();
$grid = GtkGrid::new_();
$fixed = GtkFixed::new_();
$overlay = GtkOverlay::new_();
$expander = GtkExpander::new_('details');
$revealer = GtkRevealer::new_();
$scrolled = GtkScrolledWindow::new_();
$viewport = GtkViewport::new_(0, 0);
$win = GtkWindow::new_();

$constructed = [
    'GtkAdjustment' => $adjustment, 'GtkEntryBuffer' => $buffer, 'GtkLabel' => $label,
    'GtkImage' => $image, 'GtkPicture' => $picture, 'GtkSpinner' => $spinner,
    'GtkProgressBar' => $progress, 'GtkLevelBar' => $level, 'GtkEntry' => $entry,
    'GtkText' => $text, 'GtkPasswordEntry' => $password, 'GtkSearchEntry' => $search,
    'GtkToggleButton' => $toggle, 'GtkCheckButton' => $checkBtn, 'GtkSwitch' => $switch,
    'GtkSpinButton' => $spin, 'GtkScale' => $scale, 'GtkScrollbar' => $scrollbar,
    'GtkFrame' => $frame, 'GtkAspectFrame' => $aspect, 'GtkSeparator' => $separator,
    'GtkCenterBox' => $centerBox, 'GtkGrid' => $grid, 'GtkFixed' => $fixed,
    'GtkOverlay' => $overlay, 'GtkExpander' => $expander, 'GtkRevealer' => $revealer,
    'GtkScrolledWindow' => $scrolled, 'GtkViewport' => $viewport,
];
$broken = [];
foreach ($constructed as $type => $handle) {
    if ($handle === 0 || Bridge::typeName($handle) !== $type) {
        $broken[] = $type;
    }
}
check($broken === [], 'CONSTRUCT_OK', 'not constructed/registered: ' . implode(', ', $broken));

// ---- GtkEditable through its implementors ---------------------------------

GtkEditable::setText($entry, 'hello wave a');
GtkEditable::selectRegion($entry, 0, 5);
$bounds = GtkEditable::getSelectionBounds($entry);
check(
    GtkEditable::getText($entry) === 'hello wave a'
    && GtkEditable::getChars($entry, 0, 5) === 'hello'
    && $bounds['start_pos'] === 0 && $bounds['end_pos'] === 5,
    'EDITABLE_OK',
    'GtkEditable methods through GtkEntry broke'
);

// ---- one GtkEntryBuffer feeding GtkEntry and GtkText -----------------------

check(
    GtkEntryBuffer::getText($buffer) === 'hello wave a'
    && GtkEntry::getBuffer($entry) === $buffer
    && GtkText::getBuffer($text) === $buffer
    && GtkText::getTextLength($text) === GtkEntryBuffer::getLength($buffer),
    'BUFFER_OK',
    'shared entry buffer out of sync'
);

// ---- toggles: state + synchronous signal emission --------------------------

$toggled = 0;
Bridge::connect($checkBtn, 'toggled', function () use (&$toggled): void {
    $toggled++;
});
GtkCheckButton::setActive($checkBtn, true);
GtkToggleButton::setActive($toggle, true);

$switchNotifies = 0;
Bridge::connect($switch, 'notify::active', function () use (&$switchNotifies): void {
    $switchNotifies++;
});
GtkSwitch::setActive($switch, true);

check(
    $toggled === 1
    && GtkCheckButton::getActive($checkBtn)
    && GtkToggleButton::getActive($toggle)
    && $switchNotifies === 1
    && GtkSwitch::getActive($switch),
    'TOGGLES_OK',
    "toggled={$toggled} notifies={$switchNotifies}"
);

// ---- ranges: first-class GtkAdjustment, GtkRange via GtkScale ---------------

$valueChanges = 0;
Bridge::connect($adjustment, 'value-changed', function () use (&$valueChanges): void {
    $valueChanges++;
});
GtkAdjustment::setValue($adjustment, 75.0);
GtkScale::addMark($scale, 50.0, POS_BOTTOM, 'half');
GtkSpinButton::setValue($spin, 7.0);

check(
    $valueChanges === 1
    && GtkRange::getValue($scale) === 75.0            // GtkRange methods on a GtkScale handle
    && GtkRange::getAdjustment($scale) === $adjustment
    && GtkScrollbar::getAdjustment($scrollbar) === $adjustment
    && GtkSpinButton::getValueAsInt($spin) === 7,
    'RANGES_OK',
    'adjustment/range plumbing broke'
);

// ---- feedback ---------------------------------------------------------------

GtkProgressBar::setFraction($progress, 0.62);
GtkLevelBar::setValue($level, 4.0);
GtkSpinner::start($spinner);
check(
    abs(GtkProgressBar::getFraction($progress) - 0.62) < 0.0001
    && GtkLevelBar::getValue($level) === 4.0
    && GtkSpinner::getSpinning($spinner),
    'FEEDBACK_OK',
    'progress/level/spinner state broke'
);

// ---- assemble the scene ------------------------------------------------------

GtkWindow::setTitle($win, 'gtk wave a');
GtkWindow::setDefaultSize($win, 640, 520);

// window → scrolled window → viewport → grid of everything
GtkGrid::setRowSpacing($grid, 8);
GtkGrid::setColumnSpacing($grid, 8);
GtkWidget::setMarginTop($grid, 16);
GtkWidget::setMarginBottom($grid, 16);
GtkWidget::setMarginStart($grid, 16);
GtkWidget::setMarginEnd($grid, 16);

GtkCenterBox::setStartWidget($centerBox, $image);
GtkCenterBox::setCenterWidget($centerBox, $label);
GtkCenterBox::setEndWidget($centerBox, $spinner);

GtkFrame::setChild($frame, $centerBox);
GtkAspectFrame::setChild($aspect, $picture);

GtkFixed::put($fixed, $toggle, 12.0, 6.0);
GtkOverlay::setChild($overlay, $fixed);
GtkOverlay::addOverlay($overlay, $switch);

$expanderBody = GtkBox::new_(VERTICAL, 6);
GtkBox::append($expanderBody, $password);
GtkBox::append($expanderBody, $text);
GtkExpander::setChild($expander, $expanderBody);
GtkExpander::setExpanded($expander, true);

GtkRevealer::setChild($revealer, $checkBtn);

GtkGrid::attach($grid, $frame, 0, 0, 2, 1);
GtkGrid::attach($grid, $entry, 0, 1, 1, 1);
GtkGrid::attach($grid, $search, 1, 1, 1, 1);
GtkGrid::attach($grid, $scale, 0, 2, 1, 1);
GtkGrid::attach($grid, $spin, 1, 2, 1, 1);
GtkGrid::attach($grid, $scrollbar, 0, 3, 2, 1);
GtkGrid::attach($grid, $separator, 0, 4, 2, 1);
GtkGrid::attach($grid, $progress, 0, 5, 1, 1);
GtkGrid::attach($grid, $level, 1, 5, 1, 1);
GtkGrid::attach($grid, $overlay, 0, 6, 1, 1);
GtkGrid::attach($grid, $aspect, 1, 6, 1, 1);
GtkGrid::attach($grid, $expander, 0, 7, 2, 1);
GtkGrid::attach($grid, $revealer, 0, 8, 2, 1);

GtkViewport::setChild($viewport, $grid);
GtkScrolledWindow::setChild($scrolled, $viewport);
GtkWindow::setChild($win, $scrolled);

$cell = GtkGrid::queryChild($grid, $entry);
check(
    GtkGrid::getChildAt($grid, 0, 1) === $entry
    && $cell['column'] === 0 && $cell['row'] === 1 && $cell['width'] === 1
    && GtkFrame::getChild($frame) === $centerBox
    && GtkCenterBox::getCenterWidget($centerBox) === $label
    && GtkWidget::getParent($toggle) === $fixed   // put() reparented into the fixed
    && GtkOverlay::getChild($overlay) === $fixed
    && abs(GtkAspectFrame::getRatio($aspect) - 1.5) < 0.0001
    && GtkExpander::getExpanded($expander),
    'CONTAINERS_OK',
    'container round-trips broke'
);

// ---- GtkScrollable through GtkViewport --------------------------------------

check(
    GtkScrolledWindow::getChild($scrolled) === $viewport
    && GtkViewport::getChild($viewport) === $grid
    && GtkScrollable::getHadjustment($viewport) === GtkScrolledWindow::getHadjustment($scrolled)
    && GtkScrollable::getVadjustment($viewport) === GtkScrolledWindow::getVadjustment($scrolled),
    'SCROLL_OK',
    'scrolled window / viewport / scrollable plumbing broke'
);

// ---- present and run the animated/asynchronous parts -------------------------

GtkWindow::present($win);
$deadline = microtime(true) + 3.0;
while (!GtkWidget::getVisible($win) && microtime(true) < $deadline) {
    Bridge::pump(50);
}
check(GtkWidget::getVisible($win), 'PRESENT_OK', 'window never became visible');

// gtk_fixed_get_child_position answers in allocated coordinates (it rides
// gtk_widget_compute_point since 4.10): {0,0} before allocation, and after
// mapping it carries a constant theme offset — so assert the move delta,
// not absolutes. Measured GTK 4.18.6 behaviour, .okf/traps/fixed-child-position.md.
// The window reports visible before deep descendants are allocated — pump
// until the baseline reading is live ({0,0} means "not allocated yet";
// the put position 12,6 plus the positive theme offset can never read 0,0).
$before = GtkFixed::getChildPosition($fixed, $toggle);
$deadline = microtime(true) + 3.0;
while ($before['x'] === 0.0 && $before['y'] === 0.0 && microtime(true) < $deadline) {
    Bridge::pump(50);
    $before = GtkFixed::getChildPosition($fixed, $toggle);
}
GtkFixed::move($fixed, $toggle, 40.0, 26.0); // was put at 12,6 → delta 28,20
$deadline = microtime(true) + 2.0;
do {
    Bridge::pump(50);
    $after = GtkFixed::getChildPosition($fixed, $toggle);
} while (($after['x'] - $before['x'] !== 28.0 || $after['y'] - $before['y'] !== 20.0)
    && microtime(true) < $deadline);
check(
    $after['x'] - $before['x'] === 28.0 && $after['y'] - $before['y'] === 20.0,
    'FIXED_OK',
    sprintf('move delta was {%g, %g}, expected {28, 20}', $after['x'] - $before['x'], $after['y'] - $before['y'])
);

// Revealer transition only runs while mapped — reveal now and pump through it.
GtkRevealer::setRevealChild($revealer, true);
$deadline = microtime(true) + 3.0;
while (!GtkRevealer::getChildRevealed($revealer) && microtime(true) < $deadline) {
    Bridge::pump(50);
}
check(GtkRevealer::getChildRevealed($revealer), 'REVEALER_OK', 'reveal animation never finished');

// search-changed rides the search delay (a GLib timeout) — proves pump
// dispatches timeout sources, not just GTK's own.
$searches = 0;
Bridge::connect($search, 'search-changed', function () use (&$searches): void {
    $searches++;
});
GtkSearchEntry::setSearchDelay($search, 60);
GtkEditable::setText($search, 'needle');
$deadline = microtime(true) + 3.0;
while ($searches === 0 && microtime(true) < $deadline) {
    Bridge::pump(50);
}
check($searches >= 1, 'SEARCH_OK', 'search-changed never fired through the pump');

// ---- teardown -----------------------------------------------------------------

Bridge::connect($win, 'close-request', fn (): bool => false);
GtkWindow::close($win);
Bridge::pump(200);
Bridge::release($win);

if ($failures > 0) {
    fwrite(STDERR, "wave_a: {$failures} failure(s)\n");
    exit(1);
}

echo "WAVE_A_OK\n";
