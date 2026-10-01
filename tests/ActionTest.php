<?php

declare(strict_types=1);

beforeEach(fn () => testApplication());

it('activates a plain action and passes no parameter', function (): void {
    $action = GSimpleAction::new('view.refresh', null);
    $calls = [];
    g_signal_connect($action, 'activate', function (GSimpleAction $a, ?GVariant $parameter) use (&$calls): void {
        $calls[] = [$a->getName(), $parameter];
    });

    $action->activate(null);
    $action->setEnabled(false);
    $action->activate(null);

    expect($calls)->toBe([['view.refresh', null]])
        ->and($action->getEnabled())->toBeFalse()
        ->and($action->getState())->toBeNull();
});

it('toggles a stateful action through change-state', function (): void {
    $action = GSimpleAction::newStateful('grid', null, GVariant::newBoolean(false));
    $states = [];
    g_signal_connect($action, 'change-state', function (GSimpleAction $a, GVariant $value) use (&$states): void {
        $a->setState($value);
        $states[] = $value->getBoolean();
    });

    $action->activate(null);
    $action->activate(null);
    $action->changeState(GVariant::newBoolean(true));

    expect($states)->toBe([true, false, true])
        ->and($action->getState()->getBoolean())->toBeTrue();
});

it('refuses parameters and states of the wrong type', function (): void {
    $plain = GSimpleAction::new('plain', null);
    $typed = GSimpleAction::new('typed', 's');
    $stateful = GSimpleAction::newStateful('flag', null, GVariant::newBoolean(false));

    expect(fn () => $plain->activate(GVariant::newString('x')))->toThrow(ValueError::class)
        ->and(fn () => $typed->activate(null))->toThrow(ValueError::class)
        ->and(fn () => $stateful->changeState(GVariant::newInt32(1)))->toThrow(ValueError::class)
        ->and(fn () => $stateful->setState(GVariant::newString('x')))->toThrow(ValueError::class)
        ->and(fn () => GSimpleAction::new('bad name!', null))->toThrow(ValueError::class)
        ->and(fn () => GSimpleAction::new('ok', 'not a type'))->toThrow(ValueError::class);
});

it('groups actions and activates them by name, also through a widget', function (): void {
    $group = GSimpleActionGroup::new();
    $action = GSimpleAction::new('view.refresh', null);
    $hits = 0;
    g_signal_connect($action, 'activate', function () use (&$hits): void {
        $hits++;
    });
    $group->addAction($action);

    $window = GtkWindow::new();
    $window->insertActionGroup('win', $group);

    $group->activateAction('view.refresh', null);
    $activated = $window->activateAction('win.view.refresh', null);

    expect($hits)->toBe(2)
        ->and($activated)->toBeTrue()
        ->and($group->hasAction('view.refresh'))->toBeTrue()
        ->and($group->lookupAction('view.refresh'))->toBe($action)
        ->and($group->listActions())->toBe(['view.refresh'])
        ->and(fn () => $group->activateAction('nope', null))->toThrow(ValueError::class)
        ->and($window->activateAction('win.nope', null))->toBeFalse()
        ->and(fn () => $window->insertActionGroup('x', GMenu::new()))->toThrow(TypeError::class);

    $group->removeAction('view.refresh');
    expect($group->hasAction('view.refresh'))->toBeFalse()
        ->and($group->lookupAction('view.refresh'))->toBeNull();

    $window->destroy();
});

it('keeps the application\'s "app" actions, reachable from its windows', function (): void {
    $app = testApplication();
    $action = GSimpleAction::new('tools.measure', null);
    $hits = 0;
    g_signal_connect($action, 'activate', function () use (&$hits): void {
        $hits++;
    });
    $app->addAction($action);

    $window = GtkApplicationWindow::new($app);

    $app->activateAction('tools.measure', null);
    $activated = $window->activateAction('app.tools.measure', null);

    expect($hits)->toBe(2)
        ->and($activated)->toBeTrue()
        ->and($app->hasAction('tools.measure'))->toBeTrue()
        ->and($app->lookupAction('tools.measure'))->toBe($action)
        ->and($app->listActions())->toContain('tools.measure')
        ->and(fn () => $app->activateAction('nope', null))->toThrow(ValueError::class);

    $app->removeAction('tools.measure');
    expect($app->hasAction('tools.measure'))->toBeFalse()
        ->and($app->lookupAction('tools.measure'))->toBeNull();

    $window->destroy();
});
