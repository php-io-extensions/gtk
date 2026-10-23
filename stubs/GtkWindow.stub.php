<?php

/** @generate-class-entries */

/**
 * @not-serializable
 */
class GtkWindow extends GtkWidget implements GtkNative, GtkRoot
{
    /** gtk_window_new(). Nullable because PHP holds a subclass's static new() to this return type, and GtkApplicationWindow::new() answers null. */
    public static function new(): ?GtkWindow {}

    public function getTitle(): ?string {}

    public function setTitle(?string $title): void {}

    /** @return array{0: int, 1: int} [width, height] */
    public function getDefaultSize(): array {}

    public function setDefaultSize(int $width, int $height): void {}

    public function getChild(): ?GtkWidget {}

    public function setChild(?GtkWidget $child): void {}

    public function present(): void {}

    public function close(): void {}

    public function destroy(): void {}

    public function isActive(): bool {}

    /** gtk_window_get_focus(): the widget with keyboard focus inside the window, or null. */
    public function getFocus(): ?GtkWidget {}

    public function getTransientFor(): ?GtkWindow {}

    public function setTransientFor(?GtkWindow $parent): void {}

    public function getApplication(): ?GtkApplication {}

    public function setApplication(?GtkApplication $application): void {}

    public function getModal(): bool {}

    public function setModal(bool $modal): void {}

    public function getHideOnClose(): bool {}

    public function setHideOnClose(bool $setting): void {}

    public function getDefaultWidget(): ?GtkWidget {}

    public function setDefaultWidget(?GtkWidget $defaultWidget): void {}

    /** The window's group, or GTK's default group when it has none. */
    public function getGroup(): GtkWindowGroup {}
}

/**
 * @not-serializable
 */
class GtkWindowGroup extends GObject
{
    public static function new(): GtkWindowGroup {}

    public function addWindow(GtkWindow $window): void {}

    public function removeWindow(GtkWindow $window): void {}
}

/**
 * @not-serializable
 */
class GtkApplicationWindow extends GtkWindow implements GActionGroup, GActionMap
{
    /**
     * PHP holds a static method to its parent's signature (GtkWindow::new()), so the
     * application is declared optional; gtk_application_window_new() requires it, and
     * answers null with a critical.
     */
    public static function new(?GtkApplication $application = null): ?GtkApplicationWindow {}

    public function getShowMenubar(): bool {}

    public function setShowMenubar(bool $showMenubar): void {}

    public function getId(): int {}
}

/**
 * @not-serializable
 */
class GtkAboutDialog extends GtkWindow
{
    public static function new(): GtkAboutDialog {}

    public function getProgramName(): ?string {}

    public function setProgramName(?string $name): void {}

    public function getVersion(): ?string {}

    public function setVersion(?string $version): void {}

    public function getCopyright(): ?string {}

    public function setCopyright(?string $copyright): void {}

    public function getComments(): ?string {}

    public function setComments(?string $comments): void {}

    public function getWebsite(): ?string {}

    public function setWebsite(?string $website): void {}
}
