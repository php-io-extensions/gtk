#include "runtime.h"
#include "../stubs/GtkEventController_arginfo.h"

static zend_class_entry *phpgtk_ce_GtkPropagationPhase;
static zend_class_entry *phpgtk_ce_GtkEventSequenceState;
static zend_class_entry *phpgtk_ce_GdkScrollUnit;
static zend_class_entry *phpgtk_ce_GdkEventType;
#if GTK_CHECK_VERSION(4, 20, 0)
static zend_class_entry *phpgtk_ce_GdkScrollRelativeDirection;
#endif

#define PHPGTK_CONTROLLER_CLASS(name, parent) \
	phpgtk_ce_##name = register_class_##name(parent); \
	phpgtk_object_setup(phpgtk_ce_##name); \
	phpgtk_map_gtype(#name, phpgtk_ce_##name)

void phpgtk_register_GtkEventController(void)
{
	phpgtk_ce_GtkPropagationPhase = register_class_GtkPropagationPhase();
	phpgtk_ce_GtkEventSequenceState = register_class_GtkEventSequenceState();
	phpgtk_ce_GdkScrollUnit = register_class_GdkScrollUnit();
#if GTK_CHECK_VERSION(4, 20, 0)
	phpgtk_ce_GdkScrollRelativeDirection = register_class_GdkScrollRelativeDirection();
#endif
	phpgtk_ce_GdkEventType = register_class_GdkEventType();
	phpgtk_ce_GdkEvent = register_class_GdkEvent();
	phpgtk_object_setup(phpgtk_ce_GdkEvent);
	phpgtk_ce_GdkButtonEvent = register_class_GdkButtonEvent(phpgtk_ce_GdkEvent);
	phpgtk_object_setup(phpgtk_ce_GdkButtonEvent);
	phpgtk_ce_GdkTouchEvent = register_class_GdkTouchEvent(phpgtk_ce_GdkEvent);
	phpgtk_object_setup(phpgtk_ce_GdkTouchEvent);
	phpgtk_ce_GdkScrollEvent = register_class_GdkScrollEvent(phpgtk_ce_GdkEvent);
	phpgtk_object_setup(phpgtk_ce_GdkScrollEvent);

	PHPGTK_CONTROLLER_CLASS(GtkEventController, phpgtk_ce_GObject);
	PHPGTK_CONTROLLER_CLASS(GtkEventControllerKey, phpgtk_ce_GtkEventController);
	PHPGTK_CONTROLLER_CLASS(GtkEventControllerMotion, phpgtk_ce_GtkEventController);
	PHPGTK_CONTROLLER_CLASS(GtkEventControllerScroll, phpgtk_ce_GtkEventController);
	PHPGTK_CONTROLLER_CLASS(GtkEventControllerLegacy, phpgtk_ce_GtkEventController);
	PHPGTK_CONTROLLER_CLASS(GtkIMContext, phpgtk_ce_GObject);
	PHPGTK_CONTROLLER_CLASS(GtkSettings, phpgtk_ce_GObject);
	PHPGTK_CONTROLLER_CLASS(GtkIMMulticontext, phpgtk_ce_GtkIMContext);
	PHPGTK_CONTROLLER_CLASS(GtkEventControllerFocus, phpgtk_ce_GtkEventController);
	PHPGTK_CONTROLLER_CLASS(GtkGesture, phpgtk_ce_GtkEventController);
	PHPGTK_CONTROLLER_CLASS(GtkGestureSingle, phpgtk_ce_GtkGesture);
	PHPGTK_CONTROLLER_CLASS(GtkGestureClick, phpgtk_ce_GtkGestureSingle);
	PHPGTK_CONTROLLER_CLASS(GtkGestureLongPress, phpgtk_ce_GtkGestureSingle);
}

#define THIS(cast) cast(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

/* Controllers are plain GObjects, not floating: new() hands over a full reference. */
#define PHPGTK_CONTROLLER_NEW(klass, call) \
ZEND_METHOD(klass, new) \
{ \
	ZEND_PARSE_PARAMETERS_NONE(); \
	PHPGTK_REQUIRE_MAIN_THREAD(); \
	phpgtk_box_gobject_full(return_value, call()); \
}

/* ---- GtkEventController ------------------------------------------------ */

ZEND_METHOD(GtkEventController, setPropagationPhase)
{
	zend_object *phase;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(phase, phpgtk_ce_GtkPropagationPhase)
	ZEND_PARSE_PARAMETERS_END();

	gtk_event_controller_set_propagation_phase(THIS(GTK_EVENT_CONTROLLER), (GtkPropagationPhase) phpgtk_enum_value(phase, GTK_PHASE_BUBBLE));
}

ZEND_METHOD(GtkEventController, getPropagationPhase)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_return_enum(return_value, phpgtk_ce_GtkPropagationPhase, gtk_event_controller_get_propagation_phase(THIS(GTK_EVENT_CONTROLLER)));
}

ZEND_METHOD(GtkEventController, getWidget)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_event_controller_get_widget(THIS(GTK_EVENT_CONTROLLER)));
}

ZEND_METHOD(GtkEventController, getCurrentEvent)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_event(return_value, gtk_event_controller_get_current_event(THIS(GTK_EVENT_CONTROLLER)));
}

/* ---- GdkEvent ------------------------------------------------------------ */

#define THIS_EVENT ((GdkEvent *) PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

ZEND_METHOD(GdkEvent, getEventType)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_return_enum(return_value, phpgtk_ce_GdkEventType, gdk_event_get_event_type(THIS_EVENT));
}

ZEND_METHOD(GdkEvent, getPosition)
{
	double x;
	double y;

	ZEND_PARSE_PARAMETERS_NONE();

	if (!gdk_event_get_position(THIS_EVENT, &x, &y)) {
		RETURN_NULL();
	}
	array_init_size(return_value, 2);
	add_next_index_double(return_value, x);
	add_next_index_double(return_value, y);
}

ZEND_METHOD(GdkEvent, getPointerEmulated)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_BOOL(gdk_event_get_pointer_emulated(THIS_EVENT));
}

ZEND_METHOD(GdkEvent, getModifierState)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG((zend_long) gdk_event_get_modifier_state(THIS_EVENT));
}

ZEND_METHOD(GdkButtonEvent, getButton)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG((zend_long) gdk_button_event_get_button(THIS_EVENT));
}

ZEND_METHOD(GdkTouchEvent, getEmulatingPointer)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_BOOL(gdk_touch_event_get_emulating_pointer(THIS_EVENT));
}

/* ---- GtkSettings ------------------------------------------------------- */

ZEND_METHOD(GtkSettings, getDefault)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();

	phpgtk_box_gobject(return_value, gtk_settings_get_default());
}

/* ---- GtkIMContext -------------------------------------------------------- */

ZEND_METHOD(GtkIMContext, setClientWidget)
{
	zend_object *widget = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(widget, phpgtk_ce_GtkWidget)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	gtk_im_context_set_client_widget(THIS(GTK_IM_CONTEXT), widget == NULL ? NULL : GTK_WIDGET(PHPGTK_PTR(widget)));
}

ZEND_METHOD(GtkIMContext, filterKeypress)
{
	zend_object *event;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(event, phpgtk_ce_GdkEvent)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	RETURN_BOOL(gtk_im_context_filter_keypress(THIS(GTK_IM_CONTEXT), (GdkEvent *) PHPGTK_PTR(event)));
}

ZEND_METHOD(GtkIMContext, focusIn)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();

	gtk_im_context_focus_in(THIS(GTK_IM_CONTEXT));
}

ZEND_METHOD(GtkIMContext, focusOut)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();

	gtk_im_context_focus_out(THIS(GTK_IM_CONTEXT));
}

ZEND_METHOD(GtkIMContext, reset)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();

	gtk_im_context_reset(THIS(GTK_IM_CONTEXT));
}

/* ---- GdkScrollEvent ------------------------------------------------------ */

#if GTK_CHECK_VERSION(4, 20, 0)
ZEND_METHOD(GdkScrollEvent, getRelativeDirection)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_return_enum(return_value, phpgtk_ce_GdkScrollRelativeDirection, gdk_scroll_event_get_relative_direction((GdkEvent *) PHPGTK_PTR(Z_OBJ_P(ZEND_THIS))));
}
#endif

/* ---- the controllers ---------------------------------------------------- */

PHPGTK_CONTROLLER_NEW(GtkEventControllerKey, gtk_event_controller_key_new)
PHPGTK_CONTROLLER_NEW(GtkEventControllerMotion, gtk_event_controller_motion_new)
PHPGTK_CONTROLLER_NEW(GtkEventControllerFocus, gtk_event_controller_focus_new)
PHPGTK_CONTROLLER_NEW(GtkGestureClick, gtk_gesture_click_new)
PHPGTK_CONTROLLER_NEW(GtkGestureLongPress, gtk_gesture_long_press_new)
PHPGTK_CONTROLLER_NEW(GtkEventControllerLegacy, gtk_event_controller_legacy_new)
PHPGTK_CONTROLLER_NEW(GtkIMMulticontext, gtk_im_multicontext_new)

ZEND_METHOD(GtkEventControllerScroll, new)
{
	zend_long flags;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	phpgtk_box_gobject_full(return_value, gtk_event_controller_scroll_new((GtkEventControllerScrollFlags) flags));
}

ZEND_METHOD(GtkEventControllerScroll, getFlags)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG((zend_long) gtk_event_controller_scroll_get_flags(THIS(GTK_EVENT_CONTROLLER_SCROLL)));
}

ZEND_METHOD(GtkEventControllerScroll, setFlags)
{
	zend_long flags;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(flags)
	ZEND_PARSE_PARAMETERS_END();

	gtk_event_controller_scroll_set_flags(THIS(GTK_EVENT_CONTROLLER_SCROLL), (GtkEventControllerScrollFlags) flags);
}

ZEND_METHOD(GtkEventControllerScroll, getUnit)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_return_enum(return_value, phpgtk_ce_GdkScrollUnit, gtk_event_controller_scroll_get_unit(THIS(GTK_EVENT_CONTROLLER_SCROLL)));
}

/* ---- GtkGesture --------------------------------------------------------- */

ZEND_METHOD(GtkGesture, setState)
{
	zend_object *state;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(state, phpgtk_ce_GtkEventSequenceState)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_BOOL(gtk_gesture_set_state(THIS(GTK_GESTURE), (GtkEventSequenceState) phpgtk_enum_value(state, GTK_EVENT_SEQUENCE_NONE)));
}

/* ---- GtkGestureSingle --------------------------------------------------- */

ZEND_METHOD(GtkGestureSingle, setButton)
{
	zend_long button;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(button)
	ZEND_PARSE_PARAMETERS_END();

	gtk_gesture_single_set_button(THIS(GTK_GESTURE_SINGLE), (guint) button);
}

ZEND_METHOD(GtkGestureSingle, getButton)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG((zend_long) gtk_gesture_single_get_button(THIS(GTK_GESTURE_SINGLE)));
}

ZEND_METHOD(GtkGestureSingle, setTouchOnly)
{
	bool touch_only;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(touch_only)
	ZEND_PARSE_PARAMETERS_END();

	gtk_gesture_single_set_touch_only(THIS(GTK_GESTURE_SINGLE), touch_only);
}

ZEND_METHOD(GtkGestureSingle, getTouchOnly)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_BOOL(gtk_gesture_single_get_touch_only(THIS(GTK_GESTURE_SINGLE)));
}

ZEND_METHOD(GtkGestureSingle, getCurrentButton)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG((zend_long) gtk_gesture_single_get_current_button(THIS(GTK_GESTURE_SINGLE)));
}

/* ---- keyval functions (declared in gtk.stub.php) ------------------------- */

ZEND_FUNCTION(gdk_keyval_to_unicode)
{
	zend_long keyval;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(keyval)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG((zend_long) gdk_keyval_to_unicode((guint) keyval));
}

ZEND_FUNCTION(gdk_keyval_to_lower)
{
	zend_long keyval;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(keyval)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_LONG((zend_long) gdk_keyval_to_lower((guint) keyval));
}
