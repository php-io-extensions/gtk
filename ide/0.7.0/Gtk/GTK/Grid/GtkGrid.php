<?php

namespace Gtk\GTK\Grid;

class GtkGrid
{
    public static function gtkGridNew(): int {}

    public static function gtkGridAttach(int $grid, int $child, int $column, int $row, int $width, int $height): void {}

    public static function gtkGridRemove(int $grid, int $child): void {}

    public static function gtkGridSetRowSpacing(int $grid, int $spacing): void {}

    public static function gtkGridSetColumnSpacing(int $grid, int $spacing): void {}

    public static function gtkGridSetRowHomogeneous(int $grid, bool $homogeneous): void {}

    public static function gtkGridSetColumnHomogeneous(int $grid, bool $homogeneous): void {}
}
