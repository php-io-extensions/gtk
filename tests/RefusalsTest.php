<?php

declare(strict_types=1);

beforeEach(fn () => testApplication());

/*
 * Inputs GLib would answer with a critical (and in two cases a crash) are refused
 * before the call, as ValueError, so PHP never reaches the assertion.
 */
it('refuses inputs GTK would assert on', function (Closure $call): void {
    expect($call)->toThrow(ValueError::class);
})->with([
    'entry buffer: nChars past the end (an over-read in GTK)' => [fn () => GtkEntry::new()->getBuffer()->setText('ab', 2_000_000_000)],
    'entry buffer: invalid UTF-8' => [fn () => GtkEntry::new()->getBuffer()->setText("\xff", -1)],
    'entry buffer: nChars below -1' => [fn () => GtkEntry::new()->getBuffer()->setText('ab', -2)],
    'text buffer: len past the end' => [fn () => GtkTextView::new()->getBuffer()->setText('ab', 100)],
    'text buffer: invalid UTF-8' => [fn () => GtkTextView::new()->getBuffer()->setText("\xff")],
    'scale: min >= max' => [fn () => GtkScale::newWithRange(GtkOrientation::HORIZONTAL, 5.0, 1.0, 1.0)],
    'scale: step zero' => [fn () => GtkScale::newWithRange(GtkOrientation::HORIZONTAL, 0.0, 1.0, 0.0)],
    'scale: set_range min >= max' => [fn () => GtkScale::newWithRange(GtkOrientation::HORIZONTAL, 0.0, 1.0, 0.5)->setRange(5.0, 1.0)],
    'string list: remove past guint' => [fn () => GtkStringList::new(['a', 'b'])->remove(4_294_967_296)],
    'drop-down: selected past guint' => [fn () => GtkDropDown::newFromStrings(['a'])->setSelected(4_294_967_296)],
    'single selection: selected past guint' => [fn () => GtkSingleSelection::new(GtkStringList::new(['a']))->setSelected(4_294_967_296)],
    'margin over int16' => [fn () => GtkLabel::new('x')->setMarginStart(40_000)],
    'margin under int16' => [fn () => GtkLabel::new('x')->setMarginBottom(-40_000)],
    'size request below -1' => [fn () => GtkLabel::new('x')->setSizeRequest(-2, 1)],
    'measure for_size below -1' => [fn () => GtkLabel::new('x')->measure(GtkOrientation::HORIZONTAL, -2)],
    'grid: negative row spacing' => [fn () => GtkGrid::new()->setRowSpacing(-1)],
    'grid: column spacing over int16' => [fn () => GtkGrid::new()->setColumnSpacing(40_000)],
    'grid: attach a parented child' => [function (): void {
        $box = GtkBox::new(GtkOrientation::VERTICAL, 0);
        $label = GtkLabel::new('x');
        $box->append($label);
        GtkGrid::new()->attach($label, 0, 0, 1, 1);
    }],
    'grid: column out of int range' => [fn () => GtkGrid::new()->attach(GtkLabel::new('x'), 4_294_967_296, 0, 1, 1)],
    'grid: remove a stranger' => [fn () => GtkGrid::new()->remove(GtkLabel::new('x'))],
    'fixed: put a parented child' => [function (): void {
        $box = GtkBox::new(GtkOrientation::VERTICAL, 0);
        $label = GtkLabel::new('x');
        $box->append($label);
        GtkFixed::new()->put($label, 0.0, 0.0);
    }],
    'fixed: move a stranger' => [fn () => GtkFixed::new()->move(GtkLabel::new('x'), 1.0, 1.0)],
    'fixed: remove a stranger' => [fn () => GtkFixed::new()->remove(GtkLabel::new('x'))],
    'fixed: position of a stranger' => [fn () => GtkFixed::new()->getChildPosition(GtkLabel::new('x'))],
    'box: append a parented child' => [function (): void {
        $box = GtkBox::new(GtkOrientation::VERTICAL, 0);
        $label = GtkLabel::new('x');
        $box->append($label);
        GtkBox::new(GtkOrientation::VERTICAL, 0)->append($label);
    }],
    'box: remove a stranger' => [fn () => GtkBox::new(GtkOrientation::VERTICAL, 0)->remove(GtkLabel::new('x'))],
    'box: reorder a stranger' => [fn () => GtkBox::new(GtkOrientation::VERTICAL, 0)->reorderChildAfter(GtkLabel::new('x'), null)],
    'box: insert after a sibling from elsewhere' => [function (): void {
        $other = GtkBox::new(GtkOrientation::VERTICAL, 0);
        $sibling = GtkLabel::new('s');
        $other->append($sibling);
        GtkBox::new(GtkOrientation::VERTICAL, 0)->insertChildAfter(GtkLabel::new('x'), $sibling);
    }],
    'column view: append a column twice' => [function (): void {
        $view = GtkColumnView::new(null);
        $column = GtkColumnViewColumn::new('a', null);
        $view->appendColumn($column);
        $view->appendColumn($column);
    }],
    'column view: remove a column from another view' => [function (): void {
        $column = GtkColumnViewColumn::new('a', null);
        GtkColumnView::new(null)->appendColumn($column);
        GtkColumnView::new(null)->removeColumn($column);
    }],
    'media stream: negative seek' => [fn () => GtkMediaFile::newForFilename(__DIR__.'/fixtures/clip.mp4')->seek(-1)],
    'date: month out of int range' => [fn () => GDateTime::newLocal(2026, 4_294_967_297, 2, 0, 0, 0.0)],
    'text buffer: offset out of int range' => [fn () => GtkTextView::new()->getBuffer()->getText(0, 4_294_967_296)],
]);

it('answers null for a string list position past guint instead of truncating it', function (): void {
    expect(GtkStringList::new(['a', 'b'])->getString(4_294_967_296))->toBeNull();
});

it('accepts reference elements in a string array', function (): void {
    $strings = ['x', 'y'];
    $ref = &$strings[0];

    expect(GtkStringList::new($strings)->getString(0))->toBe('x');
});

it('does not expose gtk_widget_unparent, which is for widget implementations and leaves container child pointers dangling', function (): void {
    expect(method_exists(GtkWidget::class, 'unparent'))->toBeFalse();
});
