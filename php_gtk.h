#ifndef PHP_GTK_H
#define PHP_GTK_H

extern zend_module_entry gtk_module_entry;
#define phpext_gtk_ptr &gtk_module_entry

#define PHP_GTK_VERSION "0.10.1"

#if defined(ZTS) && defined(COMPILE_DL_GTK)
ZEND_TSRMLS_CACHE_EXTERN()
#endif

#endif
