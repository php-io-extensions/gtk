<?php

namespace Gtk\GTK\GLArea;

class GtkGLArea
{
    public static function gtkGLAreaNew(): int {}

    public static function gtkGLAreaMakeCurrent(int $area): void {}

    public static function gtkGLAreaQueueRender(int $area): void {}

    public static function gtkGLAreaSetAutoRender(int $area, bool $autoRender): void {}

    public static function gtkGLAreaGetError(int $area): string {}
}
