<?php

/** @generate-class-entries */

/** GtkStyleProvider: a source of style information, implemented by GtkCssProvider and GtkSettings. */
interface GtkStyleProvider
{
}

/**
 * @not-serializable
 */
class GtkCssProvider extends GObject implements GtkStyleProvider
{
    public static function new(): GtkCssProvider {}

    public function loadFromString(string $css): void {}
}

/**
 * @not-serializable
 */
class GdkDisplay extends GObject
{
    public static function getDefault(): ?GdkDisplay {}

    public function getClipboard(): GdkClipboard {}

    /** gdk_display_sync(): flushes the requests queued for the windowing system and waits until it has handled them all (a round trip on Wayland). */
    public function sync(): void {}

#if GTK_CHECK_VERSION(4, 14, 0)
    /** gdk_display_get_dmabuf_formats(): the dmabuf formats this display imports as textures, GTK 4.14 and newer (empty off Linux). */
    public function getDmabufFormats(): GdkDmabufFormats {}
#endif
}
