<?php

declare(strict_types=1);

// Site gtk-initialized (outcome 2): a widget or media constructor before gtk_init(). Task 1 probe C2.

beforeEach(fn () => requireProbeBuild());

it('refuses a widget before GTK is initialised, which GTK dies on (SIGSEGV) without the refusal', function (): void {
    $code = 'GtkBox::new(GtkOrientation::VERTICAL, 0); return "built";';

    $kept = gtkChild($code, null, init: false);
    $off = gtkChild($code, 'gtk-initialized', init: false);

    expect($kept['signal'])->toBeNull()
        ->and($kept['threw'])->toContain('needs GTK initialised')
        ->and($off['signal'])->toBe(PROBE_SIGSEGV);
});

it('refuses a media file before GTK is initialised, which the media backend lookup traps on (SIGTRAP) without the refusal', function (): void {
    $code = 'GtkMediaFile::newForFilename("/nope.mp4"); return "built";';

    $kept = gtkChild($code, null, init: false);
    $off = gtkChild($code, 'gtk-initialized', init: false);

    expect($kept['signal'])->toBeNull()
        ->and($kept['threw'])->toContain('needs GTK initialised')
        ->and($off['signal'])->toBe(PROBE_SIGTRAP);
});

// Site gtk-initialized-media-file: GtkMediaFile::new goes through the gtk-initialized check.
it('refuses an empty media file before GTK is initialised, which the media backend lookup traps on (SIGTRAP) without the refusal', function (): void {
    $code = 'GtkMediaFile::new(); return "built";';

    $kept = gtkChild($code, null, init: false);
    $off = gtkChild($code, 'gtk-initialized', init: false);

    expect($kept['signal'])->toBeNull()
        ->and($kept['threw'])->toContain('needs GTK initialised')
        ->and($off['signal'])->toBe(PROBE_SIGTRAP);
});
