#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "php_hello.h"

static function_entry hello_functions[] = {
    PHP_FE(hello_world, NULL)
    PHP_FE(hello_long, NULL)
    PHP_FE(hello_double, NULL)
    PHP_FE(hello_bool, NULL)
    PHP_FE(hello_null, NULL)
    {NULL, NULL, NULL}
};

zend_module_entry hello_module_entry = {
#if ZEND_MODULE_API_NO >= 20010901
    STANDARD_MODULE_HEADER,
#endif
    PHP_HELLO_WORLD_EXTNAME,
    hello_functions,
    PHP_MINIT(hello),
    PHP_MSHUTDOWN(hello),
    NULL,
    NULL,
    NULL,
#if ZEND_MODULE_API_NO >= 20010901
    PHP_HELLO_WORLD_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};

PHP_INI_BEGIN()
PHP_INI_ENTRY("hello.greeting", "Hello World", PHP_INI_ALL, NULL)
PHP_INI_END()

PHP_MINIT_FUNCTION(hello)
{
    REGISTER_INI_ENTRIES();

    return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(hello)
{
    UNREGISTER_INI_ENTRIES();

    return SUCCESS;
}

#ifdef COMPILE_DL_HELLO
ZEND_GET_MODULE(hello)
#endif

PHP_FUNCTION(hello_world)
{
    RETURN_STRING(INI_STR("hello.greeting"), 1);
}

PHP_FUNCTION(hello_long)
{
    RETURN_LONG(42);
}

PHP_FUNCTION(hello_double)
{
    RETURN_DOUBLE(3.1415926535);
}

PHP_FUNCTION(hello_bool)
{
    RETURN_BOOL(1);
}

PHP_FUNCTION(hello_null)
{
    RETURN_NULL();
}
