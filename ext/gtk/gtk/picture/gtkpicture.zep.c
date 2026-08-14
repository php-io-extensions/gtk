
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
#include "kernel/operators.h"
#include "kernel/memory.h"

#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);



ZEPHIR_INIT_CLASS(Gtk_GTK_Picture_GtkPicture)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\Picture, GtkPicture, gtk, gtk_picture_gtkpicture, gtk_gtk_picture_gtkpicture_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_Picture_GtkPicture, gtkPictureNew)
{
	zend_long handle = 0;
	
            GtkWidget *picture;

            php_gtk_set_last_error(NULL);
            picture = gtk_picture_new();
            if (picture == NULL) {
                php_gtk_set_last_error("gtk_picture_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) picture;
            }
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_Picture_GtkPicture, gtkPictureNewForFilename)
{
	zend_long handle = 0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *filename_param = NULL;
	zval filename;

	ZVAL_UNDEF(&filename);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(filename_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &filename_param);
	zephir_get_strval(&filename, filename_param);
	
            GtkWidget *picture;

            php_gtk_set_last_error(NULL);
            picture = gtk_picture_new_for_filename(Z_STRVAL(filename));
            if (picture == NULL) {
                php_gtk_set_last_error("gtk_picture_new_for_filename returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) picture;
            }
        
	RETURN_MM_LONG(handle);
}

PHP_METHOD(Gtk_GTK_Picture_GtkPicture, gtkPictureSetFilename)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval filename;
	zval *picture_param = NULL, *filename_param = NULL;
	zend_long picture;

	ZVAL_UNDEF(&filename);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(picture)
		Z_PARAM_ZVAL(filename_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &picture_param, &filename_param);
	zephir_get_strval(&filename, filename_param);
	
            GtkPicture *pic = GTK_PICTURE((void *)(uintptr_t) picture);
            if (pic != NULL) {
                gtk_picture_set_filename(pic, Z_STRVAL(filename));
            }
        
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_GTK_Picture_GtkPicture, gtkPictureSetCanShrink)
{
	zend_bool canShrink;
	zval *picture_param = NULL, *canShrink_param = NULL;
	zend_long picture;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(picture)
		Z_PARAM_BOOL(canShrink)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &picture_param, &canShrink_param);
	
            GtkPicture *pic = GTK_PICTURE((void *)(uintptr_t) picture);
            if (pic != NULL) {
                gtk_picture_set_can_shrink(pic, canShrink ? TRUE : FALSE);
            }
        
}

