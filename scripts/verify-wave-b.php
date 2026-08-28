#!/usr/bin/env php
<?php
/**
 * Wave B inventory verifier. Re-measures gir constructor+method+function
 * counts from the vendored XML and asserts each listed class is bound or
 * reserved to that count, listed in extra-sources, and covered by a
 * surface test registered in run-all.php. Prints a success-only token
 * after every assertion. Does not copy plan numbers into the token.
 */

declare(strict_types=1);

const WAVES = [
    'b1' => [
        ['classPath' => 'Gio\\GListModel', 'cType' => 'GListModel', 'girName' => 'Gio-2.0', 'headerRel' => 'src/gio-glistmodel.h', 'implRel' => 'src/gio-glistmodel.c', 'surface' => 'gio-glistmodel-surface.php', 'token' => 'GLISTMODEL'],
        ['classPath' => 'Gio\\GListStore', 'cType' => 'GListStore', 'girName' => 'Gio-2.0', 'headerRel' => 'src/gio-gliststore.h', 'implRel' => 'src/gio-gliststore.c', 'surface' => 'gio-gliststore-surface.php', 'token' => 'GLISTSTORE'],
        ['classPath' => 'Gtk\\GtkStringObject', 'cType' => 'GtkStringObject', 'girName' => 'Gtk-4.0', 'headerRel' => 'src/gtk-string-object.h', 'implRel' => 'src/gtk-string-object.c', 'surface' => 'gtk-string-object-surface.php', 'token' => 'GTKSTRINGOBJECT'],
        ['classPath' => 'Gtk\\GtkStringList', 'cType' => 'GtkStringList', 'girName' => 'Gtk-4.0', 'headerRel' => 'src/gtk-string-list.h', 'implRel' => 'src/gtk-string-list.c', 'surface' => 'gtk-string-list-surface.php', 'token' => 'GTKSTRINGLIST'],
    ],
    'b2' => [
        ['classPath' => 'Gio\\GAction', 'cType' => 'GAction', 'girName' => 'Gio-2.0', 'headerRel' => 'src/gio-gaction.h', 'implRel' => 'src/gio-gaction.c', 'surface' => 'gio-gaction-surface.php', 'token' => 'GACTION'],
        ['classPath' => 'Gio\\GActionMap', 'cType' => 'GActionMap', 'girName' => 'Gio-2.0', 'headerRel' => 'src/gio-gactionmap.h', 'implRel' => 'src/gio-gactionmap.c', 'surface' => 'gio-gactionmap-surface.php', 'token' => 'GACTIONMAP'],
        ['classPath' => 'Gio\\GSimpleAction', 'cType' => 'GSimpleAction', 'girName' => 'Gio-2.0', 'headerRel' => 'src/gio-gsimpleaction.h', 'implRel' => 'src/gio-gsimpleaction.c', 'surface' => 'gio-gsimpleaction-surface.php', 'token' => 'GSIMPLEACTION'],
        ['classPath' => 'Gio\\GMenuModel', 'cType' => 'GMenuModel', 'girName' => 'Gio-2.0', 'headerRel' => 'src/gio-gmenumodel.h', 'implRel' => 'src/gio-gmenumodel.c', 'surface' => 'gio-gmenumodel-surface.php', 'token' => 'GMENUMODEL'],
        ['classPath' => 'Gio\\GMenu', 'cType' => 'GMenu', 'girName' => 'Gio-2.0', 'headerRel' => 'src/gio-gmenu.h', 'implRel' => 'src/gio-gmenu.c', 'surface' => 'gio-gmenu-surface.php', 'token' => 'GMENU'],
        ['classPath' => 'Gio\\GMenuItem', 'cType' => 'GMenuItem', 'girName' => 'Gio-2.0', 'headerRel' => 'src/gio-gmenuitem.h', 'implRel' => 'src/gio-gmenuitem.c', 'surface' => 'gio-gmenuitem-surface.php', 'token' => 'GMENUITEM'],
        ['classPath' => 'Gtk\\GtkActionable', 'cType' => 'GtkActionable', 'girName' => 'Gtk-4.0', 'headerRel' => 'src/gtk-actionable.h', 'implRel' => 'src/gtk-actionable.c', 'surface' => 'gtk-actionable-surface.php', 'token' => 'GTKACTIONABLE'],
    ],
    'b3' => [
        ['classPath' => 'Gtk\\GtkDropDown', 'cType' => 'GtkDropDown', 'girName' => 'Gtk-4.0', 'headerRel' => 'src/gtk-drop-down.h', 'implRel' => 'src/gtk-drop-down.c', 'surface' => 'gtk-drop-down-surface.php', 'token' => 'GTKDROPDOWN'],
        ['classPath' => 'Gtk\\GtkListBox', 'cType' => 'GtkListBox', 'girName' => 'Gtk-4.0', 'headerRel' => 'src/gtk-list-box.h', 'implRel' => 'src/gtk-list-box.c', 'surface' => 'gtk-list-box-surface.php', 'token' => 'GTKLISTBOX'],
        ['classPath' => 'Gtk\\GtkListBoxRow', 'cType' => 'GtkListBoxRow', 'girName' => 'Gtk-4.0', 'headerRel' => 'src/gtk-list-box-row.h', 'implRel' => 'src/gtk-list-box-row.c', 'surface' => 'gtk-list-box-row-surface.php', 'token' => 'GTKLISTBOXROW'],
    ],
    'b4' => [
        ['classPath' => 'Gtk\\GtkFlowBox', 'cType' => 'GtkFlowBox', 'girName' => 'Gtk-4.0', 'headerRel' => 'src/gtk-flow-box.h', 'implRel' => 'src/gtk-flow-box.c', 'surface' => 'gtk-flow-box-surface.php', 'token' => 'GTKFLOWBOX'],
        ['classPath' => 'Gtk\\GtkFlowBoxChild', 'cType' => 'GtkFlowBoxChild', 'girName' => 'Gtk-4.0', 'headerRel' => 'src/gtk-flow-box-child.h', 'implRel' => 'src/gtk-flow-box-child.c', 'surface' => 'gtk-flow-box-child-surface.php', 'token' => 'GTKFLOWBOXCHILD'],
        ['classPath' => 'Gtk\\GtkNotebook', 'cType' => 'GtkNotebook', 'girName' => 'Gtk-4.0', 'headerRel' => 'src/gtk-notebook.h', 'implRel' => 'src/gtk-notebook.c', 'surface' => 'gtk-notebook-surface.php', 'token' => 'GTKNOTEBOOK'],
        ['classPath' => 'Gtk\\GtkNotebookPage', 'cType' => 'GtkNotebookPage', 'girName' => 'Gtk-4.0', 'headerRel' => 'src/gtk-notebook-page.h', 'implRel' => 'src/gtk-notebook-page.c', 'surface' => 'gtk-notebook-page-surface.php', 'token' => 'GTKNOTEBOOKPAGE'],
    ],
    'b5' => [
        ['classPath' => 'Gtk\\GtkStack', 'cType' => 'GtkStack', 'girName' => 'Gtk-4.0', 'headerRel' => 'src/gtk-stack.h', 'implRel' => 'src/gtk-stack.c', 'surface' => 'gtk-stack-surface.php', 'token' => 'GTKSTACK'],
        ['classPath' => 'Gtk\\GtkStackPage', 'cType' => 'GtkStackPage', 'girName' => 'Gtk-4.0', 'headerRel' => 'src/gtk-stack-page.h', 'implRel' => 'src/gtk-stack-page.c', 'surface' => 'gtk-stack-page-surface.php', 'token' => 'GTKSTACKPAGE'],
        ['classPath' => 'Gtk\\GtkStackSwitcher', 'cType' => 'GtkStackSwitcher', 'girName' => 'Gtk-4.0', 'headerRel' => 'src/gtk-stack-switcher.h', 'implRel' => 'src/gtk-stack-switcher.c', 'surface' => 'gtk-stack-switcher-surface.php', 'token' => 'GTKSTACKSWITCHER'],
        ['classPath' => 'Gtk\\GtkStackSidebar', 'cType' => 'GtkStackSidebar', 'girName' => 'Gtk-4.0', 'headerRel' => 'src/gtk-stack-sidebar.h', 'implRel' => 'src/gtk-stack-sidebar.c', 'surface' => 'gtk-stack-sidebar-surface.php', 'token' => 'GTKSTACKSIDEBAR'],
        ['classPath' => 'Gtk\\GtkPaned', 'cType' => 'GtkPaned', 'girName' => 'Gtk-4.0', 'headerRel' => 'src/gtk-paned.h', 'implRel' => 'src/gtk-paned.c', 'surface' => 'gtk-paned-surface.php', 'token' => 'GTKPANED'],
    ],
    'b6' => [
        ['classPath' => 'Gtk\\GtkHeaderBar', 'cType' => 'GtkHeaderBar', 'girName' => 'Gtk-4.0', 'headerRel' => 'src/gtk-header-bar.h', 'implRel' => 'src/gtk-header-bar.c', 'surface' => 'gtk-header-bar-surface.php', 'token' => 'GTKHEADERBAR'],
        ['classPath' => 'Gtk\\GtkWindowControls', 'cType' => 'GtkWindowControls', 'girName' => 'Gtk-4.0', 'headerRel' => 'src/gtk-window-controls.h', 'implRel' => 'src/gtk-window-controls.c', 'surface' => 'gtk-window-controls-surface.php', 'token' => 'GTKWINDOWCONTROLS'],
        ['classPath' => 'Gtk\\GtkApplicationWindow', 'cType' => 'GtkApplicationWindow', 'girName' => 'Gtk-4.0', 'headerRel' => 'src/gtk-application-window.h', 'implRel' => 'src/gtk-application-window.c', 'surface' => 'gtk-application-window-surface.php', 'token' => 'GTKAPPLICATIONWINDOW'],
        ['classPath' => 'Gtk\\GtkAboutDialog', 'cType' => 'GtkAboutDialog', 'girName' => 'Gtk-4.0', 'headerRel' => 'src/gtk-about-dialog.h', 'implRel' => 'src/gtk-about-dialog.c', 'surface' => 'gtk-about-dialog-surface.php', 'token' => 'GTKABOUTDIALOG'],
    ],
    'b7' => [
        ['classPath' => 'Gtk\\GtkPopover', 'cType' => 'GtkPopover', 'girName' => 'Gtk-4.0', 'headerRel' => 'src/gtk-popover.h', 'implRel' => 'src/gtk-popover.c', 'surface' => 'gtk-popover-surface.php', 'token' => 'GTKPOPOVER'],
        ['classPath' => 'Gtk\\GtkPopoverMenu', 'cType' => 'GtkPopoverMenu', 'girName' => 'Gtk-4.0', 'headerRel' => 'src/gtk-popover-menu.h', 'implRel' => 'src/gtk-popover-menu.c', 'surface' => 'gtk-popover-menu-surface.php', 'token' => 'GTKPOPOVERMENU'],
        ['classPath' => 'Gtk\\GtkPopoverMenuBar', 'cType' => 'GtkPopoverMenuBar', 'girName' => 'Gtk-4.0', 'headerRel' => 'src/gtk-popover-menu-bar.h', 'implRel' => 'src/gtk-popover-menu-bar.c', 'surface' => 'gtk-popover-menu-bar-surface.php', 'token' => 'GTKPOPOVERMENUBAR'],
    ],
    'b8' => [
        ['classPath' => 'Gtk\\GtkTextBuffer', 'cType' => 'GtkTextBuffer', 'girName' => 'Gtk-4.0', 'headerRel' => 'src/gtk-text-buffer.h', 'implRel' => 'src/gtk-text-buffer.c', 'surface' => 'gtk-text-buffer-surface.php', 'token' => 'GTKTEXTBUFFER'],
        ['classPath' => 'Gtk\\GtkTextTag', 'cType' => 'GtkTextTag', 'girName' => 'Gtk-4.0', 'headerRel' => 'src/gtk-text-tag.h', 'implRel' => 'src/gtk-text-tag.c', 'surface' => 'gtk-text-tag-surface.php', 'token' => 'GTKTEXTTAG'],
        ['classPath' => 'Gtk\\GtkTextTagTable', 'cType' => 'GtkTextTagTable', 'girName' => 'Gtk-4.0', 'headerRel' => 'src/gtk-text-tag-table.h', 'implRel' => 'src/gtk-text-tag-table.c', 'surface' => 'gtk-text-tag-table-surface.php', 'token' => 'GTKTEXTTAGTABLE'],
        ['classPath' => 'Gtk\\GtkTextMark', 'cType' => 'GtkTextMark', 'girName' => 'Gtk-4.0', 'headerRel' => 'src/gtk-text-mark.h', 'implRel' => 'src/gtk-text-mark.c', 'surface' => 'gtk-text-mark-surface.php', 'token' => 'GTKTEXTMARK'],
    ],
    'b9' => [
        ['classPath' => 'Gtk\\GtkTextView', 'cType' => 'GtkTextView', 'girName' => 'Gtk-4.0', 'headerRel' => 'src/gtk-text-view.h', 'implRel' => 'src/gtk-text-view.c', 'surface' => 'gtk-text-view-surface.php', 'token' => 'GTKTEXTVIEW'],
    ],
];

$root = dirname(__DIR__);
$mode = $argv[1] ?? '';

function fail(string $msg): never
{
    fwrite(STDERR, "verify-wave-b: {$msg}\n");
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

function girExpected(string $root, string $girName, string $cType): int
{
    $gir = $root . '/scripts/gir/' . $girName . '.gir.gz';
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
        $expected = girExpected($root, $spec['girName'], $spec['cType']);
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

function verifyTypeFromName(string $root): void
{
    $h = (string) file_get_contents($root . '/src/phpgtk-bridge.h');
    $c = (string) file_get_contents($root . '/src/phpgtk-bridge.c');
    if (!preg_match('#/\*\s*@zep\s+Bridge\\\\Bridge\s+typeFromName\(string typeName\)\s*->\s*int\s*\*/#', $h)) {
        fail('phpgtk-bridge.h is missing @zep Bridge\\Bridge typeFromName(string typeName) -> int');
    }
    if (!preg_match('/zend_long\s+phpgtk_bridge_type_from_name\s*\(/', $h)) {
        fail('phpgtk-bridge.h is missing phpgtk_bridge_type_from_name prototype');
    }
    if (!preg_match('/zend_long\s+phpgtk_bridge_type_from_name\s*\(zval\s+\*typeName\)\s*\{/', $c, $m, PREG_OFFSET_CAPTURE)) {
        fail('phpgtk-bridge.c is missing phpgtk_bridge_type_from_name body');
    }
    $start = (int) $m[0][1] + strlen($m[0][0]);
    $depth = 1;
    $end = $start;
    $len = strlen($c);
    while ($end < $len && $depth > 0) {
        $ch = $c[$end];
        if ($ch === '{') {
            $depth++;
        } elseif ($ch === '}') {
            $depth--;
        }
        $end++;
    }
    if ($depth !== 0) {
        fail('phpgtk-bridge.c typeFromName body is unclosed');
    }
    $body = substr($c, $start, $end - $start - 1);
    if (!preg_match('/\bg_type_from_name\s*\(/', $body)) {
        fail('typeFromName body does not call g_type_from_name');
    }
    if (preg_match_all('/\b(g|gtk|gdk|gsk|pango)_[a-z0-9_]+\s*\(/', $body, $calls) && count($calls[0]) !== 1) {
        fail('typeFromName body must contain exactly one native call, found: ' . implode(', ', $calls[0]));
    }
    echo "TYPE_FROM_NAME_OK\n";
}

function verifyOkf(string $root): void
{
    $rules = (string) file_get_contents($root . '/.okf/binding-rules.md');
    $bridge = (string) file_get_contents($root . '/.okf/bridge.md');
    $log = (string) file_get_contents($root . '/.okf/log.md');
    $missing = [];
    foreach (WAVES as $specs) {
        foreach ($specs as $spec) {
            $short = preg_replace('/^(Gtk|Gio)\\\\/', '', $spec['classPath']);
            if (!str_contains($rules, $short) && !str_contains($log, $short)) {
                $missing[] = $short;
            }
        }
    }
    if ($missing !== []) {
        fail('OKF does not mention: ' . implode(', ', $missing));
    }
    if (!str_contains($bridge, 'typeFromName') && !str_contains($log, 'typeFromName')) {
        fail('OKF does not mention typeFromName');
    }
    if (!str_contains($log, 'Wave B') && !str_contains($log, 'wave B') && !str_contains($log, 'wave-b')) {
        fail('.okf/log.md has no Wave B entry');
    }
    echo "WAVE_B_OKF_OK\n";
}

if ($mode === '--okf') {
    verifyOkf($root);
    exit(0);
}

if ($mode === '--type-from-name') {
    verifyTypeFromName($root);
    exit(0);
}

if ($mode === '--wave') {
    $wave = strtolower((string) ($argv[2] ?? ''));
    if ($wave === 'all') {
        foreach (array_keys(WAVES) as $w) {
            verifyWave($root, $w);
        }
        echo "WAVE_B12_OK\n";
        exit(0);
    }
    verifyWave($root, $wave);
    exit(0);
}

fail('usage: verify-wave-b.php --wave b1|b2|b3|b4|b5|b6|b7|b8|b9|all | --type-from-name | --okf');
