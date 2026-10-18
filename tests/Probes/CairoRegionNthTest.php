<?php

declare(strict_types=1);

// Site cairo-region-nth (outcome 1): CairoRegion::getRectangle() with an index outside
// 0..numRectangles()-1, which cairo answers by reading past its boxes array. libgmalloc.

beforeEach(fn () => requireProbeBuild());

it('refuses an index past the region\'s rectangles, which cairo reads past (SIGSEGV) without the refusal', function (): void {
    $code = <<<'PHP'
        $region = CairoRegion::createRectangle(new GdkRectangle(0, 0, 4, 4));
        $far = $region->getRectangle(1_000_000_000);

        return [$far->x, $far->y, $far->width, $far->height];
    PHP;

    $kept = gtkChild($code, null, gmalloc: true, init: false);
    $off = gtkChild($code, 'cairo-region-nth', gmalloc: true, init: false);

    expect($kept['signal'])->toBeNull()
        ->and($kept['threw'])->toContain('ValueError')
        ->and($off['signal'])->toBeIn([PROBE_SIGSEGV, PROBE_SIGBUS]);
});
