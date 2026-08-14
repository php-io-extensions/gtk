
extern zend_class_entry *gtk_gtk_textview_gtktextview_ce;

ZEPHIR_INIT_CLASS(Gtk_GTK_TextView_GtkTextView);

PHP_METHOD(Gtk_GTK_TextView_GtkTextView, gtkTextViewNew);
PHP_METHOD(Gtk_GTK_TextView_GtkTextView, gtkTextViewGetBuffer);
PHP_METHOD(Gtk_GTK_TextView_GtkTextView, gtkTextViewSetText);
PHP_METHOD(Gtk_GTK_TextView_GtkTextView, gtkTextViewGetText);
PHP_METHOD(Gtk_GTK_TextView_GtkTextView, gtkTextViewSetEditable);
PHP_METHOD(Gtk_GTK_TextView_GtkTextView, gtkTextViewGetEditable);
PHP_METHOD(Gtk_GTK_TextView_GtkTextView, gtkTextViewSetWrapMode);
PHP_METHOD(Gtk_GTK_TextView_GtkTextView, gtkTextViewGetWrapMode);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_textview_gtktextview_gtktextviewnew, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_textview_gtktextview_gtktextviewgetbuffer, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, view, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_textview_gtktextview_gtktextviewsettext, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, view, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, text, IS_STRING, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_textview_gtktextview_gtktextviewgettext, 0, 1, IS_STRING, 0)
	ZEND_ARG_TYPE_INFO(0, view, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_textview_gtktextview_gtktextviewseteditable, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, view, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, editable, _IS_BOOL, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_textview_gtktextview_gtktextviewgeteditable, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, view, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_textview_gtktextview_gtktextviewsetwrapmode, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, view, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, wrapMode, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_textview_gtktextview_gtktextviewgetwrapmode, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, view, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_textview_gtktextview_method_entry) {
	PHP_ME(Gtk_GTK_TextView_GtkTextView, gtkTextViewNew, arginfo_gtk_gtk_textview_gtktextview_gtktextviewnew, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_TextView_GtkTextView, gtkTextViewGetBuffer, arginfo_gtk_gtk_textview_gtktextview_gtktextviewgetbuffer, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_TextView_GtkTextView, gtkTextViewSetText, arginfo_gtk_gtk_textview_gtktextview_gtktextviewsettext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_TextView_GtkTextView, gtkTextViewGetText, arginfo_gtk_gtk_textview_gtktextview_gtktextviewgettext, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_TextView_GtkTextView, gtkTextViewSetEditable, arginfo_gtk_gtk_textview_gtktextview_gtktextviewseteditable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_TextView_GtkTextView, gtkTextViewGetEditable, arginfo_gtk_gtk_textview_gtktextview_gtktextviewgeteditable, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_TextView_GtkTextView, gtkTextViewSetWrapMode, arginfo_gtk_gtk_textview_gtktextview_gtktextviewsetwrapmode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_GTK_TextView_GtkTextView, gtkTextViewGetWrapMode, arginfo_gtk_gtk_textview_gtktextview_gtktextviewgetwrapmode, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
