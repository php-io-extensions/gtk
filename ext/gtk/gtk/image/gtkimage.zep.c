
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



ZEPHIR_INIT_CLASS(Gtk_GTK_Image_GtkImage)
{
	ZEPHIR_REGISTER_CLASS(Gtk\\GTK\\Image, GtkImage, gtk, gtk_image_gtkimage, gtk_gtk_image_gtkimage_method_entry, 0);

	return SUCCESS;
}

PHP_METHOD(Gtk_GTK_Image_GtkImage, gtkImageNew)
{
	zend_long handle = 0;
	
            GtkWidget *image;

            php_gtk_set_last_error(NULL);
            image = gtk_image_new();
            if (image == NULL) {
                php_gtk_set_last_error("gtk_image_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) image;
            }
        
	RETURN_LONG(handle);
}

PHP_METHOD(Gtk_GTK_Image_GtkImage, gtkImageNewFromFile)
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
	
            GtkWidget *image;

            php_gtk_set_last_error(NULL);
            image = gtk_image_new_from_file(Z_STRVAL(filename));
            if (image == NULL) {
                php_gtk_set_last_error("gtk_image_new_from_file returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) image;
            }
        
	RETURN_MM_LONG(handle);
}

PHP_METHOD(Gtk_GTK_Image_GtkImage, gtkImageSetFromFile)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval filename;
	zval *image_param = NULL, *filename_param = NULL;
	zend_long image;

	ZVAL_UNDEF(&filename);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(image)
		Z_PARAM_ZVAL(filename_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &image_param, &filename_param);
	zephir_get_strval(&filename, filename_param);
	
            GtkImage *img = GTK_IMAGE((void *)(uintptr_t) image);
            if (img != NULL) {
                gtk_image_set_from_file(img, Z_STRVAL(filename));
            }
        
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_GTK_Image_GtkImage, gtkImageSetFromIconName)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval iconName;
	zval *image_param = NULL, *iconName_param = NULL;
	zend_long image;

	ZVAL_UNDEF(&iconName);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(image)
		Z_PARAM_ZVAL(iconName_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &image_param, &iconName_param);
	zephir_get_strval(&iconName, iconName_param);
	
            GtkImage *img = GTK_IMAGE((void *)(uintptr_t) image);
            if (img != NULL) {
                gtk_image_set_from_icon_name(img, Z_STRVAL(iconName));
            }
        
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Gtk_GTK_Image_GtkImage, gtkImageClear)
{
	zval *image_param = NULL;
	zend_long image;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(image)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(1, 0, &image_param);
	
            GtkImage *img = GTK_IMAGE((void *)(uintptr_t) image);
            if (img != NULL) {
                gtk_image_clear(img);
            }
        
}

PHP_METHOD(Gtk_GTK_Image_GtkImage, gtkImageSetPixelSize)
{
	zval *image_param = NULL, *size_param = NULL;
	zend_long image, size;

	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_LONG(image)
		Z_PARAM_LONG(size)
	ZEND_PARSE_PARAMETERS_END();
	zephir_fetch_params_without_memory_grow(2, 0, &image_param, &size_param);
	
            GtkImage *img = GTK_IMAGE((void *)(uintptr_t) image);
            if (img != NULL) {
                gtk_image_set_pixel_size(img, (int) size);
            }
        
}

