<?php
/*
 * Smoke test: every Bridge mechanism proven live against real GTK.
 * Window + button, a real "clicked" signal into a PHP callable,
 * close-request return-value writeback (veto then allow), the handle
 * registry, the property fallback, the connect guard failure paths, and the
 * input controllers (key / motion / scroll / click) plus GdkKeyval.
 * Needs the box's logged-in seat. Prints SMOKE_OK when everything held.
 *
 * Run on the Linux box: php examples/smoke.php
 */

declare(strict_types=1);

use Gtk\Bridge\Bridge;
use Gtk\Gdk\GdkKeyval\GdkKeyval;
use Gtk\Gtk\GtkBox\GtkBox;
use Gtk\Gtk\GtkButton\GtkButton;
use Gtk\Gtk\GtkEventController\GtkEventController;
use Gtk\Gtk\GtkEventControllerKey\GtkEventControllerKey;
use Gtk\Gtk\GtkEventControllerMotion\GtkEventControllerMotion;
use Gtk\Gtk\GtkEventControllerScroll\GtkEventControllerScroll;
use Gtk\Gtk\GtkGesture\GtkGesture;
use Gtk\Gtk\GtkGestureClick\GtkGestureClick;
use Gtk\Gtk\GtkGestureSingle\GtkGestureSingle;
use Gtk\Gtk\GtkPopover\GtkPopover;
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

// ---- input: event controllers, gestures, keyvals -------------------------
// Each controller goes onto the window, every one of its signals is connected
// with a counting callback, then it comes off again. Real key/pointer events
// cannot be synthesized from PHP, so firing is proven on a notify signal of
// the controller itself; the input-signal counts are printed, not asserted.

$fired = [];
$counter = function (string $label) use (&$fired): Closure {
    $fired[$label] = 0;

    return function () use ($label, &$fired): bool {
        $fired[$label]++;

        return false; // gboolean signals: let GTK continue
    };
};

$key = GtkEventControllerKey::new_();
$motion = GtkEventControllerMotion::new_();
$scroll = GtkEventControllerScroll::new_(3); // GTK_EVENT_CONTROLLER_SCROLL_BOTH_AXES
$click = GtkGestureClick::new_();
check(
    $key !== 0 && $motion !== 0 && $scroll !== 0 && $click !== 0
    && Bridge::typeName($key) === 'GtkEventControllerKey'
    && Bridge::typeName($motion) === 'GtkEventControllerMotion'
    && Bridge::typeName($scroll) === 'GtkEventControllerScroll'
    && Bridge::typeName($click) === 'GtkGestureClick'
    && Bridge::isA($click, 'GtkGestureSingle')
    && Bridge::isA($click, 'GtkEventController'),
    'CONTROLLERS_NEW_OK',
    'controller constructors returned the wrong handles'
);

$signals = [
    $key => ['key-pressed', 'key-released', 'modifiers', 'im-update'],
    $motion => ['motion', 'enter', 'leave'],
    $scroll => ['scroll', 'scroll-begin', 'scroll-end', 'decelerate'],
    $click => ['pressed', 'released', 'stopped', 'unpaired-release'],
];
$handlerIds = [];
foreach ($signals as $controller => $names) {
    GtkWidget::addController($win, $controller);
    foreach ($names as $name) {
        $label = Bridge::typeName($controller) . '::' . $name;
        $handlerIds[$label] = Bridge::connect($controller, $name, $counter($label));
    }
}
$badIds = array_keys(array_filter($handlerIds, fn (int $id): bool => $id <= 0));
check($badIds === [], 'CONTROLLER_CONNECT_OK', 'no handler id for ' . implode(', ', $badIds));
foreach ($handlerIds as $label => $id) {
    echo "  connected {$label} id={$id}\n";
}

check(
    GtkEventController::getWidget($key) === $win
    && GtkEventController::getWidget($click) === $win
    && GtkEventController::getPropagationPhase($key) === 2   // GTK_PHASE_BUBBLE
    && GtkEventController::getPropagationLimit($key) === 1   // GTK_LIMIT_SAME_NATIVE
    && GtkEventController::getName($key) === null
    && GtkEventController::getCurrentEventState($key) === 0
    && GtkEventController::getCurrentEventTime($key) === 0
    && GtkEventController::getCurrentEventDevice($key) === 0,
    'CONTROLLER_READ_OK',
    'controller getters answered wrong on an attached, idle controller'
);

$phaseNotifies = 0;
$phaseId = Bridge::connect($key, 'notify::propagation-phase', function (int $sender) use ($key, &$phaseNotifies): void {
    if ($sender === $key) {
        $phaseNotifies++;
    }
});
GtkEventController::setPropagationPhase($key, 1); // GTK_PHASE_CAPTURE
GtkEventController::setPropagationLimit($key, 0); // GTK_LIMIT_NONE
GtkEventController::setName($key, 'smoke-keys');
Bridge::pump(50);
check(
    $phaseId > 0 && $phaseNotifies === 1
    && GtkEventController::getPropagationPhase($key) === 1
    && GtkEventController::getPropagationLimit($key) === 0
    && GtkEventController::getName($key) === 'smoke-keys',
    'CONTROLLER_WRITE_OK',
    "setter round-trip or controller notify broke (notifies={$phaseNotifies})"
);
GtkEventController::setName($key, null);
GtkEventController::reset($key);

// GtkEventControllerKey::getGroup is only valid inside a key handler
// (GTK asserts a current event), so it is not called here.
check(
    GtkEventControllerKey::getImContext($key) === 0
    && GtkEventControllerMotion::containsPointer($motion) === false
    && GtkEventControllerMotion::isPointer($motion) === false
    && GtkEventControllerScroll::getFlags($scroll) === 3
    && GtkEventControllerScroll::getUnit($scroll) === 0, // GDK_SCROLL_UNIT_WHEEL
    'CONTROLLER_KINDS_OK',
    'key/motion/scroll getters answered wrong'
);
GtkEventControllerScroll::setFlags($scroll, 16); // GTK_EVENT_CONTROLLER_SCROLL_KINETIC
check(GtkEventControllerScroll::getFlags($scroll) === 16, 'SCROLL_FLAGS_OK', 'setFlags did not round-trip');

// GtkGesture::getBoundingBoxCenter is only valid while a gesture is
// active: on an idle gesture GTK 4.18.6 inspects a NULL last event and
// prints three Gdk-CRITICALs, so it is not called here.
GtkGestureSingle::setButton($click, 3);
GtkGestureSingle::setExclusive($click, true);
GtkGestureSingle::setTouchOnly($click, true);
check(
    GtkGestureSingle::getButton($click) === 3
    && GtkGestureSingle::getExclusive($click) === true
    && GtkGestureSingle::getTouchOnly($click) === true
    && GtkGestureSingle::getCurrentButton($click) === 0
    && GtkGesture::isActive($click) === false
    && GtkGesture::isRecognized($click) === false
    && GtkGesture::getBoundingBox($click) === null
    && GtkGesture::getDevice($click) === 0
    && GtkGesture::getGroup($click) === [$click]
    && is_bool(GtkGesture::setState($click, 1)), // GTK_EVENT_SEQUENCE_CLAIMED
    'GESTURE_OK',
    'gesture getters/setters answered wrong on an idle click gesture'
);
GtkGestureSingle::setButton($click, 1);
GtkGestureSingle::setTouchOnly($click, false);

// ---- gboolean + out-param returns: FALSE is null ------------------------

$popover = GtkPopover::new_();
$unsetPointing = GtkPopover::getPointingTo($popover);
GtkPopover::setPointingTo($popover, 4.0, 5.0, 6.0, 7.0);
$setPointing = GtkPopover::getPointingTo($popover);
check(
    $unsetPointing === null
    && $setPointing === ['x' => 4, 'y' => 5, 'width' => 6, 'height' => 7],
    'POINTING_TO_OK',
    'getPointingTo must be null before setPointingTo and the rect after; saw '
        . var_export($unsetPointing, true) . ' / ' . var_export($setPointing, true)
);
Bridge::release($popover);

// Two unparented widgets share no ancestor, so GTK answers FALSE.
$orphanA = GtkButton::new_();
$orphanB = GtkButton::new_();
check(
    GtkWidget::computeBounds($orphanA, $orphanB) === null
    && GtkWidget::computePoint($orphanA, $orphanB, 1.0, 1.0) === null
    && GtkGesture::getBoundingBox($click) === null,
    'OUT_PARAM_NULL_OK',
    'computeBounds/computePoint across unrelated widgets and an idle getBoundingBox must be null'
);
Bridge::release($orphanA);
Bridge::release($orphanB);

// Grouped gestures must be attached to the same widget.
$click2 = GtkGestureClick::new_();
GtkWidget::addController($win, $click2);
GtkGesture::group($click, $click2);
$grouped = GtkGesture::isGroupedWith($click, $click2) && count(GtkGesture::getGroup($click)) === 2;
GtkGesture::ungroup($click2);
check(
    $grouped && !GtkGesture::isGroupedWith($click, $click2),
    'GESTURE_GROUP_OK',
    'group/ungroup did not round-trip'
);
GtkWidget::removeController($win, $click2);
Bridge::release($click2);

check(
    GdkKeyval::toUnicode(0x61) === 97
    && GdkKeyval::name(0xff0d) === 'Return'
    && GdkKeyval::name(0x0) === null
    && GdkKeyval::fromName('Return') === 0xff0d
    && GdkKeyval::fromUnicode(97) === 0x61
    && GdkKeyval::toUpper(0x61) === 0x41
    && GdkKeyval::toLower(0x41) === 0x61
    && GdkKeyval::isLower(0x61) && !GdkKeyval::isUpper(0x61)
    && GdkKeyval::convertCase(0x61) === ['lower' => 0x61, 'upper' => 0x41],
    'KEYVAL_OK',
    'keyval functions answered wrong'
);

Bridge::pump(100);
foreach ($fired as $label => $n) {
    echo "  fired {$label}={$n}\n";
}

foreach ($signals as $controller => $names) {
    GtkWidget::removeController($win, $controller);
}
check(
    GtkEventController::getWidget($key) === 0
    && GtkEventController::getWidget($click) === 0
    && Bridge::isValid($key) && Bridge::isValid($click),
    'CONTROLLER_REMOVE_OK',
    'removeController left the controller attached or killed the handle'
);
foreach ($signals as $controller => $names) {
    Bridge::release($controller);
}

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
