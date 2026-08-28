#!/usr/bin/env php
<?php
/**
 * End-to-end GtkApplication C-surface checks.
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . '/lib/surface-check.php';

gtkSurfaceRun([
    'classPath' => 'Gtk\\GtkApplication',
    'headerRel' => 'src/gtk-application.h',
    'implRel' => 'src/gtk-application.c',
    'extraSource' => 'src/gtk-application.c',
    'girName' => 'Gtk-4.0',
    'cType' => 'GtkApplication',
    'symbolPrefix' => 'phpgtk_gtkapplication_',
    'tokenPrefix' => 'GTKAPPLICATION',
], $argv[1] ?? 'surface');
