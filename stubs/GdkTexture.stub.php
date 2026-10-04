<?php

/** @generate-class-entries */

/** The 8-bit GdkMemoryFormat layouts: the order of a pixel's bytes in memory. */
enum GdkMemoryFormat: int
{
    case B8G8R8A8_PREMULTIPLIED = 0;
    case A8R8G8B8_PREMULTIPLIED = 1;
    case R8G8B8A8_PREMULTIPLIED = 2;
    case B8G8R8A8 = 3;
    case A8R8G8B8 = 4;
    case R8G8B8A8 = 5;
    case A8B8G8R8 = 6;
    case R8G8B8 = 7;
    case B8G8R8 = 8;
    case A8B8G8R8_PREMULTIPLIED = 28;
    /** The X8 layouts ignore their fourth byte: opaque. GTK 4.14 and newer. */
    case B8G8R8X8 = 29;
    case X8R8G8B8 = 30;
    case R8G8B8X8 = 31;
    case X8B8G8R8 = 32;
}

/**
 * @not-serializable
 */
class GdkTexture extends GObject
{
    public function getWidth(): int {}

    public function getHeight(): int {}
}

/**
 * @not-serializable
 */
class GdkMemoryTexture extends GdkTexture
{
    /**
     * gdk_memory_texture_new() over a GBytes copy of $bytes. $stride is the bytes from one row's
     * start to the next; $bytes must hold every row.
     */
    public static function new(int $width, int $height, GdkMemoryFormat $format, string $bytes, int $stride): GdkMemoryTexture {}
}
