<?php

/** @generate-class-entries */

enum GtkConstraintAttribute: int
{
    case NONE = 0;
    case LEFT = 1;
    case RIGHT = 2;
    case TOP = 3;
    case BOTTOM = 4;
    case START = 5;
    case END = 6;
    case WIDTH = 7;
    case HEIGHT = 8;
    case CENTER_X = 9;
    case CENTER_Y = 10;
    case BASELINE = 11;
}

enum GtkConstraintRelation: int
{
    case LE = -1;
    case EQ = 0;
    case GE = 1;
}

enum GtkConstraintStrength: int
{
    case REQUIRED = 1001001000;
    case STRONG = 1000000000;
    case MEDIUM = 1000;
    case WEAK = 1;
}

/**
 * GtkLayoutManager: how a widget measures and places its children.
 *
 * @not-serializable
 */
class GtkLayoutManager extends GObject
{
}

/**
 * @not-serializable
 */
class GtkConstraintLayout extends GtkLayoutManager
{
    public static function new(): GtkConstraintLayout {}

    /** gtk_constraint_layout_add_constraint(): the layout takes its own reference. */
    public function addConstraint(GtkConstraint $constraint): void {}

    /** gtk_constraint_layout_add_guide(): the layout takes its own reference. */
    public function addGuide(GtkConstraintGuide $guide): void {}
}

/**
 * @not-serializable
 */
class GtkConstraint extends GObject
{
    /**
     * gtk_constraint_new(): target.targetAttribute relation source.sourceAttribute * multiplier + constant.
     * A null target or source is the widget whose layout holds the constraint. $strength is an int in
     * GTK, a GtkConstraintStrength value or any other.
     */
    public static function new(
        ?GtkConstraintTarget $target,
        GtkConstraintAttribute $targetAttribute,
        GtkConstraintRelation $relation,
        ?GtkConstraintTarget $source,
        GtkConstraintAttribute $sourceAttribute,
        float $multiplier,
        float $constant,
        int $strength,
    ): GtkConstraint {}
}

/**
 * @not-serializable
 */
class GtkConstraintGuide extends GObject implements GtkConstraintTarget
{
    public static function new(): GtkConstraintGuide {}

    public function setNatSize(int $width, int $height): void {}

    public function setMaxSize(int $width, int $height): void {}
}
