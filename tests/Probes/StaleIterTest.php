<?php

declare(strict_types=1);

// Site text-iter-stale (outcome 1): a GtkTextIter used after its buffer's text changed. libgmalloc.
// Task 1 probe C4a.

beforeEach(fn () => requireProbeBuild());

it('refuses a stale iter, which GTK reads freed segments through (SIGSEGV) without the refusal', function (): void {
    $code = <<<'PHP'
        $buffer = GtkTextView::new()->getBuffer();
        $buffer->setText("one\ntwo\nthree", -1);
        $buffer->getIterAtLine($iter, 2);
        $buffer->setText('x', -1);

        return [$iter->getLine(), $iter->getOffset(), count($iter->getTags())];
    PHP;

    $kept = gtkChild($code, null, gmalloc: true);
    $off = gtkChild($code, 'text-iter-stale', gmalloc: true);

    expect($kept['signal'])->toBeNull()
        ->and($kept['threw'])->toContain('GtkTextIter is stale')
        ->and($off['signal'])->toBe(PROBE_SIGSEGV);
});
