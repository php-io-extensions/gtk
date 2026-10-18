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

it('passes parameters and states of the wrong type to GLib, which logs a critical and changes nothing', function (): void {
    $run = gtkChild(<<<'PHP'
        $hits = 0;
        $count = function () use (&$hits): void {
            $hits++;
        };
        $plain = GSimpleAction::new('plain', null);
        $typed = GSimpleAction::new('typed', 's');
        g_signal_connect($plain, 'activate', $count);
        g_signal_connect($typed, 'activate', $count);
        $stateful = GSimpleAction::newStateful('flag', null, GVariant::newBoolean(false));

        $plain->activate(GVariant::newString('x'));
        $typed->activate(null);
        $stateful->changeState(GVariant::newInt32(1));
        $changed = $stateful->getState()->getBoolean();
        $stateful->setState(GVariant::newString('x'));

        return [$hits, $changed, $stateful->getState()->getBoolean()];
    PHP);

    expect($run['result'])->toBe([0, false, false])
        ->and($run['stderr'])->toContain("g_simple_action_activate: assertion 'simple->parameter_type == NULL ? parameter == NULL")
        ->and($run['stderr'])->toContain("g_action_change_state: assertion 'g_variant_is_of_type (value, state_type)' failed")
        ->and($run['stderr'])->toContain("g_simple_action_set_state: assertion 'g_variant_is_of_type (value, state_type)' failed");
});

it('makes the action GLib makes for an invalid name or parameter type', function (): void {
    $run = gtkChild(<<<'PHP'
        $named = GSimpleAction::new('bad name!', null);
        $untyped = GSimpleAction::new('ok', 'not a type');

        return [$named->getName(), get_class($untyped), $untyped->getParameterType()];
    PHP);

    // GLib does not check the name; the type string is a critical and no parameter type.
    expect($run['result'])->toBe(['bad name!', 'GSimpleAction', null])
        ->and($run['stderr'])->toContain("g_variant_type_checked_: assertion 'g_variant_type_string_is_valid (type_string)' failed");
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
    $activated = $window->activateActionVariant('win.view.refresh', null);

    expect($hits)->toBe(2)
        ->and($activated)->toBeTrue()
        ->and($group->hasAction('view.refresh'))->toBeTrue()
        ->and($group->lookupAction('view.refresh'))->toBe($action)
        ->and($group->listActions())->toBe(['view.refresh'])
        ->and($window->activateActionVariant('win.nope', null))->toBeFalse()
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
    $activated = $window->activateActionVariant('app.tools.measure', null);

    expect($hits)->toBe(2)
        ->and($activated)->toBeTrue()
        ->and($app->hasAction('tools.measure'))->toBeTrue()
        ->and($app->lookupAction('tools.measure'))->toBe($action)
        ->and($app->listActions())->toContain('tools.measure');

    $app->removeAction('tools.measure');
    expect($app->hasAction('tools.measure'))->toBeFalse()
        ->and($app->lookupAction('tools.measure'))->toBeNull();

    $window->destroy();
});

it('declares the native action interfaces on the classes GLib and GTK give them', function (): void {
    expect(GSimpleAction::new('a', null))->toBeInstanceOf(GAction::class)
        ->and(GSimpleActionGroup::new())->toBeInstanceOf(GActionGroup::class)
        ->and(GSimpleActionGroup::new())->toBeInstanceOf(GActionMap::class)
        ->and(testApplication())->toBeInstanceOf(GActionGroup::class)
        ->and(testApplication())->toBeInstanceOf(GActionMap::class)
        ->and(is_subclass_of(GtkApplicationWindow::class, GActionGroup::class))->toBeTrue()
        ->and(is_subclass_of(GtkApplicationWindow::class, GActionMap::class))->toBeTrue()
        ->and((new ReflectionClass(GSimpleAction::class))->isAbstract())->toBeFalse();
});

/*
 * The interfaces stand for native GTypes: a PHP class with no native object behind it (one
 * implementing them itself, or a subclass of a class whose GType does not implement them) is
 * refused when it is declared, before any method could read a native pointer it does not hold.
 */
it('refuses a PHP class implementing a native interface its objects do not hold', function (string $declaration, string $iface): void {
    $run = gtkChild("{$declaration}\n        return 'declared';", init: false);

    expect($run['signal'])->toBeNull()
        ->and($run['exit'])->toBe(255)
        ->and($run['survived'])->toBeFalse()
        ->and($run['stdout'])->toContain("cannot implement interface {$iface}: it stands for a native GType, which only the extension's GObject classes hold");
})->with([
    'GAction' => ['class Foo implements GAction {}', 'GAction'],
    'GListModel' => ['class Foo implements GListModel {}', 'GListModel'],
    'GtkSelectionModel' => ['class Foo implements GtkSelectionModel {}', 'GtkSelectionModel'],
    'GdkPaintable' => ['class Foo implements GdkPaintable {}', 'GdkPaintable'],
    'GtkStyleProvider' => ['class Foo implements GtkStyleProvider {}', 'GtkStyleProvider'],
    'GtkNative' => ['class Foo implements GtkNative {}', 'GtkNative'],
    'GtkRoot' => ['class Foo implements GtkRoot {}', 'GtkRoot'],
    'GActionMap' => ['class Foo implements GActionMap {}', 'GActionMap'],
    'GActionGroup' => ['class Foo implements GActionGroup {}', 'GActionGroup'],
    'a GObject subclass' => ['class Foo extends GObject implements GListModel {}', 'GListModel'],
]);

it('lets a PHP subclass of a native implementer keep its interfaces, and a PHP interface extend them', function (): void {
    $run = gtkChild(<<<'PHP'
        interface MyModel extends GListModel {}
        class MyAction extends GSimpleAction {}
        class MyList extends GtkStringList implements MyModel {}

        return [is_subclass_of(MyAction::class, GAction::class), is_subclass_of(MyList::class, GListModel::class)];
    PHP, init: false);

    expect($run['result'])->toBe([true, true]);
});

it('validates an action name with g_action_name_is_valid', function (): void {
    expect(GAction::nameIsValid('view.refresh'))->toBeTrue()
        ->and(GAction::nameIsValid('bad name!'))->toBeFalse()
        ->and(GSimpleAction::nameIsValid('ok'))->toBeTrue();
});

it('prints a detailed action name with g_action_print_detailed_name', function (): void {
    expect(GAction::printDetailedName('open', null))->toBe('open')
        ->and(GAction::printDetailedName('open', GVariant::newString('file')))->toBe('open::file')
        ->and(GAction::printDetailedName('zoom', GVariant::newInt32(2)))->toBe('zoom(2)');
});

it('answers an action\'s parameter type as its GVariant type string', function (): void {
    expect(GSimpleAction::new('typed', 's')->getParameterType())->toBe('s')
        ->and(GSimpleAction::new('plain', null)->getParameterType())->toBeNull();
});

it('answers an action\'s state type as its GVariant type string', function (): void {
    expect(GSimpleAction::newStateful('flag', null, GVariant::newBoolean(false))->getStateType())->toBe('b')
        ->and(GSimpleAction::new('plain', null)->getStateType())->toBeNull();
});

it('answers an action\'s state hint, null when none is set', function (): void {
    expect(GSimpleAction::newStateful('flag', null, GVariant::newBoolean(false))->getStateHint())->toBeNull();
});

it('answers whether a group\'s action is enabled', function (): void {
    $group = GSimpleActionGroup::new();
    $action = GSimpleAction::new('a', null);
    $group->addAction($action);
    $before = $group->getActionEnabled('a');
    $action->setEnabled(false);

    expect($before)->toBeTrue()
        ->and($group->getActionEnabled('a'))->toBeFalse();
});

it('answers a group\'s action parameter type by name', function (): void {
    $group = GSimpleActionGroup::new();
    $group->addAction(GSimpleAction::new('open', 's'));
    $group->addAction(GSimpleAction::new('quit', null));

    expect($group->getActionParameterType('open'))->toBe('s')
        ->and($group->getActionParameterType('quit'))->toBeNull();
});

it('answers a group\'s action state type by name', function (): void {
    $group = GSimpleActionGroup::new();
    $group->addAction(GSimpleAction::newStateful('flag', null, GVariant::newBoolean(true)));
    $group->addAction(GSimpleAction::new('quit', null));

    expect($group->getActionStateType('flag'))->toBe('b')
        ->and($group->getActionStateType('quit'))->toBeNull();
});

it('answers a group\'s action state hint by name, null when none is set', function (): void {
    $group = GSimpleActionGroup::new();
    $group->addAction(GSimpleAction::newStateful('flag', null, GVariant::newBoolean(true)));

    expect($group->getActionStateHint('flag'))->toBeNull();
});

it('answers a group\'s action state by name', function (): void {
    $group = GSimpleActionGroup::new();
    $group->addAction(GSimpleAction::newStateful('flag', null, GVariant::newBoolean(true)));
    $group->addAction(GSimpleAction::new('quit', null));

    expect($group->getActionState('flag')->getBoolean())->toBeTrue()
        ->and($group->getActionState('quit'))->toBeNull();
});

it('changes a group\'s action state by name', function (): void {
    $group = GSimpleActionGroup::new();
    $action = GSimpleAction::newStateful('flag', null, GVariant::newBoolean(false));
    $group->addAction($action);

    $group->changeActionState('flag', GVariant::newBoolean(true));

    expect($action->getState()->getBoolean())->toBeTrue();
});

it('emits action-added for a group', function (): void {
    $group = GSimpleActionGroup::new();
    $seen = [];
    g_signal_connect($group, 'action-added', function (GSimpleActionGroup $g, string $name) use (&$seen): void { $seen[] = $name; });

    $group->actionAdded('announced');

    expect($seen)->toBe(['announced']);
});

it('emits action-removed for a group', function (): void {
    $group = GSimpleActionGroup::new();
    $seen = [];
    g_signal_connect($group, 'action-removed', function (GSimpleActionGroup $g, string $name) use (&$seen): void { $seen[] = $name; });

    $group->actionRemoved('gone');

    expect($seen)->toBe(['gone']);
});

it('emits action-enabled-changed for a group', function (): void {
    $group = GSimpleActionGroup::new();
    $seen = [];
    g_signal_connect($group, 'action-enabled-changed', function (GSimpleActionGroup $g, string $name, bool $enabled) use (&$seen): void { $seen[] = [$name, $enabled]; });

    $group->actionEnabledChanged('toggle', false);

    expect($seen)->toBe([['toggle', false]]);
});

it('activates an unknown action name as GLib does: it returns, activating nothing', function (): void {
    $run = gtkChild(<<<'PHP'
        GSimpleActionGroup::new()->activateAction('nope', null);
        $app = GtkApplication::new('com.projectsaturnstudios.GtkTests.Nope', GApplicationFlags::NON_UNIQUE);
        $app->register(null);
        $app->activateAction('nope', null);

        return 'returned';
    PHP);

    expect($run['result'])->toBe('returned')
        ->and($run['signal'])->toBeNull();
});

it('emits action-state-changed for a group', function (): void {
    $group = GSimpleActionGroup::new();
    $seen = [];
    g_signal_connect($group, 'action-state-changed', function (GSimpleActionGroup $g, string $name, GVariant $state) use (&$seen): void { $seen[] = [$name, $state->getInt32()]; });

    $group->actionStateChanged('level', GVariant::newInt32(3));

    expect($seen)->toBe([['level', 3]]);
});

it('keeps a GtkApplicationWindow\'s own "win" actions through GActionMap and GActionGroup', function (): void {
    $window = GtkApplicationWindow::new(testApplication());
    $action = GSimpleAction::new('zoom', null);
    $hits = 0;
    g_signal_connect($action, 'activate', function () use (&$hits): void {
        $hits++;
    });

    $window->addAction($action);
    $window->activateAction('zoom', null);

    expect($hits)->toBe(1)
        ->and($window->lookupAction('zoom'))->toBe($action)
        ->and($window->hasAction('zoom'))->toBeTrue()
        ->and($window->activateActionVariant('win.zoom', null))->toBeTrue()
        ->and($hits)->toBe(2);

    $window->destroy();
});
