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

/* A PHP callable held for GLib to call back into: a source's function or a signal handler. */
typedef struct phpgtk_callout {
	zval callable;                 /* UNDEF once detached at request end */
	uint32_t refcount;             /* 1 for GLib's reference, +1 while invoking */
	guint source_id;               /* set for a source */
	GObject *instance;             /* set for a signal handler, not referenced */
	gulong handler_id;
	struct phpgtk_callout *prev;
	struct phpgtk_callout *next;
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
} phpgtk_kind;

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

extern zend_class_entry *phpgtk_ce_GtkException;
extern zend_class_entry *phpgtk_ce_GError;
extern zend_class_entry *phpgtk_ce_GIOCondition;
extern zend_class_entry *phpgtk_ce_GObject;
extern zend_class_entry *phpgtk_ce_GApplication;
extern zend_class_entry *phpgtk_ce_GApplicationFlags;
extern zend_class_entry *phpgtk_ce_GtkApplication;
extern zend_class_entry *phpgtk_ce_GMainContext;
extern zend_class_entry *phpgtk_ce_GtkOrientation;
extern zend_class_entry *phpgtk_ce_GtkWidget;
extern zend_class_entry *phpgtk_ce_GtkBox;
extern zend_class_entry *phpgtk_ce_GtkPopoverMenuBar;
extern zend_class_entry *phpgtk_ce_GtkWindow;
extern zend_class_entry *phpgtk_ce_GtkApplicationWindow;
extern zend_class_entry *phpgtk_ce_GtkAboutDialog;
extern zend_class_entry *phpgtk_ce_GMenuModel;
extern zend_class_entry *phpgtk_ce_GMenu;
extern zend_class_entry *phpgtk_ce_GMenuItem;
extern zend_class_entry *phpgtk_ce_GSimpleAction;
extern zend_class_entry *phpgtk_ce_GSimpleActionGroup;
extern zend_class_entry *phpgtk_ce_GVariant;

void phpgtk_register_GObject(void);
void phpgtk_register_GApplication(void);
void phpgtk_register_GtkApplication(void);
void phpgtk_register_GMainContext(void);
void phpgtk_register_GVariant(void);
void phpgtk_register_GtkWidget(void);
void phpgtk_register_GtkWindow(void);
void phpgtk_register_GMenu(void);
void phpgtk_register_GAction(void);

/* Object model. */
void phpgtk_object_setup(zend_class_entry *ce);
void phpgtk_map_gtype(const char *type_name, zend_class_entry *ce);
void phpgtk_box_gobject(zval *rv, gpointer object);
void phpgtk_box_main_context(zval *rv, GMainContext *context);
void phpgtk_box_variant(zval *rv, GVariant *variant);
void phpgtk_box_gobject_full(zval *rv, gpointer object);
void phpgtk_box_variant_full(zval *rv, GVariant *variant);

/* Values. */
zend_long phpgtk_enum_value(zend_object *obj_or_null, zend_long fallback);
bool phpgtk_fd_from_zval(zval *zfd, uint32_t arg_num, int *fd);
void phpgtk_gvalue_to_zval(zval *rv, const GValue *value);
void phpgtk_zval_to_gvalue(GValue *value, zval *zv);

/* Errors and threads. */
void phpgtk_throw_gerror(GError *error);
void phpgtk_return_string(zval *rv, const char *str);
bool phpgtk_is_detailed_action(const char *detailed);
bool phpgtk_on_main_thread(void);

/* GActionMap and GActionGroup method bodies, shared by the classes implementing them. */
void phpgtk_action_map_add_action(INTERNAL_FUNCTION_PARAMETERS);
void phpgtk_action_map_remove_action(INTERNAL_FUNCTION_PARAMETERS);
void phpgtk_action_map_lookup_action(INTERNAL_FUNCTION_PARAMETERS);
void phpgtk_action_group_has_action(INTERNAL_FUNCTION_PARAMETERS);
void phpgtk_action_group_list_actions(INTERNAL_FUNCTION_PARAMETERS);
void phpgtk_action_group_activate_action(INTERNAL_FUNCTION_PARAMETERS);

/* Callouts. */
phpgtk_callout *phpgtk_callout_new(zval *callable);
void phpgtk_callout_retain(phpgtk_callout *callout);
void phpgtk_callout_release(phpgtk_callout *callout);
bool phpgtk_callout_invoke(phpgtk_callout *callout, uint32_t argc, zval *argv, zval *retval);
void phpgtk_callouts_detach_all(void);

/* GTK asserts it runs on the thread that initialised it; this refuses other threads. */
#define PHPGTK_REQUIRE_MAIN_THREAD() do { \
	if (!phpgtk_on_main_thread()) { \
		zend_throw_exception_ex(phpgtk_ce_GtkException, 0, \
			"%s() must be called on the main thread", ZSTR_VAL(EX(func)->common.function_name)); \
		RETURN_THROWS(); \
	} \
} while (0)

/* Widgets need GTK initialised (gtk_init, or a GtkApplication's startup); GTK crashes otherwise. */
#define PHPGTK_REQUIRE_INITIALIZED() do { \
	if (!gtk_is_initialized()) { \
		zend_throw_exception_ex(phpgtk_ce_GtkException, 0, \
			"%s() needs GTK initialised: call gtk_init() or register a GtkApplication first", \
			ZSTR_VAL(EX(func)->common.function_name)); \
		RETURN_THROWS(); \
	} \
} while (0)

#endif
