<?php

namespace Gtk\GTK\Image;

class GtkImage
{
    public static function gtkImageNew(): int {}

    public static function gtkImageNewFromFile(string $filename): int {}

    public static function gtkImageSetFromFile(int $image, string $filename): void {}

    public static function gtkImageSetFromIconName(int $image, string $iconName): void {}

    public static function gtkImageClear(int $image): void {}

    public static function gtkImageSetPixelSize(int $image, int $size): void {}
}
