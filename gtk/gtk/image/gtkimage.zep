namespace Gtk\GTK\Image;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

class GtkImage
{
    public static function gtkImageNew() -> int
    {
        int handle;
        %{
            GtkWidget *image;

            php_gtk_set_last_error(NULL);
            image = gtk_image_new();
            if (image == NULL) {
                php_gtk_set_last_error("gtk_image_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) image;
            }
        }%
        return handle;
    }

    public static function gtkImageNewFromFile(string filename) -> int
    {
        int handle;
        %{
            GtkWidget *image;

            php_gtk_set_last_error(NULL);
            image = gtk_image_new_from_file(Z_STRVAL(filename));
            if (image == NULL) {
                php_gtk_set_last_error("gtk_image_new_from_file returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) image;
            }
        }%
        return handle;
    }

    public static function gtkImageSetFromFile(int image, string filename) -> void
    {
        %{
            GtkImage *img = GTK_IMAGE((void *)(uintptr_t) image);
            if (img != NULL) {
                gtk_image_set_from_file(img, Z_STRVAL(filename));
            }
        }%
    }

    public static function gtkImageSetFromIconName(int image, string iconName) -> void
    {
        %{
            GtkImage *img = GTK_IMAGE((void *)(uintptr_t) image);
            if (img != NULL) {
                gtk_image_set_from_icon_name(img, Z_STRVAL(iconName));
            }
        }%
    }

    public static function gtkImageClear(int image) -> void
    {
        %{
            GtkImage *img = GTK_IMAGE((void *)(uintptr_t) image);
            if (img != NULL) {
                gtk_image_clear(img);
            }
        }%
    }

    public static function gtkImageSetPixelSize(int image, int size) -> void
    {
        %{
            GtkImage *img = GTK_IMAGE((void *)(uintptr_t) image);
            if (img != NULL) {
                gtk_image_set_pixel_size(img, (int) size);
            }
        }%
    }
}
