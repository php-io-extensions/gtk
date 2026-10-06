<?php

declare(strict_types=1);

/*
 * A window with a menu bar on a real display, macOS or Linux:
 *
 *   php examples/window-smoke.php [--hold=SECONDS]
 *
 * 1. a GtkApplicationWindow comes up and turns active
 * 2. the menu model goes where the OS keeps menus: inside the window (GtkPopoverMenuBar) on
 *    Linux, the application menubar on macOS; actions live in the window's "win" group
 * 3. activating Refresh runs its PHP handler; activating Show Grid flips its state through change-state
 * 4. close() asks close-request, then the window leaves the application
 *
 * --hold leaves the window up that long before step 4, to click around in.
 * Prints SMOKE_OK when every step held.
 */

$hold = 0.0;
foreach (array_slice($argv, 1) as $arg) {
    if (str_starts_with($arg, '--hold=')) {
        $hold = (float) substr($arg, 7);
    }
}

function check(bool $ok, string $what): void
{
    printf("%s %s\n", $ok ? 'ok  ' : 'FAIL', $what);
    if (! $ok) {
        exit(1);
    }
}

function iterate(float $seconds): void
{
    $until = microtime(true) + $seconds;
    while (microtime(true) < $until) {
        g_timeout_add(10, fn (): bool => G_SOURCE_REMOVE);
        GMainContext::default()->iteration(true);
    }
}

$mac = PHP_OS_FAMILY === 'Darwin';
$app = GtkApplication::new('com.projectsaturnstudios.GtkWindowSmoke', GApplicationFlags::NON_UNIQUE);
g_signal_connect($app, 'activate', fn () => null);
$app->register();
$app->hold();
$log = [];

// 1. window
$window = GtkApplicationWindow::new($app);
$window->setTitle('ext-gtk window smoke');
$window->setDefaultSize(480, 320);
g_signal_connect($window, 'notify::is-active', function (GtkWindow $w) use (&$log): void {
    $log[] = 'active:' . ($w->isActive() ? 'yes' : 'no');
});
g_signal_connect($window, 'close-request', function () use (&$log): bool {
    $log[] = 'close-request';

    return false;
});

// 2. menu model + actions
$view = GMenu::new();
$view->append('Refresh', 'win.view.refresh');
$view->append('Show Grid', 'win.grid');
$bar = GMenu::new();
$bar->appendSubmenu('View', $view);

$actions = GSimpleActionGroup::new();
$refresh = GSimpleAction::new('view.refresh', null);
g_signal_connect($refresh, 'activate', function () use (&$log): void {
    $log[] = 'refresh';
});
$grid = GSimpleAction::newStateful('grid', null, GVariant::newBoolean(false));
g_signal_connect($grid, 'change-state', function (GSimpleAction $a, GVariant $on) use (&$log): void {
    $a->setState($on);
    $log[] = 'grid:' . ($on->getBoolean() ? 'on' : 'off');
});
$actions->addAction($refresh);
$actions->addAction($grid);
$window->insertActionGroup('win', $actions);
$app->setAccelsForAction('win.view.refresh', ['<Control>r']);

$content = GtkBox::new(GtkOrientation::VERTICAL, 0);
$content->setHexpand(true);
$content->setVexpand(true);
$scaffold = GtkBox::new(GtkOrientation::VERTICAL, 0);
if ($mac) {
    $app->setMenubar($bar);
    $window->setShowMenubar(true);
} else {
    $scaffold->append(GtkPopoverMenuBar::newFromModel($bar));
}
$scaffold->append($content);
$window->setChild($scaffold);

$window->present();
iterate(0.5);
check($window->getVisible() && in_array('active:yes', $log, true), 'window is up and active');
check($mac ? $app->getMenubar() === $bar : $scaffold->getParent() === $window, $mac ? 'menu model is the application menubar' : 'menu bar sits inside the window');

// 3. actions
check($window->activateAction('win.view.refresh', null) && in_array('refresh', $log, true), 'Refresh ran its PHP handler');
$window->activateAction('win.grid', null);
check($grid->getState()->getBoolean() && in_array('grid:on', $log, true), 'Show Grid flipped on through change-state');

if ($hold > 0) {
    echo "holding for {$hold}s: try the menu\n";
    iterate($hold);
}

// 4. close
$window->close();
iterate(0.1);
check(in_array('close-request', $log, true), 'close() asked close-request');
check(! in_array($window, $app->getWindows(), true), 'the window left the application');

echo "SMOKE_OK\n";
