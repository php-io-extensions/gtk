<?php

declare(strict_types=1);

/*
 * The binding only: the class, its setters, and build() refusing what it cannot import. A real
 * import of an exported image is venusian-gtk's canvas test.
 */

beforeEach(function (): void {
    if (PHP_OS_FAMILY !== 'Linux' || ! class_exists(GdkDmabufTextureBuilder::class)) {
        $this->markTestSkipped('GdkDmabufTextureBuilder is Linux only, GTK 4.14 and newer');
    }
    testApplication();
});

it('answers the builder from every setter', function (): void {
    $builder = GdkDmabufTextureBuilder::new();

    expect($builder->setDisplay(GdkDisplay::getDefault()))->toBe($builder)
        ->and($builder->setWidth(32))->toBe($builder)
        ->and($builder->setHeight(16))->toBe($builder)
        ->and($builder->setFourcc(0x34324241))->toBe($builder)
        ->and($builder->setModifier(0))->toBe($builder)
        ->and($builder->setPremultiplied(false))->toBe($builder)
        ->and($builder->setNPlanes(1))->toBe($builder)
        ->and($builder->setFd(0, -1))->toBe($builder)
        ->and($builder->setStride(0, 128))->toBe($builder)
        ->and($builder->setOffset(0, 0))->toBe($builder)
        ->and($builder->setUpdateTexture(null))->toBe($builder)
        ->and($builder->setUpdateRegion([[0, 0, 4, 4]]))->toBe($builder)
        ->and($builder->setUpdateRegion(null))->toBe($builder);
});

it('refuses a plane past the four GDK keeps', function (): void {
    GdkDmabufTextureBuilder::new()->setFd(4, 3);
})->throws(ValueError::class, 'must be a plane between 0 and 3');

it('refuses to build over no descriptor', function (): void {
    $builder = GdkDmabufTextureBuilder::new()
        ->setDisplay(GdkDisplay::getDefault())
        ->setWidth(32)->setHeight(16)
        ->setFourcc(0x34324241)->setModifier(0)
        ->setNPlanes(1)->setFd(0, -1)->setStride(0, 128)->setOffset(0, 0);

    $builder->build();
})->throws(GtkException::class, 'gdk_dmabuf_texture_builder_build() made no texture');

it('lets go of a destroy callback when the import makes no texture', function (): void {
    $called = false;
    $builder = GdkDmabufTextureBuilder::new()->setDisplay(GdkDisplay::getDefault())->setWidth(32)->setHeight(16)
        ->setFourcc(0x34324241)->setModifier(0)->setNPlanes(1)->setFd(0, -1)->setStride(0, 128)->setOffset(0, 0);

    expect(fn () => $builder->build(function () use (&$called): void {
        $called = true;
    }))->toThrow(GtkException::class)
        ->and($called)->toBeFalse()
        ->and(fn () => $builder->build('no such function'))->toThrow(TypeError::class, 'must be a valid callback or null');
});
