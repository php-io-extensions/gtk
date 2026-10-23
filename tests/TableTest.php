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

function singleSelection(): GtkSingleSelection
{
    $selection = GtkSingleSelection::new(GtkStringList::new(['a', 'b', 'c']));
    $selection->setAutoselect(false);
    $selection->setCanUnselect(true);
    // Autoselect selected the first item at construction.
    $selection->setSelected(GTK_INVALID_LIST_POSITION);

    return $selection;
}

it('derives the signal factory from GtkListItemFactory and the single selection from GtkSelectionModel', function (): void {
    expect(get_parent_class(GtkSignalListItemFactory::class))->toBe(GtkListItemFactory::class)
        ->and(GtkSignalListItemFactory::new())->toBeInstanceOf(GtkListItemFactory::class)
        ->and(singleSelection())->toBeInstanceOf(GtkSelectionModel::class)
        ->and(singleSelection())->toBeInstanceOf(GListModel::class)
        ->and(singleSelection()->getNItems())->toBe(3);
});

it('answers whether a position is selected', function (): void {
    $selection = singleSelection();
    $selection->setSelected(1);

    expect($selection->isSelected(1))->toBeTrue()
        ->and($selection->isSelected(0))->toBeFalse();
});

it('selects an item with gtk_selection_model_select_item', function (): void {
    $selection = singleSelection();

    expect($selection->selectItem(2, true))->toBeTrue()
        ->and($selection->getSelected())->toBe(2);
});

it('unselects an item with gtk_selection_model_unselect_item', function (): void {
    $selection = singleSelection();
    $selection->setSelected(1);

    expect($selection->unselectItem(1))->toBeTrue()
        ->and($selection->getSelected())->toBe(GTK_INVALID_LIST_POSITION);
});

it('answers GtkSingleSelection\'s false for a range select', function (): void {
    $selection = singleSelection();

    expect($selection->selectRange(0, 2, true))->toBeFalse()
        ->and($selection->getSelected())->toBe(GTK_INVALID_LIST_POSITION);
});

it('answers GtkSingleSelection\'s false for a range unselect', function (): void {
    $selection = singleSelection();
    $selection->setSelected(1);

    expect($selection->unselectRange(0, 3))->toBeFalse()
        ->and($selection->getSelected())->toBe(1);
});

it('answers GtkSingleSelection\'s false for select all', function (): void {
    expect(singleSelection()->selectAll())->toBeFalse();
});

it('unselects all with gtk_selection_model_unselect_all', function (): void {
    $selection = singleSelection();
    $selection->setSelected(1);

    expect($selection->unselectAll())->toBeTrue()
        ->and($selection->getSelected())->toBe(GTK_INVALID_LIST_POSITION);
});

it('emits selection-changed with gtk_selection_model_selection_changed', function (): void {
    $selection = singleSelection();
    $seen = [];
    g_signal_connect($selection, 'selection-changed', function (GObject $model, int $position, int $nItems) use (&$seen): void { $seen[] = [$position, $nItems]; });

    $selection->selectionChanged(0, 2);

    expect($seen)->toBe([[0, 2]]);
});

/** Roots a, b; a holds a1, a2; b is a leaf. */
function treeModel(?Closure $create = null): GtkTreeListModel
{
    return GtkTreeListModel::new(GtkStringList::new(['a', 'b']), false, false, $create ?? fn (GObject $item): ?GListModel => $item->getString() === 'a' ? GtkStringList::new(['a1', 'a2']) : null);
}

it('expands rows through the create function and walks them by position, depth and parent', function (): void {
    $model = treeModel();

    expect($model)->toBeInstanceOf(GListModel::class)
        ->and($model->getNItems())->toBe(2)
        ->and($model->getRow(0))->toBeInstanceOf(GtkTreeListRow::class)
        ->and($model->getRow(0)->isExpandable())->toBeTrue()
        ->and($model->getRow(1)->isExpandable())->toBeFalse()
        ->and($model->getRow(0)->getExpanded())->toBeFalse()
        ->and($model->getRow(5))->toBeNull();

    $model->getRow(0)->setExpanded(true);
    expect($model->getNItems())->toBe(4)
        ->and($model->getRow(0)->getExpanded())->toBeTrue()
        ->and($model->getRow(1)->getDepth())->toBe(1)
        ->and($model->getRow(1)->getItem()->getString())->toBe('a1')
        ->and($model->getRow(1)->getParent()->getItem()->getString())->toBe('a')
        ->and($model->getRow(0)->getParent())->toBeNull()
        ->and($model->getRow(0)->getChildRow(1)->getPosition())->toBe(2)
        ->and($model->getRow(0)->getChildRow(7))->toBeNull()
        ->and($model->getChildRow(1)->getItem()->getString())->toBe('b')
        ->and($model->getItem(1))->toBeInstanceOf(GtkTreeListRow::class);

    $model->getRow(0)->setExpanded(false);
    expect($model->getNItems())->toBe(2);
});

it('releases the create function once the model is finalized', function (): void {
    $held = new stdClass();
    $watch = WeakReference::create($held);
    $model = treeModel(function (GObject $item) use ($held): ?GListModel {
        return null;
    });
    unset($held);
    expect($watch->get())->not->toBeNull();

    unset($model);
    gc_collect_cycles();
    expect($watch->get())->toBeNull();
});

it('makes a row with an answer that is not a list model a leaf', function (): void {
    $model = treeModel(fn (GObject $item): mixed => $item->getString() === 'a' ? 'not a model' : null);

    expect($model->getRow(0)->isExpandable())->toBeFalse();
});

it('surfaces an exception from the create function at the call that asked', function (): void {
    $model = treeModel(function (GObject $item): ?GListModel {
        throw new RuntimeException('create failed for '.$item->getString());
    });

    expect(fn () => $model->getRow(0)->isExpandable())->toThrow(RuntimeException::class, 'create failed for a');
});

it('holds a tree expander\'s child and list row', function (): void {
    $model = treeModel();
    $row = $model->getRow(0);
    $expander = GtkTreeExpander::new();
    $label = GtkLabel::new('a');

    expect($expander)->toBeInstanceOf(GtkWidget::class)
        ->and($expander->getChild())->toBeNull()
        ->and($expander->getListRow())->toBeNull();

    $expander->setChild($label);
    $expander->setListRow($row);
    expect($expander->getChild())->toBe($label)
        ->and($expander->getListRow())->toBe($row);

    $expander->setListRow(null);
    expect($expander->getListRow())->toBeNull();
});

it('sets a scroll info\'s axes and scrolls a column view to a row', function (): void {
    $info = GtkScrollInfo::new();
    $info->setEnableHorizontal(false);

    expect($info->getEnableHorizontal())->toBeFalse()
        ->and($info->getEnableVertical())->toBeTrue();

    $info->setEnableVertical(false);
    expect($info->getEnableVertical())->toBeFalse();

    $view = GtkColumnView::new(GtkSingleSelection::new(treeModel()));
    $view->scrollTo(0, null, GTK_LIST_SCROLL_NONE, null);
    expect($view->getModel()->getSelected())->toBe(0);

    $view->scrollTo(1, null, GTK_LIST_SCROLL_FOCUS | GTK_LIST_SCROLL_SELECT, $info);
    expect($view->getModel()->getSelected())->toBe(1);
});
