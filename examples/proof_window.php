<?php
/*
 * Window proof: init GTK, put a titled window with a label-carrying button
 * on screen for two seconds, then close it. Needs the box's logged-in
 * Wayland/X11 seat (over ssh, export the seat env first).
 *
 * Run on the Linux box: php examples/proof_window.php
 */

declare(strict_types=1);

use Gtk\Bridge\Bridge;
use Gtk\Gtk\GtkBox\GtkBox;
use Gtk\Gtk\GtkButton\GtkButton;
use Gtk\Gtk\GtkWidget\GtkWidget;
use Gtk\Gtk\GtkWindow\GtkWindow;

if (!extension_loaded('gtk')) {
    fwrite(STDERR, "proof_window: the gtk extension is not loaded\n");
    exit(1);
}

if (!Bridge::init()) {
    fwrite(STDERR, "proof_window: gtk_init_check failed — no display? Run from the logged-in seat.\n");
    exit(1);
}

$win = GtkWindow::new_();
GtkWindow::setTitle($win, 'gtk ' . phpversion('gtk') . ' — proof window');
GtkWindow::setDefaultSize($win, 420, 260);

$box = GtkBox::new_(1, 12); // GTK_ORIENTATION_VERTICAL
GtkWidget::setMarginTop($box, 20);
GtkWidget::setMarginBottom($box, 20);
GtkWidget::setMarginStart($box, 20);
GtkWidget::setMarginEnd($box, 20);
GtkWindow::setChild($win, $box);

$btn = GtkButton::newWithLabel('PHP drives this window');
GtkBox::append($box, $btn);

GtkWindow::present($win);

$deadline = microtime(true) + 2.0;
while (microtime(true) < $deadline) {
    Bridge::pump(50);
}

$visible = GtkWidget::getVisible($win);
GtkWindow::close($win);
Bridge::pump(200);

if (!$visible) {
    fwrite(STDERR, "proof_window: window never became visible\n");
    exit(1);
}

echo "PROOF_WINDOW_OK\n";
