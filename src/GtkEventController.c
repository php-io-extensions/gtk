#include "runtime.h"
#include "../stubs/GtkEventController_arginfo.h"

static zend_class_entry *phpgtk_ce_GtkPropagationPhase;
static zend_class_entry *phpgtk_ce_GtkEventSequenceState;
static zend_class_entry *phpgtk_ce_GdkScrollUnit;
static zend_class_entry *phpgtk_ce_GdkEventType;
static zend_class_entry *phpgtk_ce_GtkShortcutScope;
static zend_class_entry *phpgtk_ce_GtkShortcutActionFlags;
static zend_class_entry *phpgtk_ce_GtkShortcutController;
static zend_class_entry *phpgtk_ce_GtkShortcut;
static zend_class_entry *phpgtk_ce_GtkShortcutTrigger;
static zend_class_entry *phpgtk_ce_GtkShortcutAction;
static zend_class_entry *phpgtk_ce_GtkCallbackAction;
#if GTK_CHECK_VERSION(4, 20, 0)
static zend_class_entry *phpgtk_ce_GdkScrollRelativeDirection;
#endif

/* The parent class, then the interfaces the class implements. */
#define PHPGTK_CONTROLLER_CLASS(name, ...) \
	phpgtk_ce_##name = register_class_##name(__VA_ARGS__); \
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
	PHPGTK_CONTROLLER_CLASS(GtkSettings, phpgtk_ce_GObject, phpgtk_ce_GtkStyleProvider);
	PHPGTK_CONTROLLER_CLASS(GtkIMMulticontext, phpgtk_ce_GtkIMContext);
	PHPGTK_CONTROLLER_CLASS(GtkEventControllerFocus, phpgtk_ce_GtkEventController);
	PHPGTK_CONTROLLER_CLASS(GtkGesture, phpgtk_ce_GtkEventController);
	PHPGTK_CONTROLLER_CLASS(GtkGestureSingle, phpgtk_ce_GtkGesture);
	PHPGTK_CONTROLLER_CLASS(GtkGestureClick, phpgtk_ce_GtkGestureSingle);
	PHPGTK_CONTROLLER_CLASS(GtkGestureLongPress, phpgtk_ce_GtkGestureSingle);

	phpgtk_ce_GtkShortcutScope = register_class_GtkShortcutScope();
	phpgtk_ce_GtkShortcutActionFlags = register_class_GtkShortcutActionFlags();
	PHPGTK_CONTROLLER_CLASS(GtkShortcutController, phpgtk_ce_GtkEventController, phpgtk_ce_GListModel);
	PHPGTK_CONTROLLER_CLASS(GtkShortcut, phpgtk_ce_GObject);
	PHPGTK_CONTROLLER_CLASS(GtkShortcutTrigger, phpgtk_ce_GObject);
	PHPGTK_CONTROLLER_CLASS(GtkShortcutAction, phpgtk_ce_GObject);
	PHPGTK_CONTROLLER_CLASS(GtkCallbackAction, phpgtk_ce_GtkShortcutAction);
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
	zval *x_ref, *y_ref;
	double x = 0.0;
	double y = 0.0;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_ZVAL(x_ref)
		Z_PARAM_ZVAL(y_ref)
	ZEND_PARSE_PARAMETERS_END();

	gboolean has_position = gdk_event_get_position(THIS_EVENT, &x, &y);

	ZEND_TRY_ASSIGN_REF_DOUBLE(x_ref, x);
	ZEND_TRY_ASSIGN_REF_DOUBLE(y_ref, y);
	RETURN_BOOL(has_position);
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

/* ---- shortcuts ---------------------------------------------------------- */

PHPGTK_CONTROLLER_NEW(GtkShortcutController, gtk_shortcut_controller_new)

ZEND_METHOD(GtkShortcutController, addShortcut)
{
	zend_object *shortcut;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(shortcut, phpgtk_ce_GtkShortcut)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	/* The shortcut argument is (transfer full); the controller gets its own reference. */
	gtk_shortcut_controller_add_shortcut(THIS(GTK_SHORTCUT_CONTROLLER), GTK_SHORTCUT(g_object_ref(PHPGTK_PTR(shortcut))));
}

ZEND_METHOD(GtkShortcutController, removeShortcut)
{
	zend_object *shortcut;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(shortcut, phpgtk_ce_GtkShortcut)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	gtk_shortcut_controller_remove_shortcut(THIS(GTK_SHORTCUT_CONTROLLER), GTK_SHORTCUT(PHPGTK_PTR(shortcut)));
}

ZEND_METHOD(GtkShortcutController, getScope)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_return_enum(return_value, phpgtk_ce_GtkShortcutScope, gtk_shortcut_controller_get_scope(THIS(GTK_SHORTCUT_CONTROLLER)));
}

ZEND_METHOD(GtkShortcutController, setScope)
{
	zend_object *scope;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS(scope, phpgtk_ce_GtkShortcutScope)
	ZEND_PARSE_PARAMETERS_END();

	gtk_shortcut_controller_set_scope(THIS(GTK_SHORTCUT_CONTROLLER), (GtkShortcutScope) phpgtk_enum_value(scope, GTK_SHORTCUT_SCOPE_LOCAL));
}

ZEND_METHOD(GtkShortcut, new)
{
	zend_object *trigger = NULL;
	zend_object *action = NULL;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(trigger, phpgtk_ce_GtkShortcutTrigger)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(action, phpgtk_ce_GtkShortcutAction)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	/* Both arguments are (transfer full); the shortcut gets its own references. */
	phpgtk_box_gobject_full(return_value, gtk_shortcut_new(
		trigger != NULL ? GTK_SHORTCUT_TRIGGER(g_object_ref(PHPGTK_PTR(trigger))) : NULL,
		action != NULL ? GTK_SHORTCUT_ACTION(g_object_ref(PHPGTK_PTR(action))) : NULL));
}

ZEND_METHOD(GtkShortcutTrigger, parseString)
{
	zend_string *string;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(string)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	phpgtk_box_gobject_full(return_value, gtk_shortcut_trigger_parse_string(ZSTR_VAL(string)));
}

ZEND_METHOD(GtkShortcutAction, activate)
{
	zend_object *flags_case = NULL;
	zend_long flags_long = 0;
	zend_object *widget;
	zend_object *args = NULL;

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJ_OF_CLASS_OR_LONG(flags_case, phpgtk_ce_GtkShortcutActionFlags, flags_long)
		Z_PARAM_OBJ_OF_CLASS(widget, phpgtk_ce_GtkWidget)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(args, phpgtk_ce_GVariant)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	RETURN_BOOL(gtk_shortcut_action_activate(THIS(GTK_SHORTCUT_ACTION),
		(GtkShortcutActionFlags) phpgtk_enum_value(flags_case, flags_long),
		GTK_WIDGET(PHPGTK_PTR(widget)),
		args != NULL ? (GVariant *) PHPGTK_PTR(args) : NULL));
}

/* GTK activates the action: the widget and the arguments go to PHP, and its bool comes back. */
static gboolean phpgtk_callback_action_call(GtkWidget *widget, GVariant *args, gpointer data)
{
	phpgtk_callout *callout = (phpgtk_callout *) data;
	zval argv[2], retval;
	gboolean handled = FALSE;

	/* Activated on another thread: the callable is not entered there. */
	if (phpgtk_callout_foreign(callout)) {
		return FALSE;
	}

	phpgtk_box_gobject(&argv[0], widget);
	if (args != NULL) {
		phpgtk_box_variant(&argv[1], args);
	} else {
		ZVAL_NULL(&argv[1]);
	}
	if (phpgtk_callout_invoke(callout, 2, argv, &retval)) {
		handled = zend_is_true(&retval);
	}
	zval_ptr_dtor(&argv[0]);
	zval_ptr_dtor(&argv[1]);
	zval_ptr_dtor(&retval);

	return handled;
}

/* The action is finalized: GLib's reference to the callable goes. */
static void phpgtk_callback_action_released(gpointer data)
{
	phpgtk_callout_release((phpgtk_callout *) data);
}

ZEND_METHOD(GtkCallbackAction, new)
{
	zval *callback;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(callback)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();

	if (!phpgtk_require_callable(callback, 1)) {
		RETURN_THROWS();
	}

	phpgtk_box_gobject_full(return_value, gtk_callback_action_new(
		phpgtk_callback_action_call, phpgtk_callout_new(callback), phpgtk_callback_action_released));
}
