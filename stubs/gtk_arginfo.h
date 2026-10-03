/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: a88ffe8e99cb49f03ac254a7cab394b6f08e10d3 */

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_init, 0, 0, IS_VOID, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_init_check, 0, 0, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

#define arginfo_gtk_is_initialized arginfo_gtk_init_check

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_get_major_version, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_gtk_get_minor_version arginfo_gtk_get_major_version

#define arginfo_gtk_get_micro_version arginfo_gtk_get_major_version

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_style_context_add_provider_for_display, 0, 3, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, display, GdkDisplay, 0)
	ZEND_ARG_OBJ_INFO(0, provider, GtkCssProvider, 0)
	ZEND_ARG_TYPE_INFO(0, priority, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_style_context_remove_provider_for_display, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, display, GdkDisplay, 0)
	ZEND_ARG_OBJ_INFO(0, provider, GtkCssProvider, 0)
ZEND_END_ARG_INFO()

#define arginfo_gtk_media_backend_available arginfo_gtk_init_check

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_g_timeout_add, 0, 2, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, interval, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, function, IS_CALLABLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_g_idle_add, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, function, IS_CALLABLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_g_unix_fd_add, 0, 3, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, fd, IS_MIXED, 0)
	ZEND_ARG_OBJ_TYPE_MASK(0, condition, GIOCondition, MAY_BE_LONG, NULL)
	ZEND_ARG_TYPE_INFO(0, function, IS_CALLABLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_g_source_remove, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, tag, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_g_signal_connect, 0, 3, IS_LONG, 0)
	ZEND_ARG_OBJ_INFO(0, instance, GObject, 0)
	ZEND_ARG_TYPE_INFO(0, detailed_signal, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, c_handler, IS_CALLABLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_g_signal_emit_by_name, 0, 2, IS_MIXED, 0)
	ZEND_ARG_OBJ_INFO(0, instance, GObject, 0)
	ZEND_ARG_TYPE_INFO(0, detailed_signal, IS_STRING, 0)
	ZEND_ARG_VARIADIC_TYPE_INFO(0, params, IS_MIXED, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_g_signal_handler_disconnect, 0, 2, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, instance, GObject, 0)
	ZEND_ARG_TYPE_INFO(0, handler_id, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_g_signal_handler_is_connected, 0, 2, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, instance, GObject, 0)
	ZEND_ARG_TYPE_INFO(0, handler_id, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_FUNCTION(gtk_init);
ZEND_FUNCTION(gtk_init_check);
ZEND_FUNCTION(gtk_is_initialized);
ZEND_FUNCTION(gtk_get_major_version);
ZEND_FUNCTION(gtk_get_minor_version);
ZEND_FUNCTION(gtk_get_micro_version);
ZEND_FUNCTION(gtk_style_context_add_provider_for_display);
ZEND_FUNCTION(gtk_style_context_remove_provider_for_display);
ZEND_FUNCTION(gtk_media_backend_available);
ZEND_FUNCTION(g_timeout_add);
ZEND_FUNCTION(g_idle_add);
ZEND_FUNCTION(g_unix_fd_add);
ZEND_FUNCTION(g_source_remove);
ZEND_FUNCTION(g_signal_connect);
ZEND_FUNCTION(g_signal_emit_by_name);
ZEND_FUNCTION(g_signal_handler_disconnect);
ZEND_FUNCTION(g_signal_handler_is_connected);

static const zend_function_entry ext_functions[] = {
	ZEND_FE(gtk_init, arginfo_gtk_init)
	ZEND_FE(gtk_init_check, arginfo_gtk_init_check)
	ZEND_FE(gtk_is_initialized, arginfo_gtk_is_initialized)
	ZEND_FE(gtk_get_major_version, arginfo_gtk_get_major_version)
	ZEND_FE(gtk_get_minor_version, arginfo_gtk_get_minor_version)
	ZEND_FE(gtk_get_micro_version, arginfo_gtk_get_micro_version)
	ZEND_FE(gtk_style_context_add_provider_for_display, arginfo_gtk_style_context_add_provider_for_display)
	ZEND_FE(gtk_style_context_remove_provider_for_display, arginfo_gtk_style_context_remove_provider_for_display)
	ZEND_FE(gtk_media_backend_available, arginfo_gtk_media_backend_available)
	ZEND_FE(g_timeout_add, arginfo_g_timeout_add)
	ZEND_FE(g_idle_add, arginfo_g_idle_add)
	ZEND_FE(g_unix_fd_add, arginfo_g_unix_fd_add)
	ZEND_FE(g_source_remove, arginfo_g_source_remove)
	ZEND_FE(g_signal_connect, arginfo_g_signal_connect)
	ZEND_FE(g_signal_emit_by_name, arginfo_g_signal_emit_by_name)
	ZEND_FE(g_signal_handler_disconnect, arginfo_g_signal_handler_disconnect)
	ZEND_FE(g_signal_handler_is_connected, arginfo_g_signal_handler_is_connected)
	ZEND_FE_END
};

static void register_gtk_symbols(int module_number)
{
	REGISTER_BOOL_CONSTANT("G_SOURCE_CONTINUE", G_SOURCE_CONTINUE, CONST_PERSISTENT);
	REGISTER_BOOL_CONSTANT("G_SOURCE_REMOVE", G_SOURCE_REMOVE, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("GTK_STYLE_PROVIDER_PRIORITY_APPLICATION", GTK_STYLE_PROVIDER_PRIORITY_APPLICATION, CONST_PERSISTENT);
	REGISTER_LONG_CONSTANT("GTK_INVALID_LIST_POSITION", GTK_INVALID_LIST_POSITION, CONST_PERSISTENT);
}

static zend_class_entry *register_class_GIOCondition(void)
{
	zend_class_entry *class_entry = zend_register_internal_enum("GIOCondition", IS_LONG, NULL);

	zval enum_case_IN_value;
	ZVAL_LONG(&enum_case_IN_value, 1);
	zend_enum_add_case_cstr(class_entry, "IN", &enum_case_IN_value);

	zval enum_case_PRI_value;
	ZVAL_LONG(&enum_case_PRI_value, 2);
	zend_enum_add_case_cstr(class_entry, "PRI", &enum_case_PRI_value);

	zval enum_case_OUT_value;
	ZVAL_LONG(&enum_case_OUT_value, 4);
	zend_enum_add_case_cstr(class_entry, "OUT", &enum_case_OUT_value);

	zval enum_case_ERR_value;
	ZVAL_LONG(&enum_case_ERR_value, 8);
	zend_enum_add_case_cstr(class_entry, "ERR", &enum_case_ERR_value);

	zval enum_case_HUP_value;
	ZVAL_LONG(&enum_case_HUP_value, 16);
	zend_enum_add_case_cstr(class_entry, "HUP", &enum_case_HUP_value);

	zval enum_case_NVAL_value;
	ZVAL_LONG(&enum_case_NVAL_value, 32);
	zend_enum_add_case_cstr(class_entry, "NVAL", &enum_case_NVAL_value);

	return class_entry;
}

static zend_class_entry *register_class_GtkException(zend_class_entry *class_entry_RuntimeException)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkException", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_RuntimeException, 0);

	return class_entry;
}

static zend_class_entry *register_class_GError(zend_class_entry *class_entry_RuntimeException)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GError", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_RuntimeException, 0);

	zval property_domain_default_value;
	ZVAL_UNDEF(&property_domain_default_value);
	zend_string *property_domain_name = zend_string_init("domain", sizeof("domain") - 1, 1);
	zend_declare_typed_property(class_entry, property_domain_name, &property_domain_default_value, ZEND_ACC_PUBLIC|ZEND_ACC_READONLY, NULL, (zend_type) ZEND_TYPE_INIT_MASK(MAY_BE_STRING));
	zend_string_release(property_domain_name);

	return class_entry;
}
