<?php

namespace Gtk\GTK\ColorDialog;

class GtkColorDialog
{
    public static function gtkColorDialogNew(): int {}

    public static function gtkColorDialogSetTitle(int $dialog, string $title): void {}

    public static function gtkColorDialogSetModal(int $dialog, bool $modal): void {}

    public static function gtkColorDialogChooseRgba(int $dialog, int $parent, mixed $callback): void {}
}
