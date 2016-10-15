#include <iostream>
#include <string>
#include <vector>
#include <memory>


class Singleton {
public:
    static Singleton& getInstance() {
        std::cout << "Singleton::getInstance()" << std::endl;
        return *_instance;
    }

    void foo() {
        std::cout << "Singleton::foo()" << std::endl;
    }

private:
    Singleton() {
        std::cout << "Singleton::Singleton()" << std::endl;
    }

    Singleton(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton(const Singleton&&) = delete;

    Singleton& operator= (Singleton) = delete;
    Singleton& operator= (Singleton&) = delete;
    Singleton& operator= (const Singleton&) = delete;
    Singleton&& operator= (Singleton&&) = delete;
    Singleton&& operator= (const Singleton&&) = delete;

    static std::unique_ptr<Singleton> _instance;
};

std::unique_ptr<Singleton> Singleton::_instance = std::unique_ptr<Singleton>{ new Singleton() };


auto main() -> int {

    Singleton& singleton = Singleton::getInstance();
    singleton.foo();

    //Singleton singleton;

    return 0;
}

