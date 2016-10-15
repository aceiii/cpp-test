

#include <string>
#include <iostream>

#include "testclass.h"

void test(int a, const std::string &str = "");


void test(int a, const std::string &str){
    std::cout << "Test: " << str << "(" << a << ")" << std::endl;
}

int main(int argc, char *argv[]) {

    const std::string &s = "test";

    std::cout << s << std::endl;


    TestClass tc;
    tc.do_something(99, "Foobar!!");

    return 0;
}


