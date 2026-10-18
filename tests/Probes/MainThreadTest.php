<?php

declare(strict_types=1);

// Site main-thread-macos (outcome 2): GTK calls off the process main thread on macOS, where the GDK
// backend calls AppKit, which raises an uncaught NSInternalInconsistencyException. Task 1 probe C1.

beforeEach(function (): void {
    requireProbeBuild();
    if (PHP_OS_FAMILY !== 'Darwin') {
        $this->markTestSkipped('the site is macOS only: on Linux GTK runs off the main thread and the gate compiles out');
    }
    if (! PHP_ZTS) {
        $this->markTestSkipped('needs a ZTS PHP: only a parallel\Runtime worker runs PHP off the main thread');
    }
    if (! is_file(probeExtension('parallel'))) {
        $this->markTestSkipped('needs ext-parallel at '.probeExtension('parallel').' (or env PHPGTK_PROBE_PARALLEL)');
    }
});

it('refuses a window off the main thread, which AppKit aborts on (SIGABRT) without the refusal', function (): void {
    $code = <<<'PHP'
        $future = (new parallel\Runtime())->run(function (): string {
            gtk_init();
            $window = GtkWindow::new();
            $window->present();
            for ($i = 0; $i < 50; $i++) {
                GMainContext::default()->iteration(false);
            }

            return 'worker finished';
        });

        return $future->value();
    PHP;

    $kept = gtkChild($code, null, parallel: true, init: false);
    $off = gtkChild($code, 'main-thread-macos', parallel: true, init: false);

    expect($kept['signal'])->toBeNull()
        ->and($kept['threw'])->toContain('must be called on the main thread')
        ->and($off['signal'])->toBe(PROBE_SIGABRT);
});

it('refuses iterating the default context off the main thread once GTK is initialised, which crashes (SIGSEGV) without the refusal', function (): void {
    $code = <<<'PHP'
        $future = (new parallel\Runtime())->run(function (): string {
            GMainContext::default()->iteration(false);

            return 'worker iterated';
        });

        return $future->value();
    PHP;

    $kept = gtkChild($code, null, parallel: true);
    $off = gtkChild($code, 'main-thread-macos', parallel: true);

    expect($kept['signal'])->toBeNull()
        ->and($kept['threw'])->toContain('iteration() must be called on the main thread')
        ->and($off['survived'])->toBeFalse()
        ->and($off['signal'])->toBe(PROBE_SIGSEGV);
});
