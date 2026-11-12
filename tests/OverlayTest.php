<?php

declare(strict_types=1);

beforeEach(fn () => testApplication());

it('stacks overlay widgets over a main child', function (): void {
    $overlay = GtkOverlay::new();
    $picture = GtkPicture::new();
    $badge = GtkLabel::new('NEW');

    $overlay->setChild($picture);
    $overlay->addOverlay($badge);

    expect($overlay)->toBeInstanceOf(GtkWidget::class)
        ->and($overlay->getChild())->toBe($picture)
        ->and($badge->getParent())->toBe($overlay);

    $overlay->removeOverlay($badge);
    $overlay->setChild(null);

    expect($badge->getParent())->toBeNull()
        ->and($overlay->getChild())->toBeNull();
});

it('shows a file in an image at the pixel size it is given', function (): void {
    $image = GtkImage::newFromIconName(null);
    $image->setFromFile(__DIR__.'/fixtures/no-such-image.png');
    $image->setPixelSize(22);

    expect($image->getPixelSize())->toBe(22)
        ->and($image->getIconName())->toBe('image-missing');

    $image->setFromFile(null);
    expect($image->getPixelSize())->toBe(22);
});

it('keeps the line limit a wrapping, ellipsizing label is given', function (): void {
    $label = GtkLabel::new('A long explanation that wraps and ends in an ellipsis after its last line.');
    $label->setWrap(true);
    $label->setEllipsize(PangoEllipsizeMode::END);

    expect($label->getLines())->toBe(-1);
    $label->setLines(3);
    expect($label->getLines())->toBe(3);
});
