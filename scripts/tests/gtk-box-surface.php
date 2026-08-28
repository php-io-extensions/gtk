#!/usr/bin/env php
<?php
/**
 * End-to-end GtkBox C-surface checks.
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . '/lib/surface-check.php';

gtkSurfaceRun([
    'classPath' => 'Gtk\\GtkBox',
    'headerRel' => 'src/gtk-box.h',
    'implRel' => 'src/gtk-box.c',
    'extraSource' => 'src/gtk-box.c',
    'girName' => 'Gtk-4.0',
    'cType' => 'GtkBox',
    'symbolPrefix' => 'phpgtk_gtkbox_',
    'tokenPrefix' => 'GTKBOX',
], $argv[1] ?? 'surface');
