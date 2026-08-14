
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"

#include <gtk/gtk.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

char php_gtk_last_error[256] = {0};

void php_gtk_set_last_error(const char *msg)
{
    if (msg == NULL || msg[0] == '\0') {
        php_gtk_last_error[0] = '\0';
        return;
    }
    snprintf(php_gtk_last_error, sizeof(php_gtk_last_error), "%s", msg);
}

typedef struct _PhpGtkClosure {
    GClosure closure;
    zval callback;
} PhpGtkClosure;

static void php_gtk_gvalue_to_zval(const GValue *value, zval *out)
{
    if (G_VALUE_HOLDS_OBJECT(value)) {
        ZVAL_LONG(out, (zend_long)(uintptr_t) g_value_get_object(value));
        return;
    }
    if (G_VALUE_HOLDS_POINTER(value)) {
        ZVAL_LONG(out, (zend_long)(uintptr_t) g_value_get_pointer(value));
        return;
    }
    if (G_VALUE_HOLDS_BOOLEAN(value)) {
        ZVAL_BOOL(out, g_value_get_boolean(value));
        return;
    }
    if (G_VALUE_HOLDS_INT(value)) {
        ZVAL_LONG(out, g_value_get_int(value));
        return;
    }
    if (G_VALUE_HOLDS_UINT(value)) {
        ZVAL_LONG(out, (zend_long) g_value_get_uint(value));
        return;
    }
    if (G_VALUE_HOLDS_LONG(value)) {
        ZVAL_LONG(out, (zend_long) g_value_get_long(value));
        return;
    }
    if (G_VALUE_HOLDS_INT64(value)) {
        ZVAL_LONG(out, (zend_long) g_value_get_int64(value));
        return;
    }
    if (G_VALUE_HOLDS_DOUBLE(value)) {
        ZVAL_DOUBLE(out, g_value_get_double(value));
        return;
    }
    if (G_VALUE_HOLDS_STRING(value)) {
        const char *s = g_value_get_string(value);
        if (s == NULL) {
            ZVAL_EMPTY_STRING(out);
        } else {
            ZVAL_STRING(out, s);
        }
        return;
    }
    if (G_VALUE_HOLDS_ENUM(value)) {
        ZVAL_LONG(out, g_value_get_enum(value));
        return;
    }
    if (G_VALUE_HOLDS_FLAGS(value)) {
        ZVAL_LONG(out, g_value_get_flags(value));
        return;
    }
    ZVAL_LONG(out, 0);
}

static void php_gtk_zval_to_gvalue(zval *in, GValue *return_value)
{
    GType t;

    if (return_value == NULL || !G_IS_VALUE(return_value) || in == NULL || Z_ISUNDEF_P(in)) {
        return;
    }
    t = G_VALUE_TYPE(return_value);
    if (t == G_TYPE_BOOLEAN) {
        g_value_set_boolean(return_value, zend_is_true(in) ? TRUE : FALSE);
        return;
    }
    if (t == G_TYPE_INT) {
        g_value_set_int(return_value, (gint) zval_get_long(in));
        return;
    }
    if (t == G_TYPE_UINT) {
        g_value_set_uint(return_value, (guint) zval_get_long(in));
        return;
    }
    if (t == G_TYPE_LONG) {
        g_value_set_long(return_value, (glong) zval_get_long(in));
        return;
    }
    if (t == G_TYPE_INT64) {
        g_value_set_int64(return_value, (gint64) zval_get_long(in));
        return;
    }
    if (t == G_TYPE_DOUBLE || t == G_TYPE_FLOAT) {
        g_value_set_double(return_value, zval_get_double(in));
        return;
    }
    if (t == G_TYPE_STRING) {
        zend_string *str = zval_get_string(in);
        g_value_set_string(return_value, ZSTR_VAL(str));
        zend_string_release(str);
        return;
    }
}

void php_gtk_closure_marshal(GClosure *closure, GValue *return_value, guint n_param_values, const GValue *param_values, gpointer invocation_hint, gpointer marshal_data)
{
    PhpGtkClosure *pc = (PhpGtkClosure *) closure;
    zval retval;
    zval *params;
    guint i;

    (void) invocation_hint;
    (void) marshal_data;

    if (Z_TYPE(pc->callback) == IS_UNDEF || Z_TYPE(pc->callback) == IS_NULL) {
        return;
    }

    params = (zval *) safe_emalloc(n_param_values > 0 ? n_param_values : 1, sizeof(zval), 0);
    for (i = 0; i < n_param_values; i++) {
        php_gtk_gvalue_to_zval(&param_values[i], &params[i]);
    }

    ZVAL_UNDEF(&retval);
    call_user_function(EG(function_table), NULL, &pc->callback, &retval, n_param_values, params);

    if (return_value != NULL && G_IS_VALUE(return_value) && !Z_ISUNDEF(retval)) {
        php_gtk_zval_to_gvalue(&retval, return_value);
    }

    if (!Z_ISUNDEF(retval)) {
        zval_ptr_dtor(&retval);
    }
    for (i = 0; i < n_param_values; i++) {
        zval_ptr_dtor(&params[i]);
    }
    efree(params);
}

void php_gtk_closure_finalize(gpointer data, GClosure *closure)
{
    PhpGtkClosure *pc = (PhpGtkClosure *) closure;
    (void) data;
    zval_ptr_dtor(&pc->callback);
}

void *php_gtk_closure_new(zval *callback)
{
    PhpGtkClosure *pc = (PhpGtkClosure *) g_closure_new_simple(sizeof(PhpGtkClosure), NULL);
    ZVAL_COPY(&pc->callback, callback);
    g_closure_add_finalize_notifier((GClosure *) pc, NULL, php_gtk_closure_finalize);
    g_closure_set_marshal((GClosure *) pc, php_gtk_closure_marshal);
    return pc;
}

gboolean php_gtk_tick_bridge(GtkWidget *widget, GdkFrameClock *clock, gpointer data)
{
    zval *callback = (zval *) data;
    zval retval;
    zval params[1];

    (void) clock;
    if (callback == NULL || Z_TYPE_P(callback) == IS_UNDEF || Z_TYPE_P(callback) == IS_NULL) {
        return FALSE;
    }

    ZVAL_LONG(&params[0], (zend_long)(uintptr_t) widget);
    ZVAL_UNDEF(&retval);
    call_user_function(EG(function_table), NULL, callback, &retval, 1, params);
    if (Z_ISUNDEF(retval)) {
        return TRUE;
    }
    {
        gboolean keep = zend_is_true(&retval) ? TRUE : FALSE;
        zval_ptr_dtor(&retval);
        return keep;
    }
}

void php_gtk_tick_dtor(gpointer data)
{
    zval *callback = (zval *) data;
    if (callback != NULL) {
        zval_ptr_dtor(callback);
        efree(callback);
    }
}

char **php_gtk_zval_to_strv(zval *arr)
{
    HashTable *ht;
    zval *entry;
    char **strv;
    guint n;
    guint i;

    if (arr == NULL || Z_TYPE_P(arr) != IS_ARRAY) {
        return NULL;
    }
    ht = Z_ARRVAL_P(arr);
    n = zend_hash_num_elements(ht);
    strv = (char **) ecalloc(n + 1, sizeof(char *));
    i = 0;
    ZEND_HASH_FOREACH_VAL(ht, entry) {
        zend_string *s = zval_get_string(entry);
        strv[i] = estrndup(ZSTR_VAL(s), ZSTR_LEN(s));
        zend_string_release(s);
        i++;
    } ZEND_HASH_FOREACH_END();
    strv[i] = NULL;
    return strv;
}

void php_gtk_strv_free(char **strv)
{
    guint i;

    if (strv == NULL) {
        return;
    }
    for (i = 0; strv[i] != NULL; i++) {
        efree(strv[i]);
    }
    efree(strv);
}

#define PHP_GTK_ASYNC_ALERT 1
#define PHP_GTK_ASYNC_FILE_OPEN 2
#define PHP_GTK_ASYNC_FILE_SAVE 3
#define PHP_GTK_ASYNC_FILE_FOLDER 4
#define PHP_GTK_ASYNC_COLOR 5
#define PHP_GTK_ASYNC_FONT 6

typedef struct _PhpGtkAsyncJob {
    zval callback;
    int kind;
} PhpGtkAsyncJob;

PhpGtkAsyncJob *php_gtk_async_job_new(zval *callback, int kind)
{
    PhpGtkAsyncJob *job;

    job = (PhpGtkAsyncJob *) ecalloc(1, sizeof(PhpGtkAsyncJob));
    ZVAL_COPY(&job->callback, callback);
    job->kind = kind;
    return job;
}

void php_gtk_async_ready(GObject *source, GAsyncResult *res, gpointer data)
{
    PhpGtkAsyncJob *job = (PhpGtkAsyncJob *) data;
    zval arg;
    zval retval;
    GError *err = NULL;

    ZVAL_NULL(&arg);

    if (job->kind == PHP_GTK_ASYNC_ALERT) {
        int idx = gtk_alert_dialog_choose_finish(GTK_ALERT_DIALOG(source), res, &err);
        if (err != NULL) {
            php_gtk_set_last_error(err->message);
            g_error_free(err);
            ZVAL_LONG(&arg, -1);
        } else {
            ZVAL_LONG(&arg, (zend_long) idx);
        }
    } else if (job->kind == PHP_GTK_ASYNC_FILE_OPEN || job->kind == PHP_GTK_ASYNC_FILE_SAVE || job->kind == PHP_GTK_ASYNC_FILE_FOLDER) {
        GFile *file = NULL;
        if (job->kind == PHP_GTK_ASYNC_FILE_OPEN) {
            file = gtk_file_dialog_open_finish(GTK_FILE_DIALOG(source), res, &err);
        } else if (job->kind == PHP_GTK_ASYNC_FILE_SAVE) {
            file = gtk_file_dialog_save_finish(GTK_FILE_DIALOG(source), res, &err);
        } else {
            file = gtk_file_dialog_select_folder_finish(GTK_FILE_DIALOG(source), res, &err);
        }
        if (file != NULL) {
            char *path = g_file_get_path(file);
            ZVAL_STRING(&arg, path ? path : "");
            g_free(path);
            g_object_unref(file);
        } else {
            if (err != NULL) {
                php_gtk_set_last_error(err->message);
                g_error_free(err);
            }
            ZVAL_EMPTY_STRING(&arg);
        }
    } else if (job->kind == PHP_GTK_ASYNC_COLOR) {
        GdkRGBA *rgba = gtk_color_dialog_choose_rgba_finish(GTK_COLOR_DIALOG(source), res, &err);
        if (rgba != NULL) {
            char buf[128];
            snprintf(buf, sizeof(buf), "%g,%g,%g,%g", rgba->red, rgba->green, rgba->blue, rgba->alpha);
            ZVAL_STRING(&arg, buf);
            gdk_rgba_free(rgba);
        } else {
            if (err != NULL) {
                php_gtk_set_last_error(err->message);
                g_error_free(err);
            }
            ZVAL_EMPTY_STRING(&arg);
        }
    } else if (job->kind == PHP_GTK_ASYNC_FONT) {
        PangoFontDescription *desc = gtk_font_dialog_choose_font_finish(GTK_FONT_DIALOG(source), res, &err);
        if (desc != NULL) {
            char *s = pango_font_description_to_string(desc);
            ZVAL_STRING(&arg, s ? s : "");
            g_free(s);
            pango_font_description_free(desc);
        } else {
            if (err != NULL) {
                php_gtk_set_last_error(err->message);
                g_error_free(err);
            }
            ZVAL_EMPTY_STRING(&arg);
        }
    }

    ZVAL_UNDEF(&retval);
    call_user_function(EG(function_table), NULL, &job->callback, &retval, 1, &arg);
    if (!Z_ISUNDEF(retval)) {
        zval_ptr_dtor(&retval);
    }
    zval_ptr_dtor(&arg);
    zval_ptr_dtor(&job->callback);
    efree(job);
}



/**
 * GTK4 init and version. Thin wrappers over gtk_init_check / gtk_get_*_version.
 */
ZEPHIR_INIT_CLASS(Gtk_GTK_Gtk)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK, Gtk, gtk, gtk_gtk, gtk_gtk_gtk_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_Gtk, gtkInitCheck)
{
	zend_bool result = 0;
	
            result = gtk_init_check() ? true : false;
        
	RETURN_BOOL(result);
}

PHP_METHOD(Gtk_GTK_Gtk, gtkGetMajorVersion)
{
	zend_long version = 0;
	
            version = (zend_long) gtk_get_major_version();
        
	RETURN_LONG(version);
}

PHP_METHOD(Gtk_GTK_Gtk, gtkGetMinorVersion)
{
	zend_long version = 0;
	
            version = (zend_long) gtk_get_minor_version();
        
	RETURN_LONG(version);
}

PHP_METHOD(Gtk_GTK_Gtk, gtkGetMicroVersion)
{
	zend_long version = 0;
	
            version = (zend_long) gtk_get_micro_version();
        
	RETURN_LONG(version);
}

PHP_METHOD(Gtk_GTK_Gtk, gtkGetBinaryAge)
{
	zend_long age = 0;
	
            age = (zend_long) gtk_get_binary_age();
        
	RETURN_LONG(age);
}

