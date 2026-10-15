<?php

declare(strict_types=1);

beforeEach(fn () => testApplication());

it('tags lines and ranges of a buffer through its tag table and properties', function (): void {
    $buffer = GtkTextView::new()->getBuffer();
    $buffer->setText("one\ntwo\nthree");
    $line = GtkTextTag::new(null);
    $range = GtkTextTag::new('range');
    g_object_set_property($line, 'paragraph-background', 'rgba(255, 0, 0, 1)');
    g_object_set_property($range, 'foreground', '#00ff00');
    $table = $buffer->getTagTable();
    $added = [$table->add($line), $table->add($range)];
    $buffer->applyTag($line, $buffer->getIterAtLine(1), $buffer->getIterAtLine(2));
    $buffer->applyTag($range, $buffer->getIterAtLineOffset(2, 1), $buffer->getIterAtLineOffset(2, 3));

    expect($added)->toBe([true, true])
        ->and($table->lookup('range'))->toBe($range)
        ->and($table->lookup('none'))->toBeNull()
        ->and(g_object_get_property($line, 'paragraph-background-set'))->toBeTrue()
        ->and(g_object_get_property($range, 'foreground-set'))->toBeTrue()
        ->and($buffer->getIterAtLineOffset(1, 0)->hasTag($line))->toBeTrue()
        ->and($buffer->getIterAtLineOffset(0, 0)->hasTag($line))->toBeFalse()
        ->and($buffer->getIterAtLineOffset(2, 2)->getTags())->toBe([$range])
        ->and($buffer->getIterAtLineOffset(2, 0)->getTags())->toBe([])
        ->and($buffer->getIterAtLine(9))->toBeNull()
        ->and($buffer->getIterAtLineOffset(0, 9))->toBeNull()
        ->and($buffer->getLineCount())->toBe(3);

    $buffer->removeTag($line, $buffer->getStartIter(), $buffer->getEndIter());
    $table->remove($range);

    expect($buffer->getIterAtLineOffset(1, 0)->hasTag($line))->toBeFalse()
        ->and($table->lookup('range'))->toBeNull()
        ->and(fn () => $buffer->applyTag(GtkTextTag::new(null), $buffer->getStartIter(), $buffer->getEndIter()))->toThrow(ValueError::class, 'tag table')
        ->and(fn () => $buffer->applyTag($line, GtkTextView::new()->getBuffer()->getStartIter(), $buffer->getEndIter()))->toThrow(ValueError::class, 'iter of this buffer')
        ->and(fn () => $table->add($line))->toThrow(ValueError::class, 'already in a tag table')
        ->and(fn () => $table->remove($range))->toThrow(ValueError::class, 'not in this table')
        ->and(fn () => g_object_set_property($line, 'no-such-property', 1))->toThrow(ValueError::class)
        ->and(fn () => g_object_set_property($line, 'foreground', 3))->toThrow(TypeError::class)
        ->and(fn () => g_object_set_property($line, 'tabs', null))->toThrow(ValueError::class, 'g_object_set_property()');
});

it('reads iters, the selection and the insert mark', function (): void {
    $buffer = GtkTextView::new()->getBuffer();
    $buffer->setText("ab\ncdé");
    $none = $buffer->getSelectionBounds();
    $buffer->selectRange($buffer->getIterAtLineOffset(1, 1), $buffer->getIterAtLineOffset(1, 3));
    [$from, $to] = $buffer->getSelectionBounds();

    expect($none)->toBeNull()
        ->and([$from->getLine(), $from->getLineOffset(), $from->getOffset()])->toBe([1, 1, 4])
        ->and([$to->getLine(), $to->getLineOffset()])->toBe([1, 3])
        ->and($buffer->getIterAtMark($buffer->getInsert())->getOffset())->toBe(4)
        ->and($buffer->getInsert())->toBeInstanceOf(GtkTextMark::class)
        ->and([$buffer->getStartIter()->getOffset(), $buffer->getEndIter()->getOffset()])->toBe([0, 6])
        ->and(fn () => GtkTextView::new()->getBuffer()->getIterAtMark($buffer->getInsert()))->toThrow(ValueError::class, 'mark of this buffer');
});

it('scrolls a text view by its scrolled window\'s adjustments and measures a line', function (): void {
    $view = GtkTextView::new();
    $view->setMonospace(true);
    $view->setCursorVisible(false);
    $view->getBuffer()->setText(implode("\n", range(1, 300)));
    $scrolled = GtkScrolledWindow::new();
    $scrolled->setChild($view);
    $window = GtkWindow::new();
    $window->setDefaultSize(200, 150);
    $window->setChild($scrolled);
    $window->present();
    $vertical = $scrolled->getVadjustment();
    iterateUntil(fn (): bool => $vertical->getUpper() - $vertical->getPageSize() >= 100.0);
    $moved = 0;
    g_signal_connect($vertical, 'value-changed', function () use (&$moved): void { $moved++; });
    $vertical->setValue(100.0);
    [$y, $height] = $view->getLineYrange($view->getBuffer()->getIterAtLine(10));
    $window->destroy();

    expect($view->getMonospace())->toBeTrue()
        ->and($view->getCursorVisible())->toBeFalse()
        ->and($vertical)->toBeInstanceOf(GtkAdjustment::class)
        ->and($scrolled->getHadjustment())->toBeInstanceOf(GtkAdjustment::class)
        ->and($vertical->getValue())->toBe(100.0)
        ->and($vertical->getLower())->toBe(0.0)
        ->and($moved)->toBe(1)
        ->and($height)->toBeGreaterThan(0)
        ->and($y)->toBeGreaterThanOrEqual(9 * $height);
});

it('refuses an iter whose buffer text changed since it was taken', function (): void {
    $buffer = GtkTextView::new()->getBuffer();
    $buffer->setText("one\ntwo");
    $tag = GtkTextTag::new(null);
    $buffer->getTagTable()->add($tag);
    $stale = $buffer->getIterAtLine(1);
    $buffer->setText('x');

    expect(fn () => $stale->getTags())->toThrow(GtkException::class, 'stale')
        ->and(fn () => $stale->getLine())->toThrow(GtkException::class, 'stale')
        ->and(fn () => $stale->getLineOffset())->toThrow(GtkException::class, 'stale')
        ->and(fn () => $stale->getOffset())->toThrow(GtkException::class, 'stale')
        ->and(fn () => $stale->hasTag($tag))->toThrow(GtkException::class, 'stale')
        ->and(fn () => $buffer->applyTag($tag, $stale, $buffer->getEndIter()))->toThrow(GtkException::class, 'stale')
        ->and(fn () => $buffer->selectRange($buffer->getStartIter(), $stale))->toThrow(GtkException::class, 'stale')
        ->and($buffer->getIterAtLine(0)->getLine())->toBe(0);

    $fresh = $buffer->getStartIter();
    $buffer->setText('y');

    expect(fn () => $fresh->getOffset())->toThrow(GtkException::class, 'stale');
});

it('reads a tag whose table was freed as in no table', function (): void {
    $tag = GtkTextTag::new(null);
    $first = GtkTextView::new()->getBuffer();
    $first->getTagTable()->add($tag);
    unset($first);
    gc_collect_cycles();
    $second = GtkTextView::new()->getBuffer();

    expect($second->getTagTable()->add($tag))->toBeTrue();
});

it('refuses property values GLib would only log or truncate', function (): void {
    $tag = GtkTextTag::new(null);

    expect(fn () => g_object_set_property($tag, 'left-margin', -5))->toThrow(ValueError::class, 'left-margin')
        ->and(fn () => g_object_set_property($tag, 'scale', -1.0))->toThrow(ValueError::class, 'out of range for property scale')
        ->and(fn () => g_object_set_property($tag, 'left-margin', 2 ** 40))->toThrow(ValueError::class, 'property left-margin')
        ->and(fn () => g_object_set_property($tag, 'foreground', 3))->toThrow(TypeError::class, 'property foreground')
        ->and(fn () => g_object_set_property($tag, 'tabs', null))->toThrow(ValueError::class, 'property tabs')
        ->and(g_object_get_property($tag, 'left-margin'))->toBe(0);

    g_object_set_property($tag, 'left-margin', 12);
    g_object_set_property($tag, 'scale', 1.5);

    expect(g_object_get_property($tag, 'left-margin'))->toBe(12)
        ->and(g_object_get_property($tag, 'scale'))->toBe(1.5);
});

it('stales an iter taken inside an insert-text or delete-range handler once the change lands', function (): void {
    $buffer = GtkTextView::new()->getBuffer();
    $buffer->setText("abc\ndef");
    $taken = [];
    g_signal_connect($buffer, 'insert-text', function () use ($buffer, &$taken): void { $taken['insert'] = $buffer->getStartIter(); });
    g_signal_connect($buffer, 'delete-range', function () use ($buffer, &$taken): void { $taken['delete'] = $buffer->getStartIter(); });
    $buffer->setText("new\ntext");

    expect(array_keys($taken))->toContain('insert', 'delete')
        ->and(fn () => $taken['insert']->getOffset())->toThrow(GtkException::class, 'stale')
        ->and(fn () => $taken['delete']->getTags())->toThrow(GtkException::class, 'stale');
});

it('refuses NaN for a float property', function (): void {
    expect(fn () => g_object_set_property(GtkTextTag::new(null), 'scale', NAN))->toThrow(ValueError::class, 'property scale');
});

it('stales the first iter of a buffer taken inside a single-emission handler', function (string $signal, string $initial, string $replacement): void {
    $buffer = GtkTextView::new()->getBuffer();
    $buffer->setText($initial);
    // No iter was handed out before the handler: the first one is taken inside it.
    $taken = null;
    g_signal_connect($buffer, $signal, function () use ($buffer, &$taken): void { $taken ??= $buffer->getStartIter(); });
    $buffer->setText($replacement);

    expect($taken)->toBeInstanceOf(GtkTextIter::class)
        ->and(fn () => $taken->getOffset())->toThrow(GtkException::class, 'stale')
        ->and(fn () => $taken->getTags())->toThrow(GtkException::class, 'stale');
})->with([
    'insert only' => ['insert-text', '', 'xyz'],
    'delete only' => ['delete-range', 'abc', ''],
]);
