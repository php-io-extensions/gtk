<?php

declare(strict_types=1);

// Sites gsettings-key-in-schema-boolean, -int, -uint, -double and -string (outcome 2): each g_settings_get_*()
// answers a key the schema does not contain with g_error() (an abort, not a critical). One site per getter.

beforeEach(fn () => requireProbeBuild());

it('refuses a key the schema lacks, which GIO traps on (SIGTRAP) without the refusal', function (string $getter, string $site): void {
    $code = "return GSettings::new('org.phpgtk.test')->{$getter}('nope');";
    $kept = settingsChild($code);
    $off = settingsChild($code, $site);

    expect($kept['signal'])->toBeNull()
        ->and($kept['threw'])->toContain('must be a key of the schema')
        ->and($off['signal'])->toBe(PROBE_SIGTRAP)
        ->and($off['stderr'])->toContain('does not contain a key named');
})->with([
    'getBoolean' => ['getBoolean', 'gsettings-key-in-schema-boolean'],
    'getInt' => ['getInt', 'gsettings-key-in-schema-int'],
    'getUint' => ['getUint', 'gsettings-key-in-schema-uint'],
    'getDouble' => ['getDouble', 'gsettings-key-in-schema-double'],
    'getString' => ['getString', 'gsettings-key-in-schema-string'],
])->skip(PHP_OS_FAMILY !== 'Linux', 'GSettings reads the desktop\'s schemas: Linux');
