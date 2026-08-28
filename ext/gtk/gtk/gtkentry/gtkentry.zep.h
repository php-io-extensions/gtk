
extern zend_class_entry *gtk_gtk_gtkentry_gtkentry_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkEntry_GtkEntry);

PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, new_);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, newWithBuffer);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getActivatesDefault);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getAlignment);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getBuffer);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getCurrentIconDragSource);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getExtraMenu);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getHasFrame);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getIconActivatable);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getIconArea);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getIconAtPos);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getIconGicon);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getIconName);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getIconPaintable);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getIconSensitive);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getIconStorageType);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getIconTooltipMarkup);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getIconTooltipText);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getInputHints);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getInputPurpose);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getInvisibleChar);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getMaxLength);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getOverwriteMode);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getPlaceholderText);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getProgressFraction);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getProgressPulseStep);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getTextLength);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, getVisibility);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, grabFocusWithoutSelecting);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, progressPulse);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, resetImContext);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setActivatesDefault);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setAlignment);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setBuffer);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setExtraMenu);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setHasFrame);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setIconActivatable);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setIconFromGicon);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setIconFromIconName);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setIconFromPaintable);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setIconSensitive);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setIconTooltipMarkup);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setIconTooltipText);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setInputHints);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setInputPurpose);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setInvisibleChar);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setMaxLength);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setOverwriteMode);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setPlaceholderText);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setProgressFraction);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setProgressPulseStep);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, setVisibility);
PHP_METHOD(Gtk_Gtk_GtkEntry_GtkEntry, unsetInvisibleChar);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_newwithbuffer, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, buffer, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_getactivatesdefault, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_getalignment, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_getbuffer, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_getcurrenticondragsource, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_getextramenu, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_gethasframe, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_geticonactivatable, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, iconPos, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_geticonarea, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, iconPos, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_geticonatpos, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_geticongicon, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, iconPos, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_geticonname, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, iconPos, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_geticonpaintable, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, iconPos, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_geticonsensitive, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, iconPos, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_geticonstoragetype, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, iconPos, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_geticontooltipmarkup, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, iconPos, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_geticontooltiptext, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, iconPos, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_getinputhints, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_getinputpurpose, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_getinvisiblechar, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_getmaxlength, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_getoverwritemode, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_getplaceholdertext, 0, 0, 1)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_getprogressfraction, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_getprogresspulsestep, 0, 1, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_gettextlength, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_getvisibility, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_grabfocuswithoutselecting, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_progresspulse, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_resetimcontext, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_setactivatesdefault, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, setting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_setalignment, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, xalign, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_setbuffer, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, buffer, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_setextramenu, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, model, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_sethasframe, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, setting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_seticonactivatable, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, iconPos, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, activatable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_seticonfromgicon, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, iconPos, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, icon, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_seticonfromiconname, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, iconPos, IS_LONG, 0)
	ZEND_ARG_INFO(0, iconName)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_seticonfrompaintable, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, iconPos, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, paintable, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_seticonsensitive, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, iconPos, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, sensitive, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_seticontooltipmarkup, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, iconPos, IS_LONG, 0)
	ZEND_ARG_INFO(0, tooltip)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_seticontooltiptext, 0, 3, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, iconPos, IS_LONG, 0)
	ZEND_ARG_INFO(0, tooltip)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_setinputhints, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, hints, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_setinputpurpose, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, purpose, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_setinvisiblechar, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, ch, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_setmaxlength, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, max, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_setoverwritemode, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, overwrite, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_setplaceholdertext, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_INFO(0, text)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_setprogressfraction, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fraction, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_setprogresspulsestep, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fraction, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_setvisibility, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, visible, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkentry_gtkentry_unsetinvisiblechar, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkentry_gtkentry_method_entry) {
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, new_, arginfo_gtk_gtk_gtkentry_gtkentry_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, newWithBuffer, arginfo_gtk_gtk_gtkentry_gtkentry_newwithbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, getActivatesDefault, arginfo_gtk_gtk_gtkentry_gtkentry_getactivatesdefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, getAlignment, arginfo_gtk_gtk_gtkentry_gtkentry_getalignment, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, getBuffer, arginfo_gtk_gtk_gtkentry_gtkentry_getbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, getCurrentIconDragSource, arginfo_gtk_gtk_gtkentry_gtkentry_getcurrenticondragsource, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, getExtraMenu, arginfo_gtk_gtk_gtkentry_gtkentry_getextramenu, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, getHasFrame, arginfo_gtk_gtk_gtkentry_gtkentry_gethasframe, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, getIconActivatable, arginfo_gtk_gtk_gtkentry_gtkentry_geticonactivatable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, getIconArea, arginfo_gtk_gtk_gtkentry_gtkentry_geticonarea, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, getIconAtPos, arginfo_gtk_gtk_gtkentry_gtkentry_geticonatpos, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, getIconGicon, arginfo_gtk_gtk_gtkentry_gtkentry_geticongicon, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, getIconName, arginfo_gtk_gtk_gtkentry_gtkentry_geticonname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, getIconPaintable, arginfo_gtk_gtk_gtkentry_gtkentry_geticonpaintable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, getIconSensitive, arginfo_gtk_gtk_gtkentry_gtkentry_geticonsensitive, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, getIconStorageType, arginfo_gtk_gtk_gtkentry_gtkentry_geticonstoragetype, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, getIconTooltipMarkup, arginfo_gtk_gtk_gtkentry_gtkentry_geticontooltipmarkup, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, getIconTooltipText, arginfo_gtk_gtk_gtkentry_gtkentry_geticontooltiptext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, getInputHints, arginfo_gtk_gtk_gtkentry_gtkentry_getinputhints, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, getInputPurpose, arginfo_gtk_gtk_gtkentry_gtkentry_getinputpurpose, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, getInvisibleChar, arginfo_gtk_gtk_gtkentry_gtkentry_getinvisiblechar, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, getMaxLength, arginfo_gtk_gtk_gtkentry_gtkentry_getmaxlength, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, getOverwriteMode, arginfo_gtk_gtk_gtkentry_gtkentry_getoverwritemode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, getPlaceholderText, arginfo_gtk_gtk_gtkentry_gtkentry_getplaceholdertext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, getProgressFraction, arginfo_gtk_gtk_gtkentry_gtkentry_getprogressfraction, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, getProgressPulseStep, arginfo_gtk_gtk_gtkentry_gtkentry_getprogresspulsestep, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, getTextLength, arginfo_gtk_gtk_gtkentry_gtkentry_gettextlength, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, getVisibility, arginfo_gtk_gtk_gtkentry_gtkentry_getvisibility, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, grabFocusWithoutSelecting, arginfo_gtk_gtk_gtkentry_gtkentry_grabfocuswithoutselecting, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, progressPulse, arginfo_gtk_gtk_gtkentry_gtkentry_progresspulse, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, resetImContext, arginfo_gtk_gtk_gtkentry_gtkentry_resetimcontext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, setActivatesDefault, arginfo_gtk_gtk_gtkentry_gtkentry_setactivatesdefault, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, setAlignment, arginfo_gtk_gtk_gtkentry_gtkentry_setalignment, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, setBuffer, arginfo_gtk_gtk_gtkentry_gtkentry_setbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, setExtraMenu, arginfo_gtk_gtk_gtkentry_gtkentry_setextramenu, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, setHasFrame, arginfo_gtk_gtk_gtkentry_gtkentry_sethasframe, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, setIconActivatable, arginfo_gtk_gtk_gtkentry_gtkentry_seticonactivatable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, setIconFromGicon, arginfo_gtk_gtk_gtkentry_gtkentry_seticonfromgicon, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, setIconFromIconName, arginfo_gtk_gtk_gtkentry_gtkentry_seticonfromiconname, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, setIconFromPaintable, arginfo_gtk_gtk_gtkentry_gtkentry_seticonfrompaintable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, setIconSensitive, arginfo_gtk_gtk_gtkentry_gtkentry_seticonsensitive, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, setIconTooltipMarkup, arginfo_gtk_gtk_gtkentry_gtkentry_seticontooltipmarkup, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, setIconTooltipText, arginfo_gtk_gtk_gtkentry_gtkentry_seticontooltiptext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, setInputHints, arginfo_gtk_gtk_gtkentry_gtkentry_setinputhints, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, setInputPurpose, arginfo_gtk_gtk_gtkentry_gtkentry_setinputpurpose, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, setInvisibleChar, arginfo_gtk_gtk_gtkentry_gtkentry_setinvisiblechar, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, setMaxLength, arginfo_gtk_gtk_gtkentry_gtkentry_setmaxlength, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, setOverwriteMode, arginfo_gtk_gtk_gtkentry_gtkentry_setoverwritemode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, setPlaceholderText, arginfo_gtk_gtk_gtkentry_gtkentry_setplaceholdertext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, setProgressFraction, arginfo_gtk_gtk_gtkentry_gtkentry_setprogressfraction, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, setProgressPulseStep, arginfo_gtk_gtk_gtkentry_gtkentry_setprogresspulsestep, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, setVisibility, arginfo_gtk_gtk_gtkentry_gtkentry_setvisibility, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkEntry_GtkEntry, unsetInvisibleChar, arginfo_gtk_gtk_gtkentry_gtkentry_unsetinvisiblechar, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
