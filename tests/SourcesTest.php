<?php

declare(strict_types=1);

beforeEach(fn () => drainContext());

it('fires a timeout once when it returns G_SOURCE_REMOVE', function (): void {
    $calls = 0;
    $tag = g_timeout_add(10, function () use (&$calls): bool {
        $calls++;

        return G_SOURCE_REMOVE;
    });

    expect($tag)->toBeGreaterThan(0)
        ->and(iterateUntil(function () use (&$calls): bool { return $calls > 0; }))->toBeTrue();

    usleep(30_000);
    drainContext();

    expect($calls)->toBe(1)
        ->and(g_source_remove($tag))->toBeFalse();
});

it('keeps firing a timeout that returns G_SOURCE_CONTINUE until removed', function (): void {
    $calls = 0;
    $tag = g_timeout_add(5, function () use (&$calls): bool {
        $calls++;

        return G_SOURCE_CONTINUE;
    });

    iterateUntil(function () use (&$calls): bool { return $calls >= 3; });

    expect($calls)->toBeGreaterThanOrEqual(3)
        ->and(g_source_remove($tag))->toBeTrue()
        ->and(g_source_remove($tag))->toBeFalse();
});

it('honours the timeout interval as the blocking budget', function (): void {
    $fired = false;
    g_timeout_add(40, function () use (&$fired): bool {
        $fired = true;

        return G_SOURCE_REMOVE;
    });

    $t = hrtime(true);
    iterateUntil(function () use (&$fired): bool { return $fired; });
    $ms = (hrtime(true) - $t) / 1e6;

    expect($ms)->toBeGreaterThanOrEqual(35.0)->toBeLessThan(150.0);
});

it('runs an idle source on the next iteration', function (): void {
    $ran = false;
    g_idle_add(function () use (&$ran): bool {
        $ran = true;

        return G_SOURCE_REMOVE;
    });

    GMainContext::default()->iteration(false);

    expect($ran)->toBeTrue();
});

it('wakes on a readable descriptor', function (string $as): void {
    [$read, $write] = stream_socket_pair(STREAM_PF_UNIX, STREAM_SOCK_STREAM, 0);
    $seen = null;

    g_unix_fd_add($as === 'Socket' ? socket_import_stream($read) : $read, GIOCondition::IN, function (int $fd, int $condition) use (&$seen): bool {
        $seen = [$fd, $condition];

        return G_SOURCE_REMOVE;
    });

    fwrite($write, 'x');

    expect(iterateUntil(function () use (&$seen): bool { return $seen !== null; }))->toBeTrue()
        ->and($seen[0])->toBeGreaterThan(2)
        ->and($seen[1] & GIOCondition::IN->value)->toBe(GIOCondition::IN->value);
})->with(['stream', 'Socket']);

it('accepts an OR of conditions as an int', function (): void {
    [$read, $write] = stream_socket_pair(STREAM_PF_UNIX, STREAM_SOCK_STREAM, 0);
    $seen = false;

    g_unix_fd_add($read, GIOCondition::IN->value | GIOCondition::HUP->value, function () use (&$seen): bool {
        $seen = true;

        return G_SOURCE_REMOVE;
    });
    fclose($write);

    expect(iterateUntil(function () use (&$seen): bool { return $seen; }))->toBeTrue();
});

it('lets an exception thrown by a source surface and removes the source', function (): void {
    $calls = 0;
    g_idle_add(function () use (&$calls): bool {
        $calls++;
        throw new LogicException('from the source');
    });

    expect(fn () => GMainContext::default()->iteration(false))->toThrow(LogicException::class, 'from the source');

    drainContext();
    expect($calls)->toBe(1);
});

it('rejects bad arguments', function (): void {
    expect(fn () => g_timeout_add(-1, fn () => false))->toThrow(ValueError::class)
        ->and(fn () => g_idle_add('no_such_function'))->toThrow(TypeError::class)
        ->and(fn () => g_unix_fd_add('3', GIOCondition::IN, fn () => false))->toThrow(TypeError::class)
        ->and(fn () => g_unix_fd_add(-1, GIOCondition::IN, fn () => false))->toThrow(ValueError::class)
        ->and(g_source_remove(0))->toBeFalse();
});
