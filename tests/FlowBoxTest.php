<?php

declare(strict_types=1);

beforeEach(fn () => testApplication());

it('keeps the children of a flow box in the order they are inserted', function (): void {
    $flow = GtkFlowBox::new();
    $a = GtkLabel::new('a');
    $b = GtkLabel::new('b');
    $c = GtkLabel::new('c');

    $flow->append($a);
    $flow->prepend($b);
    $flow->insert($c, 1);

    expect($flow)->toBeInstanceOf(GtkWidget::class)
        ->and($flow->getChildAtIndex(0)->getChild())->toBe($b)
        ->and($flow->getChildAtIndex(1)->getChild())->toBe($c)
        ->and($flow->getChildAtIndex(2)->getChild())->toBe($a)
        ->and($flow->getChildAtIndex(3))->toBeNull();

    $flow->remove($c);
    expect($flow->getChildAtIndex(1)->getChild())->toBe($a)
        ->and($c->getParent())->toBeNull();

    $flow->removeAll();
    expect($flow->getChildAtIndex(0))->toBeNull();
});

it('puts a flow box child in a flow box and takes it out again', function (): void {
    $flow = GtkFlowBox::new();
    $cell = GtkFlowBoxChild::new();
    $label = GtkLabel::new('x');

    expect($cell->getChild())->toBeNull();
    $cell->setChild($label);
    expect($cell->getChild())->toBe($label)
        ->and($label->getParent())->toBe($cell);

    $flow->append($cell);
    expect($flow->getChildAtIndex(0))->toBe($cell)
        ->and($cell->getParent())->toBe($flow)
        ->and($cell->isSelected())->toBeFalse();

    $flow->remove($cell);
    expect($cell->getParent())->toBeNull()
        ->and($flow->getChildAtIndex(0))->toBeNull();

    $flow->insert($cell, 0);
    expect($flow->getChildAtIndex(0))->toBe($cell);

    $cell->setChild(null);
    $cell->changed();
    expect($label->getParent())->toBeNull();
});

it('keeps the spacing, per-line counts, homogeneous flag and selection mode a flow box is given', function (): void {
    $flow = GtkFlowBox::new();

    expect($flow->getRowSpacing())->toBe(0)
        ->and($flow->getColumnSpacing())->toBe(0)
        ->and($flow->getMinChildrenPerLine())->toBe(0)
        ->and($flow->getMaxChildrenPerLine())->toBe(7)
        ->and($flow->getHomogeneous())->toBeFalse()
        ->and($flow->getSelectionMode())->toBe(GtkSelectionMode::SINGLE);

    $flow->setRowSpacing(4);
    $flow->setColumnSpacing(6);
    $flow->setMinChildrenPerLine(2);
    $flow->setMaxChildrenPerLine(30);
    $flow->setHomogeneous(true);
    $flow->setSelectionMode(GtkSelectionMode::NONE);

    expect($flow->getRowSpacing())->toBe(4)
        ->and($flow->getColumnSpacing())->toBe(6)
        ->and($flow->getMinChildrenPerLine())->toBe(2)
        ->and($flow->getMaxChildrenPerLine())->toBe(30)
        ->and($flow->getHomogeneous())->toBeTrue()
        ->and($flow->getSelectionMode())->toBe(GtkSelectionMode::NONE);
});

it('refuses a flow box count, spacing or position outside the C range of its type', function (): void {
    $flow = GtkFlowBox::new();

    expect(fn () => $flow->setRowSpacing(-1))->toThrow(ValueError::class)
        ->and(fn () => $flow->setMaxChildrenPerLine(4294967296))->toThrow(ValueError::class)
        ->and(fn () => $flow->insert(GtkLabel::new('x'), 2147483648))->toThrow(ValueError::class)
        ->and(fn () => $flow->getChildAtIndex(2147483648))->toThrow(ValueError::class);
});

it('wraps the children of a flow box onto a second line when its width is short', function (): void {
    $flow = GtkFlowBox::new();
    $flow->setSelectionMode(GtkSelectionMode::NONE);
    $flow->setMaxChildrenPerLine(30);
    foreach (range(1, 4) as $i) {
        $box = GtkBox::new(GtkOrientation::VERTICAL, 0);
        $box->setSizeRequest(100, 20);
        $flow->append($box);
    }

    $width = $flow->measure(GtkOrientation::HORIZONTAL, -1);
    expect($width['natural'])->toBeGreaterThanOrEqual(400)
        ->and($width['minimum'])->toBeLessThan(400);

    $oneLine = $flow->measure(GtkOrientation::VERTICAL, 1000)['natural'];
    $twoLines = $flow->measure(GtkOrientation::VERTICAL, 250)['natural'];
    expect($twoLines)->toBeGreaterThan($oneLine);
});
