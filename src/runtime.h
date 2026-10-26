/*
 * The glue every binding shares: one PHP object per native object, referenced
 * while PHP holds it; GError turned into a PHP exception; PHP callables that
 * GLib calls back into.
 */

#ifndef PHPGTK_RUNTIME_H
#define PHPGTK_RUNTIME_H

#ifdef HAVE_CONFIG_H
# include "config.h"
#endif

#include "php.h"
#include "zend_enum.h"
#include "zend_exceptions.h"
#include "php_gtk.h"

#include <gtk/gtk.h>
#include <glib-unix.h>
#include <pthread.h>

/* A PHP callable held for GLib to call back into: a source's function or a signal handler. */
typedef struct phpgtk_callout {
	zval callable;                 /* UNDEF once detached at request end */
	uint32_t refcount;             /* 1 for GLib's reference, +1 while invoking */
	guint source_id;               /* set for a source */
	GObject *instance;             /* set for a signal handler, not referenced */
	gulong handler_id;
	struct phpgtk_callout *prev;
	struct phpgtk_callout *next;
	pthread_t thread;              /* the PHP thread that made it: the only thread that may enter its callable */
} phpgtk_callout;

ZEND_BEGIN_MODULE_GLOBALS(gtk)
	HashTable boxes;               /* native address => zend_object*, not refcounted */
	phpgtk_callout *callouts;      /* every callout still attached this request */
ZEND_END_MODULE_GLOBALS(gtk)

ZEND_EXTERN_MODULE_GLOBALS(gtk)
#define PHPGTK_G(v) ZEND_MODULE_GLOBALS_ACCESSOR(gtk, v)

typedef enum {
	PHPGTK_GOBJECT = 0,            /* g_object_ref / g_object_unref */
	PHPGTK_MAIN_CONTEXT = 1,       /* g_main_context_ref / g_main_context_unref */
	PHPGTK_VARIANT = 2,            /* g_variant_ref_sink / g_variant_unref */
	PHPGTK_DATE_TIME = 3,          /* g_date_time_ref / g_date_time_unref */
	PHPGTK_DMABUF_FORMATS = 4,     /* gdk_dmabuf_formats_ref / gdk_dmabuf_formats_unref (GTK 4.14+) */
	PHPGTK_EVENT = 5,              /* gdk_event_ref / gdk_event_unref */
	PHPGTK_TEXT_ITER = 6,          /* phpgtk_text_iter: struct copy of the iter + g_object_ref of its buffer on box, g_object_unref and g_free on free */
	PHPGTK_BYTES = 7,              /* g_bytes_ref / g_bytes_unref */
	PHPGTK_CAIRO_REGION = 8,       /* cairo_region_reference / cairo_region_destroy */
	PHPGTK_PARAM_SPEC = 9,         /* g_param_spec_ref_sink / g_param_spec_unref */
	PHPGTK_SCROLL_INFO = 10,       /* gtk_scroll_info_ref / gtk_scroll_info_unref (GTK 4.12+) */
} phpgtk_kind;

/* A GtkTextIter copy, the strong reference that keeps its buffer alive as long as the PHP object lives,
 * and the buffer's text generation when it was taken (GTK invalidates an iter once the text changes). */
typedef struct {
	GtkTextIter iter;
	GtkTextBuffer *buffer;
	guint generation;
} phpgtk_text_iter;

/* The box of a GtkTextIter object. */
#define PHPGTK_ITER_BOX(zobj) ((phpgtk_text_iter *) PHPGTK_PTR(zobj))

/* The GtkTextIter inside a GtkTextIter object's box, or NULL with a GtkException once its buffer's text changed. */
GtkTextIter *phpgtk_fresh_iter(zend_object *iter_obj);

typedef struct {
	void *ptr;                     /* referenced native object, NULL before boxing */
	phpgtk_kind kind;
	zend_object std;
} phpgtk_object;

static zend_always_inline phpgtk_object *phpgtk_object_from(zend_object *obj)
{
	return (phpgtk_object *) ((char *) obj - XtOffsetOf(phpgtk_object, std));
}

#define PHPGTK_PTR(zobj) (phpgtk_object_from(zobj)->ptr)
#define PHPGTK_OPTIONAL_PTR(zobj) ((zobj) != NULL ? PHPGTK_PTR(zobj) : NULL)
/* A parameter typed with a GObject interface (GListModel, GtkSelectionModel, GActionGroup, GdkPaintable,
 * GtkStyleProvider) is parsed as a GObject: only a GObject wrapper carries the pointer, and only a GObject
 * wrapper implements the interface (phpgtk_interface_native_only). */

extern zend_class_entry *phpgtk_ce_GtkException;
extern zend_class_entry *phpgtk_ce_GError;
extern zend_class_entry *phpgtk_ce_GIOCondition;
extern zend_class_entry *phpgtk_ce_GObject;
extern zend_class_entry *phpgtk_ce_GApplication;
extern zend_class_entry *phpgtk_ce_GApplicationFlags;
extern zend_class_entry *phpgtk_ce_GtkApplication;
extern zend_class_entry *phpgtk_ce_GMainContext;
extern zend_class_entry *phpgtk_ce_GtkTextIter;
extern zend_class_entry *phpgtk_ce_GtkTextMark;
extern zend_class_entry *phpgtk_ce_GtkTextTag;
extern zend_class_entry *phpgtk_ce_GtkTextTagTable;
extern zend_class_entry *phpgtk_ce_GtkAdjustment;
extern zend_class_entry *phpgtk_ce_GtkOrientation;
extern zend_class_entry *phpgtk_ce_GtkAlign;
extern zend_class_entry *phpgtk_ce_GtkWidget;
extern zend_class_entry *phpgtk_ce_GtkEventController;
extern zend_class_entry *phpgtk_ce_GtkEventControllerKey;
extern zend_class_entry *phpgtk_ce_GtkEventControllerMotion;
extern zend_class_entry *phpgtk_ce_GtkEventControllerScroll;
extern zend_class_entry *phpgtk_ce_GtkEventControllerFocus;
extern zend_class_entry *phpgtk_ce_GtkGesture;
extern zend_class_entry *phpgtk_ce_GtkGestureSingle;
extern zend_class_entry *phpgtk_ce_GtkGestureClick;
extern zend_class_entry *phpgtk_ce_GtkGestureLongPress;
extern zend_class_entry *phpgtk_ce_GdkEvent;
extern zend_class_entry *phpgtk_ce_GdkScrollEvent;
extern zend_class_entry *phpgtk_ce_GdkButtonEvent;
extern zend_class_entry *phpgtk_ce_GdkTouchEvent;
extern zend_class_entry *phpgtk_ce_GtkEventControllerLegacy;
extern zend_class_entry *phpgtk_ce_GtkIMContext;
extern zend_class_entry *phpgtk_ce_GtkSettings;
extern zend_class_entry *phpgtk_ce_GtkIMMulticontext;
extern zend_class_entry *phpgtk_ce_GtkBox;
extern zend_class_entry *phpgtk_ce_GtkGrid;
extern zend_class_entry *phpgtk_ce_GtkFixed;
extern zend_class_entry *phpgtk_ce_GtkCssProvider;
extern zend_class_entry *phpgtk_ce_GdkDisplay;
extern zend_class_entry *phpgtk_ce_GdkSurface;
extern zend_class_entry *phpgtk_ce_GdkGLAPI;
extern zend_class_entry *phpgtk_ce_GdkGLContext;
extern zend_class_entry *phpgtk_ce_GtkGLArea;
extern zend_class_entry *phpgtk_ce_GdkMemoryFormat;
extern zend_class_entry *phpgtk_ce_GdkTexture;
extern zend_class_entry *phpgtk_ce_GdkMemoryTexture;
extern zend_class_entry *phpgtk_ce_GdkMemoryTextureBuilder;
extern zend_class_entry *phpgtk_ce_GdkDmabufTextureBuilder;
extern zend_class_entry *phpgtk_ce_GdkDmabufFormats;
extern zend_class_entry *phpgtk_ce_PangoEllipsizeMode;
extern zend_class_entry *phpgtk_ce_GtkJustification;
extern zend_class_entry *phpgtk_ce_GtkWrapMode;
extern zend_class_entry *phpgtk_ce_GtkLabel;
extern zend_class_entry *phpgtk_ce_GtkButton;
extern zend_class_entry *phpgtk_ce_GtkLinkButton;
extern zend_class_entry *phpgtk_ce_GCancellable;
extern zend_class_entry *phpgtk_ce_GAsyncResult;
extern zend_class_entry *phpgtk_ce_GtkUriLauncher;
extern zend_class_entry *phpgtk_ce_GFile;
extern zend_class_entry *phpgtk_ce_GListStore;
extern zend_class_entry *phpgtk_ce_GdkClipboard;
extern zend_class_entry *phpgtk_ce_GtkAlertDialog;
extern zend_class_entry *phpgtk_ce_GtkFileDialog;
extern zend_class_entry *phpgtk_ce_GtkFileLauncher;
extern zend_class_entry *phpgtk_ce_GtkCheckButton;
extern zend_class_entry *phpgtk_ce_GtkSwitch;
extern zend_class_entry *phpgtk_ce_GtkToggleButton;
extern zend_class_entry *phpgtk_ce_GtkEntryBuffer;
extern zend_class_entry *phpgtk_ce_GtkEntry;
extern zend_class_entry *phpgtk_ce_GtkTextBuffer;
extern zend_class_entry *phpgtk_ce_GtkTextView;
extern zend_class_entry *phpgtk_ce_GtkScale;
extern zend_class_entry *phpgtk_ce_GtkContentFit;
extern zend_class_entry *phpgtk_ce_GtkPolicyType;
extern zend_class_entry *phpgtk_ce_GtkStringList;
extern zend_class_entry *phpgtk_ce_GtkStringObject;
extern zend_class_entry *phpgtk_ce_GtkDropDown;
extern zend_class_entry *phpgtk_ce_GtkCalendar;
extern zend_class_entry *phpgtk_ce_GtkProgressBar;
extern zend_class_entry *phpgtk_ce_GtkSpinner;
extern zend_class_entry *phpgtk_ce_GtkPicture;
extern zend_class_entry *phpgtk_ce_GtkSeparator;
extern zend_class_entry *phpgtk_ce_GtkScrolledWindow;
extern zend_class_entry *phpgtk_ce_GtkPaned;
extern zend_class_entry *phpgtk_ce_GtkNotebook;
extern zend_class_entry *phpgtk_ce_GtkSignalListItemFactory;
extern zend_class_entry *phpgtk_ce_GtkListItem;
extern zend_class_entry *phpgtk_ce_GtkColumnViewColumn;
extern zend_class_entry *phpgtk_ce_GtkColumnView;
extern zend_class_entry *phpgtk_ce_GtkSingleSelection;
extern zend_class_entry *phpgtk_ce_GtkTreeListModel;
extern zend_class_entry *phpgtk_ce_GtkTreeListRow;
extern zend_class_entry *phpgtk_ce_GtkTreeExpander;
extern zend_class_entry *phpgtk_ce_GtkScrollInfo;
extern zend_class_entry *phpgtk_ce_GtkMediaStream;
extern zend_class_entry *phpgtk_ce_GtkMediaFile;
extern zend_class_entry *phpgtk_ce_GtkVideo;
extern zend_class_entry *phpgtk_ce_GtkPopoverMenuBar;
extern zend_class_entry *phpgtk_ce_GtkPopover;
extern zend_class_entry *phpgtk_ce_GtkPositionType;
extern zend_class_entry *phpgtk_ce_GtkMenuButton;
extern zend_class_entry *phpgtk_ce_GtkScrollbar;
extern zend_class_entry *phpgtk_ce_GtkListView;
extern zend_class_entry *phpgtk_ce_GtkPopoverMenu;
extern zend_class_entry *phpgtk_ce_GtkWindow;
extern zend_class_entry *phpgtk_ce_GtkApplicationWindow;
extern zend_class_entry *phpgtk_ce_GtkAboutDialog;
extern zend_class_entry *phpgtk_ce_GMenuModel;
extern zend_class_entry *phpgtk_ce_GMenu;
extern zend_class_entry *phpgtk_ce_GMenuItem;
extern zend_class_entry *phpgtk_ce_GSimpleAction;
extern zend_class_entry *phpgtk_ce_GSimpleActionGroup;
extern zend_class_entry *phpgtk_ce_GVariant;
extern zend_class_entry *phpgtk_ce_GDateTime;
extern zend_class_entry *phpgtk_ce_GParamSpec;
extern zend_class_entry *phpgtk_ce_GBytes;
extern zend_class_entry *phpgtk_ce_CairoRegion;
extern zend_class_entry *phpgtk_ce_GdkRectangle;
extern zend_class_entry *phpgtk_ce_GraphenePoint;
extern zend_class_entry *phpgtk_ce_GrapheneSize;
extern zend_class_entry *phpgtk_ce_GrapheneRect;
extern zend_class_entry *phpgtk_ce_GtkListItemFactory;

/* Interfaces. */
extern zend_class_entry *phpgtk_ce_GAction;
extern zend_class_entry *phpgtk_ce_GActionMap;
extern zend_class_entry *phpgtk_ce_GActionGroup;
extern zend_class_entry *phpgtk_ce_GListModel;
extern zend_class_entry *phpgtk_ce_GtkSelectionModel;
extern zend_class_entry *phpgtk_ce_GdkPaintable;
extern zend_class_entry *phpgtk_ce_GtkNative;
extern zend_class_entry *phpgtk_ce_GtkRoot;
extern zend_class_entry *phpgtk_ce_GtkStyleProvider;

void phpgtk_register_GObject(void);
void phpgtk_register_GApplication(void);
void phpgtk_register_GtkApplication(void);
void phpgtk_register_GMainContext(void);
void phpgtk_register_GVariant(void);
void phpgtk_register_GDateTime(void);
void phpgtk_register_GtkWidget(void);
void phpgtk_register_GtkEventController(void);
void phpgtk_register_GtkCss(void);
void phpgtk_register_GdkSurface(void);
void phpgtk_register_GdkGLContext(void);
void phpgtk_register_GtkGLArea(void);
void phpgtk_register_GdkTexture(void);
void phpgtk_register_GtkText(void);
void phpgtk_register_GtkControls(void);
void phpgtk_register_GtkUriLauncher(void);
void phpgtk_register_GtkDialogs(void);
void phpgtk_register_GtkColumnView(void);
void phpgtk_register_GtkVideo(void);
void phpgtk_register_GtkWindow(void);
void phpgtk_register_GMenu(void);
void phpgtk_register_GAction(void);

/* Object model. */
void phpgtk_object_setup(zend_class_entry *ce);
void phpgtk_map_gtype(const char *type_name, zend_class_entry *ce);
void phpgtk_box_gobject(zval *rv, gpointer object);
void phpgtk_box_main_context(zval *rv, GMainContext *context);
void phpgtk_box_variant(zval *rv, GVariant *variant);
void phpgtk_box_text_iter(zval *rv, const GtkTextIter *iter);
void phpgtk_box_date_time(zval *rv, GDateTime *date_time);
#if GTK_CHECK_VERSION(4, 14, 0)
void phpgtk_box_dmabuf_formats(zval *rv, GdkDmabufFormats *formats);
#endif
void phpgtk_box_gobject_full(zval *rv, gpointer object);
void phpgtk_box_event(zval *rv, GdkEvent *event);
void phpgtk_box_variant_full(zval *rv, GVariant *variant);
void phpgtk_box_bytes_full(zval *rv, GBytes *bytes);
void phpgtk_box_cairo_region_full(zval *rv, cairo_region_t *region);
void phpgtk_box_scroll_info_full(zval *rv, GtkScrollInfo *info);

/* Struct value classes: the struct a GdkRectangle object holds, and a new GdkRectangle / GraphenePoint /
 * GrapheneRect object holding a struct's fields. */
cairo_rectangle_int_t phpgtk_rectangle_from(zend_object *rectangle);
void phpgtk_rectangle_to(zval *rv, const cairo_rectangle_int_t *rectangle);
graphene_point_t phpgtk_graphene_point_from(zend_object *point);
void phpgtk_graphene_point_to(zval *rv, const graphene_point_t *point);
void phpgtk_graphene_rect_to(zval *rv, const graphene_rect_t *rect);
void phpgtk_box_param_spec(zval *rv, GParamSpec *pspec);

/* An interface's methods with their C bodies: a class implementing the interface inherits them as it
 * inherits a parent's. An internal interface registers its methods abstract, without a handler; each
 * gets its body here, before any class implements the interface. */
typedef struct {
	const char *name;
	zif_handler handler;
} phpgtk_interface_method;

void phpgtk_interface_bodies(zend_class_entry *iface, const phpgtk_interface_method *bodies);

/* An interface's interface_gets_implemented handler: the interface stands for a native GType, so only a class
 * whose objects are the extension's GObject wrappers implements it. A PHP class has no native form. */
int phpgtk_interface_native_only(zend_class_entry *iface, zend_class_entry *ce);

/* Values. */
zend_long phpgtk_enum_value(zend_object *obj_or_null, zend_long fallback);
void phpgtk_return_enum(zval *rv, zend_class_entry *ce, zend_long value);
bool phpgtk_fd_from_zval(zval *zfd, uint32_t arg_num, int *fd);
bool phpgtk_require_callable(zval *callable, uint32_t arg_num);
const char **phpgtk_string_array(HashTable *strings, uint32_t arg_num);
void phpgtk_async_ready(GObject *source, GAsyncResult *result, gpointer data);
void phpgtk_gvalue_to_zval(zval *rv, const GValue *value);
bool phpgtk_zval_to_gvalue(GValue *value, zval *zv);

/* Errors and threads. */
void phpgtk_throw_gerror(GError *error);
void phpgtk_gerror_object(zval *rv, const GError *error);
void phpgtk_return_string(zval *rv, const char *str);
bool phpgtk_is_detailed_action(const char *detailed);
bool phpgtk_on_main_thread(void);

/*
 * The probe switch. A kept refusal site reads `if (!PHPGTK_PROBE_OFF("<id>") && (<check>))`.
 * A build configured with --enable-gtk-probes lets env PHPGTK_PROBE_OFF=<id> turn that one
 * site off, so tests/Probes can show the crash the site prevents; any other build compiles
 * the switch out.
 */
#ifdef PHPGTK_PROBES
bool phpgtk_probe_off(const char *id);
# define PHPGTK_PROBE_OFF(id) phpgtk_probe_off(id)
#else
# define PHPGTK_PROBE_OFF(id) 0
#endif

/* Callouts. */
phpgtk_callout *phpgtk_callout_new(zval *callable);
void phpgtk_callout_retain(phpgtk_callout *callout);
void phpgtk_callout_release(phpgtk_callout *callout);
bool phpgtk_callout_invoke(phpgtk_callout *callout, uint32_t argc, zval *argv, zval *retval);
void phpgtk_callouts_detach_all(void);

/* True on a thread other than the PHP thread that made the callout. Every native entry point asks this before
 * boxing anything and drops the call when it is: PHP's state is per thread, and another thread would run the
 * callable against the wrong engine, or none. */
bool phpgtk_callout_foreign(const phpgtk_callout *callout);

/* A zend_long argument that must fit a native range; refused with ValueError otherwise. */
bool phpgtk_long_in_range(zend_long value, zend_long min, zend_long max, uint32_t arg_num);


/* On macOS the GDK backend calls AppKit, which dies off the process main thread (an uncaught
 * NSInternalInconsistencyException). On Linux GTK runs off it, so the call goes through. */
#ifdef __APPLE__
#define PHPGTK_REQUIRE_MAIN_THREAD() do { \
	if (!PHPGTK_PROBE_OFF("main-thread-macos") && (!phpgtk_on_main_thread())) { \
		zend_throw_exception_ex(phpgtk_ce_GtkException, 0, /* binding:main-thread-macos */ \
			"%s() must be called on the main thread", ZSTR_VAL(EX(func)->common.function_name)); \
		RETURN_THROWS(); \
	} \
} while (0)
#else
#define PHPGTK_REQUIRE_MAIN_THREAD() do { } while (0)
#endif

/* Widgets need GTK initialised (gtk_init, or a GtkApplication's startup); GTK crashes otherwise. */
#define PHPGTK_REQUIRE_INITIALIZED() do { \
	if (!PHPGTK_PROBE_OFF("gtk-initialized") && (!gtk_is_initialized())) { \
		zend_throw_exception_ex(phpgtk_ce_GtkException, 0, /* binding:gtk-initialized */ \
			"%s() needs GTK initialised: call gtk_init() or register a GtkApplication first", \
			ZSTR_VAL(EX(func)->common.function_name)); \
		RETURN_THROWS(); \
	} \
} while (0)

#endif
