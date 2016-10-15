#include <iostream>
#include <string>

/*
template <typename ...Args>
void variable_func(Args... args) {
    std::cout << args << std::endl;
}

auto main() -> int {
    //std::cout << "hello world" << std::endl;

    variable_func();

    return 0;
}
*/


//void tprintf(const char* format) {
auto tprintf(const char* format) -> void {
    std::cout << format;
}

template <typename T, typename... Targs>
//void tprintf(const char* format, T value, Targs... Fargs) { // recursive variadic function
auto tprintf(const char* format, T value, Targs... Fargs) -> void {
    for (; *format != '\0'; format++) {
        if (*format == '%') {
            std::cout << value;
            tprintf(format+1, Fargs...); // recursive call
            return;
        }
        std::cout << *format;
    }
}

template <typename T, typename... Targs>
//void tprintf(const std::string& sformat, T value, Targs... Fargs) {
auto tprintf(const std::string& sformat, T value, Targs... Fargs) -> void {
    tprintf(sformat.c_str(), value, Fargs...);
}


//int main() {
auto main() -> decltype(0) {
    tprintf("% world% %\n", "Hello", '!', 123);
    tprintf(std::string("% blah %\n"), "wtf", 2.432);
    return 0;
}


