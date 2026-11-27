<?php

declare(strict_types=1);

beforeEach(fn () => testApplication());

it('gives back the PHP object already boxing an address', function (): void {
    $label = GtkLabel::new('kept');

    expect(GObject::fromPointer($label->pointer()))->toBe($label);
});

it('boxes an address PHP no longer holds as the class its GType maps to', function (): void {
    $box = GtkBox::new(GtkOrientation::VERTICAL, 0);
    $label = GtkLabel::new('held by the box');
    $box->append($label);
    $pointer = $label->pointer();
    unset($label);

    $again = GObject::fromPointer($pointer);

    expect($again)->toBeInstanceOf(GtkLabel::class)
        ->and($again->getText())->toBe('held by the box')
        ->and($box->getFirstChild())->toBe($again);
});

it('gives null for address 0', function (): void {
    expect(GObject::fromPointer(0))->toBeNull();
});

it('takes an object from ext-gstreamer and reads its properties', function (): void {
    gst_init_check($argv);
    $pipeline = gst_parse_launch('playbin');
    gst_util_set_object_arg($pipeline, 'uri', 'file:///tmp/none.mp4');

    $object = GObject::fromPointer($pipeline->pointer());

    expect($object)->toBeInstanceOf(GObject::class)
        ->and($object->typeName())->toBe('GstPlayBin')
        ->and(g_object_get_property($object, 'uri'))->toBe('file:///tmp/none.mp4');

    unset($object);
    gst_object_unref($pipeline);
})->skip(! extension_loaded('gstreamer'), 'needs ext-gstreamer for a foreign GObject');
