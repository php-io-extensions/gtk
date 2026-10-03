<?php

declare(strict_types=1);

if (! extension_loaded('gtk')) {
    throw new RuntimeException('The gtk extension is not loaded; run pest with -d extension=/path/to/gtk.so');
}

/** Run every dispatch the default context has ready, without blocking. */
function drainContext(): void
{
    $ctx = GMainContext::default();
    while ($ctx->pending()) {
        $ctx->iteration(false);
    }
}

/** Iterate (blocking) until $done() holds; a guard timeout bounds the wait at $limitMs. */
function iterateUntil(callable $done, int $limitMs = 2000): bool
{
    $ctx = GMainContext::default();
    $expired = false;
    $guard = g_timeout_add($limitMs, function () use (&$expired): bool {
        $expired = true;

        return G_SOURCE_REMOVE;
    });

    while (! $done() && ! $expired) {
        $ctx->iteration(true);
    }

    if (! $expired) {
        g_source_remove($guard);
    }

    return $done();
}

/** Iterate the default context for $seconds. */
function iterateFor(float $seconds): void
{
    $until = microtime(true) + $seconds;
    while (microtime(true) < $until) {
        g_timeout_add(10, fn (): bool => G_SOURCE_REMOVE);
        GMainContext::default()->iteration(true);
    }
}

/** One application for the process: GTK initialises once, on its startup. */
function testApplication(): GtkApplication
{
    static $app = null;

    if ($app === null) {
        $app = GtkApplication::new('com.projectsaturnstudios.GtkTests', GApplicationFlags::NON_UNIQUE);
        g_signal_connect($app, 'activate', fn (): null => null);
        $app->register();
    }

    return $app;
}
