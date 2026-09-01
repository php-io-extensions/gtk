
extern zend_class_entry *gtk_gtk_gtkmediastream_gtkmediastream_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkMediaStream_GtkMediaStream);

PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, getDuration);
PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, getEnded);
PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, getLoop);
PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, getMuted);
PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, getPlaying);
PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, getTimestamp);
PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, getVolume);
PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, hasAudio);
PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, hasVideo);
PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, isPrepared);
PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, isSeekable);
PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, isSeeking);
PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, pause);
PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, play);
PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, realize);
PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, seek);
PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, seekFailed);
PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, seekSuccess);
PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, setLoop);
PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, setMuted);
PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, setPlaying);
PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, setVolume);
PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, streamEnded);
PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, streamPrepared);
PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, streamUnprepared);
PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, unrealize);
PHP_METHOD(Gtk_Gtk_GtkMediaStream_GtkMediaStream, update);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediastream_gtkmediastream_getduration, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediastream_gtkmediastream_getended, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediastream_gtkmediastream_getloop, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediastream_gtkmediastream_getmuted, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediastream_gtkmediastream_getplaying, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediastream_gtkmediastream_gettimestamp, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediastream_gtkmediastream_getvolume, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediastream_gtkmediastream_hasaudio, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediastream_gtkmediastream_hasvideo, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediastream_gtkmediastream_isprepared, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediastream_gtkmediastream_isseekable, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediastream_gtkmediastream_isseeking, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediastream_gtkmediastream_pause, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediastream_gtkmediastream_play, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediastream_gtkmediastream_realize, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, surface, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediastream_gtkmediastream_seek, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, timestamp, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediastream_gtkmediastream_seekfailed, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediastream_gtkmediastream_seeksuccess, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediastream_gtkmediastream_setloop, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, loop_, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediastream_gtkmediastream_setmuted, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, muted, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediastream_gtkmediastream_setplaying, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, playing, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediastream_gtkmediastream_setvolume, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, volume, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediastream_gtkmediastream_streamended, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediastream_gtkmediastream_streamprepared, 0, 5, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, hasAudio, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, hasVideo, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, seekable, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, duration, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediastream_gtkmediastream_streamunprepared, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediastream_gtkmediastream_unrealize, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, surface, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkmediastream_gtkmediastream_update, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, timestamp, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkmediastream_gtkmediastream_method_entry) {
	PHP_ME(Gtk_Gtk_GtkMediaStream_GtkMediaStream, getDuration, arginfo_gtk_gtk_gtkmediastream_gtkmediastream_getduration, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaStream_GtkMediaStream, getEnded, arginfo_gtk_gtk_gtkmediastream_gtkmediastream_getended, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaStream_GtkMediaStream, getLoop, arginfo_gtk_gtk_gtkmediastream_gtkmediastream_getloop, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaStream_GtkMediaStream, getMuted, arginfo_gtk_gtk_gtkmediastream_gtkmediastream_getmuted, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaStream_GtkMediaStream, getPlaying, arginfo_gtk_gtk_gtkmediastream_gtkmediastream_getplaying, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaStream_GtkMediaStream, getTimestamp, arginfo_gtk_gtk_gtkmediastream_gtkmediastream_gettimestamp, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaStream_GtkMediaStream, getVolume, arginfo_gtk_gtk_gtkmediastream_gtkmediastream_getvolume, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaStream_GtkMediaStream, hasAudio, arginfo_gtk_gtk_gtkmediastream_gtkmediastream_hasaudio, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaStream_GtkMediaStream, hasVideo, arginfo_gtk_gtk_gtkmediastream_gtkmediastream_hasvideo, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaStream_GtkMediaStream, isPrepared, arginfo_gtk_gtk_gtkmediastream_gtkmediastream_isprepared, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaStream_GtkMediaStream, isSeekable, arginfo_gtk_gtk_gtkmediastream_gtkmediastream_isseekable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaStream_GtkMediaStream, isSeeking, arginfo_gtk_gtk_gtkmediastream_gtkmediastream_isseeking, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaStream_GtkMediaStream, pause, arginfo_gtk_gtk_gtkmediastream_gtkmediastream_pause, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaStream_GtkMediaStream, play, arginfo_gtk_gtk_gtkmediastream_gtkmediastream_play, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaStream_GtkMediaStream, realize, arginfo_gtk_gtk_gtkmediastream_gtkmediastream_realize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaStream_GtkMediaStream, seek, arginfo_gtk_gtk_gtkmediastream_gtkmediastream_seek, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaStream_GtkMediaStream, seekFailed, arginfo_gtk_gtk_gtkmediastream_gtkmediastream_seekfailed, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaStream_GtkMediaStream, seekSuccess, arginfo_gtk_gtk_gtkmediastream_gtkmediastream_seeksuccess, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaStream_GtkMediaStream, setLoop, arginfo_gtk_gtk_gtkmediastream_gtkmediastream_setloop, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaStream_GtkMediaStream, setMuted, arginfo_gtk_gtk_gtkmediastream_gtkmediastream_setmuted, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaStream_GtkMediaStream, setPlaying, arginfo_gtk_gtk_gtkmediastream_gtkmediastream_setplaying, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaStream_GtkMediaStream, setVolume, arginfo_gtk_gtk_gtkmediastream_gtkmediastream_setvolume, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaStream_GtkMediaStream, streamEnded, arginfo_gtk_gtk_gtkmediastream_gtkmediastream_streamended, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaStream_GtkMediaStream, streamPrepared, arginfo_gtk_gtk_gtkmediastream_gtkmediastream_streamprepared, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaStream_GtkMediaStream, streamUnprepared, arginfo_gtk_gtk_gtkmediastream_gtkmediastream_streamunprepared, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaStream_GtkMediaStream, unrealize, arginfo_gtk_gtk_gtkmediastream_gtkmediastream_unrealize, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkMediaStream_GtkMediaStream, update, arginfo_gtk_gtk_gtkmediastream_gtkmediastream_update, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
