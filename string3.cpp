#include <iostream>
#include <string>


auto main() -> int {
    std::string str { "Hello world" };
    std::string str2 { R"foo(Hello world!)" };
alksdjfa;lsjdfl
asdflajsldfj
sldfjlsd
sldfj
sldjf
) asdflja sdf;lsjd f");
")foo)")foo" };

    using namespace std::string_literals;

    auto str3 = "This is a std::string?"s;
    auto str4 = "This is a const char* string?";

    std::cout << str << std::endl;
    std::cout << str2 << std::endl;
    std::cout << str3 << std::endl;
    std::cout << str4 << std::endl;

    std::cout << typeid(str).name() << std::endl;
    std::cout << typeid(str2).name() << std::endl;
    std::cout << typeid(str3).name() << std::endl;
    std::cout << typeid(str4).name() << std::endl;



    return 0;
}


