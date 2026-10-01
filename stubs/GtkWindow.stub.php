<?php

/** @generate-class-entries */

/**
 * @not-serializable
 */
class GtkWindow extends GtkWidget
{
    public static function new(): GtkWindow {}

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

    public function getTransientFor(): ?GtkWindow {}

    public function setTransientFor(?GtkWindow $parent): void {}

    public function getApplication(): ?GtkApplication {}

    public function setApplication(?GtkApplication $application): void {}

    public function getModal(): bool {}

    public function setModal(bool $modal): void {}

    public function getHideOnClose(): bool {}

    public function setHideOnClose(bool $setting): void {}
}

/**
 * @not-serializable
 */
class GtkApplicationWindow extends GtkWindow
{
    /**
     * PHP holds a static method to its parent's signature (GtkWindow::new()), so the
     * application is declared optional; gtk_application_window_new() requires it, and
     * null is refused.
     */
    public static function new(?GtkApplication $application = null): GtkApplicationWindow {}

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
