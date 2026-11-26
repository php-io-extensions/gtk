<?php

declare(strict_types=1);

beforeEach(fn () => testApplication());

/** A square PNG of $side pixels in the temp dir. */
function squarePng(int $side): string
{
    $file = sys_get_temp_dir()."/phpgtk-square-{$side}.png";
    $image = imagecreatetruecolor($side, $side);
    imagepng($image, $file);

    return $file;
}

/**
 * A box holding a picture of $file, its layout a constraint layout: the picture fills the box,
 * and its size is a guide's whose natural size is the picture's own and whose maximum is $max.
 *
 * @return array{GtkBox, GtkPicture}
 */
function cappedPicture(string $file, int $max): array
{
    $picture = GtkPicture::newForFilename($file);
    $box = GtkBox::new(GtkOrientation::HORIZONTAL, 0);
    $box->append($picture);

    $layout = GtkConstraintLayout::new();
    $box->setLayoutManager($layout);
    foreach ([GtkConstraintAttribute::LEFT, GtkConstraintAttribute::TOP, GtkConstraintAttribute::RIGHT, GtkConstraintAttribute::BOTTOM] as $edge) {
        $layout->addConstraint(GtkConstraint::new($picture, $edge, GtkConstraintRelation::EQ, null, $edge, 1.0, 0.0, GtkConstraintStrength::REQUIRED->value));
    }

    $width = $picture->measure(GtkOrientation::HORIZONTAL, -1)['natural'];
    $height = $picture->measure(GtkOrientation::VERTICAL, -1)['natural'];
    $guide = GtkConstraintGuide::new();
    $guide->setNatSize($width, $height);
    $guide->setMaxSize(min($max, $width), min($max, $height));
    $layout->addGuide($guide);
    foreach ([GtkConstraintAttribute::WIDTH, GtkConstraintAttribute::HEIGHT] as $side) {
        $layout->addConstraint(GtkConstraint::new($picture, $side, GtkConstraintRelation::EQ, $guide, $side, 1.0, 0.0, GtkConstraintStrength::REQUIRED->value));
    }

    return [$box, $picture];
}

it('gives a widget a layout manager, and back the one it had', function (): void {
    $box = GtkBox::new(GtkOrientation::HORIZONTAL, 0);
    $own = $box->getLayoutManager();
    expect($own)->toBeInstanceOf(GtkLayoutManager::class);

    $layout = GtkConstraintLayout::new();
    $box->setLayoutManager($layout);
    expect($box->getLayoutManager())->toBe($layout);

    $box->setLayoutManager($own);
    expect($box->getLayoutManager())->toBe($own);

    $box->setLayoutManager(null);
    expect($box->getLayoutManager())->toBeNull();
});

it('makes widgets and guides constraint targets', function (): void {
    expect(GtkBox::new(GtkOrientation::HORIZONTAL, 0))->toBeInstanceOf(GtkConstraintTarget::class)
        ->and(GtkConstraintGuide::new())->toBeInstanceOf(GtkConstraintTarget::class)
        ->and(GtkConstraint::new(null, GtkConstraintAttribute::WIDTH, GtkConstraintRelation::GE, null, GtkConstraintAttribute::NONE, 1.0, 10.0, GtkConstraintStrength::WEAK->value))
        ->toBeInstanceOf(GtkConstraint::class);
});

it('measures nothing until the constrained widget is in a window', function (): void {
    // GTK solves a constraint layout only under a root (observed with GTK 4.24.1).
    [$box] = cappedPicture(squarePng(84), 22);
    expect($box->measure(GtkOrientation::HORIZONTAL, -1)['natural'])->toBe(0);

    $window = GtkWindow::new();
    $window->setChild($box);
    expect($box->measure(GtkOrientation::HORIZONTAL, -1)['natural'])->toBe(22);

    $window->destroy();
});

it('caps a picture at the guide maximum below its own size', function (): void {
    [$box] = cappedPicture(squarePng(84), 22);
    $window = GtkWindow::new();
    $window->setChild($box);

    expect($box->measure(GtkOrientation::HORIZONTAL, -1)['natural'])->toBe(22)
        ->and($box->measure(GtkOrientation::VERTICAL, -1)['natural'])->toBe(22);

    $window->destroy();
});

it('keeps a picture at its own size under a larger maximum', function (): void {
    [$box] = cappedPicture(squarePng(84), 96);
    $window = GtkWindow::new();
    $window->setChild($box);

    expect($box->measure(GtkOrientation::HORIZONTAL, -1)['natural'])->toBe(84)
        ->and($box->measure(GtkOrientation::VERTICAL, -1)['natural'])->toBe(84);

    $window->destroy();
});

it('lays the capped picture out at its cap in a window', function (): void {
    [$box, $picture] = cappedPicture(squarePng(84), 22);
    $row = GtkBox::new(GtkOrientation::HORIZONTAL, 10);
    $row->setHalign(GtkAlign::START);
    $row->setValign(GtkAlign::START);
    $row->append($box);
    $row->append(GtkLabel::new('Time Zone'));
    $window = GtkWindow::new();
    $window->setChild($row);
    $window->present();

    expect(iterateUntil(fn () => $picture->getWidth() > 0))->toBeTrue()
        ->and($picture->getWidth())->toBe(22)
        ->and($picture->getHeight())->toBe(22)
        ->and($box->getWidth())->toBe(22);

    $window->destroy();
});
