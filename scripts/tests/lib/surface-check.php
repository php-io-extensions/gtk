<?php
/**
 * Shared end-to-end C-surface checks for one slice-zero class.
 *
 * Modes:
 *   (default)         bound+reserved == vendored gir count; every @zep has a .c body
 *   --composite       each phpgtk_* body has at most one native call
 *   --extra-sources   config.json lists the class's .c file
 *   --no-last-error   no dep-gtk process-global last-error in the class pair
 */

declare(strict_types=1);

function gtkSurfaceFail(string $msg): never
{
    fwrite(STDERR, $msg . "\n");
    exit(1);
}

/**
 * Property-only reservations cover gir <property> rows and must not inflate
 * bound+reserved (same rule as scripts/audit-gir.php).
 */
function gtkSurfaceCountReserved(string $header, string $classPath): int
{
    $count = 0;
    $quoted = preg_quote($classPath, '#');
    foreach (file($header, FILE_IGNORE_NEW_LINES) ?: [] as $line) {
        if (!preg_match('#/\*\s*@reserved\s+' . $quoted . '\s+(.*?)\s*\*/#', $line, $m)) {
            continue;
        }
        $text = $m[1];
        $propertyOnly = preg_match('/property\s+"/', $text) === 1
            && preg_match('/\b(?:gtk|gdk|gsk|pango|g)_[a-z0-9_]+/', $text) !== 1;
        if (!$propertyOnly) {
            $count++;
        }
    }

    return $count;
}

/**
 * @param array{
 *   classPath: string,
 *   headerRel: string,
 *   implRel: string,
 *   extraSource: string,
 *   girName: string,
 *   cType: string,
 *   symbolPrefix: string,
 *   tokenPrefix: string
 * } $spec
 */
function gtkSurfaceRun(array $spec, string $mode): void
{
    $root = dirname(__DIR__, 3);
    $hPath = $root . '/' . $spec['headerRel'];
    $cPath = $root . '/' . $spec['implRel'];
    $token = $spec['tokenPrefix'];

    if ($mode === '--extra-sources') {
        $config = json_decode((string) file_get_contents($root . '/config.json'), true);
        $listed = $config['extra-sources'] ?? [];
        if (!in_array($spec['extraSource'], $listed, true)) {
            gtkSurfaceFail("config.json extra-sources does not list {$spec['extraSource']}");
        }
        echo "{$token}_EXTRA_SOURCES_OK\n";
        exit(0);
    }

    if ($mode === '--no-last-error') {
        foreach ([$hPath, $cPath] as $path) {
            if (!is_file($path)) {
                gtkSurfaceFail("missing {$path}");
            }
            $src = (string) file_get_contents($path);
            if (preg_match('/php_gtk_last_error|PHPGTK_LAST_ERROR/', $src)) {
                gtkSurfaceFail("last-error side channel in {$path}");
            }
        }
        echo "{$token}_NO_LAST_ERROR_OK\n";
        exit(0);
    }

    $parity = file_get_contents($root . '/scripts/check-parity.php');
    if ($parity === false) {
        gtkSurfaceFail('cannot read check-parity.php');
    }
    $lib = preg_replace('/\/\/ ---- main ----.*$/s', '', $parity);
    $tmp = sys_get_temp_dir() . '/gtk-' . strtolower($token) . '-parity-lib.php';
    file_put_contents($tmp, $lib);
    require $tmp;

    if ($mode === '--composite') {
        if (!is_file($cPath)) {
            gtkSurfaceFail("missing {$cPath}");
        }
        $bodies = findFunctionBodies((string) file_get_contents($cPath));
        if ($bodies === []) {
            gtkSurfaceFail("no function bodies in {$spec['implRel']}");
        }
        foreach ($bodies as $symbol => $body) {
            if (!str_starts_with($symbol, $spec['symbolPrefix'])) {
                continue;
            }
            $calls = collectNativeCalls($body);
            if (count($calls) > 1) {
                gtkSurfaceFail("{$symbol} calls [" . implode(', ', $calls) . ']');
            }
        }
        echo "{$token}_COMPOSITE_OK\n";
        exit(0);
    }

    if (!is_file($hPath) || !is_file($cPath)) {
        gtkSurfaceFail("{$spec['headerRel']} / {$spec['implRel']} missing");
    }

    $classQuoted = preg_quote($spec['classPath'], '#');
    $h = (string) file_get_contents($hPath);
    $bound = preg_match_all('#/\*\s*@zep\s+' . $classQuoted . '\s+#', $h);
    $reserved = gtkSurfaceCountReserved($hPath, $spec['classPath']);

    $gir = $root . '/scripts/gir/' . $spec['girName'] . '.gir.gz';
    if (!is_file($gir)) {
        $gir = $root . '/scripts/gir/' . $spec['girName'] . '.gir';
    }
    $cmd = escapeshellarg(PHP_BINARY) . ' ' . escapeshellarg($root . '/scripts/audit-gir.php')
        . ' --count ' . escapeshellarg($gir) . ' ' . escapeshellarg($spec['cType']);
    exec($cmd, $out, $code);
    $line = implode("\n", $out);
    if ($code !== 0 || !preg_match('/expected=(\d+)/', $line, $m)) {
        gtkSurfaceFail("audit-gir --count failed: {$line}");
    }
    $expected = (int) $m[1];
    if (($bound + $reserved) !== $expected) {
        gtkSurfaceFail("bound={$bound} reserved={$reserved} total=" . ($bound + $reserved) . " gir expected={$expected}");
    }

    $symbols = [];
    $headerLines = file($hPath, FILE_IGNORE_NEW_LINES) ?: [];
    foreach ($headerLines as $i => $line) {
        if (!preg_match('#/\*\s*@zep(?:-construct)?\s+' . $classQuoted . '\s+#', $line)) {
            continue;
        }
        $proto = null;
        for ($j = $i + 1; $j < count($headerLines); $j++) {
            if (trim($headerLines[$j]) !== '') {
                $proto = $headerLines[$j];
                break;
            }
        }
        $prefixQuoted = preg_quote($spec['symbolPrefix'], '/');
        if (is_null($proto) || !preg_match('/\b(' . $prefixQuoted . '[a-z0-9_]*)\s*\(/', $proto, $pm)) {
            gtkSurfaceFail('zep without ' . $spec['symbolPrefix'] . '* prototype near line ' . ($i + 1));
        }
        $symbols[] = $pm[1];
    }

    $bodies = findFunctionBodies((string) file_get_contents($cPath));
    foreach ($symbols as $symbol) {
        if (!isset($bodies[$symbol])) {
            gtkSurfaceFail("{$symbol}: @zep has no function definition");
        }
    }

    $config = json_decode((string) file_get_contents($root . '/config.json'), true);
    if (!in_array($spec['extraSource'], $config['extra-sources'] ?? [], true)) {
        gtkSurfaceFail("config.json extra-sources does not list {$spec['extraSource']}");
    }

    echo "{$token}_SURFACE_OK\n";
}
