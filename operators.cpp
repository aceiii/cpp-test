#include <iostream>
#include <string>
#include <sstream>

template <typename T>
struct print_info_t {
    typedef T type;
    //const T& value; // willl have problems when print_info_t outlasts value it was referencing
    const T& value;

    print_info_t(const T& t):value(t) {}
};

template <typename T>
constexpr print_info_t<T> print_info(const T& t) {
    return print_info_t<T>{t};
}

template <typename T>
std::ostream& operator<< (std::ostream& os, const print_info_t<T>& pi) {
    return (os << "print_info { " << typeid(pi.value).name() << ": '" << pi.value << "' }");
}

/*
print_info_t<std::string> operator "" _wtf (const char* str, std::size_t len) {
    using namespace std::string_literals;
    std::string s { str, len };
    std::stringstream ss;
    ss << "WTF: (" << len << ") " << s;
    return print_info_t<std::string> { ss.str() }; // will print incorrect as print_info_t wants a reference, but the item is temp
}
*/

print_info_t<const char*> operator "" _wtf (const char* str, std::size_t len) {
    return print_info_t<const char*> { str };
}

/*
print_info_t<std::string> operator hello "" (const char* str, std::size_t len) {
    return print_info_t<std::string>{"world"};
}
*/

auto main() -> int {
    using namespace std::string_literals;

    auto s = "This is a std::string"s;

    std::cout << print_info(s) << std::endl;
    std::cout << "Hello world"_wtf << std::endl;

    return 0;
}

