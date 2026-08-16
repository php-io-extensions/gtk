<?php

namespace Gtk\GTK\Label;

class GtkLabel
{
    public static function gtkLabelNew(string $text): int {}

    public static function gtkLabelSetText(int $label, string $text): void {}

    public static function gtkLabelGetText(int $label): string {}

    public static function gtkLabelSetXalign(int $label, float $xalign): void {}
}
