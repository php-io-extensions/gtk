#!/usr/bin/env php
<?php
/**
 * End-to-end GtkOrientable C-surface checks (interface bound as a class).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . '/lib/surface-check.php';

gtkSurfaceRun([
    'classPath' => 'Gtk\\GtkOrientable',
    'headerRel' => 'src/gtk-orientable.h',
    'implRel' => 'src/gtk-orientable.c',
    'extraSource' => 'src/gtk-orientable.c',
    'girName' => 'Gtk-4.0',
    'cType' => 'GtkOrientable',
    'symbolPrefix' => 'phpgtk_gtkorientable_',
    'tokenPrefix' => 'GTKORIENTABLE',
], $argv[1] ?? 'surface');
