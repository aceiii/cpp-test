

#include <iostream>
#include <string>

#include "testclass.h"


TestClass::TestClass():_name("") {
}

TestClass::~TestClass() {
}

void TestClass::do_something(int a, const std::string &str) const {
    std::cout << "do something! " << str << "(" << a << ")" << std::endl;
}


