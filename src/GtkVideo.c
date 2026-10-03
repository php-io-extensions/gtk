#include "runtime.h"
#include "../stubs/GtkVideo_arginfo.h"

void phpgtk_register_GtkVideo(void)
{
	phpgtk_ce_GtkMediaStream = register_class_GtkMediaStream(phpgtk_ce_GObject);
	phpgtk_object_setup(phpgtk_ce_GtkMediaStream);
	phpgtk_map_gtype("GtkMediaStream", phpgtk_ce_GtkMediaStream);

	phpgtk_ce_GtkMediaFile = register_class_GtkMediaFile(phpgtk_ce_GtkMediaStream);
	phpgtk_object_setup(phpgtk_ce_GtkMediaFile);
	phpgtk_map_gtype("GtkMediaFile", phpgtk_ce_GtkMediaFile);

	phpgtk_ce_GtkVideo = register_class_GtkVideo(phpgtk_ce_GtkWidget);
	phpgtk_object_setup(phpgtk_ce_GtkVideo);
	phpgtk_map_gtype("GtkVideo", phpgtk_ce_GtkVideo);
}

#define THIS(cast) cast(PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

#define PHPGTK_MEDIA_GET_BOOL(klass, name, cast, call) \
ZEND_METHOD(klass, name) { ZEND_PARSE_PARAMETERS_NONE(); RETURN_BOOL(call(THIS(cast))); }

#define PHPGTK_MEDIA_SET_BOOL(klass, name, cast, call) \
ZEND_METHOD(klass, name) \
{ \
	bool value; \
	ZEND_PARSE_PARAMETERS_START(1, 1) \
		Z_PARAM_BOOL(value) \
	ZEND_PARSE_PARAMETERS_END(); \
	call(THIS(cast), value); \
}

/* ---- media backend probe (declared in gtk.stub.php) --------------------- */

/*
 * gtk_media_file_new() instantiates the backend's GtkMediaFile subclass, loading
 * the media module on first use; without a module GTK falls back to GtkNoMediaFile.
 * gtk_init() registers the extension point the lookup needs; before it the lookup
 * fails an assertion and g_object_new() traps.
 */
ZEND_FUNCTION(gtk_media_backend_available)
{
	GtkMediaStream *probe;
	bool available;

	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();
	PHPGTK_REQUIRE_INITIALIZED();

	probe = gtk_media_file_new();
	available = strcmp(G_OBJECT_TYPE_NAME(probe), "GtkNoMediaFile") != 0;
	g_object_unref(probe);

	RETURN_BOOL(available);
}

/* ---- GtkMediaStream ---------------------------------------------------- */

ZEND_METHOD(GtkMediaStream, play)
{
	ZEND_PARSE_PARAMETERS_NONE();

	gtk_media_stream_play(THIS(GTK_MEDIA_STREAM));
}

ZEND_METHOD(GtkMediaStream, pause)
{
	ZEND_PARSE_PARAMETERS_NONE();

	gtk_media_stream_pause(THIS(GTK_MEDIA_STREAM));
}

PHPGTK_MEDIA_GET_BOOL(GtkMediaStream, getPlaying, GTK_MEDIA_STREAM, gtk_media_stream_get_playing)
PHPGTK_MEDIA_SET_BOOL(GtkMediaStream, setPlaying, GTK_MEDIA_STREAM, gtk_media_stream_set_playing)
PHPGTK_MEDIA_GET_BOOL(GtkMediaStream, getEnded, GTK_MEDIA_STREAM, gtk_media_stream_get_ended)

ZEND_METHOD(GtkMediaStream, getError)
{
	const GError *error;

	ZEND_PARSE_PARAMETERS_NONE();

	error = gtk_media_stream_get_error(THIS(GTK_MEDIA_STREAM));
	if (error == NULL) {
		RETURN_NULL();
	}

	phpgtk_gerror_object(return_value, error);
}

ZEND_METHOD(GtkMediaStream, seek)
{
	zend_long timestamp;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_LONG(timestamp)
	ZEND_PARSE_PARAMETERS_END();

	if (!phpgtk_long_in_range(timestamp, 0, ZEND_LONG_MAX, 1)) {
		RETURN_THROWS();
	}

	gtk_media_stream_seek(THIS(GTK_MEDIA_STREAM), (gint64) timestamp);
}

PHPGTK_MEDIA_GET_BOOL(GtkMediaStream, isSeekable, GTK_MEDIA_STREAM, gtk_media_stream_is_seekable)

ZEND_METHOD(GtkMediaStream, getTimestamp)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG((zend_long) gtk_media_stream_get_timestamp(THIS(GTK_MEDIA_STREAM)));
}

ZEND_METHOD(GtkMediaStream, getDuration)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG((zend_long) gtk_media_stream_get_duration(THIS(GTK_MEDIA_STREAM)));
}

PHPGTK_MEDIA_GET_BOOL(GtkMediaStream, getMuted, GTK_MEDIA_STREAM, gtk_media_stream_get_muted)
PHPGTK_MEDIA_SET_BOOL(GtkMediaStream, setMuted, GTK_MEDIA_STREAM, gtk_media_stream_set_muted)
PHPGTK_MEDIA_GET_BOOL(GtkMediaStream, getLoop, GTK_MEDIA_STREAM, gtk_media_stream_get_loop)
PHPGTK_MEDIA_SET_BOOL(GtkMediaStream, setLoop, GTK_MEDIA_STREAM, gtk_media_stream_set_loop)
PHPGTK_MEDIA_GET_BOOL(GtkMediaStream, hasVideo, GTK_MEDIA_STREAM, gtk_media_stream_has_video)

/* ---- GtkMediaFile ------------------------------------------------------ */

ZEND_METHOD(GtkMediaFile, newForFilename)
{
	zend_string *filename;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(filename)
	ZEND_PARSE_PARAMETERS_END();
	PHPGTK_REQUIRE_MAIN_THREAD();
	PHPGTK_REQUIRE_INITIALIZED();

	phpgtk_box_gobject_full(return_value, gtk_media_file_new_for_filename(ZSTR_VAL(filename)));
}

ZEND_METHOD(GtkMediaFile, setFilename)
{
	zend_string *filename = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR_OR_NULL(filename)
	ZEND_PARSE_PARAMETERS_END();

	gtk_media_file_set_filename(THIS(GTK_MEDIA_FILE), filename != NULL ? ZSTR_VAL(filename) : NULL);
}

ZEND_METHOD(GtkMediaFile, clear)
{
	ZEND_PARSE_PARAMETERS_NONE();

	gtk_media_file_clear(THIS(GTK_MEDIA_FILE));
}

/* ---- GtkVideo ---------------------------------------------------------- */

ZEND_METHOD(GtkVideo, new)
{
	ZEND_PARSE_PARAMETERS_NONE();
	PHPGTK_REQUIRE_MAIN_THREAD();
	PHPGTK_REQUIRE_INITIALIZED();

	phpgtk_box_gobject(return_value, gtk_video_new());
}

ZEND_METHOD(GtkVideo, getMediaStream)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_gobject(return_value, gtk_video_get_media_stream(THIS(GTK_VIDEO)));
}

ZEND_METHOD(GtkVideo, setMediaStream)
{
	zend_object *stream = NULL;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJ_OF_CLASS_OR_NULL(stream, phpgtk_ce_GtkMediaStream)
	ZEND_PARSE_PARAMETERS_END();

	gtk_video_set_media_stream(THIS(GTK_VIDEO), (GtkMediaStream *) PHPGTK_OPTIONAL_PTR(stream));
}

PHPGTK_MEDIA_GET_BOOL(GtkVideo, getAutoplay, GTK_VIDEO, gtk_video_get_autoplay)
PHPGTK_MEDIA_SET_BOOL(GtkVideo, setAutoplay, GTK_VIDEO, gtk_video_set_autoplay)
PHPGTK_MEDIA_SET_BOOL(GtkVideo, setLoop, GTK_VIDEO, gtk_video_set_loop)
