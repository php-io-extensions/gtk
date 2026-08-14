<?php

namespace Gtk\GTK\Popover;

class GtkPopover
{
    public static function gtkPopoverNew(): int {}

    public static function gtkPopoverSetChild(int $popover, int $child): void {}

    public static function gtkPopoverGetChild(int $popover): int {}

    public static function gtkPopoverPopup(int $popover): void {}

    public static function gtkPopoverPopdown(int $popover): void {}

    public static function gtkPopoverSetAutohide(int $popover, bool $autohide): void {}
}
