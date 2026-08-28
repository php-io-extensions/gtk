<?php
/**
 * End-to-end GtkAboutDialog C-surface checks (Wave B).
 * Modes: (default), --composite, --extra-sources, --no-last-error
 */

declare(strict_types=1);

require __DIR__ . "/lib/surface-check.php";

gtkSurfaceRun([
    "classPath" => "Gtk\\GtkAboutDialog",
    "headerRel" => "src/gtk-about-dialog.h",
    "implRel" => "src/gtk-about-dialog.c",
    "extraSource" => "src/gtk-about-dialog.c",
    "girName" => "Gtk-4.0",
    "cType" => "GtkAboutDialog",
    "symbolPrefix" => "phpgtk_gtkaboutdialog_",
    "tokenPrefix" => "GTKABOUTDIALOG",
], $argv[1] ?? "surface");
