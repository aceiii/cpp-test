#include <iostream>
#include <vector>
#include <string>
#include <type_traits>
#include <sstream>

using namespace std::string_literals;

template <typename T>
class has_description {
    typedef char yes;
    typedef long no;

    template <typename C> static yes test(char[sizeof(&C::description)]);
    template <typename C> static no test(...);

public:
    enum { value = sizeof(test<T>(0)) == sizeof(yes) };
};

template <typename T>
typename std::enable_if<std::is_class<T>::value && has_description<T>::value, std::string>::type
repr(const T& obj) {
    std::cout << " - calling repr<T> where T::description is member - " << std::endl;
    return obj.description();
}

template <typename T>
typename std::enable_if<std::is_class<T>::value && !has_description<T>::value, std::string>::type
repr(const T& obj) {
    throw std::runtime_error("object must implement 'std::string description() const' member");
}

template <typename T>
typename std::enable_if<std::is_fundamental<T>::value, std::string>::type
repr(const T& obj) {
    std::cout << " - calling specialized repr<T> where T is fundamental" << std::endl;
    std::stringstream ss;
    ss << obj;
    return ss.str();
}

// cannot specialize repr<T> instead it's an overlaoded
// repr() with const char* parameter
inline std::string repr(const char* str) {
    std::cout << " - calling overloaded repr<char *> -" << std::endl;
    return str;
}

// specialize std::string
template <typename = std::string, typename = std::true_type>
inline std::string repr(const std::string& str) {
    std::cout << " - calling specialized repr<std::string> -" << std::endl;
    return str;
}

struct foo {
    std::string name;

    std::string description() const {
        return "I am foo('"s + name + "')"s;
    }
};

struct foobar {

    std::string description() const {
        return "I am foobar";
    }
};

struct blah {

};

auto main() -> int {

    std::cout << std::boolalpha
        << "has_description<foo> : " << (bool)has_description<foo>::value << std::endl
        << "has_description<foobar> : " << (bool)has_description<foobar>::value << std::endl
        << "has_description<blah> : " << (bool)has_description<blah>::value << std::endl;
    std::cout << std::endl;

    std::cout << repr("hello world!") << std::endl;

    std::string s = "This is a string"s;
    std::cout << repr(s) << std::endl;

    foo a { "hello"s };

    std::cout << repr(a) << std::endl;

    std::cout << repr(123) << std::endl;
    std::cout << repr(123.3234f) << std::endl;

    foobar b;

    std::cout << repr(b) << std::endl;

    std::cout << repr(blah {}) << std::endl;

    return 0;
}

