<?php

declare(strict_types=1);

beforeEach(fn () => testApplication());

enum SignalEmitTooWide: int
{
    case HUGE = 2 ** 40;
}

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

it('emits a signal the type does not have as GLib does: a critical, and null', function (): void {
    $run = gtkChild(<<<'PHP'
        return g_signal_emit_by_name(GtkEntry::new(), 'nope');
    PHP);

    expect($run['survived'])->toBeTrue()
        ->and($run['result'])->toBeNull()
        ->and($run['stderr'])->toContain("signal name 'nope' is invalid for instance");
});

it('refuses what it cannot pass', function (Closure $call, string $error, ?string $message = null): void {
    expect($call)->toThrow($error, $message);
})->with([
    'too few parameters' => [fn () => g_signal_emit_by_name(GtkScale::newWithRange(GtkOrientation::HORIZONTAL, 0.0, 1.0, 0.5), 'change-value', 1), ArgumentCountError::class],
    'pure enum for an int' => [fn () => g_signal_emit_by_name(GtkScale::newWithRange(GtkOrientation::HORIZONTAL, 0.0, 1.0, 0.5), 'move-slider', SignalEmitPure::A), TypeError::class],
    'wrong scalar type' => [fn () => g_signal_emit_by_name(GtkScale::newWithRange(GtkOrientation::HORIZONTAL, 0.0, 1.0, 0.5), 'change-value', 'one', 0.5), TypeError::class],
    'a string for a GParamSpec' => [fn () => g_signal_emit_by_name(GtkEntry::new(), 'notify::visibility', 'visibility'), TypeError::class, 'must be a GParam value for signal notify::visibility'],
    'a string for a boxed GtkTextIter' => [fn () => g_signal_emit_by_name(GtkTextView::new()->getBuffer(), 'insert-text', 'nope', 'x', 1), TypeError::class, 'must be a GtkTextIter value for signal insert-text in g_signal_emit_by_name(), string given'],
    'enum case past the parameter\'s C type' => [fn () => g_signal_emit_by_name(GtkScale::newWithRange(GtkOrientation::HORIZONTAL, 0.0, 1.0, 0.5), 'move-slider', SignalEmitTooWide::HUGE), ValueError::class, 'does not fit the GtkScrollType of signal move-slider'],
    'int past the parameter\'s C type' => [fn () => g_signal_emit_by_name(GtkLabel::new(''), 'query-tooltip', 2 ** 40, 0, false, null), ValueError::class, 'does not fit the gint of signal query-tooltip'],
]);

it('passes a GtkTextIter to a boxed parameter and hands it to the handler as a GtkTextIter', function (): void {
    $buffer = GtkTextView::new()->getBuffer();
    $buffer->setText('ab', -1);
    $seen = [];
    g_signal_connect($buffer, 'insert-text', function (GtkTextBuffer $b, GtkTextIter $at, string $text) use (&$seen): void { $seen = [$at->getOffset(), $text]; });

    g_signal_emit_by_name($buffer, 'insert-text', $buffer->getEndIter(), 'x', 1);

    expect($seen)->toBe([2, 'x'])
        ->and($buffer->getText($buffer->getStartIter(), $buffer->getEndIter(), false))->toBe('abx');
});

it('passes a null GParamSpec, and an address 0 iter that GTK answers with a critical', function (): void {
    $run = gtkChild(<<<'PHP'
        $entry = GtkEntry::new();
        $seen = 'not called';
        g_signal_connect($entry, 'notify::visibility', function (GtkEntry $e, ?GParamSpec $pspec) use (&$seen): void { $seen = $pspec; });
        g_signal_emit_by_name($entry, 'notify::visibility', null);
        g_signal_emit_by_name(GtkTextView::new()->getBuffer(), 'insert-text', 0, 'x', 1);

        return $seen;
    PHP);

    expect($run['survived'])->toBeTrue()
        ->and($run['result'])->toBeNull()
        ->and($run['stderr'])->toContain("gtk_text_buffer_real_insert_text: assertion 'iter != NULL' failed");
});

it('writes a handler\'s return of the signal\'s type, and leaves the default for another', function (): void {
    gtk_init();
    $notebook = GtkNotebook::new();
    $other = GtkNotebook::new();
    $page = GtkLabel::new('page');
    $notebook->appendPage($page, null);

    $handler = g_signal_connect($notebook, 'create-window', fn (GtkNotebook $n, GtkWidget $p): GtkNotebook => $other);
    $created = g_signal_emit_by_name($notebook, 'create-window', $page);
    g_signal_handler_disconnect($notebook, $handler);
    g_signal_connect($notebook, 'create-window', fn (GtkNotebook $n, GtkWidget $p): GtkLabel => GtkLabel::new('not a notebook'));

    expect($created)->toBe($other)
        ->and(g_signal_emit_by_name($notebook, 'create-window', $page))->toBeNull();
});

it('groups text buffer edits into user actions', function (): void {
    $buffer = GtkTextView::new()->getBuffer();
    $events = [];
    g_signal_connect($buffer, 'begin-user-action', function () use (&$events): void { $events[] = 'begin'; });
    g_signal_connect($buffer, 'end-user-action', function () use (&$events): void { $events[] = 'end'; });
    g_signal_connect($buffer, 'changed', function () use (&$events): void { $events[] = 'changed'; });

    $buffer->setText('old', -1);
    // setText inside a user action starts an irreversible action GTK's undo history refuses there.
    g_object_set_property($buffer, 'enable-undo', false);
    $events = [];
    $buffer->beginUserAction();
    $buffer->beginUserAction();
    $buffer->setText('new', -1);
    $buffer->endUserAction();
    $buffer->endUserAction();

    expect($events)->toBe(['begin', 'changed', 'changed', 'end']);
});

/** The GParamSpec a notify::visibility handler receives from an entry. */
function visibilityParamSpec(): GParamSpec
{
    $entry = GtkEntry::new();
    $received = [];
    g_signal_connect($entry, 'notify::visibility', function (GtkEntry $e, GParamSpec $pspec) use (&$received): void { $received[] = $pspec; });
    $entry->setVisibility(false);

    expect($received)->toHaveCount(1);

    return $received[0];
}

it('hands a notify handler the property\'s GParamSpec', function (): void {
    expect(visibilityParamSpec())->toBeInstanceOf(GParamSpec::class)
        ->and(visibilityParamSpec())->toBe(visibilityParamSpec());
});

it('reads a GParamSpec\'s name with g_param_spec_get_name', function (): void {
    expect(visibilityParamSpec()->getName())->toBe('visibility');
});

it('reads a GParamSpec\'s nick with g_param_spec_get_nick', function (): void {
    // GTK registers its properties without a nick, and GLib answers the name instead.
    expect(visibilityParamSpec()->getNick())->toBe('visibility');
});

it('reads a GParamSpec\'s value type name with G_PARAM_SPEC_VALUE_TYPE', function (): void {
    expect(visibilityParamSpec()->getValueType())->toBe('gboolean');
});

it('reads a GParamSpec\'s blurb with g_param_spec_get_blurb, null when the property has none', function (): void {
    expect(visibilityParamSpec()->getBlurb())->toBeNull();
});
