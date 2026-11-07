<?php

declare(strict_types=1);

/*
 * GSettings reads the schemas of the machine, so these run on Linux only. Each runs in a child process
 * that finds the fixture schemas of tests/fixtures/settings through GSETTINGS_SCHEMA_DIR.
 */

describe('on Linux', function (): void {
    it('reads a key of each type', function (): void {
        $run = settingsChild(<<<'PHP'
        $settings = GSettings::new('org.phpgtk.test');
        return [$settings->getBoolean('flag'), $settings->getInt('count'), $settings->getUint('size'), $settings->getDouble('ratio'), $settings->getString('name')];
        PHP);

        expect($run['threw'])->toBeNull()
            ->and($run['result'])->toBe([true, -7, 4000000000, 2.5, 'hello']);
    });

    it('is a GObject', function (): void {
        $run = settingsChild("return GSettings::new('org.phpgtk.test') instanceof GObject;");

        expect($run['result'])->toBeTrue();
    });

    it('finds a schema in the default source and tells its keys', function (): void {
        $run = settingsChild(<<<'PHP'
        $source = GSettingsSchemaSource::getDefault();
        $schema = $source->lookup('org.phpgtk.test', true);
        return [
            $source === GSettingsSchemaSource::getDefault(),
            $schema instanceof GSettingsSchema,
            $schema->hasKey('count'),
            $schema->hasKey('zzz'),
            $source->lookup('no.such.schema', true),
        ];
        PHP);

        expect($run['threw'])->toBeNull()
            ->and($run['result'])->toBe([true, true, true, false, null]);
    });

    it('passes GLib\'s answer for a key of another type through: zero or null, after a critical', function (): void {
        $run = settingsChild(<<<'PHP'
        $settings = GSettings::new('org.phpgtk.test');
        return [$settings->getInt('name'), $settings->getString('count')];
        PHP);

        expect($run['threw'])->toBeNull()
            ->and($run['result'])->toBe([0, null])
            ->and($run['stderr'])->toContain('g_variant_get_int32');
    });

    it('refuses a schema that is not installed', function (): void {
        $run = settingsChild("GSettings::new('no.such.schema'); return 'made';");

        expect($run['signal'])->toBeNull()
            ->and($run['threw'])->toContain('ValueError')->toContain('no.such.schema');
    });

    it('refuses a schema without a path', function (): void {
        $run = settingsChild("GSettings::new('org.phpgtk.relocatable'); return 'made';");

        expect($run['signal'])->toBeNull()
            ->and($run['threw'])->toContain('ValueError')->toContain('org.phpgtk.relocatable');
    });

    it('refuses a key the schema does not have', function (string $getter): void {
        $run = settingsChild("return GSettings::new('org.phpgtk.test')->{$getter}('nope');");

        expect($run['signal'])->toBeNull()
            ->and($run['threw'])->toContain('ValueError')->toContain('nope');
    })->with(['getBoolean', 'getInt', 'getUint', 'getDouble', 'getString']);
})->skip(PHP_OS_FAMILY !== 'Linux', 'GSettings reads the desktop\'s schemas: Linux');
