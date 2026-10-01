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
        ->and(GVariant::newInt32(3)->print(true))->toBe('3');
});

it('refuses reads of the wrong type and invalid input', function (): void {
    expect(fn () => GVariant::newString('x')->getBoolean())->toThrow(GtkException::class)
        ->and(fn () => GVariant::newBoolean(true)->getInt32())->toThrow(GtkException::class)
        ->and(fn () => GVariant::newInt32(2 ** 40))->toThrow(ValueError::class)
        ->and(fn () => GVariant::newString("\xff"))->toThrow(ValueError::class)
        ->and(fn () => GVariant::newBoolean(true)->isOfType('?!'))->toThrow(ValueError::class)
        ->and(fn () => new GVariant())->toThrow(Error::class);
});
