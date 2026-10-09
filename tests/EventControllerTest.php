<?php

declare(strict_types=1);

beforeEach(fn () => testApplication());

it('makes each controller and gesture as its own class', function (): void {
    expect(GtkEventControllerKey::new())->toBeInstanceOf(GtkEventController::class)
        ->and(GtkEventControllerMotion::new())->toBeInstanceOf(GtkEventController::class)
        ->and(GtkEventControllerFocus::new())->toBeInstanceOf(GtkEventController::class)
        ->and(GtkEventControllerScroll::new(GTK_EVENT_CONTROLLER_SCROLL_BOTH_AXES))->toBeInstanceOf(GtkEventController::class)
        ->and(GtkGestureClick::new())->toBeInstanceOf(GtkGestureSingle::class)
        ->and(GtkGestureClick::new())->toBeInstanceOf(GtkGesture::class);
});

it('sets the propagation phase', function (): void {
    $key = GtkEventControllerKey::new();
    $before = $key->getPropagationPhase();
    $key->setPropagationPhase(GtkPropagationPhase::CAPTURE);

    expect($before)->toBe(GtkPropagationPhase::BUBBLE)
        ->and($key->getPropagationPhase())->toBe(GtkPropagationPhase::CAPTURE);
});

it('adds a controller to a widget and removes it, the PHP object outliving both', function (): void {
    $window = GtkWindow::new();
    $key = GtkEventControllerKey::new();
    $window->addController($key);
    $on = $key->getWidget();
    $window->removeController($key);

    expect($on)->toBe($window)
        ->and($key->getWidget())->toBeNull()
        ->and($key->getPropagationPhase())->toBe(GtkPropagationPhase::BUBBLE);
});

it('reads and sets scroll flags, and starts in wheel units', function (): void {
    $scroll = GtkEventControllerScroll::new(GTK_EVENT_CONTROLLER_SCROLL_VERTICAL);
    $vertical = $scroll->getFlags();
    $scroll->setFlags(GTK_EVENT_CONTROLLER_SCROLL_BOTH_AXES | GTK_EVENT_CONTROLLER_SCROLL_DISCRETE);

    expect($vertical)->toBe(GTK_EVENT_CONTROLLER_SCROLL_VERTICAL)
        ->and($scroll->getFlags())->toBe(GTK_EVENT_CONTROLLER_SCROLL_BOTH_AXES | GTK_EVENT_CONTROLLER_SCROLL_DISCRETE)
        ->and($scroll->getUnit())->toBe(GdkScrollUnit::WHEEL)
        ->and([GTK_EVENT_CONTROLLER_SCROLL_NONE, GTK_EVENT_CONTROLLER_SCROLL_VERTICAL, GTK_EVENT_CONTROLLER_SCROLL_HORIZONTAL, GTK_EVENT_CONTROLLER_SCROLL_BOTH_AXES, GTK_EVENT_CONTROLLER_SCROLL_DISCRETE, GTK_EVENT_CONTROLLER_SCROLL_KINETIC])
        ->toBe([0, 1, 2, 3, 4, 8]);
});

it('picks a gesture button, and reads none outside an event', function (): void {
    $click = GtkGestureClick::new();
    $primary = $click->getButton();
    $click->setButton(0);

    expect($primary)->toBe(1)
        ->and($click->getButton())->toBe(0)
        ->and($click->getCurrentButton())->toBe(0);
});

it('hands key signals keyval, keycode and state as ints, and takes the handled flag back', function (): void {
    $key = GtkEventControllerKey::new();
    $seen = [];
    g_signal_connect($key, 'key-pressed', function (GtkEventControllerKey $from, int $keyval, int $keycode, int $state) use (&$seen): bool {
        $seen[] = ['pressed', $keyval, $keycode, $state];

        return true;
    });
    g_signal_connect($key, 'key-released', function (GtkEventControllerKey $from, int $keyval, int $keycode, int $state) use (&$seen): void {
        $seen[] = ['released', $keyval, $keycode, $state];
    });
    g_signal_connect($key, 'modifiers', function (GtkEventControllerKey $from, int $state) use (&$seen): bool {
        $seen[] = ['modifiers', $state];

        return false;
    });

    expect(g_signal_emit_by_name($key, 'key-pressed', 0x61, 38, GDK_SHIFT_MASK))->toBeTrue()
        ->and(g_signal_emit_by_name($key, 'key-released', 0x61, 38, 0))->toBeNull()
        ->and(g_signal_emit_by_name($key, 'modifiers', GDK_CONTROL_MASK | GDK_ALT_MASK))->toBeFalse()
        ->and($seen)->toBe([['pressed', 0x61, 38, GDK_SHIFT_MASK], ['released', 0x61, 38, 0], ['modifiers', GDK_CONTROL_MASK | GDK_ALT_MASK]]);
});

it('hands pointer, scroll, click and focus signals their coordinates', function (): void {
    [$motion, $scroll, $click, $focus] = [GtkEventControllerMotion::new(), GtkEventControllerScroll::new(GTK_EVENT_CONTROLLER_SCROLL_BOTH_AXES), GtkGestureClick::new(), GtkEventControllerFocus::new()];
    $seen = [];
    g_signal_connect($motion, 'enter', function (GtkEventControllerMotion $from, float $x, float $y) use (&$seen): void { $seen[] = ['enter', $x, $y]; });
    g_signal_connect($motion, 'motion', function (GtkEventControllerMotion $from, float $x, float $y) use (&$seen): void { $seen[] = ['motion', $x, $y]; });
    g_signal_connect($motion, 'leave', function (GtkEventControllerMotion $from) use (&$seen): void { $seen[] = ['leave']; });
    g_signal_connect($scroll, 'scroll', function (GtkEventControllerScroll $from, float $dx, float $dy) use (&$seen): bool {
        $seen[] = ['scroll', $dx, $dy];

        return true;
    });
    g_signal_connect($click, 'pressed', function (GtkGestureClick $from, int $n, float $x, float $y) use (&$seen): void { $seen[] = ['pressed', $n, $x, $y]; });
    g_signal_connect($click, 'released', function (GtkGestureClick $from, int $n, float $x, float $y) use (&$seen): void { $seen[] = ['released', $n, $x, $y]; });
    g_signal_connect($focus, 'leave', function (GtkEventControllerFocus $from) use (&$seen): void { $seen[] = ['focus-leave']; });

    g_signal_emit_by_name($motion, 'enter', 1.0, 2.0);
    g_signal_emit_by_name($motion, 'motion', 3.5, 4.5);
    g_signal_emit_by_name($motion, 'leave');
    $handled = g_signal_emit_by_name($scroll, 'scroll', 0.0, -1.5);
    g_signal_emit_by_name($click, 'pressed', 1, 5.0, 6.0);
    g_signal_emit_by_name($click, 'released', 1, 5.0, 6.0);
    g_signal_emit_by_name($focus, 'leave');

    expect($handled)->toBeTrue()
        ->and($seen)->toBe([['enter', 1.0, 2.0], ['motion', 3.5, 4.5], ['leave'], ['scroll', 0.0, -1.5], ['pressed', 1, 5.0, 6.0], ['released', 1, 5.0, 6.0], ['focus-leave']]);
});

it('turns keyvals into code points and lowercase', function (): void {
    expect([gdk_keyval_to_unicode(0x61), gdk_keyval_to_unicode(0x0E9), gdk_keyval_to_unicode(0x20AC), gdk_keyval_to_unicode(0xFFE1)])
        ->toBe([0x61, 0xE9, 0x20AC, 0])
        ->and([gdk_keyval_to_lower(0x41), gdk_keyval_to_lower(0x61)])->toBe([0x61, 0x61]);
});

it('carries the modifier masks GDK defines', function (): void {
    expect([GDK_SHIFT_MASK, GDK_LOCK_MASK, GDK_CONTROL_MASK, GDK_ALT_MASK, GDK_BUTTON1_MASK, GDK_BUTTON5_MASK, GDK_SUPER_MASK, GDK_HYPER_MASK, GDK_META_MASK])
        ->toBe([1, 2, 4, 8, 1 << 8, 1 << 12, 1 << 26, 1 << 27, 1 << 28])
        ->and(GDK_MODIFIER_MASK & GDK_SHIFT_MASK)->toBe(GDK_SHIFT_MASK);
});

it('has no current event outside a signal GTK delivered', function (): void {
    $scroll = GtkEventControllerScroll::new(GTK_EVENT_CONTROLLER_SCROLL_BOTH_AXES);
    $during = 'unset';
    g_signal_connect($scroll, 'scroll', function (GtkEventControllerScroll $from, float $dx, float $dy) use (&$during): bool {
        $during = $from->getCurrentEvent();

        return true;
    });
    g_signal_emit_by_name($scroll, 'scroll', 0.0, 1.0);

    expect($scroll->getCurrentEvent())->toBeNull()
        ->and($during)->toBeNull()
        ->and(is_subclass_of(GdkScrollEvent::class, GdkEvent::class))->toBeTrue();
});

it('names the relative directions GTK 4.20 reports for a scroll', function (): void {
    if (gtk_get_major_version() * 100 + gtk_get_minor_version() < 420) {
        test()->markTestSkipped('GdkScrollRelativeDirection is GTK 4.20+; this GTK is '.gtk_get_major_version().'.'.gtk_get_minor_version());
    }

    expect(array_map(fn (GdkScrollRelativeDirection $d): string => $d->name, GdkScrollRelativeDirection::cases()))->toBe(['IDENTICAL', 'INVERTED', 'UNKNOWN'])
        ->and(method_exists(GdkScrollEvent::class, 'getRelativeDirection'))->toBeTrue();
});

it('makes a legacy controller and an input method context that commits text to its handler', function (): void {
    $window = GtkWindow::new();
    $im = GtkIMMulticontext::new();
    $im->setClientWidget($window);
    $im->focusIn();
    $committed = [];
    g_signal_connect($im, 'commit', function (GtkIMMulticontext $from, string $text) use (&$committed): void {
        $committed[] = $text;
    });
    g_signal_emit_by_name($im, 'commit', 'é');
    $im->focusOut();
    $im->reset();
    $im->setClientWidget(null);

    expect(GtkEventControllerLegacy::new())->toBeInstanceOf(GtkEventController::class)
        ->and($im)->toBeInstanceOf(GtkIMContext::class)
        ->and($committed)->toBe(['é']);
});

it('names every GdkEventType at its C value', function (): void {
    expect(count(GdkEventType::cases()))->toBe(30)
        ->and([GdkEventType::BUTTON_PRESS->value, GdkEventType::SCROLL->value, GdkEventType::TOUCH_BEGIN->value, GdkEventType::TOUCH_END->value, GdkEventType::PAD_DIAL->value])
        ->toBe([2, 15, 17, 19, 29])
        ->and(is_subclass_of(GdkButtonEvent::class, GdkEvent::class) && is_subclass_of(GdkTouchEvent::class, GdkEvent::class))->toBeTrue();
});

it('computes a point between widgets of one window, and none between strangers', function (): void {
    $window = GtkWindow::new();
    $box = GtkBox::new(GtkOrientation::VERTICAL, 0);
    $window->setChild($box);

    expect($window->computePoint($box, 3.0, 4.0))->toBe([3.0, 4.0])
        ->and($window->computePoint(GtkBox::new(GtkOrientation::VERTICAL, 0), 3.0, 4.0))->toBeNull()
        ->and($window->getSurfaceTransform())->toHaveCount(2);
});

it('picks the innermost widget at a point, a disabled one only when asked', function (): void {
    $window = GtkWindow::new();
    $box = GtkBox::new(GtkOrientation::VERTICAL, 0);
    $button = GtkButton::newWithLabel('pick me');
    $box->append($button);
    $window->setChild($box);
    $window->setDefaultSize(200, 100);
    $window->present();
    for ($waited = 0; $button->getWidth() === 0 && $waited < 60; $waited++) {
        iterateFor(0.05);
    }
    $inside = $button->computePoint($window, 5.0, 5.0);
    $picked = $window->pick($inside[0], $inside[1], GTK_PICK_DEFAULT);
    $button->setSensitive(false);
    $skipped = $window->pick($inside[0], $inside[1], GTK_PICK_DEFAULT);
    $kept = $window->pick($inside[0], $inside[1], GTK_PICK_INSENSITIVE);
    $window->destroy();

    expect([GTK_PICK_DEFAULT, GTK_PICK_INSENSITIVE, GTK_PICK_NON_TARGETABLE])->toBe([0, 1, 2])
        ->and($picked === $button || $picked?->getParent() === $button || $picked?->getParent()?->getParent() === $button)->toBeTrue()
        ->and($skipped === $button)->toBeFalse()
        ->and($kept === $button || $kept?->getParent() === $button || $kept?->getParent()?->getParent() === $button)->toBeTrue();
});

it('makes a long-press gesture, touch-only when asked', function (): void {
    $press = GtkGestureLongPress::new();
    $before = $press->getTouchOnly();
    $press->setTouchOnly(true);
    $seen = [];
    g_signal_connect($press, 'pressed', function (GtkGestureLongPress $from, float $x, float $y) use (&$seen): void { $seen[] = [$x, $y]; });
    g_signal_emit_by_name($press, 'pressed', 7.0, 8.0);

    expect($press)->toBeInstanceOf(GtkGestureSingle::class)
        ->and([$before, $press->getTouchOnly()])->toBe([false, true])
        ->and($seen)->toBe([[7.0, 8.0]])
        ->and(method_exists(GdkEvent::class, 'getModifierState'))->toBeTrue();
});

it('reads GTK\'s settings through the default GtkSettings and g_object_get_property', function (): void {
    $settings = GtkSettings::getDefault();

    expect($settings)->toBeInstanceOf(GtkSettings::class)
        ->and(g_object_get_property($settings, 'gtk-long-press-time'))->toBeInt()->toBeGreaterThan(0)
        ->and(g_object_get_property($settings, 'gtk-dnd-drag-threshold'))->toBeInt()->toBeGreaterThan(0)
        ->and(fn () => g_object_get_property($settings, 'no-such-property'))->toThrow(ValueError::class);
});
