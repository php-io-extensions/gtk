<?php

declare(strict_types=1);

/*
 * The binding only: the class, its setters, and build() answering null for what it cannot import.
 * A real import needs an exported image, which these tests do not make.
 */

beforeEach(function (): void {
    if (PHP_OS_FAMILY !== 'Linux' || ! class_exists(GdkDmabufTextureBuilder::class)) {
        $this->markTestSkipped('GdkDmabufTextureBuilder is Linux only, GTK 4.14 and newer');
    }
    testApplication();
});

/** A builder over one linear ABGR8888 plane of 32x16, with no descriptor. */
function dmabufBuilderWithoutFd(): GdkDmabufTextureBuilder
{
    $builder = GdkDmabufTextureBuilder::new();
    $builder->setDisplay(GdkDisplay::getDefault());
    $builder->setWidth(32);
    $builder->setHeight(16);
    $builder->setFourcc(0x34324241);
    $builder->setModifier(0);
    $builder->setNPlanes(1);
    $builder->setFd(0, -1);
    $builder->setStride(0, 128);
    $builder->setOffset(0, 0);

    return $builder;
}

it('returns nothing from every setter, as the native setters do', function (): void {
    $builder = GdkDmabufTextureBuilder::new();

    expect([
        $builder->setDisplay(GdkDisplay::getDefault()),
        $builder->setWidth(32),
        $builder->setHeight(16),
        $builder->setFourcc(0x34324241),
        $builder->setModifier(0),
        $builder->setPremultiplied(false),
        $builder->setNPlanes(1),
        $builder->setFd(0, -1),
        $builder->setStride(0, 128),
        $builder->setOffset(0, 0),
        $builder->setUpdateTexture(null),
        $builder->setUpdateRegion(CairoRegion::createRectangle(new GdkRectangle(0, 0, 4, 4))),
        $builder->setUpdateRegion(null),
    ])->toBe(array_fill(0, 13, null));
});

it('refuses a plane with no unsigned int form', function (): void {
    GdkDmabufTextureBuilder::new()->setFd(-1, 3);
})->throws(ValueError::class, 'must be between 0 and 4294967295');

it('hands GDK a plane past the four it keeps, which it answers with a critical', function (): void {
    $run = gtkChild(<<<'PHP'
        GdkDmabufTextureBuilder::new()->setFd(4, 3);

        return 'returned';
    PHP);

    expect($run['result'])->toBe('returned')
        ->and($run['stderr'])->toContain('gdk_dmabuf_texture_builder_set_fd: assertion');
});

it('builds over no descriptor as GDK does: null', function (): void {
    expect(dmabufBuilderWithoutFd()->build(null))->toBeNull();
});

it('lets go of a destroy callback when the import makes no texture', function (): void {
    $called = false;
    $builder = dmabufBuilderWithoutFd();

    expect($builder->build(function () use (&$called): void {
        $called = true;
    }))->toBeNull()
        ->and($called)->toBeFalse()
        ->and(fn () => $builder->build('no such function'))->toThrow(TypeError::class, 'must be a valid callback or null');
});
