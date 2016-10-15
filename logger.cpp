
#include <iostream>
#include <sstream>


#define LOG(msg)                \
    std::ostringstream os;      \
    os << msg;                  \

#define PRINT(msg)              \
    std::cout << msg            \



void test001() {
    PRINT("hello, world!");
}


void test002() {
    std::ostringstream msg;
    msg << "This is test002!" << std::endl;
    LOG(msg);

    /*std::ostringstream os;
    os << "Hello, world";*/

}


int main(int argc, char* argv[]) {
    test001();
    test002();
    
    return 0;
}



