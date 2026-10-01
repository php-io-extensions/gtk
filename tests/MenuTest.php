<?php

declare(strict_types=1);

beforeEach(fn () => testApplication());

it('builds a menu model with submenus, sections and items', function (): void {
    $bar = GMenu::new();
    $view = GMenu::new();
    $section = GMenu::new();

    $view->append('Refresh', 'win.view.refresh');
    $view->prepend('Zoom', 'win.zoom');
    $section->append('About', 'app.about');
    $view->appendSection(null, $section);

    $item = GMenuItem::new('Quit', 'app.quit');
    $item->setAttributeValue('accel', GVariant::newString('<Control>q'));
    $view->appendItem($item);
    $bar->appendSubmenu('View', $view);

    expect($bar->getNItems())->toBe(1)
        ->and($view->getNItems())->toBe(4)
        ->and($bar->isMutable())->toBeTrue()
        ->and($item->getAttributeValue('accel', 's')?->getString())->toBe('<Control>q')
        ->and($item->getAttributeValue('missing', null))->toBeNull();

    $view->remove(0);
    expect($view->getNItems())->toBe(3)
        ->and(fn () => $view->remove(10))->toThrow(ValueError::class);

    $view->removeAll();
    expect($view->getNItems())->toBe(0);

    $bar->freeze();
    expect($bar->isMutable())->toBeFalse();
});

it('refuses detailed action names GLib would reject', function (): void {
    expect(fn () => GMenu::new()->append('X', 'not a valid name!'))->toThrow(ValueError::class)
        ->and(fn () => GMenuItem::new('X', 'a b'))->toThrow(ValueError::class);
});

it('shows a popover menu bar from a model in a window', function (): void {
    $model = GMenu::new();
    $model->appendSubmenu('View', GMenu::new());
    $bar = GtkPopoverMenuBar::newFromModel($model);
    $window = GtkWindow::new();
    $window->setChild($bar);

    expect($bar->getMenuModel())->toBe($model)
        ->and($bar->getParent())->toBe($window);

    $bar->setMenuModel(null);
    expect($bar->getMenuModel())->toBeNull();

    $window->destroy();
});

it('sets the application menubar and accelerators', function (): void {
    $app = testApplication();
    $model = GMenu::new();

    $app->setMenubar($model);
    $app->setAccelsForAction('win.view.refresh', ['<Control>r', '<Control><Shift>r']);

    expect($app->getMenubar())->toBe($model)
        ->and($app->getAccelsForAction('win.view.refresh'))->toBe(['<Control>r', '<Shift><Control>r'])
        ->and(fn () => $app->setAccelsForAction('win.x', ['not an accel']))->toThrow(ValueError::class);

    $app->setMenubar(null);
    expect($app->getMenubar())->toBeNull();
});
