#include <iostream>
#include <string>
#include <vector>


class Foo {
public:
    Foo(int i):_id(i) {
        std::cout << "Foo::Foo(" << i << ")" << std::endl;
    }

    Foo(Foo&& rhs) {
    }

    virtual ~Foo() {
        std::cout << "Foo(" << _id << ")::~Foo()" << std::endl;
    }

    int id() const {
        return _id;
    }

private:
    int _id;
};

class FooBar {
public:
    FooBar(int i):_id(i) {
        std::cout << "FooBar::FooBar(" << i << ")" << std::endl;
    }

    void setFoo(std::unique_ptr<Foo> foo) {
        if (_foo) {
            std::cout << "FooBar(" << _id << ")::setFoo() - prev Foo:" << _foo->id() << std::endl;
        }
        _foo = std::move(foo);
        if (_foo) {
            std::cout << "FooBar(" << _id << ")::setFoo() - new Foo:" << _foo->id() << std::endl;
        }
    }
private:
    int _id;
    std::unique_ptr<Foo> _foo;
};


std::unique_ptr<Foo> createFoo(int i) {
    return std::unique_ptr<Foo> { new Foo(i) };
}

auto main() -> int {

    Foo foo(1);
    std::unique_ptr<Foo> foo2 = std::make_unique<Foo>(2);

    FooBar foobar(1);
    foobar.setFoo(std::move(foo2));
    foobar.setFoo(std::make_unique<Foo>(3));
    //foobar.setFoo(std::move(std::make_unique<Foo>(3)));
    foobar.setFoo(createFoo(4));

    return 0;
}


