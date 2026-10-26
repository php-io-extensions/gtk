<?php

declare(strict_types=1);

/*
 * GtkMenuButton, GtkButton's child and frame, GtkListView, GtkScrollbar over a GtkAdjustment,
 * GtkNotebook insert, GMenu insert by item, the menu model's attribute read, GdkSurface's scale.
 */

beforeEach(fn () => testApplication());

it('opens a menu model under a menu button with its own child, and closes it', function (): void {
    $window = GtkWindow::new();
    $button = GtkMenuButton::new();
    $model = GMenu::new();
    $model->append('None', 'win.none');
    $model->append('All', 'win.all');
    $child = GtkBox::new(GtkOrientation::HORIZONTAL, 4);
    $child->append(GtkLabel::new('Ignore case'));

    $button->setMenuModel($model);
    $button->setChild($child);
    $button->setHasFrame(false);
    $window->setChild($button);
    $window->present();
    iterateUntil(fn (): bool => $window->getMapped());
    $button->popup();
    iterateUntil(fn (): bool => $button->getPopover()?->getMapped() === true);

    expect($button->getMenuModel())->toBe($model)
        ->and($button->getChild())->toBe($child)
        ->and($button->getHasFrame())->toBeFalse()
        ->and($button->getPopover())->toBeInstanceOf(GtkPopover::class)
        ->and($button->getPopover()->getMapped())->toBeTrue();

    $button->popdown();
    iterateUntil(fn (): bool => ! $button->getPopover()->getMapped());
    expect($button->getPopover()->getMapped())->toBeFalse();
    $window->destroy();
});

it('takes a popover of its own', function (): void {
    $button = GtkMenuButton::new();
    $popover = GtkPopover::new();

    $button->setPopover($popover);

    expect($button->getPopover())->toBe($popover);
});

it('gives a button a child in place of its label, and no frame', function (): void {
    $button = GtkButton::newWithLabel('Open');
    $picture = GtkPicture::new();

    $button->setChild($picture);
    $button->setHasFrame(false);

    expect($button->getChild())->toBe($picture)
        ->and($button->getLabel())->toBeNull()
        ->and($button->getHasFrame())->toBeFalse();
});

it('lists a string list through a list view with single-click activation', function (): void {
    $strings = GtkStringList::new(['/Users/angel', '/Users/Shared', '/Users/Guest']);
    $factory = GtkSignalListItemFactory::new();
    $view = GtkListView::new(GtkSingleSelection::new($strings), $factory);

    $view->setSingleClickActivate(true);

    expect($view)->toBeInstanceOf(GtkListView::class)
        ->and($view->getSingleClickActivate())->toBeTrue()
        ->and(g_signal_connect($view, 'activate', fn (GtkListView $v, int $position) => null))->toBeGreaterThan(0);
});

it('makes a scroll bar over an adjustment and configures the adjustment at once', function (): void {
    $adjustment = GtkAdjustment::new(0.0, 0.0, 1000.0, 1.0, 100.0, 100.0);
    $bar = GtkScrollbar::new(GtkOrientation::VERTICAL, $adjustment);

    expect($bar->getAdjustment())->toBe($adjustment)
        ->and($adjustment->getUpper())->toBe(1000.0);

    $adjustment->configure(400.0, 0.0, 500.0, 1.0, 100.0, 100.0);

    expect($adjustment->getValue())->toBe(400.0)
        ->and($adjustment->getUpper())->toBe(500.0)
        ->and($adjustment->getPageSize())->toBe(100.0);
});

it('inserts a notebook page at a position', function (): void {
    $notebook = GtkNotebook::new();
    $notebook->appendPage(GtkLabel::new('a'), null);
    $notebook->appendPage(GtkLabel::new('b'), null);
    $page = GtkLabel::new('new');

    expect($notebook->insertPage($page, null, 1))->toBe(1)
        ->and($notebook->getNthPage(1))->toBe($page)
        ->and($notebook->getNPages())->toBe(3);
});

it('inserts a menu item by position and reads an item attribute back', function (): void {
    $menu = GMenu::new();
    $menu->append('a', null);
    $menu->append('b', null);
    $item = GMenuItem::new('x', null);

    $menu->insertItem(1, $item);

    expect($menu->getNItems())->toBe(3)
        ->and($menu->getItemAttributeValue(1, 'label', 's')?->getString())->toBe('x')
        ->and($menu->getItemAttributeValue(1, 'nope', null))->toBeNull()
        ->and($menu->getItemAttributeValue(1, 'label', 'b'))->toBeNull();
});

it('reads a shown window surface scale', function (): void {
    $window = GtkWindow::new();
    $window->present();
    iterateUntil(fn (): bool => $window->getMapped());

    expect($window->getSurface()->getScale())->toBeGreaterThanOrEqual(1.0);
    $window->destroy();
});
