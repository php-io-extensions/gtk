<?php

namespace Gtk\GTK\ScrolledWindow;

class GtkScrolledWindow
{
    public static function gtkScrolledWindowNew(): int {}

    public static function gtkScrolledWindowSetChild(int $scrolled, int $child): void {}

    public static function gtkScrolledWindowGetChild(int $scrolled): int {}

    public static function gtkScrolledWindowSetPolicy(int $scrolled, int $hscrollbar, int $vscrollbar): void {}

    public static function gtkScrolledWindowSetMinContentHeight(int $scrolled, int $height): void {}

    public static function gtkScrolledWindowSetMinContentWidth(int $scrolled, int $width): void {}
}
