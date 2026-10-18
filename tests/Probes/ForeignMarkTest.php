<?php

declare(strict_types=1);

// Site text-iter-foreign-mark (outcome 1): getIterAtMark() with a mark that is not this buffer's.
// A deleted mark: GTK leaves the iter unwritten, and the binding reads whatever its stack slot held
// (here an iter of a buffer since freed). Another buffer's live mark: GTK writes this buffer's tree
// over that buffer's lines, and the iter reads them after that buffer is freed. libgmalloc. Task 1
// probe C4b.

beforeEach(fn () => requireProbeBuild());

it('refuses a mark that is not this buffer\'s, whose iter reads freed text segments (SIGSEGV) without the refusal', function (string $code): void {
    $kept = gtkChild($code, null, gmalloc: true);
    $off = gtkChild($code, 'text-iter-foreign-mark', gmalloc: true);

    expect($kept['signal'])->toBeNull()
        ->and($kept['threw'])->toContain('ValueError')
        ->and($off['survived'])->toBeFalse()
        ->and($off['signal'])->toBe(PROBE_SIGSEGV);
})->with([
    'a deleted mark' => [<<<'PHP'
        $view = GtkTextView::new();
        $gone = $view->getBuffer();
        $gone->setText('freed text', -1);
        $mark = $gone->getInsert();
        $taken = $gone->getIterAtMark($mark);
        unset($taken, $gone, $view);
        gc_collect_cycles();

        return GtkTextView::new()->getBuffer()->getIterAtMark($mark)->getOffset();
    PHP],
    'another buffer\'s mark, that buffer then freed' => [<<<'PHP'
        $buffer = GtkTextView::new()->getBuffer();
        $buffer->setText('this buffer', -1);
        $otherView = GtkTextView::new();
        $other = $otherView->getBuffer();
        $other->setText("another buffer\nwith lines", -1);
        $iter = $buffer->getIterAtMark($other->getInsert());
        unset($other, $otherView);
        gc_collect_cycles();

        return [$iter->getOffset(), $iter->getLine()];
    PHP],
]);
