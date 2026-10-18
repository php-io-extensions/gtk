<?php

declare(strict_types=1);

// Site accels-action-name (outcome 2): GtkApplication::setAccelsForAction() with an action name GTK
// cannot parse. GTK logs "Error parsing action name", then gtk_normalise_detailed_action_name()
// asserts on the same name, which aborts.

beforeEach(fn () => requireProbeBuild());

it('refuses an unparsable action name, which GTK aborts on (SIGABRT) without the refusal', function (): void {
    $code = <<<'PHP'
        $app = GtkApplication::new('com.projectsaturnstudios.GtkTests.BadAction', GApplicationFlags::NON_UNIQUE);
        $app->register(null);
        $app->setAccelsForAction('(', ['<Control>q']);

        return 'returned';
    PHP;

    $kept = gtkChild($code, null, init: false);
    $off = gtkChild($code, 'accels-action-name', init: false);

    expect($kept['signal'])->toBeNull()
        ->and($kept['threw'])->toContain('ValueError')
        ->and($off['signal'])->toBe(PROBE_SIGABRT)
        ->and($off['stderr'])->toContain("gtk_normalise_detailed_action_name: assertion failed (error == NULL): Detailed action name '(' has invalid format");
});
