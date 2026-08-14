<?php

namespace Gtk\GTK\Button;

class GtkButton
{
    public static function gtkButtonNew(): int {}

    public static function gtkButtonNewWithLabel(string $label): int {}

    public static function gtkButtonSetLabel(int $button, string $label): void {}

    public static function gtkButtonGetLabel(int $button): string {}
}
