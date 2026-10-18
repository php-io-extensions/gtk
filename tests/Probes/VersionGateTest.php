<?php

declare(strict_types=1);

/*
 * Sites gtk-version-4-16 and gtk-version-4-14 (outcome 2): a class compiled against newer GTK
 * headers, called on an older GTK runtime. PHP loads extensions lazily bound on Linux, so the
 * missing symbol is resolved at the call: "symbol lookup error", exit 127. On macOS chained
 * fixups bind at load, so an older libgtk fails the load and the sites are unreachable.
 *
 * The probe needs a host whose runtime GTK is older than the build's headers. Env
 * PHPGTK_OLD_GTK_HOST names it (an ssh destination with docker); the recipe, from Task 1:
 *
 *   1. Build the probe gtk.so in a debian:trixie container (GTK 4.18 headers):
 *        docker run --rm -v "$PWD":/src -w /src debian:trixie sh -c \
 *          'apt-get update && apt-get install -y php8.4-dev libgtk-4-dev pkg-config build-essential \
 *           && phpize && ./configure --enable-gtk --enable-gtk-probes && make'
 *   2. Copy modules/gtk.so to the host. Ubuntu 24.04 (GTK 4.14.5) runs the 4.16 probe;
 *      a 4.10-4.13 runtime runs the 4.14 probe (ubuntu:22.04 has 4.6.9, which fails earlier at
 *      dlopen on gtk_uri_launcher_launch, a 4.10 symbol).
 *   3. With the site kept: ValueError naming the running version. With
 *      PHPGTK_PROBE_OFF=gtk-version-4-16: "undefined symbol: gdk_memory_texture_builder_new", exit 127.
 *
 * Env PHPGTK_OLD_GTK_EXT is that gtk.so's path on the host.
 */

beforeEach(function (): void {
    requireProbeBuild();
    if (! is_string(getenv('PHPGTK_OLD_GTK_HOST')) || getenv('PHPGTK_OLD_GTK_HOST') === '') {
        $this->markTestSkipped('needs env PHPGTK_OLD_GTK_HOST: a host whose runtime GTK is older than the build headers (recipe above)');
    }
    if (! is_string(getenv('PHPGTK_OLD_GTK_EXT')) || getenv('PHPGTK_OLD_GTK_EXT') === '') {
        $this->markTestSkipped('needs env PHPGTK_OLD_GTK_EXT: the probe gtk.so path on PHPGTK_OLD_GTK_HOST');
    }
});

/** Runs $code on the old-GTK host with the probe gtk.so, $siteOff turned off; [exit code, output]. */
function oldGtkRun(string $code, ?string $siteOff): array
{
    $env = $siteOff !== null ? 'PHPGTK_PROBE_OFF='.escapeshellarg($siteOff).' ' : '';
    $remote = $env.'php -n -d extension='.escapeshellarg((string) getenv('PHPGTK_OLD_GTK_EXT')).' -r '.escapeshellarg('gtk_init(); try { '.$code.' echo "RAN"; } catch (Throwable $t) { echo "REFUSED ", get_class($t), ": ", $t->getMessage(); }');
    exec('ssh '.escapeshellarg((string) getenv('PHPGTK_OLD_GTK_HOST')).' '.escapeshellarg($remote).' 2>&1', $lines, $exit);

    return [$exit, implode("\n", $lines)];
}

it('refuses GdkMemoryTextureBuilder on a GTK older than 4.16, whose missing symbol kills PHP (exit 127) without the refusal', function (): void {
    [$keptExit, $kept] = oldGtkRun('GdkMemoryTextureBuilder::new();', null);
    [$offExit, $off] = oldGtkRun('GdkMemoryTextureBuilder::new();', 'gtk-version-4-16');

    expect($keptExit)->toBe(0)
        ->and($kept)->toContain('REFUSED ValueError')
        ->and($offExit)->toBe(127)
        ->and($off)->toContain('undefined symbol: gdk_memory_texture_builder_new');
});

it('refuses the dmabuf classes on a GTK older than 4.14, whose missing symbols kill PHP (exit 127) without the refusal', function (): void {
    [$keptExit, $kept] = oldGtkRun('GdkDisplay::getDefault()->getDmabufFormats();', null);
    [$offExit, $off] = oldGtkRun('GdkDisplay::getDefault()->getDmabufFormats();', 'gtk-version-4-14');

    expect($keptExit)->toBe(0)
        ->and($kept)->toContain('REFUSED ValueError')
        ->and($offExit)->toBe(127)
        ->and($off)->toContain('undefined symbol: gdk_display_get_dmabuf_formats');
});

it('refuses GdkDmabufTextureBuilder on a GTK older than 4.14, whose missing symbol kills PHP (exit 127) without the refusal', function (): void {
    [$keptExit, $kept] = oldGtkRun('GdkDmabufTextureBuilder::new();', null);
    [$offExit, $off] = oldGtkRun('GdkDmabufTextureBuilder::new();', 'gtk-version-4-14-dmabuf-builder');

    expect($keptExit)->toBe(0)
        ->and($kept)->toContain('REFUSED ValueError')
        ->and($offExit)->toBe(127)
        ->and($off)->toContain('undefined symbol: gdk_dmabuf_texture_builder_new');
});
