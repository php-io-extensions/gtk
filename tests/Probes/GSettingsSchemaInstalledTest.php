<?php

declare(strict_types=1);

// Site gsettings-schema-installed (outcome 2): g_settings_new() answers a schema that is not installed with
// g_error() (an abort, not a critical).

beforeEach(fn () => requireProbeBuild());

it('refuses a schema that is not installed, which GIO traps on (SIGTRAP) without the refusal', function (): void {
    $code = "GSettings::new('no.such.schema'); return 'made';";
    $kept = settingsChild($code);
    $off = settingsChild($code, 'gsettings-schema-installed');

    expect($kept['signal'])->toBeNull()
        ->and($kept['threw'])->toContain('must name an installed schema')
        ->and($off['signal'])->toBe(PROBE_SIGTRAP)
        ->and($off['stderr'])->toContain('is not installed');
})->skip(PHP_OS_FAMILY !== 'Linux', 'GSettings reads the desktop\'s schemas: Linux');
