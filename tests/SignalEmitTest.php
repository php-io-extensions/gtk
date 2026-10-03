<?php

declare(strict_types=1);

beforeEach(fn () => testApplication());

enum SignalEmitPure
{
    case A;
}

it('emits a void signal the way the engine does', function (): void {
    $entry = GtkEntry::new();
    $hits = [];
    g_signal_connect($entry, 'activate', function (GtkEntry $from) use (&$hits): void { $hits[] = $from; });

    expect(g_signal_emit_by_name($entry, 'activate'))->toBeNull()
        ->and($hits)->toBe([$entry]);
});

it('passes typed parameters and returns the handler result', function (): void {
    $scale = GtkScale::newWithRange(GtkOrientation::HORIZONTAL, 0.0, 10.0, 1.0);
    $seen = [];
    g_signal_connect($scale, 'change-value', function (GtkScale $from, int $scroll, float $value) use (&$seen): bool {
        $seen[] = [$scroll, $value];

        return true;
    });

    expect(g_signal_emit_by_name($scale, 'change-value', 1, 3))->toBeTrue()
        ->and($seen)->toBe([[1, 3.0]]);
});

it('passes objects of the declared type, or null', function (): void {
    $label = GtkLabel::new('x');
    $seen = [];
    g_signal_connect($label, 'query-tooltip', function (GtkLabel $from, int $x, int $y, bool $keyboard, ?GObject $tooltip) use (&$seen): bool {
        $seen[] = [$x, $y, $keyboard, $tooltip];

        return false;
    });

    expect(g_signal_emit_by_name($label, 'query-tooltip', 1, 2, true, null))->toBeFalse()
        ->and($seen)->toBe([[1, 2, true, null]])
        ->and(fn () => g_signal_emit_by_name($label, 'query-tooltip', 1, 2, true, GtkLabel::new('not a tooltip')))->toThrow(TypeError::class, 'GtkTooltip');
});

it('refuses what it cannot pass', function (Closure $call, string $error): void {
    expect($call)->toThrow($error);
})->with([
    'unknown signal' => [fn () => g_signal_emit_by_name(GtkEntry::new(), 'nope'), ValueError::class],
    'too few parameters' => [fn () => g_signal_emit_by_name(GtkScale::newWithRange(GtkOrientation::HORIZONTAL, 0.0, 1.0, 0.5), 'change-value', 1), ArgumentCountError::class],
    'pure enum for an int' => [fn () => g_signal_emit_by_name(GtkScale::newWithRange(GtkOrientation::HORIZONTAL, 0.0, 1.0, 0.5), 'move-slider', SignalEmitPure::A), TypeError::class],
    'wrong scalar type' => [fn () => g_signal_emit_by_name(GtkScale::newWithRange(GtkOrientation::HORIZONTAL, 0.0, 1.0, 0.5), 'change-value', 'one', 0.5), TypeError::class],
    'GParamSpec parameter' => [fn () => g_signal_emit_by_name(GtkEntry::new(), 'notify::visibility', null), ValueError::class],
    'boxed parameter' => [fn () => g_signal_emit_by_name(GtkTextView::new()->getBuffer(), 'insert-text', 0, 'x', 1), ValueError::class],
]);

it('groups text buffer edits into user actions', function (): void {
    $buffer = GtkTextView::new()->getBuffer();
    $events = [];
    g_signal_connect($buffer, 'begin-user-action', function () use (&$events): void { $events[] = 'begin'; });
    g_signal_connect($buffer, 'end-user-action', function () use (&$events): void { $events[] = 'end'; });
    g_signal_connect($buffer, 'changed', function () use (&$events): void { $events[] = 'changed'; });

    $buffer->setText('old');
    $events = [];
    $buffer->beginUserAction();
    $buffer->beginUserAction();
    $buffer->setText('new');
    $buffer->endUserAction();
    $buffer->endUserAction();

    expect($events)->toBe(['begin', 'changed', 'changed', 'end']);
});
