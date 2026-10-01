<?php

declare(strict_types=1);

it('registers the source return values', function (): void {
    expect(G_SOURCE_CONTINUE)->toBeTrue()
        ->and(G_SOURCE_REMOVE)->toBeFalse();
});

it('backs GIOCondition with the poll(2) bits', function (): void {
    expect(GIOCondition::IN->value)->toBe(1)
        ->and(GIOCondition::PRI->value)->toBe(2)
        ->and(GIOCondition::OUT->value)->toBe(4)
        ->and(GIOCondition::ERR->value)->toBe(8)
        ->and(GIOCondition::HUP->value)->toBe(16)
        ->and(GIOCondition::NVAL->value)->toBe(32);
});

it('backs GApplicationFlags with the GIO values', function (): void {
    expect(GApplicationFlags::DEFAULT_FLAGS->value)->toBe(0)
        ->and(GApplicationFlags::IS_SERVICE->value)->toBe(1)
        ->and(GApplicationFlags::NON_UNIQUE->value)->toBe(32)
        ->and(GApplicationFlags::REPLACE->value)->toBe(256);
});

it('reports the GTK runtime version', function (): void {
    expect(gtk_get_major_version())->toBe(4)
        ->and(gtk_get_minor_version())->toBeGreaterThanOrEqual(10)
        ->and(gtk_get_micro_version())->toBeGreaterThanOrEqual(0);
});
