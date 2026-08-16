<?php

declare(strict_types=1);

/**
 * Menubar proof: File → Close via GMenu + GSimpleAction on GtkApplication.
 *
 *   php examples/proof_menubar.php
 *
 * Needs a GUI seat (Wayland/X11). Ctrl+C also exits.
 */

use Gtk\GTK\Application\GtkApplication;
use Gtk\GTK\GMenu\GMenu;
use Gtk\GTK\GSimpleAction\GSimpleAction;
use Gtk\GTK\Gtk;
use Gtk\GTK\GtkGLib;
use Gtk\GTK\Window\GtkWindow;

if (! extension_loaded('gtk')) {
    fwrite(STDERR, "gtk extension not loaded\n");
    exit(1);
}

Gtk::gtkInitCheck();

$app = GtkApplication::gtkApplicationNew('io.scrapyard.gtk.proof-menubar', 0);
if ($app === 0) {
    fwrite(STDERR, "gtk_application_new failed\n");
    exit(1);
}

$closeAction = GSimpleAction::gSimpleActionNew('close');
if ($closeAction === 0) {
    fwrite(STDERR, "g_simple_action_new failed\n");
    exit(1);
}

GSimpleAction::gActionMapAddAction($app, $closeAction);

$fileMenu = GMenu::gMenuNew();
GMenu::gMenuAppend($fileMenu, 'Close', 'app.close');

$menubar = GMenu::gMenuNew();
GMenu::gMenuAppendSubmenu($menubar, 'File', $fileMenu);

GtkApplication::gtkApplicationSetMenubar($app, $menubar);
GtkApplication::gtkApplicationSetAccelsForAction($app, 'app.close', ['<Control>w']);

$windowHandle = 0;

GtkGLib::gSignalConnect($app, 'activate', static function () use ($app, &$windowHandle): void {
    if ($windowHandle !== 0) {
        return;
    }

    $windowHandle = GtkWindow::gtkApplicationWindowNew($app);
    GtkWindow::gtkWindowSetTitle($windowHandle, 'GTK Menubar Proof');
    GtkWindow::gtkWindowSetDefaultSize($windowHandle, 640, 480);
    GtkWindow::gtkWindowPresent($windowHandle);
});

GtkGLib::gSignalConnect($closeAction, 'activate', static function () use ($app, &$windowHandle): void {
    if ($windowHandle !== 0) {
        GtkWindow::gtkWindowClose($windowHandle);
    }
    GtkApplication::gtkApplicationQuit($app);
});

echo "GTK menubar proof — use File → Close or Ctrl+W\n";
GtkApplication::gtkApplicationRun($app);
