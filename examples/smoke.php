<?php
/*
 * Smoke test: every Bridge mechanism proven live against real GTK.
 * Window + button, a real "clicked" signal into a PHP callable,
 * close-request return-value writeback (veto then allow), the handle
 * registry, the property fallback, and the connect guard failure paths.
 * Needs the box's logged-in seat. Prints SMOKE_OK when everything held.
 *
 * Run on the Linux box: php examples/smoke.php
 */

declare(strict_types=1);

use Gtk\Bridge\Bridge;
use Gtk\Gtk\GtkBox\GtkBox;
use Gtk\Gtk\GtkButton\GtkButton;
use Gtk\Gtk\GtkWidget\GtkWidget;
use Gtk\Gtk\GtkWindow\GtkWindow;

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

/** Run $fn while collecting PHP warnings; returns [result, warnings[]]. */
function withWarnings(callable $fn): array
{
    $warnings = [];
    set_error_handler(function (int $no, string $msg) use (&$warnings): bool {
        $warnings[] = $msg;
        return true;
    }, E_WARNING);
    try {
        $result = $fn();
    } finally {
        restore_error_handler();
    }
    return [$result, $warnings];
}

if (!extension_loaded('gtk')) {
    fwrite(STDERR, "smoke: the gtk extension is not loaded\n");
    exit(1);
}

check(Bridge::init(), 'INIT_OK', 'gtk_init_check failed — run from the logged-in seat');
if ($failures > 0) {
    exit(1);
}

// ---- registry ----------------------------------------------------------

$win = GtkWindow::new_();
check(
    $win !== 0
    && Bridge::isValid($win)
    && Bridge::typeName($win) === 'GtkWindow'
    && Bridge::isA($win, 'GtkWidget')
    && !Bridge::isA($win, 'GtkButton')
    && !Bridge::isValid(0)
    && !Bridge::isValid(12345678),           // fabricated handle resolves invalid, no crash
    'REGISTRY_OK',
    'handle registry answers wrong'
);

// ---- build the scene ---------------------------------------------------

GtkWindow::setTitle($win, 'gtk smoke');
GtkWindow::setDefaultSize($win, 420, 260);

$box = GtkBox::new_(1, 12); // GTK_ORIENTATION_VERTICAL
GtkWidget::setMarginTop($box, 20);
GtkWidget::setMarginBottom($box, 20);
GtkWidget::setMarginStart($box, 20);
GtkWidget::setMarginEnd($box, 20);
GtkWindow::setChild($win, $box);

$btn = GtkButton::newWithLabel('smoke button');
GtkBox::append($box, $btn);

check(
    GtkWindow::getTitle($win) === 'gtk smoke'
    && GtkButton::getLabel($btn) === 'smoke button'
    && GtkWindow::getChild($win) === $box,   // GTK returns the same object -> same handle
    'ROUNDTRIP_OK',
    'setter/getter round-trip broke'
);

// ---- property fallback (reserved property "x" members) ------------------

Bridge::setProperty($win, 'default-width', 500);
check(
    Bridge::getProperty($win, 'default-width') === 500
    && Bridge::getProperty($win, 'title') === 'gtk smoke',
    'PROPERTY_OK',
    'g_object_get/set_property fallback broke'
);

// ---- clicked: a real GTK signal into a PHP callable ---------------------

$clicks = 0;
$clickedId = Bridge::connect($btn, 'clicked', function (int $sender) use ($btn, &$clicks): void {
    if ($sender === $btn) {
        $clicks++;
    }
});
check($clickedId > 0, 'CONNECT_OK', 'connect(clicked) returned no handler id');

GtkWindow::present($win);
$deadline = microtime(true) + 2.0;
while (GtkWidget::getVisible($win) === false && microtime(true) < $deadline) {
    Bridge::pump(50);
}

// gtk_widget_activate on a button returns true immediately, but "clicked"
// rides a ~250ms press animation and needs realization — pump until it lands
// (measured GTK 4.18.6 behaviour, .okf/traps/control-signal-surprises.md).
GtkWidget::activate($btn);
$deadline = microtime(true) + 3.0;
while ($clicks === 0 && microtime(true) < $deadline) {
    Bridge::pump(50);
}
check($clicks === 1, 'CLICKED_OK', "expected 1 click, saw {$clicks}");

Bridge::disconnect($btn, $clickedId);
GtkWidget::activate($btn);
$deadline = microtime(true) + 1.0;
while (microtime(true) < $deadline) {
    Bridge::pump(50);
}
check($clicks === 1, 'DISCONNECT_OK', 'handler fired after disconnect');

// ---- close-request writeback: veto, then allow ---------------------------

$veto = true;
$closeRequests = 0;
Bridge::connect($win, 'close-request', function (int $sender) use (&$veto, &$closeRequests): bool {
    $closeRequests++;
    return $veto; // true stops the close, false lets GTK proceed
});

GtkWindow::close($win);
Bridge::pump(200);
check(
    $closeRequests === 1 && GtkWidget::getVisible($win) === true,
    'CLOSE_VETO_OK',
    'returning true from close-request did not keep the window open'
);

$veto = false;
GtkWindow::close($win);
Bridge::pump(200);
check(
    $closeRequests === 2 && GtkWidget::getVisible($win) === false,
    'CLOSE_OK',
    'returning false from close-request did not close the window'
);

// The registry still owns a ref, so the handle survives the close.
check(Bridge::isValid($win), 'SURVIVES_CLOSE_OK', 'registry ref did not outlive the close');

// ---- connect guard failure paths ----------------------------------------

[$badSignal, $w1] = withWarnings(fn (): int => Bridge::connect($btn, 'no-such-signal', fn () => null));
[$badNotify, $w2] = withWarnings(fn (): int => Bridge::connect($btn, 'notify::use_underline', fn () => null));
[$goodNotify, $w3] = withWarnings(fn (): int => Bridge::connect($btn, 'notify::use-underline', fn () => null));
check(
    $badSignal === 0 && $w1 !== []
    && $badNotify === 0 && $w2 !== [] && str_contains(implode(' ', $w2), 'use-underline')
    && $goodNotify > 0 && $w3 === [],
    'CONNECT_GUARD_OK',
    'bad signal names must fail loudly; underscore notify must point at the dashed name'
);

$notifies = 0;
Bridge::disconnect($btn, $goodNotify);
Bridge::connect($btn, 'notify::use-underline', function () use (&$notifies): void {
    $notifies++;
});
GtkButton::setUseUnderline($btn, true);
Bridge::pump(100);
check($notifies === 1, 'NOTIFY_OK', "expected 1 notify, saw {$notifies}");

// ---- verdict -------------------------------------------------------------

Bridge::release($win);

if ($failures > 0) {
    fwrite(STDERR, "smoke: {$failures} failure(s)\n");
    exit(1);
}

echo "SMOKE_OK\n";
