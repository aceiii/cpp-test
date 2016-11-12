#include <iostream>
#include <string>
#include <vector>

auto main() -> int {

    int a = 5;
    int c = 123;
    int f = 92340;

    const int* b = &a;

    std::cout << "b: " << *b << std::endl;
    //*b = 99; // read-only variable b

    b = &c;
    //*b = 1024; // still can't change
    std::cout << "b: " << *b << std::endl;

    int* const d = &a;

    std::cout << "d: " << *d << std::endl;
    *d = 99;
    //d = &c; // const-qualified type 'int *const'
    std::cout << "a: " << a << std::endl;
    std::cout << "d: " << *d << std::endl;

    const int* const g = &f;
    / Can't change both value of pointer and pointed to var
    //*g = 555;
    //g = &b;
    std::cout << "g: " << *g << std::endl;

    return 0;
}

