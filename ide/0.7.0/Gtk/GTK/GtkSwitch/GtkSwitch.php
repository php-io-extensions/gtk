<?php

namespace Gtk\GTK\GtkSwitch;

class GtkSwitch
{
    public static function gtkSwitchNew(): int {}

    public static function gtkSwitchSetActive(int $sw, bool $active): void {}

    public static function gtkSwitchGetActive(int $sw): bool {}
}
