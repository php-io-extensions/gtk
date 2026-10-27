<?php

/** @generate-class-entries */

/**
 * A GIO file. GFile is a GObject interface; the GLib types it arrives as (GLocalFile, gvfs's
 * GDaemonFile, GDummyFile) box as this class.
 *
 * @not-serializable
 */
class GFile extends GObject
{
    public static function newForPath(string $path): GFile {}

    /** The local path, or null when the file has none (a remote URI). */
    public function getPath(): ?string {}
}

/**
 * A GListModel of GObjects; the type GTK hands back a file dialog's chosen files in.
 *
 * @not-serializable
 */
class GListStore extends GObject implements GListModel
{
    /** $itemType is a GType name GLib has registered, such as 'GtkFileFilter'; for any other name GLib warns and this returns null. */
    public static function new(string $itemType): ?GListStore {}

    public function append(GObject $item): void {}
}

/**
 * @not-serializable
 */
class GdkClipboard extends GObject
{
    public function setText(string $text): void {}

    /** @param callable|null $callback called once with (GdkClipboard, GAsyncResult) */
    public function readTextAsync(?GCancellable $cancellable, ?callable $callback): void {}

    /** The text, or null when the clipboard holds none. A failed read throws GError. */
    public function readTextFinish(GAsyncResult $result): ?string {}

    /** The formats the clipboard's content can be read as. */
    public function getFormats(): GdkContentFormats {}
}

/**
 * @not-serializable
 */
final class GdkContentFormats
{
    /** Made by GdkClipboard::getFormats() only. */
    private function __construct() {}

    public function containMimeType(string $mimeType): bool {}
}

/**
 * @not-serializable
 */
class GtkFileFilter extends GObject
{
    public static function new(): GtkFileFilter {}

    /** The name a file dialog shows for the filter. */
    public function setName(?string $name): void {}

    public function getName(): ?string {}

    /** A glob such as '*.txt'. */
    public function addPattern(string $pattern): void {}
}

/**
 * GTK 4.10. Its constructor gtk_alert_dialog_new() is a printf and is not bound: make one with
 * g_object_new_with_properties('GtkAlertDialog', ['message'], [$message]).
 *
 * @not-serializable
 */
class GtkAlertDialog extends GObject
{
    public function setMessage(string $message): void {}

    public function setDetail(string $detail): void {}

    /** @param string[] $labels */
    public function setButtons(array $labels): void {}

    public function setDefaultButton(int $button): void {}

    public function setCancelButton(int $button): void {}

    public function setModal(bool $modal): void {}

    /**
     * Shows the alert and returns at once.
     * @param callable|null $callback called once with (GtkAlertDialog, GAsyncResult)
     */
    public function choose(?GtkWindow $parent, ?GCancellable $cancellable, ?callable $callback): void {}

    /** The index of the chosen button; the cancel button's for Esc and the dialog's close. A dismissed or cancelled dialog throws GError. */
    public function chooseFinish(GAsyncResult $result): int {}
}

/**
 * GTK 4.10.
 *
 * @not-serializable
 */
class GtkFileDialog extends GObject
{
    public static function new(): GtkFileDialog {}

    public function setTitle(string $title): void {}

    public function setInitialFolder(?GFile $folder): void {}

    public function setInitialName(?string $name): void {}

    public function setModal(bool $modal): void {}

    /** A GListModel of GtkFileFilter; the dialog offers each one. */
    public function setFilters(?GListModel $filters): void {}

    public function getFilters(): ?GListModel {}

    /** @param callable|null $callback called once with (GtkFileDialog, GAsyncResult) */
    public function open(?GtkWindow $parent, ?GCancellable $cancellable, ?callable $callback): void {}

    /** A dismissed, cancelled or failed dialog throws GError. */
    public function openFinish(GAsyncResult $result): GFile {}

    /** @param callable|null $callback called once with (GtkFileDialog, GAsyncResult) */
    public function openMultiple(?GtkWindow $parent, ?GCancellable $cancellable, ?callable $callback): void {}

    /** A GListModel of GFile. A dismissed, cancelled or failed dialog throws GError. */
    public function openMultipleFinish(GAsyncResult $result): GListModel {}

    /** @param callable|null $callback called once with (GtkFileDialog, GAsyncResult) */
    public function selectFolder(?GtkWindow $parent, ?GCancellable $cancellable, ?callable $callback): void {}

    /** A dismissed, cancelled or failed dialog throws GError. */
    public function selectFolderFinish(GAsyncResult $result): GFile {}

    /** @param callable|null $callback called once with (GtkFileDialog, GAsyncResult) */
    public function save(?GtkWindow $parent, ?GCancellable $cancellable, ?callable $callback): void {}

    /** A dismissed, cancelled or failed dialog throws GError. */
    public function saveFinish(GAsyncResult $result): GFile {}
}

/**
 * GTK 4.10.
 *
 * @not-serializable
 */
class GtkFileLauncher extends GObject
{
    public static function new(?GFile $file): GtkFileLauncher {}

    /**
     * Opens the file in its default app.
     * @param callable|null $callback called once with (GtkFileLauncher, GAsyncResult); null launches with no callback
     */
    public function launch(?GtkWindow $parent, ?GCancellable $cancellable, ?callable $callback): void {}

    /** True when the file opened; the launch's GError is thrown as GError. */
    public function launchFinish(GAsyncResult $result): bool {}
}
