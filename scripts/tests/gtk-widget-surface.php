#!/usr/bin/env php
<?php
/**
 * End-to-end GtkWidget C-surface checks.
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . '/lib/surface-check.php';

gtkSurfaceRun([
    'classPath' => 'Gtk\\GtkWidget',
    'headerRel' => 'src/gtk-widget.h',
    'implRel' => 'src/gtk-widget.c',
    'extraSource' => 'src/gtk-widget.c',
    'girName' => 'Gtk-4.0',
    'cType' => 'GtkWidget',
    'symbolPrefix' => 'phpgtk_gtkwidget_',
    'tokenPrefix' => 'GTKWIDGET',
], $argv[1] ?? 'surface');
