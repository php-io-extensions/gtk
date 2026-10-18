/* This is a generated file, edit the .stub.php file instead.
 * Stub hash: 54e4976e5efccd8adfd1974244016cbc84885d67 */

ZEND_BEGIN_ARG_INFO_EX(arginfo_class_GtkTextIter___construct, 0, 0, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkTextIter_getLine, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkTextIter_getLineOffset arginfo_class_GtkTextIter_getLine

#define arginfo_class_GtkTextIter_getOffset arginfo_class_GtkTextIter_getLine

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkTextIter_hasTag, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_OBJ_INFO(0, tag, GtkTextTag, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkTextIter_getTags, 0, 0, IS_ARRAY, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkTextTag_new, 0, 1, GtkTextTag, 0)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 1)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkTextTagTable_add arginfo_class_GtkTextIter_hasTag

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkTextTagTable_remove, 0, 1, IS_VOID, 0)
	ZEND_ARG_OBJ_INFO(0, tag, GtkTextTag, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_OBJ_INFO_EX(arginfo_class_GtkTextTagTable_lookup, 0, 1, GtkTextTag, 1)
	ZEND_ARG_TYPE_INFO(0, name, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkAdjustment_getValue, 0, 0, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_class_GtkAdjustment_setValue, 0, 1, IS_VOID, 0)
	ZEND_ARG_TYPE_INFO(0, value, IS_DOUBLE, 0)
ZEND_END_ARG_INFO()

#define arginfo_class_GtkAdjustment_getLower arginfo_class_GtkAdjustment_getValue

#define arginfo_class_GtkAdjustment_getUpper arginfo_class_GtkAdjustment_getValue

#define arginfo_class_GtkAdjustment_getPageSize arginfo_class_GtkAdjustment_getValue

ZEND_METHOD(GtkTextIter, __construct);
ZEND_METHOD(GtkTextIter, getLine);
ZEND_METHOD(GtkTextIter, getLineOffset);
ZEND_METHOD(GtkTextIter, getOffset);
ZEND_METHOD(GtkTextIter, hasTag);
ZEND_METHOD(GtkTextIter, getTags);
ZEND_METHOD(GtkTextTag, new);
ZEND_METHOD(GtkTextTagTable, add);
ZEND_METHOD(GtkTextTagTable, remove);
ZEND_METHOD(GtkTextTagTable, lookup);
ZEND_METHOD(GtkAdjustment, getValue);
ZEND_METHOD(GtkAdjustment, setValue);
ZEND_METHOD(GtkAdjustment, getLower);
ZEND_METHOD(GtkAdjustment, getUpper);
ZEND_METHOD(GtkAdjustment, getPageSize);

static const zend_function_entry class_GtkTextIter_methods[] = {
	ZEND_ME(GtkTextIter, __construct, arginfo_class_GtkTextIter___construct, ZEND_ACC_PRIVATE)
	ZEND_ME(GtkTextIter, getLine, arginfo_class_GtkTextIter_getLine, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTextIter, getLineOffset, arginfo_class_GtkTextIter_getLineOffset, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTextIter, getOffset, arginfo_class_GtkTextIter_getOffset, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTextIter, hasTag, arginfo_class_GtkTextIter_hasTag, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTextIter, getTags, arginfo_class_GtkTextIter_getTags, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkTextTag_methods[] = {
	ZEND_ME(GtkTextTag, new, arginfo_class_GtkTextTag_new, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkTextTagTable_methods[] = {
	ZEND_ME(GtkTextTagTable, add, arginfo_class_GtkTextTagTable_add, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTextTagTable, remove, arginfo_class_GtkTextTagTable_remove, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkTextTagTable, lookup, arginfo_class_GtkTextTagTable_lookup, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static const zend_function_entry class_GtkAdjustment_methods[] = {
	ZEND_ME(GtkAdjustment, getValue, arginfo_class_GtkAdjustment_getValue, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkAdjustment, setValue, arginfo_class_GtkAdjustment_setValue, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkAdjustment, getLower, arginfo_class_GtkAdjustment_getLower, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkAdjustment, getUpper, arginfo_class_GtkAdjustment_getUpper, ZEND_ACC_PUBLIC)
	ZEND_ME(GtkAdjustment, getPageSize, arginfo_class_GtkAdjustment_getPageSize, ZEND_ACC_PUBLIC)
	ZEND_FE_END
};

static zend_class_entry *register_class_GtkTextIter(void)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkTextIter", class_GtkTextIter_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, NULL, ZEND_ACC_FINAL|ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkTextMark(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkTextMark", NULL);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkTextTag(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkTextTag", class_GtkTextTag_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkTextTagTable(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkTextTagTable", class_GtkTextTagTable_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}

static zend_class_entry *register_class_GtkAdjustment(zend_class_entry *class_entry_GObject)
{
	zend_class_entry ce, *class_entry;

	INIT_CLASS_ENTRY(ce, "GtkAdjustment", class_GtkAdjustment_methods);
	class_entry = zend_register_internal_class_with_flags(&ce, class_entry_GObject, ZEND_ACC_NOT_SERIALIZABLE);

	return class_entry;
}
