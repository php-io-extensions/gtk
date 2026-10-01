<?php

declare(strict_types=1);

it('validates application ids', function (): void {
    expect(GApplication::idIsValid('com.projectsaturnstudios.Valid'))->toBeTrue()
        ->and(GApplication::idIsValid('not an id'))->toBeFalse()
        ->and(fn () => GtkApplication::new('not an id', 0))->toThrow(ValueError::class);
});

it('creates an application with its id and flags', function (): void {
    $app = GtkApplication::new('com.projectsaturnstudios.Created', GApplicationFlags::NON_UNIQUE->value | GApplicationFlags::HANDLES_OPEN->value);

    expect($app)->toBeInstanceOf(GtkApplication::class)
        ->and($app->typeName())->toBe('GtkApplication')
        ->and($app->getApplicationId())->toBe('com.projectsaturnstudios.Created')
        ->and($app->getFlags())->toBe(GApplicationFlags::NON_UNIQUE->value | GApplicationFlags::HANDLES_OPEN->value)
        ->and($app->getIsRegistered())->toBeFalse()
        ->and(fn () => $app->getIsRemote())->toThrow(GtkException::class)
        ->and(GtkApplication::new(null, GApplicationFlags::NON_UNIQUE)->getApplicationId())->toBeNull();
});

it('registers, initialising GTK in startup', function (): void {
    $app = testApplication();

    expect($app->getIsRegistered())->toBeTrue()
        ->and($app->getIsRemote())->toBeFalse()
        ->and(gtk_is_initialized())->toBeTrue();
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
        ->and(g_signal_handler_is_connected($app, $id))->toBeFalse()
        ->and(fn () => g_signal_handler_disconnect($app, $id))->toThrow(ValueError::class);
});

it('rejects a signal the type does not have', function (): void {
    expect(fn () => g_signal_connect(testApplication(), 'no-such-signal', fn () => null))->toThrow(ValueError::class);
});

it('holds and releases', function (): void {
    $app = testApplication();

    $app->hold();
    $app->release();

    expect($app->getIsRegistered())->toBeTrue();
});
