/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: ec83db4e80437920981941c14748b4ca0f108dca */

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkLabel_new, 0, 1, GtkLabel, 0)
	ZEND_ARG_TYPE_INFO(0, str, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkLabel_getText, 0, 0, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkLabel_setText, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, str, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkLabel_getWrap, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkLabel_setWrap, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, wrap, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkLabel_setEllipsize, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, mode, PangoEllipsizeMode, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkLabel_getXalign, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkLabel_setXalign, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, xalign, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkLabel_setJustify, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, jtype, GtkJustification, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkLabel_setMarkup arginfo_class_GtkLabel_setText

#define arginfo_class_GtkLabel_getUseMarkup arginfo_class_GtkLabel_getWrap

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkLabel_setUseMarkup, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, setting, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkLabel_getCurrentUri, 0, 0, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkButton_newWithLabel, 0, 1, GtkButton, 0)
	ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkButton_getLabel arginfo_class_GtkLabel_getCurrentUri

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkButton_setLabel, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkButton_setChild, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, child, GtkWidget, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkButton_getChild, 0, 0, GtkWidget, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkButton_setHasFrame, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, hasFrame, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkButton_getHasFrame arginfo_class_GtkLabel_getWrap

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkMenuButton_new, 0, 0, GtkMenuButton, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkMenuButton_setMenuModel, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, menuModel, GMenuModel, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkMenuButton_getMenuModel, 0, 0, GMenuModel, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkMenuButton_setPopover, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, popover, GtkWidget, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkMenuButton_getPopover, 0, 0, GtkPopover, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkMenuButton_setChild arginfo_class_GtkButton_setChild

#define arginfo_class_GtkMenuButton_getChild arginfo_class_GtkButton_getChild

#define arginfo_class_GtkMenuButton_setHasFrame arginfo_class_GtkButton_setHasFrame

#define arginfo_class_GtkMenuButton_getHasFrame arginfo_class_GtkLabel_getWrap

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkMenuButton_popup, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkMenuButton_popdown arginfo_class_GtkMenuButton_popup

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkScrollbar_new, 0, 2, GtkScrollbar, 0)
	ZEND_ARG_OBJ_INFO(0, orientation, GtkOrientation, 0)
	ZEND_ARG_OBJ_INFO(0, adjustment, GtkAdjustment, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkScrollbar_getAdjustment, 0, 0, GtkAdjustment, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkLinkButton_new, 0, 1, GtkLinkButton, 0)
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkLinkButton_newWithLabel, 0, 1, GtkLinkButton, 0)
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO_WITH_DEFAULT_VALUE(0, label, IS_STRING, 1, "null")
ZEND_END_ARG_INFO()

#define arginfo_class_GtkLinkButton_getUri arginfo_class_GtkLabel_getText

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkLinkButton_setUri, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, uri, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkLinkButton_getVisited arginfo_class_GtkLabel_getWrap

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkLinkButton_setVisited, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, visited, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkImage_newFromIconName, 0, 1, GtkImage, 0)
	ZEND_ARG_TYPE_INFO(0, iconName, IS_STRING, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkImage_getIconName arginfo_class_GtkLabel_getCurrentUri

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkCheckButton_newWithLabel, 0, 1, GtkCheckButton, 0)
	ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkCheckButton_getActive arginfo_class_GtkLabel_getWrap

#define arginfo_class_GtkCheckButton_setActive arginfo_class_GtkLabel_setUseMarkup

#define arginfo_class_GtkCheckButton_getLabel arginfo_class_GtkLabel_getCurrentUri

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkCheckButton_setLabel, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkSwitch_new, 0, 0, GtkSwitch, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkSwitch_getActive arginfo_class_GtkLabel_getWrap

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkSwitch_setActive, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, isActive, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkToggleButton_newWithLabel, 0, 1, GtkToggleButton, 0)
	ZEND_ARG_TYPE_INFO(0, label, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkToggleButton_getActive arginfo_class_GtkLabel_getWrap

#define arginfo_class_GtkToggleButton_setActive arginfo_class_GtkSwitch_setActive

#define arginfo_class_GtkEntryBuffer_getText arginfo_class_GtkLabel_getText

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkEntryBuffer_setText, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, chars, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, nChars, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkEntry_new, 0, 0, GtkEntry, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkEntry_getBuffer, 0, 0, GtkEntryBuffer, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkEntry_getPlaceholderText arginfo_class_GtkLabel_getCurrentUri

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkEntry_setPlaceholderText, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkEntry_getVisibility arginfo_class_GtkLabel_getWrap

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkEntry_setVisibility, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, visible, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkTextBuffer_setText, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, len, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkTextBuffer_beginUserAction arginfo_class_GtkMenuButton_popup

#define arginfo_class_GtkTextBuffer_endUserAction arginfo_class_GtkMenuButton_popup

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkTextBuffer_getText, 0, 3, IS_STRING, 1)
	ZEND_ARG_OBJ_INFO(0, start, GtkTextIter, 0)
	ZEND_ARG_OBJ_INFO(0, end, GtkTextIter, 0)
	ZEND_ARG_TYPE_INFO(0, includeHiddenChars, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkTextBuffer_getTagTable, 0, 0, GtkTextTagTable, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkTextBuffer_getIterAtLine, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(1, iter, GtkTextIter, 1)
	ZEND_ARG_TYPE_INFO(0, lineNumber, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkTextBuffer_getIterAtLineOffset, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(1, iter, GtkTextIter, 1)
	ZEND_ARG_TYPE_INFO(0, lineNumber, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, charOffset, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkTextBuffer_getIterAtOffset, 0, 1, GtkTextIter, 0)
	ZEND_ARG_TYPE_INFO(0, charOffset, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkTextBuffer_getStartIter, 0, 0, GtkTextIter, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkTextBuffer_getEndIter arginfo_class_GtkTextBuffer_getStartIter

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkTextBuffer_applyTag, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, tag, GtkTextTag, 0)
	ZEND_ARG_OBJ_INFO(0, start, GtkTextIter, 0)
	ZEND_ARG_OBJ_INFO(0, end, GtkTextIter, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkTextBuffer_removeTag arginfo_class_GtkTextBuffer_applyTag

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkTextBuffer_getSelectionBounds, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(1, start, GtkTextIter, 1)
	ZEND_ARG_OBJ_INFO(1, end, GtkTextIter, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkTextBuffer_selectRange, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, ins, GtkTextIter, 0)
	ZEND_ARG_OBJ_INFO(0, bound, GtkTextIter, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkTextBuffer_getInsert, 0, 0, GtkTextMark, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkTextBuffer_getIterAtMark, 0, 1, GtkTextIter, 0)
	ZEND_ARG_OBJ_INFO(0, mark, GtkTextMark, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkTextBuffer_getLineCount, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkTextView_new, 0, 0, GtkTextView, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkTextView_getBuffer, 0, 0, GtkTextBuffer, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkTextView_getEditable arginfo_class_GtkLabel_getWrap

#define arginfo_class_GtkTextView_setEditable arginfo_class_GtkLabel_setUseMarkup

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkTextView_setWrapMode, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, wrapMode, GtkWrapMode, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkTextView_getMonospace arginfo_class_GtkLabel_getWrap

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkTextView_setMonospace, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, monospace, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkTextView_getCursorVisible arginfo_class_GtkLabel_getWrap

#define arginfo_class_GtkTextView_setCursorVisible arginfo_class_GtkLabel_setUseMarkup

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkTextView_getLineYrange, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, iter, GtkTextIter, 0)
	ZEND_ARG_TYPE_INFO(1, y, IS_LONG, 1)
	ZEND_ARG_TYPE_INFO(1, height, IS_LONG, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkScale_newWithRange, 0, 4, GtkScale, 1)
	ZEND_ARG_OBJ_INFO(0, orientation, GtkOrientation, 0)
	ZEND_ARG_TYPE_INFO(0, min, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, max, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, step, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkScale_getValue arginfo_class_GtkLabel_getXalign

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkScale_setValue, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkScale_setRange, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, min, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, max, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkScale_setIncrements, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, step, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, page, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkScale_setDrawValue, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, drawValue, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkScale_getDrawValue arginfo_class_GtkLabel_getWrap

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkStringList_new, 0, 1, GtkStringList, 0)
	ZEND_ARG_TYPE_INFO(0, strings, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkStringList_append, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, string, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkStringList_remove, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkStringList_splice, 0, 3, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, nRemovals, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, additions, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkStringList_getString, 0, 1, IS_STRING, 1)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkStringObject_getString arginfo_class_GtkLabel_getText

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkDropDown_newFromStrings, 0, 1, GtkDropDown, 0)
	ZEND_ARG_TYPE_INFO(0, strings, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkDropDown_getSelected arginfo_class_GtkTextBuffer_getLineCount

#define arginfo_class_GtkDropDown_setSelected arginfo_class_GtkStringList_remove

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkDropDown_getSelectedItem, 0, 0, GObject, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkDropDown_setModel, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, model, GListModel, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkCalendar_new, 0, 0, GtkCalendar, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkCalendar_getDate, 0, 0, GDateTime, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkCalendar_selectDay, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, date, GDateTime, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkProgressBar_new, 0, 0, GtkProgressBar, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkProgressBar_getFraction arginfo_class_GtkLabel_getXalign

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkProgressBar_setFraction, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, fraction, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkProgressBar_pulse arginfo_class_GtkMenuButton_popup

#define arginfo_class_GtkProgressBar_setPulseStep arginfo_class_GtkProgressBar_setFraction

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkSpinner_new, 0, 0, GtkSpinner, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkSpinner_getSpinning arginfo_class_GtkLabel_getWrap

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkSpinner_setSpinning, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, spinning, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkPicture_new, 0, 0, GtkPicture, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkPicture_newForFilename, 0, 1, GtkPicture, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkPicture_setFilename, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, filename, IS_STRING, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkPicture_getContentFit, 0, 0, GtkContentFit, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkPicture_setContentFit, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, contentFit, GtkContentFit, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkPicture_getPaintable, 0, 0, GdkPaintable, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkPicture_setPaintable, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, paintable, GdkPaintable, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkPicture_getCanShrink arginfo_class_GtkLabel_getWrap

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkPicture_setCanShrink, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, canShrink, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkSeparator_new, 0, 1, GtkSeparator, 0)
	ZEND_ARG_OBJ_INFO(0, orientation, GtkOrientation, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkScrolledWindow_new, 0, 0, GtkScrolledWindow, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkScrolledWindow_getChild arginfo_class_GtkButton_getChild

#define arginfo_class_GtkScrolledWindow_setChild arginfo_class_GtkButton_setChild

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkScrolledWindow_setPolicy, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, hscrollbarPolicy, GtkPolicyType, 0)
	ZEND_ARG_OBJ_INFO(0, vscrollbarPolicy, GtkPolicyType, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkScrolledWindow_getHadjustment arginfo_class_GtkScrollbar_getAdjustment

#define arginfo_class_GtkScrolledWindow_getVadjustment arginfo_class_GtkScrollbar_getAdjustment

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkPaned_new, 0, 1, GtkPaned, 0)
	ZEND_ARG_OBJ_INFO(0, orientation, GtkOrientation, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkPaned_getStartChild arginfo_class_GtkButton_getChild

#define arginfo_class_GtkPaned_setStartChild arginfo_class_GtkButton_setChild

#define arginfo_class_GtkPaned_getEndChild arginfo_class_GtkButton_getChild

#define arginfo_class_GtkPaned_setEndChild arginfo_class_GtkButton_setChild

#define arginfo_class_GtkPaned_getPosition arginfo_class_GtkTextBuffer_getLineCount

#define arginfo_class_GtkPaned_setPosition arginfo_class_GtkStringList_remove

#define arginfo_class_GtkPaned_getResizeStartChild arginfo_class_GtkLabel_getWrap

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkPaned_setResizeStartChild, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, resize, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkPaned_getResizeEndChild arginfo_class_GtkLabel_getWrap

#define arginfo_class_GtkPaned_setResizeEndChild arginfo_class_GtkPaned_setResizeStartChild

#define arginfo_class_GtkPaned_getShrinkStartChild arginfo_class_GtkLabel_getWrap

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkPaned_setShrinkStartChild, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, shrink, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkPaned_getShrinkEndChild arginfo_class_GtkLabel_getWrap

#define arginfo_class_GtkPaned_setShrinkEndChild arginfo_class_GtkPaned_setShrinkStartChild

#define arginfo_class_GtkPaned_getWideHandle arginfo_class_GtkLabel_getWrap

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkPaned_setWideHandle, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, wide, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkNotebook_new, 0, 0, GtkNotebook, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkNotebook_appendPage, 0, 2, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, child, GtkWidget, 0)
	ZEND_ARG_OBJ_INFO(0, tabLabel, GtkWidget, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkNotebook_insertPage, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, child, GtkWidget, 0)
	ZEND_ARG_OBJ_INFO(0, tabLabel, GtkWidget, 1)
	ZEND_ARG_TYPE_INFO(0, position, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkNotebook_removePage, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, pageNum, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkNotebook_pageNum, 0, 1, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, child, GtkWidget, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkNotebook_getNPages arginfo_class_GtkTextBuffer_getLineCount

#define arginfo_class_GtkNotebook_getCurrentPage arginfo_class_GtkTextBuffer_getLineCount

#define arginfo_class_GtkNotebook_setCurrentPage arginfo_class_GtkNotebook_removePage

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkNotebook_getNthPage, 0, 1, GtkWidget, 1)
	ZEND_ARG_TYPE_INFO(0, pageNum, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkNotebook_setTabLabelText, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, child, GtkWidget, 0)
	ZEND_ARG_TYPE_INFO(0, tabText, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkNotebook_getTabLabelText, 0, 1, IS_STRING, 1)
	ZEND_ARG_OBJ_INFO(0, child, GtkWidget, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkNotebook_getShowTabs arginfo_class_GtkLabel_getWrap

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkNotebook_setShowTabs, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, showTabs, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkNotebook_getScrollable arginfo_class_GtkLabel_getWrap

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkNotebook_setScrollable, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, scrollable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_METHOD(GtkLabel, new);
ZEND_METHOD(GtkLabel, getText);
ZEND_METHOD(GtkLabel, setText);
ZEND_METHOD(GtkLabel, getWrap);
ZEND_METHOD(GtkLabel, setWrap);
ZEND_METHOD(GtkLabel, setEllipsize);
ZEND_METHOD(GtkLabel, getXalign);
ZEND_METHOD(GtkLabel, setXalign);
ZEND_METHOD(GtkLabel, setJustify);
ZEND_METHOD(GtkLabel, setMarkup);
ZEND_METHOD(GtkLabel, getUseMarkup);
ZEND_METHOD(GtkLabel, setUseMarkup);
ZEND_METHOD(GtkLabel, getCurrentUri);
ZEND_METHOD(GtkButton, newWithLabel);
ZEND_METHOD(GtkButton, getLabel);
ZEND_METHOD(GtkButton, setLabel);
ZEND_METHOD(GtkButton, setChild);
ZEND_METHOD(GtkButton, getChild);
ZEND_METHOD(GtkButton, setHasFrame);
ZEND_METHOD(GtkButton, getHasFrame);
ZEND_METHOD(GtkMenuButton, new);
ZEND_METHOD(GtkMenuButton, setMenuModel);
ZEND_METHOD(GtkMenuButton, getMenuModel);
ZEND_METHOD(GtkMenuButton, setPopover);
ZEND_METHOD(GtkMenuButton, getPopover);
ZEND_METHOD(GtkMenuButton, setChild);
ZEND_METHOD(GtkMenuButton, getChild);
ZEND_METHOD(GtkMenuButton, setHasFrame);
ZEND_METHOD(GtkMenuButton, getHasFrame);
ZEND_METHOD(GtkMenuButton, popup);
ZEND_METHOD(GtkMenuButton, popdown);
ZEND_METHOD(GtkScrollbar, new);
ZEND_METHOD(GtkScrollbar, getAdjustment);
ZEND_METHOD(GtkLinkButton, new);
ZEND_METHOD(GtkLinkButton, newWithLabel);
ZEND_METHOD(GtkLinkButton, getUri);
ZEND_METHOD(GtkLinkButton, setUri);
ZEND_METHOD(GtkLinkButton, getVisited);
ZEND_METHOD(GtkLinkButton, setVisited);
ZEND_METHOD(GtkImage, newFromIconName);
ZEND_METHOD(GtkImage, getIconName);
ZEND_METHOD(GtkCheckButton, newWithLabel);
ZEND_METHOD(GtkCheckButton, getActive);
ZEND_METHOD(GtkCheckButton, setActive);
ZEND_METHOD(GtkCheckButton, getLabel);
ZEND_METHOD(GtkCheckButton, setLabel);
ZEND_METHOD(GtkSwitch, new);
ZEND_METHOD(GtkSwitch, getActive);
ZEND_METHOD(GtkSwitch, setActive);
ZEND_METHOD(GtkToggleButton, newWithLabel);
ZEND_METHOD(GtkToggleButton, getActive);
ZEND_METHOD(GtkToggleButton, setActive);
ZEND_METHOD(GtkEntryBuffer, getText);
ZEND_METHOD(GtkEntryBuffer, setText);
ZEND_METHOD(GtkEntry, new);
ZEND_METHOD(GtkEntry, getBuffer);
ZEND_METHOD(GtkEntry, getPlaceholderText);
ZEND_METHOD(GtkEntry, setPlaceholderText);
ZEND_METHOD(GtkEntry, getVisibility);
ZEND_METHOD(GtkEntry, setVisibility);
ZEND_METHOD(GtkTextBuffer, setText);
ZEND_METHOD(GtkTextBuffer, beginUserAction);
ZEND_METHOD(GtkTextBuffer, endUserAction);
ZEND_METHOD(GtkTextBuffer, getText);
ZEND_METHOD(GtkTextBuffer, getTagTable);
ZEND_METHOD(GtkTextBuffer, getIterAtLine);
ZEND_METHOD(GtkTextBuffer, getIterAtLineOffset);
ZEND_METHOD(GtkTextBuffer, getIterAtOffset);
ZEND_METHOD(GtkTextBuffer, getStartIter);
ZEND_METHOD(GtkTextBuffer, getEndIter);
ZEND_METHOD(GtkTextBuffer, applyTag);
ZEND_METHOD(GtkTextBuffer, removeTag);
ZEND_METHOD(GtkTextBuffer, getSelectionBounds);
ZEND_METHOD(GtkTextBuffer, selectRange);
ZEND_METHOD(GtkTextBuffer, getInsert);
ZEND_METHOD(GtkTextBuffer, getIterAtMark);
ZEND_METHOD(GtkTextBuffer, getLineCount);
ZEND_METHOD(GtkTextView, new);
ZEND_METHOD(GtkTextView, getBuffer);
ZEND_METHOD(GtkTextView, getEditable);
ZEND_METHOD(GtkTextView, setEditable);
ZEND_METHOD(GtkTextView, setWrapMode);
ZEND_METHOD(GtkTextView, getMonospace);
ZEND_METHOD(GtkTextView, setMonospace);
ZEND_METHOD(GtkTextView, getCursorVisible);
ZEND_METHOD(GtkTextView, setCursorVisible);
ZEND_METHOD(GtkTextView, getLineYrange);
ZEND_METHOD(GtkScale, newWithRange);
ZEND_METHOD(GtkScale, getValue);
ZEND_METHOD(GtkScale, setValue);
ZEND_METHOD(GtkScale, setRange);
ZEND_METHOD(GtkScale, setIncrements);
ZEND_METHOD(GtkScale, setDrawValue);
ZEND_METHOD(GtkScale, getDrawValue);
ZEND_METHOD(GtkStringList, new);
ZEND_METHOD(GtkStringList, append);
ZEND_METHOD(GtkStringList, remove);
ZEND_METHOD(GtkStringList, splice);
ZEND_METHOD(GtkStringList, getString);
ZEND_METHOD(GtkStringObject, getString);
ZEND_METHOD(GtkDropDown, newFromStrings);
ZEND_METHOD(GtkDropDown, getSelected);
ZEND_METHOD(GtkDropDown, setSelected);
ZEND_METHOD(GtkDropDown, getSelectedItem);
ZEND_METHOD(GtkDropDown, setModel);
ZEND_METHOD(GtkCalendar, new);
ZEND_METHOD(GtkCalendar, getDate);
ZEND_METHOD(GtkCalendar, selectDay);
ZEND_METHOD(GtkProgressBar, new);
ZEND_METHOD(GtkProgressBar, getFraction);
ZEND_METHOD(GtkProgressBar, setFraction);
ZEND_METHOD(GtkProgressBar, pulse);
ZEND_METHOD(GtkProgressBar, setPulseStep);
ZEND_METHOD(GtkSpinner, new);
ZEND_METHOD(GtkSpinner, getSpinning);
ZEND_METHOD(GtkSpinner, setSpinning);
ZEND_METHOD(GtkPicture, new);
ZEND_METHOD(GtkPicture, newForFilename);
ZEND_METHOD(GtkPicture, setFilename);
ZEND_METHOD(GtkPicture, getContentFit);
ZEND_METHOD(GtkPicture, setContentFit);
ZEND_METHOD(GtkPicture, getPaintable);
ZEND_METHOD(GtkPicture, setPaintable);
ZEND_METHOD(GtkPicture, getCanShrink);
ZEND_METHOD(GtkPicture, setCanShrink);
ZEND_METHOD(GtkSeparator, new);
ZEND_METHOD(GtkScrolledWindow, new);
ZEND_METHOD(GtkScrolledWindow, getChild);
ZEND_METHOD(GtkScrolledWindow, setChild);
ZEND_METHOD(GtkScrolledWindow, setPolicy);
ZEND_METHOD(GtkScrolledWindow, getHadjustment);
ZEND_METHOD(GtkScrolledWindow, getVadjustment);
ZEND_METHOD(GtkPaned, new);
ZEND_METHOD(GtkPaned, getStartChild);
ZEND_METHOD(GtkPaned, setStartChild);
ZEND_METHOD(GtkPaned, getEndChild);
ZEND_METHOD(GtkPaned, setEndChild);
ZEND_METHOD(GtkPaned, getPosition);
ZEND_METHOD(GtkPaned, setPosition);
ZEND_METHOD(GtkPaned, getResizeStartChild);
ZEND_METHOD(GtkPaned, setResizeStartChild);
ZEND_METHOD(GtkPaned, getResizeEndChild);
ZEND_METHOD(GtkPaned, setResizeEndChild);
ZEND_METHOD(GtkPaned, getShrinkStartChild);
ZEND_METHOD(GtkPaned, setShrinkStartChild);
ZEND_METHOD(GtkPaned, getShrinkEndChild);
ZEND_METHOD(GtkPaned, setShrinkEndChild);
ZEND_METHOD(GtkPaned, getWideHandle);
ZEND_METHOD(GtkPaned, setWideHandle);
ZEND_METHOD(GtkNotebook, new);
ZEND_METHOD(GtkNotebook, appendPage);
ZEND_METHOD(GtkNotebook, insertPage);
ZEND_METHOD(GtkNotebook, removePage);
ZEND_METHOD(GtkNotebook, pageNum);
ZEND_METHOD(GtkNotebook, getNPages);
ZEND_METHOD(GtkNotebook, getCurrentPage);
ZEND_METHOD(GtkNotebook, setCurrentPage);
ZEND_METHOD(GtkNotebook, getNthPage);
ZEND_METHOD(GtkNotebook, setTabLabelText);
ZEND_METHOD(GtkNotebook, getTabLabelText);
ZEND_METHOD(GtkNotebook, getShowTabs);
ZEND_METHOD(GtkNotebook, setShowTabs);
ZEND_METHOD(GtkNotebook, getScrollable);
ZEND_METHOD(GtkNotebook, setScrollable);

static const zend_function_entry class_GtkLabel_methods[] = {
	ZEND_ME(GtkLabel, new, arginfo_class_GtkLabel_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkLabel, getText, arginfo_class_GtkLabel_getText, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkLabel, setText, arginfo_class_GtkLabel_setText, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkLabel, getWrap, arginfo_class_GtkLabel_getWrap, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkLabel, setWrap, arginfo_class_GtkLabel_setWrap, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkLabel, setEllipsize, arginfo_class_GtkLabel_setEllipsize, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkLabel, getXalign, arginfo_class_GtkLabel_getXalign, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkLabel, setXalign, arginfo_class_GtkLabel_setXalign, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkLabel, setJustify, arginfo_class_GtkLabel_setJustify, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkLabel, setMarkup, arginfo_class_GtkLabel_setMarkup, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkLabel, getUseMarkup, arginfo_class_GtkLabel_getUseMarkup, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkLabel, setUseMarkup, arginfo_class_GtkLabel_setUseMarkup, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkLabel, getCurrentUri, arginfo_class_GtkLabel_getCurrentUri, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkButton_methods[] = {
	ZEND_ME(GtkButton, newWithLabel, arginfo_class_GtkButton_newWithLabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkButton, getLabel, arginfo_class_GtkButton_getLabel, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkButton, setLabel, arginfo_class_GtkButton_setLabel, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkButton, setChild, arginfo_class_GtkButton_setChild, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkButton, getChild, arginfo_class_GtkButton_getChild, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkButton, setHasFrame, arginfo_class_GtkButton_setHasFrame, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkButton, getHasFrame, arginfo_class_GtkButton_getHasFrame, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkMenuButton_methods[] = {
	ZEND_ME(GtkMenuButton, new, arginfo_class_GtkMenuButton_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkMenuButton, setMenuModel, arginfo_class_GtkMenuButton_setMenuModel, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkMenuButton, getMenuModel, arginfo_class_GtkMenuButton_getMenuModel, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkMenuButton, setPopover, arginfo_class_GtkMenuButton_setPopover, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkMenuButton, getPopover, arginfo_class_GtkMenuButton_getPopover, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkMenuButton, setChild, arginfo_class_GtkMenuButton_setChild, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkMenuButton, getChild, arginfo_class_GtkMenuButton_getChild, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkMenuButton, setHasFrame, arginfo_class_GtkMenuButton_setHasFrame, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkMenuButton, getHasFrame, arginfo_class_GtkMenuButton_getHasFrame, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkMenuButton, popup, arginfo_class_GtkMenuButton_popup, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkMenuButton, popdown, arginfo_class_GtkMenuButton_popdown, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkScrollbar_methods[] = {
	ZEND_ME(GtkScrollbar, new, arginfo_class_GtkScrollbar_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkScrollbar, getAdjustment, arginfo_class_GtkScrollbar_getAdjustment, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkLinkButton_methods[] = {
	ZEND_ME(GtkLinkButton, new, arginfo_class_GtkLinkButton_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkLinkButton, newWithLabel, arginfo_class_GtkLinkButton_newWithLabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkLinkButton, getUri, arginfo_class_GtkLinkButton_getUri, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkLinkButton, setUri, arginfo_class_GtkLinkButton_setUri, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkLinkButton, getVisited, arginfo_class_GtkLinkButton_getVisited, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkLinkButton, setVisited, arginfo_class_GtkLinkButton_setVisited, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkImage_methods[] = {
	ZEND_ME(GtkImage, newFromIconName, arginfo_class_GtkImage_newFromIconName, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkImage, getIconName, arginfo_class_GtkImage_getIconName, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkCheckButton_methods[] = {
	ZEND_ME(GtkCheckButton, newWithLabel, arginfo_class_GtkCheckButton_newWithLabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkCheckButton, getActive, arginfo_class_GtkCheckButton_getActive, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkCheckButton, setActive, arginfo_class_GtkCheckButton_setActive, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkCheckButton, getLabel, arginfo_class_GtkCheckButton_getLabel, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkCheckButton, setLabel, arginfo_class_GtkCheckButton_setLabel, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkSwitch_methods[] = {
	ZEND_ME(GtkSwitch, new, arginfo_class_GtkSwitch_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkSwitch, getActive, arginfo_class_GtkSwitch_getActive, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkSwitch, setActive, arginfo_class_GtkSwitch_setActive, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkToggleButton_methods[] = {
	ZEND_ME(GtkToggleButton, newWithLabel, arginfo_class_GtkToggleButton_newWithLabel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkToggleButton, getActive, arginfo_class_GtkToggleButton_getActive, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkToggleButton, setActive, arginfo_class_GtkToggleButton_setActive, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkEntryBuffer_methods[] = {
	ZEND_ME(GtkEntryBuffer, getText, arginfo_class_GtkEntryBuffer_getText, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkEntryBuffer, setText, arginfo_class_GtkEntryBuffer_setText, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkEntry_methods[] = {
	ZEND_ME(GtkEntry, new, arginfo_class_GtkEntry_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkEntry, getBuffer, arginfo_class_GtkEntry_getBuffer, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkEntry, getPlaceholderText, arginfo_class_GtkEntry_getPlaceholderText, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkEntry, setPlaceholderText, arginfo_class_GtkEntry_setPlaceholderText, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkEntry, getVisibility, arginfo_class_GtkEntry_getVisibility, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkEntry, setVisibility, arginfo_class_GtkEntry_setVisibility, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkTextBuffer_methods[] = {
	ZEND_ME(GtkTextBuffer, setText, arginfo_class_GtkTextBuffer_setText, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTextBuffer, beginUserAction, arginfo_class_GtkTextBuffer_beginUserAction, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTextBuffer, endUserAction, arginfo_class_GtkTextBuffer_endUserAction, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTextBuffer, getText, arginfo_class_GtkTextBuffer_getText, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTextBuffer, getTagTable, arginfo_class_GtkTextBuffer_getTagTable, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTextBuffer, getIterAtLine, arginfo_class_GtkTextBuffer_getIterAtLine, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTextBuffer, getIterAtLineOffset, arginfo_class_GtkTextBuffer_getIterAtLineOffset, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTextBuffer, getIterAtOffset, arginfo_class_GtkTextBuffer_getIterAtOffset, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTextBuffer, getStartIter, arginfo_class_GtkTextBuffer_getStartIter, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTextBuffer, getEndIter, arginfo_class_GtkTextBuffer_getEndIter, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTextBuffer, applyTag, arginfo_class_GtkTextBuffer_applyTag, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTextBuffer, removeTag, arginfo_class_GtkTextBuffer_removeTag, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTextBuffer, getSelectionBounds, arginfo_class_GtkTextBuffer_getSelectionBounds, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTextBuffer, selectRange, arginfo_class_GtkTextBuffer_selectRange, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTextBuffer, getInsert, arginfo_class_GtkTextBuffer_getInsert, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTextBuffer, getIterAtMark, arginfo_class_GtkTextBuffer_getIterAtMark, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTextBuffer, getLineCount, arginfo_class_GtkTextBuffer_getLineCount, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkTextView_methods[] = {
	ZEND_ME(GtkTextView, new, arginfo_class_GtkTextView_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkTextView, getBuffer, arginfo_class_GtkTextView_getBuffer, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTextView, getEditable, arginfo_class_GtkTextView_getEditable, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTextView, setEditable, arginfo_class_GtkTextView_setEditable, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTextView, setWrapMode, arginfo_class_GtkTextView_setWrapMode, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTextView, getMonospace, arginfo_class_GtkTextView_getMonospace, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTextView, setMonospace, arginfo_class_GtkTextView_setMonospace, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTextView, getCursorVisible, arginfo_class_GtkTextView_getCursorVisible, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTextView, setCursorVisible, arginfo_class_GtkTextView_setCursorVisible, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTextView, getLineYrange, arginfo_class_GtkTextView_getLineYrange, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkScale_methods[] = {
	ZEND_ME(GtkScale, newWithRange, arginfo_class_GtkScale_newWithRange, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkScale, getValue, arginfo_class_GtkScale_getValue, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkScale, setValue, arginfo_class_GtkScale_setValue, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkScale, setRange, arginfo_class_GtkScale_setRange, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkScale, setIncrements, arginfo_class_GtkScale_setIncrements, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkScale, setDrawValue, arginfo_class_GtkScale_setDrawValue, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkScale, getDrawValue, arginfo_class_GtkScale_getDrawValue, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkStringList_methods[] = {
	ZEND_ME(GtkStringList, new, arginfo_class_GtkStringList_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkStringList, append, arginfo_class_GtkStringList_append, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkStringList, remove, arginfo_class_GtkStringList_remove, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkStringList, splice, arginfo_class_GtkStringList_splice, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkStringList, getString, arginfo_class_GtkStringList_getString, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkStringObject_methods[] = {
	ZEND_ME(GtkStringObject, getString, arginfo_class_GtkStringObject_getString, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkDropDown_methods[] = {
	ZEND_ME(GtkDropDown, newFromStrings, arginfo_class_GtkDropDown_newFromStrings, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkDropDown, getSelected, arginfo_class_GtkDropDown_getSelected, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkDropDown, setSelected, arginfo_class_GtkDropDown_setSelected, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkDropDown, getSelectedItem, arginfo_class_GtkDropDown_getSelectedItem, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkDropDown, setModel, arginfo_class_GtkDropDown_setModel, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkCalendar_methods[] = {
	ZEND_ME(GtkCalendar, new, arginfo_class_GtkCalendar_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkCalendar, getDate, arginfo_class_GtkCalendar_getDate, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkCalendar, selectDay, arginfo_class_GtkCalendar_selectDay, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkProgressBar_methods[] = {
	ZEND_ME(GtkProgressBar, new, arginfo_class_GtkProgressBar_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkProgressBar, getFraction, arginfo_class_GtkProgressBar_getFraction, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkProgressBar, setFraction, arginfo_class_GtkProgressBar_setFraction, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkProgressBar, pulse, arginfo_class_GtkProgressBar_pulse, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkProgressBar, setPulseStep, arginfo_class_GtkProgressBar_setPulseStep, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkSpinner_methods[] = {
	ZEND_ME(GtkSpinner, new, arginfo_class_GtkSpinner_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkSpinner, getSpinning, arginfo_class_GtkSpinner_getSpinning, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkSpinner, setSpinning, arginfo_class_GtkSpinner_setSpinning, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkPicture_methods[] = {
	ZEND_ME(GtkPicture, new, arginfo_class_GtkPicture_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkPicture, newForFilename, arginfo_class_GtkPicture_newForFilename, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkPicture, setFilename, arginfo_class_GtkPicture_setFilename, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPicture, getContentFit, arginfo_class_GtkPicture_getContentFit, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPicture, setContentFit, arginfo_class_GtkPicture_setContentFit, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPicture, getPaintable, arginfo_class_GtkPicture_getPaintable, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPicture, setPaintable, arginfo_class_GtkPicture_setPaintable, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPicture, getCanShrink, arginfo_class_GtkPicture_getCanShrink, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPicture, setCanShrink, arginfo_class_GtkPicture_setCanShrink, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkSeparator_methods[] = {
	ZEND_ME(GtkSeparator, new, arginfo_class_GtkSeparator_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkScrolledWindow_methods[] = {
	ZEND_ME(GtkScrolledWindow, new, arginfo_class_GtkScrolledWindow_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkScrolledWindow, getChild, arginfo_class_GtkScrolledWindow_getChild, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkScrolledWindow, setChild, arginfo_class_GtkScrolledWindow_setChild, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkScrolledWindow, setPolicy, arginfo_class_GtkScrolledWindow_setPolicy, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkScrolledWindow, getHadjustment, arginfo_class_GtkScrolledWindow_getHadjustment, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkScrolledWindow, getVadjustment, arginfo_class_GtkScrolledWindow_getVadjustment, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkPaned_methods[] = {
	ZEND_ME(GtkPaned, new, arginfo_class_GtkPaned_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkPaned, getStartChild, arginfo_class_GtkPaned_getStartChild, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPaned, setStartChild, arginfo_class_GtkPaned_setStartChild, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPaned, getEndChild, arginfo_class_GtkPaned_getEndChild, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPaned, setEndChild, arginfo_class_GtkPaned_setEndChild, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPaned, getPosition, arginfo_class_GtkPaned_getPosition, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPaned, setPosition, arginfo_class_GtkPaned_setPosition, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPaned, getResizeStartChild, arginfo_class_GtkPaned_getResizeStartChild, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPaned, setResizeStartChild, arginfo_class_GtkPaned_setResizeStartChild, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPaned, getResizeEndChild, arginfo_class_GtkPaned_getResizeEndChild, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPaned, setResizeEndChild, arginfo_class_GtkPaned_setResizeEndChild, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPaned, getShrinkStartChild, arginfo_class_GtkPaned_getShrinkStartChild, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPaned, setShrinkStartChild, arginfo_class_GtkPaned_setShrinkStartChild, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPaned, getShrinkEndChild, arginfo_class_GtkPaned_getShrinkEndChild, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPaned, setShrinkEndChild, arginfo_class_GtkPaned_setShrinkEndChild, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPaned, getWideHandle, arginfo_class_GtkPaned_getWideHandle, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPaned, setWideHandle, arginfo_class_GtkPaned_setWideHandle, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkNotebook_methods[] = {
	ZEND_ME(GtkNotebook, new, arginfo_class_GtkNotebook_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkNotebook, appendPage, arginfo_class_GtkNotebook_appendPage, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkNotebook, insertPage, arginfo_class_GtkNotebook_insertPage, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkNotebook, removePage, arginfo_class_GtkNotebook_removePage, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkNotebook, pageNum, arginfo_class_GtkNotebook_pageNum, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkNotebook, getNPages, arginfo_class_GtkNotebook_getNPages, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkNotebook, getCurrentPage, arginfo_class_GtkNotebook_getCurrentPage, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkNotebook, setCurrentPage, arginfo_class_GtkNotebook_setCurrentPage, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkNotebook, getNthPage, arginfo_class_GtkNotebook_getNthPage, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkNotebook, setTabLabelText, arginfo_class_GtkNotebook_setTabLabelText, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkNotebook, getTabLabelText, arginfo_class_GtkNotebook_getTabLabelText, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkNotebook, getShowTabs, arginfo_class_GtkNotebook_getShowTabs, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkNotebook, setShowTabs, arginfo_class_GtkNotebook_setShowTabs, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkNotebook, getScrollable, arginfo_class_GtkNotebook_getScrollable, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkNotebook, setScrollable, arginfo_class_GtkNotebook_setScrollable, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_PangoEllipsizeMode(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("PangoEllipsizeMode", IS_LONG, NULL);

	zval enum_case_NONE_value;
	ZVAL_LONG(&enum_case_NONE_value, 0);
	zend_enum_add_case_cstr(class_entry, "NONE", &enum_case_NONE_value);

	zval enum_case_START_value;
	ZVAL_LONG(&enum_case_START_value, 1);
	zend_enum_add_case_cstr(class_entry, "START", &enum_case_START_value);

	zval enum_case_MIDDLE_value;
	ZVAL_LONG(&enum_case_MIDDLE_value, 2);
	zend_enum_add_case_cstr(class_entry, "MIDDLE", &enum_case_MIDDLE_value);

	zval enum_case_END_value;
	ZVAL_LONG(&enum_case_END_value, 3);
	zend_enum_add_case_cstr(class_entry, "END", &enum_case_END_value);

	return class_entry;
}

static zend_class_entry *register_class_GtkJustification(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GtkJustification", IS_LONG, NULL);

	zval enum_case_LEFT_value;
	ZVAL_LONG(&enum_case_LEFT_value, 0);
	zend_enum_add_case_cstr(class_entry, "LEFT", &enum_case_LEFT_value);

	zval enum_case_RIGHT_value;
	ZVAL_LONG(&enum_case_RIGHT_value, 1);
	zend_enum_add_case_cstr(class_entry, "RIGHT", &enum_case_RIGHT_value);

	zval enum_case_CENTER_value;
	ZVAL_LONG(&enum_case_CENTER_value, 2);
	zend_enum_add_case_cstr(class_entry, "CENTER", &enum_case_CENTER_value);

	zval enum_case_FILL_value;
	ZVAL_LONG(&enum_case_FILL_value, 3);
	zend_enum_add_case_cstr(class_entry, "FILL", &enum_case_FILL_value);

	return class_entry;
}

static zend_class_entry *register_class_GtkWrapMode(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GtkWrapMode", IS_LONG, NULL);

	zval enum_case_NONE_value;
	ZVAL_LONG(&enum_case_NONE_value, 0);
	zend_enum_add_case_cstr(class_entry, "NONE", &enum_case_NONE_value);

	zval enum_case_CHAR_value;
	ZVAL_LONG(&enum_case_CHAR_value, 1);
	zend_enum_add_case_cstr(class_entry, "CHAR", &enum_case_CHAR_value);

	zval enum_case_WORD_value;
	ZVAL_LONG(&enum_case_WORD_value, 2);
	zend_enum_add_case_cstr(class_entry, "WORD", &enum_case_WORD_value);

	zval enum_case_WORD_CHAR_value;
	ZVAL_LONG(&enum_case_WORD_CHAR_value, 3);
	zend_enum_add_case_cstr(class_entry, "WORD_CHAR", &enum_case_WORD_CHAR_value);

	return class_entry;
}

static zend_class_entry *register_class_GtkContentFit(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GtkContentFit", IS_LONG, NULL);

	zval enum_case_FILL_value;
	ZVAL_LONG(&enum_case_FILL_value, 0);
	zend_enum_add_case_cstr(class_entry, "FILL", &enum_case_FILL_value);

	zval enum_case_CONTAIN_value;
	ZVAL_LONG(&enum_case_CONTAIN_value, 1);
	zend_enum_add_case_cstr(class_entry, "CONTAIN", &enum_case_CONTAIN_value);

	zval enum_case_COVER_value;
	ZVAL_LONG(&enum_case_COVER_value, 2);
	zend_enum_add_case_cstr(class_entry, "COVER", &enum_case_COVER_value);

	zval enum_case_SCALE_DOWN_value;
	ZVAL_LONG(&enum_case_SCALE_DOWN_value, 3);
	zend_enum_add_case_cstr(class_entry, "SCALE_DOWN", &enum_case_SCALE_DOWN_value);

	return class_entry;
}

static zend_class_entry *register_class_GtkPolicyType(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GtkPolicyType", IS_LONG, NULL);

	zval enum_case_ALWAYS_value;
	ZVAL_LONG(&enum_case_ALWAYS_value, 0);
	zend_enum_add_case_cstr(class_entry, "ALWAYS", &enum_case_ALWAYS_value);

	zval enum_case_AUTOMATIC_value;
	ZVAL_LONG(&enum_case_AUTOMATIC_value, 1);
	zend_enum_add_case_cstr(class_entry, "AUTOMATIC", &enum_case_AUTOMATIC_value);

	zval enum_case_NEVER_value;
	ZVAL_LONG(&enum_case_NEVER_value, 2);
	zend_enum_add_case_cstr(class_entry, "NEVER", &enum_case_NEVER_value);

	zval enum_case_EXTERNAL_value;
	ZVAL_LONG(&enum_case_EXTERNAL_value, 3);
	zend_enum_add_case_cstr(class_entry, "EXTERNAL", &enum_case_EXTERNAL_value);

	return class_entry;
}

static zend_class_entry *register_class_GtkLabel(zend_class_entry *class_entry_GtkWidget)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkLabel", class_GtkLabel_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkWidget, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkButton(zend_class_entry *class_entry_GtkWidget)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkButton", class_GtkButton_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkWidget, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkMenuButton(zend_class_entry *class_entry_GtkWidget)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkMenuButton", class_GtkMenuButton_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkWidget, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkScrollbar(zend_class_entry *class_entry_GtkWidget)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkScrollbar", class_GtkScrollbar_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkWidget, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkLinkButton(zend_class_entry *class_entry_GtkButton)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkLinkButton", class_GtkLinkButton_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkButton, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkImage(zend_class_entry *class_entry_GtkWidget)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkImage", class_GtkImage_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkWidget, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkCheckButton(zend_class_entry *class_entry_GtkWidget)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkCheckButton", class_GtkCheckButton_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkWidget, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkSwitch(zend_class_entry *class_entry_GtkWidget)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkSwitch", class_GtkSwitch_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkWidget, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkToggleButton(zend_class_entry *class_entry_GtkButton)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkToggleButton", class_GtkToggleButton_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkButton, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkEntryBuffer(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkEntryBuffer", class_GtkEntryBuffer_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkEntry(zend_class_entry *class_entry_GtkWidget)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkEntry", class_GtkEntry_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkWidget, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkTextBuffer(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkTextBuffer", class_GtkTextBuffer_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkTextView(zend_class_entry *class_entry_GtkWidget)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkTextView", class_GtkTextView_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkWidget, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkScale(zend_class_entry *class_entry_GtkWidget)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkScale", class_GtkScale_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkWidget, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkStringList(zend_class_entry *class_entry_GObject, zend_class_entry *class_entry_GListModel)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkStringList", class_GtkStringList_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);
	zend_class_implements(class_entry, 1, class_entry_GListModel);

	return class_entry;
}

static zend_class_entry *register_class_GtkStringObject(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkStringObject", class_GtkStringObject_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkDropDown(zend_class_entry *class_entry_GtkWidget)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkDropDown", class_GtkDropDown_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkWidget, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkCalendar(zend_class_entry *class_entry_GtkWidget)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkCalendar", class_GtkCalendar_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkWidget, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkProgressBar(zend_class_entry *class_entry_GtkWidget)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkProgressBar", class_GtkProgressBar_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkWidget, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkSpinner(zend_class_entry *class_entry_GtkWidget)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkSpinner", class_GtkSpinner_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkWidget, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkPicture(zend_class_entry *class_entry_GtkWidget)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkPicture", class_GtkPicture_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkWidget, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkSeparator(zend_class_entry *class_entry_GtkWidget)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkSeparator", class_GtkSeparator_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkWidget, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkScrolledWindow(zend_class_entry *class_entry_GtkWidget)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkScrolledWindow", class_GtkScrolledWindow_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkWidget, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkPaned(zend_class_entry *class_entry_GtkWidget)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkPaned", class_GtkPaned_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkWidget, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkNotebook(zend_class_entry *class_entry_GtkWidget)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkNotebook", class_GtkNotebook_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkWidget, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
