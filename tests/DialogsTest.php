<?php

declare(strict_types=1);

// The spec's rule for ext tests: dialogs are made and set, but not shown. GTK's clipboard and file
// launcher are read back on the Mac only (the Pi's portal can raise its own UI).

beforeEach(fn () => testApplication());

/** Iterate the default context until $done is true or $seconds pass. */
function pumpUntilDone(Closure $done, float $seconds): bool
{
    $ctx = GMainContext::default();
    $end = microtime(true) + $seconds;
    while (! $done() && microtime(true) < $end) {
        $ctx->iteration(false);
        usleep(1000);
    }

    return $done();
}

/** Run a command while this process serves GDK's clipboard; its standard output. */
function runWhilePumping(string $command): string
{
    $proc = proc_open($command, [1 => ['pipe', 'w']], $pipes);
    stream_set_blocking($pipes[1], false);
    $out = '';
    pumpUntilDone(function () use ($proc, $pipes, &$out): bool {
        $out .= stream_get_contents($pipes[1]);

        return ! proc_get_status($proc)['running'];
    }, 2.0);
    $out .= stream_get_contents($pipes[1]);
    fclose($pipes[1]);
    proc_close($proc);

    return $out;
}

it('makes an alert dialog with its properties, and no printf', function (): void {
    $dialog = g_object_new_with_properties('GtkAlertDialog', ['message', 'modal'], ['100% %s done', false]);

    expect($dialog)->toBeInstanceOf(GtkAlertDialog::class)
        ->and(g_object_get_property($dialog, 'message'))->toBe('100% %s done')
        ->and(g_object_get_property($dialog, 'modal'))->toBeFalse();
});

it('makes a GObject of a type with no properties set', function (): void {
    expect(g_object_new_with_properties('GtkAlertDialog', [], []))->toBeInstanceOf(GtkAlertDialog::class);
});

it('sets and reads back an alert dialog', function (): void {
    $dialog = g_object_new_with_properties('GtkAlertDialog', [], []);
    $dialog->setMessage('Save changes?');
    $dialog->setDetail('3 files');
    $dialog->setButtons(['Save', 'Discard', 'Cancel']);
    $dialog->setDefaultButton(0);
    $dialog->setCancelButton(2);
    $dialog->setModal(false);

    expect(g_object_get_property($dialog, 'message'))->toBe('Save changes?')
        ->and(g_object_get_property($dialog, 'detail'))->toBe('3 files')
        ->and(g_object_get_property($dialog, 'default-button'))->toBe(0)
        ->and(g_object_get_property($dialog, 'cancel-button'))->toBe(2)
        ->and(g_object_get_property($dialog, 'modal'))->toBeFalse();
});

it('takes only strings as alert buttons', function (): void {
    expect(fn () => g_object_new_with_properties('GtkAlertDialog', [], [])->setButtons(['OK', 2]))->toThrow(TypeError::class);
});

it('sets and reads back a file dialog', function (): void {
    $dialog = GtkFileDialog::new();
    $dialog->setTitle('Pick');
    $dialog->setInitialFolder(GFile::newForPath(__DIR__));
    $dialog->setInitialName('a.txt');
    $dialog->setModal(false);
    $folder = g_object_get_property($dialog, 'initial-folder');

    expect(g_object_get_property($dialog, 'title'))->toBe('Pick')
        ->and(g_object_get_property($dialog, 'initial-name'))->toBe('a.txt')
        ->and(g_object_get_property($dialog, 'modal'))->toBeFalse()
        ->and($folder)->toBeInstanceOf(GFile::class)
        ->and($folder->getPath())->toBe(__DIR__);

    $dialog->setInitialFolder(null);
    $dialog->setInitialName(null);

    expect(g_object_get_property($dialog, 'initial-folder'))->toBeNull()
        ->and(g_object_get_property($dialog, 'initial-name'))->toBeNull();
});

it('boxes a local file as GFile', function (): void {
    $file = GFile::newForPath(__DIR__);

    expect($file)->toBeInstanceOf(GFile::class)
        ->and($file->typeName())->toBe('GLocalFile')
        ->and($file->getPath())->toBe(__DIR__);
});

it('makes GListStore a GListModel', function (): void {
    expect((new ReflectionClass(GListStore::class))->implementsInterface(GListModel::class))->toBeTrue();
});

it('sets and reads back a file filter', function (): void {
    $filter = GtkFileFilter::new();
    $filter->setName('Text');
    $filter->addPattern('*.txt');
    $filter->addPattern('*.md');

    expect($filter->getName())->toBe('Text');

    $filter->setName(null);
    expect($filter->getName())->toBeNull();
});

it('holds file filters in a list store that a file dialog takes', function (): void {
    $filter = GtkFileFilter::new();
    $filter->setName('Text');
    $store = GListStore::new('GtkFileFilter');
    $store->append($filter);
    $dialog = GtkFileDialog::new();
    $dialog->setFilters($store);

    expect($store->getNItems())->toBe(1)
        ->and($store->getItem(0))->toBe($filter)
        ->and($dialog->getFilters())->toBe($store);

    $dialog->setFilters(null);
    expect($dialog->getFilters())->toBeNull();
});

it('makes no list store for a type name GLib does not know, as GLib does: a critical and null', function (): void {
    $run = gtkChild('return GListStore::new("NoSuchType");');

    expect($run['result'])->toBeNull()
        ->and($run['stderr'])->toContain('g_list_store_new: assertion');
});

it('gives the display clipboard', function (): void {
    expect(GdkDisplay::getDefault()->getClipboard())->toBeInstanceOf(GdkClipboard::class);
});

describe('macOS', function (): void {
    beforeEach(function (): void {
        if (PHP_OS_FAMILY !== 'Darwin') {
            $this->markTestSkipped('the spec reads GTK\'s clipboard and file launcher back on the Mac only');
        }
    });

    it('puts text on the clipboard that pbpaste reads', function (): void {
        $kept = shell_exec('pbpaste');
        $text = 'c7 ' . uniqid();
        GdkDisplay::getDefault()->getClipboard()->setText($text);
        $read = runWhilePumping('pbpaste');
        GdkDisplay::getDefault()->getClipboard()->setText((string) $kept);
        runWhilePumping('pbpaste');

        expect($read)->toBe($text);
    });

    it('reads back the text it put on the clipboard, and its formats', function (): void {
        $kept = shell_exec('pbpaste');
        $clipboard = GdkDisplay::getDefault()->getClipboard();
        $clipboard->setText('round trip');
        $result = null;
        $clipboard->readTextAsync(null, function (GdkClipboard $source, GAsyncResult $r) use (&$result): void {
            $result = [$source, $r];
        });
        $done = pumpUntilDone(function () use (&$result): bool { return $result !== null; }, 2.0);
        $text = $done ? $result[0]->readTextFinish($result[1]) : null;
        $formats = $clipboard->getFormats();
        $clipboard->setText((string) $kept);
        runWhilePumping('pbpaste');

        expect($done)->toBeTrue()
            ->and($text)->toBe('round trip')
            ->and($formats)->toBeInstanceOf(GdkContentFormats::class)
            ->and($formats->containMimeType('text/plain;charset=utf-8'))->toBeTrue()
            ->and($formats->containMimeType('image/png'))->toBeFalse();
    });

    it('fails to launch a missing file', function (): void {
        $result = null;
        GtkFileLauncher::new(GFile::newForPath('/nonexistent-c7'))->launch(null, null, function (GtkFileLauncher $launcher, GAsyncResult $r) use (&$result): void {
            $result = [$launcher, $r];
        });

        expect(pumpUntilDone(function () use (&$result): bool { return $result !== null; }, 2.0))->toBeTrue()
            ->and(fn () => $result[0]->launchFinish($result[1]))->toThrow(GError::class);
    });
});
