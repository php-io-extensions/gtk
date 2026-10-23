<?php

declare(strict_types=1);

beforeEach(fn () => testApplication());

it('refuses to build a widget before GTK is initialised instead of crashing', function (string $build): void {
    // A fresh process: this one initialised GTK in beforeEach.
    $code = 'try { '.$build.'; echo "BUILT"; } catch (GtkException $e) { echo $e->getMessage(); }';
    $out = shell_exec(escapeshellarg(PHP_BINARY).' -r '.escapeshellarg($code).' 2>&1');

    expect($out)->toContain('needs GTK initialised');
})->with([
    'GtkWindow' => ['GtkWindow::new()'],
    'GtkApplicationWindow' => ["GtkApplicationWindow::new(GtkApplication::new('org.venusian.Uninitialised', GApplicationFlags::NON_UNIQUE))"],
    'GtkAboutDialog' => ['GtkAboutDialog::new()'],
    'GtkBox' => ['GtkBox::new(GtkOrientation::VERTICAL, 0)'],
    'GtkPopoverMenuBar' => ['GtkPopoverMenuBar::newFromModel(GMenu::new())'],
]);

it('creates windows with the title, size and child they were given', function (): void {
    $window = GtkApplicationWindow::new(testApplication());
    $box = GtkBox::new(GtkOrientation::VERTICAL, 4);
    $window->setTitle('Probe');
    $window->setDefaultSize(400, 300);
    $window->setChild($box);

    expect($window)->toBeInstanceOf(GtkApplicationWindow::class)
        ->and($window->typeName())->toBe('GtkApplicationWindow')
        ->and($window->getTitle())->toBe('Probe')
        ->and($window->getDefaultSize())->toBe([400, 300])
        ->and($window->getChild())->toBe($box)
        ->and($box->getParent())->toBe($window)
        ->and($window->getApplication())->toBe(testApplication())
        ->and($window->getId())->toBeGreaterThan(0)
        ->and(testApplication()->getWindows())->toContain($window);

    $window->destroy();
});

it('answers an application window without an application as GTK does: a critical and null', function (): void {
    $run = gtkChild(<<<'PHP'
        return GtkApplicationWindow::new();
    PHP);

    expect($run['survived'])->toBeTrue()
        ->and($run['result'])->toBeNull()
        ->and($run['stderr'])->toContain("gtk_application_window_new: assertion 'GTK_IS_APPLICATION (application)' failed");
});

it('closes through close-request and leaves the application', function (): void {
    $window = GtkWindow::new();
    testApplication()->addWindow($window);
    $requests = 0;

    g_signal_connect($window, 'close-request', function (GtkWindow $w) use (&$requests): bool {
        $requests++;

        return $requests === 1; // keep the window the first time, let it go the second
    });

    $window->present();
    expect($window->getRealized())->toBeTrue();

    $window->close();
    expect($requests)->toBe(1)
        ->and(testApplication()->getWindows())->toContain($window);

    $window->close();
    iterateFor(0.05);
    expect($requests)->toBe(2)
        ->and(testApplication()->getWindows())->not->toContain($window);
});

it('sets window flags', function (): void {
    $window = GtkWindow::new();

    expect($window->getRealized())->toBeFalse()
        ->and($window->getMapped())->toBeFalse();

    $window->setModal(true);
    $window->setHideOnClose(true);
    $window->setTitle(null);

    expect($window->getModal())->toBeTrue()
        ->and($window->getHideOnClose())->toBeTrue()
        ->and($window->getTitle())->toBeNull()
        ->and($window->getVisible())->toBeFalse()
        ->and($window->isActive())->toBeFalse();

    $window->destroy();
});

it('lays widgets out in a box', function (): void {
    $box = GtkBox::new(GtkOrientation::HORIZONTAL, 0);
    $first = GtkBox::new(GtkOrientation::VERTICAL, 0);
    $second = GtkBox::new(GtkOrientation::VERTICAL, 0);

    $box->append($second);
    $box->prepend($first);
    $first->setHexpand(true);
    $first->setVexpand(true);

    expect($first->getParent())->toBe($box)
        ->and($first->getHexpand())->toBeTrue()
        ->and($first->getVexpand())->toBeTrue();

    $box->remove($first);
    expect($first->getParent())->toBeNull();
});

it('builds an about dialog transient for a window', function (): void {
    $window = GtkWindow::new();
    $about = GtkAboutDialog::new();
    $about->setProgramName('Probe');
    $about->setVersion('1.0');
    $about->setCopyright('(c) Probe');
    $about->setComments('A probe');
    $about->setWebsite('https://example.com');
    $about->setTransientFor($window);

    expect($about->getProgramName())->toBe('Probe')
        ->and($about->getVersion())->toBe('1.0')
        ->and($about->getCopyright())->toBe('(c) Probe')
        ->and($about->getComments())->toBe('A probe')
        ->and($about->getWebsite())->toBe('https://example.com')
        ->and($about->getTransientFor())->toBe($window);

    $about->destroy();
    $window->destroy();
});

// In its own process: whether the window becomes active depends on what earlier windows and
// launches in this process did to the application's activation (a URI launch on macOS leaves it inactive).
it('grabs focus into an entry, whose GtkText the window then names as its focus', function (): void {
    $run = gtkChild(<<<'PHP'
        $app = GtkApplication::new('com.projectsaturnstudios.GtkTests', GApplicationFlags::NON_UNIQUE);
        g_signal_connect($app, 'activate', fn (): null => null);
        $app->register(null);
        $window = GtkApplicationWindow::new($app);
        $entry = GtkEntry::new();
        $window->setChild($entry);
        $window->present();

        $grabbed = $entry->grabFocus();
        $focus = $window->getFocus();
        // has-focus is the window's focus widget in an active window.
        $ctx = GMainContext::default();
        $start = microtime(true);
        while (! $window->isActive() && microtime(true) - $start < 2) {
            $ctx->iteration(false);
            usleep(1000);
        }
        $seen = [$grabbed, $focus->typeName(), $window->isActive(), $focus->hasFocus(), $entry->hasFocus()];
        $window->destroy();

        return $seen;
    PHP);

    expect($run['survived'])->toBeTrue()
        ->and($run['result'])->toBe([true, 'GtkText', true, true, false]);
});

it('moves focus forward and back through a window\'s children', function (): void {
    $run = gtkChild(<<<'PHP'
        $app = GtkApplication::new('com.projectsaturnstudios.GtkTests', GApplicationFlags::NON_UNIQUE);
        g_signal_connect($app, 'activate', fn (): null => null);
        $app->register(null);
        $window = GtkApplicationWindow::new($app);
        $box = GtkBox::new(GtkOrientation::VERTICAL, 0);
        $first = GtkButton::newWithLabel('first');
        $second = GtkButton::newWithLabel('second');
        $box->append($first);
        $box->append($second);
        $window->setChild($box);
        $window->present();
        $first->grabFocus();

        $seen = [$window->childFocus(GtkDirectionType::TAB_FORWARD), $window->getFocus() === $second];
        $seen[] = $window->childFocus(GtkDirectionType::TAB_BACKWARD);
        $seen[] = $window->getFocus() === $first;
        $window->destroy();

        return $seen;
    PHP);

    expect($run['survived'])->toBeTrue()
        ->and($run['result'])->toBe([true, true, true, true]);
});

/** A presented window, iterated until GTK gave it its surface. */
function presentedWindow(): GtkWindow
{
    $window = GtkWindow::new();
    $window->present();
    iterateUntil(fn (): bool => $window->getRealized());

    return $window;
}

it('declares GtkNative and GtkRoot on windows and GtkNative on popovers', function (): void {
    expect(is_subclass_of(GtkWindow::class, GtkNative::class))->toBeTrue()
        ->and(is_subclass_of(GtkWindow::class, GtkRoot::class))->toBeTrue()
        ->and(is_subclass_of(GtkAboutDialog::class, GtkRoot::class))->toBeTrue()
        ->and(is_subclass_of(GtkPopover::class, GtkNative::class))->toBeTrue()
        ->and(is_subclass_of(GtkPopover::class, GtkRoot::class))->toBeFalse();
});

it('reads a native\'s surface with gtk_native_get_surface', function (): void {
    $window = presentedWindow();
    $unrealized = GtkWindow::new();
    $getSurface = new ReflectionMethod(GtkNative::class, 'getSurface');

    expect($getSurface->invoke($window))->toBeInstanceOf(GdkSurface::class)
        ->and($getSurface->invoke($window))->toBe($window->getSurface())
        ->and($getSurface->invoke($unrealized))->toBeNull();

    $window->destroy();
    $unrealized->destroy();
});

it('finds the native of a surface with gtk_native_get_for_surface', function (): void {
    $window = presentedWindow();

    expect(GtkNative::getForSurface($window->getSurface()))->toBe($window)
        ->and(GtkWindow::getForSurface($window->getSurface()))->toBe($window);

    $window->destroy();
});

it('reads a native\'s surface transform with gtk_native_get_surface_transform', function (): void {
    $window = presentedWindow();
    $returned = $window->getSurfaceTransform($x, $y);

    expect($returned)->toBeNull()
        ->and($x)->toBeFloat()
        ->and($y)->toBeFloat();

    $window->destroy();
});

it('unrealizes a native with gtk_native_unrealize and realizes it again with gtk_native_realize', function (): void {
    // gtk_native_realize() asserts the native is not already realized: GTK's critical comes through.
    $code = <<<'PHP'
        $app = GtkApplication::new('com.projectsaturnstudios.GtkNativeProbe', GApplicationFlags::NON_UNIQUE);
        $app->register(null);
        $window = GtkWindow::new();
        $window->present();
        while (! $window->getRealized()) { GMainContext::default()->iteration(true); }
        $window->unrealize();
        $window->realize();
        echo "PAIRED\n";
        $window->realize();
        echo "TWICE\n";
        PHP;
    $out = shell_exec(escapeshellarg(PHP_BINARY).' -r '.escapeshellarg($code).' 2>&1');
    [$paired, $twice] = explode('PAIRED', $out, 2);

    expect($paired)->not->toContain('CRITICAL')
        ->and($twice)->toContain('gtk_native_realize')
        ->and($twice)->toContain('TWICE');
});

it('reads a root\'s display with gtk_root_get_display', function (): void {
    $window = GtkWindow::new();

    expect((new ReflectionMethod(GtkRoot::class, 'getDisplay'))->invoke($window))->toBe(GdkDisplay::getDefault());

    $window->destroy();
});

it('sets a root\'s focus with gtk_root_set_focus', function (): void {
    $window = GtkWindow::new();
    $button = GtkButton::newWithLabel('Go');
    $window->setChild($button);

    $window->setFocus($button);
    $set = $window->getFocus();
    $window->setFocus(null);

    expect($set)->toBe($button)
        ->and($window->getFocus())->toBeNull();

    $window->destroy();
});

it('reads a root\'s focus with gtk_root_get_focus', function (): void {
    $window = GtkWindow::new();
    $button = GtkButton::newWithLabel('Go');
    $window->setChild($button);
    $window->setFocus($button);
    $getFocus = new ReflectionMethod(GtkRoot::class, 'getFocus');

    expect($getFocus->invoke($window))->toBe($button);

    $window->destroy();
});

it('puts a window in a window group and takes it out', function (): void {
    $window = GtkWindow::new();
    $group = GtkWindowGroup::new();
    $group->addWindow($window);

    expect($window->getGroup())->toBe($group);

    $group->removeWindow($window);
    expect($window->getGroup())->not->toBe($group)
        ->and($window->getGroup())->toBeInstanceOf(GtkWindowGroup::class);

    $window->destroy();
});

it('sets the default widget of a window', function (): void {
    $window = GtkWindow::new();
    $button = GtkButton::newWithLabel('OK');
    $window->setChild($button);
    $window->setDefaultWidget($button);

    expect($window->getDefaultWidget())->toBe($button);

    $window->setDefaultWidget(null);
    expect($window->getDefaultWidget())->toBeNull();

    $window->destroy();
});
