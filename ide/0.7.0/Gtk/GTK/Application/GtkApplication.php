<?php

namespace Gtk\GTK\Application;

class GtkApplication
{
    public static function gtkApplicationNew(string $applicationId, int $flags): int {}

    public static function gtkApplicationRun(int $app): int {}

    public static function gtkApplicationQuit(int $app): void {}
}
