# Compile

phpize  
./configure --enable-hello  
make  

# Tutorial 1

http://devzone.zend.com/303/extension-writing-part-i-introduction-to-php-and-zend/

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


# Tutorial 2

http://devzone.zend.com/317/extension-writing-part-ii-parameters-arrays-and-zvals/

php -c php.ini -r "hello_greetme('Joe');"  
Hello Joe

php -c php.ini -r "echo hello_add(2, 4.1);"  
6.1

php -c php.ini -r "echo hello_add(2, 4.1, true);"  
6
