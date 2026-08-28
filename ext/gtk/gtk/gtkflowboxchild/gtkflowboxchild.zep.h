
extern zend_class_entry *gtk_gtk_gtkflowboxchild_gtkflowboxchild_ce;

ZEPHIR_INIT_CLASS(Gtk_Gtk_GtkFlowBoxChild_GtkFlowBoxChild);

PHP_METHOD(Gtk_Gtk_GtkFlowBoxChild_GtkFlowBoxChild, new_);
PHP_METHOD(Gtk_Gtk_GtkFlowBoxChild_GtkFlowBoxChild, changed);
PHP_METHOD(Gtk_Gtk_GtkFlowBoxChild_GtkFlowBoxChild, getChild);
PHP_METHOD(Gtk_Gtk_GtkFlowBoxChild_GtkFlowBoxChild, getIndex);
PHP_METHOD(Gtk_Gtk_GtkFlowBoxChild_GtkFlowBoxChild, isSelected);
PHP_METHOD(Gtk_Gtk_GtkFlowBoxChild_GtkFlowBoxChild, setChild);

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowboxchild_gtkflowboxchild_new_, 0, 0, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowboxchild_gtkflowboxchild_changed, 0, 1, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowboxchild_gtkflowboxchild_getchild, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowboxchild_gtkflowboxchild_getindex, 0, 1, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowboxchild_gtkflowboxchild_isselected, 0, 1, _IS_BOOL, 0)
	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_WITH_RETURN_TYPE_INFO_EX(arginfo_gtk_gtk_gtkflowboxchild_gtkflowboxchild_setchild, 0, 2, IS_VOID, 0)

	ZEND_ARG_TYPE_INFO(0, handle, IS_LONG, 0)
	ZEND_ARG_TYPE_INFO(0, child, IS_LONG, 0)
ZEND_END_ARG_INFO()

ZEPHIR_INIT_FUNCS(gtk_gtk_gtkflowboxchild_gtkflowboxchild_method_entry) {
	PHP_ME(Gtk_Gtk_GtkFlowBoxChild_GtkFlowBoxChild, new_, arginfo_gtk_gtk_gtkflowboxchild_gtkflowboxchild_new_, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBoxChild_GtkFlowBoxChild, changed, arginfo_gtk_gtk_gtkflowboxchild_gtkflowboxchild_changed, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBoxChild_GtkFlowBoxChild, getChild, arginfo_gtk_gtk_gtkflowboxchild_gtkflowboxchild_getchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBoxChild_GtkFlowBoxChild, getIndex, arginfo_gtk_gtk_gtkflowboxchild_gtkflowboxchild_getindex, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBoxChild_GtkFlowBoxChild, isSelected, arginfo_gtk_gtk_gtkflowboxchild_gtkflowboxchild_isselected, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_ME(Gtk_Gtk_GtkFlowBoxChild_GtkFlowBoxChild, setChild, arginfo_gtk_gtk_gtkflowboxchild_gtkflowboxchild_setchild, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};
