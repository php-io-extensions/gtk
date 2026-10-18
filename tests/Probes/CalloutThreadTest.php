<?php

declare(strict_types=1);

// Site callout-owner-thread (outcome 3): a callout dispatched on a thread other than the one whose
// PHP made it. The main thread adds an idle source; a worker iterates the shared default context.
// Task 1 callout-thread probe.

beforeEach(function (): void {
    requireProbeBuild();
    if (PHP_OS_FAMILY === 'Darwin') {
        $this->markTestSkipped('on macOS a worker cannot iterate the context (site main-thread-macos refuses it), so no callout dispatches off its thread there');
    }
    if (! PHP_ZTS) {
        $this->markTestSkipped('needs a ZTS PHP: only a parallel\Runtime worker runs PHP off the main thread');
    }
    if (! is_file(probeExtension('parallel'))) {
        $this->markTestSkipped('needs ext-parallel at '.probeExtension('parallel').' (or env PHPGTK_PROBE_PARALLEL)');
    }
});

it('drops a callout off its owner thread, which runs PHP on the wrong executor (a crash) without the drop', function (): void {
    $code = <<<'PHP'
        $ran = false;
        g_idle_add(function () use (&$ran): bool {
            $ran = true;

            return G_SOURCE_REMOVE;
        });
        $future = (new parallel\Runtime())->run(function (): string {
            GMainContext::default()->iteration(false);

            return 'worker iterated';
        });

        return [$future->value(), $ran];
    PHP;

    $kept = gtkChild($code, null, parallel: true, init: false);
    $off = gtkChild($code, 'callout-owner-thread', parallel: true, init: false);

    expect($kept['signal'])->toBeNull()
        ->and($kept['result'])->toBe(['worker iterated', false])
        ->and($off['survived'])->toBeFalse()
        ->and($off['signal'])->toBeIn([PROBE_SIGSEGV, PROBE_SIGABRT]);
});
