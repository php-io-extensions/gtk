<?php

declare(strict_types=1);

beforeEach(fn () => testApplication());

/*
 * A PHP value with no form in the native parameter's C type is refused, as ValueError: the
 * conversion would truncate it.
 */
it('refuses values with no form in the native C type', function (Closure $call): void {
    expect($call)->toThrow(ValueError::class);
})->with([
    'string list: remove past guint' => [fn () => GtkStringList::new(['a', 'b'])->remove(4_294_967_296)],
    'drop-down: selected past guint' => [fn () => GtkDropDown::newFromStrings(['a'])->setSelected(4_294_967_296)],
    'single selection: selected past guint' => [fn () => GtkSingleSelection::new(GtkStringList::new(['a']))->setSelected(4_294_967_296)],
    'grid: negative row spacing' => [fn () => GtkGrid::new()->setRowSpacing(-1)],
    'grid: column out of int range' => [fn () => GtkGrid::new()->attach(GtkLabel::new('x'), 4_294_967_296, 0, 1, 1)],
    'date: month out of int range' => [fn () => GDateTime::newLocal(2026, 4_294_967_297, 2, 0, 0, 0.0)],
    'string list: get past guint' => [fn () => GtkStringList::new(['a', 'b'])->getString(4_294_967_296)],
    'string list: negative get' => [fn () => GtkStringList::new(['a', 'b'])->getString(-1)],
    'string list: splice past guint' => [fn () => GtkStringList::new(['a'])->splice(0, 4_294_967_296, [])],
    'margin out of int range' => [fn () => GtkLabel::new('x')->setMarginStart(4_294_967_296)],
    'grid: negative column spacing' => [fn () => GtkGrid::new()->setColumnSpacing(-1)],
    'menu: insert out of int range' => [fn () => GMenu::new()->insert(4_294_967_296, 'x', null)],
    'source: negative id' => [fn () => g_source_remove(-1)],
    'text buffer: setText len out of int range' => [fn () => GtkTextView::new()->getBuffer()->setText('ab', 4_294_967_296)],
    'entry buffer: setText nChars out of int range' => [fn () => GtkEntry::new()->getBuffer()->setText('ab', -4_294_967_296)],
    'bytes: negative size' => [fn () => GBytes::new(0, -1)],
    'region: index out of int range' => [fn () => CairoRegion::create()->getRectangle(4_294_967_296)],
]);

/*
 * Inputs GTK answers itself: the call is made, GTK logs its critical or warning, and its
 * result reaches PHP. Each runs in its own process, whose stderr carries GTK's log.
 */
it('makes the call and answers with GTK\'s own result and log', function (string $code, mixed $result, ?string $logged): void {
    $run = gtkChild($code);

    expect($run['survived'])->toBeTrue()
        ->and($run['result'])->toBe($result);
    if ($logged !== null) {
        expect($run['stderr'])->toContain($logged);
    }
})->with([
    'text buffer: getText from a stale start iter is null' => [
        '$b = GtkTextView::new()->getBuffer(); $b->setText("one\ntwo", -1); $b->getIterAtLine($s, 1); $b->setText("x", -1); return $b->getText($s, $b->getEndIter(), false);', null,
        'Invalid text buffer iterator'],
    'text buffer: getText to a stale end iter is null' => [
        '$b = GtkTextView::new()->getBuffer(); $b->setText("one\ntwo", -1); $b->getIterAtLine($s, 1); $b->setText("x", -1); return $b->getText($b->getStartIter(), $s, false);', null,
        'Invalid text buffer iterator'],
    'entry buffer: invalid UTF-8 is stored as given' => [
        '$b = GtkEntry::new()->getBuffer(); $b->setText("\xff", -1); return bin2hex($b->getText());', 'ff', null],
    'entry buffer: nChars below -1 is the whole string' => [
        '$b = GtkEntry::new()->getBuffer(); $b->setText("ab", -2); return $b->getText();', 'ab', null],
    'text buffer: len past the end' => [
        '$b = GtkTextView::new()->getBuffer(); $b->setText("ab", 100); return $b->getText($b->getStartIter(), $b->getEndIter(), false);', '',
        "gtk_text_buffer_emit_insert: assertion 'g_utf8_validate (text, len, NULL)' failed"],
    'text buffer: invalid UTF-8 empties the buffer' => [
        '$b = GtkTextView::new()->getBuffer(); $b->setText("old", -1); $b->setText("\xff", -1); return $b->getText($b->getStartIter(), $b->getEndIter(), false);', '',
        "gtk_text_buffer_emit_insert: assertion 'g_utf8_validate (text, len, NULL)' failed"],
    'scale: min >= max is null' => [
        'return GtkScale::newWithRange(GtkOrientation::HORIZONTAL, 5.0, 1.0, 1.0);', null,
        "gtk_scale_new_with_range: assertion 'min < max' failed"],
    'scale: step zero is null' => [
        'return GtkScale::newWithRange(GtkOrientation::HORIZONTAL, 0.0, 1.0, 0.0);', null,
        "gtk_scale_new_with_range: assertion 'step != 0.0' failed"],
    'scale: set_range min > max leaves the range' => [
        '$s = GtkScale::newWithRange(GtkOrientation::HORIZONTAL, 0.0, 1.0, 0.5); $s->setRange(5.0, 1.0); $s->setValue(0.75); return $s->getValue();', 0.75,
        "gtk_range_set_range: assertion 'min <= max' failed"],
    'scale: set_range min == max is taken' => [
        '$s = GtkScale::newWithRange(GtkOrientation::HORIZONTAL, 0.0, 1.0, 0.5); $s->setRange(1.0, 1.0); return $s->getValue();', 1.0, null],
    'grid: remove a stranger' => [
        'GtkGrid::new()->remove(GtkLabel::new("x")); return "returned";', 'returned',
        "gtk_grid_remove: assertion 'gtk_widget_get_parent (child) == GTK_WIDGET (grid)' failed"],
    'fixed: put a parented child' => [
        '$box = GtkBox::new(GtkOrientation::VERTICAL, 0); $l = GtkLabel::new("x"); $box->append($l); GtkFixed::new()->put($l, 0.0, 0.0); return $l->getParent() === $box;', true,
        "gtk_fixed_put: assertion '_gtk_widget_get_parent (widget) == NULL' failed"],
    'fixed: move a stranger' => [
        'GtkFixed::new()->move(GtkLabel::new("x"), 1.0, 1.0); return "returned";', 'returned',
        "gtk_fixed_move: assertion 'gtk_widget_get_parent (widget) == GTK_WIDGET (fixed)' failed"],
    'fixed: remove a stranger' => [
        'GtkFixed::new()->remove(GtkLabel::new("x")); return "returned";', 'returned',
        "gtk_fixed_remove: assertion 'gtk_widget_get_parent (widget) == GTK_WIDGET (fixed)' failed"],
    'fixed: position of a stranger' => [
        'return GtkFixed::new()->getChildPosition(GtkLabel::new("x"));', [0.0, 0.0],
        "gtk_fixed_get_child_position: assertion 'gtk_widget_get_parent (widget) == GTK_WIDGET (fixed)' failed"],
    'box: append a parented child' => [
        '$box = GtkBox::new(GtkOrientation::VERTICAL, 0); $l = GtkLabel::new("x"); $box->append($l); GtkBox::new(GtkOrientation::VERTICAL, 0)->append($l); return $l->getParent() === $box;', true,
        "gtk_box_append: assertion 'gtk_widget_get_parent (child) == NULL' failed"],
    'box: remove a stranger' => [
        'GtkBox::new(GtkOrientation::VERTICAL, 0)->remove(GtkLabel::new("x")); return "returned";', 'returned',
        "gtk_box_remove: assertion 'gtk_widget_get_parent (child) == (GtkWidget *)box' failed"],
    'box: reorder a stranger' => [
        'GtkBox::new(GtkOrientation::VERTICAL, 0)->reorderChildAfter(GtkLabel::new("x"), null); return "returned";', 'returned',
        "gtk_box_reorder_child_after: assertion 'gtk_widget_get_parent (child) == (GtkWidget *)box' failed"],
    'box: insert after a sibling from elsewhere' => [
        '$other = GtkBox::new(GtkOrientation::VERTICAL, 0); $s = GtkLabel::new("s"); $other->append($s); $n = GtkLabel::new("x"); GtkBox::new(GtkOrientation::VERTICAL, 0)->insertChildAfter($n, $s); return $n->getParent() === null;', true,
        "gtk_box_insert_child_after: assertion 'gtk_widget_get_parent (sibling) == widget' failed"],
    'column view: append a column twice' => [
        '$v = GtkColumnView::new(null); $c = GtkColumnViewColumn::new("a", null); $v->appendColumn($c); $v->appendColumn($c); return "returned";', 'returned',
        "gtk_column_view_append_column: assertion 'gtk_column_view_column_get_column_view (column) == NULL' failed"],
    'column view: remove a column from another view' => [
        '$c = GtkColumnViewColumn::new("a", null); GtkColumnView::new(null)->appendColumn($c); GtkColumnView::new(null)->removeColumn($c); return "returned";', 'returned',
        "gtk_column_view_remove_column: assertion 'gtk_column_view_column_get_column_view (column) == self' failed"],
    'widget: margin over int16' => [
        '$l = GtkLabel::new("x"); $l->setMarginStart(40000); return "returned";', 'returned',
        "gtk_widget_set_margin_start: assertion 'margin <= G_MAXINT16' failed"],
    'widget: size request below -1' => [
        '$l = GtkLabel::new("x"); $l->setSizeRequest(-2, 1); return $l->getSizeRequest();', [-1, -1],
        "gtk_widget_set_size_request: assertion 'width >= -1' failed"],
    'widget: measure for_size below -1' => [
        'return GtkLabel::new("x")->measure(GtkOrientation::HORIZONTAL, -2);', ['minimum' => 0, 'natural' => 0, 'minimumBaseline' => -1, 'naturalBaseline' => -1],
        "gtk_widget_measure: assertion 'for_size >= -1' failed"],
    'grid: column spacing over int16' => [
        '$g = GtkGrid::new(); $g->setColumnSpacing(40000); return $g->getColumnSpacing();', 0,
        "gtk_grid_set_column_spacing: assertion 'spacing <= G_MAXINT16' failed"],
    'grid: row spacing over int16' => [
        '$g = GtkGrid::new(); $g->setRowSpacing(4294967295); return $g->getRowSpacing();', 0,
        "gtk_grid_set_row_spacing: assertion 'spacing <= G_MAXINT16' failed"],
    'grid: attach a parented child' => [
        '$box = GtkBox::new(GtkOrientation::VERTICAL, 0); $l = GtkLabel::new("x"); $box->append($l); GtkGrid::new()->attach($l, 0, 0, 1, 1); return $l->getParent() === $box;', true,
        "gtk_grid_attach: assertion '_gtk_widget_get_parent (child) == NULL' failed"],
    'grid: attach with no width' => [
        '$g = GtkGrid::new(); $l = GtkLabel::new("x"); $g->attach($l, 0, 0, 0, 1); return $l->getParent() === null;', true,
        "gtk_grid_attach: assertion 'width > 0' failed"],
    'string list: splice past the end' => [
        '$l = GtkStringList::new(["a", "b"]); $l->splice(2, 3, []); $l->splice(5, 0, []); return $l->getNItems();', 2,
        "gtk_string_list_splice: assertion 'position + n_removals <= objects_get_size (&self->items)' failed"],
    'media stream: negative seek' => [
        'return GtkMediaFile::newForFilename('.var_export(__DIR__.'/fixtures/clip.mp4', true).')->seek(-1);', null,
        "gtk_media_stream_seek: assertion 'timestamp >= 0' failed"],
]);

it('reads a string list position past its end as GTK does: null', function (): void {
    expect(GtkStringList::new(['a'])->getString(5))->toBeNull();
});

it('accepts reference elements in a string array', function (): void {
    $strings = ['x', 'y'];
    $ref = &$strings[0];

    expect(GtkStringList::new($strings)->getString(0))->toBe('x');
});

it('does not expose gtk_widget_unparent, which is for widget implementations and leaves container child pointers dangling', function (): void {
    expect(method_exists(GtkWidget::class, 'unparent'))->toBeFalse();
});
