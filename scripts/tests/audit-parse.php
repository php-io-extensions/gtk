#!/usr/bin/env php
<?php
/*
 * Parser oracle for audit-gir.php: the fixture gir has a known exact
 * composition; --count must report it precisely. Also runs a control for a
 * sibling type in the same file (proves we are not counting globally) and
 * for a class absent from the gir (must exit non-zero).
 * Prints GIR_PARSE_OK only when every assertion passes.
 */

declare(strict_types=1);

$scriptsDir = dirname(__DIR__);
$gir = __DIR__ . '/fixtures/audit/gir/Gtk-4.0.gir';

function runCount(string $scriptsDir, string $gir, string $cType): array
{
    $cmd = sprintf(
        '%s %s --count %s %s 2>&1',
        escapeshellarg(PHP_BINARY),
        escapeshellarg($scriptsDir . '/audit-gir.php'),
        escapeshellarg($gir),
        escapeshellarg($cType)
    );
    exec($cmd, $output, $exitCode);

    return [implode("\n", $output), $exitCode];
}

[$text, $code] = runCount($scriptsDir, $gir, 'GtkWidget');
$expected = 'GtkWidget kind=class abstract=yes constructors=1 methods=3 functions=0 expected=4 signals=1 properties=1';
if ($code !== 0 || !str_contains($text, $expected)) {
    fwrite(STDERR, "GtkWidget count mismatch (exit {$code}):\n  got:      " . trim($text) . "\n  expected: {$expected}\n");
    exit(1);
}
if (!str_contains($text, 'property visible: accessor-covered')) {
    fwrite(STDERR, "GtkWidget property line missing:\n{$text}\n");
    exit(1);
}

[$text, $code] = runCount($scriptsDir, $gir, 'GtkGadget');
$expected = 'GtkGadget kind=class abstract=no constructors=1 methods=1 functions=0 expected=2 signals=0 properties=0';
if ($code !== 0 || trim($text) !== $expected) {
    fwrite(STDERR, "sibling-type control failed (exit {$code}):\n  got:      " . trim($text) . "\n  expected: {$expected}\n");
    exit(1);
}

[$text, $code] = runCount($scriptsDir, $gir, 'GtkOrientable');
$expected = 'GtkOrientable kind=interface abstract=no constructors=0 methods=2 functions=0 expected=2 signals=0 properties=0';
if ($code !== 0 || trim($text) !== $expected) {
    fwrite(STDERR, "interface control failed (exit {$code}):\n  got:      " . trim($text) . "\n  expected: {$expected}\n");
    exit(1);
}

[$text, $code] = runCount($scriptsDir, $gir, 'GtkAbsent');
if ($code === 0) {
    fwrite(STDERR, "absent-class control accepted GtkAbsent (exit 0):\n{$text}\n");
    exit(1);
}
if (!str_contains($text, 'not found')) {
    fwrite(STDERR, "absent-class control failed without a not-found diagnostic:\n{$text}\n");
    exit(1);
}

echo "GIR_PARSE_OK\n";
