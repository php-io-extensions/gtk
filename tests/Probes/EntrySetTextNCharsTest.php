<?php

declare(strict_types=1);

// Site entry-set-text-nchars (outcome 1): GtkEntryBuffer::setText() with nChars past the string's
// characters. gtk_entry_buffer_insert_text() walks nChars characters from the string's start, past
// its end; at 2e9 the walk leaves mapped memory.

beforeEach(fn () => requireProbeBuild());

it('refuses nChars past the string, which GTK walks past (SIGBUS) without the refusal', function (): void {
    $code = 'GtkEntry::new()->getBuffer()->setText("ab", 2_000_000_000); return "returned";';

    $kept = gtkChild($code, null);
    $off = gtkChild($code, 'entry-set-text-nchars');

    expect($kept['signal'])->toBeNull()
        ->and($kept['threw'])->toContain('ValueError')
        ->and($off['survived'])->toBeFalse()
        ->and($off['signal'])->toBeIn([PROBE_SIGBUS, PROBE_SIGSEGV]);
});
