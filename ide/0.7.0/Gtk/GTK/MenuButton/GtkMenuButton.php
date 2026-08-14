<?php

namespace Gtk\GTK\MenuButton;

class GtkMenuButton
{
    public static function gtkMenuButtonNew(): int {}

    public static function gtkMenuButtonSetLabel(int $button, string $label): void {}

    public static function gtkMenuButtonGetLabel(int $button): string {}

    public static function gtkMenuButtonSetPopover(int $button, int $popover): void {}

    public static function gtkMenuButtonGetPopover(int $button): int {}

    public static function gtkMenuButtonPopup(int $button): void {}

    public static function gtkMenuButtonPopdown(int $button): void {}
}
