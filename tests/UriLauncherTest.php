<?php

declare(strict_types=1);

beforeEach(fn () => testApplication());

it('holds a URI and cancels', function (): void {
    $launcher = GtkUriLauncher::new('https://example.com/');
    $launcher->setUri('https://example.com/x');
    $cancellable = GCancellable::new();
    $before = $cancellable->isCancelled();
    $cancellable->cancel();

    expect($launcher->getUri())->toBe('https://example.com/x')
        ->and(GtkUriLauncher::new(null)->getUri())->toBeNull()
        ->and([$before, $cancellable->isCancelled()])->toBe([false, true]);
});

/*
 * A launch with no URI runs in its own process: on macOS GTK leaves the application's windows
 * inactive after it, which later window-focus tests in this process would read.
 */
const NO_URI_APP = <<<'PHP'
    $app = GtkApplication::new('com.projectsaturnstudios.GtkTests', GApplicationFlags::NON_UNIQUE);
    g_signal_connect($app, 'activate', fn (): null => null);
    $app->register(null);
    $launcher = GtkUriLauncher::new(null);
    $ctx = GMainContext::default();
    $iterate = function (callable $done) use ($ctx): void {
        $start = microtime(true);
        while (! $done() && microtime(true) - $start < 3) {
            $ctx->iteration(false);
            usleep(1000);
        }
    };
PHP;

it('launches without a URI as GTK does: the callback runs once and launchFinish throws GTK\'s GError', function (): void {
    $run = gtkChild(NO_URI_APP.<<<'PHP'
        $results = [];
        $launcher->launch(null, null, function (GtkUriLauncher $source, GAsyncResult $result) use (&$results): void {
            $results[] = $result;
        });
        $iterate(fn (): bool => $results !== []);
        try {
            $launcher->launchFinish($results[0]);

            return [count($results), 'no throw'];
        } catch (GError $e) {
            return [count($results), $e->getMessage()];
        }
    PHP);

    expect($run['survived'])->toBeTrue()
        ->and($run['result'])->toBe([1, 'No uri to launch']);
});

it('launches with a null callback as GIO\'s fire and forget, and refuses a callback that cannot be called', function (): void {
    $run = gtkChild(NO_URI_APP.<<<'PHP'
        $launcher->launch(null, null, null);
        $iterate(fn (): bool => false);
        try {
            $launcher->launch(null, null, 'no_such_function');
        } catch (TypeError $e) {
            return $e->getMessage();
        }

        return 'no throw';
    PHP);

    expect($run['survived'])->toBeTrue()
        ->and($run['result'])->toBe('GtkUriLauncher::launch(): Argument #3 ($callback) must be a valid callback');
});

it('calls back once from launch, and launchFinish throws the launch\'s GError', function (): void {
    // On Linux GTK hands the URI to the desktop portal, which answers with its own dialog once
    // that closes: launch is proven there on screen (a page opening), not by this test.
    if (PHP_OS_FAMILY !== 'Darwin') {
        $this->markTestSkipped('Linux launches go through the desktop portal, which shows a dialog');
    }
    // A scheme no app handles, and a cancellable cancelled before the launch: nothing opens.
    $launcher = GtkUriLauncher::new('venusian-no-handler:x');
    $cancellable = GCancellable::new();
    $cancellable->cancel();
    $results = [];
    $launcher->launch(null, $cancellable, function (GtkUriLauncher $source, GAsyncResult $result) use (&$results): void {
        $results[] = [$source, $result];
    });
    iterateUntil(fn (): bool => $results !== [], 3000);
    iterateFor(0.1);

    expect($results)->toHaveCount(1)
        ->and($results[0][0])->toBe($launcher)
        ->and(fn () => $launcher->launchFinish($results[0][1]))->toThrow(GError::class);
});

it('finishes a result that is not its own launch\'s as GTK does: a critical and false', function (): void {
    if (PHP_OS_FAMILY !== 'Darwin') {
        $this->markTestSkipped('Linux launches go through the desktop portal, which shows a dialog');
    }
    $run = gtkChild(<<<'PHP'
        $first = GtkUriLauncher::new('venusian-no-handler:x');
        $second = GtkUriLauncher::new('venusian-no-handler:y');
        $cancellable = GCancellable::new();
        $cancellable->cancel();
        $results = [];
        $first->launch(null, $cancellable, function (GtkUriLauncher $source, GAsyncResult $result) use (&$results): void {
            $results[] = $result;
        });
        $until = microtime(true) + 3.0;
        while ($results === [] && microtime(true) < $until) {
            GMainContext::default()->iteration(false);
            usleep(1000);
        }

        return $second->launchFinish($results[0]);
    PHP);

    expect($run['result'])->toBeFalse()
        ->and($run['stderr'])->toContain('gtk_uri_launcher_launch_finish: assertion');
});
