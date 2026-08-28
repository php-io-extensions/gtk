#!/usr/bin/env php
<?php
/*
 * Negative control for gen-zep.php: run the generator against a fixture whose
 * @zep annotation disagrees with its C prototype and assert that it fails.
 * Prints DRIFT_GUARD_OK only when the generator exits non-zero with a
 * drift-describing error and generated nothing.
 */

declare(strict_types=1);

$scriptsDir = dirname(__DIR__);
$fixtureRoot = __DIR__ . '/fixtures/drift';

$cmd = sprintf(
    '%s %s %s 2>&1',
    escapeshellarg(PHP_BINARY),
    escapeshellarg($scriptsDir . '/gen-zep.php'),
    escapeshellarg($fixtureRoot)
);

exec($cmd, $output, $exitCode);
$text = implode("\n", $output);

if ($exitCode === 0) {
    fwrite(STDERR, "generator accepted a drifted header (exit 0):\n{$text}\n");
    exit(1);
}
if (!str_contains($text, 'parameter')) {
    fwrite(STDERR, "generator failed but not with a drift diagnostic:\n{$text}\n");
    exit(1);
}
if (str_contains($text, 'GEN_OK')) {
    fwrite(STDERR, "generator printed GEN_OK despite failing:\n{$text}\n");
    exit(1);
}
foreach (['gtk', 'optimizers'] as $dir) {
    $stray = glob("{$fixtureRoot}/{$dir}/*") ?: [];
    if ($stray !== []) {
        fwrite(STDERR, 'generator wrote output despite drift: ' . implode(', ', $stray) . "\n");
        exit(1);
    }
}

echo "DRIFT_GUARD_OK\n";
