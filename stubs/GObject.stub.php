<?php

/** @generate-class-entries */

/**
 * @not-serializable
 */
class GObject
{
    private function __construct() {}

    /** G_OBJECT_TYPE_NAME() */
    public function typeName(): string {}

    /** The object's address, for handing it to another extension. */
    public function pointer(): int {}

    /**
     * The object at an address another extension handed over: the PHP object already boxing it,
     * or a new box of the class its GType maps to, holding its own reference. A floating
     * reference stays floating: the extension that handed the address keeps the reference it
     * holds. The address is trusted; 0 gives null.
     */
    public static function fromPointer(int $pointer): ?GObject {}
}

/**
 * GParamSpec: the description of an object property; a notify::* handler receives it.
 *
 * @not-serializable
 */
final class GParamSpec
{
    private function __construct() {}

    public function getName(): string {}

    public function getNick(): string {}

    public function getBlurb(): ?string {}

    /** G_PARAM_SPEC_VALUE_TYPE(): the property's value type, by its type name */
    public function getValueType(): string {}
}
