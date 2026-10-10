<?php

declare(strict_types=1);

/*
 * GtkPopover and GtkPopoverMenu: a menu parented to a widget, pointing at a point in it,
 * popped up and down. GtkWidget setParent/unparent attach it; a gesture claims its press.
 */

beforeEach(function (): void {
    testApplication();
});

it('pops a menu up over a widget at a point, and down, reporting closed', function (): void {
    $window = GtkWindow::new();
    $box = GtkBox::new(GtkOrientation::VERTICAL, 0);
    $box->setSizeRequest(200, 100);
    $window->setChild($box);
    $model = GMenu::new();
    $model->append('Download', 'ctx.download');
    $menu = GtkPopoverMenu::newFromModel($model);
    $closed = 0;
    g_signal_connect($menu, 'closed', function () use (&$closed): void {
        $closed++;
    });

    $menu->setParent($box);
    $menu->setHasArrow(false);
    $menu->setPointingTo(10, 20, 1, 1);
    $window->present();
    $menu->popup();
    $shown = iterateUntil(fn (): bool => $menu->getMapped(), 3000);
    $menu->popdown();
    iterateUntil(fn (): bool => $closed > 0, 3000);
    $pointing = $menu->getPointingTo();
    $menu->unparent();

    expect($menu)->toBeInstanceOf(GtkPopover::class)
        ->and($menu->getMenuModel())->toBe($model)
        ->and($menu->getHasArrow())->toBeFalse()
        ->and($pointing)->toBe([10, 20, 1, 1])
        ->and($shown)->toBeTrue()
        ->and($closed)->toBe(1)
        ->and($menu->getParent())->toBeNull();
    $window->destroy();
});

it('points nowhere until told, answers only with a parent, and refuses a negative size', function (): void {
    $box = GtkBox::new(GtkOrientation::VERTICAL, 0);
    $menu = GtkPopoverMenu::newFromModel(null);
    $orphan = fn () => $menu->getPointingTo();
    $refused = false;
    try {
        $orphan();
    } catch (ValueError) {
        $refused = true;
    }
    $menu->setParent($box);

    expect($refused)->toBeTrue()
        ->and($menu->getPointingTo())->toBeNull()
        ->and(fn () => $menu->setParent($box))->toThrow(ValueError::class, 'already has a parent')
        ->and(fn () => $menu->setPointingTo(0, 0, -1, 1))->toThrow(ValueError::class);
    $menu->unparent();
});

it('claims a gesture\'s sequences, and names the sequence states at their C values', function (): void {
    $click = GtkGestureClick::new();

    expect(array_map(fn (GtkEventSequenceState $s): int => $s->value, GtkEventSequenceState::cases()))->toBe([0, 1, 2])
        ->and($click->setState(GtkEventSequenceState::CLAIMED))->toBeFalse();
});
