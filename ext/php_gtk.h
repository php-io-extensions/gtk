
/* This file was generated automatically by Zephir do not modify it! */

#ifndef PHP_GTK_H
#define PHP_GTK_H 1

#ifdef PHP_WIN32
#define ZEPHIR_RELEASE 1
#endif

#include "kernel/globals.h"

#define PHP_GTK_NAME        "gtk"
#define PHP_GTK_VERSION     "0.8.0"
#define PHP_GTK_EXTNAME     "gtk"
#define PHP_GTK_AUTHOR      "Project Saturn Studios, LLC"
#define PHP_GTK_ZEPVERSION  "0.19.0-$Id$"
#define PHP_GTK_DESCRIPTION "GTK4 bound 1:1 into PHP (Zephir extension, Linux only)"



ZEND_BEGIN_MODULE_GLOBALS(gtk)

	int initialized;

	/** Function cache */
	HashTable *fcache;

	zephir_fcall_cache_entry *scache[ZEPHIR_MAX_CACHE_SLOTS];

	/* Cache enabled */
	unsigned int cache_enabled;

	/* Max recursion control */
	unsigned int recursive_lock;

	
ZEND_END_MODULE_GLOBALS(gtk)

#ifdef ZTS
#include "TSRM.h"
#endif

ZEND_EXTERN_MODULE_GLOBALS(gtk)

#ifdef ZTS
	#define ZEPHIR_GLOBAL(v) ZEND_MODULE_GLOBALS_ACCESSOR(gtk, v)
#else
	#define ZEPHIR_GLOBAL(v) (gtk_globals.v)
#endif

#ifdef ZTS
	ZEND_TSRMLS_CACHE_EXTERN()
	#define ZEPHIR_VGLOBAL ((zend_gtk_globals *) (*((void ***) tsrm_get_ls_cache()))[TSRM_UNSHUFFLE_RSRC_ID(gtk_globals_id)])
#else
	#define ZEPHIR_VGLOBAL &(gtk_globals)
#endif

#define ZEPHIR_API ZEND_API

#define zephir_globals_def gtk_globals
#define zend_zephir_globals_def zend_gtk_globals

extern zend_module_entry gtk_module_entry;
#define phpext_gtk_ptr &gtk_module_entry

#endif
