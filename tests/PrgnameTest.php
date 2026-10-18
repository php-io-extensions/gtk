<?php

declare(strict_types=1);

/*
 * The program name GLib keeps: GTK takes it for the window's WM_CLASS on X11, which docks match
 * against a desktop file's StartupWMClass. Set in a fresh process, before GTK starts.
 */
it('sets the program name GTK uses for WM_CLASS and reads it back', function (): void {
    $code = 'g_set_prgname("com.venusian.probe"); var_export(g_get_prgname());';
    $out = shell_exec(escapeshellarg(PHP_BINARY).' -r '.escapeshellarg($code).' 2>&1');

    expect($out)->toBe("'com.venusian.probe'");
});

it('stores an empty program name, as GLib does', function (): void {
    $run = gtkChild(<<<'PHP'
        g_set_prgname('');

        return g_get_prgname();
    PHP, init: false);

    expect($run['result'])->toBe('');
});
