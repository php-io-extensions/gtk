<?php

declare(strict_types=1);

beforeEach(fn () => testApplication());

it('holds a URI, cancels, and refuses to launch without a URI', function (): void {
    $launcher = GtkUriLauncher::new('https://example.com/');
    $launcher->setUri('https://example.com/x');
    $cancellable = GCancellable::new();
    $before = $cancellable->isCancelled();
    $cancellable->cancel();

    expect($launcher->getUri())->toBe('https://example.com/x')
        ->and(GtkUriLauncher::new(null)->getUri())->toBeNull()
        ->and([$before, $cancellable->isCancelled()])->toBe([false, true])
        ->and(fn () => GtkUriLauncher::new(null)->launch(null, null, fn () => null))->toThrow(GtkException::class, 'needs a URI');
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

it('refuses a result that is not its own launch\'s', function (): void {
    if (PHP_OS_FAMILY !== 'Darwin') {
        $this->markTestSkipped('Linux launches go through the desktop portal, which shows a dialog');
    }
    $first = GtkUriLauncher::new('venusian-no-handler:x');
    $second = GtkUriLauncher::new('venusian-no-handler:y');
    $cancellable = GCancellable::new();
    $cancellable->cancel();
    $results = [];
    $first->launch(null, $cancellable, function (GtkUriLauncher $source, GAsyncResult $result) use (&$results): void {
        $results[] = $result;
    });
    iterateUntil(fn (): bool => $results !== [], 3000);

    expect(fn () => $second->launchFinish($results[0]))->toThrow(ValueError::class, 'not a result of this launcher');
});
