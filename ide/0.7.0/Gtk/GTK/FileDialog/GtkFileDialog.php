<?php

namespace Gtk\GTK\FileDialog;

class GtkFileDialog
{
    public static function gtkFileDialogNew(): int {}

    public static function gtkFileDialogSetTitle(int $dialog, string $title): void {}

    public static function gtkFileDialogGetTitle(int $dialog): string {}

    public static function gtkFileDialogSetInitialName(int $dialog, string $name): void {}

    public static function gtkFileDialogOpen(int $dialog, int $parent, mixed $callback): void {}

    public static function gtkFileDialogSave(int $dialog, int $parent, mixed $callback): void {}

    public static function gtkFileDialogSelectFolder(int $dialog, int $parent, mixed $callback): void {}
}
