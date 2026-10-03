/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: e8b7f8c5ac5c73f2603f55df993ec5afcb4aa1ec */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkMediaStream_play, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkMediaStream_pause arginfo_class_GtkMediaStream_play

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkMediaStream_getPlaying, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkMediaStream_setPlaying, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, playing, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkMediaStream_getEnded arginfo_class_GtkMediaStream_getPlaying

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkMediaStream_getError, 0, 0, GError, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkMediaStream_seek, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, timestamp, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkMediaStream_isSeekable arginfo_class_GtkMediaStream_getPlaying

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkMediaStream_getTimestamp, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkMediaStream_getDuration arginfo_class_GtkMediaStream_getTimestamp

#define arginfo_class_GtkMediaStream_getMuted arginfo_class_GtkMediaStream_getPlaying

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkMediaStream_setMuted, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, muted, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkMediaStream_getLoop arginfo_class_GtkMediaStream_getPlaying

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkMediaStream_setLoop, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, loop, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkMediaStream_hasVideo arginfo_class_GtkMediaStream_getPlaying

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkMediaFile_newForFilename, 0, 1, GtkMediaFile, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkMediaFile_setFilename, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkMediaFile_clear arginfo_class_GtkMediaStream_play

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkVideo_new, 0, 0, GtkVideo, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkVideo_getMediaStream, 0, 0, GtkMediaStream, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkVideo_setMediaStream, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, stream, GtkMediaStream, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkVideo_getAutoplay arginfo_class_GtkMediaStream_getPlaying

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkVideo_setAutoplay, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, autoplay, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkVideo_setLoop arginfo_class_GtkMediaStream_setLoop

ZEND_METHOD(GtkMediaStream, play);
ZEND_METHOD(GtkMediaStream, pause);
ZEND_METHOD(GtkMediaStream, getPlaying);
ZEND_METHOD(GtkMediaStream, setPlaying);
ZEND_METHOD(GtkMediaStream, getEnded);
ZEND_METHOD(GtkMediaStream, getError);
ZEND_METHOD(GtkMediaStream, seek);
ZEND_METHOD(GtkMediaStream, isSeekable);
ZEND_METHOD(GtkMediaStream, getTimestamp);
ZEND_METHOD(GtkMediaStream, getDuration);
ZEND_METHOD(GtkMediaStream, getMuted);
ZEND_METHOD(GtkMediaStream, setMuted);
ZEND_METHOD(GtkMediaStream, getLoop);
ZEND_METHOD(GtkMediaStream, setLoop);
ZEND_METHOD(GtkMediaStream, hasVideo);
ZEND_METHOD(GtkMediaFile, newForFilename);
ZEND_METHOD(GtkMediaFile, setFilename);
ZEND_METHOD(GtkMediaFile, clear);
ZEND_METHOD(GtkVideo, new);
ZEND_METHOD(GtkVideo, getMediaStream);
ZEND_METHOD(GtkVideo, setMediaStream);
ZEND_METHOD(GtkVideo, getAutoplay);
ZEND_METHOD(GtkVideo, setAutoplay);
ZEND_METHOD(GtkVideo, setLoop);

static const zend_function_entry class_GtkMediaStream_methods[] = {
	ZEND_ME(GtkMediaStream, play, arginfo_class_GtkMediaStream_play, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkMediaStream, pause, arginfo_class_GtkMediaStream_pause, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkMediaStream, getPlaying, arginfo_class_GtkMediaStream_getPlaying, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkMediaStream, setPlaying, arginfo_class_GtkMediaStream_setPlaying, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkMediaStream, getEnded, arginfo_class_GtkMediaStream_getEnded, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkMediaStream, getError, arginfo_class_GtkMediaStream_getError, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkMediaStream, seek, arginfo_class_GtkMediaStream_seek, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkMediaStream, isSeekable, arginfo_class_GtkMediaStream_isSeekable, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkMediaStream, getTimestamp, arginfo_class_GtkMediaStream_getTimestamp, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkMediaStream, getDuration, arginfo_class_GtkMediaStream_getDuration, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkMediaStream, getMuted, arginfo_class_GtkMediaStream_getMuted, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkMediaStream, setMuted, arginfo_class_GtkMediaStream_setMuted, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkMediaStream, getLoop, arginfo_class_GtkMediaStream_getLoop, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkMediaStream, setLoop, arginfo_class_GtkMediaStream_setLoop, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkMediaStream, hasVideo, arginfo_class_GtkMediaStream_hasVideo, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkMediaFile_methods[] = {
	ZEND_ME(GtkMediaFile, newForFilename, arginfo_class_GtkMediaFile_newForFilename, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkMediaFile, setFilename, arginfo_class_GtkMediaFile_setFilename, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkMediaFile, clear, arginfo_class_GtkMediaFile_clear, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkVideo_methods[] = {
	ZEND_ME(GtkVideo, new, arginfo_class_GtkVideo_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkVideo, getMediaStream, arginfo_class_GtkVideo_getMediaStream, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkVideo, setMediaStream, arginfo_class_GtkVideo_setMediaStream, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkVideo, getAutoplay, arginfo_class_GtkVideo_getAutoplay, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkVideo, setAutoplay, arginfo_class_GtkVideo_setAutoplay, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkVideo, setLoop, arginfo_class_GtkVideo_setLoop, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_GtkMediaStream(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkMediaStream", class_GtkMediaStream_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkMediaFile(zend_class_entry *class_entry_GtkMediaStream)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkMediaFile", class_GtkMediaFile_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkMediaStream, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkVideo(zend_class_entry *class_entry_GtkWidget)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkVideo", class_GtkVideo_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkWidget, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
