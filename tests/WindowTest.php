<?php

declare(strict_types=1);

beforeEach(fn () => testApplication());

/** Iterate the default context for $seconds. */
function iterateFor(float $seconds): void
{
    $until = microtime(true) + $seconds;
    while (microtime(true) < $until) {
        g_timeout_add(10, fn (): bool => G_SOURCE_REMOVE);
        GMainContext::default()->iteration(true);
    }
}

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

it('refuses an application window without an application', function (): void {
    expect(fn () => GtkApplicationWindow::new())->toThrow(ValueError::class);
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
