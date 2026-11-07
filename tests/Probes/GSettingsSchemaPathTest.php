<?php

declare(strict_types=1);

// Site gsettings-schema-path (outcome 2): g_settings_new() has no path argument, and it answers a schema that has
// no path (a relocatable one) with g_error() (an abort, not a critical).

beforeEach(fn () => requireProbeBuild());

it('refuses a schema without a path, which GIO traps on (SIGTRAP) without the refusal', function (): void {
    $code = "GSettings::new('org.phpgtk.relocatable'); return 'made';";
    $kept = settingsChild($code);
    $off = settingsChild($code, 'gsettings-schema-path');

    expect($kept['signal'])->toBeNull()
        ->and($kept['threw'])->toContain('must name a schema with a path')
        ->and($off['signal'])->toBe(PROBE_SIGTRAP)
        ->and($off['stderr'])->toContain('without a path');
})->skip(PHP_OS_FAMILY !== 'Linux', 'GSettings reads the desktop\'s schemas: Linux');
