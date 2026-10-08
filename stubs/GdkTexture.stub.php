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
     * start to the next; $bytes must hold every row. As an address (an ext-fb buffer's pointer()),
     * the rows the width, height and stride name are read there: the address is trusted, it must
     * hold them.
     */
    public static function new(int $width, int $height, GdkMemoryFormat $format, string|int $bytes, int $stride): GdkMemoryTexture {}
}

#if GTK_CHECK_VERSION(4, 16, 0)
/**
 * gdk_memory_texture_builder: one GdkTexture's bytes, sizes and update region, GTK 4.16 and
 * newer. Each setter returns the builder; build() makes the texture, and the builder can be
 * reused. new() refuses on a GTK older than 4.16, naming the running version.
 *
 * @not-serializable
 */
final class GdkMemoryTextureBuilder extends GObject
{
    public static function new(): GdkMemoryTextureBuilder {}

    /**
     * gdk_memory_texture_builder_set_bytes() over a GBytes copy of $bytes. As an address
     * (an ext-fb buffer's pointer()), $length bytes are read there: the address is trusted, it
     * must hold $length readable bytes; $length must be null when $bytes is a string.
     */
    public function setBytes(string|int $bytes, ?int $length = null): static {}

    public function setWidth(int $width): static {}

    public function setHeight(int $height): static {}

    public function setFormat(GdkMemoryFormat $format): static {}

    public function setStride(int $stride): static {}

    public function setUpdateTexture(?GdkTexture $texture): static {}

    /**
     * gdk_memory_texture_builder_set_update_region() over one cairo_region_t built from $rects;
     * each rect is [x, y, width, height].
     *
     * @param array|null $rects One [int $x, int $y, int $width, int $height] per rect.
     */
    public function setUpdateRegion(?array $rects): static {}

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
 * (the class is absent elsewhere). Each setter returns the builder; build() imports the dmabuf, and
 * the builder can be reused. new() refuses on a GTK older than 4.14, naming the running version.
 *
 * @not-serializable
 */
final class GdkDmabufTextureBuilder extends GObject
{
    public static function new(): GdkDmabufTextureBuilder {}

    public function setDisplay(GdkDisplay $display): static {}

    public function setWidth(int $width): static {}

    public function setHeight(int $height): static {}

    /** A DRM fourcc, e.g. DRM_FORMAT_ABGR8888 (0x34324241): bytes R, G, B, A in memory. */
    public function setFourcc(int $fourcc): static {}

    /** A DRM format modifier; DRM_FORMAT_MOD_LINEAR is 0. */
    public function setModifier(int $modifier): static {}

    public function setPremultiplied(bool $premultiplied): static {}

    public function setNPlanes(int $n_planes): static {}

    /** The fd is borrowed: it must stay open while textures built here live. */
    public function setFd(int $plane, int $fd): static {}

    public function setStride(int $plane, int $stride): static {}

    public function setOffset(int $plane, int $offset): static {}

    public function setUpdateTexture(?GdkTexture $texture): static {}

    /**
     * gdk_dmabuf_texture_builder_set_update_region() over one cairo_region_t built from $rects;
     * each rect is [x, y, width, height].
     *
     * @param array|null $rects One [int $x, int $y, int $width, int $height] per rect.
     */
    public function setUpdateRegion(?array $rects): static {}

    /**
     * gdk_dmabuf_texture_builder_build(). $destroy, when given, is called once GTK has finalized
     * the texture and is done with the fds: the moment a borrowed fd may close or its buffer be
     * reused. A failed import is thrown as GTK's GError ($destroy is not called); no texture and
     * no GError (a builder missing its fd, size or fourcc, which GTK only warns about) is a
     * GtkException.
     */
    public function build(?callable $destroy = null): GdkTexture {}
}
#endif
