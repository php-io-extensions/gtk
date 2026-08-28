#!/usr/bin/env php
<?php
/*
 * Run every Mac-side negative control and per-class surface check.
 * Generates .zep/optimizers first when the class tree is missing, because
 * structure-check and the real-package half of parity-guard read that tree.
 * Prints TESTS_OK only when every child prints its success token.
 */

declare(strict_types=1);

$root = dirname(__DIR__, 2);
$tests = __DIR__;
$failures = [];

function runTest(string $script, array $args, string $token): void
{
    global $failures;
    $cmd = array_merge([PHP_BINARY, $script], $args);
    $line = implode(' ', array_map('escapeshellarg', $cmd)) . ' 2>&1';
    $output = [];
    exec($line, $output, $code);
    $text = implode("\n", $output);
    $name = basename($script) . ($args === [] ? '' : ' ' . implode(' ', $args));
    if ($code !== 0 || !str_contains($text, $token)) {
        $failures[] = "{$name}: expected {$token} (exit {$code})\n{$text}";
        fwrite(STDERR, "FAIL {$name}\n{$text}\n");
        return;
    }
    echo "PASS {$name} → {$token}\n";
}

$buttonZep = $root . '/gtk/gtk/gtkbutton/gtkbutton.zep';
if (!is_file($buttonZep)) {
    echo "run-all: generating .zep/optimizers (missing {$buttonZep})\n";
    $gen = [];
    exec(
        sprintf('%s %s 2>&1', escapeshellarg(PHP_BINARY), escapeshellarg($root . '/scripts/gen-zep.php')),
        $gen,
        $genCode
    );
    $genText = implode("\n", $gen);
    if ($genCode !== 0 || !str_contains($genText, 'GEN_OK')) {
        fwrite(STDERR, "run-all: gen-zep failed:\n{$genText}\n");
        exit(1);
    }
}

$guards = [
    ['drift-guard.php', [], 'DRIFT_GUARD_OK'],
    ['parity-guard.php', [], 'PARITY_GUARD_OK'],
    ['audit-parse.php', [], 'GIR_PARSE_OK'],
    ['audit-guard.php', [], 'AUDIT_GUARD_OK'],
    ['prepare-ext-guard.php', [], 'PREPARE_EXT_GUARD_OK'],
    ['structure-check.php', [], 'STRUCTURE_OK'],
];

foreach ($guards as [$file, $args, $token]) {
    runTest("{$tests}/{$file}", $args, $token);
}

$surfaces = [
    ['gtk-widget-surface.php', 'GTKWIDGET'],
    ['gtk-window-surface.php', 'GTKWINDOW'],
    ['gtk-button-surface.php', 'GTKBUTTON'],
    ['gtk-box-surface.php', 'GTKBOX'],
    ['gtk-orientable-surface.php', 'GTKORIENTABLE'],
    ['gtk-application-surface.php', 'GTKAPPLICATION'],
    ['gio-gapplication-surface.php', 'GAPPLICATION'],
    ['gtk-adjustment-surface.php', 'GTKADJUSTMENT'],
    ['gtk-editable-surface.php', 'GTKEDITABLE'],
    ['gtk-entry-buffer-surface.php', 'GTKENTRYBUFFER'],
    ['gtk-entry-surface.php', 'GTKENTRY'],
    ['gtk-text-surface.php', 'GTKTEXT'],
    ['gtk-password-entry-surface.php', 'GTKPASSWORDENTRY'],
    ['gtk-search-entry-surface.php', 'GTKSEARCHENTRY'],
    ['gtk-toggle-button-surface.php', 'GTKTOGGLEBUTTON'],
    ['gtk-check-button-surface.php', 'GTKCHECKBUTTON'],
    ['gtk-switch-surface.php', 'GTKSWITCH'],
    ['gtk-range-surface.php', 'GTKRANGE'],
    ['gtk-scale-surface.php', 'GTKSCALE'],
    ['gtk-scrollbar-surface.php', 'GTKSCROLLBAR'],
    ['gtk-spin-button-surface.php', 'GTKSPINBUTTON'],
    ['gtk-label-surface.php', 'GTKLABEL'],
    ['gtk-image-surface.php', 'GTKIMAGE'],
    ['gtk-picture-surface.php', 'GTKPICTURE'],
    ['gtk-spinner-surface.php', 'GTKSPINNER'],
    ['gtk-progress-bar-surface.php', 'GTKPROGRESSBAR'],
    ['gtk-level-bar-surface.php', 'GTKLEVELBAR'],
    ['gtk-separator-surface.php', 'GTKSEPARATOR'],
    ['gtk-frame-surface.php', 'GTKFRAME'],
    ['gtk-aspect-frame-surface.php', 'GTKASPECTFRAME'],
    ['gtk-center-box-surface.php', 'GTKCENTERBOX'],
    ['gtk-grid-surface.php', 'GTKGRID'],
    ['gtk-fixed-surface.php', 'GTKFIXED'],
    ['gtk-overlay-surface.php', 'GTKOVERLAY'],
    ['gtk-scrollable-surface.php', 'GTKSCROLLABLE'],
    ['gtk-viewport-surface.php', 'GTKVIEWPORT'],
    ['gtk-scrolled-window-surface.php', 'GTKSCROLLEDWINDOW'],
    ['gtk-expander-surface.php', 'GTKEXPANDER'],
    ['gtk-revealer-surface.php', 'GTKREVEALER'],
    ['gio-glistmodel-surface.php', 'GLISTMODEL'],
    ['gio-gliststore-surface.php', 'GLISTSTORE'],
    ['gtk-string-object-surface.php', 'GTKSTRINGOBJECT'],
    ['gtk-string-list-surface.php', 'GTKSTRINGLIST'],
    ['gio-gaction-surface.php', 'GACTION'],
    ['gio-gactionmap-surface.php', 'GACTIONMAP'],
    ['gio-gsimpleaction-surface.php', 'GSIMPLEACTION'],
    ['gio-gmenumodel-surface.php', 'GMENUMODEL'],
    ['gio-gmenu-surface.php', 'GMENU'],
    ['gio-gmenuitem-surface.php', 'GMENUITEM'],
    ['gtk-actionable-surface.php', 'GTKACTIONABLE'],
    ['gtk-drop-down-surface.php', 'GTKDROPDOWN'],
    ['gtk-list-box-surface.php', 'GTKLISTBOX'],
    ['gtk-list-box-row-surface.php', 'GTKLISTBOXROW'],
    ['gtk-flow-box-surface.php', 'GTKFLOWBOX'],
    ['gtk-flow-box-child-surface.php', 'GTKFLOWBOXCHILD'],
    ['gtk-notebook-surface.php', 'GTKNOTEBOOK'],
    ['gtk-notebook-page-surface.php', 'GTKNOTEBOOKPAGE'],
    ['gtk-stack-surface.php', 'GTKSTACK'],
    ['gtk-stack-page-surface.php', 'GTKSTACKPAGE'],
    ['gtk-stack-switcher-surface.php', 'GTKSTACKSWITCHER'],
    ['gtk-stack-sidebar-surface.php', 'GTKSTACKSIDEBAR'],
    ['gtk-paned-surface.php', 'GTKPANED'],
    ['gtk-header-bar-surface.php', 'GTKHEADERBAR'],
    ['gtk-window-controls-surface.php', 'GTKWINDOWCONTROLS'],
    ['gtk-application-window-surface.php', 'GTKAPPLICATIONWINDOW'],
    ['gtk-about-dialog-surface.php', 'GTKABOUTDIALOG'],
    ['gtk-popover-surface.php', 'GTKPOPOVER'],
    ['gtk-popover-menu-surface.php', 'GTKPOPOVERMENU'],
    ['gtk-popover-menu-bar-surface.php', 'GTKPOPOVERMENUBAR'],
    ['gtk-text-buffer-surface.php', 'GTKTEXTBUFFER'],
    ['gtk-text-tag-surface.php', 'GTKTEXTTAG'],
    ['gtk-text-tag-table-surface.php', 'GTKTEXTTAGTABLE'],
    ['gtk-text-mark-surface.php', 'GTKTEXTMARK'],
    ['gtk-text-view-surface.php', 'GTKTEXTVIEW'],
];

foreach ($surfaces as [$file, $prefix]) {
    runTest("{$tests}/{$file}", [], "{$prefix}_SURFACE_OK");
    runTest("{$tests}/{$file}", ['--composite'], "{$prefix}_COMPOSITE_OK");
    runTest("{$tests}/{$file}", ['--extra-sources'], "{$prefix}_EXTRA_SOURCES_OK");
    runTest("{$tests}/{$file}", ['--no-last-error'], "{$prefix}_NO_LAST_ERROR_OK");
}

if ($failures !== []) {
    fwrite(STDERR, "\n" . count($failures) . " test(s) failed\n");
    exit(1);
}

echo "TESTS_OK\n";
