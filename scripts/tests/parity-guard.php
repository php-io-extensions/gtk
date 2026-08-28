#!/usr/bin/env php
<?php
/*
 * Negative and positive controls for check-parity.php. Builds a minimal
 * package (one constructor + register, one setter), generates .zep/optimizers,
 * then asserts PARITY_OK on the good tree and a drift diagnostic on each
 * known failure mode: composite extra native call, constructor with a
 * second native call, missing optimizer, extra optimizer, arity mismatch,
 * extra-sources holes, @zep without a prototype, prototype without @zep.
 *
 * Prints PARITY_GUARD_OK only when every scenario behaves.
 */

declare(strict_types=1);

$scriptsDir = dirname(__DIR__);
$packageRoot = dirname($scriptsDir);
$check = $scriptsDir . '/check-parity.php';
$gen = $scriptsDir . '/gen-zep.php';
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

function runPhp(string $script, string $root): array
{
    $cmd = sprintf(
        '%s %s %s 2>&1',
        escapeshellarg(PHP_BINARY),
        escapeshellarg($script),
        escapeshellarg($root)
    );
    $output = [];
    exec($cmd, $output, $code);

    return ['code' => $code, 'text' => implode("\n", $output)];
}

function writeGood(string $tmp): void
{
    mkdir("{$tmp}/src", 0755, true);
    file_put_contents("{$tmp}/config.json", json_encode([
        'namespace' => 'gtk',
        'name' => 'gtk',
        'extra-sources' => ['src/gtk-sample.c'],
    ], JSON_PRETTY_PRINT | JSON_UNESCAPED_SLASHES) . "\n");

    file_put_contents("{$tmp}/src/gtk-sample.h", <<<'H'
#ifndef PHP_GTK_GTK_SAMPLE_H
#define PHP_GTK_GTK_SAMPLE_H

#include "php.h"

/*@zep Gtk\GtkSample new() -> int */
zend_long phpgtk_gtksample_new(void);
/*@zep Gtk\GtkSample setLabel(int handle, string label) -> void */
void phpgtk_gtksample_set_label(zval *handle, zval *label);
/*@reserved Gtk\GtkSample gtk_sample_set_child(...) — reserved */

#endif
H);

    file_put_contents("{$tmp}/src/gtk-sample.c", goodImpl());
}

function goodImpl(): string
{
    return <<<'C'
#include "gtk-sample.h"

zend_long phpgtk_gtksample_new(void)
{
    GtkWidget *w = gtk_sample_new();
    char c = "x"[0];
    (void) c;

    return phpgtk_handle_register(w);
}

void phpgtk_gtksample_set_label(zval *handle, zval *label)
{
    GtkSample *self = (GtkSample *) (uintptr_t) 0;
    gtk_sample_set_label(self, "ok");
    g_free(NULL);
    (void) handle;
    (void) label;
}
C;
}

function generate(string $tmp, string $gen): void
{
    $r = runPhp($gen, $tmp);
    if ($r['code'] !== 0 || !str_contains($r['text'], 'GEN_OK')) {
        fwrite(STDERR, "fixture generator failed:\n{$r['text']}\n");
        exit(1);
    }
}

function expectOk(string $label, array $result): void
{
    global $failures;
    if ($result['code'] !== 0 || !str_contains($result['text'], 'PARITY_OK')) {
        $failures[] = "{$label}: expected PARITY_OK, got exit {$result['code']}:\n{$result['text']}";
    }
}

function expectFail(string $label, array $result, string $needle): void
{
    global $failures;
    if ($result['code'] === 0 || str_contains($result['text'], 'PARITY_OK')) {
        $failures[] = "{$label}: expected non-zero without PARITY_OK, got exit {$result['code']}:\n{$result['text']}";
        return;
    }
    if (!str_contains($result['text'], $needle)) {
        $failures[] = "{$label}: failed but diagnostic did not contain '{$needle}':\n{$result['text']}";
    }
}

function freshTree(string $gen): string
{
    $tmp = sys_get_temp_dir() . '/gtk-parity-' . bin2hex(random_bytes(4));
    writeGood($tmp);
    generate($tmp, $gen);

    return $tmp;
}

// 0. The real package must already be green.
$real = runPhp($check, $packageRoot);
expectOk('real package', $real);

$trees = [];

// 1. Constructor + register + single-call setter (C subscripts and g_free
// must not count as a second native call).
$good = freshTree($gen);
$trees[] = $good;
expectOk('good fixture', runPhp($check, $good));

// 2. Extra native call on a non-constructor binding.
$composite = freshTree($gen);
$trees[] = $composite;
file_put_contents("{$composite}/src/gtk-sample.c", str_replace(
    'gtk_sample_set_label(self, "ok");',
    "gtk_sample_set_label(self, \"ok\");\n    gtk_widget_set_visible((GtkWidget *) self, 1);",
    goodImpl()
));
expectFail('composite extra native', runPhp($check, $composite), 'gtk_widget_set_visible');

// 3. Constructor binding with a second native call (register is not native).
$ctorExtra = freshTree($gen);
$trees[] = $ctorExtra;
file_put_contents("{$ctorExtra}/src/gtk-sample.c", str_replace(
    'GtkWidget *w = gtk_sample_new();',
    "GtkWidget *w = gtk_sample_new();\n    gtk_widget_set_visible(w, 1);",
    goodImpl()
));
expectFail('constructor composite', runPhp($check, $ctorExtra), 'one ext call = one native call');

// 4. Missing optimizer.
$missingOpt = freshTree($gen);
$trees[] = $missingOpt;
$optFile = glob("{$missingOpt}/optimizers/*SetLabelOptimizer.php")[0] ?? null;
if (is_null($optFile)) {
    $failures[] = 'missing-optimizer: could not find generated SetLabel optimizer';
} else {
    unlink($optFile);
    expectFail('missing optimizer', runPhp($check, $missingOpt), 'no optimizer');
}

// 5. Extra optimizer with no zep call.
$extraOpt = freshTree($gen);
$trees[] = $extraOpt;
$donor = "{$extraOpt}/optimizers/GtksampleNewOptimizer.php";
if (!is_file($donor)) {
    $failures[] = 'extra-optimizer: missing generated GtksampleNewOptimizer.php';
} else {
    $extraSrc = (string) file_get_contents($donor);
    $extraSrc = str_replace('phpgtk_gtksample_new', 'phpgtk_gtksample_ghost', $extraSrc);
    $extraSrc = str_replace('GtksampleNewOptimizer', 'GtksampleGhostOptimizer', $extraSrc);
    $extraSrc = str_replace('gtksample_new', 'gtksample_ghost', $extraSrc);
    file_put_contents("{$extraOpt}/optimizers/GtksampleGhostOptimizer.php", $extraSrc);
    expectFail('extra optimizer', runPhp($check, $extraOpt), 'no zep call');
}

// 6. Optimizer arity disagrees with the C prototype.
$arity = freshTree($gen);
$trees[] = $arity;
$optFile = glob("{$arity}/optimizers/*SetLabelOptimizer.php")[0];
$src = (string) file_get_contents($optFile);
$src = preg_replace('/!== 2/', '!== 99', $src, 1);
file_put_contents($optFile, $src);
expectFail('arity mismatch', runPhp($check, $arity), 'arity');

// 7. src/*.c not listed in extra-sources.
$missingSrc = freshTree($gen);
$trees[] = $missingSrc;
file_put_contents("{$missingSrc}/config.json", json_encode([
    'namespace' => 'gtk',
    'name' => 'gtk',
    'extra-sources' => [],
], JSON_PRETTY_PRINT) . "\n");
expectFail('extra-sources hole', runPhp($check, $missingSrc), 'not in config.json extra-sources');

// 8. extra-sources lists a file that does not exist.
$phantom = freshTree($gen);
$trees[] = $phantom;
file_put_contents("{$phantom}/config.json", json_encode([
    'namespace' => 'gtk',
    'name' => 'gtk',
    'extra-sources' => ['src/gtk-sample.c', 'src/gtk-ghost.c'],
], JSON_PRETTY_PRINT) . "\n");
expectFail('extra-sources phantom', runPhp($check, $phantom), 'does not exist');

// 9. Prototype with no preceding @zep.
$noZep = freshTree($gen);
$trees[] = $noZep;
$h = (string) file_get_contents("{$noZep}/src/gtk-sample.h");
$h = str_replace(
    "/*@reserved Gtk\\GtkSample gtk_sample_set_child(...) — reserved */\n",
    "void phpgtk_gtksample_ghost(zval *handle);\n",
    $h
);
file_put_contents("{$noZep}/src/gtk-sample.h", $h);
expectFail('prototype without @zep', runPhp($check, $noZep), 'no preceding @zep');

// 10. @zep with no following prototype.
$noProto = freshTree($gen);
$trees[] = $noProto;
$h = (string) file_get_contents("{$noProto}/src/gtk-sample.h");
$h = str_replace(
    "/*@reserved Gtk\\GtkSample gtk_sample_set_child(...) — reserved */\n",
    "/*@zep Gtk\\GtkSample ghost(int handle) -> void */\n",
    $h
);
file_put_contents("{$noProto}/src/gtk-sample.h", $h);
expectFail('zep without prototype', runPhp($check, $noProto), 'not followed by a parseable C prototype');

foreach ($trees as $dir) {
    rrmdir($dir);
}

if ($failures !== []) {
    foreach ($failures as $f) {
        fwrite(STDERR, "parity-guard: {$f}\n\n");
    }
    exit(1);
}

echo "PARITY_GUARD_OK\n";
