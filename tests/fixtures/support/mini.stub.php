<?php

namespace {
    class GtkMini
    {
        public function getValue(): int {}

        public function frobnicate(): void {}
    }

    class GtkMiniChild extends GtkMini
    {
        public static function new(): GtkMiniChild {}

        /** gtk_mini_set_value, declared on the subclass. */
        public function setValue(int $value): void {}
    }

    function gtk_mini_init(): void {}
}
