<?php

declare(strict_types=1);

it('makes a texture from bytes', function (): void {
    gtk_init();
    $texture = GdkMemoryTexture::new(3, 2, GdkMemoryFormat::R8G8B8A8, str_repeat("\xff\x80\x00\xff", 6), 12);

    expect($texture)->toBeInstanceOf(GdkTexture::class)
        ->and([$texture->getWidth(), $texture->getHeight()])->toBe([3, 2])
        ->and(GdkMemoryTexture::new(2, 2, GdkMemoryFormat::R8G8B8, str_repeat('x', 14), 8)->getWidth())->toBe(2)   // a padded stride; the last row needs no padding
        ->and(GdkMemoryTexture::new(1, 1, GdkMemoryFormat::R8G8B8X8, "\x01\x02\x03\x00", 4)->getHeight())->toBe(1);
});

it('carries GDK\'s values for the memory formats', function (): void {
    expect(array_map(fn (GdkMemoryFormat $f): int => $f->value, GdkMemoryFormat::cases()))->toBe([0, 1, 2, 3, 4, 5, 6, 7, 8, 28, 29, 30, 31, 32]);
});

it('refuses bytes that do not hold the image', function (Closure $new, string $message): void {
    gtk_init();

    expect($new)->toThrow(ValueError::class, $message);
})->with([
    'too few bytes' => [fn () => GdkMemoryTexture::new(3, 2, GdkMemoryFormat::R8G8B8A8, str_repeat('x', 23), 12), 'must hold every row (24 bytes), 23 given'],
    'a stride shorter than a row' => [fn () => GdkMemoryTexture::new(3, 2, GdkMemoryFormat::R8G8B8A8, str_repeat('x', 24), 11), 'must hold a row: at least 12 bytes'],
    'three-byte pixels' => [fn () => GdkMemoryTexture::new(3, 1, GdkMemoryFormat::B8G8R8, str_repeat('x', 8), 9), 'must hold every row (9 bytes), 8 given'],
    'no width' => [fn () => GdkMemoryTexture::new(0, 2, GdkMemoryFormat::R8G8B8A8, '', 0), 'must be between 1 and'],
    'no height' => [fn () => GdkMemoryTexture::new(2, 0, GdkMemoryFormat::R8G8B8A8, '', 8), 'must be between 1 and'],
]);

it('shows a texture in a picture, lets it shrink, and clears it', function (): void {
    gtk_init();
    $picture = GtkPicture::new();
    $texture = GdkMemoryTexture::new(3, 2, GdkMemoryFormat::R8G8B8X8, str_repeat("\xff\x80\x00\x00", 6), 12);

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

    $texture = GdkMemoryTexture::new(4, 2, GdkMemoryFormat::R8G8B8X8, $buffer->pointer(), 16);

    expect([$texture->getWidth(), $texture->getHeight()])->toBe([4, 2]);
})->skip(! class_exists(FbBuffer::class), 'needs ext-fb for a native address');

it('builds an updated texture from an address and a damage region', function () {
    $buffer = new FbBuffer(new FbFormat(FB_LAYOUT_RGBA8888, channelOrder: FB_CHANNELS_RGBA), 4, 2);
    $first = GdkMemoryTexture::new(4, 2, GdkMemoryFormat::R8G8B8X8, $buffer->pointer(), 16);
    $buffer->set(1, 1, 0xFF0000FF);

    $next = GdkMemoryTextureBuilder::new()
        ->setBytes($buffer->pointer(), $buffer->size())
        ->setWidth(4)->setHeight(2)->setFormat(GdkMemoryFormat::R8G8B8X8)->setStride(16)
        ->setUpdateTexture($first)
        ->setUpdateRegion([[1, 1, 1, 1]])
        ->build();

    expect($next)->toBeInstanceOf(GdkTexture::class)
        ->and([$next->getWidth(), $next->getHeight()])->toBe([4, 2]);
})->skip(! class_exists(FbBuffer::class) || gtk_get_minor_version() < 16, 'needs ext-fb and GTK 4.16');

it('refuses a null address and an address without a length', function () {
    expect(fn () => GdkMemoryTexture::new(4, 2, GdkMemoryFormat::R8G8B8X8, 0, 16))->toThrow(ValueError::class, 'must not be a null address')
        ->and(fn () => GdkMemoryTextureBuilder::new()->setBytes(4096))->toThrow(ValueError::class, 'must be the byte count');
});

it('refuses an update region that is not a list of four integers', function () {
    GdkMemoryTextureBuilder::new()->setUpdateRegion([[1, 1, 1]]);
})->throws(ValueError::class, 'each rect is [x, y, width, height]');

it('answers null from a builder with nothing set', function () {
    expect(GdkMemoryTextureBuilder::new()->build())->toBeNull();
})->skip(gtk_get_minor_version() < 16, 'needs GTK 4.16');
