#include "runtime.h"
#include "../stubs/GMainContext_arginfo.h"

void phpgtk_register_GMainContext(void)
{
	phpgtk_ce_GMainContext = register_class_GMainContext();
	phpgtk_object_setup(phpgtk_ce_GMainContext);
}

#define THIS_CONTEXT ((GMainContext *) PHPGTK_PTR(Z_OBJ_P(ZEND_THIS)))

ZEND_METHOD(GMainContext, __construct)
{
	ZEND_PARSE_PARAMETERS_NONE();
}

ZEND_METHOD(GMainContext, default)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_main_context(return_value, g_main_context_default());
}

ZEND_METHOD(GMainContext, getThreadDefault)
{
	ZEND_PARSE_PARAMETERS_NONE();

	phpgtk_box_main_context(return_value, g_main_context_get_thread_default());
}

ZEND_METHOD(GMainContext, iteration)
{
	bool may_block;

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_BOOL(may_block)
	ZEND_PARSE_PARAMETERS_END();

	RETURN_BOOL(g_main_context_iteration(THIS_CONTEXT, may_block));
}

ZEND_METHOD(GMainContext, pending)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_BOOL(g_main_context_pending(THIS_CONTEXT));
}

ZEND_METHOD(GMainContext, wakeup)
{
	ZEND_PARSE_PARAMETERS_NONE();

	g_main_context_wakeup(THIS_CONTEXT);
}

ZEND_METHOD(GMainContext, acquire)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_BOOL(g_main_context_acquire(THIS_CONTEXT));
}

ZEND_METHOD(GMainContext, release)
{
	ZEND_PARSE_PARAMETERS_NONE();

	g_main_context_release(THIS_CONTEXT);
}

ZEND_METHOD(GMainContext, isOwner)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_BOOL(g_main_context_is_owner(THIS_CONTEXT));
}

ZEND_METHOD(GMainContext, pointer)
{
	ZEND_PARSE_PARAMETERS_NONE();

	RETURN_LONG((zend_long) (uintptr_t) THIS_CONTEXT);
}
