<?php

declare(strict_types=1);

it('builds and reads typed variants', function (): void {
    expect(GVariant::newBoolean(true)->getBoolean())->toBeTrue()
        ->and(GVariant::newString('héllo')->getString())->toBe('héllo')
        ->and(GVariant::newInt32(-42)->getInt32())->toBe(-42)
        ->and(GVariant::newDouble(1.5)->getDouble())->toBe(1.5)
        ->and(GVariant::newBoolean(false)->getTypeString())->toBe('b')
        ->and(GVariant::newString('x')->isOfType('s'))->toBeTrue()
        ->and(GVariant::newString('x')->print(true))->toBe("'x'")
        ->and(GVariant::newInt32(3)->print(true))->toBe('3')
        ->and((string) (new ReflectionMethod(GVariant::class, 'newString'))->getReturnType())->toBe('?GVariant')
        ->and((string) (new ReflectionMethod(GVariant::class, 'getString'))->getReturnType())->toBe('?string');
});

it('refuses an int with no int32 form, and construction outside the factories', function (): void {
    expect(fn () => GVariant::newInt32(2 ** 40))->toThrow(ValueError::class)
        ->and(fn () => new GVariant())->toThrow(Error::class);
});

it('answers reads of the wrong type and invalid input as GLib does: a critical and GLib\'s value', function (): void {
    $run = gtkChild(<<<'PHP'
        return [
            GVariant::newString('x')->getBoolean(),
            GVariant::newBoolean(true)->getInt32(),
            GVariant::newString('x')->getDouble(),
            GVariant::newInt32(1)->getString(),
            GVariant::newString("\xff"),
            GVariant::newString("a\0b")->getString(),
            GVariant::newBoolean(true)->isOfType('?!'),
        ];
    PHP, init: false);

    // A string with a NUL is read up to the NUL, as the native call reads a C string.
    expect($run['result'])->toBe([false, 0, 0.0, null, null, 'a', false])
        ->and($run['stderr'])->toContain("g_variant_get_boolean: assertion 'g_variant_is_of_type (value, G_VARIANT_TYPE_BOOLEAN)' failed")
        ->and($run['stderr'])->toContain("g_variant_get_int32: assertion 'g_variant_is_of_type (value, G_VARIANT_TYPE_INT32)' failed")
        ->and($run['stderr'])->toContain("g_variant_get_double: assertion 'g_variant_is_of_type (value, G_VARIANT_TYPE_DOUBLE)' failed")
        ->and($run['stderr'])->toContain('g_variant_get_string: assertion')
        ->and($run['stderr'])->toContain('g_variant_new_string(): requires valid UTF-8')
        ->and($run['stderr'])->toContain("g_variant_type_checked_: assertion 'g_variant_type_string_is_valid (type_string)' failed");
});
