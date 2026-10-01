<?php

declare(strict_types=1);

beforeEach(fn () => drainContext());

it('hands back one PHP object for the default context', function (): void {
    expect(GMainContext::default())->toBe(GMainContext::default())
        ->and(GMainContext::default()->pointer())->toBeGreaterThan(0)
        ->and(GMainContext::getThreadDefault())->toBeNull();
});

it('has nothing pending once drained and does not dispatch on a non-blocking iteration', function (): void {
    $ctx = GMainContext::default();

    expect($ctx->pending())->toBeFalse()
        ->and($ctx->iteration(false))->toBeFalse();
});

it('returns from a blocking iteration at once after wakeup', function (): void {
    $ctx = GMainContext::default();
    $ctx->wakeup();

    $t = hrtime(true);
    $ctx->iteration(true);

    expect((hrtime(true) - $t) / 1e6)->toBeLessThan(20.0);
});

it('acquires and releases ownership', function (): void {
    $ctx = GMainContext::default();

    expect($ctx->acquire())->toBeTrue()
        ->and($ctx->isOwner())->toBeTrue();

    $ctx->release();
});
