<?php

namespace Gtk\GTK\GpuPane;

class GtkGpuPane
{
    public static function gtkGpuPaneNew(): int {}

    /**
     * @return array{backend: string, display: int, window: int}
     */
    public static function gtkGpuPaneNative(int $pane): array {}
}
