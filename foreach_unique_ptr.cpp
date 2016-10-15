#include <iostream>
#include <string>
#include <memory>
#include <algorithm>
#include <functional>
#include <vector>


template <typename It_type, typename F>
F for_each_unique_ptr(It_type first, It_type last, F f) {
    for (; first != last; ++first) {
        f(**first);
    }
    return f;
}


template <typename T>
class Container
{
public:
    typedef std::unique_ptr<T> pointer_type;

    void add(pointer_type ptr) {
        _pointers.push_back(std::move(ptr));
    }

    template <typename F>
    void call(F fn) {
        //std::for_each(_pointers.begin(), _pointers.end(), fn);

        /*for (auto it = _pointers.begin(); it != _pointers.end(); it++) {
            T& t = **it;
            fn(t);
        }*/

        for_each_unique_ptr(_pointers.begin(), _pointers.end(), fn);
    }

    size_t size() const {
        return _pointers.size();
    }

private:
    std::vector<pointer_type> _pointers;
};


class Foo
{
public:
    Foo():_id(Foo::current_id++) {}

    void bar() {
        std::cout << "Foo.bar() - " << _id << std::endl;
    }

private:
    unsigned int _id;

    static unsigned int current_id;
};

unsigned int Foo::current_id = 0;


int main() {
    Container<Foo> c;

    constexpr int n = 1 << 16;
    for (int i = 0; i < n; i += 1) {
        std::unique_ptr<Foo> foo(new Foo());
        c.add(std::move(foo));
    }

    std::cout << "Container size: " << c.size() << std::endl;
    c.call([&] (Foo& foo) {
        foo.bar();
    });

    return 0;
}


