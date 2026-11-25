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

it('keeps the measure and clip flags of an overlay child', function (): void {
    $overlay = GtkOverlay::new();
    $badge = GtkLabel::new('NEW');
    $overlay->addOverlay($badge);

    expect($overlay->getMeasureOverlay($badge))->toBeFalse()
        ->and($overlay->getClipOverlay($badge))->toBeFalse();

    $overlay->setMeasureOverlay($badge, true);
    $overlay->setClipOverlay($badge, true);
    expect($overlay->getMeasureOverlay($badge))->toBeTrue()
        ->and($overlay->getClipOverlay($badge))->toBeTrue();

    $overlay->setMeasureOverlay($badge, false);
    $overlay->setClipOverlay($badge, false);
    expect($overlay->getMeasureOverlay($badge))->toBeFalse()
        ->and($overlay->getClipOverlay($badge))->toBeFalse();
});

it('counts an overlay child in its size only when it is measured', function (): void {
    $overlay = GtkOverlay::new();
    $overlay->setChild(GtkBox::new(GtkOrientation::VERTICAL, 0));
    $badge = GtkBox::new(GtkOrientation::VERTICAL, 0);
    $badge->setSizeRequest(200, 100);
    $overlay->addOverlay($badge);

    expect($overlay->measure(GtkOrientation::HORIZONTAL, -1)['natural'])->toBe(0)
        ->and($overlay->measure(GtkOrientation::VERTICAL, -1)['natural'])->toBe(0);

    $overlay->setMeasureOverlay($badge, true);
    expect($overlay->measure(GtkOrientation::HORIZONTAL, -1)['natural'])->toBeGreaterThanOrEqual(200)
        ->and($overlay->measure(GtkOrientation::VERTICAL, -1)['natural'])->toBeGreaterThanOrEqual(100);
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
