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

/** Signal numbers a child process dies by (SIGBUS is 10 on macOS, 7 on Linux). */
const PROBE_SIGTRAP = 5;
const PROBE_SIGABRT = 6;
const PROBE_SIGBUS = PHP_OS_FAMILY === 'Darwin' ? 10 : 7;
const PROBE_SIGSEGV = 11;

/**
 * Skips a tests/Probes test unless the loaded ext-gtk is a probe build (--enable-gtk-probes),
 * the only build where env PHPGTK_PROBE_OFF turns a kept refusal off.
 */
function requireProbeBuild(): void
{
    if (! defined('PHPGTK_PROBES')) {
        test()->markTestSkipped('ext-gtk is not a probe build (configure --enable-gtk-probes): PHPGTK_PROBES is undefined');
    }
}

/**
 * The .so a child process loads: for gtk env PHPGTK_PROBE_EXT, for another extension
 * env PHPGTK_PROBE_<NAME>, else the file in this PHP's extension_dir.
 */
function probeExtension(string $name): string
{
    $given = getenv($name === 'gtk' ? 'PHPGTK_PROBE_EXT' : 'PHPGTK_PROBE_'.strtoupper($name));

    return is_string($given) && $given !== '' ? $given : ini_get('extension_dir').'/'.$name.'.so';
}

/**
 * Runs $code in a child of this PHP with only ext-gtk loaded (and ext-parallel when $parallel),
 * after gtk_init() unless $init is false; drainContext() is defined there as here. The code is
 * a function body: what it returns comes
 * back as 'result' (JSON), a throw as 'threw' ("Class: message"). GLib writes its criticals and
 * warnings to the child's stderr. $siteOff names the kept site env PHPGTK_PROBE_OFF turns off
 * (a probe build only); null keeps every site. $gmalloc runs the child under libgmalloc with
 * Zend's allocator off, so a native over-read of PHP memory faults at the guard page.
 *
 * @return array{signal: ?int, exit: ?int, result: mixed, threw: ?string, survived: bool, stdout: string, stderr: string}
 */
function gtkChild(string $code, ?string $siteOff = null, bool $gmalloc = false, bool $parallel = false, bool $init = true): array
{
    if ($gmalloc && PHP_OS_FAMILY !== 'Darwin') {
        // Without the guard page an over-read lands in mapped memory or not as the allocator happens to lay it out.
        test()->markTestSkipped('the probe faults its over-read at a libgmalloc guard page, which only macOS has');
    }

    $start = $init ? "gtk_init();\n" : '';
    $script = <<<PHP
    <?php
    declare(strict_types=1);
    function drainContext(): void {
        \$ctx = GMainContext::default();
        while (\$ctx->pending()) {
            \$ctx->iteration(false);
        }
    }
    {$start}
    try {
        \$result = (static function () {
    {$code}
        })();
        echo "\\nRESULT ", json_encode(\$result, JSON_PRESERVE_ZERO_FRACTION | JSON_PARTIAL_OUTPUT_ON_ERROR), "\\n";
    } catch (Throwable \$t) {
        echo "\\nREFUSED ", get_class(\$t), ': ', \$t->getMessage(), "\\n";
    }
    echo "SURVIVED\\n";
    PHP;

    $base = tempnam(sys_get_temp_dir(), 'gtk-child');
    $file = $base.'.php';
    $out = tempnam(sys_get_temp_dir(), 'gtk-child-out');
    $err = tempnam(sys_get_temp_dir(), 'gtk-child-err');
    file_put_contents($file, $script);

    $env = getenv();
    unset($env['PHPGTK_PROBE_OFF'], $env['DYLD_INSERT_LIBRARIES'], $env['USE_ZEND_ALLOC'], $env['G_DEBUG']);
    $env['XDEBUG_MODE'] = 'off';
    if ($siteOff !== null) {
        $env['PHPGTK_PROBE_OFF'] = $siteOff;
    }
    if ($gmalloc) {
        $env['DYLD_INSERT_LIBRARIES'] = '/usr/lib/libgmalloc.dylib';
        $env['USE_ZEND_ALLOC'] = '0';
    }

    $command = [PHP_BINARY, '-n', '-d', 'memory_limit=128M'];
    if ($parallel) {
        array_push($command, '-d', 'extension='.probeExtension('parallel'));
    }
    array_push($command, '-d', 'extension='.probeExtension('gtk'), $file);

    $process = proc_open($command, [0 => ['file', '/dev/null', 'r'], 1 => ['file', $out, 'w'], 2 => ['file', $err, 'w']], $pipes, null, $env);
    $deadline = microtime(true) + 60.0;
    do {
        $status = proc_get_status($process);
        if ($status['running'] && microtime(true) > $deadline) {
            proc_terminate($process, 9);
        }
        if ($status['running']) {
            usleep(20_000);
        }
    } while ($status['running']);
    proc_close($process);

    $stdout = (string) file_get_contents($out);
    $stderr = (string) file_get_contents($err);
    $result = preg_match('/^RESULT (.*)$/m', $stdout, $m) === 1 ? json_decode($m[1], true) : null;
    $threw = preg_match('/^REFUSED (.*)$/m', $stdout, $m) === 1 ? $m[1] : null;

    @unlink($base);
    @unlink($file);
    @unlink($out);
    @unlink($err);

    return [
        'signal' => $status['signaled'] ? $status['termsig'] : null,
        'exit' => $status['signaled'] ? null : $status['exitcode'],
        'result' => $result,
        'threw' => $threw,
        'survived' => str_contains($stdout, "SURVIVED\n"),
        'stdout' => $stdout,
        'stderr' => $stderr,
    ];
}

/** One application for the process: GTK initialises once, on its startup. */
function testApplication(): GtkApplication
{
    static $app = null;

    if ($app === null) {
        $app = GtkApplication::new('com.projectsaturnstudios.GtkTests', GApplicationFlags::NON_UNIQUE);
        g_signal_connect($app, 'activate', fn (): null => null);
        $app->register(null);
    }

    return $app;
}
