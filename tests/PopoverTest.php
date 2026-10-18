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
    $menu->setPointingTo(new GdkRectangle(10, 20, 1, 1));
    $window->present();
    $menu->popup();
    $shown = iterateUntil(fn (): bool => $menu->getMapped(), 3000);
    $menu->popdown();
    iterateUntil(fn (): bool => $closed > 0, 3000);
    $set = $menu->getPointingTo($pointing);
    $menu->unparent();

    expect($menu)->toBeInstanceOf(GtkPopover::class)
        ->and($menu->getMenuModel())->toBe($model)
        ->and($menu->getHasArrow())->toBeFalse()
        ->and($set)->toBeTrue()
        ->and([$pointing->x, $pointing->y, $pointing->width, $pointing->height])->toBe([10, 20, 1, 1])
        ->and($shown)->toBeTrue()
        ->and($closed)->toBe(1)
        ->and($menu->getParent())->toBeNull();
    $window->destroy();
});

it('points nowhere until told, and measures its parent when it has one', function (): void {
    $box = GtkBox::new(GtkOrientation::VERTICAL, 0);
    $menu = GtkPopoverMenu::newFromModel(null);
    $menu->setParent($box);
    $unset = $menu->getPointingTo($parentBounds);
    $menu->setPointingTo(new GdkRectangle(1, 2, 3, 4));
    $menu->setPointingTo(null);
    $cleared = $menu->getPointingTo($afterClear);

    expect($unset)->toBeFalse()
        ->and($parentBounds)->toBeInstanceOf(GdkRectangle::class)
        ->and($cleared)->toBeFalse();
    $menu->unparent();
});

it('answers GTK\'s own results without a parent, for a second parent, and for a negative size', function (): void {
    $run = gtkChild(<<<'PHP'
        $rect = fn (GdkRectangle $r): array => [$r->x, $r->y, $r->width, $r->height];
        $orphan = GtkPopoverMenu::newFromModel(null);
        $none = $orphan->getPointingTo($nothing);
        $orphan->setPointingTo(new GdkRectangle(1, 2, 3, 4));
        $given = $orphan->getPointingTo($pointed);

        $box = GtkBox::new(GtkOrientation::VERTICAL, 0);
        $menu = GtkPopoverMenu::newFromModel(null);
        $menu->setParent($box);
        $menu->setParent(GtkBox::new(GtkOrientation::VERTICAL, 0));
        $kept = $menu->getParent() === $box;
        $menu->setPointingTo(new GdkRectangle(0, 0, -1, 1));
        $clamped = $menu->getPointingTo($stored);

        return [$none, $rect($nothing), $given, $rect($pointed), $kept, $clamped, $rect($stored)];
    PHP);

    // No rectangle and no parent: GTK measures a NULL parent (a critical), false and a zeroed rectangle.
    // A set rectangle needs no parent. A second parent is a critical; a negative size is stored as 1.
    expect($run['result'])->toBe([false, [0, 0, 0, 0], true, [1, 2, 3, 4], true, true, [0, 0, 1, 1]])
        ->and($run['stderr'])->toContain("gtk_widget_compute_bounds: assertion 'GTK_IS_WIDGET (widget)' failed")
        ->and($run['stderr'])->toContain("gtk_widget_set_parent: assertion '_gtk_widget_get_parent (widget) == NULL' failed");
});

it('answers as a GtkNative while popped up: its own surface and surface transform', function (): void {
    $window = GtkWindow::new();
    $box = GtkBox::new(GtkOrientation::VERTICAL, 0);
    $box->setSizeRequest(200, 100);
    $window->setChild($box);
    $menu = GtkPopoverMenu::newFromModel(GMenu::new());
    $menu->setParent($box);
    $window->present();
    $menu->popup();
    iterateUntil(fn (): bool => $menu->getMapped(), 3000);

    $surface = (new ReflectionMethod(GtkNative::class, 'getSurface'))->invoke($menu);
    $menu->getSurfaceTransform($x, $y);
    $menu->popdown();
    $menu->unparent();

    expect($menu)->toBeInstanceOf(GtkNative::class)
        ->and($surface)->toBeInstanceOf(GdkSurface::class)
        ->and($surface)->not->toBe($window->getSurface())
        ->and($x)->toBeFloat()
        ->and($y)->toBeFloat();
    $window->destroy();
});

it('claims a gesture\'s sequences, and names the sequence states at their C values', function (): void {
    $click = GtkGestureClick::new();

    expect(array_map(fn (GtkEventSequenceState $s): int => $s->value, GtkEventSequenceState::cases()))->toBe([0, 1, 2])
        ->and($click->setState(GtkEventSequenceState::CLAIMED))->toBeFalse();
});
