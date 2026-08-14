<?php

namespace Gtk\GTK\AlertDialog;

class GtkAlertDialog
{
    public static function gtkAlertDialogNew(string $message): int {}

    public static function gtkAlertDialogSetDetail(int $dialog, string $detail): void {}

    public static function gtkAlertDialogSetButtons(int $dialog, array $labels): void {}

    public static function gtkAlertDialogSetModal(int $dialog, bool $modal): void {}

    public static function gtkAlertDialogShow(int $dialog, int $parent): void {}

    public static function gtkAlertDialogChoose(int $dialog, int $parent, mixed $callback): void {}
}
