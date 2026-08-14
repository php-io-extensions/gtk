namespace Gtk\GTK\Picture;

%{
#include <gtk/gtk.h>
#include <stdint.h>

extern void php_gtk_set_last_error(const char *msg);
}%

class GtkPicture
{
    public static function gtkPictureNew() -> int
    {
        int handle;
        %{
            GtkWidget *picture;

            php_gtk_set_last_error(NULL);
            picture = gtk_picture_new();
            if (picture == NULL) {
                php_gtk_set_last_error("gtk_picture_new returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) picture;
            }
        }%
        return handle;
    }

    public static function gtkPictureNewForFilename(string filename) -> int
    {
        int handle;
        %{
            GtkWidget *picture;

            php_gtk_set_last_error(NULL);
            picture = gtk_picture_new_for_filename(Z_STRVAL(filename));
            if (picture == NULL) {
                php_gtk_set_last_error("gtk_picture_new_for_filename returned NULL");
                handle = 0;
            } else {
                handle = (zend_long)(uintptr_t) picture;
            }
        }%
        return handle;
    }

    public static function gtkPictureSetFilename(int picture, string filename) -> void
    {
        %{
            GtkPicture *pic = GTK_PICTURE((void *)(uintptr_t) picture);
            if (pic != NULL) {
                gtk_picture_set_filename(pic, Z_STRVAL(filename));
            }
        }%
    }

    public static function gtkPictureSetCanShrink(int picture, bool canShrink) -> void
    {
        %{
            GtkPicture *pic = GTK_PICTURE((void *)(uintptr_t) picture);
            if (pic != NULL) {
                gtk_picture_set_can_shrink(pic, canShrink ? TRUE : FALSE);
            }
        }%
    }
}
