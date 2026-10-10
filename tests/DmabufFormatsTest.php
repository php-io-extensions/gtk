<?php

declare(strict_types=1);

/*
 * The formats a display imports as dmabuf textures, and the display a widget is on.
 */

beforeEach(function (): void {
    testApplication();
});

it('answers the display a widget is on', function (): void {
    expect(GtkLabel::new('x')->getDisplay())->toBe(GdkDisplay::getDefault());
});

it('waits for the windowing system to handle every request sent', function (): void {
    $window = GtkWindow::new();
    $window->present();
    GdkDisplay::getDefault()->sync();

    expect($window->getRealized())->toBeTrue();
    $window->destroy();
});

it('lists the dmabuf formats the display imports, and answers whether it imports one', function (): void {
    if (! method_exists(GdkDisplay::class, 'getDmabufFormats')) {
        $this->markTestSkipped('GdkDisplay::getDmabufFormats() needs GTK 4.14 headers');
    }
    $formats = GdkDisplay::getDefault()->getDmabufFormats();
    $count = $formats->getNFormats();

    expect($formats)->toBeInstanceOf(GdkDmabufFormats::class)
        ->and($formats)->toBe(GdkDisplay::getDefault()->getDmabufFormats());
    if (PHP_OS_FAMILY !== 'Linux') {
        expect($count)->toBe(0)
            ->and($formats->contains(0x34324241, 0))->toBeFalse();

        return;
    }
    [$fourcc, $modifier] = $formats->getFormat(0);

    expect($count)->toBeGreaterThan(0)
        ->and($formats->contains($fourcc, $modifier))->toBeTrue()
        ->and(fn () => $formats->getFormat($count))->toThrow(ValueError::class, 'must be between 0 and '.($count - 1));
});

it('makes no GdkDmabufFormats from PHP', function (): void {
    expect(fn () => new GdkDmabufFormats())->toThrow(Error::class);
})->skip(fn () => ! class_exists(GdkDmabufFormats::class), 'GdkDmabufFormats needs GTK 4.14 headers');
