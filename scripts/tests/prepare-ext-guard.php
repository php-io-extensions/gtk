#!/usr/bin/env php
<?php
/*
 * Positive and negative controls for scripts/prepare-ext.sh.
 *
 * Positive: a stub zephir writes config.m4, three ZEPHIR_REGISTER_CLASS
 * sites with the nested-namespace bug (arg 3 = "gtk"), and phpize leftovers.
 * prepare-ext must rewrite every site (fix_register_macro must fire),
 * stage src/, strip leftovers, write ext/.gen-stamp, and print PREPARE_EXT_OK.
 *
 * Negative: the same stub writes no config.m4. prepare-ext must exit
 * non-zero and never print PREPARE_EXT_OK.
 *
 * Prints PREPARE_EXT_GUARD_OK only when both scenarios behave.
 */

declare(strict_types=1);

$scriptsDir = dirname(__DIR__);
$fixtureM4 = __DIR__ . '/fixtures/prepare-ext/config.m4';
$fixtureDir = __DIR__ . '/fixtures/prepare-ext';
$prepare = $scriptsDir . '/prepare-ext.sh';
$failures = [];

function rrmdir(string $dir): void
{
    if (!is_dir($dir)) {
        return;
    }
    $it = new RecursiveIteratorIterator(
        new RecursiveDirectoryIterator($dir, FilesystemIterator::SKIP_DOTS),
        RecursiveIteratorIterator::CHILD_FIRST
    );
    foreach ($it as $file) {
        $file->isDir() ? rmdir($file->getPathname()) : unlink($file->getPathname());
    }
    rmdir($dir);
}

function writeTree(string $tmp, bool $writeConfigM4): void
{
    mkdir("{$tmp}/src", 0755, true);
    mkdir("{$tmp}/gtk", 0755, true);
    mkdir("{$tmp}/optimizers", 0755, true);
    file_put_contents("{$tmp}/src/gtk-sample.h", "/* sample header */\n");
    file_put_contents("{$tmp}/src/phpgtk-support.h", "/* marshalling */\n");
    file_put_contents("{$tmp}/src/phpgtk-support.c", "/* marshalling impl */\n");
    file_put_contents("{$tmp}/config.json", json_encode([
        'namespace' => 'gtk',
        'name' => 'gtk',
        'extra-sources' => ['src/phpgtk-support.c'],
    ], JSON_PRETTY_PRINT | JSON_UNESCAPED_SLASHES) . "\n");

    $writeM4 = $writeConfigM4 ? '1' : '0';
    $stub = <<<SH
#!/bin/bash
set -euo pipefail
if [ "\${1:-}" != "generate" ]; then
    echo "stub-zephir: expected generate" >&2
    exit 1
fi
mkdir -p ext/gtk/gtk/gtkbutton ext/gtk/gio/gapplication ext/gtk/bridge ext/modules
if [ "{$writeM4}" = "1" ]; then
    cp "\$STUB_M4" ext/config.m4
    cp "\$STUB_FIXDIR/gtkbutton.zep.c" ext/gtk/gtk/gtkbutton/gtkbutton.zep.c
    cp "\$STUB_FIXDIR/gapplication.zep.c" ext/gtk/gio/gapplication/gapplication.zep.c
    cp "\$STUB_FIXDIR/bridge.zep.c" ext/gtk/bridge/bridge.zep.c
    echo "MAKEFILE" > ext/Makefile
    echo "so" > ext/modules/dummy.so
    echo "configure" > ext/configure
fi
SH;
    file_put_contents("{$tmp}/stub-zephir", $stub);
    chmod("{$tmp}/stub-zephir", 0755);
}

function runPrepare(string $tmp): array
{
    $cmd = sprintf(
        'STUB_M4=%s STUB_FIXDIR=%s GTK_ROOT=%s ZEPHIR_BIN=%s bash %s 2>&1',
        escapeshellarg($GLOBALS['fixtureM4']),
        escapeshellarg($GLOBALS['fixtureDir']),
        escapeshellarg($tmp),
        escapeshellarg($tmp . '/stub-zephir'),
        escapeshellarg($GLOBALS['prepare'])
    );
    $output = [];
    exec($cmd, $output, $code);

    return ['code' => $code, 'text' => implode("\n", $output)];
}

if (!is_file($prepare) || !is_file($fixtureM4)
    || !is_file($fixtureDir . '/gtkbutton.zep.c')
    || !is_file($fixtureDir . '/gapplication.zep.c')
    || !is_file($fixtureDir . '/bridge.zep.c')) {
    fwrite(STDERR, "prepare-ext-guard: missing prepare-ext.sh or fixtures\n");
    exit(1);
}

$good = sys_get_temp_dir() . '/gtk-prepare-ext-good-' . getmypid();
$bad = sys_get_temp_dir() . '/gtk-prepare-ext-bad-' . getmypid();
rrmdir($good);
rrmdir($bad);

try {
    writeTree($good, true);
    $result = runPrepare($good);

    if ($result['code'] !== 0) {
        $failures[] = "good tree: prepare-ext exited {$result['code']}:\n{$result['text']}";
    }
    if (!str_contains($result['text'], 'PREPARE_EXT_OK')) {
        $failures[] = "good tree: missing PREPARE_EXT_OK\n{$result['text']}";
    }
    if (!preg_match('/rewrote ([1-9][0-9]*) registration site/', $result['text'], $rm)) {
        $failures[] = "good tree: fix_register_macro did not fire:\n{$result['text']}";
    } elseif ((int) $rm[1] < 3) {
        $failures[] = "good tree: expected at least 3 rewritten sites, got {$rm[1]}:\n{$result['text']}";
    }

    $rewritten = [];
    foreach ([
        'ext/gtk/gtk/gtkbutton/gtkbutton.zep.c',
        'ext/gtk/gio/gapplication/gapplication.zep.c',
        'ext/gtk/bridge/bridge.zep.c',
    ] as $rel) {
        $rewritten[$rel] = is_file("{$good}/{$rel}") ? (string) file_get_contents("{$good}/{$rel}") : '';
    }

    if (!str_contains($rewritten['ext/gtk/gtk/gtkbutton/gtkbutton.zep.c'], 'GtkButton, gtk_gtk_gtkbutton, gtkbutton')) {
        $failures[] = 'good tree: GtkButton registration was not rewritten to gtk_gtk_gtkbutton';
    }
    if (!str_contains($rewritten['ext/gtk/gio/gapplication/gapplication.zep.c'], 'GApplication, gtk_gio_gapplication, gapplication')) {
        $failures[] = 'good tree: GApplication registration was not rewritten to gtk_gio_gapplication';
    }
    if (!str_contains($rewritten['ext/gtk/bridge/bridge.zep.c'], 'Bridge, gtk_bridge, bridge')) {
        $failures[] = 'good tree: Bridge registration was not rewritten to gtk_bridge';
    }
    foreach ($rewritten as $rel => $src) {
        if (preg_match('/ZEPHIR_REGISTER_CLASS\([^)]*,\s*gtk,/', $src)) {
            $failures[] = "good tree: {$rel} still has the un-fixed 'gtk' namespace prefix";
        }
    }

    if (!is_file("{$good}/ext/src/gtk-sample.h") || !is_file("{$good}/ext/src/phpgtk-support.c")) {
        $failures[] = 'good tree: src/ was not staged into ext/src/';
    }

    $stamp = is_file("{$good}/ext/.gen-stamp") ? trim((string) file_get_contents("{$good}/ext/.gen-stamp")) : '';
    if (!preg_match('/^[0-9a-f]{64}$/', $stamp)) {
        $failures[] = "good tree: ext/.gen-stamp missing or not a SHA-256 ({$stamp})";
    }

    foreach (['ext/Makefile', 'ext/modules/dummy.so', 'ext/configure'] as $leftover) {
        if (is_file("{$good}/{$leftover}")) {
            $failures[] = "good tree: leftover {$leftover} was not stripped";
        }
    }

    writeTree($bad, false);
    $badResult = runPrepare($bad);
    if ($badResult['code'] === 0) {
        $failures[] = "negative tree: prepare-ext accepted a generate with no config.m4:\n{$badResult['text']}";
    }
    if (str_contains($badResult['text'], 'PREPARE_EXT_OK')) {
        $failures[] = 'negative tree: printed PREPARE_EXT_OK';
    }
    if (!str_contains($badResult['text'], 'config.m4')) {
        $failures[] = "negative tree: expected a config.m4 diagnostic:\n{$badResult['text']}";
    }
} finally {
    rrmdir($good);
    rrmdir($bad);
}

if ($failures !== []) {
    foreach ($failures as $f) {
        fwrite(STDERR, "prepare-ext-guard: {$f}\n");
    }
    exit(1);
}

echo "PREPARE_EXT_GUARD_OK\n";
