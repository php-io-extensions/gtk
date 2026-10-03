<?php

declare(strict_types=1);

/*
 * Every stub declaration is what the loaded extension exposes: the stubs are
 * the source of truth, so a binding missing from the build fails here.
 */

function stubDeclarations(): array
{
    $declared = ['functions' => [], 'classes' => []];

    foreach (glob(__DIR__ . '/../stubs/*.stub.php') as $stub) {
        $class = null;
        foreach (file($stub) as $line) {
            if (preg_match('/^(?:final\s+)?(?:class|enum)\s+(\w+)/', $line, $m)) {
                $class = $m[1];
                $declared['classes'][$class] ??= [];
            } elseif (preg_match('/^function\s+(\w+)/', $line, $m)) {
                $declared['functions'][] = $m[1];
            } elseif ($class !== null && preg_match('/^\s+(?:public|private)\s+(?:static\s+)?function\s+(\w+)/', $line, $m)) {
                $declared['classes'][$class][] = $m[1];
            }
        }
    }

    return $declared;
}

it('exposes every function, class, enum and method the stubs declare', function (): void {
    $declared = stubDeclarations();

    foreach ($declared['functions'] as $function) {
        expect(function_exists($function))->toBeTrue("{$function}() is missing");
    }

    foreach ($declared['classes'] as $class => $methods) {
        expect(class_exists($class) || enum_exists($class))->toBeTrue("{$class} is missing");

        foreach ($methods as $method) {
            expect(method_exists($class, $method))->toBeTrue("{$class}::{$method}() is missing");
        }
    }
});

it('reports its version', function (): void {
    expect(phpversion('gtk'))->toBe('0.10.0');
});

it('keeps the native class hierarchy', function (): void {
    expect(get_parent_class(GtkApplication::class))->toBe(GApplication::class)
        ->and(get_parent_class(GApplication::class))->toBe(GObject::class)
        ->and(get_parent_class(GtkException::class))->toBe(RuntimeException::class)
        ->and(get_parent_class(GError::class))->toBe(RuntimeException::class)
        ->and(get_parent_class(GtkWidget::class))->toBe(GObject::class)
        ->and(get_parent_class(GtkWindow::class))->toBe(GtkWidget::class)
        ->and(get_parent_class(GtkApplicationWindow::class))->toBe(GtkWindow::class)
        ->and(get_parent_class(GtkAboutDialog::class))->toBe(GtkWindow::class)
        ->and(get_parent_class(GtkBox::class))->toBe(GtkWidget::class)
        ->and(get_parent_class(GtkGrid::class))->toBe(GtkWidget::class)
        ->and(get_parent_class(GtkFixed::class))->toBe(GtkWidget::class)
        ->and(get_parent_class(GtkCssProvider::class))->toBe(GObject::class)
        ->and(get_parent_class(GdkDisplay::class))->toBe(GObject::class)
        ->and(get_parent_class(GdkSurface::class))->toBe(GObject::class)
        ->and(get_parent_class(GtkLabel::class))->toBe(GtkWidget::class)
        ->and(get_parent_class(GtkButton::class))->toBe(GtkWidget::class)
        ->and(get_parent_class(GtkCheckButton::class))->toBe(GtkWidget::class)
        ->and(get_parent_class(GtkSwitch::class))->toBe(GtkWidget::class)
        ->and(get_parent_class(GtkToggleButton::class))->toBe(GtkButton::class)
        ->and(get_parent_class(GtkEntry::class))->toBe(GtkWidget::class)
        ->and(get_parent_class(GtkEntryBuffer::class))->toBe(GObject::class)
        ->and(get_parent_class(GtkTextView::class))->toBe(GtkWidget::class)
        ->and(get_parent_class(GtkTextBuffer::class))->toBe(GObject::class)
        ->and(get_parent_class(GtkScale::class))->toBe(GtkWidget::class)
        ->and(get_parent_class(GtkStringList::class))->toBe(GObject::class)
        ->and(get_parent_class(GtkStringObject::class))->toBe(GObject::class)
        ->and(get_parent_class(GtkDropDown::class))->toBe(GtkWidget::class)
        ->and(get_parent_class(GtkCalendar::class))->toBe(GtkWidget::class)
        ->and(get_parent_class(GtkProgressBar::class))->toBe(GtkWidget::class)
        ->and(get_parent_class(GtkSpinner::class))->toBe(GtkWidget::class)
        ->and(get_parent_class(GtkPicture::class))->toBe(GtkWidget::class)
        ->and(get_parent_class(GtkSeparator::class))->toBe(GtkWidget::class)
        ->and(get_parent_class(GtkScrolledWindow::class))->toBe(GtkWidget::class)
        ->and(get_parent_class(GDateTime::class))->toBeFalse()
        ->and(get_parent_class(GtkSignalListItemFactory::class))->toBe(GObject::class)
        ->and(get_parent_class(GtkListItem::class))->toBe(GObject::class)
        ->and(get_parent_class(GtkColumnViewColumn::class))->toBe(GObject::class)
        ->and(get_parent_class(GtkColumnView::class))->toBe(GtkWidget::class)
        ->and(get_parent_class(GtkSingleSelection::class))->toBe(GObject::class)
        ->and(get_parent_class(GtkMediaStream::class))->toBe(GObject::class)
        ->and(get_parent_class(GtkMediaFile::class))->toBe(GtkMediaStream::class)
        ->and(get_parent_class(GtkVideo::class))->toBe(GtkWidget::class)
        ->and(get_parent_class(GtkPopoverMenuBar::class))->toBe(GtkWidget::class)
        ->and(get_parent_class(GMenu::class))->toBe(GMenuModel::class)
        ->and(get_parent_class(GMenuItem::class))->toBe(GObject::class)
        ->and(get_parent_class(GSimpleAction::class))->toBe(GObject::class)
        ->and(get_parent_class(GSimpleActionGroup::class))->toBe(GObject::class);
});

it('cannot construct native wrappers from PHP', function (string $class): void {
    expect(fn () => new $class())->toThrow(Error::class);
})->with([GObject::class, GApplication::class, GtkApplication::class, GMainContext::class, GtkWidget::class, GtkWindow::class, GMenu::class, GVariant::class, GDateTime::class]);

it('refuses to clone or serialize a native wrapper', function (): void {
    $ctx = GMainContext::default();

    expect(fn () => clone $ctx)->toThrow(Error::class)
        ->and(fn () => serialize($ctx))->toThrow(Exception::class);
});
