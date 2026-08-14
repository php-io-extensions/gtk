<?php

namespace Gtk\GTK\Window;

class GtkWindow
{
    public static function gtkWindowNew(): int {}

    public static function gtkApplicationWindowNew(int $app): int {}

    public static function gtkWindowSetTitle(int $window, string $title): void {}

    public static function gtkWindowGetTitle(int $window): string {}

    public static function gtkWindowSetDefaultSize(int $window, int $width, int $height): void {}

    public static function gtkWindowGetDefaultSize(int $window): array {}

    public static function gtkWindowSetChild(int $window, int $child): void {}

    public static function gtkWindowGetChild(int $window): int {}

    public static function gtkWindowPresent(int $window): void {}

    public static function gtkWindowClose(int $window): void {}

    public static function gtkWindowDestroy(int $window): void {}

    public static function gtkWindowSetTitlebar(int $window, int $titlebar): void {}

    public static function gtkWindowGetTitlebar(int $window): int {}
}
