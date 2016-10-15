#include <iostream>
#include <vector>
#include <string>
#include <exception>

#define STRINGIFY(x) #x

class FooThrows {
public:
    FooThrows() {
       //throw std::exception();
    }

    //static const std::string name;
};

//const std::string FooThrows::name = "FooThrows";

template <typename T>
struct TypeNameHelper {

    typedef char yes[1];
    typedef yes no[2];

    template <typename U, U u> struct hasName;

    template <typename C> static yes& test(hasName<std::string (C::*)(), &C::name>*) {}
    template <typename C> static yes& test(hasName<std::string (C::*)() const, &C::name>*) {}

    template <typename> static no& test(...) {}

    static const bool value = sizeof(test<T>(0)) == sizeof(yes);
};

template <typename T>
struct TypeNames {
static std::string name() {
    if (TypeNameHelper<T>::value) {
        return T::name;
    } else {
        return std::string("Unknown");
    }
}
};

template <typename T>
std::string type_names_to_string(const T& t) {
    throw std::exception();
}

template <typename T>
T* create() {
    std::cout << "Creating " << TypeNames<T>::name() << std::endl;
    return new (std::nothrow) T();
}

int main(int argc, char** argv) {

    std::cout << "Starting..." << std::endl;

    //FooThrows* foo = new FooThrows();
    //FooThrows* foo = new (std::nothrow) FooThrows[12031923012931];
    FooThrows* foo = create<FooThrows>();
    if (foo == nullptr) {
        std::cout << "Unable to initialize foo" << std::endl;
    }

    std::cout << "Exiting..." << std::endl;
    return EXIT_SUCCESS;
}


