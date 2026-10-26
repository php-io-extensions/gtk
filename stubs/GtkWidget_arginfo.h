/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 991ff7d1b3e6f93b0b0433c12ac3f495277b7b5d */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_GraphenePoint___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_GrapheneSize___construct, 0, 0, 2)
	ZEND_ARG_TYPE_INFO(0, width, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_GrapheneRect___construct, 0, 0, 2)
	ZEND_ARG_OBJ_INFO(0, origin, GraphenePoint, 0)
	ZEND_ARG_OBJ_INFO(0, size, GrapheneSize, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWidget_show, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkWidget_hide arginfo_class_GtkWidget_show

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWidget_getVisible, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkWidget_getRealized arginfo_class_GtkWidget_getVisible

#define arginfo_class_GtkWidget_getMapped arginfo_class_GtkWidget_getVisible

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWidget_setVisible, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, visible, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkWidget_getHexpand arginfo_class_GtkWidget_getVisible

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWidget_setHexpand, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, expand, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkWidget_getVexpand arginfo_class_GtkWidget_getVisible

#define arginfo_class_GtkWidget_setVexpand arginfo_class_GtkWidget_setHexpand

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkWidget_getParent, 0, 0, GtkWidget, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWidget_insertActionGroup, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, group, GActionGroup, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWidget_activateActionVariant, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
	ZEND_ARG_OBJ_INFO(0, args, GVariant, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkWidget_activate arginfo_class_GtkWidget_getVisible

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkWidget_getHalign, 0, 0, GtkAlign, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWidget_setHalign, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, align, GtkAlign, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkWidget_getValign arginfo_class_GtkWidget_getHalign

#define arginfo_class_GtkWidget_setValign arginfo_class_GtkWidget_setHalign

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWidget_setSizeRequest, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWidget_getSizeRequest, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWidget_getWidth, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkWidget_getScaleFactor arginfo_class_GtkWidget_getWidth

#define arginfo_class_GtkWidget_getHeight arginfo_class_GtkWidget_getWidth

#define arginfo_class_GtkWidget_getSensitive arginfo_class_GtkWidget_getVisible

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWidget_setSensitive, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, sensitive, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkWidget_getColor arginfo_class_GtkWidget_getSizeRequest

#define arginfo_class_GtkWidget_isSensitive arginfo_class_GtkWidget_getVisible

#define arginfo_class_GtkWidget_grabFocus arginfo_class_GtkWidget_getVisible

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWidget_childFocus, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, direction, GtkDirectionType, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkWidget_hasFocus arginfo_class_GtkWidget_getVisible

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWidget_setMarginStart, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, margin, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkWidget_setMarginEnd arginfo_class_GtkWidget_setMarginStart

#define arginfo_class_GtkWidget_setMarginTop arginfo_class_GtkWidget_setMarginStart

#define arginfo_class_GtkWidget_setMarginBottom arginfo_class_GtkWidget_setMarginStart

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWidget_addCssClass, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, cssClass, IS_STRING, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkWidget_removeCssClass arginfo_class_GtkWidget_addCssClass

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWidget_addController, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, controller, GtkEventController, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkWidget_removeController arginfo_class_GtkWidget_addController

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWidget_computePoint, 0, 3, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, target, GtkWidget, 0)
	ZEND_ARG_OBJ_INFO(0, point, GraphenePoint, 0)
	ZEND_ARG_OBJ_INFO(1, outPoint, GraphenePoint, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkWidget_pick, 0, 3, GtkWidget, 1)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, flags, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWidget_hasCssClass, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, cssClass, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWidget_measure, 0, 2, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, orientation, GtkOrientation, 0)
	ZEND_ARG_TYPE_INFO(0, forSize, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkWidget_getNative, 0, 0, GtkNative, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkWidget_computeBounds, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, target, GtkWidget, 0)
	ZEND_ARG_OBJ_INFO(1, outBounds, GrapheneRect, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkWidget_getFirstChild arginfo_class_GtkWidget_getParent

#define arginfo_class_GtkWidget_getNextSibling arginfo_class_GtkWidget_getParent

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkWidget_getDisplay, 0, 0, GdkDisplay, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkWidget_getRoot, 0, 0, GtkRoot, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkNative_getForSurface, 0, 1, GtkNative, 1)
	ZEND_ARG_OBJ_INFO(0, surface, GdkSurface, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkNative_realize arginfo_class_GtkWidget_show

#define arginfo_class_GtkNative_unrealize arginfo_class_GtkWidget_show

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkNative_getSurface, 0, 0, GdkSurface, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkNative_getSurfaceTransform, 0, 2, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(1, x, IS_DOUBLE, 1)
	ZEND_ARG_TYPE_INFO(1, y, IS_DOUBLE, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkRoot_getDisplay arginfo_class_GtkWidget_getDisplay

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkRoot_setFocus, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, focus, GtkWidget, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkRoot_getFocus arginfo_class_GtkWidget_getParent

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkBox_new, 0, 2, GtkBox, 0)
	ZEND_ARG_OBJ_INFO(0, orientation, GtkOrientation, 0)
	ZEND_ARG_TYPE_INFO(0, spacing, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkBox_append, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, child, GtkWidget, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkBox_prepend arginfo_class_GtkBox_append

#define arginfo_class_GtkBox_remove arginfo_class_GtkBox_append

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkBox_insertChildAfter, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, child, GtkWidget, 0)
	ZEND_ARG_OBJ_INFO(0, sibling, GtkWidget, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkBox_reorderChildAfter arginfo_class_GtkBox_insertChildAfter

#define arginfo_class_GtkBox_getSpacing arginfo_class_GtkWidget_getWidth

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkBox_setSpacing, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, spacing, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkBox_getHomogeneous arginfo_class_GtkWidget_getVisible

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkBox_setHomogeneous, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, homogeneous, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkGrid_new, 0, 0, GtkGrid, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkGrid_attach, 0, 5, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, child, GtkWidget, 0)
	ZEND_ARG_TYPE_INFO(0, column, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, row, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, width, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, height, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkGrid_remove arginfo_class_GtkBox_append

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkGrid_getChildAt, 0, 2, GtkWidget, 1)
	ZEND_ARG_TYPE_INFO(0, column, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, row, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkGrid_getRowSpacing arginfo_class_GtkWidget_getWidth

#define arginfo_class_GtkGrid_setRowSpacing arginfo_class_GtkBox_setSpacing

#define arginfo_class_GtkGrid_getColumnSpacing arginfo_class_GtkWidget_getWidth

#define arginfo_class_GtkGrid_setColumnSpacing arginfo_class_GtkBox_setSpacing

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkFixed_new, 0, 0, GtkFixed, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkFixed_put, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, child, GtkWidget, 0)
	ZEND_ARG_TYPE_INFO(0, x, IS_DOUBLE, 0)
	ZEND_ARG_TYPE_INFO(0, y, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkFixed_move arginfo_class_GtkFixed_put

#define arginfo_class_GtkFixed_remove arginfo_class_GtkBox_append

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkFixed_getChildPosition, 0, 1, IS_ARRAY, 0)
	ZEND_ARG_OBJ_INFO(0, child, GtkWidget, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkPopoverMenuBar_newFromModel, 0, 1, GtkPopoverMenuBar, 0)
	ZEND_ARG_OBJ_INFO(0, model, GMenuModel, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkPopoverMenuBar_getMenuModel, 0, 0, GMenuModel, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkPopoverMenuBar_setMenuModel, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, model, GMenuModel, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkPopover_setParent, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, parent, GtkWidget, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkPopover_unparent arginfo_class_GtkWidget_show

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkPopover_setPointingTo, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, rect, GdkRectangle, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkPopover_getPointingTo, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(1, rect, GdkRectangle, 1)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkPopover_setHasArrow, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, hasArrow, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkPopover_getHasArrow arginfo_class_GtkWidget_getVisible

#define arginfo_class_GtkPopover_popup arginfo_class_GtkWidget_show

#define arginfo_class_GtkPopover_popdown arginfo_class_GtkWidget_show

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkPopover_new, 0, 0, GtkPopover, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkPopover_setChild, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, child, GtkWidget, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkPopover_getChild arginfo_class_GtkWidget_getParent

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkPopover_setAutohide, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, autohide, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkPopover_getAutohide arginfo_class_GtkWidget_getVisible

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkPopover_setPosition, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, position, GtkPositionType, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkPopover_getPosition, 0, 0, GtkPositionType, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkPopoverMenu_newFromModel, 0, 1, GtkPopoverMenu, 0)
	ZEND_ARG_OBJ_INFO(0, model, GMenuModel, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkPopoverMenu_getMenuModel arginfo_class_GtkPopoverMenuBar_getMenuModel

ZEND_METHOD(GraphenePoint, __construct);
ZEND_METHOD(GrapheneSize, __construct);
ZEND_METHOD(GrapheneRect, __construct);
ZEND_METHOD(GtkWidget, show);
ZEND_METHOD(GtkWidget, hide);
ZEND_METHOD(GtkWidget, getVisible);
ZEND_METHOD(GtkWidget, getRealized);
ZEND_METHOD(GtkWidget, getMapped);
ZEND_METHOD(GtkWidget, setVisible);
ZEND_METHOD(GtkWidget, getHexpand);
ZEND_METHOD(GtkWidget, setHexpand);
ZEND_METHOD(GtkWidget, getVexpand);
ZEND_METHOD(GtkWidget, setVexpand);
ZEND_METHOD(GtkWidget, getParent);
ZEND_METHOD(GtkWidget, insertActionGroup);
ZEND_METHOD(GtkWidget, activateActionVariant);
ZEND_METHOD(GtkWidget, activate);
ZEND_METHOD(GtkWidget, getHalign);
ZEND_METHOD(GtkWidget, setHalign);
ZEND_METHOD(GtkWidget, getValign);
ZEND_METHOD(GtkWidget, setValign);
ZEND_METHOD(GtkWidget, setSizeRequest);
ZEND_METHOD(GtkWidget, getSizeRequest);
ZEND_METHOD(GtkWidget, getWidth);
ZEND_METHOD(GtkWidget, getScaleFactor);
ZEND_METHOD(GtkWidget, getHeight);
ZEND_METHOD(GtkWidget, getSensitive);
ZEND_METHOD(GtkWidget, setSensitive);
ZEND_METHOD(GtkWidget, getColor);
ZEND_METHOD(GtkWidget, isSensitive);
ZEND_METHOD(GtkWidget, grabFocus);
ZEND_METHOD(GtkWidget, childFocus);
ZEND_METHOD(GtkWidget, hasFocus);
ZEND_METHOD(GtkWidget, setMarginStart);
ZEND_METHOD(GtkWidget, setMarginEnd);
ZEND_METHOD(GtkWidget, setMarginTop);
ZEND_METHOD(GtkWidget, setMarginBottom);
ZEND_METHOD(GtkWidget, addCssClass);
ZEND_METHOD(GtkWidget, removeCssClass);
ZEND_METHOD(GtkWidget, addController);
ZEND_METHOD(GtkWidget, removeController);
ZEND_METHOD(GtkWidget, computePoint);
ZEND_METHOD(GtkWidget, pick);
ZEND_METHOD(GtkWidget, hasCssClass);
ZEND_METHOD(GtkWidget, measure);
ZEND_METHOD(GtkWidget, getNative);
ZEND_METHOD(GtkWidget, computeBounds);
ZEND_METHOD(GtkWidget, getFirstChild);
ZEND_METHOD(GtkWidget, getNextSibling);
ZEND_METHOD(GtkWidget, getDisplay);
ZEND_METHOD(GtkWidget, getRoot);
ZEND_METHOD(GtkBox, new);
ZEND_METHOD(GtkBox, append);
ZEND_METHOD(GtkBox, prepend);
ZEND_METHOD(GtkBox, remove);
ZEND_METHOD(GtkBox, insertChildAfter);
ZEND_METHOD(GtkBox, reorderChildAfter);
ZEND_METHOD(GtkBox, getSpacing);
ZEND_METHOD(GtkBox, setSpacing);
ZEND_METHOD(GtkBox, getHomogeneous);
ZEND_METHOD(GtkBox, setHomogeneous);
ZEND_METHOD(GtkGrid, new);
ZEND_METHOD(GtkGrid, attach);
ZEND_METHOD(GtkGrid, remove);
ZEND_METHOD(GtkGrid, getChildAt);
ZEND_METHOD(GtkGrid, getRowSpacing);
ZEND_METHOD(GtkGrid, setRowSpacing);
ZEND_METHOD(GtkGrid, getColumnSpacing);
ZEND_METHOD(GtkGrid, setColumnSpacing);
ZEND_METHOD(GtkFixed, new);
ZEND_METHOD(GtkFixed, put);
ZEND_METHOD(GtkFixed, move);
ZEND_METHOD(GtkFixed, remove);
ZEND_METHOD(GtkFixed, getChildPosition);
ZEND_METHOD(GtkPopoverMenuBar, newFromModel);
ZEND_METHOD(GtkPopoverMenuBar, getMenuModel);
ZEND_METHOD(GtkPopoverMenuBar, setMenuModel);
ZEND_METHOD(GtkPopover, setParent);
ZEND_METHOD(GtkPopover, unparent);
ZEND_METHOD(GtkPopover, setPointingTo);
ZEND_METHOD(GtkPopover, getPointingTo);
ZEND_METHOD(GtkPopover, setHasArrow);
ZEND_METHOD(GtkPopover, getHasArrow);
ZEND_METHOD(GtkPopover, popup);
ZEND_METHOD(GtkPopover, popdown);
ZEND_METHOD(GtkPopover, new);
ZEND_METHOD(GtkPopover, setChild);
ZEND_METHOD(GtkPopover, getChild);
ZEND_METHOD(GtkPopover, setAutohide);
ZEND_METHOD(GtkPopover, getAutohide);
ZEND_METHOD(GtkPopover, setPosition);
ZEND_METHOD(GtkPopover, getPosition);
ZEND_METHOD(GtkPopoverMenu, newFromModel);
ZEND_METHOD(GtkPopoverMenu, getMenuModel);

static const zend_function_entry class_GraphenePoint_methods[] = {
	ZEND_ME(GraphenePoint, __construct, arginfo_class_GraphenePoint___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrapheneSize_methods[] = {
	ZEND_ME(GrapheneSize, __construct, arginfo_class_GrapheneSize___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GrapheneRect_methods[] = {
	ZEND_ME(GrapheneRect, __construct, arginfo_class_GrapheneRect___construct, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkWidget_methods[] = {
	ZEND_ME(GtkWidget, show, arginfo_class_GtkWidget_show, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, hide, arginfo_class_GtkWidget_hide, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, getVisible, arginfo_class_GtkWidget_getVisible, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, getRealized, arginfo_class_GtkWidget_getRealized, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, getMapped, arginfo_class_GtkWidget_getMapped, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, setVisible, arginfo_class_GtkWidget_setVisible, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, getHexpand, arginfo_class_GtkWidget_getHexpand, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, setHexpand, arginfo_class_GtkWidget_setHexpand, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, getVexpand, arginfo_class_GtkWidget_getVexpand, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, setVexpand, arginfo_class_GtkWidget_setVexpand, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, getParent, arginfo_class_GtkWidget_getParent, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, insertActionGroup, arginfo_class_GtkWidget_insertActionGroup, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, activateActionVariant, arginfo_class_GtkWidget_activateActionVariant, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, activate, arginfo_class_GtkWidget_activate, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, getHalign, arginfo_class_GtkWidget_getHalign, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, setHalign, arginfo_class_GtkWidget_setHalign, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, getValign, arginfo_class_GtkWidget_getValign, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, setValign, arginfo_class_GtkWidget_setValign, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, setSizeRequest, arginfo_class_GtkWidget_setSizeRequest, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, getSizeRequest, arginfo_class_GtkWidget_getSizeRequest, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, getWidth, arginfo_class_GtkWidget_getWidth, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, getScaleFactor, arginfo_class_GtkWidget_getScaleFactor, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, getHeight, arginfo_class_GtkWidget_getHeight, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, getSensitive, arginfo_class_GtkWidget_getSensitive, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, setSensitive, arginfo_class_GtkWidget_setSensitive, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, getColor, arginfo_class_GtkWidget_getColor, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, isSensitive, arginfo_class_GtkWidget_isSensitive, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, grabFocus, arginfo_class_GtkWidget_grabFocus, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, childFocus, arginfo_class_GtkWidget_childFocus, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, hasFocus, arginfo_class_GtkWidget_hasFocus, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, setMarginStart, arginfo_class_GtkWidget_setMarginStart, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, setMarginEnd, arginfo_class_GtkWidget_setMarginEnd, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, setMarginTop, arginfo_class_GtkWidget_setMarginTop, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, setMarginBottom, arginfo_class_GtkWidget_setMarginBottom, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, addCssClass, arginfo_class_GtkWidget_addCssClass, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, removeCssClass, arginfo_class_GtkWidget_removeCssClass, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, addController, arginfo_class_GtkWidget_addController, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, removeController, arginfo_class_GtkWidget_removeController, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, computePoint, arginfo_class_GtkWidget_computePoint, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, pick, arginfo_class_GtkWidget_pick, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, hasCssClass, arginfo_class_GtkWidget_hasCssClass, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, measure, arginfo_class_GtkWidget_measure, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, getNative, arginfo_class_GtkWidget_getNative, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, computeBounds, arginfo_class_GtkWidget_computeBounds, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, getFirstChild, arginfo_class_GtkWidget_getFirstChild, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, getNextSibling, arginfo_class_GtkWidget_getNextSibling, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, getDisplay, arginfo_class_GtkWidget_getDisplay, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkWidget, getRoot, arginfo_class_GtkWidget_getRoot, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkNative_methods[] = {
	ZEND_RAW_FENTRY("getForSurface", NULL, arginfo_class_GtkNative_getForSurface, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("realize", NULL, arginfo_class_GtkNative_realize, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("unrealize", NULL, arginfo_class_GtkNative_unrealize, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("getSurface", NULL, arginfo_class_GtkNative_getSurface, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("getSurfaceTransform", NULL, arginfo_class_GtkNative_getSurfaceTransform, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_FE_END
};

static const zend_function_entry class_GtkRoot_methods[] = {
	ZEND_RAW_FENTRY("getDisplay", NULL, arginfo_class_GtkRoot_getDisplay, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("setFocus", NULL, arginfo_class_GtkRoot_setFocus, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_RAW_FENTRY("getFocus", NULL, arginfo_class_GtkRoot_getFocus, ZEND_ACC_PUBLIC|ZEND_ACC_ABSTRACT, NULL, NULL)
	ZEND_FE_END
};

static const zend_function_entry class_GtkBox_methods[] = {
	ZEND_ME(GtkBox, new, arginfo_class_GtkBox_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkBox, append, arginfo_class_GtkBox_append, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkBox, prepend, arginfo_class_GtkBox_prepend, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkBox, remove, arginfo_class_GtkBox_remove, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkBox, insertChildAfter, arginfo_class_GtkBox_insertChildAfter, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkBox, reorderChildAfter, arginfo_class_GtkBox_reorderChildAfter, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkBox, getSpacing, arginfo_class_GtkBox_getSpacing, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkBox, setSpacing, arginfo_class_GtkBox_setSpacing, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkBox, getHomogeneous, arginfo_class_GtkBox_getHomogeneous, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkBox, setHomogeneous, arginfo_class_GtkBox_setHomogeneous, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkGrid_methods[] = {
	ZEND_ME(GtkGrid, new, arginfo_class_GtkGrid_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkGrid, attach, arginfo_class_GtkGrid_attach, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkGrid, remove, arginfo_class_GtkGrid_remove, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkGrid, getChildAt, arginfo_class_GtkGrid_getChildAt, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkGrid, getRowSpacing, arginfo_class_GtkGrid_getRowSpacing, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkGrid, setRowSpacing, arginfo_class_GtkGrid_setRowSpacing, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkGrid, getColumnSpacing, arginfo_class_GtkGrid_getColumnSpacing, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkGrid, setColumnSpacing, arginfo_class_GtkGrid_setColumnSpacing, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkFixed_methods[] = {
	ZEND_ME(GtkFixed, new, arginfo_class_GtkFixed_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkFixed, put, arginfo_class_GtkFixed_put, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkFixed, move, arginfo_class_GtkFixed_move, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkFixed, remove, arginfo_class_GtkFixed_remove, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkFixed, getChildPosition, arginfo_class_GtkFixed_getChildPosition, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkPopoverMenuBar_methods[] = {
	ZEND_ME(GtkPopoverMenuBar, newFromModel, arginfo_class_GtkPopoverMenuBar_newFromModel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkPopoverMenuBar, getMenuModel, arginfo_class_GtkPopoverMenuBar_getMenuModel, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPopoverMenuBar, setMenuModel, arginfo_class_GtkPopoverMenuBar_setMenuModel, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkPopover_methods[] = {
	ZEND_ME(GtkPopover, setParent, arginfo_class_GtkPopover_setParent, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPopover, unparent, arginfo_class_GtkPopover_unparent, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPopover, setPointingTo, arginfo_class_GtkPopover_setPointingTo, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPopover, getPointingTo, arginfo_class_GtkPopover_getPointingTo, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPopover, setHasArrow, arginfo_class_GtkPopover_setHasArrow, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPopover, getHasArrow, arginfo_class_GtkPopover_getHasArrow, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPopover, popup, arginfo_class_GtkPopover_popup, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPopover, popdown, arginfo_class_GtkPopover_popdown, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPopover, new, arginfo_class_GtkPopover_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkPopover, setChild, arginfo_class_GtkPopover_setChild, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPopover, getChild, arginfo_class_GtkPopover_getChild, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPopover, setAutohide, arginfo_class_GtkPopover_setAutohide, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPopover, getAutohide, arginfo_class_GtkPopover_getAutohide, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPopover, setPosition, arginfo_class_GtkPopover_setPosition, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkPopover, getPosition, arginfo_class_GtkPopover_getPosition, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkPopoverMenu_methods[] = {
	ZEND_ME(GtkPopoverMenu, newFromModel, arginfo_class_GtkPopoverMenu_newFromModel, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_ME(GtkPopoverMenu, getMenuModel, arginfo_class_GtkPopoverMenu_getMenuModel, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_GtkPositionType(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GtkPositionType", IS_LONG, NULL);

	zval enum_case_LEFT_value;
	ZVAL_LONG(&enum_case_LEFT_value, 0);
	zend_enum_add_case_cstr(class_entry, "LEFT", &enum_case_LEFT_value);

	zval enum_case_RIGHT_value;
	ZVAL_LONG(&enum_case_RIGHT_value, 1);
	zend_enum_add_case_cstr(class_entry, "RIGHT", &enum_case_RIGHT_value);

	zval enum_case_TOP_value;
	ZVAL_LONG(&enum_case_TOP_value, 2);
	zend_enum_add_case_cstr(class_entry, "TOP", &enum_case_TOP_value);

	zval enum_case_BOTTOM_value;
	ZVAL_LONG(&enum_case_BOTTOM_value, 3);
	zend_enum_add_case_cstr(class_entry, "BOTTOM", &enum_case_BOTTOM_value);

	return class_entry;
}

static zend_class_entry *register_class_GtkOrientation(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GtkOrientation", IS_LONG, NULL);

	zval enum_case_HORIZONTAL_value;
	ZVAL_LONG(&enum_case_HORIZONTAL_value, 0);
	zend_enum_add_case_cstr(class_entry, "HORIZONTAL", &enum_case_HORIZONTAL_value);

	zval enum_case_VERTICAL_value;
	ZVAL_LONG(&enum_case_VERTICAL_value, 1);
	zend_enum_add_case_cstr(class_entry, "VERTICAL", &enum_case_VERTICAL_value);

	return class_entry;
}

static zend_class_entry *register_class_GtkAlign(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GtkAlign", IS_LONG, NULL);

	zval enum_case_FILL_value;
	ZVAL_LONG(&enum_case_FILL_value, 0);
	zend_enum_add_case_cstr(class_entry, "FILL", &enum_case_FILL_value);

	zval enum_case_START_value;
	ZVAL_LONG(&enum_case_START_value, 1);
	zend_enum_add_case_cstr(class_entry, "START", &enum_case_START_value);

	zval enum_case_END_value;
	ZVAL_LONG(&enum_case_END_value, 2);
	zend_enum_add_case_cstr(class_entry, "END", &enum_case_END_value);

	zval enum_case_CENTER_value;
	ZVAL_LONG(&enum_case_CENTER_value, 3);
	zend_enum_add_case_cstr(class_entry, "CENTER", &enum_case_CENTER_value);

	zval enum_case_BASELINE_FILL_value;
	ZVAL_LONG(&enum_case_BASELINE_FILL_value, 4);
	zend_enum_add_case_cstr(class_entry, "BASELINE_FILL", &enum_case_BASELINE_FILL_value);

	zval enum_case_BASELINE_CENTER_value;
	ZVAL_LONG(&enum_case_BASELINE_CENTER_value, 5);
	zend_enum_add_case_cstr(class_entry, "BASELINE_CENTER", &enum_case_BASELINE_CENTER_value);

	return class_entry;
}

static zend_class_entry *register_class_GtkDirectionType(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GtkDirectionType", IS_LONG, NULL);

	zval enum_case_TAB_FORWARD_value;
	ZVAL_LONG(&enum_case_TAB_FORWARD_value, 0);
	zend_enum_add_case_cstr(class_entry, "TAB_FORWARD", &enum_case_TAB_FORWARD_value);

	zval enum_case_TAB_BACKWARD_value;
	ZVAL_LONG(&enum_case_TAB_BACKWARD_value, 1);
	zend_enum_add_case_cstr(class_entry, "TAB_BACKWARD", &enum_case_TAB_BACKWARD_value);

	zval enum_case_UP_value;
	ZVAL_LONG(&enum_case_UP_value, 2);
	zend_enum_add_case_cstr(class_entry, "UP", &enum_case_UP_value);

	zval enum_case_DOWN_value;
	ZVAL_LONG(&enum_case_DOWN_value, 3);
	zend_enum_add_case_cstr(class_entry, "DOWN", &enum_case_DOWN_value);

	zval enum_case_LEFT_value;
	ZVAL_LONG(&enum_case_LEFT_value, 4);
	zend_enum_add_case_cstr(class_entry, "LEFT", &enum_case_LEFT_value);

	zval enum_case_RIGHT_value;
	ZVAL_LONG(&enum_case_RIGHT_value, 5);
	zend_enum_add_case_cstr(class_entry, "RIGHT", &enum_case_RIGHT_value);

	return class_entry;
}

static zend_class_entry *register_class_GraphenePoint(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GraphenePoint", class_GraphenePoint_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_x_default_value;
	ZVAL_UNDEF(&property_x_default_value);
	zend_string *property_x_name = zend_string_init("x", sizeof("x") - 1, 1);
	zend_declare_typed_property(class_entry, property_x_name, &property_x_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_x_name);

	zval property_y_default_value;
	ZVAL_UNDEF(&property_y_default_value);
	zend_string *property_y_name = zend_string_init("y", sizeof("y") - 1, 1);
	zend_declare_typed_property(class_entry, property_y_name, &property_y_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_y_name);

	return class_entry;
}

static zend_class_entry *register_class_GrapheneSize(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GrapheneSize", class_GrapheneSize_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_width_default_value;
	ZVAL_UNDEF(&property_width_default_value);
	zend_string *property_width_name = zend_string_init("width", sizeof("width") - 1, 1);
	zend_declare_typed_property(class_entry, property_width_name, &property_width_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_width_name);

	zval property_height_default_value;
	ZVAL_UNDEF(&property_height_default_value);
	zend_string *property_height_name = zend_string_init("height", sizeof("height") - 1, 1);
	zend_declare_typed_property(class_entry, property_height_name, &property_height_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_DOUBLE));
	zend_string_release(property_height_name);

	return class_entry;
}

static zend_class_entry *register_class_GrapheneRect(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GrapheneRect", class_GrapheneRect_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL);

	zval property_origin_default_value;
	ZVAL_UNDEF(&property_origin_default_value);
	zend_string *property_origin_name = zend_string_init("origin", sizeof("origin") - 1, 1);
	zend_string *property_origin_class_GraphenePoint = zend_string_init("GraphenePoint", sizeof("GraphenePoint")-1, 1);
	zend_declare_typed_property(class_entry, property_origin_name, &property_origin_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_origin_class_GraphenePoint, 0, 0));
	zend_string_release(property_origin_name);

	zval property_size_default_value;
	ZVAL_UNDEF(&property_size_default_value);
	zend_string *property_size_name = zend_string_init("size", sizeof("size") - 1, 1);
	zend_string *property_size_class_GrapheneSize = zend_string_init("GrapheneSize", sizeof("GrapheneSize")-1, 1);
	zend_declare_typed_property(class_entry, property_size_name, &property_size_default_value, ZEND_ACC_PUBLIC, NULL, (zend_type) ZEND_TYPE_INIT_CLASS(property_size_class_GrapheneSize, 0, 0));
	zend_string_release(property_size_name);

	return class_entry;
}

static zend_class_entry *register_class_GtkWidget(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkWidget", class_GtkWidget_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkNative(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkNative", class_GtkNative_methods);
	class_entry = zend_register_internal_interface(&ce);

	return class_entry;
}

static zend_class_entry *register_class_GtkRoot(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkRoot", class_GtkRoot_methods);
	class_entry = zend_register_internal_interface(&ce);

	return class_entry;
}

static zend_class_entry *register_class_GtkBox(zend_class_entry *class_entry_GtkWidget)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkBox", class_GtkBox_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkWidget, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkGrid(zend_class_entry *class_entry_GtkWidget)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkGrid", class_GtkGrid_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkWidget, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkFixed(zend_class_entry *class_entry_GtkWidget)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkFixed", class_GtkFixed_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkWidget, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkPopoverMenuBar(zend_class_entry *class_entry_GtkWidget)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkPopoverMenuBar", class_GtkPopoverMenuBar_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkWidget, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkPopover(zend_class_entry *class_entry_GtkWidget, zend_class_entry *class_entry_GtkNative)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkPopover", class_GtkPopover_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkWidget, ZEND_ACC_NOT_SERIALIZABLE);
	zend_class_implements(class_entry, 1, class_entry_GtkNative);

	return class_entry;
}

static zend_class_entry *register_class_GtkPopoverMenu(zend_class_entry *class_entry_GtkPopover)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkPopoverMenu", class_GtkPopoverMenu_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GtkPopover, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
