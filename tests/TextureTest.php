<?php

declare(strict_types=1);

/** A GBytes copy of the whole string. */
function gbytes(string $data): GBytes
{
    return GBytes::new($data, strlen($data));
}

it('makes a texture from bytes', function (): void {
    gtk_init();
    $texture = GdkMemoryTexture::new(3, 2, GdkMemoryFormat::R8G8B8A8, gbytes(str_repeat("\xff\x80\x00\xff", 6)), 12);

    expect($texture)->toBeInstanceOf(GdkTexture::class)
        ->and([$texture->getWidth(), $texture->getHeight()])->toBe([3, 2])
        ->and(GdkMemoryTexture::new(2, 2, GdkMemoryFormat::R8G8B8, gbytes(str_repeat('x', 14)), 8)->getWidth())->toBe(2)   // a padded stride; the last row needs no padding
        ->and(GdkMemoryTexture::new(1, 1, GdkMemoryFormat::R8G8B8X8, gbytes("\x01\x02\x03\x00"), 4)->getHeight())->toBe(1);
});

it('carries GDK\'s values for the memory formats', function (): void {
    expect(array_map(fn (GdkMemoryFormat $f): int => $f->value, GdkMemoryFormat::cases()))->toBe([0, 1, 2, 3, 4, 5, 6, 7, 8, 28, 29, 30, 31, 32]);
});

/** Whether $stderr holds one of GDK's wordings of a critical (GTK 4.18 and 4.24 word several differently). */
function gdkCriticalLogged(string $stderr, array $criticals): bool
{
    foreach ($criticals as $critical) {
        if (str_contains($stderr, $critical)) {
            return true;
        }
    }

    return false;
}

it('hands GDK bytes that do not hold the image, which it answers with a critical and null', function (string $call, array $criticals): void {
    $run = gtkChild('return '.$call.';');

    expect($run['survived'])->toBeTrue()
        ->and($run['result'])->toBeNull()
        ->and(gdkCriticalLogged($run['stderr'], $criticals))->toBeTrue();
})->with([
    'too few bytes' => ["GdkMemoryTexture::new(3, 2, GdkMemoryFormat::R8G8B8A8, GBytes::new(str_repeat('x', 23), 23), 12)", [
        "gdk_memory_texture_new: assertion 'g_bytes_get_size (bytes) >= gdk_memory_format_min_buffer_size (format, stride, width, height)' failed",
        "gdk_memory_texture_new: assertion 'g_bytes_get_size (bytes) >= layout.size' failed",
    ]],
    'a stride shorter than a row' => ["GdkMemoryTexture::new(3, 2, GdkMemoryFormat::R8G8B8A8, GBytes::new(str_repeat('x', 24), 24), 11)", [
        "gdk_memory_texture_new: assertion 'stride >= width * gdk_memory_format_bytes_per_pixel (format)' failed",
        "assertion 'stride for plane 0 is 11 bytes, but image width 3 requires a stride of 12 bytes' failed",
    ]],
    'three-byte pixels' => ["GdkMemoryTexture::new(3, 1, GdkMemoryFormat::B8G8R8, GBytes::new(str_repeat('x', 8), 8), 9)", [
        "gdk_memory_texture_new: assertion 'g_bytes_get_size (bytes) >= gdk_memory_format_min_buffer_size (format, stride, width, height)' failed",
        "gdk_memory_texture_new: assertion 'g_bytes_get_size (bytes) >= layout.size' failed",
    ]],
    'no width' => ["GdkMemoryTexture::new(0, 2, GdkMemoryFormat::R8G8B8A8, GBytes::new('', 0), 0)", [
        "gdk_memory_texture_new: assertion 'width > 0' failed",
        "assertion 'image size 0x2 is invalid' failed",
    ]],
    'no height' => ["GdkMemoryTexture::new(2, 0, GdkMemoryFormat::R8G8B8A8, GBytes::new('', 0), 8)", [
        "gdk_memory_texture_new: assertion 'height > 0' failed",
        "assertion 'image size 2x0 is invalid' failed",
    ]],
]);

it('refuses what has no native form: sizes outside int, a negative stride', function (Closure $new, string $message): void {
    gtk_init();

    expect($new)->toThrow(ValueError::class, $message);
})->with([
    'a width past int' => [fn () => GdkMemoryTexture::new(2 ** 31, 1, GdkMemoryFormat::R8G8B8A8, gbytes(''), 0), 'Argument #1 ($width) must be between -2147483648 and 2147483647'],
    'a negative stride' => [fn () => GdkMemoryTexture::new(1, 1, GdkMemoryFormat::R8G8B8A8, gbytes('xxxx'), -1), 'Argument #5 ($stride) must be between 0 and '.PHP_INT_MAX],
]);

it('shows a texture in a picture, lets it shrink, and clears it', function (): void {
    gtk_init();
    $picture = GtkPicture::new();
    $texture = GdkMemoryTexture::new(3, 2, GdkMemoryFormat::R8G8B8X8, gbytes(str_repeat("\xff\x80\x00\x00", 6)), 12);

    $picture->setPaintable($texture);
    expect($picture->getPaintable())->toBe($texture)
        ->and($picture->getCanShrink())->toBeTrue();

    $picture->setCanShrink(false);
    expect($picture->getCanShrink())->toBeFalse();

    $picture->setPaintable(null);
    expect($picture->getPaintable())->toBeNull()
        ->and(fn () => $picture->setPaintable(GtkBox::new(GtkOrientation::VERTICAL, 0)))->toThrow(TypeError::class, 'must be a GdkPaintable, GtkBox given')
        ->and($picture->getScaleFactor())->toBeGreaterThanOrEqual(1);
});

it('builds a memory texture from an address', function () {
    $buffer = new FbBuffer(new FbFormat(FB_LAYOUT_RGBA8888, channelOrder: FB_CHANNELS_RGBA), 4, 2);

    $texture = GdkMemoryTexture::new(4, 2, GdkMemoryFormat::R8G8B8X8, GBytes::new($buffer->pointer(), $buffer->size()), 16);

    expect([$texture->getWidth(), $texture->getHeight()])->toBe([4, 2]);
})->skip(! class_exists(FbBuffer::class), 'needs ext-fb for a native address');

it('builds an updated texture from an address and a damage region', function () {
    $buffer = new FbBuffer(new FbFormat(FB_LAYOUT_RGBA8888, channelOrder: FB_CHANNELS_RGBA), 4, 2);
    $first = GdkMemoryTexture::new(4, 2, GdkMemoryFormat::R8G8B8X8, GBytes::new($buffer->pointer(), $buffer->size()), 16);
    $buffer->set(1, 1, 0xFF0000FF);

    $builder = GdkMemoryTextureBuilder::new();
    $builder->setBytes(GBytes::new($buffer->pointer(), $buffer->size()));
    $builder->setWidth(4);
    $builder->setHeight(2);
    $builder->setFormat(GdkMemoryFormat::R8G8B8X8);
    $builder->setStride(16);
    $builder->setUpdateTexture($first);
    $builder->setUpdateRegion(CairoRegion::createRectangle(new GdkRectangle(1, 1, 1, 1)));
    $next = $builder->build();

    expect($next)->toBeInstanceOf(GdkTexture::class)
        ->and([$next->getWidth(), $next->getHeight()])->toBe([4, 2]);
})->skip(! class_exists(FbBuffer::class) || gtk_get_minor_version() < 16, 'needs ext-fb and GTK 4.16');

it('builds an updated texture from a damage region, its setters returning nothing as natively', function () {
    gtk_init();
    $first = GdkMemoryTexture::new(4, 2, GdkMemoryFormat::R8G8B8X8, gbytes(str_repeat("\x00", 32)), 16);
    $region = CairoRegion::create();
    $region->unionRectangle(new GdkRectangle(1, 1, 1, 1));
    $region->unionRectangle(new GdkRectangle(3, 0, 1, 1));

    $builder = GdkMemoryTextureBuilder::new();
    $returns = [
        $builder->setBytes(gbytes(str_repeat("\xff", 32))),
        $builder->setWidth(4),
        $builder->setHeight(2),
        $builder->setFormat(GdkMemoryFormat::R8G8B8X8),
        $builder->setStride(16),
        $builder->setUpdateTexture($first),
        $builder->setUpdateRegion($region),
    ];
    $next = $builder->build();
    $builder->setUpdateRegion(null);
    $builder->setUpdateTexture(null);

    expect($returns)->toBe([null, null, null, null, null, null, null])
        ->and($next)->toBeInstanceOf(GdkTexture::class)
        ->and([$next->getWidth(), $next->getHeight()])->toBe([4, 2])
        ->and($builder->build())->toBeInstanceOf(GdkTexture::class)
        ->and(fn () => $builder->setUpdateRegion([[1, 1, 1, 1]]))->toThrow(TypeError::class);
})->skip(gtk_get_minor_version() < 16, 'needs GTK 4.16');

it('hands the builder a negative width, which GDK stores and build() answers with a critical and null', function () {
    $run = gtkChild(<<<'PHP'
        $builder = GdkMemoryTextureBuilder::new();
        $builder->setWidth(-1);
        $builder->setHeight(1);
        $builder->setFormat(GdkMemoryFormat::R8G8B8A8);
        $builder->setStride(4);
        $builder->setBytes(GBytes::new('xxxx', 4));

        return $builder->build();
    PHP);

    expect($run['survived'])->toBeTrue()
        ->and($run['result'])->toBeNull()
        ->and(gdkCriticalLogged($run['stderr'], [
            "gdk_memory_texture_builder_build: assertion 'self->width > 0' failed",
            "gdk_memory_texture_builder_build: assertion 'stride for plane 0 is 4 bytes, but image width",
        ]))->toBeTrue();
})->skip(gtk_get_minor_version() < 16, 'needs GTK 4.16');

it('refuses a builder width or height with no int form, which the conversion would truncate', function () {
    gtk_init();
    $builder = GdkMemoryTextureBuilder::new();

    expect(fn () => $builder->setWidth(2 ** 31))->toThrow(ValueError::class, 'GdkMemoryTextureBuilder::setWidth(): Argument #1 ($width) must be between -2147483648 and 2147483647')
        ->and(fn () => $builder->setHeight(-(2 ** 31) - 1))->toThrow(ValueError::class, 'GdkMemoryTextureBuilder::setHeight(): Argument #1 ($height) must be between -2147483648 and 2147483647');
})->skip(gtk_get_minor_version() < 16, 'needs GTK 4.16');

it('answers null from a builder with nothing set', function () {
    expect(GdkMemoryTextureBuilder::new()->build())->toBeNull();
})->skip(gtk_get_minor_version() < 16, 'needs GTK 4.16');

/** A 3x2 RGBA texture. */
function paintableTexture(): GdkTexture
{
    gtk_init();

    return GdkMemoryTexture::new(3, 2, GdkMemoryFormat::R8G8B8A8, gbytes(str_repeat("\xff\x80\x00\xff", 6)), 12);
}

it('declares GdkPaintable on textures', function (): void {
    expect(paintableTexture())->toBeInstanceOf(GdkPaintable::class)
        ->and((new ReflectionClass(GdkMemoryTexture::class))->isAbstract())->toBeFalse();
});

it('reads a paintable\'s current image with gdk_paintable_get_current_image', function (): void {
    $texture = paintableTexture();

    expect($texture->getCurrentImage())->toBe($texture);
});

it('reads a paintable\'s flags with gdk_paintable_get_flags', function (): void {
    // A texture is GDK_PAINTABLE_STATIC_SIZE | GDK_PAINTABLE_STATIC_CONTENTS.
    expect(paintableTexture()->getFlags())->toBe(3);
});

it('reads a paintable\'s intrinsic width with gdk_paintable_get_intrinsic_width', function (): void {
    expect(paintableTexture()->getIntrinsicWidth())->toBe(3);
});

it('reads a paintable\'s intrinsic height with gdk_paintable_get_intrinsic_height', function (): void {
    expect(paintableTexture()->getIntrinsicHeight())->toBe(2);
});

it('reads a paintable\'s intrinsic aspect ratio with gdk_paintable_get_intrinsic_aspect_ratio', function (): void {
    expect(paintableTexture()->getIntrinsicAspectRatio())->toBe(1.5);
});

it('computes a paintable\'s concrete size into its by-reference out-parameters', function (): void {
    $texture = paintableTexture();
    $width = null;
    $height = null;

    $texture->computeConcreteSize(0.0, 0.0, 10.0, 10.0, $width, $height);
    $intrinsic = [$width, $height];
    $texture->computeConcreteSize(6.0, 0.0, 10.0, 10.0, $width, $height);

    expect($intrinsic)->toBe([3.0, 2.0])
        ->and([$width, $height])->toBe([6.0, 4.0]);
});

it('passes GDK\'s critical through for invalidating a static texture\'s contents or size', function (): void {
    $run = gtkChild(<<<'PHP'
        $texture = GdkMemoryTexture::new(1, 1, GdkMemoryFormat::R8G8B8A8, GBytes::new("\0\0\0\0", 4), 4);
        $texture->invalidateContents();
        $texture->invalidateSize();

        return 'returned';
    PHP);

    expect($run['result'])->toBe('returned')
        ->and($run['stderr'])->toContain('gdk_paintable_invalidate_contents')
        ->and($run['stderr'])->toContain('gdk_paintable_invalidate_size');
});

it('copies bytes from an address with g_bytes_new', function (): void {
    gtk_init();
    $label = GtkLabel::new('source');
    $bytes = GBytes::new($label->pointer(), 16);

    expect($bytes)->toBeInstanceOf(GBytes::class)
        ->and($bytes->getSize())->toBe(16)
        ->and(GBytes::new(0, 0)->getSize())->toBe(0);
});

it('answers GLib\'s null and critical for a null address with a non-zero size', function (): void {
    $run = gtkChild('return GBytes::new(0, 4);', init: false);

    expect($run['survived'])->toBeTrue()
        ->and($run['result'])->toBeNull()
        ->and($run['stderr'])->toContain("g_bytes_new: assertion 'data != NULL || size == 0' failed");
});

it('reads a GBytes\' size with g_bytes_get_size', function (): void {
    gtk_init();

    expect(GBytes::new(GtkLabel::new('x')->pointer(), 24)->getSize())->toBe(24);
});

it('reads a GBytes\' data with g_bytes_get_data', function (): void {
    gtk_init();
    $label = GtkLabel::new('x');
    $bytes = GBytes::new($label->pointer(), 8);

    expect($bytes->getData())->toBeString()
        ->and(strlen($bytes->getData()))->toBe(8)
        ->and($bytes->getData())->toBe(GBytes::new($label->pointer(), 8)->getData())
        ->and(GBytes::new(0, 0)->getData())->toBe('');
});

it('copies a string\'s bytes with g_bytes_new, up to its length', function (): void {
    $bytes = GBytes::new('abcdef', 4);

    expect($bytes->getData())->toBe('abcd')
        ->and(GBytes::new('abc', 3)->getData())->toBe('abc')
        ->and(GBytes::new('', 0)->getSize())->toBe(0)
        ->and(fn () => GBytes::new('abc', 4))->toThrow(ValueError::class, 'GBytes::new(): Argument #2 ($size) must not exceed the 3 bytes of $data')
        ->and(fn () => GBytes::new('abc', -1))->toThrow(ValueError::class, 'must be between 0 and '.PHP_INT_MAX);
});

it('refuses a region index outside its rectangles, which cairo reads past', function (): void {
    $region = CairoRegion::createRectangle(new GdkRectangle(1, 2, 3, 4));

    expect(fn () => $region->getRectangle(1))->toThrow(ValueError::class, "CairoRegion::getRectangle(): Argument #1 (\$nth) must be the index of one of the region's 1 rectangles")
        ->and(fn () => $region->getRectangle(-1))->toThrow(ValueError::class, "must be the index of one of the region's 1 rectangles")
        ->and(fn () => CairoRegion::create()->getRectangle(0))->toThrow(ValueError::class, "the region's 0 rectangles");
});

it('creates an empty region with cairo_region_create', function (): void {
    $region = CairoRegion::create();

    expect($region)->toBeInstanceOf(CairoRegion::class)
        ->and($region)->not->toBe(CairoRegion::create());
});

it('counts a region\'s rectangles with cairo_region_num_rectangles', function (): void {
    expect(CairoRegion::create()->numRectangles())->toBe(0);
});

it('builds a GdkRectangle from all four fields', function (): void {
    $rect = new GdkRectangle(1, 2, 30, 40);

    expect([$rect->x, $rect->y, $rect->width, $rect->height])->toBe([1, 2, 30, 40])
        ->and(fn () => $rect->x = 'a')->toThrow(TypeError::class);
});

it('creates a one-rectangle region with cairo_region_create_rectangle', function (): void {
    $region = CairoRegion::createRectangle(new GdkRectangle(1, 2, 3, 4));

    expect($region->numRectangles())->toBe(1);
});

it('reads a region\'s rectangle with cairo_region_get_rectangle', function (): void {
    $rect = CairoRegion::createRectangle(new GdkRectangle(1, 2, 3, 4))->getRectangle(0);

    expect($rect)->toBeInstanceOf(GdkRectangle::class)
        ->and([$rect->x, $rect->y, $rect->width, $rect->height])->toBe([1, 2, 3, 4]);
});

it('unions a rectangle into a region with cairo_region_union_rectangle, answering the cairo_status_t', function (): void {
    $region = CairoRegion::create();

    $status = $region->unionRectangle(new GdkRectangle(0, 0, 2, 2));
    $region->unionRectangle(new GdkRectangle(10, 10, 2, 2));
    $second = $region->getRectangle(1);

    expect($status)->toBe(0)
        ->and($region->numRectangles())->toBe(2)
        ->and([$second->x, $second->y, $second->width, $second->height])->toBe([10, 10, 2, 2]);
});
