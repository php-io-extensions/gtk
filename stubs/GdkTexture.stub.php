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

/** GdkPaintable: content that can be drawn at any size, implemented by GdkTexture and GtkMediaStream. */
interface GdkPaintable
{
    public function getCurrentImage(): GdkPaintable;

    /** GdkPaintableFlags: GDK_PAINTABLE_STATIC_SIZE (1), GDK_PAINTABLE_STATIC_CONTENTS (2), ORed */
    public function getFlags(): int;

    public function getIntrinsicWidth(): int;

    public function getIntrinsicHeight(): int;

    public function getIntrinsicAspectRatio(): float;

    public function computeConcreteSize(float $specifiedWidth, float $specifiedHeight, float $defaultWidth, float $defaultHeight, ?float &$concreteWidth, ?float &$concreteHeight): void;

    public function invalidateContents(): void;

    public function invalidateSize(): void;
}

/** GdkRectangle (cairo_rectangle_int_t): a rectangle, x, y, width and height. */
final class GdkRectangle
{
    public int $x;

    public int $y;

    public int $width;

    public int $height;

    public function __construct(int $x, int $y, int $width, int $height) {}
}

/**
 * cairo_region_t: a set of integer-aligned rectangles.
 *
 * @not-serializable
 */
final class CairoRegion
{
    private function __construct() {}

    public static function create(): CairoRegion {}

    public static function createRectangle(GdkRectangle $rectangle): CairoRegion {}

    public function numRectangles(): int {}

    public function getRectangle(int $nth): GdkRectangle {}

    /** cairo_region_union_rectangle(): the cairo_status_t, 0 (CAIRO_STATUS_SUCCESS) or 1 (CAIRO_STATUS_NO_MEMORY) */
    public function unionRectangle(GdkRectangle $rectangle): int {}
}

/**
 * GBytes: an immutable byte sequence.
 *
 * @not-serializable
 */
final class GBytes
{
    private function __construct() {}

    /** g_bytes_new(): a copy of $size bytes of the string $data, or at the address $data; null for a null address with a non-zero size */
    public static function new(string|int $data, int $size): ?GBytes {}

    public function getSize(): int {}

    /** g_bytes_get_data(): the bytes, as a string of getSize() bytes */
    public function getData(): string {}
}

/**
 * @not-serializable
 */
class GdkTexture extends GObject implements GdkPaintable
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
     * gdk_memory_texture_new(): $stride is the bytes from one row's start to the next. GDK answers
     * sizes $bytes cannot hold with a critical and null.
     */
    public static function new(int $width, int $height, GdkMemoryFormat $format, GBytes $bytes, int $stride): ?GdkMemoryTexture {}
}

#if GTK_CHECK_VERSION(4, 16, 0)
/**
 * gdk_memory_texture_builder: one GdkTexture's bytes, sizes and update region, GTK 4.16 and
 * newer. build() makes the texture, and the builder can be reused. new() refuses on a GTK older
 * than 4.16, naming the running version.
 *
 * @not-serializable
 */
final class GdkMemoryTextureBuilder extends GObject
{
    public static function new(): GdkMemoryTextureBuilder {}

    /** gdk_memory_texture_builder_set_bytes(): the builder keeps its own reference. */
    public function setBytes(GBytes $bytes): void {}

    public function setWidth(int $width): void {}

    public function setHeight(int $height): void {}

    public function setFormat(GdkMemoryFormat $format): void {}

    public function setStride(int $stride): void {}

    public function setUpdateTexture(?GdkTexture $texture): void {}

    /** gdk_memory_texture_builder_set_update_region(): the builder keeps its own reference to $region. */
    public function setUpdateRegion(?CairoRegion $region): void {}

    /**
     * gdk_memory_texture_builder_build(): a new GdkTexture, transfer full. Null when width,
     * height, format, stride or bytes is unset (GTK prints a critical warning).
     */
    public function build(): ?GdkTexture {}
}
#endif

#if GTK_CHECK_VERSION(4, 14, 0)
/**
 * GdkDmabufFormats: the (fourcc, modifier) pairs a display imports, GTK 4.14 and newer. Read only.
 *
 * @not-serializable
 */
final class GdkDmabufFormats
{
    /** Made by GdkDisplay::getDmabufFormats() only. */
    private function __construct() {}

    public function getNFormats(): int {}

    /** @return array{int, int} [fourcc, modifier]; a modifier past PHP_INT_MAX reads as its two's-complement bits. */
    public function getFormat(int $idx): array {}

    public function contains(int $fourcc, int $modifier): bool {}
}
#endif

#if GTK_CHECK_VERSION(4, 14, 0) && defined(__linux__)
/**
 * gdk_dmabuf_texture_builder: a GdkTexture over a Linux dmabuf, GTK 4.14 and newer, Linux only
 * (the class is absent elsewhere). build() imports the dmabuf, and the builder can be reused. new() refuses on a GTK older than 4.14, naming the running version.
 *
 * @not-serializable
 */
final class GdkDmabufTextureBuilder extends GObject
{
    public static function new(): GdkDmabufTextureBuilder {}

    public function setDisplay(GdkDisplay $display): void {}

    public function setWidth(int $width): void {}

    public function setHeight(int $height): void {}

    /** A DRM fourcc, e.g. DRM_FORMAT_ABGR8888 (0x34324241): bytes R, G, B, A in memory. */
    public function setFourcc(int $fourcc): void {}

    /** A DRM format modifier; DRM_FORMAT_MOD_LINEAR is 0. */
    public function setModifier(int $modifier): void {}

    public function setPremultiplied(bool $premultiplied): void {}

    public function setNPlanes(int $n_planes): void {}

    /** The fd is borrowed: it must stay open while textures built here live. */
    public function setFd(int $plane, int $fd): void {}

    public function setStride(int $plane, int $stride): void {}

    public function setOffset(int $plane, int $offset): void {}

    public function setUpdateTexture(?GdkTexture $texture): void {}

    /** gdk_dmabuf_texture_builder_set_update_region(): the builder keeps its own reference to $region. */
    public function setUpdateRegion(?CairoRegion $region): void {}

    /**
     * gdk_dmabuf_texture_builder_build(). $destroy, when not null, is called once GTK has finalized
     * the texture and is done with the fds: the moment a borrowed fd may close or its buffer be
     * reused. A failed import is thrown as GTK's GError ($destroy is not called); no texture and
     * no GError (a builder missing its fd, size or fourcc, which GTK only warns about) is null.
     */
    public function build(?callable $destroy): ?GdkTexture {}
}
#endif
