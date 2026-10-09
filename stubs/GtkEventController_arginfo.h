/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 033cf6f98d0b2e2da65a1d6780d5eb213e9c5411 */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GdkEvent_getEventType, 0, 0, GdkEventType, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkEvent_getPosition, 0, 0, IS_ARRAY, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkEvent_getPointerEmulated, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GdkEvent_getModifierState, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GdkButtonEvent_getButton arginfo_class_GdkEvent_getModifierState

#define arginfo_class_GdkTouchEvent_getEmulatingPointer arginfo_class_GdkEvent_getPointerEmulated

#if GTK_CHECK_VERSION(4, 20, 0)
ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GdkScrollEvent_getRelativeDirection, 0, 0, GdkScrollRelativeDirection, 0)
ZEND_END_ARG_INFO()
#endif

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkEventController_setPropagationPhase, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, phase, GtkPropagationPhase, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkEventController_getPropagationPhase, 0, 0, GtkPropagationPhase, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkEventController_getWidget, 0, 0, GtkWidget, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkEventController_getCurrentEvent, 0, 0, GdkEvent, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkEventControllerKey_new, 0, 0, GtkEventControllerKey, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkEventControllerMotion_new, 0, 0, GtkEventControllerMotion, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkEventControllerScroll_new, 0, 1, GtkEventControllerScroll, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkEventControllerScroll_getFlags arginfo_class_GdkEvent_getModifierState

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkEventControllerScroll_setFlags, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkEventControllerScroll_getUnit, 0, 0, GdkScrollUnit, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkEventControllerLegacy_new, 0, 0, GtkEventControllerLegacy, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkSettings_getDefault, 0, 0, GtkSettings, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkIMContext_setClientWidget, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, widget, GtkWidget, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkIMContext_filterKeypress, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, event, GdkEvent, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkIMContext_focusIn, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkIMContext_focusOut arginfo_class_GtkIMContext_focusIn

#define arginfo_class_GtkIMContext_reset arginfo_class_GtkIMContext_focusIn

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkIMMulticontext_new, 0, 0, GtkIMMulticontext, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkEventControllerFocus_new, 0, 0, GtkEventControllerFocus, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkGestureSingle_setButton, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, button, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkGestureSingle_getButton arginfo_class_GdkEvent_getModifierState

#define arginfo_class_GtkGestureSingle_getCurrentButton arginfo_class_GdkEvent_getModifierState

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkGestureSingle_setTouchOnly, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, touchOnly, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkGestureSingle_getTouchOnly arginfo_class_GdkEvent_getPointerEmulated

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkGestureLongPress_new, 0, 0, GtkGestureLongPress, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkGestureClick_new, 0, 0, GtkGestureClick, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(GdkEvent, getEventType);
ZEND_METHOD(GdkEvent, getPosition);
ZEND_METHOD(GdkEvent, getPointerEmulated);
ZEND_METHOD(GdkEvent, getModifierState);
ZEND_METHOD(GdkButtonEvent, getButton);
ZEND_METHOD(GdkTouchEvent, getEmulatingPointer);
#if GTK_CHECK_VERSION(4, 20, 0)
ZEND_METHOD(GdkScrollEvent, getRelativeDirection);
#endif
ZEND_METHOD(GtkEventController, setPropagationPhase);
ZEND_METHOD(GtkEventController, getPropagationPhase);
ZEND_METHOD(GtkEventController, getWidget);
ZEND_METHOD(GtkEventController, getCurrentEvent);
ZEND_METHOD(GtkEventControllerKey, new);
ZEND_METHOD(GtkEventControllerMotion, new);
ZEND_METHOD(GtkEventControllerScroll, new);
ZEND_METHOD(GtkEventControllerScroll, getFlags);
ZEND_METHOD(GtkEventControllerScroll, setFlags);
ZEND_METHOD(GtkEventControllerScroll, getUnit);
ZEND_METHOD(GtkEventControllerLegacy, new);
ZEND_METHOD(GtkSettings, getDefault);
ZEND_METHOD(GtkIMContext, setClientWidget);
ZEND_METHOD(GtkIMContext, filterKeypress);
ZEND_METHOD(GtkIMContext, focusIn);
ZEND_METHOD(GtkIMContext, focusOut);
ZEND_METHOD(GtkIMContext, reset);
ZEND_METHOD(GtkIMMulticontext, new);
ZEND_METHOD(GtkEventControllerFocus, new);
ZEND_METHOD(GtkGestureSingle, setButton);
ZEND_METHOD(GtkGestureSingle, getButton);
ZEND_METHOD(GtkGestureSingle, getCurrentButton);
ZEND_METHOD(GtkGestureSingle, setTouchOnly);
ZEND_METHOD(GtkGestureSingle, getTouchOnly);
ZEND_METHOD(GtkGestureLongPress, new);
ZEND_METHOD(GtkGestureClick, new);

static const zend_function_entry class_GdkEvent_methods[] = {
	ZEND_ME(GdkEvent, getEventType, arginfo_class_GdkEvent_getEventType, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkEvent, getPosition, arginfo_class_GdkEvent_getPosition, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkEvent, getPointerEmulated, arginfo_class_GdkEvent_getPointerEmulated, ZEND_ACC_PUBLIC)
	ZEND_ME(GdkEvent, getModifierState, arginfo_class_GdkEvent_getModifierState, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GdkButtonEvent_methods[] = {
	ZEND_ME(GdkButtonEvent, getButton, arginfo_class_GdkButtonEvent_getButton, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GdkTouchEvent_methods[] = {
	ZEND_ME(GdkTouchEvent, getEmulatingPointer, arginfo_class_GdkTouchEvent_getEmulatingPointer, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GdkScrollEvent_methods[] = {
#if GTK_CHECK_VERSION(4, 20, 0)
	ZEND_ME(GdkScrollEvent, getRelativeDirection, arginfo_class_GdkScrollEvent_getRelativeDirection, ZEND_ACC_PUBLIC)
#endif
	ZEND_FE_END
};

static const zend_function_entry class_GtkEventController_methods[] = {
	ZEND_ME(GtkEventController, setPropagationPhase, arginfo_class_GtkEventController_setPropagationPhase, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkEventController, getPropagationPhase, arginfo_class_GtkEventController_getPropagationPhase, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkEventController, getWidget, arginfo_class_GtkEventController_getWidget, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkEventController, getCurrentEvent, arginfo_class_GtkEventController_getCurrentEvent, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkEventControllerKey_methods[] = {
	ZEND_ME(GtkEventControllerKey, new, arginfo_class_GtkEventControllerKey_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkEventControllerMotion_methods[] = {
	ZEND_ME(GtkEventControllerMotion, new, arginfo_class_GtkEventControllerMotion_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkEventControllerScroll_methods[] = {
	ZEND_ME(GtkEventControllerScroll, new, arginfo_class_GtkEventControllerScroll_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkEventControllerScroll, getFlags, arginfo_class_GtkEventControllerScroll_getFlags, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkEventControllerScroll, setFlags, arginfo_class_GtkEventControllerScroll_setFlags, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkEventControllerScroll, getUnit, arginfo_class_GtkEventControllerScroll_getUnit, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkEventControllerLegacy_methods[] = {
	ZEND_ME(GtkEventControllerLegacy, new, arginfo_class_GtkEventControllerLegacy_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkSettings_methods[] = {
	ZEND_ME(GtkSettings, getDefault, arginfo_class_GtkSettings_getDefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkIMContext_methods[] = {
	ZEND_ME(GtkIMContext, setClientWidget, arginfo_class_GtkIMContext_setClientWidget, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkIMContext, filterKeypress, arginfo_class_GtkIMContext_filterKeypress, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkIMContext, focusIn, arginfo_class_GtkIMContext_focusIn, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkIMContext, focusOut, arginfo_class_GtkIMContext_focusOut, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkIMContext, reset, arginfo_class_GtkIMContext_reset, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkIMMulticontext_methods[] = {
	ZEND_ME(GtkIMMulticontext, new, arginfo_class_GtkIMMulticontext_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkEventControllerFocus_methods[] = {
	ZEND_ME(GtkEventControllerFocus, new, arginfo_class_GtkEventControllerFocus_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkGestureSingle_methods[] = {
	ZEND_ME(GtkGestureSingle, setButton, arginfo_class_GtkGestureSingle_setButton, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkGestureSingle, getButton, arginfo_class_GtkGestureSingle_getButton, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkGestureSingle, getCurrentButton, arginfo_class_GtkGestureSingle_getCurrentButton, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkGestureSingle, setTouchOnly, arginfo_class_GtkGestureSingle_setTouchOnly, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkGestureSingle, getTouchOnly, arginfo_class_GtkGestureSingle_getTouchOnly, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkGestureLongPress_methods[] = {
	ZEND_ME(GtkGestureLongPress, new, arginfo_class_GtkGestureLongPress_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkGestureClick_methods[] = {
	ZEND_ME(GtkGestureClick, new, arginfo_class_GtkGestureClick_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_GtkPropagationPhase(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GtkPropagationPhase", IS_LONG, NULL);

	zval enum_case_NONE_value;
	ZVAL_LONG(&enum_case_NONE_value, 0);
	zend_enum_add_case_cstr(class_entry, "NONE", &enum_case_NONE_value);

	zval enum_case_CAPTURE_value;
	ZVAL_LONG(&enum_case_CAPTURE_value, 1);
	zend_enum_add_case_cstr(class_entry, "CAPTURE", &enum_case_CAPTURE_value);

	zval enum_case_BUBBLE_value;
	ZVAL_LONG(&enum_case_BUBBLE_value, 2);
	zend_enum_add_case_cstr(class_entry, "BUBBLE", &enum_case_BUBBLE_value);

	zval enum_case_TARGET_value;
	ZVAL_LONG(&enum_case_TARGET_value, 3);
	zend_enum_add_case_cstr(class_entry, "TARGET", &enum_case_TARGET_value);

	return class_entry;
}

static zend_class_entry *register_class_GdkScrollUnit(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GdkScrollUnit", IS_LONG, NULL);

	zval enum_case_WHEEL_value;
	ZVAL_LONG(&enum_case_WHEEL_value, 0);
	zend_enum_add_case_cstr(class_entry, "WHEEL", &enum_case_WHEEL_value);

	zval enum_case_SURFACE_value;
	ZVAL_LONG(&enum_case_SURFACE_value, 1);
	zend_enum_add_case_cstr(class_entry, "SURFACE", &enum_case_SURFACE_value);

	return class_entry;
}

#if GTK_CHECK_VERSION(4, 20, 0)
static zend_class_entry *register_class_GdkScrollRelativeDirection(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GdkScrollRelativeDirection", IS_LONG, NULL);

	zval enum_case_IDENTICAL_value;
	ZVAL_LONG(&enum_case_IDENTICAL_value, 0);
	zend_enum_add_case_cstr(class_entry, "IDENTICAL", &enum_case_IDENTICAL_value);

	zval enum_case_INVERTED_value;
	ZVAL_LONG(&enum_case_INVERTED_value, 1);
	zend_enum_add_case_cstr(class_entry, "INVERTED", &enum_case_INVERTED_value);

	zval enum_case_UNKNOWN_value;
	ZVAL_LONG(&enum_case_UNKNOWN_value, 2);
	zend_enum_add_case_cstr(class_entry, "UNKNOWN", &enum_case_UNKNOWN_value);

	return class_entry;
}
#endif

static zend_class_entry *register_class_GdkEventType(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GdkEventType", IS_LONG, NULL);

	zval enum_case_DELETE_value;
	ZVAL_LONG(&enum_case_DELETE_value, 0);
	zend_enum_add_case_cstr(class_entry, "DELETE", &enum_case_DELETE_value);

	zval enum_case_MOTION_NOTIFY_value;
	ZVAL_LONG(&enum_case_MOTION_NOTIFY_value, 1);
	zend_enum_add_case_cstr(class_entry, "MOTION_NOTIFY", &enum_case_MOTION_NOTIFY_value);

	zval enum_case_BUTTON_PRESS_value;
	ZVAL_LONG(&enum_case_BUTTON_PRESS_value, 2);
	zend_enum_add_case_cstr(class_entry, "BUTTON_PRESS", &enum_case_BUTTON_PRESS_value);

	zval enum_case_BUTTON_RELEASE_value;
	ZVAL_LONG(&enum_case_BUTTON_RELEASE_value, 3);
	zend_enum_add_case_cstr(class_entry, "BUTTON_RELEASE", &enum_case_BUTTON_RELEASE_value);

	zval enum_case_KEY_PRESS_value;
	ZVAL_LONG(&enum_case_KEY_PRESS_value, 4);
	zend_enum_add_case_cstr(class_entry, "KEY_PRESS", &enum_case_KEY_PRESS_value);

	zval enum_case_KEY_RELEASE_value;
	ZVAL_LONG(&enum_case_KEY_RELEASE_value, 5);
	zend_enum_add_case_cstr(class_entry, "KEY_RELEASE", &enum_case_KEY_RELEASE_value);

	zval enum_case_ENTER_NOTIFY_value;
	ZVAL_LONG(&enum_case_ENTER_NOTIFY_value, 6);
	zend_enum_add_case_cstr(class_entry, "ENTER_NOTIFY", &enum_case_ENTER_NOTIFY_value);

	zval enum_case_LEAVE_NOTIFY_value;
	ZVAL_LONG(&enum_case_LEAVE_NOTIFY_value, 7);
	zend_enum_add_case_cstr(class_entry, "LEAVE_NOTIFY", &enum_case_LEAVE_NOTIFY_value);

	zval enum_case_FOCUS_CHANGE_value;
	ZVAL_LONG(&enum_case_FOCUS_CHANGE_value, 8);
	zend_enum_add_case_cstr(class_entry, "FOCUS_CHANGE", &enum_case_FOCUS_CHANGE_value);

	zval enum_case_PROXIMITY_IN_value;
	ZVAL_LONG(&enum_case_PROXIMITY_IN_value, 9);
	zend_enum_add_case_cstr(class_entry, "PROXIMITY_IN", &enum_case_PROXIMITY_IN_value);

	zval enum_case_PROXIMITY_OUT_value;
	ZVAL_LONG(&enum_case_PROXIMITY_OUT_value, 10);
	zend_enum_add_case_cstr(class_entry, "PROXIMITY_OUT", &enum_case_PROXIMITY_OUT_value);

	zval enum_case_DRAG_ENTER_value;
	ZVAL_LONG(&enum_case_DRAG_ENTER_value, 11);
	zend_enum_add_case_cstr(class_entry, "DRAG_ENTER", &enum_case_DRAG_ENTER_value);

	zval enum_case_DRAG_LEAVE_value;
	ZVAL_LONG(&enum_case_DRAG_LEAVE_value, 12);
	zend_enum_add_case_cstr(class_entry, "DRAG_LEAVE", &enum_case_DRAG_LEAVE_value);

	zval enum_case_DRAG_MOTION_value;
	ZVAL_LONG(&enum_case_DRAG_MOTION_value, 13);
	zend_enum_add_case_cstr(class_entry, "DRAG_MOTION", &enum_case_DRAG_MOTION_value);

	zval enum_case_DROP_START_value;
	ZVAL_LONG(&enum_case_DROP_START_value, 14);
	zend_enum_add_case_cstr(class_entry, "DROP_START", &enum_case_DROP_START_value);

	zval enum_case_SCROLL_value;
	ZVAL_LONG(&enum_case_SCROLL_value, 15);
	zend_enum_add_case_cstr(class_entry, "SCROLL", &enum_case_SCROLL_value);

	zval enum_case_GRAB_BROKEN_value;
	ZVAL_LONG(&enum_case_GRAB_BROKEN_value, 16);
	zend_enum_add_case_cstr(class_entry, "GRAB_BROKEN", &enum_case_GRAB_BROKEN_value);

	zval enum_case_TOUCH_BEGIN_value;
	ZVAL_LONG(&enum_case_TOUCH_BEGIN_value, 17);
	zend_enum_add_case_cstr(class_entry, "TOUCH_BEGIN", &enum_case_TOUCH_BEGIN_value);

	zval enum_case_TOUCH_UPDATE_value;
	ZVAL_LONG(&enum_case_TOUCH_UPDATE_value, 18);
	zend_enum_add_case_cstr(class_entry, "TOUCH_UPDATE", &enum_case_TOUCH_UPDATE_value);

	zval enum_case_TOUCH_END_value;
	ZVAL_LONG(&enum_case_TOUCH_END_value, 19);
	zend_enum_add_case_cstr(class_entry, "TOUCH_END", &enum_case_TOUCH_END_value);

	zval enum_case_TOUCH_CANCEL_value;
	ZVAL_LONG(&enum_case_TOUCH_CANCEL_value, 20);
	zend_enum_add_case_cstr(class_entry, "TOUCH_CANCEL", &enum_case_TOUCH_CANCEL_value);

	zval enum_case_TOUCHPAD_SWIPE_value;
	ZVAL_LONG(&enum_case_TOUCHPAD_SWIPE_value, 21);
	zend_enum_add_case_cstr(class_entry, "TOUCHPAD_SWIPE", &enum_case_TOUCHPAD_SWIPE_value);

	zval enum_case_TOUCHPAD_PINCH_value;
	ZVAL_LONG(&enum_case_TOUCHPAD_PINCH_value, 22);
	zend_enum_add_case_cstr(class_entry, "TOUCHPAD_PINCH", &enum_case_TOUCHPAD_PINCH_value);

	zval enum_case_PAD_BUTTON_PRESS_value;
	ZVAL_LONG(&enum_case_PAD_BUTTON_PRESS_value, 23);
	zend_enum_add_case_cstr(class_entry, "PAD_BUTTON_PRESS", &enum_case_PAD_BUTTON_PRESS_value);

	zval enum_case_PAD_BUTTON_RELEASE_value;
	ZVAL_LONG(&enum_case_PAD_BUTTON_RELEASE_value, 24);
	zend_enum_add_case_cstr(class_entry, "PAD_BUTTON_RELEASE", &enum_case_PAD_BUTTON_RELEASE_value);

	zval enum_case_PAD_RING_value;
	ZVAL_LONG(&enum_case_PAD_RING_value, 25);
	zend_enum_add_case_cstr(class_entry, "PAD_RING", &enum_case_PAD_RING_value);

	zval enum_case_PAD_STRIP_value;
	ZVAL_LONG(&enum_case_PAD_STRIP_value, 26);
	zend_enum_add_case_cstr(class_entry, "PAD_STRIP", &enum_case_PAD_STRIP_value);

	zval enum_case_PAD_GROUP_MODE_value;
	ZVAL_LONG(&enum_case_PAD_GROUP_MODE_value, 27);
	zend_enum_add_case_cstr(class_entry, "PAD_GROUP_MODE", &enum_case_PAD_GROUP_MODE_value);

	zval enum_case_TOUCHPAD_HOLD_value;
	ZVAL_LONG(&enum_case_TOUCHPAD_HOLD_value, 28);
	zend_enum_add_case_cstr(class_entry, "TOUCHPAD_HOLD", &enum_case_TOUCHPAD_HOLD_value);

	zval enum_case_PAD_DIAL_value;
	ZVAL_LONG(&enum_case_PAD_DIAL_value, 29);
	zend_enum_add_case_cstr(class_entry, "PAD_DIAL", &enum_case_PAD_DIAL_value);

	return class_entry;
}

static zend_class_entry *register_class_GdkEvent(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GdkEvent", class_GdkEvent_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GdkButtonEvent(zend_class_entry *class_entry_GdkEvent)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GdkButtonEvent", class_GdkButtonEvent_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GdkEvent, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GdkTouchEvent(zend_class_entry *class_entry_GdkEvent)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GdkTouchEvent", class_GdkTouchEvent_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GdkEvent, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GdkScrollEvent(zend_class_entry *class_entry_GdkEvent)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GdkScrollEvent", class_GdkScrollEvent_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GdkEvent, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkEventController(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkEventController", class_GtkEventController_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkEventControllerKey(zend_class_entry *class_entry_GtkEventController)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkEventControllerKey", class_GtkEventControllerKey_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkEventController, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkEventControllerMotion(zend_class_entry *class_entry_GtkEventController)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkEventControllerMotion", class_GtkEventControllerMotion_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkEventController, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkEventControllerScroll(zend_class_entry *class_entry_GtkEventController)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkEventControllerScroll", class_GtkEventControllerScroll_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkEventController, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkEventControllerLegacy(zend_class_entry *class_entry_GtkEventController)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkEventControllerLegacy", class_GtkEventControllerLegacy_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkEventController, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkSettings(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkSettings", class_GtkSettings_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkIMContext(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkIMContext", class_GtkIMContext_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkIMMulticontext(zend_class_entry *class_entry_GtkIMContext)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkIMMulticontext", class_GtkIMMulticontext_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkIMContext, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkEventControllerFocus(zend_class_entry *class_entry_GtkEventController)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkEventControllerFocus", class_GtkEventControllerFocus_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkEventController, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkGesture(zend_class_entry *class_entry_GtkEventController)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkGesture", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkEventController, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkGestureSingle(zend_class_entry *class_entry_GtkGesture)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkGestureSingle", class_GtkGestureSingle_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkGesture, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkGestureLongPress(zend_class_entry *class_entry_GtkGestureSingle)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkGestureLongPress", class_GtkGestureLongPress_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkGestureSingle, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkGestureClick(zend_class_entry *class_entry_GtkGestureSingle)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkGestureClick", class_GtkGestureClick_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkGestureSingle, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
