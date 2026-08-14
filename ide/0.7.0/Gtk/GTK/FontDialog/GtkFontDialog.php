<?php

namespace Gtk\GTK\FontDialog;

class GtkFontDialog
{
    public static function gtkFontDialogNew(): int {}

    public static function gtkFontDialogSetTitle(int $dialog, string $title): void {}

    public static function gtkFontDialogSetModal(int $dialog, bool $modal): void {}

    public static function gtkFontDialogChooseFont(int $dialog, int $parent, mixed $callback): void {}
}
