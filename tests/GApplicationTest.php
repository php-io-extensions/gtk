<?php

declare(strict_types=1);

it('validates application ids', function (): void {
    expect(GApplication::idIsValid('com.projectsaturnstudios.Valid'))->toBeTrue()
        ->and(GApplication::idIsValid('not an id'))->toBeFalse();
});

it('answers an invalid application id as GTK does: a critical and null', function (): void {
    $run = gtkChild(<<<'PHP'
        return GtkApplication::new('not an id', 0);
    PHP, init: false);

    expect($run['survived'])->toBeTrue()
        ->and($run['result'])->toBeNull()
        ->and($run['stderr'])->toContain("gtk_application_new: assertion 'application_id == NULL || g_application_id_is_valid (application_id)' failed");
});

it('answers getIsRemote() on an unregistered application as GIO does: a critical and false', function (): void {
    $run = gtkChild(<<<'PHP'
        return GtkApplication::new(null, 0)->getIsRemote();
    PHP, init: false);

    expect($run['result'])->toBeFalse()
        ->and($run['stderr'])->toContain("g_application_get_is_remote: assertion 'application->priv->is_registered' failed");
});

it('creates an application with its id and flags', function (): void {
    $app = GtkApplication::new('com.projectsaturnstudios.Created', GApplicationFlags::NON_UNIQUE->value | GApplicationFlags::HANDLES_OPEN->value);

    expect($app)->toBeInstanceOf(GtkApplication::class)
        ->and($app->typeName())->toBe('GtkApplication')
        ->and($app->getApplicationId())->toBe('com.projectsaturnstudios.Created')
        ->and($app->getFlags())->toBe(GApplicationFlags::NON_UNIQUE->value | GApplicationFlags::HANDLES_OPEN->value)
        ->and($app->getIsRegistered())->toBeFalse()
        ->and(GtkApplication::new(null, GApplicationFlags::NON_UNIQUE)->getApplicationId())->toBeNull();
});

it('registers, initialising GTK in startup', function (): void {
    $app = testApplication();

    expect($app->getIsRegistered())->toBeTrue()
        ->and($app->getIsRemote())->toBeFalse()
        ->and(gtk_is_initialized())->toBeTrue();
});

it('registers with a GCancellable, as g_application_register takes one', function (): void {
    // Its own process: a second registered application would run GTK's startup again in this one.
    $code = <<<'PHP'
        $app = GtkApplication::new('com.projectsaturnstudios.GtkRegisterCancellable', GApplicationFlags::NON_UNIQUE);
        var_dump($app->register(GCancellable::new()), $app->getIsRegistered());
        PHP;
    $out = shell_exec(escapeshellarg(PHP_BINARY).' -r '.escapeshellarg($code).' 2>&1');

    expect($out)->toBe("bool(true)\nbool(true)\n");
});

it('takes run()\'s argv as g_application_run does, with no default', function (): void {
    $argv = (new ReflectionMethod(GApplication::class, 'run'))->getParameters()[0];

    expect($argv->getName())->toBe('argv')
        ->and($argv->isOptional())->toBeFalse()
        ->and((string) $argv->getType())->toBe('array');
});

it('calls signal handlers with the instance boxed as its own class', function (): void {
    $app = testApplication();
    $seen = [];

    $id = g_signal_connect($app, 'activate', function (GApplication $instance) use (&$seen): void {
        $seen[] = $instance;
    });
    $app->activate();

    expect($seen)->toHaveCount(1)
        ->and($seen[0])->toBe($app)
        ->and(g_signal_handler_is_connected($app, $id))->toBeTrue();

    g_signal_handler_disconnect($app, $id);
    $app->activate();

    expect($seen)->toHaveCount(1)
        ->and(g_signal_handler_is_connected($app, $id))->toBeFalse();
});

it('disconnects a handler twice as GLib does: the second is a critical', function (): void {
    $run = gtkChild(<<<'PHP'
        $action = GSimpleAction::new('x', null);
        $id = g_signal_connect($action, 'activate', fn () => null);
        g_signal_handler_disconnect($action, $id);
        g_signal_handler_disconnect($action, $id);

        return g_signal_handler_is_connected($action, $id);
    PHP);

    expect($run['result'])->toBeFalse()
        ->and($run['stderr'])->toMatch("/instance '0x[0-9a-f]+' has no handler with id '\\d+'/");
});

it('connects to a signal the type does not have as GLib does: a critical and handler id 0', function (): void {
    $run = gtkChild(<<<'PHP'
        $hits = 0;
        $action = GSimpleAction::new('x', null);
        $id = g_signal_connect($action, 'no-such-signal', function () use (&$hits): void {
            $hits++;
        });
        $action->activate(null);

        return [$id, $hits];
    PHP);

    expect($run['result'])->toBe([0, 0])
        ->and($run['stderr'])->toContain("signal 'no-such-signal' is invalid for instance");
});

it('holds and releases', function (): void {
    $app = testApplication();

    $app->hold();
    $app->release();

    expect($app->getIsRegistered())->toBeTrue();
});
