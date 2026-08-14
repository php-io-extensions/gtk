<?php

namespace Gtk\GTK\Spinner;

class GtkSpinner
{
    public static function gtkSpinnerNew(): int {}

    public static function gtkSpinnerStart(int $spinner): void {}

    public static function gtkSpinnerStop(int $spinner): void {}

    public static function gtkSpinnerSetSpinning(int $spinner, bool $spinning): void {}

    public static function gtkSpinnerGetSpinning(int $spinner): bool {}
}
