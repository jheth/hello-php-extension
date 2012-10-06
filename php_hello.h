#ifndef PHP_HELLO_H
#define PHP_HELLO_H 1

#define PHP_HELLO_WORLD_VERSION "1.0"
#define PHP_HELLO_WORLD_EXTNAME "hello"

PHP_MINIT_FUNCTION(hello);
PHP_MSHUTDOWN_FUNCTION(hello);

PHP_FUNCTION(hello_world);
PHP_FUNCTION(hello_long);
PHP_FUNCTION(hello_double);
PHP_FUNCTION(hello_bool);
PHP_FUNCTION(hello_null);

extern zend_module_entry hello_module_entry;
#define phpext_hello_prt &hello_module_entry

#endif
