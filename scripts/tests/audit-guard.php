#!/usr/bin/env php
<?php
/*
 * Negative and positive controls for audit-gir.php.
 *
 *   pkg-drift       — under-bound GtkWidget; must FAIL, never print AUDIT_OK
 *   pkg-good        — exact Widget match + sanctioned-partial Gadget; AUDIT_OK
 *   pkg-prop        — uncovered property; must FAIL naming property "orphan"
 *   pkg-noconstruct — concrete class with no construction path; must FAIL
 *
 * Prints AUDIT_GUARD_OK only when every scenario behaves.
 */

declare(strict_types=1);

$scriptsDir = dirname(__DIR__);
$fixtures = __DIR__ . '/fixtures/audit';
$failures = [];

function runAudit(string $scriptsDir, string $root): array
{
    $cmd = sprintf(
        '%s %s %s 2>&1',
        escapeshellarg(PHP_BINARY),
        escapeshellarg($scriptsDir . '/audit-gir.php'),
        escapeshellarg($root)
    );
    exec($cmd, $output, $exitCode);

    return ['code' => $exitCode, 'text' => implode("\n", $output)];
}

function expectFail(string $label, array $result, string $needle, array &$failures): void
{
    if ($result['code'] === 0 || str_contains($result['text'], 'AUDIT_OK')) {
        $failures[] = "{$label}: expected non-zero without AUDIT_OK, got exit {$result['code']}:\n{$result['text']}";
        return;
    }
    if (!str_contains($result['text'], $needle)) {
        $failures[] = "{$label}: failed but diagnostic did not contain '{$needle}':\n{$result['text']}";
    }
}

$drift = runAudit($scriptsDir, $fixtures . '/pkg-drift');
if ($drift['code'] === 0) {
    $failures[] = "pkg-drift: audit accepted an under-bound class (exit 0):\n{$drift['text']}";
}
if (!preg_match('/Gtk\\\\GtkWidget\s+gir=4\s+bound=1\s+reserved=2\s+construct=0\s+signals=1\s+props=1\s+FAIL/', $drift['text'])) {
    $failures[] = "pkg-drift: did not report GtkWidget 4 vs 1+2 FAIL:\n{$drift['text']}";
}
if (str_contains($drift['text'], 'AUDIT_OK')) {
    $failures[] = "pkg-drift: printed AUDIT_OK despite failing:\n{$drift['text']}";
}

$good = runAudit($scriptsDir, $fixtures . '/pkg-good');
if ($good['code'] !== 0 || !str_contains($good['text'], 'AUDIT_OK')) {
    $failures[] = "pkg-good: expected AUDIT_OK, got exit {$good['code']}:\n{$good['text']}";
}
if (!preg_match('/Gtk\\\\GtkWidget\s+gir=4\s+bound=2\s+reserved=2\s+.*\bOK\b/', $good['text'])) {
    $failures[] = "pkg-good: GtkWidget line is not OK:\n{$good['text']}";
}
if (!preg_match('/Gtk\\\\GtkGadget\s+.*PARTIAL/', $good['text'])) {
    $failures[] = "pkg-good: GtkGadget was not reported PARTIAL:\n{$good['text']}";
}

expectFail(
    'pkg-prop',
    runAudit($scriptsDir, $fixtures . '/pkg-prop'),
    'property "orphan"',
    $failures
);
expectFail(
    'pkg-noconstruct',
    runAudit($scriptsDir, $fixtures . '/pkg-noconstruct'),
    'no construction path',
    $failures
);

if ($failures !== []) {
    foreach ($failures as $f) {
        fwrite(STDERR, "audit-guard: {$f}\n\n");
    }
    exit(1);
}

echo "AUDIT_GUARD_OK\n";
