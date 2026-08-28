#!/usr/bin/env php
<?php
/**
 * End-to-end GtkButton C-surface checks (slice-zero worked example).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . '/lib/surface-check.php';

gtkSurfaceRun([
    'classPath' => 'Gtk\\GtkButton',
    'headerRel' => 'src/gtk-button.h',
    'implRel' => 'src/gtk-button.c',
    'extraSource' => 'src/gtk-button.c',
    'girName' => 'Gtk-4.0',
    'cType' => 'GtkButton',
    'symbolPrefix' => 'phpgtk_gtkbutton_',
    'tokenPrefix' => 'GTKBUTTON',
], $argv[1] ?? 'surface');
