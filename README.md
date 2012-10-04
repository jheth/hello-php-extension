# Tutorial 

http://devzone.zend.com/303/extension-writing-part-i-introduction-to-php-and-zend/

# Compile

phpize
./configure --enable-hello
make

# Run

php -c php.ini -r "echo hello_world();"
Hello World

php -c php.ini -r "var_dump( hello_bool() );"
bool(true)

php -c php.ini -r "echo hello_long();"
42

php -c php.ini -r "echo hello_double();"
3.1415926535

php -c php.ini -r "var_dump( hello_null() );"
NULL
