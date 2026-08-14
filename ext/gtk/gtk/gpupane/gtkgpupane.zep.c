
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/operators.h"

#include <gtk/gtk.h>
#include <gdk/gdk.h>
#ifdef GDK_WINDOWING_X11
#include <gdk/x11/gdkx.h>
#include <X11/Xlib.h>
#endif
#include <stdint.h>
#include <string.h>

extern void php_gtk_set_last_error(const char *msg);

typedef struct _PhpGtkGpuPaneNative {
    void *display;
    unsigned long window;
    int created;
} PhpGtkGpuPaneNative;

static const char *PHP_GTK_GPU_PANE_KEY = "php-gtk-gpu-pane-native";

static void php_gtk_gpu_pane_native_free(void *data)
{
    efree(data);
}

static PhpGtkGpuPaneNative *php_gtk_gpu_pane_get(GtkWidget *widget)
{
    return (PhpGtkGpuPaneNative *) g_object_get_data(G_OBJECT(widget), PHP_GTK_GPU_PANE_KEY);
}

#ifdef GDK_WINDOWING_X11
static void php_gtk_gpu_pane_measure(GtkWidget *widget, int *width, int *height)
{
    GtkRoot *root;
    int dw = 0;
    int dh = 0;

    *width = gtk_widget_get_width(widget);
    *height = gtk_widget_get_height(widget);
    if (*width < 1) {
        *width = gtk_widget_get_allocated_width(widget);
    }
    if (*height < 1) {
        *height = gtk_widget_get_allocated_height(widget);
    }
    if ((*width < 1 || *height < 1) && gtk_widget_get_root(widget) != NULL) {
        root = gtk_widget_get_root(widget);
        if (GTK_IS_WINDOW(root)) {
            gtk_window_get_default_size(GTK_WINDOW(root), &dw, &dh);
            if (*width < 1) {
                *width = dw;
            }
            if (*height < 1) {
                *height = dh;
            }
        }
    }
    if (*width < 1) {
        *width = 640;
    }
    if (*height < 1) {
        *height = 480;
    }
}

static int php_gtk_gpu_pane_root_geom(GtkWidget *widget, Display **dpy_out, int *root_x, int *root_y)
{
    GtkNative *native;
    GdkSurface *surface;
    GdkDisplay *display;
    Display *dpy;
    Window gdk_xid;
    Window unused;
    graphene_point_t src;
    graphene_point_t dest;
    int local_x = 0;
    int local_y = 0;

    native = gtk_widget_get_native(widget);
    if (native == NULL) {
        return 0;
    }
    surface = gtk_native_get_surface(native);
    if (surface == NULL) {
        return 0;
    }
    display = gdk_surface_get_display(surface);
    if (display == NULL || !GDK_IS_X11_DISPLAY(display)) {
        return 0;
    }

    dpy = gdk_x11_display_get_xdisplay(display);
    gdk_xid = gdk_x11_surface_get_xid(surface);
    if (dpy == NULL || gdk_xid == 0) {
        return 0;
    }

    src = GRAPHENE_POINT_INIT(0.f, 0.f);
    dest = GRAPHENE_POINT_INIT(0.f, 0.f);
    if (gtk_widget_compute_point(widget, GTK_WIDGET(native), &src, &dest)) {
        local_x = (int) dest.x;
        local_y = (int) dest.y;
    }

    if (!XTranslateCoordinates(dpy, gdk_xid, DefaultRootWindow(dpy), local_x, local_y, root_x, root_y, &unused)) {
        return 0;
    }

    *dpy_out = dpy;
    return 1;
}

static void php_gtk_gpu_pane_sync_x11(GtkWidget *widget)
{
    PhpGtkGpuPaneNative *state;
    Display *dpy = NULL;
    int root_x = 0;
    int root_y = 0;
    int width = 0;
    int height = 0;

    state = php_gtk_gpu_pane_get(widget);
    if (state == NULL) {
        return;
    }
    if (!php_gtk_gpu_pane_root_geom(widget, &dpy, &root_x, &root_y)) {
        php_gtk_set_last_error("gtk_gpu_pane: native is not X11 or not realized (GDK_BACKEND=x11 DISPLAY=:0)");
        return;
    }

    php_gtk_gpu_pane_measure(widget, &width, &height);

    if (!state->created) {
        XSetWindowAttributes swa;
        Window child;

        memset(&swa, 0, sizeof(swa));
        swa.override_redirect = True;
        swa.event_mask = ExposureMask | StructureNotifyMask;
        child = XCreateWindow(
            dpy,
            DefaultRootWindow(dpy),
            root_x,
            root_y,
            (unsigned int) width,
            (unsigned int) height,
            0,
            CopyFromParent,
            InputOutput,
            CopyFromParent,
            CWOverrideRedirect | CWEventMask,
            &swa
        );
        if (child == 0) {
            php_gtk_set_last_error("gtk_gpu_pane: XCreateWindow failed");
            return;
        }
        XMapRaised(dpy, child);
        XRaiseWindow(dpy, child);
        XFlush(dpy);
        state->display = dpy;
        state->window = (unsigned long) child;
        state->created = 1;
        php_gtk_set_last_error(NULL);
        return;
    }

    if (state->display != dpy) {
        php_gtk_set_last_error("gtk_gpu_pane: X11 display changed");
        return;
    }
    XMoveResizeWindow(dpy, (Window) state->window, root_x, root_y, (unsigned int) width, (unsigned int) height);
    XRaiseWindow(dpy, (Window) state->window);
    XFlush(dpy);
}

static void php_gtk_gpu_pane_destroy_x11(GtkWidget *widget)
{
    PhpGtkGpuPaneNative *state;

    state = php_gtk_gpu_pane_get(widget);
    if (state == NULL || !state->created || state->display == NULL || state->window == 0) {
        return;
    }
    XDestroyWindow((Display *) state->display, (Window) state->window);
    XFlush((Display *) state->display);
    state->display = NULL;
    state->window = 0;
    state->created = 0;
}
#endif

static void php_gtk_gpu_pane_on_realize(GtkWidget *widget, gpointer data)
{
    (void) data;
#ifdef GDK_WINDOWING_X11
    php_gtk_gpu_pane_sync_x11(widget);
#else
    (void) widget;
    php_gtk_set_last_error("gtk_gpu_pane: X11 backend not compiled");
#endif
}

static void php_gtk_gpu_pane_on_map(GtkWidget *widget, gpointer data)
{
    (void) data;
#ifdef GDK_WINDOWING_X11
    php_gtk_gpu_pane_sync_x11(widget);
#else
    (void) widget;
#endif
}

static void php_gtk_gpu_pane_on_unrealize(GtkWidget *widget, gpointer data)
{
    (void) data;
#ifdef GDK_WINDOWING_X11
    php_gtk_gpu_pane_destroy_x11(widget);
#else
    (void) widget;
#endif
}

static void php_gtk_gpu_pane_on_notify_size(GtkWidget *widget, GParamSpec *pspec, gpointer data)
{
    (void) pspec;
    (void) data;
#ifdef GDK_WINDOWING_X11
    php_gtk_gpu_pane_sync_x11(widget);
#else
    (void) widget;
#endif
}

static void php_gtk_gpu_pane_on_draw(GtkDrawingArea *area, cairo_t *cr, int width, int height, gpointer data)
{
    (void) area;
    (void) cr;
    (void) width;
    (void) height;
    (void) data;
}



/**
 * Host a dedicated X11 window aligned to the widget allocation for foreign GPU WSI.
 * Not a child of the redirected GdkSurface (GSK would hide it). Not GtkVulkanArea.
 */
ZEPHIR_INIT_CLASS(Gtk_GTK_GpuPane_GtkGpuPane)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\GpuPane, GtkGpuPane, gtk, gtk_gpupane_gtkgpupane, gtk_gtk_gpupane_gtkgpupane_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_GpuPane_GtkGpuPane, gtkGpuPaneNew)
{
	zend_long handle = 0;
	
            GtkWidget *pane;
            PhpGtkGpuPaneNative *state;

            php_gtk_set_last_error(NULL);
            pane = gtk_drawing_area_new();
            if (pane == NULL) {
                php_gtk_set_last_error("gtk_gpu_pane_new: gtk_drawing_area_new returned NULL");
                handle = 0;
            } else {
                state = (PhpGtkGpuPaneNative *) ecalloc(1, sizeof(PhpGtkGpuPaneNative));
                g_object_set_data_full(G_OBJECT(pane), PHP_GTK_GPU_PANE_KEY, state, php_gtk_gpu_pane_native_free);
                gtk_widget_set_hexpand(pane, TRUE);
                gtk_widget_set_vexpand(pane, TRUE);
                gtk_widget_set_can_focus(pane, FALSE);
                gtk_widget_set_opacity(pane, 0.0);
                gtk_drawing_area_set_draw_func(GTK_DRAWING_AREA(pane), php_gtk_gpu_pane_on_draw, NULL, NULL);
                g_signal_connect(pane, "realize", G_CALLBACK(php_gtk_gpu_pane_on_realize), NULL);
                g_signal_connect(pane, "map", G_CALLBACK(php_gtk_gpu_pane_on_map), NULL);
                g_signal_connect(pane, "unrealize", G_CALLBACK(php_gtk_gpu_pane_on_unrealize), NULL);
                g_signal_connect(pane, "notify::width", G_CALLBACK(php_gtk_gpu_pane_on_notify_size), NULL);
                g_signal_connect(pane, "notify::height", G_CALLBACK(php_gtk_gpu_pane_on_notify_size), NULL);
                handle = (zend_long)(uintptr_t) pane;
            }
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_GpuPane_GtkGpuPane, gtkGpuPaneNative)
{
	zval backend;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *pane_param = NULL, _0;
	zend_long pane, display = 0, window = 0;

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&backend);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(pane)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &pane_param);
	
            GtkWidget *widget = GTK_WIDGET((void *)(uintptr_t) pane);
            PhpGtkGpuPaneNative *state = NULL;
            const char *name = "";

            php_gtk_set_last_error(NULL);
            display = 0;
            window = 0;
            if (widget != NULL) {
#ifdef GDK_WINDOWING_X11
                php_gtk_gpu_pane_sync_x11(widget);
#endif
                state = php_gtk_gpu_pane_get(widget);
            }
            if (state != NULL && state->created && state->display != NULL && state->window != 0) {
                name = "x11";
                display = (zend_long)(uintptr_t) state->display;
                window = (zend_long) state->window;
            } else if (widget == NULL) {
                php_gtk_set_last_error("gtk_gpu_pane_native: pane handle is 0");
            } else {
                php_gtk_set_last_error("gtk_gpu_pane_native: X11 surface not ready (GDK_BACKEND=x11 DISPLAY=:0)");
            }
            ZVAL_STRING(&backend, name);
        
	zephir_create_array(return_value, 3, 0);
	zephir_array_update_string(return_value, SL("backend"), &backend, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_LONG(&_0, display);
	zephir_array_update_string(return_value, SL("display"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_LONG(&_0, window);
	zephir_array_update_string(return_value, SL("window"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

