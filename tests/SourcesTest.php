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

/**
 * The descriptor number a socket stream holds: the /dev/fd entry that is the same socket. Linux links it
 * to "socket:[<inode>]", which stat() cannot follow; on macOS it is the entry with the same inode and file
 * type (macOS reports a socket's device as -1 through fstat and as /dev's through /dev/fd).
 */
function descriptorOf($socket): int
{
    $own = fstat($socket);
    foreach (scandir('/dev/fd') as $entry) {
        if (ctype_digit($entry) && is_link('/dev/fd/'.$entry) && readlink('/dev/fd/'.$entry) === 'socket:['.$own['ino'].']') {
            return (int) $entry;
        }
        // scandir()'s own descriptor is listed too, and closed by now.
        $candidate = ctype_digit($entry) && file_exists('/dev/fd/'.$entry) ? stat('/dev/fd/'.$entry) : false;
        if ($candidate !== false && $candidate['ino'] === $own['ino'] && ($candidate['mode'] & 0170000) === ($own['mode'] & 0170000)) {
            return (int) $entry;
        }
    }

    throw new RuntimeException('no /dev/fd entry for the socket');
}

it('wakes on a readable descriptor', function (): void {
    [$read, $write] = stream_socket_pair(STREAM_PF_UNIX, STREAM_SOCK_STREAM, 0);
    $fd = descriptorOf($read);
    $seen = null;

    g_unix_fd_add($fd, GIOCondition::IN, function (int $fd, int $condition) use (&$seen): bool {
        $seen = [$fd, $condition];

        return G_SOURCE_REMOVE;
    });

    fwrite($write, 'x');

    expect(iterateUntil(function () use (&$seen): bool { return $seen !== null; }))->toBeTrue()
        ->and($seen[0])->toBe($fd)
        ->and($seen[1] & GIOCondition::IN->value)->toBe(GIOCondition::IN->value);
});

it('takes the descriptor as a gint, as g_unix_fd_add does, not a stream', function (): void {
    [$read] = stream_socket_pair(STREAM_PF_UNIX, STREAM_SOCK_STREAM, 0);

    expect(fn () => g_unix_fd_add($read, GIOCondition::IN, fn () => false))->toThrow(TypeError::class);
});

it('accepts an OR of conditions as an int', function (): void {
    [$read, $write] = stream_socket_pair(STREAM_PF_UNIX, STREAM_SOCK_STREAM, 0);
    $seen = false;

    g_unix_fd_add(descriptorOf($read), GIOCondition::IN->value | GIOCondition::HUP->value, function () use (&$seen): bool {
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
        ->and(fn () => g_unix_fd_add(4_294_967_296, GIOCondition::IN, fn () => false))->toThrow(ValueError::class);
});

it('refuses a source id with no guint form, which the conversion would truncate', function (): void {
    expect(fn () => g_source_remove(-1))->toThrow(ValueError::class, 'g_source_remove(): Argument #1 ($tag) must be between 0 and 4294967295')
        ->and(fn () => g_source_remove(4_294_967_296))->toThrow(ValueError::class, 'must be between 0 and 4294967295');
});

it('hands GLib a negative fd and source ids it does not hold, and answers what GLib answers', function (): void {
    $run = gtkChild(<<<'PHP'
        // GLib takes a negative fd as a source that never dispatches.
        $negative = g_unix_fd_add(-1, GIOCondition::IN, fn () => false);

        return [$negative > 0, g_source_remove($negative), g_source_remove(0), g_source_remove(999_999)];
    PHP, init: false);

    expect($run['result'])->toBe([true, true, false, false])
        ->and($run['stderr'])->toContain("g_source_remove: assertion 'tag > 0' failed")
        ->and($run['stderr'])->toContain('Source ID 999999 was not found when attempting to remove it');
});
