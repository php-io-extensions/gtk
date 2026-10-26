<?php

declare(strict_types=1);

// Site menu-model-item-index (outcome 2): GMenu reads its item array at the index unchecked, so an
// index past the items reads outside the array and dies on the hash table it finds there.

beforeEach(fn () => requireProbeBuild());

it('refuses an item index outside the model, which GMenu dies on (SIGSEGV) without the refusal', function (): void {
    $code = '$menu = GMenu::new(); $menu->append("a", null); $menu->getItemAttributeValue(100000, "label", null); return "read";';

    $kept = gtkChild($code, null);
    $off = gtkChild($code, 'menu-model-item-index');

    expect($kept['signal'])->toBeNull()
        ->and($kept['threw'])->toContain('must be an item of the model')
        ->and($off['signal'])->toBe(PROBE_SIGSEGV);
});
