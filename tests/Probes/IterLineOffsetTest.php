<?php

declare(strict_types=1);

// Site text-iter-line-offset-negative (outcome 2): getIterAtLineOffset with a negative char offset,
// which GTK answers with g_error ("Char offset -1 is off the end of the line").

beforeEach(fn () => requireProbeBuild());

it('refuses a negative char offset, which GTK traps the process on (SIGTRAP) without the refusal', function (): void {
    $code = <<<'PHP'
        $buffer = GtkTextView::new()->getBuffer();
        $buffer->setText("one\ntwo", -1);

        return $buffer->getIterAtLineOffset($iter, 1, -1);
    PHP;

    $kept = gtkChild($code, null);
    $off = gtkChild($code, 'text-iter-line-offset-negative');

    expect($kept['signal'])->toBeNull()
        ->and($kept['threw'])->toContain('must be greater than or equal to 0')
        ->and($off['signal'])->toBe(PROBE_SIGTRAP);
});
