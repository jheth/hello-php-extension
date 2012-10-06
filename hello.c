#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ini.h"
#include "php_hello.h"

ZEND_DECLARE_MODULE_GLOBALS(hello)

static function_entry hello_functions[] = {
    PHP_FE(hello_world, NULL)
    PHP_FE(hello_long, NULL)
    PHP_FE(hello_double, NULL)
    PHP_FE(hello_bool, NULL)
    PHP_FE(hello_null, NULL)
    PHP_FE(hello_greetme, NULL)
    PHP_FE(hello_add, NULL)
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
    PHP_RINIT(hello),
    NULL,
    NULL,
#if ZEND_MODULE_API_NO >= 20010901
    PHP_HELLO_WORLD_VERSION,
#endif
    STANDARD_MODULE_PROPERTIES
};

#ifdef COMPILE_DL_HELLO
ZEND_GET_MODULE(hello)
#endif

PHP_INI_BEGIN()
    PHP_INI_ENTRY("hello.greeting", "Hello World", PHP_INI_ALL, NULL)
    STD_PHP_INI_ENTRY("hello.direction", "1", PHP_INI_ALL,
        OnUpdateBool, direction, zend_hello_globals, hello_globals)
PHP_INI_END()

static void php_hello_init_globals(zend_hello_globals *hello_globals)
{
    hello_globals->direction = 1;
}

PHP_RINIT_FUNCTION(hello)
{
    HELLO_G(counter) = 0;

    return SUCCESS;
}

PHP_MINIT_FUNCTION(hello)
{
    ZEND_INIT_MODULE_GLOBALS(hello, php_hello_init_globals, NULL);
    REGISTER_INI_ENTRIES();

    return SUCCESS;
}

PHP_MSHUTDOWN_FUNCTION(hello)
{
    UNREGISTER_INI_ENTRIES();

    return SUCCESS;
}

PHP_FUNCTION(hello_world)
{
    RETURN_STRING(INI_STR("hello.greeting"), 1);
}

PHP_FUNCTION(hello_long)
{
    if (HELLO_G(direction)) {
        HELLO_G(counter)++;
    } else {
        HELLO_G(counter)--;
    }

    RETURN_LONG(HELLO_G(counter));
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

PHP_FUNCTION(hello_greetme)
{
    char *name;
    int name_len;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "s", &name, &name_len) == FAILURE) {
        RETURN_NULL();
    }

    php_printf("Hello %s", name);

    RETURN_TRUE;
}

PHP_FUNCTION(hello_add)
{
    long a;
    double b;
    zend_bool return_long = 0;

    if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "ld|b", &a, &b, &return_long) == FAILURE) {
        RETURN_NULL();
    }

    if (return_long) {
        RETURN_LONG(a + b);
    } else {
        RETURN_DOUBLE(a + b);
    }
}
