<?php

declare(strict_types=1);

beforeEach(fn () => testApplication());

it('lays a string list out in a grid view with column bounds and single-click activation', function (): void {
    $strings = GtkStringList::new(['1995-06-16', '1995-06-17', '1995-06-18']);
    $view = GtkGridView::new(GtkSingleSelection::new($strings), GtkSignalListItemFactory::new());

    $view->setMinColumns(2);
    $view->setMaxColumns(6);
    $view->setSingleClickActivate(true);

    expect($view)->toBeInstanceOf(GtkGridView::class)
        ->and($view->getMinColumns())->toBe(2)
        ->and($view->getMaxColumns())->toBe(6)
        ->and($view->getSingleClickActivate())->toBeTrue()
        ->and(g_signal_connect($view, 'activate', fn (GtkGridView $v, int $position) => null))->toBeGreaterThan(0);
});

it('packs widgets into a header bar and sets it as a window title bar', function (): void {
    $bar = GtkHeaderBar::new();
    $start = GtkButton::newWithLabel('‹');
    $end = GtkButton::newWithLabel('›');
    $title = GtkLabel::new('APOD');

    $bar->packStart($start);
    $bar->packEnd($end);
    $bar->setTitleWidget($title);
    $bar->setShowTitleButtons(false);

    $window = GtkWindow::new();
    $window->setTitlebar($bar);

    expect($bar->getTitleWidget())->toBe($title)
        ->and($bar->getShowTitleButtons())->toBeFalse()
        ->and($start->getParent())->not->toBeNull()
        ->and($window->getTitlebar())->toBe($bar);

    $window->setTitlebar(null);
    expect($window->getTitlebar())->toBeNull();
    $window->destroy();
});

it('groups toggle buttons so one is active at a time', function (): void {
    $today = GtkToggleButton::newWithLabel('Today');
    $recent = GtkToggleButton::newWithLabel('Recently');
    $recent->setGroup($today);

    $today->setActive(true);
    $recent->setActive(true);

    expect($today->getActive())->toBeFalse()
        ->and($recent->getActive())->toBeTrue();

    $recent->setGroup(null);
    $today->setActive(true);
    expect($recent->getActive())->toBeTrue();
});
