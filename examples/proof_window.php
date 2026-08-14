<?php
/**
 * gtk extension — one GtkApplication, one window, one button.
 *
 * Needs a logged-in Wayland or X11 seat (same as any GTK app).
 *
 * Usage:
 *   php examples/proof_window.php
 */

declare(strict_types=1);

use Gtk\GTK\Application\GtkApplication;
use Gtk\GTK\Button\GtkButton;
use Gtk\GTK\GtkGLib;
use Gtk\GTK\Gtk;
use Gtk\GTK\GtkError;
use Gtk\GTK\Window\GtkWindow;

if (! extension_loaded('gtk')) {
    fwrite(STDERR, "gtk extension is not loaded\n");
    exit(1);
}

if (! Gtk::gtkInitCheck()) {
    fwrite(STDERR, "gtk_init_check failed (no display?). ".GtkError::gtkLastMessage()."\n");
    exit(1);
}

const G_APPLICATION_DEFAULT_FLAGS = 0;

$app = GtkApplication::gtkApplicationNew('org.scrapyardio.gtk.proof', G_APPLICATION_DEFAULT_FLAGS);
if ($app === 0) {
    fwrite(STDERR, "gtk_application_new failed: ".GtkError::gtkLastMessage()."\n");
    exit(1);
}

GtkGLib::gSignalConnect($app, 'activate', static function (int $application): void {
    $window = GtkWindow::gtkApplicationWindowNew($application);
    GtkWindow::gtkWindowSetTitle($window, 'ext-gtk proof');
    GtkWindow::gtkWindowSetDefaultSize($window, 400, 240);

    $button = GtkButton::gtkButtonNewWithLabel('Close');
    GtkGLib::gSignalConnect($button, 'clicked', static function () use ($window): void {
        GtkWindow::gtkWindowClose($window);
    });

    GtkWindow::gtkWindowSetChild($window, $button);
    GtkWindow::gtkWindowPresent($window);
});

$status = GtkApplication::gtkApplicationRun($app);
GtkGLib::gObjectUnref($app);

exit($status);
