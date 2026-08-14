<?php

namespace Gtk\GTK\Picture;

class GtkPicture
{
    public static function gtkPictureNew(): int {}

    public static function gtkPictureNewForFilename(string $filename): int {}

    public static function gtkPictureSetFilename(int $picture, string $filename): void {}

    public static function gtkPictureSetCanShrink(int $picture, bool $canShrink): void {}
}
