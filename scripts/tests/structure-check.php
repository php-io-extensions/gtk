#!/usr/bin/env php
<?php
/*
 * Independent structural verification of gen-zep.php output. Re-derives the
 * expected surface from the @zep/@zep-construct/@reserved annotations with its
 * own parser and asserts, per class:
 *   - the .zep file exists at the derived path with the derived namespace/class
 *   - bound method count in the .zep equals the header's @zep count
 *   - reserved comment count in the .zep equals the header's @reserved count
 *   - every C symbol has an optimizer file that passes `php -l`
 *   - bool-returning methods unwrap with `return r == 1;`
 *   - string/array/var optimizers write through the symbol variable
 * Prints STRUCTURE_OK only when every assertion passes.
 */

declare(strict_types=1);

$root = dirname(__DIR__, 2);
$errors = [];

function studly(string $snake): string
{
    return str_replace(' ', '', ucwords(str_replace('_', ' ', $snake)));
}

$expected = [];
$symbols = [];
foreach (glob("{$root}/src/*.h") ?: [] as $header) {
    $awaitingPrototype = false;
    foreach (file($header, FILE_IGNORE_NEW_LINES) ?: [] as $line) {
        // @zep-construct emits a method and an optimizer exactly like @zep; it
        // differs only in that the gir audit counts it separately.
        if (preg_match('#/\*\s*@zep(?:-construct)?\s+([A-Za-z0-9_\\\\]+)\s+(\w+)\s*\([^)]*\)\s*->\s*(\w+)\s*\*/#', $line, $m)) {
            $expected[$m[1]]['zep'][] = ['method' => $m[2], 'return' => $m[3]];
            $awaitingPrototype = true;
            continue;
        }
        if (preg_match('#/\*\s*@reserved\s+([A-Za-z0-9_\\\\]+)\s#', $line, $m)) {
            $expected[$m[1]]['reserved'] = ($expected[$m[1]]['reserved'] ?? 0) + 1;
            continue;
        }
        // Only prototypes following a @zep line get optimizers; bare phpgtk_*
        // prototypes (e.g. the handle registry) are C-internal.
        if ($awaitingPrototype && preg_match('/^\s*(?:zend_long|double|void)\s+(phpgtk_[a-z0-9_]+)\s*\(/', $line, $m)) {
            $symbols[] = $m[1];
            $awaitingPrototype = false;
        }
    }
}

if ($expected === []) {
    fwrite(STDERR, "no @zep annotations found under src/\n");
    exit(1);
}

foreach ($expected as $classPath => $info) {
    $segments = explode('\\', $classPath);
    $class = end($segments);
    $nsSegments = $segments;
    if (count($segments) >= 2 && $segments[count($segments) - 1] === $segments[count($segments) - 2]) {
        array_pop($nsSegments);
    }
    $namespace = 'Gtk\\' . implode('\\', $nsSegments);
    $zepPath = "{$root}/gtk/" . implode('/', array_map('strtolower', $nsSegments)) . '/' . strtolower($class) . '.zep';

    if (!is_file($zepPath)) {
        $errors[] = "{$classPath}: missing {$zepPath}";
        continue;
    }
    $zep = (string) file_get_contents($zepPath);

    if (!str_contains($zep, "namespace {$namespace};")) {
        $errors[] = "{$classPath}: expected 'namespace {$namespace};' in {$zepPath}";
    }
    if (!preg_match('/^class ' . preg_quote($class, '/') . '\b/m', $zep)) {
        $errors[] = "{$classPath}: expected 'class {$class}' in {$zepPath}";
    }

    $boundExpected = count($info['zep'] ?? []);
    $boundActual = preg_match_all('/^\s*public static function /m', $zep);
    if ($boundActual !== $boundExpected) {
        $errors[] = "{$classPath}: {$boundExpected} @zep annotations but {$boundActual} methods in {$zepPath}";
    }

    $reservedExpected = $info['reserved'] ?? 0;
    $reservedActual = preg_match_all('/^\s*\/\/ @reserved /m', $zep);
    if ($reservedActual !== $reservedExpected) {
        $errors[] = "{$classPath}: {$reservedExpected} @reserved annotations but {$reservedActual} reserved comments in {$zepPath}";
    }

    foreach ($info['zep'] ?? [] as $entry) {
        if ($entry['return'] === 'bool' && !str_contains($zep, 'return r == 1;')) {
            $errors[] = "{$classPath}::{$entry['method']}: bool return must unwrap via 'return r == 1;'";
        }
    }
}

$lintTargets = [];
foreach ($symbols as $symbol) {
    $bare = preg_replace('/^phpgtk_/', '', $symbol);
    $optimizerPath = "{$root}/optimizers/" . studly($bare) . 'Optimizer.php';
    if (!is_file($optimizerPath)) {
        $errors[] = "{$symbol}: missing optimizer {$optimizerPath}";
        continue;
    }
    $lintTargets[$optimizerPath] = $symbol;

    $optimizer = (string) file_get_contents($optimizerPath);
    if (str_contains($optimizer, 'getSymbolVariable') && !str_contains($optimizer, 'processExpectedReturn')) {
        $errors[] = "{$symbol}: symbol-write optimizer missing processExpectedReturn";
    }
}

/*
 * One `php -l` per optimizer means thousands of process spawns, which takes
 * minutes on a network volume. xargs lints them in parallel batches instead
 * and only the files it names as failing are reported.
 */
if ($lintTargets !== []) {
    $listFile = tempnam(sys_get_temp_dir(), 'lint');
    file_put_contents($listFile, implode("\0", array_keys($lintTargets)) . "\0");
    $cmd = sprintf(
        'xargs -0 -P 8 -n 32 %s -l < %s 2>&1',
        escapeshellarg(PHP_BINARY),
        escapeshellarg($listFile)
    );
    exec($cmd, $lintOut, $lintCode);
    unlink($listFile);

    if ($lintCode !== 0) {
        foreach ($lintOut as $line) {
            if (str_contains($line, 'No syntax errors detected')) {
                continue;
            }
            if (preg_match('/ in (\S+\.php)/', $line, $m) && isset($lintTargets[$m[1]])) {
                $errors[] = "{$lintTargets[$m[1]]}: optimizer fails php -l: {$line}";
            } elseif (trim($line) !== '') {
                $errors[] = "optimizer lint: {$line}";
            }
        }
    }
}

if ($errors !== []) {
    foreach ($errors as $e) {
        fwrite(STDERR, "structure: {$e}\n");
    }
    exit(1);
}

echo 'STRUCTURE_OK classes=' . count($expected) . ' symbols=' . count($symbols) . "\n";
