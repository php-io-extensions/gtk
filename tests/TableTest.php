<?php

declare(strict_types=1);

beforeEach(fn () => testApplication());

it('builds a two-column table over a string list and reports selection', function (): void {
    $rows = [['a', '1'], ['b', '2']];
    $model = GtkStringList::new(['0', '1']);
    $selection = GtkSingleSelection::new($model);
    $selection->setAutoselect(false);
    $view = GtkColumnView::new($selection);
    $bound = [];
    foreach ([0 => 'Name', 1 => 'Qty'] as $index => $title) {
        $factory = GtkSignalListItemFactory::new();
        g_signal_connect($factory, 'setup', fn (GtkSignalListItemFactory $f, GtkListItem $item) => $item->setChild(GtkLabel::new(null)));
        g_signal_connect($factory, 'bind', function (GtkSignalListItemFactory $f, GtkListItem $item) use ($rows, $index, &$bound): void {
            $item->getChild()->setText($rows[(int) $item->getItem()->getString()][$index]);
            $bound[] = [$index, $item->getPosition()];
        });
        $column = GtkColumnViewColumn::new($title, $factory);
        $column->setExpand(true);
        $column->setResizable(false);
        $view->appendColumn($column);
    }
    $view->setShowRowSeparators(true);
    $view->setShowColumnSeparators(true);
    $selected = [];
    g_signal_connect($selection, 'notify::selected', function () use (&$selected, $selection): void { $selected[] = $selection->getSelected(); });
    $window = GtkApplicationWindow::new(testApplication());
    $window->setChild($view);
    $window->present();
    iterateFor(0.3);
    $selection->setSelected(1);
    iterateFor(0.1);

    expect($selected)->toBe([1])
        ->and($selection->getSelectedItem()->getString())->toBe('1')
        ->and($selection->getModel())->toBe($model)
        ->and($view->getModel())->toBe($selection)
        ->and($bound)->toContain([0, 0], [1, 1])
        ->and(fn () => GtkColumnView::new($model))->toThrow(ValueError::class)
        ->and(fn () => GtkSingleSelection::new($selection->getSelectedItem()))->toThrow(ValueError::class);

    $selection->setCanUnselect(true);
    $selection->setSelected(GTK_INVALID_LIST_POSITION);
    expect($selection->getSelected())->toBe(GTK_INVALID_LIST_POSITION)
        ->and($selection->getSelectedItem())->toBeNull();

    $column = GtkColumnViewColumn::new(null, null);
    $column->setTitle('Late');
    $view->appendColumn($column);
    $view->removeColumn($column);
    expect($column->getTitle())->toBe('Late');
    $window->destroy();
});
