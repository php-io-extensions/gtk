#!/usr/bin/env php
<?php
/**
 * Slice-zero src-pair verifier. Observes the artifacts, exits non-zero
 * on any failure, and prints a success-only token after every assertion.
 *
 *   php scripts/verify-slice-zero-src.php --files
 *   php scripts/verify-slice-zero-src.php --audit
 *   php scripts/verify-slice-zero-src.php --bodies
 */
declare(strict_types=1);

const SLICE_ZERO_PAIRS = [
    'src/gtk-widget.h' => 'src/gtk-widget.c',
    'src/gtk-window.h' => 'src/gtk-window.c',
    'src/gtk-button.h' => 'src/gtk-button.c',
    'src/gtk-box.h' => 'src/gtk-box.c',
    'src/gtk-orientable.h' => 'src/gtk-orientable.c',
    'src/gtk-application.h' => 'src/gtk-application.c',
    'src/gio-gapplication.h' => 'src/gio-gapplication.c',
];

const SLICE_ZERO_CLASSES = [
    'Gtk\\GtkWidget',
    'Gtk\\GtkWindow',
    'Gtk\\GtkButton',
    'Gtk\\GtkBox',
    'Gtk\\GtkOrientable',
    'Gtk\\GtkApplication',
    'Gio\\GApplication',
];

const NATIVE_WHITELIST = [
    'g_free',
    'g_strfreev',
    'g_list_free',
    'g_list_free_full',
    'g_slist_free',
    'g_slist_free_full',
    'g_object_unref',
    'g_error_free',
];

$root = dirname(__DIR__);
$mode = $argv[1] ?? '';

function fail(string $msg): never
{
    fwrite(STDERR, "verify-slice-zero-src: {$msg}\n");
    exit(1);
}

function blankCommentsAndStrings(string $src): string
{
    $len = strlen($src);
    $out = $src;
    $i = 0;
    while ($i < $len) {
        $c = $src[$i];
        $n = $i + 1 < $len ? $src[$i + 1] : '';
        if ($c === '/' && $n === '/') {
            $i += 2;
            while ($i < $len && $src[$i] !== "\n") {
                $out[$i] = ' ';
                $i++;
            }
            continue;
        }
        if ($c === '/' && $n === '*') {
            $out[$i] = ' ';
            $out[$i + 1] = ' ';
            $i += 2;
            while ($i < $len && !($src[$i] === '*' && $i + 1 < $len && $src[$i + 1] === '/')) {
                if ($src[$i] !== "\n") {
                    $out[$i] = ' ';
                }
                $i++;
            }
            if ($i < $len) {
                $out[$i] = ' ';
                if ($i + 1 < $len) {
                    $out[$i + 1] = ' ';
                }
                $i += 2;
            }
            continue;
        }
        if ($c === '"' || $c === "'") {
            $quote = $c;
            $out[$i] = ' ';
            $i++;
            while ($i < $len && $src[$i] !== $quote) {
                if ($src[$i] === '\\' && $i + 1 < $len) {
                    $out[$i] = ' ';
                    $out[$i + 1] = ' ';
                    $i += 2;
                    continue;
                }
                if ($src[$i] !== "\n") {
                    $out[$i] = ' ';
                }
                $i++;
            }
            if ($i < $len) {
                $out[$i] = ' ';
                $i++;
            }
            continue;
        }
        $i++;
    }

    return $out;
}

function matchingClose(string $s, int $open, string $openCh = '(', string $closeCh = ')'): int
{
    $len = strlen($s);
    $depth = 0;
    for ($i = $open; $i < $len; $i++) {
        if ($s[$i] === $openCh) {
            $depth++;
        } elseif ($s[$i] === $closeCh) {
            $depth--;
            if ($depth === 0) {
                return $i;
            }
        }
    }

    return $len - 1;
}

/** @return array<string, string> */
function findFunctionBodies(string $src): array
{
    $blank = blankCommentsAndStrings($src);
    $len = strlen($blank);
    $out = [];
    $offset = 0;
    while (($pos = strpos($blank, 'phpgtk_', $offset)) !== false) {
        if ($pos > 0 && (ctype_alnum($blank[$pos - 1]) || $blank[$pos - 1] === '_')) {
            $offset = $pos + 7;
            continue;
        }
        $before = $pos;
        while ($before > 0 && ctype_space($blank[$before - 1])) {
            $before--;
        }
        $typeEnd = $before;
        $typeStart = $typeEnd;
        while ($typeStart > 0 && (ctype_alnum($blank[$typeStart - 1]) || $blank[$typeStart - 1] === '_')) {
            $typeStart--;
        }
        $returnType = substr($blank, $typeStart, $typeEnd - $typeStart);
        if (!in_array($returnType, ['zend_long', 'double', 'void'], true)) {
            $offset = $pos + 7;
            continue;
        }
        $i = $pos;
        while ($i < $len && (ctype_alnum($blank[$i]) || $blank[$i] === '_')) {
            $i++;
        }
        $symbol = substr($blank, $pos, $i - $pos);
        while ($i < $len && ctype_space($blank[$i])) {
            $i++;
        }
        if ($i >= $len || $blank[$i] !== '(') {
            $offset = $pos + 7;
            continue;
        }
        $i = matchingClose($blank, $i, '(', ')') + 1;
        while ($i < $len && ctype_space($blank[$i])) {
            $i++;
        }
        if ($i >= $len || $blank[$i] !== '{') {
            $offset = $pos + 7;
            continue;
        }
        $close = matchingClose($blank, $i, '{', '}');
        $out[$symbol] = substr($src, $i, $close - $i + 1);
        $offset = $close + 1;
    }

    return $out;
}

function collectNativeCalls(string $body): array
{
    $blank = blankCommentsAndStrings($body);
    $calls = [];
    if (preg_match_all('/\b((?:gtk|gdk|gsk|pango|g)_[a-z0-9_]+)\s*\(/', $blank, $m)) {
        foreach ($m[1] as $name) {
            if (!in_array($name, NATIVE_WHITELIST, true)) {
                $calls[] = $name;
            }
        }
    }

    return $calls;
}

function verifyFiles(string $root): void
{
    foreach (SLICE_ZERO_PAIRS as $h => $c) {
        $hp = $root . '/' . $h;
        $cp = $root . '/' . $c;
        if (!is_file($hp) || filesize($hp) < 64) {
            fail("{$h} is missing or empty");
        }
        if (!is_file($cp) || filesize($cp) < 64) {
            fail("{$c} is missing or empty");
        }
        $src = (string) file_get_contents($hp);
        if (!str_contains($src, '/*@zep ') && !str_contains($src, '/*@reserved ')) {
            fail("{$h} has no @zep/@reserved annotations");
        }
    }
    echo "SLICE_ZERO_FILES_OK\n";
}

function verifyAudit(string $root): void
{
    $audit = $root . '/scripts/audit-gir.php';
    if (!is_file($audit)) {
        fail('scripts/audit-gir.php is missing');
    }
    $cmd = escapeshellarg(PHP_BINARY) . ' ' . escapeshellarg($audit) . ' ' . escapeshellarg($root);
    exec($cmd, $out, $status);
    $text = implode("\n", $out);
    if ($status !== 0) {
        fwrite(STDERR, $text . "\n");
        fail('audit-gir exited ' . $status);
    }
    if (!str_contains($text, 'AUDIT_OK')) {
        fwrite(STDERR, $text . "\n");
        fail('audit-gir did not print AUDIT_OK');
    }
    foreach (SLICE_ZERO_CLASSES as $class) {
        $found = false;
        foreach ($out as $line) {
            if (!str_starts_with($line, $class)) {
                continue;
            }
            $found = true;
            if (str_contains($line, 'FAIL')) {
                fail("{$class} audit line is FAIL: {$line}");
            }
            if (!preg_match('/\bOK\b/', $line)) {
                fail("{$class} audit line is not OK: {$line}");
            }
        }
        if (!$found) {
            fail("{$class} was not audited");
        }
    }
    echo "SLICE_ZERO_AUDIT_OK\n";
}

function verifyBodies(string $root): void
{
    $symbols = [];
    foreach (array_keys(SLICE_ZERO_PAIRS) as $h) {
        $lines = file($root . '/' . $h, FILE_IGNORE_NEW_LINES) ?: [];
        $total = count($lines);
        for ($i = 0; $i < $total; $i++) {
            if (!preg_match('#/\*\s*@zep(?:-construct)?\s+([A-Za-z0-9_\\\\]+)\s+(\w+)\s*\(([^)]*)\)\s*->\s*(\w+)\s*\*/#', $lines[$i], $m)) {
                continue;
            }
            $proto = null;
            for ($j = $i + 1; $j < $total; $j++) {
                if (trim($lines[$j]) !== '') {
                    $proto = $lines[$j];
                    break;
                }
            }
            if (is_null($proto) || !preg_match('/\b(phpgtk_[a-z0-9_]+)\s*\(/', $proto, $pm)) {
                fail("{$h}: @{$m[2]} has no C prototype");
            }
            $symbols[$pm[1]] = $h;
        }
    }
    if ($symbols === []) {
        fail('no @zep symbols in slice-zero headers');
    }

    $bodies = [];
    foreach (SLICE_ZERO_PAIRS as $c) {
        $src = (string) file_get_contents($root . '/' . $c);
        foreach (findFunctionBodies($src) as $symbol => $body) {
            $bodies[$symbol] = ['body' => $body, 'file' => $c];
        }
    }

    foreach ($symbols as $symbol => $header) {
        if (!isset($bodies[$symbol])) {
            fail("{$symbol} (from {$header}) has no C body");
        }
        $calls = collectNativeCalls($bodies[$symbol]['body']);
        if (count($calls) > 1) {
            fail("{$bodies[$symbol]['file']}: {$symbol} calls [" . implode(', ', $calls) . ']');
        }
    }

    echo 'slice-zero symbols=' . count($symbols) . " bodies=" . count($bodies) . "\n";
    echo "SLICE_ZERO_BODIES_OK\n";
}

if ($mode === '--files') {
    verifyFiles($root);
    exit(0);
}
if ($mode === '--audit') {
    verifyAudit($root);
    exit(0);
}
if ($mode === '--bodies') {
    verifyBodies($root);
    exit(0);
}

fail('usage: verify-slice-zero-src.php --files|--audit|--bodies');
