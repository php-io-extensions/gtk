#!/usr/bin/env php
<?php
/**
 * End-to-end GtkWindow C-surface checks.
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . '/lib/surface-check.php';

gtkSurfaceRun([
    'classPath' => 'Gtk\\GtkWindow',
    'headerRel' => 'src/gtk-window.h',
    'implRel' => 'src/gtk-window.c',
    'extraSource' => 'src/gtk-window.c',
    'girName' => 'Gtk-4.0',
    'cType' => 'GtkWindow',
    'symbolPrefix' => 'phpgtk_gtkwindow_',
    'tokenPrefix' => 'GTKWINDOW',
], $argv[1] ?? 'surface');
