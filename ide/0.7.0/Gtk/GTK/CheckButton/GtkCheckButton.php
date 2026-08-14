<?php

namespace Gtk\GTK\CheckButton;

class GtkCheckButton
{
    public static function gtkCheckButtonNew(): int {}

    public static function gtkCheckButtonNewWithLabel(string $label): int {}

    public static function gtkCheckButtonSetLabel(int $button, string $label): void {}

    public static function gtkCheckButtonGetLabel(int $button): string {}

    public static function gtkCheckButtonSetActive(int $button, bool $active): void {}

    public static function gtkCheckButtonGetActive(int $button): bool {}
}
