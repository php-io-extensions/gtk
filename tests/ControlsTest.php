<?php

declare(strict_types=1);

beforeEach(fn () => testApplication());

it('round-trips label text, wrap, ellipsize, xalign and justification', function (): void {
    $label = GtkLabel::new(null);
    $label->setText('Hello');
    $label->setWrap(true);
    $label->setEllipsize(PangoEllipsizeMode::END);
    $label->setXalign(0.25);
    $label->setJustify(GtkJustification::CENTER);

    expect($label->getText())->toBe('Hello')
        ->and($label->getWrap())->toBeTrue()
        ->and($label->getXalign())->toBe(0.25)
        ->and(GtkLabel::new('x')->getText())->toBe('x');
});

it('clicks a button into PHP and relabels it', function (): void {
    $button = GtkButton::newWithLabel('Go');
    $clicks = 0;
    g_signal_connect($button, 'clicked', function () use (&$clicks): void { $clicks++; });
    $button->setLabel('Run');
    // gtk_widget_activate() on a button shows the pressed state and emits clicked on a 250ms timeout; it needs a realized button.
    $window = GtkWindow::new();
    $window->setChild($button);
    $window->present();
    iterateFor(0.1);

    expect($button->activate())->toBeTrue();
    iterateFor(0.4);

    expect($clicks)->toBe(1)->and($button->getLabel())->toBe('Run');
    $window->destroy();
});

it('toggles a check button', function (): void {
    $check = GtkCheckButton::newWithLabel('Opt');
    $toggles = 0;
    g_signal_connect($check, 'toggled', function () use (&$toggles): void { $toggles++; });
    $check->setActive(true);
    $check->setLabel('Option');

    expect($toggles)->toBe(1)
        ->and($check->getActive())->toBeTrue()
        ->and($check->getLabel())->toBe('Option');

    $check->setActive(false);
    expect($toggles)->toBe(2)->and($check->getActive())->toBeFalse();
});

it('flips a switch and notifies', function (): void {
    $switch = GtkSwitch::new();
    $notified = 0;
    g_signal_connect($switch, 'notify::active', function () use (&$notified): void { $notified++; });
    $switch->setActive(true);

    expect($notified)->toBe(1)->and($switch->getActive())->toBeTrue();
});

it('toggles a toggle button, which is a button', function (): void {
    $toggle = GtkToggleButton::newWithLabel('T');
    $toggles = 0;
    g_signal_connect($toggle, 'toggled', function () use (&$toggles): void { $toggles++; });
    $toggle->setActive(true);

    expect($toggle)->toBeInstanceOf(GtkButton::class)
        ->and($toggles)->toBe(1)
        ->and($toggle->getActive())->toBeTrue()
        ->and($toggle->getLabel())->toBe('T');
});

it('writes an entry through its buffer and hides the text', function (): void {
    $entry = GtkEntry::new();
    $changes = 0;
    g_signal_connect($entry->getBuffer(), 'notify::text', function () use (&$changes): void { $changes++; });
    $entry->getBuffer()->setText('abc', -1);
    $entry->setPlaceholderText('type');
    $entry->setVisibility(false);

    expect($changes)->toBe(1)
        ->and($entry->getBuffer()->getText())->toBe('abc')
        ->and($entry->getBuffer())->toBeInstanceOf(GtkEntryBuffer::class)
        ->and($entry->getPlaceholderText())->toBe('type')
        ->and($entry->getVisibility())->toBeFalse();
});

it('sets an entry buffer\'s first nChars characters, and refuses more than the string holds, which GTK reads past', function (): void {
    $buffer = GtkEntry::new()->getBuffer();
    $buffer->setText('héllo', 2);
    $first = $buffer->getText();
    $buffer->setText('héllo', 5);

    expect($first)->toBe('hé')
        ->and($buffer->getText())->toBe('héllo')
        ->and(fn () => $buffer->setText('ab', 3))->toThrow(ValueError::class, 'GtkEntryBuffer::setText(): Argument #2 ($nChars) must not exceed the 2 characters of $chars')
        ->and($buffer->getText())->toBe('héllo');
});

it('writes a text view through its buffer and reads it back', function (): void {
    $view = GtkTextView::new();
    $changes = 0;
    g_signal_connect($view->getBuffer(), 'changed', function () use (&$changes): void { $changes++; });
    $view->getBuffer()->setText("one\ntwo", -1);
    $view->setEditable(false);
    $view->setWrapMode(GtkWrapMode::WORD_CHAR);

    expect($changes)->toBe(1)
        ->and($view->getBuffer()->getText($view->getBuffer()->getStartIter(), $view->getBuffer()->getEndIter(), false))->toBe("one\ntwo")
        ->and($view->getBuffer()->getText($view->getBuffer()->getIterAtOffset(4), $view->getBuffer()->getIterAtOffset(7), false))->toBe('two')
        ->and($view->getEditable())->toBeFalse();
});

it('moves a scale and reports the value once', function (): void {
    $scale = GtkScale::newWithRange(GtkOrientation::HORIZONTAL, 0.0, 10.0, 0.5);
    $changes = 0;
    g_signal_connect($scale, 'value-changed', function () use (&$changes): void { $changes++; });
    $scale->setValue(7.5);
    $scale->setDrawValue(false);

    expect($changes)->toBe(1)
        ->and($scale->getValue())->toBe(7.5)
        ->and($scale->getDrawValue())->toBeFalse();

    $scale->setRange(0.0, 5.0);
    expect($scale->getValue())->toBe(5.0);

    // An arrow key moves by the step increment: GTK_SCROLL_STEP_BACKWARD = 2.
    $scale->setIncrements(0.25, 1.0);
    g_signal_emit_by_name($scale, 'move-slider', 2);
    expect($scale->getValue())->toBe(4.75);
});

it('selects from a drop-down over a string list', function (): void {
    $drop = GtkDropDown::newFromStrings(['a', 'b']);
    $selected = [];
    g_signal_connect($drop, 'notify::selected', function () use (&$selected, $drop): void { $selected[] = $drop->getSelected(); });
    $drop->setSelected(1);

    expect($selected)->toBe([1])
        ->and($drop->getSelectedItem())->toBeInstanceOf(GtkStringObject::class)
        ->and($drop->getSelectedItem()->getString())->toBe('b')
        ->and(fn () => GtkDropDown::newFromStrings(['a', 1]))->toThrow(TypeError::class)
        ->and(fn () => $drop->setModel(GMenu::new()))->toThrow(TypeError::class);

    $list = GtkStringList::new(['x']);
    $list->append('y');
    $drop->setModel($list);
    $drop->setSelected(1);
    expect($list->getNItems())->toBe(2)
        ->and($list->getString(1))->toBe('y')
        ->and($list->getString(2))->toBeNull()
        ->and($drop->getSelectedItem()->getString())->toBe('y');

    $list->remove(0);
    expect($list->getNItems())->toBe(1);

    $changes = [];
    g_signal_connect($list, 'items-changed', function (GObject $l, int $position, int $removed, int $added) use (&$changes): void { $changes[] = [$position, $removed, $added]; });
    $list->splice(0, 1, ['p', 'q', 'r']);
    $list->splice(3, 0, ['s']);
    expect($changes)->toBe([[0, 1, 3], [3, 0, 1]])
        ->and(array_map(fn (int $i): ?string => $list->getString($i), [0, 1, 2, 3]))->toBe(['p', 'q', 'r', 's'])
        ->and(fn () => $list->splice(0, 0, [1]))->toThrow(TypeError::class);
});

it('removes past a string list\'s end as GTK does: a critical, the list unchanged', function (): void {
    $run = gtkChild(<<<'PHP'
        $list = GtkStringList::new(['a']);
        $list->remove(5);

        return $list->getNItems();
    PHP);

    expect($run['result'])->toBe(1)
        ->and($run['stderr'])->toContain("gtk_string_list_splice: assertion 'position + n_removals <= objects_get_size (&self->items)' failed");
});

it('counts a string list\'s items through GListModel', function (): void {
    $list = GtkStringList::new(['a', 'b', 'c']);

    expect($list)->toBeInstanceOf(GListModel::class)
        ->and($list->getNItems())->toBe(3);
});

it('reads a list model\'s item with g_list_model_get_item, null past the end', function (): void {
    $list = GtkStringList::new(['a', 'b']);
    $item = $list->getItem(1);

    expect($item)->toBeInstanceOf(GtkStringObject::class)
        ->and($item->getString())->toBe('b')
        ->and($list->getItem(1))->toBe($item)
        ->and($list->getItem(2))->toBeNull();
});

it('reads a list model\'s item with g_list_model_get_object, null past the end', function (): void {
    $list = GtkStringList::new(['a', 'b']);

    expect($list->getObject(0)->getString())->toBe('a')
        ->and($list->getObject(2))->toBeNull();
});

it('emits items-changed with g_list_model_items_changed', function (): void {
    $list = GtkStringList::new(['a', 'b']);
    $changes = [];
    g_signal_connect($list, 'items-changed', function (GObject $l, int $position, int $removed, int $added) use (&$changes): void { $changes[] = [$position, $removed, $added]; });

    $list->itemsChanged(1, 0, 0);

    expect($changes)->toBe([[1, 0, 0]]);
});

it('selects a day on a calendar and reads it back as a GDateTime', function (): void {
    $calendar = GtkCalendar::new();
    // GTK emits day-selected only when the day of the month changes, and a calendar opens on
    // today, so it starts from a known day: the 14th, then the 15th.
    $calendar->selectDay(GDateTime::newLocal(2020, 3, 14, 0, 0, 0.0));
    $days = 0;
    g_signal_connect($calendar, 'day-selected', function () use (&$days): void { $days++; });
    $date = GDateTime::newLocal(2020, 3, 15, 0, 0, 0.0);
    $calendar->selectDay($date);

    expect($days)->toBe(1)
        ->and($calendar->getDate())->toBeInstanceOf(GDateTime::class)
        ->and($calendar->getDate()->getYear())->toBe(2020)
        ->and($calendar->getDate()->getMonth())->toBe(3)
        ->and($calendar->getDate()->getDayOfMonth())->toBe(15)
        // local midnight to local midnight, a day apart, outside DST changes: independent of PHP's own timezone setting
        ->and(GDateTime::newLocal(2020, 3, 16, 0, 0, 0.0)->toUnix() - $date->toUnix())->toBe(86400)
        ->and(GDateTime::newLocal(2026, 13, 1, 0, 0, 0.0))->toBeNull();
});

it('drives a progress bar and a spinner', function (): void {
    $bar = GtkProgressBar::new();
    $bar->setFraction(0.5);
    $bar->setPulseStep(0.2);
    $bar->pulse();
    $spinner = GtkSpinner::new();
    $spinner->setSpinning(true);

    expect($bar->getFraction())->toBe(0.5)
        ->and($spinner->getSpinning())->toBeTrue();
});

it('loads a picture from a file and reports nothing for a missing one', function (): void {
    $picture = GtkPicture::newForFilename(__DIR__.'/fixtures/pixel.png');
    $picture->setContentFit(GtkContentFit::COVER);

    expect($picture->getPaintable())->toBeInstanceOf(GdkPaintable::class)
        ->and($picture->getContentFit())->toBe(GtkContentFit::COVER);

    $picture->setFilename('/nope.png');
    expect($picture->getPaintable())->toBeNull()
        ->and(GtkPicture::new()->getPaintable())->toBeNull();
});

it('shows a themed icon and reads its name back', function (): void {
    $image = GtkImage::newFromIconName('dialog-warning');

    expect($image)->toBeInstanceOf(GtkWidget::class)
        ->and($image->getIconName())->toBe('dialog-warning')
        ->and(GtkImage::newFromIconName(null)->getIconName())->toBeNull();
});

it('hosts a child in a scrolled window beside a separator', function (): void {
    $scrolled = GtkScrolledWindow::new();
    $scrolled->setPolicy(GtkPolicyType::NEVER, GtkPolicyType::AUTOMATIC);
    $label = GtkLabel::new('inside');
    $scrolled->setChild($label);
    $separator = GtkSeparator::new(GtkOrientation::HORIZONTAL);

    // A child that is not a GtkScrollable is wrapped in a GtkViewport, which is what get_child() returns.
    expect($scrolled->getChild()->typeName())->toBe('GtkViewport')
        ->and($label->getParent())->toBe($scrolled->getChild())
        ->and($separator)->toBeInstanceOf(GtkWidget::class);

    $scrolled->setChild(null);
    expect($scrolled->getChild())->toBeNull();
});

it('builds a link button over a URI, with its label, visited state and activate-link signal', function (): void {
    $plain = GtkLinkButton::new('https://example.com/');
    $link = GtkLinkButton::newWithLabel('https://example.com/a', 'Example');
    $taken = [];
    g_signal_connect($link, 'activate-link', function (GtkLinkButton $button) use (&$taken): bool {
        $taken[] = $button->getUri();

        return true;                 // handled: GTK's own handler, which opens the URI, does not run
    });
    $link->setUri('https://example.com/b');   // resets visited
    $link->setVisited(true);
    $handled = g_signal_emit_by_name($link, 'activate-link');

    expect($plain->getUri())->toBe('https://example.com/')
        ->and($plain->getLabel())->toBe('https://example.com/')
        ->and($link->getLabel())->toBe('Example')
        ->and($link->getUri())->toBe('https://example.com/b')
        ->and($link->getVisited())->toBeTrue()
        ->and($link)->toBeInstanceOf(GtkButton::class)
        ->and(get_parent_class(GtkLinkButton::class))->toBe(GtkButton::class)
        ->and($handled)->toBeTrue()
        ->and($taken)->toBe(['https://example.com/b']);
});

it('shows Pango markup with a link, which its activate-link signal names', function (): void {
    $label = GtkLabel::new(null);
    $label->setMarkup('Read <a href="https://example.com/docs">the docs</a>');
    $seen = [];
    g_signal_connect($label, 'activate-link', function (GtkLabel $label, string $uri) use (&$seen): bool {
        $seen[] = $uri;

        return true;
    });
    g_signal_emit_by_name($label, 'activate-link', 'https://example.com/docs');
    $marked = $label->getUseMarkup();
    $shown = $label->getText();
    $label->setUseMarkup(false);      // the label shows its markup as written from here

    expect($shown)->toBe('Read the docs')
        ->and($marked)->toBeTrue()
        ->and($label->getUseMarkup())->toBeFalse()
        ->and($label->getCurrentUri())->toBeNull()        // no link is being activated by the pointer or keys
        ->and($seen)->toBe(['https://example.com/docs']);
});

it('hands malformed Pango markup to GTK, which warns and keeps the label\'s text', function (): void {
    $run = gtkChild(<<<'PHP'
        $label = GtkLabel::new('kept');
        $label->setMarkup('Read <a href="https://example.com/">the docs');

        return [$label->getText(), $label->getUseMarkup()];
    PHP);

    expect($run['result'])->toBe(['kept', true])
        ->and($run['stderr'])->toContain("Failed to set text 'Read <a href=\"https://example.com/\">the docs' from markup due to error parsing markup");
});
