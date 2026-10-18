<?php

declare(strict_types=1);

beforeEach(fn () => testApplication());

/** The iter gtk_text_buffer_get_iter_at_line() writes, whatever it answers. */
function textLineIter(GtkTextBuffer $buffer, int $lineNumber): GtkTextIter
{
    $buffer->getIterAtLine($iter, $lineNumber);

    return $iter;
}

/** The iter gtk_text_buffer_get_iter_at_line_offset() writes, whatever it answers. */
function textLineOffsetIter(GtkTextBuffer $buffer, int $lineNumber, int $charOffset): GtkTextIter
{
    $buffer->getIterAtLineOffset($iter, $lineNumber, $charOffset);

    return $iter;
}

it('tags lines and ranges of a buffer through its tag table and properties', function (): void {
    $buffer = GtkTextView::new()->getBuffer();
    $buffer->setText("one\ntwo\nthree", -1);
    $line = GtkTextTag::new(null);
    $range = GtkTextTag::new('range');
    g_object_set_property($line, 'paragraph-background', 'rgba(255, 0, 0, 1)');
    g_object_set_property($range, 'foreground', '#00ff00');
    $table = $buffer->getTagTable();
    $added = [$table->add($line), $table->add($range)];
    $buffer->applyTag($line, textLineIter($buffer, 1), textLineIter($buffer, 2));
    $buffer->applyTag($range, textLineOffsetIter($buffer, 2, 1), textLineOffsetIter($buffer, 2, 3));

    expect($added)->toBe([true, true])
        ->and($table->lookup('range'))->toBe($range)
        ->and($table->lookup('none'))->toBeNull()
        ->and(g_object_get_property($line, 'paragraph-background-set'))->toBeTrue()
        ->and(g_object_get_property($range, 'foreground-set'))->toBeTrue()
        ->and(textLineOffsetIter($buffer, 1, 0)->hasTag($line))->toBeTrue()
        ->and(textLineOffsetIter($buffer, 0, 0)->hasTag($line))->toBeFalse()
        ->and(textLineOffsetIter($buffer, 2, 2)->getTags())->toBe([$range])
        ->and(textLineOffsetIter($buffer, 2, 0)->getTags())->toBe([])
        ->and($buffer->getLineCount())->toBe(3);

    $buffer->removeTag($line, $buffer->getStartIter(), $buffer->getEndIter());
    $table->remove($range);

    expect(textLineOffsetIter($buffer, 1, 0)->hasTag($line))->toBeFalse()
        ->and($table->lookup('range'))->toBeNull()
        ->and(fn () => g_object_set_property($line, 'foreground', 3))->toThrow(TypeError::class)
        ->and(fn () => g_object_set_property($line, 'tabs', 'x'))->toThrow(TypeError::class, 'must be a PangoTabArray value for property tabs in g_object_set_property(), string given');
});

it('writes the iter at a line or line offset to $iter and answers GTK\'s gboolean, in native parameter order', function (): void {
    $buffer = GtkTextView::new()->getBuffer();
    $buffer->setText("one\ntwo", -1);

    $atLine = $buffer->getIterAtLine($line, 1);
    $pastLines = $buffer->getIterAtLine($end, 9);
    $lastLine = $buffer->getIterAtLine($last, -1);
    $atOffset = $buffer->getIterAtLineOffset($offset, 1, 2);
    $pastLine = $buffer->getIterAtLineOffset($lineEnd, 0, 9);

    expect([$atLine, $line->getLine(), $line->getLineOffset()])->toBe([true, 1, 0])
        ->and([$pastLines, $end->getOffset()])->toBe([false, 7])
        ->and([$lastLine, $last->getLine()])->toBe([true, 1])
        ->and([$atOffset, $offset->getOffset()])->toBe([true, 6])
        ->and([$pastLine, $lineEnd->getLine(), $lineEnd->getLineOffset()])->toBe([false, 0, 3])
        ->and(fn () => $buffer->getIterAtLine($x, 4_294_967_296))->toThrow(ValueError::class, 'Argument #2 ($lineNumber) must be between -2147483648 and 2147483647')
        ->and(fn () => $buffer->getIterAtLineOffset($x, 0, -1))->toThrow(ValueError::class, 'Argument #3 ($charOffset) must be greater than or equal to 0')
        ->and(fn () => $buffer->getIterAtLineOffset($x, 0, 4_294_967_296))->toThrow(ValueError::class, 'Argument #3 ($charOffset) must be between -2147483648 and 2147483647');
});

it('hands GTK tags and iters from elsewhere, which it answers with criticals, changing nothing', function (): void {
    $run = gtkChild(<<<'PHP'
        $buffer = GtkTextView::new()->getBuffer();
        $buffer->setText('ab', -1);
        $tabled = GtkTextTag::new('tabled');
        $table = $buffer->getTagTable();
        $table->add($tabled);
        $stray = GtkTextTag::new(null);
        $buffer->applyTag($stray, $buffer->getStartIter(), $buffer->getEndIter());
        $buffer->applyTag($tabled, GtkTextView::new()->getBuffer()->getStartIter(), $buffer->getEndIter());
        $other = GtkTextView::new()->getBuffer()->getTagTable();
        $other->remove($tabled);
        g_object_set_property($tabled, 'no-such-property', 1);

        return [
            $buffer->getStartIter()->hasTag($stray),
            $buffer->getStartIter()->hasTag($tabled),
            $other->add($tabled),
            $table->add($tabled),
            $table->lookup('tabled') === $tabled,
        ];
    PHP);

    expect($run['result'])->toBe([false, false, false, false, true])
        ->and($run['stderr'])->toContain("gtk_text_buffer_apply_tag: assertion 'tag->priv->table == buffer->priv->tag_table' failed")
        ->and($run['stderr'])->toContain("gtk_text_buffer_apply_tag: assertion 'gtk_text_iter_get_buffer (start) == buffer' failed")
        ->and($run['stderr'])->toContain("gtk_text_tag_table_remove: assertion 'tag->priv->table == table' failed")
        ->and($run['stderr'])->toContain("gtk_text_tag_table_add: assertion 'tag->priv->table == NULL' failed")
        ->and($run['stderr'])->toContain("object class 'GtkTextTag' has no property named 'no-such-property'");
});

it('reads an iter at a character offset, -1 and past the end at the end', function (): void {
    $buffer = GtkTextView::new()->getBuffer();
    $buffer->setText("héllo\nworld", -1);

    expect($buffer->getIterAtOffset(2)->getOffset())->toBe(2)
        ->and($buffer->getIterAtOffset(7)->getLine())->toBe(1)
        ->and($buffer->getIterAtOffset(-1)->getOffset())->toBe(11)
        ->and($buffer->getIterAtOffset(99)->getOffset())->toBe(11);
});

it('reads iters, the selection and the insert mark', function (): void {
    $buffer = GtkTextView::new()->getBuffer();
    $buffer->setText("ab\ncdé", -1);
    $none = $buffer->getSelectionBounds($cursor, $alsoCursor);
    $buffer->selectRange(textLineOffsetIter($buffer, 1, 1), textLineOffsetIter($buffer, 1, 3));
    $some = $buffer->getSelectionBounds($from, $to);

    expect($none)->toBeFalse()
        ->and($cursor)->toBeInstanceOf(GtkTextIter::class)
        ->and($cursor->getOffset())->toBe($alsoCursor->getOffset())
        ->and($some)->toBeTrue()
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
    $view->getBuffer()->setText(implode("\n", range(1, 300)), -1);
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
    $view->getLineYrange(textLineIter($view->getBuffer(), 10), $y, $height);
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
    $buffer->setText("one\ntwo", -1);
    $tag = GtkTextTag::new(null);
    $buffer->getTagTable()->add($tag);
    $stale = textLineIter($buffer, 1);
    $buffer->setText('x', -1);

    expect(fn () => $stale->getTags())->toThrow(GtkException::class, 'stale')
        ->and(fn () => $stale->getLine())->toThrow(GtkException::class, 'stale')
        ->and(fn () => $stale->getLineOffset())->toThrow(GtkException::class, 'stale')
        ->and(fn () => $stale->getOffset())->toThrow(GtkException::class, 'stale')
        ->and(fn () => $stale->hasTag($tag))->toThrow(GtkException::class, 'stale')
        ->and(fn () => $buffer->applyTag($tag, $stale, $buffer->getEndIter()))->toThrow(GtkException::class, 'stale')
        ->and(fn () => $buffer->selectRange($buffer->getStartIter(), $stale))->toThrow(GtkException::class, 'stale')
        ->and($buffer->getText($buffer->getStartIter(), $buffer->getEndIter(), false))->toBe('x')
        ->and(textLineIter($buffer, 0)->getLine())->toBe(0);

    $fresh = $buffer->getStartIter();
    $buffer->setText('y', -1);

    expect(fn () => $fresh->getOffset())->toThrow(GtkException::class, 'stale');
});

it('adds a tag to a second table once its first table is freed', function (): void {
    $tag = GtkTextTag::new(null);
    $first = GtkTextView::new()->getBuffer();
    $first->getTagTable()->add($tag);
    unset($first);
    gc_collect_cycles();
    $second = GtkTextView::new()->getBuffer();

    expect($second->getTagTable()->add($tag))->toBeTrue();
});

it('hands GLib property values out of the property\'s range, which it warns about and leaves unset', function (): void {
    $run = gtkChild(<<<'PHP'
        $tag = GtkTextTag::new(null);
        g_object_set_property($tag, 'left-margin', -5);
        g_object_set_property($tag, 'scale', -1.0);
        g_object_set_property($tag, 'scale', NAN);

        return [g_object_get_property($tag, 'left-margin'), g_object_get_property($tag, 'scale')];
    PHP);

    expect($run['result'])->toBe([0, 1.0])
        ->and($run['stderr'])->toContain("value \"-5\" of type 'gint' is invalid or out of range for property 'left-margin' of type 'gint'")
        ->and($run['stderr'])->toContain("value \"-1.000000\" of type 'gdouble' is invalid or out of range for property 'scale' of type 'gdouble'")
        ->and($run['stderr'])->toContain("value \"nan\" of type 'gdouble' is invalid or out of range for property 'scale' of type 'gdouble'");
});

it('refuses property values with no form in the property\'s C type', function (): void {
    $tag = GtkTextTag::new(null);

    expect(fn () => g_object_set_property($tag, 'left-margin', 2 ** 40))->toThrow(ValueError::class, 'property left-margin')
        ->and(fn () => g_object_set_property($tag, 'foreground', 3))->toThrow(TypeError::class, 'property foreground')
        ->and(fn () => g_object_set_property($tag, 'tabs', 'x'))->toThrow(TypeError::class, 'property tabs')
        ->and(g_object_get_property($tag, 'left-margin'))->toBe(0);

    g_object_set_property($tag, 'tabs', null);
    expect(g_object_get_property($tag, 'tabs'))->toBe(0);

    g_object_set_property($tag, 'left-margin', 12);
    g_object_set_property($tag, 'scale', 1.5);

    expect(g_object_get_property($tag, 'left-margin'))->toBe(12)
        ->and(g_object_get_property($tag, 'scale'))->toBe(1.5);
});

it('stales an iter taken inside an insert-text or delete-range handler once the change lands', function (): void {
    $buffer = GtkTextView::new()->getBuffer();
    $buffer->setText("abc\ndef", -1);
    $taken = [];
    g_signal_connect($buffer, 'insert-text', function () use ($buffer, &$taken): void { $taken['insert'] = $buffer->getStartIter(); });
    g_signal_connect($buffer, 'delete-range', function () use ($buffer, &$taken): void { $taken['delete'] = $buffer->getStartIter(); });
    $buffer->setText("new\ntext", -1);

    expect(array_keys($taken))->toContain('insert', 'delete')
        ->and(fn () => $taken['insert']->getOffset())->toThrow(GtkException::class, 'stale')
        ->and(fn () => $taken['delete']->getTags())->toThrow(GtkException::class, 'stale');
});

it('stales the first iter of a buffer taken inside a single-emission handler', function (string $signal, string $initial, string $replacement): void {
    $buffer = GtkTextView::new()->getBuffer();
    $buffer->setText($initial, -1);
    // No iter was handed out before the handler: the first one is taken inside it.
    $taken = null;
    g_signal_connect($buffer, $signal, function () use ($buffer, &$taken): void { $taken ??= $buffer->getStartIter(); });
    $buffer->setText($replacement, -1);

    expect($taken)->toBeInstanceOf(GtkTextIter::class)
        ->and(fn () => $taken->getOffset())->toThrow(GtkException::class, 'stale')
        ->and(fn () => $taken->getTags())->toThrow(GtkException::class, 'stale');
})->with([
    'insert only' => ['insert-text', '', 'xyz'],
    'delete only' => ['delete-range', 'abc', ''],
]);
