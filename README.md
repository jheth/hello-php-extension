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

php -c php.ini -r "var_dump(hello_array());"  

    array(6) {
      [42]=>
      int(123)
      [43]=>
      string(33) "I should now be found at index 43"
      [44]=>
      string(10) "I'm at 44!"
      [45]=>
      string(10) "Forty Five"
      ["pi"]=>
      float(3.1415926535)
      ["subarray"]=>
      array(1) {
        [0]=>
        string(5) "hello"
      }
    }


Show hello_array_strings:  
    <?php
    $a = array('foo', 123);
    var_dump($a);
    hello_array_strings($a);
    var_dump($a);

Working with $GLOBALS:  
    <?php
    $GLOBALS['test'] = 'Joe';
    echo hello_get_global_var('test');
    echo hello_get_global_var('none');

