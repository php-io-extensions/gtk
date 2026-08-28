#!/usr/bin/env php
<?php
/**
 * Wave A inventory verifier. Re-measures gir constructor+method+function
 * counts from the vendored XML and asserts each listed class is bound or
 * reserved to that count, listed in extra-sources, and covered by a
 * surface test registered in run-all.php. Prints a success-only token
 * after every assertion. Does not copy plan numbers into the token.
 */

declare(strict_types=1);

const WAVES = [
    'a1' => [
        ['classPath' => 'Gtk\\GtkAdjustment', 'cType' => 'GtkAdjustment', 'headerRel' => 'src/gtk-adjustment.h', 'implRel' => 'src/gtk-adjustment.c', 'surface' => 'gtk-adjustment-surface.php', 'token' => 'GTKADJUSTMENT'],
        ['classPath' => 'Gtk\\GtkEditable', 'cType' => 'GtkEditable', 'headerRel' => 'src/gtk-editable.h', 'implRel' => 'src/gtk-editable.c', 'surface' => 'gtk-editable-surface.php', 'token' => 'GTKEDITABLE'],
        ['classPath' => 'Gtk\\GtkEntryBuffer', 'cType' => 'GtkEntryBuffer', 'headerRel' => 'src/gtk-entry-buffer.h', 'implRel' => 'src/gtk-entry-buffer.c', 'surface' => 'gtk-entry-buffer-surface.php', 'token' => 'GTKENTRYBUFFER'],
    ],
    'a2' => [
        ['classPath' => 'Gtk\\GtkEntry', 'cType' => 'GtkEntry', 'headerRel' => 'src/gtk-entry.h', 'implRel' => 'src/gtk-entry.c', 'surface' => 'gtk-entry-surface.php', 'token' => 'GTKENTRY'],
        ['classPath' => 'Gtk\\GtkText', 'cType' => 'GtkText', 'headerRel' => 'src/gtk-text.h', 'implRel' => 'src/gtk-text.c', 'surface' => 'gtk-text-surface.php', 'token' => 'GTKTEXT'],
    ],
    'a3' => [
        ['classPath' => 'Gtk\\GtkPasswordEntry', 'cType' => 'GtkPasswordEntry', 'headerRel' => 'src/gtk-password-entry.h', 'implRel' => 'src/gtk-password-entry.c', 'surface' => 'gtk-password-entry-surface.php', 'token' => 'GTKPASSWORDENTRY'],
        ['classPath' => 'Gtk\\GtkSearchEntry', 'cType' => 'GtkSearchEntry', 'headerRel' => 'src/gtk-search-entry.h', 'implRel' => 'src/gtk-search-entry.c', 'surface' => 'gtk-search-entry-surface.php', 'token' => 'GTKSEARCHENTRY'],
        ['classPath' => 'Gtk\\GtkToggleButton', 'cType' => 'GtkToggleButton', 'headerRel' => 'src/gtk-toggle-button.h', 'implRel' => 'src/gtk-toggle-button.c', 'surface' => 'gtk-toggle-button-surface.php', 'token' => 'GTKTOGGLEBUTTON'],
        ['classPath' => 'Gtk\\GtkCheckButton', 'cType' => 'GtkCheckButton', 'headerRel' => 'src/gtk-check-button.h', 'implRel' => 'src/gtk-check-button.c', 'surface' => 'gtk-check-button-surface.php', 'token' => 'GTKCHECKBUTTON'],
        ['classPath' => 'Gtk\\GtkSwitch', 'cType' => 'GtkSwitch', 'headerRel' => 'src/gtk-switch.h', 'implRel' => 'src/gtk-switch.c', 'surface' => 'gtk-switch-surface.php', 'token' => 'GTKSWITCH'],
    ],
    'a4' => [
        ['classPath' => 'Gtk\\GtkRange', 'cType' => 'GtkRange', 'headerRel' => 'src/gtk-range.h', 'implRel' => 'src/gtk-range.c', 'surface' => 'gtk-range-surface.php', 'token' => 'GTKRANGE'],
        ['classPath' => 'Gtk\\GtkScale', 'cType' => 'GtkScale', 'headerRel' => 'src/gtk-scale.h', 'implRel' => 'src/gtk-scale.c', 'surface' => 'gtk-scale-surface.php', 'token' => 'GTKSCALE'],
        ['classPath' => 'Gtk\\GtkScrollbar', 'cType' => 'GtkScrollbar', 'headerRel' => 'src/gtk-scrollbar.h', 'implRel' => 'src/gtk-scrollbar.c', 'surface' => 'gtk-scrollbar-surface.php', 'token' => 'GTKSCROLLBAR'],
        ['classPath' => 'Gtk\\GtkSpinButton', 'cType' => 'GtkSpinButton', 'headerRel' => 'src/gtk-spin-button.h', 'implRel' => 'src/gtk-spin-button.c', 'surface' => 'gtk-spin-button-surface.php', 'token' => 'GTKSPINBUTTON'],
    ],
    'a5' => [
        ['classPath' => 'Gtk\\GtkLabel', 'cType' => 'GtkLabel', 'headerRel' => 'src/gtk-label.h', 'implRel' => 'src/gtk-label.c', 'surface' => 'gtk-label-surface.php', 'token' => 'GTKLABEL'],
        ['classPath' => 'Gtk\\GtkImage', 'cType' => 'GtkImage', 'headerRel' => 'src/gtk-image.h', 'implRel' => 'src/gtk-image.c', 'surface' => 'gtk-image-surface.php', 'token' => 'GTKIMAGE'],
        ['classPath' => 'Gtk\\GtkPicture', 'cType' => 'GtkPicture', 'headerRel' => 'src/gtk-picture.h', 'implRel' => 'src/gtk-picture.c', 'surface' => 'gtk-picture-surface.php', 'token' => 'GTKPICTURE'],
    ],
    'a6' => [
        ['classPath' => 'Gtk\\GtkSpinner', 'cType' => 'GtkSpinner', 'headerRel' => 'src/gtk-spinner.h', 'implRel' => 'src/gtk-spinner.c', 'surface' => 'gtk-spinner-surface.php', 'token' => 'GTKSPINNER'],
        ['classPath' => 'Gtk\\GtkProgressBar', 'cType' => 'GtkProgressBar', 'headerRel' => 'src/gtk-progress-bar.h', 'implRel' => 'src/gtk-progress-bar.c', 'surface' => 'gtk-progress-bar-surface.php', 'token' => 'GTKPROGRESSBAR'],
        ['classPath' => 'Gtk\\GtkLevelBar', 'cType' => 'GtkLevelBar', 'headerRel' => 'src/gtk-level-bar.h', 'implRel' => 'src/gtk-level-bar.c', 'surface' => 'gtk-level-bar-surface.php', 'token' => 'GTKLEVELBAR'],
        ['classPath' => 'Gtk\\GtkSeparator', 'cType' => 'GtkSeparator', 'headerRel' => 'src/gtk-separator.h', 'implRel' => 'src/gtk-separator.c', 'surface' => 'gtk-separator-surface.php', 'token' => 'GTKSEPARATOR'],
    ],
    'a7' => [
        ['classPath' => 'Gtk\\GtkFrame', 'cType' => 'GtkFrame', 'headerRel' => 'src/gtk-frame.h', 'implRel' => 'src/gtk-frame.c', 'surface' => 'gtk-frame-surface.php', 'token' => 'GTKFRAME'],
        ['classPath' => 'Gtk\\GtkAspectFrame', 'cType' => 'GtkAspectFrame', 'headerRel' => 'src/gtk-aspect-frame.h', 'implRel' => 'src/gtk-aspect-frame.c', 'surface' => 'gtk-aspect-frame-surface.php', 'token' => 'GTKASPECTFRAME'],
        ['classPath' => 'Gtk\\GtkCenterBox', 'cType' => 'GtkCenterBox', 'headerRel' => 'src/gtk-center-box.h', 'implRel' => 'src/gtk-center-box.c', 'surface' => 'gtk-center-box-surface.php', 'token' => 'GTKCENTERBOX'],
        ['classPath' => 'Gtk\\GtkGrid', 'cType' => 'GtkGrid', 'headerRel' => 'src/gtk-grid.h', 'implRel' => 'src/gtk-grid.c', 'surface' => 'gtk-grid-surface.php', 'token' => 'GTKGRID'],
        ['classPath' => 'Gtk\\GtkFixed', 'cType' => 'GtkFixed', 'headerRel' => 'src/gtk-fixed.h', 'implRel' => 'src/gtk-fixed.c', 'surface' => 'gtk-fixed-surface.php', 'token' => 'GTKFIXED'],
        ['classPath' => 'Gtk\\GtkOverlay', 'cType' => 'GtkOverlay', 'headerRel' => 'src/gtk-overlay.h', 'implRel' => 'src/gtk-overlay.c', 'surface' => 'gtk-overlay-surface.php', 'token' => 'GTKOVERLAY'],
    ],
    'a8' => [
        ['classPath' => 'Gtk\\GtkScrollable', 'cType' => 'GtkScrollable', 'headerRel' => 'src/gtk-scrollable.h', 'implRel' => 'src/gtk-scrollable.c', 'surface' => 'gtk-scrollable-surface.php', 'token' => 'GTKSCROLLABLE'],
        ['classPath' => 'Gtk\\GtkViewport', 'cType' => 'GtkViewport', 'headerRel' => 'src/gtk-viewport.h', 'implRel' => 'src/gtk-viewport.c', 'surface' => 'gtk-viewport-surface.php', 'token' => 'GTKVIEWPORT'],
        ['classPath' => 'Gtk\\GtkScrolledWindow', 'cType' => 'GtkScrolledWindow', 'headerRel' => 'src/gtk-scrolled-window.h', 'implRel' => 'src/gtk-scrolled-window.c', 'surface' => 'gtk-scrolled-window-surface.php', 'token' => 'GTKSCROLLEDWINDOW'],
        ['classPath' => 'Gtk\\GtkExpander', 'cType' => 'GtkExpander', 'headerRel' => 'src/gtk-expander.h', 'implRel' => 'src/gtk-expander.c', 'surface' => 'gtk-expander-surface.php', 'token' => 'GTKEXPANDER'],
        ['classPath' => 'Gtk\\GtkRevealer', 'cType' => 'GtkRevealer', 'headerRel' => 'src/gtk-revealer.h', 'implRel' => 'src/gtk-revealer.c', 'surface' => 'gtk-revealer-surface.php', 'token' => 'GTKREVEALER'],
    ],
];

$root = dirname(__DIR__);
$mode = $argv[1] ?? '';

function fail(string $msg): never
{
    fwrite(STDERR, "verify-wave-a: {$msg}\n");
    exit(1);
}

function countReserved(string $header, string $classPath): int
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

function girExpected(string $root, string $cType): int
{
    $gir = $root . '/scripts/gir/Gtk-4.0.gir.gz';
    $cmd = escapeshellarg(PHP_BINARY) . ' ' . escapeshellarg($root . '/scripts/audit-gir.php')
        . ' --count ' . escapeshellarg($gir) . ' ' . escapeshellarg($cType);
    $out = [];
    exec($cmd, $out, $code);
    $line = implode("\n", $out);
    if ($code !== 0 || !preg_match('/expected=(\d+)/', $line, $m)) {
        fail("audit-gir --count {$cType} failed: {$line}");
    }

    return (int) $m[1];
}

function verifyWave(string $root, string $wave): void
{
    $specs = WAVES[$wave] ?? null;
    if (is_null($specs)) {
        fail("unknown wave '{$wave}'");
    }

    $config = json_decode((string) file_get_contents($root . '/config.json'), true);
    $listed = $config['extra-sources'] ?? [];
    $runAll = (string) file_get_contents($root . '/scripts/tests/run-all.php');
    $girTotal = 0;
    $boundTotal = 0;
    $reservedTotal = 0;

    foreach ($specs as $spec) {
        $hPath = $root . '/' . $spec['headerRel'];
        $cPath = $root . '/' . $spec['implRel'];
        if (!is_file($hPath) || filesize($hPath) < 64) {
            fail("{$spec['headerRel']} is missing or empty");
        }
        if (!is_file($cPath) || filesize($cPath) < 64) {
            fail("{$spec['implRel']} is missing or empty");
        }
        if (!in_array($spec['implRel'], $listed, true)) {
            fail("config.json extra-sources does not list {$spec['implRel']}");
        }

        $h = (string) file_get_contents($hPath);
        $classQuoted = preg_quote($spec['classPath'], '#');
        $bound = preg_match_all('#/\*\s*@zep\s+' . $classQuoted . '\s+#', $h);
        $reserved = countReserved($hPath, $spec['classPath']);
        $expected = girExpected($root, $spec['cType']);
        $girTotal += $expected;
        $boundTotal += $bound;
        $reservedTotal += $reserved;
        if (($bound + $reserved) !== $expected) {
            fail("{$spec['classPath']} bound={$bound} reserved={$reserved} total=" . ($bound + $reserved) . " gir expected={$expected}");
        }

        $surface = $root . '/scripts/tests/' . $spec['surface'];
        if (!is_file($surface)) {
            fail("missing surface test {$spec['surface']}");
        }
        if (!str_contains($runAll, $spec['surface'])) {
            fail("run-all.php does not register {$spec['surface']}");
        }
        if (!str_contains($runAll, $spec['token'])) {
            fail("run-all.php does not mention token {$spec['token']}");
        }

        echo "{$spec['classPath']} gir={$expected} bound={$bound} reserved={$reserved} OK\n";
    }

    echo "wave={$wave} classes=" . count($specs) . " gir_members={$girTotal} bound={$boundTotal} reserved={$reservedTotal}\n";
    echo 'WAVE_' . strtoupper($wave) . "_OK\n";
}

function verifyOkf(string $root): void
{
    $rules = (string) file_get_contents($root . '/.okf/binding-rules.md');
    $log = (string) file_get_contents($root . '/.okf/log.md');
    $missing = [];
    foreach (WAVES as $specs) {
        foreach ($specs as $spec) {
            $short = preg_replace('/^Gtk\\\\/', '', $spec['classPath']);
            if (!str_contains($rules, $short) && !str_contains($log, $short)) {
                $missing[] = $short;
            }
        }
    }
    if ($missing !== []) {
        fail('OKF does not mention: ' . implode(', ', $missing));
    }
    if (!str_contains($log, 'Wave A') && !str_contains($log, 'wave A') && !str_contains($log, 'wave-a')) {
        fail('.okf/log.md has no Wave A entry');
    }
    echo "WAVE_A_OKF_OK\n";
}

if ($mode === '--okf') {
    verifyOkf($root);
    exit(0);
}

if ($mode === '--wave') {
    $wave = strtolower((string) ($argv[2] ?? ''));
    if ($wave === 'all') {
        foreach (array_keys(WAVES) as $w) {
            verifyWave($root, $w);
        }
        echo "WAVE_A123_OK\n";
        exit(0);
    }
    verifyWave($root, $wave);
    exit(0);
}

fail('usage: verify-wave-a.php --wave a1|a2|a3|a4|a5|a6|a7|a8|all | --okf');
