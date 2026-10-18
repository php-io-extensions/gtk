<?php

declare(strict_types=1);

// Site gmenu-detailed-action (outcome 2): an unparsable detailed action name, which
// g_menu_item_set_detailed_action() answers with g_error() (an abort, not a critical). Task 1 probe C5.

beforeEach(fn () => requireProbeBuild());

it('refuses an unparsable detailed action name, which GIO traps on (SIGTRAP) without the refusal', function (string $code): void {
    $kept = gtkChild($code, null, init: false);
    $off = gtkChild($code, 'gmenu-detailed-action', init: false);

    expect($kept['signal'])->toBeNull()
        ->and($kept['threw'])->toContain('must be a valid detailed action name')
        ->and($off['signal'])->toBe(PROBE_SIGTRAP)
        ->and($off['stderr'])->toContain('g_menu_item_set_detailed_action');
})->with([
    'GMenuItem::new' => ["GMenuItem::new('X', 'a b'); return 'made';"],
    'GMenu::append' => ["GMenu::new()->append('X', 'not a valid name!'); return 'made';"],
    'setDetailedAction' => ["GMenuItem::new('X', null)->setDetailedAction('('); return 'made';"],
]);
