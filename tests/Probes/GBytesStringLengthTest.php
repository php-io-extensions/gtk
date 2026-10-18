<?php

declare(strict_types=1);

// Site gbytes-string-length (outcome 1): GBytes::new() from a string with a size past its length,
// which g_bytes_new() copies from, reading past the string. libgmalloc.

beforeEach(fn () => requireProbeBuild());

it('refuses a size past the string, which g_bytes_new() reads past (SIGSEGV) without the refusal', function (): void {
    // A runtime string (malloc'd with Zend's allocator off) of 16 bytes, copied for 64 KiB: past the guard page.
    $code = <<<'PHP'
        return GBytes::new(str_repeat('x', 16), 65536)->getSize();
    PHP;

    $kept = gtkChild($code, null, gmalloc: true, init: false);
    $off = gtkChild($code, 'gbytes-string-length', gmalloc: true, init: false);

    expect($kept['signal'])->toBeNull()
        ->and($kept['threw'])->toContain('ValueError')
        ->and($off['signal'])->toBeIn([PROBE_SIGSEGV, PROBE_SIGBUS]);
});
