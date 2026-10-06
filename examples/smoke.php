<?php

declare(strict_types=1);

/*
 * End-to-end check of the bridge bindings on a real display, macOS or Linux:
 *
 *   php examples/smoke.php [--hold=SECONDS]
 *
 * Linux needs the session's WAYLAND_DISPLAY (or DISPLAY) and DBUS_SESSION_BUS_ADDRESS.
 *
 * 1. connect      GtkApplication::new + register (startup initialises GTK) + hold + activate
 *                 macOS: the Dock shows the icon; Linux: the application id is owned on the session bus
 * 2. pump         drain what the default context has pending
 * 3. budget       a 50ms timeout ends a blocking iteration at the budget
 * 4. wakeup       g_main_context_wakeup makes the next blocking iteration return at once
 * 5. idle         an idle source runs on the next iteration
 * 6. fd wake      a pipe written by a child process ends a blocking iteration through g_unix_fd_add
 * 7. nested wake  the same, through a kqueue (macOS) or epoll (Linux) fd
 * 8. run/quit     GApplication::run until a timeout calls quit
 * 9. disconnect   run() ends with shutdown (unregistered); release the hold
 *
 * --hold keeps pumping that long after step 1, for a look at the Dock / taskbar.
 * Prints SMOKE_OK when every step held.
 */

$hold = 0.0;
foreach (array_slice($argv, 1) as $arg) {
    if (str_starts_with($arg, '--hold=')) {
        $hold = (float) substr($arg, 7);
    }
}

const APP_ID = 'com.projectsaturnstudios.GtkSmoke';

function check(bool $ok, string $what): void
{
    printf("%s %s\n", $ok ? 'ok  ' : 'FAIL', $what);
    if (! $ok) {
        exit(1);
    }
}

function dock_type(): ?string
{
    foreach (explode("\n", (string) shell_exec('lsappinfo list 2>/dev/null')) as $line) {
        if (preg_match('/pid = ' . getmypid() . '\b.*?type="([^"]+)"/', $line, $m)) {
            return $m[1];
        }
    }

    return null;
}

function bus_owns(string $name): bool
{
    $reply = (string) shell_exec(sprintf(
        'dbus-send --session --print-reply --dest=org.freedesktop.DBus /org/freedesktop/DBus org.freedesktop.DBus.NameHasOwner string:%s 2>&1',
        escapeshellarg($name),
    ));

    return str_contains($reply, 'boolean true');
}

/**
 * Iterate (blocking) until $done() holds or $limit seconds pass; returns elapsed ms.
 * A guard timeout bounds the last blocking iteration when nothing else would end it.
 */
function iterate_until(GMainContext $ctx, callable $done, float $limit): float
{
    $expired = false;
    $guard = g_timeout_add((int) ($limit * 1000), function () use (&$expired): bool {
        $expired = true;

        return G_SOURCE_REMOVE;
    });

    $t = hrtime(true);
    while (! $done() && ! $expired) {
        $ctx->iteration(true);
    }
    $ms = (hrtime(true) - $t) / 1e6;

    if (! $expired) {
        g_source_remove($guard);
    }

    return $ms;
}

/** A child that sleeps, writes one byte to its stdout pipe, and reports when it wrote. */
function delayed_writer(float $delay): array
{
    $proc = proc_open(
        [PHP_BINARY, '-n', '-r', sprintf('usleep(%d); fwrite(STDOUT, "x"); fflush(STDOUT); fwrite(STDERR, (string) microtime(true));', (int) ($delay * 1e6))],
        [1 => ['pipe', 'w'], 2 => ['pipe', 'w']],
        $pipes,
    );

    return [$proc, $pipes[1], $pipes[2]];
}

$mac = PHP_OS_FAMILY === 'Darwin';
$ctx = GMainContext::default();

// 1. connect
$app = GtkApplication::new(APP_ID, GApplicationFlags::DEFAULT_FLAGS);
$signals = [];
g_signal_connect($app, 'startup', function (GtkApplication $a) use (&$signals): void {
    $signals[] = 'startup';
});
g_signal_connect($app, 'activate', function (GtkApplication $a) use (&$signals): void {
    $signals[] = 'activate';
});

check($app->register() && $app->getIsRegistered() && ! $app->getIsRemote(), 'register(): registered as the primary instance');
check(gtk_is_initialized(), sprintf('startup initialised GTK %d.%d.%d', gtk_get_major_version(), gtk_get_minor_version(), gtk_get_micro_version()));
$app->hold();
$app->activate();
check($signals === ['startup', 'activate'], 'startup and activate handlers ran');

if ($mac) {
    iterate_until($ctx, fn () => dock_type() === 'Foreground', 2.0);
    check(dock_type() === 'Foreground', 'lsappinfo: type="Foreground" (Dock icon up), pid ' . getmypid());
} else {
    check(bus_owns(APP_ID), 'session bus: ' . APP_ID . ' is owned');
}

if ($hold > 0) {
    echo "holding for {$hold}s\n";
    $until = microtime(true) + $hold;
    while (microtime(true) < $until) {
        g_timeout_add(50, fn (): bool => false);
        $ctx->iteration(true);
    }
}

// 2. pump
$pumped = 0;
while ($ctx->pending()) {
    $ctx->iteration(false);
    $pumped++;
}
check(! $ctx->pending(), "pump drained {$pumped} pending iteration(s)");

// 3. budget
$fired = false;
g_timeout_add(50, function () use (&$fired): bool {
    $fired = true;

    return G_SOURCE_REMOVE;
});
$ms = iterate_until($ctx, function () use (&$fired): bool {
    return $fired;
}, 2.0);
check($fired && $ms >= 45 && $ms < 80, sprintf('50ms timeout ended the blocking wait after %.1fms', $ms));

// 4. wakeup
$ctx->wakeup();
$t = hrtime(true);
$ctx->iteration(true);
$ms = (hrtime(true) - $t) / 1e6;
check($ms < 5, sprintf('wakeup(): the next blocking iteration returned in %.2fms', $ms));

// 5. idle
$ran = 0;
g_idle_add(function () use (&$ran): bool {
    $ran++;

    return G_SOURCE_REMOVE;
});
$ctx->iteration(false);
check($ran === 1, 'idle source ran once on the next iteration');

// 6. fd wake
[$proc, $out, $err] = delayed_writer(0.2);
$woke = null;
$tag = g_unix_fd_add($out, GIOCondition::IN, function (int $fd, int $condition) use (&$woke): bool {
    $woke = microtime(true);

    return G_SOURCE_REMOVE;
});
$ms = iterate_until($ctx, function () use (&$woke): bool {
    return $woke !== null;
}, 2.0);
$wrote = (float) stream_get_contents($err);
fread($out, 1);
proc_close($proc);
$latency = ($woke - $wrote) * 1e3;
check($woke !== null, sprintf('pipe fd ended the wait after %.1fms, %.2fms after the child wrote', $ms, $latency));
check($latency < 5, 'fd wake latency under 5ms');

// 7. nested wake: the waiter's own descriptor in GLib's poll set.
[$proc, $out, $err] = delayed_writer(0.2);
if ($mac && extension_loaded('kqueue')) {
    $waiter = kqueue();
    $kev = new kevent();
    EV_SET($kev, $out, EVFILT_READ, EV_ADD, 0, 0, 0);
    $none = null;
    kevent($waiter, [$kev], 1, $none, 0, null);
    $glance = function () use ($waiter): int {
        $events = [];

        return kevent($waiter, [], 0, $events, 4, new timespec());
    };
    $kind = 'kqueue';
} elseif (! $mac && extension_loaded('epoll')) {
    $waiter = epoll_create1(0);
    epoll_ctl($waiter, EPOLL_CTL_ADD, $out, EPOLLIN, 1);
    $glance = fn (): int => count(epoll_wait($waiter, 4, 0) ?: []);
    $kind = 'epoll';
} else {
    $kind = null;
}

if ($kind !== null) {
    $woke = null;
    g_unix_fd_add($waiter, GIOCondition::IN, function () use (&$woke): bool {
        $woke = microtime(true);

        return G_SOURCE_REMOVE;
    });
    $ms = iterate_until($ctx, function () use (&$woke): bool {
        return $woke !== null;
    }, 2.0);
    $wrote = (float) stream_get_contents($err);
    $n = $glance();
    $latency = ($woke - $wrote) * 1e3;
    check($woke !== null && $latency < 5, sprintf('%s fd ended the wait after %.1fms, %.2fms after the child wrote', $kind, $ms, $latency));
    check($n === 1, "the glance after the wake reads the pipe event off the {$kind}");
} else {
    echo "skip nested wake: neither ext-kqueue nor ext-epoll loaded\n";
}
fread($out, 1);
proc_close($proc);

// 8. run/quit: GApplication's own loop, ended from a timeout inside it.
$signals = [];
g_timeout_add(100, function () use ($app): bool {
    $app->quit();

    return G_SOURCE_REMOVE;
});
$t = hrtime(true);
$status = $app->run([PHP_BINARY]);
$ms = (hrtime(true) - $t) / 1e6;
check($status === 0 && $ms >= 90 && $ms < 1000, sprintf('run() returned %d after %.1fms once a timeout called quit()', $status, $ms));
check($signals === ['activate'], 'run() activated the application again');

// 9. disconnect: run() ended with GApplication's shutdown, which unregisters; the hold is released to balance hold().
check(! $app->getIsRegistered(), 'run() shut the application down: no longer registered');
$app->release();

echo "SMOKE_OK\n";
